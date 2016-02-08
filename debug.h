/*
 * debug.h
 *
 *  Created on: Feb 8, 2016
 *      Author: mdabrowski
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#ifdef __NEMO_DEBUG__
#define DEBUG_PRINT(s) Serial.println(s)
#else
#define DEBUG_PRINT(s)
#endif




#endif /* DEBUG_H_ */
