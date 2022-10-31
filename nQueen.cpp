#include<iostream>
#include<vector>

int n;
int count = 0;

bool isValid(std::vector<int> &v, int pos, int k){
    for(int i = 0; i < pos; i++){
        int row = std::abs(v[i] - k);
        int col = std::abs(pos-i);
        if(row == col) return false;
    }
    return true;
}

void nQueen(std::vector<int> &v, std::vector<bool> &used, int pos){
    if(pos == n){
        count += 1;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!used[i] && isValid(v,pos,i)){
            used[i] = true;
            v[pos] = i;
            nQueen(v,used,pos+1);
            used[i] = false;
        }
    }
}

int main(){
    std::cin >> n;
    std::vector<int> v(n);
    std::vector<bool> used(n,false);
    nQueen(v,used,0);
    std::cout << count << "\n";
}