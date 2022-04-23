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
fs._end(&fs);
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
char * r = arrAsStr(buff);
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
void * tmpS = memoryAlloc(nSize);
memcpy(tmpS,this->content+s,nSize);
this->content = tmpS;
this->editable = true;
this->length = nSize;
};
void string__trimRight(struct string* this,long int s){
long int nSize = this->length-s;
void * tmpS = memoryAlloc(nSize);
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
struct rope* parent;
char * str;
long int lCount;
long int len;
long int totalLen;
struct rope*(*getParent)(struct rope* this);
void(*addStr)(struct rope* this,char * s,long int* offset);
char *(*toStr)(struct rope* this);
struct rope*(*add)(struct rope* this,struct rope* root2);
};
struct rope* rope__getParent(struct rope* this){
if ((this->parent==null)) {
return this;
}
return this->parent->getParent(this->parent);
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
____BAH_COMPILER_VAR_50->parent= null;
____BAH_COMPILER_VAR_50->str= null;
____BAH_COMPILER_VAR_50->len = 0;
____BAH_COMPILER_VAR_50->getParent = rope__getParent;
____BAH_COMPILER_VAR_50->addStr = rope__addStr;
____BAH_COMPILER_VAR_50->toStr = rope__toStr;
____BAH_COMPILER_VAR_50->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_50;
tmp->parent = null;
tmp->left = this;
tmp->right = root2;
root2->parent = tmp;
this->parent = root2->parent;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_51 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_51->left= null;
____BAH_COMPILER_VAR_51->right= null;
____BAH_COMPILER_VAR_51->parent= null;
____BAH_COMPILER_VAR_51->str= null;
____BAH_COMPILER_VAR_51->len = 0;
____BAH_COMPILER_VAR_51->getParent = rope__getParent;
____BAH_COMPILER_VAR_51->addStr = rope__addStr;
____BAH_COMPILER_VAR_51->toStr = rope__toStr;
____BAH_COMPILER_VAR_51->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_51;
tmp->left = null;
tmp->right = null;
tmp->parent = par;
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
____BAH_COMPILER_VAR_52->parent= null;
____BAH_COMPILER_VAR_52->str= null;
____BAH_COMPILER_VAR_52->len = 0;
____BAH_COMPILER_VAR_52->getParent = rope__getParent;
____BAH_COMPILER_VAR_52->addStr = rope__addStr;
____BAH_COMPILER_VAR_52->toStr = rope__toStr;
____BAH_COMPILER_VAR_52->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_52;
tmp->parent = null;
tmp->left = root1;
tmp->right = root2;
root2->parent = tmp;
root1->parent = root2->parent;
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
#define BAH_VERSION "v1.1 (build 81)"
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
if ((((s!=null)&&(s->isBinding==false))&&(s->hasRCPmemb==true))) {
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
char compTypes(char * a,char * b){
if (((strcmp(a, "ptr") == 0)||(strcmp(b, "ptr") == 0))) {
return true;
}
if (((strcmp(a, "cpstring") == 0)&&strHasPrefix(b,"buffer:"))) {
return true;
}
if (((strcmp(b, "cpstring") == 0)&&strHasPrefix(a,"buffer:"))) {
return true;
}
return (strcmp(a, b) == 0);
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
struct reflectElement ____BAH_COMPILER_VAR_68 = {};
____BAH_COMPILER_VAR_68.type= null;
____BAH_COMPILER_VAR_68.name= null;
____BAH_COMPILER_VAR_68.arrayElem= null;
____BAH_COMPILER_VAR_68.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_68.structLayout->length = 0;
            ____BAH_COMPILER_VAR_68.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_68.value= null;
____BAH_COMPILER_VAR_68.calculateOffset = reflectElement__calculateOffset;
#define re ____BAH_COMPILER_VAR_68
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
struct reflectElement ____BAH_COMPILER_VAR_69 = {};
____BAH_COMPILER_VAR_69.type= null;
____BAH_COMPILER_VAR_69.name= null;
____BAH_COMPILER_VAR_69.arrayElem= null;
____BAH_COMPILER_VAR_69.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_69.structLayout->length = 0;
            ____BAH_COMPILER_VAR_69.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_69.value= null;
____BAH_COMPILER_VAR_69.calculateOffset = reflectElement__calculateOffset;
#define ns ____BAH_COMPILER_VAR_69
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
arr = *arrPtr;
long int i = 0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->children[%d] with length %d", i, this->children->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:106");
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
if ((isMember==true)) {
void ** arrPtr = e.value;
arr = *arrPtr;
}
else {
arr = e.value;
}
long int i = 0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->children[%d] with length %d", i, this->children->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:119");
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
arr = *arrPtr;
long int i = 0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->children[%d] with length %d", i, this->children->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:128");
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
arr = *arrPtr;
long int i = 0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: this->children[%d] with length %d", i, this->children->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:138");
                        };
                        struct jsonElement* c = this->children->data[i];
void * ne = memoryAlloc(ae->size);
long int j = 0;
while ((j<len(ae->structLayout))) {

                        if (ae->structLayout->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: ae->structLayout[%d] with length %d", j, ae->structLayout->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:141");
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
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:156");
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
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:161");
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
char * ____BAH_COMPILER_VAR_70 =k.str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_70,v);
}
else {
char * ____BAH_COMPILER_VAR_71 =k.str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_71,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_72 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_72->key= null;
____BAH_COMPILER_VAR_72->content= null;
____BAH_COMPILER_VAR_72->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_72->children->length = 0;
            ____BAH_COMPILER_VAR_72->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_72->get = jsonElement__get;
____BAH_COMPILER_VAR_72->str = jsonElement__str;
____BAH_COMPILER_VAR_72->scan = jsonElement__scan;
struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_72;
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
char * ____BAH_COMPILER_VAR_73 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_73);
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
char * ____BAH_COMPILER_VAR_74 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_74);
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
char * ____BAH_COMPILER_VAR_75 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_75);
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
char * ____BAH_COMPILER_VAR_76 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_76);
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
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:399");
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
char * ____BAH_COMPILER_VAR_77 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tabsStr);
long int strLen_4 = strlen("\t");
;                            
                    ____BAH_COMPILER_VAR_77 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_77+currStrOff, tabsStr, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_77+currStrOff, "\t", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tabsStr = ____BAH_COMPILER_VAR_77;
i = i+1;
};
char * s = "{\n";
i = 0;
while ((i<len(e.structLayout))) {

                        if (e.structLayout->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: e.structLayout[%d] with length %d", i, e.structLayout->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:444");
                        };
                        struct reflectElement m = e.structLayout->data[i];
i = i+1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_78 =null;char * ____BAH_COMPILER_VAR_79 =toJson__inner(m,true,tabs);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(tabsStr);
long int strLen_6 = strlen("\"");
long int strLen_8 = strlen(m.name);
long int strLen_10 = strlen("\": ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_79);
long int strLen_14 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_78 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_78+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_78+currStrOff, tabsStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_78+currStrOff, "\"", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_78+currStrOff, m.name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_78+currStrOff, "\": ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_78+currStrOff, ____BAH_COMPILER_VAR_79, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_78+currStrOff, ",\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                s = ____BAH_COMPILER_VAR_78;
}
else {
char * ____BAH_COMPILER_VAR_80 =null;char * ____BAH_COMPILER_VAR_81 =toJson__inner(m,true,tabs);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(tabsStr);
long int strLen_6 = strlen("\"");
long int strLen_8 = strlen(m.name);
long int strLen_10 = strlen("\": ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_81);
long int strLen_14 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_80 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_80+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_80+currStrOff, tabsStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_80+currStrOff, "\"", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_80+currStrOff, m.name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_80+currStrOff, "\": ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_80+currStrOff, ____BAH_COMPILER_VAR_81, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_80+currStrOff, "\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                s = ____BAH_COMPILER_VAR_80;
}
};
tabs = tabs-1;
tabsStr = "";
i = 0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_82 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tabsStr);
long int strLen_4 = strlen("\t");
;                            
                    ____BAH_COMPILER_VAR_82 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_82+currStrOff, tabsStr, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_82+currStrOff, "\t", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tabsStr = ____BAH_COMPILER_VAR_82;
i = i+1;
};
char * ____BAH_COMPILER_VAR_83 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(tabsStr);
long int strLen_6 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_83 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_83+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_83+currStrOff, tabsStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_83+currStrOff, "}", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                s = ____BAH_COMPILER_VAR_83;
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
char * ____BAH_COMPILER_VAR_84 =null;char * ____BAH_COMPILER_VAR_85 =jsonEscapeStr(s);
                {
                    long int currStrOff = 0;
                    long int strLen_1 = strlen("\"");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_85);
long int strLen_5 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_84 = memoryAllocSTR(1 + strLen_1 + strLen_3 + strLen_5);
                    
                        memcpy(____BAH_COMPILER_VAR_84+currStrOff, "\"", strLen_1);
                        currStrOff += strLen_1;
                        
                        memcpy(____BAH_COMPILER_VAR_84+currStrOff, ____BAH_COMPILER_VAR_85, strLen_3);
                        currStrOff += strLen_3;
                        
                        memcpy(____BAH_COMPILER_VAR_84+currStrOff, "\"", strLen_5);
                        currStrOff += strLen_5;
                        
                }
                return ____BAH_COMPILER_VAR_84;
}
else {
char ** sp = e.value;
char * s = *sp;
char * ____BAH_COMPILER_VAR_86 =null;char * ____BAH_COMPILER_VAR_87 =jsonEscapeStr(s);
                {
                    long int currStrOff = 0;
                    long int strLen_1 = strlen("\"");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_87);
long int strLen_5 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_86 = memoryAllocSTR(1 + strLen_1 + strLen_3 + strLen_5);
                    
                        memcpy(____BAH_COMPILER_VAR_86+currStrOff, "\"", strLen_1);
                        currStrOff += strLen_1;
                        
                        memcpy(____BAH_COMPILER_VAR_86+currStrOff, ____BAH_COMPILER_VAR_87, strLen_3);
                        currStrOff += strLen_3;
                        
                        memcpy(____BAH_COMPILER_VAR_86+currStrOff, "\"", strLen_5);
                        currStrOff += strLen_5;
                        
                }
                return ____BAH_COMPILER_VAR_86;
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
char * ____BAH_COMPILER_VAR_88 =null;char * ____BAH_COMPILER_VAR_89 =intToStr(arr->data[i]);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_89);
;                            
                    ____BAH_COMPILER_VAR_88 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_88+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_88+currStrOff, ____BAH_COMPILER_VAR_89, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_88;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_90 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_90 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_90+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_90+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_90;
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
char * ____BAH_COMPILER_VAR_91 =null;char * ____BAH_COMPILER_VAR_92 =floatToStr(arr->data[i]);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_92);
;                            
                    ____BAH_COMPILER_VAR_91 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_91+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_91+currStrOff, ____BAH_COMPILER_VAR_92, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_91;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_93 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_93 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_93+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_93+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_93;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
arr = *arrPtr;
char * ____BAH_COMPILER_VAR_94 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_94 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_94+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_94+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_94;
long int i = 0;
while ((i<len(arr))) {

                        if (arr->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: arr[%d] with length %d", i, arr->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:512");
                        };
                        char * ____BAH_COMPILER_VAR_95 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(arr->data[i]);
;                            
                    ____BAH_COMPILER_VAR_95 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_95+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_95+currStrOff, arr->data[i], strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_95;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_96 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_96 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_96+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_96+currStrOff, ",\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_96;
}
else {
char * ____BAH_COMPILER_VAR_97 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_97 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_97+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_97+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_97;
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
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:532");
                        };
                        void * arrElem = arr->data[i];
ae->value = arrElem;
long int j = 0;
while ((j<len(ae->structLayout))) {

                        if (ae->structLayout->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: ae->structLayout[%d] with length %d", j, ae->structLayout->length);
                            __BAH_panic((char*)buff, (char*)"/opt/bah/json.bah:535");
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
char * ____BAH_COMPILER_VAR_98 =null;char * ____BAH_COMPILER_VAR_99 =toJson__inner(*ae,false,tabs);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_99);
;                            
                    ____BAH_COMPILER_VAR_98 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_98+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_98+currStrOff, ____BAH_COMPILER_VAR_99, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_98;
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
char * ____BAH_COMPILER_VAR_102 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s);
long int strLen_4 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_102 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_102+currStrOff, s, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_102+currStrOff, "]", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                s = ____BAH_COMPILER_VAR_102;
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
char * ____BAH_COMPILER_VAR_103 = name;
struct reflectElement ____BAH_COMPILER_VAR_104 = __reflect(____BAH_COMPILER_VAR_103, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_105 =null;char * ____BAH_COMPILER_VAR_106 =toJson(____BAH_COMPILER_VAR_104);char * ____BAH_COMPILER_VAR_107 =intToStr(line);char * ____BAH_COMPILER_VAR_108 =toJson(e);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_106);
long int strLen_4 = strlen(",\n        \"path\": \"");
long int strLen_6 = strlen(compilerState.currentFile);
long int strLen_8 = strlen(":");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_107);
long int strLen_12 = strlen("\",\n        \"element\": ");
long int strLen_14 = strlen(____BAH_COMPILER_VAR_108);
long int strLen_16 = strlen("\n    },\n    ");
;                            
                    ____BAH_COMPILER_VAR_105 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, ____BAH_COMPILER_VAR_106, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, ",\n        \"path\": \"", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, compilerState.currentFile, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, ":", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, ____BAH_COMPILER_VAR_107, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, "\",\n        \"element\": ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, ____BAH_COMPILER_VAR_108, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_105+currStrOff, "\n    },\n    ", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                println(____BAH_COMPILER_VAR_105);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_109 = name;
struct reflectElement ____BAH_COMPILER_VAR_110 = __reflect(____BAH_COMPILER_VAR_109, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_111 =null;char * ____BAH_COMPILER_VAR_112 =toJson(____BAH_COMPILER_VAR_110);char * ____BAH_COMPILER_VAR_113 =intToStr(line);char * ____BAH_COMPILER_VAR_114 =intToStr(from);char * ____BAH_COMPILER_VAR_115 =intToStr(to);char * ____BAH_COMPILER_VAR_116 =toJson(e);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_112);
long int strLen_4 = strlen(",\n        \"path\": \"");
long int strLen_6 = strlen(compilerState.currentFile);
long int strLen_8 = strlen(":");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_113);
long int strLen_12 = strlen("\",\n        \"range\": [\n            ");
long int strLen_14 = strlen(____BAH_COMPILER_VAR_114);
long int strLen_16 = strlen(",\n            ");
long int strLen_18 = strlen(____BAH_COMPILER_VAR_115);
long int strLen_20 = strlen("\n        ],\n        \"element\": ");
long int strLen_22 = strlen(____BAH_COMPILER_VAR_116);
long int strLen_24 = strlen("\n    },\n    ");
;                            
                    ____BAH_COMPILER_VAR_111 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24);
                    
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, ____BAH_COMPILER_VAR_112, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, ",\n        \"path\": \"", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, compilerState.currentFile, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, ":", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, ____BAH_COMPILER_VAR_113, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, "\",\n        \"range\": [\n            ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, ____BAH_COMPILER_VAR_114, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, ",\n            ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, ____BAH_COMPILER_VAR_115, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, "\n        ],\n        \"element\": ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, ____BAH_COMPILER_VAR_116, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_111+currStrOff, "\n    },\n    ", strLen_24);
                        currStrOff += strLen_24;
                        
                }
                println(____BAH_COMPILER_VAR_111);
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
struct variable* ____BAH_COMPILER_VAR_117 = v;
char ** ____BAH_COMPILER_VAR_119 = (char **)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_120 = __reflect(____BAH_COMPILER_VAR_119, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_121 = (char **)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_122 = __reflect(____BAH_COMPILER_VAR_121, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_123 = (char*)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_124 = __reflect(____BAH_COMPILER_VAR_123, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_125 = (char **)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_126 = __reflect(____BAH_COMPILER_VAR_125, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_127 = (char*)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_128 = __reflect(____BAH_COMPILER_VAR_127, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_129 = (char **)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_130 = __reflect(____BAH_COMPILER_VAR_129, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_131 = (char*)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_132 = __reflect(____BAH_COMPILER_VAR_131, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_133 = (char*)((char*)(____BAH_COMPILER_VAR_117) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_134 = __reflect(____BAH_COMPILER_VAR_133, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_118 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_118->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_118->length = 8;
        ____BAH_COMPILER_VAR_118->data = memoryAlloc(____BAH_COMPILER_VAR_118->length * ____BAH_COMPILER_VAR_118->elemSize);
        ____BAH_COMPILER_VAR_118->data[0] = ____BAH_COMPILER_VAR_120;
____BAH_COMPILER_VAR_118->data[1] = ____BAH_COMPILER_VAR_122;
____BAH_COMPILER_VAR_118->data[2] = ____BAH_COMPILER_VAR_124;
____BAH_COMPILER_VAR_118->data[3] = ____BAH_COMPILER_VAR_126;
____BAH_COMPILER_VAR_118->data[4] = ____BAH_COMPILER_VAR_128;
____BAH_COMPILER_VAR_118->data[5] = ____BAH_COMPILER_VAR_130;
____BAH_COMPILER_VAR_118->data[6] = ____BAH_COMPILER_VAR_132;
____BAH_COMPILER_VAR_118->data[7] = ____BAH_COMPILER_VAR_134;
struct reflectElement ____BAH_COMPILER_VAR_135 = __reflect(____BAH_COMPILER_VAR_117, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_118, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_135);
}
i = i+1;
};
};
void throwErr(void * tp,char * format){
char * str = "";
char * info = "";
long int pos = 0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_136 = {};
____BAH_COMPILER_VAR_136.handle = -1;
____BAH_COMPILER_VAR_136.p= null;
____BAH_COMPILER_VAR_136.open = fileMap__open;
____BAH_COMPILER_VAR_136.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_136.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_136
char * fileSrcStr = fm.open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char * ____BAH_COMPILER_VAR_137 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_4 = strlen("'");
long int strLen_6 = strlen(t->ogCont);
long int strLen_8 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_137 = memoryAllocSTR(1 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_137+currStrOff, "'", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_137+currStrOff, t->ogCont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_137+currStrOff, "'", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                ffmt.replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_137);
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
char * ____BAH_COMPILER_VAR_138 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m");
long int strLen_2 = strlen(t->ogCont);
long int strLen_4 = strlen("\e[1;37m");
;                            
                    ____BAH_COMPILER_VAR_138 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_138+currStrOff, "\e[1;31m", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_138+currStrOff, t->ogCont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_138+currStrOff, "\e[1;37m", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                array(char)* errTk = strToArr(____BAH_COMPILER_VAR_138);
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
char * ____BAH_COMPILER_VAR_139 =null;char * ____BAH_COMPILER_VAR_140 =intToStr(t->line);char * ____BAH_COMPILER_VAR_141 =intToStr(pos);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_140);
long int strLen_4 = strlen(":");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_141);
;                            
                    ____BAH_COMPILER_VAR_139 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_139+currStrOff, ____BAH_COMPILER_VAR_140, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_139+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_139+currStrOff, ____BAH_COMPILER_VAR_141, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                info = ____BAH_COMPILER_VAR_139;
}
if ((debug==true)) {
struct Tok* t = tp;
char * ____BAH_COMPILER_VAR_142 = format;
struct reflectElement ____BAH_COMPILER_VAR_143 = __reflect(____BAH_COMPILER_VAR_142, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_143);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_144 =null;
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
                    ____BAH_COMPILER_VAR_144 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_144+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_144+currStrOff, compilerState.currentFile, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_144+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_144+currStrOff, info, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_144+currStrOff, "\n\e[1;37m\t", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_144+currStrOff, str, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_144+currStrOff, "\e[0m\n", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_144+currStrOff, format, strLen_14);
                        currStrOff += strLen_14;
                        
                }
                println(____BAH_COMPILER_VAR_144);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_145 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;33m[WARNING]\e[0m ");
long int strLen_2 = strlen(compilerState.currentFile);
long int strLen_4 = strlen("\n\e[1;37m\t");
long int strLen_6 = strlen(s);
long int strLen_8 = strlen("\e[0m");
;                            
                    ____BAH_COMPILER_VAR_145 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_145+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_145+currStrOff, compilerState.currentFile, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_145+currStrOff, "\n\e[1;37m\t", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_145+currStrOff, s, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_145+currStrOff, "\e[0m", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                println(____BAH_COMPILER_VAR_145);
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
struct variable* ____BAH_COMPILER_VAR_146 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_146->name = "";
____BAH_COMPILER_VAR_146->type = "";
____BAH_COMPILER_VAR_146->isConst = false;
____BAH_COMPILER_VAR_146->constVal = "";
____BAH_COMPILER_VAR_146->isArray = false;
____BAH_COMPILER_VAR_146->from = "";
____BAH_COMPILER_VAR_146->outterScope = false;
____BAH_COMPILER_VAR_146->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_146;
nv->type = vtstr;
nv->name = ogName;
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
struct variable* ____BAH_COMPILER_VAR_147 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_147->name = "";
____BAH_COMPILER_VAR_147->type = "";
____BAH_COMPILER_VAR_147->isConst = false;
____BAH_COMPILER_VAR_147->constVal = "";
____BAH_COMPILER_VAR_147->isArray = false;
____BAH_COMPILER_VAR_147->from = "";
____BAH_COMPILER_VAR_147->outterScope = false;
____BAH_COMPILER_VAR_147->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_147;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (tcc.count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_148 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(r);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_148 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_148+currStrOff, r, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_148+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = ____BAH_COMPILER_VAR_148;
}
long int nbUnaries = tcc.count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = ct.count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_149 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use '*' on ");
long int strLen_4 = strlen(nv->name);
long int strLen_6 = strlen(" because it is not pointer.");
;                            
                    ____BAH_COMPILER_VAR_149 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_149+currStrOff, "Cannot use '*' on ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_149+currStrOff, nv->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_149+currStrOff, " because it is not pointer.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(null,____BAH_COMPILER_VAR_149);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:104");
                        };
                        struct variable* v = elems->vars->data[i];
if ((strcmp(v->name, name) == 0)) {
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
nv->type = v->type;
nv->name = v->name;
nv->isConst = v->isConst;
char * r = nv->type;
struct string tcc = string(ogName);
if (tcc.count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_151 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(r);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_151 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_151+currStrOff, r, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_151+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = ____BAH_COMPILER_VAR_151;
}
long int nbUnaries = tcc.count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = ct.count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_152 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use '*' on ");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(" because it is not pointer.");
;                            
                    ____BAH_COMPILER_VAR_152 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_152+currStrOff, "Cannot use '*' on ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_152+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_152+currStrOff, " because it is not pointer.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(null,____BAH_COMPILER_VAR_152);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:134");
                        };
                        struct func* fn = elems->fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_153 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_153->name = "";
____BAH_COMPILER_VAR_153->type = "";
____BAH_COMPILER_VAR_153->isConst = false;
____BAH_COMPILER_VAR_153->constVal = "";
____BAH_COMPILER_VAR_153->isArray = false;
____BAH_COMPILER_VAR_153->from = "";
____BAH_COMPILER_VAR_153->outterScope = false;
____BAH_COMPILER_VAR_153->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_153;
nv->name = name;
nv->type = "function(";
long int j = 0;
while ((j<len(fn->args))) {

                        if (fn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", j, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:140");
                        };
                        struct variable* arg = fn->args->data[j];
char * ____BAH_COMPILER_VAR_154 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nv->type);
long int strLen_4 = strlen(arg->type);
;                            
                    ____BAH_COMPILER_VAR_154 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_154+currStrOff, nv->type, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_154+currStrOff, arg->type, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                nv->type = ____BAH_COMPILER_VAR_154;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_155 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nv->type);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_155 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_155+currStrOff, nv->type, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_155+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                nv->type = ____BAH_COMPILER_VAR_155;
}
};
fn->used = true;
char * ____BAH_COMPILER_VAR_156 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nv->type);
long int strLen_4 = strlen(")");
long int strLen_6 = strlen(fn->returns->type);
;                            
                    ____BAH_COMPILER_VAR_156 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_156+currStrOff, nv->type, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_156+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_156+currStrOff, fn->returns->type, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                nv->type = ____BAH_COMPILER_VAR_156;
return nv;
}
};
return null;
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp = getCType(v->type,elems);
char * t = tp.str(&tp);
char * ____BAH_COMPILER_VAR_157 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(t);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(v->name);
;                            
                    ____BAH_COMPILER_VAR_157 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_157+currStrOff, t, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_157+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_157+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                t = ____BAH_COMPILER_VAR_157;
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
struct func* ____BAH_COMPILER_VAR_158 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_158->name = "";
____BAH_COMPILER_VAR_158->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_158->args->length = 0;
            ____BAH_COMPILER_VAR_158->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_158->returns= null;
____BAH_COMPILER_VAR_158->isBinding = false;
____BAH_COMPILER_VAR_158->from = "";
____BAH_COMPILER_VAR_158->file = "";
____BAH_COMPILER_VAR_158->line = 1;
____BAH_COMPILER_VAR_158->used = false;
____BAH_COMPILER_VAR_158->code = null;
struct func* nf = ____BAH_COMPILER_VAR_158;
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
struct variable* ____BAH_COMPILER_VAR_159 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_159->name = "";
____BAH_COMPILER_VAR_159->type = "";
____BAH_COMPILER_VAR_159->isConst = false;
____BAH_COMPILER_VAR_159->constVal = "";
____BAH_COMPILER_VAR_159->isArray = false;
____BAH_COMPILER_VAR_159->from = "";
____BAH_COMPILER_VAR_159->outterScope = false;
____BAH_COMPILER_VAR_159->isGlobal = false;
struct variable* arg = ____BAH_COMPILER_VAR_159;
char * ____BAH_COMPILER_VAR_160 =null;char * ____BAH_COMPILER_VAR_161 =intToStr(len(nf->args));
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("arg_");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_161);
;                            
                    ____BAH_COMPILER_VAR_160 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_160+currStrOff, "arg_", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_160+currStrOff, ____BAH_COMPILER_VAR_161, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                arg->name = ____BAH_COMPILER_VAR_160;
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
struct variable* ____BAH_COMPILER_VAR_162 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_162->name = "";
____BAH_COMPILER_VAR_162->type = "";
____BAH_COMPILER_VAR_162->isConst = false;
____BAH_COMPILER_VAR_162->constVal = "";
____BAH_COMPILER_VAR_162->isArray = false;
____BAH_COMPILER_VAR_162->from = "";
____BAH_COMPILER_VAR_162->outterScope = false;
____BAH_COMPILER_VAR_162->isGlobal = false;
nf->returns = ____BAH_COMPILER_VAR_162;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_163 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_163->name = "";
____BAH_COMPILER_VAR_163->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_163->args->length = 0;
            ____BAH_COMPILER_VAR_163->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_163->returns= null;
____BAH_COMPILER_VAR_163->isBinding = false;
____BAH_COMPILER_VAR_163->from = "";
____BAH_COMPILER_VAR_163->file = "";
____BAH_COMPILER_VAR_163->line = 1;
____BAH_COMPILER_VAR_163->used = false;
____BAH_COMPILER_VAR_163->code = null;
struct func* fn = ____BAH_COMPILER_VAR_163;
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
char * ____BAH_COMPILER_VAR_164 =fnName.str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_164,s,elems);
name = fnName.content;
char * ____BAH_COMPILER_VAR_165 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(memb->from);
long int strLen_4 = strlen("__");
long int strLen_6 = strlen(name);
;                            
                    ____BAH_COMPILER_VAR_165 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_165+currStrOff, memb->from, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_165+currStrOff, "__", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_165+currStrOff, name, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                name = ____BAH_COMPILER_VAR_165;
}
array(struct func*)* fns = elems->fns;
long int i = 0;
while ((i<len(fns))) {

                        if (fns->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: fns[%d] with length %d", i, fns->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:280");
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
struct func* ____BAH_COMPILER_VAR_166 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_166->name = "";
____BAH_COMPILER_VAR_166->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_166->args->length = 0;
            ____BAH_COMPILER_VAR_166->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_166->returns= null;
____BAH_COMPILER_VAR_166->isBinding = false;
____BAH_COMPILER_VAR_166->from = "";
____BAH_COMPILER_VAR_166->file = "";
____BAH_COMPILER_VAR_166->line = 1;
____BAH_COMPILER_VAR_166->used = false;
____BAH_COMPILER_VAR_166->code = null;
struct func* nf = ____BAH_COMPILER_VAR_166;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:324");
                        };
                        struct structMemb* m = members->data[i];
struct string cmpt = string(m->type);
char declared = false;
if ((strlen(m->def)>0)) {
char * ____BAH_COMPILER_VAR_167 =null;
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
                    ____BAH_COMPILER_VAR_167 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_167+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_167+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_167+currStrOff, sep, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_167+currStrOff, m->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_167+currStrOff, " = ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_167+currStrOff, m->def, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_167+currStrOff, ";\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                code = ____BAH_COMPILER_VAR_167;
declared = true;
}
if ((cmpt.hasPrefix(&cmpt,"[]")==1)) {
cmpt.trimLeft(&cmpt,2);
char * cmptstr = cmpt.str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = elemCType.str(&elemCType);
char * ____BAH_COMPILER_VAR_168 =null;
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
                    ____BAH_COMPILER_VAR_168 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34);
                    
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, sep, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, m->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, " = memoryAlloc(sizeof(array(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, elemCTypeStr, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, ")));\n            ", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, v->name, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, sep, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, m->name, strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, "->length = 0;\n            ", strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, v->name, strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, sep, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, m->name, strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, "->elemSize = sizeof(", strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, elemCTypeStr, strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_168+currStrOff, ");\n            ", strLen_34);
                        currStrOff += strLen_34;
                        
                }
                code = ____BAH_COMPILER_VAR_168;
declared = true;
}
else if ((cmpt.hasPrefix(&cmpt,"map:")==1)) {
cmpt.trimLeft(&cmpt,4);
char * ____BAH_COMPILER_VAR_169 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen(m->name);
long int strLen_8 = strlen(" = mapWrapper();\n");
;                            
                    ____BAH_COMPILER_VAR_169 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_169+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_169+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_169+currStrOff, m->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_169+currStrOff, " = mapWrapper();\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                char * ____BAH_COMPILER_VAR_170 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_169);
;                            
                    ____BAH_COMPILER_VAR_170 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_170+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_170+currStrOff, ____BAH_COMPILER_VAR_169, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                code = ____BAH_COMPILER_VAR_170;
declared = true;
}
else if ((cmpt.hasPrefix(&cmpt,"chan:")==1)) {
cmpt.trimLeft(&cmpt,5);
char * ____BAH_COMPILER_VAR_171 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen(m->name);
long int strLen_8 = strlen(" = channel();\n");
;                            
                    ____BAH_COMPILER_VAR_171 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, m->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_171+currStrOff, " = channel();\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                char * ____BAH_COMPILER_VAR_172 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_171);
;                            
                    ____BAH_COMPILER_VAR_172 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_172+currStrOff, ____BAH_COMPILER_VAR_171, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                code = ____BAH_COMPILER_VAR_172;
declared = true;
}
if ((isRCPpointerType(m->type)&&(declared==false))) {
char * ____BAH_COMPILER_VAR_173 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(sep);
long int strLen_8 = strlen(m->name);
long int strLen_10 = strlen("= null;\n");
;                            
                    ____BAH_COMPILER_VAR_173 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_173+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_173+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_173+currStrOff, sep, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_173+currStrOff, m->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_173+currStrOff, "= null;\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                code = ____BAH_COMPILER_VAR_173;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:361");
                        };
                        struct func* m = es->methods->data[i];
