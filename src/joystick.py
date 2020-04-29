#! /usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy
#import serial
#arduinoData=serial.Serial("/dev/ttyACM0",9600)

velocity=0
y=0
def callback(data):
    global velocity
    global y
    twist = Twist()
    left_stick_up_down=data.axes[1]
    left_stick_left_right=data.axes[0]
    right_stick_up_down=data.axes[4]
    right_stick_left_right=data.axes[3]
    x=data.axes[7]
    Max=180
    Min=1
  
    if(x==1):
        velocity+=1
        x=velocity
        if(velocity>=180):
            velocity=Max
    elif(x==-1):
        velocity-=1
        if(velocity<=1):
            velocity=Min 
         
    twist.linear.x=left_stick_up_down
    twist.angular.x=left_stick_left_right
    twist.linear.y=right_stick_up_down
    twist.angular.y=right_stick_left_right
    '''while(left_stick_up_down > 0):
        y +=1
        if(y > 180):
            y = 180
    while(left_stick_up_down < 0):
        y-= 1
        if(y < 0):
            y = 0
    
    twist.linear.x = y'''
        


    #z=arduinoData.write(format(twist.linear.x))
    #print(z)
    rospy.loginfo('velocity=%s',velocity)
    #twist.angular.z = 4*data.axes[0]
    pub.publish(twist)

# Intializes everything
def start():
    # publishing to "turtle1/cmd_vel" to control turtle1
    global pub
    pub = rospy.Publisher('/cmd_vel', Twist)
    # subscribed to joystick inputs on topic "joy"
    rospy.Subscriber("joy", Joy, callback)
    # starts the node
    rospy.init_node('Joy2Turtle')
    rospy.spin()

if __name__ == '__main__':
    start()
