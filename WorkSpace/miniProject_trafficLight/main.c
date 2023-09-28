/****************************************************************/
/******* Author    : Abdulrahman Ahmed Saeed    *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : main.c                *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*****************************< MCAL ****************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_Interface.h"
#include "AFIO_interface.h"
#include "SCB_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"

/*****************************< APP *****************************/
int main(void){
/*****************************< Void Setup **********************/
	
	/**< Initialize System Clock */
	MCAL_RCC_InitSysClock();
	
	/**< Initialize SysTick timer */
	MCAL_STK_xInit(0);
	
  /**< Enable Peripherals */	
	MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPBEN);
	
/**<  Configure pins mode */
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT_PULL_UP);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN3, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB, GPIO_PIN2, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB, GPIO_PIN3, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	
	/**<  Set the priority of EXTI0 */
	MCAL_NVIC_vSetPriority(NVIC_EXTI0_IRQn,0,0);
	
	/**<  Enable EXTI0 */
	MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
	
	/**<  Initialize EXTI0 for port A pin 0 */
	EXTI_vInit();
	EXTI_InitForGPIO(EXTI_LINE0, EXTI_PORTMAP_GPIOA);
	EXTI_SetTrigger( EXTI_LINE0, EXTI_RISING_EDGE);
	EXTI_EnableLine(EXTI_LINE0);
	
	MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
	
	__enable_irq();
	
	
	
	
/*****************************< Void Loop ***********************/
	for(;;){
		
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
		MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
		
		MCAL_STK_SetDelay_ms(3000);
		
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
		MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
		MCAL_STK_SetDelay_ms(3000);
		
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
		MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
		MCAL_STK_SetDelay_ms(3000);
		
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
		MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
		MCAL_STK_SetDelay_ms(3000);
		
	}
}


void EXTI0_IRQHandler(void){ 
	
	u8 Pedestrain_Status;
	u32 i;
	for(i=0;i<3000;i++){
		MCAL_GPIO_GetPinValue(EXTI_PORTMAP_GPIOA, GPIO_PIN0, &Pedestrain_Status);
	}
	
		u8 Pedestrain_Red_TrafficLight;
		u8 Pedestrain_Yellow_TrafficLight;
		MCAL_GPIO_GetPinValue(GPIO_PORTB,GPIO_PIN1, &Pedestrain_Red_TrafficLight);
		MCAL_GPIO_GetPinValue(GPIO_PORTB,GPIO_PIN2, &Pedestrain_Yellow_TrafficLight);
	
	
	if(!Pedestrain_Status){
		
		if((Pedestrain_Yellow_TrafficLight) || (Pedestrain_Red_TrafficLight)){
			
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			
			u32 i;
			for (i=0; i<4000; i++){
				MCAL_GPIO_TogglePin(GPIO_PORTA,GPIO_PIN2);
				MCAL_GPIO_TogglePin(GPIO_PORTB,GPIO_PIN2);
			}
			
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
		
			for( i=0; i<100000 ; i++);
		
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
			
			if(Pedestrain_Yellow_TrafficLight){
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
				for( i=0; i<100000 ; i++);
			}
			else if(Pedestrain_Red_TrafficLight){
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
				for( i=0; i<100000 ; i++);
			}
			
			EXTI_ClearPending(EXTI_LINE0);
			MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
			
		}
		
		else {
			EXTI_ClearPending(EXTI_LINE0);
			MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
		}
	
	}
	
else if(Pedestrain_Status){
	
	/*if(Pedestrain_Yellow_TrafficLight || Pedestrain_Red_TrafficLight){
	
		MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
		MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);

			u32 i;
			for (i=0; i<2000; i++){
				MCAL_GPIO_TogglePin(GPIO_PORTA,GPIO_PIN2);
				MCAL_GPIO_TogglePin(GPIO_PORTB,GPIO_PIN2);
				
			}
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	}*/
	EXTI_ClearPending(EXTI_LINE0);
	MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
}
	
}
