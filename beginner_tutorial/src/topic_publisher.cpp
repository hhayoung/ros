#include "ros/ros.h"  // ROS기본 헤더 파일
#include "beginner_tutorial/MsgTutorial.h"  // MsgTutorial 메세지 파일의 헤더(빌드 후 자동생성됨)

int main(int argc, char **argv)  // 노드 메인함수
{
	ros::init(argc, argv, "topic_publisher");  // 노드명 초기화
    	// 모든 노드에서는 초기화 필요
    	ros::NodeHandle nh;  // ROS 시스템과 통신을 위한 노드 핸들 선언
    	// 노드를 식별하기 위한 핸들
    	// 퍼블리시어 선언, "  패키지이름  " 패키지의 MsgTutorial.msg파일을 이용한
    	// 퍼블리시어 "  퍼블리시어노드이름  " 를 작성한다.
    	ros::Publisher ros_tutorial_pub = nh.advertise<beginner_tutorial::MsgTutorial>("ros_tutorial_msg", 100);
    	// 토픽명은 "ros_tutorial_msg"이며, 퍼블리시어 큐(queue)사이즈를 100개로 설정한다는 뜻
	// ros_tutorial_pub(지은 이름)을 nh(nodehandle)로 쓰겠다.
	// 큐 : 데이터 저장하는 메모리.

    	ros::Rate loop_rate(10);  // 루프주기를 설정 "10"이라는 것은 10Hz를 의미, 0.1초마다 반복
	// Hz : 주파수. 1초에 진동하는 횟수. 1초에 루프가 몇번 수행되냐 (t = 1/Hz)
	// 1s = 1000ms

    	beginner_tutorial::MsgTutorial msg;  // MsgTutorial 메세지 파일 형식으로 msg라는 메시지 선언
    	int count = 0;  // 사용될 변수 선언
    
    	while(ros::ok()) {  // rod::ok() -> 참값 반환
        	msg.stamp=ros::Time::now();  // 현재 시간을 msg의 하위 stamp 메세지에 담는다.
        	msg.data=count;  // count라는 변수값을 msg의 하위 data에 담는다.

        	ROS_INFO("send msg=%d", msg.stamp.sec);  // stamp.sec 메세지를 표시
        	ROS_INFO("send msg=%d", msg.stamp.nsec);  // stamp.nsec 메세지를 표시
        	ROS_INFO("send msg=%d", msg.data);  // 메세지 표시
		// ROS_INFO() - print문과 비슷. 뭘보냈는지 일단 나도 봐야 하니까
        	// -> 날 위해 확인하는 부분이지 꼭 필요한 코드가 x. 
		// 이 코드로 메세지를 발행하는 건 아니다.

        	ros_tutorial_pub.publish(msg);  // 메세지 발행(누가 받던지말던지 발행중)
        	loop_rate.sleep();  // 위에서 정한 루프 주기에 따라서 슬립에 들어간다.
		// 주기를 지정하지 않고 그냥 돌리면 훨씬 빠를텐데 그걸 0.1초로 조절하는 것.
       		++count;  // count 변수 1씩 증가
	}

	return 0;

}

