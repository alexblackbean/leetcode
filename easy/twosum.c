#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct link
{
    int value;
    int index;
    struct link* next;
}link_t;
typedef struct node
{
    link_t* link;
}node_t;

void CreateNode(struct node* first, int index, int value);
bool FindNode(struct node* first, int value, int* index);
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main()
{
    int target = 0;
    int array[100]={};
    int temp = 0;
    int index = 1;
    int size = 0;
    int rsize = 0;
    int* array2;
    scanf("nums = [%d",&temp);
    array[0] = temp;
    size ++;
    while (scanf(",%d",&temp) > 0)
    {
        // printf("%d ",temp);
        array[index] = temp;
        index ++;
        size ++;
    }
    scanf("], target = %d",&target);
    array2 = twoSum(array,size,target,&rsize);
    printf("[%d,%d]\n",array2[0],array2[1]);

    return 0;
}
void CreateNode(struct node* first, int index, int value)
{
    if ((*first).link == NULL)
    {
        (*first).link = malloc(sizeof(link_t));
        (*first).link->index = index;
        (*first).link->value = value;
        (*first).link->next = NULL;
    }
    else
    {
        link_t* travel = (*first).link;
        link_t* temp = malloc(sizeof(*temp));
        temp->index = index;
        temp->next = NULL;
        temp->value = value;
        for (; travel->next; travel = travel->next);
        travel->next = temp;
    }
}
int abs(int num1)
{
    if ( num1 < 0)
        return -num1;
    else
        return num1;
}
bool FindNode(struct node* first, int value, int* index)
{
    if ( (*first).link == NULL)
    {
        printf("\ncurrent box has no head, so need to build\n");
        return false;
    }
    else
    {
        link_t* travel = (*first).link;
        for (; travel != NULL; travel = travel -> next)
        {
            printf("wanted %d but travel is %d", value, travel->value);
            if ( travel->value == value)
            {
                printf("got it");
                *index = travel->index;
                printf("\n");
                return true;
            }
        }
        printf("\n");
        return false;
    }
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // printf("numsize: %d\n",numsSize);
    // numsSize = ;
    int hash_size = numsSize;
    int* ans = malloc(sizeof(int)*2);
    ans[0] = -1; ans[1] = -1;
    *returnSize = 2;
    node_t* head = malloc(sizeof(node_t)*hash_size);
    for (int i = 0; i < hash_size; i++)
        head[i].link = NULL;
    for (int i = 0; i < numsSize; i++ )
    {
        int num = nums[i];
        int num2 = target - num;
        int key1, key2;
        int index = -1;
        bool find = false;

        printf("num1: %d , num2: %d\n", num, num2);
        key1 = abs(num % hash_size);
        key2 = abs(num2 % hash_size);
        printf("current key is %d \n",key1);
        printf("current wanted key is %d \n",key2);
        // is num2 exist?
        find = FindNode( &head[key2], num2, &index);
        if ( find )
        {
            ans[0] = i;
            ans[1] = index;
            break;
        }
        else
        {
            printf("Create New node\n");
            CreateNode(&head[key1], i, num);
            link_t* travel = head[key1].link;
            printf("Linked list is\n");
            for (; travel!=NULL; travel = travel -> next)
                printf("%d ", travel->value);
            printf("\n");
        }
    }
    return ans;
}