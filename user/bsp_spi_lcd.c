#include "bsp_spi_lcd.h"
#include "at32f435_437.h"

#include "lvgl.h"
void LCD_GPIO_Init(void)
{
    crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE); 
		crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);
    gpio_init_type gpio_initstructure;
    gpio_default_para_init(&gpio_initstructure);

    gpio_initstructure.gpio_out_type       = GPIO_OUTPUT_PUSH_PULL;
    gpio_initstructure.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
    gpio_initstructure.gpio_mode           = GPIO_MODE_MUX;
    gpio_initstructure.gpio_pins           = GPIO_PINS_5 ;
    gpio_init(GPIOA, &gpio_initstructure);
    gpio_initstructure.gpio_pins           = GPIO_PINS_5; 
    gpio_init(GPIOB, &gpio_initstructure);
	

    gpio_initstructure.gpio_mode           = GPIO_MODE_OUTPUT;
    gpio_initstructure.gpio_pins           = GPIO_PINS_3 | GPIO_PINS_4; 
    gpio_init(GPIOA, &gpio_initstructure);
    gpio_initstructure.gpio_pins           = GPIO_PINS_3 | GPIO_PINS_0; 
    gpio_init(GPIOB, &gpio_initstructure);   

		gpio_pin_mux_config(GPIOA, GPIO_PINS_SOURCE5, GPIO_MUX_5);
		gpio_pin_mux_config(GPIOB, GPIO_PINS_SOURCE5, GPIO_MUX_5);

    crm_periph_clock_enable(CRM_SPI1_PERIPH_CLOCK, TRUE);

    spi_init_type spi_init_struct;
    spi_default_para_init(&spi_init_struct);
    
    spi_init_struct.transmission_mode = SPI_TRANSMIT_HALF_DUPLEX_TX; 
    spi_init_struct.master_slave_mode = SPI_MODE_MASTER;
    spi_init_struct.mclk_freq_division = SPI_MCLK_DIV_2; 
    spi_init_struct.first_bit_transmission = SPI_FIRST_BIT_MSB;
    spi_init_struct.frame_bit_num = SPI_FRAME_8BIT;
    spi_init_struct.clock_polarity = SPI_CLOCK_POLARITY_HIGH;
    spi_init_struct.clock_phase = SPI_CLOCK_PHASE_2EDGE;
    spi_init_struct.cs_mode_selection = SPI_CS_SOFTWARE_MODE;
    spi_init(SPI1, &spi_init_struct);
    

    spi_i2s_dma_transmitter_enable(SPI1, TRUE);
    spi_enable(SPI1, TRUE);
		crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);
}

void LCD_Writ_Bus(u8 dat) 
{	
	LCD_CS_Clr();
  spi_frame_bit_num_set(SPI1, SPI_FRAME_8BIT);
  spi_i2s_data_transmit(SPI1, dat);
  while(spi_i2s_flag_get(SPI1, SPI_I2S_BF_FLAG) == SET); //�ȴ��������
  LCD_CS_Set();	
}

void LCD_WR_DATA8(u8 dat)
{
	LCD_Writ_Bus(dat);
}

void LCD_WR_DATA(u16 dat)
{
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}

void lcd_send_data(const uint8_t *data, uint8_t len)
{
	LCD_CS_Clr();    
	spi_frame_bit_num_set(SPI1, SPI_FRAME_8BIT);
	
	for(uint8_t i = 0; i < len; i ++) {
			spi_i2s_data_transmit(SPI1, data[i]);
			while(spi_i2s_flag_get(SPI1, SPI_I2S_BF_FLAG) == SET); //�ȴ��������
	}

	LCD_CS_Set();	
}

void LCD_WR_REG(u8 dat)
{
	LCD_DC_Clr();//д����
	LCD_Writ_Bus(dat);
	LCD_DC_Set();//д����
}

void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
	LCD_WR_REG(0x2a);//�е�ַ����
	LCD_WR_DATA(x1);
	LCD_WR_DATA(x2);
	LCD_WR_REG(0x2b);//�е�ַ����
	LCD_WR_DATA(y1);
	LCD_WR_DATA(y2);
	LCD_WR_REG(0x2c);//������д
}

