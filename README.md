# IOT Digital Clock
[![PIC1](https://raw.githubusercontent.com/sam-tj/IOT-Digital-Clock/master/sample-image-1.jpg)](https://www.youtube.com/watch?v=DyQfBuWmfJw )

[![IMAGE ALT TEXT HERE](https://raw.githubusercontent.com/sam-tj/IOT-Digital-Clock/master/sample-image-2.jpg)](http://www.youtube.com/watch?v=DfONEzf3ouE)

IOT Clock which display Date and Time using NodeMCU and LCD I2C

The project uses NTP server to get the Time and Date values and uses it to display it on the LCD.

------------

### Libraries Required

You need to download the following:

- NTPClient by taranais: https://github.com/taranais/NTPClient ( Use this only, not from Library Manager)
- LCD I2C: https://github.com/johnrickman/LiquidCrystal_I2C ( Can install it from Library Manager also)

------------

### List of components used:
- NodeMCU 1.0
- LCD I2C

------------

### About
This project is a DIY Clock which gets data from NTP ( Network Time Protocol ) servers and updates directly. It can be used instead of RTC ( Real Time Clock ) modules for IOT projects and smart devices.

------------
### Tutorial
1. Get the code
2. Get the libraries
3. Attach everything
4. Upload the code
	🔥🔥🔥🔥🔥

------------

### Connections
|  NodeMCU  |  LCD I2C  |
|  ------------ |  ------------ |
|  D5  |  SDA  |
|  D6  |  SCL  |
|  3.3V  |  VCC  |
|  GND  |  GND  |

![Connections](https://raw.githubusercontent.com/sam-tj/IOT-Digital-Clock/master/connections.jpg "Connections")
