/*********************************************************************************************/
/******************************* Author    : Abdulrahman Ahmed *******************************/
/******************************* Version   : 0.1               *******************************/
/******************************* Module    : RCC_interface.h   *******************************/
/*********************************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


/**
 * @defgroup RCC_Peripheral_Macros RCC Peripheral Macros
 * @brief Macros related to clock configuration for different peripherals.
 * @{
 */

/**
 * @defgroup RCC_Clock_Domains Clock Domains
 * @brief Macros defining the available clock domains for peripheral clock configuration.
 * @{
 */

/**
 * @brief Available clock domains for peripheral clock configuration.
 */

#define RCC_AHB                 0  /**< Advanced High-performance Bus (AHB) domain. */
#define RCC_APB1                1  /**< Advanced Peripheral Bus 1 (APB1) domain. */
#define RCC_APB2                2  /**< Advanced Peripheral Bus 2 (APB2) domain. */
/** @} */


/**
 * @defgroup RCC_AHBENR_Bit_Def RCC_AHBENR Bit Definitions
 * @brief Macros representing the bit positions in the AHB Peripheral Clock Enable Register (RCC_AHBENR).
 * @{
 */
#define RCC_AHBENR_DMA1EN       0  /**< DMA1 clock enable */
#define RCC_AHBENR_DMA2EN       1  /**< DMA2 clock enable */
#define RCC_AHBENR_SRAMEN       2  /**< SRAM interface clock enable */
#define RCC_AHBENR_FLITFEN      4  /**< FLITF clock enable */
#define RCC_AHBENR_CRCEN        6  /**< CRC clock enable */
#define RCC_AHBENR_OTGFSEN      12 /**< USB OTG FS clock enable */
#define RCC_AHBENR_ETHMACEN     14 /**< Ethernet MAC clock enable */
#define RCC_AHBENR_ETHMACTXEN   15 /**< Ethernet Transmission clock enable */
#define RCC_AHBENR_ETHMACRXEN   16 /**< Ethernet Reception clock enable */
#define RCC_AHBENR_ETHMACPTPEN  17 /**< Ethernet PTP clock enable */
#define RCC_AHBENR_OTGHSEN      29 /**< USB OTG HS clock enable */
/** @} */


/**
 * @defgroup RCC_APB1ENR_Bit_Def RCC_APB1ENR Bit Definitions
 * @brief Macros representing the bit positions in the APB1 Peripheral Clock Enable Register (RCC_APB1ENR).
 * @{
 */
#define RCC_APB1ENR_TIM2EN      0  /**< Timer 2 clock enable */
#define RCC_APB1ENR_TIM3EN      1  /**< Timer 3 clock enable */
#define RCC_APB1ENR_TIM4EN      2  /**< Timer 4 clock enable */
#define RCC_APB1ENR_TIM5EN      3  /**< Timer 5 clock enable */
#define RCC_APB1ENR_TIM6EN      4  /**< Timer 6 clock enable */
#define RCC_APB1ENR_TIM7EN      5  /**< Timer 7 clock enable */
#define RCC_APB1ENR_TIM12EN     6  /**< Timer 12 clock enable */
#define RCC_APB1ENR_TIM13EN     7  /**< Timer 13 clock enable */
#define RCC_APB1ENR_TIM14EN     8  /**< Timer 14 clock enable */
#define RCC_APB1ENR_WWDGEN      11 /**< Window Watchdog clock enable */
#define RCC_APB1ENR_SPI2EN      14 /**< SPI2 clock enable */
#define RCC_APB1ENR_SPI3EN      15 /**< SPI3 clock enable */
#define RCC_APB1ENR_USART2EN    17 /**< USART2 clock enable */
#define RCC_APB1ENR_USART3EN    18 /**< USART3 clock enable */
#define RCC_APB1ENR_UART4EN     19 /**< UART4 clock enable */
#define RCC_APB1ENR_UART5EN     20 /**< UART5 clock enable */
#define RCC_APB1ENR_I2C1EN      21 /**< I2C1 clock enable */
#define RCC_APB1ENR_I2C2EN      22 /**< I2C2 clock enable */
#define RCC_APB1ENR_USBEN       23 /**< USB clock enable */
#define RCC_APB1ENR_CANEN       25 /**< CAN clock enable */
#define RCC_APB1ENR_BKPEN       27 /**< Backup interface clock enable */
#define RCC_APB1ENR_PWREN       28 /**< Power interface clock enable */
#define RCC_APB1ENR_DACEN       29 /**< DAC clock enable */
/** @} */

