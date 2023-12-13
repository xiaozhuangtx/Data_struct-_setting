#include "../utils/common.hpp"

/* 基于链表实现的队列 */

class LinkedListQueue {
    private:
        ListNode *front,*rear;
        int queSize;
    public:
        LinkedListQueue(){
            front = rear = NULL;
            queSize = 0;
        }
        ~LinkedListQueue(){
            ListNode *p = front;
            while(p){
                ListNode *q = p;
                p = p->next;
                delete q;
            }
        }
        //获取队列的大小
        int size(){
            return queSize;
        }
        //判断队列是否为空
        bool isEmpty(){
            return queSize == 0;
        }
        //入队
        void push(int val){
            ListNode *node = new ListNode(val);
            if(rear == NULL){
                front = rear = node;
            }
            else{
                rear->next = node;
                rear = node;
            }
            queSize++;
        }
        //出队
        int pop(){
            if(isEmpty()){
                return -1;
            }
            ListNode *node = front;
            front = front->next;
            if(front == NULL){
                rear = NULL;
            }
            queSize--;
            int val = node->val;
            delete node;
            return val;
        }
        //获取队首元素
        int peek(){
            if(isEmpty()){
                return -1;
            }
            return front->val;
        }
        //将队列转换为数组
        vector<int> toVector(){
            vector<int> res;
            ListNode *p = front;
            while(p){
                res.push_back(p->val);
                p = p->next;
            }
            return res;
        }
};









int main() {
    /* 初始化队列 */
    LinkedListQueue *queue = new LinkedListQueue();

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

    // 释放内存
    delete queue;

    return 0;
}
