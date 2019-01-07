#include <ros/ros.h>
#include <cstdlib>
#include "ros_0107/ros_0107_msg.h"
using namespace std;

int main(int argc, char *argv[]){
    ros::init(argc, argv, "ros_0107_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<ros_0107::ros_0107_msg>("ros_tuto_msg",100);
    ros::Rate loop_rate(10);
    
    ros_0107::ros_0107_msg msg;
    u_int16_t r1;
    u_int16_t r2;
    int cnt = 0;
    std::vector<u_int16_t>::iterator i;

    srand(time(NULL));

    while(ros::ok()){
        msg.stamp = ros::Time::now();
        r1 = rand() % 20 + 1;
        msg.v.assign(r1,0);
        cnt = 0;
        msg.r = r1;
        i = msg.v.begin();
        while(i != msg.v.end()){
            r2 = 1+ rand() % 20 ;
            *i = r2;
            i++;
        }
        pub.publish(msg);
        loop_rate.sleep();
        cnt++;
    }
    return 0;
}