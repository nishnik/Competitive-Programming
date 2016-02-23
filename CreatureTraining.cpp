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

bool comp (pair<long,pair<long,int> > a,pair<long,pair<long,int> > b)
{
    return (float)a.first/(float)a.second.first > (float)b.first/(float)b.second.first; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n;
    vl count(n);
    vl power(n);
    rep(i,n)
        cin>>count[i];
    rep(i,n)
        cin>>power[i];
    vector<pair<long,pair<long,int> > > gain(n);
    gain[n-1].first=0;
    gain[n-1].second.first=0;
    gain[n-1].second.second=count[n-1];      
    

    for(int i=n-2;i>=0;i--)
    {
        if(power[i+1]>power[i])
        {
            gain[i].first=power[i+1]-power[i];
            gain[i].second.first=1;
            gain[i].second.second=count[i];      
        }
        else if(gain[i+1].second.first==0)
        {
            gain[i].first=0;
            gain[i].second.first=0;
            gain[i].second.second=count[i];
        }
        else
        {
            gain[i].first=gain[i+1].first+power[i+1]-power[i];
            gain[i].second.first=gain[i+1].second.first+1;
            gain[i].second.second=count[i];
        }

    }
    sort(all(gain),comp);

    cout<<"\n";
    rep(i,n)
        cout<<gain[i].first<<" ";
    cout<<"\n";
    rep(i,n)
        cout<<gain[i].second.first<<" ";
    
}
