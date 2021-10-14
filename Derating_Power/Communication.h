/*
 * Communication.h
 * 	帧头:0xBE
 *	帧类型：data/cmd
 *	帧长度
 *	数据/指令
 *	帧尾:0xED
 *	校验：LRC
 *
 *  Created on: 2021年7月7日
 *      Author: Lenovo
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "main.h"

#define BUFFER_SIZE			(16)		//缓冲区大小

#define CMNCTION_HEAD		(0xBE)		//帧头
#define CMNCTION_TAIL		(0xED)		//帧尾
#define CMNCTION_DATA		(0xDA)		//帧数据类型为数据
#define CMNCTION_CMD		(0xCD)		//帧数据类型为指令

#define CMNCTION_ERR_TYPE	(0xE0)		//类型出错
#define CMNCTION_ERR_LEN	(0xE1)		//帧长出错
#define CMNCTION_ERR_TAIL	(0xE2)		//帧尾出错
#define CMNCTION_ERR_LRC	(0xE3)		//校验出错

typedef struct
{
	unsigned char Head;					//帧头:0xBE
	unsigned char Type;					//帧类型
	unsigned char Len;					//数据长度
	unsigned char Data[BUFFER_SIZE];	//数据/指令
	unsigned char Tail;					//帧尾:0xED
	unsigned char LRC;					//校验
}CMNCTION;

extern CMNCTION CMNCT_rxbuff;
extern CMNCTION CMNCT_txbuff;

unsigned char Calc_LRC(unsigned char * data, unsigned char len);
void Communication_CMD(unsigned char cmd);

#endif /* COMMUNICATION_H_ */
