#include "StateOFF.h"


static void whatchButton(bool isButtonPressed, long durationOfStateInMili);
static char* getStateName(void);

static State stateOFF = {
		.whatchButton = whatchButton,
		.getStateName = getStateName
};
static BoardContext *context;

State *initStateOFF(BoardContext *c) {
	context = c;
	return &stateOFF;
}

static void whatchButton(bool isButtonPressed, long durationOfStateInMili) {
	if(isButtonPressed) {
		context->setState(context->getStateON());
	}
}

static char* getStateName(void) {
	return "OFF";
}
