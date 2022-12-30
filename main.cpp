#include <Arduino.h>
#include <AFMotor.h>
#include <SoftwareSerial.h>

#define BLUETOOTH_COMMAND_SPEED 38200
#define BLUETOOTH_DATA_SPEED 9600
const int tx = 2;
const int rx = 3;
SoftwareSerial bluetooth(rx, tx);

#define M_FORWARD           'F'
#define M_BACKWARD          'B'
#define M_STOP              'S'
#define M_TURN_RIGHT        'R'
#define M_TURN_LEFT         'L'
#define M_SIDE_RIGHT        'X'
#define M_SIDE_LEFT         'x'
#define M_DIAGONAL_RIGHT    'D'
#define M_DIAGONAL_LEFT     'd'
#define M_CONCERNING_RIGHT  'C'
#define M_CONCERNING_LEFT   'c'
#define M_REAR_AXIS_RIGHT   'A'
#define M_REAR_AXIS_LEFT    'a'

AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
AF_DCMotor m4(4);

const uint8_t m_speed = 150;

void setSpeed(uint8_t speed = m_speed) {
  m1.setSpeed(speed);
  m2.setSpeed(speed);
  m3.setSpeed(speed);
  m4.setSpeed(speed);
}

void forward() {
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void backward() {
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void turnRight() {
  m1.run(FORWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(FORWARD);
}

void turnLeft() {
  m1.run(BACKWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(BACKWARD);
}


void sideRight() {
  m1.run(BACKWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(FORWARD);
}

void sideLeft() {
  m1.run(FORWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
  m4.run(BACKWARD);
}

void diagonalRight() {
  m1.run(RELEASE);
  m2.run(FORWARD);
  m3.run(RELEASE);
  m4.run(FORWARD);
}

void diagonalLeft() {
  m1.run(FORWARD);
  m2.run(RELEASE);
  m3.run(FORWARD);
  m4.run(RELEASE);
}

void concerningRight() {
  m1.run(RELEASE);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(RELEASE);
}

void concerningLeft() {
  m1.run(FORWARD);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(FORWARD);
}

void turnRearAxisRight() {
  m1.run(FORWARD);
  m2.run(BACKWARD);
  m3.run(RELEASE);
  m4.run(RELEASE);
}

void turnRearAxisLeft() {
  m1.run(BACKWARD);
  m2.run(FORWARD);
  m3.run(RELEASE);
  m4.run(RELEASE);
}


void stop() {
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
}

void setup() {
  bluetooth.begin(BLUETOOTH_DATA_SPEED);
  pinMode(rx, INPUT);
  Serial.begin(9600);
  Serial.println("Serial set up");

  setSpeed();
  stop();
}

void loop() {
  char command = ' ';
  if(bluetooth.available() > 0) {
    char c = bluetooth.read();
    if(c >= 'A' && c <= 'z') {
      command = c;
    }
  }

  if(command == M_FORWARD) {
    forward();
  }
  else if(command == M_BACKWARD) {
    backward();
  }
  else if(command == M_STOP) {
    stop();
  }
  else if(command == M_TURN_RIGHT) {
    turnRight();
  }
  else if(command == M_TURN_LEFT) {
    turnLeft();
  }
  else if(command == M_SIDE_RIGHT) {
    sideRight();
  }     
  else if(command == M_SIDE_LEFT) {
    sideLeft();
  } 
  else if(command == M_DIAGONAL_RIGHT) {
    diagonalRight();
  } 
  else if(command == M_DIAGONAL_LEFT) {
    diagonalLeft();
  }
  else if(command == M_CONCERNING_RIGHT) {
    concerningRight();
  }
  else if(command == M_CONCERNING_LEFT) {
    concerningLeft();
  }
  else if(command == M_REAR_AXIS_RIGHT) {
    turnRearAxisRight();
  }
  else if(command == M_REAR_AXIS_LEFT) {
    turnRearAxisLeft();
  } 

  delay(10);
}