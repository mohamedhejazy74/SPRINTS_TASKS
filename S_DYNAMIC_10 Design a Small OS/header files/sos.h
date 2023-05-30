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
#define  SOS_RUNNING_STATE_IS_FREE     0X00
#define  SOS_RUNNING_STATE_IS_BUSY     0X01
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

/*
* Description :Function to initialize the SOS module 
* @return enu_sos_status_t status of the function
* SOS_E_OK :the function done successfully
* SOS_E_NOK :the function has issues performing the function
*/
enu_sos_status_t SOS_init (void);
/*
* Description :Function to de-initialize the SOS module
* @return enu_sos_status_t status of the function
* SOS_E_OK :the function done successfully
* SOS_E_NOK :the function has issues performing the function
*/
enu_sos_status_t SOS_deinit (void);
/*
* Description :Function to start the SOS module
* @return enu_sos_status_t status of the function
* SOS_E_OK :the function done successfully
* SOS_E_NOK :the function has issues performing the function
*/
enu_sos_status_t SOS_run (void);
/*
* Description :Function to disable the SOS module
* @return enu_sos_status_t status of the function
* SOS_E_OK :the function done successfully
* SOS_E_NOK :the function has issues performing the function
*/
enu_sos_status_t SOS_disable (void);
/*
* Description :Function to create a task SOS 
 *@param strPtr_task_control_data : A Reference of the SOS structure configuration
* @return enu_sos_status_t status of the function
* SOS_E_OK :the function done successfully
* SOS_E_NOK :the function has issues performing the function
*/
enu_sos_status_t SOS_create_task (str_task_control_data_t *strPtr_task_control_data);

/*
* Description :Function to modify an existence task
* @param strPtr_task_control_data : A Reference of the SOS structure configuration
*				u8_a_oldTask_id : an id of the modified task
* @return enu_sos_status_t status of the function
* SOS_E_OK :the function done successfully
* SOS_E_NOK :the function has issues performing the function
*/
enu_sos_status_t SOS_modify_task (uint8_t u8_a_oldTask_id , str_task_control_data_t *strPtr_new_task_control_data);
/*
* Description :Function to delete an existence task
* @param u8_a_oldTask_id : an id of the deleted task
* @return enu_sos_status_t status of the function
* SOS_E_OK :the function done successfully
* SOS_E_NOK :the function has issues performing the function
*/
enu_sos_status_t SOS_delete_task (uint8_t u8_a_Task_id);
/*
* Description :Function to delete an activate a dormant task
* @param u8_a_oldTask_id : an id of the dormant task
* @return enu_sos_status_t status of the function
* SOS_E_OK :the function done successfully
* SOS_E_NOK :the function has issues performing the function
*/
enu_sos_status_t SOS_activate_task (uint8_t u8_a_Task_id);

#endif /* SOS_H_ */
