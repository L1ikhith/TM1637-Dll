#include "TM4C123GH6PM.h"
#include <inttypes.h>

#ifndef _TM1637_
# define _TM1637_



#define SEG_A   0b00000001
#define SEG_B   0b00000010
#define SEG_C   0b00000100
#define SEG_D   0b00001000
#define SEG_E   0b00010000
#define SEG_F   0b00100000
#define SEG_G   0b01000000
#define SEG_DP  0b10000000

static const uint8_t minusSegments = 0b01000000;
static uint32_t ms;
extern "C" void SysTick_Handler(void);

#define DEFAULT_DELAY  1
static GPIOA_Type* GpioA =reinterpret_cast<GPIOA_Type*>(GPIOA_BASE);
static SYSCTL_Type*Sysctl =reinterpret_cast<SYSCTL_Type*>(SYSCTL_BASE);

class Display1 {

public:

  void TM1637Init(uint16_t bitDelay = DEFAULT_DELAY);

  void setBrightness(uint8_t brightness, bool on = true);

  void SendData( uint8_t segments[], uint8_t length = 4, uint8_t pos = 0);

  //! Clear the display
  void clear();

  void showNumberDec(int num, bool leading_zero = false, uint8_t length = 4, uint8_t pos = 0);

  void showNumberDecEx(int num, uint8_t dots = 0, bool leading_zero = false, uint8_t length = 4, uint8_t pos = 0);

  void showNumberHexEx(uint16_t num, uint8_t dots = 0, bool leading_zero = false, uint8_t length = 4, uint8_t pos = 0);

  static uint8_t encodeDigit(uint8_t digit);
	
  void _delay_ms(uint16_t delay);
  
protected:
  
   void start();

   void stop();

   bool WriteReg(uint8_t b);
   
   void showDots(uint8_t dots, uint8_t* digits);
   
   void showNumberBaseEx(int8_t base, uint16_t num, uint8_t dots = 0, bool leading_zero = false, uint8_t length = 4, uint8_t pos = 0);

   

private:
	uint8_t m_brightness;

};


#endif