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
    void reorderList(ListNode *head) {
        /*
         * 基本思路：题目很明显是将后半链表反转后依次插入到前半链表中, 还有存在一次遍历就能把链表分为两半的
         * 需要将后半段多少个链表反转，首先需要求出链表元素个数count，
         * if (count % 2 == 0) 可以把后面count/2 - 1 或者count / 2 个元素反转，if (count % 2 == 1) 可以把后面（count - 1 ) / 2的元素反转
         */
        int count = 0;
        ListNode *p = head;
        while (p != NULL)
        {
            p = p -> next;
            count ++;
        }
        //如果链表长度小于或者等于2根本不需要进行处理直接返回
        if (count <= 2)
            return;
        //找到前半段链表的最后一个元素，那这里对于偶数来说是将count / 2 - 1后面的元素反转，对于奇数来说是将后面(count - 1) / 2的元素反转
        p = head;
        for (int i = count / 2; i > 0 ; --i)
            p = p -> next;
        ListNode *q = p -> next; //后面反转元素的头元素
        p -> next = NULL; //将前半段链表的最后一个元素的尾部指针清除
        //使用前插入法将后面的元素翻转过来
        p = q -> next; //将p用来指向需要往前插入的元素
        q -> next = NULL;  //后半段最后一个元素的尾部指针清除
        ListNode *tmp;
        while (p)
        {
            tmp = p -> next;
            p -> next = q;
            q = p;
            p = tmp;
        }
        
        //合并两个链表
        p = head; //使p指向前半段后节点，q本身是指向后半段头节点
        while (p && q)
        {
            tmp = p -> next;
            p -> next = q;
            q = q -> next;
            p -> next -> next = tmp;
            p = tmp;
        }
        
    }
};
