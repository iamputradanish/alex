// Motor control pins
#define A1   5
#define A2   6
#define B2   9
#define B1   10

//Parse the bluetooth signal to which function
void moveByInstruction (char signal) {
  switch(signal) {
    case 12: // FORWARD
      forward();
      break;
    case 32: // BACKWARD
      backward();
      break; 
    case 13: // RIGHT FORWARD
      rightForward();
      break;
    case 11: // LEFT FORWARD
      leftForward();
      break;
    case 33: // RIGHT BACKWARD
      rightBackward();
      break;
    case 31: // LEFT BACKWARD
      leftBackward();
      break;
    case 21: // LEFT
      left();
      break;
    case 23: //RIGHT
      right();
      break;
    default:
      stop();
      break;
  }
}
