/*********************************************************************************************/
/******************************* Author    : Abdulrahman Ahmed *******************************/
/******************************* Version   : 0.1               *******************************/
/******************************* Module    : RCC_program.c     *******************************/
/*********************************************************************************************/

/******************************************** LIB ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************** MCAL *******************************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



STD_ReturnType Mcal_Rcc_InitSysClock(void);{
    STD_ReturnType local_functionStatus = E_NOT_OK;
    #if RCC_SYSCLK == RCC_HSE
        
        /**< Select which external clk to will be a CLK system */
        #if RCC_CLK_BYPASS == RCC_RC_CLK
            SET_BIT(RCC_CR, RCC_CR_HSEBYP);  /**< choose RC as a system clock*/
        #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK
            CLR_BIT(RCC_CR, RCC_CR_HSEBYP);  /**< choose crystal as a system clock*/
        #else 
            #error "wrong choice !!"
        #endif /**< RCC_CLK_BYPASS*/

        /**<Enable HSE*/
        SET_BIT(RCC_CR, RCC_CR_HSEON);

        /**< Wait until the clk be ready*/
        WHILE(!GET_BIT(RCC_CR, RCC_CR_HSERDY))

        /**<select HSE as a SYSCLK*/
        RCC_CFGR = 0X00000001;

        local_functionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_HSI
        /**< Enable HSI*/
        SET_BIT(RCC_CR, RCC_CR_HSION);

        /**< Wait until the clk be ready*/
        WHILE(!GET_BIT(RCC_CR, RCC_CR_HSIRDY))

        /**<select HSI as a SYSCLK*/
        RCC_CFGR = 0X00000000;

        local_functionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_PLL
        /**< Enable PLL*/
        SET_BIT(RCC_CR, RCC_CR_PLLON);

        /**< Wait until the clk be ready*/
        WHILE(!GET_BIT(RCC_CR, RCC_CR_PLLRDY))

        /**<select PLL as a SYSCLK*/
        RCC_CFGR = 0X00000010;

        local_functionStatus = E_OK;

    #else 
        #error"wrong choice!!"

    #endif /**< RCC_SYSCLK*/

    return local_functionStatus;
}

STD_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_PeripheralId, u8 Copy_BusId);{
    STD_ReturnType local_functionStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
    case RCC_AHB:
        SET_BIT(RCC_AHBENR, Copy_PeripheralId);
        local_functionStatus = E_OK;
        break;
    case RCC_APB1:
        SET_BIT(RCC_AHB1ENR, Copy_PeripheralId);
        local_functionStatus = E_OK;
        break;
    case RCC_APB2:
        SET_BIT(RCC_AHB2ENR, Copy_PeripheralId);
        local_functionStatus = E_OK;
        break;
    
    default:
        local_functionStatus = E_NOT_OK;
        break;
    }


    return local_functionStatus;
}

STD_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_PeripheralId, u8 Copy_BusId);{
    STD_ReturnType local_functionStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
    case RCC_AHB:
        CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
        local_functionStatus = E_OK;
        break;
    case RCC_APB1:
        CLR_BIT(RCC_AHB1ENR, Copy_PeripheralId);
        local_functionStatus = E_OK;
        break;
    case RCC_APB2:
        CLR_BIT(RCC_AHB2ENR, Copy_PeripheralId);
        local_functionStatus = E_OK;
        break;
    
    default:
        local_functionStatus = E_NOT_OK;
        break;
    }


    return local_functionStatus;
}
