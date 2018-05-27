#ifndef ILI9341_H__
#define ILI9341_H__

#include "lpc11xx.h"

#define     RED          0XF800	  //红色
#define     GREEN        0X07E0	  //绿色
#define     BLUE         0X001F	  //蓝色
#define     WHITE        0XFFFF	  //白色
#define     BLACK        0X0000	  //黑色
#define     YELLOW       0XFFE0	  //黄色
#define     ORANGE       0XFC08	  //橙色
#define     GRAY  	     0X8430   //灰色
#define     LGRAY        0XC618	  //浅灰色
#define     DARKGRAY     0X8410	  //深灰色
#define     PORPO        0X801F	  //紫色
#define     PINK         0XF81F	  //粉红色
#define     GRAYBLUE     0X5458   //灰蓝色
#define     LGRAYBLUE    0XA651   //浅灰蓝色
#define     DARKBLUE     0X01CF	  //深灰蓝色
#define 		LIGHTBLUE    0X7D7C	  //浅蓝色

#define OUT_DATA(value)	 LPC_GPIO2->DATA =(value<<4)
#define LCD_CS_SET LPC_GPIO3->DATA|=(1<<1)
#define LCD_CS_CLR LPC_GPIO3->DATA&=~(1<<1)
#define LCD_RS_SET LPC_GPIO3->DATA|=(1<<0)
#define LCD_RS_CLR LPC_GPIO3->DATA&=~(1<<0)
#define LCD_WR_SET LPC_GPIO1->DATA|=(1<<11)
#define LCD_WR_CLR LPC_GPIO1->DATA&=~(1<<11)

extern uint16_t  POINT_COLOR;
extern uint16_t  BACK_COLOR;

extern void LCD_WR_DATA(uint16_t val);
extern void LCD_WR_REG(uint16_t reg);
extern void LCD_Init(void);
extern void LCD_XYRAM(uint16_t stx,uint16_t sty,uint16_t endx,uint16_t endy);
extern void LcdWirteColorData(uint16_t color);
extern void LCD_Clear(uint16_t color);
extern void LCD_DrawPoint(uint16_t x, uint16_t y);
extern void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
extern void LCD_DrawRectage(uint16_t xstart,uint16_t ystart,uint16_t xend,uint16_t yend);
extern void LCD_Fill(uint16_t xstart, uint16_t ystart, uint16_t xend, uint16_t yend);
extern void LCD_DrawCircle(uint8_t x0, uint16_t y0, uint8_t r);
extern void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t num);


#endif



