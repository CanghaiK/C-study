#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;            //数据域
    struct Node* next;   //指针域
};
//创建链表头表示整个链表
struct Node *create_list(  )
{
    struct Node *head_node = (struct Node *)malloc(sizeof(struct Node));
    //head_node 变成了结构体变量
    //变量使用前必须被初始化
    //head_node->data = 1;
    head_node->next = NULL;

    return head_node;
}
//创建节点
struct Node *create_node(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void print_list(struct Node *head_node)
{
    struct Node *p_move = head_node->next;
    while(p_move)
    {
        printf("%d\t ",p_move->data);
        p_move = p_move->next;
    }
    printf("\n");
}

//插入节点，插入哪个链表，插入节点的数据是多少
void insert_node_by_head(struct Node *head_node,int data)
{
   //创建插入的节点
   struct  Node *new_node = create_node(data);
   new_node->next = head_node->next;
   head_node->next = new_node;
}

void delete_node_by_appoin(struct Node *head_node,int pos_data )
{
    struct Node *pos_node = head_node->next;
    struct Node *pos_node_front = head_node;
    if(pos_node == NULL)
        printf("无法删除，链表为空\n");
    else{
        while(pos_node->data != pos_data)
        {
            pos_node_front = pos_node;
            pos_node = pos_node_front->next;
            if(pos_node == NULL){
                printf("没有找到相关信息，无法删除\n");
                return;
            }
        }
        pos_node_front->next = pos_node->next;
        free(pos_node);
    }
}


int main(void)
{
    struct Node *list = create_list();
    insert_node_by_head(list,1);
    insert_node_by_head(list,2);
    insert_node_by_head(list,3);
    print_list(list);
    delete_node_by_appoin(list,2);
    print_list(list);
    system("pause");
    return 0;
}
