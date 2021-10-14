/*
 * main.h
 *
 *  Created on: 2021年5月12日
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
	float Po;		//输出功率			(W)
	float f;		//输出频率			(Hz)
	float omg;		//角频率
	float Vdc;		//输入直流电压		(V)
	float Rs;		//输入电阻			(欧)
	float Rl;		//输出电阻			（欧）
	float Gs;		//输入电导			（S）
	float Gl;		//输出电导			(S)
	float k;		//电导比=Rl/Rs

}Source;		//电源信息

struct CAP{
//	float V;		//采样电压			(V)
//	float I;		//采样电流			(I)
//	float f;		//采样到的频率		(kHz)
//	float Ph;		//相位差			(度)
	Complex Z;		//阻抗
};		//采样信息


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
