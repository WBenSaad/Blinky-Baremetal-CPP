#include "LED.h"




LED::LED(const std::uint32_t port,const GPIO_REG::Pin pin):Port(port),Pin(pin)
			{
				std::int32_t temp=0;
				//Set the Clock of the Port
				switch(Port){
					case (GPIO_REG::GPIOA) :
					{
						temp =(0x01 << 2);
						break;
					}
					case (GPIO_REG::GPIOB) :
					{
						temp =(0x01 << 3);
						break;
					}
					case (GPIO_REG::GPIOC) :
					{
						temp =(0x01 << 4);
						break;
					}
				}
				
				*reinterpret_cast<volatile std::uint32_t*>(CLOCK_REG::RCC_BASE + CLOCK_REG::RCC_AHBENR_OFFSET) 
				|= static_cast<std::uint32_t> (temp);
						
				if (Pin < 7)
					{
						//General Purpose push-pull with Output Speed of 10MHZ
						
						*reinterpret_cast<volatile std::uint32_t*>(Port + GPIO_REG::CRL_OFFSET) 
						&= ~static_cast<std::uint32_t>(0xF << 4*Pin);
						
						*reinterpret_cast<volatile std::uint32_t*>(Port + GPIO_REG::CRL_OFFSET) 
						|= static_cast<std::uint32_t>(0x01 << 4*Pin);
						
					}
			
				else 
				 {
						*reinterpret_cast<volatile std::uint32_t*>(Port + GPIO_REG::CRL_OFFSET) 
						&= ~static_cast<std::uint32_t>(0xF << 4*(Pin-8));
							
				 		*reinterpret_cast<volatile std::uint32_t*>(Port + GPIO_REG::CRH_OFFSET) 
						|= ~static_cast<std::uint32_t>(0x01 << (Pin - 8));
				 
				 }
			}
			void LED::SET()
			{
				
				*reinterpret_cast<volatile std::uint32_t*>(Port + GPIO_REG::ODR_OFFSET)
				|= static_cast<std::uint32_t>(0x1 << Pin);
		
			}
		
			void LED::RESET()
			{
				*reinterpret_cast<volatile std::uint32_t*>(Port + GPIO_REG::ODR_OFFSET)
				&= ~ static_cast<std::uint32_t>(0x1 << Pin);				
			
			}
		
			void LED::Toggle()
			{
				*reinterpret_cast<volatile std::uint32_t*>(Port + GPIO_REG::ODR_OFFSET)
				^= static_cast<std::uint32_t>(0x1 << Pin);				
		
			}
		
			void LED::Read()
			{
				
				*reinterpret_cast<volatile std::uint32_t*>(Port + GPIO_REG::IDR_OFFSET)
				&= static_cast<std::uint32_t>(0x1 << Pin);				
				
			}
		





