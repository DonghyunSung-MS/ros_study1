ROS STUDY DAY1
==============
## Enviroment
ros-kinetic(ubuntu 16.04)

## Publisher And Subscriber

#### Setting
```
$ cm
$ rocore # always~
$ roscd ros_study1/scripts & chmod +x publisher_py.py
$ roscd ros_study1/scripts & chmod +x subscriber_py.py
$ roscd ros_study1/scripts & chmod +x server_py.py
$ roscd ros_study1/scripts & chmod +x client_py.py
```
#### Python
```
$ rosrun ros_study1 publisher_py.py
$ rosrun ros_study1 subscriber_py.py
```
#### C++
```
$ rosrun ros_study1 publisher_cpp
$ rosrun ros_study1 subscriber_cpp
```
#### Executing at once using launch file
```
$ roslaunch ros_study1 pub_sub.launch
```
## Service Server & Client
#### Python
```
$ rosrun ros_study1 server_py.py
$ rosrun ros_study1 client_py.py
```
#### C++
```
$ rosrun ros_study1 client_cpp
$ rosrun ros_study1 server_cpp
```

## ROS commend

```
$ roscore
$ roscd
$ rosrun
$ rostopic
$ rosservice
$ rosnode
$ rosbag
```
#### Examples

###### rostopic
```
$ rostopic list
$ rostopic info
$ rostopic pub -1 "topic name" "msg type" "data: "
$ rostopic hz "topic name"
```
###### rosservice
```
$ rosservice call "service name" "arguments"
$ rosservice list
$ rosservice find
```
###### rosnode
```
$ rosnode list
$ rosnode info
$ rosnode kill
```
