#include "test/msg1.h"
#include "ros/ros.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "node_msg1_send");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<test::msg1>("topic_msg1", 1000);
    ros::Rate loop_rate(1000);
    while (ros::ok()) {
        test::msg1 msg;
        msg.age = 20;
        pub.publish(msg);
        cout << "publish msg" << endl;
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
