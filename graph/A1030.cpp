#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int Cost[501][501], Dist[501][501];//题目已知的各个点距离和花销的关系 
int cost[501], dist[501];//当前各个点到起点的最近距离 / 花销 
int visited[501];//标记节点是否被访问过 
int pre[501]; //存最短路径，pre[i]表示路径中 i的前面一个点 
int E,V,Dest,Start;
class Vertex{
public:
	int ID;
	int dist;
	int cost;
	bool operator<(Vertex *v){
		if(this->dist == v->dist){
			return this->cost < v->cost;
		}
		else	return this->dist < v->dist;
	}
};
void Dijkstra(){//cost和distance放一起比较了 
	visited[Start]=1;
	int target;
	int minD;//target到起点最近的距离 
	for(int loop=1; loop<V;loop++){//未被访问的集合有V-1个节点，所以循环V-1次 
		minD=INF;
		//找距离起点最近的： 
		for(int i=0;i<V;i++){
			if(visited[i]==0 && dist[i]<minD){
				minD=dist[i];
				target=i;
			}
		} 
		visited[target]=1;//找到了最近的点,加入已被访问的集合 

		//update dist
		for(int i=0;i<V;i++){//i是剩余未被访问的点 
			if(visited[i]==0){
				if(dist[i] > minD+Dist[target][i]){//旧路径不如target参与的新路径，换掉 
					dist[i]=minD+Dist[target][i];
					pre[i]=target;//若改用新路径，节点i的前一个点就是target
					cost[i]=cost[target]+Cost[target][i];//路径变了，cost就算会变大也跟着变 
				}
				else if(dist[i]==minD+Dist[target][i] && cost[i] > cost[target]+Cost[target][i]){//路径长相同，则比较cost 
					cost[i]=cost[target]+Cost[target][i];//旧cost不如target参与的新cost， 换掉 
					pre[i]=target;//若改用新路径，节点i的前一个点就是target
				}
			}
					
		} 
	}

}
void init(){
	fill(Cost[0], Cost[0]+501*501, INF);
	fill(Dist[0], Dist[0]+501*501, INF);
	fill(cost, cost+501, INF);
	fill(dist, dist+501, INF);
	fill(visited, visited+501, 0);
	fill(pre, pre+501, -1); 
	for(int i=0;i<501;i++){
		Cost[i][i]=0;
		Dist[i][i]=0;
	}	
}
int main(){
	cin>>V>>E>>Start>>Dest;
	init();
	//read in:
	int v1, v2, c, d;
	for(int i=0;i<E;i++){
		cin>>v1>>v2>>d>>c;		
		Cost[v1][v2]=c;
		Cost[v2][v1]=c;
		Dist[v1][v2]=d;
		Dist[v2][v1]=d;
	}
	for(int i=0;i<V;i++){
		dist[i]=Dist[Start][i];	
		cost[i]=Cost[Start][i];
		if(dist[i]!=INF)
			pre[i]=Start;
	}
	Dijkstra();
	
	//print out:
	vector<int> path;
	int k=Dest;
	while(1){
		path.emplace_back(k); 
		if(k==Start) break;
		k=pre[k];
	}//此时path是从Dest->Start的，要颠倒 
	reverse(path.begin(), path.end());
	for(auto i=path.begin(); i!=path.end();i++){
		cout<<*i<<" ";
	}
	cout<<dist[Dest]<<" "<<cost[Dest];
}
