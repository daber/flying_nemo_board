/*
 * nemo_codes.h
 *
 *  Created on: Jan 29, 2016
 *      Author: daber
 */
#include <IRremote.h>

#ifndef NEMO_CODES_H_
#define NEMO_CODES_H_




//hashes of the commands
#define NEMO_LEFT_PRESSED 0xC9253BF3
#define NEMO_LEFT_HOLDING 0x6507E499
#define NEMO_RIGHT_PRESSED 0x6178CD61
#define NEMO_RIGHT_HOLDING 0x9DB3F429
#define NEMO_UP_PRESSED 0xB46821C1
#define NEMO_UP_HOLDING 0xA49E53B7
#define NEMO_DOWN_PRESSED 0x5851F5E9
#define NEMO_DOWN_HOLDING 0x89121ABD
#define NEMO_FORWARD_PRESSED 0x4D1A8A6F
#define NEMO_FORWARD_HOLDING 0xAE6DCEF7
#define NEMO_RELEASED 0xB79D1F7
#define NEMO_IDLE 0x47B4F8BF


extern unsigned int nemo_right_pressed[27];
extern unsigned int nemo_right_holding[27];

extern unsigned int nemo_left_pressed[27];
extern unsigned int nemo_left_holding[27];

extern unsigned int nemo_up_pressed[27];
extern unsigned int nemo_up_holding[27];

extern unsigned int nemo_down_pressed[27];
extern unsigned int nemo_down_holding[27];

extern unsigned int nemo_forward_pressed[27];
extern unsigned int nemo_forward_holding[27];

extern unsigned int nemo_released[27];
extern unsigned int nemo_idle[27];




void printRecievedCode(decode_results result);

void printAsCTable(String name,decode_results result);

#endif /* NEMO_CODES_H_ */
