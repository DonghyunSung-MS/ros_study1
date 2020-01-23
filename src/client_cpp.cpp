#include <ros/ros.h>
#include "ros_study1/Average.h"


int main(int argc, char** argv)
{
  ros::init(argc,argv,"my_client");
  if (argc!=4)
  {
    ROS_INFO("usage:%s [sub1, sub2, sub3]",argv[0]);
    return 1;
  }
  ros::NodeHandle nh;
  ros::ServiceClient srv_client = nh.serviceClient<ros_study1::Average>("/average_calc");

  ros_study1::Average srv;
  srv.request.sub1 = atof(argv[1]);
  srv.request.sub2 = atof(argv[2]);
  srv.request.sub3 = atof(argv[3]);

  if(srv_client.call(srv))
    ROS_INFO("Avg is %.1lf",srv.response.avg);
  else
  {
    ROS_ERROR("Failed to call service");
    return 1;
  }
  return 0;
}
