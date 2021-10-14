/*
 * main.c
 * ����һ��100kHz��PWM����
 * PWM1			PWM2
 * PWM4			PWM3
 */

#include "main.h"

float I_sample[2]={0,0};
float V_sample[2]={0,0};
unsigned char Matching_Word[3]={0xFF,0xFF,0xFF};
Source S={
	.Po=0,
	.f=100000,
	.omg=2*PI*100000,
	.Vdc=48,
	.Rs=50,
	.Rl=150,
	.Gs=0.01,
	.Gl=0.005,
	.k=2,
};

void Set_Source(Source * S)
{
	S->omg=2*PI*S->f;

	S->Gs=1/S->Rs;
	S->Gl=1/S->Rl;

	S->k=S->Gs/S->Gl;
}


void init_eva(void)
{
//	EvaRegs.GPTCONA.bit.T1TOADC=3;		//�Ƚ��ж�����ADC
	EvaRegs.EVAIMRA.bit.T1UFINT=1;		//ʹ�ܶ�ʱ��T1�����ж�
	EvaRegs.EVAIFRA.bit.T1UFINT=1;		//�����ʱ��T1�����жϱ�־λ
	EvaRegs.EVAIMRA.bit.T1CINT=1;		//ʹ�ܶ�ʱ��T1�Ƚ��ж�
	EvaRegs.EVAIFRA.bit.T1CINT=1;		//�����ʱ��T1�Ƚ��жϱ�־λ

	EvaRegs.T1CMPR=186;					//����T1�Ƚ�ֵΪ�ķ�֮һ����

	EvaRegs.T1CON.all = 0xF04F;
	//bit 15-14:		11		���������Ӱ��
	//bit 13:			1		����
	//bit 12-11:		10		��������ģʽ
	//bit 10-8:			000		ʱ��Ԥ���꣬ʱ��ԴƵ��/1
	//bit 7:			0		T1T2��ͬ��
	//bit 6:			1		��ʱ��ʹ��
	//bit 5-4:			00		ѡ��ʱ��ԴΪHSPCLK
	//bit 3-2��			11		��ʱ���ȽϼĴ�����������������
	//bit 1:			1		��ʱ���Ƚ�ʹ��
	//bit 0:			1		T1CON�и�λ����

	EvaRegs.T1PR = 750-1;				// Timer1 period 100kHz,75M/1/100k=750
	EvaRegs.T1CNT = 0x0000;      	// Timer1 counter

	EvaRegs.COMCONA.all = 0x837B;
	//bit 15:		1		ʹ�ܱȽ�
	//bit 14-13:	00		T1CNT=0ʱCMPRx����
	//bit 12:		0		��ֹSVPWMģʽ
	//bit 11-10:	00		��Ϊ���ƼĴ�������������T1CNT=0
	//bit 9:		1		ȫ�Ƚ������ʹ��
	//bit 8:		1		ֻ������
	//bit 7:		0		ȫ�Ƚ���3�����ʹ��
	//bit 6:		1		ȫ�Ƚ���2���ʹ��
	//bit 5:		1		ȫ�Ƚ���1���ʹ��
	//bit 4-3:		11		����
	//bit 2:		0		ȫ�Ƚ���3�����ʹ��
	//bit 1:		1		ȫ�Ƚ���2���ʹ��
	//bit 0:		1		ȫ�Ƚ���1���ʹ��
	EvaRegs.ACTRA.all = 0x0066;
	//bit 15:		0		�ռ�ʸ��PWM����ת��
	//bit 14-12:	00		�ռ�ʸ��λ
	//bit 11-10:	00		CMP6ǿ�Ƶ�
	//bit 9-8:		00		CMP5ǿ�Ƶ�
	//bit 7-6:		01		CMP4����Ч
	//bit 5-4:		10		CMP3����Ч
	//bit 3-2:		01		CMP2����Ч
	//bit 1-0:		10		CMP1����Ч
	EvaRegs.DBTCONA.all = 0xFF6B; 	// 2110����ʱ���0.2us��MOS�ܵ���ʱ���0.025us
	//bit 15-12��	1111	����
	//bit 11-8:		1001	ת��Ϊʮ����Ϊ9��9/18.75M=0.48us
	//bit 7:		0		CMP3��Ӧ��PWM5��PWM6��ʹ��
	//bit 6:		1		CMP2��Ӧ��PWM3��PWM4ʹ��
	//bit 5:		1		CMP1��Ӧ��PWM1��PWM2ʹ��
	//bit 4-2:		011		����ʱ��ΪHSPCLK/8=18.75M
	//bit 1-0:		11		����

// Enable compare for PWM1-PWM4
	EvaRegs.CMPR1 = 375;
	EvaRegs.CMPR2 = 375;

}

