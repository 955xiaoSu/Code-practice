#include "../source/STC15F2K60S2.H"        //必须。
#include "../source/sys.H"                 //必须。
#include "../source/displayer.H" 

code unsigned long SysClock=11059200;         //必须。定义系统工作时钟频率(Hz)，用户必须修改成与实际工作频率（下载时选择的）一致
#ifdef _displayer_H_                          //显示模块选用时必须。（数码管显示译码表，用戶可修改、增加等） 
code char decode_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x08,0x40,0x01, 0x41, 0x48, 
	              /* 序号:   0   1    2	   3    4	    5    6	  7   8	   9	 10	   11		12   13    14     15     */
                /* 显示:   0   1    2    3    4     5    6    7   8    9  (无)   下-  中-  上-  上中-  中下-   */  
	                       0x3f|0x80,0x06|0x80,0x5b|0x80,0x4f|0x80,0x66|0x80,0x6d|0x80,0x7d|0x80,0x07|0x80,0x7f|0x80,0x6f|0x80 };  
             /* 带小数点     0         1         2         3         4         5         6         7         8         9        */
#endif

// 对数码管每一位进行控制，下标在 0 ~ 9，满 60 进一分

unsigned char millisecond_1 = 0;
unsigned char millisecond_2 = 0;
unsigned char millisecond_3 = 0;

unsigned char second_1 = 0;
unsigned char second_2 = 0;

unsigned char minute = 0;

unsigned char led = 0x00; // 十进制计数

void my1msCallBack() {
		millisecond_3 += 1;
	
		if (millisecond_3 >= 10) {
				millisecond_3 = 0;
				millisecond_2 += 1;
		}
		if (millisecond_2 >= 10) {
				millisecond_2 = 0;
				millisecond_1 += 1;
		}
		if (millisecond_1 >= 10) 
				millisecond_1 = 0;
		
		Seg7Print(minute, 12, second_1, second_2, 12, millisecond_1, millisecond_2, millisecond_3);
}

void my1sCallBack() {
		second_2 += 1;
		
		if (second_2 >= 10) {
				second_2 = 0;
				second_1 += 1;
		}
		if (second_1 >= 6) {
				second_1 = 0;
				minute += 1;
		}
		if (minute >= 10) {
				minute = 0;
			  led += 1;
		}		
		
		LedPrint(led);
}

void main() { 
  	DisplayerInit();  
	
		SetDisplayerArea(0,7);	
		Seg7Print(0, 12, 0, 0, 12, 0, 0, 0); // 初始化打印”0-00-000“
		LedPrint(led);
		
    SetEventCallBack(enumEventSys1mS, my1msCallBack);
		SetEventCallBack(enumEventSys1S, my1sCallBack);	
	
	  // 初始化操作系统
    MySTC_Init();	    
	  while (1) { 
		    MySTC_OS();    
		}	             
}                



