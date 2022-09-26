#include<iostream>
using namespace std;

int main() {
    int n;
    int S;
    cin>>n>>S;
    int weight[n+1], value[n+1];
    for(int i = 1; i<=n;i++) {
        cin>>weight[i];
    }
    for(int i = 1; i<=n;i++) {
        cin>>value[i];
    }
    int dp[n+1][S+1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= S;j++) {
            if(i == 0 || j == 0){
                dp[i][j] == 0;
            }else{
                dp[i][j] = dp[i-1][j];
            }
            if(j >= weight[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + value[i]);
            }
        }
    }
    cout<<dp[n][S];
}