void init_ADC(void)
{
	unsigned int i=0;

	//��λ
	AdcRegs.ADCTRL1.bit.RESET=1;
	asm ("      NOP");
	AdcRegs.ADCTRL1.bit.RESET=0;

	AdcRegs.ADCTRL1.bit.SUSMOD=0;			//������ͣ��ʽ�����Է�����ͣ

	AdcRegs.ADCTRL1.bit.ACQ_PS=15;			//�������ڴ�С��SOC������Ϊ1��ADCLK�������ԣ������ټ�
	AdcRegs.ADCTRL1.bit.CPS=0;				//��ʱ��Ԥ������������Ƶ

	AdcRegs.ADCTRL1.bit.CONT_RUN=0;			//����������/ֹͣģʽ

	AdcRegs.ADCTRL3.bit.ADCBGRFDN=0x3;		//���ڲ��ο���Դ
	for(i=0;i<10000;i++)
		asm ("      NOP");
	AdcRegs.ADCTRL3.bit.ADCPWDN=1;			//ADC��Դ���ƣ��ӵ�
	for(i=0;i<5000;i++)
		asm ("      NOP");

	AdcRegs.ADCTRL3.bit.ADCCLKPS=2;			//ADCLK=HSPCLK/��2*ADCCLKPS��=75M/��2*2��=18.75M

	AdcRegs.ADCTRL1.bit.SEQ_CASC=0;			//˫���з�����ģʽ
	AdcRegs.ADCTRL3.bit.SMODE_SEL=1;		//��������ģʽ

	AdcRegs.ADCMAXCONV.all=0x0011;			//˫���в�������������������������·

	//�����жϲ�SEQ1
	AdcRegs.ADCCHSELSEQ1.bit.CONV00=0x0;	//����ADCINA0��ADCINB0
	AdcRegs.ADCCHSELSEQ1.bit.CONV01=0x0;	//����ADCINA0��ADCINB0
	//�Ƚ��жϲ�SEQ2
	AdcRegs.ADCCHSELSEQ3.bit.CONV08=0x0;	//����ADCINA0��ADCINB0
	AdcRegs.ADCCHSELSEQ3.bit.CONV09=0x0;	//����ADCINA0��ADCINB0

	AdcRegs.ADCST.bit.INT_SEQ1_CLR=1;		//���SEQ1�е��жϱ�־λ INT_SEQ1
	AdcRegs.ADCST.bit.INT_SEQ2_CLR=1;		//���SEQ2�е��жϱ�־λ INT_SEQ2

	AdcRegs.ADCTRL2.bit.EVB_SOC_SEQ=0;
	AdcRegs.ADCTRL2.bit.RST_SEQ1=0;			//��λ���з�����1��0����������

	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1=0;		//��ʹ��SEQ1���ж�����
	AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1=0;		//ÿ������ת����������λSEQ1�жϱ�־λ
	AdcRegs.ADCTRL2.bit.EVA_SOC_SEQ1=0;		//������EVA��������SEQ1
	AdcRegs.ADCTRL2.bit.EXT_SOC_SEQ1=0;		//�������ⲿ����SEQ1

	AdcRegs.ADCTRL2.bit.RST_SEQ2=1;			//��λ���з�����2��0����������
	AdcRegs.ADCTRL2.bit.SOC_SEQ2=0;			//SEQ2�������0��������

	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2=1;		//ʹ��SEQ2���ж�����
	AdcRegs.ADCTRL2.bit.INT_MOD_SEQ2=0;		//ÿ������ת����������λSEQ2�жϱ�־λ
	AdcRegs.ADCTRL2.bit.EVB_SOC_SEQ2=0;		//������EVB��������SEQ2

	AdcRegs.ADCTRL2.bit.SOC_SEQ1=0;			//SEQ1�������0��������
}

