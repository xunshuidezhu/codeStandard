## UMShip
### UMSHIP is a project based on the ROS
## 开发标准及规范:
### 1.命名采用下划线命名法，节点命名采用node开头比如，node_lidarmsg_send，topic命名采用topic开头，比如topic_lidarmsg_send
### 2.相对独立的程序块之间、变量说明之后必须加空行。
### 说明 ：
### 以下情况应该是用空行分开：
### 1）函数之间应该用空行分开；
### 2）变量声明应尽可能靠近第一次使用处，避免一次性声明一组没有马上使用的变量；
### 3）用空行将代码按照逻辑片断划分；
### 4）每个类声明之后应该加入空格同其他代码分开。
### 3.一行代码只定义一个变量，不要定义多个变量，比如 int age = 20, sex = 1; 应该分成两行定义
### 4.每个文件开头需要注释，包括代码的主要功能，创建的节点名称，订阅/发布的topic，使用的msg文件，代码创建者信息：包括姓名及时间。
### 比如：
### @author:张三 
### @time:2019/6/17
### @theme:雷达数据发送
### @node:node_lidarmsg_send 
### @topic:pub--topic_lidarmsg_send
### 5.每个类后面需要加注释说明该类的主要数据成员，函数功能，如果是接口类（抽象类）需要说明该类需要重载
### 6.用组合代替继承
### 比如:
```cpp
继承demo:
class base 
{
public:
	virtual void foo(){...}
};
class derived : public base
{
public:
	void foo(){...}
};
应该为
组合demo:
class base
{
public:
	void foo(){...}
};
class derived
{
public:
	void foo(const base&){...}
};
```
## 开发环境及注意事项：
### ubuntu16 + ros kinetic作为基本开发环境，推荐使用vscode或者robware作为开发工具，如果使用vscode作为开发工具，为了实现代码跳转可以使用命令行编译:
### catkin_make -DCMAKE_EXPORT_COMPILE_COMMANDS=Yes， 这个命令会输出一个compile_commands.json文件在ROS工作空间的build文件夹下面，然后在c_cpp_properties.json文件添加下面一段话：
### "compileCommands": "${workspaceFolder}/build/compile_commands.json"即可实现代码跳转
#### (后续如果需要远程登陆服务器开发（比如ssh连接开发机），需要掌握vim或者emacs进行开发 )