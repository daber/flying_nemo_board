#include <IRremote.h>
#include <avr/sleep.h>

#include "BLEController.h"
#include "Decoder.h"
#include "NemoControler.h"

Decoder decoder(4);
decode_results result;
NemoControler controler;

void callback(char code){


	switch(code){
	case 'u':
		Serial.println("Controller up");
		controler.up();
		break;
	case 'd':
		Serial.println("Controller down");
		controler.down();
		break;
	case 'l':
		Serial.println("Controller up");
		controler.left();
			break;
	case 'r':
		Serial.println("Controller down");
		controler.right();
		break;
	case 'i':
		Serial.println("Controller idle");
		controler.idle();
		break;
	default:
		Serial.println("Unknown command Controller idle");
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
	decoder.init();
	//bleWrapper.setup();

	Serial.println("startup compleded!");

}


void loop() {
	decoder.interceptAndDecode();
	//bleWrapper.poolEvent();
	//controler.sendCurrent();
}

