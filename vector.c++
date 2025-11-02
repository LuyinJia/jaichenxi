#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <memory>
#include <stdexcept>
#include <typeinfo>
#include <functional>

// 1. 命名空间示例
namespace MyNamespace {
    int add(int a, int b) {
        return a + b;
    }

    namespace NestedNamespace {
        int multiply(int a, int b) {
            return a * b;
        }
    }
}

// 2. 基础数据类型与常量
void basicTypes() {
    std::cout << "\n=== 基础数据类型 ===" << std::endl;
    
    // 基本内置类型
    bool b = true;
    char c = 'A';
    short s = 32767;
    int i = 100;
    long l = 100000L;
    long long ll = 10000000000LL;
    float f = 3.14f;
    double d = 3.1415926535;
    
    // 常量
    const int CONST_VALUE = 10;
    constexpr int COMPILE_CONST = 5 + 5;  // 编译期常量
    
    std::cout << "bool: " << b << ", char: " << c << ", int: " << i << std::endl;
    std::cout << "const int: " << CONST_VALUE << ", constexpr: " << COMPILE_CONST << std::endl;
}

// 3. 函数与函数重载
// 普通函数
int calculate(int a, int b) {
    return a + b;
}

// 函数重载（参数类型不同）
double calculate(double a, double b) {
    return a * b;
}

// 函数重载（参数数量不同）
int calculate(int a, int b, int c) {
    return a + b * c;
}

// 带默认参数的函数
void printInfo(std::string name, int age = 18) {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}

// 4. 类与对象基础
class Person {
private:  // 私有成员
    std::string name;
    int age;

public:  // 公有成员
    // 构造函数
    Person(std::string n, int a) : name(n), age(a) {  // 成员初始化列表
        std::cout << "Person构造函数被调用" << std::endl;
    }
    
    // 析构函数
    ~Person() {
        std::cout << "Person析构函数被调用" << std::endl;
    }
    
    // 成员函数
    void setName(std::string n) {
        name = n;
    }
    
    std::string getName() const {  // const成员函数（不修改成员变量）
        return name;
    }
    
    // 静态成员函数（属于类，不属于对象）
    static void printClassName() {
        std::cout << "This is Person class" << std::endl;
    }
};

// 5. 继承与多态
class Animal {
protected:  // 保护成员（子类可访问）
    std::string name;

public:
    Animal(std::string n) : name(n) {}
    
    // 虚函数（支持多态）
    virtual void makeSound() const {
        std::cout << "Animal makes sound" << std::endl;
    }
    
    // 纯虚函数（抽象类的标志）
    virtual void move() const = 0;
    
    virtual ~Animal() {  // 虚析构函数
        std::cout << "Animal析构函数" << std::endl;
    }
};

class Dog : public Animal {  // 公有继承
public:
    Dog(std::string n) : Animal(n) {}
    
    // 重写父类虚函数
    void makeSound() const override {  // override关键字确保重写正确
        std::cout << name << " barks: Woof!" << std::endl;
    }
    
    void move() const override {
        std::cout << name << " runs" << std::endl;
    }
    
