#include "lpc11xx.h"
#include "ili9341.h"
#include "ascii.h"

uint16_t  POINT_COLOR=BLACK;
uint16_t  BACK_COLOR=WHITE;

volatile void delay_tft(uint32_t i)
{
	i=i*5000;
	while(i--);
}

void LCD_WR_DATA(uint16_t val)
{  
	LCD_RS_SET;  //RS=1;
	LCD_CS_CLR;	//CS=0;
	OUT_DATA(val);					
	LCD_WR_CLR;	//WR=0;
	LCD_WR_SET;	//WR=1;
	LCD_CS_SET;	//CS=1;	
}

void LCD_WR_REG(uint16_t reg)		
{	
  LCD_RS_CLR;	//RS=0;
	LCD_CS_CLR;	//CS=0;	
	OUT_DATA(reg);		
	LCD_WR_CLR;	//WR=0;
	LCD_WR_SET;	//WR=1;
	LCD_CS_SET;	//CS=1;		
}

void LCD_Init()
{
	LPC_GPIO1->DIR|=(1<<11);
	LPC_GPIO1->DATA|=(1<<11);
	LPC_GPIO3->DIR|=(1<<0);
	LPC_GPIO3->DATA|=(1<<0);
	LPC_GPIO3->DIR|=(1<<1);
	LPC_GPIO3->DATA|=(1<<1);
	LPC_GPIO3->DIR|=(1<<3);
	LPC_GPIO3->DATA|=(1<<3);
	LPC_GPIO2->DIR|=0XFF0;
	LPC_GPIO2->DATA|=0XFF0;
	
	delay_tft(120);

	LCD_WR_REG(0xCF);  
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0xC1); 
	LCD_WR_DATA(0X30); 
	LCD_WR_REG(0xED);  
	LCD_WR_DATA(0x64); 
	LCD_WR_DATA(0x03); 
	LCD_WR_DATA(0X12); 
	LCD_WR_DATA(0X81); 
	LCD_WR_REG(0xE8);  
	LCD_WR_DATA(0x85); 
	LCD_WR_DATA(0x10); 
	LCD_WR_DATA(0x7A); 
	LCD_WR_REG(0xCB);  
	LCD_WR_DATA(0x39); 
	LCD_WR_DATA(0x2C); 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x34); 
	LCD_WR_DATA(0x02); 
	LCD_WR_REG(0xF7);  
	LCD_WR_DATA(0x20); 
	LCD_WR_REG(0xEA);  
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x00); 
	LCD_WR_REG(0xC0);    //Power control 
	LCD_WR_DATA(0x1B);   //VRH[5:0] 
	LCD_WR_REG(0xC1);    //Power control 
	LCD_WR_DATA(0x01);   //SAP[2:0];BT[3:0] 
	LCD_WR_REG(0xC5);    //VCM control 
	LCD_WR_DATA(0x30); 	 //3F
	LCD_WR_DATA(0x30); 	 //3C
	LCD_WR_REG(0xC7);    //VCM control2 
	LCD_WR_DATA(0XB7); 
	LCD_WR_REG(0x36);    // Memory Access Control 
	LCD_WR_DATA(0x08); 
	LCD_WR_REG(0x3A);   
	LCD_WR_DATA(0x55); 
	LCD_WR_REG(0xB1);   
	LCD_WR_DATA(0x00);   
	LCD_WR_DATA(0x1A); 
	LCD_WR_REG(0xB6);    // Display Function Control 
	LCD_WR_DATA(0x0A); 
	LCD_WR_DATA(0xA2); 
	LCD_WR_REG(0xF2);    // 3Gamma Function Disable 
	LCD_WR_DATA(0x00); 
	LCD_WR_REG(0x26);    //Gamma curve selected 
	LCD_WR_DATA(0x01); 
	LCD_WR_REG(0xE0);    //Set Gamma 
	LCD_WR_DATA(0x0F); 
	LCD_WR_DATA(0x2A); 
	LCD_WR_DATA(0x28); 
	LCD_WR_DATA(0x08); 
	LCD_WR_DATA(0x0E); 
	LCD_WR_DATA(0x08); 
	LCD_WR_DATA(0x54); 
	LCD_WR_DATA(0XA9); 
	LCD_WR_DATA(0x43); 
	LCD_WR_DATA(0x0A); 
	LCD_WR_DATA(0x0F); 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x00); 		 
	LCD_WR_REG(0XE1);    //Set Gamma 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x15); 
	LCD_WR_DATA(0x17); 
	LCD_WR_DATA(0x07); 
	LCD_WR_DATA(0x11); 
	LCD_WR_DATA(0x06); 
	LCD_WR_DATA(0x2B); 
	LCD_WR_DATA(0x56); 
	LCD_WR_DATA(0x3C); 
	LCD_WR_DATA(0x05); 
	LCD_WR_DATA(0x10); 
	LCD_WR_DATA(0x0F); 
	LCD_WR_DATA(0x3F); 
	LCD_WR_DATA(0x3F); 
	LCD_WR_DATA(0x0F); 
	LCD_WR_REG(0x2B); 
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x01);
	LCD_WR_DATA(0x3f);
	LCD_WR_REG(0x2A); 
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0xef);	 
	LCD_WR_REG(0x11); //Exit Sleep
	delay_tft(120);
