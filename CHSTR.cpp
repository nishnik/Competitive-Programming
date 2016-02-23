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

vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

void f(vector<long long> &cnt,string s)
{

	int n=s.length();
	vector<int> z(n,n+1);
	int l=0;
	int r=n-1;
	z[0]=n;
	for(int i=1;i<n;i++)
	{
		cout<<i<<" "<<l<<" "<<r<<" ";
		if(i>r)
		{
			l=r=i;

			while(s[r]==s[r-l] && r<n)
				r++;
			z[i]=r-l;
		}
		else
		{
			int k=i-l;
			if(z[k]<r-i+1 && k<i)
				{

				z[i]=z[k];
				}
			else
			{
				l=r=i;
				while(s[r]==s[r-l] && r<n)
					r++;
				z[i]=r-l;
			}
		}
		cout<<z[i]<<"\n ";
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			cnt[i]=z[j]>i+1;
		}
	}
}

/*
void f(vector<long long> &cnt,string s)
{
	
	int n=s.length();
	vector<int> z(n,n+1);
	int l=0;
	int r=0;
	z[0]=n;
	for(int i=1;i<n;i++)
	{
		cout<<i<<" "<<l<<" "<<r<<" ";
		if(i>r)
		{
			l=r=i;

			while(s[r]==s[r-l] && r<n)
				r++;
			z[i]=r-l;
		}
		else
		{
			int k=i-l;
			if(z[k]<r-i+1 && k<i)
				{

				z[i]=z[k];
				}
			else
			{
				l=r=i;
				while(s[r]==s[r-l] && r<n)
					r++;
				z[i]=r-l;
			}
		}
		cout<<z[i]<<"\n ";
	}
}*/
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		vector<long long> cnt(n,0);
		//for(int i=0;i<n;i++)
		f(cnt,s.substr(0,n));

	}
}
