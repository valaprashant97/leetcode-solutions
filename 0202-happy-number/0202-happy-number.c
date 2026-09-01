bool isHappy(int n) {
    int sum, digit;
    while(n!=1 && n!=4){
        sum =0;
        while(n>0){
            digit = n%10;
            sum=sum+(digit*digit);
            n=n/10;
        }
        n=sum;
    }
    if(n==1){
        return true;
    }else{
        return false;
    }
}