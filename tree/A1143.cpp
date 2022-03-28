//inorder+preorder求树的方法又忘记了，得多重复几遍
//真的不用建树就能写！！LCA是pre中第一个介于v和u之间的数 
#include<bits/stdc++.h>
using namespace std;
vector<int> pre;
int N;

int main(){
	int M,node1,node2;
	vector<string> res;
	set<int> S; 
	string str;
	//read in:
	cin>>M>>N;
	for(int i=0;i<N;i++){
		cin>>node1;
		S.emplace(node1);
		pre.emplace_back(node1);
	}
	
	//check
	int flag1=1, flag2=1;
	for(int i=0;i<M;i++){
		cin>>node1>>node2;
		str.clear();
		flag1=(S.find(node1)==S.end());
		flag2=(S.find(node2)==S.end());
		if(flag1&&flag2){
			str="ERROR: "+to_string(node1)+" and "+to_string(node2)+" are not found.";
		}
		else if(!flag1&&flag2){
			str="ERROR: "+to_string(node2)+" is not found.";
		}
		else if(flag1&&!flag2){
			str="ERROR: "+to_string(node1)+" is not found.";
		}
		else{
			int lca;
			for(int j=0;j<N;j++){
				if((node1>=pre[j]&&node2<=pre[j])||(node1<=pre[j]&&node2>=pre[j])){
					lca=pre[j];
					break;
				}
			} 
			if(lca==node2)
				str=to_string(node2)+" is an ancestor of "+to_string(node1)+".";
			else if(lca==node1)
				str=to_string(node1)+" is an ancestor of "+to_string(node2)+".";
			else
				str="LCA of "+to_string(node1)+" and "+to_string(node2)+" is "+to_string(lca)+".";
		}
		res.emplace_back(str);
	}
	for(int i=0;i<M;i++){
		if(i>0) cout<<endl;
		cout<<res[i];
	}
}
