# Crockpi Slow Cooker Timer
## Usage
1. Clone the repository and follow the wiring instructions.
2. You will need wiringPi.h to use this code, you can install it with `sudo apt-get install wiringpi` if you do not already have it. 
3. Set the GPIO_PIN variable to the GPIO pin you have hooked up to the relay, I am using the second pin so I used 2.
4. To compile use `g++ -Wall -o crockpi crockpi.cpp -lwiringPi`
5. To run the timer, simply run the executable with the number of hours you want as an argument, for example `./crockpi 8` will turn the crockpot off after 8 hours and leave it on "warm mode."

## Wiring
COMING SOON
