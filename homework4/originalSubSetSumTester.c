#include <stdbool.h> //Allison's addition to this code (added so program would support bool variables)
#include "subsetSum.c" //Allison's addition to this code so tester file can see subsetSum.c file
// Driver program to test above function
int main()
{
  int set[] = {3, 7, 77,1}; //{3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}