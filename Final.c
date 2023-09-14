#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int IDs[50]; // The ID of the student
float Marks[10]; // The mark of student
int n; // Variable to input the number of students in the class
//Input information of student.
void input()
{
    int i = 0;
    int j;
    do
    {
        printf("%d. Enter student's IDs: ",i+1);
        scanf("%d",& IDs[i]);
        for (j = 0; j < i; j++){
           while(IDs[i]==IDs[j])
            { printf("Duplicated ID, please enter again\n");
               printf("%d. Enter student's IDs: ",i+1);
               scanf("%d",&IDs[i]);
            }
    }
    	do{
        	printf("%d. Enter mark's student: ",i+1);
        	scanf("%f", &Marks[i]);
    		if (Marks[i]<0|| Marks[i]>10){
           		printf("Enter wrong mark for the student, please enter again \n");
        	}
    	}while (Marks[i]<0|| Marks[i]>10);
    	i++;
    } while (i < n);
}
//Display all students information
void Display()
{int i;
	for (i = 0; i < n; i++)
		{printf("| ID: %10d | Marks: %.2f |\n", IDs[i],Marks[i]);}
	return;
}
//find the highest marks of student:
void maxMarks ()
{
   	int maxID = IDs[0];
   	int i;
	float max = Marks[0];
      	for (i=0;i<n;i++){
	if (max <= Marks[i]){
   		max = Marks [i];
   		maxID = IDs[i];
   		}
   }
		for (i=0;i<n;i++){
    		if (Marks[i] == max){
		printf("Student has highest marks: %.2f | ID: %d. \n", max, IDs[i]);
			}
		}
}
//find the lowest marks of student:
void minMarks()
{
    int minID = IDs[0];
    int i;
    float min = Marks[0];
    for (i=0;i<n;i++){
        if (Marks[i] <= min){
           	min = Marks[i];
            minID = IDs[i];
    	}
}
    for (i=0;i<n;i++){
        if(Marks[i] == min){
        printf("Student has lowest marks: %.2f | ID: %d. \n", min, IDs[i]);
    	}
    }
}
//Menu Options
int main() {
    int choice = 0;
do{
	printf("          ------------Menu------------\n");

    printf("\n*******************************************\n");
    printf("* 1. Input student's ID & Marks           *\n");
    printf("* 2. View student's ID & Marks            *\n");
    printf("* 3. Find student's who has highest marks *\n");
    printf("* 4. Find student's who has lowest marks  *\n");
    printf("* 5. Exit program                         *\n");
    printf("*******************************************\n\n");
    printf("Please input your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        	system("cls");
            do {
                printf("How many students do you want to enter(3-30): ");
                scanf("%d",&n);
            if (n<3 || n> 30){
            	printf("Enter the wrong student number,please enter again: \n");
            }}
            while (n<3 || n> 30);
            input();
            break;
        case 2:
        	system("cls");
            printf("View student's ID & marks \n");
            Display ();
            break;
        case 3:
        	system("cls");
            printf("Find student's who has highest marks \n");
            maxMarks ();
            break;
        case 4:
        	system("cls");
    		printf("Find student's who has lowest marks \n");
    		minMarks ();
    		break;
		case 5:
			system("cls");
    		printf("Exiting program ... \n");
    		break;
		default:
    		printf("Invalid input and please choose again! \n");
    		break;
	}
}while(choice !=5);
exit(0);//Exit the program
return 0;
}
