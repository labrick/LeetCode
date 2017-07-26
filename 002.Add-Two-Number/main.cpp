#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode* l2){ 
        ListNode *results = new ListNode(0);    // 只是为了统一while中的规则
        ListNode *curNodePtr = results;
        ListNode *curNodePtr1 = l1, *curNodePtr2 = l2;
        int carry = 0;
        while(curNodePtr1 || curNodePtr2){
            int x = ( curNodePtr1 != NULL) ? curNodePtr1->val : 0;
            int y = ( curNodePtr2 != NULL) ? curNodePtr2->val : 0;
            if(curNodePtr1)
                curNodePtr1 = curNodePtr1->next;
            if(curNodePtr2)
                curNodePtr2 = curNodePtr2->next;
            int sum = x + y + carry;
            carry = sum / 10;
            curNodePtr->next = new ListNode(sum % 10);
            curNodePtr = curNodePtr->next;
        }
        if(carry > 0){
            curNodePtr->next = new ListNode(carry);
        }
        return results->next;
    }
};

int main()
{
    Solution solution = Solution();
    ListNode *pNode1 = new ListNode(1), *pNode2 = new ListNode(0);
    ListNode *curNodePtr1 = pNode1, *curNodePtr2 = pNode2;

    // curNodePtr1->next = new ListNode(8);
    // curNodePtr1 = curNodePtr1->next;

    for(int i=1; i<4; i++){
        curNodePtr1->next = new ListNode(i+1);
        curNodePtr1 = curNodePtr1->next;
        curNodePtr2->next = new ListNode((i+1)*2);
        curNodePtr2 = curNodePtr2->next;
    }
    for(ListNode *p=pNode1; p != NULL; p = p->next){
        cout << p->val;
    }
    cout << endl;
    for(ListNode *p=pNode2; p != NULL; p = p->next){
        cout << p->val;
    }
    cout << endl;

    ListNode *results = solution.addTwoNumbers(pNode1, pNode2);
    for(ListNode *p=results; p != NULL; p = p->next){
        cout << p->val;
    }
    cout << endl;
}
