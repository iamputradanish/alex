#include <Arduino.h>
// Direction values
typedef enum dir
{
  STOP,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT,
  LEFT_FORWARD,
  RIGHT_FORWARD,
  LEFT_BACKWARD,
  RIGHT_BACKWARD,
} dir;

// Motor control pins
#define A1   11
#define A2   10
#define B2   6
#define B1   5

// Ensure that percent is between 0 and 100
double checkPercent(double percent)
{
  if (percent < 0.0)
    return 0.0;
  else if (percent > 100.0)
    return 100.0;
  else
    return percent;
}

// Get PWM value based on percentage
int getPWMValue(double percent)
{
  return (int)(percent / 100.0 * 255.0);
}

// Move Alex motors
// A is right motor, B is left motor
// 1 is forward, 2 is backward
void move(double percentA, double percentB, int direction)
{
  int valA = getPWMValue(checkPercent(percentA));
  int valB = getPWMValue(checkPercent(percentB));

  // Forward and reverse values for motors 1 and 2
  int A1Val, A2Val, B1Val, B2Val;

  switch (direction)
  {
    case FORWARD:
      A1Val = valA;
      A2Val = 0;

      B2Val = 0;
      B1Val = valB;

      break;

    case BACKWARD:
      A1Val = 0;
      A2Val = valA;

      B2Val = valB;
      B1Val = 0;

      break;

    case LEFT:
      A1Val = valA;
      A2Val = 0;

      B2Val = 0;
      B1Val = valB;

      break;

    case RIGHT:
      A1Val = valA;
      A2Val = 0;

      B2Val = 0;
      B1Val = valB;

      break;

    case LEFT_FORWARD:
      A1Val = valA;
      A2Val = 0;

      B2Val = 0;
      B1Val = valB;

      break;

    case RIGHT_FORWARD:
      A1Val = valA;
      A2Val = 0;

      B2Val = 0;
      B1Val = valB;

      break;

    case LEFT_BACKWARD:
      A1Val = 0;
      A2Val = valA;

      B2Val = valB;
      B1Val = 0;

      break;

    case RIGHT_BACKWARD:
      A1Val = 0;
      A2Val = valA;

      B2Val = valB;
      B1Val = 0;

      break;

    case STOP:
    default:
      A1Val = 0;
      A2Val = 0;

      B2Val = 0;
      B1Val = 0;

      break;

  }

  analogWrite(A1, A1Val);
  analogWrite(A2, A2Val);
  analogWrite(B1, B1Val);
  analogWrite(B2, B2Val);
}

void forward()
{
  move(50.0, 50.0, FORWARD);
}

void backward()
{
  move(50.0, 50.0, BACKWARD);
}

void left() {
  move(75.0, 0, LEFT);
}

void right() {
  move(25.0, 75.0, RIGHT);
}

void leftForward()
{
  move(75.0, 25.0, LEFT_FORWARD);
}

void rightForward()
{
  move(25.0, 75.0, RIGHT_FORWARD);
}

void leftBackward()
{
  move(75.0, 25.0, LEFT_BACKWARD);
}

void rightBackward()
{
  move(25.0, 75.0, RIGHT_BACKWARD);
}

void stop()
{
  move(0.0, 0.0, STOP);
}
