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

bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}

int main()
{
	ios::sync_with_stdio(false);
    int t=1;
    while(1)
    {
        string s;
        getline(cin,s);
        if(s=="bye")
            break;
        vector<pair<int,int> > arr(s.length());
        arr[0].first=s[0]-48;
        arr[0].second=1;
        for(int i=1;i<s.length();i++)
        {
            arr[i].first=arr[i-1].first+(int)s[i]-48;
            arr[i].second=i+1;
            cout<<arr[i].first<<" ";
        }
        cout<<"\n";
        int tot=arr[s.length()-1].first;
        int count[s.length()];
        int ans=0;
        count[0]=0;
        for(int i=1;i<s.length();i++)
        {
            if(arr[i])
        }   
        cout<<ans<<"\n";
    }

}
