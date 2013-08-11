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
        if(!head || head->next==NULL) return head;
        ListNode *current=head->next, *pre=head->next, *pre_pre=head;
        while(pre)
        {
            while(pre && pre->val==pre_pre->val)
            {
                pre = pre->next;
            }
            if(!pre) return NULL;
            if(pre_pre->next == pre)
                break;
            pre_pre = pre;
            pre = pre->next;
            
        }
        
        head = pre_pre;
        if(!head || head->next==NULL) return head;
        current = head->next->next;
        pre_pre = head;
        pre=head->next;
        int count=0;
        while(current)
        {
            if(current->val != pre->val)
            {
                if(count == 0)
                {
                    pre_pre->next = pre;
                    pre_pre = pre;
                    pre = current;
                    current = current->next;
                    continue;
                }
                else
                {
                    pre_pre->next = current;
                    pre = current;
                    current = current->next;
                    count = 0;
                    continue;
                }
            }
            current=current->next;
            pre_pre->next = current;
            count = 1;
        }
        return head;
    }
};
