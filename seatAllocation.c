#include <stdio.h>
#include <stdlib.h>
#include<string.h>  //no of branches is 4
#define n 100    //no. of students
#define m 7     //no. of preferences
#define seat 10  //no of seats per branch
void swap(int,int);
void assign(int,int);
void print_result(int);
void display(int);
struct student  {
    int appl_no;
    char names[50];
    int math;
    int phy;
    int chem;
    int cet;
    int pref[m];
    int choice;
    //columns till m
    }s[n];
static int i=0,k=0,j=0,f=0,g=0,p=0,q=0,r=0,t=0,u=0,nb=0;
int comps[seat][2], it[seat][2], extc[seat][2], etrx[seat][2],mech[seat][2],civil[seat][2],prod[seat][2], nobranch[n][2];
void main()
{
    FILE* fp;
    fp=fopen("spadata.csv","r");
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d, %[^,], %d,%d,%d,",&s[i].appl_no, s[i].names, &s[i].math, &s[i].phy, &s[i].chem);
        for(k=0;k<m-1;k++)
            fscanf(fp,"%d,",&s[i].pref[k]);
        fscanf(fp,"%d\n",&s[i].pref[k]);
        s[i].cet = s[i].math + s[i].phy + s[i].chem;
    /*  printf("%d %s %d %d %d %d ",s[i].appl_no, s[i].names, s[i].math, s[i].phy, s[i].chem, s[i].cet);
        for(k=0;k<m;k++)
            printf("%d ",s[i].pref[k]);
        printf("\n");*/

    }
    fclose(fp);

    /*for(i=0;i<n;i++)
    {   printf("Enter details of student %d: application no./ name/ maths/ phy/ chem/ pref1/ pref2 \n",i+1);
        scanf("%d %[^\n] %d %d %d ",&s[i].appl_no , s[i].names, &s[i].math , &s[i].phy , &s[i].chem );
        for(k=0;k<m;k++)
        {   scanf("%d",&s[i].pref[k]);
        }
        s[i].cet = s[i].math + s[i].phy + s[i].chem;
    }*/
    for(i=0;i<n;i++)
    {   for(k=i+1;k<n;k++)
        {   if(s[i].cet<s[k].cet)
                swap(i,k);
            else if(s[i].cet==s[k].cet)
            {   if(s[i].math<s[k].math)
                    swap(i,k);
                else if(s[i].math==s[k].math)
                {   if(s[i].phy<s[k].phy)
                        swap(i,k);
                    else if(s[i].phy==s[k].phy)
                    {   if(s[k].chem<s[k].chem)
                            swap(i,k);
                    }
                }
            }
        }
    }
    printf("\t\t*****WELCOME TO INSTITUTIONAL LEVEL ROUNDS CONDUCTED BY S.P.I.T COLLEGE*****\n");
    printf("\t\t\t\tTHANKS FOR APPLYING IN OUR INSTITUTE\n\n\n\n");
    printf("----> To view the ranks of candidates applied for institutional level round 'PRESS 1'\n");
    //printf("To check your allotment status 'PRESS 2'\n");
    //printf("For college login 'PRESS 3'");
    int q;
    scanf("%d",&q);
    if (q==1)
    {
    printf("===============================================================================================\n");
    printf("RANKS\t\tAPPLICATION NO.\t\tNAMES\t\t\t\t\tCET TOTAL MARKS\t\t\tpreference\n");
    for(i=0;i<n;i++)
    {    //printf("Rank %d with details\n",i+1);
         printf("%d\t\t%d\t\t%s\t\t\t\t\t\t%d\t\t\t",i+1, s[i].appl_no, s[i].names, s[i].cet);
        for(k=0;k<m;k++)
        {   printf("%d ",s[i].pref[k]);
        }
        printf("\n");
    }printf("=============================================================================================\n");}
    for(i=0;i<n;i++)
    {
        assign(i,0);
    }
    display(1);
    
    printf("if the student want to continue for round 2 then press 1\nor else press 0\n");
   for (i=0;i<n;i++)
   {    
       printf("\nfor student of application no. %d enter the choice:",s[i].appl_no);
       scanf("%d",&s[i].choice);
       }
       for (i=0;i<n;i++)
       {if(s[i].choice==1)
           {assign(i,1);}
       }
       display(1);
            
}
void swap(int i, int k)
{
    struct student temp;
    temp=s[i];
    s[i]=s[k];
    s[k]=temp;
}
void assign(int i,int j)
{   //for(j=0;j<m;j++)
    {   if(s[i].pref[j]==1 && f<seat)
        {   comps[f][1]=s[i].appl_no;
            comps[f][2]=i+1;
            f++;
            return;
        }
        else if(s[i].pref[j]==2 && g<seat)
        {   it[g][1]=s[i].appl_no;
            it[g][2]=i+1;
            g++;
            return;
        }
        else if(s[i].pref[j]==3 && p<seat)
        {   extc[p][1]=s[i].appl_no;
            extc[p][2]=i+1;

            p++;
            return;
        }
        else if(s[i].pref[j]==4 && q<seat)
        {   etrx[q][1]=s[i].appl_no;
            etrx[q][2]=i+1;
            q++;
            return;
        }
        else if(s[i].pref[j]==5 && r<seat)
        {   mech[r][1]=s[i].appl_no;
            mech[r][2]=i+1;
            r++;
            return;
        }
        else if(s[i].pref[j]==6 && t<seat)
        {   civil[t][1]=s[i].appl_no;
            civil[t][2]=i+1;
            t++;
            return;
        }
        else if(s[i].pref[j]==7 && u<seat)
        {   prod[u][1]=s[i].appl_no;
            prod[u][2]=i+1;
            u++;
            return;
        }
        else if(j==0)
        {   nobranch[nb][1]=s[i].appl_no;
            nobranch[nb][2]=i+1;
            nb++;
            return;
        }
    }
}

