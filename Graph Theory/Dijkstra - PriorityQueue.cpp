#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define MAXN 100
using namespace std;
struct Edge {
    int v;
    int w;
    Edge(int v, int weight) {
        this->v = v;
        this->w = weight;
    }
};
struct Vertex {
    int v;
    int dis;
    Vertex() {
        v=0;
        dis=0;
    }
    Vertex(int v,int dis) {
        this->v = v;
        this->dis = dis;
    }
    friend bool operator < (Vertex a, Vertex b) {
        return a.dis > b.dis;
    }
};
vector<Edge*>Adj[MAXN];
void makeGraph(int eNum) {
    int u,v;
    int w;
    for(int i = 0; i < eNum; i++) {
        scanf("%d %d %d",&u,&v,&w);
        Adj[u].push_back(new Edge(v,w));
		Adj[v].push_back(new Edge(u,w));
    }
}
int dis[MAXN];
void dijkstra(int s) {
    bool isInTree[MAXN];
    memset(dis,0x7f,sizeof(dis));
	memset(isInTree,0,sizeof(isInTree));
    dis[s] = 0;
    priority_queue<Vertex>pQ;
    Vertex f;
    f.v=s;
    f.dis=0;
    Vertex next;
    pQ.push(f);
    while(!pQ.empty()) {
        f = pQ.top();
        pQ.pop();
        if(isInTree[f.v])
            continue;
        isInTree[f.v] = true;   //dis[f.v] will never be updated again, that is, the shortest path from s to f.v has been found.
        for(int i = 0; i < Adj[f.v].size(); i++) {  // ֻ��isInTree�ĵ㣬�����ʸ��ܹ������ɳڱ�ĵ㡣
													//���ȷ��IsInTree�ĵ�֮���ܱ��ɳڣ���ô��ǰͨ�������ɳڵĵ㶼Ҫ���и��£���û��Ū�ˡ���Ҳ��ΪʲôDijkstraҪ�����и��ߵ�ԭ��
            Edge* t = Adj[f.v][i];
            if(!isInTree[t->v] && dis[t->v]>dis[f.v]+t->w) {  //if t.v is in tree, we know it won't be updated. so don't need to bother
                dis[t->v] = dis[f.v]+t->w;                   //if t.v is not in tree, it still has the potential to be relaxed.
                next.v=t->v;
                next.dis=dis[t->v];
                pQ.push(next);    //ע���ڶ����еĵ㣬δ���������·���еĵ㡣��������Ǳ��ɳڹ��ĵ㣬����Щ���п��ܻ��ᱻ�ɳڡ�
								  //������decreaseKey�Ĳ������ã���û��ɾ���ɳ�ǰ��ֵ��ֻ�ǲ������ɳں��ֵ��
								  //�����Щ����ܻ��ڶ����г��ֶ�Σ�ֻ��dis��һ��������ֻ����dis��С���Ǹ��ͺã�pQ��֤�������ȷ��ʵ���һ����dis��С���Ǹ�����Ȼ������˿ռ���˷ѡ�������Ϸ��㡣
			}
        }
    }
}


int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    makeGraph(m);
    dijkstra(1);
    for(int i = 1; i <= n; i++){
        cout<<dis[i]<<endl;
    }
	cin>>n;
}

