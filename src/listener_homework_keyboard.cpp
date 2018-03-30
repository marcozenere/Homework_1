
//Developed by Marco Zenere

//Import the libraries
#include <ros/ros.h>
#include <signal.h>
#include <stdio.h>
#include "std_msgs/String.h"
#include <sstream>

int fd = 0;

//Function that remapping "SIGINT" signal
void quit(int sig)
{
  (void)sig;
  ros::shutdown();
  exit(0);
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "listener_homework_keyboard");

  ros::NodeHandle n;

  ros::Publisher key_pub_ = n.advertise<std_msgs::String>("keyboard/key", 1);

  signal(SIGINT,quit);

  char c;

  puts("Reading from keyboard:");
  puts("---------------------------");
  puts("List of possible selection:");
  puts("- Typing 'a' will show the whole message");
  puts("- Typing 'n' will show only the name");
  puts("- Typing 'e' will show only the age");
  puts("- Typing 'c' will show only the bachelor's");

  std_msgs::String msg;

  while(ros::ok())
  {
    // get the next event from the keyboard
    if(read(fd, &c, 1) < 0)
    {
      perror("read():");
      exit(-1);
    }

    if(c == 'a' || c == 'e' || c == 'n' || c == 'c')
    {
      std::stringstream ss;
      ss << c;
      msg.data = ss.str();
      key_pub_.publish(msg);
    }
  }

  return 0;
}
