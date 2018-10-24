#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
    printf("Hello, OpenCV!\n");

    Mat img = imread("test.png");
    namedWindow("testtest");
    imshow("testtest", img);
    waitKey(6000);
    
    return 0;
}