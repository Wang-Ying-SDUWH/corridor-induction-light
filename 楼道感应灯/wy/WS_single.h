#ifndef _WS_single_h_
#define _WS_single_h_

#include <stc12.h>
#include <intrins.h>
#include <ws2812.h>

sbit k1=P2^1;      //常亮模式（单色）按键

void WS2812_single(u16 a,u16 b,u16 c);   //颜色设置函数，a、b、c分别代表RGB的值

u8 time;

u16  xdata Color_Lib[3][3]={       //颜色库，可根据需要增添或删减
	0,0,255,   //蓝色
	0,255,255,  //蓝绿
	255,255,0   //黄色
};


void WS2812_single(u16 a,u16 b,u16 c)
{
		u8 i,j;
		static u8 count=0;
		count++;
		if(count==60)
		{
				for(j=0;j<WSCOUNT;j++)
				{
						for(i=0;i<3;i++)
						{
							if(i==0)
								WS2812_BUffer[j][i]=a;
							else if (i ==1)
								WS2812_BUffer[j][i]=b;
							else 
								WS2812_BUffer[j][i]=c;
						}
				}
		}
		WS2812_Ser();
}

#endif