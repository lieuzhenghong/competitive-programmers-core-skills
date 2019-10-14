#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int mini = INT_MAX;
	int maxi = INT_MIN;
	int minindex = 0;
	int maxindex = 0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(mini>a){
			mini = a;
			minindex = i;
		}
		if(maxi<a){
			maxi = a;
			maxindex = i;
		}
		cout<<min(minindex,maxindex)<<" "<<max(minindex,maxindex)<<endl;
	}	
}
