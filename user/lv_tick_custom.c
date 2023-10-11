#include "lvgl.h"
#include "lv_tick_custom.h"

uint8_t system_timer_flag = 0;
void lv_ms_tick_tim(void)
{
	crm_clocks_freq_type crm_clocks_freq_struct = {0};
	crm_clocks_freq_get(&crm_clocks_freq_struct);
	
  /* enable tmr1 clock */
  crm_periph_clock_enable(CRM_TMR1_PERIPH_CLOCK, TRUE);

	//Tout(us) = £¨£¨arr+1£©*£¨psc+1£©£©/Tclk ; 
  tmr_base_init(TMR1, 99, (crm_clocks_freq_struct.apb2_freq * 2 / 100000) - 1);
	
  tmr_cnt_dir_set(TMR1, TMR_COUNT_UP);

  /* overflow interrupt enable */
  tmr_interrupt_enable(TMR1, TMR_OVF_INT, TRUE);
	nvic_irq_enable(TMR1_OVF_TMR10_IRQn, 0, 0);
  /* enable tmr1 */
  tmr_counter_enable(TMR1, TRUE);	
	

}

void System_Timer_Flag_Set(uint8_t flag)
{
    system_timer_flag = flag ;
}

uint8_t System_Timer_Flag_Get()
{
    return system_timer_flag ;
}


void TMR1_OVF_TMR10_IRQHandler(void)
{
    if(tmr_flag_get(TMR1, TMR_OVF_FLAG) != RESET)
    {
        tmr_flag_clear(TMR1, TMR_OVF_FLAG);
        System_Timer_Flag_Set(1);
        lv_tick_inc(1);
    }
}