void LCD_Init(void)
{
		LCD_GPIO_Init();//��ʼ��GPIO
		LCD_RES_Set();
		delay_ms(10);	
		LCD_RES_Clr();//��λ
		delay_ms(10);
		LCD_RES_Set();
		delay_ms(120);
		LCD_BLK_Set();//�򿪱���

		LCD_WR_REG(0x11);     
		delay_ms(120);                

		LCD_WR_REG(0x36);     
		if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x00);
		else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC0);
		else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x70);
		else LCD_WR_DATA8(0xA0);

		LCD_WR_REG(0x3A);     
		LCD_WR_DATA8( 0x05);   //16BIT

		LCD_WR_REG(0xB2);     
		LCD_WR_DATA8( 0x05);   
		LCD_WR_DATA8( 0x05);   
		LCD_WR_DATA8( 0x00);   
		LCD_WR_DATA8( 0x33);   
		LCD_WR_DATA8( 0x33);   

		LCD_WR_REG(0xB7);     
		LCD_WR_DATA8( 0x35);   


		LCD_WR_REG(0xBB);     
		LCD_WR_DATA8( 0x21);   

		LCD_WR_REG(0xC0);     
		LCD_WR_DATA8( 0x2C);   

		LCD_WR_REG(0xC2);     
		LCD_WR_DATA8( 0x01);   

		LCD_WR_REG(0xC3);     
		LCD_WR_DATA8( 0x0B);   

		LCD_WR_REG(0xC4);     
		LCD_WR_DATA8( 0x20);   

		LCD_WR_REG(0xC6);     
		LCD_WR_DATA8( 0x0F);   //60HZ dot inversion

		LCD_WR_REG(0xD0);     
		LCD_WR_DATA8( 0xA7);   
		LCD_WR_DATA8( 0xA1); 

		LCD_WR_REG(0xD0);     
		LCD_WR_DATA8( 0xA4);   
		LCD_WR_DATA8( 0xA1);   
			

		LCD_WR_REG(0xD6);     
		LCD_WR_DATA8( 0xA1);   

		LCD_WR_REG(0xE0);     
		LCD_WR_DATA8( 0xD0);   
		LCD_WR_DATA8( 0x04);   
		LCD_WR_DATA8( 0x08);   
		LCD_WR_DATA8( 0x0A);   
		LCD_WR_DATA8( 0x09);   
		LCD_WR_DATA8( 0x05);   
		LCD_WR_DATA8( 0x2D);   
		LCD_WR_DATA8( 0x43);   
		LCD_WR_DATA8( 0x49);   
		LCD_WR_DATA8( 0x09);   
		LCD_WR_DATA8( 0x16);   
		LCD_WR_DATA8( 0x15);   
		LCD_WR_DATA8( 0x26);   
		LCD_WR_DATA8( 0x2B);   

		LCD_WR_REG(0xE1);     
		LCD_WR_DATA8( 0xD0);   
		LCD_WR_DATA8( 0x03);   
		LCD_WR_DATA8( 0x09);   
		LCD_WR_DATA8( 0x0A);   
		LCD_WR_DATA8( 0x0A);   
		LCD_WR_DATA8( 0x06);   
		LCD_WR_DATA8( 0x2E);   
		LCD_WR_DATA8( 0x44);   
		LCD_WR_DATA8( 0x40);   
		LCD_WR_DATA8( 0x3A);   
		LCD_WR_DATA8( 0x15);   
		LCD_WR_DATA8( 0x15);   
		LCD_WR_DATA8( 0x26);   
		LCD_WR_DATA8( 0x2A);   

		LCD_WR_REG(0x21);     

		LCD_WR_REG(0x29);     

		delay_ms(10);                	
} 

void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{          
	u16 i,j; 
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//������ʾ��Χ
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			LCD_WR_DATA(color);
		}
	} 					  	    
}


void LCD_DMA_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u8 *color)
{
	uint32_t num = (xend-xsta)*(yend-ysta);
	
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//������ʾ��Χ
	LCD_CS_Clr();
	
	crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);
	dma_reset(DMA1_CHANNEL1);
	
	spi_frame_bit_num_set(SPI1, SPI_FRAME_16BIT);
	
	dma_init_type dma_init_struct;
	dma_init_struct.buffer_size = num;                                    //???
	dma_init_struct.direction = DMA_DIR_MEMORY_TO_PERIPHERAL;                   //?????
	dma_init_struct.memory_base_addr = (uint32_t)color;                        //?????
	dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_BYTE;             //????
	dma_init_struct.memory_inc_enable = TRUE;                                   //??????
	dma_init_struct.peripheral_base_addr = (uint32_t)&(SPI1->dt);                //?????
	dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_BYTE;     //??????
	dma_init_struct.peripheral_inc_enable = FALSE;                              //???????
	dma_init_struct.priority = DMA_PRIORITY_MEDIUM;                             //?????
	dma_init_struct.loop_mode_enable = FALSE;   
	dma_init(DMA1_CHANNEL1, &dma_init_struct);          

	dmamux_enable(DMA1, TRUE);
  dmamux_init(DMA1MUX_CHANNEL1, DMAMUX_DMAREQ_ID_SPI1_TX);
	dma_interrupt_enable(DMA1_CHANNEL1, DMA_FDT_INT, TRUE);                   
	nvic_irq_enable(DMA1_Channel1_IRQn, 0, 0);//????
	dma_channel_enable(DMA1_CHANNEL1, TRUE); //��������	
}

void Dma1_Ch1_Config(uint32_t memory_base_addr, uint16_t data_size)
{
crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);
	dma_reset(DMA1_CHANNEL1);
	
	
	dma_init_type dma_init_struct;
	dma_init_struct.buffer_size = data_size;                                    //???
	dma_init_struct.direction = DMA_DIR_MEMORY_TO_PERIPHERAL;                   //?????
	dma_init_struct.memory_base_addr = (uint32_t)memory_base_addr;                        //?????
	dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_BYTE;             //????
	dma_init_struct.memory_inc_enable = TRUE;                                   //??????
	dma_init_struct.peripheral_base_addr = (uint32_t)&(SPI1->dt);                //?????
	dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_BYTE;     //??????
	dma_init_struct.peripheral_inc_enable = FALSE;                              //???????
	dma_init_struct.priority = DMA_PRIORITY_MEDIUM;                             //?????
	dma_init_struct.loop_mode_enable = FALSE;   
	dma_init(DMA1_CHANNEL1, &dma_init_struct);          

	dmamux_enable(DMA1, TRUE);
  dmamux_init(DMA1MUX_CHANNEL1, DMAMUX_DMAREQ_ID_SPI1_TX);
	dma_interrupt_enable(DMA1_CHANNEL1, DMA_FDT_INT, TRUE);                   
	nvic_irq_enable(DMA1_Channel1_IRQn, 0, 0);//????
	dma_channel_enable(DMA1_CHANNEL1, TRUE); //��������	
}

extern lv_disp_drv_t disp_drv; 

void DMA1_Channel1_IRQHandler(void)
{
    if(dma_flag_get(DMA1_FDT1_FLAG))
    {
        dma_flag_clear(DMA1_FDT1_FLAG);
				LCD_CS_Set();
			
        lv_disp_flush_ready(&disp_drv);
    }
}




