#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

def callback(data):
    rospy.loginfo("Hello ROS %d",data.data)

def listener():
    rospy.init_node("sub_py_node",anonymous=True)
    rospy.Subscriber("/myrostopic",Int32,callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
