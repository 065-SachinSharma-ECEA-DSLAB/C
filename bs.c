#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x){

    while (l <= r) {
        int m =(r+l) / 2;
        
       //(i)Iterative way binary search
        if (arr[m] == x){      
            return m;
        }
        if (arr[m] < x){
            l = m + 1;      //first term will be next to mid element
        } else{
            r  = m - 1;      //last term will be just before mid element
        }  

    }
    return -1;
}

int main(){
    int x,n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    //n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    
    printf("enter the element to search");
    scanf("%d",&x);
    
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array"): printf("Element is present at index %d",result);
    return 0;
}