//2390. Removing Stars From a String
// https://leetcode.com/problems/removing-stars-from-a-string/?envType=study-plan-v2&envId=leetcode-75

typedef struct Node{
    char data;
    struct Node* next;
} Node;


typedef struct {
    Node* top;
} stack;


Node* newNode(char s){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = s;
    node->next = NULL;
    return node;
}

void push(char s, Node** top){
    Node* node = newNode(s);
    node->next = *top;
    *top = node;
}

void pop(Node** top){
    Node* temp = (*top);
    (*top) = temp->next;
    free(temp);
}

char* getFirstChar(Node* top) {
    if (top == NULL) return '\0';
    while (top->next != NULL) {
        top = top->next; 
    }
    return &top->data;
}


char* removeStars(char* s) {
    Node* stack = NULL;
    int i = 0, size = 0;
    
    while (s[i] != '\0'){
        if (s[i] != '*'){
            push(s[i], &stack);
            size++;
        } else if (stack) {
            pop(&stack);
            size--;
        }
        i++;
    }


    // Node* temp = stack;
    // while (temp) {
    //     size++;
    //     temp = temp->next;
    // }


    char* result = (char*)malloc(size + 1);
    if (!result) return NULL;
    result[size] = '\0';


    for (int j = size - 1; j >= 0 && stack!= NULL; j--) {
        result[j] = stack->data;
        pop(&stack);
    }

    return result;
}