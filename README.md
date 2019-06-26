# Crockpi Slow Cooker Timer
## Warnings and Notices
I have personally used this to help me cook, and I haven't found any issues with it yet. Please do not injure yourself or even worse overcook you food using my timer due to incorrect installation. If you follow these instructions everything should work - if you want to do some quick testing plug a lamp or something else into your relay to see if it is being properly controlled. 
This code was written to run on a Raspberry Pi 3b+, I would be suprised if it worked on any non-Pi related hardware.
## Usage
1. Clone the repository and follow the wiring instructions.
2. You will need wiringPi.h to use this code, you can install it with `sudo apt-get install wiringpi` if you do not already have it. If you run into serious problems check the [documentation](http://wiringpi.com/download-and-install/).
3. To compile* use `g++ -Wall -o crockpi crockpi.cpp -lwiringPi`
5. To run the timer, simply run the executable with the number of hours you want the crockpot to cook for and the GPIO pin you are using as arguments, for example `./crockpi --hours 9 --pin 3` or `./crockpi -h 9 p 3` means you are using GPIO pin 3 to control the relay, and want to let the crockpot cook for 9 hours (after which it will stay on "warm mode"). Note that by default the crockpot is set to run for 8 hours using GPIO pin 2 if no arguments are given.  
 
\* If you are getting errors like `undefined reference to 'crypt'` try using ` g++ -Wall -o crockpi crockpi.cpp -pthread -lwiringPi -lm -lrt -lcrypt`
## Wiring
COMING SOON
