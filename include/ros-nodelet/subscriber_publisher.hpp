#ifndef SUB_PUB_H_
#define SUB_PUB_H_

#include <ros/ros.h>

#include <nodelet/nodelet.h>
#include <std_msgs/Int64.h>


namespace nodelet_example
{
    class subscriber_publisher : public nodelet::Nodelet
    {
    private:
        virtual void onInit() override;

        void CountCB(const std_msgs::Int64::ConstPtr & msg);

        ros::NodeHandle global_nh_;
        ros::NodeHandle private_nh_;
        ros::Subscriber sub_;
        ros::Publisher pub_;
        std_msgs::Int64 msg_;

    public:
        subscriber_publisher();
        ~subscriber_publisher();
    };
} // namespace nodelet_example


#endif