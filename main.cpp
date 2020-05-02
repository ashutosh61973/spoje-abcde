#include <iostream>
#include<set>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int main(){
vector<long long>set;
vector<long long>lhs;
vector<long long>rhs;
long long n;
cin>>n;
for(int i=0;i<n;i++)
{
	long long v;cin>>v;
	set.push_back(v);
}
for(long long  i=0;i<n;i++)
{
	for(long long j=0;j<n;j++)
	{
		for(long long k=0;k<n;k++)
		{
			lhs.push_back(set[i]*set[j]+set[k]);
		}
	}
}
for(long long  i=0;i<n;i++)
{
	for(long long j=0;j<n;j++)
	{
		for(long long k=0;k<n;k++)
		{
			if(set[k]!=0)
			rhs.push_back((set[i]+set[j])*set[k]);
			
		}
	}
}
sort(lhs.begin(),lhs.end());
sort(rhs.begin(),rhs.end());
long long combi=0;
vector<long long>::iterator lloit,lupit;
vector<long long>::iterator rloit,rupit;
for(lloit=lhs.begin();lloit!=lhs.end();lloit=lupit)
{
	lloit=lower_bound(lhs.begin(),lhs.end(),*lloit);
	lupit=upper_bound(lhs.begin(),lhs.end(),*lloit);
	rloit=lower_bound(rhs.begin(),rhs.end(),*lloit);
	rupit=upper_bound(rhs.begin(),rhs.end(),*lloit);
	combi=combi+((lupit-lloit)*(rloit-rupit));
}
cout<<-combi;


}

