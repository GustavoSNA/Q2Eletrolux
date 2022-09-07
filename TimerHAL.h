#ifndef TIMERHAL_H_
#define TIMERHAL_H_

typedef long TimeInstant;

typedef struct {
	TimeInstant (*getTimeInstant)(void);
	long (*getTimeIntervalInMilisecondsBetween)(TimeInstant stamp1, TimeInstant stamp2);
} TimerHAL;

#endif
