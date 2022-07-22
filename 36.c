#include <stdio.h>

#define MAX_CAPACITY 20 // required structure
typedef struct
{                            // array to store integers
    int array[MAX_CAPACITY]; // index of next element to add in stack A
    int topA;                // index of next element to add in stack B
    int topB;
} DoubleStack; // method to push an element to stack A
void PushA(DoubleStack *stk, int element)
{ // ensuring that stack is not full. 	//full is when topA exceeds topB
    if (stk->topA <= stk->topB)
    { // adding element to index = topA, and then incrementing topA
        stk->array[stk->topA++] = element;
    }
    else
    { // stack is full
        printf("Stack is full!\n");
    }
} // method to push an element to stack B
void PushB(DoubleStack *stk, int element)
{ // ensuring that stack is not full. same equation for both cases
    if (stk->topA <= stk->topB)
    { // adding element to index = topB, and then decrementing topB
        stk->array[stk->topB--] = element;
    }
    else
    {
        printf("Stack is full!\n");
    }
} // removes and returns top element from stack A //returns -1 if empty
int PopA(DoubleStack *stk)
{ // checking if first stack is empty. stack is empty when topA is 0
    if (stk->topA == 0)
    { // printing error and returning -1
        printf("Stack A is empty!\n");
        return -1;
    }
    else
    { // decrementing topA, returning value at new topA
        return stk->array[--stk->topA];
    }
} // removes and returns top element from stack B //returns -1 if empty
int PopB(DoubleStack *stk)
{ // stack B is full when topB is at MAX_CAPACITY-1
    if (stk->topB == MAX_CAPACITY - 1)
    {
        printf("Stack B is empty!\n");
        return -1;
    }
    else
    { // incrementing topB, returning value at new topB
        return stk->array[++stk->topB];
    }
} // this method returns 1 if stack A is empty, else returns 0
int IsEmptyA(DoubleStack *stk)
{
    if (stk->topA == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
} // this method returns 1 if stack B is empty, else returns 0
int IsEmptyB(DoubleStack *stk)
{
    if (stk->topB == MAX_CAPACITY - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{                      // creating a DoubleStack
    DoubleStack dbStk; // setting 0 as topA and MAX_CAPACITY-1 as topB. very important
    dbStk.topA = 0;
    dbStk.topB = MAX_CAPACITY - 1; // adding integers from 1 to 15 to stack A
    for (int i = 1; i <= 15; i++)
    {
        PushA(&dbStk, i);
    } // adding integers from 51 to 55 to stack B
    for (int i = 51; i <= 55; i++)
    {
        PushB(&dbStk, i);
    } // right now, total number of elements in both stacks combined will 	//be 20, which is equal to current MAX_CAPACITY. So if we try to 	//add an element to either stack, it should print error. below two 	//lines will display error to ensure that this is working correctly

    PushA(&dbStk, 7); // error
    PushB(&dbStk, 2); // error 	 	//now removing and printing top elements from stack A until it is empty 	//should display numbers from 15 to 1 (in reverse order)
    printf("Stack A: ");
    while (IsEmptyA(&dbStk) != 1)
    {
        printf("%d ", PopA(&dbStk));
    }
    printf("\n"); // now removing and printing top elements from stack B until it is empty 	//should display numbers from 55 to 51 (in reverse order)
    printf("Stack B: ");
    while (IsEmptyB(&dbStk) != 1)
    {
        printf("%d ", PopB(&dbStk));
    }
    printf("\n");
    return 0;
}

