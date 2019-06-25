#include <wiringPi.h>
#include <string>

// All time measured in seconds
int SECONDSINHOUR = 3600;
int DELAYTIMEOFF = 600;
int DELAYTIMEON = 120;
int GPIO_PIN = 2;

void keepWarm() {
	digitalWrite(GPIO_PIN, LOW);
	delay(1000 * DELAYTIMEOFF);
	digitalWrite(GPIO_PIN, HIGH);
	delay(1000 * DELAYTIMEON);
}

int main(int argc, char** argv) {
	wiringPiSetupGpio();
	pinMode(GPIO_PIN, OUTPUT);
	digitalWrite(GPIO_PIN, HIGH);
	// The delay is measured in milliseconds, so multiply by 1000	
	delay(1000 * std::stof(argv[argc - 1]) * SECONDSINHOUR);
	digitalWrite(GPIO_PIN, LOW);

	while(true) {
		keepWarm();
	}
	return 0;
}
