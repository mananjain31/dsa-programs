// printing all combinations of given set *can be repetitive*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count = 0;
void _printCombinations(char* seed, char* set, int setSize, int maxLength)
{
    int i, j, duplicate, seedLength;
    char* str;
    seedLength = strlen(seed);
    if(seedLength>0)
    {
        count++;
        printf("%s\n", seed);
    }
    if(maxLength== 0) return;
    str = (char*)malloc(sizeof(char)*(seedLength+2));
    strcpy(str, seed);
    for(i=0; i<setSize; i++)
    {
        duplicate = 0;
        for(j=0;j<seedLength;j++)
        {
            if(seed[j] == set[i]) duplicate = 1;
        }
        if(duplicate) continue;
        str[seedLength] = set[i];
        str[seedLength + 1] = '\0';
        _printCombinations(str, set, setSize, maxLength-1);
    }
    free(str);
}
void printCombinations(char* set)
{
    _printCombinations("", set, strlen(set)-1, strlen(set)-1);
}

int main()
{
    char charSet[] = {'a','b','c','a'};   
    printCombinations(charSet);
    printf("Number of Combinations : %d\n", count);
    return 0;
}