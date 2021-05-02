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

  //define the move base goals for each room
  move_base_msgs::MoveBaseGoal point_b_goal;
  move_base_msgs::MoveBaseGoal point_c_goal;
  move_base_msgs::MoveBaseGoal point_d_goal;
  move_base_msgs::MoveBaseGoal point_e_goal;


  //send the first goal
  point_b_goal.target_pose.header.frame_id = "map";
  point_b_goal.target_pose.header.stamp = ros::Time::now();

  point_b_goal.target_pose.pose.position.x = -13.2508673897;
  point_b_goal.target_pose.pose.position.y = -6.03139311508;
  point_b_goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending point_b_goal");
  ac.sendGoal(point_b_goal);

  ac.waitForResult();
  if(ac.getState() != actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Failure :(");
  ac.stopTrackingGoal();

  //send the second goal
  point_c_goal.target_pose.header.frame_id = "map";
  point_c_goal.target_pose.header.stamp = ros::Time::now();

  point_c_goal.target_pose.pose.position.x = -14.6357506747;
  point_c_goal.target_pose.pose.position.y = 3.49857788575;
  point_c_goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending point_c_goal");
  ac.sendGoal(point_c_goal);

  ac.waitForResult();
  if(ac.getState() != actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Failure :(");
  ac.stopTrackingGoal();

  //send the third goal
  point_d_goal.target_pose.header.frame_id = "map";
  point_d_goal.target_pose.header.stamp = ros::Time::now();

  point_d_goal.target_pose.pose.position.x = 1.58970444857;
  point_d_goal.target_pose.pose.position.y = -2.69996306082;
  point_d_goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending point_d_goal");
  ac.sendGoal(point_d_goal);

  ac.waitForResult();
  if(ac.getState() != actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Failure :(");
  ac.stopTrackingGoal();

  //send the fourth goal
  point_e_goal.target_pose.header.frame_id = "map";
  point_e_goal.target_pose.header.stamp = ros::Time::now();

  point_e_goal.target_pose.pose.position.x = 17.1387679692;
  point_e_goal.target_pose.pose.position.y = -1.2761700023;
  point_e_goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending point_e_goal");
  ac.sendGoal(point_e_goal);

  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the task has been achieved");
  else
    ROS_INFO("The base failed to achieve task for some reason");

  return 0;
}