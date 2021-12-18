#include <iostream>
using namespace std;

int floor(int n, int a[], int target){
    int s = 0;
    int e = n;
    while(s<=e){
        int mid = s+(e-s)/n;
        if(a[mid] == target){
            return mid;
        }
        else if(a[mid]>target){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return e;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int target;
    cin>>target;
    
    cout<<floor(n,a,target);
	return 0;
}
