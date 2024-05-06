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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>  st;

        st.push( head );

        head = head->next;

        while ( head )
        {
            while ( !st.empty() and head->val > st.top()->val )
                st.pop();

            if ( !st.empty() )
                st.top()->next = head;
            st.push( head );
            head = head->next;
        }

        while ( st.size() > 1 )
            st.pop();

        return ( st.top() );
    }
};