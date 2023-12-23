﻿#include <iostream>
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
// #include <try_myrepo.hpp>


class Time {
    //时间格式: hour:minute,+day
public:
    int hour;
    int minute;
    int day;

    Time(const int h = 0, const int min = 0, const int d = 0) : hour(h), minute(min), day(d) {}
    Time(const Time& obj) : hour(obj.hour), minute(obj.minute), day(obj.day) {}

    /**
     * @brief 交换两个 Time 对象的值。
     * @param lt 左侧 Time 对象。
     * @param rt 右侧 Time 对象。
     */
    void swap(Time& lt, Time& rt) {
        std::swap(lt.day, rt.day);
        std::swap(lt.hour, rt.hour);
        std::swap(lt.minute, rt.minute);
    }

    /**
     * @brief 赋值运算符重载，使用交换技巧实现。
     * @param other_obj 要赋值的 Time 对象。
     * @return 赋值后的当前对象的引用。
     */
    Time& operator = (Time other_obj) {
        swap(*this, other_obj);
        return *this;
    }

    /**
     * @brief 获取总时间
     * @return 返回总时间
    */
    int getTotalMintue() const {
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
Time operator - (Time t1, Time t2) {
    // Time 对象的减法重载，实现两 Time 对象的时间差计算

    // 使用 getTotalMintue 函数简化获取总分钟数的操作
    if (t1 < t2) {
        throw runtime_error("Time Operator - 运算中 t1 小于 t2，结果将是负数!");
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
istream& operator >> (istream& in, Time& time) {
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
ostream& operator << (ostream& out, const Time& time) {
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
    Vnode(const string scn, const int cid) : start_city_name(scn), city_id(cid) {}
    Vnode(const char* scn, const int cid) : start_city_name(scn), city_id(cid) {}
    Vnode(const string scn) : start_city_name(scn), city_id(-1) {}
    Vnode(const char* scn) : start_city_name(scn), city_id(-1) {}

    string start_city_name;  // 地名
    int city_id;
};


//运算符'<<'重载以美化 LineNode 对象的输入, 搬运到其他位置
ostream& operator << (ostream& out, const LineNode& line) {
    return out;
}



class ALGraph {
public:
    const char* FILENAME;
    ALGraph(const char* FILENAME)
    {
        this->FILENAME = FILENAME;
        ifstream inFile(this->FILENAME);
        string line;

        // 检查文件是否成功打开
        if (!inFile.is_open()) {
            std::cerr << "无法打开文件\n";
            return;
        }

        // 读取文件的第一行，假设它包含标题或其他不需要的信息
        std::getline(inFile, line);
        std::istringstream iss(line);

        // 从文件的每一行过滤符合条件的线路信息
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            LineNode currentLine;

            // 读取当前行的线路信息
            iss >> currentLine.start_city_name >> currentLine.end_city_name >> currentLine.rank
                >> currentLine.start_time >> currentLine.end_time >> currentLine.spend_time
                >> currentLine.spend_money;

            // 传入到graph
            graph[currentLine.start_city_name].push_back(currentLine);
        }
    }

    auto cityGo();  // 返回出发城市
    auto cityArrive();  //返回到达城市
    int ifCityExist(const string& city_name);  // 查询城市是否存在
    void addLine(const string start_city_name, const string end_city_name, const Time start_time, const Time end_time, const Time spend_time,
        const float spend_money, const string rank);  // 手动添加线路
    // 删除线路，需要手动输入起点与终点
    void delLine(const std::string& startCity, const std::string& endCity, const std::string& rank);

    void showAllCity();  // 输出所有城市
    void showAllLine();  // 输出所有线路

    // 判断是否能到达终点城市
    bool getAllPath(std::string current_city, std::string end_city, vector<vector<string>>& Allpath, vector<string>& path);
    // 打印从起点城市到终点城市，所有的线路
    void printPathsByCity(const std::string& sc, const std::string& ec);
    void getinfofromPath(vector<string> path, vector<string>& ranklist, vector<Time>& STList, vector<Time>& ETList, vector<float>& spend_money_list);
    // 输出从起点城市到终点城市，花费最小的线路
    void printLeastMoneyPath(const std::string& start_city, const std::string& end_city);

    // 输出从起点城市到终点城市，总时间最短的线路
    void printLeastTimePath(const std::string& start_city, const std::string& end_city);

    // 输出从起点城市到终点城市，中转次数最少的路径
    void printLeastTransferPath(const std::string& start_city, const std::string& end_city);

    unordered_map<string, vector<LineNode>> graph;

};
void ALGraph::printLeastTransferPath(const std::string& start_city, const std::string& end_city) {
    vector<string> path;
    vector<float> spend_money_list_temp;
    vector<string> ranklist_temp;
    vector<Time> STList_temp;
    vector<Time> ETList_temp;
    vector<vector<string>> Allpath;
    getAllPath(start_city, end_city, Allpath, path);
    //找出所有路径中中转次数最少的路径  Allpath 为所有能到达终点城市的路径
    int min_transfer = INT_MAX;
    for (int i = 0; i <= Allpath.size() - 1; i++)
    {
        vector<float> spend_money_list;
        vector<string> ranklist;
        vector<Time> STList;
        vector<Time> ETList;
        getinfofromPath(Allpath[i], ranklist, STList, ETList, spend_money_list);
        int temp = 0;
        for (int j = 0; j < Allpath[i].size() - 2; j++)
        {
            if (ranklist[j] != ranklist[j + 1])
            {
                temp++;
            }
        }
        if (temp < min_transfer)
        {
            min_transfer = temp;
            path = Allpath[i];
            spend_money_list_temp = spend_money_list;
            ranklist_temp = ranklist;
            STList_temp = STList;
            ETList_temp = ETList;
        }
    }
    //打印最少中转次数的路径
    cout << "最少中转次数的路径为：" << endl;
    for (int i = 0; i < path.size() - 2; i++) //path.size()-1 为路径的长度 i不能取到path.size()-1 否则会越界
    {
        STList_temp[i + 1].day = STList_temp[i].day;
        ETList_temp[i + 1].day = ETList_temp[i].day;
        if (ETList_temp[i] >= STList_temp[i + 1])
        {
            STList_temp[i + 1].day += 1;
            ETList_temp[i + 1].day += 1;
        }
    }
    for (int i = 0; i < path.size() - 1; i++)
        cout << path[i] << "  班次为：" << ranklist_temp[i] << "  出发时间为:" << STList_temp[i] << " day" << "  到达时间为" << ETList_temp[i] << "day" << " -->" << path[i + 1] << endl;

}
void ALGraph::printLeastTimePath(const std::string& start_city, const std::string& end_city)
{
    vector<string> path;
    vector<float> spend_money_list_temp;
    vector<string> ranklist_temp;
    vector<Time> STList_temp;
    vector<Time> ETList_temp;
    vector<vector<string>> Allpath;
    getAllPath(start_city, end_city, Allpath, path);
    //找出所有路径中花时最少的路径  Allpath 为所有能到达终点城市的路径
    float min_time = FLT_MAX;
    for (int i = 0; i <= Allpath.size() - 1; i++)
    {
        vector<float> spend_money_list;
        vector<string> ranklist;
        vector<Time> STList;
        vector<Time> ETList;
        getinfofromPath(Allpath[i], ranklist, STList, ETList, spend_money_list);
        for (int j = 0; j < Allpath[i].size() - 2; j++)
        {
            STList[j + 1].day = STList[j].day;
            ETList[j + 1].day = ETList[j].day;
            if (ETList[j] >= STList[j + 1])
            {
                STList[j + 1].day += 1;
                ETList[j + 1].day += 1;
            }
        }
        if (min_time > ETList[0].day * 24 * 60 + ETList[0].getTotalMintue())
        {
            min_time = ETList[0].day * 24 * 60 + ETList[0].getTotalMintue();
            spend_money_list_temp = spend_money_list;
            ranklist_temp = ranklist;
            STList_temp = STList;
            ETList_temp = ETList;
            path = Allpath[i];
        }
    }
    //打印最快的路径
    cout << "最快的路径为：" << endl;
    for (int i = 0; i < path.size() - 1; i++)
    {
        cout << path[i] << "  班次为：" << ranklist_temp[i] << "  出发时间为:" << STList_temp[i] << " day" << "  到达时间为" << ETList_temp[i] << "day" << " -->" << path[i + 1] << endl;
    }

}

void ALGraph::printLeastMoneyPath(const std::string& start_city, const std::string& end_city) {
    vector<string> path;
    vector<float> spend_money_list_temp;
    vector<string> ranklist_temp;
    vector<Time> STList_temp;
    vector<Time> ETList_temp;
    vector<vector<string>> Allpath;
    getAllPath(start_city, end_city, Allpath, path);
    //找出所有路径中花费最少的路径  Allpath 为所有能到达终点城市的路径
    float min_money = FLT_MAX;
    for (int i = 0; i <= Allpath.size() - 1; i++)
    {
        vector<float> spend_money_list;
        vector<string> ranklist;
        vector<Time> STList;
        vector<Time> ETList;
        getinfofromPath(Allpath[i], ranklist, STList, ETList, spend_money_list);
        float temp = 0;
        for (int j = 0; j < spend_money_list.size(); j++)
        {
            temp += spend_money_list[j];
        }
        if (temp < min_money)
        {
            min_money = temp;
            path = Allpath[i];
            spend_money_list_temp = spend_money_list;
            ranklist_temp = ranklist;
            STList_temp = STList;
            ETList_temp = ETList;
        }
    }
    //打印最少花费的路径
    cout << "最少花费的路径为：" << endl;
    for (int i = 0; i < path.size() - 2; i++) //path.size()-1 为路径的长度 i不能取到path.size()-1 否则会越界
    {
        STList_temp[i + 1].day = STList_temp[i].day;
        ETList_temp[i + 1].day = ETList_temp[i].day;
        if (ETList_temp[i] >= STList_temp[i + 1])
        {
            STList_temp[i + 1].day += 1;
            ETList_temp[i + 1].day += 1;
        }
    }
    for (int i = 0; i < path.size() - 1; i++)
    {
        cout << path[i] << "  班次为：" << ranklist_temp[i] << "  出发时间为:" << STList_temp[i] << " day" << "  到达时间为" << ETList_temp[i] << "day" << " -->" << path[i + 1] << endl;
    }
}
void ALGraph::getinfofromPath(vector<string> path, vector<string>& ranklist, vector<Time>& STList, vector<Time>& ETList, vector<float>& spend_money_list)
{
    for (int i = 0; i < path.size() - 1; i++)
    {
        vector<LineNode> test = graph[path[i]];
        for (auto j : test)
        {
            if (j.end_city_name == path[i + 1])
            {
                ranklist.push_back(j.rank);
                STList.push_back(j.start_time);
                ETList.push_back(j.end_time);
                spend_money_list.push_back(j.spend_money);
            }
        }
    }
}
//深度优先 递归求得所有可行路径
bool ALGraph::getAllPath(string current_city, string end_city, vector<vector<string>>& Allpath, vector<string>& path) {
    path.push_back(current_city);
    if (current_city == end_city) {
        Allpath.push_back(path);
    }
    else {
        for (const LineNode& neighbor : graph[current_city]) {
            if (find(path.begin(), path.end(), neighbor.end_city_name) == path.end())
            {
                getAllPath(neighbor.end_city_name, end_city, Allpath, path);
            }

        }
    }
    path.pop_back();
    //若是能到达终点城市，则返回true
    return Allpath.size() != 0;
}


void ALGraph::printPathsByCity(const std::string& sc, const std::string& ec)
{
    vector<string> path;
    vector<vector<string>> Allpath;
    bool flag = getAllPath(sc, ec, Allpath, path);
    if (!flag) {
        cout << "无法从" << sc << "到达" << ec << endl;
    }
    //取出所有班次 以及对应的发车时间和到达时间 并存入ranklist STList ETList 进行打印

    vector<vector<string>> ranklist; //记录所有路径的班次
    vector<vector<Time>> STList;   //记录所有路径的发车时间
    vector<vector<Time>> ETList;   //记录所有路径的到达时间
    for (int i = 0; i < Allpath.size(); i++)
    {
        vector<string> temp;
        vector<Time> temp1;
        vector<Time> temp2;
        for (int j = 0; j < Allpath[i].size() - 1; j++)
        {
            vector<LineNode> test = graph[Allpath[i][j]];
            for (auto k : test)
            {
                if (k.end_city_name == Allpath[i][j + 1])
                {
                    temp.push_back(k.rank);
                    temp1.push_back(k.start_time);
                    temp2.push_back(k.end_time);
                }
            }
        }
        ranklist.push_back(temp);
        STList.push_back(temp1);
        ETList.push_back(temp2);
    }
    //打印所有路径
    for (int i = 0; i < Allpath.size(); i++)
    {
        cout << "路径" << i + 1 << ": ";
        cout << "\n";
        for (int j = 0; j < Allpath[i].size() - 2; j++)
        {
            STList[i][j + 1].day = STList[i][j].day;
            ETList[i][j + 1].day = ETList[i][j].day;
            if (ETList[i][j] >= STList[i][j + 1])
            {
                STList[i][j + 1].day += 1;
                ETList[i][j + 1].day += 1;
            }
        }
        for (int j = 0; j < Allpath[i].size() - 1; j++)
        {
            cout << Allpath[i][j] << "  班次为：" << ranklist[i][j] << "  出发时间为:" << STList[i][j] << " day" << "  到达时间为" << ETList[i][j] << "day" << " -->" << Allpath[i][j + 1] << endl;
        }
    }
}



/**
 * @brief 从文件中读取城市信息，提取出发城市并存储在集合中。
 * @return 一个 std::set<std::string>，包含所有出发城市的名称。
 * @note 该函数通过读取文件中的每一行，提取出发城市，并将其添加到集合中。
 */
auto ALGraph::cityGo()
{
    std::ifstream inputFile(this->FILENAME);

    // 检查文件是否成功打开
    if (!inputFile.is_open()) {
        std::cerr << "无法打开文件\n";
    }

    std::set<std::string> departureCities;  // 存储出发城市的集合

    std::string line;

    // 读取文件的第一行，假设它包含标题或其他不需要的信息
    std::getline(inputFile, line);

    // 从文件的每一行提取出发城市信息
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string departureCity;
        iss >> departureCity;  // 从每一行提取出发城市

        // 将城市添加到集合中
        departureCities.insert(departureCity);
    }

    // 返回存储出发城市的集合
    return departureCities;
}


/**
 * @brief 从文件中读取城市信息，提取到达城市并存储在集合中。
 * @return 一个 std::set<std::string>，包含所有到达城市的唯一名称。
 * @note 该函数通过读取文件的每一行，跳过出发城市和其他信息，提取到达城市，并将其添加到集合中。
 */
auto ALGraph::cityArrive()
{
    std::ifstream inputFile(this->FILENAME); // 请替换为实际的文件名

    // 检查文件是否成功打开
    if (!inputFile.is_open()) {
        std::cerr << "无法打开文件\n";
    }

    std::set<std::string> uniqueArrivalCities;  // 存储到达城市的集合

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        // 跳过出发城市和其他信息
        std::string departureCity, arrivalCity;
        iss >> departureCity >> arrivalCity; // 读取到达城市

        // 将到达城市添加到集合中
        uniqueArrivalCities.insert(arrivalCity);
    }

    inputFile.close();  // 关闭文件流

    // 返回存储到达城市的唯一集合
    return uniqueArrivalCities;
}


/**
 * @brief 查询城市是否存在于图中。
 * @param city_name 要查询的城市名称。
 * @return 如果城市存在于出发城市中，返回 1；存在与到达城市中，返回2;其余情况返回0
 */
int ALGraph::ifCityExist(const string& city_name) {
    for (const auto& city : cityGo()) {
        if (city == city_name) return 1;
    }//
    for (const auto& city : cityArrive()) {
        if (city == city_name) return 2;
    }
    return 0;

}

/**
 * @brief 手动添加线路信息到文件中。
 * @param start_city_name 出发城市名称。
 * @param end_city_name 到达城市名称。
 * @param start_time 出发时间。
 * @param end_time 到达时间。
 * @param spend_time 行程耗时。
 * @param spend_money 行程花费。
 * @param rank 线路等级。
 * @note 该函数在文件中找到插入点，并在插入点之后插入新的线路信息。如果找不到插入点，则将新线路信息插入文件末尾。
 */
void ALGraph::addLine(const string start_city_name, const string end_city_name, const Time start_time, const Time end_time, const Time spend_time,
    const float spend_money, const string rank) {

    ifstream inFile(this->FILENAME);
    ofstream tempFile("temp.txt"); // 临时文件

    // 检查文件是否成功打开
    if (!inFile.is_open() || !tempFile.is_open()) {
        std::cerr << "无法打开文件\n";
        return;
    }

    std::string line;
    bool inserted = false;

    // 逐行读取原文件内容
    while (std::getline(inFile, line)) {
        tempFile << line << std::endl;

        // 如果找到插入点，插入新的数据
        if (!inserted && line.find(start_city_name) != std::string::npos) {
            tempFile << setw(10) << start_city_name << " " << setw(10) << end_city_name
                << " " << setw(6) << rank << " ";
            tempFile.fill('0'); // 修改 fill() 的默认填充符为 0
            tempFile << start_time << " " << end_time << " " << spend_time << " "
                << setiosflags(ios_base::showpoint) << spend_money << endl;
            tempFile.fill(' '); // fill() 不像 setw()，需要手动调整
            inserted = true;
        }
    }

    // 如果数据应该插入到文件末尾
    if (!inserted) {
        tempFile << setw(10) << start_city_name << " " << setw(10) << end_city_name
            << " " << setw(6) << rank << " ";
        tempFile.fill('0'); // 修改 fill() 的默认填充符为 0
        tempFile << start_time << " " << end_time << " " << spend_time << " "
            << setiosflags(ios_base::showpoint) << spend_money << endl;
        tempFile.fill(' '); // fill() 不像 setw()，需要手动调整
    }

    // 关闭文件流
    inFile.close();
    tempFile.close();

    // 删除原文件
    std::remove(this->FILENAME);

    // 将临时文件重命名为原文件
    std::rename("temp.txt", this->FILENAME);
}


/**
 * @brief 显示所有城市的名称。
 * @note 该函数通过调用 cityGo() 函数获取所有出发城市的集合，并输出它们的名称。
 */
void ALGraph::showAllCity()
{
    int i = 0;
    cout << "城市名称如下：" << endl;
    for (const auto& city : cityGo()) {
        i++;
        cout << city << " ";
    }
    cout << endl << "一共有" << i << "个城市" << endl;
}

/**
 * @brief 显示所有线路的信息。
 * @note 该函数通过读取文件的每一行，将每条线路的信息输出到标准输出流。
 */
void ALGraph::showAllLine()
{
    std::ifstream inputFile(this->FILENAME);

    // 检查文件是否成功打开
    if (!inputFile.is_open()) {
        std::cerr << "无法打开文件\n";
    }

    std::string line;

    // 读取文件的第一行，假设它包含标题或其他不需要的信息
    std::getline(inputFile, line);

    // 从文件的每一行输出线路信息
    while (std::getline(inputFile, line)) {
        cout << line << endl;
    }
}


/**
 * @brief 从文件中删除指定线路信息。
 * @param startCity 出发城市名称。
 * @param endCity 到达城市名称。
 * @param rank 线路等级。
 * @note 该函数通过读取文件的每一行，将符合条件的线路信息过滤掉，不写入到新的临时文件中，实现删除操作。
 */
void ALGraph::delLine(const string& startCity, const string& endCity, const string& rank) {

    ifstream inFile(this->FILENAME);
    ofstream tempFile("temp.txt");
    string line;

    // 检查文件是否成功打开
    if (!inFile.is_open()) {
        std::cerr << "无法打开文件\n";
        return;
    }

    // 读取文件的第一行，假设它包含标题或其他不需要的信息
    std::getline(inFile, line);
    std::istringstream iss(line);
    tempFile << line << endl;

    // 从文件的每一行过滤符合条件的线路信息
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        LineNode currentLine;

        // 读取当前行的线路信息
        iss >> currentLine.start_city_name >> currentLine.end_city_name >> currentLine.rank
            >> currentLine.start_time >> currentLine.end_time >> currentLine.spend_time
            >> currentLine.spend_money;

        // 如果不符合条件，则将该行写入临时文件
        if (!(currentLine.start_city_name == startCity &&
            currentLine.end_city_name == endCity &&
            currentLine.rank == rank)) {
            tempFile << setw(10) << currentLine.start_city_name << " " << setw(10) << currentLine.end_city_name
                << " " << setw(6) << currentLine.rank << " ";
            tempFile.fill('0'); // 修改 fill() 的默认填充符为 0
            tempFile << currentLine.start_time << " " << currentLine.end_time << " " << currentLine.spend_time << " "
                << setiosflags(ios_base::showpoint) << currentLine.spend_money << endl;
            tempFile.fill(' '); // fill() 不像 setw()，需要手动调整
        }
    }

    // 关闭文件流
    inFile.close();
    tempFile.close();

    // 删除原文件
    std::remove(this->FILENAME);

    // 将临时文件重命名为原文件
    std::rename("temp.txt", this->FILENAME);

    cout << "已删除从" << startCity << "到" << endCity << "，班次号为" << rank << "的线路！" << endl;
}
