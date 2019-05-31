#include <ros/ros.h>
#include "autonomous_mapping/autonomous_mapping.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "autonomous_mapping");
  ros::NodeHandle nodeHandle("~");

  autonomous_mapping::autonomous_Mapping autonomous_Mapping(nodeHandle);

  ros::spin();
  return 0;
}
