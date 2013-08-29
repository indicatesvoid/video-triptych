#pragma once

#include "Arduino.h"

class Sensor {
public:
	Sensor(int pin, int screenId) {
		this->pin = pin;
		this->screenId = screenId;
	}

	int pin;
	int screenId;
};