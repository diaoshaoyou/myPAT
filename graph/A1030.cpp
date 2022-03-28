#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int Cost[501][501], Dist[501][501];//��Ŀ��֪�ĸ��������ͻ����Ĺ�ϵ 
int cost[501], dist[501];//��ǰ�����㵽����������� / ���� 
int visited[501];//��ǽڵ��Ƿ񱻷��ʹ� 
int pre[501]; //�����·����pre[i]��ʾ·���� i��ǰ��һ���� 
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
void Dijkstra(){//cost��distance��һ��Ƚ��� 
	visited[Start]=1;
	int target;
	int minD;//target���������ľ��� 
	for(int loop=1; loop<V;loop++){//δ�����ʵļ�����V-1���ڵ㣬����ѭ��V-1�� 
		minD=INF;
		//�Ҿ����������ģ� 
		for(int i=0;i<V;i++){
			if(visited[i]==0 && dist[i]<minD){
				minD=dist[i];
				target=i;
			}
		} 
		visited[target]=1;//�ҵ�������ĵ�,�����ѱ����ʵļ��� 

		//update dist
		for(int i=0;i<V;i++){//i��ʣ��δ�����ʵĵ� 
			if(visited[i]==0){
				if(dist[i] > minD+Dist[target][i]){//��·������target�������·�������� 
					dist[i]=minD+Dist[target][i];
					pre[i]=target;//��������·�����ڵ�i��ǰһ�������target
					cost[i]=cost[target]+Cost[target][i];//·�����ˣ�cost�������Ҳ���ű� 
				}
				else if(dist[i]==minD+Dist[target][i] && cost[i] > cost[target]+Cost[target][i]){//·������ͬ����Ƚ�cost 
					cost[i]=cost[target]+Cost[target][i];//��cost����target�������cost�� ���� 
					pre[i]=target;//��������·�����ڵ�i��ǰһ�������target
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
	}//��ʱpath�Ǵ�Dest->Start�ģ�Ҫ�ߵ� 
	reverse(path.begin(), path.end());
	for(auto i=path.begin(); i!=path.end();i++){
		cout<<*i<<" ";
	}
	cout<<dist[Dest]<<" "<<cost[Dest];
}
