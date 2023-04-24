#ifndef RQNODE_HPP_
#define RQNODE_HPP_
#include <QThread>
#include <ros/ros.h>
#include "std_msgs/String.h" //发布消息类型纯文本
class RQNode : public QThread
{
    Q_OBJECT
public:
    RQNode()
    {   
        // 初始化 ROS 客户端；
        //传入节点名称
        int argc = 0;
        char *argv[] = {0};
        ros::init(argc, argv, "erGouZi");
        ros::start(); // explicitly needed since our nodehandle is going out of scope.
        //创建节点句柄；
        ros::NodeHandle nh;
        ros::NodeHandle snh;
        //创建发布者对象；
        this->_pubp = nh.advertise<std_msgs::String>("FangChe", 10); //话题“FangChe”
        //创建订阅者对象；处理回调函数
        this->_subp = snh.subscribe("FangChe", 10, &RQNode::recv_callback, this);}
    // 处理订阅到的消息
    void recv_callback(const std_msgs::String::ConstPtr &msg)
    {
        emit TopicData("msg is :"+QString(msg->data.c_str()));
    }
    // spin
    void sping()
    {
        ros::spinOnce();
    }

    void _pub_msgs(QString str)
    {
        std_msgs::String pub_msgs;
        pub_msgs.data = str.toStdString();
        this->_pubp.publish(pub_msgs);
    }

private:
    ros::Publisher _pubp;
    ros::Subscriber _subp;
signals:
    /*
    含有信号的头文件需要被变异
    	CMakeLists.txt：25 PRO_SOURCE_DIR 中加入 include/ *.hpp
    */
    void TopicData(QString);
};
#endif // QNODE_HPP_
