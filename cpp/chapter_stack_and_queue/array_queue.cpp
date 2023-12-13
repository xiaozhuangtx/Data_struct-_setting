
#include "../utils/common.hpp"

/* 基于环形数组实现的队列 */
class ArrayQueue {
  private:
    int *nums;// 存储元素的数组
    int front;// 队首指针
    int queSize;// 队列的大小
    int queCapacity;// 队列的容量
  public:
    ArrayQueue(int capacity) {
        nums = new int[capacity];
        front = 0;
        queSize = 0;
        queCapacity = capacity;
    }
    ~ArrayQueue() {
        delete[] nums;
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
    void push(int val) {
        if (queSize == queCapacity&&queSize!=0) {
            cout << "队列已满，无法入队" << endl;
            return;
        }
        nums[(front + queSize) % queCapacity] = val;
        queSize++;
    }
    // 出队
    int pop() {
        if (isEmpty()) {
            return -1;
        }
        int val = nums[front];
        front = (front + 1) % queCapacity;
        queSize--;
        return val;
    }
    // 获取队首元素
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return nums[front];
    }
    // 将队列转换为数组
    vector<int> toVector() {
        vector<int> res;
        for (int i = 0; i < queSize; i++) {
            res.push_back(nums[(front + i) % queCapacity]);
        }
        return res;
    }

};

/* Driver Code */
int main() {
    /* 初始化队列 */
    int capacity = 10;
    ArrayQueue *queue = new ArrayQueue(capacity);

    /* 元素入队 */
    queue->push(1);
    queue->push(3);
    queue->push(2);
    queue->push(5);
    queue->push(4);
    cout << "队列 queue = ";
    printVector(queue->toVector());

    /* 访问队首元素 */
    int peek = queue->peek();
    cout << "队首元素 peek = " << peek << endl;

    /* 元素出队 */
    queue->pop();
    cout << "出队元素 pop = " << peek << "，出队后 queue = ";
    printVector(queue->toVector());

    /* 获取队列的长度 */
    int size = queue->size();
    cout << "队列长度 size = " << size << endl;

    /* 判断队列是否为空 */
    bool empty = queue->isEmpty();
    cout << "队列是否为空 = " << empty << endl;

    /* 测试环形数组 */
    for (int i = 0; i < 10; i++) {
        queue->push(i);
        queue->pop();
        cout << "第 " << i << " 轮入队 + 出队后 queue = ";
        printVector(queue->toVector());
    }

    // 释放内存
    delete queue;

    return 0;
}
