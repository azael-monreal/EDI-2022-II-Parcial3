typedef struct SNode
{
	int data;
	struct SNode* next;
} SNode;

int sIsEmpty(SNode* root);
void push(SNode** root, int data);
void pop(SNode** root);
int peek(SNode* root);
void displayStack(SNode* root);
void displayR(SNode* root);
