/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* rhead = reverseList(head);
        int cr = 0;
        ListNode* current = rhead, *prev = nullptr;
        while(current)
        {
            int nval = current->val * 2 + cr;
            current->val = nval % 10;
            cr = nval>9 ? 1 : 0;
            prev = current;
            current =  current->next;
        }
        if(cr!=0)
        {
            ListNode* n = new ListNode(cr);
            prev-> next=n;
        }
        ListNode* res= reverseList(rhead);
        return res;
    }
    ListNode* reverseList(ListNode* node)
    {
        ListNode* curr=node, *prev=nullptr, *nn;
        while(curr)
        {
            nn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nn;
        }
        return prev;
    }
};