//	LCD_WR_REG(0x29); //display on	
}

void LCD_XYRAM(uint16_t stx,uint16_t sty,uint16_t endx,uint16_t endy)
{
	LCD_WR_REG(0x2A);  
	LCD_WR_DATA(stx>>8);    
	LCD_WR_DATA(stx&0xff);    	
	LCD_WR_DATA(endx>>8); 
	LCD_WR_DATA(endx&0xff);	

	LCD_WR_REG(0x2B);  
	LCD_WR_DATA(sty>>8); 
	LCD_WR_DATA(sty&0xff);	
	LCD_WR_DATA(endy>>8); 
	LCD_WR_DATA(endy&0xff);	
}

void LcdWirteColorData(uint16_t color)
{
	LCD_RS_SET;  //RS=1;
	LCD_CS_CLR;	//CS=0;
 	OUT_DATA(color>>8);								
	LCD_WR_CLR;	//WR=0;
	LCD_WR_SET;	//WR=1;
	OUT_DATA(color);							
	LCD_WR_CLR;	//WR=0;
	LCD_WR_SET;	//WR=1;
	LCD_CS_SET;	//CS=1;	
}

void LCD_Clear(uint16_t color)
{  
	unsigned int i,j;
	
	LCD_WR_REG(0x28); // ����ʾ
	LCD_XYRAM(0,0,239,319);
  LCD_WR_REG(0x2C);
	for(i=0;i<320;i++)
	{
		for(j=0;j<240;j++)
		{
			LcdWirteColorData(color);
		}
	}
	LCD_WR_REG(0x29); // ����ʾ
}

// ����
void LCD_DrawPoint(uint16_t x, uint16_t y)
{
	LCD_XYRAM(x,y,x,y);
	LCD_WR_REG(0x2C);
	LcdWirteColorData(POINT_COLOR);
}

/**********************************************/
/* �������ܣ���ֱ��                           */
/**********************************************/
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	uint16_t t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 

	delta_x=x2-x1; //������������ 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //���õ������� 
	else if(delta_x==0)incx=0;//��ֱ�� 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//ˮƽ�� 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //ѡȡ�������������� 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//������� 
	{  
		LCD_DrawPoint(uRow,uCol);//���� 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}

/**********************************************/
/* �������ܣ�������                           */
/**********************************************/
void LCD_DrawRectage(uint16_t xstart,uint16_t ystart,uint16_t xend,uint16_t yend)
{
	LCD_DrawLine(xstart, ystart, xend, ystart);
	LCD_DrawLine(xstart, yend, xend, yend);
	LCD_DrawLine(xstart, ystart, xstart, yend);
	LCD_DrawLine(xend, ystart, xend, yend);
}

// �������
void LCD_Fill(uint16_t xstart, uint16_t ystart, uint16_t xend, uint16_t yend)
{
	uint32_t max;
	
	max=(uint32_t)((xend-xstart+1)*(yend-ystart+1));  
	LCD_XYRAM(xstart,ystart,xend,yend);
	LCD_WR_REG(0x2C);
	while(max--) LcdWirteColorData(POINT_COLOR);
}

/*******************************************/
/* �������ܣ���Բ                          */
/* ��ڲ�����x0,y0  Բ������               */
/*           r      �뾶(��λ������)       */
/*******************************************/
void LCD_DrawCircle(uint8_t x0, uint16_t y0, uint8_t r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //�ж��¸���λ�õı�־
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a);             //3           
		LCD_DrawPoint(x0+b,y0-a);             //0           
		LCD_DrawPoint(x0-a,y0+b);             //1       
		LCD_DrawPoint(x0-b,y0-a);             //7           
		LCD_DrawPoint(x0-a,y0-b);             //2             
		LCD_DrawPoint(x0+b,y0+a);             //4               
		LCD_DrawPoint(x0+a,y0-b);             //5
		LCD_DrawPoint(x0+a,y0+b);             //6 
		LCD_DrawPoint(x0-b,y0+a);             
		a++;
		//ʹ��Bresenham�㷨��Բ     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 
		LCD_DrawPoint(x0+a,y0+b);
	}
}

/**********************************************/
/* �������ܣ���ʾ8*16����Ӣ���ַ�             */
/* ��ڲ�����x,y :�������	 	              */
/*           num:��ĸ�����         	   	  */
/* ע    �⣺x,y��ȡֵҪ��240��320��Χ��      */
/**********************************************/
void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t num)
{
	uint8_t temp;
	uint8_t pos,t;

	LCD_XYRAM(x,y,x+7,y+15); // ����GRAM����
	LCD_WR_REG(0x002C);	  	 //ָ��RAM�Ĵ�����׼��д���ݵ�RAM
 	
	num=num-' ';//�õ�ƫ�ƺ��ֵ
	for(pos=0;pos<16;pos++)
	{
		temp=ascii_16[num][pos];		
		for(t=0;t<8;t++)
		{                 
			if(temp&0x80)LcdWirteColorData(POINT_COLOR);
			else LcdWirteColorData(BACK_COLOR);    
			temp<<=1; 
		}
	}
	return;
}






