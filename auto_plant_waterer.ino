// Pins
#define R1 8 // Pump relay on PIN 8
#define Wp 4 // Water sensor on PIN 7

// Timers
#define PUMPON 8000 // Pump ON duration (ms)
#define DELAY 86400000 // Pump trigger interval (ms)

// Function to turn relay on
void relayOn(int relay){
  digitalWrite(relay, HIGH);
}

// Function to turn relay on
void relayOff(int relay){
  digitalWrite(relay, LOW);
}

// Function to check if there is enough water in the resivour
bool hasWater(){
  if(digitalRead(Wp) == HIGH){
    return true;
  }
  else return false;
}

// Function to activate the water pump
int cyclePump(){
  int pumpRan = 0; // Default return value (assume it fails and change the value upon successful event)
  int dur = PUMPON; // 
  
  while(hasWater() && dur > 0){
    relayOn(R1); // Turn pump on
    dur -= 100; // Delay of 100ms to check if pump still has water
    delay(100); // Wait 100ms to check water level again (prevent constant running of sensor to prevent corrosion)

    // Set return value to 1 if 50% pump was active for 50% of pump time (had water for at least 50% of the duration) 
    if(dur < (PUMPON * .5)){
      pumpRan = 1; // Pump successfully ran
    }
  }
  relayOff(R1); // Turn off pump
  
  return pumpRan; // Return pump success value (0 pump didnt run, 1 pump ran successfully)
}

// Setup pins as outputs/inputs
void setup(){
  pinMode(R1, OUTPUT);
  pinMode(Wp, INPUT);
  relayOff(R1);
}

// Run program
void loop(){
  if(cyclePump()){ // Check if pump ran successfully
    delay(DELAY); // Wait until next time to pump
  }
  else{
    delay(600000); // If pump didnt work, wait 10m to try again
  }
}
