import processing.serial.*;
import SimpleOpenNI.*;
SimpleOpenNI kinect;

Serial myPort;  // Create object from Serial class

int closesetItem;
int closestX;
int closestY;
PImage depthImage;
float closestValue = 500;
float farthestValue = 1500;
String val;

void serialEvent(Serial myPort)
{
  val = myPort.readStringUntil('\n');
  myPort.bufferUntil('\n');
  println(val);
}

void setup() 
{
  //size(200,200); //make our canvas 200 x 200 pixels big
  String portName = Serial.list()[2]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  
  size(640, 480);
  kinect = new SimpleOpenNI(this);
  kinect.enableDepth();
  
}

void draw() 
{
closesetItem=8000;

kinect.update();
int[] depthValues = kinect.depthMap();
//depthImage = kinect.depthImage();
for (int y = 0; y < 480; y++) 
{
  for (int x = 0; x < 640; x++) 
  {
    int i = x + y * 640;
    int currentDepthValue = depthValues[i];
      if (currentDepthValue < closestValue || currentDepthValue > farthestValue) 
        { 
          kinect.depthImage().pixels[i] = 0;
        }
    if(currentDepthValue > 0 && currentDepthValue < closesetItem)
        {
        closesetItem = currentDepthValue;
        closestX =x;
        closestY =y;
        }
   }
}
     
      image(kinect.depthImage(), 0, 0);
      fill(255,0,0);
      ellipse(closestX,closestY,25,25);
      
      if (closestX > 50 && closestX < 320)
      {
      delay(250);
      myPort.write('2');
      println("2");
      }
      
      if (closestX >0 && closestX < 50 || closestX >590 && closestX < 640)
      {
        delay(250);
        myPort.write('4');
        println("4");
        
      }
      
      
      
      if (closestX > 320 && closestX < 590)
      {
      delay(250);
      myPort.write('1');
      println("1");
      }

      
     

//  if (mousePressed == true) 
//  {                           //if we clicked in the window
//   myPort.write('1');         //send a 1
//   println("1");   
//  } else 
//  {                           //otherwise
//  myPort.write('0');          //send a 0
//  }   
}

