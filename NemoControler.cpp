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
		codeLenght(27), carrierFreq(38) {

}

NemoControler::~NemoControler() {

}

void NemoControler::sendCode(unsigned int* table) {
	for (int i = 0; i < 4; i++) {
		irsend.sendRaw(table, codeLenght, carrierFreq);
	}
}

void NemoControler::up() {
	sendCode(nemo_up_pressed);
	sendCode(nemo_up_holding);
	sendCode(nemo_released);
	sendCode(nemo_idle);
}

void NemoControler::down() {
	sendCode(nemo_down_pressed);
	sendCode(nemo_down_holding);
	sendCode(nemo_released);
	sendCode(nemo_idle);
}
