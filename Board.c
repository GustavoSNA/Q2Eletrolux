#include "Board.h"
#include "StateOFF.h"
#include "StateON.h"
#include "StatePROTECTED.h"

static void whatchButton(void);
static State* getStateOFF(void);
static State* getStateON(void);
static State* getStatePROTECED(void);
static void setState(State *state);
static void updateHAL(TimerHAL *t, ButtonHAL *b, LOGHAL *l);
static void initStates(void);
static void setInicialState(void);
void setDurationButtonPressed(long durationInMili);

static Board board = {
		.whatchButton = whatchButton,
};

static BoardContext context = {
		.setDurationButtonPressed = setDurationButtonPressed,
		.setState = setState,
		.getStateOFF = getStateOFF,
		.getStateON = getStateON,
		.getStatePROTECED = getStatePROTECED
};

static State *stateON;
static State *stateOFF;
static State *statePROTECTED;

static TimerHAL *timer;
static ButtonHAL *button;
static LOGHAL *log;

static long durationButtonPressedInMili;
static State *currentState;
static TimeInstant stateInsertedTimeInstant;

Board *initBoard(TimerHAL *t, ButtonHAL *b, LOGHAL *l) {
	updateHAL(t, b, l);
	initStates();
	setInicialState();
	return &board;
}

static void updateHAL(TimerHAL *t, ButtonHAL *b,  LOGHAL *l) {
	timer = t;
	button = b;
	log = l;
}

static void initStates(void) {
	stateOFF = initStateOFF(&context);
	stateON = initStateON(&context);
	statePROTECTED = initStatePROTECED(&context);
}

static void setInicialState(void) {
	setState(stateOFF);
}

static void whatchButton(void) {
	TimeInstant currentTimeInstant = timer->getTimeInstant();
	currentState->whatchButton(button->isButtonPressed(), timer->getTimeIntervalInMilisecondsBetween(stateInsertedTimeInstant, currentTimeInstant));
}

static void setState(State *state) {
	stateInsertedTimeInstant = timer->getTimeInstant();
	currentState = state;
	log->logNewState(currentState);
}

static State* getStateOFF(void) {
	return stateOFF;
}

static State* getStateON(void) {
	return stateON;
}

static State* getStatePROTECED(void) {
	return statePROTECTED;
}

void setDurationButtonPressed(long durationInMili) {
	durationButtonPressedInMili = durationInMili;
	log->logDurationButtonIsPressed(durationButtonPressedInMili);
}
