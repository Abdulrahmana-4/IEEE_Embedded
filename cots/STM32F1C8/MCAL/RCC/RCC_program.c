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



STD_ReturnType Mcal_Rcc_InitSysClock(void)
{
    STD_ReturnType Local_FunctionStatus = E_NOT_OK;
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
        WHILE(!GET_BIT(RCC_CR, RCC_CR_HSERDY));

        /**<select HSE as a SYSCLK*/
        RCC_CFGR &= ~((0b11) << (RCC_CFGR_SW));
        RCC_CFGR |= ((0b01) << (RCC_CFGR_SW));

        /**< Select AHB prescaler */
        RCC_CFGR &= ~((0b1111) << (RCC_CFGR_HPRE));
        RCC_CFGR |= ((RCC_HPRE_FACTOR) << (RCC_CFGR_HPRE));

        /**< Select  APB low-speed prescaler (APB1) */
        RCC_CFGR &= ~((0b111) << (RCC_CFGR_PPRE1));
        RCC_CFGR |= ((RCC_PPRE1_FACTOR) << (RCC_CFGR_PPRE1));

        /**< Select  APB high-speed prescaler (APB2) */
        RCC_CFGR &= ~((0b111) << (RCC_CFGR_PPRE2));
        RCC_CFGR |= ((RCC_PPRE2_FACTOR) << (RCC_CFGR_PPRE2));

        /**< Select  ADC prescaler */
        RCC_CFGR &= ~((0b11) << (RCC_CFGR_ADCPRE));
        RCC_CFGR |= ((RCC_ADCPRE_FACTOR) << (RCC_CFGR_ADCPRE));

        Local_FunctionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_HSI
        /**< Enable HSI*/
        SET_BIT(RCC_CR, RCC_CR_HSION);

        /**< Wait until the clk be ready*/
        WHILE(!GET_BIT(RCC_CR, RCC_CR_HSIRDY));

        /**<select HSI as a SYSCLK*/
        RCC_CFGR &= ~((0b11) << (RCC_CFGR_SW));
        RCC_CFGR |= ((0b00) << (RCC_CFGR_SW));

        /**< Select AHB prescaler */
        RCC_CFGR &= ~((0b1111) << (RCC_CFGR_HPRE));
        RCC_CFGR |= ((CRCC_HPRE_FACTOR) << (RCC_CFGR_HPRE));

        /**< Select  APB low-speed prescaler (APB1) */
        RCC_CFGR &= ~((0b111) << (RCC_CFGR_PPRE1));
        RCC_CFGR |= ((RCC_PPRE1_FACTOR) << (RCC_CFGR_PPRE1));

        /**< Select  APB high-speed prescaler (APB2) */
        RCC_CFGR &= ~((0b111) << (RCC_CFGR_PPRE2));
        RCC_CFGR |= ((RCC_PPRE2_FACTOR) << (RCC_CFGR_PPRE2));

        /**< Select  ADC prescaler */
        RCC_CFGR &= ~((0b11) << (RCC_CFGR_ADCPRE));
        RCC_CFGR |= ((RCC_ADCPRE_FACTOR) << (RCC_CFGR_ADCPRE));  /**< printf("")*/

        Local_FunctionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_PLL

        /**< Select PLL entry clock source */
        RCC_CFGR &= ~((0b1) << (RCC_CFGR_PLLSRC));
        RCC_CFGR |= ((RCC_CFGR_PLLSRC) << (RCC_CFGR_PLLSRC));

        /**< Select HSE divider for PLL entry*/
        #if RCC_CFGR_PLLSRC == RCC_CFGR_PLLSRC_HSE
            RCC_CFGR &= ~((0b1) << (RCC_CFGR_PLLXTPRE));
            RCC_CFGR |= ((RCC_CFGR_PLLXTPRE) << (RCC_CFGR_PLLXTPRE));
        #endif

        /**< Enable PLL*/
        SET_BIT(RCC_CR, RCC_CR_PLLON);

        /**< Wait until the clk be ready*/
        WHILE(!GET_BIT(RCC_CR, RCC_CR_PLLRDY));

        /**<Select PLL as a SYSCLK */ 
        RCC_CFGR &= ~((0b11) << (RCC_CFGR_SW));
        RCC_CFGR |= ((0b10) << (RCC_CFGR_SW));

        /**< Selcet PLL multiplication factor*/
        RCC_CFGR &= ~((0b1111) << (RCC_CFGR_PLLMUL));
        RCC_CFGR |= ((RCC_PLLMUL_FACTOR) << (RCC_CFGR_PLLMUL));

        /**< Select AHB prescaler */
        RCC_CFGR &= ~((0b1111) << (RCC_CFGR_HPRE));
        RCC_CFGR |= ((RCC_HPRE_FACTOR) << (RCC_CFGR_HPRE));

        /**< Select  APB low-speed prescaler (APB1) */
        RCC_CFGR &= ~((0b111) << (RCC_CFGR_PPRE1));
        RCC_CFGR |= ((RCC_PPRE1_FACTOR) << (RCC_CFGR_PPRE1));

        /**< Select  APB high-speed prescaler (APB2) */
        RCC_CFGR &= ~((0b111) << (RCC_CFGR_PPRE2));
        RCC_CFGR |= ((RCC_PPRE2_FACTOR) << (RCC_CFGR_PPRE2));

        /**< Select  ADC prescaler */
        RCC_CFGR &= ~((0b11) << (RCC_CFGR_ADCPRE));
        RCC_CFGR |= ((RCC_ADCPRE_FACTOR) << (RCC_CFGR_ADCPRE));_

        Local_FunctionStatus = E_OK;

    #else 
        #error"wrong choice!!"

    #endif /**< RCC_SYSCLK*/

    return Local_FunctionStatus;
}

STD_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    STD_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
    case RCC_AHB:
        SET_BIT(RCC_AHBENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;
    case RCC_APB1:
        SET_BIT(RCC_AHB1ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;
    case RCC_APB2:
        SET_BIT(RCC_AHB2ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;
    
    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }


    return Local_FunctionStatus;
}

STD_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    STD_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
    case RCC_AHB:
        CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;
    case RCC_APB1:
        CLR_BIT(RCC_AHB1ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;
    case RCC_APB2:
        CLR_BIT(RCC_AHB2ENR, Copy_PeripheralId);
        Local_FunctionStatus = E_OK;
        break;
    
    default:
        Local_FunctionStatus = E_NOT_OK;
        break;
    }


    return Local_FunctionStatus;
}
