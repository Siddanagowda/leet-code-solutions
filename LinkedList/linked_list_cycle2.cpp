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
        ListNode *detectCycle(ListNode *head) {
            ListNode *fast = head,*slow = head;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    ListNode *pointer = head;
                    while(pointer != slow){
                        pointer = pointer->next;
                        slow = slow->next;
                    }
                    return pointer;
                }
            }
            return nullptr;
        }
    };