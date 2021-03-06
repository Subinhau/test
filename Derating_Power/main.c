//
//ADC采样不对，采多了

/*
 * main.c
 * 产生一个100kHz的PWM波，
 * PWM1			PWM2
 * PWM4			PWM3
 */

#include "main.h"

unsigned char ADC_flag=0;
float Data[2][FFT_Num];
unsigned int Data_int0[FFT_Num];
unsigned int Data_int1[FFT_Num];
//unsigned int *Data_int0=(unsigned int *)(&Data[0][0]);
//unsigned int *Data_int1=(unsigned int *)(&Data[1][0]);
//unsigned int I_sample[FFT_Num];
//unsigned int V_sample[FFT_Num];
unsigned char Matching_Word[3]={0x00,0x00,0xFF};		//Li	Lii		C
//int Phase_Time[2][2]={			//Vt-1	Vt
//		{0,0},{0,0}};			//周期	相差
Source S={
	.Po=0,
	.f=100000,
	.omg=2*PI*100000,
	.Vdc=48,
	.Rs=50,
	.Rl=180,
	.Gs=0.01,
	.Gl=0.005,
	.k=2,
};

struct CAP CapValue={
//	.V=30,		//采样电压			(V)
//	.I=5,		//采样电流			(I)
//	.f=100,		//采样到的频率		(kHz)
//	.Ph=15,		//相位差			(度)
	.Z.real=0,
	.Z.imag=0,
};		//采样信息

void Set_Source(Source * S)
{
	S->omg=2*PI*S->f;

	S->Gs=1/S->Rs;
	S->Gl=1/S->Rl;

	S->k=S->Gs/S->Gl;
}


