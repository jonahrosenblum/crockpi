#include <wiringPi.h>
#include <string>
#include <getopt.h>

// All time measured in seconds
const int SECONDSINHOUR = 3600;
const int DELAYTIMEOFF = 600;
const int DELAYTIMEON = 90;

void getCmdOpts(float& hours, int& gpioPin, int argc, char** argv);
void keepWarm(int gpioPin);

int main(int argc, char** argv) {
	float hours = 8.0;
	int gpioPin = 2;
	getCmdOpts(hours, gpioPin, argc, argv);
	wiringPiSetupGpio();
	pinMode(gpioPin, OUTPUT);
	digitalWrite(gpioPin, HIGH);
	// The delay is measured in milliseconds, so multiply by 1000	
	delay(1000 * hours * SECONDSINHOUR);
	digitalWrite(gpioPin, LOW);

	while(true) {
		keepWarm(gpioPin);
	}
	return 0;
}


void getCmdOpts(float& hours, int& gpioPin, int argc, char** argv) {
	opterr = true;
	int choice;
	int optionIndex = 0;
	option options[] = {
		{ "hours", required_argument, nullptr, 'h' },
		{ "pin", required_argument, nullptr, 'p' },
		{ nullptr, 0, nullptr, '\0' }
	};
	while((choice = getopt_long(argc, argv, "h:p:", options, 
	      &optionIndex)) != -1) {
		switch(choice) {
			case 'h':
				hours = std::atof(optarg);
				break;
			case 'p':
				gpioPin = std::atoi(optarg);
				break;
		}
	}
}


void keepWarm(int gpioPin) {
	digitalWrite(gpioPin, LOW);
	// Turn the pot off for 10 minutes
	delay(1000 * DELAYTIMEOFF);
	// Turn it back on for 90 seconds to keep it warm
	digitalWrite(gpioPin, HIGH);
	delay(1000 * DELAYTIMEON);
}

