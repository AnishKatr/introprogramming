//Anish Katragadda
//Monday @ 215
//lab 9:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int i, j, priorityCount;
int counter = 0;

int gsizes[5];
char name[20];
char phone[20];
char schedule[5][20];
char phones[5][20];

//Function to print the Menu
void menu()
	{
        
		printf("MENU \n");
		printf("1 - Schedule a Lesson \n");
		printf("2 - Delete \n");
		printf("3 - List \n");
		printf("4 - Show Names With Requested Letter \n");
        printf("5 - Show Groups With Requested Size \n");
		printf("6 - Schedule a Priority Lesson (Will Only Allow Once) \n");
		printf("7 - Count Letters \n");
		printf("9 - Quit \n");
        printf(" \n");
        printf("Option: ");
	}


//Makes a Reservation for Entered name, phone number, and group size, will tell user if the schedule is full
void scheduler()
    {
		int group = 0;
        if(counter == 5){
				printf("Schedule is Full\n");
			}
			else{
				printf("Please Type Your Name: \n");
				scanf("%s", name);
                printf("Please Enter Your Phone Number: \n");
                scanf("%s", phone);
                printf("Please Enter The Number Of People In Your Group (1-4 people): \n");
                scanf("%d", &group);
                while(group > 4 || group < 1){
                    printf("Please Make Sure Your Group is 1 Person at Minimum and 4 Max: \n");
                    scanf("%d", &group);
                }
				for(i = 0; i < 5; i++){
					if(strcmp (schedule[i], name) == 0){
						printf("Please Ty again The Inputted name was already booked\n");
                        printf(" \n");
                        break;
                    }else{
                        strcpy(schedule[counter], name);
                        strcpy(phones[counter], phone);
                        gsizes[counter] = group;
						counter++;
						printf("Your Lesson Has Been Scheduled for ");
						printf("%d", counter);
						printf("PM\n");
						break;
                    }
			
				}
			}
    }


//Deletes a specified name
void deleter(){
    printf("Which Persons lesson would you like to delete please type their name \n");
			scanf("%s", name);
			int hold = 0;
			for (i = 0; i < 5; i++){
				if (strcmp (schedule[i], name) == 0){
					for(j = i + 1; j < counter; j++){
						printf("Time Changed For %s, ", schedule[j]);
                        printf("%s, ", phones[j]);
                        printf("%d, ", gsizes[j]);
                        printf("From %d PM ", j + 1);
                        printf("TO %d PM \n", j);
                        strcpy(schedule[j - 1], schedule[j]);
                        strcpy(phones[j - 1], phones[j]);
                        gsizes[j - 1] = gsizes[j];
				    }
                    printf("Lesson Cancelled for: %s\n", name);
				    counter--;
				    schedule[counter][0] = '\0';
                    gsizes[counter] = '\0'; 
				    hold++;
				    break;
			    }
		}		
		if(hold == 0){
			
			printf("Name Not Found \n");
			hold = 0;

		}
}


//Lists All time slots and shows if its reserved, with name, phone number, and group size if not it will say free
void list(){
    for(i = 0; i < 5; i++){
			if( schedule[i][0] == '\0'){
				printf("%d", i + 1);
				printf(" PM: free \n");
			}
			else{
				printf("%d PM: ", i + 1);
				printf("%s, ", schedule[i]);
                printf("%s, ", phones[i]);
                printf("%d \n", gsizes[i]);
			}
	}
}



//Searches For Reseration Based On First Character which is Inputted
void searchcharacter(){
	char letter;
    printf("Please Input the First letter of the names you want to look for \n");
	scanf("\n%c", &letter);
	for(i = 0; i < 5; i++){
		if(schedule[i][0] == letter){

			printf("%d", i + 1);
			printf(" PM: ");
			printf("%s, ", schedule[i]);
            printf("%s, ", phones[i]);
            printf("%d \n", gsizes[i]);				

		}
	}
}


