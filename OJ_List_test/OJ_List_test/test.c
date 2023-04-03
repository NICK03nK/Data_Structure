#define _CRT_SECURE_NO_WARNINGS 1

//复制带随机指针的链表
//https://leetcode.cn/problems/copy-list-with-random-pointer/
//
//struct Node* copyRandomList(struct Node* head) {
//    struct Node* cur = head;
//    struct Node* next = NULL;
//    struct Node* copy = NULL;
//    //1.复制节点，链接到原链表中
//    while (cur)
//    {
//        next = cur->next;
//        copy = (struct Node*)malloc(sizeof(struct Node));
//        copy->val = cur->val;
//        cur->next = copy;
//        copy->next = next;
//        cur = next;
//    }
//    //2.更新copy节点的random
//    cur = head;
//    while (cur)
//    {
//        copy = cur->next;
//        if (cur->random == NULL)
//        {
//            copy->random = NULL;
//        }
//        else
//        {
//            copy->random = cur->random->next;
//        }
//        cur = cur->next->next;
//    }
//    //3.将copy节点解下，重新链接成新链表，将原链表还原
//    struct Node* copyHead = (struct Node*)malloc(sizeof(struct Node));
//    copyHead->next = NULL;
//    struct Node* copyTail = copyHead;
//    cur = head;
//    while (cur)
//    {
//        copy = cur->next;
//        next = copy->next;
//        copyTail->next = copy;
//        copyTail = copyTail->next;
//        cur->next = next;
//        cur = cur->next;
//    }
//    struct Node* newHead = copyHead->next;
//    free(copyHead);
//    copyHead = NULL;
//    return newHead;
//}