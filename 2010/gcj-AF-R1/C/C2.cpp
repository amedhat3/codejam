#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <list>
#include <stack>
using namespace std;

typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long LL;

#define sz size()
#define all(n) n.begin(),n.end()a
#define clr(a,n) memset(a,n,sizeof(a))
#define pb push_back
#define FOR(n,a,b) for(n=a;n<b;n++)
#define RFOR(n,b,a) for(n=b;n>=a;n--)
#define fo(i,j) for(int i=0;i<j;i++)
#define inf 1000000000000000000ll; //check!!

long long arr[1000],sum[1000];
int P,C;
long long best[61][61];

int main()
{
    FILE *in=fopen("C.in","r");
    FILE *out=fopen("C.out","w");
    int i,j,k=1,T;
	fscanf(in,"%d",&T);
    while(T--)
    {
        long long mini=inf;
        clr(best,0);
		fscanf(in,"%d %d",&P,&C);
		fo(i,P)
		{
		    fscanf(in,"%lld",&arr[i]);
		    mini=min(mini,arr[i]);
		}
		if(P==C)
		{
		    fprintf(out,"Case #%d: %lld\n",k,mini);
		    k++;
		    continue;
		}
		sort(arr,arr+P);
		sum[0]=arr[0];
		j=0;
		for(i=0;i<P;i++)
		{
		    if(i>P-C)
		    {
                j++;
                arr[i]=min(arr[i],sum[i-1]/j);
		    }
		    sum[i]=sum[i-1]+arr[i];
		}
		fprintf(out,"Case #%d: %lld\n",k,sum[P-1]/C);
		k++;
	}
    //getchar();getchar();
    return 0;
}






















