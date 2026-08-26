int fib(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }

    int fiTerm = 0;
    int secTerm = 1;

    for(int i = 1;i <= n;i++){
        int thTerm = fiTerm +secTerm;
        fiTerm = secTerm;
        secTerm = thTerm;
    }
    return fiTerm;
}

// Fibonacci Series
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55...

// 0 + 1 = 1
// 1 + 1 = 2
// 1 + 2 = 3
// 2 + 3 = 5
// 3 + 5 = 8
// 5 + 8 = 13