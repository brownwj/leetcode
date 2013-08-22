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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return head;
        ListNode* current = head->next;
        ListNode *pre = head;
        while(current)
        {
            if(current->val != pre->val)
            {
                pre = current;
                current = current->next;
                continue;
            }
            current = current->next;
            pre->next = current;
        }
        return head;
    }
};
