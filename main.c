
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
    LCD_Init();  // 初始化 LCD
    while (1)  // 主循环
    {
        showstatus();  // 显示状态
        key = keydetect();  // 检测按键

        if (key)  // 如果有按键按下
        {
            if (key == 13 && set == 0)  // 13 是设置密码的按键
            {
                setpassword();  // 设置密码
                showstatus();  // 更新状态显示
            }

            if (set == 1 && key <= 10)  // 如果已设置密码且按键为数字键
            {
                inputnum();  // 输入数字
            }
        }
    }
}
