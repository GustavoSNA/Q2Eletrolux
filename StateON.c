#include "StateON.h"
#include <stdbool.h>

static void whatchButton(bool isButtonPressed, long durationOfStateInMili);
static char* getStateName(void);
static bool isButtonReleased(bool isButtonPressedFlag);

static BoardContext *context;
static State stateON = {
		.whatchButton = whatchButton,
		.getStateName = getStateName
};

State *initStateON(BoardContext *c) {
	context = c;
	return &stateON;
}

static void whatchButton(bool isButtonPressed, long durationOfStateInMili) {
	if(isButtonReleased(isButtonPressed)) {
		context->setDurationButtonPressed(durationOfStateInMili);
		context->setState(context->getStatePROTECED());
	}
}

static bool isButtonReleased(bool isButtonPressedFlag) {
	return !isButtonPressedFlag;
}

static char* getStateName(void) {
	return "ON";
}
