#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

//usage getline(cin,str_name);

#define s(n)                        scanf("%d",&n)
#define s2(x,y)			    scanf("%d%d",&(x),&(y))
#define s3(x,y,z)		    scanf("%d%d%d",&(x),&(y),&(z))
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

int main()
{
	int t=1;
	while(1)
	{
		int a,b;

		s2(a,b);
		if(a==0)
			return 0;
		vector<string> arr(a);
		rep(i,a)
		{
			cin>>arr[i];
			
		}
		rep(i,a)
		{
			rep(j,b)
			{
				if(arr[i][j]!='*')
				{
					int count=0;
					FOR(c,-1,1)
					{
						FOR(d,-1,1)
						{
							if(c+i>=0 && c+i<a && d+j>=0 && d+j<b)
							{
								if(arr[c+i][d+j]=='*')
									count++;
							}
						}
					}
					arr[i][j]=count+'0';
				}
			}
		}
		cout<<"Field#"<<t<<":\n";
		rep(i,a)
		{
			cout<<"\n";
			cout<<arr[i];
		}
		cout<<"\n";
		t++;
	}

}
