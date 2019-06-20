/**********************************************************************************
 * @author XuHuanyu
 * @data 2019/6/18
 * @brief the threadpool based on the posix
 * it can be used in the unix/linux
 * the basic api : pthread_create, pthread_mutex_init.......
 * 
 * 
 * 
 * *********************************************************************************/

#include "thread_pool.h"
#include <stdio.h>

pthread_cond_t PthreadPool::queue_cond;
pthread_mutex_t PthreadPool::queue_lock;
int PthreadPool::cur_num = 0;
vector<ThreadWork*> PthreadPool::m_vec;
pthread_t* PthreadPool::threadid = NULL;
int PthreadPool::isshutdown = 0;

void* PthreadPool::myprocess(void* arg)
{
    printf("threadid is 0x%x, working on task %d\n", pthread_self(), *(int*)arg);
    sleep(1); /*休息一秒，延长任务的执行时间*/
    return NULL;
}

void PthreadPool::Pthreadinit()
{
    pthread_mutex_init(&queue_lock, NULL);
    pthread_cond_init(&queue_cond, NULL);
    printf("beging init\n");
    PthreadPool::m_vec.empty();
    threadid = new pthread_t[MAX_NUM];
    for (int i = 0; i < MAX_NUM; i++) //启动线程
    {
        pthread_create(&threadid[i], NULL, &func, NULL);
    }
}

void* PthreadPool::func(void* arg)
{
    printf("threadid Ox%x is start...\n", pthread_self());

    while (1) {
        pthread_mutex_lock(&queue_lock);
        while (m_vec.size() == 0 && isshutdown == 0) //如果vec为空则说明没任务，需要继续等待，直到任务添加以后被唤醒
        //while(cur_num==0 && isshutdown==0)
        {
            printf("pthread_cond_wait Ox%x \n", pthread_self());
            pthread_cond_wait(&queue_cond, &queue_lock); //阻塞函数
        }
        if (isshutdown == 1) //如果标志置为退出则结束当前进程
        {
            pthread_mutex_unlock(&queue_lock);
            printf("threadid Ox%x is exit...\n", pthread_self());
            pthread_exit(NULL);
        }
        printf("start to  work 0X%x\n", pthread_self());
        //说明在线程池中有任务可执行了。
        vector<ThreadWork*>::iterator it = m_vec.begin(); //取出任务数组的第一个任务
        --cur_num;
        //ThreadWork* mwork=*(it+cur_num);
        ThreadWork* mwork = new ThreadWork;
        memcpy(mwork, *it, sizeof(ThreadWork));
        m_vec.erase(it);
        pthread_mutex_unlock(&queue_lock); //加锁的粒度需要控制，一般是细点好

        (*(mwork->process))(mwork->arg); //函数指针调用工作函数
        delete mwork;
        mwork = NULL;
    }
}

void PthreadPool::Addwork(void* (*process)(void* arg), void* arg)
{
    ThreadWork* mwork = new ThreadWork;
    mwork->process = process;
    mwork->arg = arg;

    pthread_mutex_lock(&queue_lock);
    m_vec.push_back(mwork);
    ++cur_num;
    pthread_mutex_unlock(&queue_lock);
    pthread_cond_signal(&queue_cond); //添加任务后唤醒线程执行任务。
}

int PthreadPool::DestroyPthread()
{
    if (isshutdown == 1)
        return -1;
    isshutdown = 1;
    pthread_cond_broadcast(&queue_cond); //唤醒所以线程。主要是线程销毁的时候防止错误条件变量函数的阻塞
    for (int i = 0; i < MAX_NUM; i++) {
        pthread_join(threadid[i], NULL);
    }
    delete[] threadid;
    pthread_mutex_destroy(&queue_lock);
    pthread_cond_destroy(&queue_cond);
    return 0;
}
