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