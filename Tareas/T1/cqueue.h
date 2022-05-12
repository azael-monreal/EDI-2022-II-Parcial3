typedef struct Student
{
	char name[100];
	int type;
} Student;

typedef struct QNode
{
	Student data;
	struct QNode* next;
} QNode;

typedef struct CQueuee
{
	QNode *front, *rear;
} CQueue;

CQueue* newCQueue();
int qIsEmpty(CQueue* q);
void enqueue(CQueue* q, Student data);
void dequeue(CQueue* q);
void cycleQueue(CQueue* q);
Student* peekFront(CQueue* q);
Student* peekRear(CQueue* q);
void displayQueue2(QNode* front, QNode* qNode);
void displayQueue(CQueue* q);
