#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MyPublisherNode : public rclcpp::Node
{
public:
    MyPublisherNode() : Node("my_publisher_node")
    {
        publisher_ = create_publisher<std_msgs::msg::String>("my_topic", 10);
        timer_ = create_wall_timer(std::chrono::seconds(1), std::bind(&MyPublisherNode::timer_callback, this));
        RCLCPP_INFO(get_logger(), "My Publisher Node has been created.");
    }

private:
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello, ROS 2!";
        publisher_->publish(message);
        RCLCPP_INFO(get_logger(), "Publishing: %s", message.data.c_str());
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
