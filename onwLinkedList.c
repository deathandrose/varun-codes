#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct myLinked
{
    char* index;
    char* model;
    char* make;
    char* color;
    char* direction;
    char* time;
    struct myLinked* next;

}*h,*q,*n;


int main(){


    char name[100][100] = {"Dhanush", "Varun", "kaadi", "rahul", "Tharun"};
    char color[100][100] = {"Red", "Blue","Orange", "black", "purple"};

    h = NULL;
    n = NULL;
    q = NULL;;
    // q->next = NULL;

    int i=0;
    for(i=0;i<5;i++){


        n = (struct myLinked*) malloc(sizeof(struct myLinked));
        n->index = name[i];
        n->color=color[i];
        q=h;

        
        if(h == NULL){
            h = n;
        }
        if(q == NULL){
            q=n;
        } else{


            while(q->next != NULL){
                q=q->next;
            }

            q->next = n;
        }
    }


    q = h;

    while(q-> next != NULL){
        printf("%s\n", q->index);
        printf("%s\n",q->color);
        q=q->next;
    }

    return 0;
}
