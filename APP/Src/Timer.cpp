#include "Timer.h"



Timer::Timer(){
	  

	//Modify the Counting Mode
	*reinterpret_cast<volatile std::uint32_t*>(TIMER_REG::TIM2 + TIMER_REG::TIM_CR1) 
	&= ~static_cast<std::uint32_t> ((0x1  << 4)|(0x1 << 3));

    //Enable Timer2 Clock	
	EnablePeripheral();
	
}

void Timer::Delay(std::uint16_t milliseconds){
	
		
	//We load the PSC value and AutoReload Value
	
	SetPeriod();
	SetPrescaler(milliseconds);
	
	
	//We start the Counter
	StartCounter();
	
	//We will wait till the Counter made it to our Value 
	while(GetCounter() < milliseconds);
	
	
}
std::uint32_t Timer::GetCounter(){
	
	return(*reinterpret_cast<volatile std::uint32_t*>(TIMER_REG::TIM2 + TIMER_REG::TIM_CNT));
	
}

void Timer::SetPrescaler(std::uint16_t milliseconds){
	std::uint16_t PSC =	static_cast<std::uint16_t>((8000000*milliseconds)/(1000*(Period+1)));
	*reinterpret_cast<volatile std::uint32_t*>(TIMER_REG::TIM2 + TIMER_REG::TIM_PSC) 
	&= ~static_cast<std::uint32_t> (0xFFFF);
	*reinterpret_cast<volatile std::uint32_t*>(TIMER_REG::TIM2 + TIMER_REG::TIM_PSC) = PSC ;
	}


void Timer::SetPeriod(){
	std::uint16_t ARR =	0xFFFF - 1;
	Period=ARR;
	*reinterpret_cast<volatile std::uint16_t*>(TIMER_REG::TIM2 + TIMER_REG::TIM_ARR)  = ARR;

	}


void Timer::StartCounter(){
	
		*reinterpret_cast<volatile std::uint32_t*>(TIMER_REG::TIM2 + TIMER_REG::TIM_CR1) |= (1 << 0 );
	}


void Timer::EnablePeripheral(){

    *reinterpret_cast<volatile std::uint32_t*>(CLOCK_REG::RCC_BASE + CLOCK_REG::RCC_APB1ENR_OFFSET) 
		|= static_cast<std::uint32_t> (1 << 0);

	}


void Timer::DisablePeripheral(){

		*reinterpret_cast<volatile std::uint32_t*>(CLOCK_REG::RCC_BASE + CLOCK_REG::RCC_APB1ENR_OFFSET) 
		&= ~static_cast<std::uint32_t> (1 << 0);
}
