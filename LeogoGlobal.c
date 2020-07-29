 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <windows.h>
/// Global Variables
int numStudents, numQuiz;
char getname[100][100];
float quiz[100][100],ave[100], sum;
int i,j;


///Function
int getmax(); ///ask for maximum students and quizzes
void getscore(); ///gets the data of students and quizzes
float avescore(); ///gets the all over average of the students
void displaydata(); ///display the data
void gotoxy(int x, int y);

int main() {
    getscore(); /// passing the maximum input of students and quizzes that was entered in getmax();

 }


int getmax(){
    printf("\n Enter how many students you want to input: ");
    scanf("%d",&numStudents);
    printf("Enter how many quizzes you want to input: ");
    scanf("%d",&numQuiz);
    return numStudents, numQuiz;

 }

 void getscore(){
    system("cls");

    getmax(); ///function calling how many the user wants to input

     for (i=0; i<numStudents; i++){

        printf("\nEnter Student's Surname, Name: ");
        scanf(" %[^\n]",getname[i]);
        sum=0;
        printf("\n");
        for(j=0; j<numQuiz; j++)
        {
        printf("\t");
        printf("Enter Quiz %d:", j+1);
        scanf("%f",&quiz[i][j]);
        sum+=quiz[i][j];
        }
    ave[i]=avescore(sum,numQuiz);
     }
    displaydata(numStudents,numQuiz,getname,quiz,ave);
 }

float avescore() {
  return((float)(sum)/numQuiz);
}


void displaydata(int numStudents, int numQuiz,char getname[100][100], float quiz[100][100], float ave[100]) {


    system("cls");
    ///prints the NO, NAME, QUIZZES, AVERAGE AND REMARKS ON THE TOP
    gotoxy(0,0); printf("NO.");
    gotoxy(5,0); printf("Name");
    for(i=0; i<numQuiz; i++){
        gotoxy(28+(i*10),0); printf("Quiz %d", i+1);
        }
    gotoxy(28+((i+1)*10),0); printf("Average");
    gotoxy(28+((i+2)*10),0); printf("Remarks");

/// STARTS DISPLAYING THE DATA BELOW

    for(i=0; i<numStudents; i++){
        gotoxy(0,1+i); printf("%d.", i+1);
         printf("\033[1;33m"); ///prints the text in color yellow
        gotoxy(5,i+1);printf("%s",getname[i]);


        for(j=0; j<numQuiz; j++){
       gotoxy(28+(j*10),i+1); printf("%.2f", quiz[i][j]);
        }

        gotoxy(28+((j+1)*10),i+1);
        printf("%6.2f",ave[i]);

        if(ave[i]>=75){
            printf("\033[0;32m");
           gotoxy(28+((j+2)*10),i+1);printf("PASSED");
        }
        else
        {   printf("\033[1;31m"); /// prints in the text in color red
            gotoxy(28+((j+2)*10),i+1);printf("FAILED");
        }
        printf("\033[0m"); ///resets the text color
    }
}

///for placing of the texts.
 COORD coord={0,0};
void gotoxy(int x, int y) {

    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
