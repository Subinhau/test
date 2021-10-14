#include "Matching.h"

const float Li_Z[8]={0, 2.2, 4.7, 9.4, 18.3, 37.7, 78, 147};				//uH
const float Lii_Z[8]={13.3, 2.2, 5.5, 10, 22, 44, 90, 168};					//uH
//const float C_Z[8]={220, 1400, 698, 348, 176, 86, 43.7, 22};				//nF
const float Cd_Z[8]={4545000, 714000, 1433000, 2874000, 5682000, 11628000, 22883000, 45455000};

void delay_20ns(unsigned char t)
{
//��ʱ������ʱ��Ϊ150M��һ������Ϊ6.66��������,3������Ϊ20ns

	for(;t>0;t--)
	{
		asm(" NOP");
		asm(" NOP");
		asm(" NOP");
	}
}

void Matching_init()
{
	//��ʼ��8255оƬ

	GpioDataRegs.GPBDAT.all = 0xFF80;	//RD|CS|A1|A0|WR||ģʽ����	| A�飺ģʽѡ��	| PORTA 	| C�϶� 	| B�飺ģʽѡ�� 	|PORTB| C�¶� 	|
										// 1| 1| 1| 1| 1||   1 |    00    	|  0  		|  0  	|       0   |  0  |  0  	|
//	Matching_CS_H;		//�ر�8255AƬѡ
//	Matching_RD_H;		//�ر�8255A������
//	Matching_WR_H;		//�ر�8255Aд����
//	Matching_A0_H;		//����ģʽ
//	Matching_A1_H;
	Matching_CS_L;		//��Ƭѡ
//	Rs=1;		//��λ
//	Rs=0;

	Matching_WR_L;		//д��
	delay_20ns(10);
	Matching_WR_H;
	delay_20ns(3);

	GpioDataRegs.GPBDAT.all = 0x10FF;	//RD|CS|A1|A0|WR||7-0
										// 1| 0| 0| 0| 0||0xFF
//	A0=0;		//дPORTA
//	A1=0;
//	Wr=0;		//д
	delay_20ns(10);
	Matching_WR_H;
	delay_20ns(3);

	Matching_A0_H;		//дPORTB
//	A1=0;
	delay_20ns(3);
	Matching_WR_L;		//д
	delay_20ns(10);
	Matching_WR_H;
	delay_20ns(3);

	Matching_A0_L;		//дPORTC
	Matching_A1_H;
	delay_20ns(3);
	Matching_WR_L;		//д
	delay_20ns(10);
	Matching_WR_H;
	delay_20ns(3);
}

void Matching(unsigned char *data)
{
	//����8255оƬ�����

	GpioDataRegs.GPBDAT.all = 0xEF00^(~data[0]);
	//RD|CS|A1|A0|WR||7-0
	// 1| 0| 0| 0| 0||0x00
//	A0=0;		//дPORTA
//	A1=0;
//	Wr=0;		//д
	delay_20ns(8);
	Matching_WR_H;
	delay_20ns(2);

	GpioDataRegs.GPBDAT.all = 0xED00^(~data[1]);
	//RD|CS|A1|A0|WR||7-0
	// 1| 0| 0| 1| 0||0x00
//	Matching_A0_H;		//дPORTB
//	A1=0;
	Matching_WR_L;		//д
	delay_20ns(8);
	Matching_WR_H;
	delay_20ns(2);

	GpioDataRegs.GPBDAT.all = 0xEB00^(~data[2]);
	//RD|CS|A1|A0|WR||7-0
	// 1| 0| 1| 0| 0||0x00
	Matching_A0_L;		//дPORTC
	Matching_A1_H;
	Matching_WR_L;		//д
	delay_20ns(8);
	Matching_WR_H;
	delay_20ns(2);
}

//����Ĳ�����ɢ��
void MatchingDigital(MATCHING * mat)
{
	unsigned char i=0;
	float l1=0;
	float l2=0;
	float cd=0;

	mat->Li_word=(unsigned char)((mat->Li*1000000-Li_Z[0])/Li_unit);
	mat->Lii_word=(unsigned char)((mat->Lii*1000000-Lii_Z[0])/Lii_unit);
	mat->C_word=(unsigned char)((mat->Cd-Cd_Z[0])/Cd_unit);

	mat->Li_word=(mat->Li_word<<1)+1;
	mat->Lii_word=(mat->Lii_word<<1)+1;
	mat->C_word=(mat->C_word<<1)+1;

	for(i=0;i<8;i++)
	{
		if(((mat->Li_word)>>i) & 0x0001)
		{
//			mat->Li+=Li_Z[i];
			l1+=Li_Z[i];
		}
		if(((mat->Lii_word)>>i) & 0x0001)
		{
//			mat->Lii+=Lii_Z[i];
			l2+=Lii_Z[i];
		}
		if(((mat->C_word)>>i) & 0x0001)
		{
//			mat->Cd+=Cd_Z[i];
			cd+=Cd_Z[i];
		}
	}
//	mat->C=1/mat->Cd;
	l1-=(mat->Li*1000000);
	l2-=(mat->Lii*1000000);
	cd-=mat->Cd;

	mat->delta=abs((l1)/Li_unit)+abs((l2)/Lii_unit)+abs((cd)/Cd_unit);
}

