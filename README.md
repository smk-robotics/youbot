# youbot demo

This repository contains youbot demonstration system.

## Preparing

- Create the new ROS workspace folder:
`mkdir youbot_workspace && cd youbot_workspace`

- Create folder for source code:
`mkdir src && cd src`

- Clone this repo to the previously created *src* directory:
`git clone https://github.com/smk-robotics/youbot.git`

## Updating git submodules

`git submodule update --init --recursive`

## Installing dependencies

- Switching to the previously created workspace folder:
`cd ../..`

- Update dependencies list:
`rosdep update`

- Install dependencies:
`rosdep install --from-paths src --ignore-src -y --rosdistro melodic`

## Building workspace:

- Build ROS workspace:
`catkin_make -DBUILD_TYPE=Release`

## Starting demo:

- Source current workspace:
`source devel/setup.bash`

- Start demo:
`roslaunch damir full_system.launch`