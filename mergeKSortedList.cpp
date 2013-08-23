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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //if( lists.size() <= 1) return intervals; 
        list<ListNode* > mylist;
        
        for( int i=0; i< lists.size(); i++){
            if(lists[i] != NULL) {
                mylist.push_back( lists[i] );
            }
        }
        
        ListNode * head = NULL;
        ListNode ** pre = &head;
        
        while( ! mylist.empty()) {
            list<ListNode* > :: iterator minIt = mylist.begin();
            list<ListNode* > :: iterator it = mylist.begin();
            
            while( ++it != mylist.end() ) {                
                if( (*it)->val < (*minIt)->val ) {
                    minIt = it;
                }
            }
            
            *pre = *minIt;
            if( (*minIt)->next == NULL ) {
                mylist.erase( minIt );
            } else {
                (*minIt) = (*minIt)->next ;
            }
            pre = &( (*pre)->next);     
        }
        return head;
    }
};
