#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

/**
参考：https://www.cnblogs.com/wblyuyang/archive/2012/11/13/2768923.html
在这个例程中使用 sigaction 函数为 SIGUSR1 和 SIGUSR2 信号注册了处理函数，然后从标准输入读入字符
**/


/**
程序运行后首先输出自己的 PID，如：
　My PID is 5904
 
这时如果从另外一个终端向进程发送 SIGUSR1 或 SIGUSR2 信号，用类似如下的命令：
　kill -USR1 5904

则程序将继续输出如下内容：
 SIGUSR1 received
 read is interrupted by signal

**/

static void sig_usr(int signum)
{
    if(signum == SIGUSR1)
    {
        printf("SIGUSR1 received\n");
    }
    else if(signum == SIGUSR2)
    {
        printf("SIGUSR2 received\n");
    }
    else
    {
        printf("signal %d received\n", signum);
    }
}

int main(void)
{
    char buf[512];
    int  n;
    struct sigaction sa_usr;
    sa_usr.sa_flags = 0;
    sa_usr.sa_handler = sig_usr;   //信号处理函数
    
    sigaction(SIGUSR1, &sa_usr, NULL);
    sigaction(SIGUSR2, &sa_usr, NULL);
    
    printf("My PID is %d\n", getpid());
    
    while(1)
    {
        if((n = read(STDIN_FILENO, buf, 511)) == -1)
        {
            if(errno == EINTR)
            {
                printf("read is interrupted by signal\n");
            }
        }
        else
        {
            buf[n] = '\0';
            printf("%d bytes read: %s\n", n, buf);
        }
    }
    
    return 0;
}
