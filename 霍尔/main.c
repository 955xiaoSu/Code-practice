#include "../source/STC15F2K60S2.H"        //���롣
#include "../source/sys.H"                 //���롣
#include "../source/displayer.H" 
#include "../source/hall.H"


code unsigned long SysClock=11059200;         //���롣����ϵͳ����ʱ��Ƶ��(Hz)���û������޸ĳ���ʵ�ʹ���Ƶ�ʣ�����ʱѡ��ģ�һ��
#ifdef _displayer_H_                          //��ʾģ��ѡ��ʱ���롣���������ʾ������Ñ����޸ġ����ӵȣ� 
code char decode_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x08,0x40,0x01, 0x41, 0x48, 
	              /* ���:   0   1    2	   3    4	    5    6	  7   8	   9	 10	   11		12   13    14     15     */
                /* ��ʾ:   0   1    2    3    4     5    6    7   8    9  (��)   ��-  ��-  ��-  ����-  ����-   */  
	                       0x3f|0x80,0x06|0x80,0x5b|0x80,0x4f|0x80,0x66|0x80,0x6d|0x80,0x7d|0x80,0x07|0x80,0x7f|0x80,0x6f|0x80 };  
             /* ��С����     0         1         2         3         4         5         6         7         8         9        */
#endif

unsigned char led = 0x0f;
unsigned char flag = 0x00;

void my100msCallBack() {
		if (flag) {
			  if (led == 0x87)  led = 0x0f;
			  else if (led == 0xc3)  led = 0x87;
			  else if (led == 0xe1)  led = 0xc3;
			  else if (led == 0xf0)  led = 0xe1;
			  else  led = led<<1;
		}

		LedPrint(led);
}

void myHallCallBack(){ 
		char act = GetHallAct(); // һ���¼�ֻ�ܷ���һ����ѯ���
														 // �˺��¼������Ϊ enumEventHall
	
	  // �ų��ӽ�����ӡ1����ʼ��ˮ����ҵ
	  // ��ӡ 1������������ҵ
	  if (act == enumHallGetClose) {
			  Seg7Print(1, 10, 10, 10, 10, 10, 10, 10);	
				flag = 0x01;
		}
		// �ų�Զ�룬��ӡ0��ֹͣ��ˮ����ҵ
		else if (act == enumHallGetAway) {
				Seg7Print(0, 10, 10, 10, 10, 10, 10, 10);	
				flag = 0x00;
		}
}

void main() { 
  	DisplayerInit();  
		HallInit();
	
		SetDisplayerArea(0,7);	
	  Seg7Print(10, 10, 10, 10, 10, 10, 10, 10);	
	  LedPrint(led);
	
    SetEventCallBack(enumEventHall, myHallCallBack);
	  SetEventCallBack(enumEventSys100mS, my100msCallBack);
	
	  // ��ʼ������ϵͳ
    MySTC_Init();	    
	  while (1) { 
		    MySTC_OS();    
		}	             
}                



