#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);

	double scale = 0.5;


	double i_minH = 0;
	double i_maxH = 20;
	double i_minS = 43;
	double i_maxS = 255;
	double i_minV = 55;
	double i_maxV = 255;

	while(1)
	{
		Mat frame;
		Mat hsvMat;
		Mat detectMat;

		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz,frame.type());
		resize(frame, rFrame,ResImgSiz,INTER_LINEAR); //图像尺寸变化

		cvtColor(rFrame, hsvMat,COLOR_BGR2HSV);//颜色类型转换

		rFrame.copyTo(detectMat);
		cv::inRange(hsvMat, Scalar(i_minH,i_minS,i_minV), Scalar(i_maxH,i_maxS,i_maxV),detectMat);//双阈值化

		imshow("while in the range",detectMat);
		imshow("frame",rFrame);

		waitKey(30);
	}
}
