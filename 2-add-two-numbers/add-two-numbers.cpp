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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       /* ListNode* dummyHead= new ListNode(0);
        ListNode* curr= dummyHead;
        ListNode* t1= l1;
        ListNode* t2= l2;
        int carry=0;
        while(t1!= NULL || t2!=NULL)
        {
            int sum = carry;
            if(t1)
            {
                sum= sum+t1->val;
            }
            if(t2)
            {
                sum= sum+t2->val;
            }
        ListNode* newNode= new ListNode(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;
        }
        if(t1)
        {
            t1= t1->next;
        }
        if(t2)
        {
            t2= t2->next;
        }
      if(carry)
      {
        ListNode* newNode= new ListNode(carry);
        curr->next= newNode;
      }
      ListNode* result = dummyHead->next;
      delete dummyHead;
      return result;*/
      ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};