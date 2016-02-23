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
    int n,m;
    cin>>n>>m;
    vi arr(n,0);
    for(int i=0;i<m;i++)
    {
        long max=0;
        int pos=0;
        rep(j,n)
        {
            long a;
            cin>>a;
            if(a>max)
               { max=a;
                pos=j;
            }
        }
        arr[pos]++;
    }
    int pos=0;int max=arr[pos];
    rep(i,n)
    {
        if(arr[i]>max)
        {
            pos=i;
            max=arr[pos];

        }
    }
    cout<<pos+1;
}