/**
 * @defgroup RCC_APB2ENR_Bit_Def RCC_APB2ENR Bit Definitions
 * @brief Macros representing the bit positions in the APB2 Peripheral Clock Enable Register (RCC_APB2ENR).
 * @{
 */
#define RCC_APB2ENR_AFIOEN      0  /**< Alternate function IO clock enable */
#define RCC_APB2ENR_IOPAEN      2  /**< I/O port A clock enable */
#define RCC_APB2ENR_IOPBEN      3  /**< I/O port B clock enable */
#define RCC_APB2ENR_IOPCEN      4  /**< I/O port C clock enable */
#define RCC_APB2ENR_IOPDEN      5  /**< I/O port D clock enable */
#define RCC_APB2ENR_IOPEEN      6  /**< I/O port E clock enable */
#define RCC_APB2ENR_IOPFEN      7  /**< I/O port F clock enable */
#define RCC_APB2ENR_IOPGEN      8  /**< I/O port G clock enable */
#define RCC_APB2ENR_ADC1EN      9  /**< ADC1 clock enable */
#define RCC_APB2ENR_ADC2EN      10 /**< ADC2 clock enable */
#define RCC_APB2ENR_TIM1EN      11 /**< Timer 1 clock enable */
#define RCC_APB2ENR_SPI1EN      12 /**< SPI1 clock enable */
#define RCC_APB2ENR_TIM8EN      13 /**< Timer 8 clock enable */
#define RCC_APB2ENR_USART1EN    14 /**< USART1 clock enable */
#define RCC_APB2ENR_ADC3EN      15 /**< ADC3 clock enable */
#define RCC_APB2ENR_TIM9EN      19 /**< Timer 9 clock enable */
#define RCC_APB2ENR_TIM10EN     20 /**< Timer 10 clock enable */
#define RCC_APB2ENR_TIM11EN     21 /**< Timer 11 clock enable */
/** @} */

/** @} */  /* End of RCC_Peripheral_Macros group */


/**
 * @defgroup RCC_API RCC APIs
 * @brief Functions for RCC (Reset and Clock Control) configuration.
 * @{
 */

/**
 * @brief Initialize the system clock configuration.
 *
 * This function initializes the system clock configuration according to the desired settings.
 * It should be called early in the program to properly configure the clock system.
 *
 * @return Std_ReturnType
 * @retval E_OK     Clock initialization successful.
 * @retval E_NOT_OK Clock initialization failed.
 */
STD_ReturnType Mcal_Rcc_InitSysClock(void);

/**
 * @brief Enable a specific peripheral on a specific bus.
 *
 * This function enables a specific peripheral on a specific bus.
 *
 * @param[in] Copy_PeripheralId The ID of the peripheral to be enabled.
 * @param[in] Copy_BusId        The ID of the bus to which the peripheral belongs (RCC_AHB, RCC_APB1, or RCC_APB2).
 * @return Std_ReturnType
 * @retval E_OK     Peripheral enabling successful.
 * @retval E_NOT_OK Peripheral enabling failed.
 */
STD_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId);

/**
 * @brief Disable a specific peripheral.
 *
 * This function disables a previously enabled peripheral.
 * 
 * @param[in] Copy_PeripheralId The ID of the peripheral to be enabled.
 * @param[in] Copy_BusId        The ID of the bus to which the peripheral belongs (RCC_AHB, RCC_APB1, or RCC_APB2).
 * @return Std_ReturnType
 * @retval E_OK     Peripheral disabling successful.
 * @retval E_NOT_OK Peripheral disabling failed.
 */
STD_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId);
/**
 * @}
 */
  

/**
 * @defgroup CFGR_PLLMUL PLL multiplication factor.
 * @brief Definitions for different PLL multiplication factors.
 * @{
 */
