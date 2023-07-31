#include "../source/STC15F2K60S2.H"        
#include "../source/sys.H"                 
#include "../source/displayer.H" 
#include "../source/music.h"
#include "../source/beep.h"
#include "../source/Vib.h"
#include "../source/uart1.h"
#include "../source/Key.H"
#include "../source/adc.h"
//#include "../source/EXT.h"

code unsigned long SysClock=11059200;         //���롣����ϵͳ����ʱ��Ƶ��(Hz)���û������޸ĳ���ʵ�ʹ���Ƶ�ʣ�����ʱѡ��ģ�һ��
#ifdef _displayer_H_                          //��ʾģ��ѡ��ʱ���롣���������ʾ������Ñ����޸ġ����ӵȣ� 
code char decode_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x08,0x40,0x01, 0x41, 0x48, 0x31,
	              /* ���:   0   1    2	   3    4	    5    6	  7   8	   9	 10	   11		12   13    14     15    16 */
                /* ��ʾ:   0   1    2    3    4     5    6    7   8    9  (��)   ��-  ��-  ��-  ����-  ����-  ����7 */  
	                       0x3f|0x80,0x06|0x80,0x5b|0x80,0x4f|0x80,0x66|0x80,0x6d|0x80,0x7d|0x80,0x07|0x80,0x7f|0x80,0x6f|0x80 };  
             /* ��С����     0         1         2         3         4         5         6         7         8         9        */
#endif

/*
		����ܶ�ѡ����������
		1��С����
		2����
		3������
		4������
		5����
		6������
		7������
		8����

		����淶��ͳһʹ�� Tab
		���˼·�����ô���ͨ�ţ�ʵ�� PC ����λ��֮���ͨ��
 */


unsigned char led = 0x05;
unsigned char flag = 0x00;
		

unsigned char hall_of_fame[] = {0x31, 0x20, 0x27, 0x20, 0x31, 0x20, 0x26, 0x20};
/*
																0x31, 0x20, 0x23, 0x20, 0x31, 0x20, 0x24, 0x20,
																0x31, 0x20, 0x24, 0x20, 0x34, 0x20, 0x24, 0x20,
																0x31, 0x20, 0x24, 0x20, 0x34, 0x20, 0x24, 0x20,
																0x33, 0x20, 0x31, 0x20, 0x34, 0x20, 0x31, 0x20,
																0x35, 0x20, 0x31, 0x20, 0x32, 0x20, 0x31, 0x20,
																0x32, 0x20, 0x25, 0x20, 0x35, 0x20, 0x25, 0x20,
																0x32, 0x20, 0x25, 0x20, 0x35, 0x20, 0x25, 0x20};
*/

unsigned char rxd[3]={0xaa, 0x55, 0x00}; 

void myUart1RxdCallBack(const unsigned char signal) { 
		rxd[2] = signal;
		Uart1Print(&rxd, sizeof(rxd));
}

void myVibCallBack() {
		if (GetVibAct() == enumVibQuake)
				myUart1RxdCallBack(0x01);
}

void myKeyCallBack() {
		if (GetKeyAct(enumKey1) == enumKeyPress) 
				myUart1RxdCallBack(0x03);
}

unsigned char index = 0;
unsigned char digit[4] = {0, 0, 0, 0};

void myKNCallBack() {
		char up = GetAdcNavAct(enumAdcNavKeyUp);
		char down = GetAdcNavAct(enumAdcNavKeyDown);
		char right = GetAdcNavAct(enumAdcNavKeyRight);
	  char left = GetAdcNavAct(enumAdcNavKeyLeft);
		char center = GetAdcNavAct(enumAdcNavKeyCenter);

		// �����ϼ�������
		if (up == enumKeyPress) 
				digit[index]++;
			
		// �����¼�������
		if (down == enumKeyPress) 
				digit[index]--;
		
		// �������������
		if (left == enumKeyPress) 
				index--;
		
		// �����Ҽ�������
		if (right == enumKeyPress) 
				index++;
		
		// �������ļ�������
		if (center == enumKeyPress) {
				if (digit[0] == 1 && digit[1] == 9 && digit[2] == 9 && digit[3] == 6) {
						myUart1RxdCallBack(0x08);
						digit[0] = digit[1] = digit[2] = digit[3] = 10;
				}
				else {
						myUart1RxdCallBack(0x07);
						digit[0] = digit[1] = digit[2] = digit[3] = 0;
				}	
		}
}

void myRopCallBack() {
		struct_ADC adc_result;
		adc_result = GetADC();
		
		Seg7Print(10, 10, 10, 10, digit[0], digit[1], digit[2], digit[3]); // ��ӡ���ֵ������

		// �Դ��ж�����ס�˹������裬������ʷ�ʴ�ؿ��й�ѡ����
		// ��ֵ��Ҫ���ݻ�����������Ӧ�ĵ�����ÿ��ѡ���ʱ������� 1s ����
		if (adc_result.Rop < 10) 
		  	myUart1RxdCallBack(0x09);
		
		// �Դ��ж������ֵ�Ͳ֮��Ĺ��ߣ�������ʷ�ʴ�ؿ��й�ѡ��ȷ
		if (adc_result.Rop > 200) 
		  	myUart1RxdCallBack(0x0a);	
}

/* Ϊ�����ᣬ����������ģ��
void mytUltraSonicCallBack() {
		int distance = GetUltraSonic();
		Seg7Print(10, 10, 10, 10, distance/1000, (distance%1000)/100, (distance%100)/10, distance%10);	
		if (distance < 10)
				myUart1RxdCallBack(0x02);
}
*/

void main() { 
		// ��ʼ��ģ��
		DisplayerInit();  
		BeepInit();
		MusicPlayerInit();
		VibInit();
		KeyInit();
		AdcInit(ADCexpEXT); 
		Uart1Init(1200);
		// EXTInit(enumEXTUltraSonic); Ϊ�����ᣬ����������ģ��

		SetDisplayerArea(0,7);	
	
		// չʾ 8��24 �����£�5 ���ܹھ�
		// ����һС���֡�Hall of fame��
		Seg7Print(8, 10, 7, 16, 0, 10, 2, 4);	 
		LedPrint(led);
		SetMusic(167, 0xFA, hall_of_fame, 8, enumMscNull);
		SetPlayerMode(enumModePlay); 
	
		SetEventCallBack(enumEventVib, myVibCallBack); // ������Ϸ�ؿ�
		SetEventCallBack(enumEventKey, myKeyCallBack); // ���������ٹؿ�
		SetEventCallBack(enumEventNav, myKNCallBack);  // �����ڲ����ֹؿ�
		SetEventCallBack(enumEventSys1S, myRopCallBack); // �����ڲ����ֹؿ� & ��ʷ�ʴ�ؿ�
		// SetEventCallBack(enumEventSys1S, mytUltraSonicCallBack); Ϊ�����ᣬ����������ģ��
		
	  // ��ʼ������ϵͳ
		MySTC_Init();	    
		while (1) { 
				MySTC_OS();    
		}	             
}                



