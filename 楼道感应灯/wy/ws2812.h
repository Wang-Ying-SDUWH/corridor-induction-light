#ifndef __WS2812_H_
#define __WS2812_H_

#include <stc12.h>

sbit k=P1^3;                  //�ƴ��ӵ�Ƭ����Din
#define WSCOUNT 30            //һ��WS2812�ƴ��ϵ���ĸ���
u8 WS2812_BUffer[WSCOUNT][3];    

void WS2812_write_date();     //��������
void WS2812_Ser();            //WS2812�ƴ�ˢ��Ƶ��
void delay(u16 i);            //��ʱ

void WS2812_write_date()
{	
		bit w0,w1,w2,w3,w4,w5,w6,w7;     //һ�����ݰ�λ
		u8 i,j,shu;
		for(i=0;i<WSCOUNT;i++)
		for(j=0;j<3;j++)
		{
				switch(j)                              
				{
					case 0:shu=WS2812_BUffer[i][1];break;       //�������ݵĹ���ΪGRB
					case 1:shu=WS2812_BUffer[i][0];break;
					case 2:shu=WS2812_BUffer[i][2];break;
					
				}
				w7=shu&0x80;w6=shu&0x40;
				w5=shu&0x20;w4=shu&0x10;
				w3=shu&0x08;w2=shu&0x04;
				w1=shu&0x02;w0=shu&0x01;
			
				k=0;                  //����0���1��
				if(w7) k=1;
				else k=0;
				k=1; k=0;
				if(w6) k=1;
				else k=0;
				k=1; k=0;
				if(w5) k=1;
				else k=0;
				k=1; k=0;
				if(w4) k=1;
				else k=0;
				k=1; k=0;
				if(w3) k=1;
				else k=0;
				k=1; k=0;
				if(w2) k=1;
				else k=0;
				k=1; k=0;
				if(w1) k=1;
				else k=0;
				k=1; k=0;
				if(w0) k=1;
				else k=0;
				k=1; k=0;
		}
}
void WS2812_Ser()
{
		static u8 count=0;       //������������¼Ser�������д���
		count++;
		switch(count)
		{
			case 1:k=0;break;
			case 50:EA=0;WS2812_write_date();EA=1;break;
			case 51:k=0;break;
		}
		count%=60;
}
void delay(u16 i)
{
	while(i--);
	}

#endif