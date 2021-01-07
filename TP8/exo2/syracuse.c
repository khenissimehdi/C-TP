#include <stdio.h>
#include <stdlib.h>

void print(int* array,int s){
    int i,size;
    size = s;
    for ( i = 0; i < size; i++)
    {
        printf("%d\t",array[i]);
    }
    
}
void affiche(int long number){
	if (number == 1)
	{
		return ;
	}
	if (number%2 ==0)
	{
		printf("%ld\n",number/2);
		affiche(number/2);
	}
	else
	{
		printf("%ld\n",number*3+1);
		affiche(number*3+1);

	}		
}
int long flyCount(int long number,int long count){
	if (number == 1)
	{
		return count;
	}
	if (number%2 ==0)
	{
		
		return flyCount(number/2,count+1);
	}
	else
	{
		return flyCount(number*3+1,count+1);

	}	
}

int long flyCountMemo(int long number,int long* terms  ){
	if (number == 1)
	{
		
		return terms[number];
	}
	if (terms[number] == 0){
		
		
		if (number%2 == 0)
		{
			
			terms[number] = flyCountMemo(number/2,terms) +1;
			printf(" %ld ",terms[number]);
			
		}
		else
		{
			
			terms[number] = flyCountMemo(number*3+1,terms)+1;
			
		}	
		
	}
	
	
	
}


		