char * ____BAH_COMPILER_VAR_174 =null;
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
                    ____BAH_COMPILER_VAR_174 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18);
                    
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, sep, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, m->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, " = ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, es->name, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, "__", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, m->name, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_174+currStrOff, ";\n", strLen_18);
                        currStrOff += strLen_18;
                        
                }
                code = ____BAH_COMPILER_VAR_174;
i = i+1;
};
}
array(struct func*)* methods = s->methods;
i = 0;
while ((i<len(methods))) {

                        if (methods->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: methods[%d] with length %d", i, methods->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:369");
                        };
                        struct func* m = methods->data[i];
char * ____BAH_COMPILER_VAR_175 =null;
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
                    ____BAH_COMPILER_VAR_175 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18);
                    
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, sep, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, m->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, " = ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, s->name, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, "__", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, m->name, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_175+currStrOff, ";\n", strLen_18);
                        currStrOff += strLen_18;
                        
                }
                code = ____BAH_COMPILER_VAR_175;
i = i+1;
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); i = i+1) {

                        if (s->methods->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: s->methods[%d] with length %d", i, s->methods->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:385");
                        };
                        struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char * ____BAH_COMPILER_VAR_176 =null;
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
                    ____BAH_COMPILER_VAR_176 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_176+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_176+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_176+currStrOff, m->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_176+currStrOff, "(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_176+currStrOff, amp, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_176+currStrOff, v->name, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_176+currStrOff, ");\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                char * ____BAH_COMPILER_VAR_177 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(NEXT_LINE);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_176);
;                            
                    ____BAH_COMPILER_VAR_177 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_177+currStrOff, NEXT_LINE, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_177+currStrOff, ____BAH_COMPILER_VAR_176, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_177;
found = found+1;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char * ____BAH_COMPILER_VAR_178 =null;
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
                    ____BAH_COMPILER_VAR_178 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, "memoryOnEnd(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, v->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, sep, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, m->name, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_178+currStrOff, ");\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                char * ____BAH_COMPILER_VAR_179 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_178);
;                            
                    ____BAH_COMPILER_VAR_179 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_179+currStrOff, ____BAH_COMPILER_VAR_178, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                code = ____BAH_COMPILER_VAR_179;
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
char * ____BAH_COMPILER_VAR_180 =null;char * ____BAH_COMPILER_VAR_181 =intToStr(NB_COMP_VAR);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("____BAH_COMPILER_VAR_");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_181);
;                            
                    ____BAH_COMPILER_VAR_180 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_180+currStrOff, "____BAH_COMPILER_VAR_", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_180+currStrOff, ____BAH_COMPILER_VAR_181, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * name = ____BAH_COMPILER_VAR_180;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:417");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:429");
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
char * ____BAH_COMPILER_VAR_182 =null;char * ____BAH_COMPILER_VAR_183 =pathToVarName(compilerState.currentFile);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(name);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_183);
;                            
                    ____BAH_COMPILER_VAR_182 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_182+currStrOff, name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_182+currStrOff, ____BAH_COMPILER_VAR_183, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                name = ____BAH_COMPILER_VAR_182;
}
char * evals = "";
char * ____BAH_COMPILER_VAR_184 =null;char * ____BAH_COMPILER_VAR_185 =intToStr(len(compilerState.evals));
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_185);
long int strLen_6 = strlen("] = {");
;                            
                    ____BAH_COMPILER_VAR_184 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_184+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_184+currStrOff, ____BAH_COMPILER_VAR_185, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_184+currStrOff, "] = {", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * evalsTMPDecl = ____BAH_COMPILER_VAR_184;
long int i = 0;
for (; (i<len(compilerState.evals)); i = i+1) {

                        if (compilerState.evals->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: compilerState.evals[%d] with length %d", i, compilerState.evals->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/var.bah:450");
                        };
                        char * e = compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_186 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("{\n            .name = \"");
long int strLen_4 = strlen(e);
long int strLen_6 = strlen("\",\n            .evalFn = __Bah_eval_");
long int strLen_8 = strlen(e);
long int strLen_10 = strlen("\n        }");
;                            
                    ____BAH_COMPILER_VAR_186 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_186+currStrOff, "{\n            .name = \"", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_186+currStrOff, e, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_186+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_186+currStrOff, e, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_186+currStrOff, "\n        }", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * ____BAH_COMPILER_VAR_187 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_186);
;                            
                    ____BAH_COMPILER_VAR_187 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_187+currStrOff, evalsTMPDecl, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_187+currStrOff, ____BAH_COMPILER_VAR_186, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                evalsTMPDecl = ____BAH_COMPILER_VAR_187;
if ((i+1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_188 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_2 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_188 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_188+currStrOff, evalsTMPDecl, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_188+currStrOff, ",\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                evalsTMPDecl = ____BAH_COMPILER_VAR_188;
}
else {
char * ____BAH_COMPILER_VAR_189 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_2 = strlen("};");
;                            
                    ____BAH_COMPILER_VAR_189 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_189+currStrOff, evalsTMPDecl, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_189+currStrOff, "};", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                evalsTMPDecl = ____BAH_COMPILER_VAR_189;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_190 =null;char * ____BAH_COMPILER_VAR_191 =intToStr(len(compilerState.evals));
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_191);
long int strLen_6 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_190 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_190+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_190+currStrOff, ____BAH_COMPILER_VAR_191, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_190+currStrOff, ";", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                evals = ____BAH_COMPILER_VAR_190;
}
else {
evalsTMPDecl = "";
}
char * ____BAH_COMPILER_VAR_192 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    ");
long int strLen_2 = strlen(evalsTMPDecl);
long int strLen_4 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
long int strLen_6 = strlen(name);
long int strLen_8 = strlen("() {\n        ");
;                            
                    ____BAH_COMPILER_VAR_192 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_192+currStrOff, "\n    ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_192+currStrOff, evalsTMPDecl, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_192+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_192+currStrOff, name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_192+currStrOff, "() {\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                char * ____BAH_COMPILER_VAR_193 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        ");
long int strLen_2 = strlen(evals);
long int strLen_4 = strlen("\n    };\n    ");
;                            
                    ____BAH_COMPILER_VAR_193 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_193+currStrOff, "\n        ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_193+currStrOff, evals, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_193+currStrOff, "\n    };\n    ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_192)->add(rope(____BAH_COMPILER_VAR_192), INIT)->add(rope(____BAH_COMPILER_VAR_192)->add(rope(____BAH_COMPILER_VAR_192), INIT), rope(____BAH_COMPILER_VAR_193)));
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r = rope("");
if (strHasPrefix(v->type,"[]")) {
char * ____BAH_COMPILER_VAR_194 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_scanHeap(");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_194 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_194+currStrOff, "RCP_scanHeap(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_194+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_194+currStrOff, ");\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_194));
}
else if (strHasPrefix(v->type,"chan:")) {
char * ____BAH_COMPILER_VAR_195 =null;
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
                    ____BAH_COMPILER_VAR_195 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_195+currStrOff, "{\n            struct RCP * chanRCP = RCP_request(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_195+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_195+currStrOff, ");\n            if (chanRCP != null && chanRCP->c == 1) {\n                ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_195+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_195+currStrOff, "->destroy(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_195+currStrOff, v->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_195+currStrOff, ");\n                RCP_decr(", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_195+currStrOff, v->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_195+currStrOff, "->queue);\n            };\n            RCP_decrRCP(chanRCP);\n        };", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                r = rope(____BAH_COMPILER_VAR_195);
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_196 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_196->name = "";
____BAH_COMPILER_VAR_196->type = "";
____BAH_COMPILER_VAR_196->isConst = false;
____BAH_COMPILER_VAR_196->constVal = "";
____BAH_COMPILER_VAR_196->isArray = false;
____BAH_COMPILER_VAR_196->from = "";
____BAH_COMPILER_VAR_196->outterScope = false;
____BAH_COMPILER_VAR_196->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_196;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if (((s!=null)&&(s->isBinding==false))) {
if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_197 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_scanHeap(");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_197 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_197+currStrOff, "RCP_scanHeap(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_197+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_197+currStrOff, ");\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_197));
}
else {
char * ____BAH_COMPILER_VAR_198 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_scanStack(&");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(", sizeof(");
long int strLen_6 = strlen(v->name);
long int strLen_8 = strlen("), 1);\n");
;                            
                    ____BAH_COMPILER_VAR_198 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_198+currStrOff, "RCP_scanStack(&", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_198+currStrOff, ", sizeof(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_198+currStrOff, "), 1);\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_198));
}
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_199 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_decr(");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_199 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, "RCP_decr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_199+currStrOff, ");\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_199));
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
char * ____BAH_COMPILER_VAR_200 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_scanStack(&");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(", sizeof(");
long int strLen_6 = strlen(v->name);
long int strLen_8 = strlen("), 0);");
;                            
                    ____BAH_COMPILER_VAR_200 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_200+currStrOff, "RCP_scanStack(&", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_200+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_200+currStrOff, ", sizeof(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_200+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_200+currStrOff, "), 0);", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                return rope(____BAH_COMPILER_VAR_200);
}
char * ____BAH_COMPILER_VAR_201 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_incr(");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(");");
;                            
                    ____BAH_COMPILER_VAR_201 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_201+currStrOff, "RCP_incr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_201+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_201+currStrOff, ");", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                return rope(____BAH_COMPILER_VAR_201);
};
char RCPavailable(){
char * ____BAH_COMPILER_VAR_202 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_2 = strlen("rcp.bah");
;                            
                    ____BAH_COMPILER_VAR_202 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_202+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_202+currStrOff, "rcp.bah", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                char * ____BAH_COMPILER_VAR_203 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_2 = strlen("fastrcp.bah");
;                            
                    ____BAH_COMPILER_VAR_203 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_203+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_203+currStrOff, "fastrcp.bah", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                return (((strcmp(absPath(compilerState.currentFile), absPath(____BAH_COMPILER_VAR_202)) != 0)&&(strcmp(absPath(compilerState.currentFile), absPath(____BAH_COMPILER_VAR_203)) != 0))&&(RCPenabled==true));
};
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable exc){
if ((RCPavailable()==false)) {
long int i = 0;
for (; (i<len(elems->vars)); i = i+1) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:98");
                        };
                        struct variable* v = elems->vars->data[i];
if ((((v->outterScope==false)&&(varInArr(v,exc)==false))&&(isRCPpointerType(v->type)==false))) {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)) {
struct structMemb* memb = searchStructMemb("_end",s,elems);
if (((memb!=null)&&(memb->isFn==true))) {
char * ____BAH_COMPILER_VAR_204 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_2 = strlen("._end(&");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_204 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_204+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_204+currStrOff, "._end(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_204+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_204+currStrOff, ");\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_204));
}
}
}
};
return;
}
long int i = 0;
for (; (i<len(elems->vars)); i = i+1) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:112");
                        };
                        struct variable* v = elems->vars->data[i];
if (((v->outterScope==false)&&(varInArr(v,exc)==false))) {
if ((isRCPtype(v->type,elems)==true)) {
OUTPUT = OUTPUT->add(OUTPUT, decrVar(v,elems));
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)) {
struct structMemb* memb = searchStructMemb("_end",s,elems);
if ((memb!=null)) {
char * ____BAH_COMPILER_VAR_205 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_2 = strlen("._end(&");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_205 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_205+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_205+currStrOff, "._end(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_205+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_205+currStrOff, ");\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_205));
}
}
}
}
};
};
void beginRCPscope(__BAH_ARR_TYPE_variable vars,struct Elems* elems){
if ((RCPavailable()==false)) {
return;
}
long int i = 0;
for (; (i<len(vars)); i = i+1) {

                        if (vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: vars[%d] with length %d", i, vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:134");
                        };
                        struct variable* v = vars->data[i];
if ((isRCPpointerType(v->type)==false)) {
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
continue;
}
char * ____BAH_COMPILER_VAR_206 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_scanStack(&");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(", sizeof(");
long int strLen_6 = strlen(v->name);
long int strLen_8 = strlen("), 0);\n");
;                            
                    ____BAH_COMPILER_VAR_206 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_206+currStrOff, "RCP_scanStack(&", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_206+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_206+currStrOff, ", sizeof(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_206+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_206+currStrOff, "), 0);\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_206));
}
};
};
void decrRCPstackVars(__BAH_ARR_TYPE_variable vars,struct Elems* elems){
if ((RCPavailable()==false)) {
return;
}
long int i = 0;
for (; (i<len(vars)); i = i+1) {

                        if (vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: vars[%d] with length %d", i, vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:150");
                        };
                        struct variable* v = vars->data[i];
if ((isRCPpointerType(v->type)==false)) {
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
continue;
}
char * ____BAH_COMPILER_VAR_207 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_scanStack(&");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(", sizeof(");
long int strLen_6 = strlen(v->name);
long int strLen_8 = strlen("), 1);\n");
;                            
                    ____BAH_COMPILER_VAR_207 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_207+currStrOff, "RCP_scanStack(&", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_207+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_207+currStrOff, ", sizeof(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_207+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_207+currStrOff, "), 1);\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_207));
}
};
};
void endRCPnonGlobScope(struct Elems* elems,__BAH_ARR_TYPE_variable exc){
if ((RCPavailable()==false)) {
long int i = 0;
for (; (i<len(elems->vars)); i = i+1) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:164");
                        };
                        struct variable* v = elems->vars->data[i];
if ((((v->isGlobal==false)&&(varInArr(v,exc)==false))&&(isRCPpointerType(v->type)==false))) {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)) {
char * ____BAH_COMPILER_VAR_208 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_2 = strlen("___end");
;                            
                    ____BAH_COMPILER_VAR_208 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_208+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_208+currStrOff, "___end", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                struct func* fn = searchFunc(____BAH_COMPILER_VAR_208,elems,true);
if ((fn!=null)) {
char * ____BAH_COMPILER_VAR_209 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_2 = strlen("._end(&");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_209 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_209+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_209+currStrOff, "._end(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_209+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_209+currStrOff, ");\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_209));
}
}
}
};
return;
}
long int i = 0;
for (; (i<len(elems->vars)); i = i+1) {

                        if (elems->vars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", i, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:178");
                        };
                        struct variable* v = elems->vars->data[i];
if (((v->isGlobal==false)&&(varInArr(v,exc)==false))) {
if ((isRCPtype(v->type,elems)==true)) {
OUTPUT = OUTPUT->add(OUTPUT, decrVar(v,elems));
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)) {
struct structMemb* memb = searchStructMemb("_end",s,elems);
if ((memb!=null)) {
char * ____BAH_COMPILER_VAR_210 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_2 = strlen("._end(&");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_210 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_210+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_210+currStrOff, "._end(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_210+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_210+currStrOff, ");\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_210));
}
}
}
}
};
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* ____BAH_COMPILER_VAR_211 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_211->name = "";
____BAH_COMPILER_VAR_211->type = "";
____BAH_COMPILER_VAR_211->isConst = false;
____BAH_COMPILER_VAR_211->constVal = "";
____BAH_COMPILER_VAR_211->isArray = false;
____BAH_COMPILER_VAR_211->from = "";
____BAH_COMPILER_VAR_211->outterScope = false;
____BAH_COMPILER_VAR_211->isGlobal = false;
struct variable* av = ____BAH_COMPILER_VAR_211;
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
char * ____BAH_COMPILER_VAR_212 =null;char * ____BAH_COMPILER_VAR_213 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_213);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(av->name);
long int strLen_6 = strlen(" =");
long int strLen_8 = strlen(c);
long int strLen_10 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_212 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_212+currStrOff, ____BAH_COMPILER_VAR_213, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_212+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_212+currStrOff, av->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_212+currStrOff, " =", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_212+currStrOff, c, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_212+currStrOff, ";", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_212));
return av->name;
};
char RCPselfRef(struct variable* v){
long int i = 0;
while ((i<len(compilerState.RCPvars))) {

                        if (compilerState.RCPvars->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: compilerState.RCPvars[%d] with length %d", i, compilerState.RCPvars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/mem.bah:270");
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

                int ____BAH_COMPILER_VAR_214 = 0;
                for(int i=len(noVOfns)-1; i != -1; i--) {
                    if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                        ____BAH_COMPILER_VAR_214 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_214) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_215 = {};
____BAH_COMPILER_VAR_215.markup= null;
____BAH_COMPILER_VAR_215.content= null;
#define rv ____BAH_COMPILER_VAR_215
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_216 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__Bah_safe_string(");
long int strLen_4 = strlen(cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_216 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_216+currStrOff, "__Bah_safe_string(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_216+currStrOff, cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_216+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                cont = ____BAH_COMPILER_VAR_216;
}
char * ____BAH_COMPILER_VAR_217 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(", ");
long int strLen_4 = strlen(cont);
;                            
                    ____BAH_COMPILER_VAR_217 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_217+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_217+currStrOff, cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                cont = ____BAH_COMPILER_VAR_217;
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
char * ____BAH_COMPILER_VAR_218 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ASCII_RESET);
long int strLen_4 = strlen("{");
;                            
                    ____BAH_COMPILER_VAR_218 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_218+currStrOff, ASCII_RESET, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_218+currStrOff, "{", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ct = ____BAH_COMPILER_VAR_218;
cont = "";
long int i = 0;
for (; (i<len(s->members)); i = i+1) {

                        if (s->members->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: s->members[%d] with length %d", i, s->members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/verboseOut.bah:53");
                        };
                        struct variable* m = s->members->data[i];
char * ____BAH_COMPILER_VAR_219 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(ogCont);
long int strLen_6 = strlen(")");
long int strLen_8 = strlen(".");
long int strLen_10 = strlen(m->name);
;                            
                    ____BAH_COMPILER_VAR_219 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_219+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_219+currStrOff, ogCont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_219+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_219+currStrOff, ".", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_219+currStrOff, m->name, strLen_10);
                        currStrOff += strLen_10;
                        
                }
                struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_219,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_220 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ct);
long int strLen_4 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_220 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_220+currStrOff, ct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_220+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ct = ____BAH_COMPILER_VAR_220;
}
char * ____BAH_COMPILER_VAR_221 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ct);
long int strLen_4 = strlen(mv.markup);
;                            
                    ____BAH_COMPILER_VAR_221 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_221+currStrOff, ct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_221+currStrOff, mv.markup, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ct = ____BAH_COMPILER_VAR_221;
char * ____BAH_COMPILER_VAR_222 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(cont);
long int strLen_4 = strlen(mv.content);
;                            
                    ____BAH_COMPILER_VAR_222 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_222+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_222+currStrOff, mv.content, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                cont = ____BAH_COMPILER_VAR_222;
};
char * ____BAH_COMPILER_VAR_223 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ct);
long int strLen_4 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_223 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_223+currStrOff, ct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_223+currStrOff, "}", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ct = ____BAH_COMPILER_VAR_223;
}
}
char * ____BAH_COMPILER_VAR_224 =null;
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
                    ____BAH_COMPILER_VAR_224 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_224+currStrOff, ASCII_BLUE, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_224+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_224+currStrOff, ASCII_RESET, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_224+currStrOff, " = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_224+currStrOff, ASCII_MAGENTA, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_224+currStrOff, ct, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_224+currStrOff, ASCII_RESET, strLen_14);
                        currStrOff += strLen_14;
                        
                }
                rv.markup = ____BAH_COMPILER_VAR_224;
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
struct variable ____BAH_COMPILER_VAR_225 = {};
____BAH_COMPILER_VAR_225.name = "";
____BAH_COMPILER_VAR_225.type = "";
____BAH_COMPILER_VAR_225.isConst = false;
____BAH_COMPILER_VAR_225.constVal = "";
____BAH_COMPILER_VAR_225.isArray = false;
____BAH_COMPILER_VAR_225.from = "";
____BAH_COMPILER_VAR_225.outterScope = false;
____BAH_COMPILER_VAR_225.isGlobal = false;
____BAH_COMPILER_VAR_225.name = "(value)";
____BAH_COMPILER_VAR_225.type = getTypeFromToken(&t,true,elems);
#define v ____BAH_COMPILER_VAR_225
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
char * ____BAH_COMPILER_VAR_226 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnArgs);
long int strLen_4 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_226 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_226+currStrOff, fnArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_226+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fnArgs = ____BAH_COMPILER_VAR_226;
}

                        if (args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: args[%d] with length %d", j, args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/verboseOut.bah:120");
                        };
                        struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_227 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnArgs);
long int strLen_4 = strlen(v.markup);
;                            
                    ____BAH_COMPILER_VAR_227 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_227+currStrOff, fnArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_227+currStrOff, v.markup, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fnArgs = ____BAH_COMPILER_VAR_227;
char * ____BAH_COMPILER_VAR_228 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnArgsValues);
long int strLen_4 = strlen(v.content);
;                            
                    ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, fnArgsValues, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_228+currStrOff, v.content, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fnArgsValues = ____BAH_COMPILER_VAR_228;
};
char * ____BAH_COMPILER_VAR_229 =null;char * ____BAH_COMPILER_VAR_230 =intToStr(lineNb);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_230);
;                            
                    ____BAH_COMPILER_VAR_229 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_229+currStrOff, compilerState.currentFile, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_229+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_229+currStrOff, ____BAH_COMPILER_VAR_230, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * line = ____BAH_COMPILER_VAR_229;
char * ____BAH_COMPILER_VAR_231 =null;
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
                    ____BAH_COMPILER_VAR_231 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24);
                    
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, nameColor, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, fn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, ASCII_RESET, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, "(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, fnArgs, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, ") -> ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, ASCII_GREEN, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, line, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, ASCII_RESET, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, "\\n\"", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, fnArgsValues, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_231+currStrOff, ");\n    //\n    ", strLen_24);
                        currStrOff += strLen_24;
                        
                }
                struct rope* verboseOut = rope(____BAH_COMPILER_VAR_231);
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
char * ____BAH_COMPILER_VAR_232 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pvo.content);
long int strLen_4 = strlen(nvo.content);
;                            
                    ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, pvo.content, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_232+currStrOff, nvo.content, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * values = ____BAH_COMPILER_VAR_232;
char * ____BAH_COMPILER_VAR_233 =null;char * ____BAH_COMPILER_VAR_234 =intToStr(lineNb);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_234);
;                            
                    ____BAH_COMPILER_VAR_233 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_233+currStrOff, compilerState.currentFile, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_233+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_233+currStrOff, ____BAH_COMPILER_VAR_234, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * line = ____BAH_COMPILER_VAR_233;
