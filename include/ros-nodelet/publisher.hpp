#ifndef PUB_H_
#define PUB_H_

#include <ros/ros.h>

#include <nodelet/nodelet.h>
#include <std_msgs/Int64.h>


namespace nodelet_example
{
    class publisher : public nodelet::Nodelet
    {
    private:
        virtual void onInit() override;
    public:
        publisher();
        ~publisher();
    };
} // namespace nodelet_example


#endif