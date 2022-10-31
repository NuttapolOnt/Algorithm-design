#include<iostream>
int n;
int count = 0;
void dfs(int value, int pos){
    if(value == n){
        count += 1;
    }
    if(value > n) return;
    for(int i = pos; i <= n; i++){
        dfs(value + i, i);
    }
}
int main(){
    std::cin >> n;
    dfs(0,1);
    std::cout << count << "\n";
}