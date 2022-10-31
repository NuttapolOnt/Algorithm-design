#include<iostream>
#include<vector>


int n;

int main(){
    std::cin >> n;
    std::vector<std::vector<int>> v(n);
    for(int i = 0; i < n; i++){
        std::vector<int> tmp(n);
        for(int j = 0; j < n; j++){
            std::cin >> tmp[j];
        }
        v[i] = tmp;
    }
    int max = v[0][0];
    for(int i = 0; i < n; i++){
        int r = 0;
        int c = i;
        int suf = v[r][c];
        r++; c++;
        while(r < n && c < n){
            suf = v[r][c] > suf+v[r][c] ? v[r][c] : suf+v[r][c];
            max = max > suf ? max : suf;
            r++; c++;
        }
    }
    for(int i = 0; i < n; i++){
        int r = i;
        int c = 0;
        int suf = v[r][c];
        r++; c++;
        while(r < n && c < n){
            suf = v[r][c] > suf+v[r][c] ? v[r][c] : suf+v[r][c];
            max = max > suf ? max : suf;
            r++; c++;
        }
    }
    std::cout << max << "\n";
    return 0;
}
/*4 1 2 3 4 -2 -5 2 -5 6 3 -7 1 3 -2 7 -9*/