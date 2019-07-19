#!/bin/bash
# setup

# stop on errors
set -e

# sanity check command line options
usage() {
    echo "Usage: $0 (basic|sensor_step1|sensor_step2)"
}

if [ $# -ne 1 ]; then
    usage
    exit 1
fi

# parse args, $1 is the first argument
case $1 in
    "basic")
        sudo apt-get --assume-yes install wiringpi
        ;;

    "sensor_step1")
        read -p "Enter the pin number of your sensor's SIG wire: "  pin
        sudo echo "dtoverlay=w1-gpio,gpio-pin="$pin | sudo tee -a /boot/config.txt > /dev/null
        read -p "To continue installing you must restart your pi, enter 'y' to reboot. "  response
        if [ $response = "y" ]; 
        then
            sudo reboot;
        else
            echo "You will not be able to run the second step until you reboot."
        fi
        ;;

    "sensor_step2")
        sudo modprobe w1-gpio
        sudo modprobe w1-therm
        ;;
esac
