#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "test.pb.h"

class MySubscriberNode : public rclcpp::Node
{
public:
    MySubscriberNode() : Node("my_subscriber_node")
    {
        subscription_ = create_subscription<std_msgs::msg::String>(
                "my_topic", 10, std::bind(&MySubscriberNode::listener_callback, this, std::placeholders::_1));
    }

private:
    void listener_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(get_logger(), "Received message: %s", msg->data.c_str());
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MySubscriberNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
