#include <ros/ros.h>
#include <std_msgs/Int32.h>

void my_callback(const std_msgs::Int32::ConstPtr &msg)
{
  ROS_INFO("Hello ROS %d", msg->data);
}

int main(int argc, char** argv)
{
  ros::init(argc,argv,"sub_cpp_node");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/myrostopic",1,&my_callback);
  ros::spin();

  return 0;
}
