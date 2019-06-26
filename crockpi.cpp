#include <wiringPi.h>
#include <string>
#include <getopt.h>

// All time measured in seconds
const int SECONDSINHOUR = 3600;
const int DELAYTIMEOFF = 600;
const int DELAYTIMEON = 120;
int GPIO_PIN = 2;

void getCmdOpts(float& hours, int argc, char** argv);
void keepWarm();

int main(int argc, char** argv) {
	float hours = 8.0;
	getCmdOpts(hours, argc, argv);
	wiringPiSetupGpio();
	pinMode(GPIO_PIN, OUTPUT);
	digitalWrite(GPIO_PIN, HIGH);
	// The delay is measured in milliseconds, so multiply by 1000	
	delay(1000 * hours * SECONDSINHOUR);
	digitalWrite(GPIO_PIN, LOW);

	while(false) {
		keepWarm();
	}
	return 0;
}


void getCmdOpts(float& hours, int argc, char** argv) {
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
				GPIO_PIN = std::atoi(optarg);
				break;
		}
	}
}


void keepWarm() {
	digitalWrite(GPIO_PIN, LOW);
	delay(1000 * DELAYTIMEOFF);
	digitalWrite(GPIO_PIN, HIGH);
	delay(1000 * DELAYTIMEON);
}

