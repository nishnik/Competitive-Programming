vector<int> z_function (string s) {
//z[i] = the common prefix length of string s[0..n] and string s[i..n]
//str match fastes use s=s1+'$'+s2
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

#define mod 1000000007
int bin_pow(int o, int s) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    int d = bin_pow(o, s/2);
    d = (d * 1ll * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}

long long gcd(long long a, long long b) {
    while(b) {
        long long t = a % b;
        b = a;
        a = t;
    }
    return a;
}
/////////////////////KMP////////////////
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

/////////////////////////////////////////////////////