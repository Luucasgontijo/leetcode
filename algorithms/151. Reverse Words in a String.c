// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75


typedef struct Node{
    char* val;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* top;
} Stack;

void push(Stack* stack, char* word){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = strdup(word);
    newNode->next = stack->top;
    stack->top = newNode;
}

char* pop(Stack* stack){ 
    Node* temp = stack->top;
    char* word = temp->val;
    stack->top = temp->next;
    free(temp);
    return word;
}

char* reverseWords(char* s) {
    Stack stack = {NULL};
    int len = strlen(s);
    int i = 0, capacity = 5;
    char* word = (char*)malloc(len + 1);
    
    while (*s != '\0'){
        if (*s == ' '){ // end of the word
            if (i > 0){
                word[i] = '\0';
                push(&stack, word);
                i = 0;
            }
        } else{
            word[i++] = *s;
        }
        s++;
    }

    //i have to add this conditional statement because it was not pushing the last word if it was instantly followed by null terminator

    if (i > 0) {
        word[i] = '\0';  // Null-terminate the last word 
        push(&stack, word);  // Push the last word onto the stack
    }

    free(word);

    char* result = (char*)malloc(len+1);
    result[0] = '\0';

    while (stack.top){
        char* word = pop(&stack);
        strcat(result, word);
        free(word);
        if (stack.top) strcat(result, " ");
    }

    return result;
}