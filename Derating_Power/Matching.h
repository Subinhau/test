/*
 * Matching.h
 *
 *  Created on: 2021��7��5��
 *      Author: Lenovo
 */

#ifndef MATCHING_H_
#define MATCHING_H_

#include "main.h"

//���ſ���
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

//ƽ�淨����
//#define Li_delta	(0.00024798)		//Liƽ������
//#define Rl_delta	(199)				//�����迹�仯
#define Li_k		(0.0000012461)			//Liƽ��б��
#define Lii_k		(0.0000017296)			//Liiƽ��б��
#define Rl_min		(1)						//�����迹��Сֵ
#define Li_min		(0.00005074)			//Li����Сֵ
#define Li_unit 	(2.3708)				//Li����ֵ
#define Lii_unit	(2.7317)				//Lii����ֵ
#define Cd_unit		(716280)				//Cd����ֵ

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
