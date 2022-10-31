#include<iostream>
#include<vector>
#include<algorithm>

void print(std::vector<std::pair<int,int>> &v){
    for(std::pair<int,int> &x : v){
        std::cout << "(" << x.first << " " << x.second << ")" << ","; 
    }
    std::cout << "\n";
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i].second;
    }
    for(int i = 0; i < n; i++){
        std::cin >> v[i].first; 
    }
    std::sort(v.begin(),v.end());
    //print(v);
    int last = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(v[i].second >= last){
            last = v[i].first;
            count += 1;
        }
    }
    std::cout << count << "\n";
    return 0;
}