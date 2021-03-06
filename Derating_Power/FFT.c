/*
 * FFT.c
 *
 *  Created on: 2021年10月2日
 *      Author: Lenovo
 */


#include "main.h"

Complex C_add(Complex a,Complex b)
{
	a.real=a.real+b.real;
	a.imag=a.imag+b.imag;

	return a;
}

Complex C_sub(Complex a,Complex b)
{
	a.real=a.real-b.real;
	a.imag=a.imag-b.imag;

	return a;
}

Complex C_mul(Complex a,Complex b)
{
	Complex x={
			.real=a.real*b.real-a.imag*b.imag,
			.imag=a.real*b.imag+a.imag*b.real,
	};

	return x;
}

float C_mod(Complex a)
{
	float f=0;
	f=sqrt(a.real*a.real+a.imag*a.imag);
	return f;
}

//返回x的实虚部实际为模长和角度
Complex FFT(float * a,char opt)			//opt=1,FFT;opt=-1,IFFT
{
	unsigned char dep=0;		//度数
	unsigned char m=0;			//
	unsigned char k=0;			//序号
	unsigned char j=0;			//下标
//	float x=0;
	Complex x={.real=0,.imag=0};
	Complex wn={.real=0,.imag=0};		//单位根
	Complex w={.real=1,.imag=0};

	Complex t={.real=0,.imag=0};		//蝴蝶操作临时变量
	Complex u={.real=0,.imag=0};		//蝴蝶操作临时变量
	Complex b[FFT_Num];
	//位逆序置换
	unsigned char rev[FFT_Num];
	rev[0]=0;
	for(j=0;j<FFT_Num;j++)
	{
		rev[j]=(rev[j>>1]>>1)|((j&1)<<(FFT_len-1));
	}
	for(j=0;j<FFT_Num;j++)
	{
		b[j].real=a[j];
		b[j].imag=0;
	}
	for(j=0;j<FFT_Num;j++)
	{
		if(j<rev[j])
		{
			t=b[j];
			b[j]=b[rev[j]];
			b[rev[j]]=t;
		}
	}

	for(dep=1;dep<=FFT_len;dep++)
	{
		m=1<<dep;
		wn.real=cos(2.0*PI/m);
		wn.imag=-sin(2.0*PI/m)*opt;
		for(k=0;k<FFT_Num;k+=m)
		{
			w.real=1;
			w.imag=0;
			for(j=0;j<m/2;j++)
			{
				t=C_mul(w,b[k+j+m/2]);
				u=b[k+j];

				b[k+j]=C_add(u, t);
				b[k+j+m/2]=C_sub(u,t);
				w=C_mul(w,wn);
			}
		}
	}
	if(opt==-1)
	{
		for(j=0;j<FFT_Num;j++)
		{
			b[j].real/=FFT_Num;
		}
	}

	x.real=C_mod(b[FFT_base])/FFT_Num;
	if(b[FFT_base].imag==0)
	{
		if(b[FFT_base].real==0)
			x.imag=0;
		else if(b[FFT_base].real>0)
			x.imag=PI/2;
		else
			x.imag=-PI/2;
	}
	else
	{
		x.imag=atan(b[FFT_base].imag/b[FFT_base].real);
	}
	if((b[FFT_base].real<0)&&(b[FFT_base].imag<0))
		x.imag=x.imag-PI;
	if((b[FFT_base].real<0)&&(b[FFT_base].imag>=0))
		x.imag=x.imag+PI;
	return x;
}
