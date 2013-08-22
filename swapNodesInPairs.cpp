/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL || head->next==NULL) return head;
        ListNode *l1, *l2, *pre;
        ListNode *temp, *temp_next;
        l1=head;
        l2=head->next;
        l1->next=l2->next;
        l2->next=l1;
        
        head=l2;
        pre=l1;
        l1=l1->next;
        while(l1 && l1->next)
        {
            l2=l1->next;
            l1->next=l2->next;
            l2->next=l1;
            pre->next=l2;
            pre=l1;
            l1=l1->next;
        }
        return head;
    }
};
