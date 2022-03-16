#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* NewNode(int val);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* ans = NULL;
    struct ListNode* tra1 = NULL;
    struct ListNode* tra2 = NULL;
    struct ListNode* tail = NULL;
    bool flag1 = false;
    bool flag2 = false;
    int cout = 0;
    /*traversing*/
    tra1 = l1;
    tra2 = l2;
    for (; ((tra1 != NULL) && (tra2 != NULL)); )
    {
        int sum = tra1->val + tra2->val + cout;
        cout = 0;
        if (sum < 10)
        {       
            if (ans == NULL)
            {
                ans = malloc(sizeof(*ans));
                ans->next = NULL;
                ans->val = sum;
                tail = ans;
            }
            else
            {
                struct ListNode* temp = NewNode(sum);
                tail->next = temp;
                tail = tail->next;
            }
        }
        else
        {
            cout = 1;
            if (ans == NULL)
            {
                ans = malloc(sizeof(*ans));
                ans->next = NULL;
                ans->val = sum - 10;
                tail = ans;
            }
            else
            {
                struct ListNode* temp = NewNode(sum - 10);
                tail->next = temp;
                tail = tail->next;
            }
        }
        tra1 = tra1->next;
        tra2 = tra2->next;
        if (tra1 == NULL)
            flag1 = true;
        if (tra2 == NULL)
            flag2 = true;
    }
    // printf("flag1: %d, flag2: %d", flag1, flag2);
    if (flag1 && !flag2)
    {
        /*tra2 still have val*/
        for(;tra2 != NULL; tra2 = tra2->next)
        {
            int sum = tra2->val + cout;
            cout = 0;
            if (sum < 10)
            {
                struct ListNode* temp = NewNode(sum);
                tail->next = temp;
                tail = tail->next;
            }
            else
            {
                cout = 1;
                struct ListNode* temp = NewNode(sum-10);
                tail->next = temp;
                tail = tail->next;
            }
        }
        if (cout == 1)
        {
            struct ListNode* temp = NewNode(1);
            tail->next = temp;
        }
    }
    else if (!flag1 && flag2)
    {
        /*tra1 still have val*/
        for(;tra1 != NULL; tra1 = tra1->next)
        {
            int sum = tra1->val + cout;
            cout = 0;
            if (sum < 10)
            {
                struct ListNode* temp = NewNode(sum);
                tail->next = temp;
                tail = tail->next;
            }
            else
            {
                cout = 1;
                struct ListNode* temp = NewNode(sum-10);
                tail->next = temp;
                tail = tail->next;
            }   
        }
        if (cout == 1)
        {
            struct ListNode* temp = NewNode(1);
            tail->next = temp;
        }
    }
    else if (flag1 && flag2)
    {
        /*End*/
        if (cout == 1)
        {
            struct ListNode* temp = NewNode(1);
            tail->next = temp;
            tail = tail->next;
        }
    }
    return ans;
}

struct ListNode* NewNode(int val)
{
    struct ListNode* temp = malloc(sizeof(*temp));
    temp->val = val;
    temp->next = NULL;
    return temp;
}