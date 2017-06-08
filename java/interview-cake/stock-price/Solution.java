/*
Suppose we could access yesterday's stock prices as an array, where:

The indices are the time in minutes past trade opening time, which was 9:30am local time.
The values are the price in dollars of Apple stock at that time.
So if the stock cost $500 at 10:30am, stockPricesYesterday[60] = 500.

Write an efficient function that takes stockPricesYesterday and returns the best profit I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.

For example:

  int[] stockPricesYesterday = new int[] {10, 7, 5, 8, 11, 9};

getMaxProfit(stockPricesYesterday);
// returns 6 (buying for $5 and selling for $11)

No "shorting"—you must buy before you sell. You may not buy and sell in the same time step (at least 1 minute must pass).

Gotchas
It is not sufficient to simply take the difference between the highest price and the lowest price, because the highest price may come before the lowest price. You must buy before you sell.
What if the stock value goes down all day? In that case, the best profit will be negative.

You can do this in O(n) time and O(1) space!
Rough design: 
  1. Find max stock price (can be done in O(n))
  2. Consider 1. as sell price and Traverse back from index of max taking difference at each step (again O(n)). The highest difference is maxProfit.

*/

import java.util.Arrays;

public class Solution {
    public static String myFunction(int[] arg) {
        // write the body of your function here
        //Arrays.sort(arg); array.length=60*7+30=450
        int maxProfit=arg[1]-arg[0];//lets assume
       	int maxSell=arg[0],indexofMaxSell=0;
        for(int i=1;i<arg.length;i++)
        { 
            if(arg[i]>maxSell){
              maxSell=arg[i];
              indexofMaxSell=i;
            }  
        }	
      
        for(i=indexofMaxSell-1;i>=0;i--){
          if(maxSell-arg[i] > maxProfit){
            
            maxProfit=maxSell-arg[i];
          }
        }
        
        return "Max profit: " + maxProfit;
    }
    public static void main(String[] args) {
        // run your function through some test cases here
        // remember: debugging is half the battle!
        int[] stockPricesYesterday = new int[] {10, 7, 6, 8, 11, 6};
        int[] testInput = stockPricesYesterday;
        System.out.println(myFunction(testInput));
    }
}
