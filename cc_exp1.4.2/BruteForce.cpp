#include <iostream>
#include <vector>
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
        return head;

    vector<ListNode*> odd;
    vector<ListNode*> even;

    ListNode* temp=head;
    int pos=1;

    while(temp!=nullptr)
    {
        if(pos%2==1)
            odd.push_back(temp);
        else
            even.push_back(temp);

        temp=temp->next;
        pos++;
    }

    vector<ListNode*> result;

    for(auto node:odd)
        result.push_back(node);

    for(auto node:even)
        result.push_back(node);

    for(int i=0;i<result.size()-1;i++)
        result[i]->next=result[i+1];

    result.back()->next=nullptr;

    return result[0];
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