#include "../source/STC15F2K60S2.H"        // ����
#include "../source/sys.H"                 // ����
#include "../source/displayer.H"           // ��������ܺ� LED ��
#include "../source/key.H"

code unsigned long SysClock=11059200;         // ���롣����ϵͳ����ʱ��Ƶ��(Hz)���û������޸ĳ���ʵ�ʹ���Ƶ�ʣ�����ʱѡ��ģ�һ��
#ifdef _displayer_H_                          // ��ʾģ��ѡ��ʱ���롣���������ʾ������Ñ����޸ġ����ӵȣ� 
code char decode_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x08,0x40,0x01, 0x41, 0x48, 0x76, 0x38, 
	              /* ���:   0   1    2	   3    4	    5    6	  7   8	   9	 10	   11		12   13    14     15     16   17 */
                /* ��ʾ:   0   1    2    3    4     5    6    7   8    9  (��)   ��-  ��-  ��-  ����-  ����-   H    L  */  
	                       0x3f|0x80,0x06|0x80,0x5b|0x80,0x4f|0x80,0x66|0x80,0x6d|0x80,0x7d|0x80,0x07|0x80,0x7f|0x80,0x6f|0x80 };  
             /* ��С����     0         1         2         3         4         5         6         7         8         9        */
#endif

void myKeyCallBack() {
		char k;
	  k = GetKeyAct(enumKey1);
		if (k == enumKeyPress) 
			 Seg7Print(16);
		else 
			 Seg7Print(10);
}

void main() { 
	  DisplayerInit();  
	  SetDisplayerArea(0,0);
	
		Seg7Print(10); // �޸������Ĭ����ʾ 7 �� bug
	  LedPrint(0);   // �޸� LED ��Ĭ������� bug
	
	  KeyInit();
	  SetEventCallBack(enumEventKey, myKeyCallBack);
	
	  // ��ʼ������ϵͳ
    MySTC_Init();	    
	  while (1) { 
		  MySTC_OS();    
	  }	             
}                



