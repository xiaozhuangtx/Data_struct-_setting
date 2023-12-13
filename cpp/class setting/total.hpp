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
#include <cfloat>

#define MAXFILESIZE 50
using namespace std;



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

/**
 * @brief 重载小于运算符 (<) 用于比较两个 Time 对象。
 * @param t1 左侧 Time 对象。
 * @param t2 右侧 Time 对象。
 * @return 如果 t1 小于 t2，则返回 true；否则返回 false。
 *
 * 该比较基于两个 Time 对象的总分钟数，用于在排序和比较中确定时间的先后顺序。
 */
bool operator < (Time t1, Time t2) {
    return (t1.getTotalMintue() < t2.getTotalMintue());
}

bool operator >= (Time t1, Time t2) {
    return (t1.getTotalMintue() >= t2.getTotalMintue());
}

/**
 * @brief 重载减法运算符 (-) 用于计算两个 Time 对象的时间差。
 * @param t1 减法操作的左侧 Time 对象，表示被减数。
 * @param t2 减法操作的右侧 Time 对象，表示减数。
 * @return 返回一个新的 Time 对象，表示 t1 减去 t2 的时间差。
 * @note 默认情况下，要求 t1 晚于等于 t2，否则将抛出 runtime_error 异常。
 */
Time operator - (Time t1, Time t2){
    // Time 对象的减法重载，实现两 Time 对象的时间差计算

    // 使用 getTotalMintue 函数简化获取总分钟数的操作
    if (t1 < t2) {
        throw runtime_error ("Time Operator - 运算中 t1 小于 t2，结果将是负数!");
    }

    // 创建临时 Time 对象用于存储计算结果
    Time tmp_t;

    // 计算分钟差值
    tmp_t.minute = t1.getTotalMintue() - t2.getTotalMintue();
    if (tmp_t.minute < 0) {
        // 处理分钟借位
        tmp_t.minute += 60;
        --tmp_t.hour;
    }

    // 计算小时差值
    tmp_t.hour += t1.hour - t2.hour;
    if (tmp_t.hour < 0) {
        // 处理小时借位
        tmp_t.hour += 24;
        --tmp_t.day;
    }

    // 计算天数差值
    tmp_t.day += t1.day - t2.day;

    // 返回计算结果
    return tmp_t;
}

/**
 * @brief 重载输入流运算符 (>>) 用于从输入流中读取 Time 对象的值。
 * @param in 输入流对象，表示从中读取数据。
 * @param time 输入的 Time 对象，接收从输入流中读取的时间值。
 * @return 返回输入流对象，以支持链式输入。
 * @note 期望输入的格式为 "hour:minute,+day"，例如 "12:30,+1" 表示 12点30分第二天。
 */
istream & operator >> (istream &in, Time &time) {
    // '>>' 重载，实现从输入流中读取 Time 对象的值
    // 期望输入的格式为 "hour:minute,+day"

    char c1, c2, c3;
    int hour, minute, day;

    // 从输入流中读取小时、分钟和天数
    in >> hour >> c1 >> minute >> c2 >> c3 >> day;

    // 将读取的值赋给 Time 对象的成员变量
    time.day = day;
    time.minute = minute;
    time.hour = hour;

    // 返回输入流对象，以支持链式输入
    return in;
}

/**
 * @brief 重载输出流运算符 (<<) 用于美化输出 Time 对象的值。
 * @param out 输出流对象，表示将数据输出到该流中。
 * @param time 输出的 Time 对象，包含要输出的时间值。
 * @return 返回输出流对象，以支持链式输出。
 * @note 输出格式为 "hour:minute,+day"，例如 "12:30,+1" 表示 12点30分第二天。
 */
ostream & operator << (ostream &out, const Time &time) {
    // 运算符 '<<' 重载以美化 Time 对象的输出

    // 使用 '0' 填充数据之间的空白
    out.fill('0');

    // 将小时和分钟右对齐，并在天数前显示 '+' 号
    out << setw(2) << setiosflags(ios_base::right) << time.hour << ":" 
        << setw(2) << time.minute << resetiosflags(ios_base::right) 
        << "," << setiosflags(ios_base::showpos) << time.day << resetiosflags(ios_base::showpos);

    out.fill(' ');  // 手动关闭 fill setiosflags

    // 返回输出流对象，以支持链式输出
    return out;
}


//////////////////////////////////////// 以上是对Time相关操作的重载 ////////////////////////////////////////



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


//运算符'<<'重载以美化 LineNode 对象的输入, 搬运到其他位置
ostream & operator << (ostream &out, const LineNode &line) {
    return out;
} 



class ALGraph {
public:
    const char *FILENAME;
    ALGraph(const char *FILENAME);

    auto cityGo ();  // 返回出发城市
    auto cityArrive ();  //返回到达城市
    int ifCityExist (const string & city_name);  // 查询城市是否存在
    void addLine(const string start_city_name, const string end_city_name, const Time start_time, const Time end_time, const Time spend_time, 
                 const float spend_money, const string rank);  // 手动添加线路
    // 删除线路，需要手动输入起点与终点
    void delLine(const std::string &startCity, const std::string &endCity, const std::string &rank);  

    void showAllCity();  // 输出所有城市
    void showAllLine();  // 输出所有线路

    // 输出从起点城市到终点城市，花费最小的线路
    float dfs_for_mp(string currentCity, string end_city, vector<string>& path, double& minPrice, vector<string>& minPath, double currentPrice,vector<string>& ranklist,string Rank);
    void printLeastMoneyPath (const std::string &start_city, const std::string &end_city);  

    //     // 返回从起点城市到终点城市的所有路径
    //     std::vector<std::vector<LineNode>> getPathsByCity (const std::string &sc, const std::string &ec);

    //     // 打印从起点城市到终点城市的所有路径
    //     void printPathsByCity (const std::string &sc, const std::string &ec);
        
    //     // 输出从起点城市到终点城市，中转次数最少的路径
    //     void printLeastTransferPath (const std::string &sc, const std::string &ec);  
        


    // 输出从起点城市到终点城市，总时间最短的线路
    float dfs_for_mt(string currentCity, string end_city, vector<string>& path, double& minPrice, vector<string>& minPath, double currentPrice);
    void printLeastTimePath (const std::string &sc, const std::string &ec);
        

    //     // 通过起点城市、终点城市、班次，查询一条线路信息
    //     std::vector<LineNode> getLineNode (const std::string sc, const std::string ec, const std::string amt);

private:
    unordered_map<string, vector<LineNode>> graph;


};


