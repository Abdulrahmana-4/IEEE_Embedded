/*********************************************************************************************/
/******************************* Author    : Abdulrahman Ahmed *******************************/
/******************************* Version   : 0.1               *******************************/
/******************************* file name : STD_TYPES.h       *******************************/
/*********************************************************************************************/

#ifndef STD_TYPES_h_
#define STD_TYPES_h_

typedef unsigned char     u8;
typedef unsigned short    u16;
typedef unsigned int      u32;
typedef unsigned long     u64;

typedef signed char       s8;
typedef signed short      s16;
typedef signed int        s32;
typedef signed long       s64;

typedef float             f32;
typedef double            f64;
typedef long double       f96;

typedef u8                STD_ReturnType;
typedef s8                INVALID_VALUE;   /**< Marker for invalid or uninitialized data */

#define E_OK              (STD_ReturnType)1
#define E_NOT_OK          (STD_ReturnType)0

#define NULL              ((void*)0x00)


#endif /*STD_TYPES_h_*/
