/*********************************************************************************************/
/******************************* Author    : Abdulrahman Ahmed *******************************/
/******************************* Version   : 0.1               *******************************/
/******************************* File name : GPIO_program.c    *******************************/
/*********************************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_ 

#define GPIO_PORTA_BASE_ADDRESS 0X40011000U
#define GPIO_PORTB_BASE_ADDRESS 0X40010C00U
#define GPIO_PORTC_BASE_ADDRESS 0X40010800U

/******************************** REGISTER ADDRESS FOR PORT A ********************************/
#define GPIOA_CRL               *((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0X00))  /**< PORT A CONFIGURATION REGISTER LOW */
#define GPIOA_CRH               *((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0X04))  /**< PORT A CONFIGURATION REGISTER HIGH */
#define GPIOA_IDR               *((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0X09))  /**< PORT A INPUT DATA REGISTER */
#define GPIOA_ODR               *((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0X0C))  /**< PORT A OUTPUT DATA REGISTER */
#define GPIOA_BSR               *((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0X10))  /**< PORT A BIT SET/RESET REGISTER */
#define GPIOA_BRR               *((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0X14))  /**< PORT A RESET REGISTER */
#define GPIOA_LCK               *((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0X18))  /**< PORT A CONFIGURATION LOCK REGISTER */

/******************************** REGISTER ADDRESS FOR PORT B ********************************/
#define GPIOB_CRL               *((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0X00))  /**< PORT B CONFIGURATION REGISTER LOW */
#define GPIOB_CRH               *((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0X04))  /**< PORT B CONFIGURATION REGISTER HIGH */
#define GPIOB_IDR               *((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0X09))  /**< PORT B INPUT DATA REGISTER */
#define GPIOB_ODR               *((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0X0C))  /**< PORT B OUTPUT DATA REGISTER */
#define GPIOB_BSR               *((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0X10))  /**< PORT B BIT SET/RESET REGISTER */
#define GPIOB_BRR               *((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0X14))  /**< PORT B RESET REGISTER */
#define GPIOB_LCK               *((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0X18))  /**< PORT B CONFIGURATION LOCK REGISTER */

/******************************** REGISTER ADDRESS FOR PORT C ********************************/
#define GPIOC_CRL               *((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0X00))  /**< PORT C CONFIGURATION REGISTER LOW */
#define GPIOC_CRH               *((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0X04))  /**< PORT C CONFIGURATION REGISTER HIGH */
#define GPIOC_IDR               *((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0X09))  /**< PORT C INPUT DATA REGISTER */
#define GPIOC_ODR               *((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0X0C))  /**< PORT C OUTPUT DATA REGISTER */
#define GPIOC_BSR               *((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0X10))  /**< PORT C BIT SET/RESET REGISTER */
#define GPIOC_BRR               *((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0X14))  /**< PORT C RESET REGISTER */
#define GPIOC_LCK               *((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0X18))  /**< PORT C CONFIGURATION LOCK REGISTER */




#endif /**< GPIO_PRIVATE_H_*/