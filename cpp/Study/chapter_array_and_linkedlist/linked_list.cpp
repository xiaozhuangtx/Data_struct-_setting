#include "../utils/common.hpp"

//链表
// struct ListNode{
//     int val;
//     ListNode *next;
//     ListNode *prev;
//     ListNode(int x) : val(x), next(nullptr),prev(nullptr) {}//构造函数 
//     //val(x) : val = x next(NULL) : next = NULL
// };

//插入节点
void insert(ListNode *n0,ListNode *P){
    ListNode *n1=n0->next;
    P->next=n1;
    n0->next=P;
}
//删除节点
void remove(ListNode *n0){
    ListNode *n1=n0->next;
    ListNode *n2=n1->next;
    n0->next=n2;
}
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

//访问节点
ListNode *access(ListNode *head,int index){
    for(int i=0;i<index;i++){
        if(head==nullptr){
            return nullptr;
        }
        head=head->next;
    }
    return head;
}
//查找节点
int find(ListNode *head,int val){
    int index=0;
    while(head!=nullptr){
        if(head->val==val){
            return index;
        }
        head=head->next;
        index++;
    }
    return -1;
}
void del_front(ListNode *s){
    ListNode *temp=s;
    while (s->next->next!=temp&&s->next!=nullptr)
    {
        s=s->next;
    }
    s->next=temp;
}

//打印链表
void print(ListNode *n0){
    ListNode *p=n0;
    while(p!=NULL){
        cout<<p->val<<"\t";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    ListNode* n0=new ListNode(1);
    ListNode* n1=new ListNode(2);
    ListNode* n2=new ListNode(3);
    ListNode* n3=new ListNode(4);
    ListNode* n4=new ListNode(5);
    // 构建引用指向
    n0->next=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    cout<<"--------------"<<'\n';
    cout<<n0->val<<endl;
    //插入节点
    ListNode* n5=new ListNode(6);
    cout<<"--------------"<<'\n';
    print(n0);
    cout<<"--------------"<<'\n';
    insert(n4,n5);
    print(n0);
    //删除节点
    cout<<"--------------"<<'\n';
    remove(n3);
    print(n0);
    //访问节点
    cout<<"--------------"<<'\n';
    ListNode* n6=access(n0,2);
    cout<<n6->val<<endl;
    return 0;
}
