/**
 * @file PMOD_ALS.h
 *
 * @brief Header file for the PMOD_ALS driver.
 *
 * This file contains the function definitions for the PMOD_ALS driver.
 *
 * @note For more information regarding the SSI module, refer to the
 * Synchronous Serial Interface (SSI) section of the TM4C123GH6PM Microcontroller Datasheet.
 *   - Link: https://www.ti.com/lit/gpn/TM4C123GH6PM
 *
 * @note Assumes that the system clock (50 MHz) is used.
 *
 * @author Aaron Nanas
 */

#include "TM4C123GH6PM.h"

#define SSI0_BUSY_BIT_MASK (0x10)
#define SSI0_RX_FIFO_NOT_EMPTY_BIT_MASK (0x04)
#define SSI0_TX_FIFO_EMPTY_BIT_MASK (0x01)

/**
 * @brief
 *
 * @param None
 *
 * @return None
 */
void PMOD_ALS_Init(void);

/**
 * @brief
 *
 * @param None
 *
 * @return uint16_t
 */
uint16_t PMOD_ALS_Input_Data(void);

/**
 * @brief
 *
 * @param uint16_t data
 *
 * @return None
 */
void PMOD_ALS_Output_Data(uint16_t data);

/**
 * @brief
 *
 * @param None
 *
 * @return uint16_t
 */
uint16_t PMOD_ALS_Read(void);
