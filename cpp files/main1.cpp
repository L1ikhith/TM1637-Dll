#include "TM4C123.h"   
#include "TM1637.h"

int main()
{
	Display TM167;
	TM167.setBrightness(2);
  TM167.TM1637Init();
	while(1){
	for(int i=0;i<=100;i++){
		TM167.clear();
		TM167.showNumberDec(i, false);	// Prints __31
		TM167._delay_ms(500);
	 }
	}
 }

