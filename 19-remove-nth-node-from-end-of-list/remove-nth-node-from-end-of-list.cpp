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
        int cnt = 1;
        ListNode* temp = head;

        if(head == NULL) return NULL;
        if(head->next == NULL) return NULL;
        while(temp->next != NULL){
            temp = temp->next;
            cnt++;
        }
        ListNode* newHead = head;
        if(cnt == n){
            ListNode* deleteHead = newHead;
            newHead = newHead->next;
            delete deleteHead;
            return newHead;
        }

        int res = cnt - n;
        ListNode* newTemp = head;
        while(temp != NULL){
            res--;
            if(res == 0){
                break;
            }
            
            newTemp = newTemp->next;
        }
        ListNode* s = newTemp->next;
        newTemp->next = newTemp->next->next;
        delete s;

        return head;

    }
};