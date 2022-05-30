typedef struct QNode
{
	int data;
	struct QNode* next;
} QNode;

typedef struct
{
	QNode *front, *rear;
} Queue;

Queue* q_new();
int q_isEmpty(Queue* q);
void q_enqueue(Queue* q, int data);
void q_dequeue(Queue* q);
int q_peekFront(Queue* q);
int q_peekRear(Queue* q);
void q_display(Queue* q);
