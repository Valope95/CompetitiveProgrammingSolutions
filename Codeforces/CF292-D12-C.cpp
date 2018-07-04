/*           AUTHOR : Mahmoud Kassem 



	     As the Problem is asking the ip addresses which are palindromes and consisting of the digits given , we can try to brute force
	     all possible IP addresses and consider only the palindromes out of them as the answer , unfortunatly this approach would have 
	     high complexity e.g. around (2 ^ (8 * 4)) , (four numbers each ranges from 0 ~ 255) . 

		
	     To overcome such a problem we can brute force the answer while constructing the palindrome itself , and then checks if the 
	     string is a valid answer (all digits are considered in the string , no number is greater than 8 bits .. etc) 
	     

	     This will reduce the complexity to make it reach around ((10 ^ 6) * Complexity of check Function) . 
	     
	     
	     Complexity of check Function ~= length of the given string . 


*/ 

#include <iostream>
#include<algorithm>
#include<string>
#include<map>
#include <iterator>
#include<iomanip>
#include<vector>
#include<cmath>
#include <cstdio>
#include<queue>
#include<stack>
#include<list>
#include<stdio.h>
#include<set>
#include <functional>

#define mod 1000000007
#define mod2 30000000
#define pa(a,b) make_pair(a,b)
#define f first
#define s second
#define pb(a)  push_back(a)
#define all(a) a.begin() , a.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define LL  long long int
#define oo 1e9
#define pi 3.14159265359
#define eps  1e-9



LL maxx(LL a , LL b){ return a>b ?  a : b ;}
LL minn(LL a , LL b){ return a>b ?  b : a ;}

using namespace std;
int dx[] = {1 , 1 ,1 , 0 , 0  , -1 , -1  , -1  , 0 };
int dy[] = { -1 , 0  , 1 , 1 , -1 , 0 , 1 , -1 , 0 };
void boostIO()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
LL lcm(LL a , LL b )
{
    return (a*b)/gcd(a , b);
}
LL poww(LL base, LL exp){
  base %= mod;
  LL result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}
#define MAX  4294967295
int n ; vector<char>a;  vector<string>ans ; string s;
int vis[20] ; set<int>ss ;
int digits(int x)
{
    int ret = 0 ;
    if(x == 0)
        return 1 ;
    while(x){
        ret++ ;
        x /= 10 ;
    }
    return ret ;
}
bool check(string s)
{
    LL ret = 0 ;
    vector<int>slices ; int temp = 0 ;
    int rep = 0 ;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '.'){
            slices.pb(temp) ;
            if(digits(temp) != rep)
                return 0 ;
            temp = 0 , rep = 0 ;
            continue ;
        }
        //ret = ret * 10 + (s[i] - '0') ;
        temp = temp * 10 + (s[i] - '0') ;
        rep++ ;
    }
    slices.pb(temp) ;
    if(digits(temp) != rep)
        return 0 ;
    for(int i = 0 ; i < 4 ; i++){
        if(slices[i] >= 256){
            return 0 ;
        }
    }
    return (ret <= MAX) ;
}
void solve(int rem , int cnt , int p1 , int p2){

    if(rem <= 0){
        if(cnt == n){
            if(check(s)){
                ans.pb(s) ;
                return ;
            }
        }
        return ;
    }

    if(s[p1] == '.')
        p1++ ;
    if(s[p2] == '.')
        p2-- ;

    for(int i = 0 ; i < n ; i++){
        vis[i]++ ;
        s[p1] = a[i] , s[p2] = a[i] ;
        solve(rem - 2 , cnt + (vis[i] == 1)  , p1 + 1 , p2 - 1) ;
        vis[i]-- ;
    }

    return ;
}

int main()
{
    boostIO() ;  cin >> n ;

    for(int i = 0 ; i < n ; i++){
        int x; cin >> x ;
        a.pb('0' + x) ;
    }

    sort(all(a)) ;

    for(int i = 1 ; i <= 3 ; i++){
        for(int j = 1 ; j <= 3 ; j++){
            for(int k = 1 ; k <= 3 ; k++){
                for(int b = 1 ; b <= 3 ; b++){
                    s = string(i + j + k + b + 3 , '0') ;
                    s[i] = '.' , s[i + j + 1] = '.' , s[i + j + k + 2] = '.' ;
                    //if(i + j + k + b > 10)
                      //  continue ;
                    mem(vis , 0) ;
                    solve(i + j + k + b , 0 , 0 , i + j + k + b + 2) ;
                }
            }
        }
    }
    //sort(all(ans)) ;

    cout << ans.size() << endl ;

    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] ;
        putchar('\n') ;
    }

}
