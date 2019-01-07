#include <ros/ros.h>
#include <cstdlib>
#include <math.h>
#include "ros_0107/ros_0107_msg.h"
using namespace std;

template<typename T>
ostream& operator << (ostream& out, const vector <T>& v){
    out << "{";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i){
        out << pow(v[i],2);
        if(i != last)
            out << ", ";
    }
    out << "}";
    return out;
}

void subCallback(const ros_0107::ros_0107_msgPtr& msg){
    ROS_INFO("receive msg = %d", msg->stamp.sec);
    ROS_INFO("receive msg = %d", msg->r);
    ROS_INFO_STREAM("receive msg vector "<<msg->v);
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "ros_0107_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("ros_tuto_msg", 100, subCallback);
    ros::spin();
    return 0;
}