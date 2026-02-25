//we are given an infinite supply of denominations 
//find min no. of coins to make change for a value V.

// V = 121
// ans = 3(100+20+1)

 #include <iostream>
 #include <vector>
 using namespace std;


 int minCoins(vector<int>coins, int V){
   int ans = 0;
   int n = coins.size();

   for (int i = n-1; i >= 0 && V > 0; i--){
      if (V >= coins[i]){
         ans += V/coins[i];
         V = V % coins[i];
      }
   }

   cout << "Min coin for change = "<< ans << endl;
   return 0;
 }

 int main (){

   vector<int> coins = {1,2,5,10,20,50,100,200,500,2000};
   int V = 590;
   minCoins(coins, V);
   return 0;
 }
