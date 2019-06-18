#include "test/msg1.h"
#include "ros/ros.h"
#include <iostream>
#include <string>
#include "test/pthreadpool.h"

using namespace std;


void messageCallback(const test::msg1::ConstPtr& msg)
{
    cout << " a " << endl;
    cout << msg->age << endl;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "node_msg1_receive");
    PthreadPool a;
    a.foo();
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("topic_msg1", 1000, messageCallback);
    ros::spin();
    return 0;
}
