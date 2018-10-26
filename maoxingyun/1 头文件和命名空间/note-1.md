## 头文件和命名空间

三行标配

``` C++
#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
 
using namespace cv;
```

<br>

## 关于Mat类型

`cv::Mat` 类是用于保存图像以及其他矩阵数据的数据结构。

默认情况下，其尺寸为0，我们也可以指定初始尺寸。
比如定义一个Mat类对象：

``` 
cv::Mat pic(320,640,cv::Scalar(100));
```

其实用到Mat对象最简单的代码就是：
```
Mat img = imread("test.jpg");
```

<br>

## 编译
```bash
g++ try.cpp `pkg-config opencv --cflags --libs`
```