//Searches For Reservations Based on Size of Group Inputted
void searchbygroup(){
	int temp = 0;
    printf("Please Input the Size of Groups you want to look for \n");
			scanf("\n%d", &temp);
			for(i = 0; i < 5; i++){

				if(gsizes[i] == temp){

					printf("%d", i + 1);
					printf(" PM: ");
					printf("%s, ", schedule[i]);
                    printf("%d", gsizes[i]);
					printf("\n");				

				}
			}
}

void priority()
    {
		int group = 0;
		if(priorityCount <= 0){
			printf("Please Type Your Name: \n");
			scanf("%s", name);
            printf("Please Enter Your Phone Number: \n");
            scanf("%s", phone);
            printf("Please Enter The Number Of People In Your Group (1-4 people): \n");
            scanf("%d", &group);
            while(group > 4 || group < 1){
                printf("Please Make Sure Your Group is 1 Person at Minimum and 4 Max: \n");
                scanf("%d", &group);
            }
			for(i = 0; i < 5; i++){
					if(strcmp (schedule[i], name) == 0){
						printf("Please Ty again The Inputted name was already booked\n");
                        printf(" \n");
                        return;
        	}}
			if(counter == 5){
						printf("Lesson Cancelled For %s, ", schedule[4]);
                        printf("%s, ", phones[4]);
                        printf("%d \n", gsizes[4]);
						for(j = 3; j >= 0; j--){
							printf("Time Changed For %s, ", schedule[j]);
                        	printf("%s, ", phones[j]);
                        	printf("%d, ", gsizes[j]);
                        	printf("From %d PM ", j + 1);
                        	printf("TO %d PM \n", j + 2);
                        	strcpy(schedule[j + 1], schedule[j]);
                        	strcpy(phones[j + 1], phones[j]);
                        	gsizes[j + 1] = gsizes[j];
				   		}
						printf("Lesson Scheduled For %s, ", name);
                        printf("%s at 1PM \n", phone);
						strcpy(schedule[0], name);
                        strcpy(phones[0], phone);
                        gsizes[0] = group;
			}else {
				for(j = 0; j < counter; j++){
							printf("Time Changed For %s, ", schedule[j]);
                        	printf("%s, ", phones[j]);
                        	printf("%d, ", gsizes[j]);
                        	printf("From %d PM ", j);
                        	printf("TO %d PM \n", j + 1);
                        	strcpy(schedule[j + 1], schedule[j]);
                        	strcpy(phones[j + 1], phones[j]);
                        	gsizes[j + 1] = gsizes[j];
				   		}
						strcpy(schedule[0], name);
                        strcpy(phones[0], phone);
                        gsizes[0] = group;
			}
		}else{
				printf("You have Already Called Priority\n");
            }
	}


int count_letter(char checkLetter){
	char *p;
	int check = 0;
   for (i = 0; i < counter; i++)
   {
	p = schedule[i];
	while(*p != '\0'){
		if(*p == checkLetter){
			check++;
		}
		p++;
	}
   }
   return check;
   
}


//Execution
int main(){
	int input = 0;
	char checkLetter;
	int number = 0;

	for(i = 0; i < 5; i++){
		schedule[i][0] = '\0';
	}
    for(i = 0; i < 5; i++){
		gsizes[i] = '\0';
	}
	while(1){
		menu();
		scanf("%d", &input);
		switch(input){
		case 1: 
			scheduler();
			break;	
		case 2:
			deleter();
			break;
		case 3:
			list();
			break;
		case 4:
			searchcharacter();
			break;
        case 5:
			searchbygroup();
			break;
		case 6:
			priority();
			priorityCount++;
			break;
		case 7:
			
			printf("Please Type A letter you want to look for: \n");
			scanf(" %c", &checkLetter);
			number = count_letter (checkLetter);
			printf ("found %d occurrences of %c\n", number, checkLetter); 
			break;
		case 9:
			printf("You Have Quit \n");
			return 0;
		}
	}

}
