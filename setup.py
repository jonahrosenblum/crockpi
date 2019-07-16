import os
import sys

if len(sys.argv) != 2:
    print('Usage: sudo python/python3 setup.py basic/sensor')

if sys.argv[1] == 'basic':
    os.system('sudo apt-get --assume-yes install wiringpi')

elif sys.argv[1] == 'sensor_step1':
    with open('/boot/config.txt', 'a') as config:
        config.write('dtoverlay=w1-gpio,gpio-pin=' +
                     input('Enter the pin number of your sensor\'s SIG wire'))
        os.system('sudo reboot')

elif sys.argv[1] == 'sensor_step2':
    os.system('sudo modprobe w1-gpio')
    os.system('sudo modprobe w1-therm')
