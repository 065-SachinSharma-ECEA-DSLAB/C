#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x){
    while (l <= r) {
        int m =(r+l) / 2;

        if (arr[m] == x){
            return m;
        }
         if (arr[m] < x){
              l = m + 1;      //first term will be next to mid element
        } else{
              r = m - 1; 
        }     //last term will be before mid element
    }
    return -1;
}

int main(){
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
     int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array"): printf("Element is present at index %d",result);
    return 0;
}