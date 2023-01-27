#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode* next;
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *answer = new ListNode(INT_MAX);
        ListNode *prev = answer;

        bool rotate = true;
        while(rotate) {
            int idx = -1, val = INT_MAX;
            for(int i = 0; i < lists.size(); i++) {
               if(lists[i]) {
                   if(val > lists[i] -> val) {
                       idx = i;
                       val = lists[i] -> val;
                   } 
               }
            }
            if(idx == -1) return answer -> next;

            prev -> next = lists[idx];
            prev = lists[idx];
            lists[idx] = lists[idx] -> next;
        }
        return answer -> next;
    }
int main(){

}