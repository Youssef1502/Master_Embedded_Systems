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

u8 UART_Receive_Periodic_Check(u8 * pdata);

void UART_SendNoBlock(u8 data);
u8 UART_ReceiveNoBlock(void);
void UART_RX_InterrupEnable(void);
void UART_RX_InterrupDisable(void);
void UART_TX_InterrupEnable(void);
void UART_TX_InterrupDisable(void);
void UART_Send_String_Asynch(u8 *str);

#endif /* UART_H_ */