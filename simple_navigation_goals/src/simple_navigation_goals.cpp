#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");

   //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //we'll send a goal to the robot
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  int flag = 0;

 for (int i=0; i<4; i++) {
  if (flag==0) {
     goal.target_pose.pose.position.x = 5.0;
     goal.target_pose.pose.position.y = 5.0;
     goal.target_pose.pose.orientation.w = 1.0;

     ROS_INFO("Sending goal");
     ac.sendGoal(goal);

     ac.waitForResult();

     if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
       ROS_INFO("Succeeded");
       flag=1;
     }
     else
       {ROS_INFO("Failed");}
  }
  else if (flag==1) {
     goal.target_pose.pose.position.x = 0.0;
     goal.target_pose.pose.position.y = 0.0;
     goal.target_pose.pose.orientation.w = 1.0;

     ROS_INFO("Sending goal");
     ac.sendGoal(goal);

     ac.waitForResult();

     if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
       ROS_INFO("Succeeded");
       flag=0;
     }
     else
       {ROS_INFO("Failed");}
  }
 }
  return 0;
}
