#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int reverse(int integer);
int main() {
    int integer;
    int ans = 0;
    scanf("%d", &integer);
    ans = reverse(integer);
    printf("%d", ans);
    return 0;
}

int reverse(int integer)
{
    char string[12] = "";
    char u_bound[12] = "2147483647";
    char l_bound[12] = "2147483648";
    char ans_string[12] = "";
    int ans = 0;
    bool negative = false; 
    sprintf(string, "%d", integer);
    if (string[0] == '-')
    {
       negative = true; 
    }
    if (!negative)
    {
        // for positive number parsing
        int j = 0;
        for (int i = strlen(string)-1; i >= 0; i--)
        {
            ans_string[j] = string[i];
            j++;
        }
        // printf("%d", strlen(ans_string));
        if (strlen(u_bound) == strlen(ans_string))
        { 
            // for same length case
            if (strcmp(u_bound, ans_string) < 0) 
            {
                // return 0 if the reversed number overflow
                // printf("%s\n%s", ans_string, u_bound);
                return 0;
            }
            else
            {
                // return ans if the reversed number no overflow
                printf("hi");
                for (int k = 0; k < strlen(ans_string); k++)
                {
                     ans = ans*10 + (int)(ans_string[k] - 48);
                     return ans;
                }
            }
        }
        // for different length case
        for (int k = 0; k < strlen(ans_string); k++)
        {
            ans = ans*10 + (int)(ans_string[k] - 48);
        }
        return ans;
    }
    else
    {
        // for negative number parsing
        int j = 0;
        for (int i = strlen(string)-1; i >= 1; i--)
        {
            ans_string[j] = string[i];
            j++;
        }
        if (strlen(string) == strlen(ans_string))
        {
            // for same length case
            if (strcmp(u_bound, ans_string) < 0) 
            {
                return 0;
            }
            else
            {
               return 0 ;
            }
        }
        for (int k = 0; k < strlen(ans_string); k++)
        {
            ans = ans*10 + (int)(ans_string[k] - 48);
        }
        return -ans;
    }
}
