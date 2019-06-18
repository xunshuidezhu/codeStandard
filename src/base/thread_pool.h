#ifndef _PTHREADPOOL_H_
#define _PTHREADPOOL_H_

#include <iostream>
#include <map>
#include <string.h>
#include <unistd.h>
#include <vector>

#define MAX_NUM 3

using namespace std;

//Žæ·ÅŸßÌåÈÎÎñ
typedef struct work {
    void* (*process)(void* arg);
    void* arg;
} ThreadWork;

class PthreadPool {
public:
    void Pthreadinit();
    void Addwork(void* (*process)(void* arg), void* arg); //ÏòÏß³ÌÖÐÌíŒÓÈÎÎñ
    int DestroyPthread();
    void foo();
    static void* func(void* arg); //Ïß³ÌÖÐµ÷ÓÃµÄ»Øµ÷º¯Êý
    static void* myprocess(void* arg); //ŸßÌå¹€×÷µÄº¯Êý

private:
    static pthread_mutex_t queue_lock;
    static pthread_cond_t queue_cond;
    static vector<ThreadWork*> m_vec; //ÈÎÎñÊý×é
    static int cur_num; //µ±Ç°ÈÎÎñÊý£¬²Ù×÷Õâžö±äÁ¿Ò²¿ÉÒÔÈ¡Žú¶ÔvectorµÄŽóÐ¡ÅÐ¶Ï¡£
    static pthread_t* threadid; //Ïß³ÌŸä±ú
    static int isshutdown; //Ïß³ÌÊÇ·ñÏú»ÙÃèÊö·û£¬0 Õý³££¬1 Ïú»Ù
};
void PthreadPool::foo()
{
    cout << " pthread Pool is start" << endl;
}
#endif