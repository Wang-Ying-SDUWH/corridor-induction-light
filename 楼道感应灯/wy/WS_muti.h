#ifndef _WS_muti_h_
#define _WS_muti_h_


#include <stc12.h>
#include <ws2812.h>
#include <WS_single.h>

#define sum 1080

sbit k2=P2^2;      //��Ӧģʽ���Ų�ɫ)����

sbit rsd=P1^4;      //�����Ӧģ��
sbit signal=P1^0;   //��������ģ��
sbit led1=P1^2;      //��Ӧģʽָʾ��

u16 xdata cnt=0;
u8 xdata color2[WSCOUNT][3];
u8 code length=60;
u8 code cond=18;
u8 code beha[18][3]={
//�� �� ��
'0','0','0',
'+','0','0',//60,00,00-1
'=','+','0',//60,60,00-2
'=','=','+',//60,60,60-3
'-','=','=',//00,60,60-2
'0','-','-',//00-00-00
'0','0','0',//00-00-00
	
'0','+','0',//00,00,60-1
'0','=','+',//60-00-60-2
'+','=','=',//60-60-60-3
'=','-','=',//60-60-00-2
'-','0','-',//00-60-00-1
'0','0','0',//00-60-60-2
	
'0','0','+',//00,00,60-1
'+','0','=',//60-00-60-2
'=','+','=',//60-60-60-3
'=','=','-',//60-60-00-2	
'-','-','0',//00-60-00-1
//00-60-60-2
};

void color_get(u16 cc);
void WS2812_muti();
void keypros2();

void color_get(u16 cc)
{
	u16 i=0,j,k,m;
	u8 shu=0;
	for(k=cc/60;k<cond;k++)//12��
	{
			j=cc%60;
			cc=0;
			for(j=0;j<60;j++)//ÿ��60��
			{		
					for(m=0;m<3;m++)   //ÿ��������ɫ
					{
							switch(beha[k][m])  //ÿ����ɫ4�����,ʵ����ɫƽ������
							{
								case '0':color2[shu][m]=0;break;
								case '=':color2[shu][m]=60;break;
								case '-':color2[shu][m]=59-j;break;
								case '+':color2[shu][m]=j;break;	
							}
					}
					shu++;
					if(shu==60)
						break;
			}
			if(shu==60)
						break;
	}
}
void WS2812_muti()
{
		u8 i;
		static u8 count=0;
		count++;
		if(count>40)
		{
				count=0;
				for(i=0;i<WSCOUNT;i++)
				{
						WS2812_BUffer[i][0]=color2[i][0];
						WS2812_BUffer[i][1]=color2[i][1];
						WS2812_BUffer[i][2]=color2[i][2];
				}
		}
		WS2812_Ser();
}
void keypros2()
{
		u16 i=0;
	  if(k2==0)		  
	  {	
		delay(1000);   
		if(k2==0)			
		{
			led1=0;
      if(rsd==1&&signal==1)      //�������찵ʱ����
			{
				while(1)
				{
				i++;
				if(i>520)
					{
				   i=0;
				   cnt++;
				   cnt%=sum;
				   color_get(cnt);
			     }
			  WS2812_muti();
			  }
		  }
			else                        //�����������ɫδ��ʱ����
			{
	      WS2812_single(0,0,0);     
      }
		}
	}
}

#endif