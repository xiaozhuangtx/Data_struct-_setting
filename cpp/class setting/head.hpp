#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>
#include <limits>
#include <climits>
#include <algorithm>
#include <queue>
#include <cfloat>
#include <unordered_set>
#define MAXFILESIZE 50
using namespace std;

class ALGraph {
public:
    const char *FILENAME;
    ALGraph(const char *FILENAME); //析构函数
    
    auto cityGo ();  // 返回出发城市
    auto cityArrive ();  //返回到达城市
    int ifCityExist (const string & city_name);  // 查询城市是否存在
    void addLine(const string start_city_name, const string end_city_name, const Time start_time, const Time end_time, const Time spend_time, 
                 const float spend_money, const string rank);  // 手动添加线路
    // 删除线路，需要手动输入起点与终点
    void delLine(const std::string &startCity, const std::string &endCity, const std::string &rank);  

    void showAllCity();  // 输出所有城市
    void showAllLine();  // 输出所有线路

    // 判断是否能到达终点城市
    bool getAllPath(std::string current_city,std::string end_city,vector<vector<string>> &Allpath,vector<string>& path);
    // 打印从起点城市到终点城市，所有的线路
    void printPathsByCity (const std::string &sc, const std::string &ec);
        
    // 输出从起点城市到终点城市，花费最小的线路
    void printLeastMoneyPath (const std::string &start_city, const std::string &end_city);  

    // 输出从起点城市到终点城市，总时间最短的线路
    void printLeastTimePath (const std::string &sc, const std::string &ec);
        
    // 输出从起点城市到终点城市，中转次数最少的路径
    //     void printLeastTransferPath (const std::string &sc, const std::string &ec);  

    unordered_map<string, vector<LineNode>> graph;

};

class LineNode {  // 线路信息，作为边表的元素
public:
    std::string start_city_name; ///< 起始城市名称
    std::string end_city_name;   ///< 终点城市名称
    Time start_time;             ///< 起始时间
    Time end_time;               ///< 终点时间
    Time spend_time;             ///< 路程花费时间
    float spend_money;           ///< 花费金钱
    std::string rank;            ///< 火车或飞机的班次
    

    /**
     * @brief 构造函数，初始化 LineNode 对象。
     * @param scn 起始城市名称。
     * @param ecn 终点城市名称。
     * @param st 起始时间。
     * @param et 终点时间。
     * @param spend_t 路程花费时间。
     * @param spend_m 花费金钱。
     * @param amt 班次（火车或飞机）。
     */
    LineNode(const string scn, const string ecn, const Time st, const Time et, const Time spend_t, 
            const float spend_m, const string amt) 
            : start_city_name(scn), end_city_name(ecn), 
            start_time(st), end_time(et), spend_time(spend_t), spend_money(spend_m), rank(amt) {}
    LineNode() {}
};


class Vnode {  // 顶点表中的头结点，存储始发站的信息
public:
    Vnode (const string scn, const int cid) : start_city_name(scn), city_id(cid) {}
    Vnode (const char* scn, const int cid) : start_city_name(scn), city_id(cid) {}
    Vnode (const string scn) : start_city_name(scn), city_id(-1) {}
    Vnode (const char* scn) : start_city_name(scn), city_id(-1) {}
    
    string start_city_name;  // 地名
    int city_id;
};

class Time {
//时间格式: hour:minute,+day
public:
    int hour;
    int minute;
    int day;

    Time (const int h=0, const int min=0, const int d=0) : hour(h), minute(min), day(d) {}
    Time (const Time &obj) : hour(obj.hour), minute(obj.minute), day(obj.day) {}

    /**
     * @brief 交换两个 Time 对象的值。
     * @param lt 左侧 Time 对象。
     * @param rt 右侧 Time 对象。
     */
    void swap (Time &lt, Time &rt) {
        std::swap (lt.day, rt.day);
        std::swap (lt.hour, rt.hour);
        std::swap (lt.minute, rt.minute);
    }

    /**
     * @brief 赋值运算符重载，使用交换技巧实现。
     * @param other_obj 要赋值的 Time 对象。
     * @return 赋值后的当前对象的引用。
     */
    Time & operator = (Time other_obj) {
        swap(*this, other_obj);
        return *this;
    }

    /**
     * @brief 获取总时间
     * @return 返回总时间
    */
    int getTotalMintue () const {
        return this->day * 1440 + this->hour * 60 + this->minute;
    }
    
};