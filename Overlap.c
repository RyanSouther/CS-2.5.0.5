/** CS 2505 Spring 2014
 *  Supplied framework for Intersecting Rectangles project.  Your task is to
 *  complete the supplied code to satisfy the posted specification for this
 *  assignment.  The occurrences of "???" in the code below indicate places
 *  where you must complete the implementation.
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
#include <stdio.h>      // for I/O functions
#include <stdlib.h>     // generally useful
#include <stdbool.h>    // for the bool type
#include <stdint.h>     // for exact-width integer types
#include <inttypes.h>   // for exact-width integer output

#define MAXLEN 100

// Declaration for function Overlap():
bool Overlap(int32_t aSWx, int32_t aSWy, uint32_t aHeight, uint32_t aWidth,
             int32_t bSWx, int32_t bSWy, uint32_t bHeight, uint32_t bWidth);
			 
int main( ) {

   FILE *Data = fopen("TestData.txt", "r");         // 1: Open the test data file
   FILE *Log = fopen("Results.txt", "w");         // 2: Open the results log file

   int32_t aSWx, aSWy, aHeight, aWidth, // specification of 1st rectangle
           bSWx, bSWy, bHeight, bWidth; // specification of 2nd rectangle

   char Line[MAXLEN + 1];
   fgets(Line, MAXLEN, Data);      // Read header lines
   fgets(Line, MAXLEN, Data);
   /**
   *Print the header line to the log file
   */
   fprintf(Log, "Rectangle A                         Rectangle B\n");
   fprintf(Log, "SW corner       Height    Width     SW corner       Height    Width\n");
   /**
   *Print out the hyphens before the data
   */
   fprintf(Log, "-----------------------------------");
   fprintf(Log, "--------------------------------\n");
   // 4: Read the data for first pair of rectangles:
   int32_t numRead = fscanf(Data, "%d %d %d %d %d %d %d %d", 
   &aSWx, &aSWy, &aHeight, &aWidth,  //Read the first  rectangle
   &bSWx, &bSWy, &bHeight, &bWidth); // Read the second rectangle

   while ( numRead == 8) { // 5: Check if all values were read

      // 6: Write data for current rectangles to log:
       fprintf(Log, "(%5d, %5d)%8d %8d    (%5d, %5d) %8d %8d\n", 
       aSWx, aSWy, aHeight, aWidth,  //Read the first  rectangle
       bSWx, bSWy, bHeight, bWidth); 

      // 7: Test for an overlap and log the results:
       if ( Overlap(aSWx, aSWy, aHeight, aWidth,
                    bSWx, bSWy, bHeight, bWidth)  ) 
            {

            fprintf(Log, "     overlap detected\n");
            }
         else {

            fprintf(Log, "     no overlap detected\n");
         }
      
      // 8: Read data for next pair of rectangles:
      numRead = fscanf(Data, "%d %d %d %d %d %d %d %d", 
      &aSWx, &aSWy, &aHeight, &aWidth,  //Read the first  rectangle
      &bSWx, &bSWy, &bHeight, &bWidth); // Read the second rectangle
   }

   // 9: Write the marker for the end of the table:
   /**
   *Print out the hyphens at the end of the data
   */
   fprintf(Log, "-----------------------------------");
   fprintf(Log, "--------------------------------\n");

   fclose (Data);  /* ???; */    // 10: Close the input and output files
   fclose (Log);/* ???; */
   return 0;
}

/**  Determines whether two rectangles, A and B, intersect.
 *
 *   Pre:
 *         aSWx and aSWy specify the SW (lower, left) corner of A
 *         aHeight specifies the vertical dimension of A
 *         aWidth specifies the horizontal dimension of A
 *         bSWx and bSWy specify the SW (lower, left) corner of B
 *         bHeight specifies the vertical dimension of B
 *         bWidth specifies the horizontal dimension of B
 *       
 *   Returns:
 *         true if A and B share at least one point; false otherwise
 * @param aSWx xpos of the Southwest corner of the first rectangle
 * @param aSWy ypos of the Southwest corner of the first rectangle
 * @param aHeight height of the first rectangle
 * @param aWidth width of the first rectangle
 * @param bSWx xpos of the Southwest corner of the second rectangle
 * @param bSWy ypos of the Southwest corner of the second rectangle
 * @param bHeight height of the second rectangle
 * @param bWidth width of the second rectangle
 */
bool Overlap(int32_t aSWx, int32_t aSWy, uint32_t aHeight, uint32_t aWidth,
     int32_t bSWx, int32_t bSWy, uint32_t bHeight, uint32_t bWidth)
{
     bool overlapDetected = true;
     /**
     * This if statement sees if the rectangles overlap by checking all at the
     * same time if there are any conditions that would make the rectangles not
     * overlap.  If any of those conditions are met, it must not overlap.
     * Otherwise, it does.
     */
     if (aSWx + aWidth < bSWx || bSWx + bWidth < aSWx //check if width overlaps
        || aSWy + aHeight < bSWy || bSWy + bHeight < aSWy)//Check Height overlap
        {
                overlapDetected = false; //Set to false if there is no overlap
        }        
     return overlapDetected;
}
