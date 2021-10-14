/*
 * Communication.c
 *
 *  Created on: 2021��7��7��
 *      Author: Lenovo
 */
#include "Communication.h"

CMNCTION CMNCT_rxbuff={
	.Head = CMNCTION_HEAD,
	.Type = CMNCTION_DATA,
	.Len = 0,
	.Data = "012345678912345",
	.Tail = CMNCTION_TAIL,
	.LRC = 0,
};								//���ջ���
CMNCTION CMNCT_txbuff={
	.Head = CMNCTION_HEAD,
	.Type = CMNCTION_CMD,
	.Len = 0,
	.Data = "012345678912345",
	.Tail = CMNCTION_TAIL,
	.LRC = 0,
};								//���ͻ���

unsigned char Calc_LRC(unsigned char* data, unsigned char len)
{
	unsigned char lrc=0;
	unsigned char i=0;

	for (i=0;i<len;i++)
	{
		lrc^=data[i];
	}

	return lrc;		//~lrc+1;
}

void Communication_CMD(unsigned char cmd)
{
	CMNCT_txbuff.Type = CMNCTION_CMD;
	CMNCT_txbuff.Len = 1;
	CMNCT_txbuff.Data[0] = cmd;
	CMNCT_txbuff.Data[1] = CMNCTION_TAIL;
	CMNCT_txbuff.LRC = Calc_LRC((unsigned char *)(&CMNCT_txbuff),CMNCT_txbuff.Len+4);

	SciaRegs.SCIFFTX.bit.TXINTCLR = 1;		//��������жϱ�־λ��ʹ����Ӧ���ж�
}

