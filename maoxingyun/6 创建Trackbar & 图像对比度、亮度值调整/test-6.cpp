#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//全局变量
Mat img;
int threshval = 160;			//轨迹条滑块对应的值，给初值160


static void on_trackbar(int, void*)
{
	Mat bw = threshval < 128 ? (img < threshval) : (img > threshval);
	
	vector<vector<Point> > contours;        //轮廓
	vector<Vec4i> hierarchy;                //层次

	//查找轮廓
	findContours( bw, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );
	
	Mat dst = Mat::zeros(img.size(), CV_8UC3);
	
	if( !contours.empty() && !hierarchy.empty() )
	{
		//遍历所有顶层轮廓，随机生成颜色值绘制给各连接组成部分
		int idx = 0;
		for( ; idx >= 0; idx = hierarchy[idx][0] )
		{
			Scalar color( (rand()&255), (rand()&255), (rand()&255) );
			//绘制填充轮廓
			drawContours( dst, contours, idx, color, CV_FILLED, 8, hierarchy );
		}
	}
	
	imshow( "Connected Components", dst );
}


int main()
{
	system("color 5F"); 
	img = imread("1.jpg", 0);
	if( !img.data )
    { 
        printf("读取img图片文件错误！ \n"); 
        return -1; 
    }
	namedWindow( "Image", 1 );
	imshow( "Image", img );

	namedWindow( "Connected Components", 1 );

	createTrackbar( "Threshold", "Connected Components", &threshval, 255, on_trackbar);
	on_trackbar(threshval, 0);

	waitKey(0);
	return 0;
}




