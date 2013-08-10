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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* small=NULL,*big=NULL;
        ListNode* small_last=NULL,*big_last=NULL;
        ListNode* list = head;
        if(head==NULL) return NULL;
        while(list!=NULL)
        {
            if(list->val < x)
            {
                if(small==NULL)
                {
                    small=list;small_last=small;
                }
                else
                {
                    small_last->next = list;
                    small_last = list;
                }
            }
            else
            {
                if(big==NULL)
                {
                    big = list;big_last=big;
                }
                else
                {
                    big_last->next=list;
                    big_last = list;
                }
            }
            list = list->next;
        }
        if(small!=NULL)
        {
            small_last->next = big;
            if(big_last!=NULL)
                big_last->next = NULL;
            return small;
        }
        else
        {
            big_last->next = NULL;
            return big;
        }
    }
};
