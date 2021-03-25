#include "ros-nodelet/publisher.hpp"


namespace nodelet_example
{
    publisher::publisher()
    :   global_nh_(ros::NodeHandle()),
        private_nh_(ros::NodeHandle("~"))
    {
        // Initialize
        pub_ = global_nh_.advertise<std_msgs::Int64>("counts", 1, true);
    }

    publisher::~publisher()
    {
    }

} // namespace nodelet_example
