#include <bits/stdc++.h>
using namespace std;
string Num[10]={"ling","yi","er","san","si","wu","liu", "qi", "ba", "jiu"}; 
string Wei[5]={"Shi","Bai","Qian","Wan","Yi"};
int main(){
	vector<char> Number;
	vector<string> out;
	string str;
	char ch;
	while(1){
		scanf("%c", &ch);
		if(ch=='\n')
			break;
		Number.emplace_back(ch);
	}
	reverse(Number.begin(), Number.end());

	int i=0;
	int zero=0, rezero=0;
	int L=Number.size();
	if(L==1){//单个0别忘了处理 
		cout<<Num[Number[i]-'0'];
		return 0;
	}
	while(i<L){
		str.clear();
		if(Number[i]=='-'){
			str="Fu";
		}
		else if(Number[i]=='0'){	
			zero++;
			if(i%4+1!=zero){//当0夹在两数中间，而非做结尾 
				if(rezero!=1){//若夹在两数中间的0不止1个，只输出一个"ling" 
					rezero=1;
					str="ling";
				}
			}
			if(i==4){
				str=Wei[3];//当万位=0，必须输出"Wan" 
			}
		}
		else{//!='0'  不存在0的情况，好解决 
			zero=0;
			rezero=0;
			if(i%4==1){
				str=Num[Number[i]-'0']+" ";
				str+=Wei[0]; 
			}
			else if(i%4==2){
				str=Num[Number[i]-'0']+" ";
				str+=Wei[1]; 
			}
			else if(i%4==3){
				str=Num[Number[i]-'0']+" ";
				str+=Wei[2]; 
			}
			else if(i==8){
				str=Num[Number[i]-'0']+" ";
				str+=Wei[4];
			}
			else {//i==0 or i==4
				str=Num[Number[i]-'0'];
				if(i==4){
					str+=" ";
					str+=Wei[3];
				}
			}
		}
		if(!str.empty())//当夹在两数中间的0不止一个时，str未被赋值，clear之后默认为空格，不能输出 
			out.emplace_back(str);
		i++;
	}
	for(int i=out.size()-1;i>=0;i--){
		cout<<out[i];
		if(i>0) cout<<" "; 
		
	}
	return 0;
} 
