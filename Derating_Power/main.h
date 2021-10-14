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
#include "Communication.h"

#define PI		(3.14159)

typedef struct{
	float real;
	float imag;
}Complex;		//��������

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

extern float I_sample[2];
extern float V_sample[2];
extern Source S;
extern unsigned char Matching_Word[3];

#endif /* MAIN_H_ */
