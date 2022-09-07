#ifndef STATE_H_
#define STATE_H_

#include <stdbool.h>

typedef struct _State State;


typedef struct {
	void(*setDurationButtonPressed)(long durationInMili);
	void(*setState)(State *state);
	State*(*getStateOFF)(void);
	State*(*getStateON)(void);
	State*(*getStatePROTECED)(void);
} BoardContext;

typedef void(*StateListener)(State state);
typedef void(*ButtonPressedTimeSetter)(long buttonPressedTime);

struct _State {
	void(*whatchButton)(bool isButtonPressed, long durationOfStateInMili);
	char*(*getStateName)(void);
};


#endif
