#include "main.h"
#include "lvgl.h"
#include "lv_tick_custom.h"
#include "lv_port_disp_template.h"

#include "demos/benchmark/lv_demo_benchmark.h"
TaskHandle_t App_main_Handler;

TaskHandle_t Lvgl_task_Handler;

void App_main(void *pvParameters)
{
	LCD_Fill(0,0,240,320,DARKBLUE);
	while(1)
	{		
		
		//printf("app main task doing\r\n");
		vTaskDelay(10);
	}
}

void Lvgl_task(void *pvParameters)
{
	
	lv_demo_benchmark();
  while (1)
  {
    lv_task_handler();
    vTaskDelay(10);
  }
}

int main(void)
{
	crm_clocks_freq_type Get_Clocks;
  system_clock_config();
	
	delay_init();
  uart_print_init(115200);
	
  lv_ms_tick_tim();
  LCD_Init();
  lv_init();
  lv_port_disp_init();

	crm_clocks_freq_get(&Get_Clocks);
	
	printf("System Clock information\r\n");
	printf("SYSCLK_Frequency = %d\r\n", (uint32_t) Get_Clocks.sclk_freq);
	printf("HCLK_Frequency   = %d\r\n", (uint32_t) Get_Clocks.ahb_freq);
	printf("PCLK1_Frequency  = %d\r\n", (uint32_t) Get_Clocks.apb1_freq);
	printf("PCLK2_Frequency  = %d\r\n", (uint32_t) Get_Clocks.apb2_freq);

  taskENTER_CRITICAL(); 

  xTaskCreate((TaskFunction_t )App_main,     
              (const char*    )"App_main",   
              (uint16_t       )256, 
              (void*          )NULL,
              (UBaseType_t    )1,
              (TaskHandle_t*  )&App_main_Handler); 	
	xTaskCreate((TaskFunction_t)Lvgl_task,
              (const char *)"lvgl_task",
              (uint16_t)1024,
              (void *)NULL,
              (UBaseType_t)1,
              (TaskHandle_t *)&Lvgl_task_Handler);
   
  taskEXIT_CRITICAL();  
							
  vTaskStartScheduler();
}