char * ____BAH_COMPILER_VAR_235 =null;
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
                    ____BAH_COMPILER_VAR_235 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20);
                    
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, pvo.markup, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, " AND ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, nvo.markup, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, " -> ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, ASCII_GREEN, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, line, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, ASCII_RESET, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, "\\n\"", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, values, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_235+currStrOff, ");\n    //\n    ", strLen_20);
                        currStrOff += strLen_20;
                        
                }
                struct rope* verboseOut = rope(____BAH_COMPILER_VAR_235);
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
struct fileStream ____BAH_COMPILER_VAR_236 = {};
____BAH_COMPILER_VAR_236.handle= null;
____BAH_COMPILER_VAR_236.name= null;
____BAH_COMPILER_VAR_236.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_236.open = fileStream__open;
____BAH_COMPILER_VAR_236.close = fileStream__close;
____BAH_COMPILER_VAR_236.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_236.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_236.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_236.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_236.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_236.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_236.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_236.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_236.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_236.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_236.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_236.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_236.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_236._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_236
char * ____BAH_COMPILER_VAR_237 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_237 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_237+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_237+currStrOff, "cache/cache.json", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fs.open(&fs,____BAH_COMPILER_VAR_237,"r");
if ((fs.isValid(&fs)==0)) {
char * ____BAH_COMPILER_VAR_238 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_2 = strlen("cache");
;                            
                    ____BAH_COMPILER_VAR_238 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_238+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_238+currStrOff, "cache", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                mkdir(____BAH_COMPILER_VAR_238,S_IRWXU);
char * ____BAH_COMPILER_VAR_239 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_239 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_239+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_239+currStrOff, "cache/cache.json", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fs.createFile(&fs,____BAH_COMPILER_VAR_239);
fs._end(&fs);
return;
}
char * ____BAH_COMPILER_VAR_240 =fs.readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_240);
fs.close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_241 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_242 = 0;
char ** ____BAH_COMPILER_VAR_244 = (char **)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_245 = __reflect(____BAH_COMPILER_VAR_244, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_246 = (long int*)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_247 = __reflect(____BAH_COMPILER_VAR_246, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_248 = (char **)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_249 = __reflect(____BAH_COMPILER_VAR_248, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_250 = (long int*)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_251 = __reflect(____BAH_COMPILER_VAR_250, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_252 = (long int*)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_253 = __reflect(____BAH_COMPILER_VAR_252, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_254 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_242) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_255 = 0;
struct reflectElement ____BAH_COMPILER_VAR_256 = __reflect(____BAH_COMPILER_VAR_255, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_257 = ____BAH_COMPILER_VAR_256;
        struct reflectElement ____BAH_COMPILER_VAR_258 = __reflect(____BAH_COMPILER_VAR_254, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_257, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_243 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_243->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_243->length = 6;
        ____BAH_COMPILER_VAR_243->data = memoryAlloc(____BAH_COMPILER_VAR_243->length * ____BAH_COMPILER_VAR_243->elemSize);
        ____BAH_COMPILER_VAR_243->data[0] = ____BAH_COMPILER_VAR_245;
____BAH_COMPILER_VAR_243->data[1] = ____BAH_COMPILER_VAR_247;
____BAH_COMPILER_VAR_243->data[2] = ____BAH_COMPILER_VAR_249;
____BAH_COMPILER_VAR_243->data[3] = ____BAH_COMPILER_VAR_251;
____BAH_COMPILER_VAR_243->data[4] = ____BAH_COMPILER_VAR_253;
____BAH_COMPILER_VAR_243->data[5] = ____BAH_COMPILER_VAR_258;
struct reflectElement ____BAH_COMPILER_VAR_259 = __reflect(____BAH_COMPILER_VAR_242, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_243, 0);

        struct reflectElement ____BAH_COMPILER_VAR_260 = ____BAH_COMPILER_VAR_259;
        struct reflectElement ____BAH_COMPILER_VAR_261 = __reflect(____BAH_COMPILER_VAR_241, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_260, 0, 0, 0);
j->scan(j,____BAH_COMPILER_VAR_261);
if ((cache!=null)) {
}
fs._end(&fs);
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
struct cacheFile* ____BAH_COMPILER_VAR_262 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_262->file= null;
____BAH_COMPILER_VAR_262->ver= null;
____BAH_COMPILER_VAR_262->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_262->files->length = 0;
            ____BAH_COMPILER_VAR_262->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_262;
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
struct fileStream ____BAH_COMPILER_VAR_263 = {};
____BAH_COMPILER_VAR_263.handle= null;
____BAH_COMPILER_VAR_263.name= null;
____BAH_COMPILER_VAR_263.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_263.open = fileStream__open;
____BAH_COMPILER_VAR_263.close = fileStream__close;
____BAH_COMPILER_VAR_263.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_263.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_263.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_263.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_263.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_263.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_263.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_263.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_263.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_263.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_263.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_263.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_263.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_263._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_263
char * ____BAH_COMPILER_VAR_264 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_264 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_264+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_264+currStrOff, "cache/cache.json", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fs.open(&fs,____BAH_COMPILER_VAR_264,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_265 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_266 = 0;
char ** ____BAH_COMPILER_VAR_268 = (char **)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_269 = __reflect(____BAH_COMPILER_VAR_268, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_270 = (long int*)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_271 = __reflect(____BAH_COMPILER_VAR_270, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_272 = (char **)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_273 = __reflect(____BAH_COMPILER_VAR_272, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_274 = (long int*)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_275 = __reflect(____BAH_COMPILER_VAR_274, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_276 = (long int*)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_277 = __reflect(____BAH_COMPILER_VAR_276, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_278 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_279 = 0;
struct reflectElement ____BAH_COMPILER_VAR_280 = __reflect(____BAH_COMPILER_VAR_279, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_281 = ____BAH_COMPILER_VAR_280;
        struct reflectElement ____BAH_COMPILER_VAR_282 = __reflect(____BAH_COMPILER_VAR_278, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_281, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_267 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_267->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_267->length = 6;
        ____BAH_COMPILER_VAR_267->data = memoryAlloc(____BAH_COMPILER_VAR_267->length * ____BAH_COMPILER_VAR_267->elemSize);
        ____BAH_COMPILER_VAR_267->data[0] = ____BAH_COMPILER_VAR_269;
____BAH_COMPILER_VAR_267->data[1] = ____BAH_COMPILER_VAR_271;
____BAH_COMPILER_VAR_267->data[2] = ____BAH_COMPILER_VAR_273;
____BAH_COMPILER_VAR_267->data[3] = ____BAH_COMPILER_VAR_275;
____BAH_COMPILER_VAR_267->data[4] = ____BAH_COMPILER_VAR_277;
____BAH_COMPILER_VAR_267->data[5] = ____BAH_COMPILER_VAR_282;
struct reflectElement ____BAH_COMPILER_VAR_283 = __reflect(____BAH_COMPILER_VAR_266, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_267, 0);

        struct reflectElement ____BAH_COMPILER_VAR_284 = ____BAH_COMPILER_VAR_283;
        struct reflectElement ____BAH_COMPILER_VAR_285 = __reflect(____BAH_COMPILER_VAR_265, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_284, 0, 0, 0);
char * ____BAH_COMPILER_VAR_286 =toJson(____BAH_COMPILER_VAR_285);fs.writeFile(&fs,____BAH_COMPILER_VAR_286);
fs.close(&fs);
fs._end(&fs);
};
char isValidCacheFile(struct cacheFile* cf){
if (((cf==null)||(cf->last!=getLastModified(cf->file)))) {
return false;
}
char * ____BAH_COMPILER_VAR_287 =null;char * ____BAH_COMPILER_VAR_288 =pathToVarName(cf->file);char * ____BAH_COMPILER_VAR_289 =intToStr(cf->mem);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_2 = strlen("cache/");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_288);
long int strLen_6 = strlen(____BAH_COMPILER_VAR_289);
long int strLen_8 = strlen(".o.o");
;                            
                    ____BAH_COMPILER_VAR_287 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_287+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_287+currStrOff, "cache/", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_287+currStrOff, ____BAH_COMPILER_VAR_288, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_287+currStrOff, ____BAH_COMPILER_VAR_289, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_287+currStrOff, ".o.o", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                if ((fileExists(____BAH_COMPILER_VAR_287)==0)) {
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
char * ____BAH_COMPILER_VAR_290 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(cont);
long int strLen_4 = strlen(" '");
long int strLen_6 = strlen(t.cont);
long int strLen_8 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_290 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_290+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_290+currStrOff, " '", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_290+currStrOff, t.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_290+currStrOff, "'", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                cont = ____BAH_COMPILER_VAR_290;
i = i+1;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_291 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_291->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_291->vars->length = 0;
            ____BAH_COMPILER_VAR_291->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_291->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_291->structs->length = 0;
            ____BAH_COMPILER_VAR_291->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_291->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_291->types->length = 0;
            ____BAH_COMPILER_VAR_291->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_291->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_291->fns->length = 0;
            ____BAH_COMPILER_VAR_291->fns->elemSize = sizeof(struct func*);
            struct Elems* nElems = ____BAH_COMPILER_VAR_291;
long int j = 0;
for (; (j<len(elems->vars)); j = j+1) {

                        if (elems->vars->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->vars[%d] with length %d", j, elems->vars->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:29");
                        };
                        struct variable* v = elems->vars->data[j];
struct variable* ____BAH_COMPILER_VAR_292 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_292->name = "";
____BAH_COMPILER_VAR_292->type = "";
____BAH_COMPILER_VAR_292->isConst = false;
____BAH_COMPILER_VAR_292->constVal = "";
____BAH_COMPILER_VAR_292->isArray = false;
____BAH_COMPILER_VAR_292->from = "";
____BAH_COMPILER_VAR_292->outterScope = false;
____BAH_COMPILER_VAR_292->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_292;
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
char * ____BAH_COMPILER_VAR_293 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(cCastStr);
long int strLen_6 = strlen(")");
long int strLen_8 = strlen(nnnt.cont);
;                            
                    ____BAH_COMPILER_VAR_293 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_293+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_293+currStrOff, cCastStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_293+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_293+currStrOff, nnnt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                nnnt.cont = ____BAH_COMPILER_VAR_293;

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
char * ____BAH_COMPILER_VAR_294 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_294);
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

                int ____BAH_COMPILER_VAR_295 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                        ____BAH_COMPILER_VAR_295 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_295) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_296 = {};
____BAH_COMPILER_VAR_296.handle = -1;
____BAH_COMPILER_VAR_296.p= null;
____BAH_COMPILER_VAR_296.open = fileMap__open;
____BAH_COMPILER_VAR_296.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_296.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_296
char * ____BAH_COMPILER_VAR_297 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen(ccstr);
;                            
                    ____BAH_COMPILER_VAR_297 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_297+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_297+currStrOff, ccstr, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * fileName = ____BAH_COMPILER_VAR_297;
char isBahDir = true;
char * f = fm.open(&fm,fileName);
if ((fm.isValid(&fm)==0)) {
char * ____BAH_COMPILER_VAR_298 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_2 = strlen(ccstr);
;                            
                    ____BAH_COMPILER_VAR_298 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_298+currStrOff, compilerState.currentDir, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_298+currStrOff, ccstr, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fileName = absPath(____BAH_COMPILER_VAR_298);
f = fm.open(&fm,fileName);
isBahDir = false;
if ((fm.isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_299 =null;char * ____BAH_COMPILER_VAR_300 =getDirFromFile(ccstr);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(compilerState.currentDir);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_300);
;                            
                    ____BAH_COMPILER_VAR_299 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_299+currStrOff, compilerState.currentDir, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_299+currStrOff, ____BAH_COMPILER_VAR_300, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                compilerState.currentDir = ____BAH_COMPILER_VAR_299;
}
else {
char * ____BAH_COMPILER_VAR_301 =null;char * ____BAH_COMPILER_VAR_302 =getDirFromFile(ccstr);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_302);
;                            
                    ____BAH_COMPILER_VAR_301 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_301+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_301+currStrOff, ____BAH_COMPILER_VAR_302, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                compilerState.currentDir = ____BAH_COMPILER_VAR_301;
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
char * ____BAH_COMPILER_VAR_303 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("File '");
long int strLen_2 = strlen(ccstr);
long int strLen_4 = strlen("' not recognized.");
;                            
                    ____BAH_COMPILER_VAR_303 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_303+currStrOff, "File '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_303+currStrOff, ccstr, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_303+currStrOff, "' not recognized.", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                __BAH_panic(____BAH_COMPILER_VAR_303,"/home/alois/Documents/bah-bah/src/parser.bah:249");
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
char * ____BAH_COMPILER_VAR_304 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("compilling: ");
long int strLen_2 = strlen(fn);
;                            
                    ____BAH_COMPILER_VAR_304 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_304+currStrOff, "compilling: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_304+currStrOff, fn, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                println(____BAH_COMPILER_VAR_304);
char * ____BAH_COMPILER_VAR_305 =null;
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
                    ____BAH_COMPILER_VAR_305 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_305+currStrOff, execName, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_305+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_305+currStrOff, fn, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_305+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_305+currStrOff, rcp, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_305+currStrOff, " -object ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_305+currStrOff, verboseCC, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_305+currStrOff, " -o ", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_305+currStrOff, oName, strLen_16);
                        currStrOff += strLen_16;
                        
                }
                struct command cmd = command(____BAH_COMPILER_VAR_305);
char * res = cmd.run(&cmd);
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

                    char ____BAH_COMPILER_VAR_306 = true;
                    done->sendAny(done, &____BAH_COMPILER_VAR_306, sizeof(____BAH_COMPILER_VAR_306));
};
void parseImport(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
compilerState.hasImports = true;
if ((len(l)!=2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:312");
                        };
                        struct Tok strt = l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as file name (#import \"file\")");
}
struct string fileName = string(strt.cont);
fileName.trimLeft(&fileName,1);
fileName.trimRight(&fileName,1);

                int ____BAH_COMPILER_VAR_307 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], fileName.str(&fileName)) == 0) {
                        ____BAH_COMPILER_VAR_307 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_307) {
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
char * ____BAH_COMPILER_VAR_308 =fileName.str(&fileName);char * fn = absPath(____BAH_COMPILER_VAR_308);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_309 =null;char * ____BAH_COMPILER_VAR_310 =fileName.str(&fileName);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_310);
;                            
                    ____BAH_COMPILER_VAR_309 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_309+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_309+currStrOff, ____BAH_COMPILER_VAR_310, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fn = absPath(____BAH_COMPILER_VAR_309);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_311 = {};
____BAH_COMPILER_VAR_311.handle= null;
____BAH_COMPILER_VAR_311.name= null;
____BAH_COMPILER_VAR_311.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_311.open = fileStream__open;
____BAH_COMPILER_VAR_311.close = fileStream__close;
____BAH_COMPILER_VAR_311.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_311.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_311.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_311.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_311.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_311.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_311.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_311.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_311.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_311.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_311.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_311.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_311.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_311._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_311
fs.open(&fs,fn,"r");
char * f = fs.readContent(&fs);
fs.close(&fs);
array(struct Tok)* tokens = lexer(f);
char osod = shouldOnlyDecl;
shouldOnlyDecl = true;
char oiso = isSubObject;
isSubObject = true;
char * ____BAH_COMPILER_VAR_312 =null;char * ____BAH_COMPILER_VAR_313 =pathToVarName(fn);char * ____BAH_COMPILER_VAR_314 =intToStr(RCPlevel);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("cache/");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_313);
long int strLen_8 = strlen(____BAH_COMPILER_VAR_314);
long int strLen_10 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_312 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_312+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_312+currStrOff, "cache/", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_312+currStrOff, ____BAH_COMPILER_VAR_313, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_312+currStrOff, ____BAH_COMPILER_VAR_314, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_312+currStrOff, ".o", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * oName = ____BAH_COMPILER_VAR_312;
char * ____BAH_COMPILER_VAR_315 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("w ");
long int strLen_4 = strlen(oName);
long int strLen_6 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_315 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_315+currStrOff, "w ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_315+currStrOff, oName, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_315+currStrOff, ".o", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                
{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_315;
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_315;
}
};
struct channel * done = channel();
parallelObjCompile(fn,oName,done);
parseLines(tokens,elems);
char ok = *(char*)done->receive(done);
char * ____BAH_COMPILER_VAR_316 =null;char * ____BAH_COMPILER_VAR_317 =pathToVarName(fn);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_init");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_317);
long int strLen_4 = strlen("();\n");
;                            
                    ____BAH_COMPILER_VAR_316 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_316+currStrOff, "__BAH_init", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_316+currStrOff, ____BAH_COMPILER_VAR_317, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_316+currStrOff, "();\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_316));
writeCache();
shouldOnlyDecl = osod;
isSubObject = oiso;
compilerState.currentFile = of;
compilerState.currentDir = od;
fs._end(&fs);
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:396");
                        };
                        struct Tok strt = l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
char * sc = strt.cont;
strTrimLeft(&sc,1);
strTrimRight(&sc,1);
if (((strHasPrefix(sc,"<")||strHasSuffix(sc,".h"))||strHasSuffix(sc,".c"))) {
char * ____BAH_COMPILER_VAR_318 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#include ");
long int strLen_2 = strlen(sc);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_318 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_318+currStrOff, "#include ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_318+currStrOff, sc, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_318+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_318));

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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:419");
                        };
                        array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = line->data[0];

                        if (line->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", 0, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:420");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:423");
                        };
                        struct Tok t = line->data[i];

                        if (line->length <= i-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i-1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:424");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:432");
                        };
                        t = line->data[i];

                        if (line->length <= i-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i-1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:433");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:452");
                        };
                        struct Tok nestedT = tmpL->data[0];
char * ____BAH_COMPILER_VAR_319 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(nestedT.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_319 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_319+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_319+currStrOff, nestedT.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_319+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                nestedT.cont = ____BAH_COMPILER_VAR_319;

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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:462");
                        };
                        struct Tok t = line->data[i];

                int ____BAH_COMPILER_VAR_320 = 0;
                for(int i=len(signs)-1; i != -1; i--) {
                    if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_320 = 1;
                        break;
                    };
                };
                if (((t.type==TOKEN_TYPE_SYNTAX)&&____BAH_COMPILER_VAR_320)) {
if ((i+1>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:468");
                        };
                        struct Tok pt = nl->data[len(nl)-1];

                        if (line->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:469");
                        };
                        struct Tok nt = line->data[i+1];
if ((((strcmp(t.cont, "-") == 0)&&(pt.isValue==false))&&(nt.type==TOKEN_TYPE_INT))) {
char * ____BAH_COMPILER_VAR_321 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(t.cont);
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_321 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_321+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_321+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                nt.cont = ____BAH_COMPILER_VAR_321;

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
char * ____BAH_COMPILER_VAR_322 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(t.cont);
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_322 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_322+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_322+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * c = ____BAH_COMPILER_VAR_322;
long int tl = t.line;
long int tp = t.pos;
struct Tok ____BAH_COMPILER_VAR_323 = {};
____BAH_COMPILER_VAR_323.cont = "";
____BAH_COMPILER_VAR_323.ogCont = "";
____BAH_COMPILER_VAR_323.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_323.pos = 0;
____BAH_COMPILER_VAR_323.line = 1;
____BAH_COMPILER_VAR_323.begLine = 1;
____BAH_COMPILER_VAR_323.bahType = "";
____BAH_COMPILER_VAR_323.isValue = false;
____BAH_COMPILER_VAR_323.isFunc = false;
____BAH_COMPILER_VAR_323.isOper = false;
____BAH_COMPILER_VAR_323.isEqual = false;
____BAH_COMPILER_VAR_323.cont = c;
____BAH_COMPILER_VAR_323.ogCont = c;
____BAH_COMPILER_VAR_323.isValue = false;
____BAH_COMPILER_VAR_323.line = tl;
____BAH_COMPILER_VAR_323.pos = tp;
____BAH_COMPILER_VAR_323.type = TOKEN_TYPE_SYNTAX;
#define tmpT ____BAH_COMPILER_VAR_323

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
char * ____BAH_COMPILER_VAR_324 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(ptt);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_324 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_324+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_324+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_324+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_324+currStrOff, ptt, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_324+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&nt,____BAH_COMPILER_VAR_324);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:528");
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
char * ____BAH_COMPILER_VAR_325 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(ptt);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_325 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, ptt, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_325+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&strAddTkT,____BAH_COMPILER_VAR_325);
break;
}
char * cont = strAddTk.cont;
if ((((strAddTk.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(strAddTk.cont,"noCheck(")==false))&&(isRCPtype(strAddTkT,elems)==true))) {
cont = registerRCPvar(strAddTkT,strAddTk.cont,elems);
}
char * js = intToStr(j);
char * ____BAH_COMPILER_VAR_326 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(lens);
long int strLen_4 = strlen("long int strLen_");
long int strLen_6 = strlen(js);
long int strLen_8 = strlen(" = strlen(");
long int strLen_10 = strlen(cont);
long int strLen_12 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_326 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, lens, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, "long int strLen_", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, js, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, " = strlen(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_326+currStrOff, ");\n", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                lens = ____BAH_COMPILER_VAR_326;
char * ____BAH_COMPILER_VAR_327 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(totStrLen);
long int strLen_4 = strlen(" + strLen_");
long int strLen_6 = strlen(js);
;                            
                    ____BAH_COMPILER_VAR_327 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, totStrLen, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, " + strLen_", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_327+currStrOff, js, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                totStrLen = ____BAH_COMPILER_VAR_327;
char * ____BAH_COMPILER_VAR_328 =null;
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
                    ____BAH_COMPILER_VAR_328 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, "\n                        memcpy(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, rstr, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, "+currStrOff, ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, ", strLen_", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, js, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, ");\n                        currStrOff += strLen_", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, js, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_328+currStrOff, ";\n                        ", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                cats = cats->add(cats, rope(____BAH_COMPILER_VAR_328));
wasAdd = false;
}
};
i = j;
char * ____BAH_COMPILER_VAR_329 =null;
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
                    ____BAH_COMPILER_VAR_329 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, "\n                {\n                    long int currStrOff = 0;\n                    ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, lens, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, ";                            \n                    ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, rstr, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, " = memoryAllocSTR(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, totStrLen, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_329+currStrOff, ");\n                    ", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                struct rope* res = rope(____BAH_COMPILER_VAR_329)->add(rope(____BAH_COMPILER_VAR_329), cats)->add(rope(____BAH_COMPILER_VAR_329)->add(rope(____BAH_COMPILER_VAR_329), cats), rope("\n                }\n                "));
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
char * ____BAH_COMPILER_VAR_330 =null;
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
                    ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_330+currStrOff, "add(", strLen_6);
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
else if ((strcmp(t.cont, "-") == 0)) {
struct structMemb* subMthd = searchStructMemb("sub",s,elems);
if (((subMthd!=null)&&(subMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_331 =null;
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
                    ____BAH_COMPILER_VAR_331 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, "sub(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, amp, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, pt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, nt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_331+currStrOff, ")", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_331;
}
}
else if ((strcmp(t.cont, "*") == 0)) {
struct structMemb* multMthd = searchStructMemb("mult",s,elems);
if (((multMthd!=null)&&(multMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_332 =null;
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
                    ____BAH_COMPILER_VAR_332 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, "mult(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, amp, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, pt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, nt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_332+currStrOff, ")", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_332;
}
}
else if ((strcmp(t.cont, "/") == 0)) {
struct structMemb* divMthd = searchStructMemb("div",s,elems);
if (((divMthd!=null)&&(divMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_333 =null;
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
                    ____BAH_COMPILER_VAR_333 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, "div(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, amp, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, pt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, nt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_333+currStrOff, ")", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_333;
}
}
else {
char * ____BAH_COMPILER_VAR_334 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Undefined operation on {TOKEN} (");
long int strLen_4 = strlen(ptt);
long int strLen_6 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_334 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_334+currStrOff, "Undefined operation on {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_334+currStrOff, ptt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_334+currStrOff, ").", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&pt,____BAH_COMPILER_VAR_334);
}
}
else {
char * ____BAH_COMPILER_VAR_335 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(t.cont);
long int strLen_6 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_335 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_335+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_335+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_335+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_335;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:641");
                        };
                        struct Tok pt = nl->data[len(nl)-1];
if ((pt.isValue==true)) {
char * ptt = getTypeFromToken(&pt,true,elems);
char * ntt = getTypeFromToken(&t,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_336 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(ptt);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_336 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_336+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_336+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_336+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_336+currStrOff, ptt, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_336+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_336);
}
t.type = TOKEN_TYPE_VAR;
t.isOper = true;
char * ____BAH_COMPILER_VAR_337 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_337 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_337+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_337+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_337;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:678");
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
struct Tok ____BAH_COMPILER_VAR_338 = {};
____BAH_COMPILER_VAR_338.cont = "";
____BAH_COMPILER_VAR_338.ogCont = "";
____BAH_COMPILER_VAR_338.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_338.pos = 0;
____BAH_COMPILER_VAR_338.line = 1;
____BAH_COMPILER_VAR_338.begLine = 1;
____BAH_COMPILER_VAR_338.bahType = "";
____BAH_COMPILER_VAR_338.isValue = false;
____BAH_COMPILER_VAR_338.isFunc = false;
____BAH_COMPILER_VAR_338.isOper = false;
____BAH_COMPILER_VAR_338.isEqual = false;
____BAH_COMPILER_VAR_338.cont = "";
#define nt ____BAH_COMPILER_VAR_338
if ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:691");
                        };
                        nt = line->data[i];
}
if (((i==len(line))||(strcmp(nt.cont, "{") != 0))) {
if ((i-2>=0)) {

                        if (line->length <= i-2) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i-2, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:695");
                        };
                        struct Tok newTk = line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
struct cStruct* s = searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Cannot initialize new unknown struct {TOKEN}.");
}
t.cont = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_339 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_339->name = "";
____BAH_COMPILER_VAR_339->type = "";
____BAH_COMPILER_VAR_339->isConst = false;
____BAH_COMPILER_VAR_339->constVal = "";
____BAH_COMPILER_VAR_339->isArray = false;
____BAH_COMPILER_VAR_339->from = "";
____BAH_COMPILER_VAR_339->outterScope = false;
____BAH_COMPILER_VAR_339->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_339;
tmpV->name = t.cont;
char * ____BAH_COMPILER_VAR_340 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s->name);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_340 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_340+currStrOff, s->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_340+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpV->type = ____BAH_COMPILER_VAR_340;
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
char * ____BAH_COMPILER_VAR_341 =null;char * ____BAH_COMPILER_VAR_342 =cType.str(&cType);char * ____BAH_COMPILER_VAR_343 =structType.str(&structType);char * ____BAH_COMPILER_VAR_344 =declareStructMethods(tmpV,s,elems);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_342);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(t.cont);
long int strLen_6 = strlen(" = memoryAlloc(sizeof(");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_343);
long int strLen_10 = strlen("));\n");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_344);
;                            
                    ____BAH_COMPILER_VAR_341 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_341+currStrOff, ____BAH_COMPILER_VAR_342, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_341+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_341+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_341+currStrOff, " = memoryAlloc(sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_341+currStrOff, ____BAH_COMPILER_VAR_343, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_341+currStrOff, "));\n", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_341+currStrOff, ____BAH_COMPILER_VAR_344, strLen_12);
                        currStrOff += strLen_12;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_341));

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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:719");
                        };
                        nt = line->data[i];
if ((strcmp(nt.cont, "{") == 0)) {
char isHeap = false;
char * sep = ".";
if ((i-2>=0)) {

                        if (line->length <= i-2) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i-2, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:724");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:739");
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
struct variable* ____BAH_COMPILER_VAR_345 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_345->name = "";
____BAH_COMPILER_VAR_345->type = "";
____BAH_COMPILER_VAR_345->isConst = false;
____BAH_COMPILER_VAR_345->constVal = "";
____BAH_COMPILER_VAR_345->isArray = false;
____BAH_COMPILER_VAR_345->from = "";
____BAH_COMPILER_VAR_345->outterScope = false;
____BAH_COMPILER_VAR_345->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_345;
tmpV->name = rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_346 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s->name);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_346 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_346+currStrOff, s->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_346+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpV->type = ____BAH_COMPILER_VAR_346;

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
char * ____BAH_COMPILER_VAR_347 =rst.str(&rst);struct string structType = string(____BAH_COMPILER_VAR_347);
structType.trimRight(&structType,1);
char * ____BAH_COMPILER_VAR_348 =null;char * ____BAH_COMPILER_VAR_349 =rst.str(&rst);char * ____BAH_COMPILER_VAR_350 =structType.str(&structType);char * ____BAH_COMPILER_VAR_351 =declareStructMethods(tmpV,s,elems);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_349);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(rvn);
long int strLen_6 = strlen(" = memoryAlloc(sizeof(");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_350);
long int strLen_10 = strlen("));\n");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_351);
;                            
                    ____BAH_COMPILER_VAR_348 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_348+currStrOff, ____BAH_COMPILER_VAR_349, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_348+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_348+currStrOff, rvn, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_348+currStrOff, " = memoryAlloc(sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_348+currStrOff, ____BAH_COMPILER_VAR_350, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_348+currStrOff, "));\n", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_348+currStrOff, ____BAH_COMPILER_VAR_351, strLen_12);
                        currStrOff += strLen_12;
                        
                }
                r = rope(____BAH_COMPILER_VAR_348);
}
else {
char * ____BAH_COMPILER_VAR_352 =null;char * ____BAH_COMPILER_VAR_353 =rst.str(&rst);char * ____BAH_COMPILER_VAR_354 =declareStructMethods(tmpV,s,elems);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_353);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(rvn);
long int strLen_6 = strlen(" = {};\n");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_354);
;                            
                    ____BAH_COMPILER_VAR_352 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_352+currStrOff, ____BAH_COMPILER_VAR_353, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_352+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_352+currStrOff, rvn, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_352+currStrOff, " = {};\n", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_352+currStrOff, ____BAH_COMPILER_VAR_354, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                r = rope(____BAH_COMPILER_VAR_352);
}
long int j = 0;
long int k = 0;
while ((k<len(memory))) {

                        if (memory->length <= k) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", k, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:780");
                        };
                        t = memory->data[k];
if ((k+2<len(memory))) {

                        if (memory->length <= k+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", k+1, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:783");
                        };
                        struct Tok st = memory->data[k+1];

                        if (memory->length <= k+2) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", k+2, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:784");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:794");
                        };
                        struct structMemb* m = s->members->data[j];
if ((strcmp(m->name, t.cont) != 0)) {
j = j+1;
continue;
}
char * vlt = getTypeFromToken(&vl,true,elems);
if ((compTypes(vlt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_355 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(vlt);
long int strLen_6 = strlen(") as '");
long int strLen_8 = strlen(m->type);
long int strLen_10 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_355 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_355+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_355+currStrOff, vlt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_355+currStrOff, ") as '", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_355+currStrOff, m->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_355+currStrOff, "'.", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&vl,____BAH_COMPILER_VAR_355);
}
char * ____BAH_COMPILER_VAR_356 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(rvn);
long int strLen_2 = strlen(sep);
long int strLen_4 = strlen(m->name);
long int strLen_6 = strlen(" = ");
long int strLen_8 = strlen(vl.cont);
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
                        
                        memcpy(____BAH_COMPILER_VAR_356+currStrOff, vl.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_356+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_356));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_357 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Struct '");
long int strLen_4 = strlen(s->name);
long int strLen_6 = strlen("' has no member called {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_357 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_357+currStrOff, "Struct '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_357+currStrOff, s->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_357+currStrOff, "' has no member called {TOKEN}.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_357);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:821");
                        };
                        struct structMemb* m = s->members->data[j];
j = j+1;
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_358 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as '");
long int strLen_8 = strlen(m->type);
long int strLen_10 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_358 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_358+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_358+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_358+currStrOff, ") as '", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_358+currStrOff, m->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_358+currStrOff, "'.", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_358);
}
char * ____BAH_COMPILER_VAR_359 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(rvn);
long int strLen_2 = strlen(sep);
long int strLen_4 = strlen(m->name);
long int strLen_6 = strlen(" = ");
long int strLen_8 = strlen(t.cont);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_359 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_359+currStrOff, rvn, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_359+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_359+currStrOff, m->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_359+currStrOff, " = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_359+currStrOff, t.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_359+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                r = r->add(r, rope(____BAH_COMPILER_VAR_359));
if ((k+1<len(memory))) {
k = k+1;

                        if (memory->length <= k) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", k, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:833");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:879");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:892");
                        };
                        struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i = i+1;
while ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:896");
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
char * ____BAH_COMPILER_VAR_360 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(v->type);
long int strLen_6 = strlen(") as a structure.");
;                            
                    ____BAH_COMPILER_VAR_360 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_360+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_360+currStrOff, v->type, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_360+currStrOff, ") as a structure.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_360);
}
i = i+1;

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:913");
                        };
                        struct Tok nt = line->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as struct member name.");
}
struct structMemb* memb = searchStructMemb(nt.cont,s,elems);
if ((memb==null)) {
throwErr(&nt,"Unknown struct member {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_361 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(t.cont);
long int strLen_4 = strlen(sep);
long int strLen_6 = strlen(memb->name);
;                            
                    ____BAH_COMPILER_VAR_361 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_361+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_361+currStrOff, sep, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_361+currStrOff, memb->name, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_361;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:943");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:955");
                        };
                        struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
i = i+1;
if ((i<len(line))) {

                        if (line->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:959");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:965");
                        };
                        t = line->data[i];

                        if (line->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:966");
                        };
                        struct Tok nt = line->data[i+1];
if (((strcmp(t.cont, "[") == 0)&&(strcmp(nt.cont, "]") == 0))) {
depth = depth+1;
char * ____BAH_COMPILER_VAR_362 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(bracks);
long int strLen_4 = strlen("[]");
;                            
                    ____BAH_COMPILER_VAR_362 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_362+currStrOff, bracks, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_362+currStrOff, "[]", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                bracks = ____BAH_COMPILER_VAR_362;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:976");
                        };
                        t = line->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem = t.cont;
char * ____BAH_COMPILER_VAR_363 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(bracks);
long int strLen_4 = strlen(arrElem);
;                            
                    ____BAH_COMPILER_VAR_363 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_363+currStrOff, bracks, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_363+currStrOff, arrElem, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                t.bahType = ____BAH_COMPILER_VAR_363;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1008");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1021");
                        };
                        struct Tok t = line->data[i];
if (inArrayStr(t.cont,comparators)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1027");
                        };
                        struct Tok pt = nl->data[len(nl)-1];
long int max = i+1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (line->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1032");
                        };
                        struct Tok nt = line->data[i+1];
char * ptt = getTypeFromToken(&pt,true,elems);
char * ntt = getTypeFromToken(&nt,true,elems);
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT = string(ntt);
if ((arrT.hasPrefix(&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_364 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") as an array.");
;                            
                    ____BAH_COMPILER_VAR_364 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_364+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_364+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_364+currStrOff, ") as an array.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&nt,____BAH_COMPILER_VAR_364);
}
arrT.trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_365 =arrT.str(&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_365)==false)) {
char * ____BAH_COMPILER_VAR_366 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot search for {TOKEN} (");
long int strLen_4 = strlen(ptt);
long int strLen_6 = strlen(") inside array of type ");
long int strLen_8 = strlen(ntt);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_366 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, "Cannot search for {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, ptt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, ") inside array of type ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, ntt, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_366+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&pt,____BAH_COMPILER_VAR_366);
}
char * compVar = genCompilerVar();
char * comp = "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_367 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nt.cont);
long int strLen_4 = strlen("->data[i] != 0 && strcmp(");
long int strLen_6 = strlen(nt.cont);
long int strLen_8 = strlen("->data[i], ");
long int strLen_10 = strlen(pt.cont);
long int strLen_12 = strlen(") == 0");
;                            
                    ____BAH_COMPILER_VAR_367 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, nt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, "->data[i] != 0 && strcmp(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, "->data[i], ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, pt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_367+currStrOff, ") == 0", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                comp = ____BAH_COMPILER_VAR_367;
}
else {
char * ____BAH_COMPILER_VAR_368 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nt.cont);
long int strLen_4 = strlen("->data[i] == ");
long int strLen_6 = strlen(pt.cont);
;                            
                    ____BAH_COMPILER_VAR_368 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_368+currStrOff, nt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_368+currStrOff, "->data[i] == ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_368+currStrOff, pt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                comp = ____BAH_COMPILER_VAR_368;
}
char * ____BAH_COMPILER_VAR_369 =null;
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
                    ____BAH_COMPILER_VAR_369 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, "\n                int ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, compVar, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, " = 0;\n                for(int i=len(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, ")-1; i != -1; i--) {\n                    if (", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, comp, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, ") {\n                        ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, compVar, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_369+currStrOff, " = 1;\n                        break;\n                    };\n                };\n                ", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_369));
pt.cont = compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_370 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot compare {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") to ");
long int strLen_8 = strlen(ptt);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_370+currStrOff, "Cannot compare {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_370+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_370+currStrOff, ") to ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_370+currStrOff, ptt, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_370+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&nt,____BAH_COMPILER_VAR_370);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_371 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strcmp(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen(") == 0)");
;                            
                    ____BAH_COMPILER_VAR_371 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_371+currStrOff, "(strcmp(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_371+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_371+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_371+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_371+currStrOff, ") == 0)", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_371;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_372 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strcmp(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen(") != 0)");
;                            
                    ____BAH_COMPILER_VAR_372 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_372+currStrOff, "(strcmp(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_372+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_372+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_372+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_372+currStrOff, ") != 0)", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_372;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_373 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strlen(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(") > srtlen(");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_373 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_373+currStrOff, "(strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_373+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_373+currStrOff, ") > srtlen(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_373+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_373+currStrOff, "))", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_373;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_374 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strlen(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(") < srtlen(");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_374 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_374+currStrOff, "(strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_374+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_374+currStrOff, ") < srtlen(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_374+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_374+currStrOff, "))", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_374;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_375 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strlen(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(") >= srtlen(");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_375 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_375+currStrOff, "(strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_375+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_375+currStrOff, ") >= srtlen(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_375+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_375+currStrOff, "))", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_375;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_376 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(strlen(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(") <= srtlen(");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_376 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_376+currStrOff, "(strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_376+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_376+currStrOff, ") <= srtlen(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_376+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_376+currStrOff, "))", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_376;
}
}
else {
char * ____BAH_COMPILER_VAR_377 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(t.cont);
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_377 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_377+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_377+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_377+currStrOff, t.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_377+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_377+currStrOff, ")", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_377;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1108");
                        };
                        struct Tok t = line->data[i];
if (inArrayStr(t.cont,compSep)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1113");
                        };
                        struct Tok pt = nl->data[len(nl)-1];
long int max = i+1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (line->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", i+1, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1118");
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
char * ____BAH_COMPILER_VAR_378 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(t.cont);
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_378 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_378+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_378+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_378+currStrOff, t.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_378+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_378+currStrOff, ")", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_378;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1154");
                        };
                        struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i>0)) {

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1159");
                        };
                        struct Tok pt = nl->data[len(nl)-1];
