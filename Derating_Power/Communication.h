/*
 * Communication.h
 * 	֡ͷ:0xBE
 *	֡���ͣ�data/cmd
 *	֡����
 *	����/ָ��
 *	֡β:0xED
 *	У�飺LRC
 *
 *  Created on: 2021��7��7��
 *      Author: Lenovo
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "main.h"

#define BUFFER_SIZE			(16)		//��������С

#define CMNCTION_HEAD		(0xBE)		//֡ͷ
#define CMNCTION_TAIL		(0xED)		//֡β
#define CMNCTION_DATA		(0xDA)		//֡��������Ϊ����
#define CMNCTION_CMD		(0xCD)		//֡��������Ϊָ��

#define CMNCTION_ERR_TYPE	(0xE0)		//���ͳ���
#define CMNCTION_ERR_LEN	(0xE1)		//֡������
#define CMNCTION_ERR_TAIL	(0xE2)		//֡β����
#define CMNCTION_ERR_LRC	(0xE3)		//У�����

typedef struct
{
	unsigned char Head;					//֡ͷ:0xBE
	unsigned char Type;					//֡����
	unsigned char Len;					//���ݳ���
	unsigned char Data[BUFFER_SIZE];	//����/ָ��
	unsigned char Tail;					//֡β:0xED
	unsigned char LRC;					//У��
}CMNCTION;

extern CMNCTION CMNCT_rxbuff;
extern CMNCTION CMNCT_txbuff;

unsigned char Calc_LRC(unsigned char * data, unsigned char len);
void Communication_CMD(unsigned char cmd);

#endif /* COMMUNICATION_H_ */
