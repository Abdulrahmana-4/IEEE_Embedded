/*********************************************************************************************/
/******************************* Author    : Abdulrahman Ahmed *******************************/
/******************************* Version   : 0.1               *******************************/
/******************************* Module    : RCC_private.h     *******************************/
/*********************************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/**
 * @defgroup RCC_Registers
 * @brief Reset and Clock Control (RCC) Registers
 *
 * This module provides definitions for the RCC (Reset and Clock Control) registers
 * for configuring and controlling system clocks and resets in the microcontroller.
 *
 * @{
 */

/**
 * @brief RCC Control Register (CR)
 *
 * This register provides control over the main and PLL (Phase-Locked Loop) system clocks.
 */

#define RCC_CR               *((volatile u32*)0x40021000)

/**
 * @brief RCC Configuration Register (CFGR)
 *
 * This register configures the system clock sources, prescalers, and peripherals clocks.
 */

#define RCC_CFGR             *((volatile u32*)0x40021004)

/**
 * @brief RCC Clock Interrupt Register (CIR)
 *
 * This register manages clock interrupts and flags.
 */

#define RCC_CIR              *((volatile u32*)0x40021008)

/**
 * @brief RCC APB2 Peripheral Reset Register (APB2RSTR)
 *
 * This register controls the reset state of peripherals connected to APB2 bus.
 */

#define RCC_APB2RSTR         *((volatile u32*)0x4002100C)

/**
 * @brief RCC APB1 Peripheral Reset Register (APB1RSTR)
 *
 * This register controls the reset state of peripherals connected to APB1 bus.
 */

#define RCC_APB2RSTR         *((volatile u32*)0x40021010)

/**
 * @brief RCC AHB Peripheral Clock Enable Register (AHBENR)
 *
 * This register enables clock access for peripherals connected to AHB bus.
 */

#define RCC_AHBENR           *((volatile u32*)0x40021014)

/**
 * @brief RCC APB1 Peripheral Clock Enable Register (APB1ENR)
 *
 * This register enables clock access for peripherals connected to APB1 bus.
 */

#define RCC_AHB2ENR          *((volatile u32*)0x40021018)

/**
 * @brief RCC APB2 Peripheral Clock Enable Register (APB2ENR)
 *
 * This register enables clock access for peripherals connected to APB2 bus.
 */

#define RCC_AHB1ENR          *((volatile u32*)0x4002101C)

/**
 * @brief RCC Backup Domain Control Register (BDCR)
 *
 * This register provides control over backup domain and RTC (Real-Time Clock).
 */

#define RCC_BDCR             *((volatile u32*)0x40021020)

/**
 * @brief RCC Control and Status Register (CSR)
 *
 * This register provides various control and status flags.
 */

#define RCC_CSR              *((volatile u32*)0x40021024)

/** @} */ // end of RCC Control Register (CR)


/**
 * @defgroup RCC_CR_Bit_Definitions RCC Control Register (RCC_CR) Bit Definitions
 * @{
 */

#define RCC_CR_HSION         0          /**< Internal High-Speed Clock Enable */
#define RCC_CR_HSIRDY        1          /**< Internal High-Speed Clock Ready */
#define RCC_CR_HSICAL        8          /**< Internal High-Speed Clock Calibration */
#define RCC_CR_HSEON         16         /**< External High-Speed Clock Enable */
#define RCC_CR_HSERDY        17         /**< External High-Speed Clock Ready */
#define RCC_CR_HSEBYP        18         /**< External High-Speed Clock Bypass */
#define RCC_CR_HSEPRE        19         /**< External High-Speed Clock Prescaler */
#define RCC_CR_CSSON         24         /**< Clock Security System Enable */
#define RCC_CR_PLLON         24         /**< PLL Enable */
#define RCC_CR_PLLRDY        25         /**< PLL Ready */

/** @} */ // end of RCC_CR_Bit_Definitions


/**
 * @defgroup RCC_CFGR_Bit_Definitions RCC Clock configuration register (RCC_CFGR) Bit Definitions
 * @{
 */

#define RCC_CFGR_SW          0
#define RCC_CFGR_HPRE        4
#define RCC_CFGR_PPRE1       8
#define RCC_CFGR_PPRE2       11
#define RCC_CFGR_ADCPRE      14
#define RCC_CFGR_PLLSRC      16
#define RCC_CFGR_PLLXTPRE      17
#define RCC_CFGR_PLLMUL      18

/** @} */ // end of RCC_CR_Bit_Definitions

/**
 * @defgroup RCC_Clock_Source RCC Clock Source Macros
 * @{
 */

#define RCC_HSI              0          /**< High-Speed Internal Clock Source (HSI) */
#define RCC_HSE              1          /**< High-Speed External Clock Source (HSE) */
#define RCC_PLL              2          /**< Phase-Locked Loop Clock Source (PLL) */

/** @} */ // end of RCC_Clock_Source


/**
 * @defgroup RCC_Clock_Type RCC Clock Type Macros
 * @{
 */

#define RCC_CRYSTRAL_CLK     1          /**< Crystal Oscillator Clock Type */
#define RCC_RC_CLK           0          /**< RC Oscillator Clock Type */

/** @} */ // end of RCC_Clock_Type

#endif /*RCC_PRIVATE_H_*/
