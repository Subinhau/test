/*
 * Communication.c
 *
 *  Created on: 2021年7月7日
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
};								//接收缓冲
CMNCTION CMNCT_txbuff={
	.Head = CMNCTION_HEAD,
	.Type = CMNCTION_CMD,
	.Len = 0,
	.Data = "012345678912345",
	.Tail = CMNCTION_TAIL,
	.LRC = 0,
};								//发送缓冲

// 校验
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

//发送指令
void Send_CMD(unsigned char cmd)
{
	CMNCT_txbuff.Type = CMNCTION_CMD;
	CMNCT_txbuff.Len = 1;
	CMNCT_txbuff.Data[0] = cmd;
	CMNCT_txbuff.Data[1] = CMNCTION_TAIL;
	CMNCT_txbuff.LRC = Calc_LRC((unsigned char *)(&CMNCT_txbuff),CMNCT_txbuff.Len+4);

	SciaRegs.SCICTL1.bit.TXENA = 1;			//SCIA模块发送使能
	SciaRegs.SCIFFTX.bit.TXINTCLR = 1;		//清除发送中断标志位，使其响应新中断
}

void Send_Data(struct CAP * capdata)
{
	unsigned int temp =0;

	//保留两位小数，化为整形通信
	CMNCT_txbuff.Type = CMNCTION_DATA;
	CMNCT_txbuff.Len = 8;

	temp=(unsigned int )(capdata->V*100);
	CMNCT_txbuff.Data[0] = temp>>8;
	CMNCT_txbuff.Data[1] = temp & 0x00FF;
	temp=(unsigned int )(capdata->I*100);
	CMNCT_txbuff.Data[2] = temp>>8;
	CMNCT_txbuff.Data[3] = temp & 0x00FF;
	temp=(unsigned int )(capdata->f*100);
	CMNCT_txbuff.Data[4] = temp>>8;
	CMNCT_txbuff.Data[5] = temp & 0x00FF;
	temp=(unsigned int )(capdata->Ph*100);
	CMNCT_txbuff.Data[6] = temp>>8;
	CMNCT_txbuff.Data[7] = temp & 0x00FF;
	CMNCT_txbuff.LRC = Calc_LRC((unsigned char *)(&CMNCT_txbuff),CMNCT_txbuff.Len+4);

	SciaRegs.SCICTL1.bit.TXENA = 1;			//SCIA模块发送使能
	SciaRegs.SCIFFTX.bit.TXINTCLR = 1;		//清除发送中断标志位，使其响应新中断
}

