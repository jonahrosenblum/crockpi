# Crockpi Slow Cooker Timer
## Usage
1. Clone the repository and follow the wiring instructions.
2. You will need wiringPi.h to use this code, you can install it with `sudo apt-get install wiringpi` if you do not already have it. 
3. To compile use `g++ -Wall -o crockpi crockpi.cpp -lwiringPi`
5. To run the timer, simply run the executable with the number of hours you want the crockpot to cook for and the GPIO pin you are using as arguments, for example `./crockpi --hours 9 --pin 3` or `./crockpi -h 9 p 3` means you are using GPIO pin 3 to control the relay, and want to let the crockpot cook for 9 hours (after which it will stay on "warm mode"). Note that by default the crockpot is set to run for 8 hours using GPIO pin 2 if no arguments are given.

## Wiring
COMING SOON
