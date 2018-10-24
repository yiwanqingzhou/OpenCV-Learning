## OpenCV2的模块介绍

#### calib3d
  其实就是就是Calibration（校准）加3D这两个词的组合缩写。
  
  这个模块主要是相机校准和三维重建相关的内容。  
  基本的多视角几何算法，单个立体摄像头标定，物体姿态估计，立体相似性算法，3D信息的重建等等。

<br>

#### contrib
  也就是Contributed/Experimental Stuf的缩写。
  
  该模块包含了一些最近添加的不太稳定的可选功能，不用去多管。  
  2.4.8里的这个模块有新型人脸识别，立体匹配，人工视网膜模型等技术。

<br>

#### core
  核心功能模块，包含如下内容：
  - OpenCV基本数据结构
  - 动态数据结构
  - 绘图函数
  - 数组操作相关函数
  - 辅助功能与系统函数和宏
  - 与OpenGL的互操作

<br>  
  
#### imgproc
  Image和Processing这两个单词的缩写组合。
  
  图像处理模块，这个模块包含了如下内容：
  - 线性和非线性的图像滤波
  - 图像的几何变换
  - 其他(Miscellaneous)图像转换
  - 直方图相关
  - 结构分析和形状描述
  - 运动分析和对象跟踪
  - 特征检测
  - 目标检测等内容

<br>

#### features2d
  也就是Features2D，2D功能框架
  
  包含如下内容：
  - 特征检测和描述
  - 特征检测器 (Feature Detectors) 通用接口
  - 描述符提取器 (Descriptor Extractors) 通用接口
  - 描述符匹配器 (Descriptor Matchers) 通用接口
  - 通用描述符 (Generic Descriptor) 匹配器通用接口
  - 关键点绘制函数和匹配功能绘制函数
 
<br>
 
#### flann
  Fast Library for Approximate Nearest Nerighbors，高维的近似近邻快速搜索算法库

  包含两个部分：
  - 快速近似最近邻搜索
  - 聚类

<br>

#### gpu
  运用GPU加速的计算机视觉模块
  
<br>
  
#### highgui
  也就是high gui，高层GUI图像用户界面
  
  包含媒体的I/O输入输出，视频捕捉、图像和视频的编码解码、图形交互界面的接口等内容
  
<br>
  
#### legacy
  一些已经废弃的代码哭，保留下来作为向下兼容
  
  包含如下相关内容：
  - 运动分析
  - 期望最大化
  - 直方图
  - 平面细分 (C API)
  - 特征检测和描述 (Feature Detection and Description)
  - 描述符提取器 (Descriptor Extractors) 的通用接口
  - 通用描述符 (Generic Descriptor Matchers) 的常用接口
  - 匹配器
  
<br>

#### ML
  Machine Learning，机器学习模块，基本上是统计模型和分类算法
  
  包含如下内容：
  - 统计模型 Statistical Models
  - 一般贝叶斯分类器 Normal Bayes Classifier
  - K-近邻 K-NearestNeighbors
  - 支持向量机 Support Vector Machines
  - 决策树 Decision Trees
  - 提升 Boosting
  - 梯度提高树 Gradient Boosted Trees
  - 随机树 Random Trees
  - 超随机树 Extremely randomized trees
  - 期望最大化 Expectation Maximization
  - 神经网络 Neural Networks
  - MLData

<br>

#### nonfree
  一些具有专利的算法模块，包含特征检测和GPU相关的内容
  
<br>

#### objdetect
  目标检测模块
  
  包含 Cascade Classification（级联分类）和 Latent SVM 两个部分

<br>

#### ocl
  即OpenCL-accelerated Computer Vision，运用OpenCL加速的计算机视觉组件模块

<br>

#### photo
  也就是Computational Photography
  
  包含图像修复和图像去噪两部分
  
<br>

#### stitching
images stitching，图像拼接模块

包含如下部分：
- 拼接流水线
- 特点寻找和匹配图像
- 估计旋转
- 自动校准
- 图片歪斜
- 接缝估测
- 曝光补偿
- 图片混合

<br>

#### superres
SuperResolution，超分辨率技术的相关功能模块

<br>

#### ts

opencv测试相关代码，不用去管他

<br>

#### video
视频分析组件

该模块包括运动估计，背景分离，对象跟踪等视频处理相关内容。

<br>

#### videostab
Video stabilization，视频稳定相关的组件

官方文档中没有多作介绍，不管它了。



