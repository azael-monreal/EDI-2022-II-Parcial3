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
void s_push(Stack* s, int data);
void s_pop(Stack* s);
int s_peek(Stack* s);
void s_display(Stack* s);
