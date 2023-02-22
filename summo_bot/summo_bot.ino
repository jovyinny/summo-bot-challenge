/*

  Keep me inside the black circle
  It uses ping library for easy control of ultrasonic sensor

*/
#include "NewPing.h" // library for ultrasonic sensor(easy ping)

#define IR_1 8          //First Ir pin
#define IR_2 9          //second ir pin
#define TRIGGER_PIN 6   //trigger pin of ultrasonic sensor
#define ECHO_PIN 7      //echo pin of ultrasonic sensor
#define MOTOR_1 3      // use pmw arduino board pins for left side motor
#define MOTOR_2 5      // use pmw arduino board pins for right side motor

// Maximum distance we want to ping for (in centimeters).
//maximum distance to ping is 400cm, minimum is 2cm

#define MAX_DISTANCE 30 // this is the max distance, the sensor should detect


//Creating NewPing object(ultrassonic) by setting  pins and maximum distance.
NewPing ultrasonic(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float distance;

bool is_left = true;
void setup() {
  // put your setup code here, to run once:
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(MOTOR_1, OUTPUT);
  pinMode(MOTOR_1, OUTPUT);

//  move_around();

}

void loop() {
  // put your main code here, to run repeatedly:

  bool ir_1_in_circle = read_IR_1();
  bool ir_2_in_circle = read_IR_2();

  while (ir_1_in_circle || ir_2_in_circle) {

    distance = ultrasonic.ping_cm();

    if (distance >= 2 || distance <= MAX_DISTANCE) {
      attack();
    } else {
      move_forward();
    }
  }

  //trying to bring him back to the circle
//  if (is_left) {
//    move_left();
//    is_left = false;
//  } else {
//    move_right();
//  }

}



//black color doesn't reflect IR
bool read_IR_1() {
  if (digitalRead(IR_1)) {
    return false;
  } else {
    return true;
  }
}


bool read_IR_2() {
  if (digitalRead(IR_2)) {
    return false;
  } else {
    return true;
  }
}


//attack func
void attack() {
  //speed values can be changed to meet the requirement
  analogWrite(MOTOR_1, 220);
  analogWrite(MOTOR_2, 220);

}

void move_forward() {
  //speed values can be changed to meet the requirement
  analogWrite(MOTOR_1, 180);
  analogWrite(MOTOR_2, 180);

}

void move_around() {
  //speed values can be changed to meet the requirement
  analogWrite(MOTOR_1, 150);
  analogWrite(MOTOR_2, 150);

}

void move_left() {
  //speed values can be changed to meet the requirement
  analogWrite(MOTOR_1, 200);
  analogWrite(MOTOR_2, 100);

}

void move_right() {
  //speed values can be changed to meet the requirement
  analogWrite(MOTOR_1, 100);
  analogWrite(MOTOR_2, 200);

}


//For more info check me at jovinerobotics@gmail.com
