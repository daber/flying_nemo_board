#include <IRremote.h>
#include <avr/sleep.h>
#include "Decoder.h"
#include "Edystone.h"
#include "NemoControler.h"

Decoder decoder(4);

decode_results result;
EdystoneBeacon beacon(-55);
NemoControler controler;

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
	beacon.broadcastURL("http://neofonie.de");
	beacon.setBroadcastInterval(1000);
	beacon.init();
	Serial.println("startup compleded!");

}

void backAndForth() {
	static int counter = 0;
	counter++;
	if (counter < 10) {
		controler.up();
	} else if (counter < 20) {
		controler.down();
	} else {
		counter = 0;
	}
}

void loop() {
	decoder.interceptAndDecode();
	beacon.loop();

	//backAndForth();
}

