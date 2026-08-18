#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> visited;

    while (head != nullptr) {
        if (visited.find(head) != visited.end())
            return true;

        visited.insert(head);
        head = head->next;
    }

    return false;
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    cout << boolalpha << hasCycle(head);

    return 0;
}
