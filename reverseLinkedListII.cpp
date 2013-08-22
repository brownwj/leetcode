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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode temp_head(1);
        temp_head.next = head;
        ListNode* begin = &temp_head;
        int i=1;
        while(i<m)
        {
            begin=begin->next;
            i++;
        }
        ListNode *current = begin->next->next;
        ListNode *current_pre = begin->next;
        while(i<n)
        {
            ListNode *tmp1 = current->next;
            current_pre->next = tmp1;
            ListNode *tmp2 = begin->next;
            begin->next = current;
            current->next = tmp2;
            
            current = current_pre->next;
            i++;
        }
        return temp_head.next;
    }
};
