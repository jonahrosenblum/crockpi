#include <glob.h>
#include <iostream>
#include <string>
#include <fstream>

std::string getDeviceName() {
	// goes through the devices directory and finds the name of the sensor
	std::string filename;
	std::string deviceName;
	glob_t globResult;
	glob("/sys/bus/w1/devices/*", GLOB_TILDE, NULL, &globResult);
	for (unsigned int i = 0; i < globResult.gl_pathc; ++i) {
		filename = globResult.gl_pathv[i];
		if (filename.substr(20,2) == "28") {
			deviceName = filename;
		}
	}
	globfree(&globResult);
	return deviceName;
}

std::string getTemperature() {
	// find the unique sensor directory, read the contents
	std::string filePath = getDeviceName() + "/w1_slave";
	std::ifstream ifs(filePath);
	std::string content( (std::istreambuf_iterator<char>(ifs)), 
			     (std::istreambuf_iterator<char>()) );
	return content.substr(69, 5);
}
