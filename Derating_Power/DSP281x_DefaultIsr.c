// TI File $Revision: /main/2 $
// Checkin $Date: April 29, 2005   11:10:44 $
//###########################################################################
//
// FILE:	DSP281x_DefaultIsr.c
//
// TITLE:	DSP281x Device Default Interrupt Service Routines.
//
//###########################################################################
// $TI Release: DSP281x C/C++ Header Files V1.20 $
// $Release Date: July 27, 2009 $
//###########################################################################

#include "main.h"


// Note CPU-Timer1 ISR is reserved for TI use.
interrupt void INT13_ISR(void)     // INT13 or CPU-Timer1
{
  // Insert ISR Code here
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
     asm ("      ESTOP0");
     for(;;);
}

// Note CPU-Timer2 ISR is reserved for TI use.
interrupt void INT14_ISR(void)     // CPU-Timer2
{
  // Insert ISR Code here
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
     asm ("      ESTOP0");
     for(;;);
}

interrupt void DATALOG_ISR(void)   // Datalogging interrupt
{
  // Insert ISR Code here
 
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void RTOSINT_ISR(void)   // RTOS interrupt
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void EMUINT_ISR(void)    // Emulation interrupt
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void NMI_ISR(void)       // Non-maskable interrupt
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void ILLEGAL_ISR(void)   // Illegal operation TRAP
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  asm("          ESTOP0");
  for(;;);

}


interrupt void USER1_ISR(void)     // User Defined trap 1
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);

}

interrupt void USER2_ISR(void)     // User Defined trap 2
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);


}

interrupt void USER3_ISR(void)     // User Defined trap 3
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void USER4_ISR(void)     // User Defined trap 4
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void USER5_ISR(void)     // User Defined trap 5
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void USER6_ISR(void)     // User Defined trap 6
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void USER7_ISR(void)     // User Defined trap 7
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void USER8_ISR(void)     // User Defined trap 8
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void USER9_ISR(void)     // User Defined trap 9
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void USER10_ISR(void)    // User Defined trap 10
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void USER11_ISR(void)    // User Defined trap 11
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

interrupt void USER12_ISR(void)     // User Defined trap 12
{
 // Insert ISR Code here
 
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);

}

// -----------------------------------------------------------
// PIE Group 1 - MUXed into CPU INT1
// -----------------------------------------------------------

// INT1.1
interrupt void PDPINTA_ISR( void )    // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT1.2
interrupt void  PDPINTB_ISR(void)   // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT1.3 - Reserved

// INT1.4
interrupt void  XINT1_ISR(void)
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);

}     

// INT1.5
interrupt void  XINT2_ISR(void)
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);

}

// INT1.6
interrupt void  ADCINT_ISR(void)     // ADC
{
  // Insert ISR Code here
	static unsigned char i=0;
//	I_sample[i]=AdcRegs.ADCRESULT0;//*3.3/65520.0;		//y = 2.988x - 4.7677??3.3*2.988=9.8604   (float)
//	V_sample[i]=AdcRegs.ADCRESULT1;//*3.3/65520.0;

//	I_sample[i]=((float)AdcRegs.ADCRESULT0*0.5+(float)AdcRegs.ADCRESULT2*0.5)*9.8604/65520.0-6.0677;		//y = 2.988x - 4.7677??3.3*2.988=9.8604
//	V_sample[i]=((float)AdcRegs.ADCRESULT1*0.5+(float)AdcRegs.ADCRESULT3*0.5)*330/65520.0-205;

//	I_sample[1][i]=((float)AdcRegs.ADCRESULT8*0.5+(float)AdcRegs.ADCRESULT10*0.5)*9.8604/65520.0-6.0677;		//y = 2.988x - 4.7677??3.3*2.988=9.8604
//	V_sample[1][i]=((float)AdcRegs.ADCRESULT9*0.5+(float)AdcRegs.ADCRESULT11*0.5)*330/65520.0-205;

	Data_int0[i]=AdcRegs.ADCRESULT0;
	Data_int1[i]=AdcRegs.ADCRESULT1;

	i++;
	if(i>FFT_Num)
	{
		i=0;
		ADC_flag=1;
		EvaRegs.T2CON.bit.TENABLE=0;			//??????????2
	}

	AdcRegs.ADCTRL2.bit.RST_SEQ2=1;		//??????????????SEQ2
	AdcRegs.ADCTRL2.bit.RST_SEQ1=1;		//??????????????SEQ1

	PieCtrlRegs.PIEACK.bit.ACK1=1;		//????????????????
	AdcRegs.ADCST.bit.INT_SEQ1_CLR=1;	//????AD??????????
	AdcRegs.ADCST.bit.INT_SEQ2_CLR=1;	//????AD??????????

	EINT;								//????????????
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; 
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
//   asm ("      ESTOP0");
//   for(;;);
}

