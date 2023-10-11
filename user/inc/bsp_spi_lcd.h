#ifndef __BSP_LCD_H
#define __BSP_LCD_H

#include "stdio.h"
#include "at32f435_437.h"
#include "at32f435_437_board.h"
#define USE_HORIZONTAL 0  
#define LCD_W 320
#define LCD_H 240

//������ɫ
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //��ɫ
#define BRRED 			     0XFC07 //�غ�ɫ
#define GRAY  			     0X8430 //��ɫ
#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
#define LIGHTGREEN     	 0X841F //ǳ��ɫ
#define LGRAY 			     0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ
#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

#define LCD_RES_Clr()  gpio_bits_reset(GPIOB,GPIO_PINS_3)//RES
#define LCD_RES_Set()  gpio_bits_set(GPIOB,GPIO_PINS_3)
#define LCD_DC_Clr()   gpio_bits_reset(GPIOB,GPIO_PINS_0)//DC
#define LCD_DC_Set()   gpio_bits_set(GPIOB,GPIO_PINS_0) 
#define LCD_CS_Clr()   gpio_bits_reset(GPIOA,GPIO_PINS_4)//CS
#define LCD_CS_Set()   gpio_bits_set(GPIOA,GPIO_PINS_4)
#define LCD_BLK_Clr()  gpio_bits_reset(GPIOA,GPIO_PINS_3)//BLK
#define LCD_BLK_Set()  gpio_bits_set(GPIOA,GPIO_PINS_3)

void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(u8 dat);//ģ��SPIʱ��
void LCD_WR_DATA8(u8 dat);//д��һ���ֽ�
void LCD_WR_DATA(u16 dat);//д�������ֽ�
void lcd_send_data(const uint8_t *data, uint8_t len);
void LCD_WR_REG(u8 dat);//д��һ��ָ��
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��

void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);
void LCD_DMA_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u8 *color);
void Dma1_Ch1_Config(uint32_t memory_base_addr, uint16_t data_size);


#endif
