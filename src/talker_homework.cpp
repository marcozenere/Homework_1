
//Developed by Marco Zenere

//Import the libraries
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Homework_1/message.h"
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker_homework");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<Homework_1::message>("chatter", 1000);

  //A message every second
  ros::Rate loop_rate(1);

  /*

  By default roscpp will install a SIGINT handler which provides Ctrl-C handling which will cause ros::ok() to return false if that happens.
  ros::ok() will return false if:

  - a SIGINT is received (Ctrl-C)
  - we have been kicked off the network by another node with the same name
  - ros::shutdown() has been called by another part of the application.

  - all ros::NodeHandles have been destroyed

  Once ros::ok() returns false, all ROS calls will fail.

  */

  while (ros::ok())
  {

    Homework_1::message msg;

    std::stringstream ss;
    ss << "Marco";
    msg.name = ss.str();
    msg.age = 23;
    std::stringstream ss1;
    ss1 << "Informatica";
    msg.corso = ss1.str();

    ROS_INFO("%s,%i,%s", msg.name.c_str(),msg.age,msg.corso.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();

  }


  return 0;
}
