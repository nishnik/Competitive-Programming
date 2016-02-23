#include <bits/stdc++.h>
#include <malloc.h>
//usage getline(cin,str_name);
using namespace std;


#define rep(i, n) for(__typeof(n) i = 0; i < (n); i++)
#define rrep(i, n) for(__typeof(n) i = (n) - 1; i >= 0; --i)
#define rep1(i, n) for(__typeof(n) i = 1; i <= (n); i++)
#define FOR(i, a, b) for(__typeof(b) i = (a); i <= (b); i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define all(a)       a.begin(),a.end()
#define rall(a)      a.rbegin(),a.rend()
#define s(a)    scanf("%d",&a)
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

int dijkstra(vector<vector<pair<int,int> > > &graph, int source , int dest)
    {
    vector<int> dist(graph.size(),INT_MAX);
    dist[source] = 0;
    set<int> active;
    active.insert(source);
    while(!active.empty())
        {
        int where = *(active.begin());
        if(where == dest)
            {
            return dist[where];
        }
        active.erase(where);
        for(int i=0;i<graph[where].size();i++)
            {
            if(graph[where][i].second + dist[where] < dist[graph[where][i].first])
                {
                dist[graph[where][i].first] = graph[where][i].second + dist[where];
                active.insert(graph[where][i].first);
            }
        }
    }
    return INT_MAX;
}

int main()
{
    ios::sync_with_stdio(false);
    int m,n;
    cin>>n>>m;
    vector<vector<pair<int,int> > > graph(n);
    for (int i=0 ;i < m ;i++)
        {
        int a,b;
        cin>>a>>b;
        graph[a-1].push_back({b-1,0});
        graph[b-1].push_back({a-1,1});
    }
    cout<< dijkstra(graph,0,n-1);
}