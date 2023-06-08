/*
 * app.c
 *
 * Created: 4/5/2023 8:31:23 PM
 *  Author: Mohamed Abdel-Wahab
 */ 
#include "app.h"

static void UPDATE_ON_OFF_DURATION(void);
static void LEDS_SEQ_UPDATE(void);
static void BLINK_MODE_UPDATE(void);


static volatile uint8_t u8_g_pressCnt = IDLE_STATE ;
static volatile uint8_t u8_g_blinkMode_update = BLINK_ONE;
static volatile uint8_t u8_g_on_off_index;
static volatile uint16_t u16_g_100_ms_cnt;


Std_ReturnType APP_init(void)
{
	Std_ReturnType l_ret = E_OK;
	GLOBAL_InterruptEnable();
	l_ret  = LED_initialize(&s_led0);
	l_ret |= LED_initialize(&s_led1);
	l_ret |= LED_initialize(&s_led2);
	l_ret |= LED_initialize(&s_led3);
	l_ret |= BTN_init(&s_btn0);
	l_ret |= BTN_init(&s_btn1);
	l_ret |= EXT_INTx_Init(&s_INT0);
	l_ret |= EXT_INTx_Init(&s_INT1);
	/*initiate the timer */
	  

	
	st_g_timer.call_back_function = UPDATE_ON_OFF_DURATION;
	l_ret |= TIMER_MANGER_init(&st_g_timer);
	//l_ret = TIMERx_init(&st_g_timer);
	return l_ret;
}

