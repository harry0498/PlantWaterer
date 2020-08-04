# PlantWaterer
Automatic plant watering system for Arduino Uno R3

## Wiring
![Alt text](https://github.com/harry0498/PlantWaterer/blob/master/IMG_20200804_120340__01__01-1.jpg?raw=true "Circuit Diagram")

Connect relay signal pin to PIN 7 on the arduino

## Features
- Pump activates daily (24h delay)
- The pump is active for 8s
- If the water level drops below the sensor while the pump is active, it will shut off and check how long the pump was active for. If it was active for less than 50% of   the programmed time it will wait 10m and try to pump again
- The Pump will not activate if the water level is below the sensor
