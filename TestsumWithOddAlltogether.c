#include <stdio.h>      // for I/O functions
#include <stdlib.h>     // generally useful
#include <stdbool.h>    // for the bool type
#include <stdint.h>     // for exact-width integer types
#include <inttypes.h>   // for exact-width integer output

///////////////////////////////////////////////////////////////////////////////
//
// Pre:      Sz is a non-negative integer.
//           The dimension of List[] is at least Sz.
//           List[0:Sz-1] have been initialized.
//
// Post:     For each i from 0 to Sz-1, List[i] has been replaced with the
//               sum of List[i] and the odd values that occur between List[i+1]
//               and List[Sz-1], inclusive.
//
// Returns:  the sum of the final values in the array
//
// Restrictions:
//   You must use pointer arithmetic in your array traversals, so absolutely
//   no uses of bracket notation are allowed within the solution.
//

int32_t sumWithOddSuccessors(int32_t* const List, uint32_t Sz);

int main()
{
    int32_t testA[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int32_t* const testpoint = &testA[0];
    uint32_t yes = 10;
    int i;
    if (sumWithOddSuccessors(testA, yes) == 74)
    {
       printf("success");
    }
    else
        printf("\nfailure\n");
    for (i = 0; i < yes; i++)
    {
        printf("%d  ",testA[i]);
    }
    printf ( "Press [Enter] to continue . . ." );
    fflush ( stdout );
    getchar();
                                   
}


//NEW FUNCTION STARTS HERE
int32_t sumWithOddSuccessors(int32_t* const List, uint32_t Sz) {

   // Implement the body of this function.
   int32_t *point = List;
   int32_t *thing;
   int32_t sum = 0;
   for (point = List; point < List+Sz; point++)
   {
       for (thing = point+1; thing < List+Sz; thing++)
       {
           if (*thing%2 == 1 ||*thing%2 == -1)
           {
                *point += *thing;
           }
       }
       sum += *point;
           
   }
   return sum;
}
