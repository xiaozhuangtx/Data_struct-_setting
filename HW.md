2.11

```c++
void Insert(int *nums,int size,int num){
    for(int i=0;i<size;i++){
        if(nums[i]>num){
            insert(nums,size,num,i);
            break;
        }
    }
}
```

2.21

```c++
void Inverse(int *arr){
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len/2;i++){
        int temp = arr[i];
        arr[i]=arr[len-i-1];
        arr[len-i-1]=temp;
    }
}
```

2.22

```C++
void Inverse(ListNode *n0){
    ListNode *n1=n0->next;
    ListNode *n2=n1->next;
    n0->next=nullptr;
    while(n2!=nullptr){
        n1->next=n0;
        n0=n1;
        n1=n2;
        n2=n2->next;
    }
    n1->next=n0;
}
```

2.31

```
void del_front(ListNode *s){
    ListNode *temp=s;
    while (s->next->next!=temp&&s->next!=nullptr)
    {
        s=s->next;
    }
    s->next=temp;
}
```

3.3    stack

3.4 算法1的功能是将栈S中的元素逆序排列，即从栈底到栈顶的顺序变为从栈顶到栈底的顺序。它通过辅助数组A来保存元素，然后再将元素按相反的顺序重新入栈。

算法2的功能是从栈S中删除所有值为e的元素。它通过使用一个辅助栈T，将栈S中不等于e的元素出栈，然后再将这些元素重新入栈到栈S中，从而实现删除值为e的元素。

3.12   cha

3.13

```C++
#include <iostream>
#include <stack>
#include <unordered_map>
bool areBracketsMatching(const std::string& expression) {
    std::stack<char> bracketStack;
    std::unordered_map<char, char> bracketPairs = {{')', '('}, {']', '['}, {'}', '{'}};
    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            bracketStack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (bracketStack.empty() || bracketStack.top() != bracketPairs[ch]) {
                return false;  // 括号不匹配
            }
            bracketStack.pop();  // 匹配，弹出左括号
        }
    }
    return bracketStack.empty();  // 如果栈为空，说明所有括号都匹配
}
int main() {
    std::string expression = "{[()]()}";

    if (areBracketsMatching(expression)) {
        std::cout << "括号配对正确" << std::endl;
    } else {
        std::cout << "括号配对不正确" << std::endl;
    }
    return 0;
}
```
