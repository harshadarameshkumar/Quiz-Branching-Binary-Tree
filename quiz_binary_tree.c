#include <stdio.h>
#include <stdlib.h>

typedef struct QuizNode {
    char *question;   
    char *result;     
    struct QuizNode *yes;
    struct QuizNode *no;
} QuizNode;


QuizNode* createNode(char *question, char *result) {
    QuizNode *node = (QuizNode*)malloc(sizeof(QuizNode));
    node->question = question;
    node->result = result;
    node->yes = NULL;
    node->no = NULL;
    return node;
}


void startQuiz(QuizNode *root) {
    QuizNode *current = root;
    int choice;

    while (current->question != NULL) {
        printf("%s (1 = Yes, 0 = No): ", current->question);
        scanf("%d", &choice);

        if (choice == 1)
            current = current->yes;
        else
            current = current->no;
    }

    printf("\nResult: %s\n", current->result);
}

int main() {
    
    QuizNode *teamPlayer = createNode(NULL, "You are a Team Player!");
    QuizNode *soloPlayer = createNode(NULL, "You prefer Solo Activities!");
    QuizNode *bookLover = createNode(NULL, "You are a Book Lover!");
    QuizNode *relaxer = createNode(NULL, "You enjoy Relaxing!");

   
    QuizNode *q3 = createNode("Do you prefer team sports?", NULL);
    q3->yes = teamPlayer;
    q3->no = soloPlayer;

    QuizNode *q2 = createNode("Do you enjoy reading?", NULL);
    q2->yes = bookLover;
    q2->no = relaxer;

    QuizNode *q1 = createNode("Do you like sports?", NULL);
    q1->yes = q3;
    q1->no = q2;

   
    startQuiz(q1);

    return 0;
}
