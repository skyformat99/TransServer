/*=========================================================
 *文件名称:  TransServer.h
 *创建日期：2017-1-24
 *修改记录：
 *  2017-2-17  改进第二个版本中消息队列，改为socket发消息
 *功能描述：
 ===========================================================*/
#ifndef __TRANSSERVER_H_
#define __TRANSSERVER_H_

#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <pthread.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include "PoolSock.h"
#include "Config.h"
#include "Cfifo.h"
#include "WriteLog.h"
#include "HandleBuss.h"

#define LISTENBANKERR  400
#define ALARMERR       401

typedef struct _ProcessId
{
	int num;
	char chilId[4096];
}ProcessId;

int startMain();

int startService(int connfd, int timeout);

void DealSigchild(int num);

void dealTimeOutProcessFunc(int signo);

int recv_Send_NewSecu(void *handle, int connfd, char* inbuf, int inlen, unsigned char **outbuf, int *outlen);

int recv_Send_OldSecu(void *handle, int connfd, char* inbuf, int inlen, unsigned char **outbuf, int *outlen);

#endif

