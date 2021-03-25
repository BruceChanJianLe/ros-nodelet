#include "ros-nodelet/publisher.hpp"


namespace nodelet_example
{
    publisher::publisher()
    :   global_nh_(ros::NodeHandle()),
        private_nh_(ros::NodeHandle("~"))
    {
        // Initialize publisher
        pub_ = global_nh_.advertise<std_msgs::Int64>("counts", 1, true);

        // Initialize msgs
        msg_.data = 0;
    }

    publisher::~publisher()
    {
    }

    void publisher::start()
    {
        // Set publisher rate
        ros::Rate r(1);

        // Start publisher
        while(ros::ok())
        {
            // Publish msg_
            pub_.publish(msg_);

            // Increase data count
            ++msg_.data;

            // Sleep
            r.sleep();
        }
    }

} // namespace nodelet_example
