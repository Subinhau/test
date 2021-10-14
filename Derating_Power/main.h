/*
 * main.h
 *
 *  Created on: 2021��5��12��
 *      Author: Lenovo
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "DSP281x_Device.h"
#include "DSP281x_Examples.h"
#include <string.h>
#include <math.h>

#include "Matching.h"
//#include "Communication.h"
#include "FFT.h"

#define PI		(3.1415926535)

#define Tao_lim	(0.2)

typedef struct {
	float Po;		//�������			(W)
	float f;		//���Ƶ��			(Hz)
	float omg;		//��Ƶ��
	float Vdc;		//����ֱ����ѹ		(V)
	float Rs;		//�������			(ŷ)
	float Rl;		//�������			��ŷ��
	float Gs;		//����絼			��S��
	float Gl;		//����絼			(S)
	float k;		//�絼��=Rl/Rs

}Source;		//��Դ��Ϣ

struct CAP{
//	float V;		//������ѹ			(V)
//	float I;		//��������			(I)
//	float f;		//��������Ƶ��		(kHz)
//	float Ph;		//��λ��			(��)
	Complex Z;		//�迹
};		//������Ϣ


extern unsigned char ADC_flag;
extern float Data[2][FFT_Num];
extern unsigned int Data_int0[FFT_Num];
extern unsigned int Data_int1[FFT_Num];
//extern unsigned int *Data_int0;
//extern unsigned int *Data_int1;
//extern unsigned int I_sample[FFT_Num];
//extern unsigned int V_sample[FFT_Num];
extern Source S;
extern struct CAP CapValue;
extern unsigned char Matching_Word[3];
//extern int Phase_Time[2][2];

#endif /* MAIN_H_ */
