#include <stdio.h>
#include <stdlib.h>

// �ڵ�ṹ��
typedef struct Node{
    int id;   //���
    int code; //����
    struct Node* next; //ָ����һ���ڵ��ָ��
}Node, *pNode;

int main()
{
    int n,m,i,size;
    scanf("%d %d",&m, &n);

    // ��ʼ����
    Node* head = NULL; //����ָ���һ���ڵ�
    Node* p;//����ָ�������һ���ڵ�
    Node* q;//����ָ�������ڵ�

    for(i=1; i<=n; ++i)
    {
        if(head == NULL)//����ǵ�һ���ڵ�
        {
            head = (Node*)malloc(sizeof(Node));
            head->id = i;
            scanf("%d",&(head->code));
            head->next = head;
            p = head;
        }
        else
        {
        // �����½ڵ�
            q = (Node*)malloc(sizeof(Node));
            q->next = head; //ά�ֱջ�
            q->id = i;
            scanf("%d",&(q->code));

            // ���½ڵ���ӵ������
            p->next = q;
            p = q;
        }
    }

    if(head == NULL)
    {
        return 0;
    }

    // ��ʼģ�����
    size = n;
    i = 1;  //��¼����
    q = p;  //��ʼ����ɺ�pָ�����һ���ڵ㣬������qָ�����һ���ڵ�
    p = head;

    while(size>0)
        {
            if(i == m)//��������ﵽm
            {
                m = p->code;//����m
                printf("%d ",p->id);//��ӡ������Ա���

                q->next = p->next;// ɾ���ýڵ�
                //���ٽڵ�
                free(p);
                p = NULL;

                p = q->next;
                i = 1;  // ���ü���
                --size; // ��������
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
