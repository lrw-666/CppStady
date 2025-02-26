#include <iostream>
#include <vector>

/**
 * vector 是 C++ 标准模板库（STL）的一部分，提供了灵活的接口和高效的操作。
 * 基本特性:
 * 动态大小：vector 的大小可以根据需要自动增长和缩小。
 * 连续存储：vector 中的元素在内存中是连续存储的，这使得访问元素非常快速。
 * 可迭代：vector 可以被迭代，你可以使用循环（如 for 循环）来访问它的元素。
 * 元素类型：vector 可以存储任何类型的元素，包括内置类型、对象、指针等 */

int main() {
    // 创建一个空的整数向量
    std::vector<int> myVector;

    // 添加元素到向量中
    myVector.push_back(3);
    myVector.push_back(7);
    myVector.push_back(11);
    myVector.push_back(5);

    // 访问向量中的元素并输出
    std::cout << "Elements in the vector: ";
    for (int element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 访问向量中的第一个元素并输出
    std::cout << "First element: " << myVector[0] << std::endl;

    // 访问向量中的第二个元素并输出
    std::cout << "Second element: " << myVector.at(1) << std::endl;

    // 获取向量的大小并输出
    std::cout << "Size of the vector: " << myVector.size() << std::endl;

    // 删除向量中的第三个元素
    myVector.erase(myVector.begin() + 2);

    // 输出删除元素后的向量
    std::cout << "Elements in the vector after erasing: ";
    for (int element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 清空向量并输出
    myVector.clear();
    std::cout << "Size of the vector after clearing: " << myVector.size() << std::endl;

    return 0;
}