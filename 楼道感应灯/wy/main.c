#include <ws2812.h>
#include <WS_single.h>
#include <WS_muti.h>
#include <stc12.h>

u16 xdata i=0;

void main()
{	
 	while(1)
	{
		if(k1==0)		  //��ⰴ��K1�Ƿ���
		{	
			delay(1000);   //����������һ���Լ10ms
			if(k1==0)	 //�ٴ��жϰ����Ƿ���
			{
				 time++;
			}	
		  if(time==4)
			  time=1;
			while(!k1);	
	  }
		switch(time)    //һ���������ƶ�����ɫ
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
    keypros2();    //�Ų�ɫ��������
	}
 }

 