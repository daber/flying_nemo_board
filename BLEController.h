/*
 * BLEControlerWrapper.h
 *
 *  Created on: Jan 31, 2016
 *      Author: daber
 */
#ifndef BLECONTROLLER_H_
#define BLECONTROLLER_H_

#include <Arduino.h>

class BLEController {
public:

	typedef  void (*OnPressCallback)(char data);

private:
	int broadcastInterval;
	OnPressCallback callback;

public:
	BLEController(OnPressCallback listener, uint16_t bcastInterval_ms);
	virtual ~BLEController();
	void setup();
	void poolEvent();

};

#endif /* BLECONTROLLER_H_ */
