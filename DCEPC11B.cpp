#include<bits/stdc++.h>
using namespace std;
//int check[32000]={0};
//int primes[10000];
long factmod (long n, long p) {
	long res = 1;
	while (n > 1) {
       // cout<<"res: "<<res<<"\n";
		res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
		
        //cout<<"res: "<<res<<"\n";
        for (int i=2; i<=n%p; ++i)
			res = (res * i) % p;
        //cout<<"res2: "<<res<<"\n";
        
		n /= p;
	   //cout<<"n: "<<n<<"\n";
        
    }
	return res % p;
}
int main()
    {
        ios::sync_with_stdio(0);
    long a,b;
    int t;
    cin>>t;
    while(t--)
        {
    cin>>a>>b;
        if(b<=a)
            cout<<"0\n";
        else
    cout<<factmod(a,b)<<"\n";
    }
    return 0;
}