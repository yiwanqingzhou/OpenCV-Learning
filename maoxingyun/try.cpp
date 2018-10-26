
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
    printf("Hello, OpenCV!\n");

    

    Mat pic( 3, 5, CV_8UC1, Scalar(100));
    cout << "M = " << endl << " " << pic << endl;


    return 0;
}