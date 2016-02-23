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

bool comp(pair<long,long> T,pair<long,long> W)
{
    return T.second>W.second;
}

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
    int n,s,no_s=0;
    cin>>n>>s;
    //cin.ignore();
    vector<pair<long,long> > buy(100000,make_pair(-1,-1));
    vector<pair<long,long> > sell(100000,make_pair(-1,-1));
    
    rep(i,n)
    {
        char c;
        cin>>c;
        int price,quant;
        cin>>price>>quant;
        if(c=='B')
        {
            if(buy[price-1].first==-1)
                {buy[price-1].first=quant;
                    buy[price-1].second=price;}
            else
                buy[price-1].first+=quant;
        }
        else if(c=='S')
        {
            if(sell[price-1].first==-1)
                {sell[price-1].first=quant;
                    sell[price-1].second=price;
                    no_s++;}
            else
                sell[price-1].first+=quant;

        }
    }
   sort(all(sell),comp);
   sort(all(buy),comp);
//    cout<<buy[0][0];
   
   stack<pair<long,long> > st;
   /*int i=0;
   while(1)
   {
    if(sell[i++].second!=-1)
      {st.push(make_pair(sell[i-1].second,sell[i-1].first));
       // cout<<sell[i-1].second<<"\n";
    }

        else
        break;
   }
   stack<pair<long,long> > sn;
   while(!st.empty())
   {
    sn.push(st.top());
    //cout<<st.top().first<<"\n";
    st.pop();
    }
    int temp=s;
   while(!sn.empty() && temp--)
   {
    pair<long,long> p=sn.top();
    sn.pop();
    cout<<"S "<<p.first<<" "<<p.second<<"\n";
   }
i=0;*/
   int k=no_s-s;
   if(k<0) k=0;
   for(int i=0;i<s;i++)
   {
    if(sell[k].second!=-1)
        cout<<"S"<<" "<<sell[k].second<<" "<<sell[k].first<<"\n";
    else
        break;
    k++;
   }
   rep(i,s)
   {
    if(buy[i].second!=-1)
        cout<<"B"<<" "<<buy[i].second<<" "<<buy[i].first<<"\n";
    else
        break;
   }
}
