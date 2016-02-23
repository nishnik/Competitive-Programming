#include <bits/stdc++.h>

//usage getline(cin,str_name);

#define s(n)                        scanf("%d",&n)
#define s2(x,y)			    scanf("%d%d",&(x),&(y))
#define s3(x,y,z)		    scanf("%d%d%d",&(x),&(y),&(z))
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%ld",&n)
#define sll(n)                      scanf("%lld",&n)
#define sf(n)                       scanf("%f",&n)
#define ss(n)                       scanf("%s",n)
#define sd(n)						scanf("%lf",&n)



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
	while(1)
	{
		int t;
		s(t);
		if(t==0) break;
		double arr[t];
		double tot=0;
		rep(i,t)
			{sd(arr[i]);tot+=arr[i];}
		tot/=t;
		double pos=0.00,neg=0.00;
		rep(i,t)
		{
			if(arr[i]>tot)
			{
				cout<<"\n"<<arr[i]<<" "<<arr[i]*1000<<tot<<" "<<tot*1000;
			
				pos=pos+(int)arr[i]*1000-(int)tot*1000;
				cout<<"\n"<<pos;
			}
			
		}
		cout<<"\n"<<pos<<" "<<neg<<"\n";


	}
}