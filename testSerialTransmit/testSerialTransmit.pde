import processing.serial.*;

Serial myPort;  // Create object from Serial class

void setup() 
{
  size(200,200); //make our canvas 200 x 200 pixels big
  String portName = Serial.list()[3]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  if (keyPressed && (key == '1')) {myPort.write(1);}
  if (keyPressed && (key == '2')) {myPort.write(2);}
  if (keyPressed && (key == '3')) {myPort.write(3);}
  if (keyPressed && (key == '4')) {myPort.write(4);}
  if (keyPressed && (key == '5')) {myPort.write(5);}
  if (keyPressed && (key == '6')) {myPort.write(6);}
  if (keyPressed && (key == '7')) {myPort.write(7);}
  if (keyPressed && (key == '8')) {myPort.write(8);}
  if (keyPressed && (key == '9')) {myPort.write(9);}
  if (keyPressed && (key == 'q')) {myPort.write(10);}
  if (keyPressed && (key == 'w')) {myPort.write(11);}
  if (keyPressed && (key == 'e')) {myPort.write(12);}
  if (keyPressed && (key == 'r')) {myPort.write(13);}
  if (keyPressed && (key == 't')) {myPort.write(14);}
  if (mousePressed && (mouseButton == LEFT)) {myPort.write(100);}
  if (mousePressed && (mouseButton == RIGHT)) {myPort.write(200);}
  else {myPort.write(0);}
}
