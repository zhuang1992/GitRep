//DFS 
//访问完节点的所有子节点后，将该节点压栈。

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
class toposort{
public:
	static const int MAXN = 100;
	struct edge{
		int v;
		int w;
		edge* next;
		edge(int v,int w){
			this->v = v;
			this->w = w;
			this->next = NULL;
		}
	};
	struct adjlist{
		edge* first;
	}Adj[MAXN];
	bool grey[MAXN];
	toposort(){
		memset(Adj,0,sizeof(Adj));
		memset(grey,0,sizeof(grey));
	}
	void addEdge(int u, int v, int w){
		edge* ptr = Adj[u].first;
		if(ptr==NULL){
			Adj[u].first = new edge(v,w);
		}else{
			while(ptr->next!=NULL)
				ptr = ptr->next;
			ptr->next = new edge(v,w);
		}
	}
	void _topo(int i, stack<int>&S){
		grey[i] = true;
		edge*ptr = Adj[i].first;
		while(ptr!=NULL){
			if(!grey[ptr->v]){
				_topo(ptr->v, S);			
			}
			ptr = ptr->next;
		}
		S.push(i); //after visiting all of i's neighbor, push i to the path.
	}
	void topo(int n){
		stack<int>path;
		bool* hasInEdge = new bool(n);
		memset(hasInEdge,0,sizeof(hasInEdge));
		for(int i = 1; i <= n; i++){
			edge* ptr = Adj[i].first;
			while(ptr!=NULL){
				hasInEdge[ptr->v] = true;
				ptr = ptr->next;
			}
		}
		for(int i = 1; i <= n; i++){
			if(hasInEdge[i]==false){
				_topo(i,path);
				break;
			}
		}
		while(!path.empty()){
			cout<<path.top()<<endl;
			path.pop();
		}
	}
};
int main(){
	toposort test;
	int nodeNum,edgeNum;
	cin>>nodeNum>>edgeNum;
	for(int i = 0; i < edgeNum; i++){
		int u,v,w;
		cin>>u>>v>>w;
		test.addEdge(u,v,w);
	}
	test.topo(nodeNum);
	system("pause");
	return  0;
}