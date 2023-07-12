//Anish Katragadda
//Lab Monday @ 2:15PM
//Lab 5 Code

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int count, multiple1, multiple2, answer, Input, i, percentage;
int main()
{
    
	int count, multiple1, multiple2, answer, i, percentage, Input; 
	count = 0;
	srand ((int) time (NULL));
	for( i = 0; i < 10; i++){
        
		multiple1 = rand ( ) % 13;
		multiple2 = rand ( ) % 13;
		answer = multiple1 * multiple2;

		printf("Please Answer The Following: \n");
		printf("%d", multiple1);
		printf(" * ");
		printf("%d \n", multiple2);
    
		printf("Enter an integer: ");
		scanf("%d", &Input);  
    
		if ( Input == answer) {
        		count = count + 1;
        		printf("You are Correct \n");
        	}	
        	else {
        	printf("YOU'RE WRONG! \n");
		printf("The Correct Answer Is:");
		printf("%d \n", answer);   
        	} 
    
	}
    
	percentage = count * 10;
	printf("Percent You Have Gotten Correct : %d", percentage);
	printf("% \n ");

    return 0;
}

