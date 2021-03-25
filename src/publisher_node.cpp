#include "ros-nodelet/publisher.hpp"

#include <string>

const std::string ROSNodeName {"example_publisher_node"};
int main(int argc, char ** argv)
{
    ros::init(argc, argv, ROSNodeName);

    nodelet_example::publisher node;

    node.start();

    return 0;
}