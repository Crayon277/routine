#include <stdio.h>
#include <string.h>
#define MAX 105

char set[MAX][MAX];

int main()
{
    int i, j, count = 0, length_max = 0;
    for ( ;fgets(set[count], MAX, stdin); count++)
    {
        if ((i = strlen(set[count])) > length_max)
            length_max = i;
    }
    for (i = 0; i < length_max - 1; i++)
    {
        for (j = count - 1 ; j >= 0; j--)
            if (i < strlen(set[j]) - 1)
                printf("%c", set[j][i]);
            else
                printf(" ");
        printf("\n");
    }
    return 0;
}
