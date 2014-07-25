/*
 * ccan_rom.h
 *
 *  Created on: Apr 28, 2014
 *      Author: kevin
 */

#ifndef CCAN_ROM_H_
#define CCAN_ROM_H_


/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

#define TEST_CCAN_BAUD_RATE 1000000
//#define TEST_CCAN_BAUD_RATE 200000 //David's VW

CCAN_MSG_OBJ_T msg_obj;

/*****************************************************************************
 * Private functions
 ****************************************************************************/
void baudrateCalculate(uint32_t baud_rate, uint32_t *can_api_timing_cfg);

/*	CAN receive callback */
/*	Function is executed by the Callback handler after
    a CAN message has been received */
void CAN_rx(uint8_t msg_obj_num);

/*	CAN transmit callback */
/*	Function is executed by the Callback handler after
    a CAN message has been transmitted */
void CAN_tx(uint8_t msg_obj_num);

/*	CAN error callback */
/*	Function is executed by the Callback handler after
    an error has occured on the CAN bus */
void CAN_error(uint32_t error_info);

/**
 * @brief	CCAN Interrupt Handler
 * @return	Nothing
 * @note	The CCAN interrupt handler must be provided by the user application.
 *	It's function is to call the isr() API located in the ROM
 */
void CAN_IRQHandler(void);



#endif /* CCAN_ROM_H_ */
