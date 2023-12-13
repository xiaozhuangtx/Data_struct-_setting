#include <iostream>
#include <map>

// 假设有一个结构体 Vnode
struct Vnode {
    std::string start_city_name;

    // 其他成员...

    // 构造函数
    Vnode(const std::string& name) : start_city_name(name) {}
};

// 定义比较规则的结构体
struct cmp_vnode {
    bool operator() (const Vnode& x, const Vnode& k) const {
        return x.start_city_name >= k.start_city_name;
    }
};

int main() {
    // 使用定义的比较规则创建 map
    std::map<Vnode, int, cmp_vnode> myMap;

    // 向 map 中插入数据
    myMap[Vnode("New York")] = 1;
    myMap[Vnode("Tokyo")] = 2;
    myMap[Vnode("London")] = 3;

    // 遍历 map，按照 start_city_name 升序输出
    for (const auto& pair : myMap) {
        std::cout << "Start City: " << pair.first.start_city_name << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
