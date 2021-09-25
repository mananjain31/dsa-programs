#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
    struct _Node* next;
    struct _Node* pre;
    struct _Node* nextLevel;
    int data;
}Node;

Node* createNode(int data)
{
    Node* t = (Node*)malloc(sizeof(Node));
    t->next = NULL;
    t->nextLevel = NULL;
    t->pre = NULL;
    t->data = data;
    return t;
}

Node* generateMultiLevelDoublyLinkedListFromArray(int* arr, int size)
{
    if(size == 0) return NULL;
    Node* start = createNode(arr[0]);
    Node* currLevelStart = start;
    Node *t = start;
    int i;
    Node* curr;
    i = 1;
    while(i<size)
    {
        int data = arr[i];
        if(data == 0)
        {
            Node* nextLevelStart = currLevelStart;
            i++;
            //10 20 30 0 0 0 0 40 50
            while(i<size)
            {
                data = arr[i];
                if(data == 0)
                {
                    if(nextLevelStart->next) nextLevelStart = nextLevelStart->next;
                }
                else
                {
                    break;
                }
                i++;
            }
            if(i>=size)return start;
            nextLevelStart->nextLevel = createNode(data);
            // printf("\nlevel started with %d after %d ,",data, nextLevelStart->data);
            t = nextLevelStart->nextLevel;
            currLevelStart = t;
            i++;
        }
        else
        {
            // printf("added %d,", data);
            curr = createNode(data);
            curr->pre = t;
            t->next = curr;
            t = curr;
            i++;
        }
    }
    return start;
}

void flattern(Node* start)
{
    Node* t = start;
    while(t!=NULL)
    {
        printf("%d ", t->data);
        if(t->nextLevel) flattern(t->nextLevel);
        t = t->next;
    }
}

int main()
{
    int arr[] = {10,20,30,40,50,0,0,60,70,80,0,90,100};
    // 10 20 30 40 50
    //    60 70 80
    //    90 100

    // for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) printf("%d ", arr[i]);
    Node* start = generateMultiLevelDoublyLinkedListFromArray(arr, sizeof(arr)/sizeof(arr[0]));
    flattern(start);
    printf("\n");
    return 0;
}