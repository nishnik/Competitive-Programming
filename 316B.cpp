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

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
    long m,n;
    cin>>n>>m;
    long ans=-1;
    if(n%2)
    {
        if(m<(n+1)/2)
            ans=m+1;
        else if(m>=(n+1)/2)
            ans=m-1;
    }
    else
    {
        if(m<=n/2)
            ans=m+1;
        else
            ans =m-1;
    }
    if(ans==0)
        ans=1;
    cout<<ans;
}
