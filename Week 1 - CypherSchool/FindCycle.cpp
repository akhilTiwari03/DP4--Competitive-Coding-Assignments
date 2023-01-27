#include <bits/stdc++.h>
using namespace std;
class List{
    public:
        int val;
        List* next;
        List(int val){
            this.val = val;
        }
};
bool hasCycle(List *head) {
    List* slow = head;
    List* fast = head;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next ->next;
        slow = slow -> next;
        if(slow == fast)
            return true;
    }
    return false;
}
int main(){

}