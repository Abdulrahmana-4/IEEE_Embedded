/******************************************** LIB ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************** MCAL *******************************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

int main(void)
{
	/**< INIT RCC*/
	Mcal_Rcc_InitSysClock();
	for(;;);
	

}
