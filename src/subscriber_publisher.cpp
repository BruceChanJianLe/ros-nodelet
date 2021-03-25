#include "ros-nodelet/subscriber_publisher.hpp"
#include <pluginlib/


namespace nodelet_example
{
    subscriber_publisher::subscriber_publisher()
    {
    }

    subscriber_publisher::~subscriber_publisher()
    {
    }

    void subscriber_publisher::onInit()
    {
        // Init global and private nodehanle
        global_nh_ = getNodeHandle();
        private_nh_ = getPrivateNodeHandle();

        sub_ = global_nh_.subscribe<std_msgs::Int64>(
            "counts", 1,
            [this](std_msgs::Int64::ConstPtr & msg)
            {
                this->CountCB(msg);
            }
        );

        pub_ = private_nh_.advertise<std_msgs::Int64>("counts", 1, true);
    }

    void subscriber_publisher::CountCB(std_msgs::Int64::ConstPtr & msg)
    {
        // Pass data from msg to msg_
        msg_.data = msg->data;

        // Publish what is recieve
        pub_.publish(msg_);
    }

} // namespace nodelet_example
