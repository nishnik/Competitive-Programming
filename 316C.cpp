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
	//cin.tie(0);cout.tie(0);
    string s;
    long len,q;
    cin>>len>>q;
    cin.ignore();
    getline(cin,s);
    vl arr(len,0);
    //vector<> arr;
    long tot=0,seg=0;
    for(long i=0;i<len;i++)
    {
        if(i==0)
        {
            if(s[i]=='.')
            {
                tot++;seg++;
            }
        }
        else
        {
            if(s[i]=='.' && s[i-1]=='.')
                tot++;
            else if(s[i]=='.' && s[i-1]!='.')
            {
                seg++;tot++;
            }
        }
    }
    while(q--)
    {
        long a;
        char c;
        cin>>a>>c;
        a--;
        if(c=='.')
        {
            
            if(s[a]=='.');
            else
            {
                tot++;
                if(s[a-1]=='.' && s[a+1]=='.' && a>=0 && a<len)
                {
                    seg--;
                }
                else if((s[a-1]!='.' || a==0) && (s[a+1]!='.' || a==len-1))
                {
                    seg++;
                }
            }
        }
        else
        {
            if(s[a]!='.');
            else
            {
                tot--;
                if(s[a-1]=='.' && s[a+1]=='.' && a!=0 && a!=len-1)
                {
                    seg++;
                }
                else if((s[a-1]!='.' || a==0) && (s[a+1]!='.'|| a==len))
                {
                    seg--;
                }
            }
        }
        s[a]=c;
        cout<<tot-seg<<"\n";
    }

}