void init_SCI(void)
{
	SciaRegs.SCICCR.bit.STOPBITS = 0 ;		//1λֹͣλ
	SciaRegs.SCICCR.bit.PARITYENA = 0;		//��ֹ��żУ��
	SciaRegs.SCICCR.bit.LOOPBKENA = 0;		//��ʹ�ܻػ�����
	SciaRegs.SCICCR.bit.ADDRIDLE_MODE = 0;	//������ģʽ
	SciaRegs.SCICCR.bit.SCICHAR = 7;		//8λ����λ

	SciaRegs.SCICTL1.bit.TXENA = 1;			//SCIAģ�鷢��ʹ��
	SciaRegs.SCICTL1.bit.RXENA = 1;			//SCIAģ�����ʹ��

	SciaRegs.SCIHBAUD = 0x0000;					//������Ϊ115200
	SciaRegs.SCILBAUD = 0x0028;					//37.5M/(115200*8) -1 =39.69��

//	SciaRegs.SCICTL2.bit.RXBKINTENA = 1; 	//SCIA�����ж�
//	SciaRegs.SCICTL2.bit.TXINTENA = 1;		//SCIA�����ж�

	SciaRegs.SCIFFTX.bit.TXFIFOXRESET = 1;	//����ʹ�ܷ���FIFO����
	SciaRegs.SCIFFTX.bit.SCIFFENA = 1;		//ʹ��SCIA FIFO����
	SciaRegs.SCIFFTX.bit.TXFFST = 0;		//����FIFO����Ϊ��
//	SciaRegs.SCIFFTX.bit.TXFFINT = 0;		//�޷���FIFO�жϣ�ֻ��
	SciaRegs.SCIFFTX.bit.TXINTCLR = 0;		//�����TXFFINT��־λ
	SciaRegs.SCIFFTX.bit.TXFFIENA = 1;		//ʹ�ܷ���FIFO�ж�
	SciaRegs.SCIFFTX.bit.TXFFILIL = 0;		//�����жϼ���Ϊ0����������FIFOΪ��ʱ�����ж�

//	SciaRegs.SCIFFRX.bit.RXFFOVF = 0;		//����FIFO�������ֻ��
	SciaRegs.SCIFFRX.bit.RXFFOVRCLR = 1;	//���RXFFOVF��־λ
	SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;	//����ʹ�ܽ���FIFO�Ĳ���
	SciaRegs.SCIFFRX.bit.RXFIFST = 0;		//����FIFO����Ϊ��
//	SciaRegs.SCIFFRX.bit.RXFFINT = 0;		//�޽����жϣ�ֻ��
	SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;	//��������жϱ�־λ
	SciaRegs.SCIFFRX.bit.RXFFIENA = 1;		//ʹ��FIFO�����ж�
	SciaRegs.SCIFFRX.bit.RXFFIL = 1;		//FIFO�����жϼ���Ϊ16��������FIFO����16���ַ�ʱ�����ж�

	SciaRegs.SCICTL1.bit.SWRESET = 1;		//����SCIA
}

void main(void)
{
	unsigned char i=0;
	unsigned char j=1;
// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the DSP281x_SysCtrl.c file.
// ϵͳʱ��5������Ƶ�ʣ���������ʱ��Ϊ0.5��ϵͳʱ�ӣ���������ʱ��Ϊ0.25��ϵͳʱ��
// �������¼�������A��B��ʱ�ӣ�ADCʱ�ӣ�SCIAʱ��
	InitSysCtrl();
// Step 2. Initalize GPIO:
// This example function is found in the DSP281x_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
	InitGpio();  // Skipped for this example

// Step 3. Clear all interrupts and initialize PIE vector table:
// Disable CPU interrupts
   DINT;

// Initialize PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags
// are cleared.
// This function is found in the DSP281x_PieCtrl.c file.
   InitPieCtrl();

// Disable CPU interrupts and clear all CPU interrupt flags:
   IER = 0x0000;
   IFR = 0x0000;

// Initialize the PIE vector table with pointers to the shell Interrupt
// Service Routines (ISR).
// This will populate the entire table, even if the interrupt
// is not used in this example.  This is useful for debug purposes.
// The shell ISR routines are found in DSP281x_DefaultIsr.c.
// This function is found in DSP281x_PieVect.c.
   InitPieVectTable();

// Step 4. Initialize all the Device Peripherals:
// This function is found in DSP281x_InitPeripherals.c
// InitPeripherals(); // Not required for this example
   init_ADC();
   init_eva();
   init_SCI();
   Matching_init();

   PieCtrlRegs.PIEIER1.bit.INTx6 = 1;		//ʹ��PIEģ���е�ADC�����ж�
   PieCtrlRegs.PIEIER2.bit.INTx6 = 1;		//ʹ��PIEģ���е�T1�����ж�
   PieCtrlRegs.PIEIER2.bit.INTx5 = 1;		//ʹ��PIEģ���е�T1�Ƚ��ж�
   PieCtrlRegs.PIEIER9.bit.INTx1 = 1;		//ʹ��PIEģ���е�SCI�����ж�
   PieCtrlRegs.PIEIER9.bit.INTx2 = 1;		//ʹ��PIEģ���е�SCI�����ж�

   IER|= M_INT1|M_INT2|M_INT9;			//��CPU�ж�
   EINT;								//ʹ��ȫ���ж�
   ERTM;								//ʹ��ʵʱ�ж�

// Step 5. User specific code, enable interrupts:
   Set_Source(&S);
   PMF();
//   for(i=1;i<7;i++)
//   {
//	   Matching_Word[1]=(j<<i)+1;
	   Matching(Matching_Word);
//   }


  // Just sit and loop forever:
  // PWM pins can be observed with a scope.
  for(;;)
  {

  }
}

