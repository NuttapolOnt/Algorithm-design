#include<iostream>
#include<vector>


int check(std::vector<int> &v, int left, int right){
    if(left == right){
        if(v[left] == 1){
            return 1;
        }
        else{
            return 0;

        }
    }
    int mid = (left+right)/2;
    int l = check(v,left,mid);
    int r = check(v,mid+1,right);
    if((l == -1) || (r == -1)) return -1;
    int def = l >= r ? (l-r) : (r-l);
    if(def > 1){
        return -1;
    }
    return l+r;
}
int main(){
    int n,k;
    std::cin >> n >> k;
    int len = 1;
    for(int i = 0; i < k; i++){
        len *= 2;
    }
    for(int i = 0; i < n; i++){
        std::vector<int> v(len);
        for(int j = 0; j < len; j++){
            std::cin >> v[j];
        }
        if(check(v,0,len-1) == -1){
            std::cout << "no\n"; 
        }
        else{
            std::cout << "yes\n";
        }
    }
}