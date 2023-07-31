#include "../source/STC15F2K60S2.H"        
#include "../source/sys.H"                  
#include "../source/displayer.H" 
#include "../source/key.h"
#include "../source/hall.h"
#include "../source/Vib.h"
#include "../source/beep.h"
#include "../source/music.h"
#include "../source/adc.h"
#include "../source/uart1.h"
#include "../source/uart2.h"
#include "../source/stepmotor.h"
#include "../source/DS1302.h"
#include "../source/M24C02.h"
#include "../source/FM_Radio.h"	
#include "../source/EXT.h"
#include "../source/IR.h"


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