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

code unsigned long SysClock=11059200;         //必须。定义系统工作时钟频率(Hz)，用户必须修改成与实际工作频率（下载时选择的）一致
#ifdef _displayer_H_                          //显示模块选用时必须。（数码管显示译码表，用戶可修改、增加等） 
code char decode_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x08,0x40,0x01, 0x41, 0x48, 0x31,
	              /* 序号:   0   1    2	   3    4	    5    6	  7   8	   9	 10	   11		12   13    14     15    16 */
                /* 显示:   0   1    2    3    4     5    6    7   8    9  (无)   下-  中-  上-  上中-  中下-  镜像7 */  
	                       0x3f|0x80,0x06|0x80,0x5b|0x80,0x4f|0x80,0x66|0x80,0x6d|0x80,0x7d|0x80,0x07|0x80,0x7f|0x80,0x6f|0x80 };  
             /* 带小数点     0         1         2         3         4         5         6         7         8         9        */
#endif

/*
		数码管段选，从左至右
		1：小数点
		2：中
		3：左上
		4：左下
		5：下
		6：右下
		7：右上
		8：上

		编码规范：统一使用 Tab
		编程思路：利用串口通信，实现 PC 与下位机之间的通信
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

		// 导航上键被摁下
		if (up == enumKeyPress) 
				digit[index]++;
			
		// 导航下键被摁下
		if (down == enumKeyPress) 
				digit[index]--;
		
		// 导航左键被摁下
		if (left == enumKeyPress) 
				index--;
		
		// 导航右键被摁下
		if (right == enumKeyPress) 
				index++;
		
		// 导航中心键被摁下
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
		
		Seg7Print(10, 10, 10, 10, digit[0], digit[1], digit[2], digit[3]); // 打印数字到数码管

		// 以此判断手捂住了光敏电阻，代表历史问答关卡中勾选错误
		// 阈值需要根据环境条件作相应的调整，每次选择的时间控制在 1s 左右
		if (adc_result.Rop < 10) 
		  	myUart1RxdCallBack(0x09);
		
		// 以此判断用了手电筒之类的工具，代表历史问答关卡中勾选正确
		if (adc_result.Rop > 200) 
		  	myUart1RxdCallBack(0x0a);	
}

/* 为了连贯，舍弃超声波模块
void mytUltraSonicCallBack() {
		int distance = GetUltraSonic();
		Seg7Print(10, 10, 10, 10, distance/1000, (distance%1000)/100, (distance%100)/10, distance%10);	
		if (distance < 10)
				myUart1RxdCallBack(0x02);
}
*/

void main() { 
		// 初始化模块
		DisplayerInit();  
		BeepInit();
		MusicPlayerInit();
		VibInit();
		KeyInit();
		AdcInit(ADCexpEXT); 
		Uart1Init(1200);
		// EXTInit(enumEXTUltraSonic); 为了连贯，舍弃超声波模块

		SetDisplayerArea(0,7);	
	
		// 展示 8、24 号球衣，5 次总冠军
		// 演奏一小部分《Hall of fame》
		Seg7Print(8, 10, 7, 16, 0, 10, 2, 4);	 
		LedPrint(led);
		SetMusic(167, 0xFA, hall_of_fame, 8, enumMscNull);
		SetPlayerMode(enumModePlay); 
	
		SetEventCallBack(enumEventVib, myVibCallBack); // 进入游戏关卡
		SetEventCallBack(enumEventKey, myKeyCallBack); // 服务于手速关卡
		SetEventCallBack(enumEventNav, myKNCallBack);  // 服务于猜数字关卡
		SetEventCallBack(enumEventSys1S, myRopCallBack); // 服务于猜数字关卡 & 历史问答关卡
		// SetEventCallBack(enumEventSys1S, mytUltraSonicCallBack); 为了连贯，舍弃超声波模块
		
	  // 初始化操作系统
		MySTC_Init();	    
		while (1) { 
				MySTC_OS();    
		}	             
}                



