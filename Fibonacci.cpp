#include<iostream>
#include<vector>

// int main(){
//     int n;
//     std::cin >> n;
//     std::vector<int> v(n+1);
//     v[0] = 0; v[1] = 1;
//     for(int i = 2; i <= n; i++){
//         v[i] = v[i-2] + v[i-1];
//     }
//     std::cout << v[n];
// }

void print(std::vector<int> &v){
    for(int &x : v){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int fibo(std::vector<int> &table, int n){
    if(n == 0){
        table[0] = 0;
        return 0;
    }
    else if(n == 1){
        table[1] = 1;
        return 1;
    }
    if(table[n] == -1){
        int ans = fibo(table,n-1) + fibo(table,n-2);
        table[n] = ans;
        return ans;
    }
    return table[n];
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> table(n+1);
    for(int i = 0; i <= n; i++){
        table[i] = -1;
    }
    std::cout << fibo(table,n);
}