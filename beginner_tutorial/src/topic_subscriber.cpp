#include "ros/ros.h"  // ROS 기본 헤더 파일
#include "beginner_tutorial/MsgTutorial.h"  // MsgTutorial 메세지 파일 헤더(빌드 후 자동생성)


// 메세지 콜백 함수로서, 아래서 설정한 "ros_tutorial_msg"의 이름의 토픽, 메세지를 수신하였을 때 동작하는 함수
// 입력 메세지로는 beginner_tutorial 패키지의 MsgTutorial 메세지를 받도록 되어있음
void msgCallback(const beginner_tutorial::MsgTutorial::ConstPtr& msg) // msg의 주소값을 받아들이겠다.
{
	ROS_INFO("recieve msg=%d", msg->stamp.sec);
	ROS_INFO("recieve msg=%d", msg->stamp.nsec);
	ROS_INFO("recieve msg=%d", msg->data);
	// '->' : 오른쪽에 msg를 넣겠다.
}

int main(int argc, char **argv)  // 노드 메인함수
{
	ros::init(argc, argv, "topic_subscriber");  // 노드명 초기화
	ros::NodeHandle nh;  // ROS 시스템과 통신을 위한 노드 핸들 선언

	// 서브스크라이버 선언, "beginner_tutorial"패키지의 MsgTutorial.msg 파일을 이용한 서브스크라이버 "ros_tutorial_sub"을 작성한다.
	// topic명은 ros_tutorial_msg이며 Queue 사이즈를 100개로 설정한다.
	ros::Subscriber ros_tutorial_sub=nh.subscribe("ros_tutorial_msg", 100, msgCallback);

	// 콜백함수 호출을 위한 함수로, 메세지가 수신되기를 대기, 수신되었을 경우 콜백함수 실행
	ros::spin();
	// 보내주는 대로 받는 것이기 때문에 주기는 필요하지 않다.

	return 0;
}