    ~Dog() override {
        std::cout << "Dog析构函数" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(std::string n) : Animal(n) {}
    
    void makeSound() const override {
        std::cout << name << " meows: Meow!" << std::endl;
    }
    
    void move() const override {
        std::cout << name << " walks" << std::endl;
    }
};

// 6. 指针与引用
void pointerAndReference() {
    std::cout << "\n=== 指针与引用 ===" << std::endl;
    
    int x = 10;
    int* ptr = &x;  // 指针：存储变量地址
    int& ref = x;   // 引用：变量的别名（必须初始化，不能为null）
    
    std::cout << "x = " << x << ", *ptr = " << *ptr << ", ref = " << ref << std::endl;
    
    *ptr = 20;  // 通过指针修改值
    std::cout << "After *ptr = 20: x = " << x << ", ref = " << ref << std::endl;
    
    ref = 30;   // 通过引用修改值
    std::cout << "After ref = 30: x = " << x << ", *ptr = " << *ptr << std::endl;
    
    // 空指针
    int* nullPtr = nullptr;
    if (nullPtr == nullptr) {
        std::cout << "nullPtr is null" << std::endl;
    }
}

// 7. 动态内存管理
void dynamicMemory() {
    std::cout << "\n=== 动态内存管理 ===" << std::endl;
    
    // 原始指针（需手动释放）
    int* rawPtr = new int(100);  // 分配单个int
    std::cout << "rawPtr value: " << *rawPtr << std::endl;
    delete rawPtr;  // 释放内存
    
    // 动态数组
    int* arr = new int[5]{1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;  // 释放数组
    
    // 智能指针（自动管理内存）
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(200);  // 独占所有权
    std::cout << "uniquePtr value: " << *uniquePtr << std::endl;
    
    std::shared_ptr<std::string> sharedPtr1 = std::make_shared<std::string>("shared");
    std::shared_ptr<std::string> sharedPtr2 = sharedPtr1;  // 共享所有权
    std::cout << "sharedPtr use count: " << sharedPtr1.use_count() << std::endl;
}

// 8. 模板（函数模板与类模板）
// 函数模板
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// 类模板
template <typename T, typename U>
class Pair {
private:
    T first;
    U second;

public:
    Pair(T f, U s) : first(f), second(s) {}
    
    void print() const {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }
};

// 模板特化
template <>
class Pair<std::string, int> {
private:
    std::string first;
    int second;

public:
    Pair(std::string f, int s) : first(f), second(s) {}
    
    void print() const {
        std::cout << "Specialized Pair: Name=" << first << ", Age=" << second << std::endl;
    }
};

// 9. STL容器与算法
void stlDemo() {
    std::cout << "\n=== STL容器与算法 ===" << std::endl;
    
    // 向量（动态数组）
    std::vector<int> vec = {3, 1, 4, 1, 5};
    std::cout << "Vector elements: ";
    for (int num : vec) {  // 范围for循环
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // 排序算法
    std::sort(vec.begin(), vec.end());
    std::cout << "Sorted vector: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {  // 迭代器
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // 列表（双向链表）
    std::list<std::string> lst = {"apple", "banana", "cherry"};
    lst.push_back("date");
    std::cout << "List elements: ";
    for (const auto& s : lst) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    
    // 映射（键值对）
    std::map<int, std::string> mp;
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    std::cout << "Map elements: ";
    for (const auto& pair : mp) {
        std::cout << "(" << pair.first << ":" << pair.second << ") ";
    }
    std::cout << std::endl;
    
    // 集合（有序唯一元素）
    std::set<int> st = {5, 2, 7, 2, 5};
    std::cout << "Set elements: ";
    for (int num : st) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // 队列（先进先出）
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    std::cout << "Queue front: " << q.front() << ", back: " << q.back() << std::endl;
    q.pop();
    std::cout << "After pop, front: " << q.front() << std::endl;
    
    // 栈（后进先出）
    std::stack<int> sk;
    sk.push(100);
    sk.push(200);
    sk.push(300);
    std::cout << "Stack top: " << sk.top() << std::endl;
    sk.pop();
    std::cout << "After pop, top: " << sk.top() << std::endl;
}

// 10. 异常处理
void exceptionDemo() {
    std::cout << "\n=== 异常处理 ===" << std::endl;
    
    try {
        int divisor = 0;
        if (divisor == 0) {
            throw std::runtime_error("Division by zero");  // 抛出异常
        }
        int result = 100 / divisor;
    }
    catch (const std::runtime_error& e) {  // 捕获特定异常
        std::cout << "Caught runtime error: " << e.what() << std::endl;
    }
    catch (...) {  // 捕获所有异常
        std::cout << "Caught unknown exception" << std::endl;
    }
}

// 11. 现代C++特性
void modernCppFeatures() {
    std::cout << "\n=== 现代C++特性 ===" << std::endl;
    
    // auto：自动类型推导
    auto num = 100;
    auto str = "modern C++";
    auto vec = std::vector<float>{1.1f, 2.2f, 3.3f};
    std::cout << "auto variables: " << num << ", " << str << std::endl;
    
    // decltype：推导表达式类型
    decltype(num) anotherNum = 200;
    std::cout << "decltype variable: " << anotherNum << std::endl;
    
    // Lambda表达式
    auto addLambda = [](int a, int b) { return a + b; };
    std::cout << "Lambda add: " << addLambda(5, 3) << std::endl;
    
    // 带捕获的lambda
    int x = 10;
    auto captureLambda = [x](int y) { return x + y; };
    std::cout << "Captured lambda: " << captureLambda(5) << std::endl;
}

// 12. 类型转换
void typeCasting() {
    std::cout << "\n=== 类型转换 ===" << std::endl;
    
    // static_cast：编译期类型转换
    int i = 10;
    double d = static_cast<double>(i) / 3;
    std::cout << "static_cast: " << d << std::endl;
    
    // const_cast：去除const属性
    const int* constPtr = &i;
    int* nonConstPtr = const_cast<int*>(constPtr);
    *nonConstPtr = 20;
    std::cout << "After const_cast: i = " << i << std::endl;
    
    // dynamic_cast：运行期多态类型转换
    Animal* animal = new Dog("Buddy");
    Dog* dog = dynamic_cast<Dog*>(animal);
    if (dog) {
        std::cout << "dynamic_cast to Dog successful" << std::endl;
    }
    delete animal;
}

int main() {
    std::cout << "=== C++ 核心知识点综合示例 ===" << std::endl;
    
    // 调用各知识点演示函数
    basicTypes();
    
    // 函数演示
    std::cout << "\n=== 函数与重载 ===" << std::endl;
    std::cout << "calculate(2, 3) = " << calculate(2, 3) << std::endl;
    std::cout << "calculate(2.5, 3.5) = " << calculate(2.5, 3.5) << std::endl;
    std::cout << "calculate(2, 3, 4) = " << calculate(2, 3, 4) << std::endl;
    printInfo("Alice");
    printInfo("Bob", 25);
    
    // 类与对象演示
    std::cout << "\n=== 类与对象 ===" << std::endl;
    Person person("Charlie", 30);
    std::cout << "Person name: " << person.getName() << std::endl;
    Person::printClassName();
    
    // 继承与多态演示
    std::cout << "\n=== 继承与多态 ===" << std::endl;
    Animal* animals[] = {new Dog("Buddy"), new Cat("Whiskers")};
    for (Animal* animal : animals) {
        animal->makeSound();
        animal->move();
        delete animal;  // 多态析构
    }
    
    pointerAndReference();
    dynamicMemory();
    
    // 模板演示
    std::cout << "\n=== 模板 ===" << std::endl;
    std::cout << "maxValue(5, 10) = " << maxValue(5, 10) << std::endl;
    std::cout << "maxValue(3.14, 2.71) = " << maxValue(3.14, 2.71) << std::endl;
    
    Pair<int, std::string> pair1(1, "one");
    pair1.print();
    
    Pair<std::string, int> pair2("Alice", 25);  // 使用特化版本
    pair2.print();
    
    stlDemo();
    exceptionDemo();
    modernCppFeatures();
    typeCasting();
    
    // 命名空间使用
    std::cout << "\n=== 命名空间 ===" << std::endl;
    std::cout << "MyNamespace::add(2, 3) = " << MyNamespace::add(2, 3) << std::endl;
    std::cout << "MyNamespace::NestedNamespace::multiply(2, 3) = " 
              << MyNamespace::NestedNamespace::multiply(2, 3) << std::endl;
    

              
    return 0;
}