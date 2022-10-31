#include<iostream>
#include<vector>

int path(std::vector<int> &time, int start, int stop){
    if(start == stop) return 0;

}

int main(){
    int n,m;
    std::cin >> n >>m;
    std::vector<int> v(m);
    for(int i = 0; i < m; i++){
        std::cin >> v[i];
    }
    std::vector<int> t(m);
    for(int i = 0; i < m; i++){
        std::cin >> t[i];
    }
    for(int i = 0; i < n; i++){
        std::pair<int,int> p;
        std::cin >> p.first;
        std::cin >> p.second;
        for(int j = 0; j < m-1; j++){
            
        }
    }
}