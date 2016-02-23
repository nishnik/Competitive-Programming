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
	int t;
	cin>>t;
	while(t--)
	{
		int len;
		cin>>len;
		string s;
		int k;
		cin>>k;
		cin>>s;
		char prev=s[0];
		vi curr(len,0);
		int flip=0;
		curr[0]=1;
		if(k>1)
		{
			for(int i=1;i<len;i++)
			{
				if(s[i-1]==s[i])
					{
						curr[i]=curr[i-1]+1;
						if(curr[i]>k)
						{

							if(s[i+1]==s[i] || i==len-1 || curr[i-2]==k-1)
								s[i]=(s[i]=='1'?'0':'1');
							else
								s[i-1]=(s[i-1]=='1'?'0':'1');
							flip++;
						}

					}
				else 
					curr[i]=1;
			}
			cout<<flip<<"\n"<<s<<"\n";
		}
		else
		{
			int count1=0;string s1;s1.resize(len);
			int count2=0;string s2;s2.resize(len);
			for(int i=0;i<len;i++)
			{
				s1[i]=48+i%2;
				s2[i]=48+(i+1)%2;
				
				if((s[i]-48)-i%2==0)
				{
					count2++;
				}
				else 
					count1++;

			}
			if(count1<count2)
				cout<<count1<<"\n"<<s1;
			else

				cout<<count1<<"\n"<<s1;
		}
	}
}