void init_eva(void)
{
//	EvaRegs.GPTCONA.bit.T1TOADC=3;		//比较中断启动ADC
//	EvaRegs.EVAIMRA.bit.T1UFINT=1;		//使能定时器T1下溢中断
//	EvaRegs.EVAIFRA.bit.T1UFINT=1;		//清除定时器T1下溢中断标志位
//	EvaRegs.EVAIMRA.bit.T1CINT=1;		//使能定时器T1比较中断
//	EvaRegs.EVAIFRA.bit.T1CINT=1;		//清除定时器T1比较中断标志位
//	EvaRegs.EVAIMRA.bit.T1PINT=1;		//使能定时器T1周期中断
//	EvaRegs.EVAIFRA.bit.T1PINT=1;		//清除定时器T1周期中断标志位

//	EvaRegs.T1CMPR=186;					//设置T1比较值为四分之一周期

	EvaRegs.EVAIMRB.bit.T2PINT =1;		//使能定时器T2周期中断
	EvaRegs.EVAIFRB.bit.T2PINT=1;		//清除定时器T2周期中断标志位
//	EvaRegs.EVAIMRB.bit.T2CINT=1;		//使能定时器T2比较中断
//	EvaRegs.EVAIFRB.bit.T2CINT=1;		//清除定时器T2比较中断标志位

//时基配置
	EvaRegs.T1CON.all = 0xF00C;
	//bit 15-14:		11		仿真挂起无影响
	//bit 13:			1		保留
	//bit 12-11:		10		连续增模式
	//bit 10-8:			000		时钟预定标，时钟源频率/1
	//bit 7:			0		T1T2同步使能
	//bit 6:			0		定时器不使能
	//bit 5-4:			00		选择时钟源为HSPCLK
	//bit 3-2：			11		定时器比较寄存器重载条件，保留
	//bit 1:			0		定时器比较不使能
	//bit 0:			0		T1CON中该位保留

	EvaRegs.T1PR = 1500-1;			// Timer1 period 100kHz,150M/1/100k=1500
	EvaRegs.T1CNT = 0x0000;      	// Timer1 counter

	EvaRegs.T2CON.all = 0x300C;
	//bit 15-14:		00		仿真挂起
	//bit 13:			1		保留
	//bit 12-11:		10		连续增模式
	//bit 10-8:			000		时钟预定标，时钟源频率/1
	//bit 7:			0		T1T2同步使能
	//bit 6:			0		定时器使能
	//bit 5-4:			00		选择时钟源为HSPCLK
	//bit 3-2：			11		定时器比较寄存器重载条件，保留
	//bit 1:			0		定时器比较不使能
	//bit 0:			0		T2使用自己的周期寄存器

	EvaRegs.T2PR = 186;			// Timer2 period 1.6MHz,150M/1/1.6M=93.75
	EvaRegs.T2CMPR=38;				//设置T2比较值,ADC时钟18.75M，采样窗口15，保持时间约为1.25M，1.25M/1.6M=0.78,38/47=0.8,应该足够
	EvaRegs.T2CNT = 0x0000;      	// Timer2 counter

	EvaRegs.GPTCONA.bit.T2TOADC = 1;		//定时器2下溢中断启动ADC
//比较器配置
	EvaRegs.COMCONA.all = 0x837B;
	//bit 15:		1		使能比较
	//bit 14-13:	00		T1CNT=0时CMPRx重载
	//bit 12:		0		禁止SVPWM模式
	//bit 11-10:	00		行为控制寄存器重载条件：T1CNT=0
	//bit 9:		1		全比较器输出使能
	//bit 8:		1		只读引脚
	//bit 7:		0		全比较器3输出不使能
	//bit 6:		1		全比较器2输出使能
	//bit 5:		1		全比较器1输出使能
	//bit 4-3:		11		保留
	//bit 2:		0		全比较器3输出不使能
	//bit 1:		1		全比较器2输出使能
	//bit 0:		1		全比较器1输出使能
	EvaRegs.ACTRA.all = 0x0066;
	//bit 15:		0		空间矢量PWM正向转动
	//bit 14-12:	00		空间矢量位
	//bit 11-10:	00		CMP6强制低
	//bit 9-8:		00		CMP5强制低
	//bit 7-6:		01		CMP4低有效
	//bit 5-4:		10		CMP3高有效
	//bit 3-2:		01		CMP2低有效
	//bit 1-0:		10		CMP1高有效
// Enable compare for PWM1-PWM4
	EvaRegs.CMPR1 = 750;
	EvaRegs.CMPR2 = 750;
//死区配置
	EvaRegs.DBTCONA.all = 0xF96B; 	// 2110的延时大概0.2us，MOS管的延时大概0.025us		0xFF6B
	//bit 15-12：	1111	保留
	//bit 11-8:		1001	转换为十进制为9，9/18.75M=0.48us
	//bit 7:		0		CMP3对应的PWM5和PWM6不使能
	//bit 6:		1		CMP2对应的PWM3和PWM4使能
	//bit 5:		1		CMP1对应的PWM1和PWM2使能
	//bit 4-2:		100		死区时钟为HSPCLK/16=18.75M
	//bit 1-0:		11		保留

////捕获配置
//	EvaRegs.CAPCONA.bit.CAPRES=0;		//捕获单元复位
//
//	EvaRegs.CAPFIFOA.all=0x0000;		//清除状态位
//
//	EvaRegs.CAPCONA.all=0xBF5F;
//	//bit 15:		1		不复位
//	//bit 14-13:	01		CAP1、2使能捕获
//	//bit 12:		1		CAP3使能捕获
//	//bit 11:		1		保留
//	//bit 10:		1		CAP3选择定时器1
//	//bit 9:		1		CAP1、2选择定时器1
//	//bit 8:		1		CAP3启动ADC
//	//bit 7-6:		01		CAP1上升沿捕获
//	//bit 5-4:		01		CAP2上升沿捕获
//	//bit 3-2:		11		CAP3上下沿捕获
//	//bit 1-0:		11		保留
//
////中断配置
//	EvaRegs.EVAIMRC.bit.CAP1INT=1;		//捕获单元1中断使能
//	EvaRegs.EVAIMRC.bit.CAP2INT=1;		//捕获单元2中断使能
//	EvaRegs.EVAIMRC.bit.CAP3INT=1;		//捕获单元3中断使能

}

