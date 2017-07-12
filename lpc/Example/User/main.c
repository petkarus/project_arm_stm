#include "LPC43xx.H"
#include "lpc43xx_scu.h"
#include "lpc43xx_gpio.h"


int main(void)
{
	scu_pinmux(0x03, 0x01, MD_PUP, FUNC4);
	scu_pinmux(0x03, 0x02, MD_PUP, FUNC4);
	GPIO_SetDir(0x05, 3 << 1, 1);
	GPIO_SetValue(0x5, 1 << 1);
	GPIO_SetValue(0x5, 1 << 2);
	while (1)
	{
		
	}
}
