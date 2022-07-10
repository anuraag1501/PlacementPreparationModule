int findMinimumCoins(int amount) {
    int curr[] = {1000,500,100,50,20,10,5,2,1};
    int coins = 0;
    for(int i=0; i<9; i++){
        coins += amount/curr[i];
        amount %= curr[i];
    }
    return coins;
}