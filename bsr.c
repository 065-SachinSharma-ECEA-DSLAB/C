#include<stdio.h>

int binary_search(int arr[] ,int s,int e,int x){

    while(s<=e){
        int mid=(s+e)/2;

        //(ii)binary search recursive way
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid]>x){
            return binary_search(arr,s,mid-1,x);
        }
        else{
            return binary_search(arr,mid+1,e,x);
        }
    }
    return -1;

}
int main(){
    int n,x;
    printf("enter no elements in array");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements of array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter element to search");
    scanf("%d",&x);
    
    int result= binary_search(arr,0,n-1,x);
    if(result==-1){
        printf("element %d not found ",x);
    }
    else{
        printf("element %d found at index %d",x,result);
    }

}