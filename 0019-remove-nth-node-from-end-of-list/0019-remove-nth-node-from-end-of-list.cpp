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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;

        stack<ListNode*> st;
        while(temp != nullptr){
            st.push(temp);
            temp = temp->next;
        }
        int i = 1;
        while(i != n){
            st.pop();
            i++;
        }

        ListNode* prev = st.top();
        st.pop();
        if(st.empty()){
            head = head->next;
            return head;
        }

        ListNode* curr = st.top();
        curr->next = prev->next;
        
        delete prev;
        return head;
    }
};