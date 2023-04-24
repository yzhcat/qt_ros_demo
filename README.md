# qt_ros_demo
a demo for ros and qt5 in ubuntu20.04 ros noetic

进入ros_qt_demo 文件夹，创建build文件夹
```shell
ros_ws01/src/ros_qt_demo$ tree
.
├── build
├── CMakeLists.txt
├── include
│   ├── mainwindow.h
│   └── rqnode.hpp
├── package.xml
├── resource
├── src
│   ├── main.cpp
│   └── mainwindow.cpp
└── ui
    └── mainwindow.ui
```
编译
```shell
cd build/
cmake ..
make
```

运行

ros_ws01/src/ros_qt_demo/build$
```shell
./ros_qt_demo
```
# preview
![2023-04-21_18-38](https://user-images.githubusercontent.com/33952798/233620873-a91bf43f-4caf-431a-b08d-591d4bc732b7.png)

![2023-04-21_18-44](https://user-images.githubusercontent.com/33952798/233621037-e2d03b61-28e2-4547-8826-80d29f70fa01.png)
