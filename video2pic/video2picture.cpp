#include <iostream>
#include "cv.h"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;


/*
* video2picture
* 
* created by yanxudong on 2018/3/1
*/

class video2pic
{
public:
	void videoPic()
	{
		// ��ȡ��Ƶ�ļ�  
		VideoCapture cap("F:\\CVproject\\100.avi");

		// ��ȡ��Ƶ��֡��  
		long totalFrameNumber = cap.get(CV_CAP_PROP_FRAME_COUNT);
		cout << "total frames: " << totalFrameNumber << endl;

		Mat frame;
		bool flags = true;
		long currentFrame = 0;
		int num = 0;

		while (flags) {
			// ��ȡ��Ƶÿһ֡  
			cap.read(frame);

			stringstream str;
			str << setfill('0') << setw(4) << num << ".jpg";
			cout << "���ڴ����" << currentFrame << "֡" << endl;
			printf("\n");

			// ����ÿ30֡��ȡһ��֡  
			if (currentFrame % 1 == 0) {
				// ��֡ת��ͼƬ���  
				imwrite("F:\\CVproject\\output\\" + str.str(), frame);
				num++;
			}
			// ��������  
			if (currentFrame >= totalFrameNumber) {
				flags = false;
			}
			currentFrame++;
		}

		//system("pause");
	}
};
/*
void main() {
	video2pic v;
	v.videoPic();
}
*/