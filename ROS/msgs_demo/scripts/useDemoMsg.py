#!/usr/bin/env python3
import rospy
from msgs_demo.msg import demo_msgs # need to notice

rospy.init_node("use_demoMsg_py", anonymous=True)
pub_ = rospy.Publisher("chat_py", demo_msgs, queue_size=10)
rate = rospy.Rate(10) #10hz
i = 1.0
while not rospy.is_shutdown():
    my_msg = demo_msgs()
    my_msg.front_left_speed = i
    my_msg.front_right_speed = i+2
    pub_.publish(my_msg)
    i = i+1
    rate.sleep()
