#include<iostream>
#include<vector>

int main(){
    int n,w;
    std::cin >> n >> w;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    std::vector<int> table(n);
    table[0] = v[0];
    int start = 0;
    int max = v[0];
    int i = 1;
    while((i < n) && (start < n)){
        if((i - start) < w){
            int ans;
            int tmp = table[i-1] + v[i];
            if(tmp > v[i]){
                ans = tmp;
            }
            else{
                ans = v[i];
                start = i;
            }
            table[i] = ans;
            if(ans > max) max = ans;
            i++;
        }
        else{
            start += 1;
            table[start] = v[start];
            if(v[start] > max) max = start;
            i = start +1;
        }
    }
    std::cout << max << "\n";
    return 0;
}