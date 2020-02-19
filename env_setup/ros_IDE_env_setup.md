# Environment Setup for ROS IDE

## 1. Pycharm

For python development

* Creat command-line launch and creat desktop entry
* `sudo gedit /usr/share/applications/jetbrains-pycharm.desktop`

   modify the Exec line: add `zsh -i -c` before `=`

* Choose python2.7 as pycharm interpreter and add `/opt/ros/kinetic/lib/python2.7/dist-packages` to the interpreter paths
* Test

    `import rospy`

## 2. CLion

For c++ development

* Creat command-line launch and creat desktop entry
* `sudo gedit ~/.local/share/applications/jetbrains-clion.desktop`

    modify the Exec line: add `zsh -i -c` before `=`

---

###  For Every Project

Go to `File | Settings | Build, Execution, Deployment | CMake` and change two fields:

* CMake options

    `-DCATKIN_DEVEL_PREFIX:PATH=/home/jian/catkin_ws/devel`

* Generation Path

    `/home/jian/catkin_ws/build`

* Build Options

    `-j12`

NOTE: replace `jian` with your user name

---

###  Code for C++ testing

`ros_begining`
