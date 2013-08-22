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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;
        ListNode *first = head;
        ListNode *last = head;
        while(last->next)
        {
            last = last->next;
        }
        last->next = first;
        for(int i=0;i<k;i++)
        {
            first = last;
            ListNode* temp_last = last;
            while(last->next != temp_last)
            {
                last = last->next;
            }
        }
        last->next = NULL;
        return first;
    }
};
