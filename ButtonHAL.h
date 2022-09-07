#ifndef BUTTONHAL_H_
#define BUTTONHAL_H_

#include <stdbool.h>

typedef struct {
	bool (*isButtonPressed)(void);
} ButtonHAL;


#endif
