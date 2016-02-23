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
#define push_back pb


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
int n,m;
    //cin>>n>>m;
    vector<string> arr(n);
    vector<vector<int> > chk(50,vector<int>(50,0));
    
int dfs(int i,int j)
{
    int flag;
    queue<char> q;
    q.pb(arr[i][j]);
    while(!s.empty())
    {
        char c=q.front();
        q.pop();
        for(int a=-1;a<=1;a++)
        {
            for(int b=-1;b<=1;b++)
            {
                if(arr[a+i][b+j]==c && a+i>=0 && b+j>=0 && a+i<m && b+j<n)
                {
                    if(chk[a+i][b+j]==0)
                        chk[a+i][b+j]=1;
                    else
                    {
                        flag=1;
                        break;
                    }
                    q.pb(arr[a+i][b+j]);

                }
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        getline(cin,arr[i]);
    rep(i,n)
        rep(j,m)
        {
            if(chk[i][j]==0)
                dfs(i,j);
        }

}
