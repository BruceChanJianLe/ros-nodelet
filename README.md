# ROS Nodelet

This repository demonstrates the usage of ROS nodelet plugin API for your own package.

## Listing Available Nodelets on System

Following commands are helpful to list all nodelets available on your system found in ROS_PACKAGE_PATH. Note that it's NOT the list of currently running nodelet nor nodelet managers. Or list the nodelet xml files for [pluginlib](https://wiki.ros.org/pluginlib) by: 
```bash
rosrun nodelet declared_nodelets
# or
rospack plugins --attrib=plugin nodelet
```

## References

- Nodelet Explanation [link_blog](https://automaticaddison.com/working-with-ros-nodelets-in-ros-noetic/)
- Nodelet Explanation Video [link_youtube](https://www.youtube.com/watch?v=2eyaO2REmns)
- Nodelet Example [link_github](https://github.com/lucasw/nodelet_demo)
- Nodelet Multi-threading Example [link_github](https://github.com/ros-drivers/camera1394/blob/abc1950a6925628acc7581cabc312741706b6e4c/src/nodes/nodelet.cpp)
- Packt Nodelet Explanation [link](https://hub.packtpub.com/working-pluginlib-nodelets-and-gazebo-plugins/)
- Multiple Nodelet in Single Package [link](https://answers.ros.org/question/302004/multiple-nodelets-in-the-same-package/)
