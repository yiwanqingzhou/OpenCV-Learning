# 关于Mat类型

`cv::Mat` 类是用于保存图像以及其他矩阵数据的数据结构。

默认情况下，其尺寸为0，我们也可以指定初始尺寸。
比如定义一个Mat类对象：

``` 
Mat M(3,2, CV_8UC3, Scalar(0, 0, 255));
cout << "M = " << endl << " " << M << endl;
```

其实用到Mat对象最简单的代码就是：
```
Mat img = imread("test.jpg");
```

<br>

### 常用的构造函数

- `Mat::Mat()`  
  无参数构造方法

- `Mat::Mat(int rows, int cols, int type)`  
  创建行数为 rows，列数为 col，类型为 type 的图像

- `Mat::Mat(Size size, int type)`  
  创建大小为 size，类型为 type 的图像

- `Mat::Mat(int rows, int cols, int type, const Scalar& s)`  
  创建行数为 rows，列数为 col，类型为 type 的图像，并将所有元素初始化为值 s

- `Mat::Mat(Size size, int type, const Scalar& s)`  
创建大小为 size,类型为 type 的图像，并将所有元素初始化为值 s

- `Mat::Mat(const Mat& m)`  
将 m 赋值给新创建的对象，此处不会对图像数据进行复制, m 和新对象共用图像数据

- `Mat::Mat(int rows, int cols, int type, void* data, size_t step=AUTO_STEP)`  
创建行数为 rows，列数为 col，类型为 type 的图像，此构造函数不创建图像数据所需内存，而是直接使用 data 所指内存，图像的行步长由 step指定

- `Mat::Mat(Size size, int type, void* data, size_t step=AUTO_STEP)`  
创建大小为 size，类型为 type 的图像，此构造函数不创建图像数据所需内存，而是直接使用 data 所指内存,图像的行步长由 step 指定

- `Mat::Mat(const Mat& m, const Range& rowRange, const Range& colRange)`  
创建的新图像为 m 的一部分，具体的范围由 rowRange 和 colRange 指定，此构造函数也不进行图像数据的复制操作，新图像与 m 共用图像数据

- `Mat::Mat(const Mat& m, const Rect& roi)`  
创建的新图像为 m 的一部分，具体的范围 roi 指定，此构造函数也不进行图像数据的复制操作,新图像与 m 共用图像数据

<br>


### 关于`type`

type 可以是 `CV_8UC1, CV_16SC1, ...,CV_64FC4` 等
  
- 里面的 `8U` 表示8位无符号整数，`16S` 表示16位有符号整数，`64F` 表示64位浮点数(即 `double` 类型)
  
- C 后面的数表示通道数，例如 `C1` 表示一个通道的图像，`C4` 表示4个通道的图像,以此类推

    - 如果需要更多的通道数,需要用宏 `CV_8UC(n)`
  
        ```C++
        Mat M(3,2, CV_8UC(5));
        ```
    - 有些 type 参数如 CV_32F 未注明通道数目，这种情况下它表示单通道

<br>

### `create()`函数创建对象

除了在构造函数中可以创建图像，也可以使用 Mat 类的 create()函数创建图像。

- 如果 create()函数指定的参数与图像之前的参数相同，则不进行实质的内存申请操作；

- 如果参数不同，则减少原始数据内存的索引,并重新申请内存。

```C++
Mat M(3,2, CV_8UC3, Scalar(0,0,255));

cout << "M = " << endl << " " << M << endl;
```

<br>

### Matlab 风格的创建对象方法

OpenCV 2 中提供了 Matlab 风格的函数,如 `zeros()，ones()`和 `eyes()`。

使用这些函数需要指定图像的大小和类型：

```C++
Mat Z = Mat::zeros(2,3, CV_8UC1);

cout << "Z = " << endl << " " << Z << endl;

Mat O = Mat::ones(2, 3, CV_32F);

cout << "O = " << endl << " " << O << endl;

Mat E = Mat::eye(2, 3, CV_64F);

cout << "E = " << endl << " " << E << endl;
```

