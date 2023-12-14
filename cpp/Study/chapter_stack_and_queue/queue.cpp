#include "../utils/common.hpp"

int main(){
    //初始化队列
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    //输出队列的大小
    cout << "队列的大小为：" << q.size() << endl;
    //输出队列的第一个元素
    int front= q.front();
    cout << "队列的第一个元素为：" << front << endl;
    //输出队列的最后一个元素
    int back = q.back();
    cout << "队列的最后一个元素为：" << back << endl;
    //弹出队列的第一个元素
    q.pop();
    cout << "弹出队列的第一个元素后，队列的大小为：" << q.size() << endl;
    //判断队列是否为空
    if(q.empty()){
        cout << "队列为空" << endl;
    }else{
        cout << "队列不为空" << endl;
    }
    return 0;
}
