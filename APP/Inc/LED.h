#include "reg.h"


/*
template<typename	Port_type,
				 typename Pin_type,
				 const	Port_type Port,
				 const	Pin_type Pin  >*/

class LED
	{
		
	public:
		
		LED(const std::uint32_t port,const GPIO_REG::Pin pin);

		void SET();

		
		void RESET();

		
		void Toggle();

		
		void Read()	;

			
	private :
		
	const std::uint32_t Port;
	const std::uint8_t  Pin;
		
	};



