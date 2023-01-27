#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode* next;
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 && list2){ // if no one is empty.
            if(list1->val < list2->val){ // if first one is small
                list1->next =  mergeTwoLists(list1->next,list2);
                return list1;
            }
            else{ // if second one is smaller
                list2->next = mergeTwoLists(list1,list2->next);
                return list2;
            }
        }
        if(list1 == NULL)
            return list2;
        return list1;
    }
int main(){

}