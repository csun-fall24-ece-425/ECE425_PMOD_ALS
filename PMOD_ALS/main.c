/*
 * @file main.c
 *
 * @brief Main source code for the SSI0 program.
 *
 * This file contains the main entry point and function definitions for the SSI0 program.
 *
 * @note For more information regarding the SSI module, refer to the
 * Synchronous Serial Interface (SSI) section of the TM4C123GH6PM Microcontroller Datasheet.
 *   - Link: https://www.ti.com/lit/gpn/TM4C123GH6PM
 *
 * @author
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "UART0.h"
#include "PMOD_ALS.h"

#define SSI0_TEST 1
//#define PMOD_ALS_TEST 1

int main(void)
{
	SysTick_Delay_Init();
	
	UART0_Init();
	
	PMOD_ALS_Init();

#ifdef SSI0_TEST
	uint16_t spi_test_data = 0xAAAA;
#endif
	
	while(1)
	{
#ifdef SSI0_TEST
		PMOD_ALS_Output_Data(spi_test_data);
		PMOD_ALS_Output_Data(spi_test_data + 1);
		PMOD_ALS_Output_Data(spi_test_data + 2);
		SysTick_Delay1ms(100);
#endif
		
#ifdef PMOD_ALS_TEST
		uint8_t light_level = PMOD_ALS_Read();
		UART0_Output_String("PMOD ALS Data: ");
		UART0_Output_Unsigned_Decimal(light_level);
		UART0_Output_Newline();
		SysTick_Delay1ms(100);
#endif	
	}
}
