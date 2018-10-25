#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;

int main(){

    // Mat image = imread("test.png", -1);
    // namedWindow("test");
    // imshow("test",image);
    // waitKey(6000);


    Mat image1 = imread("test.png");
    Mat image2 = imread("test2.png");

    // namedWindow("screen1");
    // imshow("screen1",image1);

    // namedWindow("screen2");
    // imshow("screen2",image2);

    // 定义感兴趣区域ROI
    Mat imageROI;
    //imageROI = image1(Rect(800, 350, image2.cols, image2.rows));
    imageROI = image1(Range(350, 350 + image2.rows), Range(800, 800 + image2.cols));

    addWeighted(imageROI, 0.5, image2, 0.3, 0., imageROI);

    namedWindow("screen3");
    imshow("screen3", image1);

    waitKey(6000);

    return 0;
}