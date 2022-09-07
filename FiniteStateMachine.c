#include "FiniteStateMachine.h"
#include "ButtonHAL.h"
#include "ButtonHALFactory.h"
#include "TimerHAL.h"
#include "TimerHALFactory.h"
#include "LOGHAL.h"
#include "LOGHALFactory.h"
#include "Board.h"

static void setup(void);
static void loop(void);

static FiniteStateMachine instance = {
		.setup = setup,
		.loop = loop
};

static Board *board;

FiniteStateMachine *getFiniteStateMachine(void) {
	return &instance;
}

static void setup(void) {
	ButtonHAL *button = getButtonHAL();
	TimerHAL *timer = getTimerHAL();
	LOGHAL *log = getLOGHAL();
	board = initBoard(timer, button, log);
}

static void loop(void) {
	board->whatchButton();
}
