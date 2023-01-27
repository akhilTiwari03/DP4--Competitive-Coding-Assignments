#include <bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode* next;
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode *temp;
	while(headA != NULL){
		temp = headB;
		while(temp != NULL){
			if(headA == temp){
				return headA;
			}
			temp = temp -> next;
		}
		headA = headA -> next;
	}
	return NULL;
}
int main(){

}