#include <IRremote.h>
#include <avr/sleep.h>
#include "Decoder.h"
#include "NemoControler.h"
#include "BLEControlerWrapper.h"

Decoder decoder(4);
decode_results result;
NemoControler controler;

void callback(char code){


	switch(code){
	case 'u':
		Serial.println("Controler up");
		controler.up();
		break;
	case 'd':
		Serial.println("Controler down");
		controler.down();
		break;
	default:
		Serial.println("Controler idle");
		controler.idle();
	}

}

BLEControlerWrapper bleWrapper(callback,500);


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

	Serial.println("startup compleded!");

}


void loop() {
	bleWrapper.poolEvent();
	controler.sendCurrent();
}

