#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int recursive(int deb,int fin,int value,int tablo[6],int mid){
   if(tablo[mid]== value){
      return 1;
   }
   else
   {
      if(value > tablo[mid] ){
         
         recursive(mid+1,fin,value,tablo,mid+1);
      }
      else
      {
      
         recursive(deb,mid-1,value,tablo,mid-1);
          
      }
      
   }
  
   
   
}


int dicSearch(int tablo[6],int value)
{
   
  
   int deb = 0 ; 
   int fin = 6 ; 
   int mid = ((deb+fin)/2);
   int trouver = recursive(deb,fin,value,tablo,mid);
   if (trouver == 1 ){
      printf("Trouver\n");
   }
   else
   {
      printf("non Trouver\n");
   }
   
   
    
   
  return trouver; 

}



