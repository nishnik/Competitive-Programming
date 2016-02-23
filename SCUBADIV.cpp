#include <bits/stdc++.h>

//usage getline(cin,str_name);



#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define rrep(i, n) for(__typeof(n) i = (n) - 1; i >= 0; --i)
#define rep1(i, n) for(__typeof(n) i = 1; i <= (n); i++)
#define FOR(i, a, b) for(__typeof(b) i = (a); i <= (b); i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define all(a)       a.begin(),a.end()
#define rall(a)      a.rbegin(),a.rend()

#define ll long long
#define vi vector<int>
#define vvi vector<vi >
#define vl vector<long>
#define vvl vector<vl >
#define vll vector<long long>
#define vvll vector<vll >
#define mp make_pair


/*
Usage: Just create an instance of it at the start of the block of
which you want to measure running time. Reliable up to millisecond
scale. You don't need to do anything else, even works with freopen.
*/
 
class TimeTracker {
    clock_t start, end;
public:
    TimeTracker() {
        start = clock();
    }
    ~TimeTracker() {
        end = clock();
        //fprintf(stderr, "%.3lf s\n", (double)(end - start) / CLOCKS_PER_SEC);
    }
};
 
using namespace std;

struct data
{
	int o;
	int ni;
	int w;
};

int n;
vector<data> arr;
int dp[1005][22][80];
long solve(int i,int o,int ni)
{
	if(dp[i][o][ni]!=-1)
		return dp[i][o][ni];
	if(o==0 && ni==0)
	{
		dp[i][o][ni] = 0;
	}
	else if(i==0)
		dp[i][o][ni] = 9999999;
	else
		dp[i][o][ni]=min((arr[i-1].w+solve(i-1,max(0,o-arr[i-1].o),max(0,ni-arr[i-1].ni))),(solve(i-1,o,ni)));
	
	return dp[i][o][ni];
}
bool comp(data a,data b)
{
	return a.w<b.w;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int o,ni;
		cin>>o>>ni;
		
		cin>>n;

		arr.resize(n);
		rep(i,n+1)
			rep(j,o+1)
				rep(k,ni+1)
				{
					dp[i][j][k]=-1;
				}
		for(int i=0;i<n;i++)
		{
			cin>>arr[i].o>>arr[i].ni>>arr[i].w;
		}
		//sort(all(arr),comp);
		cout<<solve(n,o,ni);


	}
}
