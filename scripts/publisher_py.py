#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

def talker():
    pub = rospy.Publisher('/myrostopic',Int32,queue_size = 10)
    rospy.init_node('pub_py_node',anonymous=True)
    rate = rospy.Rate(1)
    i = 1
    while not rospy.is_shutdown():
        pub.publish(i)
        i = i + 2
        rate.sleep()

if __name__ =='__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
