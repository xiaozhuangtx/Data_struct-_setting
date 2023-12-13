
#include "../utils/common.hpp"

/* 双向链表节点 */
struct DoublyListNode {
    int val;
    DoublyListNode *prev;   // 前驱指针
    DoublyListNode *next;   // 后继指针
    DoublyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

/* 基于双向链表实现的双向队列 */
class LinkedListDeque {
  private:
    DoublyListNode *front;   // 队首指针
    DoublyListNode *rear;   // 队尾指针
    int queSize=0;            // 队列的大小
  public:
    // 构造函数
    LinkedListDeque():front(nullptr),rear(nullptr){}
    // 析构函数 
    ~LinkedListDeque() {
        DoublyListNode *p = front;
        while (p != nullptr) {
            DoublyListNode *tmp = p;
            p = p->next;
            delete tmp;
        }
    }
    // 获取队列的大小
    int size() {
        return queSize;
    }
    // 判断队列是否为空
    bool isEmpty() {
        return queSize == 0;
    }
    // 入队
    void push(int num,bool isFront){
        DoublyListNode *node = new DoublyListNode(num);
        if (isEmpty()) {
            front = node;
            rear = node;
        } else if (isFront) {
            node->next = front;
            front->prev = node;
            front = node;
        } else {
            node->prev = rear;
            rear->next = node;
            rear = node;
        }
        queSize++;
    }
    // 队首入队
    void pushFirst(int num) {
        push(num,true);
    }
    // 队尾入队
    void pushLast(int num) {
        push(num,false);
    }
    // 出队
    int pop(bool isFront) {
        if (isEmpty()) {
            return -1;
        }
        int val;
        if (isFront) {
            val = front->val;
            DoublyListNode *tmp = front;
            front = front->next;
            if (front != nullptr) {
                front->prev = nullptr;
            }
            delete tmp;
        } else {
            val = rear->val;
            DoublyListNode *tmp = rear;
            rear = rear->prev;
            if (rear != nullptr) {
                rear->next = nullptr;
            }
            delete tmp;
        }
        queSize--;
        return val;
    }
    // 队首出队
    int popFirst() {
        return pop(true);
    }
    // 队尾出队
    int popLast() {
        return pop(false);
    }
    // 获取队首元素
    int peekFirst() {
        if (isEmpty()) {
            return -1;
        }
        return front->val;
    }

    // 获取队尾元素
    int peekLast() {
        if (isEmpty()) {
            return -1;
        }
        return rear->val;
    }
    // 将队列转换为数组
    vector<int> toVector() {
        vector<int> res;
        DoublyListNode *p = front;
        while (p != nullptr) {
            res.push_back(p->val);
            p = p->next;
        }
        return res;
    }
    
};





int main() {
    /* 初始化双向队列 */
    LinkedListDeque *deque = new LinkedListDeque();
    deque->pushLast(3);
    deque->pushLast(2);
    deque->pushLast(5);
    cout << "双向队列 deque = ";
    printVector(deque->toVector());

    /* 访问元素 */
    int peekFirst = deque->peekFirst();
    cout << "队首元素 peekFirst = " << peekFirst << endl;
    int peekLast = deque->peekLast();
    cout << "队尾元素 peekLast = " << peekLast << endl;

    /* 元素入队 */
    deque->pushLast(4);
    cout << "元素 4 队尾入队后 deque =";
    printVector(deque->toVector());
    deque->pushFirst(1);
    cout << "元素 1 队首入队后 deque = ";
    printVector(deque->toVector());

    /* 元素出队 */
    int popLast = deque->popLast();
    cout << "队尾出队元素 = " << popLast << "，队尾出队后 deque = ";
    printVector(deque->toVector());
    int popFirst = deque->popFirst();
    cout << "队首出队元素 = " << popFirst << "，队首出队后 deque = ";
    printVector(deque->toVector());

    /* 获取双向队列的长度 */
    int size = deque->size();
    cout << "双向队列长度 size = " << size << endl;

    /* 判断双向队列是否为空 */
    bool isEmpty = deque->isEmpty();
    cout << "双向队列是否为空 = " << boolalpha << isEmpty << endl;

    // 释放内存
    delete deque;

    return 0;
}
