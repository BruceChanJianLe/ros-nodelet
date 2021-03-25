#include "ros-nodelet/subscriber_publisher.hpp"
#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(nodelet_example::subscriber_publisher, nodelet::Nodelet);


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
            [this](const std_msgs::Int64::ConstPtr & msg)
            {
                this->CountCB(msg);
            }
        );

        pub_ = private_nh_.advertise<std_msgs::Int64>("counts", 1, true);
    }

    void subscriber_publisher::CountCB(const std_msgs::Int64::ConstPtr & msg)
    {
        // Pass data from msg to msg_
        msg_.data = msg->data;

        // Publish what is recieve
        pub_.publish(msg_);

        ROS_INFO_STREAM(
            ros::this_node::getName() << " I have recieved counts: " << msg_.data
        );
    }

} // namespace nodelet_example
