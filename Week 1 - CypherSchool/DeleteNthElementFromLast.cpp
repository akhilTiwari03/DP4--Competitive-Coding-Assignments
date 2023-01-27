#include <bits/stdc++.h>
using namespace std;
class List{
    public:
        int val;
        ListNode* next;
        ListNode(int v){
            val = v;
        }
};
List* removeNthFromEnd(List* head, int n) {
    int size = 0;
    List* temp = head;
    while(temp != 0){
        ++size;
        temp = temp->next;
    }
    if(n == size)
        return head->next;
    temp = head;
    while(n-- > 0)
        temp = temp->next;
    List* temp2 = head;
    while(temp->next != NULL){
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp2->next = temp2->next->next;
    return head;
}
int main(){
    
}