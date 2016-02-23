#include <bits/stdc++.h>

//usage getline(cin,str_name);

#define s(n)                        scanf("%d",&n)
#define s2(x,y)             scanf("%d%d",&(x),&(y))
#define s3(x,y,z)           scanf("%d%d%d",&(x),&(y),&(z))
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%ld",&n)
#define sll(n)                      scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)



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
struct Point
{
    long x;
    long y;
};
bool comp(Point &a, Point &b)
{
    return a.x>b.x;
}
 
// Driver program to test above functions
int main()
{
    int t;
    s(t);
    while(t--)
    {

        int n;
        s(n);
        vector<vector<Point> > polygon(n);
        vector<long > max_x(n);
        map<long,int> mapping; 
        for(int i=0;i<n;i++)
        {
            int m;s(m);
            polygon[i].resize(m);
            for(int j=0;j<m;j++)
            {
                Point a;
                s(a.x);
                s(a.y);
                polygon[i][j]=a;
            }
            sort(polygon[i].begin(),polygon[i].end(),comp);
            max_x[i]=polygon[i][0].x;
            mapping[max_x[i]]=i;
        }
        sort(max_x.begin(),max_x.end(),comp);
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            res[mapping[max_x[i]]]=n-i;
        }
        for(int i=0;i<n;i++)
        {
        cout<<res[i]<<"\n";
    }

            
         
            
        
    }
    return 0;
}