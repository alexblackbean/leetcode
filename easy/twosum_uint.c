#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    // for (int i = 0;array[i] != '\0';i++)
    // {
    //     printf("%d ",array[i]);
    // }
    // printf("%d\n",target);
    // printf("%d\n",size);
    return 0;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* index_array = malloc(sizeof(int)*numsSize);
    int ans[2] = {-1, -1};
    int index_size = 0,k = 0;
    bool zero = false;
    for (int i = 0; i < numsSize; i++)
        index_array[i] = -1;
    // for (int i = 0;nums[i] != '\0';i++)
    // {
    //     printf("%d ",nums[i]);
    // }
    // printf("%d\n",target);
    // printf("%d\n",numsSize);
    /// code start from here
    // O(n)
    for (int i = 0, j = 0; i < numsSize; i++)
    {
        if (nums[i] <= target)
        {
            index_array[j] = i;
            index_size++;
            j++;
        }
        
        // if (nums[i] == 0)
            // zero = true;
    }
    // printf("%d\n",index_size);
    // for (int i = 0; i < index_size; i++)
    //     printf("%d",index_array[i]);
    
    bool flag1 = false,flag2 = false;
    bool find = false;
    for (int a = 0; a <= target; a++)
    {
        // printf("%d ",a);
        flag1 = false;
        flag2 = false;
        k = 0;
        if (find)
        {
            // printf("[%d,%d]\n",ans[0],ans[1]);
            // break;
            break;
        }
        
        for (int i = 0; i < index_size; i++)
        {
            if (nums[index_array[i]] == a && !flag1 && !flag2)
            {
                flag1 = true;
                ans[k] = index_array[i];
                k++;
                continue;
            }
                
            if (nums[index_array[i]] == (target - a) && !flag1 && !flag2)
            {
                flag2 = true;
                ans[k] = index_array[i];
                k++;
                continue;
            }
            if (flag1)
            {
                if (nums[index_array[i]] == (target-a))
                {
                    // printf("find it\n");
                    ans[k] = index_array[i];
                    find = true;
                    break;
                }
            }
            else if (flag2)
            {
                if (nums[index_array[i]] == a)
                {
                    // printf("find it\n");
                    ans[k] = index_array[i];
                    find = true;
                    break;
                }
            }
        }
    }
    return ans;
    // for (int i = 0; index_array[i] != -1; i++)
    //     printf("%d",index_array[i]);
}