#ifndef LOGHAL_H_
#define LOGHAL_H_

#include "State.h"

typedef struct {
	void (*logDurationButtonIsPressed)(long durationInMili);
	void (*logNewState)(State *state);
}LOGHAL;


#endif
