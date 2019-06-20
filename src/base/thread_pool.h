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

#ifndef _PTHREADPOOL_H_
#define _PTHREADPOOL_H_

#include <iostream>
#include <map>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>
#include "base/uncopyable.h"

#define MAX_NUM 3

using namespace std;

//存放具体任务
typedef struct work {
    void* (*process)(void* arg);
    void* arg;
} ThreadWork;

class PthreadPool : public uncopyable {
public:
    void Pthreadinit();
    void Addwork(void* (*process)(void* arg), void* arg); //向线程中添加任务
    int DestroyPthread();
    static void* func(void* arg); //线程中调用的回调函数
    static void* myprocess(void* arg); //具体工作的函数

private:
    static pthread_mutex_t queue_lock;
    static pthread_cond_t queue_cond;
    static vector<ThreadWork*> m_vec; //任务数组
    static int cur_num; //当前任务数，操作这个变量也可以取代对vector的大小判断。
    static pthread_t* threadid; //线程句柄
    static int isshutdown; //线程是否销毁描述符，0 正常，1 销毁
};

#endif
