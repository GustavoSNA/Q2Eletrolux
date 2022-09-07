#include "ButtonHALExample.h"
#include <stdio.h>

static bool isButtonPressed(void);
static void updateButtonStatus(void);
static void logButtonStatus(bool isButtonPressed);

static bool buttonIsPressed = false;

static ButtonHAL buttonHALExample = {
		.isButtonPressed = isButtonPressed
};

ButtonHAL *getButtonHALExample(void) {
	return &buttonHALExample;
}

static bool isButtonPressed(void) {
	bool isButtonPressedFlag = buttonIsPressed;
	updateButtonStatus();
	logButtonStatus(isButtonPressedFlag);
	return isButtonPressedFlag;
}

static void updateButtonStatus(void) {
	buttonIsPressed = buttonIsPressed ? false : true;
}

static void logButtonStatus(bool isButtonPressed) {
	if(isButtonPressed) {
		printf("Button is pressed!\n");
		return;
	}

	printf("Button is released!\n");
}
