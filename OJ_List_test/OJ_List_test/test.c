#define _CRT_SECURE_NO_WARNINGS 1

//���ƴ����ָ�������
//https://leetcode.cn/problems/copy-list-with-random-pointer/
//
//struct Node* copyRandomList(struct Node* head) {
//    struct Node* cur = head;
//    struct Node* next = NULL;
//    struct Node* copy = NULL;
//    //1.���ƽڵ㣬���ӵ�ԭ������
//    while (cur)
//    {
//        next = cur->next;
//        copy = (struct Node*)malloc(sizeof(struct Node));
//        copy->val = cur->val;
//        cur->next = copy;
//        copy->next = next;
//        cur = next;
//    }
//    //2.����copy�ڵ��random
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
//    //3.��copy�ڵ���£��������ӳ���������ԭ����ԭ
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