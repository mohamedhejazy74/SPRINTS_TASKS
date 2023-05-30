/*
 * sos.h
 *
 * Created: 5/30/2023 2:27:35 AM
 *  Author: Mcs
 */ 


#ifndef SOS_H_
#define SOS_H_


/**********************************  section 1: Includes ********************************************************/
#include "../../STD_LIBRARIES/std_types.h"
#include "../../STD_LIBRARIES/bit_math.h"
#include "../../STD_LIBRARIES/timer_manager/timer_manager.h"

/**********************************  section 2: Macro Declarations ***********************************************/
#define  SOS_TASKS_MAX_NUM		2u
#define  SOS_RUNNING_STATE_IS_FREE  0X00
#define  SOS_RUNNING_STATE_IS_BUSY  0X00
/**********************************  section 3: Macro Like Function Declarations *************************** *****/


/**********************************  section 4: Data Type Declarations  ******************************************/
typedef enum{
	SOS_E_NOK=0,
	SOS_E_OK
	}enu_sos_status_t;

typedef enum{
	SOS_NOT_INITIALIZED=0,
	SOS_INITIALIZED
}enu_sos_init_status_t;	
	
typedef  void (*Fptr_task_callBack_t)(void);

typedef enum{
	TASK_IDLE_STATE=0,
	TASK_READY_STATE,
	TASK_RUNING_STATE,
	TASK_WAITING_STATE,
	TASK_TERMINATED_STATE,
	TASK_INVALID_STATE,
}enu_task_state_t;
	
typedef struct {
	uint8_t				 u8_task_priority;
	uint8_t				 u8_task_id;
	uint8_t			 u16_task_priodic_time;
	enu_task_state_t	 enu_task_state;
	Fptr_task_callBack_t Fptr_task_callBack;
}str_task_control_data_t;


 
/**********************************  section 5: Function Declarations ********************************************/

enu_sos_status_t SOS_init (void);
enu_sos_status_t SOS_deinit (void);

enu_sos_status_t SOS_run (void);
enu_sos_status_t SOS_disable (void);

enu_sos_status_t SOS_create_task (str_task_control_data_t *strPtr_task_control_data);
enu_sos_status_t SOS_next_scheduleTask (str_task_control_data_t *strPtr_task_control_data);
enu_sos_status_t SOS_modify_task (uint8_t u8_a_oldTask_id , str_task_control_data_t *strPtr_new_task_control_data);
enu_sos_status_t SOS_delete_task (uint8_t u8_a_Task_id);
enu_sos_status_t SOS_activate_task (uint8_t u8_a_Task_id);

#endif /* SOS_H_ */