#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val=x;
        next=nullptr;
    }
};

ListNode* oddEvenList(ListNode* head)
{
    if(head==nullptr)
        return nullptr;

    ListNode* oddHead=nullptr;
    ListNode* oddTail=nullptr;

    ListNode* evenHead=nullptr;
    ListNode* evenTail=nullptr;

    ListNode* temp=head;
    int pos=1;

    while(temp)
    {
        ListNode* newNode=new ListNode(temp->val);

        if(pos%2==1)
        {
            if(oddHead==nullptr)
                oddHead=oddTail=newNode;
            else
            {
                oddTail->next=newNode;
                oddTail=newNode;
            }
        }
        else
        {
            if(evenHead==nullptr)
                evenHead=evenTail=newNode;
            else
            {
                evenTail->next=newNode;
                evenTail=newNode;
            }
        }

        temp=temp->next;
        pos++;
    }

    oddTail->next=evenHead;

    return oddHead;
}

void printList(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    head=oddEvenList(head);

    printList(head);
}