#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<dos.h>
#include<windows.h>
#include<time.h>
 void delay(int a)
    {
	int add;
	int time;
	int i;
	time=a*1000000000;
	for(i=0;i<time;i++)
	{
		add*=i;
		add++;
		add++;
	}
  }

struct contact

{

    long ph;

    char name[20],add[20],email[30],note[20];

} list;

char query[20],name[20];

FILE *fp, *ft;

int i,n,ch,l,found;

int main()

{

system("cls");    /* **Main menu ***  */
    system("color F4");

    printf("\n\n\n\n\n\n\n\t\t\t===================DS COURSE PROJECT===================");
    printf("\n\n\t\t\t\t\tDESIGN BY:");
    printf("\n\n\t\t\t\t---------------------------------------------------------------------------\n\t\t\t\t|\t\t\t\t\t\t\t\t\t|");
    printf("\n\t\t\t\t|\t\t\t1.Mugdha Dhopade \t70\t\t\t|");
    printf("\n\t\t\t\t|\t\t\t2.Sagar Shedge   \t89\t\t\t|");
    printf("\n\t\t\t\t|\t\t\t3.Chandasab Bangi \t81\t\t\t|");
    printf("\n\t\t\t\t|\t\t\t4.Sara chabukswar \t90\t\t\t|");
    printf("\n\t\t\t\t|\t\t\t5.Sakshi Nagare \t91\t\t\t|                                    \t\t\t\t\t\t\t\t\t\t\t|");
    printf("\n\t\t\t\t|-----------------------------------------------------------------------|");
    delay(5); 
	system("cls");
   /* **Main menu ***  */
    system("color F0");
     main:
    printf("\n\t\t\t!!! Welcome to Contact Management System!!!");

    printf("\n\n\n\t\t\tMENU OF CONTACT MANAGEMENT SYSTEM\n\t\t\t==========================================\n\t\t\t[1]\t Add a new Contact\n\t\t\t[2]\t List all Contacts\n\t\t\t[3]\t Search for contact\n\t\t\t[4]\t Edit a Contact\n\t\t\t[5]\t Delete a Contact\n\t\t\t[0]\t Exit\n\t\t\t========================================\n\t\t");

      printf("\n\tPlease read menu carefully and and option accordingly\n\t");
	printf("\n\tEnter the choice here:\n\t");

    scanf("%d",&ch);

    switch(ch)

    {

    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

        /* ***Add new contacts**  */

    case 1:

        system("cls");
        printf("\n\t\t\t---------------------ADD NEW CONTACT----------------------");
        fp=fopen("DS.dll","a");
         
        for (;;)

        {
            fflush(stdin);

            printf("\n\n\n\tTo exit enter blank space in the name input\n\n\n\t\t1.\tName:");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("\t\t2.\tPhone:");

            scanf("%ld",&list.ph);

            fflush(stdin);

            printf("\t\t3.\taddress:");

            scanf("%[^\n]",&list.add);

            fflush(stdin);

            printf("\t\t4.\temail address:");

            gets(list.email);
            
			fflush(stdin);

            printf("\t\t5.\tNotes:");

            gets(list.note);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);

        break;

        /* ***list of contacts***  */

    case 2:

        system("cls");

        printf("\n\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("DS.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\n\t1.Name\t: %s\n\t2.Phone\t: %ld\n\t3.Address: %s\n\t4.Email id: %s\n\t5.notes: %s\n",list.name,

                           list.ph,list.add,list.email,list.note);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);
            

        }

        break;

        /* ***search contacts**  */

    case 3:

        system("cls");

        do

        {
              int f=1;
            found=0;
               system("cls");
            printf("\n\n\t\t\t==================================================\n\t\t\t----------------CONTACT SEARCH----------------------\n\t\t\t================================================\n\n\n\n\tName of contact to search: ");
           
            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("DS.dll","r");

            system("cls");

            printf("\n\n\t\t\t\tSearch result for '%s' \n\t\t===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n\t1.\tName\t: %s\n\t2.\tPhone\t: %ld\n\t3.\tAddress: %s\n\t4.\tEmail id: %s\n\t5.\tNotes:%s\t\t\t--------------- Match-%d\n\n",list.name,list.ph,list.add,list.email,list.note,f);

                    found++;
                    f++;
                    if (found%4==0)

                    {

                        printf("Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\nNo match found!!!!!!!\n");

            else

                printf("\n\n\t\tTotal %d match found from contact!!!\n",found);

            fclose(fp);

            printf("\n\tAre you wants to try again?\n\tPress following keys\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        break;

        /* ***edit contacts****/

    case 4:

        system("cls");

        fp=fopen("DS.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("\n\n\t\t\t\t------------EDIT CONTACT -----------\n\t\t=========================================\n\n\tEnter the name of contact to edit:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n\t Editing '%s'\n\n",name);

        printf("\t1.\tNew Name(Use identical):");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("\t2.\tPhone:");

        scanf("%ld",&list.ph);

        fflush(stdin);

        printf("\t3.\taddress:");

        scanf("%[^\n]",&list.add);

        fflush(stdin);

        printf("\t4.\temail address:");

        gets(list.email);
        fflush(stdin);

        printf("\t5.\tNotes:");

        gets(list.note);


        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("DS.dll");

        rename("temp.dat","DS.dll");

        break;

        /* **delete contacts**/

    case 5:

        system("cls");
        do{
		

        fflush(stdin);

        printf("\n\n\t-----------------------DELETE A CONTACT------------------------\n\n\t============================================================================\n\n\n\n\t\tEnter the name of contact to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("DS.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("DS.dll");

        rename("temp.dat","DS.dll");
        
        printf("\t\tcontact deleted sucessfully!!!");
         printf("\n\n\n\tAre you wants to try again?\n\tPress following keys\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }while(ch==1);
        break;

    default:

        printf("\t\tInvalid choice");
        printf("\n\t\tEnter correct choice from menu!");

        break;

    }
gg:
    printf("\n\n\t\tEnter the Choice according to following:\n\t\t[1] Main Menu\t\t[0] Exit\n\t\t");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:
        system("cls"); 
        goto main;

    case 0:
  printf("\n\t\tThanks!!!!!!!!!!!!!!!!!\n");
  printf("\n\t\tPress any key to logout!!!!!");
        break;

    default:

         printf("\t\t\tInvalid choice!!!!!!!!!!!!!!");
         printf("\n\t\t\tEnter correct choice from menu!\n");
          goto gg;

        break;
  
    }

    return 0;

}
