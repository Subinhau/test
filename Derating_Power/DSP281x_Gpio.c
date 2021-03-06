// TI File $Revision: /main/2 $
// Checkin $Date: April 29, 2005   11:10:14 $
//###########################################################################
//
// FILE:	DSP281x_Gpio.c
//
// TITLE:	DSP281x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP281x C/C++ Header Files V1.20 $
// $Release Date: July 27, 2009 $
//###########################################################################

#include "main.h"

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known state.
//
void InitGpio(void)
{

     EALLOW;
     //PWM
     GpioMuxRegs.GPAMUX.all=0x000F;		// GPA0-3复用为PWM1-4
     GpioMuxRegs.GPADIR.all=0x001F;    	// GPA0-3设置为输出,GPA4设置为输出
     GpioMuxRegs.GPAQUAL.all=0x0000;	// Input qualifier disabled
     //Matching
     GpioMuxRegs.GPBMUX.all=0x0000;		// 作GPIO
     GpioMuxRegs.GPBDIR.all=0xFFFF;		// 0-7数据位，8-wr,9-A0,10-A1,11-CS,12-RD
     GpioMuxRegs.GPBQUAL.all=0x0000;
     //SCI
     GpioMuxRegs.GPFMUX.bit.SCITXDA_GPIOF4 = 1;		//设置SCIA发送引脚
     GpioMuxRegs.GPFMUX.bit.SCIRXDA_GPIOF5 = 1;		//设置SCIA接收引脚

     EDIS;
     GpioDataRegs.GPASET.bit.GPIOA4=1;				//保护开启
}	
	
//===========================================================================
// No more.
//===========================================================================
