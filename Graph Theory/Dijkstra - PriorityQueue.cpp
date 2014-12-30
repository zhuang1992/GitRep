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
        for(int i = 0; i < Adj[f.v].size(); i++) {  // 只有isInTree的点，才有资格能过它来松弛别的点。
													//如果确定IsInTree的点之后还能被松弛，那么以前通过它被松弛的点都要进行更新，就没法弄了。这也是为什么Dijkstra要求不能有负边的原因。
            Edge* t = Adj[f.v][i];
            if(!isInTree[t->v] && dis[t->v]>dis[f.v]+t->w) {  //if t.v is in tree, we know it won't be updated. so don't need to bother
                dis[t->v] = dis[f.v]+t->w;                   //if t.v is not in tree, it still has the potential to be relaxed.
                next.v=t->v;
                next.dis=dis[t->v];
                pQ.push(next);    //注意在队列中的点，未必是在最短路树中的点。它储存的是被松弛过的点，而这些点有可能还会被松弛。
								  //它起到了decreaseKey的部分作用，但没有删除松弛前的值，只是插入了松弛后的值。
								  //因此有些点可能会在队列中出现多次，只是dis不一样。我们只关心dis最小的那个就好，pQ保证了我们先访问到的一定是dis最小的那个。当然这造成了空间的浪费。但编码较方便。
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

