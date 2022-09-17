/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   UART Application
==================================================**/


#ifndef UART_H_
#define UART_H_

#include "../../MemMap.h"
#include "../../Utils.h"
#include "../../StdTypes.h"

/*
* ===================================================================================
* 						APIs Supported by "UART"
* ===================================================================================
*/
void UART_Init(void);
void UART_Send(u8 data);
u8 UART_Receive(void);

void UART_SendNumberU32(u32 num);
u32 UART_ReceiveNumberU32(void);

void UART_SendString(char *data);
void UART_ReceiveString(u8 *Buff);

#endif /* UART_H_ */