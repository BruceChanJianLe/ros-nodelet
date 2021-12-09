#include <ros/ros.h>

#include <nodelet/loader.h>
#include <string>


std::string ROSNodeName {"nodelet_sub_pub_node"};
std::string NodeletName {"ros-nodelet/subscriber_publisher"};

int main(int argc, char ** argv)
{
    // Initialize ROS node
    ros::init(argc, argv, ROSNodeName);

    // Instantiate ROS nodelet
    nodelet::Loader nodelet;

    // Nodelet remap
    nodelet::M_string remap(ros::names::getRemappings());

    // Nodelet argv
    nodelet::V_string nargv;

    // Obtain nodename, this can be skipped and use ROSNodeName instead
    std::string nodelet_name = ros::this_node::getName();

    // Load nodelet
    nodelet.load(nodelet_name, NodeletName, remap, nargv);

    // ROS Spin (Good practice to have)
    ros::spin();

    return 0;
}