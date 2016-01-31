/*
 * NemoControler.h
 *
 *  Created on: Jan 30, 2016
 *      Author: daber
 */
#include <IRremote.h>

#ifndef NEMOCONTROLER_H_
#define NEMOCONTROLER_H_

class NemoControler {
	unsigned int codeLenght;
	unsigned int carrierFreq;
	//works on ~3 PWM
	IRsend irsend;
protected:
	void sendCode(unsigned int* table);
public:
	NemoControler();
	virtual ~NemoControler();
	void up();
	void down();
};

#endif /* NEMOCONTROLER_H_ */
