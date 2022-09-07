#ifndef BOARD_H_
#define BOARD_H_

#include "State.h"
#include "TimerHAL.h"
#include "ButtonHAL.h"
#include "LOGHAL.h"

typedef struct {
	void(*whatchButton)(void);
} Board;

Board *initBoard(TimerHAL *timer, ButtonHAL *button, LOGHAL *logHAL);

#endif
