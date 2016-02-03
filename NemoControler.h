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

	enum PRESS_STATE {
		CONTROLER_RELEASED,
		CONTROLER_PRESSED
	};
	unsigned int codeLenght;
	unsigned int carrierFreq;
	//works on ~3 PWM
	IRsend irsend;
	char state;
	char pressState;
protected:
	void sendCode(unsigned int* table);
	void sendUp();
	void sendDown();
	void sendReleased();
public:
	NemoControler();
	virtual ~NemoControler();
	void sendCurrent();
	void idle();
	void up();
	void down();
};

#endif /* NEMOCONTROLER_H_ */
