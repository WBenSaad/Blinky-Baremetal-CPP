#include "LED.h"



int main(){
	
	 LED Led
		{
			GPIO_REG::GPIOA,
			GPIO_REG::GPIO_PIN4
		};
		
	Led.SET();
	return 0;
}
