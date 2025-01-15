#include "ros/ros.h"
// ROS Default Header File
#include "ros_mhs_topic/MsgTutorial.h"
// MsgTutorial Message File Header. The header file is automatically created when building the package.

int main(int argc, char **argv)
{
    ros::init(argc, argv, "topic_pembicara");  // Node main function
    ros::NodeHandle nh;                        // Node handle declaration for communication with ROS system

    // Declare pembicara, create pembicara 'ros_tutorial_pub' using the 'MsgTutorial'
    // message file from the 'ros_mhs_topic' package. The topic name is
    // 'ros_tutorial_msg' and the size of the pembicara queue is set to 100.
    ros::Publisher ros_tutorial_pub = nh.advertise<ros_mhs_topic::MsgTutorial>("ros_tutorial_msg", 100);

    // Set the loop period. '10' refers to 10 Hz and the main loop repeats at 0.1 second intervals
    ros::Rate loop_rate(10);

    ros_mhs_topic::MsgTutorial msg;
    int count = 0;  // Declares message 'msg' in 'MsgTutorial' message file format. Variable to be used in message.

    while (ros::ok())
    {
        msg.stamp = ros::Time::now();  // Save current time in the stamp of 'msg'
        msg.nim = "2200018345";
        msg.nama = "SIRLY ZIADATUL MUSTAFIDAH";

        // Prints the 'stamp.sec', 'stamp.nsec', and 'data' messages
        ROS_INFO("Send Time = %d", msg.stamp.sec);
        ROS_INFO("Send NIM: %s", msg.nim.c_str());
        ROS_INFO("Send nama = %s", msg.nama.c_str());

        ros_tutorial_pub.publish(msg);  // Publishes 'msg' message
        loop_rate.sleep();              // Goes to sleep according to the loop rate defined above.
        ++count;                        // Increase count variable by one
    }

    return 0;
}

