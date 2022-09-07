#include "ButtonHALFactory.h"
#include "ButtonHALExample.h"

ButtonHAL *getButtonHAL(void) {
	return getButtonHALExample();
}
