/*=========================================================
 *文件名称:  WriteLog.h
 *创建日期：2017-1-24
 *修改记录：
 *  2017-1-24  首次创建
 *功能描述：从管道中读取日志内容并将其写入日志文件
 ===========================================================*/
#ifndef __WRITELOG_H_
#define __WRITELOG_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<time.h>
#include "Cfifo.h"

/*=========================================================
 *宏定义
 ===========================================================*/
#define LOGLEVELLEN  1024
#define SYS_LOG     1    //系统日志
#define TRADE_LOG   2    //业务日志
#define INFO_LOG		3	   //信息日志
#define DEBUG_LOG   4    //调式日志
#define ERROR_LOG		5	   //错误日志
#define CORE_LOG		6	   //进程销毁日志
/*=========================================================
 *错误码定义
 ===========================================================*/
#define LOGREADFAIL 20001 
 
 /*=========================================================
 *函数入参:无   
 *函数出参:无
 *返回值:返回当日日期字符串
 *功能说明:获取系统当天日期
 *===========================================================*/
char *Timer();

/*=========================================================
 *函数入参:
 *      level    日志级别  
 *                 SYS_LOG            1      系统日志
 *                 INFO_LOG		        3	     信息日志
 *                 DEBUG_LOG          4      调式日志
 *                 ERROR_LOG	        5      错误日志
 *                 CORE_LOG		        6	     进程销毁日志
 *      log      日志内容     
 *函数出参:无
 *返回值:无
 *功能说明:写系统日志函数
 *===========================================================*/
void WriteSySLog(const int level, char *log);

/*=========================================================
 *函数入参:
 *      log    日志内容  只打业务日志
 *函数出参:无
 *返回值:无
 *功能说明:写业务日志函数
 *===========================================================*/
void WriteTradeLog(char *log);

 /*=========================================================
 *函数入参: 无       
 *函数出参: 无
 *返回值:   成功返回0，失败返回错误号
 *功能说明: 从管道中读取日志
 *===========================================================*/
 int ReadLogFromFifo();
 
 
 #endif