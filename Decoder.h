/*
 * decoder.h
 *
 *  Created on: Jan 30, 2016
 *      Author: daber
 */
#ifndef DECODER_H_
#define DECODER_H_

#include <Arduino.h>
#include <IRremote.h>

class Decoder {

	int const selectedPin;
	IRrecv   irReciever;
	decode_results decodeResults;



protected:
	void rawRecord2rawInput(volatile unsigned int* buf, int length);
	void printAsCTable(String name, const decode_results& result);
	void printRecievedCode(const decode_results& results);
	void printEncoding(const decode_results& results);
	bool printKnown(const decode_results& results);
	void printValue(const decode_results& results);
public:
	Decoder(int aSelectedPin);
	void init();
	virtual ~Decoder();
	void interceptAndDecode();
};

#endif /* DECODER_H_ */
