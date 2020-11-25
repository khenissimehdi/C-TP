#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int dicSearch(int tablo[6],int value)
{
   
  
   int deb = 0 ; 
   int fin = 6 ; 
    
   int trouver = 0;
    
   while (trouver != 1 && deb <= fin)
   {
      int mid = ((deb+fin)/2);
       printf("mid value is %d\n" , mid);
      if (tablo[mid] == value )
      {
         trouver = 1;
        
      }
      else
      {
         if (value > tablo[mid] )
         {
            deb = mid + 1;
            
         }
         else
         {
            fin = mid - 1;
           
         }
         
      }
      
      
   }
  return trouver;
   
   

}

