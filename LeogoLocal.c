 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <windows.h>

int getmax(int *numStudents, int *numQuiz);
void getscore();
float avescore(float sum, int numQuiz);
void displaydata(int numStudents,int numQuiz, char getname[100][100], float quiz[100][100], float ave[100]);
void gotoxy(int x, int y);
int main() {
    getscore(); /// passing the maximum input of students and quizzes that was entered in getmax();

 }


int getmax(int *a, int *b){

    printf("\n Enter how many students you want to input: ");
    scanf("%d",a);
    printf("Enter how many quizzes you want to input: ");
    scanf("%d",b);

 }

 void getscore(){
     int i,j;
    int numStudents, numQuiz;
    char getname[100][100];
    float quiz[100][100];
    float ave[100];
    float sum;
    system("cls");

    getmax(&numStudents,&numQuiz); ///function calling how many the user wants to input

     for (i=0; i<numStudents; i++){

        printf("\nEnter Student's Surname, Name:");
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

float avescore(float a, int b) {
  return((float)(a)/b);
}


void displaydata(int numStudents, int numQuiz,char getname[100][100], float quiz[100][100], float ave[100]) {

    int i,j=0;

    system("cls");
    ///prints the NO, NAME, QUIZZES, AVERAGE AND REMARKS ON THE TOP
    gotoxy(0,0); printf("NO.");
    gotoxy(5,0); printf("Name");
    //printf("\t\t");
    for(i=0; i<numQuiz; i++){
        gotoxy(28+(i*10),0); printf("Quiz %d", i+1);
    }
            gotoxy(28+((i+1)*10),0);
            printf("Average");
            gotoxy(28+((i+2)*10),0);
            printf("Remarks");



/// STARTS DISPLAYING THE DATA BELOW

    for(i=0; i<numStudents; i++){
        gotoxy(0,i+1); printf("%d.", i+1);
        gotoxy(5,i+1); printf("%s",getname[i]);


        for(j=0; j<numQuiz; j++){
        gotoxy(28+(j*10),i+1); printf("%.2f",quiz[i][j]);
        }
            gotoxy(28+((j+1)*10),i+1);
            printf("%6.2f",ave[i]);

        if(ave[i]>=75){
            gotoxy(28+((j+2)*10),i+1);printf("PASSED");
            }
        else{
            gotoxy(28+((j+2)*10),i+1);printf("FAILED");
            }

    }
}
 COORD coord={0,0};
void gotoxy(int x, int y) {

    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
