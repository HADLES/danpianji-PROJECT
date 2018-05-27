/************************************************************************************** 
*   日期    ：2015年2月15日  
*   目标    ：ARM Cortex-M0 LPC1114 
*   编译环境：KEIL 5.13
*   外部晶振：10Mhz(主频50M)
*   功能    ：液晶显示器显示英文字符
*   作者    ：瑞生(Ration)
*   官方网址：http://www.rationmcu.com
**************************************************************************************/
#include "lpc11xx.h"
#include "ili9341.h"

volatile void delay()
{
	uint32_t i;
	
	i=10000000;
	while(i--);
}

int main()
{
	LCD_Init(); // 液晶屏初始化
	LCD_Clear(WHITE); // 显示白色
	LCD_ShowChar(10, 10, 'A');
	LCD_ShowChar(18, 10, 'B');
	LCD_ShowChar(26, 10, 'C');
	
	while(1)
	{
		;
	}
}








