#include<bits/stdc++.h>
#define MAX 999999
using namespace std;
int N;
double C, Distance, avgD;
struct Node{
	double per;
	double dist;
};
int cmp(Node &n1, Node &n2){
	return n1.dist<n2.dist;
}
int main(){
	cin>>C>>Distance>>avgD>>N;
	if(N<=0){
		printf("The maximum travel distance = 0.00");
		return 0;	
	}
	vector<Node> List(N);
	double sumD=-1, sumP=0;
	double totalD=C*avgD;
	for(int i=0;i<N;i++){
		cin>>List[i].per>>List[i].dist;
	}
	sort(List.begin(), List.end(),cmp);
	if(List[0].dist!=0){
		printf("The maximum travel distance = 0.00");//测试点2！！！ 
		return 0;
	}
	int cur=0, next=1, flag=0;//flag==0, next all per prices>cur; flag==1, find cheaper one
	double oil=0, minPer=0, need=0;
	int minPos=0;
	while(cur<N && next<N && List[next].dist<Distance){//若加油站在终点之外的反例未被测试到 
		flag=0;
		minPer=MAX;
		minPos=MAX;
		while(next<N && List[next].dist-List[cur].dist<=totalD){
			if(List[next].per <  List[cur].per){
				flag=1;
				break;
			}
			if(List[next].per < minPer){
				minPer=List[next].per;
				minPos=next; 
			}
			next++;
		}
		if(flag==0 && minPos==MAX){//next is unreached
			break;
		}
		if(flag==1){//fill partial
			need=(List[next].dist-List[cur].dist)/avgD;
		}
		else{//fill the tank to full, no cheaper one
			if(List[cur].dist+totalD>Distance){//already can reach destination
				break;	//测试点4！！！ 
			}
			else{
				need=C;
				next=minPos;
			}
		}
		
		if(need>oil){
			sumP+=(need-oil)*List[cur].per;
			oil=need;
		}
		//arrive next station
		oil-=(List[next].dist-List[cur].dist)/avgD;
		cur=next;
		next++;
	}
	sumD=List[cur].dist+totalD;
	if(sumD<Distance){
		printf("The maximum travel distance = %.2f", sumD);
	}
	else{
		sumP+=(Distance-List[cur].dist)/avgD*List[cur].per;
		printf("%.2f", sumP);
	}
}
