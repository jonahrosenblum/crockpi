# Crockpi Slow Cooker Timer/Controller
## Warnings and Notices
I have personally used this to help me cook, and I haven't found any issues with it. That being said, please do not injure yourself or even worse overcook your food using my timer due to incorrect installation. If you follow these instructions everything should work - if you want to do some quick testing with the relay plug a lamp or something else into a socket to see if it is being properly controlled. 
This code was written to run on a Raspberry Pi 3b+, I would be suprised if it worked on any non-Pi related hardware.
## Usage
1. Clone the repository and follow the wiring instructions.
2. You will need wiringPi.h to use this code, you can install it with `sudo apt-get install wiringpi` if you do not already have it. If you run into serious problems check the [documentation](http://wiringpi.com/download-and-install/).
3. To compile\* use `g++ -Wall -o crockpi crockpi.cpp -lwiringPi`
4. To run the timer, simply run the executable with the number of hours you want the crockpot to cook for and the GPIO pin you are using as arguments, for example `./crockpi --hours 9 --pin 3 &` or `./crockpi -h 9 p 3 &` means you are using GPIO pin 3 to control the relay, and want to let the crockpot cook for 9 hours (after which it will stay on "warm mode"). Note that by default the crockpot is set to run for 8 hours using GPIO pin 2 if no arguments are given. I recommend running the process in the background with a `&`.  
 
\* If you are getting errors like `undefined reference to 'crypt'` try using ` g++ -Wall -o crockpi crockpi.cpp -pthread -lwiringPi -lm -lrt -lcrypt`
## Wiring
### Specific Hardware
I used the [DLI power relay](https://dlidirect.com/products/iot-power-relay) and the [Sunfounder DS18B20 temperature sensor](https://www.sunfounder.com/ds18b20-temperature-sensor-module.html). Both should be on Amazon for sale if they are sold out/shipping is expensive.

### Wiring Schematic
![Reference Photo](https://github.com/jonahrosenblum/crockpi/blob/master/photos/wiring-diagram.png)
**If you only plan on using the timing feature and do not want to use the sensor, you can ignore the breadboard and sensor in the diagram.** All black wires pictured are ground wires. Yellow is SIG. Red is VCC. The white is another signal, it connects the GPIO pin to the positive terminal on the relay, the ground connects to the negative terminal on the relay.
#### NOTE
The temperature sensor shown in the diagram is different from the DS18B20 I use, the one pictured in this diagram requires a 4.7K resistor to work, and the VCC and SIG are switched. Mine does not require this resistor, which is why I do not include it in the diagram. The wires are relative to my DS18B20, please keep this in mind if you try and use the more common one.



