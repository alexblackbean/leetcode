#include <stdio.h>
#include <stdlib.h>
typedef struct heap{
    int index;
    int key;
}heap_t;
void Build_Max_Heap(heap_t** array, int size);
void Heapify(heap_t** array, int size, int index);
void exchange(heap_t** array, int i1, int i2);
char ** Parsing(heap_t* score2, int size);
char ** findRelativeRanks(int* score, int scoreSize, int* returnSize);
int main() {
    int array[10000] = {0};
    int temp;
    int size = 0;
    int rsize = 0;
    int index = 1;
    scanf("[%d",&temp);
    array[0] = temp;
    size ++;
    while (scanf(",%d",&temp) > 0)
    {
        // printf("%d ",temp);
        array[index] = temp;
        index ++;
        size ++;
    }
    scanf("]");
    findRelativeRanks(array,size,&rsize);
    return 0;
}
void Build_Max_Heap(heap_t** array, int size)
{
    for (int i = (size/2) - 1; i >= 0; i --)
    {
        Heapify(array, size, i);
    }
}
void Heapify(heap_t** array, int size, int index)
{
    // for (int i = 0; i < size; i++)
        // printf("%d ",(*array)[i]);
    int largest;
    int left = (index + 1) * 2 -1;
    int right = (index + 1) * 2;
    if ((left <= size-1) && ((*array)[left].key > (*array)[index].key))
        largest = left;
    else
        largest = index;
    if ((right <= size-1) && ((*array)[right].key > (*array)[largest].key))
        largest = right;
    if (largest != index)
    {
        exchange(array, index, largest);
        Heapify(array, size, largest);
    }
        
}
void exchange(heap_t** array, int i1, int i2)
{
    int temp_key = (*array)[i1].key;
    int temp_index = (*array)[i1].index;
    (*array)[i1].key = (*array)[i2].key;
    (*array)[i1].index = (*array)[i2].index;
    (*array)[i2].key = temp_key;
    (*array)[i2].index = temp_index;

}
char** Parsing(heap_t* score2, int size)
{
    int name = 1;
    char number[10001] ="";
    char** string = malloc(sizeof(char*)*size);
    for (int i = size-1; i >= 1; i--)
    {
        heap_t node = score2[0];
        if (name == 1)
            string[node.index] = "Gold Medal";
        else if (name == 2)
            string[node.index] = "Silver Medal";
        else if (name == 3)
            string[node.index] = "Bronze Medal";
        else
        {
            sprintf(number,"%d", name);
            string[node.index] = number;
        }
        name++;
        printf("index: %d, key: %d\n",node.index,node.key);
        exchange(&score2, 0, i);
        Heapify(&score2, --size, 0);
    }
    // number[0] = (char)(name + 48);
    // printf("%d\n",score2[0].index);
    sprintf(number,"%d", name);
    string[score2[0].index] = number;
    // printf("%s\n", string[0]);
    // for (int i = 1; i < size; i++)
    //     printf("%s ",string[i]);
    return string;
}
char ** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char** ans;
    char** ans2;
    heap_t* score2 = malloc(sizeof(*score2)* scoreSize);
    for (int i = 0; i < scoreSize; i++)
    {
        score2[i].index = i;
        score2[i].key = score[i];
    }
    for (int i = 0; i < scoreSize; i++)
        printf("index: %d\nscore: %d\n\n",score2[i].index,score2[i].key);
    Build_Max_Heap(&score2, scoreSize);
    printf("~~~~~~~~~~~~~~~~~~~\n");
    for (int i = 0; i < scoreSize; i++)
        printf("index: %d\nscore: %d\n\n",score2[i].index,score2[i].key);
    ans2 = Parsing(score2, scoreSize);
    // printf("%s", ans2[1]);
    for (int i = 0; i < scoreSize; i++)
        printf("%s ",ans2[i]);
    return ans2;
}