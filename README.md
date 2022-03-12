# LED Ball

## Hardware

ESP8266MOD D1 Mini

## Setup SSH in WSL

exec ssh-agent bash && eval ssh-agent -s && ssh-add ~/.ssh/<your-key-name>

## How to clone this project

### https://github.com/Reimund-Koenig/led_ball

### Download and install Arduino IDE: <https://www.arduino.cc/en/Main/Software>

### Board Package

<https://arduino.esp8266.com/stable/package_esp8266com_index.json>

### OTA Describtion

https://lastminuteengineers.com/esp8266-ota-updates-arduino-ide/
https://arduino-esp8266.readthedocs.io/en/latest/ota_updates/readme.html#arduino-ide
https://github.com/versamodule/ESP32-OTA-Commandline

### Reed-Sensor describtion

https://randomnerdtutorials.com/monitor-your-door-using-magnetic-reed-switch-and-arduino/

## CLI (not recommended because FOTA not supported with CLI)

### Grant access to Serial_Port

* sudo chmod a+rw /dev/ttyUSB0

    mkdir ~/workspace
    cd ~/workspace
    git clone https://github.com/Reimund-Koenig/led_ball.git

### Install Arduino related stuff

* run ./install_arduino_1.8.6 // last compatible version for vscode-arduino
* \<CNTL + SHIFT + P> and type "settings json"
* copy "dimmer/.vscode/settings.json" to global settings.json
* \<CTRL + P> and type "ext install vscode-arduino"
* restart
* \<CNTL + SHIFT + P> and type Arduino Board Manager
* Search for esp8266 and install it
* \<CNTL + SHIFT + P> and type Arduino Library Manager
* Search for PubSubClient by  Nick O'Leary <nick.oleary@gmail.com> and install it
* Search for losant-mqtt-arduino by Brandon Cannaday <brandon@losant.com>  and install it
* Copy dimmer/.vscode/arduino.json" to .vscode/arduino

#### More Arduino installation (maybe not needed)

sudo apt-get install gcc-avr avr-libc avrdude &&
sudo apt install arduino-mk &&
sudo apt install screen &&
sudo apt install cmake &&
sudo apt install libgcc-8-dev &&
sudo apt-get install build-essential &&
sudo apt-get install g++

