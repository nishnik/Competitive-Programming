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
    long n,m;
    cin>>n>>m;
    vector<vector<long> > child(n+1);
    vector<long> level(n+1);
    level[0]=-1;
    level[1]=0;
    child[0].push_back(-1000);
    child[1].push_back(-1);
    long a;
    for(int i=2;i<=n;i++)
    {
        cin>>a;
        child[a].push_back(i);
        level[i]=level[a]+1;
    }
    string s;
    cin.ignore();
    getline(cin,s);
    while(m--)
    {
        long a,b;
        cin>>a>>b;
        if(level[a]!=)
    }
}
