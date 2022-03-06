// Leetcode problem no 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = 1000000000;
        int maxPrice = -1;
        int maxProfit = 0;
        
        for(int i=0;i<prices.size();i++)\
        {
            if(prices[i] < minPrice)
            {
                minPrice = prices[i];
                maxPrice = prices[i];
            }
            else if(prices[i] > maxPrice)
            {
                maxPrice = prices[i];
                if((maxPrice - minPrice) > maxProfit)
                    maxProfit = maxPrice - minPrice;
            }
        }
        
        return maxProfit;
    }
};



// Short soln : 
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int minPrice=1000000000, maxProfit=0;
        
//         for(int i=0;i<prices.size();i++)
//         {
//             minPrice = min(minPrice,prices[i]);
//             maxProfit = max(maxProfit,prices[i]-minPrice);
//         }
//         return maxProfit;
//     }
// };
