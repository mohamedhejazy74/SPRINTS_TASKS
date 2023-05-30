/*
 * sos_config.c
 *
 * Created: 5/30/2023 4:19:21 AM
 *  Author: Mcs
 */ 
 #include "sos_config.h"
 #include "sos.h" 
 
 #define PERIODIC_TASK_EVERY_3_SEC		3U
 #define TASK_ONE_ID					1U
 #define TASK_PRIORITY_EQUAL_ONE		1U
 
 str_task_control_data_t  str_g_task_1_ = {
	.enu_task_state = TASK_IDLE_STATE,
	.u16_task_priodic_time = PERIODIC_TASK_EVERY_3_SEC,
	.u8_task_id = TASK_ONE_ID,
	.u8_task_priority = TASK_PRIORITY_EQUAL_ONE,
 };
 
  str_task_control_data_t  str_g_task_2_ = {
	  .enu_task_state = TASK_IDLE_STATE,
	  .u16_task_priodic_time = 4,
	  .u8_task_id = 2,
	  .u8_task_priority = 2,
  };