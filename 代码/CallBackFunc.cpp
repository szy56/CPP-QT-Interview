/*
    回调函数就是编程中一种反向调用的设计模式。
    核心逻辑是：定义一个函数，但不直接调用它，而是把这个函数的“地址/引用”传递给另一个函数/对象，由这个函数/对象在特定时机进行调用。
*/

#include<iostream>
#include<string>

//1.定义回调函数类型（函数指针）--约定函数签名
typedef void (*clickCallBack)(const std::string&);

class Button
{
private:
    clickCallBack callBack;
    std::string name;
public:
    Button(const std::string& btnName) : name(btnName), callBack(nullptr){}

    //接收外部传入函数地址
    void setCallBack(clickCallBack func)
    {
        callBack = func;
    }

    void click()
    {
        std::cout << "按钮【" << name << "】被点击了" << std::endl;
        //触发时机
        if(callBack != nullptr)
        {
            callBack(name);
        }
    }
};

//定义回调函数
void handleButtonClicked(const std::string& btnName)
{
    std::cout << "处理点击事件，按钮【" << btnName << "】的逻辑执行中..." << std::endl;
}

int main()
{
    Button okBtn("确认按钮");

    okBtn.setCallBack(handleButtonClicked);

    okBtn.click();

    return 0;
}

/*
    缺点：
        1.耦合度高。按钮类必须知道回调函数签名，比如示例中必须用void(*)(const string&)类型函数；
          且如果回调函数是某个类的成员函数，还需要传递实例指针，按钮类就会直接依赖于这个类。
        2.类型不安全。如果传入的函数签名不匹配，编译期可能只报警告，运行时直接崩溃。
        3.扩展能力差。一个按钮想出发多个回调函数，需要手动维护回调函数列表，自己写循环调用逻辑。
        4.跨线程处理复杂。需要手动处理线程切换、加锁等逻辑，极易出现线程安全问题。
*/