if ((pt.type==TOKEN_TYPE_VAR)) {
if ((i+1<len(l))) {

                        if (l->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i+1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1162");
                        };
                        struct Tok nt = l->data[i+1];
if ((nt.isValue==false)) {
char * ____BAH_COMPILER_VAR_379 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_379 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_379+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_379+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_379;

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
char * ____BAH_COMPILER_VAR_380 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(pt.cont);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_380 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_380+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_380+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                pt.cont = ____BAH_COMPILER_VAR_380;

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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1181");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1190");
                        };
                        struct Tok nt = l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_381 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(t.cont);
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_381 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_381+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_381+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                nt.cont = ____BAH_COMPILER_VAR_381;

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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1217");
                        };
                        struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i = i+1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1221");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1235");
                        };
                        struct Tok ft = l->data[0];
long int i = 0;
for (; (i<len(l)); i = i+1) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1238");
                        };
                        struct Tok t = l->data[i];
if ((strcmp(t.cont, "[") == 0)) {
long int ti = i-1;

                        if (nl->length <= len(nl)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: nl[%d] with length %d", len(nl)-1, nl->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1242");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1254");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1275");
                        };
                        struct Tok mt = memory->data[j];
if ((strcmp(mt.cont, ":") == 0)) {
sepPos = j;
split = true;
}
char * ____BAH_COMPILER_VAR_382 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(cont);
long int strLen_4 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_382 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_382+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_382+currStrOff, mt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                cont = ____BAH_COMPILER_VAR_382;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1289");
                        };
                        struct Tok mt = memory->data[j];
char * ____BAH_COMPILER_VAR_383 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(from);
long int strLen_2 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_383 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_383+currStrOff, from, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_383+currStrOff, mt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                from = ____BAH_COMPILER_VAR_383;
};
}
if ((sepPos==len(memory)-1)) {
char * ____BAH_COMPILER_VAR_384 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("strlen(");
long int strLen_4 = strlen(lt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_384 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_384+currStrOff, "strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_384+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_384+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                to = ____BAH_COMPILER_VAR_384;
}
else {
j = sepPos+1;
for (; (j<len(memory)); j = j+1) {

                        if (memory->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", j, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1297");
                        };
                        struct Tok mt = memory->data[j];
char * ____BAH_COMPILER_VAR_385 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(to);
long int strLen_2 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_385 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_385+currStrOff, to, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_385+currStrOff, mt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                to = ____BAH_COMPILER_VAR_385;
};
}
}
if ((strcmp(tt, "cpstring") == 0)) {
if ((split==false)) {
char * ____BAH_COMPILER_VAR_386 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("cpstringCharAt(");
long int strLen_4 = strlen(lt.cont);
long int strLen_6 = strlen(",");
long int strLen_8 = strlen(cont);
long int strLen_10 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_386 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_386+currStrOff, "cpstringCharAt(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_386+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_386+currStrOff, ",", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_386+currStrOff, cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_386+currStrOff, ")", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_386;
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
char * ____BAH_COMPILER_VAR_387 =null;
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
                    ____BAH_COMPILER_VAR_387 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_387+currStrOff, "cpstringSubsitute(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_387+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_387+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_387+currStrOff, from, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_387+currStrOff, ", ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_387+currStrOff, to, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_387+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_387;
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
struct variable* ____BAH_COMPILER_VAR_388 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_388->name = "";
____BAH_COMPILER_VAR_388->type = "";
____BAH_COMPILER_VAR_388->isConst = false;
____BAH_COMPILER_VAR_388->constVal = "";
____BAH_COMPILER_VAR_388->isArray = false;
____BAH_COMPILER_VAR_388->from = "";
____BAH_COMPILER_VAR_388->outterScope = false;
____BAH_COMPILER_VAR_388->isGlobal = false;
____BAH_COMPILER_VAR_388->name = genCompilerVar();
____BAH_COMPILER_VAR_388->type = tt;
struct variable* tmpV = ____BAH_COMPILER_VAR_388;

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
char * ____BAH_COMPILER_VAR_389 =null;char * ____BAH_COMPILER_VAR_390 =elemType.str(&elemType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_390);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(tmpV->name);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_389 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_389+currStrOff, ____BAH_COMPILER_VAR_390, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_389+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_389+currStrOff, tmpV->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_389+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_389));
}
else {
char * ____BAH_COMPILER_VAR_391 =null;char * ____BAH_COMPILER_VAR_392 =elemType.str(&elemType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_392);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(tmpV->name);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_391 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, ____BAH_COMPILER_VAR_392, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, tmpV->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_391+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_391));
}
if (isRCPpointerType(tt)) {
char * ____BAH_COMPILER_VAR_393 =null;
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
                    ____BAH_COMPILER_VAR_393 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, "->set(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, lt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, ", ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, tmpV->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_393+currStrOff, ");\n", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_393;
}
else {
char * ____BAH_COMPILER_VAR_394 =null;
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
                    ____BAH_COMPILER_VAR_394 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20);
                    
                        memcpy(____BAH_COMPILER_VAR_394+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_394+currStrOff, "->setAny(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_394+currStrOff, lt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_394+currStrOff, ", ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_394+currStrOff, cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_394+currStrOff, ", &", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_394+currStrOff, tmpV->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_394+currStrOff, ", sizeof(", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_394+currStrOff, tmpV->name, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_394+currStrOff, "));\n", strLen_20);
                        currStrOff += strLen_20;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_394;
}
lt.cont = tmpV->name;
}
else {
if (isRCPpointerType(tt)) {
char * ____BAH_COMPILER_VAR_395 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(lt.cont);
long int strLen_4 = strlen("->get(");
long int strLen_6 = strlen(lt.cont);
long int strLen_8 = strlen(", ");
long int strLen_10 = strlen(cont);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_395 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_395+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_395+currStrOff, "->get(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_395+currStrOff, lt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_395+currStrOff, ", ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_395+currStrOff, cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_395+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_395;
}
else {
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_396 =null;char * ____BAH_COMPILER_VAR_397 =elemType.str(&elemType);char * ____BAH_COMPILER_VAR_398 =intToStr(lt.line);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_397);
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
long int strLen_28 = strlen(____BAH_COMPILER_VAR_398);
long int strLen_30 = strlen("): ");
long int strLen_32 = strlen(lt.cont);
long int strLen_34 = strlen("[\\\"%s\\\"] does not exist\\n\", ");
long int strLen_36 = strlen(cont);
long int strLen_38 = strlen(");\n                            exit(1);\n                        };");
;                            
                    ____BAH_COMPILER_VAR_396 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34 + strLen_36 + strLen_38);
                    
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, ____BAH_COMPILER_VAR_397, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, "* ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, tmpV, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, " = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, lt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, "->get(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, lt.cont, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, ", ", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, cont, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, ");\n                        if(", strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, tmpV, strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, " == null) {\n                            printf(\"map (", strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, compilerState.currentFile, strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, ":", strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, ____BAH_COMPILER_VAR_398, strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, "): ", strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, lt.cont, strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, "[\\\"%s\\\"] does not exist\\n\", ", strLen_34);
                        currStrOff += strLen_34;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, cont, strLen_36);
                        currStrOff += strLen_36;
                        
                        memcpy(____BAH_COMPILER_VAR_396+currStrOff, ");\n                            exit(1);\n                        };", strLen_38);
                        currStrOff += strLen_38;
                        
                }
                struct rope* res = rope(____BAH_COMPILER_VAR_396);
char * ____BAH_COMPILER_VAR_399 =null;char * ____BAH_COMPILER_VAR_400 =elemType.str(&elemType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_400);
long int strLen_6 = strlen(")(*");
long int strLen_8 = strlen(tmpV);
long int strLen_10 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_399 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_399+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_399+currStrOff, ____BAH_COMPILER_VAR_400, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_399+currStrOff, ")(*", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_399+currStrOff, tmpV, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_399+currStrOff, ")", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_399;
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
char * ____BAH_COMPILER_VAR_401 =null;char * ____BAH_COMPILER_VAR_402 =intToStr(lt.line);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                        if (");
long int strLen_2 = strlen(cont);
long int strLen_4 = strlen(" >= ");
long int strLen_6 = strlen(amm);
long int strLen_8 = strlen(") {\n                            printf(\"buffer (");
long int strLen_10 = strlen(compilerState.currentFile);
long int strLen_12 = strlen(":");
long int strLen_14 = strlen(____BAH_COMPILER_VAR_402);
long int strLen_16 = strlen("): ");
long int strLen_18 = strlen(lt.cont);
long int strLen_20 = strlen("[%d] with length %d\\n\", ");
long int strLen_22 = strlen(cont);
long int strLen_24 = strlen(", ");
long int strLen_26 = strlen(amm);
long int strLen_28 = strlen(");\n                            exit(1);\n                        };\n                        ");
;                            
                    ____BAH_COMPILER_VAR_401 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, "\n                        if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, " >= ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, amm, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, ") {\n                            printf(\"buffer (", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, compilerState.currentFile, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, ":", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, ____BAH_COMPILER_VAR_402, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, "): ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, lt.cont, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, "[%d] with length %d\\n\", ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, cont, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, ", ", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, amm, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_401+currStrOff, ");\n                            exit(1);\n                        };\n                        ", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_401));
}
char * ____BAH_COMPILER_VAR_403 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(lt.cont);
long int strLen_4 = strlen("[");
long int strLen_6 = strlen(cont);
long int strLen_8 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_403 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, "[", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_403+currStrOff, "]", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_403;
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
char * ____BAH_COMPILER_VAR_404 =null;
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
                    ____BAH_COMPILER_VAR_404 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_404+currStrOff, "cpstringSubsitute(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_404+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_404+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_404+currStrOff, from, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_404+currStrOff, ", ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_404+currStrOff, to, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_404+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_404;
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
char * ____BAH_COMPILER_VAR_405 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as an array.");
;                            
                    ____BAH_COMPILER_VAR_405 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_405+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_405+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_405+currStrOff, ") as an array.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&lt,____BAH_COMPILER_VAR_405);
}
strTrimLeft(&tt,2);
if ((split==false)) {
if (((ti>0)&&(strcmp(ft.cont, "else") != 0))) {
if ((isUnsafe==false)) {
char * ____BAH_COMPILER_VAR_406 =null;char * ____BAH_COMPILER_VAR_407 =intToStr(lt.line);
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
long int strLen_26 = strlen(____BAH_COMPILER_VAR_407);
long int strLen_28 = strlen("\");\n                        };\n                        ");
;                            
                    ____BAH_COMPILER_VAR_406 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, "\n                        if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, "->length <= ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, ") {\n                            char buff[300];\n                            snprintf(buff, 299, \"array: ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, lt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, "[%d] with length %d\", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, ", ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, lt.cont, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, "->length);\n                            __BAH_panic((char*)buff, (char*)\"", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, compilerState.currentFile, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, ":", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, ____BAH_COMPILER_VAR_407, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_406+currStrOff, "\");\n                        };\n                        ", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_406));
}
}
char * ____BAH_COMPILER_VAR_408 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(lt.cont);
long int strLen_4 = strlen("->data[");
long int strLen_6 = strlen(cont);
long int strLen_8 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_408 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_408+currStrOff, lt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_408+currStrOff, "->data[", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_408+currStrOff, cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_408+currStrOff, "]", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_408;
lt.bahType = tt;
}
else {
char * ____BAH_COMPILER_VAR_409 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("[]");
long int strLen_4 = strlen(tt);
;                            
                    ____BAH_COMPILER_VAR_409 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_409+currStrOff, "[]", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_409+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                lt.bahType = ____BAH_COMPILER_VAR_409;
char * ____BAH_COMPILER_VAR_410 =null;
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
                    ____BAH_COMPILER_VAR_410 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_410+currStrOff, "arraySubstitute(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_410+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_410+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_410+currStrOff, from, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_410+currStrOff, ", ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_410+currStrOff, to, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_410+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                lt.cont = ____BAH_COMPILER_VAR_410;
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
char * ____BAH_COMPILER_VAR_411 =null;char * ____BAH_COMPILER_VAR_412 =svt.str(&svt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__serialize(&");
long int strLen_4 = strlen(e.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen("sizeof(struct ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_412);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_411 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, "__serialize(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, e.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, "sizeof(struct ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, ____BAH_COMPILER_VAR_412, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_411+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                code = ____BAH_COMPILER_VAR_411;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_413 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ptrRect);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_413 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_413+currStrOff, ptrRect, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_413+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ptrRect = ____BAH_COMPILER_VAR_413;
ptrLevel = ptrLevel-1;
};
char * ____BAH_COMPILER_VAR_414 =null;char * ____BAH_COMPILER_VAR_415 =svt.str(&svt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__serialize(");
long int strLen_4 = strlen(ptrRect);
long int strLen_6 = strlen(e.cont);
long int strLen_8 = strlen(", ");
long int strLen_10 = strlen("sizeof(struct ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_415);
long int strLen_14 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_414 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_414+currStrOff, "__serialize(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_414+currStrOff, ptrRect, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_414+currStrOff, e.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_414+currStrOff, ", ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_414+currStrOff, "sizeof(struct ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_414+currStrOff, ____BAH_COMPILER_VAR_415, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_414+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                code = ____BAH_COMPILER_VAR_414;
long int i = 0;
while ((i<len(s->members))) {

                        if (s->members->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: s->members[%d] with length %d", i, s->members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1450");
                        };
                        struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_416 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen("+strlen(");
long int strLen_6 = strlen(e.cont);
long int strLen_8 = strlen("->");
long int strLen_10 = strlen(m->name);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_416 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_416+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_416+currStrOff, "+strlen(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_416+currStrOff, e.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_416+currStrOff, "->", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_416+currStrOff, m->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_416+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                code = ____BAH_COMPILER_VAR_416;
}
i = i+1;
};
}
char * ____BAH_COMPILER_VAR_417 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_1 = strlen(code);
long int strLen_3 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_417 = memoryAllocSTR(1 + strLen_1 + strLen_3);
                    
                        memcpy(____BAH_COMPILER_VAR_417+currStrOff, code, strLen_1);
                        currStrOff += strLen_1;
                        
                        memcpy(____BAH_COMPILER_VAR_417+currStrOff, ")", strLen_3);
                        currStrOff += strLen_3;
                        
                }
                return ____BAH_COMPILER_VAR_417;
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
char * ____BAH_COMPILER_VAR_418 =null;char * ____BAH_COMPILER_VAR_419 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_419);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(v);
long int strLen_6 = strlen(" = ");
long int strLen_8 = strlen(t.cont);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_418 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_418+currStrOff, ____BAH_COMPILER_VAR_419, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_418+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_418+currStrOff, v, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_418+currStrOff, " = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_418+currStrOff, t.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_418+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_418));
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
struct Tok ____BAH_COMPILER_VAR_420 = {};
____BAH_COMPILER_VAR_420.cont = "";
____BAH_COMPILER_VAR_420.ogCont = "";
____BAH_COMPILER_VAR_420.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_420.pos = 0;
____BAH_COMPILER_VAR_420.line = 1;
____BAH_COMPILER_VAR_420.begLine = 1;
____BAH_COMPILER_VAR_420.bahType = "";
____BAH_COMPILER_VAR_420.isValue = false;
____BAH_COMPILER_VAR_420.isFunc = false;
____BAH_COMPILER_VAR_420.isOper = false;
____BAH_COMPILER_VAR_420.isEqual = false;
#define tmpT ____BAH_COMPILER_VAR_420
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_421 =aet.str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_421,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_422 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_2 = strlen(aev);
long int strLen_4 = strlen(" = ");
long int strLen_6 = strlen(rt.cont);
long int strLen_8 = strlen(";\n        ");
;                            
                    ____BAH_COMPILER_VAR_422 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_422+currStrOff, "\n        struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_422+currStrOff, aev, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_422+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_422+currStrOff, rt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_422+currStrOff, ";\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_422));
char * ____BAH_COMPILER_VAR_423 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("&");
long int strLen_4 = strlen(aev);
;                            
                    ____BAH_COMPILER_VAR_423 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_423+currStrOff, "&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_423+currStrOff, aev, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                arrElem = ____BAH_COMPILER_VAR_423;
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
aet.trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_424 = {};
____BAH_COMPILER_VAR_424.cont = "";
____BAH_COMPILER_VAR_424.ogCont = "";
____BAH_COMPILER_VAR_424.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_424.pos = 0;
____BAH_COMPILER_VAR_424.line = 1;
____BAH_COMPILER_VAR_424.begLine = 1;
____BAH_COMPILER_VAR_424.bahType = "";
____BAH_COMPILER_VAR_424.isValue = false;
____BAH_COMPILER_VAR_424.isFunc = false;
____BAH_COMPILER_VAR_424.isOper = false;
____BAH_COMPILER_VAR_424.isEqual = false;
#define tmpT ____BAH_COMPILER_VAR_424
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_425 =aet.str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_425,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_426 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_2 = strlen(aev);
long int strLen_4 = strlen(" = ");
long int strLen_6 = strlen(rt.cont);
long int strLen_8 = strlen(";\n        ");
;                            
                    ____BAH_COMPILER_VAR_426 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_426+currStrOff, "\n        struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_426+currStrOff, aev, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_426+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_426+currStrOff, rt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_426+currStrOff, ";\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_426));
char * ____BAH_COMPILER_VAR_427 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("&");
long int strLen_4 = strlen(aev);
;                            
                    ____BAH_COMPILER_VAR_427 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_427+currStrOff, "&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_427+currStrOff, aev, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                arrElem = ____BAH_COMPILER_VAR_427;
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_428 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_428->name = "";
____BAH_COMPILER_VAR_428->type = "";
____BAH_COMPILER_VAR_428->isConst = false;
____BAH_COMPILER_VAR_428->constVal = "";
____BAH_COMPILER_VAR_428->isArray = false;
____BAH_COMPILER_VAR_428->from = "";
____BAH_COMPILER_VAR_428->outterScope = false;
____BAH_COMPILER_VAR_428->isGlobal = false;
struct variable* slv = ____BAH_COMPILER_VAR_428;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1533");
                        };
                        struct structMemb* m = ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_429 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_429->name = "";
____BAH_COMPILER_VAR_429->type = "";
____BAH_COMPILER_VAR_429->isConst = false;
____BAH_COMPILER_VAR_429->constVal = "";
____BAH_COMPILER_VAR_429->isArray = false;
____BAH_COMPILER_VAR_429->from = "";
____BAH_COMPILER_VAR_429->outterScope = false;
____BAH_COMPILER_VAR_429->isGlobal = false;
____BAH_COMPILER_VAR_429->def = "";
____BAH_COMPILER_VAR_429->isFn = false;
struct structMemb* nm = ____BAH_COMPILER_VAR_429;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_430 = {};
____BAH_COMPILER_VAR_430.cont = "";
____BAH_COMPILER_VAR_430.ogCont = "";
____BAH_COMPILER_VAR_430.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_430.pos = 0;
____BAH_COMPILER_VAR_430.line = 1;
____BAH_COMPILER_VAR_430.begLine = 1;
____BAH_COMPILER_VAR_430.bahType = "";
____BAH_COMPILER_VAR_430.isValue = false;
____BAH_COMPILER_VAR_430.isFunc = false;
____BAH_COMPILER_VAR_430.isOper = false;
____BAH_COMPILER_VAR_430.isEqual = false;
#define tmpT ____BAH_COMPILER_VAR_430
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
offsetTT.replace(&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_431 =null;char * ____BAH_COMPILER_VAR_432 =mCtype.str(&mCtype);char * ____BAH_COMPILER_VAR_433 =offsetTT.str(&offsetTT);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_432);
long int strLen_6 = strlen("*)((char*)(");
long int strLen_8 = strlen(t.cont);
long int strLen_10 = strlen(") + offsetof(struct ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_433);
long int strLen_14 = strlen(", ");
long int strLen_16 = strlen(m->name);
long int strLen_18 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_431 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18);
                    
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, ____BAH_COMPILER_VAR_432, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, "*)((char*)(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, t.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, ") + offsetof(struct ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, ____BAH_COMPILER_VAR_433, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, ", ", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, m->name, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_431+currStrOff, "))", strLen_18);
                        currStrOff += strLen_18;
                        
                }
                tmpT.cont = ____BAH_COMPILER_VAR_431;
char * ____BAH_COMPILER_VAR_434 =null;char * ____BAH_COMPILER_VAR_435 =offsetTT.str(&offsetTT);
                {
                    long int currStrOff = 0;
                    long int strLen_10 = strlen("offsetof(struct ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_435);
long int strLen_14 = strlen(", ");
long int strLen_16 = strlen(m->name);
long int strLen_18 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_434 = memoryAllocSTR(1 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18);
                    
                        memcpy(____BAH_COMPILER_VAR_434+currStrOff, "offsetof(struct ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_434+currStrOff, ____BAH_COMPILER_VAR_435, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_434+currStrOff, ", ", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_434+currStrOff, m->name, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_434+currStrOff, ")", strLen_18);
                        currStrOff += strLen_18;
                        
                }
                struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_434);
char * ____BAH_COMPILER_VAR_436 =null;char * ____BAH_COMPILER_VAR_437 =intToStr(i);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(structLayout);
long int strLen_2 = strlen("->data[");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_437);
long int strLen_6 = strlen("] = ");
long int strLen_8 = strlen(rt.cont);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_436+currStrOff, structLayout, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_436+currStrOff, "->data[", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_436+currStrOff, ____BAH_COMPILER_VAR_437, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_436+currStrOff, "] = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_436+currStrOff, rt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_436+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                dataLayout = dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_436));
};
char * ____BAH_COMPILER_VAR_438 =null;char * ____BAH_COMPILER_VAR_439 =intToStr(len(ts->members));
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        array(struct reflectElement) * ");
long int strLen_2 = strlen(structLayout);
long int strLen_4 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_6 = strlen(structLayout);
long int strLen_8 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_10 = strlen(structLayout);
long int strLen_12 = strlen("->length = ");
long int strLen_14 = strlen(____BAH_COMPILER_VAR_439);
long int strLen_16 = strlen(";\n        ");
long int strLen_18 = strlen(structLayout);
long int strLen_20 = strlen("->data = memoryAlloc(");
long int strLen_22 = strlen(structLayout);
long int strLen_24 = strlen("->length * ");
long int strLen_26 = strlen(structLayout);
long int strLen_28 = strlen("->elemSize);\n        ");
;                            
                    ____BAH_COMPILER_VAR_438 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, "\n        array(struct reflectElement) * ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, structLayout, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, structLayout, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, structLayout, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, "->length = ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, ____BAH_COMPILER_VAR_439, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, ";\n        ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, structLayout, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, "->data = memoryAlloc(", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, structLayout, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, "->length * ", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, structLayout, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_438+currStrOff, "->elemSize);\n        ", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_438))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_438)), dataLayout);
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
struct variable* ____BAH_COMPILER_VAR_440 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_440->name = "";
____BAH_COMPILER_VAR_440->type = "";
____BAH_COMPILER_VAR_440->isConst = false;
____BAH_COMPILER_VAR_440->constVal = "";
____BAH_COMPILER_VAR_440->isArray = false;
____BAH_COMPILER_VAR_440->from = "";
____BAH_COMPILER_VAR_440->outterScope = false;
____BAH_COMPILER_VAR_440->isGlobal = false;
struct variable* rv = ____BAH_COMPILER_VAR_440;
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
char * ____BAH_COMPILER_VAR_441 =null;char * ____BAH_COMPILER_VAR_442 =cType.str(&cType);char * ____BAH_COMPILER_VAR_443 =name.str(&name);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct reflectElement ");
long int strLen_2 = strlen(rv->name);
long int strLen_4 = strlen(" = __reflect(");
long int strLen_6 = strlen(amp);
long int strLen_8 = strlen(t.cont);
long int strLen_10 = strlen(", sizeof(");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_442);
long int strLen_14 = strlen("), \"");
long int strLen_16 = strlen(tt);
long int strLen_18 = strlen("\", \"");
long int strLen_20 = strlen(____BAH_COMPILER_VAR_443);
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
                    ____BAH_COMPILER_VAR_441 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34 + strLen_36 + strLen_38 + strLen_40 + strLen_42);
                    
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, "struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, rv->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, " = __reflect(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, amp, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, t.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, ", sizeof(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, ____BAH_COMPILER_VAR_442, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, "), \"", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, tt, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, "\", \"", strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, ____BAH_COMPILER_VAR_443, strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, "\", ", strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, isArr, strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, ", ", strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, arrElem, strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, ", ", strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, isStruct, strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, ", ", strLen_34);
                        currStrOff += strLen_34;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, structLayout, strLen_36);
                        currStrOff += strLen_36;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, ", ", strLen_38);
                        currStrOff += strLen_38;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, offset, strLen_40);
                        currStrOff += strLen_40;
                        
                        memcpy(____BAH_COMPILER_VAR_441+currStrOff, ");\n", strLen_42);
                        currStrOff += strLen_42;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_441));
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1609");
                        };
                        struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i = i+1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1613");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1629");
                        };
                        struct Tok ot = l->data[i];
if ((ot.type==TOKEN_TYPE_VAR)) {
i = i+1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1634");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1647");
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
char * ____BAH_COMPILER_VAR_444 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnName);
long int strLen_4 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_444 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_444+currStrOff, fnName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_444+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_444;
long int paramIndex = 0;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
if ((varName.length>0)) {
struct Tok ____BAH_COMPILER_VAR_445 = {};
____BAH_COMPILER_VAR_445.cont = "";
____BAH_COMPILER_VAR_445.ogCont = "";
____BAH_COMPILER_VAR_445.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_445.pos = 0;
____BAH_COMPILER_VAR_445.line = 1;
____BAH_COMPILER_VAR_445.begLine = 1;
____BAH_COMPILER_VAR_445.bahType = "";
____BAH_COMPILER_VAR_445.isValue = false;
____BAH_COMPILER_VAR_445.isFunc = false;
____BAH_COMPILER_VAR_445.isOper = false;
____BAH_COMPILER_VAR_445.isEqual = false;
#define tk ____BAH_COMPILER_VAR_445
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1680");
                        };
                        nt = l->data[i];
if ((strcmp(nt.cont, ")") != 0)) {
struct Tok ____BAH_COMPILER_VAR_446 = {};
____BAH_COMPILER_VAR_446.cont = "";
____BAH_COMPILER_VAR_446.ogCont = "";
____BAH_COMPILER_VAR_446.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_446.pos = 0;
____BAH_COMPILER_VAR_446.line = 1;
____BAH_COMPILER_VAR_446.begLine = 1;
____BAH_COMPILER_VAR_446.bahType = "";
____BAH_COMPILER_VAR_446.isValue = false;
____BAH_COMPILER_VAR_446.isFunc = false;
____BAH_COMPILER_VAR_446.isOper = false;
____BAH_COMPILER_VAR_446.isEqual = false;
tk = ____BAH_COMPILER_VAR_446;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1690");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1707");
                        };
                        struct Tok t = memory->data[j];
char * ____BAH_COMPILER_VAR_447 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ot.cont);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_447 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_447+currStrOff, ot.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_447+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_447;
j = j+1;
};
ot.cont = ot.cont;
ot.type = TOKEN_TYPE_FUNC;
ot.isFunc = true;
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
char * ____BAH_COMPILER_VAR_448 =null;char * ____BAH_COMPILER_VAR_449 =intToStr(ot.line);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("\"");
long int strLen_4 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_449);
long int strLen_10 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_448 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_448+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_448+currStrOff, compilerState.currentFile, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_448+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_448+currStrOff, ____BAH_COMPILER_VAR_449, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_448+currStrOff, "\"", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * currLine = ____BAH_COMPILER_VAR_448;

                        if (memory->length <= len(memory)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", len(memory)-1, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1721");
                        };
                        struct Tok par = memory->data[len(memory)-1];
long int cl = par.line;
struct Tok ____BAH_COMPILER_VAR_450 = {};
____BAH_COMPILER_VAR_450.cont = "";
____BAH_COMPILER_VAR_450.ogCont = "";
____BAH_COMPILER_VAR_450.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_450.pos = 0;
____BAH_COMPILER_VAR_450.line = 1;
____BAH_COMPILER_VAR_450.begLine = 1;
____BAH_COMPILER_VAR_450.bahType = "";
____BAH_COMPILER_VAR_450.isValue = false;
____BAH_COMPILER_VAR_450.isFunc = false;
____BAH_COMPILER_VAR_450.isOper = false;
____BAH_COMPILER_VAR_450.isEqual = false;
____BAH_COMPILER_VAR_450.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_450.cont = ",";
____BAH_COMPILER_VAR_450.line = cl;

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)-1] = ____BAH_COMPILER_VAR_450;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] = ____BAH_COMPILER_VAR_450;
}
};
struct Tok ____BAH_COMPILER_VAR_451 = {};
____BAH_COMPILER_VAR_451.cont = "";
____BAH_COMPILER_VAR_451.ogCont = "";
____BAH_COMPILER_VAR_451.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_451.pos = 0;
____BAH_COMPILER_VAR_451.line = 1;
____BAH_COMPILER_VAR_451.begLine = 1;
____BAH_COMPILER_VAR_451.bahType = "";
____BAH_COMPILER_VAR_451.isValue = false;
____BAH_COMPILER_VAR_451.isFunc = false;
____BAH_COMPILER_VAR_451.isOper = false;
____BAH_COMPILER_VAR_451.isEqual = false;
____BAH_COMPILER_VAR_451.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_451.cont = currLine;
____BAH_COMPILER_VAR_451.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_451;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_451;
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
char * ____BAH_COMPILER_VAR_452 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnName);
long int strLen_4 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_452 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_452+currStrOff, fnName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_452+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_452;
fn = searchFunc(fnName,elems,true);
}
else if ((strcmp(fnName, "__dumpSymbols") == 0)) {
char * ____BAH_COMPILER_VAR_453 =null;char * ____BAH_COMPILER_VAR_454 =intToStr(ot.line);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("\"");
long int strLen_4 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_454);
long int strLen_10 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_453+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_453+currStrOff, compilerState.currentFile, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_453+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_453+currStrOff, ____BAH_COMPILER_VAR_454, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_453+currStrOff, "\"", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * currLine = ____BAH_COMPILER_VAR_453;

                        if (memory->length <= len(memory)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", len(memory)-1, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1739");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1745");
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
struct variable* ____BAH_COMPILER_VAR_455 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_455->name = "";
____BAH_COMPILER_VAR_455->type = "";
____BAH_COMPILER_VAR_455->isConst = false;
____BAH_COMPILER_VAR_455->constVal = "";
____BAH_COMPILER_VAR_455->isArray = false;
____BAH_COMPILER_VAR_455->from = "";
____BAH_COMPILER_VAR_455->outterScope = false;
____BAH_COMPILER_VAR_455->isGlobal = false;
____BAH_COMPILER_VAR_455->name = genCompilerVar();
____BAH_COMPILER_VAR_455->type = "[]reflectElement";
____BAH_COMPILER_VAR_455->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_455;

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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1760");
                        };
                        struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_456 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("&");
