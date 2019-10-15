#include <ws2812.h>
#include <WS_single.h>
#include <WS_muti.h>
#include <stc12.h>

u16 xdata i=0;

void main()
{	
 	while(1)
	{
		if(k1==0)		  //检测按键K1是否按下
		{	
			delay(1000);   //消除抖动，一般大约10ms
			if(k1==0)	 //再次判断按键是否按下
			{
				 time++;
			}	
		  if(time==4)
			  time=1;
			while(!k1);	
	  }
		switch(time)    //一个按键控制多种颜色
		{
			case 1:
				WS2812_single(Color_Lib[0][0],Color_Lib[0][1],Color_Lib[0][2]);
			  break;
			case 2:
				WS2812_single(Color_Lib[1][0],Color_Lib[1][1],Color_Lib[1][2]);
			  break;
			case 3:
				WS2812_single(Color_Lib[2][0],Color_Lib[2][1],Color_Lib[2][2]);
   			break;
			default:break;
		}
    keypros2();    //炫彩色按键函数
	}
 }

 