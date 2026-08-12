#include <iostream>
using namespace std;

// Node Structure
struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

// Function to rearrange odd-even nodes
ListNode* oddEvenList(ListNode* head)
{
    if(head==nullptr || head->next==nullptr)
        return head;

    ListNode* odd=head;
    ListNode* even=head->next;
    ListNode* evenHead=even;

    while(even!=nullptr && even->next!=nullptr)
    {
        odd->next=even->next;
        odd=odd->next;

        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenHead;

    return head;
}

// Print Linked List
void printList(ListNode* head)
{
    while(head!=nullptr)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    cout<<"Original List : ";
    printList(head);

    head=oddEvenList(head);

    cout<<"Modified List : ";
    printList(head);

    return 0;
}