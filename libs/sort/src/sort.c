/*
    Declare left variable to 0 and right variable to n-1 
    Find mid by medium formula. mid = (left+right)/2
    Call merge sort on (left,mid)
    Call merge sort on (mid+1,rear)
    Continue till left is less than right
    Then call merge function to perform merge sort.
*/
void merge(int* arr, int* mid, int* size){
    int i = 0, j = mid, k = 0;
    int left = *arr;
    int right = *mid;
    int rear = *size;
    int temp[rear];
    while(i < right && j < rear){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i < right){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j < rear){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(i = left; i < rear; i++){
        arr[i] = temp[i];
    }
}

void mergesort(int* arr, int* size){
    if(arr < size){
        int* mid = (arr+size)/2;
        mergesort(arr,mid);
        mergesort(arr,mid+1,size);
        merge(arr,mid,size);
    }
    return;
}