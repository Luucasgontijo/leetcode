// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75


typedef struct Node {
    char vowel;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;


void push(Stack* stack, char vowel) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vowel = vowel;
    newNode->next = stack->top;
    stack->top = newNode;
}


char pop(Stack* stack) {
    Node* temp = stack->top;
    char poppedVowel = temp->vowel;
    stack->top = temp->next;
    free(temp);  
    return poppedVowel;
}


char* reverseVowels(char* s) {
    Stack vowelsStack = {NULL};  
    int i = 0;


    while (s[i] != '\0') {
         if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' ||
            s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
            push(&vowelsStack, s[i]);
        }
        i++;
    }


    i = 0;  
    while (s[i] != '\0') {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' ||
            s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
            s[i] = pop(&vowelsStack);  
        }
        i++;
    }

    return s;
}

