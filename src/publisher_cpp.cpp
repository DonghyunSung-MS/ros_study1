#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char** argv)
{
  ros::init(argc,argv,"Pub_cpp_node");

  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::Int32>("/myrostopic",1);

  ros::Rate rate(1);
  std_msgs::Int32 msg;
  int i=1;
  while(ros::ok())
  {
    msg.data = i++;
    pub.publish(msg);
    rate.sleep();
  }
  return 0;
}
