/*
 * NemoControler.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: daber
 */
#include "NemoControler.h"
#include "nemo_codes.h"
#include <IRremote.h>

#define DEBUG_PRINT(s) Serial.println(s)
NemoControler::NemoControler() :
		codeLenght(27), carrierFreq(38), state('i'), targetState('i') {

}

NemoControler::~NemoControler() {

}

void NemoControler::sendCode(unsigned int* table) {
	for (int i = 0; i < 1; i++) {
		irsend.sendRaw(table, codeLenght, carrierFreq);
		delay(50);
	}
}

char NemoControler::onStateTransition() {

	if (state == 'i' && targetState == 'i') {
		//nothing
		return 'i';
	}
	if (state == 'i' && targetState == 'u') {
		DEBUG_PRINT("up_pressed");
		sendCode(nemo_up_pressed);
		return 'u';
	}
	if (state == 'u' && targetState == 'u') {
		DEBUG_PRINT("up_holding");
		sendCode(nemo_up_holding);
		return 'u';
	}
	if (state == 'i' && targetState == 'd') {
		DEBUG_PRINT("down_pressed");
		sendCode(nemo_down_pressed);
		return 'd';
	}
	if (state == 'd' && targetState == 'd') {
		DEBUG_PRINT("down_holding");
		sendCode(nemo_down_holding);
		return 'd';
	}

	if (state == 'i' && targetState == 'l') {
		DEBUG_PRINT("left_pressed");
		sendCode(nemo_left_pressed);
		return 'l';
	}

	if (state == 'l' && targetState == 'l') {
		DEBUG_PRINT("left_holding");
		sendCode(nemo_left_holding);
		return 'l';
	}

	if (state == 'i' && targetState == 'r') {
		DEBUG_PRINT("right_pressed");
		sendCode(nemo_right_pressed);
		return 'r';
	}
	if (state == 'r' && targetState == 'r') {
		DEBUG_PRINT("right_holding");
		sendCode(nemo_right_holding);
		return 'r';
	}

	// eg. u -> d has to be u->i then i->d
	if(state !='i' && targetState != 'i' && targetState!=state){
		DEBUG_PRINT("indirect pass _ passing through idle");
		sendCode(nemo_released);
		sendCode(nemo_idle);
		return 'i';
	}
	if(state !='i' && targetState =='i'){
		DEBUG_PRINT("idling");
		sendCode(nemo_released);
		sendCode(nemo_idle);
		return 'i';
	}

	DEBUG_PRINT("ERROR_CASE NOT MET");
	DEBUG_PRINT(state);
	DEBUG_PRINT("TARGET");
	DEBUG_PRINT(state);
	//just in case
	return 'i';
}

void NemoControler::sendCurrent() {
	state = onStateTransition();
}

void NemoControler::idle() {
	targetState = 'i';
}

void NemoControler::up() {
	targetState = 'u';
}

void NemoControler::down() {
	targetState = 'd';
}

void NemoControler::left() {
	targetState = 'l';
}

void NemoControler::right() {
	targetState = 'r';
}
