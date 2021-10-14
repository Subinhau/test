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
#include "Communication.h"

#define PI		(3.14159)

typedef struct{
	float real;
	float imag;
}Complex;		//复数类型

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

extern float I_sample[2];
extern float V_sample[2];
extern Source S;
extern unsigned char Matching_Word[3];

#endif /* MAIN_H_ */
