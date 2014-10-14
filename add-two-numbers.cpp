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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *Sum = NULL;
        ListNode *SHead = NULL;
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        int remain = 0, add;
        while (head1 != NULL && head2 != NULL)
        {
            add = head1->val + head2->val + remain;
            if (SHead == NULL)
            {
                SHead = new ListNode(add % 10);
                Sum = SHead;
            }
            else
            {
                SHead -> next = new ListNode(add % 10);
                SHead = SHead -> next;
            }
            remain = add / 10;
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        while (head1 != NULL)
        {
            add = head1->val + remain;
            if (SHead == NULL)
            {
                SHead = new ListNode(add % 10);
                Sum = SHead;
            }
            else
            {
                SHead -> next = new ListNode(add % 10);
                SHead = SHead -> next;
            }
            remain = add / 10;
            head1 = head1 -> next;
        }
        while (head2 != NULL)
        {
            add = head2->val + remain;
            if (SHead == NULL)
            {
                SHead = new ListNode(add % 10);
                Sum = SHead;
            }
            else
            {
                SHead -> next = new ListNode(add % 10);
                SHead = SHead -> next;
            }
            remain = add / 10;
            head2 = head2 -> next;
        }
        if (remain != 0)
        {
            SHead -> next = new ListNode(remain);
        }
        return Sum;
        
    }
};
