#include "FiniteStateMachine.h"

static FiniteStateMachine *machine;

int main() {
	machine = getFiniteStateMachine();
	machine->setup();

	while(1) {
		machine->loop();
	}

	return 0;
}
