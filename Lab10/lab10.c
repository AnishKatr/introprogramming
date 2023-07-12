//Anish Katragadda
//Monday @ 215
//lab 10:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//Prototypes
void input (void);  // Function for Task 1
void reverse (void);  // Function for Task 2
void convert (void); // Function for Task 3
void info (void);  // Function for Task 4
void show (void);  // Function to print all words in words array


char words[10][20];  // 2D array for words (up 10 words of length 19)
int length[10]; // Array to hold lengths of each word
int counter = 0;  // Counter to keep track of how many words we have

int main (void)  // Main just calls other functions
{ 
    input();
    reverse();
    convert();
    info();
    return 0;
}

void input()
	{
        int j, i;
        char temp[10];
        printf("Please Input words you want to enter\n");
		for (i = 0; i < 10; i++)
        {
            if(scanf("%s", temp) < 1){
                break;
            }
            for(j = 0; j < i; j++){
                    if(strcmp(temp, words[j]) < 0){
                        break;
                    }
            }
            for(int k = i; k >= j; k--){
                strcpy(words[k + 1], words[k]);
            }
            strcpy(words[j],temp);
        }
        
        printf("In order:\n");
        for (int x = 0; x < i; x++)
        {
            printf("%s \n", words[x]);
        }
        counter = i;
	}
void reverse()
	{
        int i,j;
        char temp[20];
        j = counter - 1;
        int half = counter/ 2;
        printf("reverse order:\n");
        for (i = 0; i < half; i++){
            j = counter - i - 1;
            strcpy(temp, words[i]);
            strcpy(words[i], words[j]);
            strcpy(words[j], temp);
        }

        for (int x = 0; x < counter; x++)
        {
            printf("%s \n", words[x]);
        }
	}
void convert()
	{
        char *p;
        for (int i = 0; i < counter; i++){
	        p = words[i];
	        while(*p != '\0'){
		        if(islower(*p)){
			        *p = toupper(*p);
		        }
		        p++;
	        }
            length[i] =(int) (p - words[i]);
         }
          printf("Converted:\n");
          for (int x = 0; x < counter; x++){
            printf("%s \n", words[x]);
        }
	}
void info()
	{
        printf("Information:\n");
        int min = length[0];
        int max = length[0];
        int temp = 0;
        int total = 0;
        int average = 0;
        int temporary = 0;
        for (int i = 0; i < counter; i++) {     
            if(length[i] < min)    
                min = length[i];    
        }
        for (int i = 0; i < counter; i++) {     
            if(length[i] == min){    
                    temp = i;
                    break;
            }
        }

        printf("The shortest string is %s\n", words[temp]);

        for (int i = 0; i < counter; i++) {     
            if(length[i] > max)    
                max = length[i];   
        }
        for (int i = 0; i < counter; i++) {     
            if(length[i] == max){    
                    temp = i;
                    break;
            }
        }

        printf("The largest string is %s\n", words[temp]);
        
        for (int i = 0; i < counter; i++) {     
            total += length[i];
            average = total/counter;
        }
        printf("The average length of the strings are: %d\n", average);
        printf("Words Not Starting with a letter: \n");
        for (int i = 0; i < counter; i++) {     
            if(isalpha(words[i][0]) == 0){
                printf("%s\n", words[i]);
                temporary++;
            }
        }
        if(temporary == 0){
            printf("All inputs start with a character");
        }
	}    
