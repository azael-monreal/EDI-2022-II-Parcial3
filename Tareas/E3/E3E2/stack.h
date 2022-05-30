typedef struct SNode
{
	int data;
	struct SNode* next;
} SNode;

typedef struct
{
	SNode* root;
} Stack;

Stack* s_new();
int s_isEmpty(Stack* s);
void s_push(Stack* s, char data);
char s_pop(Stack* s);
char s_peek(Stack* s);
void s_display(Stack* s);
