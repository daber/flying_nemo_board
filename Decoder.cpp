/*
 * decoder.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: daber
 */
#include <Arduino.h>
#include <IRremote.h>
#include "Decoder.h"
#include "nemo_codes.h"

Decoder::Decoder(int aSelectedPin) :
		selectedPin(aSelectedPin), irReciever(aSelectedPin) {

}

Decoder::~Decoder() {

}
void Decoder::init() {
	Serial.println(F("IR capturer-decoder started"));
	irReciever.enableIRIn();
}



bool Decoder::printKnown(const decode_results& results) {
	switch (results.value) {
	case NEMO_LEFT_PRESSED: //left pressed
		Serial.println(F("left_pressed"));
		printAsCTable("left_pressed", results);
		return true;
		break;
	case NEMO_LEFT_HOLDING: //left holding
		Serial.println(F("left_holding"));
		printAsCTable("left_holding", results);
		return true;
		break;
	case NEMO_RIGHT_PRESSED: //right pressed
		Serial.println(F("right_pressed"));
		printAsCTable("right_pressed", results);
		return true;
		break;
	case NEMO_RIGHT_HOLDING: //right holding
		Serial.println(F("right_holding"));
		printAsCTable("right_holding", results);
		return true;
		break;
	case NEMO_RELEASED: // released
		Serial.println(F("released"));
		printAsCTable("released", results);
		return true;
		break;
	case NEMO_IDLE: // idle
		Serial.println(F("idle"));
		printAsCTable("idle", results);
		return true;
		break;
	case NEMO_UP_PRESSED: //up pressed
		Serial.println(F("up_pressed"));
		printAsCTable("up_pressed", results);
		return true;
		break;
	case NEMO_UP_HOLDING: // up holding
		Serial.println(F("up_holding"));
		printAsCTable("up_holding", results);
		return true;
		break;
	case NEMO_DOWN_PRESSED: //down pressed pressed
		Serial.println(F("down_pressed"));
		printAsCTable("down_pressed", results);
		return true;
		break;
	case NEMO_DOWN_HOLDING: //down holding pressed
		Serial.println(F("down_holding"));
		printAsCTable("down_holding", results);
		return true;
		break;
	case NEMO_FORWARD_PRESSED: //forward pressed
		Serial.println(F("forward_pressed"));
		printAsCTable("forward_pressed", results);
		return true;
		break;
	case NEMO_FORWARD_HOLDING: //forward holding
		Serial.println(F("forward_holding"));
		printAsCTable("forward_holding", results);
		return true;
		break;

	}
	return false;
}

void Decoder::printRecievedCode(const decode_results& results) {

	Serial.println("Inside print code");
	if(!printKnown(results)){
		printEncoding(results);
		printValue(results);
	}
}

void Decoder::printValue(const decode_results& results) {
	Serial.print(" Value :0x");
	Serial.println(results.value,DEC);
}

void Decoder::interceptAndDecode() {
	if (irReciever.decode(&decodeResults)) {
		printRecievedCode(decodeResults);
		Serial.println(F("--------"));
		irReciever.resume();
	}
}

void Decoder::printAsCTable(String name, const decode_results& result) {

	Serial.println("Size :");
	Serial.println(result.rawlen, DEC);

	Serial.print(F("unsigned int nemo_"));
	Serial.print(name);
	Serial.print(F("["));
	Serial.print(result.rawlen-1);
	Serial.print(F("] = {"));
	Serial.print(result.rawbuf[1]*USECPERTICK);
	for (int i = 2; i < result.rawlen; i++) {
		Serial.print(F(", "));
		Serial.print(result.rawbuf[i]*USECPERTICK);
	}
	Serial.println(F("};"));

}

void Decoder::printEncoding(const decode_results& results) {
	Serial.print("Encoding:");
	  switch (results.decode_type) {
	    default:
	    case UNKNOWN:      Serial.print("UNKNOWN");       break ;
	    case NEC:          Serial.print("NEC");           break ;
	    case SONY:         Serial.print("SONY");          break ;
	    case RC5:          Serial.print("RC5");           break ;
	    case RC6:          Serial.print("RC6");           break ;
	    case DISH:         Serial.print("DISH");          break ;
	    case SHARP:        Serial.print("SHARP");         break ;
	    case JVC:          Serial.print("JVC");           break ;
	    case SANYO:        Serial.print("SANYO");         break ;
	    case MITSUBISHI:   Serial.print("MITSUBISHI");    break ;
	    case SAMSUNG:      Serial.print("SAMSUNG");       break ;
	    case LG:           Serial.print("LG");            break ;
	    case WHYNTER:      Serial.print("WHYNTER");       break ;
	    case AIWA_RC_T501: Serial.print("AIWA_RC_T501");  break ;
	    case PANASONIC:    Serial.print("PANASONIC");     break ;
	    case DENON:        Serial.print("Denon");         break ;
	  }
}
