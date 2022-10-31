#include<iostream>
#include<vector>

// int n;
// int max = -1;

// void bb(std::vector<int> &v, std::vector<int> table, int pos){
//     if(pos >= n){
//         return;
//     }
//     int ref = table[pos-2] > table[pos-1] ? table[pos-1] : table[pos-1];
//     int tmp = table[pos-3] + v[pos];
//     int ans = tmp > ref ? tmp : ref;
//     if(ans > max) max = ans;
//     table[pos] = ans;
//     bb(v,table,pos+1);
// }


// int main(){
//     std::cin >> n;
//     std::vector<int> v(n);
//     std::vector<int> table(n,-1);
//     for(int i = 0; i < n; i++){
//         std::cin >> v[i];
//     }
//     table[0] = v[0];
//     table[1] = v[1] > table[0] ? v[1] : table[0];
//     table[2] = v[2] > table[1] ? v[2] : table[1];
//     bb(v,table,3);
//     std::cout << max << "\n";
//     return 0;
// }

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    std::vector<int> table(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    table[0] = v[0];
    table[1] = v[1] > table[0] ? v[1] : table[0];
    table[2] = v[2] > table[1] ? v[2] : table[1];
    for(int i = 3; i < n; i++){
        if(table[i-1] > table[i-3]+v[i]){
            table[i] = table[i-1];
        }
        else{
            table[i] = table[i-3] + v[i];
        }
    }
    std::cout << table[n-1] << "\n";
    return 0;
}