#include <stdio.h>

     
     //total objects
    int n = 7;  
    // profit
    int p[7] = {10, 5, 15, 7, 6, 18};
    //weight 
    int w[7] = {2, 3, 5, 7, 1, 4}; 
    //knapsack capacity
    int cap = 15;

     
    void solution() {

        int current_weight;
        float tot_value;
        int i, maxi;
        int used[7];

        // we are initailling used array to zero because at first there is no element used.
        // this will keep track of how much weight is used.
        for (i = 0; i < n; ++i){
            used[i] = 0; 
        }
     
        // we will set current wieght capacity to max cap we can have handle in sack.
        current_weight = cap;

        // check if we still have space to fill in the sack.       
        while (current_weight > 0) {

            // find the most profitablity with less weight.
            maxi = -1;
            for (i = 0; i < n; ++i){
                if ((used[i] == 0) &&((maxi == -1) || ((float)p[i]/w[i] > (float)p[maxi]/w[maxi]))){
                    maxi = i;
                }
            }

            // we will mark the index used from 0 to 1.
            used[maxi] = 1; 

            // we will decrease that much wieght from the capacity.
            current_weight -= w[maxi];
            // add profit attained fromt that corresponding weight to the total profit
            tot_value += p[maxi];

            // when whole wieght is taken
            if (current_weight >= 0){
                printf("Added object %d. Space left: %d.\n", maxi + 1, current_weight);
            }
            // when partial weight is taken
            else{
                printf("Added %d%% of object %d in the bag.\n", (int)((1+(float)current_weight/p[maxi]) * 100), maxi + 1);
                tot_value -= w[maxi];
                tot_value += (1 + (float)current_weight/p[maxi]) * w[maxi];
            }
        }
        printf("Filled the sack with objects profit %.2frs.\n", tot_value);
     }

    int main(){
        solution();
        return 0;
    }