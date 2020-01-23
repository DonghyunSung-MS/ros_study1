#!/usr/bin/env python

from ros_study1.srv import *
import rospy

def handle_cal(req):
    print("Caculating Average of 3 subjects: %s %s %s")%(req.sub1, req.sub2, req.sub3)
    res = AverageResponse()
    res.avg = (req.sub1+req.sub2+req.sub3)/3;
    return res

def my_server():
    rospy.init_node('my_server')
    s = rospy.Service('/average_calc',Average,handle_cal)
    print("Ready to calculate the average")
    rospy.spin()

if __name__ == '__main__':
    my_server()
