#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct bike {
	char* data;
	struct bike* next;

};
struct bike* head;
void insertindex(char *x)
{
    struct bike* index=malloc(sizeof(struct bike));
    index->data=x;
    index->next=head;
    head=index;
}
void insertmake(char *x)
{
    struct bike* make=malloc(sizeof(struct bike));
    make->data=x;
    make->next=head;
    head=make;
}
void insertmodel(char *x)
{
    struct bike* model=malloc(sizeof(struct bike));
    model->data=x;
    model->next=head;
    head=model;
}
void insertcolor(char *x)
{

    struct bike* color=malloc(sizeof(struct bike));
    color->data=x;
    color->next=head;
    head=color;
}
void insertdir(char *x)
{
    struct bike* dir=malloc(sizeof(struct bike));
    dir->data=x;
    dir->next=head;
    head=dir;
}
void inserttime(char *x)
{
    struct bike* time=malloc(sizeof(struct bike));
    time->data=x;
    time->next=head;
    head=time;
}

void readfile()
{
        char*  line;
        FILE *fp;
        if (fp == NULL) {
		perror("Error \n");
		exit(1);
        }
        char* deet;
		int row=0,col=0;
		line = (char*)malloc(200*sizeof(char));
		fgets(line, 100, fp);
		while (!feof(fp)){
            //printf("%-10s  \n", line);
            while(fgets(line,100,fp)){
            deet=(char*)malloc(200*sizeof(char));
            deet=strtok(line, ",");
            while(deet!=NULL){
                    {
                    if(row==0){
                        insertindex(deet);
                    }
                    if(row==1){
                        insertmake(deet);
                    }
                    if(row==2){
                        insertmodel(deet);
                    }
                    if(row==3){
                        insertcolor(deet);
                        }
                    if(row==4){
                        insertdir(deet);
                    }
                    if(row==5){
                        inserttime(deet);
                    }

            }
            printf("$$%d$$ ",col);
            printf("<<%d>>",row);
            printf("%-20s", deet);
            row++;
            deet=strtok(NULL,",");
            }
            row=0;
                printf("%s", deet);

            col++;
        }
        fgets(line, 100, fp);
		}
    fclose(fp);

struct bike* model=head;
while(model!=NULL){
    printf("%s \n",model->data);
    model=model->next;
}
};


int main()
{
    head=NULL;
	readfile();
}

