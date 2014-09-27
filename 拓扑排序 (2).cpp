//���л����ڣ���topsort�᷵��false
//��û�л�����Ὣ�������д�����toporder��
//����̽���Ƿ��л��Ĵ��ڣ���������������Ҳ����dfs��
//����������е���������(�簴�ֵ���)������dfs��������hoj1114
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXNODE 100
using namespace std;

typedef struct Node
{
    int adj;
    int cost;
    Node* next;
    Node()
    {
        adj=0;
        cost=0;
        next=NULL;
    }
} EdgeNode;
typedef struct Vnode
{
    EdgeNode* first_edge;
    int id;
    Vnode()
    {
        first_edge=NULL;
    }
} VertexNode;
VertexNode* Adjlist=new VertexNode[MAXNODE];
void AddEdge(int s,int e,int w)
{
    EdgeNode* p=new EdgeNode();
    p->adj=e;
    p->cost=w;
    p->next=Adjlist[s].first_edge;
    Adjlist[s].first_edge=p;
}
int indegree[MAXNODE];
char route[MAXNODE];
void FindIndgree(int n)
{
    memset(indegree,0,sizeof(indegree));
    for(int i=0; i<n; i++)
    {
        EdgeNode* t=Adjlist[i].first_edge;
        while(t!=NULL)
        {
            indegree[t->adj]++;
            t=t->next;
        }
    }
}

bool topsort(int n,int toporder[])
{
    queue <int>Q;
    int nodecnt=0;
    while(!Q.empty())Q.pop();
    for(int i=0; i<n; i++)
    {
        if(indegree[i]==0)Q.push(i);
    }
    while(!Q.empty())
    {
        int t;
        t=Q.front();
        Q.pop();
        toporder[nodecnt++]=t;
        EdgeNode* pt;
        pt=Adjlist[t].first_edge;
        while(pt!=NULL)
        {
            indegree[pt->adj]--;
            if(indegree[pt->adj]==0)
            {
                Q.push(pt->adj);
            }
            pt=pt->next;
        }
    }
    if(nodecnt<n)
    {
        printf("There are circles!\n"); //����л��Ĵ��ڣ���ô��Ȼ�е�������Զ��Ϊ0����Զ������Ӳ����
        return false;
    }
    else return true;
}

int main()
{
    freopen("1.txt","r",stdin);
    int n,m;
    int toporder[MAXNODE];
    scanf("%d %d",&n,&m);
    while(m--)
    {
        int s,e,w;
        scanf("%d %d %d",&s,&e,&w);
        AddEdge(s,e,w);
    }
    FindIndgree(n);
    for(int i=0; i<n; i++)
        printf("%d ",indegree[i]);
    putchar('\n');
    if(topsort(n,toporder))
    {
        for(int i=0; i<n; i++)
            printf("%d ",toporder[i]);
    }
    return 0;
}

