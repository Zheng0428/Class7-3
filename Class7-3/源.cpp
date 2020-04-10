#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2\imgproc\types_c.h>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = cv::imread("D:\\a\\3.png", 0);
	cv::Mat canny;
	/*threshold(srcMat, canny, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);*/
	Canny(srcMat, canny, 100, 120);
	std::vector <cv::Vec4i> lines;
	cv::HoughLinesP(canny, lines, 1, CV_PI / 180, 50, 0, 20);
	imshow("src1", canny);
	for (int i = 0; i < lines.size(); i++) 
	{
		line(srcMat, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), (0, 0, 255));
	}
	imshow("src", srcMat);
	cv::waitKey(0);

}