void print_result(int v)
{
    printf("Enter your application no to check your allotment\n");
    scanf("%d",&v);
    for(i=0;i<n;i++)
    {   if(v==comps[i][1]&&i<f)
        {   printf("\t\t!!!CONGRATULATIONS!!!\n");
             printf("___________________________________________________________________________\n");
            printf("RANK\t\t\tAPPLICATION NO.\t\t\tSEAT ALLOTED IN  BRANCH\n");
            printf("%d\t\t\t\t%d\t\t\t",comps[i][2],comps[i][1]);
            printf("COMPUTER ENGINEERING\n");
            printf("_______________________________________________________________________________\n");
            exit(1);
        }
        else if(v==it[i][1] && i<g)
        {   printf("\t\t!!!CONGRATULATIONS!!!\n");
            printf("___________________________________________________________________________\n");
            printf("RANK\t\t\tAPPLICATION NO.\t\t\tSEAT ALLOTED IN  BRANCH\n");
            printf("%d\t\t\t\t%d\t\t\t",it[i][2],it[i][1]);
            printf("INFORMATION TECHNOLOGY\n");
            printf("_______________________________________________________________________________\n");
            exit(1);
        }
        else if(v==extc[i][1] && i<p)
        {   printf("\t\t!!!CONGRATULATIONS!!!\n");
           printf("___________________________________________________________________________\n");
            printf("RANK\t\t\tAPPLICATION NO.\t\t\tSEAT ALLOTED IN  BRANCH\n");
            printf("%d\t\t\t\t%d\t\t\t",extc[i][2],extc[i][1]);
            printf("EXTC\n");
            printf("_______________________________________________________________________________\n");
            exit(1);
        }
        else if(v==etrx[i][1] && i<q)
        {   printf("\t\t!!!CONGRATULATIONS!!!\n");
           printf("___________________________________________________________________________\n");
            printf("RANK\t\t\tAPPLICATION NO.\t\t\tSEAT ALLOTED IN  BRANCH\n");
            printf("%d\t\t\t\t%d\t\t\t",etrx[i][2],etrx[i][1]);
            printf("ETRX\n");
            printf("_______________________________________________________________________________\n");
            exit(1);
        }
        else if(v==mech[i][1] && i<q)
        {   printf("\t\t!!!CONGRATULATIONS!!!\n");
            printf("___________________________________________________________________________\n");
            printf("RANK\t\t\tAPPLICATION NO.\t\t\tSEAT ALLOTED IN  BRANCH\n");
            printf("%d\t\t\t\t%d\t\t\t",mech[i][2],mech[i][1]);
            printf("MECHANICAL ENGINEERING\n");
            printf("_______________________________________________________________________________\n");
            exit(1);
        }
        else if(v==civil[i][1] && i<q)
        {   printf("\t\t!!!CONGRATULATIONS!!!\n");
             printf("___________________________________________________________________________\n");
            printf("RANK\t\t\tAPPLICATION NO.\t\t\tSEAT ALLOTED IN  BRANCH\n");
            printf("%d\t\t\t\t%d\t\t\t",civil[i][2],civil[i][1]);
            printf("CIVIL ENGINEERING\n");
            printf("_______________________________________________________________________________\n");
            exit(1);
        }
        else if(v==prod[i][1] && i<q)
        {   printf("\t\t!!!CONGRATULATIONS!!!\n");
             printf("___________________________________________________________________________\n");
            printf("RANK\t\t\tAPPLICATION NO.\t\t\tSEAT ALLOTED IN  BRANCH\n");
            printf("%d\t\t\t\t%d\t\t\t",prod[i][2],prod[i][1]);
            printf("PRODUCTION ENGINEERING\n");
            printf("_______________________________________________________________________________\n");
            exit(1);
        }
        else if(v==nobranch[i][1] && i<nb)
        {   printf("Your rank is %d\n", nobranch[i][2]);
            printf("You havent been alloted any seat\n");
            exit(1);
        }
    }
}
void display(int w)
{int z,v=1;
    printf("---->Press 1 for student login\n---->Press 2 for college login \n");
    scanf("%d",&z);
    if (z==1)
    {   print_result(v);
    }
    if(z==2)
    {   char passwrd[50]="hello123",pass[50];
        printf("ENTER THE PASSWORD:");
        scanf("%s",pass);
        if(strcmp(passwrd,pass)!=0)
        {   printf("**Invalid password**\nPlease try Again\n");
        }
        else
        {   printf("Application nos. students in Computer Sciences are as follows:\n");
            for(i=0;i<f;i++)
            {   printf("%d\n",comps[i][1]);
            }printf("the no. of seats assigned in COMPUTER ENGINEERING are %d\nthe no. of seats empty in COMPUTER ENGINEERING are %d\n\n",f,seat-f);
            printf("Application nos. students in Information Technology are as follows:\n");
            for(i=0;i<g;i++)
            {   printf("%d\n",it[i][1]);
            }printf("the no. of seats assigned in Information Technology are %d\nthe no. of seats empty in Information Technology are %d\n\n",g,seat-g);
            printf("Application nos. students in Electronics and Telecommunication are as follows:\n");
            for(i=0;i<p;i++)
            {   printf("%d\n",extc[i][1]);
            }printf("the no. of seats assigned in Electronics and Telecommunication are %d\nthe no. of seats empty in Electronics and Telecommunication are %d\n\n",p,seat-p);
            printf("Application nos. students in Electronics are as follows:\n");
            for(i=0;i<q;i++)
            {    printf("%d\n",etrx[i][1]);
            }printf("the no. of seats assigned in Electronics  are %d\nthe no. of seats empty in Electronics are %d\n\n",q,seat-q);
            printf("Application nos. students in Mechanical Engineering are as follows:\n");
            for(i=0;i<r;i++)
            {    printf("%d\n",mech[i][1]);
            }printf("the no. of seats assigned in Mechanical Engineering  are %d\nthe no. of seats empty in Mechanical Engineering are %d\n\n",r,seat-r);
            printf("Application nos. students in Civil Engineering are as follows:\n");
            for(i=0;i<t;i++)
            {    printf("%d\n",civil[i][1]);
            }printf("the no. of seats assigned in Civil Engineering  are %d\nthe no. of seats empty in Civil Engineering are %d\n\n",t,seat-t);
            printf("Application nos. students in Production Engineering are as follows:\n");
            for(i=0;i<u;i++)
            {    printf("%d\n",prod[i][1]);
            }printf("the no. of seats assigned in Production Engineering  are %d\nthe no. of seats empty in Production Engineering are %d\n\n",u,seat-u);
            printf("Application nos. students with no branch assigned are as follows:\n");
            for(i=0;i<nb;i++)
            {   printf("%d\n",nobranch[i][1]);
            }
        }
    }
}
