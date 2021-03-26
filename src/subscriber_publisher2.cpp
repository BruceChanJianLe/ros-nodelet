#include "ros-nodelet/subscriber_publisher2.hpp"
#include <pluginlib/class_list_macros.h>

PLUGINLIB_EXPORT_CLASS(nodelet_example::subscriber_publisher2, nodelet::Nodelet);


namespace nodelet_example
{
    subscriber_publisher2::subscriber_publisher2()
    {
    }

    subscriber_publisher2::~subscriber_publisher2()
    {
    }

    void subscriber_publisher2::onInit()
    {
        // Initialize nodelet
        gloabal_nh_ = getNodeHandle();
        private_nh_ = getPrivateNodeHandle();

        sub_ = gloabal_nh_.subscribe<std_msgs::Int64>(
            "demo_sub_pub_node/counts", 1,
            [this](const std_msgs::Int64::ConstPtr & msg)
            {
                this->CountCB(msg);
            }
        );

        pub_ = private_nh_.advertise<std_msgs::Int64>("counts", 1, true);
    }

    void subscriber_publisher2::CountCB(const std_msgs::Int64::ConstPtr & msg)
    {
        // Pass data from msg to msg_
        msg_.data = msg->data;

        // Publish what is recieve
        pub_.publish(msg_);

        NODELET_INFO_STREAM(
            ros::this_node::getName() << " I have recieved counts: " << msg_.data
        );
    }

} // namespace nodelet_example