#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int v){
            val = v;
        }
};
void removeDuplicates(ListNode* head){
        if(head == NULL)
            return;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr != NULL){
            if(curr->val == prev->val){
                ListNode* temp = curr;
                curr = curr->next;
                prev->next = curr;
                delete temp;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }

    }
    ListNode* deleteDuplicates(ListNode* head) {
        removeDuplicates(head);
        return head;
    }
int main(){

}