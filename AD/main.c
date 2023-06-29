#include "../source/STC15F2K60S2.H"        //���롣
#include "../source/sys.H"                 //���롣
#include "../source/displayer.H" 
#include "../source/adc.h"
#include "../source/Key.H"


code unsigned long SysClock=11059200;         //���롣����ϵͳ����ʱ��Ƶ��(Hz)���û������޸ĳ���ʵ�ʹ���Ƶ�ʣ�����ʱѡ��ģ�һ��
#ifdef _displayer_H_                          //��ʾģ��ѡ��ʱ���롣���������ʾ������Ñ����޸ġ����ӵȣ� 
code char decode_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x08,0x40,0x01, 0x41, 0x48, 
	              /* ���:   0   1    2	   3    4	    5    6	  7   8	   9	 10	   11		12   13    14     15     */
                /* ��ʾ:   0   1    2    3    4     5    6    7   8    9  (��)   ��-  ��-  ��-  ����-  ����-   */  
	                       0x3f|0x80,0x06|0x80,0x5b|0x80,0x4f|0x80,0x66|0x80,0x6d|0x80,0x7d|0x80,0x07|0x80,0x7f|0x80,0x6f|0x80 };  
             /* ��С����     0         1         2         3         4         5         6         7         8         9        */
#endif

unsigned char led = 0x18;

void myKNCallBack(){ 
	  char right = GetAdcNavAct(enumAdcNavKeyRight);
	  char left = GetAdcNavAct(enumAdcNavKeyLeft);
		
		// �����Ҽ�������
		if (right == enumKeyPress) {
		  	if (led == 0x81)  led = 0xc0;
				else if (led == 0x03)  led = 0x81;
				else  led = led>>1;
		}
		
		// �������������
		if (left == enumKeyPress) {
			  if (led == 0x81)  led = 0x03;  
				else if (led == 0xc0)  led = 0x81;
				else  led = led<<1;
		}
		
		LedPrint(led);
}

void main() { 
  	DisplayerInit();  
		AdcInit(ADCexpEXT);
	
		SetDisplayerArea(0,7);	
		Seg7Print(10, 10, 10, 10, 10, 10, 10, 10);
	  LedPrint(led);
	
    SetEventCallBack(enumEventNav, myKNCallBack);
	
	  // ��ʼ������ϵͳ
    MySTC_Init();	    
	  while (1) { 
		    MySTC_OS();    
		}	             
}                



