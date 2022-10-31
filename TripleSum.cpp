#include<iostream>
#include<vector>

int main(){
    int n,m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    for(int i = 0; i < n;i++){
        std::cin >> v[i];
    }
    for(int i = 0; i < m; i++){
        int target;
        std::cin >> target;
        bool found = false;
        for(int j = 0; j < n-2; j++){
            int l = j+1;
            int r = n-1;
            int target2 = target - v[j];
            while((target2 - v[l]) > v[r]){
                l++;
            }
            while(l < r){
                int tmp = v[l] + v[r];
                if(tmp > target2){
                    r--;
                }
                else if( tmp < target2){
                    l++;
                }
                else if(tmp == target2){
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        if(found){
            std::cout << "YES\n";
        }
        else{
            std::cout << "NO\n";
        }
    }
}