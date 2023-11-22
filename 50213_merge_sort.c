#include <stdio.h>
#define LEN 100005
void print_arr(int arr[],int start,int end){
    for(int i=start;i<=end;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return;
}
void merge(int arr[],int l_start,int l_end,int r_start,int r_end){
    int left = l_start;
    int right = r_start;
    int len = r_end-l_start + 1;
    int index = l_start;
    int tmp[LEN];
    //printf("lstart %d,l_end %d\n",l_start,l_end);
    while(index<=r_end){
        if(left>l_end && right<=r_end){
            tmp[index] = arr[right];
            right++;
        }
        else if(right>r_end && left<=l_end){
            tmp[index] = arr[left];
            left++;
        }
        else if(arr[left]<arr[right]){
            tmp[index] = arr[left];
            left++;
        }
        else if(arr[right]<arr[left]){
            tmp[index] = arr[right];
            right++;
        }
        //printf("%d,arr[index]: %d\n",index,arr[index]);
        index++;
    }
    for(int i=l_start;i<=r_end;i++){
        // printf("i: %d, arr[i]: %d\n",i,arr[i]);
        arr[i] = tmp[i];
    }    
}
void merge_sort(int arr[],int start,int end){
    print_arr(arr,start,end);
    if(start==end)
        return;
    int mid = (start+end)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    //printf("start: %d, end: %d,mid: %d\n",start,end,mid);
    merge(arr,start,mid,mid+1,end);
    print_arr(arr,start,end);
    return;
}
int main(){
    int arr[LEN];
    int index=0;
    while(scanf("%d",&arr[index])!=EOF) index++;
    merge_sort(arr,0,index-1);
    // print_arr(arr,0,index-1);
    return 0;
}