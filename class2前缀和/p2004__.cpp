#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,c;
    cin >> n >> m >> c;

    auto all = vector(n+1,vector<long long> (m+1));
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=m;j++){
            long long x;
            cin >> x;
            all[i][j] = all[i-1][j]+all[i][j-1]+x-all[i-1][j-1];
        }
    }
    auto he =[&](int i,int g){
        return all[i-1][g-1]+all[i+c-1][g+c-1]-all[i+c-1][g-1]-all[i-1][g+c-1];
    };
    long long max = 0;
    int ansx,ansy;
    for(int i = 1;i+c-1<=n;i++){
        for(int g =1;g+c-1<m;g++){
            if((he(i,g))>max){
                max=he(i,g);
                ansx = i;
                ansy = g;
            }             
        }
    }
    cout << ansx <<' ' << ansy;
}