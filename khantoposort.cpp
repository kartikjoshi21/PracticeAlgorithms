

#include "bits/stdc++.h"
using namespace std;

#define int long long
#define mod 1000000007
#define pb push_back
#define endl "\n"

const int N = 100005 ;
vector<int>arr[N] ;
set<pair<int , int > >st ;
int in[N] ;
int32_t main()
{
   // ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
   	int n , m  ;
   	cin >> n >> m ;
   	for(int i  = 0 ; i < m ; i ++ )
    {
        int a , b , c ;
        cin >> a >> b ;
        in[b] ++ ;
        arr[a].pb(b) ;
    }
    /*
6 6
6 3
6 1
5 1
5 2
3 4
4 2
    */
    for(int i = 1 ; i <=  n ; i ++ )
    {
        st.insert({in[i] , i }) ;
    }


    vector<int>ans ;
    //set<pair<int , int  > > :: iterator it ;
    while(!st.empty() )
    {
        vector<int>temp ;
        while(!st.empty() )
        {
            pair<int,int>it = *st.begin() ;
            if(it.first > 0 )
                break ;
            cout << it.second << endl ;
            st.erase(st.begin()) ;
            temp.pb(it.second) ;
        }


        for(int j = 0 ; j < temp.size() ;  j ++ )
        {
            int k = temp[j] ;
            ans.pb(k) ;
            for(int i = 0 ;i < arr[k].size() ; i ++ )
            {
                st.erase(st.find({in[arr[k][i]] , arr[k][i]})) ;
                in[arr[k][i]] -- ;
                st.insert({in[arr[k][i]] , arr[k][i]}) ;
            }
        }
    }
    for(int i = 0 ;i < ans.size() ; i++ )
        cout << ans[i] << " " ;
        cout << endl ;




}
