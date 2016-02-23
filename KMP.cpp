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

vector<int> computeLPS(string s)
{
	int len=0;
	int size=s.length();
	vector<int> lps(size);
	lps[0]=0;
	int i=1;
	while(i<size)
	{
		if(s[i]==s[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	return lps;
}

vector<int> KMPSearch(string pat,string txt)
{
	vector<int> lps=computeLPS(pat);
	int i=0;//for txt
	int j=0;//for pat
	int size_txt=txt.length();
	int size_pat=pat.length();
	vector<int> res(size_txt);
	while(i<size_txt)
	{
		if(pat[j]==txt[i])
		{
			res[i]=j+1;
			j++;
			i++;
		}
		if(j==size_pat)
		{
			//found
			j=lps[j-1];
		}
		else if(i<size_txt && pat[j]!=txt[i])
		{
			if(j!=0)
				j=lps[j-1];
			else
			{
				res[i]=0;
				i++;
			}
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	string s="ababderasdabahab";
	vector<int> res=KMPSearch("aba",s);
	for(int i=0;i<res.size();i++)
	{
		cout<<s[i]<<" "<<res[i]<<"\n";
	}
}
