#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
 
using namespace std;
using namespace cv;
 
static void ContrastAndBright(int, void *);

int g_nContrastValue; //对比度值
int g_nBrightValue;  //亮度值
Mat g_srcImage,g_dstImage;


int main(  )
{
  //改变控制台前景色和背景色
  //system("color5F"); 

  g_srcImage = imread("test2.png");
  
  if(!g_srcImage.data ) 
  { 
    printf("读取g_srcImage图片错误！\n"); 
    return false; 
  }

  //开一个空的Mat，用来放调整后的像素
  g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());

  g_nContrastValue = 80;
  g_nBrightValue = 80;

  namedWindow("test", 1);
  createTrackbar("对比度：", "test", &g_nContrastValue, 300, ContrastAndBright );
  createTrackbar("亮  度：", "test", &g_nBrightValue, 200, ContrastAndBright );  
  ContrastAndBright(g_nContrastValue, 0);
  ContrastAndBright(g_nBrightValue, 0);
  
  cout << endl << "\t嗯。好了，请调整滚动条观察图像效果~\n\n"
               << "\t按下“q”键时，程序退出~!\n";

  //按下“q”键时，程序退出
  while(char(waitKey(1)) != 'q') {}

  return 0;
}
 
 
static void ContrastAndBright(int, void *)
{
  
  for (int y = 0; y < g_srcImage.rows; y++ )
  {
    for (int x = 0; x < g_srcImage.cols; x++ )
    {
      for (int c = 0; c < 3; c++ )
      {
          g_dstImage.at<Vec3b>(y, x)[c]= saturate_cast<uchar>((g_nContrastValue * 0.01) * (g_srcImage.at<Vec3b>(y,x)[c]) + g_nBrightValue);
      }
    }
  }

  imshow("test", g_dstImage);
}
