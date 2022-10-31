#include<iostream>
#include<vector>
#include<algorithm>


bool check(std::vector<int> &v, int left,int right, bool state){
    if(state){
        reverse(v.begin()+left,v.begin()+right+1);
    }
    if((left + 1) == right){
        return (v[left] == 0 && v[right] == 1);
    }
    else{
        int mid = (left + right)/2;
        return check(v,mid+1,right, false) && (check(v,left,mid,false) || check(v,left,mid,true));
    }
}



int main(){
    int n,k;
    int len = 1;
    std::cin >> n >> k;
    for(int i = 0; i < k; i++){
        len *= 2;
    }
    for(int i = 0; i < n; i++){
        std::vector<int> v(len);
        for(int j = 0; j < len; j++){
            std::cin >> v[j];
        }
        if(check(v,0,len-1,false)){
            std::cout << "yes\n";
        }
        else{
            std::cout << "no\n";
        }
    }
}