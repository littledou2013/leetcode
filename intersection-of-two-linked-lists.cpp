/**
 * 难度：**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        /* 如果两条单链表最后合并为一个单链表，找出合并的节点
         * 如果两个链表没有合并为一个单链表，则return NULL;
         * 1、计算两条单链表的长度count1, count2
         * 2、设置两个指针hea1、 head2指向两个链表的头结点，使指向长链表的指针向前遍历abs(coun1 - count2)
         * 3、head1、head2同时遍历后面节点并比较两指针，直到两针指向同一个节点，或者结束遍历时停止
         */
         int length1 = 0, length2 = 0;
         ListNode *head1 = headA, *head2 = headB;
         //计算两条单链表长度
         while (head1 != NULL)
         {
            head1 = head1 -> next;
            ++length1;
         }
         while (head2 != NULL)
         {
             head2 = head2 -> next; 
             ++length2;
         }
         //设置两个指针指向头结点，指向长链表的指针向后遍历abs(length1 - length2)，使剩余历节点与短链表长度相等
        head1= headA, head2 = headB;
        while (length1 > length2)
        {
            head1 = head1 -> next;
            --length1;
        }
        while (length2 > length1)
        {
            head2 = head2 -> next;
            --length2;
        }
        //同时遍历两链路
        while (head1 != head2)
        {
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        return head1;
    }
};
