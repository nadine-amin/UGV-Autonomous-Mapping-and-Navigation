#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <vector>
#include <string>
#include <std_msgs/Float32.h>
#include <math.h>
#include <geometry_msgs/Twist.h>
#include <visualization_msgs/Marker.h>
#include <std_msgs/Bool.h>
#define pi 3.1419265358

namespace autonomous_mapping {

/*!
 * Class containing the Husky Highlevel Controller 2
 */
class autonomous_Mapping {
public:
	/*!
	 * Constructor.
	 */
	autonomous_Mapping(ros::NodeHandle& nodeHandle);

	/*!
	 * Destructor.
	 */
	virtual ~autonomous_Mapping();

private:
	ros::NodeHandle nodeHandle_;
        ros::Subscriber laser_scan_subs;

	ros::Publisher controlled_cmd_vel_publ; 
        std::string topic_name;
        int queue_size;
        int i;
        int flag;
        //float controller_gain;
        //float index;
        //float angle;
        //float minrange;
	geometry_msgs::Twist cmd_vel_command; 
        void scannerCallback (const  sensor_msgs::LaserScan::ConstPtr & laser_scan_msgs);
};

} /* namespace */
