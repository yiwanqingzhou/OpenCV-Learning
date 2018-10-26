# 图像的载入和显示

在OpenCV2中，最简单的图像载入和显示只需要3句代码，非常便捷。这三句代码分别对应了三个函数，他们分别是：

	imread( ) namedWindow( ) imshow( )
    
<br>

## imread
**用于载入图片**

官方文档API：
```
Mat imread(const string& filename, intflags = 1 );
```  
#### filename

第一个参数，`const string&`类型的`filename`，填需要载入的图片路径名。

<br>

#### flags

第二个参数`flags`为载入标识，它指定一个加载图像的颜色类型。  

可以看到它自带缺省值1，表示载入三通道的彩色图像（RGB）。  
可以在OpenCV中标识图像格式的枚举体中取值。

```C++
enum
{
/* 8bit, color or not */
   CV_LOAD_IMAGE_UNCHANGED  =-1,
/* 8bit, gray */
   CV_LOAD_IMAGE_GRAYSCALE  = 0,
/* ?, color */
   CV_LOAD_IMAGE_COLOR      = 1,
/* any depth, ? */
   CV_LOAD_IMAGE_ANYDEPTH   = 2,
/* ?, any color */
   CV_LOAD_IMAGE_ANYCOLOR   = 4
};
```

如果输入有冲突的标志，将采用较小的数字值。  
因为`flags`是`int`型的变量，如果我们不在这个枚举体中取值的话，还可以这样来：

$flags >0$  返回一个3通道的彩色图像。  
$flags =0$  返回灰度图像。  
$flags <0$  返回包含Alpha通道的加载的图像。  

<br>

#### 示例   
```C++
Mat image0=imread("dota.jpg",CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR); //载入最真实的图像

Mat image1=imread("dota.jpg",0);   //载入灰度图

Mat image2=imread("dota.jpg",199); //载入3通道的彩色图像

Mat logo=imread("dota_logo.jpg");  //载入3通道的彩色图像
```

<br>


## namedWindow

**用于创建一个窗口**

`namedWindow` 函数的作用是，通过指定的名字，创建一个可以作为图像和进度条的容器窗口。  
如果具有相同名称的窗口已经存在，则函数不做任何事情。

<br>

官方文档API：
```
void namedWindow(const string& winname,int flags = WINDOW_AUTOSIZE ); 
```

<br>

#### winname

第一个参数，`const string&`型的`name`，填被用作窗口的标识符的窗口名称。

<br>

#### flags
窗口的标识，可以填如下的值：

`WINDOW_NORMAL` 设置了这个值，用户便可以改变窗口的大小（没有限制）  
`WINDOW_AUTOSIZE` 如果设置了这个值，窗口大小会自动调整以适应所显示的图像，并且不能手动改变窗口大小  
`WINDOW_OPENGL`  如果设置了这个值的话，窗口创建的时候便会支持OpenGL  

需要注意的是，它有默认值 `WINDOW_AUTOSIZE`。

<br>

#### 关闭

我们可以调用 `destroyWindow()` 或者 `destroyAllWindows()` 函数来关闭窗口，并取消之前分配的与窗口相关的所有内存空间。

但其实对于代码量不大的简单小程序来说，我们完全没有必要手动调用上述的函数。  
因为在退出时，所有的资源和应用程序的窗口会被操作系统会自动关闭。

<Br>

## imshow

**在指定的窗口中显示一幅图像**

官方文档API：
```
void imshow(const string& winname, InputArray mat);
```

- `winname` 填需要显示的窗口标识名称

- `mat` 填需要显示的图像

<br>

`imshow` 函数用于在指定的窗口中显示图像。

- 如果窗口是用 `CV_WINDOW_AUTOSIZE`（默认值）标志创建的，那么显示图像原始大小。  否则，将图像进行缩放以适合窗口。

- 而imshow 函数缩放图像，取决于图像的深度：  
	- 如果载入的图像是8位无符号类型(`8-bit unsigned`)，就显示图像本来的样子。  
	- 如果图像是16位无符号类型(`16-bit unsigned`)或32位整型(`32-bit integer`)，便用像素值除以256。也就是说，值的范围是[0,255 x 256]映射到[0,255]。  
	- 如果图像是32位浮点型(`32-bit floating-point`)，像素值便要乘以255。也就是说，该值的范围是[0,1]映射到[0,255]。

- 若窗口创建 (namedWindow函数) 的时候，如果设定了支持OpenGL (WINDOW_OPENGL)，那么imshow还支持 `ogl::Buffer, ogl::Texture2D` 以及 `gpu::GpuMat` 作为输入。

<br>

## imwrite
**输出图像到文件**

官方文档API：
```
bool imwrite(const string& filename,InputArray img, const vector<int>& params=vector<int>() );
```

#### filename
填需要写入的文件名就行了，带上后缀，比如，“123.jpg”这样

#### img
一般填一个Mat类型的图像数据就行了

#### params
表示为特定格式保存的参数编码，它有默认值 `vector<int>()`，所以一般情况下不需要填写。

而如果要填写的话，有下面这些需要了解的地方：
- 对于JPEG格式的图片，这个参数表示从0到100的图片质量 `(CV_IMWRITE_JPEG_QUALITY)`，默认值是95.
- 对于PNG格式的图片，这个参数表示压缩级别` (CV_IMWRITE_PNG_COMPRESSION)` 从0到9。较高的值意味着更小的尺寸和更长的压缩时间，而默认值是3。
- 对于PPM，PGM，或PBM格式的图片，这个参数表示一个二进制格式标志 `(CV_IMWRITE_PXM_BINARY)`，取值为0或1，而默认值是1。

