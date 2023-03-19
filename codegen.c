#include<stdio.h>
#include<conio.h>
#include<string.h>

char op[2],arg1[5],arg2[5],result[5], var[5], val[5];;
void codegen()
{
  FILE *fp1,*fp2;
  fp1=fopen("Intermediate.txt","r");
  fp2=fopen("Target_code.txt","w");
  while(!feof(fp1))
  {

    fscanf(fp1,"%s%s%s%s",op,arg1,arg2,result);
    if(strcmp(op,"+")==0)
    {
      fprintf(fp2,"\nMOV R0,%s",arg1);
      fprintf(fp2,"\nADD R0,%s",arg2);
      fprintf(fp2,"\nMOV %s,R0",result);
    }
     if(strcmp(op,"*")==0)
    {
      fprintf(fp2,"\nMOV R0,%s",arg1);
      fprintf(fp2,"\nMUL R0,%s",arg2);
      fprintf(fp2,"\nMOV %s,R0",result);
    }
    if(strcmp(op,"-")==0)
    {
      fprintf(fp2,"\nMOV R0,%s",arg1);
      fprintf(fp2,"\nSUB R0,%s",arg2);
      fprintf(fp2,"\nMOV %s,R0",result);
    }
       if(strcmp(op,"/")==0)
    {
      fprintf(fp2,"\nMOV R0,%s",arg1);
      fprintf(fp2,"\nDIV R0,%s",arg2);
      fprintf(fp2,"\nMOV %s,R0",result);
    }
if(strcmp(op,"=")==0)
    {
       if(strcmp(arg1, "int") == 0) {
        // declare a variable with the given name and initial value
        fscanf(fp1, "%s %s", var, val);
        fprintf(fp2, "\nMOV R0, %s", val);
        fprintf(fp2, "\nMOV %s, R0", var);
      } else {
        // this is a regular assignment statement
        fprintf(fp2,"\nMOV R0,%s",arg1);
        fprintf(fp2,"\nMOV %s,R0",result);
      }
    }
    }
    fclose(fp1);
    fclose(fp2);
    getch();
}