#include "RGB_interface.h"
#include "RGB_private.h"


void Color_Choose(Color_type color)
{    
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	TCNT1=0;
	TCNT0=0;
	ICR1=255;
	OCR0=Colors[color][0];
	OCR1A=Colors[color][1];
	OCR1B=Colors[color][2];
}
void Switch_Colors (Color_type color_from ,Color_type color_to)
{  u8 flag0=0,flag1=0,flag2=0,c=0,i;
	
		for(i=0;i<255;i++)
		{   c=0;
			if((Colors[color_from][0]<Colors[color_to][0])&&flag0<=1)
			{   
				c++;
				Colors[color_from][0]++;
				OCR0=Colors[color_from][0];
				flag0=1;
			}
			else if (Colors[color_from][0]>Colors[color_to][0]&&(flag0==0||flag0==2))
			{
				c++;
				Colors[color_from][0]--;
				OCR0=Colors[color_from][0];
				flag0=2;
			}
				if((Colors[color_from][1]<Colors[color_to][1])&&flag1<=1)
				{  
					c++;
					Colors[color_from][1]++;
					OCR1A=Colors[color_from][1];
					flag1=1;
				}
				else if (Colors[color_from][1]>Colors[color_to][1]&&(flag1==0||flag1==2))
				{
					c++;
					Colors[color_from][1]--;
					OCR1A=Colors[color_from][1];
					flag1=2;
				}
				if((Colors[color_from][2]<Colors[color_to][2])&&flag2<=1)
				{
					c++;
					Colors[color_from][2]++;
					OCR1B=Colors[color_from][2];
					flag2=1;
				}
				else if (Colors[color_from][2]>Colors[color_to][2]&&(flag2==0||flag2==2))
				{
					c++;
					Colors[color_from][2]--;
					OCR1B=Colors[color_from][2];
					flag2=2;
				}
				if(c==0)
				{
					break;
				}
				_delay_ms(5);
		}
}