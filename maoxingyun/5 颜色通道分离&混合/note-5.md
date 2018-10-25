# 分离颜色通道&多通道图像混合

为了更好的观察一些图像材料的特征，有时需要对RGB三个颜色通道的分量进行分别显示和调整。

通过OpenCV的```split```和```merge```方法可以很方便的达到目的。

<br>


## split

将一个多通道数组分离成几个单通道数组

这个split函数的C++版本有两个原型，他们分别是：

```C++
void split(const Mat& src, Mat* mvbegin);

void split(InputArray m, OutputArrayOfArrays mv);
```

- 第一个参数，```InputArray```类型的m或者```const Mat&```类型的src，填我们需要进行分离的多通道数组。
- 第二个参数，```OutputArrayOfArrays```类型的```mv```，填函数的输出数组或者输出的```vector```容器。


```split``` 函数分割多通道数组转换成独立的单通道数组，按公式来看就是这样：

$$
    mv[c](I) = src(I)_c
$$

<br>

分割后的通道，一半共其中的 ```Mat::at()``` 方法对某个通道进行存取，也就是这样用 ```channels.at(0)```。  
值得注意的是，```Mat::at()``` 方法返回一个**引用**到指定的数组元素。由于是引用，相当于两者等价，修改其中一个另一个也会跟着改变。

示例：

```C++
Mat M1(3,2, CV_8UC3, Scalar(10,10,10));
Mat M2(3,2, CV_8UC1, Scalar(50));
vector<Mat> channels;
split(M1,channels);


Mat M1ROI = channels.at(0);
addWeighted(M1ROI, 0.3, M2, 0.5, 0., M1ROI);

cout << "M1ROI = " << endl << M1ROI << endl;
cout << "channels0 = " << endl << channels.at(0) << endl;
cout << "channels1 = " << endl << channels.at(1) << endl;
cout << "channels2 = " << endl << channels.at(2) << endl;

merge(channels, M1);
cout << "M1 = " << endl << M1 << endl;
```

*如果我们需要从多通道数组中提取出特定的单通道数组，或者说实现一些复杂的通道组合，可以使用```mixChannels()函数```。*

<br>

## merge
```merge()``` 函数的功能是 ```split()``` 函数的逆向操作，将多个数组组合合并成一个多通道的数组。

它通过组合一些给定的单通道数组，将这些孤立的单通道数组合并成一个多通道的数组，从而创建出一个由多个单通道阵列组成的多通道阵列。它有两个基于C++的函数原型：

```C++
void merge(const Mat* mv, size_tcount, OutputArray dst)

void merge(InputArrayOfArrays mv,OutputArray dst)
```

- 第一个参数，```mv```，填需要被合并的输入矩阵或```vector```容器的阵列，这个```mv```参数中所有的矩阵必须有着一样的尺寸和深度。
- 第二个参数，```count```，当```mv```为一个空白的C数组时，代表输入矩阵的个数，这个参数显然必须大于1.
- 第三个参数，```dst```，即输出矩阵，和```mv[0]```拥有一样的尺寸和深度，并且通道的数量是矩阵阵列中的通道的总数。
 

