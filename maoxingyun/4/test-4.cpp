#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>


using namespace cv;
using namespace std;

bool ROI_AddImage(){
    
    Mat srcImage1= imread("test.png");
    Mat logoImage= imread("test2.png");
    // if(!srcImage1.data ) { printf("读取srcImage1错误~！ \n"); return false; }
    // if(!logoImage.data ) { printf("读取logoImage错误~！ \n"); return false; }

    //定义一个Mat类型并给其设定ROI区域
    Mat imageROI= srcImage1(Rect(800, 250, logoImage.cols, logoImage.rows));

    //加载掩模（必须是灰度图）
    Mat mask= imread("test2.png", 0);
    // namedWindow("1");
    // imshow("1",mask);

    //将掩膜拷贝到ROI
    logoImage.copyTo(imageROI, mask);

    //显示结果
    namedWindow("利用ROI实现图像叠加示例窗口");
    imshow("利用ROI实现图像叠加示例窗口",srcImage1);

    waitKey(5000);
    return true;
}

bool LinearBlending()
{
    double alphaValue = 0.5;
    double betaValue;
    Mat srcImage2, srcImage3, dstImage;

    //读取图像 ( 两幅图片需为同样的类型和尺寸 )
    srcImage2= imread("mogu.jpg");
    srcImage3= imread("rain.jpg");

    if(!srcImage2.data ) { printf("读取srcImage2错误~！ \n"); return false; }
    if(!srcImage3.data ) { printf("读取srcImage3错误~！ \n"); return false; }

    //做图像混合加权操作
    betaValue= ( 1.0 - alphaValue );
    addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);

    namedWindow("线性混合示例窗口【原图】", 1);
    imshow("线性混合示例窗口【原图】", srcImage2 );

    namedWindow("线性混合示例窗口【效果图】", 1);
    imshow("线性混合示例窗口【效果图】", dstImage );

    return true;
}

bool ROI_LinearBlending()
{

    Mat srcImage4= imread("test.png", 1);
    Mat logoImage= imread("test2.png");

    if(!srcImage4.data ) { printf("读取srcImage4错误~！ \n"); return false; }
    if(!logoImage.data ) { printf("读取logoImage错误~！ \n"); return false; }

    //定义一个Mat类型并给其设定ROI区域
    Mat imageROI;
            //方法一
    imageROI=srcImage4(Rect(200,250,logoImage.cols,logoImage.rows));
    //方法二
    //imageROI=srcImage4(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));

    //将logo加到原图上
    addWeighted(imageROI,0.5,logoImage,0.3,0.,imageROI);
    namedWindow("区域线性图像混合示例窗口");
    imshow("区域线性图像混合示例窗口",srcImage4);
    
    return true;
}


int main()
{
    system("color 5E");

    // if(ROI_AddImage()&& LinearBlending( )&&ROI_LinearBlending( ))
    // {
    //         cout<<endl<<"嗯。好了，得出了你需要的图像~! : )";
    // }

    // waitKey(0);
    
    return 0;

}