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

int main()
{
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    int count=0;
    for(int i=2;i<n+1;i++)
    {
        if(arr[i]==0)
            {
                int flag=-1;
        for(int j=i-1;j>=2;j--)
        {   
            /*if(i==16 && j==8)
                cout<<"---"<<arr[j]<<
*/
            if(i%j==0 && arr[j]!=1 && arr[i/j]==1 )
            {
                arr[j]=1;
                flag=j;
                break;
            }

        }
        int q;
        if(flag==-1)
            {arr[i]=1;q=i;}
        else
            {q=flag;}
        count++;
        
        for(int j=i-1;j>=2;j--)
        {
            if(q*j<=n && arr[j]==1)
                arr[q*j]=2;

            

        }
        }
    }
    cout<<count<<"\n";
    for(int i=2;i<=n ;i++)
    {
        if(arr[i]==1)
            cout<<i<<" ";
    }

}
