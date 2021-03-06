#include <wiringPi.h>
#include <string>
#include <getopt.h>
#include "temperature.cpp"

// All time measured in seconds
const int SECONDSINHOUR = 3600;
const int DELAYTIMEOFF = 600;
const int DELAYTIMEON = 90;
// On the 'warm' setting, the outside of the crockpot is ~31.5 celcius, so give or take 1 degree.
const int MAXTEMPERATURE = 32500;
const int MINTEMPERATURE = 30500;

void getCmdOpts(float& hours, int& gpioPin, bool& sensor, int argc, char** argv);
void keepWarmBasic(int gpioPin);
void keepWarmSensor(int gpioPin);

int main(int argc, char** argv) {
	// default values for time, gpio pin, and use of sensor
	float hours = 8.0;
	int gpioPin = 2;
	bool sensor = false;

	getCmdOpts(hours, gpioPin, sensor, argc, argv);
	wiringPiSetupGpio();

	pinMode(gpioPin, OUTPUT);
	digitalWrite(gpioPin, HIGH);
	// The delay is measured in milliseconds, so multiply by 1000	
	delay(1000 * hours * SECONDSINHOUR);
	digitalWrite(gpioPin, LOW);

	while(true) {
		if (sensor) {
			keepWarmSensor(gpioPin);
		}
		else {
			keepWarmBasic(gpioPin);
		}
	}
	return 0;
}


void getCmdOpts(float& hours, int& gpioPin, bool& sensor, int argc, char** argv) {
	// set up to read in command line args
	opterr = true;
	int choice;
	int optionIndex = 0;
	option options[] = {
		{ "hours", required_argument, nullptr, 'h' },
		{ "pin", required_argument, nullptr, 'p' },
		{ "sensor", no_argument, nullptr, 's' },
		{ nullptr, 0, nullptr, '\0' }
	};

	while((choice = getopt_long(argc, argv, "h:p:s", options, 
	      &optionIndex)) != -1) {
		switch(choice) {
			case 'h':
				hours = std::atof(optarg);
				break;

			case 'p':
				gpioPin = std::atoi(optarg);
				break;

			case 's':
				sensor = true;
				break;
		}
	}
}


void keepWarmBasic(int gpioPin) {
	digitalWrite(gpioPin, LOW);
	// Turn the pot off for 10 minutes
	delay(1000 * DELAYTIMEOFF);
	// Turn it back on for 90 seconds to keep it warm
	digitalWrite(gpioPin, HIGH);
	delay(1000 * DELAYTIMEON);
}

void keepWarmSensor(int gpioPin) {
	int temperature = stoi(getTemperature());
	if (temperature > MAXTEMPERATURE) {
		digitalWrite(gpioPin, LOW);
	}
	if (temperature < MINTEMPERATURE) {
		digitalWrite(gpioPin, HIGH);
	}
	// check every 10 seconds
	delay(10000);
}

