#include <iostream>
using namespace std;

int Ceiling(int n, int a[], int target){
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
    return s;
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
    
    cout<<Ceiling(n,a,target);
	return 0;
}