long int strLen_4 = strlen(v->name);
;                            
                    ____BAH_COMPILER_VAR_456 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_456+currStrOff, "&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_456+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                vname = ____BAH_COMPILER_VAR_456;
}
struct Tok ____BAH_COMPILER_VAR_457 = {};
____BAH_COMPILER_VAR_457.cont = "";
____BAH_COMPILER_VAR_457.ogCont = "";
____BAH_COMPILER_VAR_457.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_457.pos = 0;
____BAH_COMPILER_VAR_457.line = 1;
____BAH_COMPILER_VAR_457.begLine = 1;
____BAH_COMPILER_VAR_457.bahType = "";
____BAH_COMPILER_VAR_457.isValue = false;
____BAH_COMPILER_VAR_457.isFunc = false;
____BAH_COMPILER_VAR_457.isOper = false;
____BAH_COMPILER_VAR_457.isEqual = false;
____BAH_COMPILER_VAR_457.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_457.cont = vname;
____BAH_COMPILER_VAR_457.bahType = v->type;
____BAH_COMPILER_VAR_457.isValue = true;
#define tmpT ____BAH_COMPILER_VAR_457
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_458 =null;char * ____BAH_COMPILER_VAR_459 =intToStr(j);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpV->name);
long int strLen_4 = strlen("->data[");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_459);
long int strLen_8 = strlen("] = ");
long int strLen_10 = strlen(tmpT.cont);
long int strLen_12 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_458 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, tmpV->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, "->data[", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, ____BAH_COMPILER_VAR_459, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, "] = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, tmpT.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_458+currStrOff, ";\n", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                char * ____BAH_COMPILER_VAR_460 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(decls);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_458);
;                            
                    ____BAH_COMPILER_VAR_460 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_460+currStrOff, decls, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_460+currStrOff, ____BAH_COMPILER_VAR_458, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                decls = ____BAH_COMPILER_VAR_460;
};
char * ____BAH_COMPILER_VAR_461 =null;char * ____BAH_COMPILER_VAR_462 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_463 =intToStr(len(symbols));
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                        array(struct reflectElement)* ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_4 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n                        ");
long int strLen_6 = strlen(tmpV->name);
long int strLen_8 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_462);
long int strLen_12 = strlen(");\n                        ");
long int strLen_14 = strlen(tmpV->name);
long int strLen_16 = strlen("->length = ");
long int strLen_18 = strlen(____BAH_COMPILER_VAR_463);
long int strLen_20 = strlen(";\n                        ");
long int strLen_22 = strlen(tmpV->name);
long int strLen_24 = strlen("->elemSize = sizeof(struct reflectElement);\n                        ");
long int strLen_26 = strlen(decls);
long int strLen_28 = strlen("\n                        ");
;                            
                    ____BAH_COMPILER_VAR_461 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, "\n                        array(struct reflectElement)* ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, tmpV->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n                        ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, tmpV->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, ____BAH_COMPILER_VAR_462, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, ");\n                        ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, tmpV->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, "->length = ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, ____BAH_COMPILER_VAR_463, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, ";\n                        ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, tmpV->name, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, "->elemSize = sizeof(struct reflectElement);\n                        ", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, decls, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_461+currStrOff, "\n                        ", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_461));
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
____BAH_COMPILER_VAR_464.cont = tmpV->name;
____BAH_COMPILER_VAR_464.line = cl;
____BAH_COMPILER_VAR_464.isValue = true;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[0] = ____BAH_COMPILER_VAR_464;
memory->length = nLength+1;
} else {
memory->data[0] = ____BAH_COMPILER_VAR_464;
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
char * ____BAH_COMPILER_VAR_465 =null;char * ____BAH_COMPILER_VAR_466 =intToStr(ot.line);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("\"");
long int strLen_4 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_466);
long int strLen_10 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_465 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_465+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_465+currStrOff, compilerState.currentFile, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_465+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_465+currStrOff, ____BAH_COMPILER_VAR_466, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_465+currStrOff, "\"", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                char * currLine = ____BAH_COMPILER_VAR_465;

                        if (memory->length <= len(memory)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", len(memory)-1, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1794");
                        };
                        struct Tok par = memory->data[len(memory)-1];
long int cl = par.line;
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
____BAH_COMPILER_VAR_467.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_467.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_467.line = cl;
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
____BAH_COMPILER_VAR_468.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_468.cont = "(";
____BAH_COMPILER_VAR_468.line = cl;
struct Tok ____BAH_COMPILER_VAR_469 = {};
____BAH_COMPILER_VAR_469.cont = "";
____BAH_COMPILER_VAR_469.ogCont = "";
____BAH_COMPILER_VAR_469.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_469.pos = 0;
____BAH_COMPILER_VAR_469.line = 1;
____BAH_COMPILER_VAR_469.begLine = 1;
____BAH_COMPILER_VAR_469.bahType = "";
____BAH_COMPILER_VAR_469.isValue = false;
____BAH_COMPILER_VAR_469.isFunc = false;
____BAH_COMPILER_VAR_469.isOper = false;
____BAH_COMPILER_VAR_469.isEqual = false;
____BAH_COMPILER_VAR_469.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_469.cont = ")";
____BAH_COMPILER_VAR_469.line = cl;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);memory->data[0] = ____BAH_COMPILER_VAR_467;
memory->data[1] = ____BAH_COMPILER_VAR_468;
memory->data[2] = ____BAH_COMPILER_VAR_469;
memory = parseFnCall(memory,(lineType)-1,elems,false);
struct Tok ____BAH_COMPILER_VAR_470 = {};
____BAH_COMPILER_VAR_470.cont = "";
____BAH_COMPILER_VAR_470.ogCont = "";
____BAH_COMPILER_VAR_470.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_470.pos = 0;
____BAH_COMPILER_VAR_470.line = 1;
____BAH_COMPILER_VAR_470.begLine = 1;
____BAH_COMPILER_VAR_470.bahType = "";
____BAH_COMPILER_VAR_470.isValue = false;
____BAH_COMPILER_VAR_470.isFunc = false;
____BAH_COMPILER_VAR_470.isOper = false;
____BAH_COMPILER_VAR_470.isEqual = false;
____BAH_COMPILER_VAR_470.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_470.cont = ",";
____BAH_COMPILER_VAR_470.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_470;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_470;
}
};
struct Tok ____BAH_COMPILER_VAR_471 = {};
____BAH_COMPILER_VAR_471.cont = "";
____BAH_COMPILER_VAR_471.ogCont = "";
____BAH_COMPILER_VAR_471.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_471.pos = 0;
____BAH_COMPILER_VAR_471.line = 1;
____BAH_COMPILER_VAR_471.begLine = 1;
____BAH_COMPILER_VAR_471.bahType = "";
____BAH_COMPILER_VAR_471.isValue = false;
____BAH_COMPILER_VAR_471.isFunc = false;
____BAH_COMPILER_VAR_471.isOper = false;
____BAH_COMPILER_VAR_471.isEqual = false;
____BAH_COMPILER_VAR_471.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_471.cont = currLine;
____BAH_COMPILER_VAR_471.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_471;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_471;
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
char * ____BAH_COMPILER_VAR_472 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fnName);
long int strLen_4 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_472 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_472+currStrOff, fnName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_472+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_472;
fn = searchFunc(fnName,elems,true);
}
else if ((strcmp(fnName, "sizeof") == 0)) {
char * tp = "";
long int j = 0;
for (; (j<len(memory)-1); j = j+1) {

                        if (memory->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", j, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1835");
                        };
                        struct Tok t = memory->data[j];
char * ____BAH_COMPILER_VAR_473 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tp);
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_473 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_473+currStrOff, tp, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_473+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                tp = ____BAH_COMPILER_VAR_473;
};
struct string cType = getCType(tp,elems);
char * ____BAH_COMPILER_VAR_474 =null;char * ____BAH_COMPILER_VAR_475 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_475);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_474 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_474+currStrOff, ____BAH_COMPILER_VAR_475, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_474+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * ____BAH_COMPILER_VAR_476 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_474);
;                            
                    ____BAH_COMPILER_VAR_476 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_476+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_476+currStrOff, ____BAH_COMPILER_VAR_474, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_476;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1860");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1867");
                        };
                        struct Tok t = memory->data[j];
if ((paramIndex>=len(fn->args))) {
throwErr(&t,"Too many arguments in function call.");
}

                        if (fn->args->length <= paramIndex) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", paramIndex, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1872");
                        };
                        struct variable* arg = fn->args->data[paramIndex];
char * tt = getTypeFromToken(&t,true,elems);
if (((strcmp(arg->type, "reflectElement") == 0)&&(strcmp(tt, "reflectElement") != 0))) {
t = parseReflect(t,tt,elems,false,t.cont,"0");
tt = "reflectElement";
}
if ((compTypes(tt,arg->type)==false)) {
char * ____BAH_COMPILER_VAR_477 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(arg->type);
long int strLen_10 = strlen(" in function call.");
;                            
                    ____BAH_COMPILER_VAR_477 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_477+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_477+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_477+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_477+currStrOff, arg->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_477+currStrOff, " in function call.", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_477);
}
if (((t.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(t.cont,"noCheck(")==false))) {
struct string ____BAH_COMPILER_VAR_478 =string(t.cont);char * afnName = splitStringBefore(____BAH_COMPILER_VAR_478,"(");
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
char * ____BAH_COMPILER_VAR_479 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ot.cont);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_479 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_479+currStrOff, ot.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_479+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_479;
j = j+1;

                        if (memory->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", j, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1898");
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
char * ____BAH_COMPILER_VAR_480 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ot.cont);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_480 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_480+currStrOff, ot.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_480+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_480;
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
char * ____BAH_COMPILER_VAR_481 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ot.cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_481 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_481+currStrOff, ot.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_481+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                ot.cont = ____BAH_COMPILER_VAR_481;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1934");
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
char * ____BAH_COMPILER_VAR_482 =null;char * ____BAH_COMPILER_VAR_483 =arrType.str(&arrType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("memoryAlloc(sizeof(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_483);
long int strLen_6 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_482 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_482+currStrOff, "memoryAlloc(sizeof(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_482+currStrOff, ____BAH_COMPILER_VAR_483, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_482+currStrOff, "))", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * code = ____BAH_COMPILER_VAR_482;
arrType.trimLeft(&arrType,6);
arrType.trimRight(&arrType,1);
char * elemTypeStr = arrType.str(&arrType);
if ((i+1!=max)) {
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1964");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1974");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1979");
                        };
                        struct Tok t = memory->data[i];
if ((strcmp(t.cont, "{") == 0)) {
long int j = i-1;
long int nbBraces = 0;
for (; (i<len(memory)); i = i+1) {

                        if (memory->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", i, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:1985");
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
struct variable* ____BAH_COMPILER_VAR_484 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_484->name = "";
____BAH_COMPILER_VAR_484->type = "";
____BAH_COMPILER_VAR_484->isConst = false;
____BAH_COMPILER_VAR_484->constVal = "";
____BAH_COMPILER_VAR_484->isArray = false;
____BAH_COMPILER_VAR_484->from = "";
____BAH_COMPILER_VAR_484->outterScope = false;
____BAH_COMPILER_VAR_484->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_484;
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
char * ____BAH_COMPILER_VAR_485 =elemType.str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_485,elems);
char * ____BAH_COMPILER_VAR_486 =null;char * ____BAH_COMPILER_VAR_487 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                array(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_487);
long int strLen_4 = strlen(") * ");
long int strLen_6 = strlen(tmpV->name);
long int strLen_8 = strlen(" = ");
long int strLen_10 = strlen(innerCode);
long int strLen_12 = strlen(";\n                ");
long int strLen_14 = strlen(NEXT_LINE);
long int strLen_16 = strlen("\n                ");
;                            
                    ____BAH_COMPILER_VAR_486 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, "\n                array(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, ____BAH_COMPILER_VAR_487, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, ") * ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, tmpV->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, " = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, innerCode, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, ";\n                ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, NEXT_LINE, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_486+currStrOff, "\n                ", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_486));
NEXT_LINE = oldNL;
struct Tok ____BAH_COMPILER_VAR_488 = {};
____BAH_COMPILER_VAR_488.cont = "";
____BAH_COMPILER_VAR_488.ogCont = "";
____BAH_COMPILER_VAR_488.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_488.pos = 0;
____BAH_COMPILER_VAR_488.line = 1;
____BAH_COMPILER_VAR_488.begLine = 1;
____BAH_COMPILER_VAR_488.bahType = "";
____BAH_COMPILER_VAR_488.isValue = false;
____BAH_COMPILER_VAR_488.isFunc = false;
____BAH_COMPILER_VAR_488.isOper = false;
____BAH_COMPILER_VAR_488.isEqual = false;
____BAH_COMPILER_VAR_488.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_488.cont = tmpV->name;
____BAH_COMPILER_VAR_488.bahType = elemType.str(&elemType);
____BAH_COMPILER_VAR_488.isValue = true;
t = ____BAH_COMPILER_VAR_488;
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_489 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(elemBahTypeStr);
;                            
                    ____BAH_COMPILER_VAR_489 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_489+currStrOff, elemBahTypeStr, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_489);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char * ____BAH_COMPILER_VAR_490 =null;
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
                    ____BAH_COMPILER_VAR_490 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_490+currStrOff, NEXT_LINE, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_490+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_490+currStrOff, "->data[", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_490+currStrOff, strArrayLength, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_490+currStrOff, "] = ", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_490+currStrOff, t.cont, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_490+currStrOff, ";\n", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_490;
i = i+1;

                        if (memory->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: memory[%d] with length %d", i, memory->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2030");
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
char * ____BAH_COMPILER_VAR_491 =null;
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
                    ____BAH_COMPILER_VAR_491 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_491+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_491+currStrOff, "->data = memoryAlloc(sizeof(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_491+currStrOff, elemTypeStr, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_491+currStrOff, ") * ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_491+currStrOff, allocLengthStr, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_491+currStrOff, ");", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_491+currStrOff, NEXT_LINE, strLen_14);
                        currStrOff += strLen_14;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_491;
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
char * ____BAH_COMPILER_VAR_492 =null;
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
                    ____BAH_COMPILER_VAR_492 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20);
                    
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, "\n", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, "->length = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, strArrayLength, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, v->name, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, "->elemSize = sizeof(", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, elemTypeStr, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, ");\n", strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_492+currStrOff, NEXT_LINE, strLen_20);
                        currStrOff += strLen_20;
                        
                }
                NEXT_LINE = ____BAH_COMPILER_VAR_492;
return code;
};
array(char *)* equalsTokens;
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2063");
                        };
                        struct Tok ft = l->data[0];
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2068");
                        };
                        ft = l->data[0];
char parsed = true;
char * ____BAH_COMPILER_VAR_493 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_493 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_493+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_493+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_493));
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2080");
                        };
                        ft = l->data[0];
struct variable* v = searchVar(ft.cont,elems);
char exists = true;
char * ogName= null;
if ((v==null)) {
exists = false;
struct variable* ____BAH_COMPILER_VAR_494 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_494->name = "";
____BAH_COMPILER_VAR_494->type = "";
____BAH_COMPILER_VAR_494->isConst = false;
____BAH_COMPILER_VAR_494->constVal = "";
____BAH_COMPILER_VAR_494->isArray = false;
____BAH_COMPILER_VAR_494->from = "";
____BAH_COMPILER_VAR_494->outterScope = false;
____BAH_COMPILER_VAR_494->isGlobal = false;
v = ____BAH_COMPILER_VAR_494;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2102");
                        };
                        struct Tok lt = l->data[1];
if ((((lt.type==TOKEN_TYPE_SYNTAX)&&(strcmp(lt.cont, "++") == 0))||(strcmp(lt.cont, "--") == 0))) {
if ((exists==false)) {
char * ____BAH_COMPILER_VAR_495 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use '");
long int strLen_4 = strlen(lt.cont);
long int strLen_6 = strlen("' on non declared {TOKEN} variable.");
;                            
                    ____BAH_COMPILER_VAR_495 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_495+currStrOff, "Cannot use '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_495+currStrOff, lt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_495+currStrOff, "' on non declared {TOKEN} variable.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&ft,____BAH_COMPILER_VAR_495);
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2108");
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
____BAH_COMPILER_VAR_496.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_496.cont = "=";
____BAH_COMPILER_VAR_496.isValue = false;

{
long nLength = 1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[1] = ____BAH_COMPILER_VAR_496;
nl->length = nLength+1;
} else {
nl->data[1] = ____BAH_COMPILER_VAR_496;
}
};
char * c = "";
if ((strcmp(lt.cont, "++") == 0)) {
char * ____BAH_COMPILER_VAR_497 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ft.cont);
long int strLen_4 = strlen("+1");
;                            
                    ____BAH_COMPILER_VAR_497 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_497+currStrOff, ft.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_497+currStrOff, "+1", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                c = ____BAH_COMPILER_VAR_497;
}
else if ((strcmp(lt.cont, "--") == 0)) {
char * ____BAH_COMPILER_VAR_498 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(ft.cont);
long int strLen_4 = strlen("-1");
;                            
                    ____BAH_COMPILER_VAR_498 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_498+currStrOff, ft.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_498+currStrOff, "-1", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                c = ____BAH_COMPILER_VAR_498;
}
long int ltl = lt.line;
long int ltp = lt.pos;
char * ltc = lt.cont;
struct Tok ____BAH_COMPILER_VAR_499 = {};
____BAH_COMPILER_VAR_499.cont = "";
____BAH_COMPILER_VAR_499.ogCont = "";
____BAH_COMPILER_VAR_499.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_499.pos = 0;
____BAH_COMPILER_VAR_499.line = 1;
____BAH_COMPILER_VAR_499.begLine = 1;
____BAH_COMPILER_VAR_499.bahType = "";
____BAH_COMPILER_VAR_499.isValue = false;
____BAH_COMPILER_VAR_499.isFunc = false;
____BAH_COMPILER_VAR_499.isOper = false;
____BAH_COMPILER_VAR_499.isEqual = false;
____BAH_COMPILER_VAR_499.type = TOKEN_TYPE_INT;
____BAH_COMPILER_VAR_499.cont = c;
____BAH_COMPILER_VAR_499.line = ltl;
____BAH_COMPILER_VAR_499.ogCont = ltc;
____BAH_COMPILER_VAR_499.pos = ltp;
____BAH_COMPILER_VAR_499.isOper = true;
____BAH_COMPILER_VAR_499.isValue = true;

{
long nLength = 2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[2] = ____BAH_COMPILER_VAR_499;
nl->length = nLength+1;
} else {
nl->data[2] = ____BAH_COMPILER_VAR_499;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2143");
                        };
                        struct Tok operT = l->data[1];

                int ____BAH_COMPILER_VAR_500 = 0;
                for(int i=len(equalsTokens)-1; i != -1; i--) {
                    if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                        ____BAH_COMPILER_VAR_500 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_500&&(strcmp(operT.cont, "=") != 0))) {

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2145");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2157");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2166");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2174");
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
char * ____BAH_COMPILER_VAR_501 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(currentType);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_501 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_501+currStrOff, currentType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_501+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                currentType = ____BAH_COMPILER_VAR_501;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2200");
                        };
                        struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_502 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("chan:");
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_502 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_502+currStrOff, "chan:", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_502+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                v->type = ____BAH_COMPILER_VAR_502;
code = "channel()";
if ((i+1!=len(l))) {

                        if (l->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i+1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2204");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2213");
                        };
                        struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_503 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("map:");
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_503 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_503+currStrOff, "map:", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_503+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                v->type = ____BAH_COMPILER_VAR_503;
code = "mapWrapper()";
if ((i+1!=len(l))) {

                        if (l->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i+1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2217");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2226");
                        };
                        struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_INT)) {
throwErr(&nt,"Expected buffer length, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_504 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("buffer:");
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_504 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_504+currStrOff, "buffer:", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_504+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                v->type = ____BAH_COMPILER_VAR_504;
struct variable* ____BAH_COMPILER_VAR_505 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_505->name = "";
____BAH_COMPILER_VAR_505->type = "";
____BAH_COMPILER_VAR_505->isConst = false;
____BAH_COMPILER_VAR_505->constVal = "";
____BAH_COMPILER_VAR_505->isArray = false;
____BAH_COMPILER_VAR_505->from = "";
____BAH_COMPILER_VAR_505->outterScope = false;
____BAH_COMPILER_VAR_505->isGlobal = false;
struct variable* av = ____BAH_COMPILER_VAR_505;
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
char * ____BAH_COMPILER_VAR_506 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("char ");
long int strLen_2 = strlen(av->name);
long int strLen_4 = strlen("[");
long int strLen_6 = strlen(nt.cont);
long int strLen_8 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_506 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_506+currStrOff, "char ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_506+currStrOff, av->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_506+currStrOff, "[", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_506+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_506+currStrOff, "];", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_506));
code = av->name;
if ((i+1!=len(l))) {

                        if (l->length <= i+1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i+1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2239");
                        };
                        struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after buffer declaration.");
}
break;
}
char * tp = getTypeFromToken(&t,true,elems);
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_507 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tp);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(v->type);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_507 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, tp, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, v->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_507+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_507);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_508 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tp);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(v->type);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_508 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_508+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_508+currStrOff, tp, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_508+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_508+currStrOff, v->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_508+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_508);
}
}
}
}
if (((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false))) {
char * ____BAH_COMPILER_VAR_509 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_509 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_509+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_509+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_509;
if (((t.isOper==false)&&(RCPavailable()==true))) {
struct variable* iv = searchVar(t.cont,elems);
if (((iv!=null)&&(iv->isConst==false))) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((((s!=null)&&(strCount(iv->type,"*")==0))&&(s->isBinding==false))) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_510 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen("; RCP_scanStack(&");
long int strLen_6 = strlen(iv->name);
long int strLen_8 = strlen(", sizeof(");
long int strLen_10 = strlen(iv->name);
long int strLen_12 = strlen("), 0)");
;                            
                    ____BAH_COMPILER_VAR_510 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_510+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_510+currStrOff, "; RCP_scanStack(&", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_510+currStrOff, iv->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_510+currStrOff, ", sizeof(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_510+currStrOff, iv->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_510+currStrOff, "), 0)", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                code = ____BAH_COMPILER_VAR_510;
}
else {
struct string ivn = string(iv->name);
ivn.replace(&ivn,"*","");
char * ____BAH_COMPILER_VAR_511 =null;char * ____BAH_COMPILER_VAR_512 =ivn.str(&ivn);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen("; RCP_incr(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_512);
long int strLen_8 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_511 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_511+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_511+currStrOff, "; RCP_incr(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_511+currStrOff, ____BAH_COMPILER_VAR_512, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_511+currStrOff, ")", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                code = ____BAH_COMPILER_VAR_511;
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
char * ____BAH_COMPILER_VAR_513 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_513 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_513+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_513+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_513;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2308");
                        };
                        struct Tok st = l->data[1];
char * ____BAH_COMPILER_VAR_514 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot change the type of already declared var '");
long int strLen_4 = strlen(ft.cont);
long int strLen_6 = strlen("' to {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_514 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, "Cannot change the type of already declared var '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, ft.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_514+currStrOff, "' to {TOKEN}.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&st,____BAH_COMPILER_VAR_514);
}
char * preCode = "";
if ((isStruct==false)) {
if (((isRCPpointerType(v->type)&&(isPointedVar==false))&&(RCPavailable()==true))) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_515 =null;char * ____BAH_COMPILER_VAR_516 =cType.str(&cType);char * ____BAH_COMPILER_VAR_517 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("*(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_516);
long int strLen_6 = strlen("*)RCP_decrIL(&");
long int strLen_8 = strlen(v->name);
long int strLen_10 = strlen(") = *(");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_517);
long int strLen_14 = strlen("*)RCP_incrIL(&");
long int strLen_16 = strlen(code);
long int strLen_18 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_515 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18);
                    
                        memcpy(____BAH_COMPILER_VAR_515+currStrOff, "*(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_515+currStrOff, ____BAH_COMPILER_VAR_516, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_515+currStrOff, "*)RCP_decrIL(&", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_515+currStrOff, v->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_515+currStrOff, ") = *(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_515+currStrOff, ____BAH_COMPILER_VAR_517, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_515+currStrOff, "*)RCP_incrIL(&", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_515+currStrOff, code, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_515+currStrOff, ")", strLen_18);
                        currStrOff += strLen_18;
                        
                }
                code = ____BAH_COMPILER_VAR_515;
}
else {
struct variable* ____BAH_COMPILER_VAR_518 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_518->name = "";
____BAH_COMPILER_VAR_518->type = "";
____BAH_COMPILER_VAR_518->isConst = false;
____BAH_COMPILER_VAR_518->constVal = "";
____BAH_COMPILER_VAR_518->isArray = false;
____BAH_COMPILER_VAR_518->from = "";
____BAH_COMPILER_VAR_518->outterScope = false;
____BAH_COMPILER_VAR_518->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_518;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_519 =null;char * ____BAH_COMPILER_VAR_520 =cType.str(&cType);char * ____BAH_COMPILER_VAR_521 =cType.str(&cType);char * ____BAH_COMPILER_VAR_522 =dv->toStr(dv);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_520);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(tmpV->name);
long int strLen_8 = strlen(" = ");
long int strLen_10 = strlen(v->name);
long int strLen_12 = strlen("; ");
long int strLen_14 = strlen(v->name);
long int strLen_16 = strlen(" = *(");
long int strLen_18 = strlen(____BAH_COMPILER_VAR_521);
long int strLen_20 = strlen("*)RCP_incrIL(&");
long int strLen_22 = strlen(code);
long int strLen_24 = strlen(");");
long int strLen_26 = strlen(____BAH_COMPILER_VAR_522);
;                            
                    ____BAH_COMPILER_VAR_519 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26);
                    
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, ____BAH_COMPILER_VAR_520, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, tmpV->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, " = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, v->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, "; ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, v->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, " = *(", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, ____BAH_COMPILER_VAR_521, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, "*)RCP_incrIL(&", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, code, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, ");", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_519+currStrOff, ____BAH_COMPILER_VAR_522, strLen_26);
                        currStrOff += strLen_26;
                        
                }
                code = ____BAH_COMPILER_VAR_519;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_523 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_523->name = "";
____BAH_COMPILER_VAR_523->type = "";
____BAH_COMPILER_VAR_523->isConst = false;
____BAH_COMPILER_VAR_523->constVal = "";
____BAH_COMPILER_VAR_523->isArray = false;
____BAH_COMPILER_VAR_523->from = "";
____BAH_COMPILER_VAR_523->outterScope = false;
____BAH_COMPILER_VAR_523->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_523;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_524 =null;char * ____BAH_COMPILER_VAR_525 =cType.str(&cType);char * ____BAH_COMPILER_VAR_526 =dv->toStr(dv);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_525);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(tmpV->name);
long int strLen_8 = strlen(" = ");
long int strLen_10 = strlen(v->name);
long int strLen_12 = strlen("; ");
long int strLen_14 = strlen(v->name);
long int strLen_16 = strlen(" = ");
long int strLen_18 = strlen(code);
long int strLen_20 = strlen(";");
long int strLen_22 = strlen(____BAH_COMPILER_VAR_526);
;                            
                    ____BAH_COMPILER_VAR_524 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22);
                    
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, ____BAH_COMPILER_VAR_525, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, tmpV->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, " = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, v->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, "; ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, v->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, " = ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, code, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, ";", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_524+currStrOff, ____BAH_COMPILER_VAR_526, strLen_22);
                        currStrOff += strLen_22;
                        
                }
                code = ____BAH_COMPILER_VAR_524;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((((((s!=null)&&(RCPavailable()==true))&&(RCPselfRef(v)==false))&&(s->isBinding==false))&&(strCount(v->name,"*")==0))) {
char * ____BAH_COMPILER_VAR_527 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("RCP_scanStack(&");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(", sizeof(");
long int strLen_8 = strlen(v->name);
long int strLen_10 = strlen("), 1); ");
;                            
                    ____BAH_COMPILER_VAR_527 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_527+currStrOff, "RCP_scanStack(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_527+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_527+currStrOff, ", sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_527+currStrOff, v->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_527+currStrOff, "), 1); ", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                preCode = ____BAH_COMPILER_VAR_527;
char * ____BAH_COMPILER_VAR_528 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(" = ");
long int strLen_6 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_528 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_528+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_528+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_528+currStrOff, code, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                code = ____BAH_COMPILER_VAR_528;
}
else {
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
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
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
char * ____BAH_COMPILER_VAR_531 =null;
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
                    ____BAH_COMPILER_VAR_531 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34 + strLen_36);
                    
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, "\n{\nlong nLength = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, nLengthStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, ";\nif (", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, nstr, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, nstr, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, "->data, (nLength+50)*sizeof(", strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, elemTypeStr, strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, "));\n", strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, nstr, strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, "->data = newPtr;\n}\n", strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, code, strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, ";\n", strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, nstr, strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, "->length = nLength+1;\n} else {\n", strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, preCode, strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, code, strLen_34);
                        currStrOff += strLen_34;
                        
                        memcpy(____BAH_COMPILER_VAR_531+currStrOff, ";\n}\n}", strLen_36);
                        currStrOff += strLen_36;
                        
                }
                code = ____BAH_COMPILER_VAR_531;
}
else {
char * ____BAH_COMPILER_VAR_532 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(preCode);
long int strLen_4 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_532 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, preCode, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_532+currStrOff, code, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_532;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2412");
                        };
                        struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_533 =null;char * ____BAH_COMPILER_VAR_534 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_534);
