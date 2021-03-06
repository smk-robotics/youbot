#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

static const auto SERVICE_WAIT_TIMEOUT = ros::Duration(5.0); 

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv) {
  ros::init(argc, argv, "navigation_node");
  MoveBaseClient actionClient("move_base", true);

  while (!actionClient.waitForServer(SERVICE_WAIT_TIMEOUT)) {
    ROS_INFO("[navigation_node]: Waiting for the move_base action server to come up.");
  }

  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = -4.0;
  goal.target_pose.pose.position.y = 8.0;
  goal.target_pose.pose.orientation.w = 1.0;

  actionClient.sendGoal(goal);
  actionClient.waitForResult();

  if (actionClient.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("[navigation_node]: The initial goal is reached.");
  else
    ROS_ERROR("[navigation_node]: Failed to reach initial goal.");

  return EXIT_SUCCESS;
}