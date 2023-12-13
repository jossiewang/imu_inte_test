#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "imu_inte_test_2");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 10);

    geometry_msgs::Twist vel;
    vel.linear.x = 0.138;

    ros::Rate rate(10);

    ros::Time startTime = ros::Time::now();

    // Run the loop for 5 seconds
    while (ros::ok() && (ros::Time::now() - startTime).toSec() < 5.0)
    {
        pub.publish(vel);

        rate.sleep();

        ros::spinOnce();
    }

    // Stop the robot by publishing a Twist message with zero velocities
    vel.linear.x = 0.0;
    pub.publish(vel);

    // Shutdown the node
    ros::shutdown();

    return 0;
}