#define CFGR_PLLMUL_2        0b0000    /**< PLL input clock x 2  */
#define CFGR_PLLMUL_3        0b0001    /**< PLL input clock x 3  */
#define CFGR_PLLMUL_4        0b0010    /**< PLL input clock x 4  */
#define CFGR_PLLMUL_5        0b0011    /**< PLL input clock x 5  */
#define CFGR_PLLMUL_6        0b0100    /**< PLL input clock x 6  */
#define CFGR_PLLMUL_7        0b0101    /**< PLL input clock x 7  */
#define CFGR_PLLMUL_8        0b0110    /**< PLL input clock x 8  */
#define CFGR_PLLMUL_9        0b0111    /**< PLL input clock x 9  */
#define CFGR_PLLMUL_10       0b1000    /**< PLL input clock x 10 */
#define CFGR_PLLMUL_11       0b1001    /**< PLL input clock x 11 */
#define CFGR_PLLMUL_12       0b1010    /**< PLL input clock x 12 */
#define CFGR_PLLMUL_13       0b1011    /**< PLL input clock x 13 */
#define CFGR_PLLMUL_14       0b1100    /**< PLL input clock x 14 */
#define CFGR_PLLMUL_15       0b1101    /**< PLL input clock x 15 */
#define CFGR_PLLMUL_16       0b1110    /**< PLL input clock x 16 */
/** @} */


/**
 * @defgroup CFGR_HPRE AHB prescaler.
 * @brief Definitions for different division factors of the AHB clock.
 * @{
 */
#define CFGR_HPRE_1          0b0000    /**< SYSCLK not divided*/
#define CFGR_HPRE_2          0b1000    /**< SYSCLK divided by 2*/
#define CFGR_HPRE_4          0b1001    /**< SYSCLK divided by 4*/
#define CFGR_HPRE_8          0b1010    /**< SYSCLK divided by 8*/
#define CFGR_HPRE_16         0b1011    /**< SYSCLK divided by 16*/
#define CFGR_HPRE_64         0b1100    /**< SYSCLK divided by 64*/
#define CFGR_HPRE_128        0b1101    /**< SYSCLK divided by 128*/
#define CFGR_HPRE_256        0b1110    /**< SYSCLK divided by 256*/
#define CFGR_HPRE_512        0b1111    /**< SYSCLK divided by 512*/
/** @} */


/**
 * @defgroup CFGR_PPRE1 APB low-speed prescaler (APB1).
 * @brief Definitions for different division factors of the APB high-speed clock (PCLK1).
 * @{
 */
#define CFGR_PPRE1_1         0b000     /**< HCLK not divided*/     
#define CFGR_PPRE1_2         0b100     /**< HCLK divided by 2*/  
#define CFGR_PPRE1_4         0b101     /**< HCLK divided by 4*/  
#define CFGR_PPRE1_8         0b110     /**< HCLK divided by 8*/  
#define CFGR_PPRE1_16        0b111     /**< HCLK divided by 16*/  
/** @} */


/**
 * @defgroup CFGR_PPRE1 APB high-speed prescaler (APB2).
 * @brief Definitions for different division factorS of the APB high-speed clock (PCLK2).
 * @{
 */
#define CFGR_PPRE2_1         0b000     /**< HCLK not divided*/     
#define CFGR_PPRE2_2         0b100     /**< HCLK divided by 2*/  
#define CFGR_PPRE2_4         0b101     /**< HCLK divided by 4*/  
#define CFGR_PPRE2_8         0b110     /**< HCLK divided by 8*/  
#define CFGR_PPRE2_16        0b111     /**< HCLK divided by 16*/  
/** @} */

/**
 * @defgroup CFGR_ADCPRE: ADC prescaler.
 * @brief Definitions for different division factorS of the clock to the ADCs.
 * @{
 */
#define CFGR_ADCPRE_2         0b00     /**< PCLK2 divided by 2*/     
#define CFGR_ADCPRE_4         0b01     /**< PCLK2 divided by 4*/  
#define CFGR_ADCPRE_6         0b10     /**< PCLK2 divided by 6*/  
#define CFGR_ADCPRE_8         0b11     /**< PCLK2 divided by 8*/   
/** @} */


/**
 * @brief Available clock sources for PLL clock.
 */
#define RCC_CFGR_PLLSRC_HSI   0
#define RCC_CFGR_PLLSRC_HSE   1
/** @} */

/**
 * @defgroup CFGR_ADCPRE: ADC prescaler.
 * @brief Definitions for different division factorS of the clock to the ADCs.
 * @{
 */
#define CFGR_PLLXTPRE_1         0     /**< clock not divided*/     
#define CFGR_PLLXTPRE_2         1     /**< clock divided by 2*/     
/** @} */

#endif /*RCC_INTERFACE_H_*/
