#include <IRremote.h>
#include <avr/sleep.h>

#include "BLEController.h"
#include "Decoder.h"
#include "NemoControler.h"
#include "debug.h"


Decoder decoder(4);
decode_results result;
NemoControler controler;



void callback(char code){


	switch(code){
	case 'u':
		DEBUG_PRINT("Controller up");
		controler.up();
		break;
	case 'd':
		DEBUG_PRINT("Controller down");
		controler.down();
		break;
	case 'l':
		DEBUG_PRINT("Controller up");
		controler.left();
			break;
	case 'r':
		DEBUG_PRINT("Controller down");
		controler.right();
		break;
	case 'i':
		DEBUG_PRINT("Controller idle");
		controler.idle();
		break;
	default:
		DEBUG_PRINT("Unknown command Controller idle");
		controler.idle();
	}

}

BLEController bleWrapper(callback,500);


void disableACDC() {
	ADCSRA = ADCSRA & B01111111;
	ACSR = B10000000;
}

void sleep_until_interrupted() {
	set_sleep_mode (SLEEP_MODE_IDLE);
	sleep_mode();
}

void setup() {
	Serial.begin(9600);
	bleWrapper.setup();
	DEBUG_PRINT("startup completed!");
}


void loop() {
	bleWrapper.poolEvent();
	controler.sendCurrent();
}

