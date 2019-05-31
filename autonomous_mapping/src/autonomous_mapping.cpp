#include "autonomous_mapping/autonomous_mapping.hpp"

namespace autonomous_mapping {

autonomous_Mapping::autonomous_Mapping(ros::NodeHandle &nodeHandle) :
  nodeHandle_(nodeHandle)
{

	nodeHandle.getParam("/autonomous_mapping/topic_name", topic_name); 
	nodeHandle.getParam("/autonomous_mapping/queue_size", queue_size);   
	ROS_INFO_STREAM(topic_name << " " << queue_size); 
laser_scan_subs = nodeHandle.subscribe(topic_name, queue_size, &autonomous_Mapping::scannerCallback, this);
	controlled_cmd_vel_publ = nodeHandle.advertise<geometry_msgs::Twist>("/cmd_vel", 1); 


ROS_INFO("okk");

}

void autonomous_Mapping::scannerCallback (const  sensor_msgs::LaserScan::ConstPtr & laser_scan_msgs) 
{

//minrange = laser_scan_msgs->ranges[0];
//for (int i = 0; i< (laser_scan_msgs->ranges.size()); i++)
//{
//  if (laser_scan_msgs->ranges[i]<minrange) {
//
//       minrange = laser_scan_msgs->ranges[i];
//       index = i;
//}
//}

flag = 0;
for ( i=laser_scan_msgs->ranges.size()*0.42 ; i<(laser_scan_msgs->ranges.size()*0.50); i++) {

if (laser_scan_msgs->ranges[i]<1.2) {
       flag = 1;
}
}
for ( i=laser_scan_msgs->ranges.size()*0.50 ; i<(laser_scan_msgs->ranges.size()*0.58); i++) {

if ((laser_scan_msgs->ranges[i]<1.2)&&(flag!=1)) {
       flag = 2;
}
}

if (flag == 1) {
       cmd_vel_command.linear.x = 0.1;
       cmd_vel_command.angular.z = 10;
       ROS_INFO("opsgoleft");
}
else if(flag == 2) {
       cmd_vel_command.linear.x = 0.1;
       cmd_vel_command.angular.z = -10;
       ROS_INFO("opsgoright");
} 
else if(flag == 0) {
       // UNCOMMENT SECTION TO INCLUDE RANDOMNESS
       //int dice = rand()%25;
       //ROS_INFO(dice);
       //if (dice!=0) {
       //       cmd_vel_command.linear.x = 0.5;
       //       cmd_vel_command.angular.z = 0;
       //}
       //else {
       //       int dice2 = rand()%2;
       //       cmd_vel_command.linear.x = 0.1;
       //       if (dice==0) {
       //              cmd_vel_command.angular.z = 10;
       //       }
       //       else {
       //              cmd_vel_command.angular.z = -10;
       //       }
       //}

       // COMMENT SECTION TO INCLUDE RANDOMNESS
       cmd_vel_command.linear.x = 0.5;
       cmd_vel_command.angular.z = 0;
       ROS_INFO("ok");
}

//ROS_INFO("index [%f]", index);

//angle = (-2.356190) + (0.006554*index);
//ROS_INFO("x-coordinate is: [%f]", minrange*cos(angle));
//ROS_INFO("y-coordinate is: [%f]", minrange*(-sin(angle)));

//ROS_INFO("minimum angle is: [%f]", laser_scan_msgs->angle_min);
//ROS_INFO("maximum angle is: [%f]", laser_scan_msgs->angle_max);
//ROS_INFO("angle increment is: [%f]", laser_scan_msgs->angle_increment);
//ROS_INFO("time increment is: [%f]", laser_scan_msgs->time_increment);
//ROS_INFO("time increment is: [%f]", laser_scan_msgs->scan_time);
//ROS_INFO("minimum distance is: [%f]", minrange);


//msg.angular.z = -controller_gain*(angle);
	controlled_cmd_vel_publ.publish(cmd_vel_command);

}

autonomous_Mapping::~autonomous_Mapping()
{
}

} /* namespace */
