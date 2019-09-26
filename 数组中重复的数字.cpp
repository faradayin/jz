bool duplicate(int numbers[], int length, int* duplication) {
    for(int i=0;i!=length;++i){
        int index=numbers[i]%length;
        if(numbers[index]>=length)
        {
            *duplication=index;
            return 1;
        }              
        numbers[index]+=length;
    }
    return 0;
}