;                            
                    ____BAH_COMPILER_VAR_533 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_533+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_533+currStrOff, ____BAH_COMPILER_VAR_534, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_533;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_535 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_535 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_535+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_535+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_535;
}
};
char * ____BAH_COMPILER_VAR_536 =null;char * ____BAH_COMPILER_VAR_537 =tmpfnRetCType.str(&tmpfnRetCType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_537);
long int strLen_4 = strlen(" (*");
long int strLen_6 = strlen(v->name);
long int strLen_8 = strlen(")(");
long int strLen_10 = strlen(tmpfnArgsCType);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_536 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_536+currStrOff, ____BAH_COMPILER_VAR_537, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_536+currStrOff, " (*", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_536+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_536+currStrOff, ")(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_536+currStrOff, tmpfnArgsCType, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_536+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                vct = ____BAH_COMPILER_VAR_536;
}
else {
vct = setCType(v,elems);
}
if (((strcmp(code, "") != 0)&&(shouldOnlyDecl==false))) {
if ((((isRCPpointerType(v->type)&&(RCPavailable()==true))&&(toVar==true))&&(isPointedVar==false))) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_538 =null;char * ____BAH_COMPILER_VAR_539 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_2 = strlen(" = *(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_539);
long int strLen_6 = strlen("*)RCP_incrIL(&");
long int strLen_8 = strlen(code);
long int strLen_10 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_538 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_538+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_538+currStrOff, " = *(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_538+currStrOff, ____BAH_COMPILER_VAR_539, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_538+currStrOff, "*)RCP_incrIL(&", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_538+currStrOff, code, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_538+currStrOff, ");\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_538));
}
else {
char * ____BAH_COMPILER_VAR_540 =null;char * ____BAH_COMPILER_VAR_541 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(vct);
long int strLen_4 = strlen(" = *(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_541);
long int strLen_8 = strlen("*)RCP_incrIL(&");
long int strLen_10 = strlen(code);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_540 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_540+currStrOff, vct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_540+currStrOff, " = *(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_540+currStrOff, ____BAH_COMPILER_VAR_541, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_540+currStrOff, "*)RCP_incrIL(&", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_540+currStrOff, code, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_540+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                code = ____BAH_COMPILER_VAR_540;
}
}
else {
if ((needsDefine==true)) {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_542 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(code);
long int strLen_8 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_542 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_542+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_542+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_542+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_542+currStrOff, code, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_542+currStrOff, "\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_542));
}
else {
char * ____BAH_COMPILER_VAR_543 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("#define ");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_543 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_543+currStrOff, "#define ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_543+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_543+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_543+currStrOff, code, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                code = ____BAH_COMPILER_VAR_543;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_544 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_2 = strlen(" = ");
long int strLen_4 = strlen(code);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_544 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_544+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_544+currStrOff, " = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_544+currStrOff, code, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_544+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_544));
}
else {
char * ____BAH_COMPILER_VAR_545 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(vct);
long int strLen_4 = strlen(" = ");
long int strLen_6 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_545+currStrOff, vct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_545+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_545+currStrOff, code, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                code = ____BAH_COMPILER_VAR_545;
}
}
}
}
else {
if ((isRCPpointerType(v->type)&&(shouldOnlyDecl==false))) {
char * ____BAH_COMPILER_VAR_546 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(vct);
long int strLen_4 = strlen("= null");
;                            
                    ____BAH_COMPILER_VAR_546 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_546+currStrOff, vct, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_546+currStrOff, "= null", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_546;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_547 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("extern ");
long int strLen_4 = strlen(vct);
;                            
                    ____BAH_COMPILER_VAR_547 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_547+currStrOff, "extern ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_547+currStrOff, vct, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                vct = ____BAH_COMPILER_VAR_547;
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
struct variable* ____BAH_COMPILER_VAR_548 = v;
char ** ____BAH_COMPILER_VAR_550 = (char **)((char*)(____BAH_COMPILER_VAR_548) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_551 = __reflect(____BAH_COMPILER_VAR_550, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_552 = (char **)((char*)(____BAH_COMPILER_VAR_548) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_553 = __reflect(____BAH_COMPILER_VAR_552, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_554 = (char*)((char*)(____BAH_COMPILER_VAR_548) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_555 = __reflect(____BAH_COMPILER_VAR_554, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_556 = (char **)((char*)(____BAH_COMPILER_VAR_548) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_557 = __reflect(____BAH_COMPILER_VAR_556, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_558 = (char*)((char*)(____BAH_COMPILER_VAR_548) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_559 = __reflect(____BAH_COMPILER_VAR_558, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_560 = (char **)((char*)(____BAH_COMPILER_VAR_548) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_561 = __reflect(____BAH_COMPILER_VAR_560, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_562 = (char*)((char*)(____BAH_COMPILER_VAR_548) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_563 = __reflect(____BAH_COMPILER_VAR_562, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_564 = (char*)((char*)(____BAH_COMPILER_VAR_548) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_565 = __reflect(____BAH_COMPILER_VAR_564, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_549 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_549->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_549->length = 8;
        ____BAH_COMPILER_VAR_549->data = memoryAlloc(____BAH_COMPILER_VAR_549->length * ____BAH_COMPILER_VAR_549->elemSize);
        ____BAH_COMPILER_VAR_549->data[0] = ____BAH_COMPILER_VAR_551;
____BAH_COMPILER_VAR_549->data[1] = ____BAH_COMPILER_VAR_553;
____BAH_COMPILER_VAR_549->data[2] = ____BAH_COMPILER_VAR_555;
____BAH_COMPILER_VAR_549->data[3] = ____BAH_COMPILER_VAR_557;
____BAH_COMPILER_VAR_549->data[4] = ____BAH_COMPILER_VAR_559;
____BAH_COMPILER_VAR_549->data[5] = ____BAH_COMPILER_VAR_561;
____BAH_COMPILER_VAR_549->data[6] = ____BAH_COMPILER_VAR_563;
____BAH_COMPILER_VAR_549->data[7] = ____BAH_COMPILER_VAR_565;
struct reflectElement ____BAH_COMPILER_VAR_566 = __reflect(____BAH_COMPILER_VAR_548, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_549, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_566);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_567 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_567 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_567+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_567+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_567));
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
char * ____BAH_COMPILER_VAR_568 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_568+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_568+currStrOff, "\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_568));
}
else {
char * ____BAH_COMPILER_VAR_569 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_569 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_569+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_569+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_569));
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2502");
                        };
                        struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_570 =null;char * ____BAH_COMPILER_VAR_571 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_571);
;                            
                    ____BAH_COMPILER_VAR_570 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_570+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_570+currStrOff, ____BAH_COMPILER_VAR_571, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_570;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_572 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_572 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_572+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_572+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_572;
}
};
char * ____BAH_COMPILER_VAR_573 =null;char * ____BAH_COMPILER_VAR_574 =tmpfnRetCType.str(&tmpfnRetCType);
                {
                    long int currStrOff = 0;
                    long int strLen_1 = strlen(____BAH_COMPILER_VAR_574);
long int strLen_3 = strlen(" (*");
long int strLen_5 = strlen(elemName);
long int strLen_7 = strlen(")(");
long int strLen_9 = strlen(tmpfnArgsCType);
long int strLen_11 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_573 = memoryAllocSTR(1 + strLen_1 + strLen_3 + strLen_5 + strLen_7 + strLen_9 + strLen_11);
                    
                        memcpy(____BAH_COMPILER_VAR_573+currStrOff, ____BAH_COMPILER_VAR_574, strLen_1);
                        currStrOff += strLen_1;
                        
                        memcpy(____BAH_COMPILER_VAR_573+currStrOff, " (*", strLen_3);
                        currStrOff += strLen_3;
                        
                        memcpy(____BAH_COMPILER_VAR_573+currStrOff, elemName, strLen_5);
                        currStrOff += strLen_5;
                        
                        memcpy(____BAH_COMPILER_VAR_573+currStrOff, ")(", strLen_7);
                        currStrOff += strLen_7;
                        
                        memcpy(____BAH_COMPILER_VAR_573+currStrOff, tmpfnArgsCType, strLen_9);
                        currStrOff += strLen_9;
                        
                        memcpy(____BAH_COMPILER_VAR_573+currStrOff, ")", strLen_11);
                        currStrOff += strLen_11;
                        
                }
                return ____BAH_COMPILER_VAR_573;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
long int j = *i;

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2518");
                        };
                        struct Tok ft = l->data[j];
char * tpdf = "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_575 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(prev);
long int strLen_4 = strlen(ft.cont);
;                            
                    ____BAH_COMPILER_VAR_575 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_575+currStrOff, prev, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_575+currStrOff, ft.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fn->name = ____BAH_COMPILER_VAR_575;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_576 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fn->name);
long int strLen_4 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_576 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_576+currStrOff, fn->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_576+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * code = ____BAH_COMPILER_VAR_576;
j = j+2;

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2532");
                        };
                        struct Tok t = l->data[j];
if ((strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2536");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2546");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2553");
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
char * ____BAH_COMPILER_VAR_577 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(argType);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_577 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_577+currStrOff, argType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_577+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                argType = ____BAH_COMPILER_VAR_577;
}
}
else {
isComa = true;
break;
}
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_578 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_578->name = "";
____BAH_COMPILER_VAR_578->type = "";
____BAH_COMPILER_VAR_578->isConst = false;
____BAH_COMPILER_VAR_578->constVal = "";
____BAH_COMPILER_VAR_578->isArray = false;
____BAH_COMPILER_VAR_578->from = "";
____BAH_COMPILER_VAR_578->outterScope = false;
____BAH_COMPILER_VAR_578->isGlobal = false;
struct variable* argument = ____BAH_COMPILER_VAR_578;
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
char * ____BAH_COMPILER_VAR_579 =null;char * ____BAH_COMPILER_VAR_580 =cfrt.str(&cfrt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__BAH_ARR_TYPE_");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_580);
;                            
                    ____BAH_COMPILER_VAR_579 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_579+currStrOff, "__BAH_ARR_TYPE_", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_579+currStrOff, ____BAH_COMPILER_VAR_580, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                newArgType = ____BAH_COMPILER_VAR_579;
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
char * ____BAH_COMPILER_VAR_581 =null;char * ____BAH_COMPILER_VAR_582 =argCType.str(&argCType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tpdf);
long int strLen_4 = strlen("typedef ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_582);
long int strLen_8 = strlen(" ");
long int strLen_10 = strlen(newArgType);
long int strLen_12 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_581 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_581+currStrOff, tpdf, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_581+currStrOff, "typedef ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_581+currStrOff, ____BAH_COMPILER_VAR_582, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_581+currStrOff, " ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_581+currStrOff, newArgType, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_581+currStrOff, ";\n", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                tpdf = ____BAH_COMPILER_VAR_581;
}
}
if ((cfrt.hasPrefix(&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_583 =null;char * ____BAH_COMPILER_VAR_584 =getCfunctionType(cfrt,argName,elems);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_584);
;                            
                    ____BAH_COMPILER_VAR_583 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_583+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_583+currStrOff, ____BAH_COMPILER_VAR_584, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_583;
}
else {
char * ____BAH_COMPILER_VAR_585 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(newArgType);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(argName);
;                            
                    ____BAH_COMPILER_VAR_585 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_585+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_585+currStrOff, newArgType, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_585+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_585+currStrOff, argName, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                code = ____BAH_COMPILER_VAR_585;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_586 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_586 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_586+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_586+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_586;
}
else {
char * ____BAH_COMPILER_VAR_587 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_587 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_587+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_587+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_587;
break;
}
j = j+1;
};
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
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_589 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_589->name = "";
____BAH_COMPILER_VAR_589->type = "";
____BAH_COMPILER_VAR_589->isConst = false;
____BAH_COMPILER_VAR_589->constVal = "";
____BAH_COMPILER_VAR_589->isArray = false;
____BAH_COMPILER_VAR_589->from = "";
____BAH_COMPILER_VAR_589->outterScope = false;
____BAH_COMPILER_VAR_589->isGlobal = false;
struct variable* returns = ____BAH_COMPILER_VAR_589;
returns->type = "";
while ((j<len(l))) {

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2618");
                        };
                        t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_590 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(returns->type);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_590 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_590+currStrOff, returns->type, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_590+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                returns->type = ____BAH_COMPILER_VAR_590;
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
char * ____BAH_COMPILER_VAR_591 =null;char * ____BAH_COMPILER_VAR_592 =cfrt.str(&cfrt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__BAH_ARR_TYPE_");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_592);
;                            
                    ____BAH_COMPILER_VAR_591 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_591+currStrOff, "__BAH_ARR_TYPE_", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_591+currStrOff, ____BAH_COMPILER_VAR_592, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                newFnRetType = ____BAH_COMPILER_VAR_591;
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
char * ____BAH_COMPILER_VAR_593 =null;char * ____BAH_COMPILER_VAR_594 =fnRetType.str(&fnRetType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tpdf);
long int strLen_4 = strlen("typedef ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_594);
long int strLen_8 = strlen(" ");
long int strLen_10 = strlen(newFnRetType);
long int strLen_12 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_593 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_593+currStrOff, tpdf, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_593+currStrOff, "typedef ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_593+currStrOff, ____BAH_COMPILER_VAR_594, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_593+currStrOff, " ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_593+currStrOff, newFnRetType, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_593+currStrOff, ";\n", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                tpdf = ____BAH_COMPILER_VAR_593;
}
}
char * ____BAH_COMPILER_VAR_595 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tpdf);
long int strLen_4 = strlen(newFnRetType);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_595 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_595+currStrOff, tpdf, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_595+currStrOff, newFnRetType, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_595+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_595+currStrOff, code, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                code = ____BAH_COMPILER_VAR_595;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_596 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_596->name = "";
____BAH_COMPILER_VAR_596->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_596->members->length = 0;
            ____BAH_COMPILER_VAR_596->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_596->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_596->methods->length = 0;
            ____BAH_COMPILER_VAR_596->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_596->postCode = "";
____BAH_COMPILER_VAR_596->extendedFrom = "";
____BAH_COMPILER_VAR_596->isBinding = false;
____BAH_COMPILER_VAR_596->hasRCPmemb = false;
struct cStruct* s = ____BAH_COMPILER_VAR_596;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2668");
                        };
                        struct Tok nameToken = l->data[1];
long int i = 2;
char doesOutput = true;
if ((strcmp(nameToken.cont, "!") == 0)) {

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2672");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2688");
                        };
                        struct Tok st = l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(st.cont, "extend") == 0)) {
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2692");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2704");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2712");
                        };
                        struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_597 =null;char * ____BAH_COMPILER_VAR_598 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_598);
;                            
                    ____BAH_COMPILER_VAR_597 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_597+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_597+currStrOff, ____BAH_COMPILER_VAR_598, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_597;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_599 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_599 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_599+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_599+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_599;
}
};
char * ____BAH_COMPILER_VAR_600 =null;char * ____BAH_COMPILER_VAR_601 =tmpfnRetCType.str(&tmpfnRetCType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_601);
long int strLen_4 = strlen(" (*");
long int strLen_6 = strlen(em->name);
long int strLen_8 = strlen(")(");
long int strLen_10 = strlen(tmpfnArgsCType);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_600 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_600+currStrOff, ____BAH_COMPILER_VAR_601, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_600+currStrOff, " (*", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_600+currStrOff, em->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_600+currStrOff, ")(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_600+currStrOff, tmpfnArgsCType, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_600+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                membDeclStr = ____BAH_COMPILER_VAR_600;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2736");
                        };
                        struct func* emt = extdS->methods->data[k];
struct string mthdDecl = getCType(emt->returns->type,elems);
char * ____BAH_COMPILER_VAR_602 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(*");
long int strLen_4 = strlen(emt->name);
long int strLen_6 = strlen(")(");
;                            
                    ____BAH_COMPILER_VAR_602 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_602+currStrOff, "(*", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_602+currStrOff, emt->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_602+currStrOff, ")(", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_602);
j = 0;
while ((j<len(emt->args))) {

                        if (emt->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: emt->args[%d] with length %d", j, emt->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2741");
                        };
                        struct variable* a = emt->args->data[j];
struct string tp = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_603 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_603 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_603+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_603+currStrOff, a->name, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tp.append(&tp,____BAH_COMPILER_VAR_603);
long int max = len(emt->args)-1;
if ((j!=max)) {
tp.append(&tp,",");
}
char * ____BAH_COMPILER_VAR_604 =tp.str(&tp);mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_604);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2760");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2768");
                        };
                        struct Tok t = l->data[i];
long int max = i+2;
if ((max>=len(l))) {
if (((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "}") == 0))) {
break;
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* ____BAH_COMPILER_VAR_605 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_605->name = "";
____BAH_COMPILER_VAR_605->type = "";
____BAH_COMPILER_VAR_605->isConst = false;
____BAH_COMPILER_VAR_605->constVal = "";
____BAH_COMPILER_VAR_605->isArray = false;
____BAH_COMPILER_VAR_605->from = "";
____BAH_COMPILER_VAR_605->outterScope = false;
____BAH_COMPILER_VAR_605->isGlobal = false;
____BAH_COMPILER_VAR_605->def = "";
____BAH_COMPILER_VAR_605->isFn = false;
struct structMemb* memb = ____BAH_COMPILER_VAR_605;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name = t.cont;
long int ii = 0;
while ((ii<len(members))) {

                        if (members->length <= ii) {
                            char buff[300];
                            snprintf(buff, 299, "array: members[%d] with length %d", ii, members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2782");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2789");
                        };
                        t = l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_606 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s->name);
long int strLen_4 = strlen("__");
;                            
                    ____BAH_COMPILER_VAR_606 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_606+currStrOff, s->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_606+currStrOff, "__", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * fnPrefix = ____BAH_COMPILER_VAR_606;
struct func* ____BAH_COMPILER_VAR_607 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_607->name = "";
____BAH_COMPILER_VAR_607->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_607->args->length = 0;
            ____BAH_COMPILER_VAR_607->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_607->returns= null;
____BAH_COMPILER_VAR_607->isBinding = false;
____BAH_COMPILER_VAR_607->from = "";
____BAH_COMPILER_VAR_607->file = "";
____BAH_COMPILER_VAR_607->line = 1;
____BAH_COMPILER_VAR_607->used = false;
____BAH_COMPILER_VAR_607->code = null;
struct func* fn = ____BAH_COMPILER_VAR_607;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int j = i-1;
while ((j<len(l))) {

                        if (l->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", j, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2798");
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
char * ____BAH_COMPILER_VAR_608 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(s->name);
long int strLen_4 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_608 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_608+currStrOff, s->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_608+currStrOff, "*", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_608;
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2814");
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
char * ____BAH_COMPILER_VAR_609 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_609);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2843");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2854");
                        };
                        t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
i = i+1;
}
while ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2859");
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
struct func* ____BAH_COMPILER_VAR_610 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_610->name = "";
____BAH_COMPILER_VAR_610->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_610->args->length = 0;
            ____BAH_COMPILER_VAR_610->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_610->returns= null;
____BAH_COMPILER_VAR_610->isBinding = false;
____BAH_COMPILER_VAR_610->from = "";
____BAH_COMPILER_VAR_610->file = "";
____BAH_COMPILER_VAR_610->line = 1;
____BAH_COMPILER_VAR_610->used = false;
____BAH_COMPILER_VAR_610->code = null;
struct func* mfn = ____BAH_COMPILER_VAR_610;
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
beginRCPscope(fn->args,elems);
parseLines(tokens,fnElems);
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_611 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Function '");
long int strLen_4 = strlen(fn->name);
long int strLen_6 = strlen("' is not returned.");
;                            
                    ____BAH_COMPILER_VAR_611 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_611+currStrOff, "Function '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_611+currStrOff, fn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_611+currStrOff, "' is not returned.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_611);
}
endRCPscope(fnElems,null);
decrRCPstackVars(fn->args,elems);
}
code = code->add(code, OUTPUT)->add(code->add(code, OUTPUT), rope("};\n"));
}
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_612 =null;char * ____BAH_COMPILER_VAR_613 =code->toStr(code);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(nextLine);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_613);
;                            
                    ____BAH_COMPILER_VAR_612 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_612+currStrOff, nextLine, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_612+currStrOff, ____BAH_COMPILER_VAR_613, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                nextLine = ____BAH_COMPILER_VAR_612;
}
struct string mthdDecl = getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_614 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(*");
long int strLen_4 = strlen(mfn->name);
long int strLen_6 = strlen(")(");
;                            
                    ____BAH_COMPILER_VAR_614 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_614+currStrOff, "(*", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_614+currStrOff, mfn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_614+currStrOff, ")(", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_614);
j = 0;
while ((j<len(arguments))) {

                        if (arguments->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: arguments[%d] with length %d", j, arguments->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2911");
                        };
                        struct variable* a = arguments->data[j];
struct string tp = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_615 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_615 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_615+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_615+currStrOff, a->name, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tp.append(&tp,____BAH_COMPILER_VAR_615);
max = len(arguments)-1;
if ((j!=max)) {
tp.append(&tp,",");
}
char * ____BAH_COMPILER_VAR_616 =tp.str(&tp);mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_616);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2933");
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
char * ____BAH_COMPILER_VAR_617 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(mbmType);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_617 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_617+currStrOff, mbmType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_617+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                mbmType = ____BAH_COMPILER_VAR_617;
i = i+1;
};
memb->type = mbmType;
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2948");
                        };
                        t = l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
i = i+1;

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2952");
                        };
                        t = l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char * ____BAH_COMPILER_VAR_618 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(memb->type);
long int strLen_10 = strlen(" for member.");
;                            
                    ____BAH_COMPILER_VAR_618 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_618+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_618+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_618+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_618+currStrOff, memb->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_618+currStrOff, " for member.", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&t,____BAH_COMPILER_VAR_618);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:2978");
                        };
                        struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_619 =null;char * ____BAH_COMPILER_VAR_620 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_620);
;                            
                    ____BAH_COMPILER_VAR_619 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_619+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_619+currStrOff, ____BAH_COMPILER_VAR_620, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_619;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_621 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_621 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_621+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_621+currStrOff, ",", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_621;
}
};
char * ____BAH_COMPILER_VAR_622 =null;char * ____BAH_COMPILER_VAR_623 =tmpfnRetCType.str(&tmpfnRetCType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_623);
long int strLen_4 = strlen(" (*");
long int strLen_6 = strlen(memb->name);
long int strLen_8 = strlen(")(");
long int strLen_10 = strlen(tmpfnArgsCType);
long int strLen_12 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_622 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_622+currStrOff, ____BAH_COMPILER_VAR_623, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_622+currStrOff, " (*", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_622+currStrOff, memb->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_622+currStrOff, ")(", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_622+currStrOff, tmpfnArgsCType, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_622+currStrOff, ")", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                membDeclStr = ____BAH_COMPILER_VAR_622;
}
else {
struct string membDecl = getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_624 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(memb->name);
;                            
                    ____BAH_COMPILER_VAR_624 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_624+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_624+currStrOff, memb->name, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                membDecl.append(&membDecl,____BAH_COMPILER_VAR_624);
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
char * ____BAH_COMPILER_VAR_625 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct ");
long int strLen_2 = strlen(s->name);
long int strLen_4 = strlen(" {\n");
;                            
                    ____BAH_COMPILER_VAR_625 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_625+currStrOff, "struct ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_625+currStrOff, s->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_625+currStrOff, " {\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                struct rope* code = rope(____BAH_COMPILER_VAR_625);
i = 0;
while ((i<len(allMembs))) {

                        if (allMembs->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: allMembs[%d] with length %d", i, allMembs->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3001");
                        };
                        char * m = allMembs->data[i];
char * ____BAH_COMPILER_VAR_626 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(m);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_626 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_626+currStrOff, m, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_626+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                code = code->add(code, rope(____BAH_COMPILER_VAR_626));
i = i+1;
};
code = code->add(code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, code);
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_627 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_627->name= null;
____BAH_COMPILER_VAR_627->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_627->membs->length = 0;
            ____BAH_COMPILER_VAR_627->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_627;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {

                        if (s->members->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: s->members[%d] with length %d", i, s->members->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3018");
                        };
                        struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_628 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_628->name = "";
____BAH_COMPILER_VAR_628->type = "";
____BAH_COMPILER_VAR_628->isConst = false;
____BAH_COMPILER_VAR_628->constVal = "";
____BAH_COMPILER_VAR_628->isArray = false;
____BAH_COMPILER_VAR_628->from = "";
____BAH_COMPILER_VAR_628->outterScope = false;
____BAH_COMPILER_VAR_628->isGlobal = false;
struct variable* mv = ____BAH_COMPILER_VAR_628;
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
struct debugStruct* ____BAH_COMPILER_VAR_629 = ds;
char ** ____BAH_COMPILER_VAR_631 = (char **)((char*)(____BAH_COMPILER_VAR_629) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_632 = __reflect(____BAH_COMPILER_VAR_631, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_633 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_629) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_634 = 0;
char ** ____BAH_COMPILER_VAR_636 = (char **)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_637 = __reflect(____BAH_COMPILER_VAR_636, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_638 = (char **)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_639 = __reflect(____BAH_COMPILER_VAR_638, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_640 = (char*)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_641 = __reflect(____BAH_COMPILER_VAR_640, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_642 = (char **)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_643 = __reflect(____BAH_COMPILER_VAR_642, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_644 = (char*)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_645 = __reflect(____BAH_COMPILER_VAR_644, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_646 = (char **)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_647 = __reflect(____BAH_COMPILER_VAR_646, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_648 = (char*)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_649 = __reflect(____BAH_COMPILER_VAR_648, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_650 = (char*)((char*)(____BAH_COMPILER_VAR_634) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_651 = __reflect(____BAH_COMPILER_VAR_650, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_635 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_635->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_635->length = 8;
        ____BAH_COMPILER_VAR_635->data = memoryAlloc(____BAH_COMPILER_VAR_635->length * ____BAH_COMPILER_VAR_635->elemSize);
        ____BAH_COMPILER_VAR_635->data[0] = ____BAH_COMPILER_VAR_637;
____BAH_COMPILER_VAR_635->data[1] = ____BAH_COMPILER_VAR_639;
____BAH_COMPILER_VAR_635->data[2] = ____BAH_COMPILER_VAR_641;
____BAH_COMPILER_VAR_635->data[3] = ____BAH_COMPILER_VAR_643;
____BAH_COMPILER_VAR_635->data[4] = ____BAH_COMPILER_VAR_645;
____BAH_COMPILER_VAR_635->data[5] = ____BAH_COMPILER_VAR_647;
____BAH_COMPILER_VAR_635->data[6] = ____BAH_COMPILER_VAR_649;
____BAH_COMPILER_VAR_635->data[7] = ____BAH_COMPILER_VAR_651;
struct reflectElement ____BAH_COMPILER_VAR_652 = __reflect(____BAH_COMPILER_VAR_634, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_635, 0);

        struct reflectElement ____BAH_COMPILER_VAR_653 = ____BAH_COMPILER_VAR_652;
        struct reflectElement ____BAH_COMPILER_VAR_654 = __reflect(____BAH_COMPILER_VAR_633, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_653, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_630 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_630->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_630->length = 2;
        ____BAH_COMPILER_VAR_630->data = memoryAlloc(____BAH_COMPILER_VAR_630->length * ____BAH_COMPILER_VAR_630->elemSize);
        ____BAH_COMPILER_VAR_630->data[0] = ____BAH_COMPILER_VAR_632;
____BAH_COMPILER_VAR_630->data[1] = ____BAH_COMPILER_VAR_654;
struct reflectElement ____BAH_COMPILER_VAR_655 = __reflect(____BAH_COMPILER_VAR_629, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_630, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_655);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3040");
                        };
                        struct Tok ft = l->data[1];

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3041");
                        };
                        struct Tok st = l->data[2];
long int i = 1;
char doesOutput = true;
if ((strcmp(ft.cont, "!") == 0)) {

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3046");
                        };
                        ft = l->data[2];

                        if (l->length <= 3) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 3, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3047");
                        };
                        st = l->data[3];
i = 2;
doesOutput = false;
}
if ((strcmp(st.cont, "(") == 0)) {
struct func* ____BAH_COMPILER_VAR_656 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_656->name = "";
____BAH_COMPILER_VAR_656->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_656->args->length = 0;
            ____BAH_COMPILER_VAR_656->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_656->returns= null;
____BAH_COMPILER_VAR_656->isBinding = false;
____BAH_COMPILER_VAR_656->from = "";
____BAH_COMPILER_VAR_656->file = "";
____BAH_COMPILER_VAR_656->line = 1;
____BAH_COMPILER_VAR_656->used = false;
____BAH_COMPILER_VAR_656->code = null;
struct func* fn = ____BAH_COMPILER_VAR_656;
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
char * ____BAH_COMPILER_VAR_657 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_657 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_657+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_657+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_657));
}
}
else {
char * tp = "";
i = i+1;
for (; (i<len(l)); i = i+1) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3066");
                        };
                        struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_658 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tp);
long int strLen_4 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_658 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_658+currStrOff, tp, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_658+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tp = ____BAH_COMPILER_VAR_658;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = cTypeNewType.str(&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_659 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("typedef ");
long int strLen_2 = strlen(cTypeNewTypeStr);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(ft.cont);
long int strLen_8 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_659 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_659+currStrOff, "typedef ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_659+currStrOff, cTypeNewTypeStr, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_659+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_659+currStrOff, ft.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_659+currStrOff, ";\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_659));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_660 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_660->name= null;
____BAH_COMPILER_VAR_660->refers= null;
struct debugType* dt = ____BAH_COMPILER_VAR_660;
dt->name = ft.cont;
dt->refers = tp;
struct debugType* ____BAH_COMPILER_VAR_661 = dt;
char ** ____BAH_COMPILER_VAR_663 = (char **)((char*)(____BAH_COMPILER_VAR_661) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_664 = __reflect(____BAH_COMPILER_VAR_663, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_665 = (char **)((char*)(____BAH_COMPILER_VAR_661) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_666 = __reflect(____BAH_COMPILER_VAR_665, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_662 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_662->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_662->length = 2;
        ____BAH_COMPILER_VAR_662->data = memoryAlloc(____BAH_COMPILER_VAR_662->length * ____BAH_COMPILER_VAR_662->elemSize);
        ____BAH_COMPILER_VAR_662->data[0] = ____BAH_COMPILER_VAR_664;
____BAH_COMPILER_VAR_662->data[1] = ____BAH_COMPILER_VAR_666;
struct reflectElement ____BAH_COMPILER_VAR_667 = __reflect(____BAH_COMPILER_VAR_661, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_662, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_667);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3096");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3108");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3131");
                        };
                        struct Tok vart = l->data[1];

                        if (l->length <= 2) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 2, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3132");
                        };
                        struct Tok equt = l->data[2];

                        if (l->length <= 3) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 3, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3133");
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
struct variable* ____BAH_COMPILER_VAR_668 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_668->name = "";
____BAH_COMPILER_VAR_668->type = "";
____BAH_COMPILER_VAR_668->isConst = false;
____BAH_COMPILER_VAR_668->constVal = "";
____BAH_COMPILER_VAR_668->isArray = false;
____BAH_COMPILER_VAR_668->from = "";
____BAH_COMPILER_VAR_668->outterScope = false;
____BAH_COMPILER_VAR_668->isGlobal = false;
struct variable* v = ____BAH_COMPILER_VAR_668;
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
char * ____BAH_COMPILER_VAR_669 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(valt.cont);
long int strLen_8 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_669 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_669+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_669+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_669+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_669+currStrOff, valt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_669+currStrOff, "\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_669));
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
char * ____BAH_COMPILER_VAR_670 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot return nothing as ");
long int strLen_4 = strlen(currentFn->returns->type);
long int strLen_6 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_670 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_670+currStrOff, "Cannot return nothing as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_670+currStrOff, currentFn->returns->type, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_670+currStrOff, ".", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&l->data[0],____BAH_COMPILER_VAR_670);
}
}
else {

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3184");
                        };
                        struct Tok rvt = l->data[1];
if ((rvt.isValue==false)) {
throwErr(&rvt,"Must be a value, not {TOKEN}.");
}
else if (((rvt.type==TOKEN_TYPE_VAR)&&(rvt.isOper==false))) {
struct variable* v = searchVar(rvt.cont,elems);
tmpV = v;
if (((((v!=null)&&(isRCPtype(v->type,elems)==true))&&(v->outterScope==false))&&(RCPavailable()==true))) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(v,elems));
}
}
rv = rvt.cont;
tt = getTypeFromToken(&rvt,true,elems);
if ((compTypes(tt,currentFn->returns->type)==false)) {
char * ____BAH_COMPILER_VAR_671 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot return {TOKEN} (");
long int strLen_4 = strlen(tt);
long int strLen_6 = strlen(") as ");
long int strLen_8 = strlen(currentFn->returns->type);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_671 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_671+currStrOff, "Cannot return {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_671+currStrOff, tt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_671+currStrOff, ") as ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_671+currStrOff, currentFn->returns->type, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_671+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&rvt,____BAH_COMPILER_VAR_671);
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
char * ____BAH_COMPILER_VAR_672 =null;char * ____BAH_COMPILER_VAR_673 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_673);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(rvar);
long int strLen_6 = strlen(" = ");
long int strLen_8 = strlen(rv);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_672 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, ____BAH_COMPILER_VAR_673, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, rvar, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, " = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, rv, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_672+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_672));
}
endRCPnonGlobScope(elems,currentFn->args);
if (strHasPrefix(tt,"buffer:")) {
char * ____BAH_COMPILER_VAR_674 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__STR(");
long int strLen_4 = strlen(rvar);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_674 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_674+currStrOff, "__STR(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_674+currStrOff, rvar, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_674+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                rvar = ____BAH_COMPILER_VAR_674;
}
decrRCPstackVars(currentFn->args,elems);
char * ____BAH_COMPILER_VAR_675 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("return ");
long int strLen_2 = strlen(rvar);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_675 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_675+currStrOff, "return ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_675+currStrOff, rvar, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_675+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_675));
}
else {
endRCPnonGlobScope(elems,currentFn->args);
decrRCPstackVars(currentFn->args,elems);
OUTPUT = OUTPUT->add(OUTPUT, rope("return;\n"));
}
};
void parseIf(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3227");
                        };
                        struct Tok ft = l->data[0];
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3230");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3236");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3243");
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
char * ____BAH_COMPILER_VAR_676 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("if (");
long int strLen_2 = strlen(condt.cont);
long int strLen_4 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_676 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_676+currStrOff, "if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_676+currStrOff, condt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_676+currStrOff, ") {\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_676));
struct Elems* ifElems = dupElems(elems);
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
parseLines(tokens,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                        if (l->length <= len(l)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", len(l)-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3256");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3275");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3280");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3293");
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
parseLines(memory,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                        if (l->length <= len(l)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", len(l)-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3304");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3323");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3339");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3344");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3352");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3359");
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
char * ____BAH_COMPILER_VAR_677 =OUTPUT->toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_677);
OUTPUT = oldOut;
instC.trimRight(&instC,2);

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3375");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3382");
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
char * ____BAH_COMPILER_VAR_678 =null;char * ____BAH_COMPILER_VAR_679 =instC.str(&instC);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("for (; ");
long int strLen_2 = strlen(condt.cont);
long int strLen_4 = strlen("; ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_679);
long int strLen_8 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_678 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_678+currStrOff, "for (; ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_678+currStrOff, condt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_678+currStrOff, "; ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_678+currStrOff, ____BAH_COMPILER_VAR_679, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_678+currStrOff, ") {\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_678));
}
else {

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3389");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3395");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3401");
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
char * ____BAH_COMPILER_VAR_680 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("while (");
long int strLen_2 = strlen(condt.cont);
long int strLen_4 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_680 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_680+currStrOff, "while (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_680+currStrOff, condt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_680+currStrOff, ") {\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_680));
}
struct Elems* ifElems = dupElems(elems);
char oldIB = compilerState.isBranch;
char oldIF = compilerState.isFor;
compilerState.isBranch = true;
compilerState.isFor = true;
parseLines(tokens,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                        if (l->length <= len(l)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", len(l)-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3415");
                        };
                        struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isFor = oldIF;