//��ƽ�淨����ƥ��
//����ӿڣ��趨Դ�迹�������迹
//����ӿڣ����������Ŀ�����
void PMF()		//float Rs, float Rl
{
//	unsigned char flag=0;
	float l1=0;
	float l2=0;
//	float Q0=0;
	float Q1=0;
	float Q2=0;
	float dt1=0;
	float dt2=0;
//	float OmgL1G1_OmgL2G2=0;
//	float SqrtOmgLG=0;
//	float SqrtK=0;

	MATCHING mat1={
		.Q0=0,
		.Li=0,
		.Lii=0,
//		.C=0,
		.wlg=0,
		.Cd=0,
		.Li_word=0,
		.Lii_word=0,
		.C_word=0,
		.delta=3,
	};
	MATCHING mat2={
		.Q0=0,
		.Li=0,
		.Lii=0,
//		.C=0,
		.wlg=0,
		.Cd=0,
		.Li_word=0,
		.Lii_word=0,
		.C_word=0,
		.delta=3,
	};

	//��Li��
	l1=Li_k*(S.Rl-Rl_min)+Li_min;
//	Q0=((S.k-1)*((S.omg*l1*S.Gs*sqrt((S.omg*l1*S.Gs)*(S.omg*l1*S.Gs)+1-S.k))-(sqrt(S.k))))/(2*((S.k*sqrt((S.omg*l1*S.Gs)*(S.omg*l1*S.Gs)+1-S.k))-(sqrt(S.k)*S.omg*l1*S.Gs)));
	mat1.wlg=S.omg*l1*S.Gs;
	dt1=mat1.wlg*mat1.wlg/S.k+1/S.k-1;

	if(dt1>=0)
	{
		mat1.Q0=0.5*(mat1.wlg+sqrt(dt1));
		if(S.Gs>S.Gl)
		{
			Q1=(2*mat1.Q0*S.Gs-sqrt(4*mat1.Q0*mat1.Q0*S.Gs*S.Gl-(S.Gs-S.Gl)*(S.Gs-S.Gl)))/(S.Gs-S.Gl);
			Q2=2*mat1.Q0-Q1;
		}
		else if(S.Gs<S.Gl)
		{
			Q2=(2*mat1.Q0*S.Gl-sqrt(4*mat1.Q0*mat1.Q0*S.Gs*S.Gl-(S.Gl-S.Gs)*(S.Gl-S.Gs)))/(S.Gl-S.Gs);
			Q1=2*mat1.Q0-Q2;
		}
		else
		{
			Q1=mat1.Q0;
			Q2=mat1.Q0;
		}
		mat1.Li=Q1/(S.omg*S.Gs);
		mat1.Lii=Q2/(S.omg*S.Gl);
//		mat1.C=(2*Q0*S.Gs)/(S.omg*(1+Q1*Q1));
		mat1.Cd=(S.omg*(1+Q1*Q1))/(2*mat1.Q0*S.Gs);

		MatchingDigital(&mat1);
	}

	//��Lii��
	l2=Lii_k*(S.Rl-Rl_min)+Lii_Z[0]/1000000;
//	Q0=((1-S.k)*((S.omg*l2*S.Gl*sqrt((S.omg*l2*S.Gl)*(S.omg*l2*S.Gl)*S.k+S.k-1))-1))/(2*((sqrt((S.omg*l2*S.Gl)*(S.omg*l2*S.Gl)*S.k+S.k-1))-(S.k*S.omg*l2*S.Gl)));
	mat2.wlg=S.omg*l2*S.Gl;
	dt2=S.k*mat2.wlg*mat2.wlg+S.k-1;
	if(dt2>=0)
	{
		mat2.Q0=0.5*(mat2.wlg+sqrt(dt2));
		if(S.Gs>S.Gl)
		{
			Q1=(2*mat2.Q0*S.Gs-sqrt(4*mat2.Q0*mat2.Q0*S.Gs*S.Gl-(S.Gs-S.Gl)*(S.Gs-S.Gl)))/(S.Gs-S.Gl);
			Q2=2*mat2.Q0-Q1;
		}
		else if(S.Gs<S.Gl)
		{
			Q2=(2*mat2.Q0*S.Gl-sqrt(4*mat2.Q0*mat2.Q0*S.Gs*S.Gl-(S.Gl-S.Gs)*(S.Gl-S.Gs)))/(S.Gl-S.Gs);
			Q1=2*mat2.Q0-Q2;
		}
		else
		{
			Q1=mat2.Q0;
			Q2=mat2.Q0;
		}
		mat2.Li=Q1/(S.omg*S.Gs);
		mat2.Lii=Q2/(S.omg*S.Gl);
//		mat2.C=(2*Q0*S.Gs)/(S.omg*(1+Q1*Q1));
		mat2.Cd=(S.omg*(1+Q1*Q1))/(2*mat2.Q0*S.Gs);

		MatchingDigital(&mat2);
	}

	if(mat1.delta<=mat2.delta)
	{
		Matching_Word[0]=mat1.Li_word;
		Matching_Word[1]=mat1.Lii_word;
		Matching_Word[2]=mat1.C_word;
	}
	else
	{
		Matching_Word[0]=mat2.Li_word;
		Matching_Word[1]=mat2.Lii_word;
		Matching_Word[2]=mat2.C_word;
	}

	return;
}
