#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define pb push_back
#define endl "\n"

const int N = 10005 ;
int arr[N] , larr[N] , rarr[N] ;
int32_t main()
{
        int n ;
        cin >> n ;
        for(int i = 0; i < n ; i ++ )
            cin >> arr[i] ;

        larr[0]  = arr[0] ;
        for(int i = 1 ; i < n ; i ++ )
        {
            larr[i] = max(arr[i] , larr[i-1]) ;
        }

        rarr[n-1]  = arr[n-1] ;
        for(int i = n -2 ; i >= 0 ; i--)
        {
            rarr[i] = max(arr[i] , rarr[i + 1]) ;
        }

        int ans = 0 ;
        for(int i = 0; i < n ; i ++ )
            cout << larr[i] << " " ;
        cout << endl ;

        for(int i  = 0 ; i < n ; i ++ )
        {
            cout << rarr[i] << " " ;
        }
        cout << endl ;
        for(int i = 0; i < n ; i++ )
        {
            ans += ( min(larr[i] , rarr[i]) - arr[i]  ) ;
        }

        cout << ans << endl ;

}
