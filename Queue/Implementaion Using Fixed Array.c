#include <stdio.h>
#include <stdlib.h>

struct student
{
    int id;
    char name[20];
};

struct queue
{
    int size;   // the size which i will store it from queue.
    int front;
    int rear;
    struct student stdata[50];
};

int Enqueue(struct queue *q , struct student st)
{
    if(q->rear == q->size -1)
    {
        printf("Queue is Full");
        return 0;
    }
    else
    {
        q->rear ++;                // ana zawdt rear
        q->stdata[q->rear] = st;  // store the new student
        return 1;
    }
}


struct student Dequeue(struct queue *q)
{
    struct student st = {0 , ""};
    if(q->front == q->rear == -1)
        printf("Queue is empty \n");
    else
    {
        q->front ++;
        st = q->stdata[q->front];
    }
    return st;
}


void display(struct queue *q)
{
    if(q->front == q->rear == -1)
        printf("queue is empty");

        for (int i = q->front + 1; i <= q->rear; i++)
        {
            printf("ID: %d, Name: %s\n", q->stdata[i].id, q->stdata[i].name);
        }
}



int main()
{
    struct queue StoreStudentInfo;           // struct from queue with all memebers exist it.
    printf("Enter The size Of Queue:  ");
    scanf("%d" ,&StoreStudentInfo.size);    // Mn 8elal el-size Dh i will store array of student --> 7
    if(StoreStudentInfo.size > 50 )
    {
       printf("The size of Queue is less then %d.\n" ,StoreStudentInfo.size );
       return 1;
    }

    StoreStudentInfo.front = StoreStudentInfo.rear = -1;
    int choice;
    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: 
            {
                struct student st;
                printf("Enter ID: ");
                scanf("%d", &st.id);
                printf("Enter Name: ");
                scanf("%[^\n]",&st.name);
                if (Enqueue(&StoreStudentInfo,st))
                    printf("Student added successfully.\n");
                else
                    printf("Student Not added successfully beacause Queue if full.\n");
                break;
            }
            case 2: 
            {
                struct student st = Dequeue(&StoreStudentInfo);
                if (st.id != 0 && st.name[0] != '\0')
                    printf("Dequeue Student -> ID: %d, Name: %s\n", st.id, st.name);
                else
                    printf("The initial value for Student -> ID: %d, Name: %s\n", st.id, st.name);
                break;
            }
            case 3:
                display(&StoreStudentInfo);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}