// INT1.7
interrupt void  TINT0_ISR(void)      // CPU-Timer 0
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; 
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
     asm ("      ESTOP0");
     for(;;);
}


// INT1.8
interrupt void  WAKEINT_ISR(void)    // WD
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; 
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}


// -----------------------------------------------------------
// PIE Group 2 - MUXed into CPU INT2
// -----------------------------------------------------------

// INT2.1
interrupt void CMP1INT_ISR(void)    // EV-A
{
  // Insert ISR Code here
											//????????????
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT2.2
interrupt void CMP2INT_ISR(void)    // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT2.3
interrupt void CMP3INT_ISR(void)    // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}


// INT2.4
interrupt void T1PINT_ISR(void)    // EV-A
{
  // Insert ISR Code here
//	AdcRegs.ADCTRL2.bit.SOC_SEQ1=1;				//????SEQ1
//
//	PieCtrlRegs.PIEACK.all=PIEACK_GROUP2;		//????????????????
//	EvaRegs.EVAIFRA.bit.T1PINT=1;				//??????????????
//	EINT;										//????????????
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}


// INT2.5
interrupt void T1CINT_ISR(void)    // EV-A
{
  // Insert ISR Code here

//	AdcRegs.ADCTRL2.bit.SOC_SEQ2=1;				//????SEQ2
//
//	PieCtrlRegs.PIEACK.all=PIEACK_GROUP2;		//????????????????
//	EvaRegs.EVAIFRA.bit.T1CINT=1;				//??????????????
//	EINT;										//????????????
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT2.6
interrupt void T1UFINT_ISR(void)   // EV-A
{
  // Insert ISR Code here

//	AdcRegs.ADCTRL2.bit.SOC_SEQ1=1;				//????SEQ1
//
//	PieCtrlRegs.PIEACK.all=PIEACK_GROUP2;		//????????????????
//	EvaRegs.EVAIFRA.bit.T1UFINT=1;				//??????????????
//	EINT;										//????????????
//
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT2.7
interrupt void T1OFINT_ISR(void)   // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}
      
      
// INT2.8 - Reserved

// -----------------------------------------------------------
// PIE Group 3 - MUXed into CPU INT3
// -----------------------------------------------------------
   
// INT 3.1         
interrupt void T2PINT_ISR(void)     // EV-A
{
  // Insert ISR Code here
//	GpioDataRegs.GPBTOGGLE.bit.GPIOB1=1;

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
   EvaRegs.EVAIFRB.bit.T2PINT=1;				//??????????????
   EINT;										//????????????
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
//   asm ("      ESTOP0");
//   for(;;);
}

// INT3.2
interrupt void T2CINT_ISR(void)     // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT3.3
interrupt void T2UFINT_ISR(void)    // EV-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT3.4
interrupt void T2OFINT_ISR(void)    // EV-A
{
  // Insert ISR Code here
  
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;  

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT3.5
interrupt void CAPINT1_ISR(void)    // EV-A
{
  // Insert ISR Code here
//	Phase_Time[0][0]=Phase_Time[0][1];
//	Phase_Time[0][1]=EvaRegs.CAP1FIFO;
//	Phase_Time[1][0]=Phase_Time[0][1]-Phase_Time[0][0]+EvaRegs.T1PR;
//
//	PieCtrlRegs.PIEACK.all=PIEACK_GROUP3;		//????????????????
//	EvaRegs.EVAIFRC.bit.CAP1INT=1;				//??????????????
//	EINT;

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;  

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT3.6
interrupt void CAPINT2_ISR(void)    // EV-A
{
  // Insert ISR Code here
//	Phase_Time[1][1]=EvaRegs.CAP2FIFO;
//	Phase_Time[1][1]=Phase_Time[0][1]-Phase_Time[1][1];
//
//	PieCtrlRegs.PIEACK.all=PIEACK_GROUP3;		//????????????????
//	EvaRegs.EVAIFRC.bit.CAP2INT=1;				//??????????????
//	EINT;										//????????????
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT3.7
interrupt void CAPINT3_ISR(void)    // EV-A
{
  // Insert ISR Code here
//	static unsigned char flag=1;
//	if(flag)
//	{
//		AdcRegs.ADCTRL2.bit.SOC_SEQ1=1;				//????SEQ1
//	}
//	else
//	{
//		AdcRegs.ADCTRL2.bit.SOC_SEQ2=1;				//????SEQ2
//	}
//	flag=!flag;
//
//	PieCtrlRegs.PIEACK.all=PIEACK_GROUP3;		//????????????????
//	EvaRegs.EVAIFRC.bit.CAP3INT=1;				//??????????????
//	EINT;										//????????????
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}
      
// INT3.8 - Reserved


// -----------------------------------------------------------
// PIE Group 4 - MUXed into CPU INT4
// -----------------------------------------------------------

// INT 4.1
interrupt void CMP4INT_ISR(void)    // EV-B
{
  // Insert ISR Code here
  
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;  

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT4.2
interrupt void CMP5INT_ISR(void)    // EV-B
{
  // Insert ISR Code here
  
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT4.3
interrupt void CMP6INT_ISR(void)    // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT4.4
interrupt void T3PINT_ISR(void)     // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT4.5
interrupt void T3CINT_ISR(void)     // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT4.6
interrupt void T3UFINT_ISR(void)    // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT4.7
interrupt void T3OFINT_ISR(void)    // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}
     
// INT4.8 -- Reserved

// -----------------------------------------------------------
// PIE Group 5 - MUXed into CPU INT5
// -----------------------------------------------------------

// INT 5.1
interrupt void T4PINT_ISR(void)    // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT5.2
interrupt void T4CINT_ISR(void)    // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;
 
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT5.3
interrupt void T4UFINT_ISR(void)   // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;
  
  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT5.4
interrupt void T4OFINT_ISR(void)   // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT5.5
interrupt void CAPINT4_ISR(void)   // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT5.6
interrupt void CAPINT5_ISR(void)   // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT5.7
interrupt void CAPINT6_ISR(void)   // EV-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}


// INT5.8 - Reserved

// -----------------------------------------------------------
// PIE Group 6 - MUXed into CPU INT6
// -----------------------------------------------------------

// INT6.1
interrupt void SPIRXINTA_ISR(void)    // SPI-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT6.2
interrupt void SPITXINTA_ISR(void)     // SPI-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT6.3 - Reserved
// INT6.4 - Reserved

// INT6.5
interrupt void MRINTA_ISR(void)     // McBSP-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT6.6
interrupt void MXINTA_ISR(void)     // McBSP-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);
}

// INT6.7 - Reserved
// INT6.8 - Reserved


// -----------------------------------------------------------
// PIE Group 7 - MUXed into CPU INT7
// -----------------------------------------------------------

// INT7.1 - Reserved
// INT7.2 - Reserved
// INT7.3 - Reserved
// INT7.4 - Reserved
// INT7.5 - Reserved
// INT7.6 - Reserved
// INT7.7 - Reserved
// INT7.8 - Reserved

// -----------------------------------------------------------
// PIE Group 8 - MUXed into CPU INT8
// -----------------------------------------------------------

// INT8.1 - Reserved
// INT8.2 - Reserved
// INT8.3 - Reserved
// INT8.4 - Reserved
// INT8.5 - Reserved
// INT8.6 - Reserved
// INT8.7 - Reserved
// INT8.8 - Reserved


// -----------------------------------------------------------
// PIE Group 9 - MUXed into CPU INT9
// -----------------------------------------------------------

// INT9.1
interrupt void SCIRXINTA_ISR(void)     // SCI-A
{
  // Insert ISR Code here
//	static unsigned char flag=0;
//	unsigned char i=0;
//
//	switch(flag)
//	{
//		case 0:		//????????
//			CMNCT_rxbuff.Head=SciaRegs.SCIRXBUF.all;
//			if(CMNCT_rxbuff.Head==CMNCTION_HEAD)		//????????
//			{
//				flag=1;		//????????????
//			}
//			break;
//		case 1:		//????????
//			CMNCT_rxbuff.Type=SciaRegs.SCIRXBUF.all;
//			switch(CMNCT_rxbuff.Type)
//			{
//				case CMNCTION_DATA:
//				case CMNCTION_CMD:	flag=2;break;
//				default://????????
//					Send_CMD(CMNCTION_ERR_TYPE);
//					flag=0;		//????????????
//					break;
//			}
//			break;
//		case 2:		//????????
//			CMNCT_rxbuff.Len=SciaRegs.SCIRXBUF.all;
//			if(CMNCT_rxbuff.Len>BUFFER_SIZE)			//????FIFO????
//			{
//				//????????????
//				Send_CMD(CMNCTION_ERR_LEN);
//				flag=0;		//????????????
//			}
//			else
//			{
//				SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;	//??????????????????
//				SciaRegs.SCIFFRX.bit.RXFFIL=CMNCT_rxbuff.Len;
//
//				flag=3;			//????????????
//			}
//			break;
//		case 3:		//????????
//			for(i=0;i<CMNCT_rxbuff.Len;i++)
//			{
//				CMNCT_rxbuff.Data[i]=SciaRegs.SCIRXBUF.all;
//			}
//			flag=4;			//????????????
//
//			SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;	//??????????????????
//			SciaRegs.SCIFFRX.bit.RXFFIL=1;
//
//			break;
//		case 4:		//????????
//			CMNCT_rxbuff.Tail=SciaRegs.SCIRXBUF.all;
//			if(CMNCT_rxbuff.Tail==CMNCTION_TAIL)
//			{
//				if(CMNCT_rxbuff.Len<BUFFER_SIZE)
//				{
//					CMNCT_rxbuff.Data[CMNCT_rxbuff.Len]=CMNCT_rxbuff.Tail;		//????????
//				}
//				flag=5;
//			}
//			else
//			{
//				//??????????
//				Send_CMD(CMNCTION_ERR_TAIL);
//				flag=0;		//????????????
//			}
//			break;
//		case 5:
//			CMNCT_rxbuff.LRC=SciaRegs.SCIRXBUF.all;
//			if(CMNCT_rxbuff.LRC!=Calc_LRC((unsigned char *)(&CMNCT_rxbuff),CMNCT_rxbuff.Len+4))
//			{
//				//??????????
//				Send_CMD(CMNCTION_ERR_LRC);
//			}
//			flag=0;		//????????????
//		default:flag=0;break;
//	}
//	SciaRegs.SCIFFRX.bit.RXFIFORESET=0;
//	SciaRegs.SCIFFRX.bit.RXFIFORESET=1;
//	SciaRegs.SCIFFRX.bit.RXFFINTCLR=1;
//
//	PieCtrlRegs.PIEACK.bit.ACK9=1;			//????????????????????
//	EINT;

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);

}

// INT9.2
interrupt void SCITXINTA_ISR(void)     // SCI-A
{
  // Insert ISR Code here
//	static unsigned char flag=0;
//	unsigned char * tx_p;
//	unsigned char i=0;
//
//	switch(flag)
//	{
//		case 0:		//????????????????????
//			tx_p=(unsigned char *)(&CMNCT_txbuff.Head);
//			for(i=0;i<3;i++)
//			{
//				SciaRegs.SCITXBUF = *(tx_p+i);
//			}
//			flag=1;
//			SciaRegs.SCIFFTX.bit.TXINTCLR = 1;		//??????????????????????????????????
//			break;
//		case 1:		//????????
//			tx_p=(unsigned char *)(&CMNCT_txbuff.Data[0]);
//			for(i=0;i<CMNCT_txbuff.Len;i++)
//			{
//				SciaRegs.SCITXBUF = *(tx_p+i);
//			}
//			flag=2;
//			SciaRegs.SCIFFTX.bit.TXINTCLR = 1;		//??????????????????????????????????
//			break;
//		case 2:		//??????????????
//			tx_p=(unsigned char *)(&CMNCT_txbuff.Tail);
//			for(i=0;i<2;i++)
//			{
//				SciaRegs.SCITXBUF = *(tx_p+i);
//			}
//			flag=0;
//			break;
//		default:flag=0;break;
//	}
//
//	PieCtrlRegs.PIEACK.bit.ACK9=1;			//????????????????????
//	EINT;
  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);

}


// INT9.3
interrupt void SCIRXINTB_ISR(void)     // SCI-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);

}

// INT9.4
interrupt void SCITXINTB_ISR(void)     // SCI-B
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);

}

// INT9.5
interrupt void ECAN0INTA_ISR(void)  // eCAN-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);

}

// INT9.6
interrupt void ECAN1INTA_ISR(void)  // eCAN-A
{
  // Insert ISR Code here

  // To receive more interrupts from this PIE group, acknowledge this interrupt 
  // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
   asm ("      ESTOP0");
   for(;;);

}

// -----------------------------------------------------------
// PIE Group 10 - MUXed into CPU INT10
// -----------------------------------------------------------

// INT10.1 - Reserved
// INT10.2 - Reserved
// INT10.3 - Reserved
// INT10.4 - Reserved
// INT10.5 - Reserved
// INT10.6 - Reserved
// INT10.7 - Reserved
// INT10.8 - Reserved


// -----------------------------------------------------------
// PIE Group 11 - MUXed into CPU INT11
// -----------------------------------------------------------

// INT11.1 - Reserved
// INT11.2 - Reserved
// INT11.3 - Reserved
// INT11.4 - Reserved
// INT11.5 - Reserved
// INT11.6 - Reserved
// INT11.7 - Reserved
// INT11.8 - Reserved

// -----------------------------------------------------------
// PIE Group 12 - MUXed into CPU INT12
// -----------------------------------------------------------

// INT12.1 - Reserved
// INT12.2 - Reserved
// INT12.3 - Reserved
// INT12.4 - Reserved
// INT12.5 - Reserved
// INT12.6 - Reserved
// INT12.7 - Reserved
// INT12.8 - Reserved

//---------------------------------------------------------------------------
// Catch All Default ISRs: 
//

interrupt void EMPTY_ISR(void)  // Empty ISR - only does a return.
{

}

interrupt void PIE_RESERVED(void)  // Reserved space.  For test.
{
  asm ("      ESTOP0");
  for(;;);
}

interrupt void rsvd_ISR(void)      // For test
{
  asm ("      ESTOP0");
  for(;;);
}

//===========================================================================
// No more.
//===========================================================================

