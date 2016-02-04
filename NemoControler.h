/*
 * NemoControler.h
 *
 *  Created on: Jan 30, 2016
 *      Author: daber
 */
#ifndef NEMOCONTROLER_H_
#define NEMOCONTROLER_H_

#include <IRremote.h>

class NemoControler {

	unsigned int codeLenght;
	unsigned int carrierFreq;
	//works on ~3 PWM
	IRsend irsend;
	char state;
	char targetState;
protected:
	void sendCode(unsigned int* table);
	char onStateTransition();
public:
	NemoControler();
	virtual ~NemoControler();
	void sendCurrent();
	void idle();
	void up();
	void down();
	void right();
	void left();

};

#endif /* NEMOCONTROLER_H_ */
