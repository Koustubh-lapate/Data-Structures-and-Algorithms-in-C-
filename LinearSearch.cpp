#include <iostream>
using namespace std;

int LinearSearch(int n, int a[], int target){
    for(int i=0;i<n;i++){
        if(a[i]==target){
            return i;
        }
    }
    return -1;
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
    
    cout<<LinearSearch(n,a,target);
	return 0;
}
