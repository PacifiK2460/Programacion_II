/*
    Declare left variable to 0 and right variable to n-1 
    Find mid by medium formula. mid = (left+right)/2
    Call merge sort on (left,mid)
    Call merge sort on (mid+1,rear)
    Continue till left is less than right
    Then call merge function to perform merge sort.
*/
void mergesort(void* left,void* mid ,void* rear, int(*compar)(const void *, const void *)){
    int mid = size/2;
    int i = left, j = mid, k = 0;
    int right = mid;
    void* temp[rear];
    
    while(i < right && j < rear){
        switch(compar(arr + i, arr + j)){
            case -1:
                temp[k] = arr + i;
                i++;
                break;
            default:
                temp[k] = arr + j;
                j++;
                break;
        }
        k++;
    }
    while(i < right){
        temp[k] = arr + i;
        i++;
        k++;
    }
    while(j < rear){
        temp[k] = arr + j;
        j++;
        k++;
    }
    for(i = left; i < rear; i++){
        arr[i] = temp[i];
    }
}

void mergesort(void* arr, int size, int(*compar)(const void *, const void *)){
    if(arr < size){
        void* mid = (arr+size)/2;
        mergesort(arr,size/2,compar);
        mergesort(mid+1,size/2,compar);
        merge(arr,mid,size);
    }
    return;
}