
// A Dynamic Programming solution for subset sum problem
#include <stdio.h>
#include <stdbool.h> //Allison's addition to this code (added so program would support bool variables)

 
// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];

	   // If sum is 0, then answer is true for an i that is 0 because only 0 = 0
	subset[0][0] = true;
    for (int i = 1; i <= n; i++){ ////For all other cases, 
      subset[0][i] = false; //when the sum is 0, then the answer is false because non-zero sums do not equal 0.
	} 
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++){
      subset[i][0] = false;
	}
	
	// Fill the subset table in bottom up manner
for (int i = 0; i <= sum; i++)   {
 for (int j = 1; j <= n; j++) {
    if(subset[i][j-1] == true){
    // it is possible to generate sum "i" from smaller subset itself. 
    // So obviously it can be generated by bigger one. So no need to       
    //    think more
    subset[i][j] = true;   
    }else if (i == set[j-1]) {
          // Required sum is equal to current number. So mark it true
          subset[i][j] = true;
    }else if (i >= set[j-1]) {
      //  sum "i" is bigger than current number set[j-1]. 
      // Lets say  set[j-1] + x = i
      // So x = i - set[j-1]
     // Now we need to refer currently populated array to check if 
     // difference "x" can be achieved by first j-1 elements.
     // If we can achieve it; then we can achieve sum "i".
     int x = i - set[j-1];
     if(subset[x][j-1] == true){
           subset[i][j] = true;
      }
    }
  }
}	

 
    /* // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } */
 
     return subset[sum][n];
}