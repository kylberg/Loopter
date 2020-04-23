

/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board, AccelStepper and Arduino UNO: acceleration and deceleration. More info: https://www.makerguides.com */
// Include new stepper library:
#include <TinyStepper_28BYJ_48.h>

// Motor pin assignment:

const int MOTOR_IN1_PIN = 8;
const int MOTOR_IN2_PIN = 9;
const int MOTOR_IN3_PIN = 10;
const int MOTOR_IN4_PIN = 11;

const int LEFT_LIMIT_PIN = 2;
const int RIGHT_LIMIT_PIN = 3;

//
// create the stepper motor object
//
TinyStepper_28BYJ_48 stepper;



void setup() 
{
  //
  // setup the LED pin, stop button pin and enable print statements
  //
  // pinMode(LED_PIN, OUTPUT);   
  pinMode(LEFT_LIMIT_PIN, INPUT_PULLUP);
  pinMode(RIGHT_LIMIT_PIN, INPUT_PULLUP);
  Serial.begin(9600);


  //
  // connect and configure the stepper motor to its IO pins
  //
 stepper.connectToPins(MOTOR_IN1_PIN, MOTOR_IN2_PIN, MOTOR_IN3_PIN, MOTOR_IN4_PIN);
}



void loop() 
{
  //
  // set the speed and acceleration rates for the stepper motor
  //
  stepper.setSpeedInStepsPerSecond(550);
  stepper.setAccelerationInStepsPerSecondPerSecond(550);


  //
  // set the motor's current positon to 0 and turn off the LED
  //
  stepper.setCurrentPositionInSteps(0);

  bool stopFlag = false;


  //
  // setup the motor so that it will rotate 10 turns, note: this 
  // command does not start moving yet
  //
  stepper.setupMoveInSteps(2048 * 10);
  

  //
  // now execute the move, looping until the motor has finished
  //
    Serial.println("START ");
  while(!stepper.motionComplete())
  {
    //
    // Note: The code added to this loop must execute VERY fast.  
    // Perhaps no longer than 0.05 milliseconds.
    //
    
    //
    // process motor steps
    //
    stepper.processMovement();
    
    //
    // check if motor has moved past position 2048, if so turn On the LED
    //

    if(stepper.getCurrentPositionInSteps()%2048==0){
      Serial.print("Step ");
      Serial.println(stepper.getCurrentPositionInSteps());
    }   

    //
    // check if the user has pressed the "Stop" button, if so decelerate to a stop
    //
    if ((digitalRead(LFFT_LIMIT_PIN) == LOW) && (stopFlag == false))
    {
      Serial.println("-- STOP, left limit reached --");
      stepper.setupStop();
      stopFlag = true;
    }
    if ((digitalRead(RIGHT_LIMIT_PIN) == LOW) && (stopFlag == false))
    {
      Serial.println("-- STOP, right limit reached --");
      stepper.setupStop();
      stopFlag = true;
    }
  }


  //
  // delay before starting again
  //
  delay(4000);
}