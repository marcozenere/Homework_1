
//Developed by Marco Zenere 

//Import the libraries
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "Homework_1/message.h"

std::string choice;

//Function that allows you to cath up the choice of the user 
void keyCallback(const std_msgs::String ::ConstPtr& msg)
{
  choice = msg->data.c_str();
}

//Function that allows you to print the user choice
void chatterCallback(const Homework_1::message& msg)
{
  if(choice.compare("a") == 0)
    ROS_INFO("I heard: [%s, %i, %s]", msg.name.c_str(), msg.age, msg.corso.c_str());
  else if(choice.compare("n") == 0)
    ROS_INFO("I heard: [%s]", msg.name.c_str());
  else if(choice.compare("e") == 0)
    ROS_INFO("I heard: [%i]", msg.age);
  else if(choice.compare("c") == 0)
    ROS_INFO("I heard: [%s]", msg.corso.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener_homework");

  //Node for listen the "talker" node
  ros::NodeHandle n0;
  //Node for listen the "keyboard" node
  ros::NodeHandle n1;

  ros::Subscriber sub0 = n0.subscribe("chatter", 1000, chatterCallback);
  ros::Subscriber sub1 = n1.subscribe("keyboard/key", 1000, keyCallback);

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */

  ros::spin();

  return 0;
}
