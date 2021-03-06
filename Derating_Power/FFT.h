/*
 * FFT.h
 *
 *  Created on: 2021年10月2日
 *      Author: Lenovo
 */

#ifndef FFT_H_
#define FFT_H_

#define FFT_Num		(32)
#define FFT_len		(5)
#define FFT_base	(4)		//32*100k/800k

typedef struct{
	float real;
	float imag;
}Complex;		//复数类型

Complex C_add(Complex a,Complex b);
Complex C_sub(Complex a,Complex b);
Complex C_mul(Complex a,Complex b);
float C_mod(Complex a);

Complex FFT(float * a,char opt);

#endif /* FFT_H_ */
