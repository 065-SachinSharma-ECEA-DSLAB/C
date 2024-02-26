#include <stdio.h>

struct Element{
    int row ;
    int col;
    int value;
};
int main(){
    int i,j,k,n,m;
    printf("enter number of rows");
    scanf("%d",&n);
    printf("enter number of columns");
    scanf("%d",&m);
    int arr[n][m];
    printf("enter matrix elements");

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    int count =0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j]==0){
                count++;
            }
        }
    }
    
    printf("No. of  elements is %d and no of 0's in array is %d\n",n*m,count);
    if (count >= (n*m)/2){
        printf("it is a sparse matrix\n") ;
        struct Element sparse_arr[(n*m)-count];
        k=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(arr[i][j]!=0){
                    sparse_arr[k].row=i;
                    sparse_arr[k].col=j;
                    sparse_arr[k].value=arr[i][j];
                    k++;
                }
            }
        }
        printf("Array representation of sparse matrix\n");
        printf("Row\tColumn\tValue\n");
        for(i=0;i<(n*m)-count;i++){
            printf(" %d \t %d \t %d\n",sparse_arr[i].row,sparse_arr[i].col,sparse_arr[i].value);
        }
    }
    else{
        printf("not a sparse sparse matrix\n");
    }
    return 0;
}