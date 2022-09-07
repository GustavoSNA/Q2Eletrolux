#include "StatePROTECTED.h"


#define TIME_PROTECTED_IN_MILI (10000)

static void whatchButton(bool isButtonPressed, long durationOfStateInMili);
static char* getStateName(void);

static BoardContext *context;
static State statePROECTED = {
		.whatchButton = whatchButton,
		.getStateName = getStateName
};

State *initStatePROTECED(BoardContext *c) {
	context = c;
	return &statePROECTED;
}

static void whatchButton(bool isButtonPressed, long durationOfStateInMili) {
	if(durationOfStateInMili >= TIME_PROTECTED_IN_MILI) {
		context->setState(context->getStateOFF());
	}
}

static char* getStateName(void) {
	return "PROTECED";
}
