/*
 * BLEControlerWrapper.h
 *
 *  Created on: Jan 31, 2016
 *      Author: daber
 */
#ifndef BLECONTROLERWRAPPER_H_
#define BLECONTROLERWRAPPER_H_


class BLEControlerWrapper {
public:

	typedef  void (*OnPressCallback)(char data);

private:
	int broadcastInterval;
	OnPressCallback callback;

public:
	BLEControlerWrapper(OnPressCallback listener, uint16_t bcastInterval_ms);
	virtual ~BLEControlerWrapper();
	void setup();
	void poolEvent();

};

#endif /* BLECONTROLERWRAPPER_H_ */