compilerState.isBranch = oldIB;
OUTPUT = OUTPUT->add(OUTPUT, rope("};\n"));
};
void parseForOp(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3426");
                        };
                        struct Tok ft = l->data[0];
if ((compilerState.isFor==false)) {
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}
if ((len(l)!=1)) {
throwErr(&ft,"Nothing expected after {TOKEN}.");
}
endRCPscope(elems,null);
char * ____BAH_COMPILER_VAR_681 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_681 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_681+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_681+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_681));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

                int ____BAH_COMPILER_VAR_682 = 0;
                for(int i=len(compilerState.evals)-1; i != -1; i--) {
                    if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                        ____BAH_COMPILER_VAR_682 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_682) {
return;
}
char * ____BAH_COMPILER_VAR_683 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("__Bah_eval_");
long int strLen_4 = strlen(fn->name);
;                            
                    ____BAH_COMPILER_VAR_683 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_683+currStrOff, "__Bah_eval_", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_683+currStrOff, fn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                struct func* ____BAH_COMPILER_VAR_684 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_684->name = "";
____BAH_COMPILER_VAR_684->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_684->args->length = 0;
            ____BAH_COMPILER_VAR_684->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_684->returns= null;
____BAH_COMPILER_VAR_684->isBinding = false;
____BAH_COMPILER_VAR_684->from = "";
____BAH_COMPILER_VAR_684->file = "";
____BAH_COMPILER_VAR_684->line = 1;
____BAH_COMPILER_VAR_684->used = false;
____BAH_COMPILER_VAR_684->code = null;
____BAH_COMPILER_VAR_684->name = ____BAH_COMPILER_VAR_683;
struct func* efn = ____BAH_COMPILER_VAR_684;
struct variable* ____BAH_COMPILER_VAR_685 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_685->name = "";
____BAH_COMPILER_VAR_685->type = "";
____BAH_COMPILER_VAR_685->isConst = false;
____BAH_COMPILER_VAR_685->constVal = "";
____BAH_COMPILER_VAR_685->isArray = false;
____BAH_COMPILER_VAR_685->from = "";
____BAH_COMPILER_VAR_685->outterScope = false;
____BAH_COMPILER_VAR_685->isGlobal = false;
____BAH_COMPILER_VAR_685->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_685;
struct variable* ____BAH_COMPILER_VAR_686 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_686->name = "";
____BAH_COMPILER_VAR_686->type = "";
____BAH_COMPILER_VAR_686->isConst = false;
____BAH_COMPILER_VAR_686->constVal = "";
____BAH_COMPILER_VAR_686->isArray = false;
____BAH_COMPILER_VAR_686->from = "";
____BAH_COMPILER_VAR_686->outterScope = false;
____BAH_COMPILER_VAR_686->isGlobal = false;
____BAH_COMPILER_VAR_686->name = "fnArgs";
____BAH_COMPILER_VAR_686->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);efn->args->data[0] = ____BAH_COMPILER_VAR_686;
char * fnBinding = "";
char * ____BAH_COMPILER_VAR_687 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fn->name);
long int strLen_4 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_687 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_687+currStrOff, fn->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_687+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * fnCall = ____BAH_COMPILER_VAR_687;
long int i = 0;
for (; (i<len(fn->args)); i = i+1) {

                        if (fn->args->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", i, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3461");
                        };
                        struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
cType.append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_688 =null;char * ____BAH_COMPILER_VAR_689 =cType.str(&cType);char * ____BAH_COMPILER_VAR_690 =intToStr(i);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_689);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(v);
long int strLen_8 = strlen(" = fnArgs->data[");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_690);
long int strLen_12 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_688 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_688+currStrOff, ____BAH_COMPILER_VAR_689, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_688+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_688+currStrOff, v, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_688+currStrOff, " = fnArgs->data[", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_688+currStrOff, ____BAH_COMPILER_VAR_690, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_688+currStrOff, "];", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                char * ____BAH_COMPILER_VAR_691 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnBinding);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_688);
;                            
                    ____BAH_COMPILER_VAR_691 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_691+currStrOff, fnBinding, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_691+currStrOff, ____BAH_COMPILER_VAR_688, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fnBinding = ____BAH_COMPILER_VAR_691;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_692 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_2 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_692 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_692+currStrOff, fnCall, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_692+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fnCall = ____BAH_COMPILER_VAR_692;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_693 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_2 = strlen(v);
;                            
                    ____BAH_COMPILER_VAR_693 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_693+currStrOff, fnCall, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_693+currStrOff, v, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fnCall = ____BAH_COMPILER_VAR_693;
}
else {
char * ____BAH_COMPILER_VAR_694 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("*");
long int strLen_4 = strlen(v);
;                            
                    ____BAH_COMPILER_VAR_694 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_694+currStrOff, "*", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_694+currStrOff, v, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                char * ____BAH_COMPILER_VAR_695 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_694);
;                            
                    ____BAH_COMPILER_VAR_695 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_695+currStrOff, fnCall, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_695+currStrOff, ____BAH_COMPILER_VAR_694, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                fnCall = ____BAH_COMPILER_VAR_695;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(cType.str(&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_696 =null;char * ____BAH_COMPILER_VAR_697 =cType.str(&cType);char * ____BAH_COMPILER_VAR_698 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(____BAH_COMPILER_VAR_697);
long int strLen_4 = strlen("* r = memoryAlloc(sizeof(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_698);
long int strLen_8 = strlen("));*r = ");
;                            
                    ____BAH_COMPILER_VAR_696 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_696+currStrOff, ____BAH_COMPILER_VAR_697, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_696+currStrOff, "* r = memoryAlloc(sizeof(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_696+currStrOff, ____BAH_COMPILER_VAR_698, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_696+currStrOff, "));*r = ", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                setReturnValue = ____BAH_COMPILER_VAR_696;
}
}
char * ____BAH_COMPILER_VAR_699 =null;char * ____BAH_COMPILER_VAR_700 =intToStr(len(fn->args));
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("void* __attribute__((optimize(\"O0\"))) ");
long int strLen_2 = strlen(efn->name);
long int strLen_4 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_700);
long int strLen_8 = strlen(") {\n            __BAH_panic((char*)\"eval: calling function ");
long int strLen_10 = strlen(fn->name);
long int strLen_12 = strlen("() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ");
long int strLen_14 = strlen(fnBinding);
long int strLen_16 = strlen("\n        ");
long int strLen_18 = strlen(setReturnValue);
long int strLen_20 = strlen(fnCall);
long int strLen_22 = strlen(");\n        return (void*)r;\n    };");
;                            
                    ____BAH_COMPILER_VAR_699 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22);
                    
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, efn->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, ____BAH_COMPILER_VAR_700, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, ") {\n            __BAH_panic((char*)\"eval: calling function ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, fn->name, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, fnBinding, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, "\n        ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, setReturnValue, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, fnCall, strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_699+currStrOff, ");\n        return (void*)r;\n    };", strLen_22);
                        currStrOff += strLen_22;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_699));

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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3503");
                        };
                        struct Tok ft = l->data[0];
if ((strcmp(ft.cont, "#warning") == 0)) {
if ((len(l)!=2)) {
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3509");
                        };
                        struct Tok mt = l->data[1];
if ((mt.type!=TOKEN_TYPE_STR)) {
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}
struct string msg = string(mt.cont);
msg.trimLeft(&msg,1);
msg.trimRight(&msg,1);
char * ____BAH_COMPILER_VAR_701 =msg.str(&msg);throwWarning(____BAH_COMPILER_VAR_701);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

                int ____BAH_COMPILER_VAR_702 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                        ____BAH_COMPILER_VAR_702 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_702==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_703 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
long int strLen_4 = strlen(BAH_DIR);
long int strLen_6 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_703 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_703+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_703+currStrOff, BAH_DIR, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_703+currStrOff, ").", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&l->data[0],____BAH_COMPILER_VAR_703);
}
}
if (((len(l)!=2)||(isGlobal()==false))) {
throwErr(&l->data[0],"Invalid usage of {TOKEN} <#eval fnName>.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3536");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3550");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3605");
                        };
                        struct Tok st = l->data[1];

                        if (l->length <= len(l)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", len(l)-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3606");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3613");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3623");
                        };
                        struct Tok ft = l->data[0];
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}

                        if (l->length <= 1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3626");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3633");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3646");
                        };
                        struct string fnName = fnNameParts->data[0];
char * ____BAH_COMPILER_VAR_704 =fnName.str(&fnName);struct func* fn = searchFunc(____BAH_COMPILER_VAR_704,elems,true);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_705 =null;char * ____BAH_COMPILER_VAR_706 =fnName.str(&fnName);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Internal compiler error.\n Error parsing async call for function '");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_706);
long int strLen_6 = strlen("', arround {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_705 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_705+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_705+currStrOff, ____BAH_COMPILER_VAR_706, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_705+currStrOff, "', arround {TOKEN}.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&fnT,____BAH_COMPILER_VAR_705);
}
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {

                        if (fn->args->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", i, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3657");
                        };
                        struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_707 =null;char * ____BAH_COMPILER_VAR_708 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(sMembs);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_708);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(a->name);
long int strLen_10 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_707 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_707+currStrOff, sMembs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_707+currStrOff, ____BAH_COMPILER_VAR_708, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_707+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_707+currStrOff, a->name, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_707+currStrOff, ";\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                sMembs = ____BAH_COMPILER_VAR_707;
char * ____BAH_COMPILER_VAR_709 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(unSerMembs);
long int strLen_4 = strlen("args->");
long int strLen_6 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_709 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_709+currStrOff, unSerMembs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_709+currStrOff, "args->", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_709+currStrOff, a->name, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                unSerMembs = ____BAH_COMPILER_VAR_709;
i = i+1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_710 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(unSerMembs);
long int strLen_4 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_710 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_710+currStrOff, unSerMembs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_710+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                unSerMembs = ____BAH_COMPILER_VAR_710;
}
};
char * ____BAH_COMPILER_VAR_711 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("struct {\n");
long int strLen_4 = strlen(sMembs);
long int strLen_6 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_711 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_711+currStrOff, "struct {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_711+currStrOff, sMembs, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_711+currStrOff, "}", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                char * tmpArgsStruct = ____BAH_COMPILER_VAR_711;
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
char * ____BAH_COMPILER_VAR_712 =null;char * ____BAH_COMPILER_VAR_713 =fnName.str(&fnName);char * ____BAH_COMPILER_VAR_714 =sFnT.str(&sFnT);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    void ");
long int strLen_2 = strlen(fnWrapper);
long int strLen_4 = strlen("(");
long int strLen_6 = strlen(tmpArgsStruct);
long int strLen_8 = strlen("* args) {\n        ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_713);
long int strLen_12 = strlen("(");
long int strLen_14 = strlen(unSerMembs);
long int strLen_16 = strlen(");\n    };\n    {\n        ");
long int strLen_18 = strlen(tmpArgsStruct);
long int strLen_20 = strlen(" ");
long int strLen_22 = strlen(tmpArgs);
long int strLen_24 = strlen(" = {");
long int strLen_26 = strlen(____BAH_COMPILER_VAR_714);
long int strLen_28 = strlen("};\n        pthread_t id;\n        ");
long int strLen_30 = strlen(tCreate);
long int strLen_32 = strlen("(&id, 0, ");
long int strLen_34 = strlen(fnWrapper);
long int strLen_36 = strlen(", &");
long int strLen_38 = strlen(tmpArgs);
long int strLen_40 = strlen(");\n    }; \n    \n    ");
;                            
                    ____BAH_COMPILER_VAR_712 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34 + strLen_36 + strLen_38 + strLen_40);
                    
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, "\n    void ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, fnWrapper, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, tmpArgsStruct, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, "* args) {\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, ____BAH_COMPILER_VAR_713, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, "(", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, unSerMembs, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, ");\n    };\n    {\n        ", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, tmpArgsStruct, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, " ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, tmpArgs, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, " = {", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, ____BAH_COMPILER_VAR_714, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, "};\n        pthread_t id;\n        ", strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, tCreate, strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, "(&id, 0, ", strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, fnWrapper, strLen_34);
                        currStrOff += strLen_34;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, ", &", strLen_36);
                        currStrOff += strLen_36;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, tmpArgs, strLen_38);
                        currStrOff += strLen_38;
                        
                        memcpy(____BAH_COMPILER_VAR_712+currStrOff, ");\n    }; \n    \n    ", strLen_40);
                        currStrOff += strLen_40;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_712));
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3705");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3722");
                        };
                        struct Tok t = l->data[i];
if ((((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "->") == 0))||(strcmp(t.cont, "<-") == 0))) {
if ((strcmp(t.cont, "<-") == 0)) {
i = i+1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3728");
                        };
                        struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_715 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_715);
if ((ntt.hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_716 =null;char * ____BAH_COMPILER_VAR_717 =ntt.str(&ntt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use var {TOKEN} (");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_717);
long int strLen_6 = strlen(") as channel.");
;                            
                    ____BAH_COMPILER_VAR_716 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_716+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_716+currStrOff, ____BAH_COMPILER_VAR_717, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_716+currStrOff, ") as channel.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&nt,____BAH_COMPILER_VAR_716);
}
ntt.trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_718 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_718)) {
char * ____BAH_COMPILER_VAR_719 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_719,elems);
char * ____BAH_COMPILER_VAR_720 =null;char * ____BAH_COMPILER_VAR_721 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_721);
long int strLen_6 = strlen(")");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("->receive(");
long int strLen_12 = strlen(nt.cont);
long int strLen_14 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_720 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_720+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_720+currStrOff, ____BAH_COMPILER_VAR_721, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_720+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_720+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_720+currStrOff, "->receive(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_720+currStrOff, nt.cont, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_720+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_720;
}
else {
char * ____BAH_COMPILER_VAR_722 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_722,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_723 =null;char * ____BAH_COMPILER_VAR_724 =ntt.str(&ntt);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_724);
long int strLen_2 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_723+currStrOff, ____BAH_COMPILER_VAR_724, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_723+currStrOff, "*", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                char * ____BAH_COMPILER_VAR_725 =null;char * ____BAH_COMPILER_VAR_726 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_4 = strlen("(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_726);
long int strLen_8 = strlen("*)");
long int strLen_10 = strlen(nt.cont);
long int strLen_12 = strlen("->receive(");
long int strLen_14 = strlen(nt.cont);
long int strLen_16 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_725 = memoryAllocSTR(1 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_725+currStrOff, "(", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_725+currStrOff, ____BAH_COMPILER_VAR_726, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_725+currStrOff, "*)", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_725+currStrOff, nt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_725+currStrOff, "->receive(", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_725+currStrOff, nt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_725+currStrOff, ")", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                tmpV = registerRCPvar(____BAH_COMPILER_VAR_723,____BAH_COMPILER_VAR_725,elems);
char * ____BAH_COMPILER_VAR_727 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("*");
long int strLen_4 = strlen(tmpV);
;                            
                    ____BAH_COMPILER_VAR_727 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_727+currStrOff, "*", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_727+currStrOff, tmpV, strLen_4);
                        currStrOff += strLen_4;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_727;
}
else {
char * ____BAH_COMPILER_VAR_728 =null;char * ____BAH_COMPILER_VAR_729 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("*(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_729);
long int strLen_6 = strlen("*)");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen("->receive(");
long int strLen_12 = strlen(nt.cont);
long int strLen_14 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_728 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14);
                    
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, "*(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, ____BAH_COMPILER_VAR_729, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, "*)", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, "->receive(", strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, nt.cont, strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_728+currStrOff, ")", strLen_14);
                        currStrOff += strLen_14;
                        
                }
                t.cont = ____BAH_COMPILER_VAR_728;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_730 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_730)) {
char * ____BAH_COMPILER_VAR_731 =ntt.str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_731,t.cont,elems);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3782");
                        };
                        struct Tok pt = l->data[i+1];

                        if (l->length <= i-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", i-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3783");
                        };
                        struct Tok nt = l->data[i-1];
char * ntt = getTypeFromToken(&nt,true,elems);
if ((pt.type!=TOKEN_TYPE_VAR)) {
throwErr(&pt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_732 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_732);
if ((ptt.hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_733 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot use var {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") as channel.");
;                            
                    ____BAH_COMPILER_VAR_733 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_733+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_733+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_733+currStrOff, ") as channel.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&pt,____BAH_COMPILER_VAR_733);
}
ptt.trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_734 =ptt.str(&ptt);if ((compTypes(____BAH_COMPILER_VAR_734,ntt)==false)) {
char * ____BAH_COMPILER_VAR_735 =null;char * ____BAH_COMPILER_VAR_736 =ptt.str(&ptt);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot send {TOKEN} (");
long int strLen_4 = strlen(ntt);
long int strLen_6 = strlen(") to channel of type ");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_736);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_735 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_735+currStrOff, "Cannot send {TOKEN} (", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_735+currStrOff, ntt, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_735+currStrOff, ") to channel of type ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_735+currStrOff, ____BAH_COMPILER_VAR_736, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_735+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&nt,____BAH_COMPILER_VAR_735);
}
i = i+1;
char * ____BAH_COMPILER_VAR_737 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_737)) {
char * ____BAH_COMPILER_VAR_738 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_2 = strlen("->send(");
long int strLen_4 = strlen(pt.cont);
long int strLen_6 = strlen(", ");
long int strLen_8 = strlen(nt.cont);
long int strLen_10 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_738 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, "->send(", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_738+currStrOff, ");\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_738));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_739 =null;char * ____BAH_COMPILER_VAR_740 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_740);
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
                    ____BAH_COMPILER_VAR_739 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, "\n                    ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, ____BAH_COMPILER_VAR_740, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, tmpV, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, " = ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, nt.cont, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, ";\n                    ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, pt.cont, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, "->sendAny(", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, pt.cont, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, ", &", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, tmpV, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, ", sizeof(", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, tmpV, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_739+currStrOff, "));\n", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_739));
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3841");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3848");
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

                int ____BAH_COMPILER_VAR_741 = 0;
                for(int i=len(comparators)-1; i != -1; i--) {
                    if (comparators->data[i] != 0 && strcmp(comparators->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_741 = 1;
                        break;
                    };
                };
                
                int ____BAH_COMPILER_VAR_742 = 0;
                for(int i=len(compSep)-1; i != -1; i--) {
                    if (compSep->data[i] != 0 && strcmp(compSep->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_742 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_741||____BAH_COMPILER_VAR_742)) {
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

                int ____BAH_COMPILER_VAR_743 = 0;
                for(int i=len(signs)-1; i != -1; i--) {
                    if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_743 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_743||strHasPrefix(t.cont,"-"))) {
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3930");
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
struct func* ____BAH_COMPILER_VAR_744 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_744->name = "";
____BAH_COMPILER_VAR_744->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_744->args->length = 0;
            ____BAH_COMPILER_VAR_744->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_744->returns= null;
____BAH_COMPILER_VAR_744->isBinding = false;
____BAH_COMPILER_VAR_744->from = "";
____BAH_COMPILER_VAR_744->file = "";
____BAH_COMPILER_VAR_744->line = 1;
____BAH_COMPILER_VAR_744->used = false;
____BAH_COMPILER_VAR_744->code = null;
struct func* fn = ____BAH_COMPILER_VAR_744;
if (((RCPavailable()==false)&&(RCPenabled==true))) {
fn->used = true;
}

                        if (l->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", 0, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3947");
                        };
                        struct Tok ft = l->data[0];
char * code = parseFnHeader("",l,&i,fn,elems);
fn->line = ft.line;
fn->file = compilerState.currentFile;
struct func* ogFn = searchFunc(fn->name,elems,false);
if ((ogFn!=null)) {
if ((ogFn->isBinding==false)) {
char * lineStr = intToStr(ogFn->line);
char * ____BAH_COMPILER_VAR_745 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
long int strLen_4 = strlen(ogFn->file);
long int strLen_6 = strlen(":");
long int strLen_8 = strlen(lineStr);
long int strLen_10 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_745 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_745+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_745+currStrOff, ogFn->file, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_745+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_745+currStrOff, lineStr, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_745+currStrOff, ".", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                throwErr(&ft,____BAH_COMPILER_VAR_745);
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3968");
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
char * ____BAH_COMPILER_VAR_746 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_746 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_746+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_746+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_746));
return;
}
char * ____BAH_COMPILER_VAR_747 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(code);
long int strLen_4 = strlen("{\n");
;                            
                    ____BAH_COMPILER_VAR_747 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_747+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_747+currStrOff, "{\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                code = ____BAH_COMPILER_VAR_747;
fn->code = rope(code);
struct Elems* fnElems = dupElems(elems);
array(struct variable*)* vs = fnElems->vars;
long int j = 0;
while ((j<len(fn->args))) {

                        if (fn->args->length <= j) {
                            char buff[300];
                            snprintf(buff, 299, "array: fn->args[%d] with length %d", j, fn->args->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:3993");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4013");
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
beginRCPscope(fn->args,elems);
parseLines(tokens,fnElems);
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_748 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen("Function '");
long int strLen_4 = strlen(fn->name);
long int strLen_6 = strlen("' is not returned.");
;                            
                    ____BAH_COMPILER_VAR_748 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_748+currStrOff, "Function '", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_748+currStrOff, fn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_748+currStrOff, "' is not returned.", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_748);
}
endRCPscope(fnElems,null);
decrRCPstackVars(fn->args,elems);
}
fn->code = fn->code->add(fn->code, OUTPUT);
OUTPUT = oOut;
fn->code = fn->code->add(fn->code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, fn->code);
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_749 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_749->name= null;
____BAH_COMPILER_VAR_749->returns= null;
____BAH_COMPILER_VAR_749->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_749->args->length = 0;
            ____BAH_COMPILER_VAR_749->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_749;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_750 = df;
