#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;            //数据域
    struct Node* next;   //指针域
};

int main(void)
{

    struct Node Node1 = {1,NUll};
    struct Node Node2 = {1,NUll};
    struct Node Node3 = {1,NUll};
    Node1.next = &Node2;
    Node2.next = &Node3;


    return 0;
}
