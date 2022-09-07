#ifndef FINITESTATEMACHINE_H_
#define FINITESTATEMACHINE_H_

typedef struct {
	void(*setup)(void);
	void(*loop)(void);
} FiniteStateMachine;

FiniteStateMachine *getFiniteStateMachine(void);

#endif
