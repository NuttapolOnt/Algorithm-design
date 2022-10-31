#include<iostream>
#include<vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 1) c1 += 1;
        else if(v[i] == 2) c2 += 1;
        else if(v[i] == 2) c3 += 1; 
    }
    int ans = 0;
    for(int i = 0; i < c1; i++){
        if(v[i] == 2){
            for(int j = c1; j < n; j++){
                if(v[j] == 1) {
                    std::swap(v[i],v[j]);
                    ans += 1;
                    break;
                }
            }
        }
        else if(v[i] == 3){
            bool check = false;
            for(int j = c1 + c2; j < n; j++){
                if(v[j] == 1){
                    std::swap(v[j],v[i]);
                    ans += 1;
                    check = true;
                    break;
                }
            }
            if(!check){
                for(int j = c1; j < c1+c2; j++){
                    if(v[j] == 1){
                        std::swap(v[i],v[j]);
                        ans += 1;
                        break;
                    }
                }
            }
        }
    }
    for(int i = c1; i < c1+c2; i++){
        if(v[i] != 2){
            for(int j = c1+c2; j < n; j++){
                if(v[j] == 2){
                    std::swap(v[i],v[j]);
                    ans += 1;
                    break;
                }
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}