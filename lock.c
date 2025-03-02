#include "matrix.h"
#include <REGX52.H>
#include "LCD1602.h"

#include "lock.h"
int set;
int key;
int current;
int password;
void showstatus()
{
	if(!set)
	LCD_ShowString(1,1,"nopassword");
	else
	LCD_ShowString(1,1,"password  ");
}
void inputnum()
{
		unsigned char count=0;
	
		while(1)
		{
			
			if(key)
			{
			  
				if(key==11)
				{
					if(current==password)
					{
						LCD_ShowString(1,14,"OK");
						current=0;
						count=0;
						LCD_ShowNum(2,1,current,4);
					}
					
					else
					{
						LCD_ShowString(1,14,"ERR");
						current=0;
						count=0;
						LCD_ShowNum(2,1,current,4);
					}
						
				}
				if(key==12)
				{
					current=0;
					count=0;
					LCD_ShowNum(2,1,current,4);
				}
				else if(key<=10&&count<4)
				{
		    current*=10;
		    current+=key%10;
			  count++;
		    LCD_ShowNum(2,1,current,4);
				
				}
			}
			key=keydetect();
		}
}
void setpassword()
	{
		unsigned char count=0;
		key=0;
		while(1)
		{
			key=keydetect();
			if(key)
			{
			  
				if(key==11)
				{
					
					count=0;
					set=1;
					LCD_ShowNum(2,1,0,4);
					key=0;
					return;
				}
				if(key==12)
				{
					password=0;
					count=0;
					LCD_ShowNum(2,1,0,4);
				}
				if(count<4&&key<=10)
				{
		    password*=10;
		    password+=key%10;
			  count++;
				}
		  }
			LCD_ShowNum(2,1,password,4);
		}
	}