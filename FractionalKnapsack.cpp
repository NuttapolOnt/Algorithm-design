#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

int main(){
    int n;
    double w;
    std::cin >> w >> n;
    std::vector<std::pair<double,std::pair<double,double>>> v(n);
    for(int i = 0; i < n; i++){
        double tmp;
        std::cin >> tmp;
        v[i].second.first = tmp;
    }
    for(int i = 0; i < n; i++){
        double tmp;
        std::cin >> tmp;
        v[i].second.second = tmp;
        double r = v[i].second.first/v[i].second.second;
        v[i].first = r;
    }
    std::sort(v.begin(), v.end());
    double ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(w <= 0){
            break;
        }
        if(w >= v[i].second.second){
            ans += v[i].second.first;
            w -= v[i].second.second;
        }
        else{
            ans += v[i].first * (w);
            w = 0;
        }
    }
    std::cout << std::fixed << std::setprecision(4) << ans;
    return 0;
}