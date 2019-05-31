# UGV-Autonomous-Mapping-and-Navigation

The Robotics Operating System platform (ROS) was used to drive the robot, Husky, to autonomously map 5 different previously unknown terrains, localize itself after building the full maps, and eventually autonomously navigating to desired locations while avoiding obstacles and choosing the shortest path.

# For autonomous mapping of Husky in the different worlds, run:
roslaunch husky_autonomous_mapping husky_autonomous_mapping_map1.launch
roslaunch husky_autonomous_mapping husky_autonomous_mapping_map2.launch
roslaunch husky_autonomous_mapping husky_autonomous_mapping_map3.launch
roslaunch husky_autonomous_mapping husky_autonomous_mapping_map4.launch
roslaunch husky_autonomous_mapping husky_autonomous_mapping_map5.launch

# To save the generated map in your home, run:
rosrun map_server map_saver -f ~/generated_map

# For Husky navigation in the different worlds:
1. Open chefbot/chefbot_gazebo/launch/amcl_demo_map1.launch
2. Change the default value of the map file name to the name of the desired map and its path
3. run roslaunch husky_navigating husky_navigating_map1.launch

Note: If you saved the provided maps in your home, you can just edit your home section in the path in the files amcl_demo_map1.launch, amcl_demo_map2.launch, amcl_demo_map3.launch, amcl_demo_map4.launch and amcl_demo_map5.launch. You will also need to edit your home section in the path of the map pmg files in each of the maps yaml files.
