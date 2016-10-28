#include "sumWithOddSuccessors.h"

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
/** CS 2505 Spring 2014
 *
 *  Student:   Ryan Souther
 *  PID:       Ryan1992
 */
 // On my honor:
//
// - I have not discussed the C language code in my program with
// anyone other than my instructor or the teaching assistants
// assigned to this course.
//
// - I have not used C language code obtained fromanother student,
// or any other unauthorized source, either modified or unmodified.
//
// - If any C language code or documentation used in my program
// was obtained from an authorized source, such as a text book or
// course notes, that has been clearly noted with a proper citation
// in the comments of my program.
//
// - I have not designed this program in such a way as to defeat or
// interfere with the normal operation of the Curator System.
//
// Ryan Souther 


/**Goes through an array, and replaces each number with the sum of itself 
* and all odd values that come after it, using only pointers.
*
* @returns the sum of all changed numbers
*
*@param List, a list of integers
*@param size, the amount of the list to go though, same or smaller than size
*of list
*/
int32_t sumWithOddSuccessors(int32_t* const List, uint32_t Sz) {

   // Implement the body of this function.
   //Initialize all starting variables
   int32_t *point = List;    //pointer to move through list
   int32_t *thing;           //pointer to add secondary variables
   int32_t sum = 0;          //keeps track of the sums
   
                             //Moves through list via point
   for (point = List; point < List+Sz; point++)
   {
       //adds the odd values to point that come after it in the list
       for (thing = point+1; thing < List+Sz; thing++)
       {
           if (*thing%2 == 1||*thing%2 == -1)
           {
                *point += *thing;
           }
       }
       sum += *point;
           
   }
   return sum;  //returns the sum of all changed values
}

