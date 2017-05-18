 char val; // Data received from the serial port
// int ledPin = 13; // Set the pin to digital I/O 13
 int pinI1=8;//define I1 interface
int pinI2=11;//define I2 interface 
int speedpinA=9;//enable motor A
int pinI3=12;//define I3 interface 
int pinI4=13;//define I4 interface 
int speedpinB=10;//enable motor B
int spead =127;//define the spead of motor

 
 
 void setup() 
 {
  //pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  pinMode(pinI1,OUTPUT);
  pinMode(pinI2,OUTPUT);
  pinMode(speedpinA,OUTPUT);
  pinMode(pinI3,OUTPUT);
  pinMode(pinI4,OUTPUT);
  pinMode(speedpinB,OUTPUT);
  Serial.begin(9600); // Start serial communication at 9600 bps
 }
 
void forward()
{
analogWrite(speedpinA,spead);//input a simulation value to set the speed
//analogWrite(speedpinB,spead);
//digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
//digitalWrite(pinI3,LOW);
digitalWrite(pinI2,LOW);//turn DC Motor A move anticlockwise
digitalWrite(pinI1,HIGH);
}
void backward()//
{
analogWrite(speedpinA,spead);//input a simulation value to set the speed
//analogWrite(speedpinB,spead);
//digitalWrite(pinI4,LOW);//turn DC Motor B move anticlockwise
//digitalWrite(pinI3,HIGH);
digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
digitalWrite(pinI1,LOW);
}
void left()//
{
//analogWrite(speedpinA,spead);//input a simulation value to set the speed
analogWrite(speedpinB,spead);
digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
digitalWrite(pinI3,LOW);
//digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
//digitalWrite(pinI1,LOW);
}
void right()//
{
//analogWrite(speedpinA,spead);//input a simulation value to set the speed
analogWrite(speedpinB,spead);
digitalWrite(pinI4,LOW);//turn DC Motor B move anticlockwise
digitalWrite(pinI3,HIGH);
//digitalWrite(pinI2,LOW);//turn DC Motor A move clockwise
//digitalWrite(pinI1,HIGH);
}
void stop()//
{
digitalWrite(speedpinA,LOW);// Unenble the pin, to stop the motor. this should be done to avid damaging the motor.
digitalWrite(speedpinB,LOW);
delay(1000);

}

 void loop() 
 {
   if (Serial.available()) 
   { // If data is available to read,
     val = Serial.read(); // read it and store it in val
     
      if (val =='1') //if 1 was received
      {     
        Serial.println("Right Turn");
            right();
           delay(800);
            //stop();
    //        forward();
           // delay(300);
           //  stop();
       }
       val= Serial.read();
      if (val =='2') //if 2 was received
       {    
            Serial.println("left Turn");
            left();
           delay(800);
          //  stop();
       //   forward();
         //  delay(300);
          // stop();
        }
       val=Serial.read();
       if (val =='3')//if 3 was received
        {
          Serial.println("Reverse");
            backward();
            delay(200);
            stop();
         }
           val=Serial.read();
       if (val =='4')//if 4 was received
         {
           Serial.println("Forward");
            forward();
            delay(200);
          stop();
          }
        val=Serial.read();
delay(100); // Wait 10 milliseconds for next reading
            forward();
            delay(200);
          stop();
   }
 }


