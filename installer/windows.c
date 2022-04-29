//COMPILE WITH: 'x86_64-w64-mingw32-gcc -I "/opt/bah/libs/windows/include/" -L "/opt/bah/libs/windows/" ../installer/windows.c -static -O1 -w  -l:gc.a -lpthread -lm'

    void __BAH_init();
    #define noCheck(v) v
    #define array(type)	    struct{	    type *data;     long int length;     long int elemSize;     }
    typedef array(char*)* __BAH_ARR_TYPE_cpstring;
    long int __BAH__main(__BAH_ARR_TYPE_cpstring);
    
            #include <gc.h>
            int main(int argc, char ** argv) {
            GC_INIT();
            array(char*) * args = GC_MALLOC(sizeof(array(char*)));
            args->data = GC_MALLOC(sizeof(char*)*argc);
            memcpy(args->data, argv, sizeof(char*)*argc);
            args->elemSize = sizeof(char*);
            args->length = argc;
            __BAH_init();
            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);
            GC_FREE(args->data);
            GC_FREE(args);
            return r;
            };
            #define main(v) __BAH__main(v)
            #include <signal.h>
#include <string.h>
void __BAH_panic(char * e,char * l);
char * __Bah_safe_string(char * s);
#define null (void *)0
#define true (char)1
#define false (char)0
long int __bah_strcmp(char * a,char * b){
if (((void *)a==null)) {
a = "";
}
if (((void *)b==null)) {
b = "";
}
return strcmp(a,b);
};
#define strcmp __bah_strcmp
long int __bah_strlen(char * s){
if (((void *)s==null)) {
return 0;
}
return strlen(s);
};
#define strlen __bah_strlen
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#define SIZE_OF_INT 8
#define SIZE_OF_CHAR 1
#define SIZE_OF_INT32 4
#define SIZE_OF_FLOAT32 4
#define SIZE_OF_FLOAT 8
long int len(void * a){
if ((a==null)) {
return 0;
}
long int i = 0;
array(void*)*arr=a;
i=arr->length;
return i;
};
#include <gc.h>
void * memoryAlloc(long int s){
return GC_MALLOC(s);
};
void destroy(void * a){
GC_FREE(a);
};
void clear(void * a){
array(void*)*arr=a;
destroy(arr->data);
arr->data=memoryAlloc(sizeof(0));
arr->length=0;
};
void * memoryRealloc(void * p,long int s){
return GC_REALLOC(p,s);
};
void cleanShutDown(){
exit(1);
return;
};
void memoryOnEnd(void * obj,void * fn){
GC_REGISTER_FINALIZER_IGNORE_SELF(obj,fn,null,null,null);
};
void append(void * a,void * b){
array(void*)*arrA=a;
array(void*)*arrB=b;
long int lenA = 0;
long int lenB = 0;
long int realSizeA = 0;
long int realSizeB = 0;
lenA=len(arrA);
lenB=len(arrB);
if ((lenB==0)) {
return;
}
if ((lenA==0)) {
arrA->data=arrB->data;
arrA->length=arrB->length;
return;
}
realSizeA=lenA*arrA->elemSize;
realSizeB=lenB*arrB->elemSize;
void * buff = memoryAlloc(realSizeA+realSizeB+32);
memcpy(buff,arrA->data,realSizeA);
memcpy(buff+lenA,arrB->data,realSizeB);
arrA->length=lenA+lenB;
arrA->data=buff;
};
void copy(void * a,void * b){
array(void*)*arrA=a;
array(void*)*arrB=b;
long int lenB = 0;
long int realSizeB = 0;
lenB=len(arrB);
realSizeB=lenB*arrB->elemSize;
arrA->data=memoryAlloc(realSizeB);
memcpy(arrA->data,arrB->data,realSizeB);
arrA->length=arrB->length;
};
#define PROT_READ 2
#define PROT_READWRITE 4
void * GLOBAL_MAPPED_MEMORY_FILE;
void * sharedMemory(long int size){
if ((size==0)) {
size = 4096;
}
if ((GLOBAL_MAPPED_MEMORY_FILE==null)) {
GLOBAL_MAPPED_MEMORY_FILE = CreateFileMapping(-1,0,PROT_READWRITE,0,size,"Global\\BahFileMap");
}
if ((GLOBAL_MAPPED_MEMORY_FILE==null)) {
printf("sharedMemory: could not make map file.");
exit(1);
}
void * r = MapViewOfFile(GLOBAL_MAPPED_MEMORY_FILE,FILE_MAP_ALL_ACCESS,0,0,size);
return r;
};
void closeSharedMemory(){
CloseHandle(GLOBAL_MAPPED_MEMORY_FILE);
};
void allocateArray(void * arr,long int nbElems){
array(void*)*a=arr;
a->length=nbElems;
a->data=memoryAlloc(nbElems*a->elemSize);
};
typedef array(char)* __BAH_ARR_TYPE_char;
__BAH_ARR_TYPE_char ser(void * a);
__BAH_ARR_TYPE_char __serialize(void * a,long int s){
char * r = memoryAlloc(s+9);
memcpy(r,&s,8);
memcpy(r+8,a,s);
long int l = s+1;
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
arr->length=s+8;
arr->elemSize=1;
arr->data=r;
return arr;
};
long int serlen(__BAH_ARR_TYPE_char data){

                        if (data->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: data[%d] with length %d", 0, data->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/memory.bah:194");
                        };
                        
                        if (data->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: data[%d] with length %d", 1, data->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/memory.bah:194");
                        };
                        
                        if (data->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: data[%d] with length %d", 2, data->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/memory.bah:194");
                        };
                        
                        if (data->length <= 3) {
                            char buff[300];
                            snprintf(buff, 299, "array: data[%d] with length %d", 3, data->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/memory.bah:194");
                        };
                        
                        if (data->length <= 4) {
                            char buff[300];
                            snprintf(buff, 299, "array: data[%d] with length %d", 4, data->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/memory.bah:194");
                        };
                        
                        if (data->length <= 5) {
                            char buff[300];
                            snprintf(buff, 299, "array: data[%d] with length %d", 5, data->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/memory.bah:194");
                        };
                        
                        if (data->length <= 6) {
                            char buff[300];
                            snprintf(buff, 299, "array: data[%d] with length %d", 6, data->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/memory.bah:194");
                        };
                        
                        if (data->length <= 7) {
                            char buff[300];
                            snprintf(buff, 299, "array: data[%d] with length %d", 7, data->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/memory.bah:194");
                        };
                        array(char)* sarr = memoryAlloc(sizeof(array(char)));

sarr->length = 8;
sarr->elemSize = sizeof(char);
sarr->data = memoryAlloc(sizeof(char) * 50);sarr->data[0] = data->data[0];
sarr->data[1] = data->data[1];
sarr->data[2] = data->data[2];
sarr->data[3] = data->data[3];
sarr->data[4] = data->data[4];
sarr->data[5] = data->data[5];
sarr->data[6] = data->data[6];
sarr->data[7] = data->data[7];
return *sarr->data;
};
void * unser(__BAH_ARR_TYPE_char data){
long int sptr = serlen(data);
void * r = memoryAlloc(sptr);
memcpy(r,data->data+8,sptr);
return r;
};
char * memoryAllocSTR(long int s){
char * r = GC_malloc_atomic(s);
r[s-1]=0;
return r;
};
void delete(void * a,long int i){
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
arr = a;
long int length = len(arr);
if (((i>=length)||(i<0))) {
return;
}
if ((length==1)) {
arr->length=0;
return;
}
long int elemSize = arr->elemSize;
char* data = arr->data;
void * destOffset = elemSize*i;
i = i+1;
void * offset = elemSize*i;
char* src = (long int)data+(long int)offset;
char* dest = (long int)data+(long int)destOffset;
long int rightNB = length-(i-1);
memmove(dest,src,rightNB*elemSize);
arr->length=length-1;
};
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen = len(arr);
char * str = memoryAllocSTR(strLen+1);
memcpy(str,arr->data,strLen);
return str;
};
__BAH_ARR_TYPE_char strToArr(char * str){
long int strLen = strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
arr->data=memoryAlloc(strLen+1);
memcpy(arr->data,str,strLen);
arr->length=strLen;
return arr;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr){
return arr->data;
};
__BAH_ARR_TYPE_char strAsArr(char * str){
long int l = strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
arr->length=l;
arr->data=str;
return arr;
};
void strTrimLeft(char ** s,long int i){
long int ls = strlen(*s);
char * ns = memoryAlloc(ls-i+1);
memcpy(ns,*s+i,ls-i);
*s = ns;
};
void strTrimRight(char ** s,long int i){
long int ls = strlen(*s);
char * ns = memoryAlloc(ls-i+1);
memcpy(ns,*s,ls-i);
*s = ns;
};
#define __bah_memory_realloc memoryRealloc
#define __bah_memory_str memoryAllocSTR
char * concatCPSTRING(char * a,char * b){
long int lenA = strlen(a);
long int lenB = strlen(b);
char * r = memoryAlloc(lenA+lenB+1);
strncpy(r,a,lenA);
strcat(r,b);
return r;
};
char * __STR(char * a){
long int lenA = strlen(a);
char * r = memoryAllocSTR(lenA+1);
memcpy(r,a,lenA);
return r;
};
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void print(char * s){
write((void *)1,s,strlen(s));
};
void * cArr(void * arr){
array(void*)*a=arr;
return a->data;
};
char __checkString(char * s,char * l){
if (((void *)s==null)) {
char * ____BAH_COMPILER_VAR_0 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("cpstring (");
long int strLen_2 = strlen(l);
long int strLen_4 = strlen(") is null \n");
;                            
                    ____BAH_COMPILER_VAR_0 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_0+currStrOff, "cpstring (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_0+currStrOff, l, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_0+currStrOff, ") is null \n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                print(____BAH_COMPILER_VAR_0);
exit(1);
}
return true;
};
#include <pthread.h>
#define __thread_create pthread_create
#define __thread_join pthread_join
#define currentThread pthread_self
struct mutex {
pthread_mutex_t id;
void(*init)(struct mutex* this);
void(*lock)(struct mutex* this);
void(*unlock)(struct mutex* this);
void(*destroy)(struct mutex* this);
};
void mutex__init(struct mutex* this){
pthread_mutex_init(&this->id,0);
};
void mutex__lock(struct mutex* this){
pthread_mutex_lock(&this->id);
};
void mutex__unlock(struct mutex* this){
pthread_mutex_unlock(&this->id);
};
void mutex__destroy(struct mutex* this){
pthread_mutex_destroy(&this->id);
};
struct mutexCondition {
pthread_cond_t id;
void(*init)(struct mutexCondition* this);
void(*wait)(struct mutexCondition* this,struct mutex m);
void(*send)(struct mutexCondition* this);
void(*destroy)(struct mutexCondition* this);
};
void mutexCondition__init(struct mutexCondition* this){
pthread_cond_init(&this->id,0);
};
void mutexCondition__wait(struct mutexCondition* this,struct mutex m){
pthread_mutex_t mid = m.id;
pthread_cond_wait(&this->id,&mid);
};
void mutexCondition__send(struct mutexCondition* this){
pthread_cond_signal(&this->id);
};
void mutexCondition__destroy(struct mutexCondition* this){
pthread_cond_destroy(&this->id);
};
struct mutexCondition mutexCondition(){
struct mutexCondition ____BAH_COMPILER_VAR_1 = {};
____BAH_COMPILER_VAR_1.init = mutexCondition__init;
____BAH_COMPILER_VAR_1.wait = mutexCondition__wait;
____BAH_COMPILER_VAR_1.send = mutexCondition__send;
____BAH_COMPILER_VAR_1.destroy = mutexCondition__destroy;
#define m ____BAH_COMPILER_VAR_1
m.init(&m);
return m;
};
struct thread {
pthread_t id;
void (*handle)(void *);
void(*create)(struct thread* this);
void(*createWithArg)(struct thread* this,void * arg);
void(*wait)(struct thread* this);
};
void thread__create(struct thread* this){
__thread_create(&this->id,null,this->handle,null);
};
void thread__createWithArg(struct thread* this,void * arg){
__thread_create(&this->id,null,this->handle,arg);
};
void thread__wait(struct thread* this){
__thread_join(this->id,null);
};
struct mutex mutex(){
struct mutex ____BAH_COMPILER_VAR_2 = {};
____BAH_COMPILER_VAR_2.init = mutex__init;
____BAH_COMPILER_VAR_2.lock = mutex__lock;
____BAH_COMPILER_VAR_2.unlock = mutex__unlock;
____BAH_COMPILER_VAR_2.destroy = mutex__destroy;
#define m ____BAH_COMPILER_VAR_2
m.init(&m);
return m;
};
struct queueNode {
long int key;
void * data;
struct queueNode* next;
struct queueNode* prev;
};
struct queue {
long int length;
struct queueNode* head;
struct queueNode* end;
void(*insert)(struct queue* this,void * data);
void(*delete)(struct queue* this,long int key);
void *(*get)(struct queue* this,long int key);
void(*set)(struct queue* this,long int key,void * data);
void *(*pop)(struct queue* this);
void(*clear)(struct queue* this);
};
void queue__insert(struct queue* this,void * data){
struct queueNode* ____BAH_COMPILER_VAR_3 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_3->data= null;
____BAH_COMPILER_VAR_3->next= null;
____BAH_COMPILER_VAR_3->prev= null;
____BAH_COMPILER_VAR_3->key = this->length;
____BAH_COMPILER_VAR_3->data = data;
____BAH_COMPILER_VAR_3->prev = this->end;
struct queueNode* node = ____BAH_COMPILER_VAR_3;
this->length = this->length+1;
if ((this->end==null)) {
this->head = node;
this->end = this->head;
}
else {
this->end->next = node;
this->end = node;
}
};
void queue__delete(struct queue* this,long int key){
if ((this->length==0)) {
return;
}
struct queueNode* current = this->head;
struct queueNode* previous= null;
while ((current->key!=key)) {
if ((current->next==null)) {
return;
}
previous = current;
current = current->next;
};
if ((current==this->head)) {
this->head = current->next;
}
else {
previous->next = current->next;
}
this->length = this->length-1;
};
void * queue__get(struct queue* this,long int key){
long int z = 0;
void * zp = (void *)z;
if ((this->length==0)) {
return zp;
}
struct queueNode* ptr = this->head;
while ((ptr->key!=key)) {
if ((ptr->next==null)) {
return zp;
}
ptr = ptr->next;
};
void * data = ptr->data;
return data;
};
void queue__set(struct queue* this,long int key,void * data){
this->delete(this,key);
struct queueNode* ____BAH_COMPILER_VAR_4 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_4->data= null;
____BAH_COMPILER_VAR_4->next= null;
____BAH_COMPILER_VAR_4->prev= null;
struct queueNode* node = ____BAH_COMPILER_VAR_4;
node->key = key;
node->data = data;
node->next = this->head;
this->length = this->length+1;
this->head = node;
};
void * queue__pop(struct queue* this){
if ((this->head==null)) {
return null;
}
void * data = this->head->data;
this->head = this->head->next;
if ((this->head==null)) {
this->end = null;
}
this->length = this->length-1;
return data;
};
void queue__clear(struct queue* this){
this->head = (void *)0;
this->length = 0;
};
struct channel {
pthread_mutex_t m_mut;
pthread_cond_t w_cond;
pthread_cond_t r_cond;
long int w_waitting;
long int r_waitting;
struct queue* queue;
long int cap;
void(*send)(struct channel* this,void * data);
void(*sendAny)(struct channel* this,void * data,long int len);
void *(*receive)(struct channel* this);
void(*destroy)(struct channel* this);
long int(*len)(struct channel* this);
};
void channel__send(struct channel* this,void * data){
pthread_mutex_lock(&this->m_mut);
if ((this->cap!=-1)) {
while ((this->queue->length==this->cap)) {
this->w_waitting = this->w_waitting+1;
pthread_cond_wait(&this->w_cond,&this->m_mut);
this->w_waitting = this->w_waitting-1;
};
}
this->queue->insert(this->queue,data);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void channel__sendAny(struct channel* this,void * data,long int len){
pthread_mutex_lock(&this->m_mut);
if ((this->cap!=-1)) {
while ((this->queue->length==this->cap)) {
this->w_waitting = this->w_waitting+1;
pthread_cond_wait(&this->w_cond,&this->m_mut);
this->w_waitting = this->w_waitting-1;
};
}
void * p = memoryAlloc(len);
memcpy(p,data,len);
this->queue->insert(this->queue,p);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void * channel__receive(struct channel* this){
pthread_mutex_lock(&this->m_mut);
while ((this->queue->length==0)) {
this->r_waitting = this->r_waitting+1;
pthread_cond_wait(&this->r_cond,&this->m_mut);
this->r_waitting = this->r_waitting-1;
};
void * data = this->queue->pop(this->queue);
if ((this->w_waitting>0)) {
pthread_cond_signal(&this->w_cond);
}
pthread_mutex_unlock(&this->m_mut);
return data;
};
void channel__destroy(struct channel* this){
pthread_mutex_destroy(&this->m_mut);
pthread_cond_destroy(&this->w_cond);
pthread_cond_destroy(&this->r_cond);
};
long int channel__len(struct channel* this){
long int l = this->queue->length;
return l;
};
struct channel* channel(){
struct channel* ____BAH_COMPILER_VAR_5 = memoryAlloc(sizeof(struct channel));
____BAH_COMPILER_VAR_5->w_waitting = 0;
____BAH_COMPILER_VAR_5->r_waitting = 0;
____BAH_COMPILER_VAR_5->queue= null;
____BAH_COMPILER_VAR_5->cap = -1;
____BAH_COMPILER_VAR_5->send = channel__send;
____BAH_COMPILER_VAR_5->sendAny = channel__sendAny;
____BAH_COMPILER_VAR_5->receive = channel__receive;
____BAH_COMPILER_VAR_5->destroy = channel__destroy;
____BAH_COMPILER_VAR_5->len = channel__len;
struct channel* c = ____BAH_COMPILER_VAR_5;
pthread_mutex_init(&c->m_mut,0);
pthread_cond_init(&c->w_cond,0);
pthread_cond_init(&c->r_cond,0);
struct queue* ____BAH_COMPILER_VAR_6 = memoryAlloc(sizeof(struct queue));
____BAH_COMPILER_VAR_6->length = 0;
____BAH_COMPILER_VAR_6->head = null;
____BAH_COMPILER_VAR_6->end = null;
____BAH_COMPILER_VAR_6->insert = queue__insert;
____BAH_COMPILER_VAR_6->delete = queue__delete;
____BAH_COMPILER_VAR_6->get = queue__get;
____BAH_COMPILER_VAR_6->set = queue__set;
____BAH_COMPILER_VAR_6->pop = queue__pop;
____BAH_COMPILER_VAR_6->clear = queue__clear;
c->queue = ____BAH_COMPILER_VAR_6;
return c;
};
void setChanCap(void * c,long int cap){
struct channel* cp = c;
cp->cap = cap;
};
struct channel * __BAH_panic_chan;
void __Bah_common_panic(char * e){
if (strlen(e)) {
print(e);
print("\n");
cleanShutDown();
}
};
#define panic __Bah_common_panic
struct __Bah_fnName_mapper {
void * p;
char * n;
};
array(struct __Bah_fnName_mapper)* __Bah_fnNames;
void __Bah_fnNames_append(struct __Bah_fnName_mapper fnn){

{
long nLength = len(__Bah_fnNames);
if (__Bah_fnNames->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(__Bah_fnNames->data, (nLength+50)*sizeof(struct __Bah_fnName_mapper));
__Bah_fnNames->data = newPtr;
}
__Bah_fnNames->data[len(__Bah_fnNames)] = fnn;
__Bah_fnNames->length = nLength+1;
} else {
__Bah_fnNames->data[len(__Bah_fnNames)] = fnn;
}
};
};
void __BAH_panic(char * e,char * line){
if ((__BAH_panic_chan!=null)) {
__BAH_panic_chan->send(__BAH_panic_chan, e);
return;
}
char * ____BAH_COMPILER_VAR_7 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("panic (");
long int strLen_2 = strlen(line);
long int strLen_4 = strlen("): ");
long int strLen_6 = strlen(e);
long int strLen_8 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_7 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_7+currStrOff, "panic (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_7+currStrOff, line, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_7+currStrOff, "): ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_7+currStrOff, e, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_7+currStrOff, "\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                print(____BAH_COMPILER_VAR_7);
cleanShutDown();
};
void __Bah_segfault_handle(long int sig){
__BAH_panic("Memory error (segfault).","???");
};
char __Bah_init_segfaultHandle(){
signal(SIGSEGV,__Bah_segfault_handle);
return true;
};
char __Bah_init_segfaultHandle_OK;
char recover(char ** s){
__BAH_panic_chan = channel();
char * err = (char *)__BAH_panic_chan->receive(__BAH_panic_chan);
*s = err;
return true;
};
char * __Bah_safe_string(char * s){
if (((void *)s==null)) {
return "(nil)";
}
if ((strlen(s)>50)) {
s = __STR(s);
array(char)* a = strAsArr(s);

{
long nLength = 47;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[47] = 46;
a->length = nLength+1;
} else {
a->data[47] = 46;
}
};

{
long nLength = 48;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[48] = 46;
a->length = nLength+1;
} else {
a->data[48] = 46;
}
};

{
long nLength = 49;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[49] = 46;
a->length = nLength+1;
} else {
a->data[49] = 46;
}
};

{
long nLength = 50;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[50] = (char)0;
a->length = nLength+1;
} else {
a->data[50] = (char)0;
}
};
}
char * ____BAH_COMPILER_VAR_8 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_1 = strlen("\"");
long int strLen_3 = strlen(s);
long int strLen_5 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_8 = memoryAllocSTR(1 + strLen_1 + strLen_3 + strLen_5);
                    
                        memcpy(____BAH_COMPILER_VAR_8+currStrOff, "\"", strLen_1);
                        currStrOff += strLen_1;
                        
                        memcpy(____BAH_COMPILER_VAR_8+currStrOff, s, strLen_3);
                        currStrOff += strLen_3;
                        
                        memcpy(____BAH_COMPILER_VAR_8+currStrOff, "\"", strLen_5);
                        currStrOff += strLen_5;
                        
                }
                return ____BAH_COMPILER_VAR_8;
};
char cpstringCharAt(char * s,long int i){
char c = (char)0;
c=s[i];
return c;
};
char * cpstringSubsitute(char * s,long int i,long int l){
long int size = l-i;
char * ns = memoryAllocSTR(size+1);
memcpy(ns,s+i,size);
return ns;
};
typedef array(void *)* __BAH_ARR_TYPE_ptr;
void * arraySubstitute(__BAH_ARR_TYPE_ptr arr,long int i,long int l){
long int length = l-i;
long int offset = i*arr->elemSize;
array(void *)* na = memoryAlloc(sizeof(array(void *)));

na->length = 0;
na->elemSize = sizeof(void *);
na->elemSize=arr->elemSize;
na->length=length;
long int allocLength = length;
if ((length>50)) {
allocLength = allocLength+allocLength%50;
}
else {
allocLength = 50;
}
long int size = allocLength*arr->elemSize;
long int realSize = length*arr->elemSize;
void * data = memoryAlloc(size);
char * oData = arr->data;
memcpy(data,oData+offset,realSize);
na->data=data;
return na;
};
long int __Bah_map_hash(char * s,long int l){
long int hash = 5381;
long int i = 0;
for (; (i<strlen(s)); i = i+1) {
hash = ((long int)hash<<5+0)+hash+(long int)cpstringCharAt(s,i);
};
if ((hash<0)) {
hash = 0-hash;
}
return hash%l;
};
struct mapElem {
char * key;
void * val;
};
struct mapWrapper {
array(struct mapElem*)* elems;
long int length;
void(*grow)(struct mapWrapper* this,long int nb);
void(*set)(struct mapWrapper* this,char * k,void * e);
void(*setAny)(struct mapWrapper* this,char * k,void * e,long int s);
void(*delete)(struct mapWrapper* this,char * k);
void *(*get)(struct mapWrapper* this,char * k);
};
void mapWrapper__grow(struct mapWrapper* this,long int nb){
long int l = len(this->elems);
long int i = l;
for (; (i<l+nb); i = i+1) {

{
long nLength = i;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[i] = null;
this->elems->length = nLength+1;
} else {
this->elems->data[i] = null;
}
};
};
};
void mapWrapper__set(struct mapWrapper* this,char * k,void * e){
if ((this->length*2>=len(this->elems))) {
this->grow(this,this->length);
}
struct mapElem* ____BAH_COMPILER_VAR_9 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_9->key= null;
____BAH_COMPILER_VAR_9->val= null;
____BAH_COMPILER_VAR_9->key = k;
____BAH_COMPILER_VAR_9->val = e;
struct mapElem* elem = ____BAH_COMPILER_VAR_9;
long int ind = __Bah_map_hash(k,len(this->elems));
long int i = 0;
for (; (i<len(this->elems)); i = i+1) {
long int j = (i+ind)%len(this->elems);

                        if (this->elems->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->elems[%d] with length %d", j, this->elems->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/map.bah:42");
                        };
                        struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] = elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] = elem;
}
};
this->length = this->length+1;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] = elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] = elem;
}
};
break;
}
};
};
void mapWrapper__setAny(struct mapWrapper* this,char * k,void * e,long int s){
if ((this->length==0)) {
this->grow(this,50);
}
if ((this->length*2>=len(this->elems))) {
this->grow(this,this->length);
}
void * p = memoryAlloc(s);
memcpy(p,e,s);
struct mapElem* ____BAH_COMPILER_VAR_10 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_10->key= null;
____BAH_COMPILER_VAR_10->val= null;
____BAH_COMPILER_VAR_10->key = k;
____BAH_COMPILER_VAR_10->val = p;
struct mapElem* elem = ____BAH_COMPILER_VAR_10;
long int ind = __Bah_map_hash(k,len(this->elems));
long int i = 0;
for (; (i<len(this->elems)); i = i+1) {
long int j = (i+ind)%len(this->elems);

                        if (this->elems->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->elems[%d] with length %d", j, this->elems->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/map.bah:70");
                        };
                        struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] = elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] = elem;
}
};
this->length = this->length+1;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] = elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] = elem;
}
};
break;
}
};
};
void mapWrapper__delete(struct mapWrapper* this,char * k){
long int ind = __Bah_map_hash(k,len(this->elems));
long int i = 0;
for (; (i<len(this->elems)); i = i+1) {
long int j = (i+ind)%len(this->elems);

                        if (this->elems->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->elems[%d] with length %d", j, this->elems->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/map.bah:86");
                        };
                        struct mapElem* e = this->elems->data[j];
if (((e!=null)&&(strcmp(e->key, k) == 0))) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] = null;
this->elems->length = nLength+1;
} else {
this->elems->data[j] = null;
}
};
}
};
};
void * mapWrapper__get(struct mapWrapper* this,char * k){
long int ind = __Bah_map_hash(k,len(this->elems));
long int i = 0;
for (; (i<len(this->elems)); i = i+1) {
long int j = (i+ind)%len(this->elems);

                        if (this->elems->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->elems[%d] with length %d", j, this->elems->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/map.bah:97");
                        };
                        struct mapElem* e = this->elems->data[j];
if (((e!=null)&&(strcmp(e->key, k) == 0))) {
return e->val;
}
};
return null;
};
struct mapWrapper* mapWrapper(){
struct mapWrapper* ____BAH_COMPILER_VAR_11 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_11->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_11->elems->length = 0;
            ____BAH_COMPILER_VAR_11->elems->elemSize = sizeof(struct mapElem*);
            ____BAH_COMPILER_VAR_11->grow = mapWrapper__grow;
____BAH_COMPILER_VAR_11->set = mapWrapper__set;
____BAH_COMPILER_VAR_11->setAny = mapWrapper__setAny;
____BAH_COMPILER_VAR_11->delete = mapWrapper__delete;
____BAH_COMPILER_VAR_11->get = mapWrapper__get;
struct mapWrapper* m = ____BAH_COMPILER_VAR_11;
m->grow(m,50);
return m;
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
char * stdinput(){
char * buff = memoryAlloc(1025);
char * response = "";
long int nDataLength = read((void *)0,buff,1024);
if ((nDataLength<1024)) {
char * ____BAH_COMPILER_VAR_12 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(response);
long int strLen_2 = strlen(buff);
;                            
                    ____BAH_COMPILER_VAR_12 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_12+currStrOff, response, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_12+currStrOff, buff, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                response = ____BAH_COMPILER_VAR_12;
}
else {
while ((nDataLength>0)) {
char * ____BAH_COMPILER_VAR_13 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(response);
long int strLen_2 = strlen(buff);
;                            
                    ____BAH_COMPILER_VAR_13 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_13+currStrOff, response, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_13+currStrOff, buff, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                response = ____BAH_COMPILER_VAR_13;
if ((nDataLength<1024)) {
long int trimAmm = 1024-nDataLength;
strTrimRight(&response,trimAmm);
break;
}
else {
nDataLength = read((void *)0,buff,1024);
}
};
}
strTrimRight(&response,1);
return response;
};
void println(char * s){
char * ____BAH_COMPILER_VAR_14 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_14 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_14+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_14+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                write((void *)1,____BAH_COMPILER_VAR_14,strlen(s)+1);
};
struct fileStream {
FILE* handle;
char * name;
long int(*isValid)(struct fileStream* this);
void(*open)(struct fileStream* this,char * path,char * mode);
void(*close)(struct fileStream* this);
long int(*getPos)(struct fileStream* this);
void(*setPos)(struct fileStream* this,long int i);
long int(*getSize)(struct fileStream* this);
void(*rewind)(struct fileStream* this);
char(*getChar)(struct fileStream* this);
void(*setChar)(struct fileStream* this,char c);
void(*createFile)(struct fileStream* this,char * path);
long int(*writeFile)(struct fileStream* this,char * content);
void(*writePtr)(struct fileStream* this,void * a,long int s);
long int(*readPtr)(struct fileStream* this,void * a,long int s);
char *(*readContent)(struct fileStream* this);
array(char)*(*readBytes)(struct fileStream* this);
void(*writeBytes)(struct fileStream* this,array(char)* d);
void(*_end)(struct fileStream* this);
};
long int fileStream__isValid(struct fileStream* this){
if ((this->handle==null)) {
return 0;
}
return 1;
};
void fileStream__open(struct fileStream* this,char * path,char * mode){
this->name = path;
this->handle = fopen(path,mode);
};
void fileStream__close(struct fileStream* this){
if ((this->isValid(this)==0)) {
return;
}
fclose(this->handle);
this->handle = null;
};
long int fileStream__getPos(struct fileStream* this){
if ((this->isValid(this)==0)) {
return 0;
}
return ftell(this->handle);
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((this->isValid(this)==0)) {
return;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((this->isValid(this)==0)) {
return -1;
}
long int oldPos = this->getPos(this);
fseek(this->handle,0,2);
long int size = ftell(this->handle);
this->setPos(this,oldPos);
return size;
};
void fileStream__rewind(struct fileStream* this){
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){
char c = getc(this->handle);
return c;
};
void fileStream__setChar(struct fileStream* this,char c){
fputc(c,this->handle);
};
void fileStream__createFile(struct fileStream* this,char * path){
this->open(this,path,"w");
this->close(this);
};
long int fileStream__writeFile(struct fileStream* this,char * content){
if ((this->isValid(this)==0)) {
return -1;
}
fputs(content,this->handle);
return 1;
};
void fileStream__writePtr(struct fileStream* this,void * a,long int s){
fwrite(a,s,1,this->handle);
};
long int fileStream__readPtr(struct fileStream* this,void * a,long int s){
return fread(a,s,1,this->handle);
};
char * fileStream__readContent(struct fileStream* this){
if ((this->isValid(this)==0)) {
return "invalid";
}
long int sz = this->getSize(this);
char * r = memoryAllocSTR(sz+1);
long int l = fread(r,1,sz,this->handle);
if ((sz!=l)) {
array(char)* rarr = strAsArr(r);

{
long nLength = l;
if (rarr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(rarr->data, (nLength+50)*sizeof(char));
rarr->data = newPtr;
}
rarr->data[l] = (char)0;
rarr->length = nLength+1;
} else {
rarr->data[l] = (char)0;
}
};
}
return r;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,this->getSize(this));
this->readPtr(this,r->data,len(r));
return r;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
this->writePtr(this,d->data,len(d));
};
void fileStream___end(struct fileStream* this){
if (this->isValid(this)) {
char * ____BAH_COMPILER_VAR_15 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("iostream: warning, auto-closing file: '");
long int strLen_2 = strlen(this->name);
long int strLen_4 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_15 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_15+currStrOff, "iostream: warning, auto-closing file: '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_15+currStrOff, this->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_15+currStrOff, "'.", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                println(____BAH_COMPILER_VAR_15);
this->close(this);
}
};
struct fileMap {
long int handle;
long int size;
void * p;
char *(*open)(struct fileMap* this,char * fileName);
long int(*isValid)(struct fileMap* this);
void(*close)(struct fileMap* this);
};
char * fileMap__open(struct fileMap* this,char * fileName){
struct fileStream ____BAH_COMPILER_VAR_16 = {};
____BAH_COMPILER_VAR_16.handle= null;
____BAH_COMPILER_VAR_16.name= null;
____BAH_COMPILER_VAR_16.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_16.open = fileStream__open;
____BAH_COMPILER_VAR_16.close = fileStream__close;
____BAH_COMPILER_VAR_16.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_16.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_16.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_16.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_16.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_16.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_16.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_16.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_16.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_16.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_16.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_16.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_16.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_16._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_16
fs.open(&fs,fileName,"r+");
long int iv = fs.isValid(&fs);
if ((iv==1)) {
this->handle = 0;
}
else {
this->handle = -1;
}
char * file = fs.readContent(&fs);
fs.close(&fs);
return file;
};
long int fileMap__isValid(struct fileMap* this){
if ((this->handle<0)) {
return 0;
}
return 1;
};
void fileMap__close(struct fileMap* this){
};
__BAH_ARR_TYPE_cpstring listFiles(char * dir){
array(char *)* files = memoryAlloc(sizeof(array(char *)));

files->length = 0;
files->elemSize = sizeof(char *);
DIR* d = opendir(dir);
struct dirent* file = readdir(d);
while ((file!=null)) {
long int lf = len(files);
if ((strcmp(file->d_name,".")==0)) {
file = readdir(d);
continue;
}
if ((strcmp(file->d_name,"..")==0)) {
file = readdir(d);
continue;
}

{
long nLength = lf;
if (files->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(files->data, (nLength+50)*sizeof(char *));
files->data = newPtr;
}
files->data[lf] = __STR(file->d_name);
files->length = nLength+1;
} else {
files->data[lf] = __STR(file->d_name);
}
};
file = readdir(d);
};
closedir(d);
return files;
};
long int fileExists(char * path){
long int is = access(path,0);
if ((is==0)) {
return 1;
}
return 0;
};
char removeFile(char * name){
if ((remove(name)==0)) {
return true;
}
return false;
};
long int getLastModified(char * name){
struct stat attr;
stat(name,&attr);
return attr.st_ctime;
};
long int __windows_mkdir(char * s,long int m){
return mkdir(s);
};
#define mkdir __windows_mkdir
#include <string.h>
#include <math.h>
#include <stdlib.h>
void strCatOffset(char * dest,long int destLen,char * src,long int srcLen){
memcpy(dest+destLen,src,srcLen);
};
char * charToString(char c){
char * s = memoryAlloc(2);
strncpy(s,(char *)&c,1);
return s;
};
char isUpper(char c){
return ((c>=65)&&(c<=90));
};
char isLower(char c){
return ((c>=97)&&(c<=122));
};
char isLetter(char s){
return (isLower(s)||isUpper(s));
};
char isNumber(char c){
return ((c>=48)&&(c<=57));
};
char isAlphaNumeric(char s){
return (isLetter(s)||isNumber(s));
};
char isSpace(char c){
return (((((c==(char)32)||(c==(char)9))||(c==(char)10))||(c==(char)11))||(c==(char)13));
};
struct string {
char * content;
char editable;
long int length;
void(*set)(struct string* this,char * s);
void(*makeEditable)(struct string* this);
void(*append)(struct string* this,char * s);
void(*prepend)(struct string* this,char * s);
char(*charAt)(struct string* this,long int i);
long int(*compare)(struct string* this,char * s);
char *(*str)(struct string* this);
void(*replace)(struct string* this,char * nd,char * rl);
long int(*countChar)(struct string* this,char need);
long int(*count)(struct string* this,char * need);
long int(*hasPrefix)(struct string* this,char * need);
long int(*hasSuffix)(struct string* this,char * need);
void(*trim)(struct string* this);
void(*trimLeft)(struct string* this,long int s);
void(*trimRight)(struct string* this,long int s);
struct string(*add)(struct string* this,struct string s2);
};
void string__set(struct string* this,char * s){
this->length = strlen(s);
this->editable = false;
this->content = s;
};
void string__makeEditable(struct string* this){
this->editable = true;
char * old = this->content;
this->content = (char *)memoryAlloc(this->length+1);
strncpy(this->content,old,this->length);
};
void string__append(struct string* this,char * s){
if ((this->editable==false)) {
this->makeEditable(this);
}
long int sl = strlen(s);
long int nl = sl+this->length;
void * nc = memoryRealloc(this->content,nl+1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:109");
}
this->content = nc;
strCatOffset(this->content,this->length,s,sl);
this->length = nl;
};
void string__prepend(struct string* this,char * s){
this->editable = true;
long int sl = strlen(s);
long int nl = this->length+sl;
char * tmpS = this->content;
void * nc = memoryAlloc(nl+1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:124");
}
this->content = nc;
strncpy(this->content,s,sl);
strCatOffset(this->content,sl,tmpS,this->length);
destroy(tmpS);
this->length = nl;
};
char string__charAt(struct string* this,long int i){
if (((void *)this->content==null)) {
return null;
}
if (((i<this->length)&&(i>=0))) {
return cpstringCharAt(this->content,i);
}
return null;
};
long int string__compare(struct string* this,char * s){
long int r = strcmp(this->content,s);
if ((r==0)) {
return 1;
}
return 0;
};
char * string__str(struct string* this){
return this->content;
};
void string__replace(struct string* this,char * nd,char * rl){
if ((this->editable==false)) {
this->makeEditable(this);
}
struct string ____BAH_COMPILER_VAR_17 = {};
____BAH_COMPILER_VAR_17.content= null;
____BAH_COMPILER_VAR_17.set = string__set;
____BAH_COMPILER_VAR_17.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_17.append = string__append;
____BAH_COMPILER_VAR_17.prepend = string__prepend;
____BAH_COMPILER_VAR_17.charAt = string__charAt;
____BAH_COMPILER_VAR_17.compare = string__compare;
____BAH_COMPILER_VAR_17.str = string__str;
____BAH_COMPILER_VAR_17.replace = string__replace;
#define needle ____BAH_COMPILER_VAR_17
needle.set(&needle,nd);
struct string ____BAH_COMPILER_VAR_18 = {};
____BAH_COMPILER_VAR_18.content= null;
____BAH_COMPILER_VAR_18.set = string__set;
____BAH_COMPILER_VAR_18.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_18.append = string__append;
____BAH_COMPILER_VAR_18.prepend = string__prepend;
____BAH_COMPILER_VAR_18.charAt = string__charAt;
____BAH_COMPILER_VAR_18.compare = string__compare;
____BAH_COMPILER_VAR_18.str = string__str;
____BAH_COMPILER_VAR_18.replace = string__replace;
#define repl ____BAH_COMPILER_VAR_18
repl.set(&repl,rl);
long int i = 0;
long int si = 0;
long int replcBuffSart = 0;
long int replcBuffLength = 0;
array(char)* buff = memoryAlloc(sizeof(array(char)));

buff->length = 0;
buff->elemSize = sizeof(char);
while ((i<this->length)) {
char c = this->charAt(this,i);
char rc = needle.charAt(&needle,si);
if ((c==rc)) {
si = si+1;
if ((replcBuffLength==0)) {
replcBuffSart = i;
}
replcBuffLength = replcBuffLength+1;
}
else {
if ((replcBuffLength>0)) {
si = 0;
long int j = 0;
while ((j<replcBuffLength)) {

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] = this->charAt(this,j+replcBuffSart);
buff->length = nLength+1;
} else {
buff->data[len(buff)] = this->charAt(this,j+replcBuffSart);
}
};
j = j+1;
};
replcBuffLength = 0;
}

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] = c;
buff->length = nLength+1;
} else {
buff->data[len(buff)] = c;
}
};
}
if ((si==needle.length)) {
replcBuffLength = 0;
long int ii = 0;
while ((ii<repl.length)) {
long int a = ii;

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] = repl.charAt(&repl,ii);
buff->length = nLength+1;
} else {
buff->data[len(buff)] = repl.charAt(&repl,ii);
}
};
ii = ii+1;
};
si = 0;
}
i = i+1;
};
char * r = arrToStr(buff);
if ((replcBuffLength>0)) {
array(char)* replbuffStr = memoryAlloc(sizeof(array(char)));

replbuffStr->length = 0;
replbuffStr->elemSize = sizeof(char);
allocateArray(replbuffStr,replcBuffLength+1);
long int j = 0;
while ((j<replcBuffLength)) {

{
long nLength = j;
if (replbuffStr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(replbuffStr->data, (nLength+50)*sizeof(char));
replbuffStr->data = newPtr;
}
replbuffStr->data[j] = this->charAt(this,j+replcBuffSart);
replbuffStr->length = nLength+1;
} else {
replbuffStr->data[j] = this->charAt(this,j+replcBuffSart);
}
};
j = j+1;
};
char * ____BAH_COMPILER_VAR_19 =null;char * ____BAH_COMPILER_VAR_20 =arrAsStr(replbuffStr);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(r);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_20);
;                            
                    ____BAH_COMPILER_VAR_19 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_19+currStrOff, r, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_19+currStrOff, ____BAH_COMPILER_VAR_20, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = ____BAH_COMPILER_VAR_19;
}
if (((void *)r!=null)) {
this->set(this,r);
}
};
long int string__countChar(struct string* this,char need){
long int c = 0;
long int i = 0;
for (; (i<this->length); i = i+1) {
if ((this->charAt(this,i)==need)) {
c = c+1;
}
};
return c;
};
long int string__count(struct string* this,char * need){
if ((strlen(need)==1)) {
return this->countChar(this,cpstringCharAt(need,0));
}
long int i = 0;
long int count = 0;
struct string ____BAH_COMPILER_VAR_21 = {};
____BAH_COMPILER_VAR_21.content= null;
____BAH_COMPILER_VAR_21.set = string__set;
____BAH_COMPILER_VAR_21.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_21.append = string__append;
____BAH_COMPILER_VAR_21.prepend = string__prepend;
____BAH_COMPILER_VAR_21.charAt = string__charAt;
____BAH_COMPILER_VAR_21.compare = string__compare;
____BAH_COMPILER_VAR_21.str = string__str;
____BAH_COMPILER_VAR_21.replace = string__replace;
____BAH_COMPILER_VAR_21.countChar = string__countChar;
____BAH_COMPILER_VAR_21.count = string__count;
#define needle ____BAH_COMPILER_VAR_21
needle.set(&needle,need);
long int countIndex = 0;
while ((i<this->length)) {
char c = this->charAt(this,i);
char sc = needle.charAt(&needle,countIndex);
if ((c==sc)) {
countIndex = countIndex+1;
}
else {
countIndex = 0;
}
if ((countIndex==needle.length)) {
count = count+1;
countIndex = 0;
}
i = i+1;
};
return count;
};
long int string__hasPrefix(struct string* this,char * need){
long int i = 0;
long int nl = strlen(need);
if ((this->length<nl)) {
return 0;
}
while ((i<nl)) {
char c = this->charAt(this,i);
char sc = cpstringCharAt(need,i);
if ((c!=sc)) {
return 0;
}
i = i+1;
};
return 1;
};
long int string__hasSuffix(struct string* this,char * need){
long int nl = strlen(need);
if ((this->length<nl)) {
return 0;
}
long int i = this->length-nl;
long int needleIndex = 0;
while ((i<this->length)) {
char c = this->charAt(this,i);
char sc = cpstringCharAt(need,needleIndex);
if ((c!=sc)) {
return 0;
}
needleIndex = needleIndex+1;
i = i+1;
};
return 1;
};
void string__trim(struct string* this){
if ((this->length==0)) {
return;
}
char fc = this->charAt(this,0);
if ((isSpace(fc)==false)) {
return;
}
long int i = 0;
for (; (i<this->length); i = i+1) {
if ((isSpace(this->charAt(this,i))==false)) {
break;
}
};
if ((i>0)) {
this->length = this->length-i;
char * tmpS = memoryAlloc(this->length+1);
memcpy(tmpS,this->content+i,this->length+1);
this->content = tmpS;
this->editable = true;
}
};
void string__trimLeft(struct string* this,long int s){
long int nSize = this->length-s;
void * tmpS = memoryAlloc(nSize+1);
memcpy(tmpS,this->content+s,nSize);
this->content = tmpS;
this->editable = true;
this->length = nSize;
};
void string__trimRight(struct string* this,long int s){
long int nSize = this->length-s;
void * tmpS = memoryAlloc(nSize+1);
memcpy(tmpS,this->content,nSize);
this->content = tmpS;
this->editable = true;
this->length = nSize;
};
struct string string__add(struct string* this,struct string s2){
struct string ____BAH_COMPILER_VAR_22 = {};
____BAH_COMPILER_VAR_22.content= null;
____BAH_COMPILER_VAR_22.set = string__set;
____BAH_COMPILER_VAR_22.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_22.append = string__append;
____BAH_COMPILER_VAR_22.prepend = string__prepend;
____BAH_COMPILER_VAR_22.charAt = string__charAt;
____BAH_COMPILER_VAR_22.compare = string__compare;
____BAH_COMPILER_VAR_22.str = string__str;
____BAH_COMPILER_VAR_22.replace = string__replace;
____BAH_COMPILER_VAR_22.countChar = string__countChar;
____BAH_COMPILER_VAR_22.count = string__count;
____BAH_COMPILER_VAR_22.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_22.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_22.trim = string__trim;
____BAH_COMPILER_VAR_22.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_22.trimRight = string__trimRight;
____BAH_COMPILER_VAR_22.add = string__add;
#define r ____BAH_COMPILER_VAR_22
r.length = this->length+s2.length;
r.content = memoryAlloc(r.length+1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
return r;
};
struct string string(char * s){
struct string ____BAH_COMPILER_VAR_23 = {};
____BAH_COMPILER_VAR_23.content= null;
____BAH_COMPILER_VAR_23.set = string__set;
____BAH_COMPILER_VAR_23.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_23.append = string__append;
____BAH_COMPILER_VAR_23.prepend = string__prepend;
____BAH_COMPILER_VAR_23.charAt = string__charAt;
____BAH_COMPILER_VAR_23.compare = string__compare;
____BAH_COMPILER_VAR_23.str = string__str;
____BAH_COMPILER_VAR_23.replace = string__replace;
____BAH_COMPILER_VAR_23.countChar = string__countChar;
____BAH_COMPILER_VAR_23.count = string__count;
____BAH_COMPILER_VAR_23.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_23.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_23.trim = string__trim;
____BAH_COMPILER_VAR_23.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_23.trimRight = string__trimRight;
____BAH_COMPILER_VAR_23.add = string__add;
#define a ____BAH_COMPILER_VAR_23
a.set(&a,s);
return a;
};
char * intToStr(long int i){
if ((i==0)) {
return "0";
}
char ____BAH_COMPILER_VAR_24[66];char* s = ____BAH_COMPILER_VAR_24;
long int ind = -1;
char subZero = (i<0);
if ((subZero==true)) {
i = 0-i;
}
for (; (i!=0); i = i/10) {
long int conv = i%10;
conv = conv+48;

                        if (ind+1 >= 66) {
                            printf("buffer (/opt/bah/string.bah:382): s[%d] with length %d\n", ind+1, 66);
                            exit(1);
                        };
                        s[ind+1] = (char)conv;
ind = ind+1;
};
if ((subZero==true)) {

                        if (ind+1 >= 66) {
                            printf("buffer (/opt/bah/string.bah:387): s[%d] with length %d\n", ind+1, 66);
                            exit(1);
                        };
                        s[ind+1] = 45;
ind = ind+1;
}
long int ls = ind+1;
i = 0;
for (; (i<ls/2); i = i+1) {
long int ii = ls-i-1;

                        if (i >= 66) {
                            printf("buffer (/opt/bah/string.bah:393): s[%d] with length %d\n", i, 66);
                            exit(1);
                        };
                        char osi = s[i];

                        if (i >= 66) {
                            printf("buffer (/opt/bah/string.bah:394): s[%d] with length %d\n", i, 66);
                            exit(1);
                        };
                        
                        if (ii >= 66) {
                            printf("buffer (/opt/bah/string.bah:394): s[%d] with length %d\n", ii, 66);
                            exit(1);
                        };
                        s[i] = s[ii];

                        if (ii >= 66) {
                            printf("buffer (/opt/bah/string.bah:395): s[%d] with length %d\n", ii, 66);
                            exit(1);
                        };
                        s[ii] = osi;
};

                        if (ind+1 >= 66) {
                            printf("buffer (/opt/bah/string.bah:398): s[%d] with length %d\n", ind+1, 66);
                            exit(1);
                        };
                        s[ind+1] = (char)0;
return __STR(s);
};
struct string intToString(long int i){
char * ____BAH_COMPILER_VAR_25 =intToStr(i);struct string r = string(____BAH_COMPILER_VAR_25);
return r;
};
char * floatToStr(double f){
char ____BAH_COMPILER_VAR_26[50];char* buff = ____BAH_COMPILER_VAR_26;
sprintf(buff,"%lf",f);
return __STR(buff);
};
long int strToInt(char * s){
return atol(s);
};
double strToFloat(char * s){
return strtod(s,null);
};
long int stringToInt(struct string s){
long int i = atol(s.content);
return i;
};
typedef array(struct string)* __BAH_ARR_TYPE_string;
__BAH_ARR_TYPE_string splitString(struct string s,char * sp){
struct string sep = string(sp);
array(struct string)* res = memoryAlloc(sizeof(array(struct string)));

res->length = 0;
res->elemSize = sizeof(struct string);
struct string sepBuffer = string("");
long int sepIndex = 0;
long int i = 0;
struct string replcBuff = string("");
array(char)* tmpString = memoryAlloc(sizeof(array(char)));

tmpString->length = 0;
tmpString->elemSize = sizeof(char);
while ((i<s.length)) {
char c = s.charAt(&s,i);
char sepc = sep.charAt(&sep,sepIndex);
if ((c==sepc)) {
sepIndex = sepIndex+1;
char * ____BAH_COMPILER_VAR_27 =charToString(c);replcBuff.append(&replcBuff,____BAH_COMPILER_VAR_27);
}
else {
if ((sepIndex>0)) {
sepIndex = 0;
char * ____BAH_COMPILER_VAR_28 =charToString(c);replcBuff.append(&replcBuff,____BAH_COMPILER_VAR_28);
long int ii = 0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] = replcBuff.charAt(&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] = replcBuff.charAt(&replcBuff,ii);
}
};
ii = ii+1;
};
replcBuff.set(&replcBuff,"");
}
else {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] = c;
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] = c;
}
};
}
}
if ((sepIndex==sep.length)) {
replcBuff.set(&replcBuff,"");
struct string* ____BAH_COMPILER_VAR_29 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_29->content= null;
____BAH_COMPILER_VAR_29->set = string__set;
____BAH_COMPILER_VAR_29->makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_29->append = string__append;
____BAH_COMPILER_VAR_29->prepend = string__prepend;
____BAH_COMPILER_VAR_29->charAt = string__charAt;
____BAH_COMPILER_VAR_29->compare = string__compare;
____BAH_COMPILER_VAR_29->str = string__str;
____BAH_COMPILER_VAR_29->replace = string__replace;
____BAH_COMPILER_VAR_29->countChar = string__countChar;
____BAH_COMPILER_VAR_29->count = string__count;
____BAH_COMPILER_VAR_29->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_29->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_29->trim = string__trim;
____BAH_COMPILER_VAR_29->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_29->trimRight = string__trimRight;
____BAH_COMPILER_VAR_29->add = string__add;
struct string* elem = ____BAH_COMPILER_VAR_29;
char * ____BAH_COMPILER_VAR_30 =arrToStr(tmpString);elem->set(elem,____BAH_COMPILER_VAR_30);
long int lenRes = len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] = *elem;
res->length = nLength+1;
} else {
res->data[lenRes] = *elem;
}
};
clear(tmpString);
sepIndex = 0;
}
i = i+1;
};
if ((replcBuff.length>0)) {
long int ii = 0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] = replcBuff.charAt(&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] = replcBuff.charAt(&replcBuff,ii);
}
};
ii = ii+1;
};
}
if ((len(tmpString)>0)) {
struct string* ____BAH_COMPILER_VAR_31 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_31->content= null;
____BAH_COMPILER_VAR_31->set = string__set;
____BAH_COMPILER_VAR_31->makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_31->append = string__append;
____BAH_COMPILER_VAR_31->prepend = string__prepend;
____BAH_COMPILER_VAR_31->charAt = string__charAt;
____BAH_COMPILER_VAR_31->compare = string__compare;
____BAH_COMPILER_VAR_31->str = string__str;
____BAH_COMPILER_VAR_31->replace = string__replace;
____BAH_COMPILER_VAR_31->countChar = string__countChar;
____BAH_COMPILER_VAR_31->count = string__count;
____BAH_COMPILER_VAR_31->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_31->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_31->trim = string__trim;
____BAH_COMPILER_VAR_31->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_31->trimRight = string__trimRight;
____BAH_COMPILER_VAR_31->add = string__add;
struct string* elem = ____BAH_COMPILER_VAR_31;
char * ____BAH_COMPILER_VAR_32 =arrToStr(tmpString);elem->set(elem,____BAH_COMPILER_VAR_32);
long int lenRes = len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] = *elem;
res->length = nLength+1;
} else {
res->data[lenRes] = *elem;
}
};
}
return res;
};
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){
long int i = 0;
struct string s = string("");
long int max = len(a)-1;
while ((i<len(a))) {

                        if (a->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: a[%d] with length %d", i, a->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/string.bah:506");
                        };
                        struct string e = a->data[i];
if ((e.length==0)) {
i = i+1;
continue;
}
char * ____BAH_COMPILER_VAR_33 =e.str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_33);
if ((i!=max)) {
tmpS.append(&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_34 =tmpS.str(&tmpS);s.append(&s,____BAH_COMPILER_VAR_34);
i = i+1;
};
return s;
};
char * splitStringBefore(struct string s,char * sp){
struct string sep = string(sp);
if ((sep.length>=s.length)) {
return "";
}
long int sepIndex = 0;
long int foundIndex = 0;
long int i = 0;
while ((i<s.length)) {
char c = s.charAt(&s,i);
char sc = sep.charAt(&sep,sepIndex);
if ((c==sc)) {
if ((sepIndex==0)) {
foundIndex = i-1;
}
sepIndex = sepIndex+1;
if ((sepIndex==sep.length)) {
long int max = s.length-foundIndex-1;
s.trimRight(&s,max);
return s.str(&s);
}
}
else {
foundIndex = 0;
sepIndex = 0;
}
i = i+1;
};
return "";
};
struct string toLower(struct string s){
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
long int i = 0;
while ((i<s.length)) {
char c = s.charAt(&s,i);
if (isUpper(c)) {
c = c+(char)32;
}

{
long nLength = len(ns);
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] = c;
ns->length = nLength+1;
} else {
ns->data[len(ns)] = c;
}
};
i = i+1;
};
char * ____BAH_COMPILER_VAR_35 =arrToStr(ns);return string(____BAH_COMPILER_VAR_35);
};
char strHasPrefix(char * s,char * need){
long int i = 0;
long int nl = strlen(need);
long int sl = strlen(s);
if ((sl<nl)) {
return false;
}
while ((i<nl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
return false;
}
i = i+1;
};
return true;
};
char strHasSuffix(char * s,char * need){
long int sl = strlen(s);
long int nl = strlen(need);
if ((nl>sl)) {
return false;
}
long int i = sl-nl;
while ((i<sl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
return false;
}
i = i+1;
};
return true;
};
void strTrim(char ** s){
long int l = strlen(*s);
long int i = 0;
while ((i<l)) {
char c = cpstringCharAt(*s,i);
if ((isSpace(c)==false)) {
break;
}
i = i+1;
};
*s = *s+i;
};
long int strCount(char * src,char * needle){
long int i = 0;
long int count = 0;
long int countIndex = 0;
long int sl = strlen(src);
long int nl = strlen(needle);
while ((i<sl)) {
char c = cpstringCharAt(src,i);
char sc = cpstringCharAt(needle,countIndex);
if ((c==sc)) {
countIndex = countIndex+1;
}
else {
countIndex = 0;
}
if ((countIndex==nl)) {
count = count+1;
countIndex = 0;
}
i = i+1;
};
return count;
};
#define FLAG_TYPE_CPSTRING 0
#define FLAG_TYPE_INT 1
#define FLAG_TYPE_FLOAT 2
#define FLAG_TYPE_BOOL 3
struct flag {
char * name;
char * help;
char * content;
long int cont_int;
double cont_float;
long int isSet;
long int type;
};
struct flags {
array(struct flag*)* flags;
array(char *)* args;
void(*addString)(struct flags* this,char * name,char * help);
void(*addBool)(struct flags* this,char * name,char * help);
void(*addInt)(struct flags* this,char * name,char * help);
void(*addFloat)(struct flags* this,char * name,char * help);
void(*invalidate)(struct flags* this);
struct flag*(*getFlag)(struct flags* this,struct string name);
char *(*get)(struct flags* this,char * name);
long int(*getInt)(struct flags* this,char * name);
double(*getFloat)(struct flags* this,char * name);
long int(*isSet)(struct flags* this,char * name);
void(*parse)(struct flags* this,array(char *)* args);
};
void flags__addString(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_36 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_36->name= null;
____BAH_COMPILER_VAR_36->help= null;
____BAH_COMPILER_VAR_36->content= null;
struct flag* f = ____BAH_COMPILER_VAR_36;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_CPSTRING;
long int lf = len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] = f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] = f;
}
};
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_37 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_37->name= null;
____BAH_COMPILER_VAR_37->help= null;
____BAH_COMPILER_VAR_37->content= null;
struct flag* f = ____BAH_COMPILER_VAR_37;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_BOOL;
long int lf = len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] = f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] = f;
}
};
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_38 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_38->name= null;
____BAH_COMPILER_VAR_38->help= null;
____BAH_COMPILER_VAR_38->content= null;
struct flag* f = ____BAH_COMPILER_VAR_38;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_INT;
long int lf = len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] = f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] = f;
}
};
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_39 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_39->name= null;
____BAH_COMPILER_VAR_39->help= null;
____BAH_COMPILER_VAR_39->content= null;
struct flag* f = ____BAH_COMPILER_VAR_39;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_FLOAT;
long int lf = len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] = f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] = f;
}
};
};
void flags__invalidate(struct flags* this){
print("Usage of ");
print(this->args->data[0]);
println(":");
long int i = 0;
while ((i<len(this->flags))) {

                        if (this->flags->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->flags[%d] with length %d", i, this->flags->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/flags.bah:75");
                        };
                        struct flag* flag = this->flags->data[i];
print("    -");
print(flag->name);
if ((flag->type==FLAG_TYPE_CPSTRING)) {
println(" (string)");
}
else if ((flag->type==FLAG_TYPE_BOOL)) {
println(" (bool)");
}
else if ((flag->type==FLAG_TYPE_INT)) {
println(" (int)");
}
else if ((flag->type==FLAG_TYPE_FLOAT)) {
println(" (float)");
}
print("\t");
println(flag->help);
i = i+1;
};
exit(1);
};
struct flag* flags__getFlag(struct flags* this,struct string name){
long int i = 0;
while ((i<len(this->flags))) {

                        if (this->flags->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->flags[%d] with length %d", i, this->flags->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/flags.bah:98");
                        };
                        struct flag* flag = this->flags->data[i];
if (name.compare(&name,flag->name)) {
return flag;
}
i = i+1;
};
struct flag* ____BAH_COMPILER_VAR_40 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_40->name= null;
____BAH_COMPILER_VAR_40->help= null;
____BAH_COMPILER_VAR_40->content= null;
struct flag* z = ____BAH_COMPILER_VAR_40;
z->isSet = 0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_41 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_41);
char * ctn = flag->content;
return ctn;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_42 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_42);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_43 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Flag '");
long int strLen_4 = strlen(flag->name);
long int strLen_6 = strlen("' is not int.");
;                            
                    ____BAH_COMPILER_VAR_43 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_43+currStrOff, "Flag '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_43+currStrOff, flag->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_43+currStrOff, "' is not int.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * error = ____BAH_COMPILER_VAR_43;
__BAH_panic(error,"/opt/bah/flags.bah:124");
}
long int ctn = flag->cont_int;
return ctn;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_44 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_44);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_45 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Flag '");
long int strLen_4 = strlen(flag->name);
long int strLen_6 = strlen("' is not float.");
;                            
                    ____BAH_COMPILER_VAR_45 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_45+currStrOff, "Flag '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_45+currStrOff, flag->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_45+currStrOff, "' is not float.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * error = ____BAH_COMPILER_VAR_45;
__BAH_panic(error,"/opt/bah/flags.bah:136");
}
double ctn = flag->cont_float;
return ctn;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_46 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_46);
long int ctn = flag->isSet;
return ctn;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){
struct flag* currentFlag= null;
char isVal = false;
this->args = args;
long int i = 1;
while ((i<len(args))) {
struct string argName = string(args->data[i]);
if ((isVal==true)) {
currentFlag->content = argName.str(&argName);
if ((currentFlag->type==FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_47 =argName.str(&argName);currentFlag->cont_int = atoi(____BAH_COMPILER_VAR_47);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_48 =argName.str(&argName);currentFlag->cont_float = strtod(____BAH_COMPILER_VAR_48,0);
}
isVal = false;
}
else {
if ((argName.charAt(&argName,0)!=45)) {
i = i+1;
continue;
}
argName.trimLeft(&argName,1);
if (argName.compare(&argName,"help")) {
this->invalidate(this);
}
else if (argName.compare(&argName,"h")) {
this->invalidate(this);
}
currentFlag = this->getFlag(this,argName);
if ((currentFlag==null)) {
this->invalidate(this);
}
currentFlag->isSet = 1;
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
isVal = true;
}
}
i = i+1;
};
if ((isVal==true)) {
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
this->invalidate(this);
}
}
};
#include <stdlib.h>
#include <wincrypt.h>
#include <time.h>
#define TIME_MS 1000000
#define TIME_S 1000000000
#define TIME_MIN 60000000000
struct time {
long int timestamp;
void(*now)(struct time* this);
char *(*format)(struct time* this,char * a);
long int(*since)(struct time* this);
};
void time__now(struct time* this){
this->timestamp = time(0);
};
char * time__format(struct time* this,char * a){
long int lt = localtime(&this->timestamp);
char * date = memoryAlloc(1024);
strftime(date,1024,a,lt);
return date;
};
long int time__since(struct time* this){
long int nt = time(0);
long int r = nt-this->timestamp;
return r;
};
long int getTimeUnix(){
struct timespec ____BAH_COMPILER_VAR_49 = {};
#define ts ____BAH_COMPILER_VAR_49
long int s = clock_gettime(CLOCK_REALTIME,&ts);
s = ts.tv_sec*1000000000+ts.tv_nsec;
return s;
};
long int RAND_SEEDED;
void seedRandom(long int i){
srand(i);
RAND_SEEDED = 1;
};
long int randomInRange(long int min,long int max){
if ((RAND_SEEDED==0)) {
srand(time(0)+getTimeUnix());
RAND_SEEDED = 1;
}
long int range = max-min;
long int i = rand()%range+1;
i = i+min;
return i;
};
long int cryptoRand(){
HCRYPTPROV hp;
long int* buff = memoryAlloc(SIZE_OF_INT);
CryptGenRandom(hp,1,buff);
long int i = *buff;
return i;
};
#define ROPE_LEAF_LEN 200
struct rope {
struct rope* left;
struct rope* right;
char * str;
long int lCount;
long int len;
long int totalLen;
void(*addStr)(struct rope* this,char * s,long int* offset);
char *(*toStr)(struct rope* this);
struct rope*(*add)(struct rope* this,struct rope* root2);
};
void rope__addStr(struct rope* this,char * s,long int* offset){
if (((this->left==null)&&(this->right==null))) {
long int off = *offset;
memcpy(s+off,this->str,this->lCount+1);
*offset = *offset+this->lCount+1;
return;
}
long int l = *offset;
this->left->addStr(this->left,s,offset);
this->right->addStr(this->right,s,offset);
};
char * rope__toStr(struct rope* this){
if (((this->left==null)&&(this->right==null))) {
return this->str;
}
char * s = memoryAlloc(this->totalLen+1);
long int offset = 0;
this->left->addStr(this->left,s,&offset);
this->right->addStr(this->right,s,&offset);
return s;
};
struct rope* rope__add(struct rope* this,struct rope* root2){
long int n1 = this->len;
struct rope* ____BAH_COMPILER_VAR_50 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_50->left= null;
____BAH_COMPILER_VAR_50->right= null;
____BAH_COMPILER_VAR_50->str= null;
____BAH_COMPILER_VAR_50->len = 0;
____BAH_COMPILER_VAR_50->addStr = rope__addStr;
____BAH_COMPILER_VAR_50->toStr = rope__toStr;
____BAH_COMPILER_VAR_50->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_50;
tmp->left = this;
tmp->right = root2;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_51 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_51->left= null;
____BAH_COMPILER_VAR_51->right= null;
____BAH_COMPILER_VAR_51->str= null;
____BAH_COMPILER_VAR_51->len = 0;
____BAH_COMPILER_VAR_51->addStr = rope__addStr;
____BAH_COMPILER_VAR_51->toStr = rope__toStr;
____BAH_COMPILER_VAR_51->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_51;
tmp->left = null;
tmp->right = null;
if ((r-l>ROPE_LEAF_LEN)) {
tmp->str = null;
tmp->lCount = r-l;
tmp->lCount = tmp->lCount/2;
struct rope* node = tmp;
long int m = l+r;
m = m/2;
node->left = createRopeStructure(node,a,l,m);
node->right = createRopeStructure(node,a,m+1,r);
}
else {
struct rope* node = tmp;
tmp->lCount = r-l;
long int j = 0;
long int i = l;
char * arr = memoryAlloc(r+1);
while ((i<=r)) {
arr[j]=a[i];
j = j+1;
i = i+1;
};
tmp->str = arr;
}
return tmp;
};
void ropeSet(struct rope* r,char * a){
long int n1 = strlen(a);
struct rope* nr = createRopeStructure(null,a,0,n1-1);
nr->totalLen = n1;
nr->len = n1;
*r = *nr;
};
struct rope* concatenateRopes(struct rope* root1,struct rope* root2){
long int n1 = root1->len;
struct rope* ____BAH_COMPILER_VAR_52 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_52->left= null;
____BAH_COMPILER_VAR_52->right= null;
____BAH_COMPILER_VAR_52->str= null;
____BAH_COMPILER_VAR_52->len = 0;
____BAH_COMPILER_VAR_52->addStr = rope__addStr;
____BAH_COMPILER_VAR_52->toStr = rope__toStr;
____BAH_COMPILER_VAR_52->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_52;
tmp->left = root1;
tmp->right = root2;
tmp->totalLen = root1->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* rope(char * a){
long int n1 = strlen(a);
struct rope* r = createRopeStructure(null,a,0,n1-1);
r->totalLen = n1;
r->len = n1;
return r;
};
struct command {
char * command;
char error;
long int status;
char * input;
FILE* handle;
char *(*run)(struct command* this);
array(char)*(*runBytes)(struct command* this);
};
char * command__run(struct command* this){
char * cm = this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_53 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(cm);
long int strLen_4 = strlen(" 2>/dev/null");
;                            
                    ____BAH_COMPILER_VAR_53 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_53+currStrOff, cm, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_53+currStrOff, " 2>/dev/null", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                cm = ____BAH_COMPILER_VAR_53;
}
else {
char * ____BAH_COMPILER_VAR_54 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(cm);
long int strLen_4 = strlen(" 2>&1");
;                            
                    ____BAH_COMPILER_VAR_54 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_54+currStrOff, cm, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_54+currStrOff, " 2>&1", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                cm = ____BAH_COMPILER_VAR_54;
}
this->handle = popen(cm,"w");
if ((this->handle==null)) {
return "";
}
if ((strcmp(this->input, null) != 0)) {
fputs(this->input,(void *)this->handle);
}
char * buff = memoryAlloc(1025);
char * res = "";
while (((void *)fgets(buff,1024,this->handle)!=null)) {
char * ____BAH_COMPILER_VAR_55 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(res);
long int strLen_4 = strlen(buff);
;                            
                    ____BAH_COMPILER_VAR_55 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_55+currStrOff, res, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_55+currStrOff, buff, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                res = ____BAH_COMPILER_VAR_55;
};
this->status = pclose(this->handle);
return res;
};
__BAH_ARR_TYPE_char command__runBytes(struct command* this){
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
char * cm = this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_56 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(cm);
long int strLen_4 = strlen(" 2>/dev/null");
;                            
                    ____BAH_COMPILER_VAR_56 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_56+currStrOff, cm, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_56+currStrOff, " 2>/dev/null", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                cm = ____BAH_COMPILER_VAR_56;
}
else {
char * ____BAH_COMPILER_VAR_57 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(cm);
long int strLen_4 = strlen(" 2>&1");
;                            
                    ____BAH_COMPILER_VAR_57 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_57+currStrOff, cm, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_57+currStrOff, " 2>&1", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                cm = ____BAH_COMPILER_VAR_57;
}
this->handle = popen(cm,"r");
if ((this->handle==null)) {
return arr;
}
long int total = 0;
long int fd = fileno(this->handle);
char * buff = memoryAlloc(1024);
char * response = "";
void * res = fgets(buff,1023,this->handle);
while ((res!=null)) {
char * ____BAH_COMPILER_VAR_58 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(response);
long int strLen_2 = strlen(buff);
;                            
                    ____BAH_COMPILER_VAR_58 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_58+currStrOff, response, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_58+currStrOff, buff, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                response = ____BAH_COMPILER_VAR_58;
res = fgets(buff,1023,this->handle);
};
this->status = pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_59 = {};
____BAH_COMPILER_VAR_59.command= null;
____BAH_COMPILER_VAR_59.error = true;
____BAH_COMPILER_VAR_59.status = 0;
____BAH_COMPILER_VAR_59.input = null;
____BAH_COMPILER_VAR_59.handle= null;
____BAH_COMPILER_VAR_59.run = command__run;
____BAH_COMPILER_VAR_59.runBytes = command__runBytes;
#define cmd ____BAH_COMPILER_VAR_59
cmd.command = s;
return cmd;
};
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){
long int r;
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));

nArgs->length = 0;
nArgs->elemSize = sizeof(char *);

{
long nLength = 0;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[0] = s;
nArgs->length = nLength+1;
} else {
nArgs->data[0] = s;
}
};
long int i = 0;
while ((i<len(args))) {

                        if (args->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: args[%d] with length %d", i, args->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/exec.bah:96");
                        };
                        
{
long nLength = i+1;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i+1] = args->data[i];
nArgs->length = nLength+1;
} else {
nArgs->data[i+1] = args->data[i];
}
};
i = i+1;
};

{
long nLength = i+2;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i+2] = (char *)0;
nArgs->length = nLength+1;
} else {
nArgs->data[i+2] = (char *)0;
}
};
r=execvp(s,nArgs->data);
return r;
};
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.1 (build 83)"
char debug;
char verboseRuntime;
char isObject;
char isUnsafe;
char * execName;
char isSubObject;
struct rope* OUTPUT;
char * NEXT_LINE;
struct rope* INIT;
struct variable {
char * name;
char * type;
char isConst;
char * constVal;
char isArray;
char * from;
char outterScope;
char isGlobal;
};
struct structMemb {
char * name;
char * type;
char isConst;
char * constVal;
char isArray;
char * from;
char outterScope;
char isGlobal;
char * def;
char isFn;
};
struct func {
char * name;
array(struct variable*)* args;
struct variable* returns;
char returned;
char isBinding;
char * from;
char * file;
long int line;
char used;
struct rope* code;
};
struct cStruct {
char * name;
array(struct structMemb*)* members;
array(struct func*)* methods;
char * postCode;
char print;
char * extendedFrom;
char isBinding;
char hasRCPmemb;
};
struct Elems {
array(struct variable*)* vars;
array(struct cStruct*)* structs;
array(char *)* types;
array(struct func*)* fns;
};
struct compilerStateTag {
array(char *)* includes;
array(char *)* cIncludes;
array(char *)* cLibs;
char * currentFile;
char * currentDir;
char isBranch;
char isFor;
array(char *)* arrTypesDecl;
char haveEntryPoint;
array(struct variable*)* RCPvars;
array(char *)* evals;
char hasImports;
struct Elems* currForElems;
struct Elems* currFnElems;
};
char shouldOnlyDecl;
struct compilerStateTag compilerState;
struct cStruct* currentCStruct;
long int threadCount;
struct func* currentFn;
long int totalLines;
long int totalLexerTime;
char RCPenabled;
long int RCPlevel;
struct flags flags;
struct variable* currSetVar;
typedef long int tokenType;
#define TOKEN_NO_TYPE (tokenType)-1
#define TOKEN_TYPE_INT (tokenType)0
#define TOKEN_TYPE_FLOAT (tokenType)1
#define TOKEN_TYPE_VAR (tokenType)2
#define TOKEN_TYPE_ENCL (tokenType)3
#define TOKEN_TYPE_SEP (tokenType)4
#define TOKEN_TYPE_STR (tokenType)5
#define TOKEN_TYPE_KEYWORD (tokenType)6
#define TOKEN_TYPE_CHAR (tokenType)7
#define TOKEN_TYPE_BOOL (tokenType)8
#define TOKEN_TYPE_SYNTAX (tokenType)10
#define TOKEN_TYPE_FUNC (tokenType)11
struct Tok {
char * cont;
char * ogCont;
tokenType type;
long int pos;
long int line;
long int begLine;
char * bahType;
char isValue;
char isFunc;
char isOper;
char isEqual;
};
char inArray(char needle,__BAH_ARR_TYPE_char arr){
long int i = 0;
while ((i<len(arr))) {

                        if (arr->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: arr[%d] with length %d", i, arr->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/lexer.bah:39");
                        };
                        if ((needle==arr->data[i])) {
return true;
}
i = i+1;
};
return false;
};
char inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){
long int i = 0;
while ((i<len(arr))) {

                        if (arr->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: arr[%d] with length %d", i, arr->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/lexer.bah:49");
                        };
                        if ((strcmp(needle, arr->data[i]) == 0)) {
return true;
}
i = i+1;
};
return false;
};
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){
struct Tok ____BAH_COMPILER_VAR_60 = {};
____BAH_COMPILER_VAR_60.cont = "";
____BAH_COMPILER_VAR_60.ogCont = "";
____BAH_COMPILER_VAR_60.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_60.pos = 0;
____BAH_COMPILER_VAR_60.line = 1;
____BAH_COMPILER_VAR_60.begLine = 1;
____BAH_COMPILER_VAR_60.bahType = "";
____BAH_COMPILER_VAR_60.isValue = false;
____BAH_COMPILER_VAR_60.isFunc = false;
____BAH_COMPILER_VAR_60.isOper = false;
____BAH_COMPILER_VAR_60.isEqual = false;
#define t ____BAH_COMPILER_VAR_60
t.cont = arrToStr(cont);
t.ogCont = t.cont;
clear(cont);
t.pos = pos;
t.line = lineNb;
t.type = type;
if (((((((type==TOKEN_TYPE_INT)||(type==TOKEN_TYPE_STR))||(type==TOKEN_TYPE_FLOAT))||(type==TOKEN_TYPE_VAR))||(type==TOKEN_TYPE_BOOL))||(type==TOKEN_TYPE_CHAR))) {
t.isValue = true;
}
return t;
};
char isMinus(char c,char nc){
return ((c==45)&&isNumber(nc));
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr = intToStr(line);
char * posStr = intToStr(pos);
char * ____BAH_COMPILER_VAR_61 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[LEXER-ERROR]\e[0m ");
long int strLen_2 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_6 = strlen(lineStr);
long int strLen_8 = strlen(":");
long int strLen_10 = strlen(posStr);
long int strLen_12 = strlen("\n\e[0m\n");
long int strLen_14 = strlen(msg);
;                            
                    ____BAH_COMPILER_VAR_61 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_61+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_61+currStrOff, compilerState.currentFile, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_61+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_61+currStrOff, lineStr, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_61+currStrOff, ":", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_61+currStrOff, posStr, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_61+currStrOff, "\n\e[0m\n", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_61+currStrOff, msg, strLen_14);
                        currStrOff += strLen_14;
                        
                }
                println(____BAH_COMPILER_VAR_61);
exit(1);
};
array(char)* enclavers;
array(char)* syntaxes;
array(char *)* keywords;
typedef array(struct Tok)* __BAH_ARR_TYPE_Tok;
__BAH_ARR_TYPE_Tok lexer(char * s){
long int dur = getTimeUnix();
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int codeLength = strlen(s);
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);
long int lineNb = 1;
long int i = 0;
for (; (i<codeLength); i = i+1) {
char c = cpstringCharAt(s,i);
char nc = (char)0;
if ((i+1<codeLength)) {
nc = cpstringCharAt(s,i+1);
}
if ((c==47)) {
nc = cpstringCharAt(s,i+1);
if ((nc==47)) {
for (; (i<codeLength); i = i+1) {
c = cpstringCharAt(s,i);
if ((c==(char)10)) {
break;
}
};
if ((i==codeLength)) {
break;
}
}
}
if ((c==(char)10)) {
lineNb = lineNb+1;
}
if ((c==(char)34)) {
long int pos = i;
long int begLine = lineNb;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
i = i+1;
for (; (i<codeLength); i = i+1) {
c = cpstringCharAt(s,i);
char pc = cpstringCharAt(s,i-1);
if ((c==(char)34)) {
if ((pc!=(char)92)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
break;
}
}
if ((c==(char)10)) {
lineNb = lineNb+1;
if ((pc!=(char)92)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = (char)92;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = (char)92;
}
};
c = 110;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
}
};

                        if (tokens->length <= len(tokens)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: tokens[%d] with length %d", len(tokens)-1, tokens->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/lexer.bah:161");
                        };
                        struct Tok lt = tokens->data[len(tokens)-1];
lt.begLine = begLine;

{
long nLength = len(tokens)-1;
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)-1] = lt;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)-1] = lt;
}
};
}
else if ((isNumber(c)||isMinus(c,nc))) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
long int pos = i;
i = i+1;
tokenType currentType = TOKEN_TYPE_INT;
char isHex = false;
for (; (i<codeLength); i = i+1) {
c = cpstringCharAt(s,i);
if ((c==(char)46)) {
currentType = TOKEN_TYPE_FLOAT;
}
else if ((isNumber(c)==false)) {
if ((isHex==false)) {
if ((c==120)) {
isHex = true;
}
else {
break;
}
}
else {
if (isUpper(c)) {
c = c+(char)32;
}
if (((c<97)||(c>102))) {
break;
}
}
if ((isHex==false)) {
break;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};
i = i-1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
}
};
}
else if ((c==(char)39)) {
i = i+1;
char n = cpstringCharAt(s,i);
char * toInt = intToStr((long int)nc);
memory = strToArr(toInt);
i = i+1;
c = cpstringCharAt(s,i);
if ((c!=(char)39)) {
lexerErr(lineNb,i,"Missing closing tag in char declaration.");
}

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
}
};
}
else if ((c==(char)35)) {
long int pos = i;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
i = i+1;
for (; (i<codeLength); i = i+1) {
c = cpstringCharAt(s,i);
if ((isAlphaNumeric(c)==false)) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};
i = i-1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
}
};
}
else if (inArray(c,enclavers)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
}
};
}
else if (inArray(c,syntaxes)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
long int pos = i;
i = i+1;
char fc = c;
for (; (i<codeLength); i = i+1) {
c = cpstringCharAt(s,i);

                int ____BAH_COMPILER_VAR_62 = 0;
                for(int i=len(syntaxes)-1; i != -1; i--) {
                    if (syntaxes->data[i] == c) {
                        ____BAH_COMPILER_VAR_62 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_62==false)) {
break;
}
if ((fc==60)) {
if (((c!=45)&&(c!=61))) {
break;
}
}
else if ((c==124)) {
if ((fc!=c)) {
break;
}
}
else if ((c==38)) {
if ((fc!=c)) {
break;
}
}
else if ((c!=61)) {
if ((c!=62)) {
break;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};
i = i-1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
}
};
}
else if ((c==46)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
}
};
}
else if ((isAlphaNumeric(c)||(c==95))) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] = c;
memory->length = nLength+1;
} else {
memory->data[0] = c;
}
};
long int pos = i;
i = i+1;
for (; (i<codeLength); i = i+1) {
c = cpstringCharAt(s,i);
if ((isAlphaNumeric(c)==false)) {
if ((c!=95)) {
if ((c==62)) {

                        if (memory->length <= len(memory)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", len(memory)-1, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/lexer.bah:276");
                        };
                        char lc = memory->data[len(memory)-1];
if ((lc==45)) {

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)-1] = (char)0;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] = (char)0;
}
};
i = i-1;
break;
}
}
break;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
};
i = i-1;
tokenType currentType = TOKEN_TYPE_VAR;
char * memstr = arrAsStr(memory);

                int ____BAH_COMPILER_VAR_63 = 0;
                for(int i=len(keywords)-1; i != -1; i--) {
                    if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                        ____BAH_COMPILER_VAR_63 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_63) {
currentType = TOKEN_TYPE_KEYWORD;
}

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
}
};
}
};
totalLines = totalLines+lineNb-1;
dur = getTimeUnix()-dur;
totalLexerTime = totalLexerTime+dur;
return tokens;
};
char hasStructSep(struct string n){
if (n.count(&n,".")) {
return true;
}
if (n.count(&n,"->")) {
return true;
}
return false;
};
struct string splitStructSepBefore(struct string n){
if (n.count(&n,".")) {
char * ____BAH_COMPILER_VAR_64 =splitStringBefore(n,".");struct string res = string(____BAH_COMPILER_VAR_64);
return res;
}
if (n.count(&n,"->")) {
char * ____BAH_COMPILER_VAR_65 =splitStringBefore(n,"->");struct string res = string(____BAH_COMPILER_VAR_65);
return res;
}
return string("");
};
struct string splitStructSepAfter(struct string n){
long int i = n.length;
while ((i>0)) {
char c = n.charAt(&n,i);
if ((c==46)) {
break;
}
else if ((c==62)) {
char pc = n.charAt(&n,i-1);
if ((pc==45)) {
break;
}
}
i = i-1;
};
i = i+1;
n.trimLeft(&n,i);
return n;
};
struct cStruct* searchStruct(char * name,struct Elems* elems){
struct string n = string(name);
n.replace(&n,"&","");
n.replace(&n,"*","");
name = n.content;
long int i = len(elems->structs)-1;
for (; (i!=-1); i = i-1) {

                        if (elems->structs->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->structs[%d] with length %d", i, elems->structs->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/struct.bah:57");
                        };
                        struct cStruct* s = elems->structs->data[i];
if ((strcmp(s->name, name) == 0)) {
return s;
}
};
return null;
};
struct structMemb* searchStructMemb(char * name,struct cStruct* s,struct Elems* elems){
struct string n = string(name);
if (hasStructSep(n)) {
struct string rn = splitStructSepBefore(n);
name = rn.content;
n.trimLeft(&n,rn.length);
if (n.hasPrefix(&n,".")) {
n.trimLeft(&n,1);
}
else {
n.trimLeft(&n,2);
}
char * membs = n.content;
struct structMemb* memb = searchStructMemb(name,s,elems);
if ((n.length>0)) {
s = searchStruct(memb->type,elems);
char * nstr = n.str(&n);
memb = searchStructMemb(nstr,s,elems);
}
return memb;
}
array(struct structMemb*)* members = s->members;
long int i = 0;
while ((i<len(members))) {

                        if (members->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: members[%d] with length %d", i, members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/struct.bah:88");
                        };
                        struct structMemb* m = members->data[i];
if ((strcmp(m->name, name) == 0)) {
return m;
}
i = i+1;
};
array(struct func*)* mthds = s->methods;
i = 0;
while ((i<len(mthds))) {

                        if (mthds->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: mthds[%d] with length %d", i, mthds->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/struct.bah:96");
                        };
                        struct func* m = mthds->data[i];
if ((strcmp(m->name, name) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_66 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_66->name = "";
____BAH_COMPILER_VAR_66->type = "";
____BAH_COMPILER_VAR_66->isConst = false;
____BAH_COMPILER_VAR_66->constVal = "";
____BAH_COMPILER_VAR_66->isArray = false;
____BAH_COMPILER_VAR_66->from = "";
____BAH_COMPILER_VAR_66->outterScope = false;
____BAH_COMPILER_VAR_66->isGlobal = false;
____BAH_COMPILER_VAR_66->def = "";
____BAH_COMPILER_VAR_66->isFn = false;
struct structMemb* sm = ____BAH_COMPILER_VAR_66;
sm->name = m->name;
sm->from = m->from;
sm->type = m->returns->type;
sm->isFn = true;
return sm;
}
i = i+1;
};
if ((strlen(s->extendedFrom)==0)) {
return null;
}
struct cStruct* es = searchStruct(s->extendedFrom,elems);
return searchStructMemb(name,es,elems);
};
char isRCPpointerType(char * t){
if (strHasPrefix(t,"function(")) {
return false;
}
if (((((((strcmp(t, "cpstring") == 0)||(strcmp(t, "ptr") == 0))||(strCount(t,"*")>0))||(strHasPrefix(t,"[]")==true))||(strHasPrefix(t,"chan:")==true))||(strHasPrefix(t,"map:")==true))) {
return true;
}
return false;
};
char isRCPtype(char * t,struct Elems* elems){
if ((isRCPpointerType(t)==true)) {
return true;
}
struct cStruct* s = searchStruct(t,elems);
if (((s!=null)&&(s->isBinding==false))) {
return true;
}
return false;
};
struct string getCType(char * t,struct Elems* elems){
if ((strlen(t)==0)) {
return string("void");
}
struct string tp = string(t);
tp.replace(&tp," ","");
if (tp.hasPrefix(&tp,"[]")) {
tp.trimLeft(&tp,2);
char * tpstr = tp.str(&tp);
tp = getCType(tpstr,elems);
t = tp.str(&tp);
char * ____BAH_COMPILER_VAR_67 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("array(");
long int strLen_4 = strlen(t);
long int strLen_6 = strlen(")*");
;                            
                    ____BAH_COMPILER_VAR_67 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_67+currStrOff, "array(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_67+currStrOff, t, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_67+currStrOff, ")*", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * r = ____BAH_COMPILER_VAR_67;
return string(r);
}
struct string ctp = tp;
ctp.replace(&ctp,"*","");
if ((tp.hasPrefix(&tp,"chan:")==1)) {
tp.set(&tp,"struct channel *");
}
else if ((tp.hasPrefix(&tp,"map:")==1)) {
tp.set(&tp,"struct mapWrapper *");
}
else if ((tp.hasPrefix(&tp,"buffer:")==1)) {
tp.set(&tp,"char*");
}
else if (ctp.compare(&ctp,"int")) {
tp.replace(&tp,"int","long int");
}
else if (ctp.compare(&ctp,"int32")) {
tp.replace(&tp,"int32","int");
}
else if (ctp.compare(&ctp,"uint32")) {
tp.replace(&tp,"uint32","unsigned int");
}
else if (ctp.compare(&ctp,"uint")) {
tp.replace(&tp,"uint","unsigned long int");
}
else if (ctp.compare(&ctp,"float32")) {
tp.replace(&tp,"float32","float");
}
else if (ctp.compare(&ctp,"ufloat32")) {
tp.replace(&tp,"ufloat32","unsigned float");
}
else if (ctp.compare(&ctp,"ufloat")) {
tp.replace(&tp,"ufloat","unsigned double");
}
else if (ctp.compare(&ctp,"float")) {
tp.replace(&tp,"float","double");
}
else if (ctp.compare(&ctp,"long")) {
tp.replace(&tp,"long","long long");
}
else if (ctp.compare(&ctp,"ulong")) {
tp.replace(&tp,"ulong","unsigned long long");
}
else if (ctp.compare(&ctp,"cpstring")) {
tp.replace(&tp,"cpstring","char *");
}
else if (ctp.compare(&ctp,"ptr")) {
tp.replace(&tp,"ptr","void *");
}
else if (ctp.compare(&ctp,"ushort")) {
tp.replace(&tp,"ushort","unsigned short");
}
else if (ctp.compare(&ctp,"byte")) {
tp.replace(&tp,"byte","unsigned char");
}
else if (ctp.compare(&ctp,"bool")) {
tp.replace(&tp,"bool","char");
}
else if (ctp.compare(&ctp,"char")) {
}
else {
char * ctpstr = ctp.str(&ctp);
struct cStruct* s = searchStruct(ctpstr,elems);
if ((s!=null)) {
tp.prepend(&tp,"struct ");
}
else {
long int i = 0;
while ((i<len(elems->types))) {

                        if (elems->types->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->types[%d] with length %d", i, elems->types->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/type.bah:97");
                        };
                        char * ct = elems->types->data[i];
if (ctp.compare(&ctp,ct)) {
return tp;
}
i = i+1;
};
return string("");
}
}
return tp;
};
array(char *)* intTypes;
array(char *)* floatTypes;
char compTypeEquiv(char * a,char * b,char first){
if (((strcmp(a, "cpstring") == 0)&&strHasPrefix(b,"buffer:"))) {
return true;
}

                int ____BAH_COMPILER_VAR_68 = 0;
                for(int i=len(intTypes)-1; i != -1; i--) {
                    if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], a) == 0) {
                        ____BAH_COMPILER_VAR_68 = 1;
                        break;
                    };
                };
                
                int ____BAH_COMPILER_VAR_69 = 0;
                for(int i=len(intTypes)-1; i != -1; i--) {
                    if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], b) == 0) {
                        ____BAH_COMPILER_VAR_69 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_68&&____BAH_COMPILER_VAR_69)) {
return true;
}

                int ____BAH_COMPILER_VAR_70 = 0;
                for(int i=len(floatTypes)-1; i != -1; i--) {
                    if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], a) == 0) {
                        ____BAH_COMPILER_VAR_70 = 1;
                        break;
                    };
                };
                
                int ____BAH_COMPILER_VAR_71 = 0;
                for(int i=len(floatTypes)-1; i != -1; i--) {
                    if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], b) == 0) {
                        ____BAH_COMPILER_VAR_71 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_70&&____BAH_COMPILER_VAR_71)) {
return true;
}
if ((first==false)) {
return false;
}
if (compTypeEquiv(b,a,false)) {
return true;
}
return (strcmp(a, b) == 0);
};
char compTypes(char * a,char * b){
if (((strcmp(a, "ptr") == 0)||(strcmp(b, "ptr") == 0))) {
return true;
}
return compTypeEquiv(a,b,true);
};
#include <stddef.h>
struct reflectElement {
long int size;
char * type;
char * name;
char isArray;
struct reflectElement* arrayElem;
char isStruct;
array(struct reflectElement)* structLayout;
long int offset;
void * value;
void *(*calculateOffset)(struct reflectElement* this,void * origin);
};
void * reflectElement__calculateOffset(struct reflectElement* this,void * origin){
char * base = origin;
return base+this->offset;
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,char isArr,struct reflectElement* ae,char isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement ____BAH_COMPILER_VAR_72 = {};
____BAH_COMPILER_VAR_72.type= null;
____BAH_COMPILER_VAR_72.name= null;
____BAH_COMPILER_VAR_72.arrayElem= null;
____BAH_COMPILER_VAR_72.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_72.structLayout->length = 0;
            ____BAH_COMPILER_VAR_72.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_72.value= null;
____BAH_COMPILER_VAR_72.calculateOffset = reflectElement__calculateOffset;
#define re ____BAH_COMPILER_VAR_72
re.size = s;
re.type = t;
re.name = n;
re.isArray = isArr;
re.arrayElem = ae;
re.isStruct = isStruct;
re.structLayout = sl;
re.value = v;
re.offset = offset;
return re;
};
typedef void * reflectSymbols;
__BAH_ARR_TYPE_reflectElement __dumpSymbols(__BAH_ARR_TYPE_reflectElement syms){
return syms;
};
struct reflectElement __debug_get_sym(__BAH_ARR_TYPE_reflectElement syms,struct string a){
if ((a.count(&a,".")>0)) {
array(struct string)* parts = splitString(a,".");

                        if (parts->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: parts[%d] with length %d", 0, parts->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/reflect.bah:63");
                        };
                        struct string p1 = parts->data[0];

                        if (parts->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: parts[%d] with length %d", 1, parts->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/reflect.bah:64");
                        };
                        struct string p2 = parts->data[1];
long int j = 0;
for (; (j<len(syms)); j = j+1) {

                        if (syms->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: syms[%d] with length %d", j, syms->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/reflect.bah:66");
                        };
                        struct reflectElement s = syms->data[j];
if ((strcmp(s.name, p1.str(&p1)) == 0)) {
long int k = 0;
for (; (k<len(s.structLayout)); k = k+1) {

                        if (s.structLayout->length <= k) {
                            char buff[300];
                            snprintf(buff, 299, "array: s.structLayout[%d] with length %d", k, s.structLayout->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/reflect.bah:69");
                        };
                        struct reflectElement m = s.structLayout->data[k];
if ((strcmp(m.name, p2.str(&p2)) == 0)) {
m.value = m.calculateOffset(&m,s.value);
return m;
}
};
break;
}
};
}
else {
long int j = 0;
for (; (j<len(syms)); j = j+1) {

                        if (syms->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: syms[%d] with length %d", j, syms->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/reflect.bah:80");
                        };
                        struct reflectElement s = syms->data[j];
if ((strcmp(s.name, a.str(&a)) == 0)) {
return s;
}
};
}
struct reflectElement ____BAH_COMPILER_VAR_73 = {};
____BAH_COMPILER_VAR_73.type= null;
____BAH_COMPILER_VAR_73.name= null;
____BAH_COMPILER_VAR_73.arrayElem= null;
____BAH_COMPILER_VAR_73.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_73.structLayout->length = 0;
            ____BAH_COMPILER_VAR_73.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_73.value= null;
____BAH_COMPILER_VAR_73.calculateOffset = reflectElement__calculateOffset;
#define ns ____BAH_COMPILER_VAR_73
return ns;
};
#define __bah_reflect __reflect
#define __bah_dump_symbols __dumpSymbols
#define __bah_debug_get_sym __debug_get_sym
#define JSON_TYPE_STRING 0
#define JSON_TYPE_INT 1
#define JSON_TYPE_FLOAT 2
#define JSON_TYPE_ARRAY 3
#define JSON_TYPE_MAP 4
char * toJson(struct reflectElement e);
void json_scan_inner(void * this,struct reflectElement e,char isMember);
struct jsonElement {
long int type;
char * key;
char * content;
array(struct jsonElement*)* children;
struct jsonElement*(*get)(struct jsonElement* this,char * key);
char *(*str)(struct jsonElement* this);
void(*scan)(struct jsonElement* this,struct reflectElement e);
};
struct jsonElement* jsonElement__get(struct jsonElement* this,char * key){
long int l = len(this->children);
long int i = 0;
while ((i<l)) {

                        if (this->children->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->children[%d] with length %d", i, this->children->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:29");
                        };
                        struct jsonElement* elem = this->children->data[i];
char fc = cpstringCharAt(elem->key,0);
if ((fc==(char)34)) {
array(char)* nk = memoryAlloc(sizeof(array(char)));

nk->length = 0;
nk->elemSize = sizeof(char);
long int lk = strlen(elem->key);
long int j = 1;
while ((j<lk-1)) {
char c = cpstringCharAt(elem->key,j);

{
long nLength = j-1;
if (nk->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nk->data, (nLength+50)*sizeof(char));
nk->data = newPtr;
}
nk->data[j-1] = c;
nk->length = nLength+1;
} else {
nk->data[j-1] = c;
}
};
j = j+1;
};
if ((strcmp(arrAsStr(nk), key) == 0)) {
return elem;
}
}
else {
if ((strcmp(elem->key, key) == 0)) {
return elem;
}
}
i = i+1;
};
void * z = (void *)0;
return z;
};
char * jsonElement__str(struct jsonElement* this){
char * ctn = this->content;
return ctn;
};
void jsonElement__scan(struct jsonElement* this,struct reflectElement e){
json_scan_inner(this,e,false);
};
void json_scan_inner(void * thisp,struct reflectElement e,char isMember){
struct jsonElement* this = thisp;
if ((e.isStruct==true)) {
long int i = 0;
while ((i<len(e.structLayout))) {

                        if (e.structLayout->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: e.structLayout[%d] with length %d", i, e.structLayout->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:71");
                        };
                        struct reflectElement m = e.structLayout->data[i];
struct jsonElement* ov = this->get(this,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
i = i+1;
};
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ep = e.value;
*ep = strToInt(this->content);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
char ** ep = e.value;
*ep = memoryAlloc(strlen(this->content)+1);
strcpy(*ep,this->content);
}
else if ((strcmp(e.type, "float") == 0)) {
double* ep = e.value;
*ep = strToFloat(this->content);
}
else if ((strcmp(e.type, "bool") == 0)) {
char* ep = e.value;
if (((strcmp(this->content, "1") == 0)||(strcmp(this->content, "true") == 0))) {
*ep = true;
}
else {
*ep = false;
}
}
else if ((e.isArray==true)) {
if ((len(this->children)==0)) {
return;
}
struct reflectElement* ae = e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr = e.value;
if ((isMember==true)) {
*arrPtr = arr;
}
else {
arr = *arrPtr;
}
long int i = 0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->children[%d] with length %d", i, this->children->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:110");
                        };
                        struct jsonElement* c = this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(long int));
arr->data = newPtr;
}
arr->data[i] = strToInt(c->content);
arr->length = nLength+1;
} else {
arr->data[i] = strToInt(c->content);
}
};
i = i+1;
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr = e.value;
if ((isMember==true)) {
*arrPtr = arr;
}
else {
arr = *arrPtr;
}
long int i = 0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->children[%d] with length %d", i, this->children->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:123");
                        };
                        struct jsonElement* c = this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(double));
arr->data = newPtr;
}
arr->data[i] = strToFloat(c->content);
arr->length = nLength+1;
} else {
arr->data[i] = strToFloat(c->content);
}
};
i = i+1;
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
if ((isMember==true)) {
*arrPtr = arr;
}
else {
arr = *arrPtr;
}
long int i = 0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->children[%d] with length %d", i, this->children->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:136");
                        };
                        struct jsonElement* c = this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(char *));
arr->data = newPtr;
}
arr->data[i] = memoryAlloc(strlen(c->content)+1);
arr->length = nLength+1;
} else {
arr->data[i] = memoryAlloc(strlen(c->content)+1);
}
};
strcpy(arr->data[i],c->content);
i = i+1;
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
void ** arrPtr = e.value;
if ((isMember==true)) {
*arrPtr = arr;
}
else {
arr = *arrPtr;
}
long int i = 0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->children[%d] with length %d", i, this->children->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:150");
                        };
                        struct jsonElement* c = this->children->data[i];
void * ne = memoryAlloc(ae->size);
long int j = 0;
while ((j<len(ae->structLayout))) {

                        if (ae->structLayout->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: ae->structLayout[%d] with length %d", j, ae->structLayout->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:153");
                        };
                        struct reflectElement m = ae->structLayout->data[j];
m.value = m.calculateOffset(&m,ne);
struct jsonElement* ov = c->get(c,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
j = j+1;
};

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(void *));
arr->data = newPtr;
}
arr->data[i] = ne;
arr->length = nLength+1;
} else {
arr->data[i] = ne;
}
};
i = i+1;
};
}
}
else if (strHasPrefix(e.type,"map:")) {
struct mapWrapper** p = e.value;
long int i = 0;
for (; (i<len(this->children)); i = i+1) {

                        if (this->children->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->children[%d] with length %d", i, this->children->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:168");
                        };
                        struct jsonElement* c = this->children->data[i];
struct reflectElement* ae = e.arrayElem;
void * v = memoryAlloc(ae->size);
ae->value = &v;
long int j = 0;
for (; (j<len(ae->structLayout)); j = j+1) {

                        if (ae->structLayout->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: ae->structLayout[%d] with length %d", j, ae->structLayout->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:173");
                        };
                        struct reflectElement m = ae->structLayout->data[j];
m.value = m.calculateOffset(&m,&v);

{
long nLength = j;
if (ae->structLayout->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ae->structLayout->data, (nLength+50)*sizeof(struct reflectElement));
ae->structLayout->data = newPtr;
}
ae->structLayout->data[j] = m;
ae->structLayout->length = nLength+1;
} else {
ae->structLayout->data[j] = m;
}
};
};
json_scan_inner(c,*ae,true);
struct string k = string(c->key);
k.trimLeft(&k,1);
k.trimRight(&k,1);
if (((((strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0))||(strcmp(ae->type, "cpstring") == 0))||strHasPrefix(ae->type,"[]"))||strHasPrefix(ae->type,"map:"))) {
char * ____BAH_COMPILER_VAR_74 =k.str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_74,v);
}
else {
char * ____BAH_COMPILER_VAR_75 =k.str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_75,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_76 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_76->key= null;
____BAH_COMPILER_VAR_76->content= null;
____BAH_COMPILER_VAR_76->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_76->children->length = 0;
            ____BAH_COMPILER_VAR_76->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_76->get = jsonElement__get;
____BAH_COMPILER_VAR_76->str = jsonElement__str;
____BAH_COMPILER_VAR_76->scan = jsonElement__scan;
struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_76;
long int lenS = strlen(s);
long int i = 0;
while ((i<lenS)) {
if ((isSpace(cpstringCharAt(s,i))==false)) {
break;
}
i = i+1;
};
char fc = cpstringCharAt(s,i);
if ((fc==91)) {
jsonElem->type = JSON_TYPE_ARRAY;
}
else if ((fc==123)) {
jsonElem->type = JSON_TYPE_MAP;
}
else if ((fc==(char)34)) {
jsonElem->type = JSON_TYPE_STRING;
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
i = i+1;
long int start = i;
while ((i<lenS-1)) {
char c = cpstringCharAt(s,i);
if (((i>start)&&(cpstringCharAt(s,i-1)==(char)92))) {
if ((c==110)) {
c = (char)10;
}
else if ((c==114)) {
c = (char)13;
}

{
long nLength = len(ns)-1;
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)-1] = c;
ns->length = nLength+1;
} else {
ns->data[len(ns)-1] = c;
}
};
}
else {

{
long nLength = len(ns);
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] = c;
ns->length = nLength+1;
} else {
ns->data[len(ns)] = c;
}
};
}
i = i+1;
};
jsonElem->content = arrToStr(ns);
}
else if (isNumber(cpstringCharAt(s,strlen(s)-1))) {
char isFloat = false;
while ((i<lenS)) {
if ((cpstringCharAt(s,i)==46)) {
isFloat = true;
break;
}
i = i+1;
};
if ((isFloat==true)) {
jsonElem->type = JSON_TYPE_FLOAT;
}
else {
jsonElem->type = JSON_TYPE_INT;
}
jsonElem->content = s;
}
else {
return null;
}
if ((jsonElem->type==JSON_TYPE_ARRAY)) {
i = i+1;
long int trim = 1;
long int j = lenS-1;
while ((j>=0)) {
char c = cpstringCharAt(s,j);
if (isSpace(c)) {
trim = trim+1;
}
else {
break;
}
j = j-1;
};
while ((i<lenS-1)) {
char c = cpstringCharAt(s,i);
if ((isSpace(c)==false)) {
break;
}
i = i+1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
long int currentBracks = 0;
long int currentBraces = 0;
long int currentQuotes = 0;
long int elemIndex = 0;
while ((i<lenS-trim)) {
char c = cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes = 1;
}
else {
currentQuotes = 0;
}
}
else if ((c==91)) {
currentBracks = currentBracks+1;
}
else if ((c==93)) {
currentBracks = currentBracks-1;
}
else if ((c==123)) {
currentBraces = currentBraces+1;
}
else if ((c==125)) {
currentBraces = currentBraces-1;
}
long int total = currentBracks+currentBraces+currentQuotes;
if ((total>0)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] = c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] = c;
}
};
i = i+1;
continue;
}
if ((c==44)) {
char * ____BAH_COMPILER_VAR_77 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_77);
if ((child!=null)) {

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] = child;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] = child;
}
};
}
clear(currentElem);
elemIndex = elemIndex+1;
}
else {
if (isSpace(c)) {
i = i+1;
continue;
}

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] = c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] = c;
}
};
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_78 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_78);
if ((child!=null)) {

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] = child;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] = child;
}
};
}
}
else if ((jsonElem->type==JSON_TYPE_MAP)) {
i = i+1;
long int trim = 1;
long int j = lenS-1;
while ((j>=0)) {
char c = cpstringCharAt(s,j);
if (isSpace(c)) {
trim = trim+1;
}
else {
break;
}
j = j-1;
};
while ((i<lenS-1)) {
char c = cpstringCharAt(s,i);
if ((isSpace(c)==false)) {
break;
}
i = i+1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
array(char)* currentKey = memoryAlloc(sizeof(array(char)));

currentKey->length = 0;
currentKey->elemSize = sizeof(char);
long int isVal = 0;
long int currentBracks = 0;
long int currentBraces = 0;
long int currentQuotes = 0;
long int elemIndex = 0;
while ((i<lenS-trim)) {
char c = cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes = 1;
}
else {
currentQuotes = 0;
}
}
else if ((c==91)) {
currentBracks = currentBracks+1;
}
else if ((c==93)) {
currentBracks = currentBracks-1;
}
else if ((c==123)) {
currentBraces = currentBraces+1;
}
else if ((c==125)) {
currentBraces = currentBraces-1;
}
long int total = currentBracks+currentBraces+currentQuotes;
if ((total>0)) {
if ((isVal==1)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] = c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] = c;
}
};
}
else {

{
long nLength = len(currentKey);
if (currentKey->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentKey->data, (nLength+50)*sizeof(char));
currentKey->data = newPtr;
}
currentKey->data[len(currentKey)] = c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] = c;
}
};
}
i = i+1;
continue;
}
if ((c==58)) {
isVal = 1;
}
else if ((c==44)) {
char * ____BAH_COMPILER_VAR_79 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_79);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] = elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] = elem;
}
};
elemIndex = elemIndex+1;
}
clear(currentElem);
clear(currentKey);
isVal = 0;
}
else {
if (isSpace(c)) {
i = i+1;
continue;
}
if ((isVal==1)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] = c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] = c;
}
};
}
else {

{
long nLength = len(currentKey);
if (currentKey->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentKey->data, (nLength+50)*sizeof(char));
currentKey->data = newPtr;
}
currentKey->data[len(currentKey)] = c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] = c;
}
};
}
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_80 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_80);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] = elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] = elem;
}
};
}
}
return jsonElem;
};
char * jsonEscapeStr(char * s){
array(char)* a = strAsArr(s);
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
long int i = 0;
while ((i<len(a))) {

                        if (a->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: a[%d] with length %d", i, a->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:411");
                        };
                        char c = a->data[i];
if ((c==(char)34)) {

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] = (char)92;
}
};
}
else if ((c==(char)10)) {

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] = (char)92;
}
};

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = 110;
r->length = nLength+1;
} else {
r->data[len(r)] = 110;
}
};
i = i+1;
continue;
}
else if ((c==(char)13)) {

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] = (char)92;
}
};

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = 114;
r->length = nLength+1;
} else {
r->data[len(r)] = 114;
}
};
i = i+1;
continue;
}

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] = c;
r->length = nLength+1;
} else {
r->data[len(r)] = c;
}
};
i = i+1;
};
return arrToStr(r);
};
char * toJson__inner(struct reflectElement e,char isMember,long int tabs){
void ** v = e.value;
if (((e.value==null)||(*v==null))) {
if (((strcmp(e.type, "int") == 0)||(strcmp(e.type, "float") == 0))) {
return "0";
}
if ((strcmp(e.type, "bool") == 0)) {
return "false";
}
if ((((strcmp(e.type, "ptr") == 0)||(strcmp(e.type, "cpstring") == 0))||(strCount(e.type,"*")!=0))) {
return "null";
}
}
if ((e.isStruct==true)) {
tabs = tabs+1;
char * tabsStr = "";
long int i = 0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_81 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tabsStr);
long int strLen_4 = strlen("\t");
;                            
                    ____BAH_COMPILER_VAR_81 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_81+currStrOff, tabsStr, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_81+currStrOff, "\t", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tabsStr = ____BAH_COMPILER_VAR_81;
i = i+1;
};
char * s = "{\n";
i = 0;
while ((i<len(e.structLayout))) {

                        if (e.structLayout->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: e.structLayout[%d] with length %d", i, e.structLayout->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:456");
                        };
                        struct reflectElement m = e.structLayout->data[i];
i = i+1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_82 =null;char * ____BAH_COMPILER_VAR_83 =toJson__inner(m,true,tabs);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(tabsStr);
long int strLen_6 = strlen("\"");
long int strLen_8 = strlen(m.name);
long int strLen_10 = strlen("\": ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_83);
long int strLen_14 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_82 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_82+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_82+currStrOff, tabsStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_82+currStrOff, "\"", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_82+currStrOff, m.name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_82+currStrOff, "\": ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_82+currStrOff, ____BAH_COMPILER_VAR_83, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_82+currStrOff, ",\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                s = ____BAH_COMPILER_VAR_82;
}
else {
char * ____BAH_COMPILER_VAR_84 =null;char * ____BAH_COMPILER_VAR_85 =toJson__inner(m,true,tabs);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(tabsStr);
long int strLen_6 = strlen("\"");
long int strLen_8 = strlen(m.name);
long int strLen_10 = strlen("\": ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_85);
long int strLen_14 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_84 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_84+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_84+currStrOff, tabsStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_84+currStrOff, "\"", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_84+currStrOff, m.name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_84+currStrOff, "\": ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_84+currStrOff, ____BAH_COMPILER_VAR_85, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_84+currStrOff, "\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                s = ____BAH_COMPILER_VAR_84;
}
};
tabs = tabs-1;
tabsStr = "";
i = 0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_86 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tabsStr);
long int strLen_4 = strlen("\t");
;                            
                    ____BAH_COMPILER_VAR_86 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_86+currStrOff, tabsStr, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_86+currStrOff, "\t", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tabsStr = ____BAH_COMPILER_VAR_86;
i = i+1;
};
char * ____BAH_COMPILER_VAR_87 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(tabsStr);
long int strLen_6 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_87 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_87+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_87+currStrOff, tabsStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_87+currStrOff, "}", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                s = ____BAH_COMPILER_VAR_87;
return s;
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ip = e.value;
return intToStr(*ip);
}
else if ((strcmp(e.type, "float") == 0)) {
double* fp = e.value;
return floatToStr(*fp);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
if ((isMember==false)) {
void * s = e.value;
char * ____BAH_COMPILER_VAR_88 =null;char * ____BAH_COMPILER_VAR_89 =jsonEscapeStr(s);
                {
                    long int currStrOff = 0;
                    long int strLen_1 = strlen("\"");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_89);
long int strLen_5 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_88 = memoryAllocSTR(1 + strLen_1 + strLen_3 + strLen_5);
                    
                        memcpy(____BAH_COMPILER_VAR_88+currStrOff, "\"", strLen_1);
                        currStrOff += strLen_1;
                        
                        memcpy(____BAH_COMPILER_VAR_88+currStrOff, ____BAH_COMPILER_VAR_89, strLen_3);
                        currStrOff += strLen_3;
                        
                        memcpy(____BAH_COMPILER_VAR_88+currStrOff, "\"", strLen_5);
                        currStrOff += strLen_5;
                        
                }
                return ____BAH_COMPILER_VAR_88;
}
else {
char ** sp = e.value;
char * s = *sp;
char * ____BAH_COMPILER_VAR_90 =null;char * ____BAH_COMPILER_VAR_91 =jsonEscapeStr(s);
                {
                    long int currStrOff = 0;
                    long int strLen_1 = strlen("\"");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_91);
long int strLen_5 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_90 = memoryAllocSTR(1 + strLen_1 + strLen_3 + strLen_5);
                    
                        memcpy(____BAH_COMPILER_VAR_90+currStrOff, "\"", strLen_1);
                        currStrOff += strLen_1;
                        
                        memcpy(____BAH_COMPILER_VAR_90+currStrOff, ____BAH_COMPILER_VAR_91, strLen_3);
                        currStrOff += strLen_3;
                        
                        memcpy(____BAH_COMPILER_VAR_90+currStrOff, "\"", strLen_5);
                        currStrOff += strLen_5;
                        
                }
                return ____BAH_COMPILER_VAR_90;
}
}
else if ((strcmp(e.type, "bool") == 0)) {
char* bp = e.value;
if ((*bp==true)) {
return "true";
}
return "false";
}
else if ((e.isArray==true)) {
char * s = "[";
struct reflectElement* ae = e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr = e.value;
arr = *arrPtr;
long int i = 0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_92 =null;char * ____BAH_COMPILER_VAR_93 =intToStr(arr->data[i]);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_93);
;                            
                    ____BAH_COMPILER_VAR_92 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_92+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_92+currStrOff, ____BAH_COMPILER_VAR_93, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_92;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_94 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_94 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_94+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_94+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_94;
}
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr = e.value;
arr = *arrPtr;
long int i = 0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_95 =null;char * ____BAH_COMPILER_VAR_96 =floatToStr(arr->data[i]);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_96);
;                            
                    ____BAH_COMPILER_VAR_95 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_95+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_95+currStrOff, ____BAH_COMPILER_VAR_96, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_95;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_97 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_97 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_97+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_97+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_97;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
arr = *arrPtr;
char * ____BAH_COMPILER_VAR_98 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_98 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_98+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_98+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_98;
long int i = 0;
while ((i<len(arr))) {

                        if (arr->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: arr[%d] with length %d", i, arr->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:524");
                        };
                        char * ____BAH_COMPILER_VAR_99 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(arr->data[i]);
;                            
                    ____BAH_COMPILER_VAR_99 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_99+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_99+currStrOff, arr->data[i], strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_99;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_100 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_100 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_100+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_100+currStrOff, ",\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_100;
}
else {
char * ____BAH_COMPILER_VAR_101 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_101 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_101+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_101+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_101;
}
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
if ((isMember==false)) {
arr = e.value;
}
else {
void ** ev = e.value;
arr = *ev;
}
long int i = 0;
while ((i<len(arr))) {

                        if (arr->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: arr[%d] with length %d", i, arr->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:544");
                        };
                        void * arrElem = arr->data[i];
ae->value = arrElem;
long int j = 0;
while ((j<len(ae->structLayout))) {

                        if (ae->structLayout->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: ae->structLayout[%d] with length %d", j, ae->structLayout->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:547");
                        };
                        struct reflectElement m = ae->structLayout->data[j];
m.value = m.calculateOffset(&m,ae->value);

{
long nLength = j;
if (ae->structLayout->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ae->structLayout->data, (nLength+50)*sizeof(struct reflectElement));
ae->structLayout->data = newPtr;
}
ae->structLayout->data[j] = m;
ae->structLayout->length = nLength+1;
} else {
ae->structLayout->data[j] = m;
}
};
j = j+1;
};
char * ____BAH_COMPILER_VAR_102 =null;char * ____BAH_COMPILER_VAR_103 =toJson__inner(*ae,false,tabs);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_103);
;                            
                    ____BAH_COMPILER_VAR_102 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_102+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_102+currStrOff, ____BAH_COMPILER_VAR_103, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_102;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_104 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_104 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_104+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_104+currStrOff, ",\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_104;
}
else {
char * ____BAH_COMPILER_VAR_105 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_105 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_105;
}
};
}
char * ____BAH_COMPILER_VAR_106 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_106 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_106+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_106+currStrOff, "]", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_106;
return s;
}
return "";
};
char * toJson(struct reflectElement e){
return toJson__inner(e,false,0);
};
struct debugFunctionArgument {
char * name;
char * type;
};
struct debugFunction {
char * name;
char * returns;
array(struct variable*)* args;
};
struct debugStruct {
char * name;
array(struct variable*)* membs;
};
struct debugType {
char * name;
char * refers;
};
void debugStart(){
println("[");
};
void debugPrint(char * name,long int line,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_107 = name;
struct reflectElement ____BAH_COMPILER_VAR_108 = __reflect(____BAH_COMPILER_VAR_107, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_109 =null;char * ____BAH_COMPILER_VAR_110 =toJson(____BAH_COMPILER_VAR_108);char * ____BAH_COMPILER_VAR_111 =intToStr(line);char * ____BAH_COMPILER_VAR_112 =toJson(e);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_110);
long int strLen_4 = strlen(",\n        \"path\": \"");
long int strLen_6 = strlen(compilerState.currentFile);
long int strLen_8 = strlen(":");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_111);
long int strLen_12 = strlen("\",\n        \"element\": ");
long int strLen_14 = strlen(____BAH_COMPILER_VAR_112);
long int strLen_16 = strlen("\n    },\n    ");
;                            
                    ____BAH_COMPILER_VAR_109 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_109+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_109+currStrOff, ____BAH_COMPILER_VAR_110, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_109+currStrOff, ",\n        \"path\": \"", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_109+currStrOff, compilerState.currentFile, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_109+currStrOff, ":", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_109+currStrOff, ____BAH_COMPILER_VAR_111, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_109+currStrOff, "\",\n        \"element\": ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_109+currStrOff, ____BAH_COMPILER_VAR_112, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_109+currStrOff, "\n    },\n    ", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                println(____BAH_COMPILER_VAR_109);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_113 = name;
struct reflectElement ____BAH_COMPILER_VAR_114 = __reflect(____BAH_COMPILER_VAR_113, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_115 =null;char * ____BAH_COMPILER_VAR_116 =toJson(____BAH_COMPILER_VAR_114);char * ____BAH_COMPILER_VAR_117 =intToStr(line);char * ____BAH_COMPILER_VAR_118 =intToStr(from);char * ____BAH_COMPILER_VAR_119 =intToStr(to);char * ____BAH_COMPILER_VAR_120 =toJson(e);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_116);
long int strLen_4 = strlen(",\n        \"path\": \"");
long int strLen_6 = strlen(compilerState.currentFile);
long int strLen_8 = strlen(":");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_117);
long int strLen_12 = strlen("\",\n        \"range\": [\n            ");
long int strLen_14 = strlen(____BAH_COMPILER_VAR_118);
long int strLen_16 = strlen(",\n            ");
long int strLen_18 = strlen(____BAH_COMPILER_VAR_119);
long int strLen_20 = strlen("\n        ],\n        \"element\": ");
long int strLen_22 = strlen(____BAH_COMPILER_VAR_120);
long int strLen_24 = strlen("\n    },\n    ");
;                            
                    ____BAH_COMPILER_VAR_115 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24);
                    
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_116, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, ",\n        \"path\": \"", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, compilerState.currentFile, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, ":", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_117, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\",\n        \"range\": [\n            ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_118, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, ",\n            ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_119, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\n        ],\n        \"element\": ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_120, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\n    },\n    ", strLen_24);
                        currStrOff += strLen_24;
                        
                }
                println(____BAH_COMPILER_VAR_115);
};
void debugEnd(){
println("\n    {\n        \"name\": \"file_end\"\n    }\n    ]\n    ");
};
void debugExit(){
println("\n    {\n        \"name\": \"error_end\"\n    }\n    ]\n    ");
};
void debugEndScope(long int line,struct Elems* elems){
if ((debug==false)) {
return;
}
long int i = 0;
while ((i<len(elems->vars))) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/logger.bah:83");
                        };
                        struct variable* v = elems->vars->data[i];
if (((v->outterScope==false)&&(v->isConst==false))) {
struct variable* ____BAH_COMPILER_VAR_121 = v;
char ** ____BAH_COMPILER_VAR_123 = (char **)((char*)(____BAH_COMPILER_VAR_121) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_124 = __reflect(____BAH_COMPILER_VAR_123, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_125 = (char **)((char*)(____BAH_COMPILER_VAR_121) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_126 = __reflect(____BAH_COMPILER_VAR_125, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_127 = (char*)((char*)(____BAH_COMPILER_VAR_121) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_128 = __reflect(____BAH_COMPILER_VAR_127, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_129 = (char **)((char*)(____BAH_COMPILER_VAR_121) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_130 = __reflect(____BAH_COMPILER_VAR_129, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_131 = (char*)((char*)(____BAH_COMPILER_VAR_121) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_132 = __reflect(____BAH_COMPILER_VAR_131, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_133 = (char **)((char*)(____BAH_COMPILER_VAR_121) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_134 = __reflect(____BAH_COMPILER_VAR_133, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_135 = (char*)((char*)(____BAH_COMPILER_VAR_121) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_136 = __reflect(____BAH_COMPILER_VAR_135, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_137 = (char*)((char*)(____BAH_COMPILER_VAR_121) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_138 = __reflect(____BAH_COMPILER_VAR_137, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_122 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_122->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_122->length = 8;
        ____BAH_COMPILER_VAR_122->data = memoryAlloc(____BAH_COMPILER_VAR_122->length * ____BAH_COMPILER_VAR_122->elemSize);
        ____BAH_COMPILER_VAR_122->data[0] = ____BAH_COMPILER_VAR_124;
____BAH_COMPILER_VAR_122->data[1] = ____BAH_COMPILER_VAR_126;
____BAH_COMPILER_VAR_122->data[2] = ____BAH_COMPILER_VAR_128;
____BAH_COMPILER_VAR_122->data[3] = ____BAH_COMPILER_VAR_130;
____BAH_COMPILER_VAR_122->data[4] = ____BAH_COMPILER_VAR_132;
____BAH_COMPILER_VAR_122->data[5] = ____BAH_COMPILER_VAR_134;
____BAH_COMPILER_VAR_122->data[6] = ____BAH_COMPILER_VAR_136;
____BAH_COMPILER_VAR_122->data[7] = ____BAH_COMPILER_VAR_138;
struct reflectElement ____BAH_COMPILER_VAR_139 = __reflect(____BAH_COMPILER_VAR_121, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_122, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_139);
}
i = i+1;
};
};
void throwErr(void * tp,char * format){
char * str = "";
char * info = "";
long int pos = 0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_140 = {};
____BAH_COMPILER_VAR_140.handle = -1;
____BAH_COMPILER_VAR_140.p= null;
____BAH_COMPILER_VAR_140.open = fileMap__open;
____BAH_COMPILER_VAR_140.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_140.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_140
char * fileSrcStr = fm.open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char * ____BAH_COMPILER_VAR_141 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_4 = strlen("'");
long int strLen_6 = strlen(t->ogCont);
long int strLen_8 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_141 = memoryAllocSTR(1 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_141+currStrOff, "'", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_141+currStrOff, t->ogCont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_141+currStrOff, "'", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                ffmt.replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_141);
format = ffmt.str(&ffmt);
array(char)* line = memoryAlloc(sizeof(array(char)));

line->length = 0;
line->elemSize = sizeof(char);
long int beg = t->pos;
while ((beg>0)) {
char c = cpstringCharAt(fileSrcStr,beg);
if ((c==(char)10)) {
beg = beg+1;
break;
}
beg = beg-1;
};
pos = t->pos-beg+1;
long int i = beg;
while ((i<fm.size)) {
char c = cpstringCharAt(fileSrcStr,i);
if ((c==(char)10)) {
break;
}
if ((i==t->pos)) {
char * ____BAH_COMPILER_VAR_142 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m");
long int strLen_2 = strlen(t->ogCont);
long int strLen_4 = strlen("\e[1;37m");
;                            
                    ____BAH_COMPILER_VAR_142 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_142+currStrOff, "\e[1;31m", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_142+currStrOff, t->ogCont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_142+currStrOff, "\e[1;37m", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                array(char)* errTk = strToArr(____BAH_COMPILER_VAR_142);
long int ii = 0;
while ((ii<len(errTk))) {

                        if (errTk->length <= ii) {
                            char buff[300];
                            snprintf(buff, 299, "array: errTk[%d] with length %d", ii, errTk->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/errors.bah:44");
                        };
                        
{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(char));
line->data = newPtr;
}
line->data[len(line)] = errTk->data[ii];
line->length = nLength+1;
} else {
line->data[len(line)] = errTk->data[ii];
}
};
ii = ii+1;
};
i = i+strlen(t->ogCont);
continue;
}

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(char));
line->data = newPtr;
}
line->data[len(line)] = c;
line->length = nLength+1;
} else {
line->data[len(line)] = c;
}
};
i = i+1;
};
fm.close(&fm);
str = arrToStr(line);
char * ____BAH_COMPILER_VAR_143 =null;char * ____BAH_COMPILER_VAR_144 =intToStr(t->line);char * ____BAH_COMPILER_VAR_145 =intToStr(pos);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_144);
long int strLen_4 = strlen(":");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_145);
;                            
                    ____BAH_COMPILER_VAR_143 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_143+currStrOff, ____BAH_COMPILER_VAR_144, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_143+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_143+currStrOff, ____BAH_COMPILER_VAR_145, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                info = ____BAH_COMPILER_VAR_143;
}
if ((debug==true)) {
struct Tok* t = tp;
char * ____BAH_COMPILER_VAR_146 = format;
struct reflectElement ____BAH_COMPILER_VAR_147 = __reflect(____BAH_COMPILER_VAR_146, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_147);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_148 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[ERROR]\e[0m ");
long int strLen_2 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_6 = strlen(info);
long int strLen_8 = strlen("\n\e[1;37m\t");
long int strLen_10 = strlen(str);
long int strLen_12 = strlen("\e[0m\n");
long int strLen_14 = strlen(format);
;                            
                    ____BAH_COMPILER_VAR_148 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_148+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_148+currStrOff, compilerState.currentFile, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_148+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_148+currStrOff, info, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_148+currStrOff, "\n\e[1;37m\t", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_148+currStrOff, str, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_148+currStrOff, "\e[0m\n", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_148+currStrOff, format, strLen_14);
                        currStrOff += strLen_14;
                        
                }
                println(____BAH_COMPILER_VAR_148);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_149 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;33m[WARNING]\e[0m ");
long int strLen_2 = strlen(compilerState.currentFile);
long int strLen_4 = strlen("\n\e[1;37m\t");
long int strLen_6 = strlen(s);
long int strLen_8 = strlen("\e[0m");
;                            
                    ____BAH_COMPILER_VAR_149 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_149+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_149+currStrOff, compilerState.currentFile, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_149+currStrOff, "\n\e[1;37m\t", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_149+currStrOff, s, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_149+currStrOff, "\e[0m", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                println(____BAH_COMPILER_VAR_149);
};
#include <stdlib.h>
char * absPath(char * path){
char * buff = memoryAlloc(4096);
char * p = _fullpath(buff,path,4095);
if (((void *)p!=null)) {
array(char)* arr = strAsArr(p);
long int i = 0;
for (; (i<len(arr)); i = i+1) {

                        if (arr->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: arr[%d] with length %d", i, arr->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/path.bah:23");
                        };
                        char c = arr->data[i];
if ((c==(char)92)) {

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(char));
arr->data = newPtr;
}
arr->data[i] = 47;
arr->length = nLength+1;
} else {
arr->data[i] = 47;
}
};
}
};
}
return p;
};
char * getCurrentPath(){
char * cwd = memoryAlloc(4096);
getcwd(cwd,4096);
return cwd;
};
char isInside(char * basePath,char * subPath){
char * abs1 = absPath(basePath);
char * abs2 = absPath(subPath);
return (strHasPrefix(subPath,basePath)==true);
};
void setCurrentPath(char * s){
chdir(s);
};
char isGlobal(){
return (currentFn==null);
};
struct variable* searchVar(char * name,struct Elems* elems){
char * ogName = name;
struct string n = string(name);
n.replace(&n,"&","");
n.replace(&n,"*","");
if (n.hasSuffix(&n,"]")) {
long int i = n.length;
while ((i>0)) {
char c = n.charAt(&n,i);
if ((c==91)) {
break;
}
i = i-1;
};
long int tamm = n.length-i;
n.trimRight(&n,tamm);
char isArr = (n.hasSuffix(&n,"->data")==1);
if ((isArr==true)) {
n.trimRight(&n,6);
}
name = n.str(&n);
struct variable* v = searchVar(name,elems);
struct string vt = string(v->type);
if ((isArr==true)) {
vt.trimLeft(&vt,2);
}
else {
vt.set(&vt,"char");
}
char * vtstr = vt.str(&vt);
struct variable* ____BAH_COMPILER_VAR_150 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_150->name = "";
____BAH_COMPILER_VAR_150->type = "";
____BAH_COMPILER_VAR_150->isConst = false;
____BAH_COMPILER_VAR_150->constVal = "";
____BAH_COMPILER_VAR_150->isArray = false;
____BAH_COMPILER_VAR_150->from = "";
____BAH_COMPILER_VAR_150->outterScope = false;
____BAH_COMPILER_VAR_150->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_150;
nv->type = vtstr;
nv->name = ogName;
nv->outterScope = v->outterScope;
nv->isArray = isArr;
return nv;
}
name = n.content;
if ((hasStructSep(n)&&(n.count(&n,")")==0))) {
struct string rn = splitStructSepBefore(n);
name = rn.content;
n.trimLeft(&n,rn.length);
if (n.hasPrefix(&n,".")) {
n.trimLeft(&n,1);
}
else {
n.trimLeft(&n,2);
}
char * membs = n.content;
struct variable* v = searchVar(name,elems);
if ((v==null)) {
return null;
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
return null;
}
struct structMemb* memb = searchStructMemb(membs,s,elems);
if ((memb==null)) {
return null;
}
struct variable* ____BAH_COMPILER_VAR_151 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_151->name = "";
____BAH_COMPILER_VAR_151->type = "";
____BAH_COMPILER_VAR_151->isConst = false;
____BAH_COMPILER_VAR_151->constVal = "";
____BAH_COMPILER_VAR_151->isArray = false;
____BAH_COMPILER_VAR_151->from = "";
____BAH_COMPILER_VAR_151->outterScope = false;
____BAH_COMPILER_VAR_151->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_151;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->outterScope = v->outterScope;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (tcc.count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_152 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(r);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_152 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_152+currStrOff, r, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_152+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = ____BAH_COMPILER_VAR_152;
}
long int nbUnaries = tcc.count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = ct.count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_153 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use '*' on ");
long int strLen_4 = strlen(nv->name);
long int strLen_6 = strlen(" because it is not pointer.");
;                            
                    ____BAH_COMPILER_VAR_153 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_153+currStrOff, "Cannot use '*' on ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_153+currStrOff, nv->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_153+currStrOff, " because it is not pointer.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(null,____BAH_COMPILER_VAR_153);
}
ct.trimRight(&ct,nbUnaries);
r = ct.str(&ct);
}
nv->type = r;
nv->name = ogName;
return nv;
}
long int i = len(elems->vars)-1;
for (; (i!=-1); i = i-1) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:106");
                        };
                        struct variable* v = elems->vars->data[i];
if ((strcmp(v->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_154 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_154->name = "";
____BAH_COMPILER_VAR_154->type = "";
____BAH_COMPILER_VAR_154->isConst = false;
____BAH_COMPILER_VAR_154->constVal = "";
____BAH_COMPILER_VAR_154->isArray = false;
____BAH_COMPILER_VAR_154->from = "";
____BAH_COMPILER_VAR_154->outterScope = false;
____BAH_COMPILER_VAR_154->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_154;
nv->type = v->type;
nv->name = v->name;
nv->isConst = v->isConst;
nv->outterScope = v->outterScope;
char * r = nv->type;
struct string tcc = string(ogName);
if (tcc.count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_155 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(r);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_155 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_155+currStrOff, r, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_155+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = ____BAH_COMPILER_VAR_155;
}
long int nbUnaries = tcc.count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = ct.count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_156 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use '*' on ");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(" because it is not pointer.");
;                            
                    ____BAH_COMPILER_VAR_156 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_156+currStrOff, "Cannot use '*' on ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_156+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_156+currStrOff, " because it is not pointer.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(null,____BAH_COMPILER_VAR_156);
}
ct.trimRight(&ct,nbUnaries);
r = ct.str(&ct);
}
nv->type = r;
nv->name = ogName;
return nv;
}
};
i = 0;
for (; (i<len(elems->fns)); i = i+1) {

                        if (elems->fns->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->fns[%d] with length %d", i, elems->fns->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:137");
                        };
                        struct func* fn = elems->fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_157 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_157->name = "";
____BAH_COMPILER_VAR_157->type = "";
____BAH_COMPILER_VAR_157->isConst = false;
____BAH_COMPILER_VAR_157->constVal = "";
____BAH_COMPILER_VAR_157->isArray = false;
____BAH_COMPILER_VAR_157->from = "";
____BAH_COMPILER_VAR_157->outterScope = false;
____BAH_COMPILER_VAR_157->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_157;
nv->name = name;
nv->type = "function(";
long int j = 0;
while ((j<len(fn->args))) {

                        if (fn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", j, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:143");
                        };
                        struct variable* arg = fn->args->data[j];
char * ____BAH_COMPILER_VAR_158 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nv->type);
long int strLen_4 = strlen(arg->type);
;                            
                    ____BAH_COMPILER_VAR_158 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_158+currStrOff, nv->type, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_158+currStrOff, arg->type, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                nv->type = ____BAH_COMPILER_VAR_158;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_159 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nv->type);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_159 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_159+currStrOff, nv->type, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_159+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                nv->type = ____BAH_COMPILER_VAR_159;
}
};
fn->used = true;
char * ____BAH_COMPILER_VAR_160 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nv->type);
long int strLen_4 = strlen(")");
long int strLen_6 = strlen(fn->returns->type);
;                            
                    ____BAH_COMPILER_VAR_160 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_160+currStrOff, nv->type, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_160+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_160+currStrOff, fn->returns->type, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                nv->type = ____BAH_COMPILER_VAR_160;
return nv;
}
};
return null;
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp = getCType(v->type,elems);
char * t = tp.str(&tp);
char * ____BAH_COMPILER_VAR_161 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(t);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(v->name);
;                            
                    ____BAH_COMPILER_VAR_161 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_161+currStrOff, t, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_161+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_161+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                t = ____BAH_COMPILER_VAR_161;
return t;
};
char * getTypeFromToken(struct Tok* t,char strict,struct Elems* elems){
if ((strcmp(t->bahType, "") != 0)) {
char * r = t->bahType;
return r;
}
if ((t->type==TOKEN_TYPE_VAR)) {
struct variable* v = searchVar(t->cont,elems);
if ((v==null)) {
if ((strict==true)) {
throwErr(t,"Unknown var {TOKEN}.");
}
else {
return "";
}
}
if ((strict==true)) {
if ((strcmp(v->type, "") == 0)) {
throwErr(t,"Cannot use {TOKEN} because it does not have any type.");
}
}
t->bahType = v->type;
return v->type;
}
if ((t->type==TOKEN_TYPE_FLOAT)) {
return "float";
}
if ((t->type==TOKEN_TYPE_INT)) {
return "int";
}
if ((t->type==TOKEN_TYPE_STR)) {
return "cpstring";
}
if ((t->type==TOKEN_TYPE_CHAR)) {
return "char";
}
if ((t->type==TOKEN_TYPE_BOOL)) {
return "bool";
}
throwErr(t,"Cannot use {TOKEN} as value.");
return "";
};
struct func* parseFnType(struct string cvt){
struct func* ____BAH_COMPILER_VAR_162 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_162->name = "";
____BAH_COMPILER_VAR_162->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_162->args->length = 0;
            ____BAH_COMPILER_VAR_162->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_162->returns= null;
____BAH_COMPILER_VAR_162->isBinding = false;
____BAH_COMPILER_VAR_162->from = "";
____BAH_COMPILER_VAR_162->file = "";
____BAH_COMPILER_VAR_162->line = 1;
____BAH_COMPILER_VAR_162->used = false;
____BAH_COMPILER_VAR_162->code = null;
struct func* nf = ____BAH_COMPILER_VAR_162;
cvt.trimLeft(&cvt,9);
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);
long int j = 0;
while ((j<cvt.length)) {
char c = cvt.charAt(&cvt,j);
if ((c==41)) {
break;
}
struct variable* ____BAH_COMPILER_VAR_163 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_163->name = "";
____BAH_COMPILER_VAR_163->type = "";
____BAH_COMPILER_VAR_163->isConst = false;
____BAH_COMPILER_VAR_163->constVal = "";
____BAH_COMPILER_VAR_163->isArray = false;
____BAH_COMPILER_VAR_163->from = "";
____BAH_COMPILER_VAR_163->outterScope = false;
____BAH_COMPILER_VAR_163->isGlobal = false;
struct variable* arg = ____BAH_COMPILER_VAR_163;
char * ____BAH_COMPILER_VAR_164 =null;char * ____BAH_COMPILER_VAR_165 =intToStr(len(nf->args));
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("arg_");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_165);
;                            
                    ____BAH_COMPILER_VAR_164 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_164+currStrOff, "arg_", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_164+currStrOff, ____BAH_COMPILER_VAR_165, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                arg->name = ____BAH_COMPILER_VAR_164;
while ((j<cvt.length)) {
c = cvt.charAt(&cvt,j);
if (((c==44)||(c==41))) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
j = j+1;
};
arg->type = arrToStr(memory);
clear(memory);

{
long nLength = len(nf->args);
if (nf->args->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nf->args->data, (nLength+50)*sizeof(struct variable*));
nf->args->data = newPtr;
}
nf->args->data[len(nf->args)] = arg;
nf->args->length = nLength+1;
} else {
nf->args->data[len(nf->args)] = arg;
}
};
if ((c==41)) {
break;
}
j = j+1;
};
j = j+1;
while ((j<cvt.length)) {
char c = cvt.charAt(&cvt,j);

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] = c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = c;
}
};
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_166 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_166->name = "";
____BAH_COMPILER_VAR_166->type = "";
____BAH_COMPILER_VAR_166->isConst = false;
____BAH_COMPILER_VAR_166->constVal = "";
____BAH_COMPILER_VAR_166->isArray = false;
____BAH_COMPILER_VAR_166->from = "";
____BAH_COMPILER_VAR_166->outterScope = false;
____BAH_COMPILER_VAR_166->isGlobal = false;
nf->returns = ____BAH_COMPILER_VAR_166;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_167 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_167->name = "";
____BAH_COMPILER_VAR_167->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_167->args->length = 0;
            ____BAH_COMPILER_VAR_167->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_167->returns= null;
____BAH_COMPILER_VAR_167->isBinding = false;
____BAH_COMPILER_VAR_167->from = "";
____BAH_COMPILER_VAR_167->file = "";
____BAH_COMPILER_VAR_167->line = 1;
____BAH_COMPILER_VAR_167->used = false;
____BAH_COMPILER_VAR_167->code = null;
struct func* fn = ____BAH_COMPILER_VAR_167;
fn->name = "noCheck";
return fn;
}
struct string n = string(name);
if (hasStructSep(n)) {
struct string fnName = splitStructSepAfter(n);
n.trimRight(&n,fnName.length);
char c = n.charAt(&n,n.length-1);
if ((c==46)) {
n.trimRight(&n,1);
}
else {
n.trimRight(&n,2);
}
name = n.str(&n);
struct variable* v = searchVar(name,elems);
struct cStruct* s = searchStruct(v->type,elems);
char * ____BAH_COMPILER_VAR_168 =fnName.str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_168,s,elems);
name = fnName.content;
char * ____BAH_COMPILER_VAR_169 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(memb->from);
long int strLen_4 = strlen("__");
long int strLen_6 = strlen(name);
;                            
                    ____BAH_COMPILER_VAR_169 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_169+currStrOff, memb->from, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_169+currStrOff, "__", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_169+currStrOff, name, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                name = ____BAH_COMPILER_VAR_169;
}
array(struct func*)* fns = elems->fns;
long int i = 0;
while ((i<len(fns))) {

                        if (fns->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: fns[%d] with length %d", i, fns->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:283");
                        };
                        struct func* fn = fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
fn->used = true;
return fn;
}
i = i+1;
};
if ((inclCurr==true)) {
if ((strcmp(currentFn->name, name) == 0)) {
currentFn->used = true;
return currentFn;
}
}
struct variable* v = searchVar(ogName,elems);
if ((v==null)) {
return null;
}
struct func* ____BAH_COMPILER_VAR_170 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_170->name = "";
____BAH_COMPILER_VAR_170->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_170->args->length = 0;
            ____BAH_COMPILER_VAR_170->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_170->returns= null;
____BAH_COMPILER_VAR_170->isBinding = false;
____BAH_COMPILER_VAR_170->from = "";
____BAH_COMPILER_VAR_170->file = "";
____BAH_COMPILER_VAR_170->line = 1;
____BAH_COMPILER_VAR_170->used = false;
____BAH_COMPILER_VAR_170->code = null;
struct func* nf = ____BAH_COMPILER_VAR_170;
nf->name = ogName;
struct string cvt = string(v->type);
if ((cvt.hasPrefix(&cvt,"function(")==0)) {
return null;
}
struct func* pfn = parseFnType(cvt);
nf->returns = pfn->returns;
nf->args = pfn->args;
return nf;
};
char RCPavailable();
char * declareStructMethods(struct variable* v,struct cStruct* s,struct Elems* elems){
char * code = "";
array(struct structMemb*)* members = s->members;
struct string typec = string(v->type);
char * sep = ".";
char * amp = "&";
if (typec.count(&typec,"*")) {
sep = "->";
amp = "";
}
long int i = 0;
while ((i<len(members))) {

                        if (members->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: members[%d] with length %d", i, members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:327");
                        };
                        struct structMemb* m = members->data[i];
struct string cmpt = string(m->type);
char declared = false;
if ((strlen(m->def)>0)) {
char * ____BAH_COMPILER_VAR_171 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(sep);
long int strLen_8 = strlen(m->name);
long int strLen_10 = strlen(" = ");
long int strLen_12 = strlen(m->def);
long int strLen_14 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_171 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, sep, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, m->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, " = ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, m->def, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, ";\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                code = ____BAH_COMPILER_VAR_171;
declared = true;
}
if ((cmpt.hasPrefix(&cmpt,"[]")==1)) {
cmpt.trimLeft(&cmpt,2);
char * cmptstr = cmpt.str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = elemCType.str(&elemCType);
char * ____BAH_COMPILER_VAR_172 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(sep);
long int strLen_8 = strlen(m->name);
long int strLen_10 = strlen(" = memoryAlloc(sizeof(array(");
long int strLen_12 = strlen(elemCTypeStr);
long int strLen_14 = strlen(")));\n            ");
long int strLen_16 = strlen(v->name);
long int strLen_18 = strlen(sep);
long int strLen_20 = strlen(m->name);
long int strLen_22 = strlen("->length = 0;\n            ");
long int strLen_24 = strlen(v->name);
long int strLen_26 = strlen(sep);
long int strLen_28 = strlen(m->name);
long int strLen_30 = strlen("->elemSize = sizeof(");
long int strLen_32 = strlen(elemCTypeStr);
long int strLen_34 = strlen(");\n            ");
;                            
                    ____BAH_COMPILER_VAR_172 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34);
                    
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, sep, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, m->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, " = memoryAlloc(sizeof(array(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, elemCTypeStr, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, ")));\n            ", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, v->name, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, sep, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, m->name, strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, "->length = 0;\n            ", strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, v->name, strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, sep, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, m->name, strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, "->elemSize = sizeof(", strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, elemCTypeStr, strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, ");\n            ", strLen_34);
                        currStrOff += strLen_34;
                        
                }
                code = ____BAH_COMPILER_VAR_172;
declared = true;
}
else if ((cmpt.hasPrefix(&cmpt,"map:")==1)) {
cmpt.trimLeft(&cmpt,4);
char * ____BAH_COMPILER_VAR_173 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen(m->name);
long int strLen_8 = strlen(" = mapWrapper();\n");
;                            
                    ____BAH_COMPILER_VAR_173 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_173+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_173+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_173+currStrOff, m->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_173+currStrOff, " = mapWrapper();\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                char * ____BAH_COMPILER_VAR_174 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_173);
;                            
                    ____BAH_COMPILER_VAR_174 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, ____BAH_COMPILER_VAR_173, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                code = ____BAH_COMPILER_VAR_174;
declared = true;
}
else if ((cmpt.hasPrefix(&cmpt,"chan:")==1)) {
cmpt.trimLeft(&cmpt,5);
char * ____BAH_COMPILER_VAR_175 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen(m->name);
long int strLen_8 = strlen(" = channel();\n");
;                            
                    ____BAH_COMPILER_VAR_175 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, m->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, " = channel();\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                char * ____BAH_COMPILER_VAR_176 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_175);
;                            
                    ____BAH_COMPILER_VAR_176 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_176+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_176+currStrOff, ____BAH_COMPILER_VAR_175, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                code = ____BAH_COMPILER_VAR_176;
declared = true;
}
if ((isRCPpointerType(m->type)&&(declared==false))) {
char * ____BAH_COMPILER_VAR_177 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(sep);
long int strLen_8 = strlen(m->name);
long int strLen_10 = strlen("= null;\n");
;                            
                    ____BAH_COMPILER_VAR_177 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_177+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_177+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_177+currStrOff, sep, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_177+currStrOff, m->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_177+currStrOff, "= null;\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                code = ____BAH_COMPILER_VAR_177;
}
i = i+1;
};
if ((strlen(s->extendedFrom)>0)) {
struct cStruct* es = searchStruct(s->extendedFrom,elems);
i = 0;
while ((i<len(es->methods))) {

                        if (es->methods->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: es->methods[%d] with length %d", i, es->methods->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:364");
                        };
                        struct func* m = es->methods->data[i];
char * ____BAH_COMPILER_VAR_178 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(sep);
long int strLen_8 = strlen(m->name);
long int strLen_10 = strlen(" = ");
long int strLen_12 = strlen(es->name);
long int strLen_14 = strlen("__");
long int strLen_16 = strlen(m->name);
long int strLen_18 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_178 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18);
                    
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, sep, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, m->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, " = ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, es->name, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, "__", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, m->name, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, ";\n", strLen_18);
                        currStrOff += strLen_18;
                        
                }
                code = ____BAH_COMPILER_VAR_178;
i = i+1;
};
}
array(struct func*)* methods = s->methods;
i = 0;
while ((i<len(methods))) {

                        if (methods->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: methods[%d] with length %d", i, methods->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:372");
                        };
                        struct func* m = methods->data[i];
char * ____BAH_COMPILER_VAR_179 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(sep);
long int strLen_8 = strlen(m->name);
long int strLen_10 = strlen(" = ");
long int strLen_12 = strlen(s->name);
long int strLen_14 = strlen("__");
long int strLen_16 = strlen(m->name);
long int strLen_18 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_179 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18);
                    
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, sep, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, m->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, " = ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, s->name, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, "__", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, m->name, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, ";\n", strLen_18);
                        currStrOff += strLen_18;
                        
                }
                code = ____BAH_COMPILER_VAR_179;
i = i+1;
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); i = i+1) {

                        if (s->methods->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: s->methods[%d] with length %d", i, s->methods->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:388");
                        };
                        struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char * ____BAH_COMPILER_VAR_180 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen(m->name);
long int strLen_8 = strlen("(");
long int strLen_10 = strlen(amp);
long int strLen_12 = strlen(v->name);
long int strLen_14 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_180 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_180+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_180+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_180+currStrOff, m->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_180+currStrOff, "(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_180+currStrOff, amp, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_180+currStrOff, v->name, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_180+currStrOff, ");\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                char * ____BAH_COMPILER_VAR_181 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(NEXT_LINE);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_180);
;                            
                    ____BAH_COMPILER_VAR_181 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_181+currStrOff, NEXT_LINE, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_181+currStrOff, ____BAH_COMPILER_VAR_180, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_181;
found = found+1;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char * ____BAH_COMPILER_VAR_182 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("memoryOnEnd(");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen(v->name);
long int strLen_10 = strlen(sep);
long int strLen_12 = strlen(m->name);
long int strLen_14 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_182 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_182+currStrOff, "memoryOnEnd(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_182+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_182+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_182+currStrOff, v->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_182+currStrOff, sep, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_182+currStrOff, m->name, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_182+currStrOff, ");\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                char * ____BAH_COMPILER_VAR_183 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_182);
;                            
                    ____BAH_COMPILER_VAR_183 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_183+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_183+currStrOff, ____BAH_COMPILER_VAR_182, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                code = ____BAH_COMPILER_VAR_183;
}
found = found+1;
}
if ((found==2)) {
break;
}
};
}
return code;
};
long int NB_COMP_VAR;
char * genCompilerVar(){
char * ____BAH_COMPILER_VAR_184 =null;char * ____BAH_COMPILER_VAR_185 =intToStr(NB_COMP_VAR);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("____BAH_COMPILER_VAR_");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_185);
;                            
                    ____BAH_COMPILER_VAR_184 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_184+currStrOff, "____BAH_COMPILER_VAR_", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_184+currStrOff, ____BAH_COMPILER_VAR_185, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * name = ____BAH_COMPILER_VAR_184;
NB_COMP_VAR = NB_COMP_VAR+1;
return name;
};
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
char varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){
if ((arr==null)) {
return false;
}
long int j = 0;
while ((j<len(arr))) {

                        if (arr->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: arr[%d] with length %d", j, arr->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:420");
                        };
                        struct variable* ev = arr->data[j];
if ((strcmp(ev->name, v->name) == 0)) {
return true;
}
j = j+1;
};
return false;
};
char * pathToVarName(char * p){
array(char)* a = strToArr(p);
long int i = 0;
for (; (i<len(a)); i = i+1) {

                        if (a->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: a[%d] with length %d", i, a->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:432");
                        };
                        long int c = a->data[i];
c = c-(long int)97;
if ((c<0)) {
c = 0-c;
}
c = c%((long int)122-(long int)97);
c = c+(long int)97;

{
long nLength = i;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[i] = (char)c;
a->length = nLength+1;
} else {
a->data[i] = (char)c;
}
};
};
return arrToStr(a);
};
void makeInit(){
char * name = "__BAH_init";
if ((isObject==true)) {
char * ____BAH_COMPILER_VAR_186 =null;char * ____BAH_COMPILER_VAR_187 =pathToVarName(compilerState.currentFile);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(name);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_187);
;                            
                    ____BAH_COMPILER_VAR_186 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_186+currStrOff, name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_186+currStrOff, ____BAH_COMPILER_VAR_187, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                name = ____BAH_COMPILER_VAR_186;
}
char * evals = "";
char * ____BAH_COMPILER_VAR_188 =null;char * ____BAH_COMPILER_VAR_189 =intToStr(len(compilerState.evals));
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_189);
long int strLen_6 = strlen("] = {");
;                            
                    ____BAH_COMPILER_VAR_188 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_188+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_188+currStrOff, ____BAH_COMPILER_VAR_189, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_188+currStrOff, "] = {", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * evalsTMPDecl = ____BAH_COMPILER_VAR_188;
long int i = 0;
for (; (i<len(compilerState.evals)); i = i+1) {

                        if (compilerState.evals->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: compilerState.evals[%d] with length %d", i, compilerState.evals->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:453");
                        };
                        char * e = compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_190 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("{\n            .name = \"");
long int strLen_4 = strlen(e);
long int strLen_6 = strlen("\",\n            .evalFn = __Bah_eval_");
long int strLen_8 = strlen(e);
long int strLen_10 = strlen("\n        }");
;                            
                    ____BAH_COMPILER_VAR_190 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_190+currStrOff, "{\n            .name = \"", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_190+currStrOff, e, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_190+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_190+currStrOff, e, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_190+currStrOff, "\n        }", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * ____BAH_COMPILER_VAR_191 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_190);
;                            
                    ____BAH_COMPILER_VAR_191 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_191+currStrOff, evalsTMPDecl, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_191+currStrOff, ____BAH_COMPILER_VAR_190, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                evalsTMPDecl = ____BAH_COMPILER_VAR_191;
if ((i+1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_192 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_2 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_192 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_192+currStrOff, evalsTMPDecl, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_192+currStrOff, ",\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                evalsTMPDecl = ____BAH_COMPILER_VAR_192;
}
else {
char * ____BAH_COMPILER_VAR_193 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_2 = strlen("};");
;                            
                    ____BAH_COMPILER_VAR_193 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_193+currStrOff, evalsTMPDecl, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_193+currStrOff, "};", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                evalsTMPDecl = ____BAH_COMPILER_VAR_193;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_194 =null;char * ____BAH_COMPILER_VAR_195 =intToStr(len(compilerState.evals));
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_195);
long int strLen_6 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_194 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_194+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_194+currStrOff, ____BAH_COMPILER_VAR_195, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_194+currStrOff, ";", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                evals = ____BAH_COMPILER_VAR_194;
}
else {
evalsTMPDecl = "";
}
char * ____BAH_COMPILER_VAR_196 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    ");
long int strLen_2 = strlen(evalsTMPDecl);
long int strLen_4 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
long int strLen_6 = strlen(name);
long int strLen_8 = strlen("() {\n        ");
;                            
                    ____BAH_COMPILER_VAR_196 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_196+currStrOff, "\n    ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_196+currStrOff, evalsTMPDecl, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_196+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_196+currStrOff, name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_196+currStrOff, "() {\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                char * ____BAH_COMPILER_VAR_197 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        ");
long int strLen_2 = strlen(evals);
long int strLen_4 = strlen("\n    };\n    ");
;                            
                    ____BAH_COMPILER_VAR_197 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_197+currStrOff, "\n        ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_197+currStrOff, evals, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_197+currStrOff, "\n    };\n    ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_196)->add(rope(____BAH_COMPILER_VAR_196), INIT)->add(rope(____BAH_COMPILER_VAR_196)->add(rope(____BAH_COMPILER_VAR_196), INIT), rope(____BAH_COMPILER_VAR_197)));
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r = rope("");
if (strHasPrefix(v->type,"[]")) {
char * ____BAH_COMPILER_VAR_198 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_decr(");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_198 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_198+currStrOff, "RCP_decr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_198+currStrOff, ");\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_198));
}
else if (strHasPrefix(v->type,"chan:")) {
char * ____BAH_COMPILER_VAR_199 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("{\n            struct RCP * chanRCP = RCP_request(");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(");\n            if (chanRCP != null && chanRCP->c == 1) {\n                ");
long int strLen_6 = strlen(v->name);
long int strLen_8 = strlen("->destroy(");
long int strLen_10 = strlen(v->name);
long int strLen_12 = strlen(");\n                RCP_decr(");
long int strLen_14 = strlen(v->name);
long int strLen_16 = strlen("->queue);\n            };\n            RCP_decrRCP(chanRCP);\n        };");
;                            
                    ____BAH_COMPILER_VAR_199 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, "{\n            struct RCP * chanRCP = RCP_request(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, ");\n            if (chanRCP != null && chanRCP->c == 1) {\n                ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, "->destroy(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, ");\n                RCP_decr(", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, "->queue);\n            };\n            RCP_decrRCP(chanRCP);\n        };", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                r = rope(____BAH_COMPILER_VAR_199);
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_200 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_200->name = "";
____BAH_COMPILER_VAR_200->type = "";
____BAH_COMPILER_VAR_200->isConst = false;
____BAH_COMPILER_VAR_200->constVal = "";
____BAH_COMPILER_VAR_200->isArray = false;
____BAH_COMPILER_VAR_200->from = "";
____BAH_COMPILER_VAR_200->outterScope = false;
____BAH_COMPILER_VAR_200->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_200;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if (((s!=null)&&(s->isBinding==false))) {
if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_201 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_decr(");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_201 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_201+currStrOff, "RCP_decr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_201+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_201+currStrOff, ");\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_201));
}
else {
char * ____BAH_COMPILER_VAR_202 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_scanStack(&");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(", sizeof(");
long int strLen_6 = strlen(v->name);
long int strLen_8 = strlen("), 1);\n");
;                            
                    ____BAH_COMPILER_VAR_202 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_202+currStrOff, "RCP_scanStack(&", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_202+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_202+currStrOff, ", sizeof(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_202+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_202+currStrOff, "), 1);\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_202));
}
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_203 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_decr(");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_203 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_203+currStrOff, "RCP_decr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_203+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_203+currStrOff, ");\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_203));
}
}
return r;
};
struct rope* incrVar(struct variable* v,struct Elems* elems){
if ((strCount(v->name,"*")>0)) {
return rope("");
}
struct cStruct* s = searchStruct(v->type,elems);
if ((((s!=null)&&(isRCPpointerType(v->type)==false))&&(s->isBinding==false))) {
char * ____BAH_COMPILER_VAR_204 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_scanStack(&");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(", sizeof(");
long int strLen_6 = strlen(v->name);
long int strLen_8 = strlen("), 0);");
;                            
                    ____BAH_COMPILER_VAR_204 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_204+currStrOff, "RCP_scanStack(&", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_204+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_204+currStrOff, ", sizeof(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_204+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_204+currStrOff, "), 0);", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                return rope(____BAH_COMPILER_VAR_204);
}
char * ____BAH_COMPILER_VAR_205 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_incr(");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(");");
;                            
                    ____BAH_COMPILER_VAR_205 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_205+currStrOff, "RCP_incr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_205+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_205+currStrOff, ");", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                return rope(____BAH_COMPILER_VAR_205);
};
char RCPavailable(){
char * ____BAH_COMPILER_VAR_206 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_2 = strlen("rcp.bah");
;                            
                    ____BAH_COMPILER_VAR_206 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_206+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_206+currStrOff, "rcp.bah", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                char * ____BAH_COMPILER_VAR_207 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_2 = strlen("fastrcp.bah");
;                            
                    ____BAH_COMPILER_VAR_207 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_207+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_207+currStrOff, "fastrcp.bah", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                return (((strcmp(absPath(compilerState.currentFile), absPath(____BAH_COMPILER_VAR_206)) != 0)&&(strcmp(absPath(compilerState.currentFile), absPath(____BAH_COMPILER_VAR_207)) != 0))&&(RCPenabled==true));
};
void beginRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
if ((RCPavailable()==false)) {
return;
}
long int i = 0;
for (; (i<len(elems->vars)); i = i+1) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:63");
                        };
                        struct variable* v = elems->vars->data[i];
if (varInArr(v,excl)) {
continue;
}
if (((v->isGlobal==false)&&isRCPtype(v->type,elems))) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(v,elems));
}
};
};
void beginRCPscopeLeaky(struct Elems* elems){
if ((RCPavailable()==false)) {
return;
}
long int i = 0;
for (; (i<len(elems->vars)); i = i+1) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:78");
                        };
                        struct variable* v = elems->vars->data[i];
if ((((v->isGlobal==false)&&(v->outterScope==false))&&isRCPtype(v->type,elems))) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(v,elems));
}
};
};
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
if ((RCPavailable()==false)) {
return;
}
long int i = 0;
for (; (i<len(elems->vars)); i = i+1) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:90");
                        };
                        struct variable* v = elems->vars->data[i];
if (varInArr(v,excl)) {
continue;
}
if (((v->isGlobal==false)&&isRCPtype(v->type,elems))) {
OUTPUT = OUTPUT->add(OUTPUT, decrVar(v,elems));
}
};
};
void endRCPscopeLeaky(struct Elems* elems,struct variable* excl){
if ((RCPavailable()==false)) {
return;
}
long int i = 0;
for (; (i<len(elems->vars)); i = i+1) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:105");
                        };
                        struct variable* v = elems->vars->data[i];
if (((excl!=null)&&(strcmp(excl->name, v->name) == 0))) {
continue;
}
if ((((v->isGlobal==false)&&(v->outterScope==false))&&isRCPtype(v->type,elems))) {
OUTPUT = OUTPUT->add(OUTPUT, decrVar(v,elems));
}
};
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* ____BAH_COMPILER_VAR_208 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_208->name = "";
____BAH_COMPILER_VAR_208->type = "";
____BAH_COMPILER_VAR_208->isConst = false;
____BAH_COMPILER_VAR_208->constVal = "";
____BAH_COMPILER_VAR_208->isArray = false;
____BAH_COMPILER_VAR_208->from = "";
____BAH_COMPILER_VAR_208->outterScope = false;
____BAH_COMPILER_VAR_208->isGlobal = false;
struct variable* av = ____BAH_COMPILER_VAR_208;
av->type = t;
av->name = genCompilerVar();

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = av;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = av;
}
};
struct string cType = getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_209 =null;char * ____BAH_COMPILER_VAR_210 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_210);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(av->name);
long int strLen_6 = strlen(" =");
long int strLen_8 = strlen(c);
long int strLen_10 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_209 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_209+currStrOff, ____BAH_COMPILER_VAR_210, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_209+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_209+currStrOff, av->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_209+currStrOff, " =", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_209+currStrOff, c, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_209+currStrOff, ";", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_209));
return av->name;
};
char RCPselfRef(struct variable* v){
long int i = 0;
while ((i<len(compilerState.RCPvars))) {

                        if (compilerState.RCPvars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: compilerState.RCPvars[%d] with length %d", i, compilerState.RCPvars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:315");
                        };
                        struct variable* r = compilerState.RCPvars->data[i];
if ((strcmp(r->name, v->name) == 0)) {
return true;
}
i = i+1;
};
return false;
};
#define ASCII_RESET "\\033[0m"
#define ASCII_YELLOW "\\033[33m"
#define ASCII_BLUE "\\033[36m"
#define ASCII_GREEN "\\033[32m"
#define ASCII_MAGENTA "\\033[35m"
#define ASCII_GREY "\\033[2m"
struct verboseOutVar {
char * markup;
char * content;
};
array(char *)* noVOfns;
char verboseOutGuard(){
if ((currentFn!=null)) {

                int ____BAH_COMPILER_VAR_211 = 0;
                for(int i=len(noVOfns)-1; i != -1; i--) {
                    if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                        ____BAH_COMPILER_VAR_211 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_211) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_212 = {};
____BAH_COMPILER_VAR_212.markup= null;
____BAH_COMPILER_VAR_212.content= null;
#define rv ____BAH_COMPILER_VAR_212
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_213 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__Bah_safe_string(");
long int strLen_4 = strlen(cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_213 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_213+currStrOff, "__Bah_safe_string(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_213+currStrOff, cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_213+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                cont = ____BAH_COMPILER_VAR_213;
}
char * ____BAH_COMPILER_VAR_214 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(", ");
long int strLen_4 = strlen(cont);
;                            
                    ____BAH_COMPILER_VAR_214 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_214+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_214+currStrOff, cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                cont = ____BAH_COMPILER_VAR_214;
char * ct = "";
if ((strcmp(v->type, "cpstring") == 0)) {
ct = "%s";
}
else if ((strcmp(v->type, "int") == 0)) {
ct = "%li";
}
else if ((strcmp(v->type, "float") == 0)) {
ct = "%d";
}
else if ((isRCPpointerType(v->type)==true)) {
ct = "%p";
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
ct = "%li";
}
else {
char * ____BAH_COMPILER_VAR_215 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ASCII_RESET);
long int strLen_4 = strlen("{");
;                            
                    ____BAH_COMPILER_VAR_215 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_215+currStrOff, ASCII_RESET, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_215+currStrOff, "{", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ct = ____BAH_COMPILER_VAR_215;
cont = "";
long int i = 0;
for (; (i<len(s->members)); i = i+1) {

                        if (s->members->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: s->members[%d] with length %d", i, s->members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/verboseOut.bah:53");
                        };
                        struct variable* m = s->members->data[i];
char * ____BAH_COMPILER_VAR_216 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(ogCont);
long int strLen_6 = strlen(")");
long int strLen_8 = strlen(".");
long int strLen_10 = strlen(m->name);
;                            
                    ____BAH_COMPILER_VAR_216 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_216+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_216+currStrOff, ogCont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_216+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_216+currStrOff, ".", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_216+currStrOff, m->name, strLen_10);
                        currStrOff += strLen_10;
                        
                }
                struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_216,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_217 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ct);
long int strLen_4 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_217 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_217+currStrOff, ct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_217+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ct = ____BAH_COMPILER_VAR_217;
}
char * ____BAH_COMPILER_VAR_218 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ct);
long int strLen_4 = strlen(mv.markup);
;                            
                    ____BAH_COMPILER_VAR_218 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_218+currStrOff, ct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_218+currStrOff, mv.markup, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ct = ____BAH_COMPILER_VAR_218;
char * ____BAH_COMPILER_VAR_219 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(cont);
long int strLen_4 = strlen(mv.content);
;                            
                    ____BAH_COMPILER_VAR_219 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_219+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_219+currStrOff, mv.content, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                cont = ____BAH_COMPILER_VAR_219;
};
char * ____BAH_COMPILER_VAR_220 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ct);
long int strLen_4 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_220 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_220+currStrOff, ct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_220+currStrOff, "}", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ct = ____BAH_COMPILER_VAR_220;
}
}
char * ____BAH_COMPILER_VAR_221 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ASCII_BLUE);
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(ASCII_RESET);
long int strLen_8 = strlen(" = ");
long int strLen_10 = strlen(ASCII_MAGENTA);
long int strLen_12 = strlen(ct);
long int strLen_14 = strlen(ASCII_RESET);
;                            
                    ____BAH_COMPILER_VAR_221 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_221+currStrOff, ASCII_BLUE, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_221+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_221+currStrOff, ASCII_RESET, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_221+currStrOff, " = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_221+currStrOff, ASCII_MAGENTA, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_221+currStrOff, ct, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_221+currStrOff, ASCII_RESET, strLen_14);
                        currStrOff += strLen_14;
                        
                }
                rv.markup = ____BAH_COMPILER_VAR_221;
rv.content = cont;
return rv;
};
struct verboseOutVar verboseOutTransformTok(struct Tok t,struct Elems* elems){
if (((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false))) {
struct variable* v = searchVar(t.cont,elems);
if ((v==null)) {
return verboseOutTransformVar(v,t.cont,elems);
}
}
struct variable ____BAH_COMPILER_VAR_222 = {};
____BAH_COMPILER_VAR_222.name = "";
____BAH_COMPILER_VAR_222.type = "";
____BAH_COMPILER_VAR_222.isConst = false;
____BAH_COMPILER_VAR_222.constVal = "";
____BAH_COMPILER_VAR_222.isArray = false;
____BAH_COMPILER_VAR_222.from = "";
____BAH_COMPILER_VAR_222.outterScope = false;
____BAH_COMPILER_VAR_222.isGlobal = false;
____BAH_COMPILER_VAR_222.name = "(value)";
____BAH_COMPILER_VAR_222.type = getTypeFromToken(&t,true,elems);
#define v ____BAH_COMPILER_VAR_222
return verboseOutTransformVar(&v,t.cont,elems);
};
void verboseOutFunc(struct func* fn,__BAH_ARR_TYPE_Tok args,long int lineNb,struct Elems* elems){
if ((verboseOutGuard()==false)) {
return;
}
char * nameColor = ASCII_YELLOW;
if ((fn->isBinding==true)) {
if (strHasPrefix(compilerState.currentFile,BAH_DIR)) {
return;
}
nameColor = ASCII_GREY;
}
if (strHasPrefix(fn->file,BAH_DIR)) {
char hasPtr = false;
long int i = 0;
for (; (i<len(fn->args)); i = i+1) {

                        if (fn->args->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", i, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/verboseOut.bah:101");
                        };
                        struct variable* a = fn->args->data[i];
if ((isRCPpointerType(a->type)==true)) {
hasPtr = true;
break;
}
};
if ((hasPtr==false)) {
return;
}
}
char * fnArgs = "";
char * fnArgsValues = "";
long int j = 0;
for (; (j<len(fn->args)); j = j+1) {

                        if (fn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", j, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/verboseOut.bah:115");
                        };
                        struct variable* a = fn->args->data[j];
if ((j!=0)) {
char * ____BAH_COMPILER_VAR_223 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnArgs);
long int strLen_4 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_223 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_223+currStrOff, fnArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_223+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fnArgs = ____BAH_COMPILER_VAR_223;
}

                        if (args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: args[%d] with length %d", j, args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/verboseOut.bah:120");
                        };
                        struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_224 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnArgs);
long int strLen_4 = strlen(v.markup);
;                            
                    ____BAH_COMPILER_VAR_224 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_224+currStrOff, fnArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_224+currStrOff, v.markup, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fnArgs = ____BAH_COMPILER_VAR_224;
char * ____BAH_COMPILER_VAR_225 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnArgsValues);
long int strLen_4 = strlen(v.content);
;                            
                    ____BAH_COMPILER_VAR_225 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_225+currStrOff, fnArgsValues, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_225+currStrOff, v.content, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fnArgsValues = ____BAH_COMPILER_VAR_225;
};
char * ____BAH_COMPILER_VAR_226 =null;char * ____BAH_COMPILER_VAR_227 =intToStr(lineNb);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_227);
;                            
                    ____BAH_COMPILER_VAR_226 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_226+currStrOff, compilerState.currentFile, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_226+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_226+currStrOff, ____BAH_COMPILER_VAR_227, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * line = ____BAH_COMPILER_VAR_226;
char * ____BAH_COMPILER_VAR_228 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    //Verbose Runtime\n        printf(\"[VO] calling: ");
long int strLen_2 = strlen(nameColor);
long int strLen_4 = strlen(fn->name);
long int strLen_6 = strlen(ASCII_RESET);
long int strLen_8 = strlen("(");
long int strLen_10 = strlen(fnArgs);
long int strLen_12 = strlen(") -> ");
long int strLen_14 = strlen(ASCII_GREEN);
long int strLen_16 = strlen(line);
long int strLen_18 = strlen(ASCII_RESET);
long int strLen_20 = strlen("\\n\"");
long int strLen_22 = strlen(fnArgsValues);
long int strLen_24 = strlen(");\n    //\n    ");
;                            
                    ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24);
                    
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, nameColor, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, fn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, ASCII_RESET, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, "(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, fnArgs, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, ") -> ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, ASCII_GREEN, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, line, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, ASCII_RESET, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, "\\n\"", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, fnArgsValues, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, ");\n    //\n    ", strLen_24);
                        currStrOff += strLen_24;
                        
                }
                struct rope* verboseOut = rope(____BAH_COMPILER_VAR_228);
if (isGlobal()) {
INIT = INIT->add(INIT, verboseOut);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, verboseOut);
}
};
void verboseOutOper(struct Tok pt,struct Tok nt,long int lineNb,struct Elems* elems){
if ((verboseOutGuard()==false)) {
return;
}
struct verboseOutVar pvo = verboseOutTransformTok(pt,elems);
struct verboseOutVar nvo = verboseOutTransformTok(nt,elems);
char * ____BAH_COMPILER_VAR_229 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pvo.content);
long int strLen_4 = strlen(nvo.content);
;                            
                    ____BAH_COMPILER_VAR_229 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_229+currStrOff, pvo.content, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_229+currStrOff, nvo.content, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * values = ____BAH_COMPILER_VAR_229;
char * ____BAH_COMPILER_VAR_230 =null;char * ____BAH_COMPILER_VAR_231 =intToStr(lineNb);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_231);
;                            
                    ____BAH_COMPILER_VAR_230 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_230+currStrOff, compilerState.currentFile, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_230+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_230+currStrOff, ____BAH_COMPILER_VAR_231, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * line = ____BAH_COMPILER_VAR_230;
char * ____BAH_COMPILER_VAR_232 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    //Verbose Runtime\n        printf(\"[VO]    oper: ");
long int strLen_2 = strlen(pvo.markup);
long int strLen_4 = strlen(" AND ");
long int strLen_6 = strlen(nvo.markup);
long int strLen_8 = strlen(" -> ");
long int strLen_10 = strlen(ASCII_GREEN);
long int strLen_12 = strlen(line);
long int strLen_14 = strlen(ASCII_RESET);
long int strLen_16 = strlen("\\n\"");
long int strLen_18 = strlen(values);
long int strLen_20 = strlen(");\n    //\n    ");
;                            
                    ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20);
                    
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, pvo.markup, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, " AND ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, nvo.markup, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, " -> ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, ASCII_GREEN, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, line, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, ASCII_RESET, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, "\\n\"", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, values, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, ");\n    //\n    ", strLen_20);
                        currStrOff += strLen_20;
                        
                }
                struct rope* verboseOut = rope(____BAH_COMPILER_VAR_232);
if (isGlobal()) {
INIT = INIT->add(INIT, verboseOut);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, verboseOut);
}
};
struct cacheFile {
char * file;
long int last;
char * ver;
long int date;
long int mem;
array(char *)* files;
};
array(struct cacheFile*)* cache;
void readCache(){
struct fileStream ____BAH_COMPILER_VAR_233 = {};
____BAH_COMPILER_VAR_233.handle= null;
____BAH_COMPILER_VAR_233.name= null;
____BAH_COMPILER_VAR_233.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_233.open = fileStream__open;
____BAH_COMPILER_VAR_233.close = fileStream__close;
____BAH_COMPILER_VAR_233.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_233.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_233.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_233.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_233.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_233.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_233.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_233.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_233.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_233.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_233.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_233.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_233.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_233._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_233
char * ____BAH_COMPILER_VAR_234 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_234 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_234+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_234+currStrOff, "cache/cache.json", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fs.open(&fs,____BAH_COMPILER_VAR_234,"r");
if ((fs.isValid(&fs)==0)) {
char * ____BAH_COMPILER_VAR_235 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_2 = strlen("cache");
;                            
                    ____BAH_COMPILER_VAR_235 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, "cache", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                mkdir(____BAH_COMPILER_VAR_235,S_IRWXU);
char * ____BAH_COMPILER_VAR_236 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_236 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_236+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_236+currStrOff, "cache/cache.json", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fs.createFile(&fs,____BAH_COMPILER_VAR_236);
return;
}
char * ____BAH_COMPILER_VAR_237 =fs.readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_237);
fs.close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_238 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_239 = 0;
char ** ____BAH_COMPILER_VAR_241 = (char **)((char*)(____BAH_COMPILER_VAR_239) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_242 = __reflect(____BAH_COMPILER_VAR_241, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_243 = (long int*)((char*)(____BAH_COMPILER_VAR_239) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_244 = __reflect(____BAH_COMPILER_VAR_243, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_245 = (char **)((char*)(____BAH_COMPILER_VAR_239) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_246 = __reflect(____BAH_COMPILER_VAR_245, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_247 = (long int*)((char*)(____BAH_COMPILER_VAR_239) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_248 = __reflect(____BAH_COMPILER_VAR_247, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_249 = (long int*)((char*)(____BAH_COMPILER_VAR_239) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_250 = __reflect(____BAH_COMPILER_VAR_249, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_251 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_239) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_252 = 0;
struct reflectElement ____BAH_COMPILER_VAR_253 = __reflect(____BAH_COMPILER_VAR_252, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_254 = ____BAH_COMPILER_VAR_253;
        struct reflectElement ____BAH_COMPILER_VAR_255 = __reflect(____BAH_COMPILER_VAR_251, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_254, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_240 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_240->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_240->length = 6;
        ____BAH_COMPILER_VAR_240->data = memoryAlloc(____BAH_COMPILER_VAR_240->length * ____BAH_COMPILER_VAR_240->elemSize);
        ____BAH_COMPILER_VAR_240->data[0] = ____BAH_COMPILER_VAR_242;
____BAH_COMPILER_VAR_240->data[1] = ____BAH_COMPILER_VAR_244;
____BAH_COMPILER_VAR_240->data[2] = ____BAH_COMPILER_VAR_246;
____BAH_COMPILER_VAR_240->data[3] = ____BAH_COMPILER_VAR_248;
____BAH_COMPILER_VAR_240->data[4] = ____BAH_COMPILER_VAR_250;
____BAH_COMPILER_VAR_240->data[5] = ____BAH_COMPILER_VAR_255;
struct reflectElement ____BAH_COMPILER_VAR_256 = __reflect(____BAH_COMPILER_VAR_239, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_240, 0);

        struct reflectElement ____BAH_COMPILER_VAR_257 = ____BAH_COMPILER_VAR_256;
        struct reflectElement ____BAH_COMPILER_VAR_258 = __reflect(____BAH_COMPILER_VAR_238, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_257, 0, 0, 0);
j->scan(j,____BAH_COMPILER_VAR_258);
if ((cache!=null)) {
}
};
struct cacheFile* getCacheFile(char * s){
if ((cache==null)) {
return null;
}
long int i = 0;
for (; (i<len(cache)); i = i+1) {

                        if (cache->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: cache[%d] with length %d", i, cache->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/cache.bah:44");
                        };
                        struct cacheFile* c = cache->data[i];
if (((strcmp(c->file, s) == 0)&&(c->mem==RCPlevel))) {
return c;
}
};
return null;
};
void updateCacheFile(struct cacheFile* c){
c->last = getLastModified(c->file);
c->ver = BAH_VERSION;
c->date = getTimeUnix();
};
void makeCacheFile(char * f){
struct cacheFile* ____BAH_COMPILER_VAR_259 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_259->file= null;
____BAH_COMPILER_VAR_259->ver= null;
____BAH_COMPILER_VAR_259->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_259->files->length = 0;
            ____BAH_COMPILER_VAR_259->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_259;
c->file = f;
c->ver = BAH_VERSION;
c->mem = RCPlevel;
c->date = getTimeUnix();
c->last = getLastModified(f);
if ((cache==null)) {
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
}

{
long nLength = len(cache);
if (cache->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(cache->data, (nLength+50)*sizeof(struct cacheFile*));
cache->data = newPtr;
}
cache->data[len(cache)] = c;
cache->length = nLength+1;
} else {
cache->data[len(cache)] = c;
}
};
};
void writeCache(){
struct fileStream ____BAH_COMPILER_VAR_260 = {};
____BAH_COMPILER_VAR_260.handle= null;
____BAH_COMPILER_VAR_260.name= null;
____BAH_COMPILER_VAR_260.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_260.open = fileStream__open;
____BAH_COMPILER_VAR_260.close = fileStream__close;
____BAH_COMPILER_VAR_260.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_260.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_260.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_260.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_260.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_260.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_260.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_260.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_260.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_260.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_260.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_260.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_260.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_260._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_260
char * ____BAH_COMPILER_VAR_261 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_261 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_261+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_261+currStrOff, "cache/cache.json", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fs.open(&fs,____BAH_COMPILER_VAR_261,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_262 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_263 = 0;
char ** ____BAH_COMPILER_VAR_265 = (char **)((char*)(____BAH_COMPILER_VAR_263) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_266 = __reflect(____BAH_COMPILER_VAR_265, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_267 = (long int*)((char*)(____BAH_COMPILER_VAR_263) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_268 = __reflect(____BAH_COMPILER_VAR_267, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_269 = (char **)((char*)(____BAH_COMPILER_VAR_263) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_270 = __reflect(____BAH_COMPILER_VAR_269, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_271 = (long int*)((char*)(____BAH_COMPILER_VAR_263) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_272 = __reflect(____BAH_COMPILER_VAR_271, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_273 = (long int*)((char*)(____BAH_COMPILER_VAR_263) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_274 = __reflect(____BAH_COMPILER_VAR_273, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_275 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_263) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_276 = 0;
struct reflectElement ____BAH_COMPILER_VAR_277 = __reflect(____BAH_COMPILER_VAR_276, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_278 = ____BAH_COMPILER_VAR_277;
        struct reflectElement ____BAH_COMPILER_VAR_279 = __reflect(____BAH_COMPILER_VAR_275, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_278, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_264 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_264->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_264->length = 6;
        ____BAH_COMPILER_VAR_264->data = memoryAlloc(____BAH_COMPILER_VAR_264->length * ____BAH_COMPILER_VAR_264->elemSize);
        ____BAH_COMPILER_VAR_264->data[0] = ____BAH_COMPILER_VAR_266;
____BAH_COMPILER_VAR_264->data[1] = ____BAH_COMPILER_VAR_268;
____BAH_COMPILER_VAR_264->data[2] = ____BAH_COMPILER_VAR_270;
____BAH_COMPILER_VAR_264->data[3] = ____BAH_COMPILER_VAR_272;
____BAH_COMPILER_VAR_264->data[4] = ____BAH_COMPILER_VAR_274;
____BAH_COMPILER_VAR_264->data[5] = ____BAH_COMPILER_VAR_279;
struct reflectElement ____BAH_COMPILER_VAR_280 = __reflect(____BAH_COMPILER_VAR_263, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_264, 0);

        struct reflectElement ____BAH_COMPILER_VAR_281 = ____BAH_COMPILER_VAR_280;
        struct reflectElement ____BAH_COMPILER_VAR_282 = __reflect(____BAH_COMPILER_VAR_262, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_281, 0, 0, 0);
char * ____BAH_COMPILER_VAR_283 =toJson(____BAH_COMPILER_VAR_282);fs.writeFile(&fs,____BAH_COMPILER_VAR_283);
fs.close(&fs);
};
char isValidCacheFile(struct cacheFile* cf){
if (((cf==null)||(cf->last!=getLastModified(cf->file)))) {
return false;
}
char * ____BAH_COMPILER_VAR_284 =null;char * ____BAH_COMPILER_VAR_285 =pathToVarName(cf->file);char * ____BAH_COMPILER_VAR_286 =intToStr(cf->mem);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_2 = strlen("cache/");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_285);
long int strLen_6 = strlen(____BAH_COMPILER_VAR_286);
long int strLen_8 = strlen(".o.o");
;                            
                    ____BAH_COMPILER_VAR_284 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_284+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_284+currStrOff, "cache/", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_284+currStrOff, ____BAH_COMPILER_VAR_285, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_284+currStrOff, ____BAH_COMPILER_VAR_286, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_284+currStrOff, ".o.o", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                if ((fileExists(____BAH_COMPILER_VAR_284)==0)) {
return false;
}
if ((strcmp(cf->ver, BAH_VERSION) != 0)) {
return false;
}
return true;
};
void debugLine(__BAH_ARR_TYPE_Tok line){
char * cont = "";
long int i = 0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:16");
                        };
                        struct Tok t = line->data[i];
char * ____BAH_COMPILER_VAR_287 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(cont);
long int strLen_4 = strlen(" '");
long int strLen_6 = strlen(t.cont);
long int strLen_8 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_287 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_287+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_287+currStrOff, " '", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_287+currStrOff, t.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_287+currStrOff, "'", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                cont = ____BAH_COMPILER_VAR_287;
i = i+1;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_288 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_288->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_288->vars->length = 0;
            ____BAH_COMPILER_VAR_288->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_288->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_288->structs->length = 0;
            ____BAH_COMPILER_VAR_288->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_288->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_288->types->length = 0;
            ____BAH_COMPILER_VAR_288->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_288->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_288->fns->length = 0;
            ____BAH_COMPILER_VAR_288->fns->elemSize = sizeof(struct func*);
            struct Elems* nElems = ____BAH_COMPILER_VAR_288;
long int j = 0;
for (; (j<len(elems->vars)); j = j+1) {

                        if (elems->vars->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", j, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:29");
                        };
                        struct variable* v = elems->vars->data[j];
struct variable* ____BAH_COMPILER_VAR_289 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_289->name = "";
____BAH_COMPILER_VAR_289->type = "";
____BAH_COMPILER_VAR_289->isConst = false;
____BAH_COMPILER_VAR_289->constVal = "";
____BAH_COMPILER_VAR_289->isArray = false;
____BAH_COMPILER_VAR_289->from = "";
____BAH_COMPILER_VAR_289->outterScope = false;
____BAH_COMPILER_VAR_289->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_289;
*nv = *v;
nv->outterScope = true;

{
long nLength = j;
if (nElems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nElems->vars->data, (nLength+50)*sizeof(struct variable*));
nElems->vars->data = newPtr;
}
nElems->vars->data[j] = nv;
nElems->vars->length = nLength+1;
} else {
nElems->vars->data[j] = nv;
}
};
};
nElems->structs = elems->structs;
nElems->types = elems->types;
nElems->fns = elems->fns;
return nElems;
};
typedef long int lineType;
#define LINE_TYPE_INCLUDE (lineType)0
#define LINE_TYPE_DEFINE (lineType)1
#define LINE_TYPE_CONST (lineType)2
#define LINE_TYPE_VAR (lineType)3
#define LINE_TYPE_FN_DECL (lineType)4
#define LINE_TYPE_FN_CALL (lineType)5
#define LINE_TYPE_STRUCT (lineType)6
#define LINE_TYPE_CLIB (lineType)7
#define LINE_TYPE_RETURN (lineType)8
#define LINE_TYPE_IF (lineType)9
#define LINE_TYPE_ELSE (lineType)10
#define LINE_TYPE_MACRO (lineType)11
#define LINE_TYPE_FOR (lineType)12
#define LINE_TYPE_FOR_OPERATOR (lineType)13
#define LINE_TYPE_PRE_KEYWORD (lineType)14
#define LINE_TYPE_ASYNC (lineType)15
#define LINE_TYPE_IMPORT (lineType)16
lineType prevLine;
lineType getLineType(__BAH_ARR_TYPE_Tok line){

                        if (line->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", 0, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:73");
                        };
                        struct Tok ft = line->data[0];
if ((ft.type==TOKEN_TYPE_FUNC)) {
return LINE_TYPE_FN_CALL;
}
if ((ft.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(ft.cont, "#include") == 0)) {
return LINE_TYPE_INCLUDE;
}
else if ((strcmp(ft.cont, "#import") == 0)) {
return LINE_TYPE_IMPORT;
}
else if ((strcmp(ft.cont, "#define") == 0)) {
return LINE_TYPE_DEFINE;
}
else if ((strcmp(ft.cont, "const") == 0)) {
return LINE_TYPE_CONST;
}
else if ((strcmp(ft.cont, "struct") == 0)) {
return LINE_TYPE_STRUCT;
}
else if ((strcmp(ft.cont, "#cLib") == 0)) {
return LINE_TYPE_CLIB;
}
else if ((strcmp(ft.cont, "return") == 0)) {
return LINE_TYPE_RETURN;
}
else if ((strcmp(ft.cont, "if") == 0)) {
return LINE_TYPE_IF;
}
else if ((strcmp(ft.cont, "else") == 0)) {
return LINE_TYPE_ELSE;
}
else if ((strcmp(ft.cont, "#macro") == 0)) {
return LINE_TYPE_MACRO;
}
else if ((strcmp(ft.cont, "for") == 0)) {
return LINE_TYPE_FOR;
}
else if ((strcmp(ft.cont, "async") == 0)) {
return LINE_TYPE_ASYNC;
}
else if (((strcmp(ft.cont, "continue") == 0)||(strcmp(ft.cont, "break") == 0))) {
return LINE_TYPE_FOR_OPERATOR;
}
else {
return LINE_TYPE_PRE_KEYWORD;
}
}
else if ((ft.type==TOKEN_TYPE_VAR)) {
if ((len(line)==1)) {
throwErr(&ft,"Cannot declare var {TOKEN} without a type.");
}

                        if (line->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", 1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:112");
                        };
                        struct Tok st = line->data[1];
if (((st.type==TOKEN_TYPE_ENCL)&&(strcmp(st.cont, "(") == 0))) {

                        if (line->length <= len(line)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", len(line)-1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:114");
                        };
                        struct Tok lt = line->data[len(line)-1];
if (((lt.type==TOKEN_TYPE_ENCL)&&(strcmp(lt.cont, "}") == 0))) {
return LINE_TYPE_FN_DECL;
}
return LINE_TYPE_FN_CALL;
}
return LINE_TYPE_VAR;
}
return (lineType)-1;
};
__BAH_ARR_TYPE_Tok parseCast(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i = 0;
if ((guard==true)) {
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:135");
                        };
                        struct Tok t = line->data[i];
if ((strcmp(t.cont, "<") == 0)) {
break;
}

{
long nLength = i;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i] = t;
nl->length = nLength+1;
} else {
nl->data[i] = t;
}
};
i = i+1;
};
if ((i==len(line))) {
return line;
}
}
for (; (i<len(line)); i = i+1) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:148");
                        };
                        struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "<") == 0)) {
if ((i+3<len(line))) {

                        if (line->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:152");
                        };
                        struct Tok nt = line->data[i+1];

                        if (line->length <= i+2) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+2, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:153");
                        };
                        struct Tok nnt = line->data[i+2];

                        if (line->length <= i+3) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+3, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:154");
                        };
                        struct Tok nnnt = line->data[i+3];
if ((nt.type==TOKEN_TYPE_VAR)) {
if ((nnt.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(nnt.cont, ">") == 0)) {
nnnt.bahType = nt.cont;
struct string cCast = getCType(nt.cont,elems);
char * cCastStr = cCast.str(&cCast);
char * ____BAH_COMPILER_VAR_290 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(cCastStr);
long int strLen_6 = strlen(")");
long int strLen_8 = strlen(nnnt.cont);
;                            
                    ____BAH_COMPILER_VAR_290 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_290+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_290+currStrOff, cCastStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_290+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_290+currStrOff, nnnt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                nnnt.cont = ____BAH_COMPILER_VAR_290;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = nnnt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = nnnt;
}
};
i = i+3;
continue;
}
}
}
}
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
};
return nl;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_291 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_291);
long int i = len(p)-1;
while ((i>=0)) {

                        if (p->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: p[%d] with length %d", i, p->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:182");
                        };
                        char c = p->data[i];
if ((c==47)) {

{
long nLength = i+1;
if (p->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(p->data, (nLength+50)*sizeof(char));
p->data = newPtr;
}
p->data[i+1] = (char)0;
p->length = nLength+1;
} else {
p->data[i+1] = (char)0;
}
};
break;
}
i = i-1;
};
if ((i<=0)) {
return "";
}
return arrAsStr(p);
};
void parseLines(__BAH_ARR_TYPE_Tok ts,struct Elems* elems);
char includeFile(char * ccstr,struct Elems* elems){
if ((strcmp(ccstr, "BAH_MEM_COLLECTOR") == 0)) {
if ((RCPenabled==true)) {
if (flags.isSet(&flags,"rcp")) {
ccstr = "rcp.bah";
}
else if (flags.isSet(&flags,"fastrcp")) {
ccstr = "fastrcp.bah";
}
}
else {
ccstr = "gc.bah";
}
}

                int ____BAH_COMPILER_VAR_292 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                        ____BAH_COMPILER_VAR_292 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_292) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_293 = {};
____BAH_COMPILER_VAR_293.handle = -1;
____BAH_COMPILER_VAR_293.p= null;
____BAH_COMPILER_VAR_293.open = fileMap__open;
____BAH_COMPILER_VAR_293.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_293.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_293
char * ____BAH_COMPILER_VAR_294 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen(ccstr);
;                            
                    ____BAH_COMPILER_VAR_294 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_294+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_294+currStrOff, ccstr, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * fileName = ____BAH_COMPILER_VAR_294;
char isBahDir = true;
char * f = fm.open(&fm,fileName);
if ((fm.isValid(&fm)==0)) {
char * ____BAH_COMPILER_VAR_295 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_2 = strlen(ccstr);
;                            
                    ____BAH_COMPILER_VAR_295 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_295+currStrOff, compilerState.currentDir, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_295+currStrOff, ccstr, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fileName = absPath(____BAH_COMPILER_VAR_295);
f = fm.open(&fm,fileName);
isBahDir = false;
if ((fm.isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_296 =null;char * ____BAH_COMPILER_VAR_297 =getDirFromFile(ccstr);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(compilerState.currentDir);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_297);
;                            
                    ____BAH_COMPILER_VAR_296 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_296+currStrOff, compilerState.currentDir, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_296+currStrOff, ____BAH_COMPILER_VAR_297, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                compilerState.currentDir = ____BAH_COMPILER_VAR_296;
}
else {
char * ____BAH_COMPILER_VAR_298 =null;char * ____BAH_COMPILER_VAR_299 =getDirFromFile(ccstr);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_299);
;                            
                    ____BAH_COMPILER_VAR_298 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_298+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_298+currStrOff, ____BAH_COMPILER_VAR_299, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                compilerState.currentDir = ____BAH_COMPILER_VAR_298;
}
char * oFile = compilerState.currentFile;
compilerState.currentFile = fileName;

{
long nLength = len(compilerState.includes);
if (compilerState.includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.includes->data, (nLength+50)*sizeof(char *));
compilerState.includes->data = newPtr;
}
compilerState.includes->data[len(compilerState.includes)] = ccstr;
compilerState.includes->length = nLength+1;
} else {
compilerState.includes->data[len(compilerState.includes)] = ccstr;
}
};
array(struct Tok)* tokens = lexer(f);
fm.close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_300 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("File '");
long int strLen_2 = strlen(ccstr);
long int strLen_4 = strlen("' not recognized.");
;                            
                    ____BAH_COMPILER_VAR_300 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_300+currStrOff, "File '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_300+currStrOff, ccstr, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_300+currStrOff, "' not recognized.", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                __BAH_panic(____BAH_COMPILER_VAR_300,"/home/alois/Documents/bah-bah/src/parser.bah:249");
}
char oshd = shouldOnlyDecl;
if ((isObject==true)) {
shouldOnlyDecl = true;
}
else if ((isSubObject==true)) {
shouldOnlyDecl = false;
}
parseLines(tokens,elems);
shouldOnlyDecl = oshd;
compilerState.currentFile = oFile;
compilerState.currentDir = oDir;
return true;
};
void parallelObjCompile(char * fn,char * oName,struct channel * done){
readCache();
struct cacheFile* cf = getCacheFile(fn);
char * wrkd = getCurrentPath();
char * rcp = "";
if ((RCPlevel==1)) {
rcp = "-rcp";
}
else if ((RCPlevel==2)) {
rcp = "-fastrcp";
}
if ((isValidCacheFile(cf)==false)) {
setCurrentPath(compilerState.currentDir);
char * verboseCC = "";
if ((flags.isSet(&flags,"verboseCC")==1)) {
verboseCC = "-verboseCC";
}
char * ____BAH_COMPILER_VAR_301 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("compilling: ");
long int strLen_2 = strlen(fn);
long int strLen_4 = strlen("... ");
;                            
                    ____BAH_COMPILER_VAR_301 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_301+currStrOff, "compilling: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_301+currStrOff, fn, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_301+currStrOff, "... ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                print(____BAH_COMPILER_VAR_301);
char * ____BAH_COMPILER_VAR_302 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(execName);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(fn);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(rcp);
long int strLen_10 = strlen(" -object ");
long int strLen_12 = strlen(verboseCC);
long int strLen_14 = strlen(" -o ");
long int strLen_16 = strlen(oName);
;                            
                    ____BAH_COMPILER_VAR_302 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_302+currStrOff, execName, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_302+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_302+currStrOff, fn, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_302+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_302+currStrOff, rcp, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_302+currStrOff, " -object ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_302+currStrOff, verboseCC, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_302+currStrOff, " -o ", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_302+currStrOff, oName, strLen_16);
                        currStrOff += strLen_16;
                        
                }
                struct command cmd = command(____BAH_COMPILER_VAR_302);
char * res = cmd.run(&cmd);
println("ok");
setCurrentPath(wrkd);
if ((cmd.status!=0)) {
print(res);
exit(1);
}
if ((cf==null)) {
makeCacheFile(fn);
}
else {
updateCacheFile(cf);
}
}

                    char ____BAH_COMPILER_VAR_303 = true;
                    done->sendAny(done, &____BAH_COMPILER_VAR_303, sizeof(____BAH_COMPILER_VAR_303));
};
void parseImport(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
compilerState.hasImports = true;
if ((len(l)!=2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:313");
                        };
                        struct Tok strt = l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as file name (#import \"file\")");
}
struct string fileName = string(strt.cont);
fileName.trimLeft(&fileName,1);
fileName.trimRight(&fileName,1);

                int ____BAH_COMPILER_VAR_304 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], fileName.str(&fileName)) == 0) {
                        ____BAH_COMPILER_VAR_304 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_304) {
return;
}

{
long nLength = len(compilerState.includes);
if (compilerState.includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.includes->data, (nLength+50)*sizeof(char *));
compilerState.includes->data = newPtr;
}
compilerState.includes->data[len(compilerState.includes)] = fileName.str(&fileName);
compilerState.includes->length = nLength+1;
} else {
compilerState.includes->data[len(compilerState.includes)] = fileName.str(&fileName);
}
};
char * ____BAH_COMPILER_VAR_305 =fileName.str(&fileName);char * fn = absPath(____BAH_COMPILER_VAR_305);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_306 =null;char * ____BAH_COMPILER_VAR_307 =fileName.str(&fileName);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_307);
;                            
                    ____BAH_COMPILER_VAR_306 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_306+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_306+currStrOff, ____BAH_COMPILER_VAR_307, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fn = absPath(____BAH_COMPILER_VAR_306);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_308 = {};
____BAH_COMPILER_VAR_308.handle= null;
____BAH_COMPILER_VAR_308.name= null;
____BAH_COMPILER_VAR_308.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_308.open = fileStream__open;
____BAH_COMPILER_VAR_308.close = fileStream__close;
____BAH_COMPILER_VAR_308.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_308.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_308.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_308.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_308.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_308.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_308.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_308.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_308.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_308.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_308.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_308.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_308.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_308._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_308
fs.open(&fs,fn,"r");
char * f = fs.readContent(&fs);
fs.close(&fs);
array(struct Tok)* tokens = lexer(f);
char osod = shouldOnlyDecl;
shouldOnlyDecl = true;
char oiso = isSubObject;
isSubObject = true;
char * ____BAH_COMPILER_VAR_309 =null;char * ____BAH_COMPILER_VAR_310 =pathToVarName(fn);char * ____BAH_COMPILER_VAR_311 =intToStr(RCPlevel);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("cache/");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_310);
long int strLen_8 = strlen(____BAH_COMPILER_VAR_311);
long int strLen_10 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_309 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_309+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_309+currStrOff, "cache/", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_309+currStrOff, ____BAH_COMPILER_VAR_310, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_309+currStrOff, ____BAH_COMPILER_VAR_311, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_309+currStrOff, ".o", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * oName = ____BAH_COMPILER_VAR_309;
char * ____BAH_COMPILER_VAR_312 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("w ");
long int strLen_4 = strlen(oName);
long int strLen_6 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_312 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_312+currStrOff, "w ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_312+currStrOff, oName, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_312+currStrOff, ".o", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                
{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_312;
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_312;
}
};
struct channel * done = channel();
parallelObjCompile(fn,oName,done);
parseLines(tokens,elems);
char ok = *(char*)done->receive(done);
char * ____BAH_COMPILER_VAR_313 =null;char * ____BAH_COMPILER_VAR_314 =pathToVarName(fn);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_init");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_314);
long int strLen_4 = strlen("();\n");
;                            
                    ____BAH_COMPILER_VAR_313 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_313+currStrOff, "__BAH_init", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_313+currStrOff, ____BAH_COMPILER_VAR_314, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_313+currStrOff, "();\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_313));
writeCache();
shouldOnlyDecl = osod;
isSubObject = oiso;
compilerState.currentFile = of;
compilerState.currentDir = od;
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:397");
                        };
                        struct Tok strt = l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
char * sc = strt.cont;
strTrimLeft(&sc,1);
strTrimRight(&sc,1);
if (((strHasPrefix(sc,"<")||strHasSuffix(sc,".h"))||strHasSuffix(sc,".c"))) {
char * ____BAH_COMPILER_VAR_315 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#include ");
long int strLen_2 = strlen(sc);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_315 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_315+currStrOff, "#include ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_315+currStrOff, sc, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_315+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_315));

{
long nLength = len(compilerState.cIncludes);
if (compilerState.cIncludes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cIncludes->data, (nLength+50)*sizeof(char *));
compilerState.cIncludes->data = newPtr;
}
compilerState.cIncludes->data[len(compilerState.cIncludes)] = sc;
compilerState.cIncludes->length = nLength+1;
} else {
compilerState.cIncludes->data[len(compilerState.cIncludes)] = sc;
}
};
}
else {
if ((includeFile(sc,elems)==false)) {
throwErr(&strt,"Could not find file {TOKEN}.");
}
}
};
array(char *)* signs;
__BAH_ARR_TYPE_Tok parseOperations(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){

                        if (line->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", 0, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:420");
                        };
                        array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = line->data[0];

                        if (line->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", 0, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:421");
                        };
                        array(struct Tok)* unNestedLine = memoryAlloc(sizeof(array(struct Tok)));

unNestedLine->length = 1;
unNestedLine->elemSize = sizeof(struct Tok);
unNestedLine->data = memoryAlloc(sizeof(struct Tok) * 50);unNestedLine->data[0] = line->data[0];
long int i = 1;
for (; (i<len(line)); i = i+1) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:424");
                        };
                        struct Tok t = line->data[i];

                        if (line->length <= i-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i-1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:425");
                        };
                        struct Tok pt = line->data[i-1];
if (((strcmp(t.cont, "(") == 0)&&(pt.type!=TOKEN_TYPE_KEYWORD))) {
long int nbPars = 1;
i = i+1;
array(struct Tok)* mem = memoryAlloc(sizeof(array(struct Tok)));

mem->length = 0;
mem->elemSize = sizeof(struct Tok);
struct Tok ft = t;
for (; (i<len(line)); i = i+1) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:433");
                        };
                        t = line->data[i];

                        if (line->length <= i-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i-1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:434");
                        };
                        pt = line->data[i-1];
if (((strcmp(t.cont, "(") == 0)&&(pt.type!=TOKEN_TYPE_KEYWORD))) {
nbPars = nbPars+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPars = nbPars-1;
}
if ((nbPars==0)) {
break;
}

{
long nLength = len(mem);
if (mem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(mem->data, (nLength+50)*sizeof(struct Tok));
mem->data = newPtr;
}
mem->data[len(mem)] = t;
mem->length = nLength+1;
} else {
mem->data[len(mem)] = t;
}
};
};
if ((len(mem)==0)) {

{
long nLength = len(unNestedLine);
if (unNestedLine->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(unNestedLine->data, (nLength+50)*sizeof(struct Tok));
unNestedLine->data = newPtr;
}
unNestedLine->data[len(unNestedLine)] = ft;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] = ft;
}
};

{
long nLength = len(unNestedLine);
if (unNestedLine->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(unNestedLine->data, (nLength+50)*sizeof(struct Tok));
unNestedLine->data = newPtr;
}
unNestedLine->data[len(unNestedLine)] = t;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] = t;
}
};
continue;
}
array(struct Tok)* tmpL = parseOperations(mem,ltp,elems);

                        if (tmpL->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: tmpL[%d] with length %d", 0, tmpL->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:453");
                        };
                        struct Tok nestedT = tmpL->data[0];
char * ____BAH_COMPILER_VAR_316 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(nestedT.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_316 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_316+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_316+currStrOff, nestedT.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_316+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                nestedT.cont = ____BAH_COMPILER_VAR_316;

{
long nLength = len(unNestedLine);
if (unNestedLine->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(unNestedLine->data, (nLength+50)*sizeof(struct Tok));
unNestedLine->data = newPtr;
}
unNestedLine->data[len(unNestedLine)] = nestedT;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] = nestedT;
}
};
continue;
}

{
long nLength = len(unNestedLine);
if (unNestedLine->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(unNestedLine->data, (nLength+50)*sizeof(struct Tok));
unNestedLine->data = newPtr;
}
unNestedLine->data[len(unNestedLine)] = t;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] = t;
}
};
};
line = unNestedLine;
i = 1;
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:463");
                        };
                        struct Tok t = line->data[i];

                int ____BAH_COMPILER_VAR_317 = 0;
                for(int i=len(signs)-1; i != -1; i--) {
                    if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_317 = 1;
                        break;
                    };
                };
                if (((t.type==TOKEN_TYPE_SYNTAX)&&____BAH_COMPILER_VAR_317)) {
if ((i+1>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:469");
                        };
                        struct Tok pt = nl->data[len(nl)-1];

                        if (line->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:470");
                        };
                        struct Tok nt = line->data[i+1];
if ((((strcmp(t.cont, "-") == 0)&&(pt.isValue==false))&&(nt.type==TOKEN_TYPE_INT))) {
char * ____BAH_COMPILER_VAR_318 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(t.cont);
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_318 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_318+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_318+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                nt.cont = ____BAH_COMPILER_VAR_318;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = nt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = nt;
}
};
i = i+2;
continue;
}
if (((nt.type==TOKEN_TYPE_SYNTAX)&&(strcmp(nt.cont, t.cont) == 0))) {
char * ____BAH_COMPILER_VAR_319 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(t.cont);
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_319 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_319+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_319+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * c = ____BAH_COMPILER_VAR_319;
long int tl = t.line;
long int tp = t.pos;
struct Tok ____BAH_COMPILER_VAR_320 = {};
____BAH_COMPILER_VAR_320.cont = "";
____BAH_COMPILER_VAR_320.ogCont = "";
____BAH_COMPILER_VAR_320.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_320.pos = 0;
____BAH_COMPILER_VAR_320.line = 1;
____BAH_COMPILER_VAR_320.begLine = 1;
____BAH_COMPILER_VAR_320.bahType = "";
____BAH_COMPILER_VAR_320.isValue = false;
____BAH_COMPILER_VAR_320.isFunc = false;
____BAH_COMPILER_VAR_320.isOper = false;
____BAH_COMPILER_VAR_320.isEqual = false;
____BAH_COMPILER_VAR_320.cont = c;
____BAH_COMPILER_VAR_320.ogCont = c;
____BAH_COMPILER_VAR_320.isValue = false;
____BAH_COMPILER_VAR_320.line = tl;
____BAH_COMPILER_VAR_320.pos = tp;
____BAH_COMPILER_VAR_320.type = TOKEN_TYPE_SYNTAX;
#define tmpT ____BAH_COMPILER_VAR_320

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = tmpT;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = tmpT;
}
};
i = i+2;
continue;
}
char * ptt = getTypeFromToken(&pt,true,elems);
char * ntt = getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_321 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(ptt);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_321 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_321+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_321+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_321+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_321+currStrOff, ptt, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_321+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&nt,____BAH_COMPILER_VAR_321);
}
t.isValue = true;
if (((verboseRuntime==true)&&(ltp!=LINE_TYPE_ELSE))) {
if ((isRCPpointerType(ntt)||isRCPpointerType(ptt))) {
verboseOutOper(pt,nt,pt.line,elems);
}
}
if (compTypes(ptt,"cpstring")) {
if ((strcmp(t.cont, "+") != 0)) {
throwErr(&t,"Can only do concatenation (+) on cpstrings, not {TOKEN}.");
}
long int j = i-1;
char * lens = "";
char * totStrLen = "1";
struct rope* cats = rope("");
char * rstr = registerRCPvar("cpstring","null",elems);
char wasAdd = true;
for (; (j<len(line)); j = j+1) {

                        if (line->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", j, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:529");
                        };
                        struct Tok strAddTk = line->data[j];
if ((wasAdd==false)) {
if ((strcmp(strAddTk.cont, "+") != 0)) {
break;
}
wasAdd = true;
}
else {
char * strAddTkT = getTypeFromToken(&strAddTk,true,elems);
if ((compTypes(strAddTkT,"cpstring")==false)) {
char * ____BAH_COMPILER_VAR_322 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(ptt);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_322 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_322+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_322+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_322+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_322+currStrOff, ptt, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_322+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&strAddTkT,____BAH_COMPILER_VAR_322);
break;
}
char * cont = strAddTk.cont;
if ((((strAddTk.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(strAddTk.cont,"noCheck(")==false))&&(isRCPtype(strAddTkT,elems)==true))) {
cont = registerRCPvar(strAddTkT,strAddTk.cont,elems);
}
char * js = intToStr(j);
char * ____BAH_COMPILER_VAR_323 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(lens);
long int strLen_4 = strlen("long int strLen_");
long int strLen_6 = strlen(js);
long int strLen_8 = strlen(" = strlen(");
long int strLen_10 = strlen(cont);
long int strLen_12 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_323 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_323+currStrOff, lens, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_323+currStrOff, "long int strLen_", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_323+currStrOff, js, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_323+currStrOff, " = strlen(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_323+currStrOff, cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_323+currStrOff, ");\n", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                lens = ____BAH_COMPILER_VAR_323;
char * ____BAH_COMPILER_VAR_324 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(totStrLen);
long int strLen_4 = strlen(" + strLen_");
long int strLen_6 = strlen(js);
;                            
                    ____BAH_COMPILER_VAR_324 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_324+currStrOff, totStrLen, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_324+currStrOff, " + strLen_", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_324+currStrOff, js, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                totStrLen = ____BAH_COMPILER_VAR_324;
char * ____BAH_COMPILER_VAR_325 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                        memcpy(");
long int strLen_2 = strlen(rstr);
long int strLen_4 = strlen("+currStrOff, ");
long int strLen_6 = strlen(cont);
long int strLen_8 = strlen(", strLen_");
long int strLen_10 = strlen(js);
long int strLen_12 = strlen(");\n                        currStrOff += strLen_");
long int strLen_14 = strlen(js);
long int strLen_16 = strlen(";\n                        ");
;                            
                    ____BAH_COMPILER_VAR_325 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, "\n                        memcpy(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, rstr, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, "+currStrOff, ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, ", strLen_", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, js, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, ");\n                        currStrOff += strLen_", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, js, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, ";\n                        ", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                cats = cats->add(cats, rope(____BAH_COMPILER_VAR_325));
wasAdd = false;
}
};
i = j;
char * ____BAH_COMPILER_VAR_326 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                {\n                    long int currStrOff = 0;\n                    ");
long int strLen_2 = strlen(lens);
long int strLen_4 = strlen(";                            \n                    ");
long int strLen_6 = strlen(rstr);
long int strLen_8 = strlen(" = memoryAllocSTR(");
long int strLen_10 = strlen(totStrLen);
long int strLen_12 = strlen(");\n                    ");
;                            
                    ____BAH_COMPILER_VAR_326 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, "\n                {\n                    long int currStrOff = 0;\n                    ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, lens, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, ";                            \n                    ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, rstr, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, " = memoryAllocSTR(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, totStrLen, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, ");\n                    ", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                struct rope* res = rope(____BAH_COMPILER_VAR_326)->add(rope(____BAH_COMPILER_VAR_326), cats)->add(rope(____BAH_COMPILER_VAR_326)->add(rope(____BAH_COMPILER_VAR_326), cats), rope("\n                }\n                "));
if (isGlobal()) {
INIT = INIT->add(INIT, res);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, res);
}
t.cont = rstr;
t.type = TOKEN_TYPE_VAR;
t.bahType = ptt;
t.isOper = false;
t.pos = pt.pos;
t.ogCont = pt.cont;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = t;
}
};
continue;
}
else {
struct cStruct* s = searchStruct(ptt,elems);
if ((s!=null)) {
char * sep = ".";
char * amp = "&";
if ((strCount(ptt,"*")>0)) {
sep = "->";
amp = "";
}
if ((strcmp(t.cont, "+") == 0)) {
struct structMemb* addMthd = searchStructMemb("add",s,elems);
if (((addMthd!=null)&&(addMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_327 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen("add(");
long int strLen_8 = strlen(amp);
long int strLen_10 = strlen(pt.cont);
long int strLen_12 = strlen(", ");
long int strLen_14 = strlen(nt.cont);
long int strLen_16 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_327 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, "add(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, amp, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, pt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, nt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, ")", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_327;
}
}
else if ((strcmp(t.cont, "-") == 0)) {
struct structMemb* subMthd = searchStructMemb("sub",s,elems);
if (((subMthd!=null)&&(subMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_328 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen("sub(");
long int strLen_8 = strlen(amp);
long int strLen_10 = strlen(pt.cont);
long int strLen_12 = strlen(", ");
long int strLen_14 = strlen(nt.cont);
long int strLen_16 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_328 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, "sub(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, amp, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, pt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, nt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, ")", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_328;
}
}
else if ((strcmp(t.cont, "*") == 0)) {
struct structMemb* multMthd = searchStructMemb("mult",s,elems);
if (((multMthd!=null)&&(multMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_329 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen("mult(");
long int strLen_8 = strlen(amp);
long int strLen_10 = strlen(pt.cont);
long int strLen_12 = strlen(", ");
long int strLen_14 = strlen(nt.cont);
long int strLen_16 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_329 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, "mult(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, amp, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, pt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, nt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, ")", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_329;
}
}
else if ((strcmp(t.cont, "/") == 0)) {
struct structMemb* divMthd = searchStructMemb("div",s,elems);
if (((divMthd!=null)&&(divMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_330 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen("div(");
long int strLen_8 = strlen(amp);
long int strLen_10 = strlen(pt.cont);
long int strLen_12 = strlen(", ");
long int strLen_14 = strlen(nt.cont);
long int strLen_16 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, "div(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, amp, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, pt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, nt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, ")", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_330;
}
}
else {
char * ____BAH_COMPILER_VAR_331 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Undefined operation on {TOKEN} (");
long int strLen_4 = strlen(ptt);
long int strLen_6 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_331 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, "Undefined operation on {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, ptt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, ").", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&pt,____BAH_COMPILER_VAR_331);
}
}
else {
char * ____BAH_COMPILER_VAR_332 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(t.cont);
long int strLen_6 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_332 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_332;
}
}
t.type = TOKEN_TYPE_VAR;
t.bahType = ptt;
t.pos = pt.pos;
t.isOper = true;
t.ogCont = pt.cont;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = t;
}
};
i = i+2;
continue;
}
else if ((t.isValue==true)) {
if (strHasPrefix(t.cont,"-")) {

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:642");
                        };
                        struct Tok pt = nl->data[len(nl)-1];
if ((pt.isValue==true)) {
char * ptt = getTypeFromToken(&pt,true,elems);
char * ntt = getTypeFromToken(&t,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_333 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(ptt);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_333 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, ptt, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_333);
}
t.type = TOKEN_TYPE_VAR;
t.isOper = true;
char * ____BAH_COMPILER_VAR_334 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_334 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_334+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_334+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_334;
t.bahType = ptt;
t.pos = pt.pos;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = t;
}
};
i = i+1;
continue;
}
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i = i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems);
__BAH_ARR_TYPE_Tok parseStructType(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){
if ((ltp==LINE_TYPE_VAR)) {
return line;
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i = 0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:679");
                        };
                        struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
if (strHasPrefix(t.bahType,"[]")) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i = i+1;
continue;
}
i = i+1;
struct Tok ____BAH_COMPILER_VAR_335 = {};
____BAH_COMPILER_VAR_335.cont = "";
____BAH_COMPILER_VAR_335.ogCont = "";
____BAH_COMPILER_VAR_335.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_335.pos = 0;
____BAH_COMPILER_VAR_335.line = 1;
____BAH_COMPILER_VAR_335.begLine = 1;
____BAH_COMPILER_VAR_335.bahType = "";
____BAH_COMPILER_VAR_335.isValue = false;
____BAH_COMPILER_VAR_335.isFunc = false;
____BAH_COMPILER_VAR_335.isOper = false;
____BAH_COMPILER_VAR_335.isEqual = false;
____BAH_COMPILER_VAR_335.cont = "";
#define nt ____BAH_COMPILER_VAR_335
if ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:692");
                        };
                        nt = line->data[i];
}
if (((i==len(line))||(strcmp(nt.cont, "{") != 0))) {
if ((i-2>=0)) {

                        if (line->length <= i-2) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i-2, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:696");
                        };
                        struct Tok newTk = line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
struct cStruct* s = searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Cannot initialize new unknown struct {TOKEN}.");
}
t.cont = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_336 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_336->name = "";
____BAH_COMPILER_VAR_336->type = "";
____BAH_COMPILER_VAR_336->isConst = false;
____BAH_COMPILER_VAR_336->constVal = "";
____BAH_COMPILER_VAR_336->isArray = false;
____BAH_COMPILER_VAR_336->from = "";
____BAH_COMPILER_VAR_336->outterScope = false;
____BAH_COMPILER_VAR_336->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_336;
tmpV->name = t.cont;
char * ____BAH_COMPILER_VAR_337 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s->name);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_337 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_337+currStrOff, s->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_337+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpV->type = ____BAH_COMPILER_VAR_337;
struct string cType = getCType(tmpV->type,elems);
struct string structType = getCType(s->name,elems);

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = tmpV;
}
};
char * ____BAH_COMPILER_VAR_338 =null;char * ____BAH_COMPILER_VAR_339 =cType.str(&cType);char * ____BAH_COMPILER_VAR_340 =structType.str(&structType);char * ____BAH_COMPILER_VAR_341 =declareStructMethods(tmpV,s,elems);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_339);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(t.cont);
long int strLen_6 = strlen(" = memoryAlloc(sizeof(");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_340);
long int strLen_10 = strlen("));\n");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_341);
;                            
                    ____BAH_COMPILER_VAR_338 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_338+currStrOff, ____BAH_COMPILER_VAR_339, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_338+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_338+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_338+currStrOff, " = memoryAlloc(sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_338+currStrOff, ____BAH_COMPILER_VAR_340, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_338+currStrOff, "));\n", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_338+currStrOff, ____BAH_COMPILER_VAR_341, strLen_12);
                        currStrOff += strLen_12;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_338));

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = t;
}
};
continue;
}
}
}
if ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:720");
                        };
                        nt = line->data[i];
if ((strcmp(nt.cont, "{") == 0)) {
char isHeap = false;
char * sep = ".";
if ((i-2>=0)) {

                        if (line->length <= i-2) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i-2, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:725");
                        };
                        struct Tok newTk = line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
isHeap = true;
sep = "->";
}
}
i = i+1;
struct cStruct* s = searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int nbBraces = 1;
for (; (i<len(line)); i = i+1) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:740");
                        };
                        t = line->data[i];
if ((strcmp(t.cont, "{") == 0)) {
nbBraces = nbBraces+1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbBraces = nbBraces-1;
if ((nbBraces==0)) {
break;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = t;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = t;
}
};
};
if ((len(memory)>0)) {
memory = prePross(memory,(lineType)-1,elems);
}
long int declType = 0;
char * rvn = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_342 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_342->name = "";
____BAH_COMPILER_VAR_342->type = "";
____BAH_COMPILER_VAR_342->isConst = false;
____BAH_COMPILER_VAR_342->constVal = "";
____BAH_COMPILER_VAR_342->isArray = false;
____BAH_COMPILER_VAR_342->from = "";
____BAH_COMPILER_VAR_342->outterScope = false;
____BAH_COMPILER_VAR_342->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_342;
tmpV->name = rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_343 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s->name);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_343 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_343+currStrOff, s->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_343+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpV->type = ____BAH_COMPILER_VAR_343;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = tmpV;
}
};
}
else {
tmpV->type = s->name;
}
struct string rst = getCType(tmpV->type,elems);
struct rope* r= null;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_344 =rst.str(&rst);struct string structType = string(____BAH_COMPILER_VAR_344);
structType.trimRight(&structType,1);
char * ____BAH_COMPILER_VAR_345 =null;char * ____BAH_COMPILER_VAR_346 =rst.str(&rst);char * ____BAH_COMPILER_VAR_347 =structType.str(&structType);char * ____BAH_COMPILER_VAR_348 =declareStructMethods(tmpV,s,elems);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_346);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(rvn);
long int strLen_6 = strlen(" = memoryAlloc(sizeof(");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_347);
long int strLen_10 = strlen("));\n");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_348);
;                            
                    ____BAH_COMPILER_VAR_345 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_345+currStrOff, ____BAH_COMPILER_VAR_346, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_345+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_345+currStrOff, rvn, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_345+currStrOff, " = memoryAlloc(sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_345+currStrOff, ____BAH_COMPILER_VAR_347, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_345+currStrOff, "));\n", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_345+currStrOff, ____BAH_COMPILER_VAR_348, strLen_12);
                        currStrOff += strLen_12;
                        
                }
                r = rope(____BAH_COMPILER_VAR_345);
}
else {
char * ____BAH_COMPILER_VAR_349 =null;char * ____BAH_COMPILER_VAR_350 =rst.str(&rst);char * ____BAH_COMPILER_VAR_351 =declareStructMethods(tmpV,s,elems);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_350);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(rvn);
long int strLen_6 = strlen(" = {};\n");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_351);
;                            
                    ____BAH_COMPILER_VAR_349 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_349+currStrOff, ____BAH_COMPILER_VAR_350, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_349+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_349+currStrOff, rvn, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_349+currStrOff, " = {};\n", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_349+currStrOff, ____BAH_COMPILER_VAR_351, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                r = rope(____BAH_COMPILER_VAR_349);
}
long int j = 0;
long int k = 0;
while ((k<len(memory))) {

                        if (memory->length <= k) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", k, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:781");
                        };
                        t = memory->data[k];
if ((k+2<len(memory))) {

                        if (memory->length <= k+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", k+1, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:784");
                        };
                        struct Tok st = memory->data[k+1];

                        if (memory->length <= k+2) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", k+2, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:785");
                        };
                        struct Tok vl = memory->data[k+2];
if ((strcmp(st.cont, ":") == 0)) {
if (((declType!=0)&&(declType!=1))) {
throwErr(&t,"Cannot declare member {TOKEN} by name in list declaration.");
}
declType = 1;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as struct member name.");
}
j = 0;
while ((j<len(s->members))) {

                        if (s->members->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: s->members[%d] with length %d", j, s->members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:795");
                        };
                        struct structMemb* m = s->members->data[j];
if ((strcmp(m->name, t.cont) != 0)) {
j = j+1;
continue;
}
char * vlt = getTypeFromToken(&vl,true,elems);
if ((compTypes(vlt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_352 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(vlt);
long int strLen_6 = strlen(") as '");
long int strLen_8 = strlen(m->type);
long int strLen_10 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_352 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_352+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_352+currStrOff, vlt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_352+currStrOff, ") as '", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_352+currStrOff, m->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_352+currStrOff, "'.", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&vl,____BAH_COMPILER_VAR_352);
}
char * ____BAH_COMPILER_VAR_353 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(rvn);
long int strLen_2 = strlen(sep);
long int strLen_4 = strlen(m->name);
long int strLen_6 = strlen(" = ");
long int strLen_8 = strlen(vl.cont);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_353 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_353+currStrOff, rvn, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_353+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_353+currStrOff, m->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_353+currStrOff, " = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_353+currStrOff, vl.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_353+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_353));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_354 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Struct '");
long int strLen_4 = strlen(s->name);
long int strLen_6 = strlen("' has no member called {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_354 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_354+currStrOff, "Struct '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_354+currStrOff, s->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_354+currStrOff, "' has no member called {TOKEN}.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_354);
}
k = k+3;
continue;
}
}
if (((declType!=0)&&(declType!=2))) {
throwErr(&t,"Cannot declare member {TOKEN} without specifying its name.");
}
declType = 2;
if ((j>len(s->members))) {
throwErr(&t,"Too many members {TOKEN}.");
}

                        if (s->members->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: s->members[%d] with length %d", j, s->members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:822");
                        };
                        struct structMemb* m = s->members->data[j];
j = j+1;
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_355 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as '");
long int strLen_8 = strlen(m->type);
long int strLen_10 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_355 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_355+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_355+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_355+currStrOff, ") as '", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_355+currStrOff, m->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_355+currStrOff, "'.", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_355);
}
char * ____BAH_COMPILER_VAR_356 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(rvn);
long int strLen_2 = strlen(sep);
long int strLen_4 = strlen(m->name);
long int strLen_6 = strlen(" = ");
long int strLen_8 = strlen(t.cont);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_356 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_356+currStrOff, rvn, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_356+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_356+currStrOff, m->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_356+currStrOff, " = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_356+currStrOff, t.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_356+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_356));
if ((k+1<len(memory))) {
k = k+1;

                        if (memory->length <= k) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", k, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:834");
                        };
                        struct Tok st = memory->data[k];
if ((strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Need ',' separator between two values, not {TOKEN}.");
}
}
k = k+1;
};
if (isGlobal()) {
INIT = INIT->add(INIT, r);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, r);
}
t.bahType = tmpV->type;
t.cont = rvn;
t.isValue = true;
if ((isHeap==true)) {

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = t;
}
};
}
else {
t.isEqual = true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
}
i = i+1;
continue;
}
else {
i = i-1;
}
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i = i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseStructVars(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
if ((guard==true)) {
long int i = 0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:880");
                        };
                        struct Tok t = line->data[i];
if ((strcmp(t.cont, ".") == 0)) {
break;
}
i = i+1;
};
if ((i==len(line))) {
return line;
}
}
long int i = 0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:893");
                        };
                        struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i = i+1;
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:897");
                        };
                        struct Tok it = line->data[i];
if ((strcmp(it.cont, ".") != 0)) {
break;
}
struct variable* v = searchVar(t.cont,elems);
if ((v==null)) {
throwErr(&t,"Unknown var {TOKEN}.");
}
char * sep = ".";
if (strCount(v->type,"*")) {
sep = "->";
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
char * ____BAH_COMPILER_VAR_357 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(v->type);
long int strLen_6 = strlen(") as a structure.");
;                            
                    ____BAH_COMPILER_VAR_357 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_357+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_357+currStrOff, v->type, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_357+currStrOff, ") as a structure.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_357);
}
i = i+1;

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:914");
                        };
                        struct Tok nt = line->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as struct member name.");
}
struct structMemb* memb = searchStructMemb(nt.cont,s,elems);
if ((memb==null)) {
throwErr(&nt,"Unknown struct member {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_358 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(t.cont);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen(memb->name);
;                            
                    ____BAH_COMPILER_VAR_358 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_358+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_358+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_358+currStrOff, memb->name, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_358;
i = i+1;
};

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i = i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i = 0;
if ((guard==true)) {
for (; (i<len(line)); i = i+1) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:944");
                        };
                        struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
break;
}

{
long nLength = i;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i] = t;
nl->length = nLength+1;
} else {
nl->data[i] = t;
}
};
};
if ((i==len(line))) {
return line;
}
}
for (; (i<len(line)); i = i+1) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:956");
                        };
                        struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
i = i+1;
if ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:960");
                        };
                        t = line->data[i];
if ((strcmp(t.cont, "]") == 0)) {
i = i+1;
long int depth = 1;
char * bracks = "[]";
for (; (i<len(line)-1); i = i+1) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:966");
                        };
                        t = line->data[i];

                        if (line->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:967");
                        };
                        struct Tok nt = line->data[i+1];
if (((strcmp(t.cont, "[") == 0)&&(strcmp(nt.cont, "]") == 0))) {
depth = depth+1;
char * ____BAH_COMPILER_VAR_359 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(bracks);
long int strLen_4 = strlen("[]");
;                            
                    ____BAH_COMPILER_VAR_359 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_359+currStrOff, bracks, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_359+currStrOff, "[]", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                bracks = ____BAH_COMPILER_VAR_359;
i = i+1;
}
else {
break;
}
};
if ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:977");
                        };
                        t = line->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem = t.cont;
char * ____BAH_COMPILER_VAR_360 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(bracks);
long int strLen_4 = strlen(arrElem);
;                            
                    ____BAH_COMPILER_VAR_360 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_360+currStrOff, bracks, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_360+currStrOff, arrElem, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                t.bahType = ____BAH_COMPILER_VAR_360;
t.cont = "";
t.isValue = true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
continue;
}
}
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
};
return nl;
};
array(char *)* comparators;
array(char *)* compSep;
__BAH_ARR_TYPE_Tok parseBool(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i = 0;
if ((guard==true)) {
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1009");
                        };
                        struct Tok t = line->data[i];
if ((inArrayStr(t.cont,comparators)||inArrayStr(t.cont,compSep))) {
break;
}

{
long nLength = i;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i] = t;
nl->length = nLength+1;
} else {
nl->data[i] = t;
}
};
i = i+1;
};
if ((i==len(line))) {
return line;
}
}
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1022");
                        };
                        struct Tok t = line->data[i];
if (inArrayStr(t.cont,comparators)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1028");
                        };
                        struct Tok pt = nl->data[len(nl)-1];
long int max = i+1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (line->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1033");
                        };
                        struct Tok nt = line->data[i+1];
char * ptt = getTypeFromToken(&pt,true,elems);
char * ntt = getTypeFromToken(&nt,true,elems);
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT = string(ntt);
if ((arrT.hasPrefix(&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_361 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") as an array.");
;                            
                    ____BAH_COMPILER_VAR_361 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_361+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_361+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_361+currStrOff, ") as an array.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&nt,____BAH_COMPILER_VAR_361);
}
arrT.trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_362 =arrT.str(&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_362)==false)) {
char * ____BAH_COMPILER_VAR_363 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot search for {TOKEN} (");
long int strLen_4 = strlen(ptt);
long int strLen_6 = strlen(") inside array of type ");
long int strLen_8 = strlen(ntt);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_363 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_363+currStrOff, "Cannot search for {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_363+currStrOff, ptt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_363+currStrOff, ") inside array of type ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_363+currStrOff, ntt, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_363+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&pt,____BAH_COMPILER_VAR_363);
}
char * compVar = genCompilerVar();
char * comp = "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_364 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nt.cont);
long int strLen_4 = strlen("->data[i] != 0 && strcmp(");
long int strLen_6 = strlen(nt.cont);
long int strLen_8 = strlen("->data[i], ");
long int strLen_10 = strlen(pt.cont);
long int strLen_12 = strlen(") == 0");
;                            
                    ____BAH_COMPILER_VAR_364 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_364+currStrOff, nt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_364+currStrOff, "->data[i] != 0 && strcmp(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_364+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_364+currStrOff, "->data[i], ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_364+currStrOff, pt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_364+currStrOff, ") == 0", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                comp = ____BAH_COMPILER_VAR_364;
}
else {
char * ____BAH_COMPILER_VAR_365 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nt.cont);
long int strLen_4 = strlen("->data[i] == ");
long int strLen_6 = strlen(pt.cont);
;                            
                    ____BAH_COMPILER_VAR_365 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_365+currStrOff, nt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_365+currStrOff, "->data[i] == ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_365+currStrOff, pt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                comp = ____BAH_COMPILER_VAR_365;
}
char * ____BAH_COMPILER_VAR_366 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                int ");
long int strLen_2 = strlen(compVar);
long int strLen_4 = strlen(" = 0;\n                for(int i=len(");
long int strLen_6 = strlen(nt.cont);
long int strLen_8 = strlen(")-1; i != -1; i--) {\n                    if (");
long int strLen_10 = strlen(comp);
long int strLen_12 = strlen(") {\n                        ");
long int strLen_14 = strlen(compVar);
long int strLen_16 = strlen(" = 1;\n                        break;\n                    };\n                };\n                ");
;                            
                    ____BAH_COMPILER_VAR_366 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, "\n                int ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, compVar, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, " = 0;\n                for(int i=len(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, ")-1; i != -1; i--) {\n                    if (", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, comp, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, ") {\n                        ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, compVar, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, " = 1;\n                        break;\n                    };\n                };\n                ", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_366));
pt.cont = compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_367 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot compare {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") to ");
long int strLen_8 = strlen(ptt);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_367 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, "Cannot compare {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, ") to ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, ptt, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&nt,____BAH_COMPILER_VAR_367);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_368 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strcmp(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen(") == 0)");
;                            
                    ____BAH_COMPILER_VAR_368 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_368+currStrOff, "(strcmp(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_368+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_368+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_368+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_368+currStrOff, ") == 0)", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_368;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_369 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strcmp(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen(") != 0)");
;                            
                    ____BAH_COMPILER_VAR_369 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, "(strcmp(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, ") != 0)", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_369;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_370 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strlen(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(") > srtlen(");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_370+currStrOff, "(strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_370+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_370+currStrOff, ") > srtlen(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_370+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_370+currStrOff, "))", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_370;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_371 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strlen(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(") < srtlen(");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_371 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_371+currStrOff, "(strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_371+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_371+currStrOff, ") < srtlen(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_371+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_371+currStrOff, "))", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_371;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_372 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strlen(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(") >= srtlen(");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_372 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_372+currStrOff, "(strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_372+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_372+currStrOff, ") >= srtlen(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_372+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_372+currStrOff, "))", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_372;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_373 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strlen(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(") <= srtlen(");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_373 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_373+currStrOff, "(strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_373+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_373+currStrOff, ") <= srtlen(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_373+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_373+currStrOff, "))", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_373;
}
}
else {
char * ____BAH_COMPILER_VAR_374 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(t.cont);
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_374 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_374+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_374+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_374+currStrOff, t.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_374+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_374+currStrOff, ")", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_374;
}
}
pt.bahType = "bool";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = pt;
}
};
i = i+2;
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i = i+1;
};
line = nl;
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
i = 0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1109");
                        };
                        struct Tok t = line->data[i];
if (inArrayStr(t.cont,compSep)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1114");
                        };
                        struct Tok pt = nl->data[len(nl)-1];
long int max = i+1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (line->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1119");
                        };
                        struct Tok nt = line->data[i+1];
char * ptt = getTypeFromToken(&pt,true,elems);
char * ntt = getTypeFromToken(&nt,true,elems);
if ((strcmp(ptt, "bool") != 0)) {
if ((strcmp(ptt, "int") != 0)) {
throwErr(&pt,"Cannot compare {TOKEN} that is not a bool.");
}
}
if ((strcmp(ntt, "bool") != 0)) {
if ((strcmp(ntt, "int") != 0)) {
throwErr(&nt,"Cannot compare {TOKEN} that is not a bool.");
}
}
char * ____BAH_COMPILER_VAR_375 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(t.cont);
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_375 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_375+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_375+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_375+currStrOff, t.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_375+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_375+currStrOff, ")", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_375;
pt.bahType = "bool";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = pt;
}
};
i = i+2;
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i = i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parsePointers(__BAH_ARR_TYPE_Tok l){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
array(char *)* ptrOpers = memoryAlloc(sizeof(array(char *)));

ptrOpers->length = 2;
ptrOpers->elemSize = sizeof(char *);
ptrOpers->data = memoryAlloc(sizeof(char *) * 50);ptrOpers->data[0] = "&";
ptrOpers->data[1] = "*";
long int i = 0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1155");
                        };
                        struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i>0)) {

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1160");
                        };
                        struct Tok pt = nl->data[len(nl)-1];
if ((pt.type==TOKEN_TYPE_VAR)) {
if ((i+1<len(l))) {

                        if (l->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i+1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1163");
                        };
                        struct Tok nt = l->data[i+1];
if ((nt.isValue==false)) {
char * ____BAH_COMPILER_VAR_376 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_376 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_376+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_376+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_376;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = pt;
}
};
i = i+1;
continue;
}
}
else {
char * ____BAH_COMPILER_VAR_377 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_377 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_377+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_377+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_377;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = pt;
}
};
i = i+1;
continue;
}
}
}
}
if (inArrayStr(t.cont,ptrOpers)) {
if ((i>0)) {

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1182");
                        };
                        struct Tok pt = nl->data[len(nl)-1];
if ((pt.isValue==true)) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i = i+1;
continue;
}
}
i = i+1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1191");
                        };
                        struct Tok nt = l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_378 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(t.cont);
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_378 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_378+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_378+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                nt.cont = ____BAH_COMPILER_VAR_378;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = nt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = nt;
}
};
i = i+1;
continue;
}
}
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
i = i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayVars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
if ((guard==true)) {
char found = false;
long int i = 0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1218");
                        };
                        struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i = i+1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1222");
                        };
                        t = l->data[i];
if ((strcmp(t.cont, "[") == 0)) {
found = true;
break;
}
}
}
i = i+1;
};
if ((found==false)) {
return l;
}
}

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1236");
                        };
                        struct Tok ft = l->data[0];
long int i = 0;
for (; (i<len(l)); i = i+1) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1239");
                        };
                        struct Tok t = l->data[i];
if ((strcmp(t.cont, "[") == 0)) {
long int ti = i-1;

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1243");
                        };
                        struct Tok lt = nl->data[len(nl)-1];
if (((lt.type!=TOKEN_TYPE_VAR)&&(lt.type!=TOKEN_TYPE_FUNC))) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
continue;
}
char * tt = getTypeFromToken(&lt,true,elems);
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i = i+1;
long int nbBracks = 1;
for (; (i<len(l)); i = i+1) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1255");
                        };
                        struct Tok it = l->data[i];
if ((strcmp(it.cont, "[") == 0)) {
nbBracks = nbBracks+1;
}
else if ((strcmp(it.cont, "]") == 0)) {
nbBracks = nbBracks-1;
if ((nbBracks==0)) {
break;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = it;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = it;
}
};
};
if ((len(memory)==0)) {
throwErr(&l->data[i],"Expected index not {TOKEN}.");
}
memory = prePross(memory,(lineType)-1,elems);
char split = false;
long int sepPos = 0;
char * cont = "";
long int j = 0;
for (; (j<len(memory)); j = j+1) {

                        if (memory->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", j, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1276");
                        };
                        struct Tok mt = memory->data[j];
if ((strcmp(mt.cont, ":") == 0)) {
sepPos = j;
split = true;
}
char * ____BAH_COMPILER_VAR_379 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(cont);
long int strLen_4 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_379 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_379+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_379+currStrOff, mt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                cont = ____BAH_COMPILER_VAR_379;
};
char * from = "";
char * to = "";
if ((split==true)) {
if ((sepPos==0)) {
from = "0";
}
else {
j = 0;
for (; (j<sepPos); j = j+1) {

                        if (memory->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", j, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1290");
                        };
                        struct Tok mt = memory->data[j];
char * ____BAH_COMPILER_VAR_380 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(from);
long int strLen_2 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_380 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_380+currStrOff, from, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_380+currStrOff, mt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                from = ____BAH_COMPILER_VAR_380;
};
}
if ((sepPos==len(memory)-1)) {
char * ____BAH_COMPILER_VAR_381 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("strlen(");
long int strLen_4 = strlen(lt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_381 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_381+currStrOff, "strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_381+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_381+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                to = ____BAH_COMPILER_VAR_381;
}
else {
j = sepPos+1;
for (; (j<len(memory)); j = j+1) {

                        if (memory->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", j, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1298");
                        };
                        struct Tok mt = memory->data[j];
char * ____BAH_COMPILER_VAR_382 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(to);
long int strLen_2 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_382 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_382+currStrOff, to, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_382+currStrOff, mt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                to = ____BAH_COMPILER_VAR_382;
};
}
}
if ((strcmp(tt, "cpstring") == 0)) {
if ((split==false)) {
char * ____BAH_COMPILER_VAR_383 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("cpstringCharAt(");
long int strLen_4 = strlen(lt.cont);
long int strLen_6 = strlen(",");
long int strLen_8 = strlen(cont);
long int strLen_10 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_383 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_383+currStrOff, "cpstringCharAt(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_383+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_383+currStrOff, ",", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_383+currStrOff, cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_383+currStrOff, ")", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_383;
lt.isFunc = true;
lt.bahType = "char";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = lt;
}
};
}
else {
char * ____BAH_COMPILER_VAR_384 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("cpstringSubsitute(");
long int strLen_4 = strlen(lt.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen(from);
long int strLen_10 = strlen(", ");
long int strLen_12 = strlen(to);
long int strLen_14 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_384 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_384+currStrOff, "cpstringSubsitute(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_384+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_384+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_384+currStrOff, from, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_384+currStrOff, ", ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_384+currStrOff, to, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_384+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_384;
lt.isFunc = true;
lt.bahType = "cpstring";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = lt;
}
};
}
continue;
}
if (strHasPrefix(tt,"map:")) {
strTrimLeft(&tt,4);
struct string elemType = getCType(tt,elems);
if (((ti==0)&&(ltp==LINE_TYPE_VAR))) {
struct variable* ____BAH_COMPILER_VAR_385 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_385->name = "";
____BAH_COMPILER_VAR_385->type = "";
____BAH_COMPILER_VAR_385->isConst = false;
____BAH_COMPILER_VAR_385->constVal = "";
____BAH_COMPILER_VAR_385->isArray = false;
____BAH_COMPILER_VAR_385->from = "";
____BAH_COMPILER_VAR_385->outterScope = false;
____BAH_COMPILER_VAR_385->isGlobal = false;
____BAH_COMPILER_VAR_385->name = genCompilerVar();
____BAH_COMPILER_VAR_385->type = tt;
struct variable* tmpV = ____BAH_COMPILER_VAR_385;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = tmpV;
}
};
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_386 =null;char * ____BAH_COMPILER_VAR_387 =elemType.str(&elemType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_387);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(tmpV->name);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_386 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_386+currStrOff, ____BAH_COMPILER_VAR_387, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_386+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_386+currStrOff, tmpV->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_386+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_386));
}
else {
char * ____BAH_COMPILER_VAR_388 =null;char * ____BAH_COMPILER_VAR_389 =elemType.str(&elemType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_389);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(tmpV->name);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_388 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_388+currStrOff, ____BAH_COMPILER_VAR_389, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_388+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_388+currStrOff, tmpV->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_388+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_388));
}
if (isRCPpointerType(tt)) {
char * ____BAH_COMPILER_VAR_390 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(lt.cont);
long int strLen_4 = strlen("->set(");
long int strLen_6 = strlen(lt.cont);
long int strLen_8 = strlen(", ");
long int strLen_10 = strlen(cont);
long int strLen_12 = strlen(", ");
long int strLen_14 = strlen(tmpV->name);
long int strLen_16 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_390 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_390+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_390+currStrOff, "->set(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_390+currStrOff, lt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_390+currStrOff, ", ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_390+currStrOff, cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_390+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_390+currStrOff, tmpV->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_390+currStrOff, ");\n", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_390;
}
else {
char * ____BAH_COMPILER_VAR_391 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(lt.cont);
long int strLen_4 = strlen("->setAny(");
long int strLen_6 = strlen(lt.cont);
long int strLen_8 = strlen(", ");
long int strLen_10 = strlen(cont);
long int strLen_12 = strlen(", &");
long int strLen_14 = strlen(tmpV->name);
long int strLen_16 = strlen(", sizeof(");
long int strLen_18 = strlen(tmpV->name);
long int strLen_20 = strlen("));\n");
;                            
                    ____BAH_COMPILER_VAR_391 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20);
                    
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, "->setAny(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, lt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, ", ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, ", &", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, tmpV->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, ", sizeof(", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, tmpV->name, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, "));\n", strLen_20);
                        currStrOff += strLen_20;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_391;
}
lt.cont = tmpV->name;
}
else {
if (isRCPpointerType(tt)) {
char * ____BAH_COMPILER_VAR_392 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(lt.cont);
long int strLen_4 = strlen("->get(");
long int strLen_6 = strlen(lt.cont);
long int strLen_8 = strlen(", ");
long int strLen_10 = strlen(cont);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_392 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_392+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_392+currStrOff, "->get(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_392+currStrOff, lt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_392+currStrOff, ", ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_392+currStrOff, cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_392+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_392;
}
else {
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_393 =null;char * ____BAH_COMPILER_VAR_394 =elemType.str(&elemType);char * ____BAH_COMPILER_VAR_395 =intToStr(lt.line);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_394);
long int strLen_2 = strlen("* ");
long int strLen_4 = strlen(tmpV);
long int strLen_6 = strlen(" = ");
long int strLen_8 = strlen(lt.cont);
long int strLen_10 = strlen("->get(");
long int strLen_12 = strlen(lt.cont);
long int strLen_14 = strlen(", ");
long int strLen_16 = strlen(cont);
long int strLen_18 = strlen(");\n                        if(");
long int strLen_20 = strlen(tmpV);
long int strLen_22 = strlen(" == null) {\n                            printf(\"map (");
long int strLen_24 = strlen(compilerState.currentFile);
long int strLen_26 = strlen(":");
long int strLen_28 = strlen(____BAH_COMPILER_VAR_395);
long int strLen_30 = strlen("): ");
long int strLen_32 = strlen(lt.cont);
long int strLen_34 = strlen("[\\\"%s\\\"] does not exist\\n\", ");
long int strLen_36 = strlen(cont);
long int strLen_38 = strlen(");\n                            exit(1);\n                        };");
;                            
                    ____BAH_COMPILER_VAR_393 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34 + strLen_36 + strLen_38);
                    
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, ____BAH_COMPILER_VAR_394, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, "* ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, tmpV, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, " = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, lt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, "->get(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, lt.cont, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, ", ", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, cont, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, ");\n                        if(", strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, tmpV, strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, " == null) {\n                            printf(\"map (", strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, compilerState.currentFile, strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, ":", strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, ____BAH_COMPILER_VAR_395, strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, "): ", strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, lt.cont, strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, "[\\\"%s\\\"] does not exist\\n\", ", strLen_34);
                        currStrOff += strLen_34;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, cont, strLen_36);
                        currStrOff += strLen_36;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, ");\n                            exit(1);\n                        };", strLen_38);
                        currStrOff += strLen_38;
                        
                }
                struct rope* res = rope(____BAH_COMPILER_VAR_393);
char * ____BAH_COMPILER_VAR_396 =null;char * ____BAH_COMPILER_VAR_397 =elemType.str(&elemType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_397);
long int strLen_6 = strlen(")(*");
long int strLen_8 = strlen(tmpV);
long int strLen_10 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_396 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, ____BAH_COMPILER_VAR_397, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, ")(*", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, tmpV, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, ")", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_396;
if (isGlobal()) {
INIT = INIT->add(INIT, res);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, res);
}
}
lt.bahType = tt;
}

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = lt;
}
};
continue;
}
if (strHasPrefix(tt,"buffer:")) {
if ((split==false)) {
char * amm = cpstringSubsitute(tt, 7, strlen(tt));
if ((isUnsafe==false)) {
char * ____BAH_COMPILER_VAR_398 =null;char * ____BAH_COMPILER_VAR_399 =intToStr(lt.line);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                        if (");
long int strLen_2 = strlen(cont);
long int strLen_4 = strlen(" >= ");
long int strLen_6 = strlen(amm);
long int strLen_8 = strlen(") {\n                            printf(\"buffer (");
long int strLen_10 = strlen(compilerState.currentFile);
long int strLen_12 = strlen(":");
long int strLen_14 = strlen(____BAH_COMPILER_VAR_399);
long int strLen_16 = strlen("): ");
long int strLen_18 = strlen(lt.cont);
long int strLen_20 = strlen("[%d] with length %d\\n\", ");
long int strLen_22 = strlen(cont);
long int strLen_24 = strlen(", ");
long int strLen_26 = strlen(amm);
long int strLen_28 = strlen(");\n                            exit(1);\n                        };\n                        ");
;                            
                    ____BAH_COMPILER_VAR_398 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, "\n                        if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, " >= ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, amm, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, ") {\n                            printf(\"buffer (", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, compilerState.currentFile, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, ":", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, ____BAH_COMPILER_VAR_399, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, "): ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, lt.cont, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, "[%d] with length %d\\n\", ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, cont, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, ", ", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, amm, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_398+currStrOff, ");\n                            exit(1);\n                        };\n                        ", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_398));
}
char * ____BAH_COMPILER_VAR_400 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(lt.cont);
long int strLen_4 = strlen("[");
long int strLen_6 = strlen(cont);
long int strLen_8 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_400 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_400+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_400+currStrOff, "[", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_400+currStrOff, cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_400+currStrOff, "]", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_400;
lt.isFunc = false;
lt.bahType = "char";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = lt;
}
};
}
else {
char * ____BAH_COMPILER_VAR_401 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("cpstringSubsitute(");
long int strLen_4 = strlen(lt.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen(from);
long int strLen_10 = strlen(", ");
long int strLen_12 = strlen(to);
long int strLen_14 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_401 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, "cpstringSubsitute(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, from, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, ", ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, to, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_401;
lt.isFunc = true;
lt.bahType = "cpstring";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = lt;
}
};
}
continue;
}
else if ((strHasPrefix(tt,"[]")==false)) {
char * ____BAH_COMPILER_VAR_402 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as an array.");
;                            
                    ____BAH_COMPILER_VAR_402 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_402+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_402+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_402+currStrOff, ") as an array.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&lt,____BAH_COMPILER_VAR_402);
}
strTrimLeft(&tt,2);
if ((split==false)) {
if (((ti>0)&&(strcmp(ft.cont, "else") != 0))) {
if ((isUnsafe==false)) {
char * ____BAH_COMPILER_VAR_403 =null;char * ____BAH_COMPILER_VAR_404 =intToStr(lt.line);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                        if (");
long int strLen_2 = strlen(lt.cont);
long int strLen_4 = strlen("->length <= ");
long int strLen_6 = strlen(cont);
long int strLen_8 = strlen(") {\n                            char buff[300];\n                            snprintf(buff, 299, \"array: ");
long int strLen_10 = strlen(lt.cont);
long int strLen_12 = strlen("[%d] with length %d\", ");
long int strLen_14 = strlen(cont);
long int strLen_16 = strlen(", ");
long int strLen_18 = strlen(lt.cont);
long int strLen_20 = strlen("->length);\n                            __BAH_panic((char*)buff, (char*)\"");
long int strLen_22 = strlen(compilerState.currentFile);
long int strLen_24 = strlen(":");
long int strLen_26 = strlen(____BAH_COMPILER_VAR_404);
long int strLen_28 = strlen("\");\n                        };\n                        ");
;                            
                    ____BAH_COMPILER_VAR_403 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, "\n                        if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, "->length <= ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, ") {\n                            char buff[300];\n                            snprintf(buff, 299, \"array: ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, lt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, "[%d] with length %d\", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, ", ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, lt.cont, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, "->length);\n                            __BAH_panic((char*)buff, (char*)\"", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, compilerState.currentFile, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, ":", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, ____BAH_COMPILER_VAR_404, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, "\");\n                        };\n                        ", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_403));
}
}
char * ____BAH_COMPILER_VAR_405 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(lt.cont);
long int strLen_4 = strlen("->data[");
long int strLen_6 = strlen(cont);
long int strLen_8 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_405 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_405+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_405+currStrOff, "->data[", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_405+currStrOff, cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_405+currStrOff, "]", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_405;
lt.bahType = tt;
}
else {
char * ____BAH_COMPILER_VAR_406 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("[]");
long int strLen_4 = strlen(tt);
;                            
                    ____BAH_COMPILER_VAR_406 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, "[]", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                lt.bahType = ____BAH_COMPILER_VAR_406;
char * ____BAH_COMPILER_VAR_407 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("arraySubstitute(");
long int strLen_4 = strlen(lt.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen(from);
long int strLen_10 = strlen(", ");
long int strLen_12 = strlen(to);
long int strLen_14 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_407 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_407+currStrOff, "arraySubstitute(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_407+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_407+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_407+currStrOff, from, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_407+currStrOff, ", ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_407+currStrOff, to, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_407+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_407;
}

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] = lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] = lt;
}
};
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
};
return nl;
};
char * parseSerialize(struct Tok e,struct Elems* elems){
struct variable* v = searchVar(e.cont,elems);
if ((v==null)) {
throwErr(&e,"Must be a var, not {TOKEN}.");
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
throwErr(&e,"Must be a struct, not {TOKEN}.");
}
struct string svt = string(v->type);
long int ptrLevel = svt.count(&svt,"*");
svt.replace(&svt,"*","");
char * code= null;
if ((ptrLevel==0)) {
char * ____BAH_COMPILER_VAR_408 =null;char * ____BAH_COMPILER_VAR_409 =svt.str(&svt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__serialize(&");
long int strLen_4 = strlen(e.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen("sizeof(struct ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_409);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_408 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_408+currStrOff, "__serialize(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_408+currStrOff, e.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_408+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_408+currStrOff, "sizeof(struct ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_408+currStrOff, ____BAH_COMPILER_VAR_409, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_408+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                code = ____BAH_COMPILER_VAR_408;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_410 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ptrRect);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_410 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_410+currStrOff, ptrRect, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_410+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ptrRect = ____BAH_COMPILER_VAR_410;
ptrLevel = ptrLevel-1;
};
char * ____BAH_COMPILER_VAR_411 =null;char * ____BAH_COMPILER_VAR_412 =svt.str(&svt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__serialize(");
long int strLen_4 = strlen(ptrRect);
long int strLen_6 = strlen(e.cont);
long int strLen_8 = strlen(", ");
long int strLen_10 = strlen("sizeof(struct ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_412);
long int strLen_14 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_411 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, "__serialize(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, ptrRect, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, e.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, ", ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, "sizeof(struct ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, ____BAH_COMPILER_VAR_412, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                code = ____BAH_COMPILER_VAR_411;
long int i = 0;
while ((i<len(s->members))) {

                        if (s->members->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: s->members[%d] with length %d", i, s->members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1451");
                        };
                        struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_413 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen("+strlen(");
long int strLen_6 = strlen(e.cont);
long int strLen_8 = strlen("->");
long int strLen_10 = strlen(m->name);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_413 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_413+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_413+currStrOff, "+strlen(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_413+currStrOff, e.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_413+currStrOff, "->", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_413+currStrOff, m->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_413+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                code = ____BAH_COMPILER_VAR_413;
}
i = i+1;
};
}
char * ____BAH_COMPILER_VAR_414 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_1 = strlen(code);
long int strLen_3 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_414 = memoryAllocSTR(1 + strLen_1 + strLen_3);
                    
                        memcpy(____BAH_COMPILER_VAR_414+currStrOff, code, strLen_1);
                        currStrOff += strLen_1;
                        
                        memcpy(____BAH_COMPILER_VAR_414+currStrOff, ")", strLen_3);
                        currStrOff += strLen_3;
                        
                }
                return ____BAH_COMPILER_VAR_414;
};
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,char parsedPointer,char * ogName,char * offset){
char * isArr = "0";
if (((t.type!=TOKEN_TYPE_VAR)||(t.type!=TOKEN_TYPE_FUNC))) {
struct string cType;
if (strHasPrefix(tt,"function(")) {
cType = string("void*");
}
else {
cType = getCType(tt,elems);
}
char * v = genCompilerVar();
if ((parsedPointer==true)) {
cType.append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_415 =null;char * ____BAH_COMPILER_VAR_416 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_416);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(v);
long int strLen_6 = strlen(" = ");
long int strLen_8 = strlen(t.cont);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_415 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_415+currStrOff, ____BAH_COMPILER_VAR_416, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_415+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_415+currStrOff, v, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_415+currStrOff, " = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_415+currStrOff, t.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_415+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_415));
t.cont = v;
if ((t.type==TOKEN_TYPE_STR)) {
ogName = "[bah cpstring]";
}
}
char * arrElem = "0";
if (strHasPrefix(tt,"[]")) {
isArr = "1";
struct string aet = string(tt);
aet.trimLeft(&aet,2);
struct Tok ____BAH_COMPILER_VAR_417 = {};
____BAH_COMPILER_VAR_417.cont = "";
____BAH_COMPILER_VAR_417.ogCont = "";
____BAH_COMPILER_VAR_417.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_417.pos = 0;
____BAH_COMPILER_VAR_417.line = 1;
____BAH_COMPILER_VAR_417.begLine = 1;
____BAH_COMPILER_VAR_417.bahType = "";
____BAH_COMPILER_VAR_417.isValue = false;
____BAH_COMPILER_VAR_417.isFunc = false;
____BAH_COMPILER_VAR_417.isOper = false;
____BAH_COMPILER_VAR_417.isEqual = false;
#define tmpT ____BAH_COMPILER_VAR_417
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_418 =aet.str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_418,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_419 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_2 = strlen(aev);
long int strLen_4 = strlen(" = ");
long int strLen_6 = strlen(rt.cont);
long int strLen_8 = strlen(";\n        ");
;                            
                    ____BAH_COMPILER_VAR_419 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_419+currStrOff, "\n        struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_419+currStrOff, aev, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_419+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_419+currStrOff, rt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_419+currStrOff, ";\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_419));
char * ____BAH_COMPILER_VAR_420 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("&");
long int strLen_4 = strlen(aev);
;                            
                    ____BAH_COMPILER_VAR_420 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_420+currStrOff, "&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_420+currStrOff, aev, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                arrElem = ____BAH_COMPILER_VAR_420;
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
aet.trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_421 = {};
____BAH_COMPILER_VAR_421.cont = "";
____BAH_COMPILER_VAR_421.ogCont = "";
____BAH_COMPILER_VAR_421.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_421.pos = 0;
____BAH_COMPILER_VAR_421.line = 1;
____BAH_COMPILER_VAR_421.begLine = 1;
____BAH_COMPILER_VAR_421.bahType = "";
____BAH_COMPILER_VAR_421.isValue = false;
____BAH_COMPILER_VAR_421.isFunc = false;
____BAH_COMPILER_VAR_421.isOper = false;
____BAH_COMPILER_VAR_421.isEqual = false;
#define tmpT ____BAH_COMPILER_VAR_421
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_422 =aet.str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_422,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_423 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_2 = strlen(aev);
long int strLen_4 = strlen(" = ");
long int strLen_6 = strlen(rt.cont);
long int strLen_8 = strlen(";\n        ");
;                            
                    ____BAH_COMPILER_VAR_423 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_423+currStrOff, "\n        struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_423+currStrOff, aev, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_423+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_423+currStrOff, rt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_423+currStrOff, ";\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_423));
char * ____BAH_COMPILER_VAR_424 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("&");
long int strLen_4 = strlen(aev);
;                            
                    ____BAH_COMPILER_VAR_424 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_424+currStrOff, "&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_424+currStrOff, aev, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                arrElem = ____BAH_COMPILER_VAR_424;
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_425 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_425->name = "";
____BAH_COMPILER_VAR_425->type = "";
____BAH_COMPILER_VAR_425->isConst = false;
____BAH_COMPILER_VAR_425->constVal = "";
____BAH_COMPILER_VAR_425->isArray = false;
____BAH_COMPILER_VAR_425->from = "";
____BAH_COMPILER_VAR_425->outterScope = false;
____BAH_COMPILER_VAR_425->isGlobal = false;
struct variable* slv = ____BAH_COMPILER_VAR_425;
slv->name = structLayout;
slv->type = "[]reflectElement";

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = slv;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = slv;
}
};
struct rope* dataLayout = rope("");
long int i = 0;
for (; (i<len(ts->members)); i = i+1) {

                        if (ts->members->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: ts->members[%d] with length %d", i, ts->members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1534");
                        };
                        struct structMemb* m = ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_426 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_426->name = "";
____BAH_COMPILER_VAR_426->type = "";
____BAH_COMPILER_VAR_426->isConst = false;
____BAH_COMPILER_VAR_426->constVal = "";
____BAH_COMPILER_VAR_426->isArray = false;
____BAH_COMPILER_VAR_426->from = "";
____BAH_COMPILER_VAR_426->outterScope = false;
____BAH_COMPILER_VAR_426->isGlobal = false;
____BAH_COMPILER_VAR_426->def = "";
____BAH_COMPILER_VAR_426->isFn = false;
struct structMemb* nm = ____BAH_COMPILER_VAR_426;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_427 = {};
____BAH_COMPILER_VAR_427.cont = "";
____BAH_COMPILER_VAR_427.ogCont = "";
____BAH_COMPILER_VAR_427.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_427.pos = 0;
____BAH_COMPILER_VAR_427.line = 1;
____BAH_COMPILER_VAR_427.begLine = 1;
____BAH_COMPILER_VAR_427.bahType = "";
____BAH_COMPILER_VAR_427.isValue = false;
____BAH_COMPILER_VAR_427.isFunc = false;
____BAH_COMPILER_VAR_427.isOper = false;
____BAH_COMPILER_VAR_427.isEqual = false;
#define tmpT ____BAH_COMPILER_VAR_427
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
offsetTT.replace(&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_428 =null;char * ____BAH_COMPILER_VAR_429 =mCtype.str(&mCtype);char * ____BAH_COMPILER_VAR_430 =offsetTT.str(&offsetTT);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_429);
long int strLen_6 = strlen("*)((char*)(");
long int strLen_8 = strlen(t.cont);
long int strLen_10 = strlen(") + offsetof(struct ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_430);
long int strLen_14 = strlen(", ");
long int strLen_16 = strlen(m->name);
long int strLen_18 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_428 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18);
                    
                        memcpy(____BAH_COMPILER_VAR_428+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_428+currStrOff, ____BAH_COMPILER_VAR_429, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_428+currStrOff, "*)((char*)(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_428+currStrOff, t.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_428+currStrOff, ") + offsetof(struct ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_428+currStrOff, ____BAH_COMPILER_VAR_430, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_428+currStrOff, ", ", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_428+currStrOff, m->name, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_428+currStrOff, "))", strLen_18);
                        currStrOff += strLen_18;
                        
                }
                tmpT.cont = ____BAH_COMPILER_VAR_428;
char * ____BAH_COMPILER_VAR_431 =null;char * ____BAH_COMPILER_VAR_432 =offsetTT.str(&offsetTT);
                {
                    long int currStrOff = 0;
                    long int strLen_10 = strlen("offsetof(struct ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_432);
long int strLen_14 = strlen(", ");
long int strLen_16 = strlen(m->name);
long int strLen_18 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_431 = memoryAllocSTR(1 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18);
                    
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, "offsetof(struct ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, ____BAH_COMPILER_VAR_432, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, ", ", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, m->name, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, ")", strLen_18);
                        currStrOff += strLen_18;
                        
                }
                struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_431);
char * ____BAH_COMPILER_VAR_433 =null;char * ____BAH_COMPILER_VAR_434 =intToStr(i);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(structLayout);
long int strLen_2 = strlen("->data[");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_434);
long int strLen_6 = strlen("] = ");
long int strLen_8 = strlen(rt.cont);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_433 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_433+currStrOff, structLayout, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_433+currStrOff, "->data[", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_433+currStrOff, ____BAH_COMPILER_VAR_434, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_433+currStrOff, "] = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_433+currStrOff, rt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_433+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                dataLayout = dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_433));
};
char * ____BAH_COMPILER_VAR_435 =null;char * ____BAH_COMPILER_VAR_436 =intToStr(len(ts->members));
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        array(struct reflectElement) * ");
long int strLen_2 = strlen(structLayout);
long int strLen_4 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_6 = strlen(structLayout);
long int strLen_8 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_10 = strlen(structLayout);
long int strLen_12 = strlen("->length = ");
long int strLen_14 = strlen(____BAH_COMPILER_VAR_436);
long int strLen_16 = strlen(";\n        ");
long int strLen_18 = strlen(structLayout);
long int strLen_20 = strlen("->data = memoryAlloc(");
long int strLen_22 = strlen(structLayout);
long int strLen_24 = strlen("->length * ");
long int strLen_26 = strlen(structLayout);
long int strLen_28 = strlen("->elemSize);\n        ");
;                            
                    ____BAH_COMPILER_VAR_435 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, "\n        array(struct reflectElement) * ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, structLayout, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, structLayout, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, structLayout, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, "->length = ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, ____BAH_COMPILER_VAR_436, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, ";\n        ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, structLayout, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, "->data = memoryAlloc(", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, structLayout, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, "->length * ", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, structLayout, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_435+currStrOff, "->elemSize);\n        ", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_435))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_435)), dataLayout);
}
char * amp = "";
if (((((strCount(tt,"*")==0)&&(strcmp(tt, "cpstring") != 0))&&(strcmp(tt, "ptr") != 0))&&(parsedPointer==false))) {
amp = "&";
}
struct string name = string(ogName);
if ((hasStructSep(name)==true)) {
name = splitStructSepAfter(name);
}
struct string cType;
if (strHasPrefix(tt,"function(")) {
cType = string("void*");
}
else {
cType = getCType(tt,elems);
}
if (cType.hasPrefix(&cType,"struct ")) {
cType.replace(&cType,"*","");
}
if ((cType.length==0)) {
cType.set(&cType,"0");
}
struct variable* ____BAH_COMPILER_VAR_437 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_437->name = "";
____BAH_COMPILER_VAR_437->type = "";
____BAH_COMPILER_VAR_437->isConst = false;
____BAH_COMPILER_VAR_437->constVal = "";
____BAH_COMPILER_VAR_437->isArray = false;
____BAH_COMPILER_VAR_437->from = "";
____BAH_COMPILER_VAR_437->outterScope = false;
____BAH_COMPILER_VAR_437->isGlobal = false;
struct variable* rv = ____BAH_COMPILER_VAR_437;
rv->name = genCompilerVar();
rv->type = "reflectElement";

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = rv;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = rv;
}
};
char * ____BAH_COMPILER_VAR_438 =null;char * ____BAH_COMPILER_VAR_439 =cType.str(&cType);char * ____BAH_COMPILER_VAR_440 =name.str(&name);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct reflectElement ");
long int strLen_2 = strlen(rv->name);
long int strLen_4 = strlen(" = __reflect(");
long int strLen_6 = strlen(amp);
long int strLen_8 = strlen(t.cont);
long int strLen_10 = strlen(", sizeof(");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_439);
long int strLen_14 = strlen("), \"");
long int strLen_16 = strlen(tt);
long int strLen_18 = strlen("\", \"");
long int strLen_20 = strlen(____BAH_COMPILER_VAR_440);
long int strLen_22 = strlen("\", ");
long int strLen_24 = strlen(isArr);
long int strLen_26 = strlen(", ");
long int strLen_28 = strlen(arrElem);
long int strLen_30 = strlen(", ");
long int strLen_32 = strlen(isStruct);
long int strLen_34 = strlen(", ");
long int strLen_36 = strlen(structLayout);
long int strLen_38 = strlen(", ");
long int strLen_40 = strlen(offset);
long int strLen_42 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_438 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34 + strLen_36 + strLen_38 + strLen_40 + strLen_42);
                    
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, "struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, rv->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, " = __reflect(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, amp, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, t.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, ", sizeof(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, ____BAH_COMPILER_VAR_439, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, "), \"", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, tt, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, "\", \"", strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, ____BAH_COMPILER_VAR_440, strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, "\", ", strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, isArr, strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, ", ", strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, arrElem, strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, ", ", strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, isStruct, strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, ", ", strLen_34);
                        currStrOff += strLen_34;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, structLayout, strLen_36);
                        currStrOff += strLen_36;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, ", ", strLen_38);
                        currStrOff += strLen_38;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, offset, strLen_40);
                        currStrOff += strLen_40;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, ");\n", strLen_42);
                        currStrOff += strLen_42;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_438));
t.cont = rv->name;
return t;
};
__BAH_ARR_TYPE_Tok parseFnCall(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
if ((guard==true)) {
char found = false;
long int i = 0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1610");
                        };
                        struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i = i+1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1614");
                        };
                        t = l->data[i];
if ((strcmp(t.cont, "(") == 0)) {
found = true;
break;
}
}
}
i = i+1;
};
if ((found==false)) {
return l;
}
}
long int i = 0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1630");
                        };
                        struct Tok ot = l->data[i];
if ((ot.type==TOKEN_TYPE_VAR)) {
i = i+1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1635");
                        };
                        struct Tok nt = l->data[i];
if ((strcmp(nt.cont, "(") == 0)) {
long int nbPar = 1;
i = i+1;
char * fnName = ot.cont;
struct func* fn = searchFunc(fnName,elems,true);
if ((fn==null)) {
throwErr(&ot,"Unknown function {TOKEN}.");
}
struct string varName = string("");
struct string fnStr = string(fnName);
struct variable* arg1= null;
if (hasStructSep(fnStr)) {

                        if (fn->args->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", 0, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1648");
                        };
                        arg1 = fn->args->data[0];
varName = fnStr;
struct string realFn = splitStructSepAfter(fnStr);
varName.trimRight(&varName,realFn.length);
char c = varName.charAt(&varName,varName.length-1);
if ((c==46)) {
varName.trimRight(&varName,1);
}
else {
varName.trimRight(&varName,2);
}
char * varNameStr = varName.str(&varName);
struct variable* v = searchVar(varNameStr,elems);
if ((v==null)) {
throwErr(&ot,"Cannot use {TOKEN} as a struct.");
}
if ((strCount(v->type,"*")==0)) {
varName.prepend(&varName,"&");
}
}
char * ____BAH_COMPILER_VAR_441 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnName);
long int strLen_4 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_441 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, fnName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_441;
long int paramIndex = 0;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
if ((varName.length>0)) {
struct Tok ____BAH_COMPILER_VAR_442 = {};
____BAH_COMPILER_VAR_442.cont = "";
____BAH_COMPILER_VAR_442.ogCont = "";
____BAH_COMPILER_VAR_442.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_442.pos = 0;
____BAH_COMPILER_VAR_442.line = 1;
____BAH_COMPILER_VAR_442.begLine = 1;
____BAH_COMPILER_VAR_442.bahType = "";
____BAH_COMPILER_VAR_442.isValue = false;
____BAH_COMPILER_VAR_442.isFunc = false;
____BAH_COMPILER_VAR_442.isOper = false;
____BAH_COMPILER_VAR_442.isEqual = false;
#define tk ____BAH_COMPILER_VAR_442
tk.cont = varName.str(&varName);
tk.bahType = arg1->type;
tk.type = TOKEN_TYPE_VAR;
tk.isValue = true;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = tk;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = tk;
}
};

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1681");
                        };
                        nt = l->data[i];
if ((strcmp(nt.cont, ")") != 0)) {
struct Tok ____BAH_COMPILER_VAR_443 = {};
____BAH_COMPILER_VAR_443.cont = "";
____BAH_COMPILER_VAR_443.ogCont = "";
____BAH_COMPILER_VAR_443.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_443.pos = 0;
____BAH_COMPILER_VAR_443.line = 1;
____BAH_COMPILER_VAR_443.begLine = 1;
____BAH_COMPILER_VAR_443.bahType = "";
____BAH_COMPILER_VAR_443.isValue = false;
____BAH_COMPILER_VAR_443.isFunc = false;
____BAH_COMPILER_VAR_443.isOper = false;
____BAH_COMPILER_VAR_443.isEqual = false;
tk = ____BAH_COMPILER_VAR_443;
tk.cont = ",";
tk.type = TOKEN_TYPE_SYNTAX;
tk.isValue = false;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = tk;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = tk;
}
};
}
}
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1691");
                        };
                        struct Tok t = l->data[i];
if ((strcmp(t.cont, "(") == 0)) {
nbPar = nbPar+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPar = nbPar-1;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = t;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = t;
}
};
if ((nbPar==0)) {
i = i+1;
break;
}
i = i+1;
};
if ((strcmp(fnName, "noCheck") == 0)) {
ot.cont = "";
long int j = 0;
while ((j<len(memory)-1)) {

                        if (memory->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", j, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1708");
                        };
                        struct Tok t = memory->data[j];
char * ____BAH_COMPILER_VAR_444 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ot.cont);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_444 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_444+currStrOff, ot.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_444+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_444;
j = j+1;
};
ot.cont = ot.cont;
ot.type = TOKEN_TYPE_FUNC;
ot.isFunc = true;
ot.isOper = true;
ot.bahType = "ptr";

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = ot;
}
};
continue;
}
if ((strcmp(fnName, "panic") == 0)) {
char * ____BAH_COMPILER_VAR_445 =null;char * ____BAH_COMPILER_VAR_446 =intToStr(ot.line);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("\"");
long int strLen_4 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_446);
long int strLen_10 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_445 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_445+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_445+currStrOff, compilerState.currentFile, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_445+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_445+currStrOff, ____BAH_COMPILER_VAR_446, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_445+currStrOff, "\"", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * currLine = ____BAH_COMPILER_VAR_445;

                        if (memory->length <= len(memory)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", len(memory)-1, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1723");
                        };
                        struct Tok par = memory->data[len(memory)-1];
long int cl = par.line;
struct Tok ____BAH_COMPILER_VAR_447 = {};
____BAH_COMPILER_VAR_447.cont = "";
____BAH_COMPILER_VAR_447.ogCont = "";
____BAH_COMPILER_VAR_447.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_447.pos = 0;
____BAH_COMPILER_VAR_447.line = 1;
____BAH_COMPILER_VAR_447.begLine = 1;
____BAH_COMPILER_VAR_447.bahType = "";
____BAH_COMPILER_VAR_447.isValue = false;
____BAH_COMPILER_VAR_447.isFunc = false;
____BAH_COMPILER_VAR_447.isOper = false;
____BAH_COMPILER_VAR_447.isEqual = false;
____BAH_COMPILER_VAR_447.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_447.cont = ",";
____BAH_COMPILER_VAR_447.line = cl;

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)-1] = ____BAH_COMPILER_VAR_447;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] = ____BAH_COMPILER_VAR_447;
}
};
struct Tok ____BAH_COMPILER_VAR_448 = {};
____BAH_COMPILER_VAR_448.cont = "";
____BAH_COMPILER_VAR_448.ogCont = "";
____BAH_COMPILER_VAR_448.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_448.pos = 0;
____BAH_COMPILER_VAR_448.line = 1;
____BAH_COMPILER_VAR_448.begLine = 1;
____BAH_COMPILER_VAR_448.bahType = "";
____BAH_COMPILER_VAR_448.isValue = false;
____BAH_COMPILER_VAR_448.isFunc = false;
____BAH_COMPILER_VAR_448.isOper = false;
____BAH_COMPILER_VAR_448.isEqual = false;
____BAH_COMPILER_VAR_448.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_448.cont = currLine;
____BAH_COMPILER_VAR_448.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_448;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_448;
}
};

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = par;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = par;
}
};
fnName = "__BAH_panic";
char * ____BAH_COMPILER_VAR_449 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnName);
long int strLen_4 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_449 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_449+currStrOff, fnName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_449+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_449;
fn = searchFunc(fnName,elems,true);
}
else if ((strcmp(fnName, "__dumpSymbols") == 0)) {
char * ____BAH_COMPILER_VAR_450 =null;char * ____BAH_COMPILER_VAR_451 =intToStr(ot.line);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("\"");
long int strLen_4 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_451);
long int strLen_10 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_450 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_450+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_450+currStrOff, compilerState.currentFile, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_450+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_450+currStrOff, ____BAH_COMPILER_VAR_451, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_450+currStrOff, "\"", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * currLine = ____BAH_COMPILER_VAR_450;

                        if (memory->length <= len(memory)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", len(memory)-1, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1741");
                        };
                        struct Tok par = memory->data[len(memory)-1];
long int cl = par.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);
long int j = 0;
for (; (j<len(elems->vars)); j = j+1) {

                        if (elems->vars->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", j, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1747");
                        };
                        struct variable* v = elems->vars->data[j];
if ((v->isConst==false)) {

{
long nLength = len(symbols);
if (symbols->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(symbols->data, (nLength+50)*sizeof(struct variable*));
symbols->data = newPtr;
}
symbols->data[len(symbols)] = v;
symbols->length = nLength+1;
} else {
symbols->data[len(symbols)] = v;
}
};
}
};
struct variable* ____BAH_COMPILER_VAR_452 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_452->name = "";
____BAH_COMPILER_VAR_452->type = "";
____BAH_COMPILER_VAR_452->isConst = false;
____BAH_COMPILER_VAR_452->constVal = "";
____BAH_COMPILER_VAR_452->isArray = false;
____BAH_COMPILER_VAR_452->from = "";
____BAH_COMPILER_VAR_452->outterScope = false;
____BAH_COMPILER_VAR_452->isGlobal = false;
____BAH_COMPILER_VAR_452->name = genCompilerVar();
____BAH_COMPILER_VAR_452->type = "[]reflectElement";
____BAH_COMPILER_VAR_452->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_452;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = tmpV;
}
};
char * decls = "";
j = 0;
for (; (j<len(symbols)); j = j+1) {

                        if (symbols->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: symbols[%d] with length %d", j, symbols->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1762");
                        };
                        struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_453 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("&");
long int strLen_4 = strlen(v->name);
;                            
                    ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_453+currStrOff, "&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_453+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                vname = ____BAH_COMPILER_VAR_453;
}
struct Tok ____BAH_COMPILER_VAR_454 = {};
____BAH_COMPILER_VAR_454.cont = "";
____BAH_COMPILER_VAR_454.ogCont = "";
____BAH_COMPILER_VAR_454.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_454.pos = 0;
____BAH_COMPILER_VAR_454.line = 1;
____BAH_COMPILER_VAR_454.begLine = 1;
____BAH_COMPILER_VAR_454.bahType = "";
____BAH_COMPILER_VAR_454.isValue = false;
____BAH_COMPILER_VAR_454.isFunc = false;
____BAH_COMPILER_VAR_454.isOper = false;
____BAH_COMPILER_VAR_454.isEqual = false;
____BAH_COMPILER_VAR_454.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_454.cont = vname;
____BAH_COMPILER_VAR_454.bahType = v->type;
____BAH_COMPILER_VAR_454.isValue = true;
#define tmpT ____BAH_COMPILER_VAR_454
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_455 =null;char * ____BAH_COMPILER_VAR_456 =intToStr(j);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpV->name);
long int strLen_4 = strlen("->data[");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_456);
long int strLen_8 = strlen("] = ");
long int strLen_10 = strlen(tmpT.cont);
long int strLen_12 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_455 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_455+currStrOff, tmpV->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_455+currStrOff, "->data[", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_455+currStrOff, ____BAH_COMPILER_VAR_456, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_455+currStrOff, "] = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_455+currStrOff, tmpT.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_455+currStrOff, ";\n", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                char * ____BAH_COMPILER_VAR_457 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(decls);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_455);
;                            
                    ____BAH_COMPILER_VAR_457 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_457+currStrOff, decls, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_457+currStrOff, ____BAH_COMPILER_VAR_455, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                decls = ____BAH_COMPILER_VAR_457;
};
char * ____BAH_COMPILER_VAR_458 =null;char * ____BAH_COMPILER_VAR_459 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_460 =intToStr(len(symbols));
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                        array(struct reflectElement)* ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_4 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n                        ");
long int strLen_6 = strlen(tmpV->name);
long int strLen_8 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_459);
long int strLen_12 = strlen(");\n                        ");
long int strLen_14 = strlen(tmpV->name);
long int strLen_16 = strlen("->length = ");
long int strLen_18 = strlen(____BAH_COMPILER_VAR_460);
long int strLen_20 = strlen(";\n                        ");
long int strLen_22 = strlen(tmpV->name);
long int strLen_24 = strlen("->elemSize = sizeof(struct reflectElement);\n                        ");
long int strLen_26 = strlen(decls);
long int strLen_28 = strlen("\n                        ");
;                            
                    ____BAH_COMPILER_VAR_458 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, "\n                        array(struct reflectElement)* ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, tmpV->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n                        ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, tmpV->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, ____BAH_COMPILER_VAR_459, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, ");\n                        ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, tmpV->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, "->length = ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, ____BAH_COMPILER_VAR_460, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, ";\n                        ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, tmpV->name, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, "->elemSize = sizeof(struct reflectElement);\n                        ", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, decls, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, "\n                        ", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_458));
struct Tok ____BAH_COMPILER_VAR_461 = {};
____BAH_COMPILER_VAR_461.cont = "";
____BAH_COMPILER_VAR_461.ogCont = "";
____BAH_COMPILER_VAR_461.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_461.pos = 0;
____BAH_COMPILER_VAR_461.line = 1;
____BAH_COMPILER_VAR_461.begLine = 1;
____BAH_COMPILER_VAR_461.bahType = "";
____BAH_COMPILER_VAR_461.isValue = false;
____BAH_COMPILER_VAR_461.isFunc = false;
____BAH_COMPILER_VAR_461.isOper = false;
____BAH_COMPILER_VAR_461.isEqual = false;
____BAH_COMPILER_VAR_461.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_461.cont = tmpV->name;
____BAH_COMPILER_VAR_461.line = cl;
____BAH_COMPILER_VAR_461.isValue = true;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[0] = ____BAH_COMPILER_VAR_461;
memory->length = nLength+1;
} else {
memory->data[0] = ____BAH_COMPILER_VAR_461;
}
};

{
long nLength = 1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[1] = par;
memory->length = nLength+1;
} else {
memory->data[1] = par;
}
};
}
else if ((strcmp(fnName, "breakPoint") == 0)) {
char * ____BAH_COMPILER_VAR_462 =null;char * ____BAH_COMPILER_VAR_463 =intToStr(ot.line);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("\"");
long int strLen_4 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_463);
long int strLen_10 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_462 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_462+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_462+currStrOff, compilerState.currentFile, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_462+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_462+currStrOff, ____BAH_COMPILER_VAR_463, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_462+currStrOff, "\"", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * currLine = ____BAH_COMPILER_VAR_462;

                        if (memory->length <= len(memory)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", len(memory)-1, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1796");
                        };
                        struct Tok par = memory->data[len(memory)-1];
long int cl = par.line;
struct Tok ____BAH_COMPILER_VAR_464 = {};
____BAH_COMPILER_VAR_464.cont = "";
____BAH_COMPILER_VAR_464.ogCont = "";
____BAH_COMPILER_VAR_464.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_464.pos = 0;
____BAH_COMPILER_VAR_464.line = 1;
____BAH_COMPILER_VAR_464.begLine = 1;
____BAH_COMPILER_VAR_464.bahType = "";
____BAH_COMPILER_VAR_464.isValue = false;
____BAH_COMPILER_VAR_464.isFunc = false;
____BAH_COMPILER_VAR_464.isOper = false;
____BAH_COMPILER_VAR_464.isEqual = false;
____BAH_COMPILER_VAR_464.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_464.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_464.line = cl;
struct Tok ____BAH_COMPILER_VAR_465 = {};
____BAH_COMPILER_VAR_465.cont = "";
____BAH_COMPILER_VAR_465.ogCont = "";
____BAH_COMPILER_VAR_465.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_465.pos = 0;
____BAH_COMPILER_VAR_465.line = 1;
____BAH_COMPILER_VAR_465.begLine = 1;
____BAH_COMPILER_VAR_465.bahType = "";
____BAH_COMPILER_VAR_465.isValue = false;
____BAH_COMPILER_VAR_465.isFunc = false;
____BAH_COMPILER_VAR_465.isOper = false;
____BAH_COMPILER_VAR_465.isEqual = false;
____BAH_COMPILER_VAR_465.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_465.cont = "(";
____BAH_COMPILER_VAR_465.line = cl;
struct Tok ____BAH_COMPILER_VAR_466 = {};
____BAH_COMPILER_VAR_466.cont = "";
____BAH_COMPILER_VAR_466.ogCont = "";
____BAH_COMPILER_VAR_466.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_466.pos = 0;
____BAH_COMPILER_VAR_466.line = 1;
____BAH_COMPILER_VAR_466.begLine = 1;
____BAH_COMPILER_VAR_466.bahType = "";
____BAH_COMPILER_VAR_466.isValue = false;
____BAH_COMPILER_VAR_466.isFunc = false;
____BAH_COMPILER_VAR_466.isOper = false;
____BAH_COMPILER_VAR_466.isEqual = false;
____BAH_COMPILER_VAR_466.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_466.cont = ")";
____BAH_COMPILER_VAR_466.line = cl;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);memory->data[0] = ____BAH_COMPILER_VAR_464;
memory->data[1] = ____BAH_COMPILER_VAR_465;
memory->data[2] = ____BAH_COMPILER_VAR_466;
memory = parseFnCall(memory,(lineType)-1,elems,false);
struct Tok ____BAH_COMPILER_VAR_467 = {};
____BAH_COMPILER_VAR_467.cont = "";
____BAH_COMPILER_VAR_467.ogCont = "";
____BAH_COMPILER_VAR_467.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_467.pos = 0;
____BAH_COMPILER_VAR_467.line = 1;
____BAH_COMPILER_VAR_467.begLine = 1;
____BAH_COMPILER_VAR_467.bahType = "";
____BAH_COMPILER_VAR_467.isValue = false;
____BAH_COMPILER_VAR_467.isFunc = false;
____BAH_COMPILER_VAR_467.isOper = false;
____BAH_COMPILER_VAR_467.isEqual = false;
____BAH_COMPILER_VAR_467.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_467.cont = ",";
____BAH_COMPILER_VAR_467.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_467;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_467;
}
};
struct Tok ____BAH_COMPILER_VAR_468 = {};
____BAH_COMPILER_VAR_468.cont = "";
____BAH_COMPILER_VAR_468.ogCont = "";
____BAH_COMPILER_VAR_468.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_468.pos = 0;
____BAH_COMPILER_VAR_468.line = 1;
____BAH_COMPILER_VAR_468.begLine = 1;
____BAH_COMPILER_VAR_468.bahType = "";
____BAH_COMPILER_VAR_468.isValue = false;
____BAH_COMPILER_VAR_468.isFunc = false;
____BAH_COMPILER_VAR_468.isOper = false;
____BAH_COMPILER_VAR_468.isEqual = false;
____BAH_COMPILER_VAR_468.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_468.cont = currLine;
____BAH_COMPILER_VAR_468.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_468;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_468;
}
};

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = par;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = par;
}
};
fnName = "breakPoint__inner";
char * ____BAH_COMPILER_VAR_469 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnName);
long int strLen_4 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_469 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_469+currStrOff, fnName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_469+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_469;
fn = searchFunc(fnName,elems,true);
}
else if ((strcmp(fnName, "sizeof") == 0)) {
char * tp = "";
long int j = 0;
for (; (j<len(memory)-1); j = j+1) {

                        if (memory->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", j, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1837");
                        };
                        struct Tok t = memory->data[j];
char * ____BAH_COMPILER_VAR_470 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tp);
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_470 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_470+currStrOff, tp, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_470+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                tp = ____BAH_COMPILER_VAR_470;
};
struct string cType = getCType(tp,elems);
char * ____BAH_COMPILER_VAR_471 =null;char * ____BAH_COMPILER_VAR_472 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_472);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_471 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_471+currStrOff, ____BAH_COMPILER_VAR_472, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_471+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * ____BAH_COMPILER_VAR_473 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_471);
;                            
                    ____BAH_COMPILER_VAR_473 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_473+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_473+currStrOff, ____BAH_COMPILER_VAR_471, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_473;
ot.type = TOKEN_TYPE_FUNC;
ot.isFunc = true;
ot.bahType = "int";

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = ot;
}
};
continue;
}
memory = prePross(memory,ltp,elems);

                        if (memory->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", 0, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1863");
                        };
                        struct Tok ft = memory->data[0];
array(struct Tok)* fnArgs = memoryAlloc(sizeof(array(struct Tok)));

fnArgs->length = 0;
fnArgs->elemSize = sizeof(struct Tok);
if ((strcmp(ft.cont, ")") != 0)) {
long int j = 0;
while ((j<len(memory))) {

                        if (memory->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", j, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1870");
                        };
                        struct Tok t = memory->data[j];
if ((paramIndex>=len(fn->args))) {
throwErr(&t,"Too many arguments in function call.");
}

                        if (fn->args->length <= paramIndex) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", paramIndex, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1875");
                        };
                        struct variable* arg = fn->args->data[paramIndex];
char * tt = getTypeFromToken(&t,true,elems);
if (((strcmp(arg->type, "reflectElement") == 0)&&(strcmp(tt, "reflectElement") != 0))) {
t = parseReflect(t,tt,elems,false,t.cont,"0");
tt = "reflectElement";
}
if ((compTypes(tt,arg->type)==false)) {
char * ____BAH_COMPILER_VAR_474 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(arg->type);
long int strLen_10 = strlen(" in function call.");
;                            
                    ____BAH_COMPILER_VAR_474 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_474+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_474+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_474+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_474+currStrOff, arg->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_474+currStrOff, " in function call.", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_474);
}
if ((((((((RCPavailable()==true)&&(ltp==LINE_TYPE_VAR))&&(t.type==TOKEN_TYPE_VAR))&&(t.isOper==false))&&(currSetVar!=null))&&(strcmp(t.cont, currSetVar->name) == 0))&&isRCPtype(currSetVar->type,elems))) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(currSetVar,elems));
}
if (((t.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(t.cont,"noCheck(")==false))) {
struct string ____BAH_COMPILER_VAR_475 =string(t.cont);char * afnName = splitStringBefore(____BAH_COMPILER_VAR_475,"(");
struct func* afn = searchFunc(afnName,elems,true);
if (((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true))) {
t.cont = registerRCPvar(afn->returns->type,t.cont,elems);
}
}
if ((verboseRuntime==true)) {

{
long nLength = len(fnArgs);
if (fnArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fnArgs->data, (nLength+50)*sizeof(struct Tok));
fnArgs->data = newPtr;
}
fnArgs->data[len(fnArgs)] = t;
fnArgs->length = nLength+1;
} else {
fnArgs->data[len(fnArgs)] = t;
}
};
}
char * ____BAH_COMPILER_VAR_476 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ot.cont);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_476 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_476+currStrOff, ot.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_476+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_476;
j = j+1;

                        if (memory->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", j, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1905");
                        };
                        t = memory->data[j];
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, ")") == 0)) {
j = j+1;
paramIndex = paramIndex+1;
break;
}
else {
throwErr(&t,"Expected separator between values, not {TOKEN} in function call.");
}
}
else {
paramIndex = paramIndex+1;
char * ____BAH_COMPILER_VAR_477 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ot.cont);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_477 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_477+currStrOff, ot.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_477+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_477;
}
j = j+1;
};
}
if ((paramIndex<len(fn->args))) {
ot.cont = fnName;
throwErr(&ot,"Not enough arguments in function call, ending by {TOKEN}.");
}
if ((strcmp(fn->name, "ser") == 0)) {
ot.cont = parseSerialize(memory->data[0],elems);
}
else {
char * ____BAH_COMPILER_VAR_478 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ot.cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_478 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_478+currStrOff, ot.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_478+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_478;
}
ot.type = TOKEN_TYPE_FUNC;
ot.bahType = fn->returns->type;
ot.isFunc = true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = ot;
}
};

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1941");
                        };
                        ft = l->data[0];
if (((verboseRuntime==true)&&(ltp!=LINE_TYPE_ELSE))) {
verboseOutFunc(fn,fnArgs,ft.line,elems);
}
continue;
}
}
i = i-1;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = ot;
}
};
i = i+1;
};
return nl;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength = 0;
struct string arrType = getCType(v->type,elems);
arrType.trimRight(&arrType,1);
char * ____BAH_COMPILER_VAR_479 =null;char * ____BAH_COMPILER_VAR_480 =arrType.str(&arrType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("memoryAlloc(sizeof(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_480);
long int strLen_6 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_479 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_479+currStrOff, "memoryAlloc(sizeof(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_479+currStrOff, ____BAH_COMPILER_VAR_480, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_479+currStrOff, "))", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * code = ____BAH_COMPILER_VAR_479;
arrType.trimLeft(&arrType,6);
arrType.trimRight(&arrType,1);
char * elemTypeStr = arrType.str(&arrType);
if ((i+1!=max)) {
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1971");
                        };
                        struct Tok nt = l->data[i];
if ((strcmp(nt.cont, "{") != 0)) {
throwErr(&l->data[i+1],"{TOKEN} not expected after array initialization.");
}
struct string elemBahType = string(v->type);
elemBahType.trimLeft(&elemBahType,2);
char * elemBahTypeStr = elemBahType.str(&elemBahType);
i = i+1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
while ((i<max)) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1981");
                        };
                        
{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] = l->data[i];
}
};
i = i+1;
};
memory = prePross(memory,(lineType)-1,elems);
i = 0;
while ((i<len(memory))) {

                        if (memory->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", i, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1986");
                        };
                        struct Tok t = memory->data[i];
if ((strcmp(t.cont, "{") == 0)) {
long int j = i-1;
long int nbBraces = 0;
for (; (i<len(memory)); i = i+1) {

                        if (memory->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", i, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1992");
                        };
                        struct Tok tmpT = memory->data[i];
if ((strcmp(tmpT.cont, "{") == 0)) {
nbBraces = nbBraces+1;
}
else if ((strcmp(tmpT.cont, "}") == 0)) {
nbBraces = nbBraces-1;
}
if ((nbBraces==0)) {
break;
}
};
struct variable* ____BAH_COMPILER_VAR_481 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_481->name = "";
____BAH_COMPILER_VAR_481->type = "";
____BAH_COMPILER_VAR_481->isConst = false;
____BAH_COMPILER_VAR_481->constVal = "";
____BAH_COMPILER_VAR_481->isArray = false;
____BAH_COMPILER_VAR_481->from = "";
____BAH_COMPILER_VAR_481->outterScope = false;
____BAH_COMPILER_VAR_481->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_481;
tmpV->name = genCompilerVar();
struct string elemType = string(v->type);
elemType.trimLeft(&elemType,2);
tmpV->type = elemType.str(&elemType);

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = tmpV;
}
};
char * oldNL = NEXT_LINE;
NEXT_LINE = "";
char * innerCode = parseArrayDecl(tmpV,memory,j,i+1,elems);
char * ____BAH_COMPILER_VAR_482 =elemType.str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_482,elems);
char * ____BAH_COMPILER_VAR_483 =null;char * ____BAH_COMPILER_VAR_484 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                array(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_484);
long int strLen_4 = strlen(") * ");
long int strLen_6 = strlen(tmpV->name);
long int strLen_8 = strlen(" = ");
long int strLen_10 = strlen(innerCode);
long int strLen_12 = strlen(";\n                ");
long int strLen_14 = strlen(NEXT_LINE);
long int strLen_16 = strlen("\n                ");
;                            
                    ____BAH_COMPILER_VAR_483 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_483+currStrOff, "\n                array(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_483+currStrOff, ____BAH_COMPILER_VAR_484, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_483+currStrOff, ") * ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_483+currStrOff, tmpV->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_483+currStrOff, " = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_483+currStrOff, innerCode, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_483+currStrOff, ";\n                ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_483+currStrOff, NEXT_LINE, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_483+currStrOff, "\n                ", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_483));
NEXT_LINE = oldNL;
struct Tok ____BAH_COMPILER_VAR_485 = {};
____BAH_COMPILER_VAR_485.cont = "";
____BAH_COMPILER_VAR_485.ogCont = "";
____BAH_COMPILER_VAR_485.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_485.pos = 0;
____BAH_COMPILER_VAR_485.line = 1;
____BAH_COMPILER_VAR_485.begLine = 1;
____BAH_COMPILER_VAR_485.bahType = "";
____BAH_COMPILER_VAR_485.isValue = false;
____BAH_COMPILER_VAR_485.isFunc = false;
____BAH_COMPILER_VAR_485.isOper = false;
____BAH_COMPILER_VAR_485.isEqual = false;
____BAH_COMPILER_VAR_485.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_485.cont = tmpV->name;
____BAH_COMPILER_VAR_485.bahType = elemType.str(&elemType);
____BAH_COMPILER_VAR_485.isValue = true;
t = ____BAH_COMPILER_VAR_485;
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_486 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(elemBahTypeStr);
;                            
                    ____BAH_COMPILER_VAR_486 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, elemBahTypeStr, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_486);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char * ____BAH_COMPILER_VAR_487 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(NEXT_LINE);
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen("->data[");
long int strLen_8 = strlen(strArrayLength);
long int strLen_10 = strlen("] = ");
long int strLen_12 = strlen(t.cont);
long int strLen_14 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_487 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_487+currStrOff, NEXT_LINE, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_487+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_487+currStrOff, "->data[", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_487+currStrOff, strArrayLength, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_487+currStrOff, "] = ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_487+currStrOff, t.cont, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_487+currStrOff, ";\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_487;
i = i+1;

                        if (memory->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", i, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2037");
                        };
                        t = memory->data[i];
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, "}") == 0)) {
long int allocLength = arrayLength;
if ((allocLength>50)) {
long int modAllocAmm = allocLength%50;
allocLength = allocLength+modAllocAmm;
}
else {
allocLength = 50;
}
char * allocLengthStr = intToStr(allocLength);
char * ____BAH_COMPILER_VAR_488 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen("->data = memoryAlloc(sizeof(");
long int strLen_6 = strlen(elemTypeStr);
long int strLen_8 = strlen(") * ");
long int strLen_10 = strlen(allocLengthStr);
long int strLen_12 = strlen(");");
long int strLen_14 = strlen(NEXT_LINE);
;                            
                    ____BAH_COMPILER_VAR_488 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_488+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_488+currStrOff, "->data = memoryAlloc(sizeof(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_488+currStrOff, elemTypeStr, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_488+currStrOff, ") * ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_488+currStrOff, allocLengthStr, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_488+currStrOff, ");", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_488+currStrOff, NEXT_LINE, strLen_14);
                        currStrOff += strLen_14;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_488;
break;
}
else {
throwErr(&t,"Expected ',' got {TOKEN}.");
}
}
i = i+1;
};
}
char * strArrayLength = intToStr(arrayLength);
char * ____BAH_COMPILER_VAR_489 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("\n");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen("->length = ");
long int strLen_8 = strlen(strArrayLength);
long int strLen_10 = strlen(";\n");
long int strLen_12 = strlen(v->name);
long int strLen_14 = strlen("->elemSize = sizeof(");
long int strLen_16 = strlen(elemTypeStr);
long int strLen_18 = strlen(");\n");
long int strLen_20 = strlen(NEXT_LINE);
;                            
                    ____BAH_COMPILER_VAR_489 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20);
                    
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, "\n", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, "->length = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, strArrayLength, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, v->name, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, "->elemSize = sizeof(", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, elemTypeStr, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, ");\n", strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, NEXT_LINE, strLen_20);
                        currStrOff += strLen_20;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_489;
return code;
};
array(char *)* equalsTokens;
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2070");
                        };
                        struct Tok ft = l->data[0];
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2075");
                        };
                        ft = l->data[0];
char parsed = true;
char * ____BAH_COMPILER_VAR_490 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_490 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_490+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_490+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_490));
return;
}
l = parseStructType(l,(lineType)-1,elems);
char isEqual = false;
char toVar = false;
char isPointedVar = false;
char isStruct = false;
char * currentType = "";
char needsDefine = false;

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2087");
                        };
                        ft = l->data[0];
struct variable* v = searchVar(ft.cont,elems);
char exists = true;
char * ogName= null;
if ((v==null)) {
exists = false;
struct variable* ____BAH_COMPILER_VAR_491 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_491->name = "";
____BAH_COMPILER_VAR_491->type = "";
____BAH_COMPILER_VAR_491->isConst = false;
____BAH_COMPILER_VAR_491->constVal = "";
____BAH_COMPILER_VAR_491->isArray = false;
____BAH_COMPILER_VAR_491->from = "";
____BAH_COMPILER_VAR_491->outterScope = false;
____BAH_COMPILER_VAR_491->isGlobal = false;
v = ____BAH_COMPILER_VAR_491;
v->name = ft.cont;
v->type = "";
}
else {
ogName = v->name;
}
if ((v->isConst==true)) {
throwErr(&ft,"Cannot set the value of const {TOKEN}.");
}
char * code = "";
if (((exists==true)&&isGlobal())) {
throwErr(&ft,"Cannot redeclare global variable {TOKEN}.");
}
if ((len(l)==2)) {

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2109");
                        };
                        struct Tok lt = l->data[1];
if ((((lt.type==TOKEN_TYPE_SYNTAX)&&(strcmp(lt.cont, "++") == 0))||(strcmp(lt.cont, "--") == 0))) {
if ((exists==false)) {
char * ____BAH_COMPILER_VAR_492 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use '");
long int strLen_4 = strlen(lt.cont);
long int strLen_6 = strlen("' on non declared {TOKEN} variable.");
;                            
                    ____BAH_COMPILER_VAR_492 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, "Cannot use '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, "' on non declared {TOKEN} variable.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&ft,____BAH_COMPILER_VAR_492);
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2115");
                        };
                        
{
long nLength = 0;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[0] = l->data[0];
nl->length = nLength+1;
} else {
nl->data[0] = l->data[0];
}
};
struct Tok ____BAH_COMPILER_VAR_493 = {};
____BAH_COMPILER_VAR_493.cont = "";
____BAH_COMPILER_VAR_493.ogCont = "";
____BAH_COMPILER_VAR_493.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_493.pos = 0;
____BAH_COMPILER_VAR_493.line = 1;
____BAH_COMPILER_VAR_493.begLine = 1;
____BAH_COMPILER_VAR_493.bahType = "";
____BAH_COMPILER_VAR_493.isValue = false;
____BAH_COMPILER_VAR_493.isFunc = false;
____BAH_COMPILER_VAR_493.isOper = false;
____BAH_COMPILER_VAR_493.isEqual = false;
____BAH_COMPILER_VAR_493.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_493.cont = "=";
____BAH_COMPILER_VAR_493.isValue = false;

{
long nLength = 1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[1] = ____BAH_COMPILER_VAR_493;
nl->length = nLength+1;
} else {
nl->data[1] = ____BAH_COMPILER_VAR_493;
}
};
char * c = "";
if ((strcmp(lt.cont, "++") == 0)) {
char * ____BAH_COMPILER_VAR_494 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ft.cont);
long int strLen_4 = strlen("+1");
;                            
                    ____BAH_COMPILER_VAR_494 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_494+currStrOff, ft.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_494+currStrOff, "+1", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                c = ____BAH_COMPILER_VAR_494;
}
else if ((strcmp(lt.cont, "--") == 0)) {
char * ____BAH_COMPILER_VAR_495 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ft.cont);
long int strLen_4 = strlen("-1");
;                            
                    ____BAH_COMPILER_VAR_495 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_495+currStrOff, ft.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_495+currStrOff, "-1", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                c = ____BAH_COMPILER_VAR_495;
}
long int ltl = lt.line;
long int ltp = lt.pos;
char * ltc = lt.cont;
struct Tok ____BAH_COMPILER_VAR_496 = {};
____BAH_COMPILER_VAR_496.cont = "";
____BAH_COMPILER_VAR_496.ogCont = "";
____BAH_COMPILER_VAR_496.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_496.pos = 0;
____BAH_COMPILER_VAR_496.line = 1;
____BAH_COMPILER_VAR_496.begLine = 1;
____BAH_COMPILER_VAR_496.bahType = "";
____BAH_COMPILER_VAR_496.isValue = false;
____BAH_COMPILER_VAR_496.isFunc = false;
____BAH_COMPILER_VAR_496.isOper = false;
____BAH_COMPILER_VAR_496.isEqual = false;
____BAH_COMPILER_VAR_496.type = TOKEN_TYPE_INT;
____BAH_COMPILER_VAR_496.cont = c;
____BAH_COMPILER_VAR_496.line = ltl;
____BAH_COMPILER_VAR_496.ogCont = ltc;
____BAH_COMPILER_VAR_496.pos = ltp;
____BAH_COMPILER_VAR_496.isOper = true;
____BAH_COMPILER_VAR_496.isValue = true;

{
long nLength = 2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[2] = ____BAH_COMPILER_VAR_496;
nl->length = nLength+1;
} else {
nl->data[2] = ____BAH_COMPILER_VAR_496;
}
};
l = nl;
}
}
if ((len(l)<2)) {
throwErr(&ft,"Missing '=' after {TOKEN}.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2150");
                        };
                        struct Tok operT = l->data[1];

                int ____BAH_COMPILER_VAR_497 = 0;
                for(int i=len(equalsTokens)-1; i != -1; i--) {
                    if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                        ____BAH_COMPILER_VAR_497 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_497&&(strcmp(operT.cont, "=") != 0))) {

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2152");
                        };
                        array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = l->data[0];
if ((2==len(l))) {
throwErr(&operT,"Cannot use {TOKEN} on nothing.");
}
struct string oper = string(operT.cont);
oper.trimRight(&oper,1);
struct Tok operTok = operT;
operTok.cont = oper.str(&oper);

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2164");
                        };
                        array(struct Tok)* tmpL = memoryAlloc(sizeof(array(struct Tok)));

tmpL->length = 3;
tmpL->elemSize = sizeof(struct Tok);
tmpL->data = memoryAlloc(sizeof(struct Tok) * 50);tmpL->data[0] = ft;
tmpL->data[1] = operTok;
tmpL->data[2] = l->data[2];
tmpL = parseOperations(tmpL,LINE_TYPE_VAR,elems);
operT.cont = "=";

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = operT;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = operT;
}
};
long int j = 0;
for (; (j<len(tmpL)); j = j+1) {

                        if (tmpL->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: tmpL[%d] with length %d", j, tmpL->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2173");
                        };
                        
{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = tmpL->data[j];
nl->length = nLength+1;
} else {
nl->data[len(nl)] = tmpL->data[j];
}
};
};
l = nl;
}
long int i = 1;
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2181");
                        };
                        struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "=") == 0)) {
if ((strlen(currentType)>0)) {
struct string sct = string(currentType);
sct.replace(&sct," ","");
v->type = sct.str(&sct);
}
isEqual = true;
i = i+1;
continue;
}
}
if ((isEqual==false)) {
char * ____BAH_COMPILER_VAR_498 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(currentType);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_498 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_498+currStrOff, currentType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_498+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                currentType = ____BAH_COMPILER_VAR_498;
}
else {
if ((((t.isEqual==true)&&(exists==false))&&(isGlobal()==false))) {
needsDefine = true;
}
if ((strcmp(t.cont, "chan") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2207");
                        };
                        struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_499 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("chan:");
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_499 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_499+currStrOff, "chan:", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_499+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                v->type = ____BAH_COMPILER_VAR_499;
code = "channel()";
if ((i+1!=len(l))) {

                        if (l->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i+1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2211");
                        };
                        struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after channel declaration.");
}
break;
}
else if ((strcmp(t.cont, "map") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (map <type>).");
}
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2220");
                        };
                        struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_500 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("map:");
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_500 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_500+currStrOff, "map:", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_500+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                v->type = ____BAH_COMPILER_VAR_500;
code = "mapWrapper()";
if ((i+1!=len(l))) {

                        if (l->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i+1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2224");
                        };
                        struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after map declaration.");
}
break;
}
else if ((strcmp(t.cont, "buffer") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a length (buffer <length>).");
}
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2233");
                        };
                        struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_INT)) {
throwErr(&nt,"Expected buffer length, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_501 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("buffer:");
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_501 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_501+currStrOff, "buffer:", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_501+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                v->type = ____BAH_COMPILER_VAR_501;
struct variable* ____BAH_COMPILER_VAR_502 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_502->name = "";
____BAH_COMPILER_VAR_502->type = "";
____BAH_COMPILER_VAR_502->isConst = false;
____BAH_COMPILER_VAR_502->constVal = "";
____BAH_COMPILER_VAR_502->isArray = false;
____BAH_COMPILER_VAR_502->from = "";
____BAH_COMPILER_VAR_502->outterScope = false;
____BAH_COMPILER_VAR_502->isGlobal = false;
struct variable* av = ____BAH_COMPILER_VAR_502;
av->type = "char*";
av->name = genCompilerVar();

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = av;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = av;
}
};
struct string cType = getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_503 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("char ");
long int strLen_2 = strlen(av->name);
long int strLen_4 = strlen("[");
long int strLen_6 = strlen(nt.cont);
long int strLen_8 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_503 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_503+currStrOff, "char ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_503+currStrOff, av->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_503+currStrOff, "[", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_503+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_503+currStrOff, "];", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_503));
code = av->name;
if ((i+1!=len(l))) {

                        if (l->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i+1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2246");
                        };
                        struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after buffer declaration.");
}
break;
}
char * tp = getTypeFromToken(&t,true,elems);
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_504 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tp);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(v->type);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_504 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_504+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_504+currStrOff, tp, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_504+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_504+currStrOff, v->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_504+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_504);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_505 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tp);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(v->type);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_505 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_505+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_505+currStrOff, tp, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_505+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_505+currStrOff, v->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_505+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_505);
}
}
}
}
if (((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false))) {
char * ____BAH_COMPILER_VAR_506 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_506 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_506+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_506+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_506;
if (((t.isOper==false)&&(RCPavailable()==true))) {
struct variable* iv = searchVar(t.cont,elems);
if (((iv!=null)&&(iv->isConst==false))) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((((s!=null)&&(strCount(iv->type,"*")==0))&&(s->isBinding==false))) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_507 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen("; RCP_scanStack(&");
long int strLen_6 = strlen(iv->name);
long int strLen_8 = strlen(", sizeof(");
long int strLen_10 = strlen(iv->name);
long int strLen_12 = strlen("), 0)");
;                            
                    ____BAH_COMPILER_VAR_507 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, "; RCP_scanStack(&", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, iv->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, ", sizeof(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, iv->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, "), 0)", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                code = ____BAH_COMPILER_VAR_507;
}
else {
struct string ivn = string(iv->name);
if ((ivn.count(&ivn,"*")>0)) {
ivn.replace(&ivn,"*","");
char * ____BAH_COMPILER_VAR_508 =null;char * ____BAH_COMPILER_VAR_509 =ivn.str(&ivn);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("; RCP_scanStack(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_509);
long int strLen_6 = strlen(", sizeof(");
long int strLen_8 = strlen(iv->name);
long int strLen_10 = strlen("), 0)");
;                            
                    ____BAH_COMPILER_VAR_508 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_508+currStrOff, "; RCP_scanStack(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_508+currStrOff, ____BAH_COMPILER_VAR_509, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_508+currStrOff, ", sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_508+currStrOff, iv->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_508+currStrOff, "), 0)", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * ____BAH_COMPILER_VAR_510 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_508);
;                            
                    ____BAH_COMPILER_VAR_510 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_510+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_510+currStrOff, ____BAH_COMPILER_VAR_508, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                code = ____BAH_COMPILER_VAR_510;
}
else {
char * ____BAH_COMPILER_VAR_511 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen("; RCP_incr(");
long int strLen_6 = strlen(iv->name);
long int strLen_8 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_511 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_511+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_511+currStrOff, "; RCP_incr(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_511+currStrOff, iv->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_511+currStrOff, ")", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                code = ____BAH_COMPILER_VAR_511;
}
}
}
}
}
break;
}
if (strHasPrefix(v->type,"[]")) {
code = parseArrayDecl(v,l,i,len(l),elems);
break;
}
isStruct = true;
if ((i+1!=len(l))) {
throwErr(&l->data[i+1],"{TOKEN} not expected after struct initialization.");
}
char * ____BAH_COMPILER_VAR_512 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_512 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_512+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_512+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_512;
}
i = i+1;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2319");
                        };
                        struct Tok st = l->data[1];
char * ____BAH_COMPILER_VAR_513 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot change the type of already declared var '");
long int strLen_4 = strlen(ft.cont);
long int strLen_6 = strlen("' to {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_513 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_513+currStrOff, "Cannot change the type of already declared var '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_513+currStrOff, ft.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_513+currStrOff, "' to {TOKEN}.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&st,____BAH_COMPILER_VAR_513);
}
char * preCode = "";
if ((isStruct==false)) {
if (((isRCPpointerType(v->type)&&(isPointedVar==false))&&(RCPavailable()==true))) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_514 =null;char * ____BAH_COMPILER_VAR_515 =cType.str(&cType);char * ____BAH_COMPILER_VAR_516 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("*(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_515);
long int strLen_6 = strlen("*)RCP_decrIL(&");
long int strLen_8 = strlen(v->name);
long int strLen_10 = strlen(") = *(");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_516);
long int strLen_14 = strlen("*)RCP_incrIL(&");
long int strLen_16 = strlen(code);
long int strLen_18 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_514 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18);
                    
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, "*(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, ____BAH_COMPILER_VAR_515, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, "*)RCP_decrIL(&", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, v->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, ") = *(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, ____BAH_COMPILER_VAR_516, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, "*)RCP_incrIL(&", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, code, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, ")", strLen_18);
                        currStrOff += strLen_18;
                        
                }
                code = ____BAH_COMPILER_VAR_514;
}
else {
struct variable* ____BAH_COMPILER_VAR_517 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_517->name = "";
____BAH_COMPILER_VAR_517->type = "";
____BAH_COMPILER_VAR_517->isConst = false;
____BAH_COMPILER_VAR_517->constVal = "";
____BAH_COMPILER_VAR_517->isArray = false;
____BAH_COMPILER_VAR_517->from = "";
____BAH_COMPILER_VAR_517->outterScope = false;
____BAH_COMPILER_VAR_517->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_517;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_518 =null;char * ____BAH_COMPILER_VAR_519 =cType.str(&cType);char * ____BAH_COMPILER_VAR_520 =cType.str(&cType);char * ____BAH_COMPILER_VAR_521 =dv->toStr(dv);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_519);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(tmpV->name);
long int strLen_8 = strlen(" = ");
long int strLen_10 = strlen(v->name);
long int strLen_12 = strlen("; ");
long int strLen_14 = strlen(v->name);
long int strLen_16 = strlen(" = *(");
long int strLen_18 = strlen(____BAH_COMPILER_VAR_520);
long int strLen_20 = strlen("*)RCP_incrIL(&");
long int strLen_22 = strlen(code);
long int strLen_24 = strlen(");");
long int strLen_26 = strlen(____BAH_COMPILER_VAR_521);
;                            
                    ____BAH_COMPILER_VAR_518 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26);
                    
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, ____BAH_COMPILER_VAR_519, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, tmpV->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, " = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, v->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, "; ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, v->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, " = *(", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, ____BAH_COMPILER_VAR_520, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, "*)RCP_incrIL(&", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, code, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, ");", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_518+currStrOff, ____BAH_COMPILER_VAR_521, strLen_26);
                        currStrOff += strLen_26;
                        
                }
                code = ____BAH_COMPILER_VAR_518;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_522 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_522->name = "";
____BAH_COMPILER_VAR_522->type = "";
____BAH_COMPILER_VAR_522->isConst = false;
____BAH_COMPILER_VAR_522->constVal = "";
____BAH_COMPILER_VAR_522->isArray = false;
____BAH_COMPILER_VAR_522->from = "";
____BAH_COMPILER_VAR_522->outterScope = false;
____BAH_COMPILER_VAR_522->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_522;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_523 =null;char * ____BAH_COMPILER_VAR_524 =cType.str(&cType);char * ____BAH_COMPILER_VAR_525 =dv->toStr(dv);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_524);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(tmpV->name);
long int strLen_8 = strlen(" = ");
long int strLen_10 = strlen(v->name);
long int strLen_12 = strlen("; ");
long int strLen_14 = strlen(v->name);
long int strLen_16 = strlen(" = ");
long int strLen_18 = strlen(code);
long int strLen_20 = strlen(";");
long int strLen_22 = strlen(____BAH_COMPILER_VAR_525);
;                            
                    ____BAH_COMPILER_VAR_523 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22);
                    
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, ____BAH_COMPILER_VAR_524, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, tmpV->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, " = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, v->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, "; ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, v->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, " = ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, code, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, ";", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_523+currStrOff, ____BAH_COMPILER_VAR_525, strLen_22);
                        currStrOff += strLen_22;
                        
                }
                code = ____BAH_COMPILER_VAR_523;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if (((((s!=null)&&(RCPavailable()==true))&&(RCPselfRef(v)==false))&&(s->isBinding==false))) {
if ((strCount(v->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_526 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("RCP_scanStack(&");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(", sizeof(");
long int strLen_8 = strlen(v->name);
long int strLen_10 = strlen("), 1); ");
;                            
                    ____BAH_COMPILER_VAR_526 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_526+currStrOff, "RCP_scanStack(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_526+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_526+currStrOff, ", sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_526+currStrOff, v->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_526+currStrOff, "), 1); ", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                preCode = ____BAH_COMPILER_VAR_526;
}
else {
struct string vn = string(v->name);
vn.replace(&vn,"*","");
char * ____BAH_COMPILER_VAR_527 =null;char * ____BAH_COMPILER_VAR_528 =vn.str(&vn);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("RCP_scanStack(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_528);
long int strLen_6 = strlen(", sizeof(");
long int strLen_8 = strlen(v->name);
long int strLen_10 = strlen("), 1); ");
;                            
                    ____BAH_COMPILER_VAR_527 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_527+currStrOff, "RCP_scanStack(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_527+currStrOff, ____BAH_COMPILER_VAR_528, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_527+currStrOff, ", sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_527+currStrOff, v->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_527+currStrOff, "), 1); ", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                preCode = ____BAH_COMPILER_VAR_527;
}
char * ____BAH_COMPILER_VAR_529 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(" = ");
long int strLen_6 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_529 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_529+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_529+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_529+currStrOff, code, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                code = ____BAH_COMPILER_VAR_529;
}
else {
char * ____BAH_COMPILER_VAR_530 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(" = ");
long int strLen_6 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_530 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_530+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_530+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_530+currStrOff, code, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                code = ____BAH_COMPILER_VAR_530;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_531 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(" = ");
long int strLen_6 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_531 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, code, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                code = ____BAH_COMPILER_VAR_531;
}
}
if ((v->isArray==true)) {
struct string nLength = string(v->name);
struct string n = string(v->name);
i = 0;
while ((i<nLength.length)) {
char c = nLength.charAt(&nLength,i);
if ((c==91)) {
break;
}
i = i+1;
};
nLength.trimLeft(&nLength,i+1);
nLength.trimRight(&nLength,1);
char * nLengthStr = nLength.str(&nLength);
i = n.length;
while ((i>0)) {
char c = n.charAt(&n,i);
if ((c==91)) {
break;
}
i = i-1;
};
long int tamm = n.length-i;
n.trimRight(&n,tamm+6);
char * nstr = n.str(&n);
struct string elemType = getCType(v->type,elems);
char * elemTypeStr = elemType.str(&elemType);
char * ____BAH_COMPILER_VAR_532 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("\n{\nlong nLength = ");
long int strLen_4 = strlen(nLengthStr);
long int strLen_6 = strlen(";\nif (");
long int strLen_8 = strlen(nstr);
long int strLen_10 = strlen("->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(");
long int strLen_12 = strlen(nstr);
long int strLen_14 = strlen("->data, (nLength+50)*sizeof(");
long int strLen_16 = strlen(elemTypeStr);
long int strLen_18 = strlen("));\n");
long int strLen_20 = strlen(nstr);
long int strLen_22 = strlen("->data = newPtr;\n}\n");
long int strLen_24 = strlen(code);
long int strLen_26 = strlen(";\n");
long int strLen_28 = strlen(nstr);
long int strLen_30 = strlen("->length = nLength+1;\n} else {\n");
long int strLen_32 = strlen(preCode);
long int strLen_34 = strlen(code);
long int strLen_36 = strlen(";\n}\n}");
;                            
                    ____BAH_COMPILER_VAR_532 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34 + strLen_36);
                    
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, "\n{\nlong nLength = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, nLengthStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, ";\nif (", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, nstr, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, nstr, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, "->data, (nLength+50)*sizeof(", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, elemTypeStr, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, "));\n", strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, nstr, strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, "->data = newPtr;\n}\n", strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, code, strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, ";\n", strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, nstr, strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, "->length = nLength+1;\n} else {\n", strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, preCode, strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, code, strLen_34);
                        currStrOff += strLen_34;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, ";\n}\n}", strLen_36);
                        currStrOff += strLen_36;
                        
                }
                code = ____BAH_COMPILER_VAR_532;
}
else {
char * ____BAH_COMPILER_VAR_533 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(preCode);
long int strLen_4 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_533 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_533+currStrOff, preCode, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_533+currStrOff, code, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_533;
}
}
else {
if ((strcmp(currentType, "") != 0)) {
v->type = currentType;
}
struct string vts = string(v->type);
vts.replace(&vts," ","");
v->type = vts.str(&vts);
if ((strlen(v->type)==0)) {
throwErr(&ft,"Cannot declare {TOKEN} without a type.");
}
char * vct= null;
if (vts.hasPrefix(&vts,"function(")) {
struct func* tmpfn = parseFnType(vts);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
long int j = 0;
while ((j<len(tmpfn->args))) {

                        if (tmpfn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: tmpfn->args[%d] with length %d", j, tmpfn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2429");
                        };
                        struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_534 =null;char * ____BAH_COMPILER_VAR_535 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_535);
;                            
                    ____BAH_COMPILER_VAR_534 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_534+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_534+currStrOff, ____BAH_COMPILER_VAR_535, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_534;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_536 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_536 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_536+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_536+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_536;
}
};
char * ____BAH_COMPILER_VAR_537 =null;char * ____BAH_COMPILER_VAR_538 =tmpfnRetCType.str(&tmpfnRetCType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_538);
long int strLen_4 = strlen(" (*");
long int strLen_6 = strlen(v->name);
long int strLen_8 = strlen(")(");
long int strLen_10 = strlen(tmpfnArgsCType);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_537 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_537+currStrOff, ____BAH_COMPILER_VAR_538, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_537+currStrOff, " (*", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_537+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_537+currStrOff, ")(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_537+currStrOff, tmpfnArgsCType, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_537+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                vct = ____BAH_COMPILER_VAR_537;
}
else {
vct = setCType(v,elems);
}
if (((strcmp(code, "") != 0)&&(shouldOnlyDecl==false))) {
if ((((isRCPpointerType(v->type)&&(RCPavailable()==true))&&(toVar==true))&&(isPointedVar==false))) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_539 =null;char * ____BAH_COMPILER_VAR_540 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_2 = strlen(" = *(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_540);
long int strLen_6 = strlen("*)RCP_incrIL(&");
long int strLen_8 = strlen(code);
long int strLen_10 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_539 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_539+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_539+currStrOff, " = *(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_539+currStrOff, ____BAH_COMPILER_VAR_540, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_539+currStrOff, "*)RCP_incrIL(&", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_539+currStrOff, code, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_539+currStrOff, ");\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_539));
}
else {
char * ____BAH_COMPILER_VAR_541 =null;char * ____BAH_COMPILER_VAR_542 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(vct);
long int strLen_4 = strlen(" = *(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_542);
long int strLen_8 = strlen("*)RCP_incrIL(&");
long int strLen_10 = strlen(code);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_541 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_541+currStrOff, vct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_541+currStrOff, " = *(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_541+currStrOff, ____BAH_COMPILER_VAR_542, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_541+currStrOff, "*)RCP_incrIL(&", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_541+currStrOff, code, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_541+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                code = ____BAH_COMPILER_VAR_541;
}
}
else {
if ((needsDefine==true)) {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_543 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(code);
long int strLen_8 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_543 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_543+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_543+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_543+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_543+currStrOff, code, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_543+currStrOff, "\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_543));
}
else {
char * ____BAH_COMPILER_VAR_544 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("#define ");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_544 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_544+currStrOff, "#define ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_544+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_544+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_544+currStrOff, code, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                code = ____BAH_COMPILER_VAR_544;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_545 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_2 = strlen(" = ");
long int strLen_4 = strlen(code);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_545+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_545+currStrOff, " = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_545+currStrOff, code, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_545+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_545));
}
else {
char * ____BAH_COMPILER_VAR_546 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(vct);
long int strLen_4 = strlen(" = ");
long int strLen_6 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_546 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_546+currStrOff, vct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_546+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_546+currStrOff, code, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                code = ____BAH_COMPILER_VAR_546;
}
}
}
}
else {
if ((isRCPpointerType(v->type)&&(shouldOnlyDecl==false))) {
char * ____BAH_COMPILER_VAR_547 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(vct);
long int strLen_4 = strlen("= null");
;                            
                    ____BAH_COMPILER_VAR_547 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_547+currStrOff, vct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_547+currStrOff, "= null", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_547;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_548 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("extern ");
long int strLen_4 = strlen(vct);
;                            
                    ____BAH_COMPILER_VAR_548 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_548+currStrOff, "extern ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_548+currStrOff, vct, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                vct = ____BAH_COMPILER_VAR_548;
}
if (isGlobal()) {
v->isGlobal = true;
}
else {
v->isGlobal = false;
}

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = v;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = v;
}
};
struct variable* ____BAH_COMPILER_VAR_549 = v;
char ** ____BAH_COMPILER_VAR_551 = (char **)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_552 = __reflect(____BAH_COMPILER_VAR_551, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_553 = (char **)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_554 = __reflect(____BAH_COMPILER_VAR_553, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_555 = (char*)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_556 = __reflect(____BAH_COMPILER_VAR_555, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_557 = (char **)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_558 = __reflect(____BAH_COMPILER_VAR_557, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_559 = (char*)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_560 = __reflect(____BAH_COMPILER_VAR_559, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_561 = (char **)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_562 = __reflect(____BAH_COMPILER_VAR_561, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_563 = (char*)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_564 = __reflect(____BAH_COMPILER_VAR_563, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_565 = (char*)((char*)(____BAH_COMPILER_VAR_549) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_566 = __reflect(____BAH_COMPILER_VAR_565, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_550 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_550->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_550->length = 8;
        ____BAH_COMPILER_VAR_550->data = memoryAlloc(____BAH_COMPILER_VAR_550->length * ____BAH_COMPILER_VAR_550->elemSize);
        ____BAH_COMPILER_VAR_550->data[0] = ____BAH_COMPILER_VAR_552;
____BAH_COMPILER_VAR_550->data[1] = ____BAH_COMPILER_VAR_554;
____BAH_COMPILER_VAR_550->data[2] = ____BAH_COMPILER_VAR_556;
____BAH_COMPILER_VAR_550->data[3] = ____BAH_COMPILER_VAR_558;
____BAH_COMPILER_VAR_550->data[4] = ____BAH_COMPILER_VAR_560;
____BAH_COMPILER_VAR_550->data[5] = ____BAH_COMPILER_VAR_562;
____BAH_COMPILER_VAR_550->data[6] = ____BAH_COMPILER_VAR_564;
____BAH_COMPILER_VAR_550->data[7] = ____BAH_COMPILER_VAR_566;
struct reflectElement ____BAH_COMPILER_VAR_567 = __reflect(____BAH_COMPILER_VAR_549, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_550, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_567);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_568 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_568+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_568+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_568));
}
}
if (isGlobal()) {
if ((isSubObject==false)) {
INIT = INIT->add(INIT, rope(NEXT_LINE));
}
NEXT_LINE = "";
}
else {
if ((needsDefine==true)) {
char * ____BAH_COMPILER_VAR_569 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_569 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_569+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_569+currStrOff, "\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_569));
}
else {
char * ____BAH_COMPILER_VAR_570 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_570 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_570+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_570+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_570));
}
}
};
char * getCfunctionType(struct string cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn = parseFnType(cfrt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
long int j = 0;
while ((j<len(tmpfn->args))) {

                        if (tmpfn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: tmpfn->args[%d] with length %d", j, tmpfn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2519");
                        };
                        struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_571 =null;char * ____BAH_COMPILER_VAR_572 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_572);
;                            
                    ____BAH_COMPILER_VAR_571 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_571+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_571+currStrOff, ____BAH_COMPILER_VAR_572, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_571;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_573 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_573 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_573+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_573+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_573;
}
};
char * ____BAH_COMPILER_VAR_574 =null;char * ____BAH_COMPILER_VAR_575 =tmpfnRetCType.str(&tmpfnRetCType);
                {
                    long int currStrOff = 0;
                    long int strLen_1 = strlen(____BAH_COMPILER_VAR_575);
long int strLen_3 = strlen(" (*");
long int strLen_5 = strlen(elemName);
long int strLen_7 = strlen(")(");
long int strLen_9 = strlen(tmpfnArgsCType);
long int strLen_11 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_574 = memoryAllocSTR(1 + strLen_1 + strLen_3 + strLen_5 + strLen_7 + strLen_9 + strLen_11);
                    
                        memcpy(____BAH_COMPILER_VAR_574+currStrOff, ____BAH_COMPILER_VAR_575, strLen_1);
                        currStrOff += strLen_1;
                        
                        memcpy(____BAH_COMPILER_VAR_574+currStrOff, " (*", strLen_3);
                        currStrOff += strLen_3;
                        
                        memcpy(____BAH_COMPILER_VAR_574+currStrOff, elemName, strLen_5);
                        currStrOff += strLen_5;
                        
                        memcpy(____BAH_COMPILER_VAR_574+currStrOff, ")(", strLen_7);
                        currStrOff += strLen_7;
                        
                        memcpy(____BAH_COMPILER_VAR_574+currStrOff, tmpfnArgsCType, strLen_9);
                        currStrOff += strLen_9;
                        
                        memcpy(____BAH_COMPILER_VAR_574+currStrOff, ")", strLen_11);
                        currStrOff += strLen_11;
                        
                }
                return ____BAH_COMPILER_VAR_574;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
long int j = *i;

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2535");
                        };
                        struct Tok ft = l->data[j];
char * tpdf = "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_576 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(prev);
long int strLen_4 = strlen(ft.cont);
;                            
                    ____BAH_COMPILER_VAR_576 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_576+currStrOff, prev, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_576+currStrOff, ft.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fn->name = ____BAH_COMPILER_VAR_576;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_577 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fn->name);
long int strLen_4 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_577 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_577+currStrOff, fn->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_577+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * code = ____BAH_COMPILER_VAR_577;
j = j+2;

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2549");
                        };
                        struct Tok t = l->data[j];
if ((strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2553");
                        };
                        t = l->data[j];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as argument name.");
}
char * argName = t.cont;
j = j+1;
if ((j>=len(l))) {
throwErr(&t,"Cannot declare argument {TOKEN} without a type.");
}

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2563");
                        };
                        t = l->data[j];
char * argType = t.cont;
j = j+1;
char isComa = false;
long int nbPars = 1;
while ((j<len(l))) {

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2570");
                        };
                        t = l->data[j];
isComa = false;
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, "(") == 0)) {
nbPars = nbPars+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPars = nbPars-1;
}
if (((strcmp(t.cont, ")") == 0)&&(nbPars==0))) {
break;
}
else {
char * ____BAH_COMPILER_VAR_578 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(argType);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_578 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_578+currStrOff, argType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_578+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                argType = ____BAH_COMPILER_VAR_578;
}
}
else {
isComa = true;
break;
}
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_579 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_579->name = "";
____BAH_COMPILER_VAR_579->type = "";
____BAH_COMPILER_VAR_579->isConst = false;
____BAH_COMPILER_VAR_579->constVal = "";
____BAH_COMPILER_VAR_579->isArray = false;
____BAH_COMPILER_VAR_579->from = "";
____BAH_COMPILER_VAR_579->outterScope = false;
____BAH_COMPILER_VAR_579->isGlobal = false;
struct variable* argument = ____BAH_COMPILER_VAR_579;
argument->name = argName;
argument->type = argType;

{
long nLength = len(arguments);
if (arguments->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arguments->data, (nLength+50)*sizeof(struct variable*));
arguments->data = newPtr;
}
arguments->data[len(arguments)] = argument;
arguments->length = nLength+1;
} else {
arguments->data[len(arguments)] = argument;
}
};
struct string argCType = getCType(argType,elems);
struct string cfrt = string(argType);
char * newArgType = argCType.str(&argCType);
if ((cfrt.hasPrefix(&cfrt,"[]")==1)) {
cfrt.trimLeft(&cfrt,2);
if (cfrt.hasSuffix(&cfrt,"*")) {
long int nbast = cfrt.count(&cfrt,"*");
cfrt.trimRight(&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_580 =null;char * ____BAH_COMPILER_VAR_581 =cfrt.str(&cfrt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__BAH_ARR_TYPE_");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_581);
;                            
                    ____BAH_COMPILER_VAR_580 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_580+currStrOff, "__BAH_ARR_TYPE_", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_580+currStrOff, ____BAH_COMPILER_VAR_581, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                newArgType = ____BAH_COMPILER_VAR_580;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newArgType,csatd)==false)) {

{
long nLength = len(csatd);
if (csatd->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(csatd->data, (nLength+50)*sizeof(char *));
csatd->data = newPtr;
}
csatd->data[len(csatd)] = newArgType;
csatd->length = nLength+1;
} else {
csatd->data[len(csatd)] = newArgType;
}
};
char * ____BAH_COMPILER_VAR_582 =null;char * ____BAH_COMPILER_VAR_583 =argCType.str(&argCType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tpdf);
long int strLen_4 = strlen("typedef ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_583);
long int strLen_8 = strlen(" ");
long int strLen_10 = strlen(newArgType);
long int strLen_12 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_582 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_582+currStrOff, tpdf, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_582+currStrOff, "typedef ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_582+currStrOff, ____BAH_COMPILER_VAR_583, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_582+currStrOff, " ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_582+currStrOff, newArgType, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_582+currStrOff, ";\n", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                tpdf = ____BAH_COMPILER_VAR_582;
}
}
if ((cfrt.hasPrefix(&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_584 =null;char * ____BAH_COMPILER_VAR_585 =getCfunctionType(cfrt,argName,elems);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_585);
;                            
                    ____BAH_COMPILER_VAR_584 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_584+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_584+currStrOff, ____BAH_COMPILER_VAR_585, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_584;
}
else {
char * ____BAH_COMPILER_VAR_586 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(newArgType);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(argName);
;                            
                    ____BAH_COMPILER_VAR_586 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_586+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_586+currStrOff, newArgType, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_586+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_586+currStrOff, argName, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                code = ____BAH_COMPILER_VAR_586;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_587 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_587 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_587+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_587+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_587;
}
else {
char * ____BAH_COMPILER_VAR_588 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_588 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_588+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_588+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_588;
break;
}
j = j+1;
};
}
else {
char * ____BAH_COMPILER_VAR_589 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_589 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_589+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_589+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_589;
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_590 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_590->name = "";
____BAH_COMPILER_VAR_590->type = "";
____BAH_COMPILER_VAR_590->isConst = false;
____BAH_COMPILER_VAR_590->constVal = "";
____BAH_COMPILER_VAR_590->isArray = false;
____BAH_COMPILER_VAR_590->from = "";
____BAH_COMPILER_VAR_590->outterScope = false;
____BAH_COMPILER_VAR_590->isGlobal = false;
struct variable* returns = ____BAH_COMPILER_VAR_590;
returns->type = "";
while ((j<len(l))) {

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2635");
                        };
                        t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_591 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(returns->type);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_591 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_591+currStrOff, returns->type, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_591+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                returns->type = ____BAH_COMPILER_VAR_591;
j = j+1;
};
if (strlen(returns->type)) {
struct string rts = string(returns->type);
rts.replace(&rts," ","");
returns->type = rts.content;
}
*i = j;
returns->name = fn->name;
fn->returns = returns;
fn->args = arguments;
struct string fnRetType = getCType(returns->type,elems);
char * newFnRetType = fnRetType.str(&fnRetType);
struct string cfrt = string(returns->type);
if ((cfrt.hasPrefix(&cfrt,"[]")==1)) {
cfrt.trimLeft(&cfrt,2);
if (cfrt.hasSuffix(&cfrt,"*")) {
long int nbast = cfrt.count(&cfrt,"*");
cfrt.trimRight(&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_592 =null;char * ____BAH_COMPILER_VAR_593 =cfrt.str(&cfrt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__BAH_ARR_TYPE_");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_593);
;                            
                    ____BAH_COMPILER_VAR_592 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_592+currStrOff, "__BAH_ARR_TYPE_", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_592+currStrOff, ____BAH_COMPILER_VAR_593, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                newFnRetType = ____BAH_COMPILER_VAR_592;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newFnRetType,csatd)==false)) {

{
long nLength = len(csatd);
if (csatd->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(csatd->data, (nLength+50)*sizeof(char *));
csatd->data = newPtr;
}
csatd->data[len(csatd)] = newFnRetType;
csatd->length = nLength+1;
} else {
csatd->data[len(csatd)] = newFnRetType;
}
};
char * ____BAH_COMPILER_VAR_594 =null;char * ____BAH_COMPILER_VAR_595 =fnRetType.str(&fnRetType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tpdf);
long int strLen_4 = strlen("typedef ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_595);
long int strLen_8 = strlen(" ");
long int strLen_10 = strlen(newFnRetType);
long int strLen_12 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_594 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_594+currStrOff, tpdf, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_594+currStrOff, "typedef ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_594+currStrOff, ____BAH_COMPILER_VAR_595, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_594+currStrOff, " ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_594+currStrOff, newFnRetType, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_594+currStrOff, ";\n", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                tpdf = ____BAH_COMPILER_VAR_594;
}
}
char * ____BAH_COMPILER_VAR_596 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tpdf);
long int strLen_4 = strlen(newFnRetType);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_596 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_596+currStrOff, tpdf, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_596+currStrOff, newFnRetType, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_596+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_596+currStrOff, code, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                code = ____BAH_COMPILER_VAR_596;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_597 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_597->name = "";
____BAH_COMPILER_VAR_597->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_597->members->length = 0;
            ____BAH_COMPILER_VAR_597->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_597->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_597->methods->length = 0;
            ____BAH_COMPILER_VAR_597->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_597->postCode = "";
____BAH_COMPILER_VAR_597->extendedFrom = "";
____BAH_COMPILER_VAR_597->isBinding = false;
____BAH_COMPILER_VAR_597->hasRCPmemb = false;
struct cStruct* s = ____BAH_COMPILER_VAR_597;
array(struct cStruct*)* structs = elems->structs;

{
long nLength = len(structs);
if (structs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(structs->data, (nLength+50)*sizeof(struct cStruct*));
structs->data = newPtr;
}
structs->data[len(structs)] = s;
structs->length = nLength+1;
} else {
structs->data[len(structs)] = s;
}
};
array(struct func*)* methds = s->methods;
if ((len(l)<4)) {
throwErr(&l->data[len(l)-1],"Cannot declare struct has such, please do 'struct <name> { <memberName>:<memberType> }'.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2685");
                        };
                        struct Tok nameToken = l->data[1];
long int i = 2;
char doesOutput = true;
if ((strcmp(nameToken.cont, "!") == 0)) {

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2689");
                        };
                        nameToken = l->data[2];
i = 3;
doesOutput = false;
s->isBinding = true;
}
if ((nameToken.type!=TOKEN_TYPE_VAR)) {
throwErr(&nameToken,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* os = searchStruct(nameToken.cont,elems);
if ((os!=null)) {
throwErr(&nameToken,"Struct {TOKEN} already exists.");
}
s->name = nameToken.cont;
array(struct structMemb*)* members = s->members;
currentCStruct = s;
array(char *)* allMembs = memoryAlloc(sizeof(array(char *)));

allMembs->length = 0;
allMembs->elemSize = sizeof(char *);

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2705");
                        };
                        struct Tok st = l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(st.cont, "extend") == 0)) {
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2709");
                        };
                        struct Tok extdSNameTk = l->data[i];
i = i+1;
if ((extdSNameTk.type!=TOKEN_TYPE_VAR)) {
throwErr(&extdSNameTk,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* extdS = searchStruct(extdSNameTk.cont,elems);
s->extendedFrom = extdS->name;
if ((extdS==null)) {
throwErr(&extdSNameTk,"Struct {TOKEN} does not exist.");
}
array(struct structMemb*)* extdsmbs = extdS->members;
long int j = 0;
while ((j<len(extdsmbs))) {

                        if (extdsmbs->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: extdsmbs[%d] with length %d", j, extdsmbs->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2721");
                        };
                        struct structMemb* em = extdsmbs->data[j];
struct string cemt = string(em->type);
char * membDeclStr= null;
if ((cemt.hasPrefix(&cemt,"function(")==1)) {
struct func* tmpfn = parseFnType(cemt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
j = 0;
while ((j<len(tmpfn->args))) {

                        if (tmpfn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: tmpfn->args[%d] with length %d", j, tmpfn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2729");
                        };
                        struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_598 =null;char * ____BAH_COMPILER_VAR_599 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_599);
;                            
                    ____BAH_COMPILER_VAR_598 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_598+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_598+currStrOff, ____BAH_COMPILER_VAR_599, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_598;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_600 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_600 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_600+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_600+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_600;
}
};
char * ____BAH_COMPILER_VAR_601 =null;char * ____BAH_COMPILER_VAR_602 =tmpfnRetCType.str(&tmpfnRetCType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_602);
long int strLen_4 = strlen(" (*");
long int strLen_6 = strlen(em->name);
long int strLen_8 = strlen(")(");
long int strLen_10 = strlen(tmpfnArgsCType);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_601 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_601+currStrOff, ____BAH_COMPILER_VAR_602, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_601+currStrOff, " (*", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_601+currStrOff, em->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_601+currStrOff, ")(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_601+currStrOff, tmpfnArgsCType, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_601+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                membDeclStr = ____BAH_COMPILER_VAR_601;
}
else {
if (isRCPpointerType(em->type)) {
s->hasRCPmemb = true;
}
struct string membDecl = getCType(em->type,elems);
membDecl.append(&membDecl," ");
membDecl.append(&membDecl,em->name);
membDeclStr = membDecl.content;
}

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] = membDeclStr;
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] = membDeclStr;
}
};

{
long nLength = len(members);
if (members->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(members->data, (nLength+50)*sizeof(struct structMemb*));
members->data = newPtr;
}
members->data[len(members)] = em;
members->length = nLength+1;
} else {
members->data[len(members)] = em;
}
};
j = j+1;
};
long int k = 0;
while ((k<len(extdS->methods))) {

                        if (extdS->methods->length <= k) {
                            char buff[300];
                            snprintf(buff, 299, "array: extdS->methods[%d] with length %d", k, extdS->methods->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2753");
                        };
                        struct func* emt = extdS->methods->data[k];
struct string mthdDecl = getCType(emt->returns->type,elems);
char * ____BAH_COMPILER_VAR_603 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(*");
long int strLen_4 = strlen(emt->name);
long int strLen_6 = strlen(")(");
;                            
                    ____BAH_COMPILER_VAR_603 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_603+currStrOff, "(*", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_603+currStrOff, emt->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_603+currStrOff, ")(", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_603);
j = 0;
while ((j<len(emt->args))) {

                        if (emt->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: emt->args[%d] with length %d", j, emt->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2758");
                        };
                        struct variable* a = emt->args->data[j];
struct string tp = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_604 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_604 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_604+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_604+currStrOff, a->name, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tp.append(&tp,____BAH_COMPILER_VAR_604);
long int max = len(emt->args)-1;
if ((j!=max)) {
tp.append(&tp,",");
}
char * ____BAH_COMPILER_VAR_605 =tp.str(&tp);mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_605);
j = j+1;
};
mthdDecl.append(&mthdDecl,")");

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] = mthdDecl.str(&mthdDecl);
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] = mthdDecl.str(&mthdDecl);
}
};
k = k+1;
};
}
else {
throwErr(&st,"Cannot use keyword {TOKEN} in struct declaration.");
}
}

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2777");
                        };
                        struct Tok braceTk = l->data[i];
i = i+1;
if ((strcmp(braceTk.cont, "{") != 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
struct rope* OOUT = OUTPUT;
char * nextLine = "";
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2785");
                        };
                        struct Tok t = l->data[i];
long int max = i+2;
if ((max>=len(l))) {
if (((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "}") == 0))) {
break;
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* ____BAH_COMPILER_VAR_606 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_606->name = "";
____BAH_COMPILER_VAR_606->type = "";
____BAH_COMPILER_VAR_606->isConst = false;
____BAH_COMPILER_VAR_606->constVal = "";
____BAH_COMPILER_VAR_606->isArray = false;
____BAH_COMPILER_VAR_606->from = "";
____BAH_COMPILER_VAR_606->outterScope = false;
____BAH_COMPILER_VAR_606->isGlobal = false;
____BAH_COMPILER_VAR_606->def = "";
____BAH_COMPILER_VAR_606->isFn = false;
struct structMemb* memb = ____BAH_COMPILER_VAR_606;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name = t.cont;
long int ii = 0;
while ((ii<len(members))) {

                        if (members->length <= ii) {
                            char buff[300];
                            snprintf(buff, 299, "array: members[%d] with length %d", ii, members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2799");
                        };
                        struct structMemb* m = members->data[ii];
if ((strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii = ii+1;
};
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2806");
                        };
                        t = l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_607 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s->name);
long int strLen_4 = strlen("__");
;                            
                    ____BAH_COMPILER_VAR_607 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_607+currStrOff, s->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_607+currStrOff, "__", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * fnPrefix = ____BAH_COMPILER_VAR_607;
struct func* ____BAH_COMPILER_VAR_608 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_608->name = "";
____BAH_COMPILER_VAR_608->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_608->args->length = 0;
            ____BAH_COMPILER_VAR_608->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_608->returns= null;
____BAH_COMPILER_VAR_608->isBinding = false;
____BAH_COMPILER_VAR_608->from = "";
____BAH_COMPILER_VAR_608->file = "";
____BAH_COMPILER_VAR_608->line = 1;
____BAH_COMPILER_VAR_608->used = false;
____BAH_COMPILER_VAR_608->code = null;
struct func* fn = ____BAH_COMPILER_VAR_608;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int j = i-1;
while ((j<len(l))) {

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2815");
                        };
                        t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
if ((j==i)) {
t.type = TOKEN_TYPE_VAR;
t.cont = "this";
t.isValue = true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
t.type = TOKEN_TYPE_VAR;
char * ____BAH_COMPILER_VAR_609 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s->name);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_609 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_609+currStrOff, s->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_609+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_609;
t.isValue = true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};

                        if (l->length <= j+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j+1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2831");
                        };
                        struct Tok nt = l->data[j+1];
if ((strcmp(nt.cont, ")") != 0)) {
t.type = TOKEN_TYPE_SYNTAX;
t.cont = ",";
t.isValue = false;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
}
}
j = j+1;
};
i = i-1;
long int nli = 0;
char * ____BAH_COMPILER_VAR_610 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_610);
i = i+nli;
i = i-2;
struct variable* returns = fn->returns;
array(struct variable*)* arguments = fn->args;
fn->from = s->name;
if ((shouldOnlyDecl==true)) {
code = code->add(code, rope(";\n"));
}
else {
code = code->add(code, rope("{\n"));
}
struct Elems* fnElems = dupElems(elems);
j = 0;
while ((j<len(arguments))) {

                        if (arguments->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: arguments[%d] with length %d", j, arguments->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2860");
                        };
                        struct variable* a = arguments->data[j];
a->outterScope = true;

{
long nLength = len(fnElems->vars);
if (fnElems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fnElems->vars->data, (nLength+50)*sizeof(struct variable*));
fnElems->vars->data = newPtr;
}
fnElems->vars->data[len(fnElems->vars)] = a;
fnElems->vars->length = nLength+1;
} else {
fnElems->vars->data[len(fnElems->vars)] = a;
}
};
j = j+1;
};
array(struct func*)* fns = elems->fns;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] = fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] = fn;
}
};
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int nbBraces = 1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2871");
                        };
                        t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
i = i+1;
}
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2876");
                        };
                        t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
nbBraces = nbBraces+1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbBraces = nbBraces-1;
}
if ((nbBraces==0)) {
break;
}

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = t;
}
};
i = i+1;
};
struct func* ____BAH_COMPILER_VAR_611 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_611->name = "";
____BAH_COMPILER_VAR_611->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_611->args->length = 0;
            ____BAH_COMPILER_VAR_611->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_611->returns= null;
____BAH_COMPILER_VAR_611->isBinding = false;
____BAH_COMPILER_VAR_611->from = "";
____BAH_COMPILER_VAR_611->file = "";
____BAH_COMPILER_VAR_611->line = 1;
____BAH_COMPILER_VAR_611->used = false;
____BAH_COMPILER_VAR_611->code = null;
struct func* mfn = ____BAH_COMPILER_VAR_611;
mfn->args = fn->args;
mfn->name = fn->name;
mfn->returns = fn->returns;
mfn->from = s->name;
strTrimLeft(&mfn->name,strlen(fnPrefix));

{
long nLength = len(methds);
if (methds->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(methds->data, (nLength+50)*sizeof(struct func*));
methds->data = newPtr;
}
methds->data[len(methds)] = mfn;
methds->length = nLength+1;
} else {
methds->data[len(methds)] = mfn;
}
};
if ((shouldOnlyDecl==false)) {
if ((len(tokens)==0)) {
code = code->add(code, rope("};\n"));
}
else {
OUTPUT = rope("");
currentFn = fn;
beginRCPscope(fnElems,fn->args);
struct Elems* ocurrFnElems = compilerState.currFnElems;
compilerState.currFnElems = fnElems;
parseLines(tokens,fnElems);
compilerState.currFnElems = ocurrFnElems;
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_612 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Function '");
long int strLen_4 = strlen(fn->name);
long int strLen_6 = strlen("' is not returned.");
;                            
                    ____BAH_COMPILER_VAR_612 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_612+currStrOff, "Function '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_612+currStrOff, fn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_612+currStrOff, "' is not returned.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_612);
}
endRCPscope(fnElems,fn->args);
}
code = code->add(code, OUTPUT)->add(code->add(code, OUTPUT), rope("};\n"));
}
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_613 =null;char * ____BAH_COMPILER_VAR_614 =code->toStr(code);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nextLine);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_614);
;                            
                    ____BAH_COMPILER_VAR_613 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_613+currStrOff, nextLine, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_613+currStrOff, ____BAH_COMPILER_VAR_614, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                nextLine = ____BAH_COMPILER_VAR_613;
}
struct string mthdDecl = getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_615 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(*");
long int strLen_4 = strlen(mfn->name);
long int strLen_6 = strlen(")(");
;                            
                    ____BAH_COMPILER_VAR_615 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_615+currStrOff, "(*", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_615+currStrOff, mfn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_615+currStrOff, ")(", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_615);
j = 0;
while ((j<len(arguments))) {

                        if (arguments->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: arguments[%d] with length %d", j, arguments->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2932");
                        };
                        struct variable* a = arguments->data[j];
struct string tp = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_616 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_616 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_616+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_616+currStrOff, a->name, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tp.append(&tp,____BAH_COMPILER_VAR_616);
max = len(arguments)-1;
if ((j!=max)) {
tp.append(&tp,",");
}
char * ____BAH_COMPILER_VAR_617 =tp.str(&tp);mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_617);
j = j+1;
};
mthdDecl.append(&mthdDecl,")");

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] = mthdDecl.str(&mthdDecl);
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] = mthdDecl.str(&mthdDecl);
}
};
i = i+1;
continue;
}
}
i = i+1;
char * mbmType = "";
long int currentLine = t.line;
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2954");
                        };
                        t = l->data[i];
if ((strcmp(t.cont, "=") == 0)) {
i = i-1;
break;
}
if ((t.line!=currentLine)) {
i = i-1;
break;
}
char * ____BAH_COMPILER_VAR_618 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(mbmType);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_618 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_618+currStrOff, mbmType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_618+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                mbmType = ____BAH_COMPILER_VAR_618;
i = i+1;
};
memb->type = mbmType;
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2969");
                        };
                        t = l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2973");
                        };
                        t = l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char * ____BAH_COMPILER_VAR_619 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(memb->type);
long int strLen_10 = strlen(" for member.");
;                            
                    ____BAH_COMPILER_VAR_619 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_619+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_619+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_619+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_619+currStrOff, memb->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_619+currStrOff, " for member.", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_619);
}
memb->def = t.cont;
}
else {
i = i-1;
}
}
if (isRCPpointerType(memb->type)) {
s->hasRCPmemb = true;
}

{
long nLength = len(members);
if (members->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(members->data, (nLength+50)*sizeof(struct structMemb*));
members->data = newPtr;
}
members->data[len(members)] = memb;
members->length = nLength+1;
} else {
members->data[len(members)] = memb;
}
};
char * membDeclStr= null;
struct string cmt = string(memb->type);
if ((cmt.hasPrefix(&cmt,"function(")==1)) {
struct func* tmpfn = parseFnType(cmt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
long int j = 0;
while ((j<len(tmpfn->args))) {

                        if (tmpfn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: tmpfn->args[%d] with length %d", j, tmpfn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2999");
                        };
                        struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_620 =null;char * ____BAH_COMPILER_VAR_621 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_621);
;                            
                    ____BAH_COMPILER_VAR_620 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_620+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_620+currStrOff, ____BAH_COMPILER_VAR_621, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_620;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_622 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_622 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_622+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_622+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_622;
}
};
char * ____BAH_COMPILER_VAR_623 =null;char * ____BAH_COMPILER_VAR_624 =tmpfnRetCType.str(&tmpfnRetCType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_624);
long int strLen_4 = strlen(" (*");
long int strLen_6 = strlen(memb->name);
long int strLen_8 = strlen(")(");
long int strLen_10 = strlen(tmpfnArgsCType);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_623 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_623+currStrOff, ____BAH_COMPILER_VAR_624, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_623+currStrOff, " (*", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_623+currStrOff, memb->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_623+currStrOff, ")(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_623+currStrOff, tmpfnArgsCType, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_623+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                membDeclStr = ____BAH_COMPILER_VAR_623;
}
else {
struct string membDecl = getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_625 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(memb->name);
;                            
                    ____BAH_COMPILER_VAR_625 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_625+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_625+currStrOff, memb->name, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                membDecl.append(&membDecl,____BAH_COMPILER_VAR_625);
membDeclStr = membDecl.str(&membDecl);
}

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] = membDeclStr;
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] = membDeclStr;
}
};
i = i+1;
};
s->members = members;
if ((doesOutput==true)) {
OUTPUT = OOUT;
NEXT_LINE = nextLine;
char * ____BAH_COMPILER_VAR_626 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct ");
long int strLen_2 = strlen(s->name);
long int strLen_4 = strlen(" {\n");
;                            
                    ____BAH_COMPILER_VAR_626 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_626+currStrOff, "struct ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_626+currStrOff, s->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_626+currStrOff, " {\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                struct rope* code = rope(____BAH_COMPILER_VAR_626);
i = 0;
while ((i<len(allMembs))) {

                        if (allMembs->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: allMembs[%d] with length %d", i, allMembs->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3022");
                        };
                        char * m = allMembs->data[i];
char * ____BAH_COMPILER_VAR_627 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(m);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_627 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_627+currStrOff, m, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_627+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                code = code->add(code, rope(____BAH_COMPILER_VAR_627));
i = i+1;
};
code = code->add(code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, code);
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_628 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_628->name= null;
____BAH_COMPILER_VAR_628->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_628->membs->length = 0;
            ____BAH_COMPILER_VAR_628->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_628;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {

                        if (s->members->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: s->members[%d] with length %d", i, s->members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3039");
                        };
                        struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_629 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_629->name = "";
____BAH_COMPILER_VAR_629->type = "";
____BAH_COMPILER_VAR_629->isConst = false;
____BAH_COMPILER_VAR_629->constVal = "";
____BAH_COMPILER_VAR_629->isArray = false;
____BAH_COMPILER_VAR_629->from = "";
____BAH_COMPILER_VAR_629->outterScope = false;
____BAH_COMPILER_VAR_629->isGlobal = false;
struct variable* mv = ____BAH_COMPILER_VAR_629;
mv->name = m->name;
mv->type = m->type;
mv->isConst = false;
mv->isArray = m->isArray;

{
long nLength = i;
if (ds->membs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ds->membs->data, (nLength+50)*sizeof(struct variable*));
ds->membs->data = newPtr;
}
ds->membs->data[i] = mv;
ds->membs->length = nLength+1;
} else {
ds->membs->data[i] = mv;
}
};
i = i+1;
};
struct debugStruct* ____BAH_COMPILER_VAR_630 = ds;
char ** ____BAH_COMPILER_VAR_632 = (char **)((char*)(____BAH_COMPILER_VAR_630) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_633 = __reflect(____BAH_COMPILER_VAR_632, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_634 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_630) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_635 = 0;
char ** ____BAH_COMPILER_VAR_637 = (char **)((char*)(____BAH_COMPILER_VAR_635) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_638 = __reflect(____BAH_COMPILER_VAR_637, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_639 = (char **)((char*)(____BAH_COMPILER_VAR_635) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_640 = __reflect(____BAH_COMPILER_VAR_639, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_641 = (char*)((char*)(____BAH_COMPILER_VAR_635) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_642 = __reflect(____BAH_COMPILER_VAR_641, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_643 = (char **)((char*)(____BAH_COMPILER_VAR_635) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_644 = __reflect(____BAH_COMPILER_VAR_643, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_645 = (char*)((char*)(____BAH_COMPILER_VAR_635) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_646 = __reflect(____BAH_COMPILER_VAR_645, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_647 = (char **)((char*)(____BAH_COMPILER_VAR_635) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_648 = __reflect(____BAH_COMPILER_VAR_647, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_649 = (char*)((char*)(____BAH_COMPILER_VAR_635) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_650 = __reflect(____BAH_COMPILER_VAR_649, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_651 = (char*)((char*)(____BAH_COMPILER_VAR_635) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_652 = __reflect(____BAH_COMPILER_VAR_651, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_636 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_636->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_636->length = 8;
        ____BAH_COMPILER_VAR_636->data = memoryAlloc(____BAH_COMPILER_VAR_636->length * ____BAH_COMPILER_VAR_636->elemSize);
        ____BAH_COMPILER_VAR_636->data[0] = ____BAH_COMPILER_VAR_638;
____BAH_COMPILER_VAR_636->data[1] = ____BAH_COMPILER_VAR_640;
____BAH_COMPILER_VAR_636->data[2] = ____BAH_COMPILER_VAR_642;
____BAH_COMPILER_VAR_636->data[3] = ____BAH_COMPILER_VAR_644;
____BAH_COMPILER_VAR_636->data[4] = ____BAH_COMPILER_VAR_646;
____BAH_COMPILER_VAR_636->data[5] = ____BAH_COMPILER_VAR_648;
____BAH_COMPILER_VAR_636->data[6] = ____BAH_COMPILER_VAR_650;
____BAH_COMPILER_VAR_636->data[7] = ____BAH_COMPILER_VAR_652;
struct reflectElement ____BAH_COMPILER_VAR_653 = __reflect(____BAH_COMPILER_VAR_635, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_636, 0);

        struct reflectElement ____BAH_COMPILER_VAR_654 = ____BAH_COMPILER_VAR_653;
        struct reflectElement ____BAH_COMPILER_VAR_655 = __reflect(____BAH_COMPILER_VAR_634, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_654, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_631 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_631->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_631->length = 2;
        ____BAH_COMPILER_VAR_631->data = memoryAlloc(____BAH_COMPILER_VAR_631->length * ____BAH_COMPILER_VAR_631->elemSize);
        ____BAH_COMPILER_VAR_631->data[0] = ____BAH_COMPILER_VAR_633;
____BAH_COMPILER_VAR_631->data[1] = ____BAH_COMPILER_VAR_655;
struct reflectElement ____BAH_COMPILER_VAR_656 = __reflect(____BAH_COMPILER_VAR_630, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_631, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_656);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3061");
                        };
                        struct Tok ft = l->data[1];

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3062");
                        };
                        struct Tok st = l->data[2];
long int i = 1;
char doesOutput = true;
if ((strcmp(ft.cont, "!") == 0)) {

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3067");
                        };
                        ft = l->data[2];

                        if (l->length <= 3) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 3, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3068");
                        };
                        st = l->data[3];
i = 2;
doesOutput = false;
}
if ((strcmp(st.cont, "(") == 0)) {
struct func* ____BAH_COMPILER_VAR_657 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_657->name = "";
____BAH_COMPILER_VAR_657->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_657->args->length = 0;
            ____BAH_COMPILER_VAR_657->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_657->returns= null;
____BAH_COMPILER_VAR_657->isBinding = false;
____BAH_COMPILER_VAR_657->from = "";
____BAH_COMPILER_VAR_657->file = "";
____BAH_COMPILER_VAR_657->line = 1;
____BAH_COMPILER_VAR_657->used = false;
____BAH_COMPILER_VAR_657->code = null;
struct func* fn = ____BAH_COMPILER_VAR_657;
char * code = parseFnHeader("",l,&i,fn,elems);
array(struct func*)* fns = elems->fns;
fn->isBinding = true;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] = fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] = fn;
}
};
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_658 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_658 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_658+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_658+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_658));
}
}
else {
char * tp = "";
i = i+1;
for (; (i<len(l)); i = i+1) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3087");
                        };
                        struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_659 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tp);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_659 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_659+currStrOff, tp, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_659+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tp = ____BAH_COMPILER_VAR_659;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = cTypeNewType.str(&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_660 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("typedef ");
long int strLen_2 = strlen(cTypeNewTypeStr);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(ft.cont);
long int strLen_8 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_660 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_660+currStrOff, "typedef ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_660+currStrOff, cTypeNewTypeStr, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_660+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_660+currStrOff, ft.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_660+currStrOff, ";\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_660));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_661 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_661->name= null;
____BAH_COMPILER_VAR_661->refers= null;
struct debugType* dt = ____BAH_COMPILER_VAR_661;
dt->name = ft.cont;
dt->refers = tp;
struct debugType* ____BAH_COMPILER_VAR_662 = dt;
char ** ____BAH_COMPILER_VAR_664 = (char **)((char*)(____BAH_COMPILER_VAR_662) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_665 = __reflect(____BAH_COMPILER_VAR_664, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_666 = (char **)((char*)(____BAH_COMPILER_VAR_662) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_667 = __reflect(____BAH_COMPILER_VAR_666, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_663 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_663->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_663->length = 2;
        ____BAH_COMPILER_VAR_663->data = memoryAlloc(____BAH_COMPILER_VAR_663->length * ____BAH_COMPILER_VAR_663->elemSize);
        ____BAH_COMPILER_VAR_663->data[0] = ____BAH_COMPILER_VAR_665;
____BAH_COMPILER_VAR_663->data[1] = ____BAH_COMPILER_VAR_667;
struct reflectElement ____BAH_COMPILER_VAR_668 = __reflect(____BAH_COMPILER_VAR_662, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_663, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_668);
}
array(char *)* tps = elems->types;

{
long nLength = len(tps);
if (tps->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tps->data, (nLength+50)*sizeof(char *));
tps->data = newPtr;
}
tps->data[len(tps)] = ft.cont;
tps->length = nLength+1;
} else {
tps->data[len(tps)] = ft.cont;
}
};
}
};
void parseClib(__BAH_ARR_TYPE_Tok line){
array(char *)* clibs = compilerState.cLibs;
long int i = 1;
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3117");
                        };
                        struct Tok t = line->data[i];
if ((t.type!=TOKEN_TYPE_STR)) {
throwErr(&t,"Cannot use {TOKEN} as C library name.");
}
struct string cc = string(t.cont);
cc.trimLeft(&cc,1);
cc.trimRight(&cc,1);
char * ccstr = cc.str(&cc);
char found = false;
long int j = 0;
while ((j<len(clibs))) {

                        if (clibs->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: clibs[%d] with length %d", j, clibs->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3129");
                        };
                        char * l = clibs->data[j];
if ((strcmp(l, ccstr) == 0)) {
found = true;
break;
}
j = j+1;
};
if ((found==true)) {
i = i+1;
continue;
}

{
long nLength = len(clibs);
if (clibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(clibs->data, (nLength+50)*sizeof(char *));
clibs->data = newPtr;
}
clibs->data[len(clibs)] = ccstr;
clibs->length = nLength+1;
} else {
clibs->data[len(clibs)] = ccstr;
}
};
i = i+1;
};
};
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
l = parseCast(l,elems,true);
if ((len(l)!=4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3152");
                        };
                        struct Tok vart = l->data[1];

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3153");
                        };
                        struct Tok equt = l->data[2];

                        if (l->length <= 3) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 3, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3154");
                        };
                        struct Tok valt = l->data[3];
if ((vart.type!=TOKEN_TYPE_VAR)) {
throwErr(&vart,"Cannot take {TOKEN} as const name.");
}
if ((strcmp(equt.cont, "=") != 0)) {
throwErr(&equt,"Expected '=' not {TOKEN}.");
}
if ((valt.isValue==false)) {
throwErr(&equt,"Must be a value, not {TOKEN}.");
}
if ((valt.type==TOKEN_TYPE_VAR)) {
struct func* fn = searchFunc(valt.cont,elems,true);
if ((fn!=null)) {
fn->used = true;
}
}
struct variable* ____BAH_COMPILER_VAR_669 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_669->name = "";
____BAH_COMPILER_VAR_669->type = "";
____BAH_COMPILER_VAR_669->isConst = false;
____BAH_COMPILER_VAR_669->constVal = "";
____BAH_COMPILER_VAR_669->isArray = false;
____BAH_COMPILER_VAR_669->from = "";
____BAH_COMPILER_VAR_669->outterScope = false;
____BAH_COMPILER_VAR_669->isGlobal = false;
struct variable* v = ____BAH_COMPILER_VAR_669;
if (isGlobal()) {
v->isGlobal = true;
}
v->isConst = true;
v->constVal = valt.cont;
v->name = vart.cont;
v->type = getTypeFromToken(&valt,true,elems);
array(struct variable*)* vars = elems->vars;

{
long nLength = len(vars);
if (vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(vars->data, (nLength+50)*sizeof(struct variable*));
vars->data = newPtr;
}
vars->data[len(vars)] = v;
vars->length = nLength+1;
} else {
vars->data[len(vars)] = v;
}
};
char * ____BAH_COMPILER_VAR_670 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(valt.cont);
long int strLen_8 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_670 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_670+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_670+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_670+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_670+currStrOff, valt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_670+currStrOff, "\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_670));
};
void parseReturn(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'return <returnValue>'");
}
if ((currentFn==null)) {
throwErr(&l->data[0],"Cannot return a value outside of a function.");
}
char * rv = "";
char * tt = "";
struct variable* tmpV = null;
if ((len(l)==1)) {
if ((strlen(currentFn->returns->type)!=0)) {
char * ____BAH_COMPILER_VAR_671 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot return nothing as ");
long int strLen_4 = strlen(currentFn->returns->type);
long int strLen_6 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_671 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_671+currStrOff, "Cannot return nothing as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_671+currStrOff, currentFn->returns->type, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_671+currStrOff, ".", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&l->data[0],____BAH_COMPILER_VAR_671);
}
}
else {

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3205");
                        };
                        struct Tok rvt = l->data[1];
tt = getTypeFromToken(&rvt,true,elems);
rv = rvt.cont;
if ((rvt.isValue==false)) {
throwErr(&rvt,"Must be a value, not {TOKEN}.");
}
else if (((rvt.type==TOKEN_TYPE_VAR)&&(rvt.isOper==false))) {
tmpV = searchVar(rvt.cont,compilerState.currFnElems);
if ((tmpV==null)) {
tmpV = searchVar(rvt.cont,elems);
}
}
else if ((RCPavailable()&&(rvt.type==TOKEN_TYPE_FUNC))) {
rv = genCompilerVar();
struct string cType = getCType(tt,elems);
char * ____BAH_COMPILER_VAR_672 =null;char * ____BAH_COMPILER_VAR_673 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_673);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(rv);
long int strLen_6 = strlen("=");
long int strLen_8 = strlen(rvt.cont);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_672 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, ____BAH_COMPILER_VAR_673, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, rv, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, "=", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, rvt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_672));
}
if ((compTypes(tt,currentFn->returns->type)==false)) {
char * ____BAH_COMPILER_VAR_674 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot return {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(currentFn->returns->type);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_674 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_674+currStrOff, "Cannot return {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_674+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_674+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_674+currStrOff, currentFn->returns->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_674+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&rvt,____BAH_COMPILER_VAR_674);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned = true;
}
if ((strlen(rv)>0)) {
char * rvar = rv;
if (((RCPavailable()==true)&&isRCPpointerType(currentFn->returns->type))) {
rvar = genCompilerVar();
struct string cType = getCType(currentFn->returns->type,elems);
char * ____BAH_COMPILER_VAR_675 =null;char * ____BAH_COMPILER_VAR_676 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_676);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(rvar);
long int strLen_6 = strlen(" = ");
long int strLen_8 = strlen(rv);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_675 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_675+currStrOff, ____BAH_COMPILER_VAR_676, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_675+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_675+currStrOff, rvar, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_675+currStrOff, " = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_675+currStrOff, rv, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_675+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_675));
if (((tmpV!=null)&&(tmpV->outterScope==true))) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(tmpV,elems));
}
}
if (strHasPrefix(tt,"buffer:")) {
char * ____BAH_COMPILER_VAR_677 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__STR(");
long int strLen_4 = strlen(rvar);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_677 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_677+currStrOff, "__STR(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_677+currStrOff, rvar, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_677+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                rvar = ____BAH_COMPILER_VAR_677;
}
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
long int j = 0;
for (; (j<len(currentFn->args)); j = j+1) {

                        if (currentFn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: currentFn->args[%d] with length %d", j, currentFn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3244");
                        };
                        
{
long nLength = j;
if (excl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(excl->data, (nLength+50)*sizeof(struct variable*));
excl->data = newPtr;
}
excl->data[j] = currentFn->args->data[j];
excl->length = nLength+1;
} else {
excl->data[j] = currentFn->args->data[j];
}
};
};
if ((tmpV!=null)) {

{
long nLength = len(excl);
if (excl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(excl->data, (nLength+50)*sizeof(struct variable*));
excl->data = newPtr;
}
excl->data[len(excl)] = tmpV;
excl->length = nLength+1;
} else {
excl->data[len(excl)] = tmpV;
}
};
}
endRCPscope(elems,excl);
}
char * ____BAH_COMPILER_VAR_678 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("return ");
long int strLen_2 = strlen(rvar);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_678 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_678+currStrOff, "return ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_678+currStrOff, rvar, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_678+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_678));
}
else {
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
long int j = 0;
for (; (j<len(currentFn->args)); j = j+1) {

                        if (currentFn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: currentFn->args[%d] with length %d", j, currentFn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3256");
                        };
                        
{
long nLength = j;
if (excl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(excl->data, (nLength+50)*sizeof(struct variable*));
excl->data = newPtr;
}
excl->data[j] = currentFn->args->data[j];
excl->length = nLength+1;
} else {
excl->data[j] = currentFn->args->data[j];
}
};
};
if ((tmpV!=null)) {

{
long nLength = len(excl);
if (excl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(excl->data, (nLength+50)*sizeof(struct variable*));
excl->data = newPtr;
}
excl->data[len(excl)] = tmpV;
excl->length = nLength+1;
} else {
excl->data[len(excl)] = tmpV;
}
};
}
endRCPscope(elems,excl);
}
OUTPUT = OUTPUT->add(OUTPUT, rope("return;\n"));
}
};
void parseIf(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3270");
                        };
                        struct Tok ft = l->data[0];
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3273");
                        };
                        struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3279");
                        };
                        struct Tok t = l->data[2];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in if statement.");
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int max = len(l)-1;
long int i = 3;
while ((i<max)) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3286");
                        };
                        t = l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = t;
}
};
i = i+1;
};
char * ____BAH_COMPILER_VAR_679 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("if (");
long int strLen_2 = strlen(condt.cont);
long int strLen_4 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_679 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_679+currStrOff, "if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_679+currStrOff, condt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_679+currStrOff, ") {\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_679));
struct Elems* ifElems = dupElems(elems);
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
beginRCPscopeLeaky(ifElems);
parseLines(tokens,ifElems);
endRCPscopeLeaky(ifElems,null);
if ((debug==true)) {

                        if (l->length <= len(l)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", len(l)-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3300");
                        };
                        struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isBranch = oldIB;
OUTPUT = OUTPUT->add(OUTPUT, rope("}\n"));
};
void parseElse(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((prevLine!=LINE_TYPE_IF)) {
if ((prevLine!=LINE_TYPE_ELSE)) {
throwErr(&l->data[0],"Can only use {TOKEN} after 'if' statement.");
}
}
if ((len(l)<3)) {
throwErr(&l->data[0],"Incalid usage of {TOKEN}, must be 'else {<code>}'.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3319");
                        };
                        struct Tok ft = l->data[1];
OUTPUT = OUTPUT->add(OUTPUT, rope("else "));
if ((strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int i = 1;
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3324");
                        };
                        
{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] = l->data[i];
}
};
i = i+1;
};
parseIf(memory,elems);
prevLine = LINE_TYPE_IF;
}
else {
if ((strcmp(ft.cont, "{") != 0)) {
throwErr(&ft,"Expected 'if' or '{' not {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int max = len(l)-1;
long int i = 2;
while ((i<max)) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3337");
                        };
                        
{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] = l->data[i];
}
};
i = i+1;
};
OUTPUT = OUTPUT->add(OUTPUT, rope("{\n"));
struct Elems* ifElems = dupElems(elems);
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3345");
                        };
                        struct Tok t = l->data[0];
beginRCPscopeLeaky(ifElems);
parseLines(memory,ifElems);
endRCPscopeLeaky(ifElems,null);
if ((debug==true)) {

                        if (l->length <= len(l)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", len(l)-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3350");
                        };
                        struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isBranch = oldIB;
OUTPUT = OUTPUT->add(OUTPUT, rope("}\n"));
}
};
void parseLine(__BAH_ARR_TYPE_Tok l,struct Elems* elems);
void parseFor(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}
long int nbComas = 0;
long int i = 1;
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3369");
                        };
                        struct Tok t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
if (((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, ",") == 0))) {
if ((nbComas==1)) {
throwErr(&t,"Invalid line separation of for, cannot set more than 2 lines: {TOKEN}.");
}
nbComas = nbComas+1;
}
i = i+1;
};
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
if ((nbComas>0)) {
if ((nbComas!=1)) {

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3385");
                        };
                        struct Tok t = l->data[0];
throwErr(&t,"Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3390");
                        };
                        struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3398");
                        };
                        struct Tok st = l->data[2];
if (((st.type!=TOKEN_TYPE_SYNTAX)||(strcmp(st.cont, ",") != 0))) {
throwErr(&st,"Cannot use {TOKEN}, need ',' to split for loop instructions.");
}
i = 3;
for (; (i<len(l)); i = i+1) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3405");
                        };
                        struct Tok t = l->data[i];
if (((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "{") == 0))) {
break;
}

{
long nLength = len(inst);
if (inst->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(inst->data, (nLength+50)*sizeof(struct Tok));
inst->data = newPtr;
}
inst->data[len(inst)] = t;
inst->length = nLength+1;
} else {
inst->data[len(inst)] = t;
}
};
};
struct rope* oldOut = OUTPUT;
OUTPUT = rope("");
parseLine(inst,elems);
char * ____BAH_COMPILER_VAR_680 =OUTPUT->toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_680);
OUTPUT = oldOut;
instC.trimRight(&instC,2);

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3421");
                        };
                        struct Tok t = l->data[i];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}
long int max = len(l)-1;
i = i+1;
for (; (i<max); i = i+1) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3428");
                        };
                        t = l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = t;
}
};
};
char * ____BAH_COMPILER_VAR_681 =null;char * ____BAH_COMPILER_VAR_682 =instC.str(&instC);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("for (; ");
long int strLen_2 = strlen(condt.cont);
long int strLen_4 = strlen("; ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_682);
long int strLen_8 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_681 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_681+currStrOff, "for (; ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_681+currStrOff, condt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_681+currStrOff, "; ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_681+currStrOff, ____BAH_COMPILER_VAR_682, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_681+currStrOff, ") {\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_681));
}
else {

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3435");
                        };
                        struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3441");
                        };
                        struct Tok t = l->data[2];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}
long int max = len(l)-1;
i = 3;
for (; (i<max); i = i+1) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3447");
                        };
                        t = l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = t;
}
};
};
char * ____BAH_COMPILER_VAR_683 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("while (");
long int strLen_2 = strlen(condt.cont);
long int strLen_4 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_683 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_683+currStrOff, "while (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_683+currStrOff, condt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_683+currStrOff, ") {\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_683));
}
struct Elems* oForElems = compilerState.currForElems;
struct Elems* ifElems = dupElems(elems);
compilerState.currForElems = ifElems;
char oldIB = compilerState.isBranch;
char oldIF = compilerState.isFor;
compilerState.isBranch = true;
compilerState.isFor = true;

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3460");
                        };
                        struct Tok t = l->data[0];
beginRCPscopeLeaky(ifElems);
parseLines(tokens,ifElems);
endRCPscopeLeaky(ifElems,null);
if ((debug==true)) {

                        if (l->length <= len(l)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", len(l)-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3465");
                        };
                        struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isFor = oldIF;
compilerState.isBranch = oldIB;
compilerState.currForElems = oForElems;
OUTPUT = OUTPUT->add(OUTPUT, rope("};\n"));
};
void parseForOp(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3477");
                        };
                        struct Tok ft = l->data[0];
if ((compilerState.isFor==false)) {
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}
if ((len(l)!=1)) {
throwErr(&ft,"Nothing expected after {TOKEN}.");
}
endRCPscopeLeaky(elems,null);
endRCPscopeLeaky(compilerState.currForElems,null);
char * ____BAH_COMPILER_VAR_684 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_684 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_684+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_684+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_684));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

                int ____BAH_COMPILER_VAR_685 = 0;
                for(int i=len(compilerState.evals)-1; i != -1; i--) {
                    if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                        ____BAH_COMPILER_VAR_685 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_685) {
return;
}
char * ____BAH_COMPILER_VAR_686 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__Bah_eval_");
long int strLen_4 = strlen(fn->name);
;                            
                    ____BAH_COMPILER_VAR_686 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_686+currStrOff, "__Bah_eval_", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_686+currStrOff, fn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                struct func* ____BAH_COMPILER_VAR_687 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_687->name = "";
____BAH_COMPILER_VAR_687->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_687->args->length = 0;
            ____BAH_COMPILER_VAR_687->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_687->returns= null;
____BAH_COMPILER_VAR_687->isBinding = false;
____BAH_COMPILER_VAR_687->from = "";
____BAH_COMPILER_VAR_687->file = "";
____BAH_COMPILER_VAR_687->line = 1;
____BAH_COMPILER_VAR_687->used = false;
____BAH_COMPILER_VAR_687->code = null;
____BAH_COMPILER_VAR_687->name = ____BAH_COMPILER_VAR_686;
struct func* efn = ____BAH_COMPILER_VAR_687;
struct variable* ____BAH_COMPILER_VAR_688 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_688->name = "";
____BAH_COMPILER_VAR_688->type = "";
____BAH_COMPILER_VAR_688->isConst = false;
____BAH_COMPILER_VAR_688->constVal = "";
____BAH_COMPILER_VAR_688->isArray = false;
____BAH_COMPILER_VAR_688->from = "";
____BAH_COMPILER_VAR_688->outterScope = false;
____BAH_COMPILER_VAR_688->isGlobal = false;
____BAH_COMPILER_VAR_688->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_688;
struct variable* ____BAH_COMPILER_VAR_689 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_689->name = "";
____BAH_COMPILER_VAR_689->type = "";
____BAH_COMPILER_VAR_689->isConst = false;
____BAH_COMPILER_VAR_689->constVal = "";
____BAH_COMPILER_VAR_689->isArray = false;
____BAH_COMPILER_VAR_689->from = "";
____BAH_COMPILER_VAR_689->outterScope = false;
____BAH_COMPILER_VAR_689->isGlobal = false;
____BAH_COMPILER_VAR_689->name = "fnArgs";
____BAH_COMPILER_VAR_689->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);efn->args->data[0] = ____BAH_COMPILER_VAR_689;
char * fnBinding = "";
char * ____BAH_COMPILER_VAR_690 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fn->name);
long int strLen_4 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_690 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_690+currStrOff, fn->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_690+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * fnCall = ____BAH_COMPILER_VAR_690;
long int i = 0;
for (; (i<len(fn->args)); i = i+1) {

                        if (fn->args->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", i, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3514");
                        };
                        struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
cType.append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_691 =null;char * ____BAH_COMPILER_VAR_692 =cType.str(&cType);char * ____BAH_COMPILER_VAR_693 =intToStr(i);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_692);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(v);
long int strLen_8 = strlen(" = fnArgs->data[");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_693);
long int strLen_12 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_691 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_691+currStrOff, ____BAH_COMPILER_VAR_692, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_691+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_691+currStrOff, v, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_691+currStrOff, " = fnArgs->data[", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_691+currStrOff, ____BAH_COMPILER_VAR_693, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_691+currStrOff, "];", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                char * ____BAH_COMPILER_VAR_694 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnBinding);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_691);
;                            
                    ____BAH_COMPILER_VAR_694 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_694+currStrOff, fnBinding, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_694+currStrOff, ____BAH_COMPILER_VAR_691, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fnBinding = ____BAH_COMPILER_VAR_694;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_695 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_2 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_695 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_695+currStrOff, fnCall, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_695+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fnCall = ____BAH_COMPILER_VAR_695;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_696 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_2 = strlen(v);
;                            
                    ____BAH_COMPILER_VAR_696 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_696+currStrOff, fnCall, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_696+currStrOff, v, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fnCall = ____BAH_COMPILER_VAR_696;
}
else {
char * ____BAH_COMPILER_VAR_697 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("*");
long int strLen_4 = strlen(v);
;                            
                    ____BAH_COMPILER_VAR_697 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_697+currStrOff, "*", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_697+currStrOff, v, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * ____BAH_COMPILER_VAR_698 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_697);
;                            
                    ____BAH_COMPILER_VAR_698 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_698+currStrOff, fnCall, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_698+currStrOff, ____BAH_COMPILER_VAR_697, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fnCall = ____BAH_COMPILER_VAR_698;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(cType.str(&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_699 =null;char * ____BAH_COMPILER_VAR_700 =cType.str(&cType);char * ____BAH_COMPILER_VAR_701 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_700);
long int strLen_4 = strlen("* r = memoryAlloc(sizeof(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_701);
long int strLen_8 = strlen("));*r = ");
;                            
                    ____BAH_COMPILER_VAR_699 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, ____BAH_COMPILER_VAR_700, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, "* r = memoryAlloc(sizeof(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, ____BAH_COMPILER_VAR_701, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, "));*r = ", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                setReturnValue = ____BAH_COMPILER_VAR_699;
}
}
char * ____BAH_COMPILER_VAR_702 =null;char * ____BAH_COMPILER_VAR_703 =intToStr(len(fn->args));
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("void* __attribute__((optimize(\"O0\"))) ");
long int strLen_2 = strlen(efn->name);
long int strLen_4 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_703);
long int strLen_8 = strlen(") {\n            __BAH_panic((char*)\"eval: calling function ");
long int strLen_10 = strlen(fn->name);
long int strLen_12 = strlen("() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ");
long int strLen_14 = strlen(fnBinding);
long int strLen_16 = strlen("\n        ");
long int strLen_18 = strlen(setReturnValue);
long int strLen_20 = strlen(fnCall);
long int strLen_22 = strlen(");\n        return (void*)r;\n    };");
;                            
                    ____BAH_COMPILER_VAR_702 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22);
                    
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, efn->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, ____BAH_COMPILER_VAR_703, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, ") {\n            __BAH_panic((char*)\"eval: calling function ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, fn->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, fnBinding, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, "\n        ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, setReturnValue, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, fnCall, strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_702+currStrOff, ");\n        return (void*)r;\n    };", strLen_22);
                        currStrOff += strLen_22;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_702));

{
long nLength = len(compilerState.evals);
if (compilerState.evals->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.evals->data, (nLength+50)*sizeof(char *));
compilerState.evals->data = newPtr;
}
compilerState.evals->data[len(compilerState.evals)] = fn->name;
compilerState.evals->length = nLength+1;
} else {
compilerState.evals->data[len(compilerState.evals)] = fn->name;
}
};

{
long nLength = len(elems->fns);
if (elems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->fns->data, (nLength+50)*sizeof(struct func*));
elems->fns->data = newPtr;
}
elems->fns->data[len(elems->fns)] = efn;
elems->fns->length = nLength+1;
} else {
elems->fns->data[len(elems->fns)] = efn;
}
};
};
void parsePreKeyword(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3556");
                        };
                        struct Tok ft = l->data[0];
if ((strcmp(ft.cont, "#warning") == 0)) {
if ((len(l)!=2)) {
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3562");
                        };
                        struct Tok mt = l->data[1];
if ((mt.type!=TOKEN_TYPE_STR)) {
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}
struct string msg = string(mt.cont);
msg.trimLeft(&msg,1);
msg.trimRight(&msg,1);
char * ____BAH_COMPILER_VAR_704 =msg.str(&msg);throwWarning(____BAH_COMPILER_VAR_704);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

                int ____BAH_COMPILER_VAR_705 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                        ____BAH_COMPILER_VAR_705 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_705==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_706 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
long int strLen_4 = strlen(BAH_DIR);
long int strLen_6 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_706 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_706+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_706+currStrOff, BAH_DIR, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_706+currStrOff, ").", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&l->data[0],____BAH_COMPILER_VAR_706);
}
}
if (((len(l)!=2)||(isGlobal()==false))) {
throwErr(&l->data[0],"Invalid usage of {TOKEN} <#eval fnName>.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3589");
                        };
                        struct Tok fnT = l->data[1];
struct func* fn = searchFunc(fnT.cont,elems,false);
if ((fn==null)) {
throwErr(&fnT,"Unknown function {TOKEN}.");
}
fn->used = true;
makeEvalFunc(fn,elems);
return;
}
if ((strcmp(ft.cont, "#evalAll") == 0)) {
long int i = 0;
for (; (i<len(elems->fns)); i = i+1) {

                        if (elems->fns->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->fns[%d] with length %d", i, elems->fns->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3603");
                        };
                        struct func* fn = elems->fns->data[i];
fn->used = true;
if (((fn->isBinding==false)&&(strHasPrefix(fn->name,"__Bah_eval_")==false))) {
makeEvalFunc(fn,elems);
}
};
return;
}
if ((len(l)<3)) {
throwErr(&ft,"Invalid usage of keyword {TOKEN}.");
}
if ((((strcmp(ft.cont, "#linux") == 0)||(strcmp(ft.cont, "#windows") == 0))||(strcmp(ft.cont, "#darwin") == 0))) {
struct string isOS = string(ft.cont);
isOS.trimLeft(&isOS,1);
if ((strcmp(isOS.str(&isOS), BAH_OS) != 0)) {
return;
}
}
else if ((strcmp(ft.cont, "#static") == 0)) {
if ((flags.isSet(&flags,"d")==1)) {
return;
}
}
else if ((strcmp(ft.cont, "#dynamic") == 0)) {
if ((flags.isSet(&flags,"d")==0)) {
return;
}
}
else if ((strcmp(ft.cont, "#gc") == 0)) {
if ((RCPavailable()==true)) {
return;
}
}
else if ((strcmp(ft.cont, "#rcp") == 0)) {
if ((RCPavailable()==false)) {
return;
}
}
else if ((strcmp(ft.cont, "#lib") == 0)) {
if ((flags.isSet(&flags,"l")==0)) {
return;
}
}
else if ((strcmp(ft.cont, "#exec") == 0)) {
if ((flags.isSet(&flags,"l")==1)) {
return;
}
}
else if ((strcmp(ft.cont, "#imported") == 0)) {
if (((isSubObject==false)||(isObject==false))) {
return;
}
}
else if ((strcmp(ft.cont, "#included") == 0)) {
if (((isSubObject==true)||(isObject==true))) {
return;
}
}
else {
throwErr(&ft,"Undefined token {TOKEN}.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3658");
                        };
                        struct Tok st = l->data[1];

                        if (l->length <= len(l)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", len(l)-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3659");
                        };
                        struct Tok lt = l->data[len(l)-1];
if (((strcmp(st.cont, "{") != 0)||(strcmp(lt.cont, "}") != 0))) {
throwErr(&st,"Expected code block after keyword {TOKEN}.");
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i = 2;
while ((i<len(l)-1)) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3666");
                        };
                        
{
long nLength = i-2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i-2] = l->data[i];
nl->length = nLength+1;
} else {
nl->data[i-2] = l->data[i];
}
};
i = i+1;
};
parseLines(nl,elems);
};
void parseAsync(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)!=2)) {

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3676");
                        };
                        struct Tok ft = l->data[0];
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3679");
                        };
                        struct Tok fnT = l->data[1];
if ((fnT.isFunc==false)) {
throwErr(&fnT,"Cannot use keyword async on {TOKEN}. Usage: 'async <function call>'.");
}
char found = false;
long int i = 0;
while ((i<len(compilerState.cLibs))) {

                        if (compilerState.cLibs->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: compilerState.cLibs[%d] with length %d", i, compilerState.cLibs->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3686");
                        };
                        if ((strcmp(compilerState.cLibs->data[i], "lpthread") == 0)) {
found = true;
break;
}
i = i+1;
};
if ((found==false)) {

{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] = "lpthread";
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] = "lpthread";
}
};
}
struct string sFnT = string(fnT.cont);
array(struct string)* fnNameParts = splitString(sFnT,"(");

                        if (fnNameParts->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: fnNameParts[%d] with length %d", 0, fnNameParts->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3699");
                        };
                        struct string fnName = fnNameParts->data[0];
char * ____BAH_COMPILER_VAR_707 =fnName.str(&fnName);struct func* fn = searchFunc(____BAH_COMPILER_VAR_707,elems,true);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_708 =null;char * ____BAH_COMPILER_VAR_709 =fnName.str(&fnName);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Internal compiler error.\n Error parsing async call for function '");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_709);
long int strLen_6 = strlen("', arround {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_708 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_708+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_708+currStrOff, ____BAH_COMPILER_VAR_709, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_708+currStrOff, "', arround {TOKEN}.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&fnT,____BAH_COMPILER_VAR_708);
}
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {

                        if (fn->args->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", i, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3710");
                        };
                        struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_710 =null;char * ____BAH_COMPILER_VAR_711 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(sMembs);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_711);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(a->name);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_710 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_710+currStrOff, sMembs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_710+currStrOff, ____BAH_COMPILER_VAR_711, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_710+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_710+currStrOff, a->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_710+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                sMembs = ____BAH_COMPILER_VAR_710;
char * ____BAH_COMPILER_VAR_712 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(unSerMembs);
long int strLen_4 = strlen("args->");
long int strLen_6 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_712 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, unSerMembs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, "args->", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, a->name, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                unSerMembs = ____BAH_COMPILER_VAR_712;
i = i+1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_713 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(unSerMembs);
long int strLen_4 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_713 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_713+currStrOff, unSerMembs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_713+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                unSerMembs = ____BAH_COMPILER_VAR_713;
}
};
char * ____BAH_COMPILER_VAR_714 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("struct {\n");
long int strLen_4 = strlen(sMembs);
long int strLen_6 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_714 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_714+currStrOff, "struct {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_714+currStrOff, sMembs, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_714+currStrOff, "}", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * tmpArgsStruct = ____BAH_COMPILER_VAR_714;
char * fnWrapper = genCompilerVar();
char * tmpArgs = genCompilerVar();
sFnT.trimLeft(&sFnT,fnName.length+1);
sFnT.trimRight(&sFnT,1);
char * tCreate = "";
if ((strcmp(BAH_OS, "windows") == 0)) {
tCreate = "pthread_create";
}
else {
if (RCPavailable()) {
tCreate = "pthread_create";
}
else {
tCreate = "GC_pthread_create";
}
}
char * ____BAH_COMPILER_VAR_715 =null;char * ____BAH_COMPILER_VAR_716 =fnName.str(&fnName);char * ____BAH_COMPILER_VAR_717 =sFnT.str(&sFnT);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    void ");
long int strLen_2 = strlen(fnWrapper);
long int strLen_4 = strlen("(");
long int strLen_6 = strlen(tmpArgsStruct);
long int strLen_8 = strlen("* args) {\n        ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_716);
long int strLen_12 = strlen("(");
long int strLen_14 = strlen(unSerMembs);
long int strLen_16 = strlen(");\n    };\n    {\n        ");
long int strLen_18 = strlen(tmpArgsStruct);
long int strLen_20 = strlen(" ");
long int strLen_22 = strlen(tmpArgs);
long int strLen_24 = strlen(" = {");
long int strLen_26 = strlen(____BAH_COMPILER_VAR_717);
long int strLen_28 = strlen("};\n        pthread_t id;\n        ");
long int strLen_30 = strlen(tCreate);
long int strLen_32 = strlen("(&id, 0, ");
long int strLen_34 = strlen(fnWrapper);
long int strLen_36 = strlen(", &");
long int strLen_38 = strlen(tmpArgs);
long int strLen_40 = strlen(");\n    }; \n    \n    ");
;                            
                    ____BAH_COMPILER_VAR_715 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34 + strLen_36 + strLen_38 + strLen_40);
                    
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, "\n    void ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, fnWrapper, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, tmpArgsStruct, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, "* args) {\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, ____BAH_COMPILER_VAR_716, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, "(", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, unSerMembs, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, ");\n    };\n    {\n        ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, tmpArgsStruct, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, " ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, tmpArgs, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, " = {", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, ____BAH_COMPILER_VAR_717, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, "};\n        pthread_t id;\n        ", strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, tCreate, strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, "(&id, 0, ", strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, fnWrapper, strLen_34);
                        currStrOff += strLen_34;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, ", &", strLen_36);
                        currStrOff += strLen_36;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, tmpArgs, strLen_38);
                        currStrOff += strLen_38;
                        
                        memcpy(____BAH_COMPILER_VAR_715+currStrOff, ");\n    }; \n    \n    ", strLen_40);
                        currStrOff += strLen_40;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_715));
};
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
long int i = 0;
if ((ltp==LINE_TYPE_VAR)) {
i = 1;
}
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3758");
                        };
                        struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
struct variable* v = searchVar(t.cont,elems);
if ((v!=null)) {

{
long nLength = len(compilerState.RCPvars);
if (compilerState.RCPvars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.RCPvars->data, (nLength+50)*sizeof(struct variable*));
compilerState.RCPvars->data = newPtr;
}
compilerState.RCPvars->data[len(compilerState.RCPvars)] = v;
compilerState.RCPvars->length = nLength+1;
} else {
compilerState.RCPvars->data[len(compilerState.RCPvars)] = v;
}
};
}
}
i = i+1;
};
};
__BAH_ARR_TYPE_Tok parseChan(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i = 0;
for (; (i<len(l)); i = i+1) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3775");
                        };
                        struct Tok t = l->data[i];
if ((((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "->") == 0))||(strcmp(t.cont, "<-") == 0))) {
if ((strcmp(t.cont, "<-") == 0)) {
i = i+1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3781");
                        };
                        struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_718 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_718);
if ((ntt.hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_719 =null;char * ____BAH_COMPILER_VAR_720 =ntt.str(&ntt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use var {TOKEN} (");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_720);
long int strLen_6 = strlen(") as channel.");
;                            
                    ____BAH_COMPILER_VAR_719 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_719+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_719+currStrOff, ____BAH_COMPILER_VAR_720, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_719+currStrOff, ") as channel.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&nt,____BAH_COMPILER_VAR_719);
}
ntt.trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_721 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_721)) {
char * ____BAH_COMPILER_VAR_722 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_722,elems);
char * ____BAH_COMPILER_VAR_723 =null;char * ____BAH_COMPILER_VAR_724 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_724);
long int strLen_6 = strlen(")");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("->receive(");
long int strLen_12 = strlen(nt.cont);
long int strLen_14 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_723+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_723+currStrOff, ____BAH_COMPILER_VAR_724, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_723+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_723+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_723+currStrOff, "->receive(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_723+currStrOff, nt.cont, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_723+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_723;
}
else {
char * ____BAH_COMPILER_VAR_725 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_725,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_726 =null;char * ____BAH_COMPILER_VAR_727 =ntt.str(&ntt);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_727);
long int strLen_2 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_726 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_726+currStrOff, ____BAH_COMPILER_VAR_727, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_726+currStrOff, "*", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                char * ____BAH_COMPILER_VAR_728 =null;char * ____BAH_COMPILER_VAR_729 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_4 = strlen("(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_729);
long int strLen_8 = strlen("*)");
long int strLen_10 = strlen(nt.cont);
long int strLen_12 = strlen("->receive(");
long int strLen_14 = strlen(nt.cont);
long int strLen_16 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_728 = memoryAllocSTR(1 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, ____BAH_COMPILER_VAR_729, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, "*)", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, nt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, "->receive(", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, nt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, ")", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                tmpV = registerRCPvar(____BAH_COMPILER_VAR_726,____BAH_COMPILER_VAR_728,elems);
char * ____BAH_COMPILER_VAR_730 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("*");
long int strLen_4 = strlen(tmpV);
;                            
                    ____BAH_COMPILER_VAR_730 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_730+currStrOff, "*", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_730+currStrOff, tmpV, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_730;
}
else {
char * ____BAH_COMPILER_VAR_731 =null;char * ____BAH_COMPILER_VAR_732 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("*(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_732);
long int strLen_6 = strlen("*)");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("->receive(");
long int strLen_12 = strlen(nt.cont);
long int strLen_14 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_731 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_731+currStrOff, "*(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_731+currStrOff, ____BAH_COMPILER_VAR_732, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_731+currStrOff, "*)", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_731+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_731+currStrOff, "->receive(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_731+currStrOff, nt.cont, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_731+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_731;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_733 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_733)) {
char * ____BAH_COMPILER_VAR_734 =ntt.str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_734,t.cont,elems);
t.type = TOKEN_TYPE_VAR;
t.isFunc = false;
t.cont = tmpV;
}
else {
}
}
t.isValue = true;
t.bahType = ntt.str(&ntt);
}
else {
throwErr(&t,"Cannot use {TOKEN} on nothing");
}
}
else {
if ((i==0)) {
throwErr(&t,"Cannot une {TOKEN} on nothing.");
}
if ((i+1>=len(l))) {
throwErr(&t,"Cannot send ({TOKEN}) to nothing.");
}

                        if (l->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i+1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3835");
                        };
                        struct Tok pt = l->data[i+1];

                        if (l->length <= i-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3836");
                        };
                        struct Tok nt = l->data[i-1];
char * ntt = getTypeFromToken(&nt,true,elems);
if ((pt.type!=TOKEN_TYPE_VAR)) {
throwErr(&pt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_735 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_735);
if ((ptt.hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_736 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use var {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") as channel.");
;                            
                    ____BAH_COMPILER_VAR_736 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_736+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_736+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_736+currStrOff, ") as channel.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&pt,____BAH_COMPILER_VAR_736);
}
ptt.trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_737 =ptt.str(&ptt);if ((compTypes(____BAH_COMPILER_VAR_737,ntt)==false)) {
char * ____BAH_COMPILER_VAR_738 =null;char * ____BAH_COMPILER_VAR_739 =ptt.str(&ptt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot send {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") to channel of type ");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_739);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_738 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, "Cannot send {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, ") to channel of type ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, ____BAH_COMPILER_VAR_739, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&nt,____BAH_COMPILER_VAR_738);
}
i = i+1;
char * ____BAH_COMPILER_VAR_740 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_740)) {
char * ____BAH_COMPILER_VAR_741 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_2 = strlen("->send(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_741 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_741+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_741+currStrOff, "->send(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_741+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_741+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_741+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_741+currStrOff, ");\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_741));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_742 =null;char * ____BAH_COMPILER_VAR_743 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_743);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(tmpV);
long int strLen_8 = strlen(" = ");
long int strLen_10 = strlen(nt.cont);
long int strLen_12 = strlen(";\n                    ");
long int strLen_14 = strlen(pt.cont);
long int strLen_16 = strlen("->sendAny(");
long int strLen_18 = strlen(pt.cont);
long int strLen_20 = strlen(", &");
long int strLen_22 = strlen(tmpV);
long int strLen_24 = strlen(", sizeof(");
long int strLen_26 = strlen(tmpV);
long int strLen_28 = strlen("));\n");
;                            
                    ____BAH_COMPILER_VAR_742 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, "\n                    ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, ____BAH_COMPILER_VAR_743, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, tmpV, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, " = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, nt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, ";\n                    ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, pt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, "->sendAny(", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, pt.cont, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, ", &", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, tmpV, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, ", sizeof(", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, tmpV, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_742+currStrOff, "));\n", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_742));
}
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
return nl;
}
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] = t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] = t;
}
};
};
return nl;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){
array(struct Tok)* fl = memoryAlloc(sizeof(array(struct Tok)));

fl->length = 0;
fl->elemSize = sizeof(struct Tok);
long int i = 0;
long int nbPar = 0;
char isChan = false;
char isBool = false;
char isFunc = false;
char isArr = false;
char isStruct = false;
char isOper = false;
char isCast = false;
char needGuard = false;
if ((ltp!=(lineType)-1)) {
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3894");
                        };
                        struct Tok t = line->data[i];
if ((strcmp(t.cont, "(") == 0)) {
isFunc = true;
nbPar = nbPar+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPar = nbPar-1;
}
else if (((nbPar==0)&&(strcmp(t.cont, "{") == 0))) {

                        if (line->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3901");
                        };
                        struct Tok nt = line->data[i+1];
char isStructType = true;
if ((nt.line!=t.line)) {
break;
}
}
if ((isChan==false)) {
if (((strcmp(t.cont, "->") == 0)||(strcmp(t.cont, "<-") == 0))) {
isChan = true;
}
}
if ((isBool==false)) {

                int ____BAH_COMPILER_VAR_744 = 0;
                for(int i=len(comparators)-1; i != -1; i--) {
                    if (comparators->data[i] != 0 && strcmp(comparators->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_744 = 1;
                        break;
                    };
                };
                
                int ____BAH_COMPILER_VAR_745 = 0;
                for(int i=len(compSep)-1; i != -1; i--) {
                    if (compSep->data[i] != 0 && strcmp(compSep->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_745 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_744||____BAH_COMPILER_VAR_745)) {
isBool = true;
}
}
if ((isArr==false)) {
if ((strcmp(t.cont, "[") == 0)) {
isArr = true;
}
}
if ((isStruct==false)) {
if ((strcmp(t.cont, ".") == 0)) {
isStruct = true;
}
}
if ((isOper==false)) {

                int ____BAH_COMPILER_VAR_746 = 0;
                for(int i=len(signs)-1; i != -1; i--) {
                    if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_746 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_746||strHasPrefix(t.cont,"-"))) {
isOper = true;
}
}
if ((isCast==false)) {
if ((strcmp(t.cont, "<") == 0)) {
isCast = true;
}
}

{
long nLength = len(fl);
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[len(fl)] = t;
fl->length = nLength+1;
} else {
fl->data[len(fl)] = t;
}
};
i = i+1;
};
}
else {
isStruct = true;
isFunc = true;
isChan = true;
isArr = true;
isBool = true;
isOper = true;
isCast = true;
needGuard = true;
fl = line;
}
if ((isStruct==true)) {
fl = parseStructVars(fl,elems,needGuard);
}
if ((isFunc==true)) {
fl = parseFnCall(fl,ltp,elems,needGuard);
}
if ((isArr==true)) {
fl = parseArrayVars(fl,ltp,elems,needGuard);
fl = parseArrayType(fl,elems,needGuard);
}
if ((isCast==true)) {
fl = parseCast(fl,elems,needGuard);
}
addRCPvars(fl,ltp,elems);
if ((isOper==true)) {
fl = parseOperations(fl,ltp,elems);
}
if ((isBool==true)) {
fl = parseBool(fl,elems,needGuard);
}
if ((isChan==true)) {
fl = parseChan(fl,elems);
}
if ((ltp!=(lineType)-1)) {
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3983");
                        };
                        
{
long nLength = len(fl);
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[len(fl)] = line->data[i];
fl->length = nLength+1;
} else {
fl->data[len(fl)] = line->data[i];
}
};
i = i+1;
};
}
return fl;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i = 0;
struct func* ____BAH_COMPILER_VAR_747 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_747->name = "";
____BAH_COMPILER_VAR_747->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_747->args->length = 0;
            ____BAH_COMPILER_VAR_747->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_747->returns= null;
____BAH_COMPILER_VAR_747->isBinding = false;
____BAH_COMPILER_VAR_747->from = "";
____BAH_COMPILER_VAR_747->file = "";
____BAH_COMPILER_VAR_747->line = 1;
____BAH_COMPILER_VAR_747->used = false;
____BAH_COMPILER_VAR_747->code = null;
struct func* fn = ____BAH_COMPILER_VAR_747;
if (((RCPavailable()==false)&&(RCPenabled==true))) {
fn->used = true;
}

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4000");
                        };
                        struct Tok ft = l->data[0];
char * code = parseFnHeader("",l,&i,fn,elems);
fn->line = ft.line;
fn->file = compilerState.currentFile;
struct func* ogFn = searchFunc(fn->name,elems,false);
if ((ogFn!=null)) {
if ((ogFn->isBinding==false)) {
char * lineStr = intToStr(ogFn->line);
char * ____BAH_COMPILER_VAR_748 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
long int strLen_4 = strlen(ogFn->file);
long int strLen_6 = strlen(":");
long int strLen_8 = strlen(lineStr);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_748 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_748+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_748+currStrOff, ogFn->file, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_748+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_748+currStrOff, lineStr, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_748+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&ft,____BAH_COMPILER_VAR_748);
}
}
if ((strcmp(fn->name, "main") == 0)) {
compilerState.haveEntryPoint = true;
if ((compTypes(fn->returns->type,"int")==false)) {
throwErr(&ft,"{TOKEN} function should return 'int'.");
}
if ((len(fn->args)!=1)) {
throwErr(&ft,"{TOKEN} function should take one []cpstring argument. Should be: \n            'main(args []cpstring) int'");
}

                        if (fn->args->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", 0, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4021");
                        };
                        struct variable* fa = fn->args->data[0];
if ((compTypes(fa->type,"[]cpstring")==false)) {
throwErr(&ft,"{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}
if ((shouldOnlyDecl==true)) {
if ((ogFn!=null)) {
fn->isBinding = false;
}

{
long nLength = len(elems->fns);
if (elems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->fns->data, (nLength+50)*sizeof(struct func*));
elems->fns->data = newPtr;
}
elems->fns->data[len(elems->fns)] = fn;
elems->fns->length = nLength+1;
} else {
elems->fns->data[len(elems->fns)] = fn;
}
};
char * ____BAH_COMPILER_VAR_749 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_749 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_749+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_749+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_749));
return;
}
char * ____BAH_COMPILER_VAR_750 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen("{\n");
;                            
                    ____BAH_COMPILER_VAR_750 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_750+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_750+currStrOff, "{\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_750;
fn->code = rope(code);
struct Elems* fnElems = dupElems(elems);
array(struct variable*)* vs = fnElems->vars;
long int j = 0;
while ((j<len(fn->args))) {

                        if (fn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", j, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4046");
                        };
                        struct variable* a = fn->args->data[j];
a->outterScope = true;

{
long nLength = len(vs);
if (vs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(vs->data, (nLength+50)*sizeof(struct variable*));
vs->data = newPtr;
}
vs->data[len(vs)] = a;
vs->length = nLength+1;
} else {
vs->data[len(vs)] = a;
}
};
j = j+1;
};
fnElems->vars = vs;
if ((ogFn!=null)) {
ogFn->isBinding = false;
ogFn->used = true;
ogFn = fn;
}
else {
array(struct func*)* fns = elems->fns;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] = fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] = fn;
}
};
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
i = i+1;
long int max = len(l)-1;
while ((i<max)) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4066");
                        };
                        struct Tok t = l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = t;
}
};
i = i+1;
};
if ((len(tokens)==0)) {
fn->code = fn->code->add(fn->code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, fn->code);
return;
}
currentFn = fn;
struct rope* oOut = OUTPUT;
OUTPUT = rope("");

                        if (tokens->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: tokens[%d] with length %d", 0, tokens->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4081");
                        };
                        struct Tok t = tokens->data[0];
beginRCPscope(fnElems,fn->args);
struct Elems* ocurrFnElems = compilerState.currFnElems;
compilerState.currFnElems = fnElems;
parseLines(tokens,fnElems);
compilerState.currFnElems = ocurrFnElems;
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_751 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Function '");
long int strLen_4 = strlen(fn->name);
long int strLen_6 = strlen("' is not returned.");
;                            
                    ____BAH_COMPILER_VAR_751 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_751+currStrOff, "Function '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_751+currStrOff, fn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_751+currStrOff, "' is not returned.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_751);
}
endRCPscope(fnElems,fn->args);
}
fn->code = fn->code->add(fn->code, OUTPUT);
OUTPUT = oOut;
fn->code = fn->code->add(fn->code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, fn->code);
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_752 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_752->name= null;
____BAH_COMPILER_VAR_752->returns= null;
____BAH_COMPILER_VAR_752->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_752->args->length = 0;
            ____BAH_COMPILER_VAR_752->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_752;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_753 = df;
char ** ____BAH_COMPILER_VAR_755 = (char **)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_756 = __reflect(____BAH_COMPILER_VAR_755, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_757 = (char **)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_758 = __reflect(____BAH_COMPILER_VAR_757, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_759 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_753) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_760 = 0;
char ** ____BAH_COMPILER_VAR_762 = (char **)((char*)(____BAH_COMPILER_VAR_760) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_763 = __reflect(____BAH_COMPILER_VAR_762, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_764 = (char **)((char*)(____BAH_COMPILER_VAR_760) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_765 = __reflect(____BAH_COMPILER_VAR_764, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_766 = (char*)((char*)(____BAH_COMPILER_VAR_760) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_767 = __reflect(____BAH_COMPILER_VAR_766, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_768 = (char **)((char*)(____BAH_COMPILER_VAR_760) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_769 = __reflect(____BAH_COMPILER_VAR_768, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_770 = (char*)((char*)(____BAH_COMPILER_VAR_760) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_771 = __reflect(____BAH_COMPILER_VAR_770, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_772 = (char **)((char*)(____BAH_COMPILER_VAR_760) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_773 = __reflect(____BAH_COMPILER_VAR_772, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_774 = (char*)((char*)(____BAH_COMPILER_VAR_760) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_775 = __reflect(____BAH_COMPILER_VAR_774, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_776 = (char*)((char*)(____BAH_COMPILER_VAR_760) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_777 = __reflect(____BAH_COMPILER_VAR_776, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_761 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_761->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_761->length = 8;
        ____BAH_COMPILER_VAR_761->data = memoryAlloc(____BAH_COMPILER_VAR_761->length * ____BAH_COMPILER_VAR_761->elemSize);
        ____BAH_COMPILER_VAR_761->data[0] = ____BAH_COMPILER_VAR_763;
____BAH_COMPILER_VAR_761->data[1] = ____BAH_COMPILER_VAR_765;
____BAH_COMPILER_VAR_761->data[2] = ____BAH_COMPILER_VAR_767;
____BAH_COMPILER_VAR_761->data[3] = ____BAH_COMPILER_VAR_769;
____BAH_COMPILER_VAR_761->data[4] = ____BAH_COMPILER_VAR_771;
____BAH_COMPILER_VAR_761->data[5] = ____BAH_COMPILER_VAR_773;
____BAH_COMPILER_VAR_761->data[6] = ____BAH_COMPILER_VAR_775;
____BAH_COMPILER_VAR_761->data[7] = ____BAH_COMPILER_VAR_777;
struct reflectElement ____BAH_COMPILER_VAR_778 = __reflect(____BAH_COMPILER_VAR_760, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_761, 0);

        struct reflectElement ____BAH_COMPILER_VAR_779 = ____BAH_COMPILER_VAR_778;
        struct reflectElement ____BAH_COMPILER_VAR_780 = __reflect(____BAH_COMPILER_VAR_759, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_779, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_754 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_754->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_754->length = 3;
        ____BAH_COMPILER_VAR_754->data = memoryAlloc(____BAH_COMPILER_VAR_754->length * ____BAH_COMPILER_VAR_754->elemSize);
        ____BAH_COMPILER_VAR_754->data[0] = ____BAH_COMPILER_VAR_756;
____BAH_COMPILER_VAR_754->data[1] = ____BAH_COMPILER_VAR_758;
____BAH_COMPILER_VAR_754->data[2] = ____BAH_COMPILER_VAR_780;
struct reflectElement ____BAH_COMPILER_VAR_781 = __reflect(____BAH_COMPILER_VAR_753, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_754, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_781);

                        if (l->length <= len(l)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", len(l)-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4110");
                        };
                        struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,fnElems);
}
};
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
if ((len(line)==0)) {
return;
}
line = parsePointers(line);
lineType ltp = getLineType(line);
compilerState.RCPvars = memoryAlloc(sizeof(array(struct variable*)));

compilerState.RCPvars->length = 0;
compilerState.RCPvars->elemSize = sizeof(struct variable*);
currSetVar = null;
if ((ltp==LINE_TYPE_VAR)) {

                        if (line->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", 0, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4131");
                        };
                        struct Tok ft = line->data[0];

                        if (line->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", 1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4132");
                        };
                        struct Tok st = line->data[1];
if ((strcmp(st.cont, "=") == 0)) {
struct variable* v = searchVar(ft.cont,elems);
currSetVar = v;
}
}
char parsed = false;
if ((ltp==LINE_TYPE_INCLUDE)) {
parsed = true;
parseInclude(line,elems);
}
else if ((ltp==LINE_TYPE_IMPORT)) {
parsed = true;
parseImport(line,elems);
}
else if ((ltp==LINE_TYPE_DEFINE)) {
parsed = true;
parseDefine(line,elems);
}
else if ((ltp==LINE_TYPE_CLIB)) {
parsed = true;
parseClib(line);
}
else if ((ltp==LINE_TYPE_STRUCT)) {
parsed = true;
parseStruct(line,elems);
}
else if ((ltp==LINE_TYPE_CONST)) {
parsed = true;
parseConst(line,elems);
}
else if ((ltp==LINE_TYPE_MACRO)) {
return;
}
else if ((ltp!=LINE_TYPE_FN_DECL)) {
line = prePross(line,ltp,elems);
if ((len(line)==0)) {
return;
}
}

                        if (line->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", 0, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4167");
                        };
                        struct Tok ft = line->data[0];
if (((ft.isOper==false)&&(ft.isFunc==true))) {
struct string ____BAH_COMPILER_VAR_782 =string(ft.cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_782,"(");
struct func* fn = searchFunc(fnName,elems,true);
if ((((fn!=null)&&(fn->returns!=null))&&isRCPtype(fn->returns->type,elems))) {
char * ____BAH_COMPILER_VAR_783 =registerRCPvar(fn->returns->type,ft.cont,elems);return;
}
}
if ((ltp==LINE_TYPE_VAR)) {
parsed = true;
parseVar(line,elems);
}
else if ((ltp==LINE_TYPE_FN_CALL)) {
if ((len(line)>1)) {
throwErr(&line->data[len(line)-1],"Not expecting {TOKEN} after function call.");
}
parsed = true;
char * ____BAH_COMPILER_VAR_784 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_784 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_784+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_784+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_784));
}
else if ((ltp==LINE_TYPE_FN_DECL)) {
parsed = true;
parseFnDeclare(line,elems);
}
else if ((ltp==LINE_TYPE_RETURN)) {
parsed = true;
parseReturn(line,elems);
}
else if ((ltp==LINE_TYPE_IF)) {
parsed = true;
parseIf(line,elems);
}
else if ((ltp==LINE_TYPE_ELSE)) {
parsed = true;
parseElse(line,elems);
}
else if ((ltp==LINE_TYPE_FOR)) {
parsed = true;
parseFor(line,elems);
}
else if ((ltp==LINE_TYPE_FOR_OPERATOR)) {
parsed = true;
parseForOp(line,elems);
}
else if ((ltp==LINE_TYPE_PRE_KEYWORD)) {
parsePreKeyword(line,elems);
parsed = true;
}
else if ((ltp==LINE_TYPE_ASYNC)) {
parseAsync(line,elems);
parsed = true;
}
if ((parsed==false)) {
throwErr(&ft,"{TOKEN} not expected.");
}
if ((strlen(NEXT_LINE)>0)) {
OUTPUT = OUTPUT->add(OUTPUT, rope(NEXT_LINE));
NEXT_LINE = "";
}
prevLine = ltp;
};
void parseLines(__BAH_ARR_TYPE_Tok tokens,struct Elems* elems){
if ((len(tokens)==0)) {
return;
}
array(struct Tok)* line = memoryAlloc(sizeof(array(struct Tok)));

line->length = 0;
line->elemSize = sizeof(struct Tok);

                        if (tokens->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: tokens[%d] with length %d", 0, tokens->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4232");
                        };
                        struct Tok ft = tokens->data[0];
long int currentLine = ft.line;
long int nbEncl = 0;
long int i = 0;
while ((i<len(tokens))) {

                        if (tokens->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: tokens[%d] with length %d", i, tokens->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4236");
                        };
                        struct Tok t = tokens->data[i];
if ((t.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(t.cont, "(") == 0)) {
nbEncl = nbEncl+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbEncl = nbEncl-1;
}
else if ((strcmp(t.cont, "{") == 0)) {
nbEncl = nbEncl+1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbEncl = nbEncl-1;
}
else if ((strcmp(t.cont, "[") == 0)) {
nbEncl = nbEncl+1;
}
else if ((strcmp(t.cont, "]") == 0)) {
nbEncl = nbEncl-1;
}
}
if (((t.type==TOKEN_TYPE_STR)&&(t.begLine==currentLine))) {
currentLine = t.line;
}
if ((nbEncl==0)) {
if ((t.line!=currentLine)) {
if ((t.type==TOKEN_TYPE_ENCL)) {

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(struct Tok));
line->data = newPtr;
}
line->data[len(line)] = t;
line->length = nLength+1;
} else {
line->data[len(line)] = t;
}
};

                        if (tokens->length <= i-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: tokens[%d] with length %d", i-1, tokens->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4262");
                        };
                        struct Tok pt = tokens->data[i-1];
currentLine = pt.line;
}
else {
currentLine = t.line;
}
parseLine(line,elems);
clear(line);
if ((t.type==TOKEN_TYPE_ENCL)) {
i = i+1;
continue;
}
}
else if ((strcmp(t.cont, ";") == 0)) {
currentLine = t.line;
parseLine(line,elems);
clear(line);
i = i+1;
continue;
}
}

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(struct Tok));
line->data = newPtr;
}
line->data[len(line)] = t;
line->length = nLength+1;
} else {
line->data[len(line)] = t;
}
};
i = i+1;
};
if ((len(line)>0)) {
if ((nbEncl==0)) {
parseLine(line,elems);
clear(line);
}
else {

                        if (line->length <= len(line)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", len(line)-1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4291");
                        };
                        ft = line->data[len(line)-1];
throwErr(&ft,"Missing closing token, line ending by {TOKEN}.");
}
}
};
void declareFunc(struct func* fn,struct Elems* elems){
struct string tmpfnRetCType = getCType(fn->returns->type,elems);
char * tmpfnArgsCType = "";
long int j = 0;
while ((j<len(fn->args))) {

                        if (fn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", j, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/declarative.bah:6");
                        };
                        struct variable* arg = fn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_785 =null;char * ____BAH_COMPILER_VAR_786 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_786);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(arg->name);
;                            
                    ____BAH_COMPILER_VAR_785 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_785+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_785+currStrOff, ____BAH_COMPILER_VAR_786, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_785+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_785+currStrOff, arg->name, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_785;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_787 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_787 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_787+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_787+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_787;
}
};
char * ____BAH_COMPILER_VAR_788 =null;char * ____BAH_COMPILER_VAR_789 =tmpfnRetCType.str(&tmpfnRetCType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_789);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(fn->name);
long int strLen_6 = strlen("(");
long int strLen_8 = strlen(tmpfnArgsCType);
long int strLen_10 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_788 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_788+currStrOff, ____BAH_COMPILER_VAR_789, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_788+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_788+currStrOff, fn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_788+currStrOff, "(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_788+currStrOff, tmpfnArgsCType, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_788+currStrOff, ");\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_788));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_790 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(v->constVal);
long int strLen_8 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_790+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_790+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_790+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_790+currStrOff, v->constVal, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_790+currStrOff, "\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_790));
}
else {
struct string cType = getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_791 =null;char * ____BAH_COMPILER_VAR_792 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_792);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_791 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_791+currStrOff, ____BAH_COMPILER_VAR_792, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_791+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_791+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_791+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_791));
}
};
void declareAll(struct Elems* elems){
OUTPUT = rope("\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\ntypedef array(char*)* __BAH_ARR_TYPE_cpstring;\nlong int __BAH__main(__BAH_ARR_TYPE_cpstring);\n");
long int i = 0;
for (; (i<len(compilerState.cIncludes)); i = i+1) {

                        if (compilerState.cIncludes->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: compilerState.cIncludes[%d] with length %d", i, compilerState.cIncludes->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/declarative.bah:42");
                        };
                        char * ____BAH_COMPILER_VAR_793 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#include ");
long int strLen_2 = strlen(compilerState.cIncludes->data[i]);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_793 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_793+currStrOff, "#include ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_793+currStrOff, compilerState.cIncludes->data[i], strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_793+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_793));
};
i = 1;
for (; (i<len(compilerState.arrTypesDecl)); i = i+1) {

                        if (compilerState.arrTypesDecl->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: compilerState.arrTypesDecl[%d] with length %d", i, compilerState.arrTypesDecl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/declarative.bah:46");
                        };
                        char * t = compilerState.arrTypesDecl->data[i];
struct string elemType = string(t);
elemType.trimLeft(&elemType,15);
char * ____BAH_COMPILER_VAR_794 =elemType.str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_794,elems);
char * ____BAH_COMPILER_VAR_795 =null;char * ____BAH_COMPILER_VAR_796 =elemCtype.str(&elemCtype);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("typedef array(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_796);
long int strLen_4 = strlen(")* ");
long int strLen_6 = strlen(t);
long int strLen_8 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_795 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_795+currStrOff, "typedef array(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_795+currStrOff, ____BAH_COMPILER_VAR_796, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_795+currStrOff, ")* ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_795+currStrOff, t, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_795+currStrOff, ";\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_795));
};
i = 0;
for (; (i<len(elems->vars)); i = i+1) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/declarative.bah:54");
                        };
                        struct variable* v = elems->vars->data[i];
declareVar(v,elems);
};
i = 0;
for (; (i<len(elems->fns)); i = i+1) {

                        if (elems->fns->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->fns[%d] with length %d", i, elems->fns->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/declarative.bah:59");
                        };
                        struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
declareFunc(fn,elems);
};
};
long int main(__BAH_ARR_TYPE_cpstring args){

                        if (args->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: args[%d] with length %d", 0, args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:51");
                        };
                        execName = args->data[0];
if (((cpstringCharAt(execName,0)==46)||(cpstringCharAt(execName,0)==47))) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_797 = {};
____BAH_COMPILER_VAR_797.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_797.flags->length = 0;
            ____BAH_COMPILER_VAR_797.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_797.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_797.args->length = 0;
            ____BAH_COMPILER_VAR_797.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_797.addString = flags__addString;
____BAH_COMPILER_VAR_797.addBool = flags__addBool;
____BAH_COMPILER_VAR_797.addInt = flags__addInt;
____BAH_COMPILER_VAR_797.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_797.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_797.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_797.get = flags__get;
____BAH_COMPILER_VAR_797.getInt = flags__getInt;
____BAH_COMPILER_VAR_797.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_797.isSet = flags__isSet;
____BAH_COMPILER_VAR_797.parse = flags__parse;
flags = ____BAH_COMPILER_VAR_797;
flags.addString(&flags,"o","Name of the file to output.");
flags.addBool(&flags,"c","Translate bah file to C instead of compiling it.");
flags.addBool(&flags,"v","Show version of the compiler.");
flags.addBool(&flags,"l","Compile as a library.");
flags.addBool(&flags,"d","Compile as a dynamic executable. (useful if you are using a library that is only available shared but might reduce portability).");
flags.addBool(&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");
flags.addBool(&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");
flags.addBool(&flags,"debug","Enables verbose json output.");
flags.addBool(&flags,"verboseRuntime","Enables verbose runtime, a debug mode of the compiled program.");
flags.addBool(&flags,"verboseCC","Enables verbose C compiler output, USE IN LAST RESORT.");
char * ____BAH_COMPILER_VAR_798 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_4 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
long int strLen_6 = strlen(BAH_OS);
long int strLen_8 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_798 = memoryAllocSTR(1 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_798+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_798+currStrOff, BAH_OS, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_798+currStrOff, ".", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                flags.addString(&flags,"target",____BAH_COMPILER_VAR_798);
char * ____BAH_COMPILER_VAR_799 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_4 = strlen("If your Bah directory is not the default one (");
long int strLen_6 = strlen(BAH_DIR);
long int strLen_8 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_799 = memoryAllocSTR(1 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_799+currStrOff, "If your Bah directory is not the default one (", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_799+currStrOff, BAH_DIR, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_799+currStrOff, ").", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                flags.addString(&flags,"bahDir",____BAH_COMPILER_VAR_799);
char * ____BAH_COMPILER_VAR_800 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_4 = strlen("To change the C compiler used, default: ");
long int strLen_6 = strlen(BAH_CC);
long int strLen_8 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_800 = memoryAllocSTR(1 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_800+currStrOff, "To change the C compiler used, default: ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_800+currStrOff, BAH_CC, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_800+currStrOff, ".", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                flags.addString(&flags,"CC",____BAH_COMPILER_VAR_800);
flags.addBool(&flags,"object","Compile as an object.");
flags.addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags.parse(&flags,args);
if ((flags.isSet(&flags,"target")==1)) {
BAH_OS = flags.get(&flags,"target");
char * ____BAH_COMPILER_VAR_801 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Build target: ");
long int strLen_2 = strlen(BAH_OS);
;                            
                    ____BAH_COMPILER_VAR_801 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_801+currStrOff, "Build target: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_801+currStrOff, BAH_OS, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                println(____BAH_COMPILER_VAR_801);
}
if ((flags.isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags.get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);

                        if (bahDirArr->length <= len(bahDirArr)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: bahDirArr[%d] with length %d", len(bahDirArr)-1, bahDirArr->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:89");
                        };
                        if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_802 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("/");
;                            
                    ____BAH_COMPILER_VAR_802 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_802+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_802+currStrOff, "/", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                BAH_DIR = ____BAH_COMPILER_VAR_802;
}
char * ____BAH_COMPILER_VAR_803 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Bah directory: ");
long int strLen_2 = strlen(BAH_DIR);
;                            
                    ____BAH_COMPILER_VAR_803 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_803+currStrOff, "Bah directory: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_803+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                println(____BAH_COMPILER_VAR_803);
}
if ((flags.isSet(&flags,"CC")==1)) {
BAH_CC = flags.get(&flags,"CC");
char * ____BAH_COMPILER_VAR_804 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("C compiler: ");
long int strLen_2 = strlen(BAH_CC);
;                            
                    ____BAH_COMPILER_VAR_804 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_804+currStrOff, "C compiler: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_804+currStrOff, BAH_CC, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                println(____BAH_COMPILER_VAR_804);
}
RCPlevel = 0;
if (flags.isSet(&flags,"rcp")) {
RCPlevel = 1;
}
else if (flags.isSet(&flags,"fastrcp")) {
RCPlevel = 2;
}
verboseRuntime = (flags.isSet(&flags,"verboseRuntime")==1);
debug = (flags.isSet(&flags,"debug")==1);
isObject = (flags.isSet(&flags,"object")==1);
isUnsafe = (flags.isSet(&flags,"unsafe")==1);
if ((debug==true)) {
debugStart();
}
RCPenabled = ((flags.isSet(&flags,"rcp")==1)||flags.isSet(&flags,"fastrcp"));
if ((flags.isSet(&flags,"v")==1)) {
char * ____BAH_COMPILER_VAR_805 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Bah compiler version: ");
long int strLen_2 = strlen(BAH_VERSION);
long int strLen_4 = strlen(".\n© Alois Laurent Boe");
;                            
                    ____BAH_COMPILER_VAR_805 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_805+currStrOff, "Bah compiler version: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_805+currStrOff, BAH_VERSION, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_805+currStrOff, ".\n© Alois Laurent Boe", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                println(____BAH_COMPILER_VAR_805);
return 0;
}
if (((flags.isSet(&flags,"c")==1)&&(flags.isSet(&flags,"l")==1))) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:123");
}
INIT = rope("");
OUTPUT = rope("\n    void __BAH_init();\n    #define noCheck(v) v\n    #define array(type)	\
    struct{	\
    type *data; \
    long int length; \
    long int elemSize; \
    }\n    typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n    long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n    ");
if ((flags.isSet(&flags,"l")==0)) {
if ((RCPenabled==true)) {
OUTPUT = OUTPUT->add(OUTPUT, rope("\n            void RCP_init();\n            void RCP_shutdown();\n            void free(void*);\n            int main(int argc, char ** argv) {\n            RCP_init();\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            RCP_shutdown();\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
else {
OUTPUT = OUTPUT->add(OUTPUT, rope("\n            #include <gc.h>\n            int main(int argc, char ** argv) {\n            GC_INIT();\n            array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n            args->data = GC_MALLOC(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            GC_FREE(args->data);\n            GC_FREE(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
}
struct compilerStateTag ____BAH_COMPILER_VAR_806 = {};
____BAH_COMPILER_VAR_806.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_806.includes->length = 0;
            ____BAH_COMPILER_VAR_806.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_806.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_806.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_806.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_806.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_806.cLibs->length = 0;
            ____BAH_COMPILER_VAR_806.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_806.currentFile= null;
____BAH_COMPILER_VAR_806.currentDir = "./";
____BAH_COMPILER_VAR_806.isBranch = false;
____BAH_COMPILER_VAR_806.isFor = false;
____BAH_COMPILER_VAR_806.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_806.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_806.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_806.haveEntryPoint = false;
____BAH_COMPILER_VAR_806.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_806.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_806.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_806.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_806.evals->length = 0;
            ____BAH_COMPILER_VAR_806.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_806.hasImports = false;
____BAH_COMPILER_VAR_806.currForElems= null;
____BAH_COMPILER_VAR_806.currFnElems= null;
compilerState = ____BAH_COMPILER_VAR_806;

{
long nLength = 0;
if (compilerState.arrTypesDecl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.arrTypesDecl->data, (nLength+50)*sizeof(char *));
compilerState.arrTypesDecl->data = newPtr;
}
compilerState.arrTypesDecl->data[0] = "__BAH_ARR_TYPE_cpstring";
compilerState.arrTypesDecl->length = nLength+1;
} else {
compilerState.arrTypesDecl->data[0] = "__BAH_ARR_TYPE_cpstring";
}
};
char * fileName = absPath(args->data[1]);
compilerState.currentFile = fileName;
struct fileMap ____BAH_COMPILER_VAR_807 = {};
____BAH_COMPILER_VAR_807.handle = -1;
____BAH_COMPILER_VAR_807.p= null;
____BAH_COMPILER_VAR_807.open = fileMap__open;
____BAH_COMPILER_VAR_807.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_807.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_807
char * f = fm.open(&fm,fileName);
if (((fm.isValid(&fm)==0)||(fm.size==0))) {
char * ____BAH_COMPILER_VAR_808 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not open file '");
long int strLen_2 = strlen(fileName);
long int strLen_4 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_808 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_808+currStrOff, "Could not open file '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_808+currStrOff, fileName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_808+currStrOff, "'.", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                println(____BAH_COMPILER_VAR_808);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f);
fm.close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_809 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("File '");
long int strLen_2 = strlen(fileName);
long int strLen_4 = strlen("' not recognized.");
;                            
                    ____BAH_COMPILER_VAR_809 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_809+currStrOff, "File '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_809+currStrOff, fileName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_809+currStrOff, "' not recognized.", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                println(____BAH_COMPILER_VAR_809);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_810 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_810->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_810->vars->length = 0;
            ____BAH_COMPILER_VAR_810->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_810->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_810->structs->length = 0;
            ____BAH_COMPILER_VAR_810->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_810->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_810->types->length = 0;
            ____BAH_COMPILER_VAR_810->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_810->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_810->fns->length = 0;
            ____BAH_COMPILER_VAR_810->fns->elemSize = sizeof(struct func*);
            struct Elems* elems = ____BAH_COMPILER_VAR_810;
if ((isObject==true)) {
OUTPUT = rope("\n        #define noCheck(v) v\n        #define array(type)	\
        struct{	\
        type *data; \
        long int length; \
        long int elemSize; \
        }\n        typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n        long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n        ");
shouldOnlyDecl = true;
}
if ((includeFile("builtin.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_811 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not find std-libs, please check '");
long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_811 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_811+currStrOff, "Could not find std-libs, please check '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_811+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_811+currStrOff, "'", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                __BAH_panic(____BAH_COMPILER_VAR_811,"/home/alois/Documents/bah-bah/src/main.bah:229");
}
shouldOnlyDecl = false;
if ((flags.isSet(&flags,"l")==1)) {
OUTPUT = rope("");
declareAll(elems);
}
compilerState.currentDir = getDirFromFile(fileName);
parseLines(tokens,elems);
if (((isObject==false)&&(isUnsafe==false))) {
long int l = 0;
long int i = 0;
for (; (i<len(elems->fns)); i = i+1) {

                        if (elems->fns->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->fns[%d] with length %d", i, elems->fns->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:245");
                        };
                        struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
l = l+1;
};
char * ____BAH_COMPILER_VAR_812 =null;char * ____BAH_COMPILER_VAR_813 =intToStr(l);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_813);
long int strLen_4 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_812 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, ____BAH_COMPILER_VAR_813, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, "];", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_812));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); i = i+1) {

                        if (elems->fns->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->fns[%d] with length %d", i, elems->fns->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:254");
                        };
                        struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char * ____BAH_COMPILER_VAR_814 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fn->from);
long int strLen_4 = strlen("__");
;                            
                    ____BAH_COMPILER_VAR_814 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_814+currStrOff, fn->from, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_814+currStrOff, "__", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                if (((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_814))) {
struct string n = string(name);
n.trimLeft(&n,strlen(fn->from)+2);
char * ____BAH_COMPILER_VAR_815 =null;char * ____BAH_COMPILER_VAR_816 =n.str(&n);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fn->from);
long int strLen_4 = strlen(".");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_816);
;                            
                    ____BAH_COMPILER_VAR_815 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_815+currStrOff, fn->from, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_815+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_815+currStrOff, ____BAH_COMPILER_VAR_816, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                name = ____BAH_COMPILER_VAR_815;
}
char * ____BAH_COMPILER_VAR_817 =null;char * ____BAH_COMPILER_VAR_818 =intToStr(j);char * ____BAH_COMPILER_VAR_819 =intToStr(j);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n            __tmp____Bah_fnNames[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_818);
long int strLen_4 = strlen("].n = \"");
long int strLen_6 = strlen(name);
long int strLen_8 = strlen("\";\n            __tmp____Bah_fnNames[");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_819);
long int strLen_12 = strlen("].p = ");
long int strLen_14 = strlen(fn->name);
long int strLen_16 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_817 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, "\n            __tmp____Bah_fnNames[", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, ____BAH_COMPILER_VAR_818, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, "].n = \"", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, "\";\n            __tmp____Bah_fnNames[", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, ____BAH_COMPILER_VAR_819, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, "].p = ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, fn->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, ";\n", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_817));
j = j+1;
};
char * ____BAH_COMPILER_VAR_820 =null;char * ____BAH_COMPILER_VAR_821 =intToStr(l);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_821);
long int strLen_4 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_820 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_820+currStrOff, "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_820+currStrOff, ____BAH_COMPILER_VAR_821, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_820+currStrOff, ";", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_820));
}
makeInit();
array(char *)* excludeFns = memoryAlloc(sizeof(array(char *)));

excludeFns->length = 6;
excludeFns->elemSize = sizeof(char *);
excludeFns->data = memoryAlloc(sizeof(char *) * 50);excludeFns->data[0] = "main";
excludeFns->data[1] = "cpstringCharAt";
excludeFns->data[2] = "cpstringSubsitute";
excludeFns->data[3] = "channel";
excludeFns->data[4] = "mapWrapper";
excludeFns->data[5] = "arraySubstitute";
if ((debug==true)) {
debugEnd();
return 0;
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char * ____BAH_COMPILER_VAR_822 =null;char * ____BAH_COMPILER_VAR_823 =intToStr(totalLines);char * ____BAH_COMPILER_VAR_824 =intToStr(totalTime/1000000);char * ____BAH_COMPILER_VAR_825 =intToStr(totalLexerTime/1000000);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Parsed. (");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_823);
long int strLen_4 = strlen(" lines, total time: ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_824);
long int strLen_8 = strlen("ms, lexer time: ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_825);
long int strLen_12 = strlen("ms)\e[0m");
;                            
                    ____BAH_COMPILER_VAR_822 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, "Parsed. (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, ____BAH_COMPILER_VAR_823, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, " lines, total time: ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, ____BAH_COMPILER_VAR_824, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, "ms, lexer time: ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, ____BAH_COMPILER_VAR_825, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, "ms)\e[0m", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                println(____BAH_COMPILER_VAR_822);
}
if ((flags.isSet(&flags,"o")==1)) {
fileName = flags.get(&flags,"o");
}
else {
struct string outFileName = string(args->data[1]);
outFileName.trimRight(&outFileName,4);
fileName = outFileName.str(&outFileName);
}
char * isStatic = "-static";
if (((flags.isSet(&flags,"d")==1)||(strcmp(BAH_OS, "darwin") == 0))) {
isStatic = "";
}
if ((flags.isSet(&flags,"c")==0)) {
char * obj = "";
if ((flags.isSet(&flags,"object")==1)) {
char * ____BAH_COMPILER_VAR_826 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fileName);
long int strLen_4 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_826 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_826+currStrOff, fileName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_826+currStrOff, ".o", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fileName = ____BAH_COMPILER_VAR_826;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char * ____BAH_COMPILER_VAR_827 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_CC);
long int strLen_4 = strlen(" -I \"");
long int strLen_6 = strlen(BAH_DIR);
long int strLen_8 = strlen("libs/");
long int strLen_10 = strlen(BAH_OS);
long int strLen_12 = strlen("/include/\" -L \"");
long int strLen_14 = strlen(BAH_DIR);
long int strLen_16 = strlen("libs/");
long int strLen_18 = strlen(BAH_OS);
long int strLen_20 = strlen("/\" ");
long int strLen_22 = strlen(randFileName);
long int strLen_24 = strlen(" ");
long int strLen_26 = strlen(isStatic);
long int strLen_28 = strlen(" ");
long int strLen_30 = strlen(obj);
long int strLen_32 = strlen(" -w -O1 -o ");
long int strLen_34 = strlen(fileName);
;                            
                    ____BAH_COMPILER_VAR_827 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34);
                    
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, BAH_CC, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, " -I \"", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, BAH_DIR, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, "libs/", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, BAH_OS, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, "/include/\" -L \"", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, BAH_DIR, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, "libs/", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, BAH_OS, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, "/\" ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, randFileName, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, " ", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, isStatic, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, " ", strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, obj, strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, " -w -O1 -o ", strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, fileName, strLen_34);
                        currStrOff += strLen_34;
                        
                }
                char * gccArgs = ____BAH_COMPILER_VAR_827;
if ((flags.isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_828 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(gccArgs);
long int strLen_4 = strlen(" -c");
;                            
                    ____BAH_COMPILER_VAR_828 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, gccArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, " -c", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                gccArgs = ____BAH_COMPILER_VAR_828;
}
array(char *)* cLibs = compilerState.cLibs;
long int i = 0;
while ((i<len(cLibs))) {

                        if (cLibs->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: cLibs[%d] with length %d", i, cLibs->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:342");
                        };
                        char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_829 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(gccArgs);
long int strLen_4 = strlen(" -");
long int strLen_6 = strlen(l);
;                            
                    ____BAH_COMPILER_VAR_829 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_829+currStrOff, gccArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_829+currStrOff, " -", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_829+currStrOff, l, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                gccArgs = ____BAH_COMPILER_VAR_829;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = OUTPUT->toStr(OUTPUT);
if ((flags.isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_830 =cmd.run(&cmd);println(____BAH_COMPILER_VAR_830);
}
else {
char * ____BAH_COMPILER_VAR_831 =cmd.run(&cmd);}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags.isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_832 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("ar rcs ");
long int strLen_2 = strlen(fileName);
long int strLen_4 = strlen(".a ");
long int strLen_6 = strlen(fileName);
;                            
                    ____BAH_COMPILER_VAR_832 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_832+currStrOff, "ar rcs ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_832+currStrOff, fileName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_832+currStrOff, ".a ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_832+currStrOff, fileName, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                cmd = command(____BAH_COMPILER_VAR_832);
char * ____BAH_COMPILER_VAR_833 =cmd.run(&cmd);}
}
else {
if ((flags.isSet(&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_834 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fileName);
long int strLen_4 = strlen(".c");
;                            
                    ____BAH_COMPILER_VAR_834 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_834+currStrOff, fileName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_834+currStrOff, ".c", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fileName = ____BAH_COMPILER_VAR_834;
}
char * ____BAH_COMPILER_VAR_835 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_CC);
long int strLen_4 = strlen(" -I \"");
long int strLen_6 = strlen(BAH_DIR);
long int strLen_8 = strlen("libs/");
long int strLen_10 = strlen(BAH_OS);
long int strLen_12 = strlen("/include/\" -L \"");
long int strLen_14 = strlen(BAH_DIR);
long int strLen_16 = strlen("libs/");
long int strLen_18 = strlen(BAH_OS);
long int strLen_20 = strlen("/\" ");
long int strLen_22 = strlen(fileName);
long int strLen_24 = strlen(" ");
long int strLen_26 = strlen(isStatic);
long int strLen_28 = strlen(" -O1 -w ");
;                            
                    ____BAH_COMPILER_VAR_835 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, BAH_CC, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, " -I \"", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, BAH_DIR, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, "libs/", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, BAH_OS, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, "/include/\" -L \"", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, BAH_DIR, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, "libs/", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, BAH_OS, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, "/\" ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, fileName, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, " ", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, isStatic, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_835+currStrOff, " -O1 -w ", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                char * gccArgs = ____BAH_COMPILER_VAR_835;
array(char *)* cLibs = compilerState.cLibs;
long int i = 0;
while ((i<len(cLibs))) {

                        if (cLibs->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: cLibs[%d] with length %d", i, cLibs->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:380");
                        };
                        char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_836 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(gccArgs);
long int strLen_4 = strlen(" -");
long int strLen_6 = strlen(l);
;                            
                    ____BAH_COMPILER_VAR_836 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_836+currStrOff, gccArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_836+currStrOff, " -", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_836+currStrOff, l, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                gccArgs = ____BAH_COMPILER_VAR_836;
i = i+1;
};
char * ____BAH_COMPILER_VAR_837 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("//COMPILE WITH: '");
long int strLen_2 = strlen(gccArgs);
long int strLen_4 = strlen("'\n");
;                            
                    ____BAH_COMPILER_VAR_837 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_837+currStrOff, "//COMPILE WITH: '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_837+currStrOff, gccArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_837+currStrOff, "'\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = rope(____BAH_COMPILER_VAR_837)->add(rope(____BAH_COMPILER_VAR_837), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_838 = {};
____BAH_COMPILER_VAR_838.handle= null;
____BAH_COMPILER_VAR_838.name= null;
____BAH_COMPILER_VAR_838.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_838.open = fileStream__open;
____BAH_COMPILER_VAR_838.close = fileStream__close;
____BAH_COMPILER_VAR_838.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_838.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_838.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_838.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_838.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_838.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_838.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_838.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_838.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_838.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_838.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_838.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_838.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_838._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_838
fs.open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_839 =OUTPUT->toStr(OUTPUT);fs.writeFile(&fs,____BAH_COMPILER_VAR_839);
fs.close(&fs);
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char * ____BAH_COMPILER_VAR_840 =null;char * ____BAH_COMPILER_VAR_841 =intToStr(totalTime/1000000);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;32mDone. (compiled in ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_841);
long int strLen_4 = strlen("ms)\e[0m");
;                            
                    ____BAH_COMPILER_VAR_840 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_840+currStrOff, "\e[1;32mDone. (compiled in ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_840+currStrOff, ____BAH_COMPILER_VAR_841, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_840+currStrOff, "ms)\e[0m", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                println(____BAH_COMPILER_VAR_840);
}
return 0;
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[284];
    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan = null;
__Bah_fnNames = memoryAlloc(sizeof(array(struct __Bah_fnName_mapper)));

__Bah_fnNames->length = 0;
__Bah_fnNames->elemSize = sizeof(struct __Bah_fnName_mapper);
__Bah_init_segfaultHandle_OK = __Bah_init_segfaultHandle();
RAND_SEEDED = 0;
BAH_DIR = "C:/Bah/";
BAH_OS = "windows";
BAH_CC = "gcc";
debug = false;
verboseRuntime = false;
isObject = false;
isUnsafe = false;
execName = "bah";
isSubObject = false;
NEXT_LINE = "";
shouldOnlyDecl = false;
threadCount = 0;
currentFn = null;
totalLines = 0;
totalLexerTime = 0;
RCPenabled = false;
RCPlevel = 0;
currSetVar = null;
enclavers = memoryAlloc(sizeof(array(char)));

enclavers->length = 6;
enclavers->elemSize = sizeof(char);
enclavers->data = memoryAlloc(sizeof(char) * 50);enclavers->data[0] = 40;
enclavers->data[1] = 41;
enclavers->data[2] = 123;
enclavers->data[3] = 125;
enclavers->data[4] = 91;
enclavers->data[5] = 93;
syntaxes = memoryAlloc(sizeof(array(char)));

syntaxes->length = 14;
syntaxes->elemSize = sizeof(char);
syntaxes->data = memoryAlloc(sizeof(char) * 50);syntaxes->data[0] = 33;
syntaxes->data[1] = 61;
syntaxes->data[2] = 124;
syntaxes->data[3] = (char)38;
syntaxes->data[4] = 37;
syntaxes->data[5] = 43;
syntaxes->data[6] = 45;
syntaxes->data[7] = 42;
syntaxes->data[8] = 47;
syntaxes->data[9] = 44;
syntaxes->data[10] = 60;
syntaxes->data[11] = 62;
syntaxes->data[12] = 58;
syntaxes->data[13] = (char)59;
keywords = memoryAlloc(sizeof(array(char *)));

keywords->length = 21;
keywords->elemSize = sizeof(char *);
keywords->data = memoryAlloc(sizeof(char *) * 50);keywords->data[0] = "if";
keywords->data[1] = "else";
keywords->data[2] = "for";
keywords->data[3] = "struct";
keywords->data[4] = "const";
keywords->data[5] = "return";
keywords->data[6] = "extend";
keywords->data[7] = "new";
keywords->data[8] = "break";
keywords->data[9] = "continue";
keywords->data[10] = "default";
keywords->data[11] = "switch";
keywords->data[12] = "case";
keywords->data[13] = "while";
keywords->data[14] = "typedef";
keywords->data[15] = "function";
keywords->data[16] = "async";
keywords->data[17] = "in";
keywords->data[18] = "chan";
keywords->data[19] = "map";
keywords->data[20] = "buffer";
intTypes = memoryAlloc(sizeof(array(char *)));

intTypes->length = 4;
intTypes->elemSize = sizeof(char *);
intTypes->data = memoryAlloc(sizeof(char *) * 50);intTypes->data[0] = "int";
intTypes->data[1] = "int32";
intTypes->data[2] = "uint";
intTypes->data[3] = "uint32";
floatTypes = memoryAlloc(sizeof(array(char *)));

floatTypes->length = 4;
floatTypes->elemSize = sizeof(char *);
floatTypes->data = memoryAlloc(sizeof(char *) * 50);floatTypes->data[0] = "float";
floatTypes->data[1] = "float32";
floatTypes->data[2] = "ufloat";
floatTypes->data[3] = "ufloat32";
NB_COMP_VAR = 0;
noVOfns = memoryAlloc(sizeof(array(char *)));

noVOfns->length = 1;
noVOfns->elemSize = sizeof(char *);
noVOfns->data = memoryAlloc(sizeof(char *) * 50);noVOfns->data[0] = "__Bah_safe_string";
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
prevLine = (lineType)-1;
signs = memoryAlloc(sizeof(array(char *)));

signs->length = 7;
signs->elemSize = sizeof(char *);
signs->data = memoryAlloc(sizeof(char *) * 50);signs->data[0] = "|";
signs->data[1] = "&";
signs->data[2] = "%";
signs->data[3] = "+";
signs->data[4] = "-";
signs->data[5] = "*";
signs->data[6] = "/";
comparators = memoryAlloc(sizeof(array(char *)));

comparators->length = 7;
comparators->elemSize = sizeof(char *);
comparators->data = memoryAlloc(sizeof(char *) * 50);comparators->data[0] = "==";
comparators->data[1] = "!=";
comparators->data[2] = ">";
comparators->data[3] = "<";
comparators->data[4] = "<=";
comparators->data[5] = ">=";
comparators->data[6] = "in";
compSep = memoryAlloc(sizeof(array(char *)));

compSep->length = 2;
compSep->elemSize = sizeof(char *);
compSep->data = memoryAlloc(sizeof(char *) * 50);compSep->data[0] = "||";
compSep->data[1] = "&&";
equalsTokens = memoryAlloc(sizeof(array(char *)));

equalsTokens->length = 5;
equalsTokens->elemSize = sizeof(char *);
equalsTokens->data = memoryAlloc(sizeof(char *) * 50);equalsTokens->data[0] = "=";
equalsTokens->data[1] = "+=";
equalsTokens->data[2] = "-=";
equalsTokens->data[3] = "*=";
equalsTokens->data[4] = "/=";

            __tmp____Bah_fnNames[0].n = "__BAH_panic";
            __tmp____Bah_fnNames[0].p = __BAH_panic;

            __tmp____Bah_fnNames[1].n = "__Bah_safe_string";
            __tmp____Bah_fnNames[1].p = __Bah_safe_string;

            __tmp____Bah_fnNames[2].n = "__bah_strcmp";
            __tmp____Bah_fnNames[2].p = __bah_strcmp;

            __tmp____Bah_fnNames[3].n = "__bah_strlen";
            __tmp____Bah_fnNames[3].p = __bah_strlen;

            __tmp____Bah_fnNames[4].n = "len";
            __tmp____Bah_fnNames[4].p = len;

            __tmp____Bah_fnNames[5].n = "memoryAlloc";
            __tmp____Bah_fnNames[5].p = memoryAlloc;

            __tmp____Bah_fnNames[6].n = "destroy";
            __tmp____Bah_fnNames[6].p = destroy;

            __tmp____Bah_fnNames[7].n = "clear";
            __tmp____Bah_fnNames[7].p = clear;

            __tmp____Bah_fnNames[8].n = "memoryRealloc";
            __tmp____Bah_fnNames[8].p = memoryRealloc;

            __tmp____Bah_fnNames[9].n = "cleanShutDown";
            __tmp____Bah_fnNames[9].p = cleanShutDown;

            __tmp____Bah_fnNames[10].n = "memoryOnEnd";
            __tmp____Bah_fnNames[10].p = memoryOnEnd;

            __tmp____Bah_fnNames[11].n = "append";
            __tmp____Bah_fnNames[11].p = append;

            __tmp____Bah_fnNames[12].n = "copy";
            __tmp____Bah_fnNames[12].p = copy;

            __tmp____Bah_fnNames[13].n = "sharedMemory";
            __tmp____Bah_fnNames[13].p = sharedMemory;

            __tmp____Bah_fnNames[14].n = "closeSharedMemory";
            __tmp____Bah_fnNames[14].p = closeSharedMemory;

            __tmp____Bah_fnNames[15].n = "allocateArray";
            __tmp____Bah_fnNames[15].p = allocateArray;

            __tmp____Bah_fnNames[16].n = "__serialize";
            __tmp____Bah_fnNames[16].p = __serialize;

            __tmp____Bah_fnNames[17].n = "serlen";
            __tmp____Bah_fnNames[17].p = serlen;

            __tmp____Bah_fnNames[18].n = "unser";
            __tmp____Bah_fnNames[18].p = unser;

            __tmp____Bah_fnNames[19].n = "memoryAllocSTR";
            __tmp____Bah_fnNames[19].p = memoryAllocSTR;

            __tmp____Bah_fnNames[20].n = "delete";
            __tmp____Bah_fnNames[20].p = delete;

            __tmp____Bah_fnNames[21].n = "arrToStr";
            __tmp____Bah_fnNames[21].p = arrToStr;

            __tmp____Bah_fnNames[22].n = "strToArr";
            __tmp____Bah_fnNames[22].p = strToArr;

            __tmp____Bah_fnNames[23].n = "arrAsStr";
            __tmp____Bah_fnNames[23].p = arrAsStr;

            __tmp____Bah_fnNames[24].n = "strAsArr";
            __tmp____Bah_fnNames[24].p = strAsArr;

            __tmp____Bah_fnNames[25].n = "strTrimLeft";
            __tmp____Bah_fnNames[25].p = strTrimLeft;

            __tmp____Bah_fnNames[26].n = "strTrimRight";
            __tmp____Bah_fnNames[26].p = strTrimRight;

            __tmp____Bah_fnNames[27].n = "concatCPSTRING";
            __tmp____Bah_fnNames[27].p = concatCPSTRING;

            __tmp____Bah_fnNames[28].n = "__STR";
            __tmp____Bah_fnNames[28].p = __STR;

            __tmp____Bah_fnNames[29].n = "print";
            __tmp____Bah_fnNames[29].p = print;

            __tmp____Bah_fnNames[30].n = "cArr";
            __tmp____Bah_fnNames[30].p = cArr;

            __tmp____Bah_fnNames[31].n = "__checkString";
            __tmp____Bah_fnNames[31].p = __checkString;

            __tmp____Bah_fnNames[32].n = "mutex.init";
            __tmp____Bah_fnNames[32].p = mutex__init;

            __tmp____Bah_fnNames[33].n = "mutex.lock";
            __tmp____Bah_fnNames[33].p = mutex__lock;

            __tmp____Bah_fnNames[34].n = "mutex.unlock";
            __tmp____Bah_fnNames[34].p = mutex__unlock;

            __tmp____Bah_fnNames[35].n = "mutex.destroy";
            __tmp____Bah_fnNames[35].p = mutex__destroy;

            __tmp____Bah_fnNames[36].n = "mutexCondition.init";
            __tmp____Bah_fnNames[36].p = mutexCondition__init;

            __tmp____Bah_fnNames[37].n = "mutexCondition.wait";
            __tmp____Bah_fnNames[37].p = mutexCondition__wait;

            __tmp____Bah_fnNames[38].n = "mutexCondition.send";
            __tmp____Bah_fnNames[38].p = mutexCondition__send;

            __tmp____Bah_fnNames[39].n = "mutexCondition.destroy";
            __tmp____Bah_fnNames[39].p = mutexCondition__destroy;

            __tmp____Bah_fnNames[40].n = "mutexCondition";
            __tmp____Bah_fnNames[40].p = mutexCondition;

            __tmp____Bah_fnNames[41].n = "thread.create";
            __tmp____Bah_fnNames[41].p = thread__create;

            __tmp____Bah_fnNames[42].n = "thread.createWithArg";
            __tmp____Bah_fnNames[42].p = thread__createWithArg;

            __tmp____Bah_fnNames[43].n = "thread.wait";
            __tmp____Bah_fnNames[43].p = thread__wait;

            __tmp____Bah_fnNames[44].n = "mutex";
            __tmp____Bah_fnNames[44].p = mutex;

            __tmp____Bah_fnNames[45].n = "queue.insert";
            __tmp____Bah_fnNames[45].p = queue__insert;

            __tmp____Bah_fnNames[46].n = "queue.delete";
            __tmp____Bah_fnNames[46].p = queue__delete;

            __tmp____Bah_fnNames[47].n = "queue.get";
            __tmp____Bah_fnNames[47].p = queue__get;

            __tmp____Bah_fnNames[48].n = "queue.set";
            __tmp____Bah_fnNames[48].p = queue__set;

            __tmp____Bah_fnNames[49].n = "queue.pop";
            __tmp____Bah_fnNames[49].p = queue__pop;

            __tmp____Bah_fnNames[50].n = "queue.clear";
            __tmp____Bah_fnNames[50].p = queue__clear;

            __tmp____Bah_fnNames[51].n = "channel.send";
            __tmp____Bah_fnNames[51].p = channel__send;

            __tmp____Bah_fnNames[52].n = "channel.sendAny";
            __tmp____Bah_fnNames[52].p = channel__sendAny;

            __tmp____Bah_fnNames[53].n = "channel.receive";
            __tmp____Bah_fnNames[53].p = channel__receive;

            __tmp____Bah_fnNames[54].n = "channel.destroy";
            __tmp____Bah_fnNames[54].p = channel__destroy;

            __tmp____Bah_fnNames[55].n = "channel.len";
            __tmp____Bah_fnNames[55].p = channel__len;

            __tmp____Bah_fnNames[56].n = "channel";
            __tmp____Bah_fnNames[56].p = channel;

            __tmp____Bah_fnNames[57].n = "setChanCap";
            __tmp____Bah_fnNames[57].p = setChanCap;

            __tmp____Bah_fnNames[58].n = "__Bah_common_panic";
            __tmp____Bah_fnNames[58].p = __Bah_common_panic;

            __tmp____Bah_fnNames[59].n = "__Bah_fnNames_append";
            __tmp____Bah_fnNames[59].p = __Bah_fnNames_append;

            __tmp____Bah_fnNames[60].n = "__Bah_segfault_handle";
            __tmp____Bah_fnNames[60].p = __Bah_segfault_handle;

            __tmp____Bah_fnNames[61].n = "__Bah_init_segfaultHandle";
            __tmp____Bah_fnNames[61].p = __Bah_init_segfaultHandle;

            __tmp____Bah_fnNames[62].n = "recover";
            __tmp____Bah_fnNames[62].p = recover;

            __tmp____Bah_fnNames[63].n = "cpstringCharAt";
            __tmp____Bah_fnNames[63].p = cpstringCharAt;

            __tmp____Bah_fnNames[64].n = "cpstringSubsitute";
            __tmp____Bah_fnNames[64].p = cpstringSubsitute;

            __tmp____Bah_fnNames[65].n = "arraySubstitute";
            __tmp____Bah_fnNames[65].p = arraySubstitute;

            __tmp____Bah_fnNames[66].n = "__Bah_map_hash";
            __tmp____Bah_fnNames[66].p = __Bah_map_hash;

            __tmp____Bah_fnNames[67].n = "mapWrapper.grow";
            __tmp____Bah_fnNames[67].p = mapWrapper__grow;

            __tmp____Bah_fnNames[68].n = "mapWrapper.set";
            __tmp____Bah_fnNames[68].p = mapWrapper__set;

            __tmp____Bah_fnNames[69].n = "mapWrapper.setAny";
            __tmp____Bah_fnNames[69].p = mapWrapper__setAny;

            __tmp____Bah_fnNames[70].n = "mapWrapper.delete";
            __tmp____Bah_fnNames[70].p = mapWrapper__delete;

            __tmp____Bah_fnNames[71].n = "mapWrapper.get";
            __tmp____Bah_fnNames[71].p = mapWrapper__get;

            __tmp____Bah_fnNames[72].n = "mapWrapper";
            __tmp____Bah_fnNames[72].p = mapWrapper;

            __tmp____Bah_fnNames[73].n = "stdinput";
            __tmp____Bah_fnNames[73].p = stdinput;

            __tmp____Bah_fnNames[74].n = "println";
            __tmp____Bah_fnNames[74].p = println;

            __tmp____Bah_fnNames[75].n = "fileStream.isValid";
            __tmp____Bah_fnNames[75].p = fileStream__isValid;

            __tmp____Bah_fnNames[76].n = "fileStream.open";
            __tmp____Bah_fnNames[76].p = fileStream__open;

            __tmp____Bah_fnNames[77].n = "fileStream.close";
            __tmp____Bah_fnNames[77].p = fileStream__close;

            __tmp____Bah_fnNames[78].n = "fileStream.getPos";
            __tmp____Bah_fnNames[78].p = fileStream__getPos;

            __tmp____Bah_fnNames[79].n = "fileStream.setPos";
            __tmp____Bah_fnNames[79].p = fileStream__setPos;

            __tmp____Bah_fnNames[80].n = "fileStream.getSize";
            __tmp____Bah_fnNames[80].p = fileStream__getSize;

            __tmp____Bah_fnNames[81].n = "fileStream.rewind";
            __tmp____Bah_fnNames[81].p = fileStream__rewind;

            __tmp____Bah_fnNames[82].n = "fileStream.getChar";
            __tmp____Bah_fnNames[82].p = fileStream__getChar;

            __tmp____Bah_fnNames[83].n = "fileStream.setChar";
            __tmp____Bah_fnNames[83].p = fileStream__setChar;

            __tmp____Bah_fnNames[84].n = "fileStream.createFile";
            __tmp____Bah_fnNames[84].p = fileStream__createFile;

            __tmp____Bah_fnNames[85].n = "fileStream.writeFile";
            __tmp____Bah_fnNames[85].p = fileStream__writeFile;

            __tmp____Bah_fnNames[86].n = "fileStream.writePtr";
            __tmp____Bah_fnNames[86].p = fileStream__writePtr;

            __tmp____Bah_fnNames[87].n = "fileStream.readPtr";
            __tmp____Bah_fnNames[87].p = fileStream__readPtr;

            __tmp____Bah_fnNames[88].n = "fileStream.readContent";
            __tmp____Bah_fnNames[88].p = fileStream__readContent;

            __tmp____Bah_fnNames[89].n = "fileStream.readBytes";
            __tmp____Bah_fnNames[89].p = fileStream__readBytes;

            __tmp____Bah_fnNames[90].n = "fileStream.writeBytes";
            __tmp____Bah_fnNames[90].p = fileStream__writeBytes;

            __tmp____Bah_fnNames[91].n = "fileStream._end";
            __tmp____Bah_fnNames[91].p = fileStream___end;

            __tmp____Bah_fnNames[92].n = "fileMap.open";
            __tmp____Bah_fnNames[92].p = fileMap__open;

            __tmp____Bah_fnNames[93].n = "fileMap.isValid";
            __tmp____Bah_fnNames[93].p = fileMap__isValid;

            __tmp____Bah_fnNames[94].n = "fileMap.close";
            __tmp____Bah_fnNames[94].p = fileMap__close;

            __tmp____Bah_fnNames[95].n = "listFiles";
            __tmp____Bah_fnNames[95].p = listFiles;

            __tmp____Bah_fnNames[96].n = "fileExists";
            __tmp____Bah_fnNames[96].p = fileExists;

            __tmp____Bah_fnNames[97].n = "removeFile";
            __tmp____Bah_fnNames[97].p = removeFile;

            __tmp____Bah_fnNames[98].n = "getLastModified";
            __tmp____Bah_fnNames[98].p = getLastModified;

            __tmp____Bah_fnNames[99].n = "__windows_mkdir";
            __tmp____Bah_fnNames[99].p = __windows_mkdir;

            __tmp____Bah_fnNames[100].n = "strCatOffset";
            __tmp____Bah_fnNames[100].p = strCatOffset;

            __tmp____Bah_fnNames[101].n = "charToString";
            __tmp____Bah_fnNames[101].p = charToString;

            __tmp____Bah_fnNames[102].n = "isUpper";
            __tmp____Bah_fnNames[102].p = isUpper;

            __tmp____Bah_fnNames[103].n = "isLower";
            __tmp____Bah_fnNames[103].p = isLower;

            __tmp____Bah_fnNames[104].n = "isLetter";
            __tmp____Bah_fnNames[104].p = isLetter;

            __tmp____Bah_fnNames[105].n = "isNumber";
            __tmp____Bah_fnNames[105].p = isNumber;

            __tmp____Bah_fnNames[106].n = "isAlphaNumeric";
            __tmp____Bah_fnNames[106].p = isAlphaNumeric;

            __tmp____Bah_fnNames[107].n = "isSpace";
            __tmp____Bah_fnNames[107].p = isSpace;

            __tmp____Bah_fnNames[108].n = "string.set";
            __tmp____Bah_fnNames[108].p = string__set;

            __tmp____Bah_fnNames[109].n = "string.makeEditable";
            __tmp____Bah_fnNames[109].p = string__makeEditable;

            __tmp____Bah_fnNames[110].n = "string.append";
            __tmp____Bah_fnNames[110].p = string__append;

            __tmp____Bah_fnNames[111].n = "string.prepend";
            __tmp____Bah_fnNames[111].p = string__prepend;

            __tmp____Bah_fnNames[112].n = "string.charAt";
            __tmp____Bah_fnNames[112].p = string__charAt;

            __tmp____Bah_fnNames[113].n = "string.compare";
            __tmp____Bah_fnNames[113].p = string__compare;

            __tmp____Bah_fnNames[114].n = "string.str";
            __tmp____Bah_fnNames[114].p = string__str;

            __tmp____Bah_fnNames[115].n = "string.replace";
            __tmp____Bah_fnNames[115].p = string__replace;

            __tmp____Bah_fnNames[116].n = "string.countChar";
            __tmp____Bah_fnNames[116].p = string__countChar;

            __tmp____Bah_fnNames[117].n = "string.count";
            __tmp____Bah_fnNames[117].p = string__count;

            __tmp____Bah_fnNames[118].n = "string.hasPrefix";
            __tmp____Bah_fnNames[118].p = string__hasPrefix;

            __tmp____Bah_fnNames[119].n = "string.hasSuffix";
            __tmp____Bah_fnNames[119].p = string__hasSuffix;

            __tmp____Bah_fnNames[120].n = "string.trim";
            __tmp____Bah_fnNames[120].p = string__trim;

            __tmp____Bah_fnNames[121].n = "string.trimLeft";
            __tmp____Bah_fnNames[121].p = string__trimLeft;

            __tmp____Bah_fnNames[122].n = "string.trimRight";
            __tmp____Bah_fnNames[122].p = string__trimRight;

            __tmp____Bah_fnNames[123].n = "string.add";
            __tmp____Bah_fnNames[123].p = string__add;

            __tmp____Bah_fnNames[124].n = "string";
            __tmp____Bah_fnNames[124].p = string;

            __tmp____Bah_fnNames[125].n = "intToStr";
            __tmp____Bah_fnNames[125].p = intToStr;

            __tmp____Bah_fnNames[126].n = "intToString";
            __tmp____Bah_fnNames[126].p = intToString;

            __tmp____Bah_fnNames[127].n = "floatToStr";
            __tmp____Bah_fnNames[127].p = floatToStr;

            __tmp____Bah_fnNames[128].n = "strToInt";
            __tmp____Bah_fnNames[128].p = strToInt;

            __tmp____Bah_fnNames[129].n = "strToFloat";
            __tmp____Bah_fnNames[129].p = strToFloat;

            __tmp____Bah_fnNames[130].n = "stringToInt";
            __tmp____Bah_fnNames[130].p = stringToInt;

            __tmp____Bah_fnNames[131].n = "splitString";
            __tmp____Bah_fnNames[131].p = splitString;

            __tmp____Bah_fnNames[132].n = "joinString";
            __tmp____Bah_fnNames[132].p = joinString;

            __tmp____Bah_fnNames[133].n = "splitStringBefore";
            __tmp____Bah_fnNames[133].p = splitStringBefore;

            __tmp____Bah_fnNames[134].n = "toLower";
            __tmp____Bah_fnNames[134].p = toLower;

            __tmp____Bah_fnNames[135].n = "strHasPrefix";
            __tmp____Bah_fnNames[135].p = strHasPrefix;

            __tmp____Bah_fnNames[136].n = "strHasSuffix";
            __tmp____Bah_fnNames[136].p = strHasSuffix;

            __tmp____Bah_fnNames[137].n = "strTrim";
            __tmp____Bah_fnNames[137].p = strTrim;

            __tmp____Bah_fnNames[138].n = "strCount";
            __tmp____Bah_fnNames[138].p = strCount;

            __tmp____Bah_fnNames[139].n = "flags.addString";
            __tmp____Bah_fnNames[139].p = flags__addString;

            __tmp____Bah_fnNames[140].n = "flags.addBool";
            __tmp____Bah_fnNames[140].p = flags__addBool;

            __tmp____Bah_fnNames[141].n = "flags.addInt";
            __tmp____Bah_fnNames[141].p = flags__addInt;

            __tmp____Bah_fnNames[142].n = "flags.addFloat";
            __tmp____Bah_fnNames[142].p = flags__addFloat;

            __tmp____Bah_fnNames[143].n = "flags.invalidate";
            __tmp____Bah_fnNames[143].p = flags__invalidate;

            __tmp____Bah_fnNames[144].n = "flags.getFlag";
            __tmp____Bah_fnNames[144].p = flags__getFlag;

            __tmp____Bah_fnNames[145].n = "flags.get";
            __tmp____Bah_fnNames[145].p = flags__get;

            __tmp____Bah_fnNames[146].n = "flags.getInt";
            __tmp____Bah_fnNames[146].p = flags__getInt;

            __tmp____Bah_fnNames[147].n = "flags.getFloat";
            __tmp____Bah_fnNames[147].p = flags__getFloat;

            __tmp____Bah_fnNames[148].n = "flags.isSet";
            __tmp____Bah_fnNames[148].p = flags__isSet;

            __tmp____Bah_fnNames[149].n = "flags.parse";
            __tmp____Bah_fnNames[149].p = flags__parse;

            __tmp____Bah_fnNames[150].n = "time.now";
            __tmp____Bah_fnNames[150].p = time__now;

            __tmp____Bah_fnNames[151].n = "time.format";
            __tmp____Bah_fnNames[151].p = time__format;

            __tmp____Bah_fnNames[152].n = "time.since";
            __tmp____Bah_fnNames[152].p = time__since;

            __tmp____Bah_fnNames[153].n = "getTimeUnix";
            __tmp____Bah_fnNames[153].p = getTimeUnix;

            __tmp____Bah_fnNames[154].n = "seedRandom";
            __tmp____Bah_fnNames[154].p = seedRandom;

            __tmp____Bah_fnNames[155].n = "randomInRange";
            __tmp____Bah_fnNames[155].p = randomInRange;

            __tmp____Bah_fnNames[156].n = "cryptoRand";
            __tmp____Bah_fnNames[156].p = cryptoRand;

            __tmp____Bah_fnNames[157].n = "rope.addStr";
            __tmp____Bah_fnNames[157].p = rope__addStr;

            __tmp____Bah_fnNames[158].n = "rope.toStr";
            __tmp____Bah_fnNames[158].p = rope__toStr;

            __tmp____Bah_fnNames[159].n = "rope.add";
            __tmp____Bah_fnNames[159].p = rope__add;

            __tmp____Bah_fnNames[160].n = "createRopeStructure";
            __tmp____Bah_fnNames[160].p = createRopeStructure;

            __tmp____Bah_fnNames[161].n = "ropeSet";
            __tmp____Bah_fnNames[161].p = ropeSet;

            __tmp____Bah_fnNames[162].n = "concatenateRopes";
            __tmp____Bah_fnNames[162].p = concatenateRopes;

            __tmp____Bah_fnNames[163].n = "rope";
            __tmp____Bah_fnNames[163].p = rope;

            __tmp____Bah_fnNames[164].n = "command.run";
            __tmp____Bah_fnNames[164].p = command__run;

            __tmp____Bah_fnNames[165].n = "command.runBytes";
            __tmp____Bah_fnNames[165].p = command__runBytes;

            __tmp____Bah_fnNames[166].n = "command";
            __tmp____Bah_fnNames[166].p = command;

            __tmp____Bah_fnNames[167].n = "exec";
            __tmp____Bah_fnNames[167].p = exec;

            __tmp____Bah_fnNames[168].n = "inArray";
            __tmp____Bah_fnNames[168].p = inArray;

            __tmp____Bah_fnNames[169].n = "inArrayStr";
            __tmp____Bah_fnNames[169].p = inArrayStr;

            __tmp____Bah_fnNames[170].n = "makeToken";
            __tmp____Bah_fnNames[170].p = makeToken;

            __tmp____Bah_fnNames[171].n = "isMinus";
            __tmp____Bah_fnNames[171].p = isMinus;

            __tmp____Bah_fnNames[172].n = "lexerErr";
            __tmp____Bah_fnNames[172].p = lexerErr;

            __tmp____Bah_fnNames[173].n = "lexer";
            __tmp____Bah_fnNames[173].p = lexer;

            __tmp____Bah_fnNames[174].n = "hasStructSep";
            __tmp____Bah_fnNames[174].p = hasStructSep;

            __tmp____Bah_fnNames[175].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[175].p = splitStructSepBefore;

            __tmp____Bah_fnNames[176].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[176].p = splitStructSepAfter;

            __tmp____Bah_fnNames[177].n = "searchStruct";
            __tmp____Bah_fnNames[177].p = searchStruct;

            __tmp____Bah_fnNames[178].n = "searchStructMemb";
            __tmp____Bah_fnNames[178].p = searchStructMemb;

            __tmp____Bah_fnNames[179].n = "isRCPpointerType";
            __tmp____Bah_fnNames[179].p = isRCPpointerType;

            __tmp____Bah_fnNames[180].n = "isRCPtype";
            __tmp____Bah_fnNames[180].p = isRCPtype;

            __tmp____Bah_fnNames[181].n = "getCType";
            __tmp____Bah_fnNames[181].p = getCType;

            __tmp____Bah_fnNames[182].n = "compTypeEquiv";
            __tmp____Bah_fnNames[182].p = compTypeEquiv;

            __tmp____Bah_fnNames[183].n = "compTypes";
            __tmp____Bah_fnNames[183].p = compTypes;

            __tmp____Bah_fnNames[184].n = "reflectElement.calculateOffset";
            __tmp____Bah_fnNames[184].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[185].n = "__reflect";
            __tmp____Bah_fnNames[185].p = __reflect;

            __tmp____Bah_fnNames[186].n = "__dumpSymbols";
            __tmp____Bah_fnNames[186].p = __dumpSymbols;

            __tmp____Bah_fnNames[187].n = "__debug_get_sym";
            __tmp____Bah_fnNames[187].p = __debug_get_sym;

            __tmp____Bah_fnNames[188].n = "toJson";
            __tmp____Bah_fnNames[188].p = toJson;

            __tmp____Bah_fnNames[189].n = "json_scan_inner";
            __tmp____Bah_fnNames[189].p = json_scan_inner;

            __tmp____Bah_fnNames[190].n = "jsonElement.get";
            __tmp____Bah_fnNames[190].p = jsonElement__get;

            __tmp____Bah_fnNames[191].n = "jsonElement.str";
            __tmp____Bah_fnNames[191].p = jsonElement__str;

            __tmp____Bah_fnNames[192].n = "jsonElement.scan";
            __tmp____Bah_fnNames[192].p = jsonElement__scan;

            __tmp____Bah_fnNames[193].n = "parseJson";
            __tmp____Bah_fnNames[193].p = parseJson;

            __tmp____Bah_fnNames[194].n = "jsonEscapeStr";
            __tmp____Bah_fnNames[194].p = jsonEscapeStr;

            __tmp____Bah_fnNames[195].n = "toJson__inner";
            __tmp____Bah_fnNames[195].p = toJson__inner;

            __tmp____Bah_fnNames[196].n = "debugStart";
            __tmp____Bah_fnNames[196].p = debugStart;

            __tmp____Bah_fnNames[197].n = "debugPrint";
            __tmp____Bah_fnNames[197].p = debugPrint;

            __tmp____Bah_fnNames[198].n = "debugError";
            __tmp____Bah_fnNames[198].p = debugError;

            __tmp____Bah_fnNames[199].n = "debugEnd";
            __tmp____Bah_fnNames[199].p = debugEnd;

            __tmp____Bah_fnNames[200].n = "debugExit";
            __tmp____Bah_fnNames[200].p = debugExit;

            __tmp____Bah_fnNames[201].n = "debugEndScope";
            __tmp____Bah_fnNames[201].p = debugEndScope;

            __tmp____Bah_fnNames[202].n = "throwErr";
            __tmp____Bah_fnNames[202].p = throwErr;

            __tmp____Bah_fnNames[203].n = "throwWarning";
            __tmp____Bah_fnNames[203].p = throwWarning;

            __tmp____Bah_fnNames[204].n = "absPath";
            __tmp____Bah_fnNames[204].p = absPath;

            __tmp____Bah_fnNames[205].n = "getCurrentPath";
            __tmp____Bah_fnNames[205].p = getCurrentPath;

            __tmp____Bah_fnNames[206].n = "isInside";
            __tmp____Bah_fnNames[206].p = isInside;

            __tmp____Bah_fnNames[207].n = "setCurrentPath";
            __tmp____Bah_fnNames[207].p = setCurrentPath;

            __tmp____Bah_fnNames[208].n = "isGlobal";
            __tmp____Bah_fnNames[208].p = isGlobal;

            __tmp____Bah_fnNames[209].n = "searchVar";
            __tmp____Bah_fnNames[209].p = searchVar;

            __tmp____Bah_fnNames[210].n = "setCType";
            __tmp____Bah_fnNames[210].p = setCType;

            __tmp____Bah_fnNames[211].n = "getTypeFromToken";
            __tmp____Bah_fnNames[211].p = getTypeFromToken;

            __tmp____Bah_fnNames[212].n = "parseFnType";
            __tmp____Bah_fnNames[212].p = parseFnType;

            __tmp____Bah_fnNames[213].n = "searchFunc";
            __tmp____Bah_fnNames[213].p = searchFunc;

            __tmp____Bah_fnNames[214].n = "RCPavailable";
            __tmp____Bah_fnNames[214].p = RCPavailable;

            __tmp____Bah_fnNames[215].n = "declareStructMethods";
            __tmp____Bah_fnNames[215].p = declareStructMethods;

            __tmp____Bah_fnNames[216].n = "genCompilerVar";
            __tmp____Bah_fnNames[216].p = genCompilerVar;

            __tmp____Bah_fnNames[217].n = "varInArr";
            __tmp____Bah_fnNames[217].p = varInArr;

            __tmp____Bah_fnNames[218].n = "pathToVarName";
            __tmp____Bah_fnNames[218].p = pathToVarName;

            __tmp____Bah_fnNames[219].n = "makeInit";
            __tmp____Bah_fnNames[219].p = makeInit;

            __tmp____Bah_fnNames[220].n = "decrVar";
            __tmp____Bah_fnNames[220].p = decrVar;

            __tmp____Bah_fnNames[221].n = "incrVar";
            __tmp____Bah_fnNames[221].p = incrVar;

            __tmp____Bah_fnNames[222].n = "beginRCPscope";
            __tmp____Bah_fnNames[222].p = beginRCPscope;

            __tmp____Bah_fnNames[223].n = "beginRCPscopeLeaky";
            __tmp____Bah_fnNames[223].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[224].n = "endRCPscope";
            __tmp____Bah_fnNames[224].p = endRCPscope;

            __tmp____Bah_fnNames[225].n = "endRCPscopeLeaky";
            __tmp____Bah_fnNames[225].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[226].n = "registerRCPvar";
            __tmp____Bah_fnNames[226].p = registerRCPvar;

            __tmp____Bah_fnNames[227].n = "RCPselfRef";
            __tmp____Bah_fnNames[227].p = RCPselfRef;

            __tmp____Bah_fnNames[228].n = "verboseOutGuard";
            __tmp____Bah_fnNames[228].p = verboseOutGuard;

            __tmp____Bah_fnNames[229].n = "verboseOutTransformVar";
            __tmp____Bah_fnNames[229].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[230].n = "verboseOutTransformTok";
            __tmp____Bah_fnNames[230].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[231].n = "verboseOutFunc";
            __tmp____Bah_fnNames[231].p = verboseOutFunc;

            __tmp____Bah_fnNames[232].n = "verboseOutOper";
            __tmp____Bah_fnNames[232].p = verboseOutOper;

            __tmp____Bah_fnNames[233].n = "readCache";
            __tmp____Bah_fnNames[233].p = readCache;

            __tmp____Bah_fnNames[234].n = "getCacheFile";
            __tmp____Bah_fnNames[234].p = getCacheFile;

            __tmp____Bah_fnNames[235].n = "updateCacheFile";
            __tmp____Bah_fnNames[235].p = updateCacheFile;

            __tmp____Bah_fnNames[236].n = "makeCacheFile";
            __tmp____Bah_fnNames[236].p = makeCacheFile;

            __tmp____Bah_fnNames[237].n = "writeCache";
            __tmp____Bah_fnNames[237].p = writeCache;

            __tmp____Bah_fnNames[238].n = "isValidCacheFile";
            __tmp____Bah_fnNames[238].p = isValidCacheFile;

            __tmp____Bah_fnNames[239].n = "debugLine";
            __tmp____Bah_fnNames[239].p = debugLine;

            __tmp____Bah_fnNames[240].n = "dupElems";
            __tmp____Bah_fnNames[240].p = dupElems;

            __tmp____Bah_fnNames[241].n = "getLineType";
            __tmp____Bah_fnNames[241].p = getLineType;

            __tmp____Bah_fnNames[242].n = "parseCast";
            __tmp____Bah_fnNames[242].p = parseCast;

            __tmp____Bah_fnNames[243].n = "getDirFromFile";
            __tmp____Bah_fnNames[243].p = getDirFromFile;

            __tmp____Bah_fnNames[244].n = "parseLines";
            __tmp____Bah_fnNames[244].p = parseLines;

            __tmp____Bah_fnNames[245].n = "includeFile";
            __tmp____Bah_fnNames[245].p = includeFile;

            __tmp____Bah_fnNames[246].n = "parallelObjCompile";
            __tmp____Bah_fnNames[246].p = parallelObjCompile;

            __tmp____Bah_fnNames[247].n = "parseImport";
            __tmp____Bah_fnNames[247].p = parseImport;

            __tmp____Bah_fnNames[248].n = "parseInclude";
            __tmp____Bah_fnNames[248].p = parseInclude;

            __tmp____Bah_fnNames[249].n = "parseOperations";
            __tmp____Bah_fnNames[249].p = parseOperations;

            __tmp____Bah_fnNames[250].n = "prePross";
            __tmp____Bah_fnNames[250].p = prePross;

            __tmp____Bah_fnNames[251].n = "parseStructType";
            __tmp____Bah_fnNames[251].p = parseStructType;

            __tmp____Bah_fnNames[252].n = "parseStructVars";
            __tmp____Bah_fnNames[252].p = parseStructVars;

            __tmp____Bah_fnNames[253].n = "parseArrayType";
            __tmp____Bah_fnNames[253].p = parseArrayType;

            __tmp____Bah_fnNames[254].n = "parseBool";
            __tmp____Bah_fnNames[254].p = parseBool;

            __tmp____Bah_fnNames[255].n = "parsePointers";
            __tmp____Bah_fnNames[255].p = parsePointers;

            __tmp____Bah_fnNames[256].n = "parseArrayVars";
            __tmp____Bah_fnNames[256].p = parseArrayVars;

            __tmp____Bah_fnNames[257].n = "parseSerialize";
            __tmp____Bah_fnNames[257].p = parseSerialize;

            __tmp____Bah_fnNames[258].n = "parseReflect";
            __tmp____Bah_fnNames[258].p = parseReflect;

            __tmp____Bah_fnNames[259].n = "parseFnCall";
            __tmp____Bah_fnNames[259].p = parseFnCall;

            __tmp____Bah_fnNames[260].n = "parseArrayDecl";
            __tmp____Bah_fnNames[260].p = parseArrayDecl;

            __tmp____Bah_fnNames[261].n = "parseVar";
            __tmp____Bah_fnNames[261].p = parseVar;

            __tmp____Bah_fnNames[262].n = "getCfunctionType";
            __tmp____Bah_fnNames[262].p = getCfunctionType;

            __tmp____Bah_fnNames[263].n = "parseFnHeader";
            __tmp____Bah_fnNames[263].p = parseFnHeader;

            __tmp____Bah_fnNames[264].n = "parseStruct";
            __tmp____Bah_fnNames[264].p = parseStruct;

            __tmp____Bah_fnNames[265].n = "parseDefine";
            __tmp____Bah_fnNames[265].p = parseDefine;

            __tmp____Bah_fnNames[266].n = "parseClib";
            __tmp____Bah_fnNames[266].p = parseClib;

            __tmp____Bah_fnNames[267].n = "parseConst";
            __tmp____Bah_fnNames[267].p = parseConst;

            __tmp____Bah_fnNames[268].n = "parseReturn";
            __tmp____Bah_fnNames[268].p = parseReturn;

            __tmp____Bah_fnNames[269].n = "parseIf";
            __tmp____Bah_fnNames[269].p = parseIf;

            __tmp____Bah_fnNames[270].n = "parseElse";
            __tmp____Bah_fnNames[270].p = parseElse;

            __tmp____Bah_fnNames[271].n = "parseLine";
            __tmp____Bah_fnNames[271].p = parseLine;

            __tmp____Bah_fnNames[272].n = "parseFor";
            __tmp____Bah_fnNames[272].p = parseFor;

            __tmp____Bah_fnNames[273].n = "parseForOp";
            __tmp____Bah_fnNames[273].p = parseForOp;

            __tmp____Bah_fnNames[274].n = "makeEvalFunc";
            __tmp____Bah_fnNames[274].p = makeEvalFunc;

            __tmp____Bah_fnNames[275].n = "parsePreKeyword";
            __tmp____Bah_fnNames[275].p = parsePreKeyword;

            __tmp____Bah_fnNames[276].n = "parseAsync";
            __tmp____Bah_fnNames[276].p = parseAsync;

            __tmp____Bah_fnNames[277].n = "addRCPvars";
            __tmp____Bah_fnNames[277].p = addRCPvars;

            __tmp____Bah_fnNames[278].n = "parseChan";
            __tmp____Bah_fnNames[278].p = parseChan;

            __tmp____Bah_fnNames[279].n = "parseFnDeclare";
            __tmp____Bah_fnNames[279].p = parseFnDeclare;

            __tmp____Bah_fnNames[280].n = "declareFunc";
            __tmp____Bah_fnNames[280].p = declareFunc;

            __tmp____Bah_fnNames[281].n = "declareVar";
            __tmp____Bah_fnNames[281].p = declareVar;

            __tmp____Bah_fnNames[282].n = "declareAll";
            __tmp____Bah_fnNames[282].p = declareAll;

            __tmp____Bah_fnNames[283].n = "main";
            __tmp____Bah_fnNames[283].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 284;
        
    };
    