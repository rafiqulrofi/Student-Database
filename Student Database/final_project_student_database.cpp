#include<stdio.h>
#include<conio.h>

int menu();


void enter();

void search();

void display();



struct database {
    char name[20];
    int id;
    int phone;
    char email[20];
    char blood[10];


};

int main()
{
   int choice;

   choice=menu();
  switch(choice)
  {
   case 1:enter();
  break;
   case 2:search();
 break;
   case 3:display();


}
}

     int menu()
  {
    int i;
    int menu_soft;



    printf("Enter Your Choice...\n");
    
    
    printf("   \n\n1 Enter Student Info.\n");

    printf("   \n2 Enter Student Info Search.\n");
    
    printf("   \n3 Enter Student All Info Display.\n\n\n");

     scanf("%d",&menu_soft);
     return menu_soft;
    }


    void enter(void) {
    int i,n;
    
    printf("Enter number of the students: ");
    
    scanf(" %d", &n);
    
    struct database student[n];
    
        FILE *myfile;
        
        myfile=fopen("test.txt","a");

    for (i=0; i<n; i++) {

        printf("\nEnter Student Name: ");
        scanf(" %s", &student[i].name);

        printf("\nEnter Student id: ");
        scanf(" %d", &student[i].id);

        printf("\nEnter Student phone: ");
        scanf(" %d", &student[i].phone);

        printf("\nEnter Student Email: ");
        scanf(" %s", &student[i].email);

        printf("\nEnter Student Blood: ");
        scanf(" %s", &student[i].blood);

        fprintf(myfile," \n%s\n",student[i].name);

        fprintf(myfile," \n%d\n",student[i].id);

        fprintf(myfile," \n%d\n",student[i].phone);

        fprintf(myfile," \n%s\n",student[i].email);

        fprintf(myfile," \n%s\n",student[i].blood);

        }
        fclose(myfile);
        getch();

        
 }

  void search(void)
     {  
       int i,id;
       
       struct database student;
       
       int flag =0;
       FILE *myfile;
       
       myfile=fopen("test.txt","r");
       
       printf("enter your id");
       scanf("%d",&id);
       
       while (!feof(myfile))
         {

       fscanf(myfile,"%s\t%d\t%d\t%s\t%s\n",&student.name,&student.id,&student.phone,&student.email,&student.blood);

       if(id==student.id) 
         {
       printf("%s\n",student.name);
       printf("%d\n",student.id);
	   printf("%d\n",student.phone);
	   printf("%s\n",student.email);
	   printf("%s\n",student.blood);
	   
	   flag =1;
	   break;
	   }
 }
 if(flag ==0) printf("Entry not found...\n");
 getch();

}


void display()

{


int i,id;

struct database student;


FILE *myfile;

myfile=fopen("test.txt","r");

printf("Display All Data\n");

while (!feof(myfile))
{

    fscanf(myfile,"%s\t%d\t%d\t%s\t%s\n",&student.name,&student.id,&student.phone,&student.email,&student.blood);

    printf("%s\t%d\t%d\t%s\t%s\n",student.name,student.id,student.phone,student.email,student.blood);


}
getch();
}


