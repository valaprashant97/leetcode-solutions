int numWaterBottles(int numBottles, int numExchange) {
    int total = numBottles;

    while(numBottles>=numExchange){
        int newBottles = numBottles/numExchange;
        int remBottles = numBottles%numExchange;
        total = total + newBottles;
        numBottles = newBottles+remBottles;
    }
    return total;
}
