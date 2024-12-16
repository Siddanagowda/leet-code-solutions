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
    ListNode* sortList(ListNode* head) {
        if(!head || head->next==nullptr) return head;

        ListNode* mid=getmid(head);
        ListNode* nextmid=mid->next;
        mid->next=nullptr;

        ListNode* left=sortList(head);
        ListNode* right=sortList(nextmid);

        return merge(left,right);
    }
private:
    ListNode* getmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l,ListNode* r){
        ListNode temp(0);
        ListNode* cur=&temp;
        while(l && r){
            if(l->val<r->val){
                cur->next=l;
                l=l->next;
            }
            else{
                cur->next=r;
                r=r->next;
            }
            cur=cur->next;
        }
        if(l) cur->next=l;
        if(r) cur->next=r;

        return temp.next;
    }
};