# beijing-weiguanghe-interview-qt

北京维广合交通安全信息科技有限公司的Qt面试项目题

当时在昆明市场还没有这么差，所以它工资给了我11.5K，被我拒了。

## Install Qt

- https://download.qt.io/archive/qt/5.12/5.12.12/

## Requirements

做一个qt demo (qt creator能加载的项目)

- 功能一、做一个"提升的窗口部件"，可命名为higerwidgetview，父类QWidget，该部件higerwidgetview内部布局包含4个label，两行两列自动调整大小，每个label赋值不同文字和底色。最终提供包含higerwidgetview.cpp higerwidgetview.h higerwidgetview.ui得项目给我们
我们可以在任意项目引用这三个文件后将任意窗口得某个widget提升至该higerwidgetview，实现该部件得展示效果

- 功能二、做一个"提升的窗口部件"，可命名为higerwatchview，父类QWidget，该部件可命名为higerwatchview绘制一个手表表盘,实现分针秒针即可，（可以参考网络上代码，不能照搬）。最终提供包含higerwatchview.cpp higerwatchview.h higerwatchview.ui得项目给我们
我们可以在任意项目引用这三个文件后将任意窗口得某个widget提升至该higerwatchview，实现该部件得展示效果

- 功能三、在上面的项目中通过按钮触发调用【get方式】"http://119.180.25.95:8088/videoServer/webCams"   将返回的结果显示到界面得一个label中,如果网络不通进行弹窗提示。

- 功能四、在上面的项目中用sqlite数据库实现一个添加、修改、删除和查询展示得窗口界面（字段不少于2个，且有一个blob字段存放图片或者其他二进制数据用），查询数据库在线程中执行，然后通过信号槽将数据传递给界面显示。

以上四个基本功能全部都要实现。必须在1-2天内完成。

## 为什么

为了完成这个Qt面试项目，我重度使用了chatGPT，在当时是使用GPT 3.5，那时候刚出没多久，github copilot 都还是Codex补全代码那种（不是现在的Codex cli），那时候没写C++有两年了，并且Qt更是四五年没写了，从零开始，借助对话式的chatGPT，也就花了3个小时就写完了，比较震惊。当然，现在是Coding Agent的时代了，只是纪念一下。


ChatGPT的对话历史记录: https://github.com/AlexiaChen/interview-qt-demos/issues/1 
