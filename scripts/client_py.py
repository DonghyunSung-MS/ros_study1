#!/usr/bin/env python

import sys
import rospy
from ros_study1.srv import *

def my_client(sub1,sub2,sub3):
    rospy.wait_for_service('/average_calc')
    try:
        calc = rospy.ServiceProxy("/average_calc",Average)
        resp1 = calc(sub1, sub2, sub3)
        return resp1.avg

    except rospy.ServiceException, e:
        print  "Service call failed: %s"%e

def usage():
    return "%s [sub1 sub2 sub3]"%sys.argv[0]

if __name__ == "__main__":
    if len(sys.argv) == 4:
        sub1 = float(sys.argv[1])
        sub2 = float(sys.argv[2])
        sub3 = float(sys.argv[3])
    else:
        print usage()
        sys.exit(1)
    print("Requesting with %s %s %s"%(sub1, sub2, sub3))
    print("Avg = %s"%(my_client(sub1, sub2, sub3)))
