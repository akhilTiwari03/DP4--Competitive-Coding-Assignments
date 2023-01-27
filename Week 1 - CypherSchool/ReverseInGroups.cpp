#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode* next;
};
ListNode* F(ListNode *curr) {
    ListNode *next = curr, *prev = nullptr;
    while(curr) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || !head-> next || k == 1) return head;

    ListNode *curr = head;
    ListNode *answer = nullptr, *dummy = nullptr;
    while(curr) {
        ListNode *left = curr, *right = nullptr;
        int cnt = 0;
        while(curr && cnt != k) {
            right = curr;
            curr = curr -> next;
            cnt++;
        }
        if(cnt != k) {
            if(!answer) return head;
            dummy -> next = left;
            return answer;
        }
        right -> next = nullptr;
        ListNode *r = F(left);

        if(!answer) answer = r;
        else dummy -> next = r;
        dummy = left;
    }
    return answer;
}
int main(){

}