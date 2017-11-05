#include <TheThingsNetwork.h>

#define loraSerial Serial1
#define debugSerial Serial

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868
    
TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

switchState = 0;
prevState = switchState;
    
void setup() {
  loraSerial.begin(57600);
  debugSerial.begin(9600);
    
  // Wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000);
    
  debugSerial.println("-- STATUS");
  ttn.showStatus();

  // setting PB pin
  pinMode(13, INPUT);
}


void loop() {
  debugSerial.println("-- LOOP");

  // Check the state of the PB
  switchState = digitalRead(13);

  if(switchState == LOW){
    // button not pressed
    if(prevState == HIGH){
      //button released
      prevState = switchState;
    }
  } else {
    // button pressed
    if(prevState == LOW){
      // button just pressed
      // DO SOMETHING: send lora frame
      
      prevState = switchState;
    }
  }
      
  delay(10000);

}