Std_ReturnType APP_start_program(void)
{
	Std_ReturnType l_ret = E_OK;
	l_ret = EXT_INTx_setCallBack(&LEDS_SEQ_UPDATE,INTERRUPT_EXTERNAL_INT0);
	l_ret = EXT_INTx_setCallBack(&BLINK_MODE_UPDATE,INTERRUPT_EXTERNAL_INT1);
	/*set call-back function that increment the timer tick */
	//l_ret |= TIMERx_setCallBack(&UPDATE_ON_OFF_DURATION , Timer0);
	
		switch(u8_g_pressCnt)
		{
			case FIRST_STATE:
				/*start the timer with the first press, will fire an interrupt on compare match with 100ms */
				l_ret = TIMER_MANGER_start(F_CPU_1024,st_g_timer.timer_num);
				//l_ret = TIMERx_start(F_CPU_1024,st_g_timer.timer_num);
				
				switch(u8_g_blinkMode_update)
				{
					case BLINK_ONE:
						while((BLINK_ONE==u8_g_blinkMode_update)&&(FIRST_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_ONE_ON)
							{
									/*blink led0 with the current mode*/
								    l_ret |= LED_turn_on(&s_led0);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_ONE_ON)
							{		/*blink led0 with the current mode*/
									l_ret |= LED_turn_off(&s_led0);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						
						break;
					case BLINK_TWO:
						while((BLINK_TWO==u8_g_blinkMode_update)&&(FIRST_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_TWO_ON)
							{
								/*blink led0 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_TWO_ON)
							{		/*blink led0 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_THREE:
						while((BLINK_THREE==u8_g_blinkMode_update)&&(FIRST_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_THREE_ON)
							{
								/*blink led0 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_THREE_ON)
							{		/*blink led0 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FOUR:
						while((BLINK_FOUR==u8_g_blinkMode_update)&&(FIRST_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FOUR_ON)
							{
								/*blink led0 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FOUR_ON)
							{		/*blink led0 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FIVE:
						while((BLINK_FIVE==u8_g_blinkMode_update)&&(FIRST_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FIVE_ON)
							{
								/*blink led0 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FIVE_ON)
							{		/*blink led0 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						u8_g_blinkMode_update = BLINK_ONE;
						break;
					default: 
						l_ret = E_NOT_OK;
						break;
				}
				break;	

			case SECOND_STATE:
			
				switch(u8_g_blinkMode_update)
				{
					case BLINK_ONE:
						while((BLINK_ONE==u8_g_blinkMode_update)&&(SECOND_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_ONE_ON)
							{
									/*blink led0 with the current mode*/
								    l_ret |= LED_turn_on(&s_led0);
									l_ret |= LED_turn_on(&s_led1);

									
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_ONE_ON)
							{		/*blink led0 with the current mode*/
									l_ret |= LED_turn_off(&s_led0);
									l_ret |= LED_turn_off(&s_led1);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						
						break;
					case BLINK_TWO:
						while((BLINK_TWO==u8_g_blinkMode_update)&&(SECOND_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_TWO_ON)
							{
								/*blink led0 with the current mode*/
								 l_ret |= LED_turn_on(&s_led0);
								 l_ret |= LED_turn_on(&s_led1);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_TWO_ON)
							{	
								/*blink led0 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_THREE:
						while((BLINK_THREE==u8_g_blinkMode_update)&&(SECOND_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_THREE_ON)
							{
								/*blink led0 with the current mode*/
								 l_ret |= LED_turn_on(&s_led0);
								 l_ret |= LED_turn_on(&s_led1);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_THREE_ON)
							{	
								/*blink led0 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FOUR:
						while((BLINK_FOUR==u8_g_blinkMode_update)&&(SECOND_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FOUR_ON)
							{
								/*blink led0 with the current mode*/
								 l_ret |= LED_turn_on(&s_led0);
								 l_ret |= LED_turn_on(&s_led1);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FOUR_ON)
							{	
								/*blink led0 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FIVE:
						while((BLINK_FIVE==u8_g_blinkMode_update)&&(SECOND_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FIVE_ON)
							{
								/*blink led0 with the current mode*/
								 l_ret |= LED_turn_on(&s_led0);
								 l_ret |= LED_turn_on(&s_led1);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FIVE_ON)
							{	
								/*blink led0 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						u8_g_blinkMode_update = BLINK_ONE;
						break;
					default: 
						l_ret = E_NOT_OK;
						break;
				}
				break;
				
			case THIRD_STATE:
				switch(u8_g_blinkMode_update)
				{
					case BLINK_ONE:
						while((BLINK_ONE==u8_g_blinkMode_update)&&(THIRD_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_ONE_ON)
							{
									/*blink led0,led1,led2 with the current mode*/
								    l_ret |= LED_turn_on(&s_led0);
									l_ret |= LED_turn_on(&s_led1);
									l_ret |= LED_turn_on(&s_led2);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_ONE_ON)
							{		
									/*blink led0,led1,led2 with the current mode*/
									l_ret |= LED_turn_off(&s_led0);
									l_ret |= LED_turn_off(&s_led1);
									l_ret |= LED_turn_off(&s_led2);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						
						break;
					case BLINK_TWO:
						while((BLINK_TWO==u8_g_blinkMode_update)&&(THIRD_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_TWO_ON)
							{
								/*blink led0,led1,led2 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_TWO_ON)
							{								
								/*blink led0,led1,led2 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_THREE:
						while((BLINK_THREE==u8_g_blinkMode_update)&&(THIRD_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_THREE_ON)
							{
								/*blink led0,led1,led2 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_THREE_ON)
							{	
								/*blink led0,led1,led2 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FOUR:
						while((BLINK_FOUR==u8_g_blinkMode_update)&&(THIRD_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FOUR_ON)
							{
								/*blink led0,led1,led2 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FOUR_ON)
							{	
								/*blink led0,led1,led2 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FIVE:
						while((BLINK_FIVE==u8_g_blinkMode_update)&&(THIRD_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FIVE_ON)
							{
								/*blink led0,led1,led2 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FIVE_ON)
							{	
								/*blink led0,led1,led2 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						u8_g_blinkMode_update = BLINK_ONE;
						break;
					default: 
						l_ret = E_NOT_OK;
						break;
				}
				break;
				
			case FOURTH_STATE:
				switch(u8_g_blinkMode_update)
				{
					case BLINK_ONE:
						while((BLINK_ONE==u8_g_blinkMode_update)&&(FOURTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_ONE_ON)
							{
									/*blink led0,led1,led2,led4 with the current mode*/
									l_ret |= LED_turn_on(&s_led0);
									l_ret |= LED_turn_on(&s_led1);
									l_ret |= LED_turn_on(&s_led2);
									l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_ONE_ON)
							{		
									/*blink led0,led1,led2,led4 with the current mode*/
									l_ret |= LED_turn_off(&s_led0);
									l_ret |= LED_turn_off(&s_led1);
									l_ret |= LED_turn_off(&s_led2);
									l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						
						break;
					case BLINK_TWO:
						while((BLINK_TWO==u8_g_blinkMode_update)&&(FOURTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_TWO_ON)
							{
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_TWO_ON)
							{								
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_THREE:
						while((BLINK_THREE==u8_g_blinkMode_update)&&(FOURTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_THREE_ON)
							{
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_THREE_ON)
							{	
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FOUR:
						while((BLINK_FOUR==u8_g_blinkMode_update)&&(FOURTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FOUR_ON)
							{
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);		
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FOUR_ON)
							{	
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FIVE:
						while((BLINK_FIVE==u8_g_blinkMode_update)&&(FOURTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FIVE_ON)
							{
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_on(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FIVE_ON)
							{	
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						u8_g_blinkMode_update = BLINK_ONE;
						break;
					default: 
						l_ret = E_NOT_OK;
						break;
				}
				break;
				
			case FIFTH_STATE:
				switch(u8_g_blinkMode_update)
				{
					case BLINK_ONE:
						while((BLINK_ONE==u8_g_blinkMode_update)&&(FIFTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_ONE_ON)
							{
									/*blink led1,led2,led4 with the current mode*/
									l_ret |= LED_turn_off(&s_led0);
									l_ret |= LED_turn_on(&s_led1);
									l_ret |= LED_turn_on(&s_led2);
									l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_ONE_ON)
							{		
									/*blink led1,led2,led4 with the current mode*/
									l_ret |= LED_turn_off(&s_led0);
									l_ret |= LED_turn_off(&s_led1);
									l_ret |= LED_turn_off(&s_led2);
									l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						
						break;
					case BLINK_TWO:
						while((BLINK_TWO==u8_g_blinkMode_update)&&(FIFTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_TWO_ON)
							{
								/*blink led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_TWO_ON)
							{								
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_THREE:
						while((BLINK_THREE==u8_g_blinkMode_update)&&(FIFTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_THREE_ON)
							{
								/*blink led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_THREE_ON)
							{	
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FOUR:
						while((BLINK_FOUR==u8_g_blinkMode_update)&&(FIFTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FOUR_ON)
							{
								/*blink led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FOUR_ON)
							{	
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FIVE:
						while((BLINK_FIVE==u8_g_blinkMode_update)&&(FIFTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FIVE_ON)
							{
								/*blink led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_on(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FIVE_ON)
							{	
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						u8_g_blinkMode_update = BLINK_ONE;
						break;
					default: 
						l_ret = E_NOT_OK;
						break;
				}	
				break;
				
			case SIXTH_STATE:
				switch(u8_g_blinkMode_update)
				{
					case BLINK_ONE:
						while((BLINK_ONE==u8_g_blinkMode_update)&&(SIXTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_ONE_ON)
							{
									/*blink led0,led1,led2,led3 with the current mode*/
									l_ret |= LED_turn_off(&s_led0);
									l_ret |= LED_turn_off(&s_led1);
									l_ret |= LED_turn_on(&s_led2);
									l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_ONE_ON)
							{		
									/*blink led1,led2,led4 with the current mode*/
									l_ret |= LED_turn_off(&s_led0);
									l_ret |= LED_turn_off(&s_led1);
									l_ret |= LED_turn_off(&s_led2);
									l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						
						break;
					case BLINK_TWO:
						while((BLINK_TWO==u8_g_blinkMode_update)&&(SIXTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_TWO_ON)
							{
								/*blink led0,led1,led2,led3 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_TWO_ON)
							{								
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_THREE:
						while((BLINK_THREE==u8_g_blinkMode_update)&&(SIXTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_THREE_ON)
							{
								/*blink led0,led1,led2,led3 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_THREE_ON)
							{	
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FOUR:
						while((BLINK_FOUR==u8_g_blinkMode_update)&&(SIXTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FOUR_ON)
							{
								/*blink led0,led1,led2,led3 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FOUR_ON)
							{	
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FIVE:
						while((BLINK_FIVE==u8_g_blinkMode_update)&&(SIXTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FIVE_ON)
							{
								/*blink led0,led1,led2,led3 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_on(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FIVE_ON)
							{	
								/*blink led0,led1,led2,led3 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						u8_g_blinkMode_update = BLINK_ONE;
						break;
					default: 
						l_ret = E_NOT_OK;
						break;
				}	
				break;
			case SEVENTH_STATE:
				switch(u8_g_blinkMode_update)
				{
					case BLINK_ONE:
						while((BLINK_ONE==u8_g_blinkMode_update)&&(SEVENTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_ONE_ON)
							{
									/*blink led3 with the current mode*/
									l_ret |= LED_turn_off(&s_led0);
									l_ret |= LED_turn_off(&s_led1);
									l_ret |= LED_turn_off(&s_led2);
									l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_ONE_ON)
							{		
									/*blink led1,led2,led4 with the current mode*/
									l_ret |= LED_turn_off(&s_led0);
									l_ret |= LED_turn_off(&s_led1);
									l_ret |= LED_turn_off(&s_led2);
									l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						
						break;
					case BLINK_TWO:
						while((BLINK_TWO==u8_g_blinkMode_update)&&(SEVENTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_TWO_ON)
							{
								/*blink led3 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_TWO_ON)
							{								
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_THREE:
						while((BLINK_THREE==u8_g_blinkMode_update)&&(SEVENTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_THREE_ON)
							{
								/*blink led3 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_THREE_ON)
							{	
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FOUR:
						while((BLINK_FOUR==u8_g_blinkMode_update)&&(SEVENTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FOUR_ON)
							{
								/*blink led3 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FOUR_ON)
							{	
								/*blink led0,led1,led2,led4 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						break;
					case BLINK_FIVE:
						while((BLINK_FIVE==u8_g_blinkMode_update)&&(SEVENTH_STATE==u8_g_pressCnt))
						{
							if(u16_g_100_ms_cnt<BLINK_MODE_FIVE_ON)
							{
								/*blink led3 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_on(&s_led3);
							}
							else if(u16_g_100_ms_cnt>=BLINK_MODE_FIVE_ON)
							{	
								/*blink led3 with the current mode*/
								l_ret |= LED_turn_off(&s_led0);
								l_ret |= LED_turn_off(&s_led1);
								l_ret |= LED_turn_off(&s_led2);
								l_ret |= LED_turn_off(&s_led3);
							}
							else
							{
								/*DO NOTHING*/
							}
						}
						u8_g_blinkMode_update = BLINK_ONE;
						break;
					default: 
						l_ret = E_NOT_OK;
						break;
				}
				break;
			case EIGHTH_STATE:
				l_ret |= LED_turn_off(&s_led3);
				u8_g_pressCnt = IDLE_STATE;
				break;
		}
	
	return l_ret;
}

static void UPDATE_ON_OFF_DURATION(void)
{
	u16_g_100_ms_cnt++;
	/*the life time of the blink cycle is 1000ms*/
	if(u16_g_100_ms_cnt >= BLINK_ON_OFF_MAX_DURATION)
	{
		/*start count from beginning*/
		u16_g_100_ms_cnt = 0;
	}
	else
	{
		/*DO NOTHING*/
	}
}

static  void LEDS_SEQ_UPDATE(void)
{
	u16_g_100_ms_cnt = 0;
	u8_g_pressCnt++;
}
static void BLINK_MODE_UPDATE(void)
{
	u16_g_100_ms_cnt = 0;
	u8_g_blinkMode_update++;
}
