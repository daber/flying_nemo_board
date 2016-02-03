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
		codeLenght(27), carrierFreq(38), state('i') {

}

NemoControler::~NemoControler() {

}

void NemoControler::sendCode(unsigned int* table) {
	for (int i = 0; i < 4; i++) {
		irsend.sendRaw(table, codeLenght, carrierFreq);
	}
}

void NemoControler::sendUp() {
	sendCode(nemo_up_pressed);
	sendCode(nemo_up_holding);
	sendCode(nemo_released);
	sendCode(nemo_idle);
}

void NemoControler::sendDown() {
	sendCode(nemo_down_pressed);
	sendCode(nemo_down_holding);
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
	default:
		break;
	}

}

void NemoControler::idle() {
	state = 'i';
}

void NemoControler::up() {
	state = 'u';
}

void NemoControler::down() {
	state = 'd';
}
