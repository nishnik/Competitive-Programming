#include <bits/stdc++.h>

//usage getline(cin,str_name);

#define s(n)                        scanf("%d",&n)
#define s2(x,y)			    scanf("%d%d",&(x),&(y))
#define s3(x,y,z)		    scanf("%d%d%d",&(x),&(y),&(z))
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%ld",&n)
#define sll(n)                      scanf("%lld",&n)
#define sf(n)                       scanf("%f",&n)
#define ss(n)                       scanf("%s",n)
#define sd(n)						scanf("%lf",&n)



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
	while(1)
	{
        int a;string b;
        cin>>a;
        cin>>b;
        if(a==0)
            break;
        map<int,int> arr;
        arr[10]=0;
        arr[110]=0;
        arr[111]=1;
        arr[12]=0;
        arr[130]=0;
        arr[131]=1;
        arr[14]=0;

        arr[20]=1;
        arr[210]=0;
        arr[211]=1;
        arr[22]=1;
        arr[230]=1;
        arr[231]=0;
        arr[24]=1;

        arr[30]=1;
        arr[310]=0;
        arr[311]=1;
        arr[32]=1;
        arr[330]=0;
        arr[331]=1;
        arr[34]=1;

        arr[40]=0;
        arr[410]=1;
        arr[411]=1;
        arr[42]=1;
        arr[430]=0;
        arr[431]=1;
        arr[44]=0;

        arr[50]=1;
        arr[510]=1;
        arr[511]=0;
        arr[52]=1;
        arr[530]=0;
        arr[531]=1;
        arr[54]=1;

        arr[60]=1;
        arr[610]=1;
        arr[611]=0;
        arr[62]=1;
        arr[630]=1;
        arr[631]=1;
        arr[64]=1;

        arr[70]=1;
        arr[710]=0;
        arr[711]=1;
        arr[72]=0;
        arr[730]=0;
        arr[731]=1;
        arr[74]=0;

        arr[80]=1;
        arr[810]=1;
        arr[811]=1;
        arr[82]=1;
        arr[830]=1;
        arr[831]=1;
        arr[84]=1;

        arr[90]=1;
        arr[910]=1;
        arr[911]=1;
        arr[92]=1;
        arr[930]=0;
        arr[931]=1;
        arr[94]=1;

        arr[100]=1;
        arr[1010]=1;
        arr[1011]=1;
        arr[102]=0;
        arr[1030]=1;
        arr[1031]=1;
        arr[104]=1;

        for(int i=0;i<2*a+3;i++)
        {
            
            for(int j=0;j<b.length();j++)
            {
                if(i==0)
                {
                    int flag;
                    if(b[j]!='0')
                    {
                        flag=arr[(b[j]-'0')*10];
                    }
                    else
                        flag=arr[10*10];
                    cout<<" ";
                    for(int s=0;s<a;s++)
                    {
                        cout<<(flag?"_":" ");
                    }
                    cout<<" ";
                }
                else if(i>0 && i<=a)
                {
                    int flag1,flag2;
                    if(b[j]!='0')
                    {
                        flag1=arr[(((b[j]-'0')*10)+1)*10];
                        flag2=arr[(((b[j]-'0')*10)+1)*10+1];
                    }
                    else
                        {
                            flag1=arr[(10*10+1)*10];
                            flag2=arr[(10*10+1)*10+1];
                        }
                    cout<<(flag1?"|":" ");
                    for(int s=0;s<a;s++)
                    {
                        cout<<" ";
                    }
                    cout<<(flag2?"|":" ");
                }
                else if(i==a+1)
                {
                    int flag;
                    if(b[j]!='0')
                    {
                        flag=arr[((b[j]-'0')*10)+2];
                    }
                    else
                        flag=arr[10*10+2];
                    cout<<" ";
                    for(int s=0;s<a;s++)
                    {
                        cout<<(flag?"_":" ");
                    }
                    cout<<" ";
                }
                else if(i==2*a+2)
                {
                    int flag;
                    if(b[j]!='0')
                    {
                        flag=arr[((b[j]-'0')*10)+4];
                    }
                    else
                        flag=arr[10*10+4];
                    cout<<" ";
                    for(int s=0;s<a;s++)
                    {
                        cout<<(flag?"_":" ");
                    }
                    cout<<" ";   
                }
                else
                {
                    int flag1,flag2;
                    if(b[j]!='0')
                    {
                        flag1=arr[(((b[j]-'0')*10)+3)*10];
                        flag2=arr[(((b[j]-'0')*10)+3)*10+1];
                    }
                    else
                        {
                            flag1=arr[(10*10+3)*10];
                            flag2=arr[(10*10+3)*10+1];
                        }
                    cout<<(flag1?"|":" ");
                    for(int s=0;s<a;s++)
                    {
                        cout<<" ";
                    }
                    cout<<(flag2?"|":" ");
                }
                cout<<" ";
            }
            cout<<"\n";
        }
    }
}