void init_ADC(void)
{
	unsigned int i=0;

	//复位
	AdcRegs.ADCTRL1.bit.RESET=1;
	asm ("      NOP");
	AdcRegs.ADCTRL1.bit.RESET=0;

	AdcRegs.ADCTRL1.bit.SUSMOD=0;			//仿真暂停方式：忽略仿真暂停

	AdcRegs.ADCTRL1.bit.ACQ_PS=1;			//采样窗口大小，SOC脉冲宽度为15个ADCLK,1.25M
	AdcRegs.ADCTRL1.bit.CPS=0;				//核时钟预定标器，不分频

	AdcRegs.ADCTRL1.bit.CONT_RUN=0;			//运行于启动/停止模式

	AdcRegs.ADCTRL3.bit.ADCBGRFDN=0x3;		//打开内部参考电源
	for(i=0;i<10000;i++)
		asm ("      NOP");
	AdcRegs.ADCTRL3.bit.ADCPWDN=1;			//ADC电源控制，加电
	for(i=0;i<5000;i++)
		asm ("      NOP");

	AdcRegs.ADCTRL3.bit.ADCCLKPS=2;			//ADCLK=HSPCLK/（2*ADCCLKPS）=150M/（2*3）=25M

	AdcRegs.ADCTRL1.bit.SEQ_CASC=1;			//级联模式
	AdcRegs.ADCTRL3.bit.SMODE_SEL=1;		//并发采样模式

	AdcRegs.ADCMAXCONV.all=0x0000;			//双序列并发采样，采两路

	//下溢中断采SEQ1
	AdcRegs.ADCCHSELSEQ1.bit.CONV00=0x2;	//采样ADCINA0和ADCINB0
//	AdcRegs.ADCCHSELSEQ1.bit.CONV01=0x0;	//采样ADCINA0和ADCINB0
//	AdcRegs.ADCCHSELSEQ1.bit.CONV02=0x0;	//采样ADCINA0和ADCINB0
//	AdcRegs.ADCCHSELSEQ1.bit.CONV03=0x0;	//采样ADCINA0和ADCINB0
//	AdcRegs.ADCCHSELSEQ2.bit.CONV04=0x0;	//采样ADCINA0和ADCINB0
//	AdcRegs.ADCCHSELSEQ2.bit.CONV05=0x0;	//采样ADCINA0和ADCINB0
//	AdcRegs.ADCCHSELSEQ2.bit.CONV06=0x0;	//采样ADCINA0和ADCINB0
//	AdcRegs.ADCCHSELSEQ2.bit.CONV07=0x0;	//采样ADCINA0和ADCINB0
//	//比较中断采SEQ2
//	AdcRegs.ADCCHSELSEQ3.bit.CONV08=0x0;	//采样ADCINA0和ADCINB0
//	AdcRegs.ADCCHSELSEQ3.bit.CONV09=0x0;	//采样ADCINA0和ADCINB0

	AdcRegs.ADCST.bit.INT_SEQ1_CLR=1;		//清除SEQ1中的中断标志位 INT_SEQ1
	AdcRegs.ADCST.bit.INT_SEQ2_CLR=1;		//清除SEQ2中的中断标志位 INT_SEQ2

	AdcRegs.ADCTRL2.bit.EVB_SOC_SEQ=0;
	AdcRegs.ADCTRL2.bit.RST_SEQ1=1;			//复位序列发生器1，0：不起作用

	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1=1;		//使能SEQ1的中断请求
	AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1=0;		//每个序列转换结束后置位SEQ1中断标志位
	AdcRegs.ADCTRL2.bit.EVA_SOC_SEQ1=1;		//允许EVA启动触发SEQ1
	AdcRegs.ADCTRL2.bit.EXT_SOC_SEQ1=0;		//不启用外部触发SEQ1

	AdcRegs.ADCTRL2.bit.RST_SEQ2=0;			//复位序列发生器2，0：不起作用
	AdcRegs.ADCTRL2.bit.SOC_SEQ2=0;			//SEQ2启动命令，0：不启动

	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2=0;		//不使能SEQ2的中断请求
	AdcRegs.ADCTRL2.bit.INT_MOD_SEQ2=0;		//每个序列转换结束后置位SEQ2中断标志位
	AdcRegs.ADCTRL2.bit.EVB_SOC_SEQ2=0;		//不允许EVB启动触发SEQ2

	AdcRegs.ADCTRL2.bit.SOC_SEQ1=0;			//SEQ1启动命令，0：不启动
}

