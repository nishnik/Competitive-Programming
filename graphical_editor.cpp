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

int main()
{
	std::vector<std::vector<char> > v(250,std::vector<char>(250));
	int a,b;
	while(1)
	{
		string s;
		getline(cin,s);
		if(s[0]=='I')
		{
			int d;
			for(int i=3;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					d=i;break;
				}
			}
			b=stoi(s.substr(2,d));
			a=stoi(s.substr(d,s.length()));
			for(int i=0;i<a;i++)
			{
				rep(j,b)
				v[i][j]='0';
			}
		}
		if(s[0]=='C')
		{
			for(int i=0;i<a;i++)
			{
				rep(j,b)
				v[i][j]='0';
			}	
		}
		else if(s[0]=='L')
		{
			int d;
			for(int i=3;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					d=i;break;
				}
			}
			int y=stoi(s.substr(2,d));
			int x=stoi(s.substr(d+1,s.length()-2));
			char c=s[s.length()-1];
			v[x-1][y-1]=c;
		}
		else if(s[0]=='V')
		{
			int d;
			for(int i=3;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					d=i;break;
				}
			}
			int y=stoi(s.substr(2,d));
			int d2;
			for(int i=d+1;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					d2=i;break;
				}
			}
			int xa=stoi(s.substr(d+1,d2));
			int xb=stoi(s.substr(d2+1,s.length()-2));
			int x1=min(xa,xb);
			int x2=max(xa,xb);
			char c=s[s.length()-1];
			for(int i=x1-1;i<=x2-1;i++)
			{
				v[i][y-1]=c;
			}
		}
		else if(s[0]=='H')
		{
			int d;
			for(int i=3;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					d=i;break;
				}
			}
			int y1=stoi(s.substr(2,d));
			int d2;
			for(int i=d+1;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					d2=i;break;
				}
			}
			int y2=stoi(s.substr(d+1,d2));
			int x=stoi(s.substr(d2+1,s.length()-2));
			int ya=min(y1,y2);
			int yb=max(y1,y2);
			char c=s[s.length()-1];
			for(int i=ya-1;i<=yb-1;i++)
			{
				v[x-1][i]=c;
			}	
		}
		else if(s[0]=='K')
		{
			int d;
			for(int i=3;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					d=i;break;
				}
			}
			int xa=stoi(s.substr(2,d));
			int d2;
			for(int i=d+1;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					d2=i;break;
				}
			}
			int ya=stoi(s.substr(d+1,d2));
			int d3;
			for(int i=d2+1;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					d3=i;break;
				}
			}

			int xb=stoi(s.substr(d2+1,d3));
			int yb=stoi(s.substr(d3+1,s.length()-2));
			int x1=min(xa,xb);
			int x2=max(xa,xb);
			int y1=min(ya,yb);
			int y2=max(ya,yb);
			char c=s[s.length()-1];
			FOR(i,x1-1,x2-1)
			{
				FOR(j,y1-1,y2-1)
				v[i][j]=c;
			}
			
		}
		else if(s[0]=='F')
		{
			int d;
			for(int i=3;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					d=i;break;
				}
			}
			int x=stoi(s.substr(2,d));
			int y=stoi(s.substr(d+1,s.length()-2));
			char c=s[s.length()-1];
			char f=v[x-1][y-1];
			for(int i=0;i<a;i++)

			{
				for(int j=0;j<b;j++)
				{
					
				if(v[i][j]==f)
					v[i][j]=c;
				
			}
		}

		}
		else if(s[0]=='S')
		{
			cout<<s.substr(2,s.length())<<"\n";
			rep(i,a)
			{rep(j,b)
			cout<<v[i][j];
			cout<<"\n";}
		}
		else if(s[0]=='X')
			break;
	}

}
