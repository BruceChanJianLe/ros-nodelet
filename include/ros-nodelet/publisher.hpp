#ifndef PUB_H_
#define PUB_H_

#include <ros/ros.h>

#include <std_msgs/Int64.h>


namespace nodelet_example
{
    class publisher
    {
    private:
        ros::NodeHandle global_nh_;
        ros::NodeHandle private_nh_;
        ros::Publisher pub_;
        std_msgs::Int64 msg_;

    public:
        publisher();
        ~publisher();
    };
} // namespace nodelet_example


#endif