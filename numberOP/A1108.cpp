#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<double> valid;
	string str;
	vector<string> print;
	int flag=1, j=0;
	for(int i=0;i<N;i++){
		cin>>str;
		flag=1;
		j=0;
		if(str.find_first_of('.')!=str.find_last_of('.')){//one more .
			flag=0;
		}
		else if(str.find('.')!=str.npos && str.length()-str.find_first_of('.')>3){//用长度差判断小数位数时，必须先保证存在小数点 
			flag=0;
		}
		else{
			while(j<26){
				if(str.find('a'+j)!=str.npos){
					flag=0;
					break;
				}
				else if(str.find('A'+j)!=str.npos){
					flag=0;
					break;
				}
				j++;
			}
			if(flag==1 && (stof(str)>1000 || stof(str)<-1000))
				flag=0;
		}
		if(flag==0){
			print.emplace_back("ERROR: "+str+" is not a legal number\n");
		}
		else{
			valid.emplace_back(stof(str));
		}
	}
	
	for(auto it=print.begin(); it!=print.end();it++){
		cout<<*it;
	}
	if(valid.empty()){
		cout<<"The average of 0 numbers is Undefined";
	}
	else if(valid.size()==1){
		printf("The average of 1 number is %.2f",valid[0]);
	}
	else{
		double sum=0;
		for(auto it=valid.begin();it!=valid.end();it++){
			sum+=*it;
		}
		sum/=valid.size();
		printf("The average of %d numbers is %.2f", valid.size(), sum);
	}
}
