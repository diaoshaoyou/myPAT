//多条最短路径的Dijkstra算法 
#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int V, E, Start=0, Dest=0;
map<string, int> City;
string Name[201];
int Cost[201][201];
int Happy[201];
int visited[201];
vector<int> pre[201];//存多条最短路径的前驱点 
int cost[201];
vector<int> Path, tmpPath;
int maxHappy=0;
double maxAvg=0;
int pathN=0;
void Dijkstra(){
	int minC, target;
	cost[Start]=0; 
	for(int loop=0;loop<V;loop++){//第一次找到的最近点就是Start 
		minC=INF;
		target=-1;
		//找cost最小的点
		for(int i=0;i<V;i++){
			if(visited[i]==0 && minC>cost[i]){
				minC=cost[i];
				target=i;
			}
		} 
		if(target==-1) return ;
		visited[target]=1; 
		//update 
		for(int i=0;i<V;i++){
			if(visited[i]==0 && cost[i]>minC+Cost[target][i]){
				cost[i]=minC+Cost[target][i];
				pre[i].clear();//清空原来记录的最短路径 
				pre[i].emplace_back(target);
			}
			else if(visited[i]==0 && cost[i]==minC+Cost[target][i]){
				pre[i].emplace_back(target); 
			}
		}
	}
}

void dfs(int dest){
	tmpPath.emplace_back(dest);
	if(dest==0){
		pathN++;
		int sum=0;
		double avg=0;
		for(auto i=tmpPath.begin(); i!=tmpPath.end(); i++){
			sum+=Happy[*i];
		}
		avg=1.0*sum/(tmpPath.size()-1);
		if(sum>maxHappy){
			maxHappy=sum;
			maxAvg=avg;
			Path.assign(tmpPath.begin(), tmpPath.end());
		}
		else if(sum==maxHappy && avg>maxAvg){
			maxAvg=avg;
			Path.assign(tmpPath.begin(), tmpPath.end());
		}
//		tmpPath.clear();//不能直接清除，有可能2条路径共用了部分节点！！！！ 
	}
	else{
		for(auto it=pre[dest].begin(); it!=pre[dest].end(); it++){
			dfs(*it);
		}	
	}
	tmpPath.pop_back();//当前点走完后要pop，回到父节点，方便父节点dfs下一个孩子 
}
int main(){
	string city1, city2;
	cin>>V>>E>>city1;
	if(V<2) return 0;
	
	//init
	fill(Happy, Happy+201, 0);
	fill(Cost[0], Cost[0]+201*201, INF);
	fill(visited, visited+201, 0);
	fill(cost, cost+201, INF);
	//read	
	City.insert(pair<string, int>(city1, 0));
	Name[0]=city1;
	for(int i=1;i<V;i++){
		cin>>city1;
		City.insert(pair<string, int>(city1, i));
		Name[i]=city1;
		cin>>Happy[i];
	}
	Dest=City["ROM"];
	int c;
	for(int i=0;i<E;i++){
		cin>>city1>>city2>>c;
		Cost[City[city1]][City[city2]]=c;
		Cost[City[city2]][City[city1]]=c;
	}
	Dijkstra();//find shortest path
	dfs(Dest);//find best path
	
	reverse(Path.begin(), Path.end());
	cout<<pathN<<" "<<cost[Dest]<<" "<<maxHappy<<" "<<(int)maxAvg<<endl;
	for(auto it=Path.begin(); it!=Path.end();it++){
		if(it>Path.begin())
			cout<<"->";
		cout<<Name[*it];
	}
} 
