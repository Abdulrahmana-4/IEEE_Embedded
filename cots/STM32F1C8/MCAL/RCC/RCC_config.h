/*********************************************************************************************/
/******************************* Author    : Abdulrahman Ahmed *******************************/
/******************************* Version   : 0.1               *******************************/
/******************************* Module    : RCC_config.h      *******************************/
/*********************************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and type.
 * @{
 */

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */



/**
 * @brief
 * your options : RCC_HSI
 *              : RCC_HSE
 *              : RCC_PLL
 */

#define RCC_SYSCLK              RCC_HSE


/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */

#if RCC_SYSCLK == RCC_HSE
#define RCC_CLK_BYPASS          RCC_RC_CLK

#endif

/**
 * @brief Configure PLL multiplication factor.
 * @note CFGR_PLLMUL_(multiplication factor)
 * multiplication factor = Choose number from 2 to 16
 */
#define RCC_PLLMUL_FACTOR       CFGR_PLLMUL_2


/**
 * @brief Configure  AHB prescalerr.
 * @note CFGR_HPRE_(division factor)
 * division factor = Choose number from {1,2,4,8,16,64,128,256,512}
 */
#define RCC_HPRE_FACTOR         CFGR_HPRE_1


/**
 * @brief Configure   APB low-speed prescaler (APB1).
 * @note CFGR_PPRE1_(division factor)
 * division factor = Choose number from {1,2,4,8,16}
 */
#define RCC_PPRE1_FACTOR         CFGR_PPRE1_1


/**
 * @brief Configure   APB high-speed prescaler (APB2).
 * @note CFGR_PPRE2_(division factor)
 * division factor = Choose number from {1,2,4,8,16}
 */
#define RCC_PPRE2_FACTOR         CFGR_PPRE2_1


/**
 * @brief Configure   APB high-speed prescaler (APB2).
 * @note CFGR_ ADCPRE_(division factor)
 * division factor = Choose number from {2,4,6,8}
 */
#define RCC_ADCPRE_FACTOR        CFGR_ADCPRE_2

/**
 * @brief Configure the PLL clock source.
 * @note Choose one of the available options:
 *       RCC_CFGR_PLLSRC_HSI  - HSI oscillator clock / 2 selected as PLL input clock.
 *       RCC_CFGR_PLLSRC_HSE  - HSE oscillator clock selected as PLL input clock.
 */

#define RCC_CFGR_PLLSRC          RCC_CFGR_PLLSRC_HSI


/**
 * @brief Configure HSE divider for PLL entry.
 * @note Choose one of the available options:
 *       CFGR_PLLXTPRE_1  - HSE clock not divided.
 *       CFGR_PLLXTPRE_2  - HSE clock divided by 2.
 */
#define RCC_CFGR_PLLXTPRE        CFGR_PLLXTPRE_1


#endif /*RCC_CONFIG_H_*/






[2, 1, 3, 6]  [3, 5, 6, 8]
[2, 1, 3, 6]
[2, 1, 3, 6] 

[6, 5, 18, 48]