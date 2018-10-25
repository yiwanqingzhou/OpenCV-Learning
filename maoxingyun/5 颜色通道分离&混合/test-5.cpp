#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>


using namespace cv;
using namespace std;

int main()
{
    // Mat M1(3,2, CV_8UC3, Scalar(10,10,10));
    // Mat M2(3,2, CV_8UC1, Scalar(50));
    // vector<Mat> channels;
    // split(M1,channels);


    // Mat M1ROI = channels.at(0);
    // addWeighted(M1ROI, 0.3, M2, 0.5, 0., M1ROI);

    // cout << "M1ROI = " << endl << M1ROI << endl;
    // cout << "channels0 = " << endl << channels.at(0) << endl;
    // cout << "channels1 = " << endl << channels.at(1) << endl;
    // cout << "channels2 = " << endl << channels.at(2) << endl;

    // merge(channels, M1);
    // cout << "M1 = " << endl << M1 << endl;



    
    vector<Mat> channels;

    Mat srcImage= imread("test.png");
    Mat logoImage= imread("test2.png", 0);

    split(srcImage, channels);

    //注意这里是引用 channels随imageROI改变
    Mat imageROI = channels.at(1);
    
    // 两种方法深度拷贝 channels不随imageROI改变
    // Mat imageROI = channels.at(1).clone();
    // Mat imageROI;
    // channels.at(1).copyTo(imageROI);

    addWeighted(imageROI(Rect(500,500,logoImage.cols,logoImage.rows)),1.0,logoImage,10,0.,imageROI(Rect(500,500,logoImage.cols,logoImage.rows)));

    merge(channels,srcImage);
    namedWindow("sample");
    imshow("sample",srcImage);

    waitKey(6000);
}