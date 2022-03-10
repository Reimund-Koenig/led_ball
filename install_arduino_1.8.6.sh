#!/bin/sh

mkdir arduino
cd arduino
wget https://downloads.arduino.cc/arduino-1.8.6-linux64.tar.xz
tar xvJf arduino-1.8.6-linux64.tar.xz
cd arduino-1.8.6/
sudo ./install.sh
