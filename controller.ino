/*
 * Hamudi Hasan Sonet
 * uiurobotics@gmail.com 
 * President : UIU Robotics Club
*/

const int motorA1  = 5;
const int motorA2  = 6;
const int motorB1  = 10;
const int motorB2  = 9;
const int BTState = 2;
int state;
int vSpeed=255 ;

void setup()
{

    // wheel dc motor
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);

    // for Bluetooth
    pinMode(BTState, INPUT);
    Serial.begin(9600);
}

void loop()
{
    if(digitalRead(BTState)==LOW)
    {
        state='S';
    }
    
    if(Serial.available() > 0)
    {
        state = Serial.read();
    }

    if (state == '0')
    {
        vSpeed=0;
    }
    else if (state == '1')
    {
        vSpeed=100;
    }
    else if (state == '2')
    {
        vSpeed=180;
    }
    else if (state == '3')
    {
        vSpeed=230;
    }
    else if (state == '4')
    {
        vSpeed=255;
    }

    if(state =='F')
    {
        forward();
    }

    else if(state =='B')
    {
        backward();
    }
    else if(state =='L')
    {
        left();

    }
    else if(state =='R')
    {
        right();
    }
    else if(state =='G')
    {
        forwardleft();
    }

    else if(state =='I')
    {
        forwardRight();
    }
    else if(state =='H')
    {
        backwardLeft();
    }
    else if(state =='J')
    {
        backwardRight();
    }
    else if(state =='S')
    {
        stop_bot();
    }
}

void forward()
{
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);

    analogWrite(motorB1, vSpeed);
    analogWrite(motorB2, 0);
}
void backward()
{
    analogWrite(motorA1, 0);
    analogWrite(motorA2, vSpeed);

    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
}
void left()
{
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
}
void right()
{
    analogWrite(motorA1, 0);
    analogWrite(motorA2, vSpeed);

    analogWrite(motorB1, vSpeed);
    analogWrite(motorB2, 0);
}

void stop_bot()
{
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
}
void forwardleft()
{
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, vSpeed-50);
    analogWrite(motorB2, 0);
}
void forwardRight()
{
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed-50);
}
void backwardLeft()
{
    analogWrite(motorA1, 0);
    analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, vSpeed-30);
    analogWrite(motorB2, 0);
}
void backwardRight()
{
    analogWrite(motorA1, 0);
    analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed-50);
}

