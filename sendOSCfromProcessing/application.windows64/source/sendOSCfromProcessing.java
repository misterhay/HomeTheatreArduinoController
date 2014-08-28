import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import oscP5.*; 
import netP5.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sendOSCfromProcessing extends PApplet {

 //requires the oscP5 library from http://www.sojamo.de/libraries/oscP5/

PFont font; // so that we can display printing

OscP5 oscP5;
NetAddress serverAddress;
String theServerAddress = "192.168.1.64";
int theServerPort = 9000;
int theReceivingPort = theServerPort + 1;
int size = 150; //the size of the buttons (power and volume will be double this)
int spacing = 5; //the spacing between the buttons
int powerX1 = spacing,  powerX2 =  powerX1+size*2,  powerY1 = spacing,  powerY2 =  powerY1+size*2;
int volumeUpX1 = spacing*5+size*5,  volumeUpX2 =  volumeUpX1+size,  volumeUpY1 = spacing,  volumeUpY2 =  volumeUpY1+size*2;
int volumeDownX1 = spacing*5+size*5,  volumeDownX2 =  volumeDownX1+size*2,  volumeDownY1 = spacing*2+size*2,  volumeDownY2 =  volumeDownY1+size*2;
int stationX1 = spacing*4+size*4,  stationX2 =  stationX1+size,  stationY1 = spacing*2+size/2,  stationY2 =  stationY1+size;
int appleX1 = spacing*2+size*2,  appleX2 =  appleX1+size,  appleY1 = spacing,  appleY2 =  appleY1+size;
int radioX1 = spacing*3+size*3,  radioX2 =  radioX1+size,  radioY1 = spacing,  radioY2 =  radioY1+size;
int xboxX1 = spacing*2+size*2,  xboxX2 =  xboxX1+size,  xboxY1 = spacing*2+size,  xboxY2 =  xboxY1+size;
int computerX1 = spacing*3+size*3,  computerX2 =  computerX1+size,  computerY1 = spacing*2+size,  computerY2 =  computerY1+size;
int nightX1 = spacing,  nightX2 =  nightX1+size,  nightY1 = spacing*2+size*3,  nightY2 =  nightY1+size;

public void setup() {
  frameRate(1);
  size(spacing*6+size*7,spacing*3+size*4);
  font = createFont("Arial",12,true); // Arial, 12 point, anti-aliasing on
  oscP5 = new OscP5(this,theReceivingPort);
  serverAddress = new NetAddress(theServerAddress,theServerPort);
}

public void draw() {
  background(0xff000000);
  fill(0xffF2261B);
  rect(powerX1, powerY1, size*2, size*2); //power button
  fill(0xff00FF00);
  rect(appleX1, appleY1, size, size); //input buttons
  rect(radioX1, radioY1, size, size);
  rect(xboxX1, xboxY1, size, size);
  rect(computerX1, computerY1, size, size);
  fill(0xffFFFF46);
  rect(volumeUpX1, volumeUpY1, size*2, size*2); //volume buttons
  rect(volumeDownX1, volumeDownY1, size*2, size*2);
  fill(0xffB2B2B2);
  rect(stationX1, stationY1, size, size); //station button
  rect(nightX1, nightY1, size, size); //night mode button
  fill(0xff000000);
  textFont(font,size/4);
  textAlign(CENTER);
  text("Power", spacing+size, spacing+size);
  textFont(font,size/5);
  text("Apple TV", spacing*2+size*2.5f, spacing+size*.5f);
  text("Radio", spacing*3+size*3.5f, spacing+size*.5f);
  text("Xbox", spacing*2+size*2.5f, spacing*2+size*1.5f);
  text("Computer", spacing*3+size*3.5f, spacing*2+size*1.5f);
  text("station", spacing*4+size*4.5f, spacing*2+size);
  text("Volume Up", spacing*5+size*6, spacing+size);
  text("Volume Down", spacing*5+size*6, spacing*2+size*3);
  text("Night", spacing+size*.5f, spacing*2+size*3.5f);
}

public void mouseClicked() {
  if(mouseX > powerX1 && mouseX < powerX2 && mouseY > powerY1 && mouseY <powerY2) {sendOsc(1);}
  if(mouseX > volumeUpX1 && mouseX < volumeUpX2 && mouseY > volumeUpY1 && mouseY <volumeUpY2) {sendOsc(2);}
  if(mouseX > volumeDownX1 && mouseX < volumeDownX2 && mouseY > volumeDownY1 && mouseY <volumeDownY2) {sendOsc(3);}
  if(mouseX > stationX1 && mouseX < stationX2 && mouseY > stationY1 && mouseY <stationY2) {sendOsc(4);}
  if(mouseX > appleX1 && mouseX < appleX2 && mouseY > appleY1 && mouseY <appleY2) {sendOsc(5);}
  if(mouseX > radioX1 && mouseX < radioX2 && mouseY > radioY1 && mouseY <radioY2) {sendOsc(6);}
  if(mouseX > xboxX1 && mouseX < xboxX2 && mouseY > xboxY1 && mouseY <xboxY2) {sendOsc(7);}
  if(mouseX > computerX1 && mouseX < computerX2 && mouseY > computerY1 && mouseY <computerY2) {sendOsc(8);}
  if(mouseX > nightX1 && mouseX < nightX2 && mouseY > nightY1 && mouseY <nightY2) {sendOsc(9);}//*/
}

/*void buttonDetect(int X1, int X2, int Y1, int Y2) {
  
  concat(
}//*/

public void sendOsc(int parameter) {
  OscMessage myMessage = new OscMessage("/yamaha"); 
  myMessage.add(parameter);
  oscP5.send(myMessage, serverAddress);
  
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sendOSCfromProcessing" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
