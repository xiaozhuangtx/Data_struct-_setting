## 链表
class ListNode:
    def __init__(self, val:int):
        self.val:int = val
        self.next:ListNode|None = None
        
 ## 打印链表      
def print_list(head:ListNode):
    cur=head
    while cur:
        print(cur.val,end=' ')
        cur=cur.next
    print()
## 1. insert
def insert(n0:ListNode,P:ListNode):
    n1=n0.next
    n0.next=P
    P.next=n1
## 2. delete
def remove(n0:ListNode):
    if not n0.next:
        raise Exception("n0.next is None")
    n1=n0.next
    n0.next=n1.next
    n1.next=None
## 3. access
def access(head:ListNode,index:int)->ListNode:
    cur=head
    for i in range(index):
        if not cur:
            raise Exception("Index out of bound")
        cur=cur.next
    return cur
## 4. search
def search(head:ListNode,value:int)->ListNode:
    cur=head
    while cur:
        if cur.val==value:
            return cur
        cur=cur.next
    return None


def main():
    n0=ListNode(0)
    n1=ListNode(1)
    n2=ListNode(2)
    n3=ListNode(3)
    n4=ListNode(4)
    n0.next=n1
    n1.next=n2
    n2.next=n3
    n3.next=n4
    print_list(n0) # 0 1 2 3 4
    ## insert
    insert(n3,ListNode(100))
    print_list(n0) # 0 1 2 100 3 4
    ## delete
    remove(n2)
    print_list(n0) # 0 1 100 3 4

if __name__ == "__main__":
    main()