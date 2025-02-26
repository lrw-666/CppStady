#include <iostream>
using namespace std;
 
// 基类 Shape，表示形状
class Shape {
   protected:
      int width, height; // 宽度和高度
 
   public:
      // 构造函数，带有默认参数
      Shape(int a = 0, int b = 0) : width(a), height(b) { }
 
      // 虚函数 area，用于计算面积
      // 使用 virtual 关键字，实现多态
      virtual int area() {
         cout << "Shape class area: " << endl;
         return 0;
      }
};
 
// 派生类 Rectangle，表示矩形
class Rectangle : public Shape {
   public:
      // 构造函数，使用基类构造函数初始化 width 和 height
      Rectangle(int a = 0, int b = 0) : Shape(a, b) { }
 
      // 重写 area 函数，计算矩形面积
      int area() override { 
         cout << "Rectangle class area: " << endl;
         return width * height;
      }
};
 
// 派生类 Triangle，表示三角形
class Triangle : public Shape {
   public:
      // 构造函数，使用基类构造函数初始化 width 和 height
      Triangle(int a = 0, int b = 0) : Shape(a, b) { }
 
      // 重写 area 函数，计算三角形面积
      int area() override { 
         cout << "Triangle class area: " << endl;
         return (width * height / 2); 
      }
};
 
// 主函数：动态绑定
int main() {
   Shape *shape;           // 基类指针
   Rectangle rec(10, 7);   // 矩形对象
   Triangle tri(10, 5);    // 三角形对象
 
   // 将基类指针指向矩形对象，并调用 area 函数
   shape = &rec;
   cout << "Rectangle Area: " << shape->area() << endl;
 
   // 将基类指针指向三角形对象，并调用 area 函数
   shape = &tri;
   cout << "Triangle Area: " << shape->area() << endl;
 
   return 0;
}

/**父类与子类构造函数的关系
 * 1.如果父类有一个默认构造函数（即无参构造函数），子类的构造函数可以不显式调用父类的构造函数，编译器会自动调用父类的默认构造函数。
 * 2.如果父类没有默认构造函数，子类的构造函数必须调用父类的构造函数，否则编译器会报错(本例所示)。
 * 在子类的构造函数中，可以通过初始化列表显式调用父类的构造函数。
 * 这种方式更高效，因为它直接在对象构造时初始化父类成员，而不是先调用默认构造函数再赋值。
 */

 /**C++默认构造函数特征
  * 无参数：默认构造函数不接受任何参数。
  * 自动生成：如果程序员没有为类定义任何构造函数，编译器会自动生成一个默认构造函数。
  * 初始化成员：默认构造函数会按照以下规则初始化类的成员变量：
      * 对于内置类型（如int、float等），默认构造函数不会初始化它们，它们的值是未定义的。
      * 对于类类型成员，默认构造函数会调用它们的默认构造函数。
      * 对于指针类型，默认构造函数不会初始化它们，它们的值是未定义的。
  * 显式定义：程序员可以显式定义默认构造函数
  * 在C++中，如果显式定义了一个带参数的构造函数，系统不会自动生成默认构造函数（即无参构造函数）
  * 显式删除默认构造函数：可以使用= delete显式删除默认构造函数，防止对象被默认构造
  * class MyClass {
  * public:
  *     MyClass() = delete; // 删除默认构造函数
  * };
  * 
  * 显式默认构造函数：可以使用= default显式要求编译器生成默认构造函数
  * class MyClass {
  * public:
  *     MyClass() = default; // 显式要求编译器生成默认构造函数
  * };
  */