//Anish Katragadda
//Monday @ 215
//lab 7:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void menu()
	{
		printf("MENU \n");
		printf("1 - Schedule a Lesson \n");
		printf("2 - Delete \n");
		printf("3 - List \n");
		printf("4 - Show Names With Requested Letter \n");
		printf("9 - Quit \n");
	}
int main(){

        int input, i, input2, hold,j;
	int x[] = {0,0,0,0,0};
	int counter = 0;
	char name[20];
	char schedule[5][20];
	char letter;
	

	for(i = 0; i < 5; i++){
		schedule[i][0] = '\0';
	}

	while(1){
		menu();
		printf("Option: ");
		scanf("%d", &input);
		switch(input){
		case 1: 
			if(counter == 5){
				printf("Schedule is Full");
				break;
			}
			else{
				printf("Please Type Your Name: ");
				scanf("%s", name);
				for(i = 0; i < 5; i++){
					if(schedule[i][0] == '\0'){
						strcpy(schedule[counter], name);
						counter++;
						printf("Your Lesson Has Been Scheduled for ");
						hold = i + 1;
						printf("%d", hold);
						printf("PM\n");
						break;
				}
			
				}
			}
			break;	
		case 2:
			printf("Which Persons lesson would you like to delete please type their name \n");
			scanf("%s", name);
			hold = 0;
			for (i = 0; i < 5; i++){
			
				if (strcmp (schedule[i], name) == 0){
					for(j = i + 1; j < counter; j++){
						strcpy(schedule[j - 1], schedule[j]);
						

					}
					counter--;
					schedule[counter][0] = '\0'; 
					hold++;
					break;
				}
			}		
			if(hold == 0){
			
				printf("Name Not Found \n");
				hold = 0;

			}
			break;
			
		case 3:
			for(i = 0; i < 5; i++){
				if( schedule[i][0] == '\0'){
					printf("%d", i + 1);
					printf(" PM: free \n");
				}
				else{
					printf("%d", i + 1);
					printf(" PM: ");
					printf("%s", schedule[i]);
					printf("\n");
				}
			}
			break;
		
		case 4:
			printf("Please Input the First letter of the names you want to look for \n");
			scanf("\n%c", &letter);
			for(i = 0; i < 5; i++){

				if(schedule[i][0] == letter){

					printf("%d", i + 1);
					printf(" PM: ");
					printf("%s", schedule[i]);
					printf("\n");				

				}
			}
			break;
		case 9:

			printf("You Have Quit \n");
			return 0;

		}
	}
}