char ** ____BAH_COMPILER_VAR_752 = (char **)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_753 = __reflect(____BAH_COMPILER_VAR_752, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_754 = (char **)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_755 = __reflect(____BAH_COMPILER_VAR_754, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_756 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_750) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_757 = 0;
char ** ____BAH_COMPILER_VAR_759 = (char **)((char*)(____BAH_COMPILER_VAR_757) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_760 = __reflect(____BAH_COMPILER_VAR_759, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_761 = (char **)((char*)(____BAH_COMPILER_VAR_757) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_762 = __reflect(____BAH_COMPILER_VAR_761, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_763 = (char*)((char*)(____BAH_COMPILER_VAR_757) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_764 = __reflect(____BAH_COMPILER_VAR_763, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_765 = (char **)((char*)(____BAH_COMPILER_VAR_757) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_766 = __reflect(____BAH_COMPILER_VAR_765, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_767 = (char*)((char*)(____BAH_COMPILER_VAR_757) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_768 = __reflect(____BAH_COMPILER_VAR_767, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_769 = (char **)((char*)(____BAH_COMPILER_VAR_757) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_770 = __reflect(____BAH_COMPILER_VAR_769, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_771 = (char*)((char*)(____BAH_COMPILER_VAR_757) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_772 = __reflect(____BAH_COMPILER_VAR_771, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_773 = (char*)((char*)(____BAH_COMPILER_VAR_757) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_774 = __reflect(____BAH_COMPILER_VAR_773, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_758 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_758->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_758->length = 8;
        ____BAH_COMPILER_VAR_758->data = memoryAlloc(____BAH_COMPILER_VAR_758->length * ____BAH_COMPILER_VAR_758->elemSize);
        ____BAH_COMPILER_VAR_758->data[0] = ____BAH_COMPILER_VAR_760;
____BAH_COMPILER_VAR_758->data[1] = ____BAH_COMPILER_VAR_762;
____BAH_COMPILER_VAR_758->data[2] = ____BAH_COMPILER_VAR_764;
____BAH_COMPILER_VAR_758->data[3] = ____BAH_COMPILER_VAR_766;
____BAH_COMPILER_VAR_758->data[4] = ____BAH_COMPILER_VAR_768;
____BAH_COMPILER_VAR_758->data[5] = ____BAH_COMPILER_VAR_770;
____BAH_COMPILER_VAR_758->data[6] = ____BAH_COMPILER_VAR_772;
____BAH_COMPILER_VAR_758->data[7] = ____BAH_COMPILER_VAR_774;
struct reflectElement ____BAH_COMPILER_VAR_775 = __reflect(____BAH_COMPILER_VAR_757, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_758, 0);

        struct reflectElement ____BAH_COMPILER_VAR_776 = ____BAH_COMPILER_VAR_775;
        struct reflectElement ____BAH_COMPILER_VAR_777 = __reflect(____BAH_COMPILER_VAR_756, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_776, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_751 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_751->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_751->length = 3;
        ____BAH_COMPILER_VAR_751->data = memoryAlloc(____BAH_COMPILER_VAR_751->length * ____BAH_COMPILER_VAR_751->elemSize);
        ____BAH_COMPILER_VAR_751->data[0] = ____BAH_COMPILER_VAR_753;
____BAH_COMPILER_VAR_751->data[1] = ____BAH_COMPILER_VAR_755;
____BAH_COMPILER_VAR_751->data[2] = ____BAH_COMPILER_VAR_777;
struct reflectElement ____BAH_COMPILER_VAR_778 = __reflect(____BAH_COMPILER_VAR_750, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_751, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_778);

                        if (l->length <= len(l)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: l[%d] with length %d", len(l)-1, l->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4054");
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
if ((ltp==LINE_TYPE_VAR)) {
parsed = true;
parseVar(line,elems);
}
else if ((ltp==LINE_TYPE_FN_CALL)) {
if ((len(line)>1)) {
throwErr(&line->data[len(line)-1],"Not expecting {TOKEN} after function call.");
}

                        if (line->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", 0, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4108");
                        };
                        struct Tok ft = line->data[0];
parsed = true;
char * ____BAH_COMPILER_VAR_779 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_779 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_779+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_779+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_779));
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

                        if (line->length <= 0) {
                            char buff[300];
                            snprintf(buff, 299, "array: line[%d] with length %d", 0, line->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4138");
                        };
                        struct Tok ft = line->data[0];
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4157");
                        };
                        struct Tok ft = tokens->data[0];
long int currentLine = ft.line;
long int nbEncl = 0;
long int i = 0;
while ((i<len(tokens))) {

                        if (tokens->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: tokens[%d] with length %d", i, tokens->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4161");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4187");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/parser.bah:4216");
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
char * ____BAH_COMPILER_VAR_780 =null;char * ____BAH_COMPILER_VAR_781 =ct.str(&ct);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(____BAH_COMPILER_VAR_781);
long int strLen_6 = strlen(" ");
long int strLen_8 = strlen(arg->name);
;                            
                    ____BAH_COMPILER_VAR_780 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_780+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_780+currStrOff, ____BAH_COMPILER_VAR_781, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_780+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_780+currStrOff, arg->name, strLen_8);
                        currStrOff += strLen_8;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_780;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_782 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(tmpfnArgsCType);
long int strLen_4 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_782 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_782+currStrOff, tmpfnArgsCType, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_782+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                tmpfnArgsCType = ____BAH_COMPILER_VAR_782;
}
};
char * ____BAH_COMPILER_VAR_783 =null;char * ____BAH_COMPILER_VAR_784 =tmpfnRetCType.str(&tmpfnRetCType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_784);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(fn->name);
long int strLen_6 = strlen("(");
long int strLen_8 = strlen(tmpfnArgsCType);
long int strLen_10 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_783 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10);
                    
                        memcpy(____BAH_COMPILER_VAR_783+currStrOff, ____BAH_COMPILER_VAR_784, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_783+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_783+currStrOff, fn->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_783+currStrOff, "(", strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_783+currStrOff, tmpfnArgsCType, strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_783+currStrOff, ");\n", strLen_10);
                        currStrOff += strLen_10;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_783));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_785 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_2 = strlen(v->name);
long int strLen_4 = strlen(" ");
long int strLen_6 = strlen(v->constVal);
long int strLen_8 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_785 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_785+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_785+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_785+currStrOff, " ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_785+currStrOff, v->constVal, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_785+currStrOff, "\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_785));
}
else {
struct string cType = getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_786 =null;char * ____BAH_COMPILER_VAR_787 =cType.str(&cType);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_787);
long int strLen_2 = strlen(" ");
long int strLen_4 = strlen(v->name);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_786 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_786+currStrOff, ____BAH_COMPILER_VAR_787, strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_786+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_786+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_786+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_786));
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
                        char * ____BAH_COMPILER_VAR_788 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#include ");
long int strLen_2 = strlen(compilerState.cIncludes->data[i]);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_788 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_788+currStrOff, "#include ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_788+currStrOff, compilerState.cIncludes->data[i], strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_788+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_788));
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
char * ____BAH_COMPILER_VAR_789 =elemType.str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_789,elems);
char * ____BAH_COMPILER_VAR_790 =null;char * ____BAH_COMPILER_VAR_791 =elemCtype.str(&elemCtype);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("typedef array(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_791);
long int strLen_4 = strlen(")* ");
long int strLen_6 = strlen(t);
long int strLen_8 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_790+currStrOff, "typedef array(", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_790+currStrOff, ____BAH_COMPILER_VAR_791, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_790+currStrOff, ")* ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_790+currStrOff, t, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_790+currStrOff, ";\n", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_790));
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:52");
                        };
                        execName = args->data[0];
if (((cpstringCharAt(execName,0)==46)||(cpstringCharAt(execName,0)==47))) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_792 = {};
____BAH_COMPILER_VAR_792.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_792.flags->length = 0;
            ____BAH_COMPILER_VAR_792.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_792.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_792.args->length = 0;
            ____BAH_COMPILER_VAR_792.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_792.addString = flags__addString;
____BAH_COMPILER_VAR_792.addBool = flags__addBool;
____BAH_COMPILER_VAR_792.addInt = flags__addInt;
____BAH_COMPILER_VAR_792.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_792.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_792.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_792.get = flags__get;
____BAH_COMPILER_VAR_792.getInt = flags__getInt;
____BAH_COMPILER_VAR_792.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_792.isSet = flags__isSet;
____BAH_COMPILER_VAR_792.parse = flags__parse;
flags = ____BAH_COMPILER_VAR_792;
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
char * ____BAH_COMPILER_VAR_793 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_4 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
long int strLen_6 = strlen(BAH_OS);
long int strLen_8 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_793 = memoryAllocSTR(1 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_793+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_793+currStrOff, BAH_OS, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_793+currStrOff, ".", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                flags.addString(&flags,"target",____BAH_COMPILER_VAR_793);
char * ____BAH_COMPILER_VAR_794 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_4 = strlen("If your Bah directory is not the default one (");
long int strLen_6 = strlen(BAH_DIR);
long int strLen_8 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_794 = memoryAllocSTR(1 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_794+currStrOff, "If your Bah directory is not the default one (", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_794+currStrOff, BAH_DIR, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_794+currStrOff, ").", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                flags.addString(&flags,"bahDir",____BAH_COMPILER_VAR_794);
char * ____BAH_COMPILER_VAR_795 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_4 = strlen("To change the C compiler used, default: ");
long int strLen_6 = strlen(BAH_CC);
long int strLen_8 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_795 = memoryAllocSTR(1 + strLen_4 + strLen_6 + strLen_8);
                    
                        memcpy(____BAH_COMPILER_VAR_795+currStrOff, "To change the C compiler used, default: ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_795+currStrOff, BAH_CC, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_795+currStrOff, ".", strLen_8);
                        currStrOff += strLen_8;
                        
                }
                flags.addString(&flags,"CC",____BAH_COMPILER_VAR_795);
flags.addBool(&flags,"object","Compile as an object.");
flags.addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags.parse(&flags,args);
if ((flags.isSet(&flags,"target")==1)) {
BAH_OS = flags.get(&flags,"target");
char * ____BAH_COMPILER_VAR_796 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Build target: ");
long int strLen_2 = strlen(BAH_OS);
;                            
                    ____BAH_COMPILER_VAR_796 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_796+currStrOff, "Build target: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_796+currStrOff, BAH_OS, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                println(____BAH_COMPILER_VAR_796);
}
if ((flags.isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags.get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);

                        if (bahDirArr->length <= len(bahDirArr)-1) {
                            char buff[300];
                            snprintf(buff, 299, "array: bahDirArr[%d] with length %d", len(bahDirArr)-1, bahDirArr->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:90");
                        };
                        if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_797 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("/");
;                            
                    ____BAH_COMPILER_VAR_797 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_797+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_797+currStrOff, "/", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                BAH_DIR = ____BAH_COMPILER_VAR_797;
}
char * ____BAH_COMPILER_VAR_798 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Bah directory: ");
long int strLen_2 = strlen(BAH_DIR);
;                            
                    ____BAH_COMPILER_VAR_798 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_798+currStrOff, "Bah directory: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_798+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                println(____BAH_COMPILER_VAR_798);
}
if ((flags.isSet(&flags,"CC")==1)) {
BAH_CC = flags.get(&flags,"CC");
char * ____BAH_COMPILER_VAR_799 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("C compiler: ");
long int strLen_2 = strlen(BAH_CC);
;                            
                    ____BAH_COMPILER_VAR_799 = memoryAllocSTR(1 + strLen_0 + strLen_2);
                    
                        memcpy(____BAH_COMPILER_VAR_799+currStrOff, "C compiler: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_799+currStrOff, BAH_CC, strLen_2);
                        currStrOff += strLen_2;
                        
                }
                println(____BAH_COMPILER_VAR_799);
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
char * ____BAH_COMPILER_VAR_800 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Bah compiler version: ");
long int strLen_2 = strlen(BAH_VERSION);
long int strLen_4 = strlen(".\n© Alois Laurent Boe");
;                            
                    ____BAH_COMPILER_VAR_800 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_800+currStrOff, "Bah compiler version: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_800+currStrOff, BAH_VERSION, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_800+currStrOff, ".\n© Alois Laurent Boe", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                println(____BAH_COMPILER_VAR_800);
return 0;
}
if (((flags.isSet(&flags,"c")==1)&&(flags.isSet(&flags,"l")==1))) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:124");
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
struct compilerStateTag ____BAH_COMPILER_VAR_801 = {};
____BAH_COMPILER_VAR_801.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_801.includes->length = 0;
            ____BAH_COMPILER_VAR_801.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_801.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_801.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_801.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_801.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_801.cLibs->length = 0;
            ____BAH_COMPILER_VAR_801.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_801.currentFile= null;
____BAH_COMPILER_VAR_801.currentDir = "./";
____BAH_COMPILER_VAR_801.isBranch = false;
____BAH_COMPILER_VAR_801.isFor = false;
____BAH_COMPILER_VAR_801.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_801.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_801.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_801.haveEntryPoint = false;
____BAH_COMPILER_VAR_801.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_801.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_801.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_801.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_801.evals->length = 0;
            ____BAH_COMPILER_VAR_801.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_801.hasImports = false;
compilerState = ____BAH_COMPILER_VAR_801;

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
struct fileMap ____BAH_COMPILER_VAR_802 = {};
____BAH_COMPILER_VAR_802.handle = -1;
____BAH_COMPILER_VAR_802.p= null;
____BAH_COMPILER_VAR_802.open = fileMap__open;
____BAH_COMPILER_VAR_802.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_802.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_802
char * f = fm.open(&fm,fileName);
if (((fm.isValid(&fm)==0)||(fm.size==0))) {
char * ____BAH_COMPILER_VAR_803 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not open file '");
long int strLen_2 = strlen(fileName);
long int strLen_4 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_803 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_803+currStrOff, "Could not open file '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_803+currStrOff, fileName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_803+currStrOff, "'.", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                println(____BAH_COMPILER_VAR_803);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f);
fm.close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_804 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("File '");
long int strLen_2 = strlen(fileName);
long int strLen_4 = strlen("' not recognized.");
;                            
                    ____BAH_COMPILER_VAR_804 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_804+currStrOff, "File '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_804+currStrOff, fileName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_804+currStrOff, "' not recognized.", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                println(____BAH_COMPILER_VAR_804);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_805 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_805->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_805->vars->length = 0;
            ____BAH_COMPILER_VAR_805->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_805->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_805->structs->length = 0;
            ____BAH_COMPILER_VAR_805->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_805->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_805->types->length = 0;
            ____BAH_COMPILER_VAR_805->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_805->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_805->fns->length = 0;
            ____BAH_COMPILER_VAR_805->fns->elemSize = sizeof(struct func*);
            struct Elems* elems = ____BAH_COMPILER_VAR_805;
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
char * ____BAH_COMPILER_VAR_806 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not find std-libs, please check '");
long int strLen_2 = strlen(BAH_DIR);
long int strLen_4 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_806 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_806+currStrOff, "Could not find std-libs, please check '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_806+currStrOff, BAH_DIR, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_806+currStrOff, "'", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                __BAH_panic(____BAH_COMPILER_VAR_806,"/home/alois/Documents/bah-bah/src/main.bah:230");
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
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:246");
                        };
                        struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
l = l+1;
};
char * ____BAH_COMPILER_VAR_807 =null;char * ____BAH_COMPILER_VAR_808 =intToStr(l);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_808);
long int strLen_4 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_807 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_807+currStrOff, "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_807+currStrOff, ____BAH_COMPILER_VAR_808, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_807+currStrOff, "];", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_807));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); i = i+1) {

                        if (elems->fns->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: elems->fns[%d] with length %d", i, elems->fns->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:255");
                        };
                        struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char * ____BAH_COMPILER_VAR_809 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fn->from);
long int strLen_4 = strlen("__");
;                            
                    ____BAH_COMPILER_VAR_809 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_809+currStrOff, fn->from, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_809+currStrOff, "__", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                if (((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_809))) {
struct string n = string(name);
n.trimLeft(&n,strlen(fn->from)+2);
char * ____BAH_COMPILER_VAR_810 =null;char * ____BAH_COMPILER_VAR_811 =n.str(&n);
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fn->from);
long int strLen_4 = strlen(".");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_811);
;                            
                    ____BAH_COMPILER_VAR_810 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_810+currStrOff, fn->from, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_810+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_810+currStrOff, ____BAH_COMPILER_VAR_811, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                name = ____BAH_COMPILER_VAR_810;
}
char * ____BAH_COMPILER_VAR_812 =null;char * ____BAH_COMPILER_VAR_813 =intToStr(j);char * ____BAH_COMPILER_VAR_814 =intToStr(j);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n            __tmp____Bah_fnNames[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_813);
long int strLen_4 = strlen("].n = \"");
long int strLen_6 = strlen(name);
long int strLen_8 = strlen("\";\n            __tmp____Bah_fnNames[");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_814);
long int strLen_12 = strlen("].p = ");
long int strLen_14 = strlen(fn->name);
long int strLen_16 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_812 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16);
                    
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, "\n            __tmp____Bah_fnNames[", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, ____BAH_COMPILER_VAR_813, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, "].n = \"", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, name, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, "\";\n            __tmp____Bah_fnNames[", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, ____BAH_COMPILER_VAR_814, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, "].p = ", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, fn->name, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_812+currStrOff, ";\n", strLen_16);
                        currStrOff += strLen_16;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_812));
j = j+1;
};
char * ____BAH_COMPILER_VAR_815 =null;char * ____BAH_COMPILER_VAR_816 =intToStr(l);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_816);
long int strLen_4 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_815 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_815+currStrOff, "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_815+currStrOff, ____BAH_COMPILER_VAR_816, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_815+currStrOff, ";", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_815));
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
char * ____BAH_COMPILER_VAR_817 =null;char * ____BAH_COMPILER_VAR_818 =intToStr(totalLines);char * ____BAH_COMPILER_VAR_819 =intToStr(totalTime/1000000);char * ____BAH_COMPILER_VAR_820 =intToStr(totalLexerTime/1000000);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Parsed. (");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_818);
long int strLen_4 = strlen(" lines, total time: ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_819);
long int strLen_8 = strlen("ms, lexer time: ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_820);
long int strLen_12 = strlen("ms)\e[0m");
;                            
                    ____BAH_COMPILER_VAR_817 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12);
                    
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, "Parsed. (", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, ____BAH_COMPILER_VAR_818, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, " lines, total time: ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, ____BAH_COMPILER_VAR_819, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, "ms, lexer time: ", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, ____BAH_COMPILER_VAR_820, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_817+currStrOff, "ms)\e[0m", strLen_12);
                        currStrOff += strLen_12;
                        
                }
                println(____BAH_COMPILER_VAR_817);
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
char * ____BAH_COMPILER_VAR_821 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fileName);
long int strLen_4 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_821 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_821+currStrOff, fileName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_821+currStrOff, ".o", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fileName = ____BAH_COMPILER_VAR_821;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char * ____BAH_COMPILER_VAR_822 =null;
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
                    ____BAH_COMPILER_VAR_822 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28 + strLen_30 + strLen_32 + strLen_34);
                    
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, BAH_CC, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, " -I \"", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, BAH_DIR, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, "libs/", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, BAH_OS, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, "/include/\" -L \"", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, BAH_DIR, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, "libs/", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, BAH_OS, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, "/\" ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, randFileName, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, " ", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, isStatic, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, " ", strLen_28);
                        currStrOff += strLen_28;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, obj, strLen_30);
                        currStrOff += strLen_30;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, " -w -O1 -o ", strLen_32);
                        currStrOff += strLen_32;
                        
                        memcpy(____BAH_COMPILER_VAR_822+currStrOff, fileName, strLen_34);
                        currStrOff += strLen_34;
                        
                }
                char * gccArgs = ____BAH_COMPILER_VAR_822;
if ((flags.isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_823 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(gccArgs);
long int strLen_4 = strlen(" -c");
;                            
                    ____BAH_COMPILER_VAR_823 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_823+currStrOff, gccArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_823+currStrOff, " -c", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                gccArgs = ____BAH_COMPILER_VAR_823;
}
array(char *)* cLibs = compilerState.cLibs;
long int i = 0;
while ((i<len(cLibs))) {

                        if (cLibs->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: cLibs[%d] with length %d", i, cLibs->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:343");
                        };
                        char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_824 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(gccArgs);
long int strLen_4 = strlen(" -");
long int strLen_6 = strlen(l);
;                            
                    ____BAH_COMPILER_VAR_824 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_824+currStrOff, gccArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_824+currStrOff, " -", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_824+currStrOff, l, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                gccArgs = ____BAH_COMPILER_VAR_824;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = OUTPUT->toStr(OUTPUT);
if ((flags.isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_825 =cmd.run(&cmd);println(____BAH_COMPILER_VAR_825);
}
else {
cmd.run(&cmd);
}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags.isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_826 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("ar rcs ");
long int strLen_2 = strlen(fileName);
long int strLen_4 = strlen(".a ");
long int strLen_6 = strlen(fileName);
;                            
                    ____BAH_COMPILER_VAR_826 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4 + strLen_6);
                    
                        memcpy(____BAH_COMPILER_VAR_826+currStrOff, "ar rcs ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_826+currStrOff, fileName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_826+currStrOff, ".a ", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_826+currStrOff, fileName, strLen_6);
                        currStrOff += strLen_6;
                        
                }
                cmd = command(____BAH_COMPILER_VAR_826);
cmd.run(&cmd);
}
}
else {
if ((flags.isSet(&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_827 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_2 = strlen(fileName);
long int strLen_4 = strlen(".c");
;                            
                    ____BAH_COMPILER_VAR_827 = memoryAllocSTR(1 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, fileName, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_827+currStrOff, ".c", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                fileName = ____BAH_COMPILER_VAR_827;
}
char * ____BAH_COMPILER_VAR_828 =null;
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
                    ____BAH_COMPILER_VAR_828 = memoryAllocSTR(1 + strLen_2 + strLen_4 + strLen_6 + strLen_8 + strLen_10 + strLen_12 + strLen_14 + strLen_16 + strLen_18 + strLen_20 + strLen_22 + strLen_24 + strLen_26 + strLen_28);
                    
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, BAH_CC, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, " -I \"", strLen_4);
                        currStrOff += strLen_4;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, BAH_DIR, strLen_6);
                        currStrOff += strLen_6;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, "libs/", strLen_8);
                        currStrOff += strLen_8;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, BAH_OS, strLen_10);
                        currStrOff += strLen_10;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, "/include/\" -L \"", strLen_12);
                        currStrOff += strLen_12;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, BAH_DIR, strLen_14);
                        currStrOff += strLen_14;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, "libs/", strLen_16);
                        currStrOff += strLen_16;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, BAH_OS, strLen_18);
                        currStrOff += strLen_18;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, "/\" ", strLen_20);
                        currStrOff += strLen_20;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, fileName, strLen_22);
                        currStrOff += strLen_22;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, " ", strLen_24);
                        currStrOff += strLen_24;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, isStatic, strLen_26);
                        currStrOff += strLen_26;
                        
                        memcpy(____BAH_COMPILER_VAR_828+currStrOff, " -O1 -w ", strLen_28);
                        currStrOff += strLen_28;
                        
                }
                char * gccArgs = ____BAH_COMPILER_VAR_828;
array(char *)* cLibs = compilerState.cLibs;
long int i = 0;
while ((i<len(cLibs))) {

                        if (cLibs->length <= i) {
                            char buff[300];
                            snprintf(buff, 299, "array: cLibs[%d] with length %d", i, cLibs->length);
                            __BAH_panic((char*)buff, (char*)"/home/alois/Documents/bah-bah/src/main.bah:381");
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
char * ____BAH_COMPILER_VAR_830 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("//COMPILE WITH: '");
long int strLen_2 = strlen(gccArgs);
long int strLen_4 = strlen("'\n");
;                            
                    ____BAH_COMPILER_VAR_830 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_830+currStrOff, "//COMPILE WITH: '", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_830+currStrOff, gccArgs, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_830+currStrOff, "'\n", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                OUTPUT = rope(____BAH_COMPILER_VAR_830)->add(rope(____BAH_COMPILER_VAR_830), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_831 = {};
____BAH_COMPILER_VAR_831.handle= null;
____BAH_COMPILER_VAR_831.name= null;
____BAH_COMPILER_VAR_831.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_831.open = fileStream__open;
____BAH_COMPILER_VAR_831.close = fileStream__close;
____BAH_COMPILER_VAR_831.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_831.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_831.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_831.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_831.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_831.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_831.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_831.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_831.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_831.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_831.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_831.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_831.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_831._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_831
fs.open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_832 =OUTPUT->toStr(OUTPUT);fs.writeFile(&fs,____BAH_COMPILER_VAR_832);
fs.close(&fs);
fs._end(&fs);
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char * ____BAH_COMPILER_VAR_833 =null;char * ____BAH_COMPILER_VAR_834 =intToStr(totalTime/1000000);
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;32mDone. (compiled in ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_834);
long int strLen_4 = strlen("ms)\e[0m");
;                            
                    ____BAH_COMPILER_VAR_833 = memoryAllocSTR(1 + strLen_0 + strLen_2 + strLen_4);
                    
                        memcpy(____BAH_COMPILER_VAR_833+currStrOff, "\e[1;32mDone. (compiled in ", strLen_0);
                        currStrOff += strLen_0;
                        
                        memcpy(____BAH_COMPILER_VAR_833+currStrOff, ____BAH_COMPILER_VAR_834, strLen_2);
                        currStrOff += strLen_2;
                        
                        memcpy(____BAH_COMPILER_VAR_833+currStrOff, "ms)\e[0m", strLen_4);
                        currStrOff += strLen_4;
                        
                }
                println(____BAH_COMPILER_VAR_833);
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

            __tmp____Bah_fnNames[0].n = "__Bah_safe_string";
            __tmp____Bah_fnNames[0].p = __Bah_safe_string;

            __tmp____Bah_fnNames[1].n = "__bah_strcmp";
            __tmp____Bah_fnNames[1].p = __bah_strcmp;

            __tmp____Bah_fnNames[2].n = "__bah_strlen";
            __tmp____Bah_fnNames[2].p = __bah_strlen;

            __tmp____Bah_fnNames[3].n = "len";
            __tmp____Bah_fnNames[3].p = len;

            __tmp____Bah_fnNames[4].n = "memoryAlloc";
            __tmp____Bah_fnNames[4].p = memoryAlloc;

            __tmp____Bah_fnNames[5].n = "destroy";
            __tmp____Bah_fnNames[5].p = destroy;

            __tmp____Bah_fnNames[6].n = "clear";
            __tmp____Bah_fnNames[6].p = clear;

            __tmp____Bah_fnNames[7].n = "memoryRealloc";
            __tmp____Bah_fnNames[7].p = memoryRealloc;

            __tmp____Bah_fnNames[8].n = "cleanShutDown";
            __tmp____Bah_fnNames[8].p = cleanShutDown;

            __tmp____Bah_fnNames[9].n = "memoryOnEnd";
            __tmp____Bah_fnNames[9].p = memoryOnEnd;

            __tmp____Bah_fnNames[10].n = "append";
            __tmp____Bah_fnNames[10].p = append;

            __tmp____Bah_fnNames[11].n = "copy";
            __tmp____Bah_fnNames[11].p = copy;

            __tmp____Bah_fnNames[12].n = "sharedMemory";
            __tmp____Bah_fnNames[12].p = sharedMemory;

            __tmp____Bah_fnNames[13].n = "closeSharedMemory";
            __tmp____Bah_fnNames[13].p = closeSharedMemory;

            __tmp____Bah_fnNames[14].n = "allocateArray";
            __tmp____Bah_fnNames[14].p = allocateArray;

            __tmp____Bah_fnNames[15].n = "__serialize";
            __tmp____Bah_fnNames[15].p = __serialize;

            __tmp____Bah_fnNames[16].n = "serlen";
            __tmp____Bah_fnNames[16].p = serlen;

            __tmp____Bah_fnNames[17].n = "unser";
            __tmp____Bah_fnNames[17].p = unser;

            __tmp____Bah_fnNames[18].n = "memoryAllocSTR";
            __tmp____Bah_fnNames[18].p = memoryAllocSTR;

            __tmp____Bah_fnNames[19].n = "delete";
            __tmp____Bah_fnNames[19].p = delete;

            __tmp____Bah_fnNames[20].n = "arrToStr";
            __tmp____Bah_fnNames[20].p = arrToStr;

            __tmp____Bah_fnNames[21].n = "strToArr";
            __tmp____Bah_fnNames[21].p = strToArr;

            __tmp____Bah_fnNames[22].n = "arrAsStr";
            __tmp____Bah_fnNames[22].p = arrAsStr;

            __tmp____Bah_fnNames[23].n = "strAsArr";
            __tmp____Bah_fnNames[23].p = strAsArr;

            __tmp____Bah_fnNames[24].n = "strTrimLeft";
            __tmp____Bah_fnNames[24].p = strTrimLeft;

            __tmp____Bah_fnNames[25].n = "strTrimRight";
            __tmp____Bah_fnNames[25].p = strTrimRight;

            __tmp____Bah_fnNames[26].n = "concatCPSTRING";
            __tmp____Bah_fnNames[26].p = concatCPSTRING;

            __tmp____Bah_fnNames[27].n = "__STR";
            __tmp____Bah_fnNames[27].p = __STR;

            __tmp____Bah_fnNames[28].n = "print";
            __tmp____Bah_fnNames[28].p = print;

            __tmp____Bah_fnNames[29].n = "cArr";
            __tmp____Bah_fnNames[29].p = cArr;

            __tmp____Bah_fnNames[30].n = "__checkString";
            __tmp____Bah_fnNames[30].p = __checkString;

            __tmp____Bah_fnNames[31].n = "mutex.init";
            __tmp____Bah_fnNames[31].p = mutex__init;

            __tmp____Bah_fnNames[32].n = "mutex.lock";
            __tmp____Bah_fnNames[32].p = mutex__lock;

            __tmp____Bah_fnNames[33].n = "mutex.unlock";
            __tmp____Bah_fnNames[33].p = mutex__unlock;

            __tmp____Bah_fnNames[34].n = "mutex.destroy";
            __tmp____Bah_fnNames[34].p = mutex__destroy;

            __tmp____Bah_fnNames[35].n = "mutexCondition.init";
            __tmp____Bah_fnNames[35].p = mutexCondition__init;

            __tmp____Bah_fnNames[36].n = "mutexCondition.wait";
            __tmp____Bah_fnNames[36].p = mutexCondition__wait;

            __tmp____Bah_fnNames[37].n = "mutexCondition.send";
            __tmp____Bah_fnNames[37].p = mutexCondition__send;

            __tmp____Bah_fnNames[38].n = "mutexCondition.destroy";
            __tmp____Bah_fnNames[38].p = mutexCondition__destroy;

            __tmp____Bah_fnNames[39].n = "mutexCondition";
            __tmp____Bah_fnNames[39].p = mutexCondition;

            __tmp____Bah_fnNames[40].n = "thread.create";
            __tmp____Bah_fnNames[40].p = thread__create;

            __tmp____Bah_fnNames[41].n = "thread.createWithArg";
            __tmp____Bah_fnNames[41].p = thread__createWithArg;

            __tmp____Bah_fnNames[42].n = "thread.wait";
            __tmp____Bah_fnNames[42].p = thread__wait;

            __tmp____Bah_fnNames[43].n = "mutex";
            __tmp____Bah_fnNames[43].p = mutex;

            __tmp____Bah_fnNames[44].n = "queue.insert";
            __tmp____Bah_fnNames[44].p = queue__insert;

            __tmp____Bah_fnNames[45].n = "queue.delete";
            __tmp____Bah_fnNames[45].p = queue__delete;

            __tmp____Bah_fnNames[46].n = "queue.get";
            __tmp____Bah_fnNames[46].p = queue__get;

            __tmp____Bah_fnNames[47].n = "queue.set";
            __tmp____Bah_fnNames[47].p = queue__set;

            __tmp____Bah_fnNames[48].n = "queue.pop";
            __tmp____Bah_fnNames[48].p = queue__pop;

            __tmp____Bah_fnNames[49].n = "queue.clear";
            __tmp____Bah_fnNames[49].p = queue__clear;

            __tmp____Bah_fnNames[50].n = "channel.send";
            __tmp____Bah_fnNames[50].p = channel__send;

            __tmp____Bah_fnNames[51].n = "channel.sendAny";
            __tmp____Bah_fnNames[51].p = channel__sendAny;

            __tmp____Bah_fnNames[52].n = "channel.receive";
            __tmp____Bah_fnNames[52].p = channel__receive;

            __tmp____Bah_fnNames[53].n = "channel.destroy";
            __tmp____Bah_fnNames[53].p = channel__destroy;

            __tmp____Bah_fnNames[54].n = "channel.len";
            __tmp____Bah_fnNames[54].p = channel__len;

            __tmp____Bah_fnNames[55].n = "channel";
            __tmp____Bah_fnNames[55].p = channel;

            __tmp____Bah_fnNames[56].n = "setChanCap";
            __tmp____Bah_fnNames[56].p = setChanCap;

            __tmp____Bah_fnNames[57].n = "__Bah_common_panic";
            __tmp____Bah_fnNames[57].p = __Bah_common_panic;

            __tmp____Bah_fnNames[58].n = "__Bah_fnNames_append";
            __tmp____Bah_fnNames[58].p = __Bah_fnNames_append;

            __tmp____Bah_fnNames[59].n = "__BAH_panic";
            __tmp____Bah_fnNames[59].p = __BAH_panic;

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

            __tmp____Bah_fnNames[157].n = "rope.getParent";
            __tmp____Bah_fnNames[157].p = rope__getParent;

            __tmp____Bah_fnNames[158].n = "rope.addStr";
            __tmp____Bah_fnNames[158].p = rope__addStr;

            __tmp____Bah_fnNames[159].n = "rope.toStr";
            __tmp____Bah_fnNames[159].p = rope__toStr;

            __tmp____Bah_fnNames[160].n = "rope.add";
            __tmp____Bah_fnNames[160].p = rope__add;

            __tmp____Bah_fnNames[161].n = "createRopeStructure";
            __tmp____Bah_fnNames[161].p = createRopeStructure;

            __tmp____Bah_fnNames[162].n = "ropeSet";
            __tmp____Bah_fnNames[162].p = ropeSet;

            __tmp____Bah_fnNames[163].n = "concatenateRopes";
            __tmp____Bah_fnNames[163].p = concatenateRopes;

            __tmp____Bah_fnNames[164].n = "rope";
            __tmp____Bah_fnNames[164].p = rope;

            __tmp____Bah_fnNames[165].n = "command.run";
            __tmp____Bah_fnNames[165].p = command__run;

            __tmp____Bah_fnNames[166].n = "command.runBytes";
            __tmp____Bah_fnNames[166].p = command__runBytes;

            __tmp____Bah_fnNames[167].n = "command";
            __tmp____Bah_fnNames[167].p = command;

            __tmp____Bah_fnNames[168].n = "exec";
            __tmp____Bah_fnNames[168].p = exec;

            __tmp____Bah_fnNames[169].n = "inArray";
            __tmp____Bah_fnNames[169].p = inArray;

            __tmp____Bah_fnNames[170].n = "inArrayStr";
            __tmp____Bah_fnNames[170].p = inArrayStr;

            __tmp____Bah_fnNames[171].n = "makeToken";
            __tmp____Bah_fnNames[171].p = makeToken;

            __tmp____Bah_fnNames[172].n = "isMinus";
            __tmp____Bah_fnNames[172].p = isMinus;

            __tmp____Bah_fnNames[173].n = "lexerErr";
            __tmp____Bah_fnNames[173].p = lexerErr;

            __tmp____Bah_fnNames[174].n = "lexer";
            __tmp____Bah_fnNames[174].p = lexer;

            __tmp____Bah_fnNames[175].n = "hasStructSep";
            __tmp____Bah_fnNames[175].p = hasStructSep;

            __tmp____Bah_fnNames[176].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[176].p = splitStructSepBefore;

            __tmp____Bah_fnNames[177].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[177].p = splitStructSepAfter;

            __tmp____Bah_fnNames[178].n = "searchStruct";
            __tmp____Bah_fnNames[178].p = searchStruct;

            __tmp____Bah_fnNames[179].n = "searchStructMemb";
            __tmp____Bah_fnNames[179].p = searchStructMemb;

            __tmp____Bah_fnNames[180].n = "isRCPpointerType";
            __tmp____Bah_fnNames[180].p = isRCPpointerType;

            __tmp____Bah_fnNames[181].n = "isRCPtype";
            __tmp____Bah_fnNames[181].p = isRCPtype;

            __tmp____Bah_fnNames[182].n = "getCType";
            __tmp____Bah_fnNames[182].p = getCType;

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

            __tmp____Bah_fnNames[222].n = "endRCPscope";
            __tmp____Bah_fnNames[222].p = endRCPscope;

            __tmp____Bah_fnNames[223].n = "beginRCPscope";
            __tmp____Bah_fnNames[223].p = beginRCPscope;

            __tmp____Bah_fnNames[224].n = "decrRCPstackVars";
            __tmp____Bah_fnNames[224].p = decrRCPstackVars;

            __tmp____Bah_fnNames[225].n = "endRCPnonGlobScope";
            __tmp____Bah_fnNames[225].p = endRCPnonGlobScope;

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
    