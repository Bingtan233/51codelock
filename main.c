
#include <REGX52.H>
#include <INTRINS.H>
#include "LCD1602.h"
#include "matrix.h"
#include "lock.h"
extern int password;
extern int set;
extern int key;
extern int current;

void main()
{
	LCD_Init();
	while(1)
	{
	 showstatus();
	 key=keydetect();
	if(key)
	{
	if(key==13&&set==0)//13ÎªÉèÖÃÃÜÂë
	{
		setpassword();
		showstatus();
	}
	if(set==1&&key<=10)
	 inputnum();
   } 
	}
}