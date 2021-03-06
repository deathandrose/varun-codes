#include <stdio.h>
#include <stdlib.h>
#include<string.h>


struct bike {
	char* index;
	char* make;
	char* model;
	char* color;
	char* dir;
	char* time;
	struct bike* next;

};
        
        void printLinkedList(struct bike* q, struct bike* head){
    q=head;
    while(q->next !=NULL){
        printf("%s\n", q->color);
        q=q->next;
    }
}



void readfile()
{
    printf("we are here");
        char*  line;
        struct bike* head;
        struct bike* data;
        struct bike* q;
        FILE *fp;
        fp = fopen("vdata.txt", "r");
        if (fp == NULL) {
		perror("Error \n");
		exit(1);
        }
        head=NULL;
        q=NULL;
        char* deet;
		int i=0,row=0,col=0;
		line = (char*)malloc(200*sizeof(char));
		fgets(line, 100, fp);
		while (!feof(fp)){
        data=(struct bike*)calloc(200,sizeof(struct bike));
            while(fgets(line,100,fp)){
            deet=(char*)malloc(200*sizeof(char));
            deet=strtok(line, ",");

            while(deet!=NULL){
                    if(row==0){
                        data->index=deet;
                    }
                    if(row==1){

                        data->make=deet;
                    }
                    if(row==2){
                        data->model=deet;
                    }
                    if(row==3){
                        data->color=deet;
                        }
                    if(row==4){
                        data->dir=deet;
                    }
                    if(row==5){
                        data->time=deet;
                    }

            row++;
            deet=strtok(NULL,",");
            }
            row=0;


/* Linked list build*/

if(head == NULL){
    head = data;
} 

if(q==NULL){
    q=data;
} else{
    q=head;
    while(q->next != NULL){
        q=q->next;
    }

    q->next = data;
}

/* Linked list build end*/
            col++;
        }
        fgets(line, 100, fp);
        printf(" \n\n%s",data->color);

		}
fclose(fp);
    printLinkedList(q, head);

};



int main()
{
	readfile();
}