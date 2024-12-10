struct stack
{
    int top;
    int size;
    int *ptr;
};


int isEmpty(struct stack st)
{
    if(st.top == -1)
    {
    printf("Stack is empty");
    return 1;
    }
    else
    return 0;
}

int isFull(struct stack st)
{
    if(st.top == st.size-1)
    {
    printf("Stack is Full");
    return 1;
    }
    else
    return 0;
}

int stackTop(struct stack st)
{
 if(!isEmpty(st))
 return st.ptr[st.top];
 return -1;
}

void createStack(struct stack *st)
{
    printf("Enter Size Please: ");
    scanf("%d" , &st->size);
    st->top=-1; // now my stack is not refer for everything
    st->ptr=(int *)malloc(st->size*sizeof(int));  // create stack
}

void Display(struct stack *st)
{
    for(int i = st->top ; i >= 0 ; i--)
    {
        printf("%d" , st->ptr[i]);
    }
        printf("\n");
}

void push(struct stack *st , int x)
{
    if(st->top == st->size-1)
    printf("Stack Overflow");
    else
    {
        st->top ++;
        st->ptr[st->top];
    }
}

int pop(struct stack *st , int x)
{
    int x = -1;
    if(st->top == -1)
    printf("Stack underflow");
    else
    {
        x = st->ptr[st->top];
        st->top --;
    }
    return x;
}

int peek(struct stack st , int index)
{
   int x=-1;
   if(st.top-index+1<0)
   printf("Invalid Index \n");
   x=st.ptr[st.top-index+1];
   return x;
}


int main()
{
 struct stack st;
 create(&st);
 
 push(&st,10);
 push(&st,20);
 push(&st,30);
 push(&st,40);
 
printf("%d \n",peek(st,2));
 
 return 0;
}