//hello how is your day
//Anish Katragadda
//Monday @ 215
//lab 6:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int input, i, input2;
int main(){

        int input, i, input2;
	int x[] = {0,0,0,0,0};

	while(1){
		printf("MENU \n");
		printf("1 - Schedule a Lesson \n");
		printf("2 - Delete \n");
		printf("3 - List \n");
		printf("9 - Quit \n");
		printf("Option: ");
		scanf("%d", &input);
		switch(input){
		case 1: 
			
			for(i = 0; i < 5; i++){
				if(x[i] == 0){
					x[i] = i + 1;
					printf("Your Lesson Has Been Scheduled \n");
					break;
				}
			}
			break;	
		case 2:
			printf("Which Lesson Would You like To Delete \n");
			scanf("%d", &input2);
			if(x[input2 - 1] == 0){
				printf("This Hour is Already Free \n");
			}
			else{
			x[input2 - 1] = 0;
			printf("Deleted \n");
			}
			break;
			
		case 3:
			for(i = 0; i < 5; i++){
				if( x[i] > 0){
					printf("%d", i + 1);
					printf(": lesson \n");
				}
				else{
					printf("%d", i + 1);
					printf(": Free \n");
				}
			}
			break;
		case 9:

			printf("You Have Quit \n");
			return 0;

		}
	}
}
