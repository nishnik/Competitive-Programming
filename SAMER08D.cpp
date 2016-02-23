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
	cin.tie(0);cout.tie(0);
    while(1)
    {
        int t;
        cin>>t;
        if(t==0)
            break;
        else
        {
            string a,b;
            cin.ignore();
            getline(cin,a);
            getline(cin,b);
            vector<pair<int,int> > first_a(a.length()+1,make_pair(0,0));
            vector<pair<int,int> > second_a(a.length()+1);
            for(int i=1;i<=b.length();i++)
            {
                for(int j=0;j<=a.length();j++)
                {

                    if(j==0)
                    {
                        second_a[j]=make_pair(0,0);
                    }
                    else
                    {
                        if(b[i-1]==a[j-1])
                        {
                                second_a[j].first=first_a[j-1].first+1;
                                if(second_a[j].first>=t)
                                {
                                    second_a[j].second=second_a[j].first+first_a[j-1].second-first_a[j-1].first;
                                    if(first_a[j-1].first<t)
                                        second_a[j].second+=first_a[j-1].first;
                                    second_a[j].second=max(second_a[j].second,max(second_a[j-1].second,first_a[j-1].second));
                                }
                                else
                                {
                                    second_a[j].second=max(first_a[j-1].second,second_a[j-1].second);
                                }

                            
                            

                        }
                        else
                        {
                            second_a[j].first=0;
                            second_a[j].second=max(first_a[j-1].second,max(first_a[j].second,second_a[j-1].second));
                        }
                    }
                }
                for(int j=0;j<=a.length();j++)
                {
                    first_a[j]=second_a[j];
                }
               /*cout<<"\n";
                rep(j,a.length()+1)
                    cout<<second_a[j].first<second_a[j].second<<" ";*/

            }

        cout<<second_a[a.length()].second<<"\n";   
        }
    }
    return 0;
}
