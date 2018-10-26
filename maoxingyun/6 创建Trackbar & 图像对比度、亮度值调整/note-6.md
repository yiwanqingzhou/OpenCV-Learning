# 创建Trackbar & 图像对比度、亮度值调整

## OpenCV中轨迹条（Trackbar）的创建和使用

### 创建轨迹条 ——— createTrackbar

> 这个`createTrackbar`函数，为我们创建一个具有特定名称和范围的轨迹条（Trackbar，或者说是滑块范围控制工具），指定一个和轨迹条位置同步的变量。而且要指定回调函数`onChange`（第五个参数），在轨迹条位置改变的时候来调用这个回调函数。并且我们知道，创建的轨迹条显示在指定的`winname`（第二个参数）所代表的窗口上。


首先大家要记住，它往往会和一个回调函数配合起来使用。

函数原型：

 ```C++
 int createTrackbar(conststring& trackbarname, conststring& winname, int* value, int count, TrackbarCallback onChange = 0, void* userdata = 0);
 ```

- 第一个参数，`const string& `类型的`trackbarname`，表示轨迹条的名字，用来代表我们创建的轨迹条。
  
- 第二个参数，`const string& `类型的`winname`，填窗口的名字，表示这个轨迹条会依附到哪个窗口上。
  
- 第三个参数，`int* `类型的`value`，一个指向整型的指针，表示滑块的位置。并且在创建时，滑块的初始位置就是该变量当前的值。
  
- 第四个参数，`int `类型的`count`，表示滑块可以达到的最大位置的值。  
  PS:滑块最小的位置的值始终为0。
  
- 第五个参数，`TrackbarCallback `类型的onChange，首先注意他有默认值0。  
  这是一个指向回调函数的指针，每次滑块位置改变时，这个函数都会进行回调。  
  **并且这个函数的原型必须为`void XXXX(int,void*);` 其中第一个参数是轨迹条的位置，第二个参数是用户数据（看下面的第六个参数）。**  
  如果回调是NULL指针，表示没有回调函数的调用，仅第三个参数value有变化。
  
- 第六个参数，`void* `类型的`userdata`，他也有默认值0。  
  这个参数是用户传给回调函数的数据，用来处理轨迹条事件。  
  如果使用的第三个参数value实参是全局变量的话，完全可以不去管这个`userdata`参数。

<br>

小示例：
```C++
 createTrackbar("对比度：", "【效果图窗口】", &g_nContrastValue, 300, ContrastAndBright);
 // g_nContrastValue为全局的整型变量，ContrastAndBright为回调函数的函数名（即指向函数地址的指针）
```

### 获取当前轨迹条的位置 ——— getTrackbarPos

这个函数用于获取当前轨迹条的位置并返回。

函数原型：
```C++
int getTrackbarPos(conststring& trackbarname, conststring& winname);
```

- 第一个参数，`const string&`类型的`trackbarname`，表示轨迹条的名字。
- 
- 第二个参数，`const string&`类型的`winname`，表示轨迹条的父窗口的名称。


<br>
<br>

## 亮度和对比度调整的理论依据

图像亮度和对比度的调整操作，属于图像处理变换中比较简单的一种——点操作（pointoperators）。
点操作有一个特点，仅仅根据输入像素值（有时可加上某些全局信息或参数），来计算相应的输出像素值。
这类算子包括亮度（brightness）和对比度（contrast）调整，以及颜色校正（colorcorrection）和变换（transformations）。

最两种常用的点操作（或者说点算子），很显然，是乘上一个常数（对应对比度的调节）以及加上一个常数（对应亮度值的调节）。

用公式表示出来就是这样：

$$
g(x) = a * f(x) + b
$$

- 参数f(x)表示源图像像素。
  
- 参数g(x) 表示输出图像像素。
  
- 参数a（需要满足a>0）被称为增益（gain），常常被用来控制图像的对比度。
  
- 参数b通常被称为偏置（bias），常常被用来控制图像的亮度。
  
<br>

而更近一步，我们这样改写这个式子：

$$
g(i,j) = a * f(i,j) + b
$$

其中，i 和 j 表示像素位于第i行 和 第j列 。


<br>
<br>

## 关于访问图片中的像素

为了执行上述式子，我们需要访问图像的每一个像素。

因为是对GBR图像进行运算，每个像素有三个值（G、B、R），所以我们必须分别访问它们。

以下是访问像素的代码片段，三个for循环解决问题：

```C++
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
```

- 为了访问图像的每一个像素，我们使用这样的语法： `image.at<Vec3b>(y,x)[c]`
  - 其中，y是像素所在的行， x是像素所在的列， c是R、G、B（对应0、1、2）其中之一。
  
- 因为我们的运算结果可能超出像素取值范围（溢出），还可能是非整数（如果是浮点数的话），所以我们要用`saturate_cast`对结果进行转换，以确保它为有效值。
  
- 这里的`a`也就是对比度，一般为了观察的效果，取值为0.0到3.0的浮点值。但是我们的轨迹条一般取值都会整数，所以可以将其代表对比度值的`nContrastValue`参数设为0到300之间的整型，在最后的式子中乘以一个0.01，这样就可以完成轨迹条中300个不同取值的变化。  
  所以在式子中，我们会看到`saturate_cast<uchar>( (g_nContrastValue*0.01)*(image.at<Vec3b>(y,x)[c] ) + g_nBrightValue )中的g_nContrastValue*0.01。`

