/*
 * NemoControler.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: daber
 */
#include "NemoControler.h"
#include "nemo_codes.h"
#include <IRremote.h>

NemoControler::NemoControler() :
		codeLenght(27), carrierFreq(38), state('i'), pressState(
				CONTROLER_RELEASED) {

}

NemoControler::~NemoControler() {

}

void NemoControler::sendCode(unsigned int* table) {
	for (int i = 0; i < 1; i++) {
		irsend.sendRaw(table, codeLenght, carrierFreq);
		delay(50);
	}
}

void NemoControler::sendUp() {
	switch (pressState) {
	case CONTROLER_RELEASED:
		sendCode(nemo_up_pressed);
		pressState = CONTROLER_PRESSED;
		break;
	case CONTROLER_PRESSED:
		sendCode(nemo_up_holding);
		break;
	}

}

void NemoControler::sendDown() {
	switch (pressState) {
	case CONTROLER_RELEASED:
		sendCode(nemo_down_pressed);
		pressState = CONTROLER_PRESSED;
		break;
	case CONTROLER_PRESSED:
		sendCode(nemo_down_holding);
		break;
	}

}

void NemoControler::sendReleased() {
	pressState = CONTROLER_RELEASED;
	sendCode(nemo_released);
	sendCode(nemo_idle);
}

void NemoControler::sendCurrent() {
	switch (state) {

	case 'u':
		sendUp();
		break;
	case 'd':
		sendDown();
		break;
	case 'i':
		sendReleased();
		break;
	default:
		break;
	}

}

void NemoControler::idle() {
	state = 'i';
}

void NemoControler::up() {
	if (pressState == CONTROLER_PRESSED) {
		sendReleased();
	}
	state = 'u';
}

void NemoControler::down() {
	if (pressState == CONTROLER_PRESSED) {
		sendReleased();
	}
	state = 'd';
}
