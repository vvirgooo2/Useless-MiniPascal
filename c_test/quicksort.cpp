#include<iostream>
#include<vector>
#define MAXMSIZE 10001
using namespace std;

vector<int> vlist;

void swap(int i, int j){
    int temp;
    temp = vlist[i];
    vlist[i] = vlist[j];
    vlist[j] = temp;
}

void quicksort(int l, int r){
    if(l >= r)return;
    int pivot = vlist[l], left = l, right = r;
    while(left <= right && right > l && left < r){
        if(vlist[left] <= pivot)left++;
        else if(vlist[right] >= pivot)right--;
        else swap(left, right);
    }
    if(vlist[left] > pivot){
        swap(left-1, l);
        if(left <= l + 1){
            quicksort(right+1, r);
        }else{
            quicksort(l, left-2);
            quicksort(right, r);
        }
    }
    else if(vlist[left] < pivot){
        swap(left, l);
        quicksort(l, left-1);
        if(right<l)
        quicksort(right+1, r);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        vlist.push_back(t);
    }
    quicksort(0, n-1);
    for(int i=0;i<n;i++){
        cout << vlist[i] << " ";
    }
    return 0;
}