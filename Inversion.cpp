#include<iostream>
#include<vector>
#include<algorithm>

void print(std::vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        std:: cout << v[i] << " ";
    }
    std::cout << "\n";
}

void merge(std::vector<int> &v, int start1, int stop1, int start2, int stop2){
    int n = stop2 - start1 + 1;
    int idl = start1;
    int idr = start2;
    std::vector<int> tmp(n);
    for(int i = 0; i < n; i++){
        if(idl > stop1){
            for(;idr <= stop2;){
                tmp[i] = v[idr];
                idr++;
                i++;
            }
        }
        else if(idr > stop2){
            for(;idl <= stop1;){
                tmp[i] = v[idl];
                idl++;
                i++;
            }
        }
        else if(v[idl] <= v[idr]){
            tmp[i] = v[idl];
            idl++;
        }
        else{
            tmp[i] = v[idr];
            idr++;
        }
    }
    for(int i = 0; i < n; i++){
        v[start1 + i] = tmp[i];
    }
}


int check(std::vector<int> &v,int start1,int stop1, int start2,int stop2){
    int count = 0;
    int j = start2;
    for(int i = start1; i <= stop1; i++){
        while((j <= stop2) && (v[i] > v[j])){
            count += (stop1 - i +1);
            j+=1;
        }
        if(j > stop2){
            break;
        }
    }
    merge(v,start1,stop1,start2,stop2);
    return count;
}



int ans(std::vector<int> &v,int left,int right){
    int result = 0;
    if(left+1 == right){
        if(v[left] > v[right]){
            std::swap(v[left], v[right]);
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(left == right){
        return 0;
    }
    else{
        int mid = (left+right)/2;
        int l = ans(v,left,mid);
        int r = ans(v,mid+1,right);
        result = check(v,left,mid,mid+1,right) + l + r;
    }
    return result;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    std::cout << ans(v,0,n-1) << "\n";
    return 0;
}