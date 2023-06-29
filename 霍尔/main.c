#include "../source/STC15F2K60S2.H"        //必须。
#include "../source/sys.H"                 //必须。
#include "../source/displayer.H" 
#include "../source/hall.H"


code unsigned long SysClock=11059200;         //必须。定义系统工作时钟频率(Hz)，用户必须修改成与实际工作频率（下载时选择的）一致
#ifdef _displayer_H_                          //显示模块选用时必须。（数码管显示译码表，用戶可修改、增加等） 
code char decode_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x08,0x40,0x01, 0x41, 0x48, 
	              /* 序号:   0   1    2	   3    4	    5    6	  7   8	   9	 10	   11		12   13    14     15     */
                /* 显示:   0   1    2    3    4     5    6    7   8    9  (无)   下-  中-  上-  上中-  中下-   */  
	                       0x3f|0x80,0x06|0x80,0x5b|0x80,0x4f|0x80,0x66|0x80,0x6d|0x80,0x7d|0x80,0x07|0x80,0x7f|0x80,0x6f|0x80 };  
             /* 带小数点     0         1         2         3         4         5         6         7         8         9        */
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
		char act = GetHallAct(); // 一次事件只能返回一个查询结果
														 // 此后事件结果变为 enumEventHall
	
	  // 磁场接近，打印1，开始流水灯作业
	  // 打印 1，表明正在作业
	  if (act == enumHallGetClose) {
			  Seg7Print(1, 10, 10, 10, 10, 10, 10, 10);	
				flag = 0x01;
		}
		// 磁场远离，打印0，停止流水灯作业
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
	
	  // 初始化操作系统
    MySTC_Init();	    
	  while (1) { 
		    MySTC_OS();    
		}	             
}                



