#ifndef SUB_PUB_2_H_
#define SUB_PUB_2_H_

#include <ros/ros.h>

#include <nodelet/nodelet.h>
#include <std_msgs/Int64.h>


namespace nodelet_example
{
    class subscriber_publisher2 : public nodelet::Nodelet
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
        subscriber_publisher2();
        ~subscriber_publisher2();
    };
} // namespace nodelet_example


#endif