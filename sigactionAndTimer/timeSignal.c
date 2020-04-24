/**
 链接(librt)
 gcc time.c -o time -lrt
**/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
 
#define CLOCKID CLOCK_REALTIME
 
struct timeval tv_start;
struct timeval tv_end;
double tv_diff_first = 0.;
double tv_diff_last = 0.;
double tv_diff_max = 0.;
double tv_diff = 0.;
int    first_test = 0;
timer_t timerid;
int timeout_cnt = 0;
int all_cnt = 0;


static double MaxValue(double m_dest,double m_src)
{
    if(m_dest > m_src){
        return m_dest;
    } else{
        return m_src;
    }
}


void sig_handler(int signo)
{ 
    
    gettimeofday(&tv_end,NULL);

    printf("接收到定时器信号值： %d    ", signo);

 

    tv_diff_first = (double)(tv_end.tv_sec*1000000 + tv_end.tv_usec) - (double)(tv_start.tv_sec*1000000 + tv_start.tv_usec);


    
    
    tv_diff = abs(tv_diff_first - tv_diff_last); 
    if(tv_diff > 1000*1000) //1s
    {
	tv_diff = 0;
    }
    tv_diff_max = MaxValue(tv_diff_max,tv_diff);
    printf("\033[36;45m 总次数：%d  超过200us次数：%d  定时器误差最大值:%lf \033[0m \n,",all_cnt,timeout_cnt,tv_diff_max);
    
    
    if(tv_diff > 200.0)
    {
	timeout_cnt++;
	//timer_delete(timerid);
	//return;
    }
    
    
    gettimeofday(&tv_start,NULL);

    tv_diff_last = tv_diff_first;

    all_cnt++;
}
 

int main()
{
	//XXX int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
	// signum--指定的信号编号，可以指定SIGKILL和SIGSTOP以外的所有信号编号
	// act结构体--设置信号编号为signum的处理方式
	// oldact结构体--保存上次的处理方式
	//
	// struct sigaction 
	// {
	// void (*sa_handler)(int);			//信号响应函数地址
	// void (*sa_sigaction)(int, siginfo_t *, void *);   //但sa_flags为SA——SIGINFO时才使用
	// sigset_t sa_mask;         //说明一个信号集在调用捕捉函数之前，会加入进程的屏蔽中，当捕捉函数返回时，还原
	// int sa_flags;
	// void (*sa_restorer)(void);	//未用
	// };
	//
	timer_t timerid;
	struct sigevent evp;
 
	struct sigaction act;
	memset(&act, 0, sizeof(act));
	act.sa_handler = sig_handler;
	act.sa_flags = 0;
 
	// XXX int sigaddset(sigset_t *set, int signum);  //将signum指定的信号加入set信号集
	// XXX int sigemptyset(sigset_t *set);			//初始化信号集
	
	sigemptyset(&act.sa_mask);
 
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		perror("fail to sigaction");
		exit(-1);
	}
 
	memset(&evp, 0, sizeof(struct sigevent));
	evp.sigev_signo = SIGUSR2;
	evp.sigev_notify = SIGEV_SIGNAL;
	if (timer_create(CLOCK_REALTIME, &evp, &timerid) == -1)
	{
		perror("fail to timer_create");
		exit(-1);
	}
 
	struct itimerspec it;
	it.it_interval.tv_sec = 0;
	it.it_interval.tv_nsec = 1000*1000*5;
	it.it_value.tv_sec = 0;
	it.it_value.tv_nsec = 1000*1000*5;
	if (timer_settime(timerid, 0, &it, 0) == -1)
	{
		perror("fail to timer_settime");
		exit(-1);
	}
 
	//pause();
 
	while(1)
	{
		usleep(1000);
	}
	return 0;
}
