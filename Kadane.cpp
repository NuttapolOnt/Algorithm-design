#include<iostream>
#include<vector>


int kadane(std::vector<int> &v){
    int suf = v[0];
    int mss = v[0];
    int start = 0; 
    for(int i = 1; i < v.size(); i++){
        std::cout << suf << " " << mss << "\n";
        if(v[i] > suf+v[i]){
            start = i;
            suf = v[i];
        }
        suf = v[i] > suf+v[i] ? v[i] : suf+v[i];
        mss = mss > suf ? mss : suf;
    }
    return mss;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0;i < n; i++){
        std::cin >> v[i];
    }
    std::cout << kadane(v) << "\n";
    return 0;
}