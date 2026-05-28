// chatbot

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *question;
    char *answer;
} QAndA;
QAndA *db = NULL;
int size = 0;

void addEntry(char *Q, char *A){
    int n_size = size + 1;
    QAndA *temp = realloc(db, n_size * sizeof(QAndA));
    if(temp == NULL){
        printf("Fault at reallocationg\n");
        exit(1);
    }
    db = temp;

    db[size].question = strdup(Q);
    db[size].answer = strdup(A);

    size += 1;
}

int main(){
    addEntry("hi", "Hello!");
    char query[256];
    char answer[256];
    while(1){
        printf(": ");
        if(scanf(" %255[^\n]", query) != 1) break;
        if(strcmp("bye", query) == 0){
            printf("I sEE YuO!\n");
            break;
        }
        int found = 0;
        for(int i = 0; i < size; i++){
            if(strcmp(db[i].question, query) == 0){
                printf("-> ");
                printf("%s\n", db[i].answer);
                found = 1;
                break;
            }
        }

        if(found == 0){
            printf("Answer: ");
            scanf(" %255[^\n]", answer);
            addEntry(query, answer);
            /*printf(query);*/
            /*printf(answer);*/
            /*printf(db[3].question);*/
        }
    }
    free(db);
    return 0;
}
