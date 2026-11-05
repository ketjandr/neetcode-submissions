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
        // strategy find the tail, get the size
        // so we remove the (size - n) idx node

        int sz = 0;
        ListNode *curr = head;
        while (curr) {
            curr = curr->next;
            sz++;
        }

        curr = head;
        int target = sz - n;
        int counter = 0;
        while (counter < target - 1) {
            curr = curr->next;
            counter++;
        }

        if (counter == target) {
            ListNode *deleted = head;
            head = head->next;
            delete deleted;
        } else {
            ListNode *deleted = curr->next;
            curr->next = curr->next->next;
            delete deleted;
        }

        
            
        return head;
    }
};