//void init_SCI(void)
//{
//	SciaRegs.SCICCR.bit.STOPBITS = 0 ;		//1位停止位
//	SciaRegs.SCICCR.bit.PARITYENA = 0;		//禁止奇偶校验
//	SciaRegs.SCICCR.bit.LOOPBKENA = 0;		//不使能回环测试
//	SciaRegs.SCICCR.bit.ADDRIDLE_MODE = 0;	//空闲线模式
//	SciaRegs.SCICCR.bit.SCICHAR = 7;		//8位数据位
//
////	SciaRegs.SCICTL1.bit.TXENA = 1;			//SCIA模块发送使能
//	SciaRegs.SCICTL1.bit.RXENA = 1;			//SCIA模块接收使能
//
//	SciaRegs.SCIHBAUD = 0x0000;					//波特率为115200
//	SciaRegs.SCILBAUD = 0x0028;					//37.5M/(115200*8) -1 =39.69…
//
////	SciaRegs.SCICTL2.bit.RXBKINTENA = 1; 	//SCIA接收中断
////	SciaRegs.SCICTL2.bit.TXINTENA = 1;		//SCIA发送中断
//
//	SciaRegs.SCIFFTX.bit.TXFIFOXRESET = 1;	//重新使能发送FIFO操作
//	SciaRegs.SCIFFTX.bit.SCIFFENA = 1;		//使能SCIA FIFO功能
//	SciaRegs.SCIFFTX.bit.TXFFST = 0;		//发送FIFO队列为空
////	SciaRegs.SCIFFTX.bit.TXFFINT = 0;		//无发送FIFO中断（只读
//	SciaRegs.SCIFFTX.bit.TXINTCLR = 0;		//不清除TXFFINT标志位
//	SciaRegs.SCIFFTX.bit.TXFFIENA = 1;		//使能发送FIFO中断
//	SciaRegs.SCIFFTX.bit.TXFFILIL = 0;		//发送中断级别为0，即当发送FIFO为空时发生中断
//
////	SciaRegs.SCIFFRX.bit.RXFFOVF = 0;		//接收FIFO无溢出（只读
//	SciaRegs.SCIFFRX.bit.RXFFOVRCLR = 1;	//清除RXFFOVF标志位
//	SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;	//重新使能接收FIFO的操作
//	SciaRegs.SCIFFRX.bit.RXFIFST = 0;		//接收FIFO队列为空
////	SciaRegs.SCIFFRX.bit.RXFFINT = 0;		//无接收中断（只读
//	SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;	//清除接收中断标志位
//	SciaRegs.SCIFFRX.bit.RXFFIENA = 1;		//使能FIFO接收中断
//	SciaRegs.SCIFFRX.bit.RXFFIL = 1;		//FIFO接收中断级别为16，即接收FIFO中有16个字符时发生中断
//
//	SciaRegs.SCICTL1.bit.SWRESET = 1;		//重启SCIA
//}

//void qsort(Complex * a, int left, int right)		//快速排序
//{
//	if(left>=right)
//	{return;}
//	int i = left;
//	int j = right;
//	Complex key = a[left];
//	Complex temp={.imag=0,.real=0};
//
//	while(i<j)
//	{
//		while(i<j && key.real<=a[j].real)
//		{
//			j--;
//		}
//		temp=a[j];
//		a[j]=a[i];
//		a[i]=temp;
//		while(i<j && key.real>=a[i].real)
//		{
//			i++;
//		}
//		temp=a[j];
//		a[j]=a[i];
//		a[i]=temp;
//	}
//	qsort(a, left, i-1);
//	qsort(a, i+1, right);
//}

Complex Cul_Z()
{
	char i=0;
	unsigned char j=0;
	Complex t1={.real=0,.imag=0};
	Complex t2={.real=0,.imag=0};
	Complex t3[10];
	Complex t4[10];
	EvaRegs.T2CNT = 0x0000;      	// Timer2 counter
	EvaRegs.T2CON.bit.TENABLE=1;			//启动定时器2
	for(;;)
	  {
		  if(ADC_flag)
		  {
			  EvaRegs.T2CON.bit.TENABLE=0;			//关闭定时器2
			  for(i=FFT_Num-1;i>=0;i--)				//数据转移变换
			  {
				  Data[1][i]=Data_int1[i]*396.0/65520.0-233.60195625;		//*94.64	3.3*186		1.94668296875*186
				  Data[0][i]=Data_int0[i]*6.27/65520.0-3.698697640625;		//*2.988	3.3*3.5		1.94668296875*3.5
			  }

			  //FFT
			  t1=FFT(&Data[1][0],1);
			  t2=FFT(&Data[0][0],1);
			  t3[j].real=t1.real/t2.real;				//此时的real代表幅值，imag代表角度
			  t3[j].imag=t1.imag-t2.imag;
			  t4[j]=C_mul(t1,t2);
	//		  EvaRegs.EVAIMRB.bit.T2PINT=1;				//使能T2周期中断

			  ADC_flag=0;
			  j++;
			  if(j>=10)
			  {
				  j=0;
				  for(i=1;i<10;i++)
				  {
					  t3[0]=C_add(t3[0],t3[i]);
					  t4[0]=C_add(t4[0],t4[i]);
				  }
				  t3[0].real/=10;
				  t3[0].imag/=10;
				  t4[0].real/=10;
				  t4[0].imag/=10;
//				  qsort(t3,0,8);
				  return t3[0];
			  }
			  else
			  {
				  EvaRegs.T2CNT = 0x0000;      	// Timer2 counter
				  EvaRegs.T2CON.bit.TENABLE=1;			//启动定时器2
			  }
		  }
	  }
}

