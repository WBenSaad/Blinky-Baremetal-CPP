#include <cstdint>
#pragma once

	// Compile-time constant register addresses.
/*
template<typename addr_type,
				 typename reg_type,
				 const addr_type addr,
				 const std::uint32_t offset,
				 std::uint32_t Pin>
					 
class reg_access 
	{
		
	public :
		static void reg_set()
		{
				*reinterpret_cast<volatile reg_type*>(addr + offset)
				|= static_cast<reg_type>(0x1 << Pin);
		}

		static void reg_reset()
		{
				*reinterpret_cast<volatile reg_type*>(addr + offset)
				&= ~static_cast<reg_type>(0x1 << Pin);
		}
		static void reg_toggle()
		{
				*reinterpret_cast<volatile reg_type*>(addr + offset)
				^= static_cast<reg_type>(0x1 << Pin);
		}		
		static void reg_read()
		{
				*reinterpret_cast<volatile reg_type*>(addr + offset)
				&= static_cast<reg_type>(0x1 << Pin);
		}
		
	};
	*/
	namespace MISC_REG
	{
		
		constexpr std::uint32_t PERIPH_BASE 		=	0x40000000 ;
		constexpr std::uint32_t APB1PERIPH_BASE =	PERIPH_BASE ;
		constexpr std::uint32_t APB2PERIPH_BASE =	(PERIPH_BASE + 0x10000) ;
		constexpr std::uint32_t AHBPERIPH_BASE  = (PERIPH_BASE + 0x20000);
	}
	
	
	namespace CLOCK_REG
	{
		
		constexpr std::uint32_t RCC_BASE 	 							=	(MISC_REG::AHBPERIPH_BASE + 0x1000) ;
		constexpr std::uint32_t RCC_APB1ENR_OFFSET 			=	0x1C ;
		constexpr std::uint32_t RCC_AHBENR_OFFSET 			=	0x18 ;

	
	}
	namespace TIMER_REG
	{

		
		constexpr std::uint32_t 	TIM2 			=		(MISC_REG::APB1PERIPH_BASE +0x0000) ;
		constexpr	std::uint32_t 	TIM_CR1 	=		0x0;
		constexpr	std::uint32_t 	TIM_CR2 	=		0x04;
		constexpr	std::uint32_t 	TIM_SR 		=		0x10;
		constexpr	std::uint32_t 	TIM_CNT 	=		0x24;
		constexpr	std::uint32_t 	TIM_PSC 	=		0x28;
		constexpr	std::uint32_t 	TIM_ARR 	=		0x2C;




	}	
		
		
	

	
	namespace GPIO_REG
	{
		
		
		constexpr 	std::uint32_t GPIOA 				= MISC_REG::APB2PERIPH_BASE + 0x0800;
		constexpr 	std::uint32_t GPIOB 				= MISC_REG::APB2PERIPH_BASE + 0x0C00;
		constexpr 	std::uint32_t GPIOC 				= MISC_REG::APB2PERIPH_BASE + 0x1000;
		constexpr		std::uint32_t CRL_OFFSET 		=0x0;
		constexpr		std::uint32_t CRH_OFFSET 		=0x04;
		constexpr		std::uint32_t IDR_OFFSET 		=0x08;
		constexpr		std::uint32_t	ODR_OFFSET 		=0x0C;
		constexpr		std::uint32_t BSSR_OFFSET 	=0x10;




		// The values of bit0 through bit7.
		typedef enum Pin
		{			
		
		GPIO_PIN0 	= 		0x00,
		GPIO_PIN1 	= 		0x01,
		GPIO_PIN2 	= 		0x02,
		GPIO_PIN3 	= 		0x03,
		GPIO_PIN4 	= 		0x04,
		GPIO_PIN5 	= 		0x05,
		GPIO_PIN6 	= 		0x06,
		GPIO_PIN7 	= 		0x07,
		GPIO_PIN8 	= 		0x08,
		GPIO_PIN9 	= 		0x09,
		GPIO_PIN10 	= 		0x0A,
		GPIO_PIN11 	= 		0x0B,
		GPIO_PIN12 	= 		0x0C,
		GPIO_PIN13 	= 		0x0D,
		GPIO_PIN14 	= 		0x0E,
		GPIO_PIN15 	= 		0x0F,
		
		}Pin;
	}

