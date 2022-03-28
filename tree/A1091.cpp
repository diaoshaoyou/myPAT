//先后改了4种思路 !!!
#include<bits/stdc++.h>
using namespace std;
int L1, L2, N, Limit;
int maxSize=1; 
int M[61][1290][1290];//==0, not; ==1, stroke; ==-1, visited
class Pos{
public:
	int level;
	int x;
	int y;
	void assign(int p1, int p2, int p3){
		level=p1;
		x=p2;
		y=p3;
	}
};
void bfs(int root1, int root2, int root3){//root position
	queue<Pos> Q;
	int p1, p2, p3;
	Pos pos, cur;
	pos.assign(root1, root2, root3);
	Q.push(pos);
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		p1=cur.level;
		p2=cur.x;
		p3=cur.y;
		if(p1>0 && M[p1-1][p2][p3]==1){
			M[p1-1][p2][p3]=-1;
			maxSize++;
			pos.assign(p1-1, p2, p3);
			Q.push(pos);
		}
		if(p1<N-1 && M[p1+1][p2][p3]==1){
			M[p1+1][p2][p3]=-1;
			maxSize++;
			pos.assign(p1+1, p2, p3);
			Q.push(pos);			
		}
		if(p2>0 && M[p1][p2-1][p3]==1){
			M[p1][p2-1][p3]=-1;
			maxSize++;
			pos.assign(p1, p2-1, p3);
			Q.push(pos);
		}
		if(p2<L1-1 && M[p1][p2+1][p3]==1){
			M[p1][p2+1][p3]=-1;
			maxSize++;
			pos.assign(p1, p2+1, p3);
			Q.push(pos);
		}	
		if(p3>0 && M[p1][p2][p3-1]==1){
			M[p1][p2][p3-1]=-1;
			maxSize++;
			pos.assign(p1, p2, p3-1);
			Q.push(pos);
		}
		if(p3<L2-1 && M[p1][p2][p3+1]==1){
			M[p1][p2][p3+1]=-1;
			maxSize++;
			pos.assign(p1, p2, p3+1);
			Q.push(pos);
		}
	
	}
}

int main(){
	cin>>L1>>L2>>N>>Limit;
	for(int level=0;level<N;level++){
	 	for(int i=0;i<L1;i++){
		 	for(int j=0;j<L2;j++){
				cin>>M[level][i][j];			 	
			}
		}
	}

	int sum=0;
	for(int level=0;level<N;level++){
		for(int i=0;i<L1;i++){
			for(int j=0;j<L2;j++){
				if(M[level][i][j]==1){
					maxSize=1;
					M[level][i][j]=-1;
				 	bfs(level, i, j);	
					if(maxSize>=Limit)
						sum+=maxSize;	
				}
			}
		}
	}
	cout<<sum;
	return 0;
} 
