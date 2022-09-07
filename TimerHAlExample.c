#include "TimerHAlExample.h"

static TimeInstant getTimeInstant(void);
static long getTimeIntervalInMilisecondsBetween(TimeInstant stamp1, TimeInstant stamp2);
static void testDelay(void);

static TimerHAL timerHALExample = {
		.getTimeInstant = getTimeInstant,
		.getTimeIntervalInMilisecondsBetween = getTimeIntervalInMilisecondsBetween
};

static TimeInstant currentTimeInstant = 0;

TimerHAL *getTimerHAlExample(void) {
	return &timerHALExample;
}

static TimeInstant getTimeInstant(void) {
	testDelay();
	TimeInstant timeInstant = currentTimeInstant;
	currentTimeInstant += 1000;
	return timeInstant;
}

static void testDelay(void) {
	for(int i = 0; i < 50e7; i++);
}

static long getTimeIntervalInMilisecondsBetween(TimeInstant stamp1, TimeInstant stamp2) {
	return stamp2 - stamp1;
}
