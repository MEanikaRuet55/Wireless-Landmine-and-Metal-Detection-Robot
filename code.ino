char command;  // Variable to store Bluetooth command

// Motor pins
const int motor1Pin1 = 8;  
const int motor1Pin2 = 9;  
const int motor2Pin1 = 10; 
const int motor2Pin2 = 11;

void setup() {
  // Set motor pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  // Start serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();  // Read the Bluetooth command
    
    switch (command) {
      case 'F':  // Move forward
        moveForward();
        break;
      case 'B':  // Move backward
        moveBackward();
        break;
      case 'L':  // Turn left
        turnLeft();
        break;
      case 'R':  // Turn right
        turnRight();
        break;
      case 'S':  // Stop
        stopMotors();
        break;
    }
  }
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}