#include <ros/ros.h>
#include "ros_study1/Average.h"



bool service_callback(ros_study1::Average::Request &req,
                      ros_study1::Average::Response &res)
{
  res.c = (req.sub1 + req.sub2 + req.sub3)/3;
  ROS_INFO("Caculating Average of 3 subjects: %.1lf %.1lf %.1lf",
            req.sub1, req.sub2, req.sub3);
  return true;
}

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "my_server");
  ros::NodeHandle nh;
  ros::ServiceServer srv_server = nh.advertiseService("/average_calc",service_callback)
  ros::spin();
  return 0;
}
