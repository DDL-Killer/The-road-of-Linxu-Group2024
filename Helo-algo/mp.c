int bubbleSort(int* nums,int n){
    int count = 0;//计数器
    for(int i = n-1;i>0;i--){
        for(int j = 0;j<i;j++){
            if(nums[j]>nums[j+1]){
                int buf = nums[j];
                nums[j] = nums[j+1];
                nums[j+1]=buf;
                count +=3;
            }
        }
    }
    return count;
}