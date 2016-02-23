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

vector<long> z_function(string s)
{
	long n=s.length();

	vector<long> z(n);
	long l=0,r=0;
	z[0]=n;
	for(long i=1;i<n;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(s[r-l]==s[r] && r<n)
				r++;
			z[i]=r-l;r--;
		}	
		else
		{
			long k=i-l;
			if(z[k]<r-i+1)
				z[i]=z[k];
			else
			{
				l=i;
				while(r<n && s[r-l]==s[r])
				{
					r++;
				}
				z[i]=r-l;r--;
			}
		}

	}
	return z;
}


int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		vector<long> z=z_function(s);
		long q;
		cin>>q;
		int size=z.size();
		while(q--)
		{
			long a;
			cin>>a;
			cout<<z[size-a]<<"\n";
		}
	}
}