#!/bin/sh

curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
cd ~/bin
./arduino-cli config init
cp ~/.arduino15/arduino-cli.yaml ~/.arduino15/arduino-cli-backup.yaml
echo "board_manager:
  additional_urls:
    [https://arduino.esp8266.com/stable/package_esp8266com_index.json]
daemon:
  port: "50051"
directories:
  data: /home/reimund/.arduino15
  downloads: /home/reimund/.arduino15/staging
  user: /home/reimund/Arduino
library:
  enable_unsafe_install: false
logging:
  file: ""
  format: text
  level: info
metrics:
  addr: :9090
  enabled: true
sketch:
  always_export_binaries: false" > ~/.arduino15/arduino-cli.yaml
