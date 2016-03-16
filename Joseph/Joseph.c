#include <stdio.h>
#include <stdlib.h>

// 节点结构体
typedef struct Node{
    int id;   //编号
    int code; //密码
    struct Node* next; //指向下一个节点的指针
}Node, *pNode;

int main()
{
    int n,m,i,size;
    scanf("%d %d",&m, &n);

    // 初始化环
    Node* head = NULL; //用于指向第一个节点
    Node* p;//用于指向表的最后一个节点
    Node* q;//用于指向新增节点

    for(i=1; i<=n; ++i)
    {
        if(head == NULL)//如果是第一个节点
        {
            head = (Node*)malloc(sizeof(Node));
            head->id = i;
            scanf("%d",&(head->code));
            head->next = head;
            p = head;
        }
        else
        {
        // 产生新节点
            q = (Node*)malloc(sizeof(Node));
            q->next = head; //维持闭环
            q->id = i;
            scanf("%d",&(q->code));

            // 将新节点添加到表最后
            p->next = q;
            p = q;
        }
    }

    if(head == NULL)
    {
        return 0;
    }

    // 开始模拟过程
    size = n;
    i = 1;  //记录报数
    q = p;  //初始化完成后，p指向最后一个节点，现在让q指向最后一个节点
    p = head;

    while(size>0)
        {
            if(i == m)//如果报数达到m
            {
                m = p->code;//更新m
                printf("%d ",p->id);//打印出列人员编号

                q->next = p->next;// 删除该节点
                //销毁节点
                free(p);
                p = NULL;

                p = q->next;
                i = 1;  // 重置计数
                --size; // 更新人数
            }
            else
            {
                q = p;
                p = p->next;
                ++i;
            }
        }

    return 0;
}
