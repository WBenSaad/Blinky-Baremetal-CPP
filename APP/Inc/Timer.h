#include "reg.h"


class Timer
{ 
public:
  
  Timer ();

	void Delay(std::uint16_t seconds);



private :

	std::uint32_t GetCounter(void);
	void StartCounter(void);
	void SetPeriod(void);
	void SetPrescaler(std::uint16_t milliseconds);
	void EnablePeripheral(void);
  void DisablePeripheral(void);
	
  std::uint16_t Period ;

};
	
	
	
	
	
