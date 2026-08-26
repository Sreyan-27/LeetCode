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
        // Create a dummy node pointing to head to handle edge cases easily
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = head;
        int length = 0;
        
        // Pass 1: Calculate the exact length of the list
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        
        // Find the node right BEFORE the one we want to delete
        int stepsToTarget = length - n;
        ListNode* prev = dummy;
        
        for (int i = 0; i < stepsToTarget; i++) {
            prev = prev->next;
        }
        
        // Pass 2: Unlink and delete the target node
        ListNode* nodeToDelete = prev->next;
        prev->next = prev->next->next;
        delete nodeToDelete; // Free memory
        
        // Save new head, delete dummy node container, and return
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
