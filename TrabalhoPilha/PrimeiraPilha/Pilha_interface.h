 #ifndef _STACK_H
 #define _STACK_H

 #include <dbLkList.h>
 
 typedef struct Stack *StackP;
 typedef void (StDestroyFunction)(StackP st, void *object);

 typedef struct _Stack_ {
         DbLkList *elements;
         StDestroyFunction *destroyFunction;
 } Stack;
 
 typedef enum { ST_DM_KEEP=0, ST_DM_FREE } StDestroyMode;
 
 
 Stack *stCreate();
 void stDestroy(Stack **stackAddress, StDestroyMode mode);
 int stPush(Stack *st, void *object);
 int stPop(Stack *st, void **objectAddress);
 int stGetTop(Stack *st, void **objectAddress);
 int stNumElements(Stack *st);
 int stRegisterDestroyFunction(Stack *st, StDestroyFunction *destroyFunction);
