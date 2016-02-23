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

bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second > b.second;
}
bool comp_sec(pair<int,int> a,pair<int,int> b)
{
    return a.second <= b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<pair<int,int> > arr(m);
        rep(i,m)
        {
            cin>>arr[i].first>>arr[i].second;
        }
        sort(all(arr),comp);
        vector<pair<int,int> > v;
        v.push_back(arr[m-1]);
        for(int i=m-2;i>=0;i--)
        {
            vector<pair<int,int> >::iterator up = upper_bound(all(v),arr[i],comp_sec);
            if(up==v.end())
                v.push_back(arr[i]);
            else
            {
               up->second=arr[i].second;
                up->first=arr[i].first;
            }
        }

    cout<<v.size()<<"\n";
    }
}
