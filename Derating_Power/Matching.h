/*
 * Matching.h
 *
 *  Created on: 2021年7月5日
 *      Author: Lenovo
 */

#ifndef MATCHING_H_
#define MATCHING_H_

#include "main.h"

//引脚控制
#define Matching_WR_H	GpioDataRegs.GPBSET.bit.GPIOB8=1
#define Matching_WR_L	GpioDataRegs.GPBCLEAR.bit.GPIOB8=1
#define Matching_A0_H	GpioDataRegs.GPBSET.bit.GPIOB9=1
#define Matching_A0_L	GpioDataRegs.GPBCLEAR.bit.GPIOB9=1
#define Matching_A1_H	GpioDataRegs.GPBSET.bit.GPIOB10=1
#define Matching_A1_L	GpioDataRegs.GPBCLEAR.bit.GPIOB10=1
#define Matching_CS_H	GpioDataRegs.GPBSET.bit.GPIOB11=1
#define Matching_CS_L	GpioDataRegs.GPBCLEAR.bit.GPIOB11=1
#define Matching_RD_H	GpioDataRegs.GPBSET.bit.GPIOB12=1
#define Matching_RD_L	GpioDataRegs.GPBCLEAR.bit.GPIOB12=1

//平面法计算
//#define Li_delta	(0.00024798)		//Li平面上升
//#define Rl_delta	(199)				//负载阻抗变化
#define Li_k		(0.0000012461)			//Li平面斜率
#define Lii_k		(0.0000017296)			//Lii平面斜率
#define Rl_min		(1)						//负载阻抗最小值
#define Li_min		(0.00005074)			//Li的最小值
#define Li_unit 	(2.3708)				//Li步进值
#define Lii_unit	(2.7317)				//Lii步进值
#define Cd_unit		(716280)				//Cd步进值

typedef struct {
	float Q0;
	float wlg;
	float Li;
	float Lii;
//	float C;
	float Cd;
	unsigned char Li_word;
	unsigned char Lii_word;
	unsigned char C_word;
	float delta;
}MATCHING;

void Matching_init();
void Matching(unsigned char *data);
void PMF();

#endif /* MATCHING_H_ */
