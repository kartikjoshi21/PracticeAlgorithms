
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define mod 1000000007
#define pb push_back
#define endl "\n"

const int N = 100005 ;
vector<pair<int , int > >arr[N] ;
int dis[N] ;
int32_t main()
{
   // ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
   	int n , m  ;
   	cin >> n >> m ;
   	for(int i  = 0 ; i < m ; i ++ )
    {
        int a , b , c ;
        cin >> a >> b >> c ;
        arr[a].pb({b , c }) ;
        arr[b].pb({a , c }) ;
    }
    for(int i = 1 ; i <= n ; i ++ )
    {
        dis[i] = INT_MAX ;
    }
    dis[1] = 0 ;
    for(int i = 0 ; i < n - 1 ; i ++ )
    {
        for(int j = 1 ; j < n ; j ++ )
        {
            for(int k = 0 ; k < arr[j].size() ; j ++ )
            {
                if(dis[j] + arr[j][k].second < dis[arr[j][k].first])
                {
                    dis[arr[j][k].first] = dis[j] + arr[j][k].second ;
                }
            }
        }
    }
    for(int j = 1 ; j < n ; j ++ )
    {
        for(int  k  =  0  ; k < arr[j].size() ; k ++ )
        {
            if(dis[j] + arr[j][k].second < dis[arr[j][k].first])
                {
                   cout << "-1" << endl ;
                    return  0 ;
                }
        }
    }


}
