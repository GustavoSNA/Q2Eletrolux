#include "LOGHALExample.h"
#include <stdio.h>

static void logDurationButtonIsPressed(long durationInMili);
static void logNewState(State *state);

static LOGHAL logHALExample = {
		.logDurationButtonIsPressed = logDurationButtonIsPressed,
		.logNewState = logNewState
};

LOGHAL *getLOGHALExample(void) {
	return &logHALExample;
}

static void logDurationButtonIsPressed(long durationInMili) {
	int durationInSeconds = (int) (durationInMili / 1000);
	printf("Duration button was pressed: %d(s)\n", durationInSeconds);
}

static void logNewState(State *state) {
	printf("State of the board was changed: %s\n", state->getStateName());
}