void main(void)
{
//	char i=0;
//	unsigned char j=0;
//	unsigned char k=0;
	float tao_mod=0;
	Complex tao={.imag=0,.real=0};
	Complex t={.imag=0,.real=0};
// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the DSP281x_SysCtrl.c file.
// 系统时钟5倍晶振频率，高速外设时钟为1倍系统时钟，低速外设时钟为0.25倍系统时钟
// 开启了事件管理器A、B的时钟，ADC时钟，SCIA时钟
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
//   init_SCI();
   Matching_init();

   PieCtrlRegs.PIEIER1.bit.INTx6 = 1;		//使能PIE模块中的ADC采样中断
   PieCtrlRegs.PIEIER1.bit.INTx4 = 0;		//使能PIE模块中的ADC采样中断
//   PieCtrlRegs.PIEIER3.bit.INTx5 = 1;		//使能PIE模块中的CAP1中断
//   PieCtrlRegs.PIEIER3.bit.INTx6 = 1;		//使能PIE模块中的CAP2中断
//   PieCtrlRegs.PIEIER3.bit.INTx7 = 1;		//使能PIE模块中的CAP3中断
//   PieCtrlRegs.PIEIER9.bit.INTx1 = 1;		//使能PIE模块中的SCI接收中断
//   PieCtrlRegs.PIEIER9.bit.INTx2 = 1;		//使能PIE模块中的SCI发送中断
//   PieCtrlRegs.PIEIER2.bit.INTx4 = 1;		//使能PIE模块中的T1周期中断
//   PieCtrlRegs.PIEIER2.bit.INTx5 = 1;		//使能PIE模块中的T1比较中断
   PieCtrlRegs.PIEIER3.bit.INTx1 = 1;		//使能PIE模块中的T2周期中断

   IER|= M_INT1|M_INT3;					//开CPU中断	M_INT2|	|M_INT9
   EINT;								//使能全局中断
   ERTM;								//使能实时中断

   EvaRegs.T1CON.bit.TENABLE=1;			//启动定时器1
//   EvaRegs.T2CON.bit.TENABLE=1;			//启动定时器2
   GpioDataRegs.GPACLEAR.bit.GPIOA4=1;
// Step 5. User specific code, enable interrupts:
//   Set_Source(&S);
//   PMF();
//   for(i=1;i<7;i++)
//   {
//	   Matching_Word[1]=(j<<i)+1;
//	   Matching(Matching_Word);
//   }
//   Send_Data(&CapValue);

   Matching(Matching_Word);

  // Just sit and loop forever:
  // PWM pins can be observed with a scope.
   S.Po=20;
   S.Vdc=29.5;
   S.Rs=(8.0*S.Vdc*S.Vdc)/(S.Po*PI*PI);


   for(;;)
   {
	   t=Cul_Z();
		CapValue.Z.real=t.real*cos(t.imag);		//借用临时变量t将幅角制转换为虚实部
		CapValue.Z.imag=t.real*sin(t.imag);

		S.Rl=CapValue.Z.real;
		Set_Source(&S);

		t=CapValue.Z;
		tao=CapValue.Z;
		t.real=t.real-S.Rs;
		tao.real=tao.real+S.Rs;
		tao.imag=-tao.imag;

		tao_mod=C_mod(tao);

		tao=C_mul(tao,t);
		tao.real=tao.real/tao_mod;
		tao.imag=tao.imag/tao_mod;
		tao_mod=C_mod(tao);

		if(tao_mod>Tao_lim)
		{
			PMF();
			GpioDataRegs.GPASET.bit.GPIOA4=1;				//保护开启
			Matching(Matching_Word);
			GpioDataRegs.GPACLEAR.bit.GPIOA4=1;
		}
   }

}

