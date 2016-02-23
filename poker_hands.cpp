#include <bits/stdc++.h>

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
string suite="HDSC";

int hash(char &a, char &b)
{
	int val;
	for(int i=0;i<suite.length();i++)
	{
		if(b==suite[i])
		{
			val=13*i;
			break;
		}
	}
	if(a=='T')
		val+=9;
	else if(a=='J')
		val+=10;
	else if(a=='Q')
		val+=11;
	else if(a=='K')
		val+=12;
	else if(a=='A')
		val+=13;
	else
		val+=(a-'0'-1);
	
		
}
int straight_flush(vector<int> &w,vector<int> &b)
{
	int is_w=0,is_b=0;
	if(w[4]-w[0]==4)
		is_w=1;
	if(b[4]-b[0]==4)
		is_b=1;
	if(is_w==is_b && is_w==0)
		return 0;
	else if(is_w>is_b)
		return 1;
	else if(is_w < is_b)
		return 2;
	else
	{
		is_w=w[4]%13;
		is_b=b[4]%13;
		if(is_w==is_b)
			return 3;
		else if(is_w>is_b)
			return 1;
		else if(is_w < is_b)
			return 2;
		
	}
}

int four_of_a_kind(vector<int> &w,vector<int> &b)
{
	int is_w=0,is_b=0;
	
}

int main()
{
	string s;
	getline(cin,s);
	int b=0,w=0;
	vector<int> black(5),white(5);
	for(int i=0;i<s.length();i++)
	{
		if(i<s.length()/2)
		{
			black[b++]=hash(s[i],s[i+1]);

			i++;
		}
		else
		{
			white[w++]=hash(s[i],s[i+1]);
			i++;
		}
	}
	sort(all(black));
	sort(all(white));
	int straight_flush_result = straight_flush(white,black);
	if(straight_flush_result==1)
		cout<<"white wins";
	else if(straight_flush_result==2)
		cout<<"black wins";
	else if(straight_flush_result==3)
		cout<<"tie";
	else
	{
		int four_of_a_kind_result = four_of_a_kind(white,black);
	}
}
