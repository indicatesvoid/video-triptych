
void setup()
{
	Serial.begin(9600);
}

void loop()
{
	if (Serial.available() > 0) {
		int sensor, degrees;
		if (Serial.read() == 1){
			sensor = analogRead(0);
			degrees = map(sensor, 768, 853, 0, 90);
			if (degrees < 0) degrees = 0;
			Serial.write(degrees);
		}
	}
}
