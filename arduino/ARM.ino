
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <geometry_msgs/Twist.h>
ros::NodeHandle  nh;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int servo_state1 = 0;
int servo_state2 = 0;
int servo_state3 = 0;
int servo_state4 = 0;
int servo_state5 = 0;
int x=0;
int y=0;
int z=0;
int f=0;
int h=0;
void servo_cb( const geometry_msgs::Twist& cmd_msg){
  servo_state1=cmd_msg.linear.x;
  servo_state2=cmd_msg.linear.y;
  servo_state3=cmd_msg.angular.x;
  servo_state4=cmd_msg.angular.y;
}


ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", servo_cb);

//  servo.write(cmd_msg.data); //set servo angle, should be from 0-180  
  //digitalWrite(13, HIGH-digitalRead(13));  //toggle led  

void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
  
  servo1.attach(7);
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(4);
  servo5.attach(3);
}

void loop(){

  //servo.write(servo_state);
  if (servo_state1 > 0){
    y+=1; 
  }
  else if(servo_state1 < 0){
    y-=1;
  }
  servo1.write(y);
  
  if (servo_state2 > 0){
    x+=1; 
  }
  else if(servo_state2 < 0){
    x-=1;
  }
  servo2.write(x);
  if (servo_state3 > 0){
    z+=1; 
  }
  else if(servo_state3 < 0){
    z-=1;
  }
  servo3.write(z);
  if (servo_state4 > 0){
    f+=1; 
  }
  else if(servo_state4 < 0){
    f-=1;
  }
  servo4.write(f);
  if (servo_state5 > 0){
    h+=1; 
  }
  else if(servo_state5 < 0){
    h-=1;
  }
  servo5.write(h);
  
  nh.spinOnce();
  delay(7);
}
