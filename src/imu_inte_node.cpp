#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include <geometry_msgs/Twist.h>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "imu_inte_test");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);
    ros::Rate loop_rate(10);
    
    int vel_x = 0;
    int vel_y = 0;
    int vel_z = 0;
    int ang = 0;
    int start = 50;

    //vel_x = 0.138 for 5 second

    geometry_msgs::Twist vel;
    
    while(ros::ok())
    {
        vel.linear.x = vel_x;
        vel.linear.y = vel_y;
        vel.linear.z = vel_z;

        if(start){
            
        }

        // ROS_INFO("%ld", msg.data);
        pub.publish(vel);
        
        number++;
        loop_rate.sleep();
    }
    return 0;
}