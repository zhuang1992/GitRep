/*���⣺�����˳�����n,�Լ��ֵ���m���ֵ���˫�����ͨ�еģ�, ����ÿһ����mi,�����������˵ĳ��У��Լ����ܳ��ص���������������

Ҫ��������ӳ���1������n�������������ٻ��


���������򡢴�Ȩͼ�ĵ�Դ���·���⡣ ������·���Ķ������ˣ�����·��Ȩֵ��С���Ƕ�· ��Ȩֵ���������жε�Ȩֵ֮�ͣ���

���ǵ�������������ÿһ����1��n��·�ϣ���·���� �����ֵ�� �������ͳ�����Դ���·������

*/
//hoj 1653
//Dijkstra ��Դ���·
//ע�������·���Ķ������ˣ�����·��Ȩֵ����Сֵ

#include <iostream>
#include <cstdio>
#include <memory.h>
#include <climits>
#define N 1005
#define MinN 0
using namespace std;

int map[N][N];

bool used[N];
int dis[N];
int main()
{
    int caseNum;
    scanf("%d",&caseNum);
    for(int t=1; t<=caseNum; t++) {

        memset(map,0,sizeof(map));  //��ʼ��Ϊ�㣬����Ϊ�����ڵ���������ͨ������Ϊ0����Ҫ����˼ά��ʼ��Ϊ�����
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++) {
            int s,e;
            scanf("%d %d",&s,&e);
            scanf("%d",&map[s][e]);
            map[e][s]=map[s][e];

        }

        memset(used,0,sizeof(used));

        for(int i=1; i<=n; i++) {
            dis[i]=map[1][i];        //dis[i]�����i��Դ��1��·��
        }

        used[1]=1;
        int count=n;

        while(count--) {
            int m=MinN;
            int v;
            for(int i=2; i<=n; i++) {
                if(!used[i]&&m<dis[i]) {  //����ÿ���㵽Դ��1�����ľ��루���·������������ö��Ż�
                    m=dis[i];
                    v=i;
                }
            }
            used[v]=1;
            for(int j=1; j<=n; j++) {
                dis[j]=max(dis[j],min(dis[v],map[v][j])); //ת�Ʒ���
                //min(dis[v],map[v][j])��õ���1��j����·�ġ�·����
                //max()�������µ�1����j���·��      }
            }
            printf("Scenario #%d:\n",t);
            printf("%d\n\n",dis[n]);
        }
        return 0;
    }
