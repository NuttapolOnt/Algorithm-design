#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    std::vector<int> time(m);
    for(int i = 0; i < m; i++){
        std::cin >> time[i];
    }
    std::sort(time.begin(),time.end());
    double ans = 0;
    for(int &x : time){
        int pos = 0;
        for(int i = 0; i < n; i++){
            if(v[i] < v[pos]){
                pos = i;
            }
        }
        v[pos] += x;
        ans += v[pos];
    }
    ans = ans/m;
    std::cout << std::fixed << std::setprecision(3) << ans;
}
/*4 3 2 4 1 2 5 3 4 5*/