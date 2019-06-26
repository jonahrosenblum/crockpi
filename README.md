# Crockpi Slow Cooker Timer
## Usage
1. Clone the repository and follow the wiring instructions.
2. You will need wiringPi.h to use this code, you can install it with `sudo apt-get install wiringpi` if you do not already have it. 
3. To compile use `g++ -Wall -o crockpi crockpi.cpp -lwiringPi`
5. To run the timer, simply run the executable with the number of hours you want the crockpot to cook for and the GPIO pin you are using as arguments, for example `./crockpi -h 8 p 4` means you are using GPIO pin 4 to control the relay, and want to let the crockpot cook for 8 hours (after which it will stay on "warm mode").

## Wiring
COMING SOON
