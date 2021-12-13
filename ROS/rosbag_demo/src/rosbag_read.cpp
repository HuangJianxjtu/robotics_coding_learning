#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

using namespace std;

int main(){
    rosbag::Bag bag;
    // 1.打开一个bag文件
    bag.open("test.bag", rosbag::bagmode::Read); // 第二个参数可不填，默认是read

    // 2.设置需要遍历的topic
    std::vector<std::string> topics;
    topics.push_back(std::string("chatter"));
    topics.push_back(std::string("numbers"));
    // 读指定的两个topic，如果全读，第二个参数不写，这样：rosbag::View view_all(view);
    rosbag::View view(bag, rosbag::TopicQuery(topics));

    foreach(rosbag::MessageInstance const m, view)
    {
        std::cout << m.getTopic() << " " << m.getTime() << std::endl; //获取topic和时间戳
        // 实例化消息，注意s是指针，instantiate<消息类型>
        std_msgs::String::ConstPtr s = m.instantiate<std_msgs::String>();
        if (s != NULL)
            std::cout << s->data << std::endl;

        std_msgs::Int32::ConstPtr i = m.instantiate<std_msgs::Int32>();
        if (i != NULL)
            std::cout << i->data << std::endl;
    }

    bag.close();
}
