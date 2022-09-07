#include "TimerHALFactory.h"
#include "TimerHAlExample.h"

TimerHAL *getTimerHAL(void) {
	return getTimerHAlExample();
}
