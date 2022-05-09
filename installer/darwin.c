//COMPILE WITH: '../builder/osxcross/target/bin/x86_64h-apple-darwin14-clang -I "/opt/bah/libs/darwin/include/" -L "/opt/bah/libs/darwin/" ../installer/darwin.c  -O1 -w  -lgc -lpthread -lm'

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
#include <mach/mach.h>
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
#include <sys/mman.h>
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
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_READWRITE 3
#define MAP_SHARED 1
#define MAP_ANONYMOUS 32
void * sharedMemory(long int size){
if ((size==0)) {
size = 4096;
}
void * r = mmap(0,size,PROT_READ+PROT_WRITE,MAP_SHARED+MAP_ANONYMOUS,-1,0);
return r;
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
array(void *)* arr = (array(void *)*)a;
long int length = len(arr);
if ((i>=length)||(i<0)) {
return;
}
if ((length==1)) {
arr->length=0;
return;
}
long int elemSize = arr->elemSize;
char* data = arr->data;
void * destOffset = elemSize*i;
i++;
void * offset = elemSize*i;
char* src = (long int)data+(long int)offset;
char* dest = (long int)data+(long int)destOffset;
long int rightNB = length-(i-1);
memmove(dest,src,rightNB*elemSize);
arr->length=length-1;
};
void deleteRange(void * a,long int from,long int to){
if ((from==to)) {
delete(a,from);
return;
}
array(void *)* arr = (array(void *)*)a;
long int length = len(arr);
long int elemSize = arr->elemSize;
char* data = arr->data;
long int size = elemSize*(to-from);
void * dest = (long int)data+elemSize*from;
void * src = (long int)dest+size+elemSize;
long int rightNB = length-to;
memmove(dest,src,rightNB*elemSize);
arr->length=length-(to-from+1);
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
            long int strLen_0 = strlen(l);
long int strLen_1 = strlen(") is null \n");
long int strLen_2 = strlen("cpstring (");
;                            
            ____BAH_COMPILER_VAR_0 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_0+currStrOff, "cpstring (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_0+currStrOff, l, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_0+currStrOff, ") is null \n", strLen_1);
            currStrOff += strLen_1;
        
        }print(____BAH_COMPILER_VAR_0);
exit(1);
}
return true;
};
#include <pthread.h>
#define __thread_create GC_pthread_create
#define __thread_join GC_pthread_join
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
this->length++;
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
this->length--;
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
this->w_waitting++;
pthread_cond_wait(&this->w_cond,&this->m_mut);
this->w_waitting--;
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
this->w_waitting++;
pthread_cond_wait(&this->w_cond,&this->m_mut);
this->w_waitting--;
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
this->r_waitting++;
pthread_cond_wait(&this->r_cond,&this->m_mut);
this->r_waitting--;
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
            long int strLen_0 = strlen(e);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("): ");
long int strLen_3 = strlen(line);
long int strLen_4 = strlen("panic (");
;                            
            ____BAH_COMPILER_VAR_7 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, "panic (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, line, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_7+currStrOff, "): ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_7+currStrOff, e, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_7+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }print(____BAH_COMPILER_VAR_7);
cleanShutDown();
};
char * (*onMemoryError)();
void __Bah_segfault_handle(long int sig){
char * res = "";
if ((onMemoryError!=null)) {
res = onMemoryError();
}
char * ____BAH_COMPILER_VAR_8 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("Memory error (segfault).\n");
long int strLen_1 = strlen(res);
;                            
            ____BAH_COMPILER_VAR_8 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_8+currStrOff, "Memory error (segfault).\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_8+currStrOff, res, strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_8,"???");
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
char * ____BAH_COMPILER_VAR_9 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_9 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_9+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_9+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_9+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_9;
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
for (; (i<strlen(s)); i++) {
hash = ((long int)hash<<5+0)+hash+(long int)s[i];
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
for (; (i<l+nb); i++) {

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
struct mapElem* ____BAH_COMPILER_VAR_10 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_10->key= null;
____BAH_COMPILER_VAR_10->val= null;
____BAH_COMPILER_VAR_10->key = k;
____BAH_COMPILER_VAR_10->val = e;
struct mapElem* elem = ____BAH_COMPILER_VAR_10;
long int ind = __Bah_map_hash(k,len(this->elems));
long int i = 0;
for (; (i<len(this->elems)); i++) {
long int j = (i+ind)%len(this->elems);
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
this->length++;
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
struct mapElem* ____BAH_COMPILER_VAR_11 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_11->key= null;
____BAH_COMPILER_VAR_11->val= null;
____BAH_COMPILER_VAR_11->key = k;
____BAH_COMPILER_VAR_11->val = p;
struct mapElem* elem = ____BAH_COMPILER_VAR_11;
long int ind = __Bah_map_hash(k,len(this->elems));
long int i = 0;
for (; (i<len(this->elems)); i++) {
long int j = (i+ind)%len(this->elems);
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
this->length++;
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
for (; (i<len(this->elems)); i++) {
long int j = (i+ind)%len(this->elems);
struct mapElem* e = this->elems->data[j];
if ((e!=null)&&(strcmp(e->key, k) == 0)) {

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
for (; (i<len(this->elems)); i++) {
long int j = (i+ind)%len(this->elems);
struct mapElem* e = this->elems->data[j];
if ((e!=null)&&(strcmp(e->key, k) == 0)) {
return e->val;
}
};
return null;
};
struct mapWrapper* mapWrapper(){
struct mapWrapper* ____BAH_COMPILER_VAR_12 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_12->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_12->elems->length = 0;
            ____BAH_COMPILER_VAR_12->elems->elemSize = sizeof(struct mapElem*);
            ____BAH_COMPILER_VAR_12->grow = mapWrapper__grow;
____BAH_COMPILER_VAR_12->set = mapWrapper__set;
____BAH_COMPILER_VAR_12->setAny = mapWrapper__setAny;
____BAH_COMPILER_VAR_12->delete = mapWrapper__delete;
____BAH_COMPILER_VAR_12->get = mapWrapper__get;
struct mapWrapper* m = ____BAH_COMPILER_VAR_12;
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
char * ____BAH_COMPILER_VAR_13 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_13 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_13+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_13+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_13;
}
else {
while ((nDataLength>0)) {
char * ____BAH_COMPILER_VAR_14 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_14 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_14+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_14+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_14;
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
char * ____BAH_COMPILER_VAR_15 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_15 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_15+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_15+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }write((void *)1,____BAH_COMPILER_VAR_15,strlen(s)+1);
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
char * ____BAH_COMPILER_VAR_16 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(this->name);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("iostream: warning, auto-closing file: '");
;                            
            ____BAH_COMPILER_VAR_16 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_16+currStrOff, "iostream: warning, auto-closing file: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_16+currStrOff, this->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_16+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_16);
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
this->handle = open(fileName,O_RDWR,S_IRUSR|S_IWUSR);
struct stat ____BAH_COMPILER_VAR_17 = {};
#define sb ____BAH_COMPILER_VAR_17
fstat(this->handle,&sb);
this->size = sb.st_size;
this->p = mmap(0,sb.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,this->handle,0);
return this->p;
};
long int fileMap__isValid(struct fileMap* this){
if ((this->handle<0)) {
return 0;
}
return 1;
};
void fileMap__close(struct fileMap* this){
if ((this->handle==-1)) {
return;
}
munmap(this->p,this->size);
close(this->handle);
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
return (c>=65)&&(c<=90);
};
char isLower(char c){
return (c>=97)&&(c<=122);
};
char isLetter(char s){
return isLower(s)||isUpper(s);
};
char isNumber(char c){
return (c>=48)&&(c<=57);
};
char isAlphaNumeric(char s){
return isLetter(s)||isNumber(s);
};
char isSpace(char c){
return (c==(char)32)||(c==(char)9)||(c==(char)10)||(c==(char)11)||(c==(char)13);
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
if ((i<this->length)&&(i>=0)) {
return this->content[i];
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
#define needle ____BAH_COMPILER_VAR_18
needle.set(&needle,nd);
struct string ____BAH_COMPILER_VAR_19 = {};
____BAH_COMPILER_VAR_19.content= null;
____BAH_COMPILER_VAR_19.set = string__set;
____BAH_COMPILER_VAR_19.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_19.append = string__append;
____BAH_COMPILER_VAR_19.prepend = string__prepend;
____BAH_COMPILER_VAR_19.charAt = string__charAt;
____BAH_COMPILER_VAR_19.compare = string__compare;
____BAH_COMPILER_VAR_19.str = string__str;
____BAH_COMPILER_VAR_19.replace = string__replace;
#define repl ____BAH_COMPILER_VAR_19
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
char * ____BAH_COMPILER_VAR_20 =null;char * ____BAH_COMPILER_VAR_21 =arrAsStr(replbuffStr);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_21);
;                            
            ____BAH_COMPILER_VAR_20 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_20+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_20+currStrOff, ____BAH_COMPILER_VAR_21, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_20;
}
if (((void *)r!=null)) {
this->set(this,r);
}

#undef needle

#undef repl
};
long int string__countChar(struct string* this,char need){
long int c = 0;
long int i = 0;
for (; (i<this->length); i++) {
if ((this->charAt(this,i)==need)) {
c++;
}
};
return c;
};
long int string__count(struct string* this,char * need){
if ((strlen(need)==1)) {
return this->countChar(this,need[0]);
}
long int i = 0;
long int count = 0;
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
#define needle ____BAH_COMPILER_VAR_22
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
for (; (i<this->length); i++) {
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
#define r ____BAH_COMPILER_VAR_23
r.length = this->length+s2.length;
r.content = memoryAlloc(r.length+1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
return r;
};
struct string string(char * s){
struct string ____BAH_COMPILER_VAR_24 = {};
____BAH_COMPILER_VAR_24.content= null;
____BAH_COMPILER_VAR_24.set = string__set;
____BAH_COMPILER_VAR_24.makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_24.append = string__append;
____BAH_COMPILER_VAR_24.prepend = string__prepend;
____BAH_COMPILER_VAR_24.charAt = string__charAt;
____BAH_COMPILER_VAR_24.compare = string__compare;
____BAH_COMPILER_VAR_24.str = string__str;
____BAH_COMPILER_VAR_24.replace = string__replace;
____BAH_COMPILER_VAR_24.countChar = string__countChar;
____BAH_COMPILER_VAR_24.count = string__count;
____BAH_COMPILER_VAR_24.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_24.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_24.trim = string__trim;
____BAH_COMPILER_VAR_24.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_24.trimRight = string__trimRight;
____BAH_COMPILER_VAR_24.add = string__add;
#define a ____BAH_COMPILER_VAR_24
a.set(&a,s);
return a;
};
char * intToStr(long int i){
if ((i==0)) {
return "0";
}
char ____BAH_COMPILER_VAR_25[66];char* s = ____BAH_COMPILER_VAR_25;
long int ind = -1;
char subZero = (i<0);
if ((subZero==true)) {
i = 0-i;
}
for (; (i!=0); i = i/10) {
long int conv = i%10;
conv = conv+48;
s[ind+1] = (char)conv;
ind++;
};
if ((subZero==true)) {
s[ind+1] = 45;
ind++;
}
long int ls = ind+1;
i = 0;
for (; (i<ls/2); i++) {
long int ii = ls-i-1;
char osi = s[i];
s[i] = s[ii];
s[ii] = osi;
};
s[ind+1] = (char)0;
return __STR(s);
};
struct string intToString(long int i){
char * ____BAH_COMPILER_VAR_26 =intToStr(i);struct string r = string(____BAH_COMPILER_VAR_26);
return r;
};
char * floatToStr(double f){
char ____BAH_COMPILER_VAR_27[50];char* buff = ____BAH_COMPILER_VAR_27;
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
char * ____BAH_COMPILER_VAR_28 =charToString(c);replcBuff.append(&replcBuff,____BAH_COMPILER_VAR_28);
}
else {
if ((sepIndex>0)) {
sepIndex = 0;
char * ____BAH_COMPILER_VAR_29 =charToString(c);replcBuff.append(&replcBuff,____BAH_COMPILER_VAR_29);
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
struct string* ____BAH_COMPILER_VAR_30 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_30->content= null;
____BAH_COMPILER_VAR_30->set = string__set;
____BAH_COMPILER_VAR_30->makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_30->append = string__append;
____BAH_COMPILER_VAR_30->prepend = string__prepend;
____BAH_COMPILER_VAR_30->charAt = string__charAt;
____BAH_COMPILER_VAR_30->compare = string__compare;
____BAH_COMPILER_VAR_30->str = string__str;
____BAH_COMPILER_VAR_30->replace = string__replace;
____BAH_COMPILER_VAR_30->countChar = string__countChar;
____BAH_COMPILER_VAR_30->count = string__count;
____BAH_COMPILER_VAR_30->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_30->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_30->trim = string__trim;
____BAH_COMPILER_VAR_30->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_30->trimRight = string__trimRight;
____BAH_COMPILER_VAR_30->add = string__add;
struct string* elem = ____BAH_COMPILER_VAR_30;
char * ____BAH_COMPILER_VAR_31 =arrToStr(tmpString);elem->set(elem,____BAH_COMPILER_VAR_31);
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
struct string* ____BAH_COMPILER_VAR_32 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_32->content= null;
____BAH_COMPILER_VAR_32->set = string__set;
____BAH_COMPILER_VAR_32->makeEditable = string__makeEditable;
____BAH_COMPILER_VAR_32->append = string__append;
____BAH_COMPILER_VAR_32->prepend = string__prepend;
____BAH_COMPILER_VAR_32->charAt = string__charAt;
____BAH_COMPILER_VAR_32->compare = string__compare;
____BAH_COMPILER_VAR_32->str = string__str;
____BAH_COMPILER_VAR_32->replace = string__replace;
____BAH_COMPILER_VAR_32->countChar = string__countChar;
____BAH_COMPILER_VAR_32->count = string__count;
____BAH_COMPILER_VAR_32->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_32->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_32->trim = string__trim;
____BAH_COMPILER_VAR_32->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_32->trimRight = string__trimRight;
____BAH_COMPILER_VAR_32->add = string__add;
struct string* elem = ____BAH_COMPILER_VAR_32;
char * ____BAH_COMPILER_VAR_33 =arrToStr(tmpString);elem->set(elem,____BAH_COMPILER_VAR_33);
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
struct string e = a->data[i];
if ((e.length==0)) {
i = i+1;
continue;
}
char * ____BAH_COMPILER_VAR_34 =e.str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_34);
if ((i!=max)) {
tmpS.append(&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_35 =tmpS.str(&tmpS);s.append(&s,____BAH_COMPILER_VAR_35);
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
char * ____BAH_COMPILER_VAR_36 =arrToStr(ns);return string(____BAH_COMPILER_VAR_36);
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
struct flag* ____BAH_COMPILER_VAR_37 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_37->name= null;
____BAH_COMPILER_VAR_37->help= null;
____BAH_COMPILER_VAR_37->content= null;
struct flag* f = ____BAH_COMPILER_VAR_37;
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
struct flag* ____BAH_COMPILER_VAR_38 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_38->name= null;
____BAH_COMPILER_VAR_38->help= null;
____BAH_COMPILER_VAR_38->content= null;
struct flag* f = ____BAH_COMPILER_VAR_38;
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
struct flag* ____BAH_COMPILER_VAR_39 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_39->name= null;
____BAH_COMPILER_VAR_39->help= null;
____BAH_COMPILER_VAR_39->content= null;
struct flag* f = ____BAH_COMPILER_VAR_39;
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
struct flag* ____BAH_COMPILER_VAR_40 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_40->name= null;
____BAH_COMPILER_VAR_40->help= null;
____BAH_COMPILER_VAR_40->content= null;
struct flag* f = ____BAH_COMPILER_VAR_40;
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
struct flag* flag = this->flags->data[i];
if (name.compare(&name,flag->name)) {
return flag;
}
i = i+1;
};
struct flag* ____BAH_COMPILER_VAR_41 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_41->name= null;
____BAH_COMPILER_VAR_41->help= null;
____BAH_COMPILER_VAR_41->content= null;
struct flag* z = ____BAH_COMPILER_VAR_41;
z->isSet = 0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_42 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_42);
char * ctn = flag->content;
return ctn;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_43 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_43);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_44 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(flag->name);
long int strLen_1 = strlen("' is not int.");
long int strLen_2 = strlen("Flag '");
;                            
            ____BAH_COMPILER_VAR_44 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_44+currStrOff, "Flag '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_44+currStrOff, flag->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_44+currStrOff, "' is not int.", strLen_1);
            currStrOff += strLen_1;
        
        }char * error = ____BAH_COMPILER_VAR_44;
__BAH_panic(error,"/opt/bah/flags.bah:124");
}
long int ctn = flag->cont_int;
return ctn;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_45 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_45);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_46 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(flag->name);
long int strLen_1 = strlen("' is not float.");
long int strLen_2 = strlen("Flag '");
;                            
            ____BAH_COMPILER_VAR_46 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_46+currStrOff, "Flag '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_46+currStrOff, flag->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_46+currStrOff, "' is not float.", strLen_1);
            currStrOff += strLen_1;
        
        }char * error = ____BAH_COMPILER_VAR_46;
__BAH_panic(error,"/opt/bah/flags.bah:136");
}
double ctn = flag->cont_float;
return ctn;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_47 =string(name);struct flag* flag = this->getFlag(this,____BAH_COMPILER_VAR_47);
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
char * ____BAH_COMPILER_VAR_48 =argName.str(&argName);currentFlag->cont_int = atoi(____BAH_COMPILER_VAR_48);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_49 =argName.str(&argName);currentFlag->cont_float = strtod(____BAH_COMPILER_VAR_49,0);
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
#include <time.h>
#include <sys/time.h>
#include <mach/clock.h>
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
struct timespec ____BAH_COMPILER_VAR_50 = {};
#define ts ____BAH_COMPILER_VAR_50
clock_serv_t cclock;
mach_timespec_t mts;
void * ____BAH_COMPILER_VAR_51 =mach_host_self();host_get_clock_service(____BAH_COMPILER_VAR_51,CALENDAR_CLOCK,&cclock);
clock_get_time(cclock,&mts);
void * ____BAH_COMPILER_VAR_52 =mach_task_self();mach_port_deallocate(____BAH_COMPILER_VAR_52,cclock);
mach_timespec_t* mtsp = &mts;
ts.tv_sec = mtsp->tv_sec;
ts.tv_nsec = mtsp->tv_nsec;
long int s = ts.tv_sec*1000000000+ts.tv_nsec;
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
struct fileStream ____BAH_COMPILER_VAR_53 = {};
____BAH_COMPILER_VAR_53.handle= null;
____BAH_COMPILER_VAR_53.name= null;
____BAH_COMPILER_VAR_53.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_53.open = fileStream__open;
____BAH_COMPILER_VAR_53.close = fileStream__close;
____BAH_COMPILER_VAR_53.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_53.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_53.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_53.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_53.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_53.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_53.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_53.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_53.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_53.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_53.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_53.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_53.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_53._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_53
fs.open(&fs,"/dev/urandom","r");
char c = fs.getChar(&fs);
fs.close(&fs);
long int i = (long int)c;
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
if ((this->left==null)&&(this->right==null)) {
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
if ((this->left==null)&&(this->right==null)) {
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
struct rope* ____BAH_COMPILER_VAR_54 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_54->left= null;
____BAH_COMPILER_VAR_54->right= null;
____BAH_COMPILER_VAR_54->str= null;
____BAH_COMPILER_VAR_54->len = 0;
____BAH_COMPILER_VAR_54->addStr = rope__addStr;
____BAH_COMPILER_VAR_54->toStr = rope__toStr;
____BAH_COMPILER_VAR_54->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_54;
tmp->left = this;
tmp->right = root2;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_55 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_55->left= null;
____BAH_COMPILER_VAR_55->right= null;
____BAH_COMPILER_VAR_55->str= null;
____BAH_COMPILER_VAR_55->len = 0;
____BAH_COMPILER_VAR_55->addStr = rope__addStr;
____BAH_COMPILER_VAR_55->toStr = rope__toStr;
____BAH_COMPILER_VAR_55->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_55;
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
j++;
i++;
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
struct rope* ____BAH_COMPILER_VAR_56 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_56->left= null;
____BAH_COMPILER_VAR_56->right= null;
____BAH_COMPILER_VAR_56->str= null;
____BAH_COMPILER_VAR_56->len = 0;
____BAH_COMPILER_VAR_56->addStr = rope__addStr;
____BAH_COMPILER_VAR_56->toStr = rope__toStr;
____BAH_COMPILER_VAR_56->add = rope__add;
struct rope* tmp = ____BAH_COMPILER_VAR_56;
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
char * ____BAH_COMPILER_VAR_57 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_57 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_57+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_57+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_57;
}
else {
char * ____BAH_COMPILER_VAR_58 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_58 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_58;
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
char * ____BAH_COMPILER_VAR_59 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(res);
long int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_59 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, res, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }res = ____BAH_COMPILER_VAR_59;
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
char * ____BAH_COMPILER_VAR_60 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_60 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_60+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_60+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_60;
}
else {
char * ____BAH_COMPILER_VAR_61 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_61 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_61+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_61+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_61;
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
char * ____BAH_COMPILER_VAR_62 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_62 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_62+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_62+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_62;
res = fgets(buff,1023,this->handle);
};
this->status = pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_63 = {};
____BAH_COMPILER_VAR_63.command= null;
____BAH_COMPILER_VAR_63.error = true;
____BAH_COMPILER_VAR_63.status = 0;
____BAH_COMPILER_VAR_63.input = null;
____BAH_COMPILER_VAR_63.handle= null;
____BAH_COMPILER_VAR_63.run = command__run;
____BAH_COMPILER_VAR_63.runBytes = command__runBytes;
#define cmd ____BAH_COMPILER_VAR_63
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
#define BAH_VERSION "v1.2 (build 87)"
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
array(char *)* defined;
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
#define TOKEN_TYPE_CAST (tokenType)12
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
char pass;
void * bahRef;
};
char inArray(char needle,__BAH_ARR_TYPE_char arr){
long int i = 0;
while ((i<len(arr))) {
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
if ((strcmp(needle, arr->data[i]) == 0)) {
return true;
}
i = i+1;
};
return false;
};
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){
struct Tok ____BAH_COMPILER_VAR_64 = {};
____BAH_COMPILER_VAR_64.cont = "";
____BAH_COMPILER_VAR_64.ogCont = "";
____BAH_COMPILER_VAR_64.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_64.pos = 0;
____BAH_COMPILER_VAR_64.line = 1;
____BAH_COMPILER_VAR_64.begLine = 1;
____BAH_COMPILER_VAR_64.bahType = "";
____BAH_COMPILER_VAR_64.isValue = false;
____BAH_COMPILER_VAR_64.isFunc = false;
____BAH_COMPILER_VAR_64.isOper = false;
____BAH_COMPILER_VAR_64.isEqual = false;
____BAH_COMPILER_VAR_64.pass = false;
____BAH_COMPILER_VAR_64.bahRef= null;
#define t ____BAH_COMPILER_VAR_64
t.cont = arrToStr(cont);
t.ogCont = t.cont;
clear(cont);
t.pos = pos;
t.line = lineNb;
t.type = type;
if ((type==TOKEN_TYPE_INT)||(type==TOKEN_TYPE_STR)||(type==TOKEN_TYPE_FLOAT)||(type==TOKEN_TYPE_VAR)||(type==TOKEN_TYPE_BOOL)||(type==TOKEN_TYPE_CHAR)) {
t.isValue = true;
}
return t;
};
char isMinus(char c,char nc){
return (c==45)&&isNumber(nc);
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr = intToStr(line);
char * posStr = intToStr(pos);
char * ____BAH_COMPILER_VAR_65 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("\n\e[0m\n");
long int strLen_1 = strlen(msg);
long int strLen_2 = strlen(posStr);
long int strLen_3 = strlen(":");
long int strLen_4 = strlen(lineStr);
long int strLen_5 = strlen(":");
long int strLen_6 = strlen(compilerState.currentFile);
long int strLen_7 = strlen("\e[1;31m[LEXER-ERROR]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_65 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, lineStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, ":", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_65+currStrOff, posStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_65+currStrOff, "\n\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_65+currStrOff, msg, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_65);
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
for (; (i<codeLength); i++) {
char c = s[i];
char nc = (char)0;
if ((i+1<codeLength)) {
nc = s[i+1];
}
if ((c==47)) {
nc = s[i+1];
if ((nc==47)) {
for (; (i<codeLength); i++) {
c = s[i];
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
lineNb++;
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
for (; (i<codeLength); i++) {
c = s[i];
char pc = s[i-1];
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
else if (isNumber(c)||isMinus(c,nc)) {

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
for (; (i<codeLength); i++) {
c = s[i];
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
if ((c<97)||(c>102)) {
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
i--;

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
i++;
char n = s[i];
char * toInt = intToStr((long int)nc);
memory = strToArr(toInt);
i++;
c = s[i];
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
i++;
for (; (i<codeLength); i++) {
c = s[i];
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
i--;

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
if ((c==60)) {
long int pos = i;
char isCast = false;

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
i++;
for (; (i<codeLength); i++) {
c = s[i];
if ((c==62)) {
isCast = true;

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
if ((isAlphaNumeric(c)==false)&&(c!=42)&&(c!=58)&&(c!=95)&&(c!=91)&&(c!=93)) {
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
if ((isCast==true)) {

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
}
};
continue;
}
i = pos;
c = 60;
clear(memory);
}

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
i++;
char fc = c;
for (; (i<codeLength); i++) {
c = s[i];

        char ____BAH_COMPILER_VAR_66 = 0;
        for(int i=syntaxes->length-1; i!=-1;i--) {
            if (syntaxes->data[i] == c) {
                ____BAH_COMPILER_VAR_66=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_66==false)) {
break;
}
if ((fc==60)) {
if ((c!=45)&&(c!=61)&&(c!=60)) {
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
i--;

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
else if (isAlphaNumeric(c)||(c==95)) {

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
i++;
for (; (i<codeLength); i++) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
if ((c!=95)) {
if ((c==62)) {
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
i--;
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
i--;
tokenType currentType = TOKEN_TYPE_VAR;
char * memstr = arrAsStr(memory);

        char ____BAH_COMPILER_VAR_67 = 0;
        for(int i=keywords->length-1; i!=-1;i--) {
            if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                ____BAH_COMPILER_VAR_67=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_67) {
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
char * ____BAH_COMPILER_VAR_68 =splitStringBefore(n,".");struct string res = string(____BAH_COMPILER_VAR_68);
return res;
}
if (n.count(&n,"->")) {
char * ____BAH_COMPILER_VAR_69 =splitStringBefore(n,"->");struct string res = string(____BAH_COMPILER_VAR_69);
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
for (; (i!=-1); i--) {
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
struct structMemb* m = members->data[i];
if ((strcmp(m->name, name) == 0)) {
return m;
}
i = i+1;
};
array(struct func*)* mthds = s->methods;
i = 0;
while ((i<len(mthds))) {
struct func* m = mthds->data[i];
if ((strcmp(m->name, name) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_70 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_70->name = "";
____BAH_COMPILER_VAR_70->type = "";
____BAH_COMPILER_VAR_70->isConst = false;
____BAH_COMPILER_VAR_70->constVal = "";
____BAH_COMPILER_VAR_70->isArray = false;
____BAH_COMPILER_VAR_70->from = "";
____BAH_COMPILER_VAR_70->outterScope = false;
____BAH_COMPILER_VAR_70->isGlobal = false;
____BAH_COMPILER_VAR_70->def = "";
____BAH_COMPILER_VAR_70->isFn = false;
struct structMemb* sm = ____BAH_COMPILER_VAR_70;
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
struct func* searchFunc(char * n,struct Elems* e,char c);
struct func* parseFnType(struct string n);
struct func* searchStructMethod(char * name,struct cStruct* s,struct Elems* elems){
if ((s==null)) {
return null;
}
char * ____BAH_COMPILER_VAR_71 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_71 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_71+currStrOff, s->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_71+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_71+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* fn = searchFunc(____BAH_COMPILER_VAR_71,elems,true);
if ((fn!=null)) {
return fn;
}
long int i = 0;
for (; (i<len(s->members)); i++) {
if ((strcmp(s->members->data[i]->name, name) == 0)) {
struct string ____BAH_COMPILER_VAR_72 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_72);
fn->name = name;
return fn;
}
};
s = searchStruct(s->extendedFrom,elems);
return searchStructMethod(name,s,elems);
};
char typeAsStar(char * t){
return (t[strlen(t)-1]==42);
};
char isRCPpointerType(char * t){
if (strHasPrefix(t,"function(")) {
return false;
}
if ((strcmp(t, "cpstring") == 0)||(strcmp(t, "ptr") == 0)||typeAsStar(t)||strHasPrefix(t,"[]")||strHasPrefix(t,"chan:")||strHasPrefix(t,"map:")) {
return true;
}
return false;
};
char isRCPtype(char * t,struct Elems* elems){
if ((isRCPpointerType(t)==true)) {
return true;
}
struct cStruct* s = searchStruct(t,elems);
if ((s!=null)&&(s->isBinding==false)) {
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
char * ____BAH_COMPILER_VAR_73 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t);
long int strLen_1 = strlen(")*");
long int strLen_2 = strlen("array(");
;                            
            ____BAH_COMPILER_VAR_73 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_73+currStrOff, "array(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_73+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_73+currStrOff, ")*", strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_73;
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
else if ((strcmp(ctp.str(&ctp), "int") == 0)) {
tp.replace(&tp,"int","long int");
}
else if ((strcmp(ctp.str(&ctp), "int32") == 0)) {
tp.replace(&tp,"int32","int");
}
else if ((strcmp(ctp.str(&ctp), "uint32") == 0)) {
tp.replace(&tp,"uint32","unsigned int");
}
else if ((strcmp(ctp.str(&ctp), "uint") == 0)) {
tp.replace(&tp,"uint","unsigned long int");
}
else if ((strcmp(ctp.str(&ctp), "float32") == 0)) {
tp.replace(&tp,"float32","float");
}
else if ((strcmp(ctp.str(&ctp), "ufloat32") == 0)) {
tp.replace(&tp,"ufloat32","unsigned float");
}
else if ((strcmp(ctp.str(&ctp), "ufloat") == 0)) {
tp.replace(&tp,"ufloat","unsigned double");
}
else if ((strcmp(ctp.str(&ctp), "float") == 0)) {
tp.replace(&tp,"float","double");
}
else if ((strcmp(ctp.str(&ctp), "long") == 0)) {
tp.replace(&tp,"long","long long");
}
else if ((strcmp(ctp.str(&ctp), "ulong") == 0)) {
tp.replace(&tp,"ulong","unsigned long long");
}
else if ((strcmp(ctp.str(&ctp), "cpstring") == 0)) {
tp.replace(&tp,"cpstring","char *");
}
else if ((strcmp(ctp.str(&ctp), "ptr") == 0)) {
tp.replace(&tp,"ptr","void *");
}
else if ((strcmp(ctp.str(&ctp), "ushort") == 0)) {
tp.replace(&tp,"ushort","unsigned short");
}
else if ((strcmp(ctp.str(&ctp), "byte") == 0)) {
tp.replace(&tp,"byte","unsigned char");
}
else if ((strcmp(ctp.str(&ctp), "bool") == 0)) {
tp.replace(&tp,"bool","char");
}
else if ((strcmp(ctp.str(&ctp), "char") == 0)) {
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
if ((strcmp(a, "cpstring") == 0)&&strHasPrefix(b,"buffer:")) {
return true;
}

        char ____BAH_COMPILER_VAR_74 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_74=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_75 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_75=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_74&&____BAH_COMPILER_VAR_75) {
return true;
}

        char ____BAH_COMPILER_VAR_76 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_76=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_77 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_77=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_76&&____BAH_COMPILER_VAR_77) {
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
if ((strcmp(a, "ptr") == 0)||(strcmp(b, "ptr") == 0)||(strcmp(a, b) == 0)) {
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
struct reflectElement ____BAH_COMPILER_VAR_78 = {};
____BAH_COMPILER_VAR_78.type= null;
____BAH_COMPILER_VAR_78.name= null;
____BAH_COMPILER_VAR_78.arrayElem= null;
____BAH_COMPILER_VAR_78.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_78.structLayout->length = 0;
            ____BAH_COMPILER_VAR_78.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_78.value= null;
____BAH_COMPILER_VAR_78.calculateOffset = reflectElement__calculateOffset;
#define re ____BAH_COMPILER_VAR_78
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
struct string p1 = parts->data[0];
struct string p2 = parts->data[1];
long int j = 0;
for (; (j<len(syms)); j++) {
struct reflectElement s = syms->data[j];
if ((strcmp(s.name, p1.str(&p1)) == 0)) {
long int k = 0;
for (; (k<len(s.structLayout)); k++) {
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
for (; (j<len(syms)); j++) {
struct reflectElement s = syms->data[j];
if ((strcmp(s.name, a.str(&a)) == 0)) {
return s;
}
};
}
struct reflectElement ____BAH_COMPILER_VAR_79 = {};
____BAH_COMPILER_VAR_79.type= null;
____BAH_COMPILER_VAR_79.name= null;
____BAH_COMPILER_VAR_79.arrayElem= null;
____BAH_COMPILER_VAR_79.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_79.structLayout->length = 0;
            ____BAH_COMPILER_VAR_79.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_79.value= null;
____BAH_COMPILER_VAR_79.calculateOffset = reflectElement__calculateOffset;
#define ns ____BAH_COMPILER_VAR_79
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
if ((strcmp(this->content, "1") == 0)||(strcmp(this->content, "true") == 0)) {
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
struct jsonElement* c = this->children->data[i];
void * ne = memoryAlloc(ae->size);
long int j = 0;
while ((j<len(ae->structLayout))) {
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
for (; (i<len(this->children)); i++) {
struct jsonElement* c = this->children->data[i];
struct reflectElement* ae = e.arrayElem;
void * v = memoryAlloc(ae->size);
ae->value = &v;
long int j = 0;
for (; (j<len(ae->structLayout)); j++) {
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
if (strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0)||(strcmp(ae->type, "cpstring") == 0)||strHasPrefix(ae->type,"[]")||strHasPrefix(ae->type,"map:")) {
char * ____BAH_COMPILER_VAR_80 =k.str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_80,v);
}
else {
char * ____BAH_COMPILER_VAR_81 =k.str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_81,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_82 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_82->key= null;
____BAH_COMPILER_VAR_82->content= null;
____BAH_COMPILER_VAR_82->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_82->children->length = 0;
            ____BAH_COMPILER_VAR_82->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_82->get = jsonElement__get;
____BAH_COMPILER_VAR_82->str = jsonElement__str;
____BAH_COMPILER_VAR_82->scan = jsonElement__scan;
struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_82;
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
if ((i>start)&&(cpstringCharAt(s,i-1)==(char)92)) {
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
char * ____BAH_COMPILER_VAR_83 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_83);
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
char * ____BAH_COMPILER_VAR_84 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_84);
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
char * ____BAH_COMPILER_VAR_85 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_85);
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
char * ____BAH_COMPILER_VAR_86 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_86);
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
if ((e.value==null)||(*v==null)) {
if ((strcmp(e.type, "int") == 0)||(strcmp(e.type, "float") == 0)) {
return "0";
}
if ((strcmp(e.type, "bool") == 0)) {
return "false";
}
if ((strcmp(e.type, "ptr") == 0)||(strcmp(e.type, "cpstring") == 0)||(strCount(e.type,"*")!=0)) {
return "null";
}
}
if ((e.isStruct==true)) {
tabs = tabs+1;
char * tabsStr = "";
long int i = 0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_87 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_87 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_87+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_87+currStrOff, "\t", strLen_1);
            currStrOff += strLen_1;
        
        }tabsStr = ____BAH_COMPILER_VAR_87;
i = i+1;
};
char * s = "{\n";
i = 0;
while ((i<len(e.structLayout))) {
struct reflectElement m = e.structLayout->data[i];
i = i+1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_88 =null;char * ____BAH_COMPILER_VAR_89 =toJson__inner(m,true,tabs);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_89);
long int strLen_1 = strlen(",\n");
long int strLen_2 = strlen("\": ");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\"");
long int strLen_5 = strlen(tabsStr);
long int strLen_6 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_88 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, s, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, tabsStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_88+currStrOff, "\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_88+currStrOff, ____BAH_COMPILER_VAR_89, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_88+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_88;
}
else {
char * ____BAH_COMPILER_VAR_90 =null;char * ____BAH_COMPILER_VAR_91 =toJson__inner(m,true,tabs);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_91);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("\": ");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\"");
long int strLen_5 = strlen(tabsStr);
long int strLen_6 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_90 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, s, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, tabsStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_90+currStrOff, "\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_90+currStrOff, ____BAH_COMPILER_VAR_91, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_90+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_90;
}
};
tabs = tabs-1;
tabsStr = "";
i = 0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_92 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_92 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_92+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_92+currStrOff, "\t", strLen_1);
            currStrOff += strLen_1;
        
        }tabsStr = ____BAH_COMPILER_VAR_92;
i = i+1;
};
char * ____BAH_COMPILER_VAR_93 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("}");
long int strLen_2 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_93 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_93+currStrOff, s, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_93+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_93+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_93;
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
char * ____BAH_COMPILER_VAR_94 =null;char * ____BAH_COMPILER_VAR_95 =jsonEscapeStr(s);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_95);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_94 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_94+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_94+currStrOff, ____BAH_COMPILER_VAR_95, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_94+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_94;
}
else {
char ** sp = e.value;
char * s = *sp;
char * ____BAH_COMPILER_VAR_96 =null;char * ____BAH_COMPILER_VAR_97 =jsonEscapeStr(s);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_97);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_96 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_96+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_96+currStrOff, ____BAH_COMPILER_VAR_97, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_96+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_96;
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
char * ____BAH_COMPILER_VAR_98 =null;char * ____BAH_COMPILER_VAR_99 =intToStr(arr->data[i]);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_99);
;                            
            ____BAH_COMPILER_VAR_98 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_98+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_98+currStrOff, ____BAH_COMPILER_VAR_99, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_98;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_100 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_100 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_100+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_100+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_100;
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
char * ____BAH_COMPILER_VAR_101 =null;char * ____BAH_COMPILER_VAR_102 =floatToStr(arr->data[i]);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_102);
;                            
            ____BAH_COMPILER_VAR_101 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_101+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_101+currStrOff, ____BAH_COMPILER_VAR_102, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_101;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_103 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_103 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_103+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_103+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_103;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
arr = *arrPtr;
char * ____BAH_COMPILER_VAR_104 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_104 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_104+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_104+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_104;
long int i = 0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_105 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(arr->data[i]);
;                            
            ____BAH_COMPILER_VAR_105 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, arr->data[i], strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_105;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_106 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_106 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_106+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_106+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_106;
}
else {
char * ____BAH_COMPILER_VAR_107 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_107 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_107+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_107+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_107;
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
void * arrElem = arr->data[i];
ae->value = arrElem;
long int j = 0;
while ((j<len(ae->structLayout))) {
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
char * ____BAH_COMPILER_VAR_108 =null;char * ____BAH_COMPILER_VAR_109 =toJson__inner(*ae,false,tabs);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_109);
;                            
            ____BAH_COMPILER_VAR_108 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_108+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_108+currStrOff, ____BAH_COMPILER_VAR_109, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_108;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_110 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_110 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_110+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_110+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_110;
}
else {
char * ____BAH_COMPILER_VAR_111 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_111 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_111+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_111+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_111;
}
};
}
char * ____BAH_COMPILER_VAR_112 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_112 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_112+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_112+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_112;
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
char * ____BAH_COMPILER_VAR_113 = name;
struct reflectElement ____BAH_COMPILER_VAR_114 = __reflect(____BAH_COMPILER_VAR_113, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_115 =null;char * ____BAH_COMPILER_VAR_116 =toJson(e);char * ____BAH_COMPILER_VAR_117 =intToStr(line);char * ____BAH_COMPILER_VAR_118 =toJson(____BAH_COMPILER_VAR_114);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_116);
long int strLen_1 = strlen("\n    },\n    ");
long int strLen_2 = strlen("\",\n        \"element\": ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_117);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(",\n        \"path\": \"");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_118);
long int strLen_8 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_115 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\n    {\n        \"name\": ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_118, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ",\n        \"path\": \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_117, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\",\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_115+currStrOff, ____BAH_COMPILER_VAR_116, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_115+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_119 =____BAH_COMPILER_VAR_115;println(____BAH_COMPILER_VAR_119);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_120 = name;
struct reflectElement ____BAH_COMPILER_VAR_121 = __reflect(____BAH_COMPILER_VAR_120, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_122 =null;char * ____BAH_COMPILER_VAR_123 =toJson(e);char * ____BAH_COMPILER_VAR_124 =intToStr(to);char * ____BAH_COMPILER_VAR_125 =intToStr(from);char * ____BAH_COMPILER_VAR_126 =intToStr(line);char * ____BAH_COMPILER_VAR_127 =toJson(____BAH_COMPILER_VAR_121);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_123);
long int strLen_1 = strlen("\n    },\n    ");
long int strLen_2 = strlen("\n        ],\n        \"element\": ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_124);
long int strLen_4 = strlen(",\n            ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_125);
long int strLen_6 = strlen("\",\n        \"range\": [\n            ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_126);
long int strLen_8 = strlen(":");
long int strLen_9 = strlen(compilerState.currentFile);
long int strLen_10 = strlen(",\n        \"path\": \"");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_127);
long int strLen_12 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_122 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, "\n    {\n        \"name\": ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ____BAH_COMPILER_VAR_127, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ",\n        \"path\": \"", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, compilerState.currentFile, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ":", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ____BAH_COMPILER_VAR_126, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ____BAH_COMPILER_VAR_125, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ",\n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, ____BAH_COMPILER_VAR_124, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_122+currStrOff, "\n        ],\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_122+currStrOff, ____BAH_COMPILER_VAR_123, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_122+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_128 =____BAH_COMPILER_VAR_122;println(____BAH_COMPILER_VAR_128);
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
struct variable* v = elems->vars->data[i];
if ((v->outterScope==false)&&(v->isConst==false)) {
struct variable* ____BAH_COMPILER_VAR_129 = v;
char ** ____BAH_COMPILER_VAR_131 = (char **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_132 = __reflect(____BAH_COMPILER_VAR_131, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_133 = (char **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_134 = __reflect(____BAH_COMPILER_VAR_133, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_135 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_136 = __reflect(____BAH_COMPILER_VAR_135, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_137 = (char **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_138 = __reflect(____BAH_COMPILER_VAR_137, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_139 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_140 = __reflect(____BAH_COMPILER_VAR_139, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_141 = (char **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_142 = __reflect(____BAH_COMPILER_VAR_141, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_143 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_144 = __reflect(____BAH_COMPILER_VAR_143, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_145 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_146 = __reflect(____BAH_COMPILER_VAR_145, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_130 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_130->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_130->length = 8;
        ____BAH_COMPILER_VAR_130->data = memoryAlloc(____BAH_COMPILER_VAR_130->length * ____BAH_COMPILER_VAR_130->elemSize);
        ____BAH_COMPILER_VAR_130->data[0] = ____BAH_COMPILER_VAR_132;
____BAH_COMPILER_VAR_130->data[1] = ____BAH_COMPILER_VAR_134;
____BAH_COMPILER_VAR_130->data[2] = ____BAH_COMPILER_VAR_136;
____BAH_COMPILER_VAR_130->data[3] = ____BAH_COMPILER_VAR_138;
____BAH_COMPILER_VAR_130->data[4] = ____BAH_COMPILER_VAR_140;
____BAH_COMPILER_VAR_130->data[5] = ____BAH_COMPILER_VAR_142;
____BAH_COMPILER_VAR_130->data[6] = ____BAH_COMPILER_VAR_144;
____BAH_COMPILER_VAR_130->data[7] = ____BAH_COMPILER_VAR_146;
struct reflectElement ____BAH_COMPILER_VAR_147 = __reflect(____BAH_COMPILER_VAR_129, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_130, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_147);
}
i = i+1;
};
};
void throwErr(void * tp,char * format){
char * str = "";
char * info = "";
long int pos = 0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_148 = {};
____BAH_COMPILER_VAR_148.handle = -1;
____BAH_COMPILER_VAR_148.p= null;
____BAH_COMPILER_VAR_148.open = fileMap__open;
____BAH_COMPILER_VAR_148.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_148.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_148
char * fileSrcStr = fm.open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char * ____BAH_COMPILER_VAR_149 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t->ogCont);
long int strLen_1 = strlen("'");
long int strLen_2 = strlen("'");
;                            
            ____BAH_COMPILER_VAR_149 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_149+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_149+currStrOff, t->ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_149+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }ffmt.replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_149);
format = ffmt.str(&ffmt);
array(char)* line = memoryAlloc(sizeof(array(char)));

line->length = 0;
line->elemSize = sizeof(char);
long int beg = t->pos;
while ((beg>0)) {
char c = fileSrcStr[beg];
if ((c==(char)10)) {
beg = beg+1;
break;
}
beg = beg-1;
};
pos = t->pos-beg+1;
long int i = beg;
while ((i<fm.size)) {
char c = fileSrcStr[i];
if ((c==(char)10)) {
break;
}
if ((i==t->pos)) {
char * ____BAH_COMPILER_VAR_150 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t->ogCont);
long int strLen_1 = strlen("\e[1;37m");
long int strLen_2 = strlen("\e[1;31m");
;                            
            ____BAH_COMPILER_VAR_150 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_150+currStrOff, "\e[1;31m", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_150+currStrOff, t->ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_150+currStrOff, "\e[1;37m", strLen_1);
            currStrOff += strLen_1;
        
        }array(char)* errTk = strToArr(____BAH_COMPILER_VAR_150);
long int ii = 0;
while ((ii<len(errTk))) {

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
char * ____BAH_COMPILER_VAR_151 =null;char * ____BAH_COMPILER_VAR_152 =intToStr(pos);char * ____BAH_COMPILER_VAR_153 =intToStr(t->line);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(":");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_152);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_153);
;                            
            ____BAH_COMPILER_VAR_151 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_151+currStrOff, ____BAH_COMPILER_VAR_153, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_151+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_151+currStrOff, ____BAH_COMPILER_VAR_152, strLen_1);
            currStrOff += strLen_1;
        
        }info = ____BAH_COMPILER_VAR_151;

#undef fm
}
if ((debug==true)) {
struct Tok* t = tp;
char * ____BAH_COMPILER_VAR_154 = format;
struct reflectElement ____BAH_COMPILER_VAR_155 = __reflect(____BAH_COMPILER_VAR_154, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_155);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_156 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("\e[0m\n");
long int strLen_1 = strlen(format);
long int strLen_2 = strlen(str);
long int strLen_3 = strlen("\n\e[1;37m\t");
long int strLen_4 = strlen(info);
long int strLen_5 = strlen(":");
long int strLen_6 = strlen(compilerState.currentFile);
long int strLen_7 = strlen("\e[1;31m[ERROR]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_156 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, info, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, "\n\e[1;37m\t", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_156+currStrOff, str, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_156+currStrOff, "\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_156+currStrOff, format, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_156);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_157 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\e[0m");
long int strLen_2 = strlen("\n\e[1;37m\t");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen("\e[1;33m[WARNING]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_157 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_157+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_157+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_157+currStrOff, "\n\e[1;37m\t", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_157+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_157+currStrOff, "\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_157);
};
#include <stdlib.h>
char * absPath(char * path){
char * p = realpath(path,null);
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
struct variable* ____BAH_COMPILER_VAR_158 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_158->name = "";
____BAH_COMPILER_VAR_158->type = "";
____BAH_COMPILER_VAR_158->isConst = false;
____BAH_COMPILER_VAR_158->constVal = "";
____BAH_COMPILER_VAR_158->isArray = false;
____BAH_COMPILER_VAR_158->from = "";
____BAH_COMPILER_VAR_158->outterScope = false;
____BAH_COMPILER_VAR_158->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_158;
nv->type = vtstr;
nv->name = ogName;
nv->outterScope = v->outterScope;
nv->isArray = isArr;
return nv;
}
name = n.content;
if (hasStructSep(n)&&(n.count(&n,")")==0)) {
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
struct variable* ____BAH_COMPILER_VAR_159 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_159->name = "";
____BAH_COMPILER_VAR_159->type = "";
____BAH_COMPILER_VAR_159->isConst = false;
____BAH_COMPILER_VAR_159->constVal = "";
____BAH_COMPILER_VAR_159->isArray = false;
____BAH_COMPILER_VAR_159->from = "";
____BAH_COMPILER_VAR_159->outterScope = false;
____BAH_COMPILER_VAR_159->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_159;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->outterScope = v->outterScope;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (tcc.count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_160 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_160 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_160+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_160+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_160;
}
long int nbUnaries = tcc.count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = ct.count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_161 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nv->name);
long int strLen_1 = strlen(" because it is not pointer.");
long int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_161 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_161+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_161+currStrOff, nv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_161+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_161);
}
ct.trimRight(&ct,nbUnaries);
r = ct.str(&ct);
}
nv->type = r;
nv->name = ogName;
return nv;
}
long int i = len(elems->vars)-1;
for (; (i!=-1); i--) {
struct variable* v = elems->vars->data[i];
if ((strcmp(v->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_162 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_162->name = "";
____BAH_COMPILER_VAR_162->type = "";
____BAH_COMPILER_VAR_162->isConst = false;
____BAH_COMPILER_VAR_162->constVal = "";
____BAH_COMPILER_VAR_162->isArray = false;
____BAH_COMPILER_VAR_162->from = "";
____BAH_COMPILER_VAR_162->outterScope = false;
____BAH_COMPILER_VAR_162->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_162;
nv->type = v->type;
nv->name = v->name;
nv->isConst = v->isConst;
nv->outterScope = v->outterScope;
char * r = nv->type;
struct string tcc = string(ogName);
if (tcc.count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_163 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_163 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_163+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_163+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_163;
}
long int nbUnaries = tcc.count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = ct.count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_164 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" because it is not pointer.");
long int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_164 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_164+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_164+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_164+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_164);
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
for (; (i<len(elems->fns)); i++) {
struct func* fn = elems->fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_165 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_165->name = "";
____BAH_COMPILER_VAR_165->type = "";
____BAH_COMPILER_VAR_165->isConst = false;
____BAH_COMPILER_VAR_165->constVal = "";
____BAH_COMPILER_VAR_165->isArray = false;
____BAH_COMPILER_VAR_165->from = "";
____BAH_COMPILER_VAR_165->outterScope = false;
____BAH_COMPILER_VAR_165->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_165;
nv->name = name;
nv->type = "function(";
long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
char * ____BAH_COMPILER_VAR_166 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(arg->type);
;                            
            ____BAH_COMPILER_VAR_166 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_166+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_166+currStrOff, arg->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_166;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_167 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_167 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_167+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_167+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_167;
}
};
fn->used = true;
char * ____BAH_COMPILER_VAR_168 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(")");
long int strLen_1 = strlen(fn->returns->type);
long int strLen_2 = strlen(nv->type);
;                            
            ____BAH_COMPILER_VAR_168 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_168+currStrOff, nv->type, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_168+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_168+currStrOff, fn->returns->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_168;
return nv;
}
};
return null;
};
struct variable* searchVarByToken(struct Tok t,struct Elems* elems){
if ((t.bahRef!=null)) {
return t.bahRef;
}
return searchVar(t.cont,elems);
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp = getCType(v->type,elems);
char * t = tp.str(&tp);
char * ____BAH_COMPILER_VAR_169 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(t);
;                            
            ____BAH_COMPILER_VAR_169 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_169+currStrOff, t, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_169+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_169+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }t = ____BAH_COMPILER_VAR_169;
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
struct variable* ____BAH_COMPILER_VAR_171 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_171->name = "";
____BAH_COMPILER_VAR_171->type = "";
____BAH_COMPILER_VAR_171->isConst = false;
____BAH_COMPILER_VAR_171->constVal = "";
____BAH_COMPILER_VAR_171->isArray = false;
____BAH_COMPILER_VAR_171->from = "";
____BAH_COMPILER_VAR_171->outterScope = false;
____BAH_COMPILER_VAR_171->isGlobal = false;
struct variable* arg = ____BAH_COMPILER_VAR_171;
char * ____BAH_COMPILER_VAR_172 =null;char * ____BAH_COMPILER_VAR_173 =intToStr(len(nf->args));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("arg_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_173);
;                            
            ____BAH_COMPILER_VAR_172 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_172+currStrOff, "arg_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_172+currStrOff, ____BAH_COMPILER_VAR_173, strLen_1);
            currStrOff += strLen_1;
        
        }arg->name = ____BAH_COMPILER_VAR_172;
while ((j<cvt.length)) {
c = cvt.charAt(&cvt,j);
if ((c==44)||(c==41)) {
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
struct variable* ____BAH_COMPILER_VAR_174 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_174->name = "";
____BAH_COMPILER_VAR_174->type = "";
____BAH_COMPILER_VAR_174->isConst = false;
____BAH_COMPILER_VAR_174->constVal = "";
____BAH_COMPILER_VAR_174->isArray = false;
____BAH_COMPILER_VAR_174->from = "";
____BAH_COMPILER_VAR_174->outterScope = false;
____BAH_COMPILER_VAR_174->isGlobal = false;
nf->returns = ____BAH_COMPILER_VAR_174;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_175 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_175->name = "";
____BAH_COMPILER_VAR_175->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_175->args->length = 0;
            ____BAH_COMPILER_VAR_175->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_175->returns= null;
____BAH_COMPILER_VAR_175->isBinding = false;
____BAH_COMPILER_VAR_175->from = "";
____BAH_COMPILER_VAR_175->file = "";
____BAH_COMPILER_VAR_175->line = 1;
____BAH_COMPILER_VAR_175->used = false;
____BAH_COMPILER_VAR_175->code = null;
struct func* fn = ____BAH_COMPILER_VAR_175;
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
char * ____BAH_COMPILER_VAR_176 =fnName.str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_176,s,elems);
name = fnName.content;
char * ____BAH_COMPILER_VAR_177 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen(memb->from);
;                            
            ____BAH_COMPILER_VAR_177 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_177+currStrOff, memb->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_177+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_177+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_177;
}
array(struct func*)* fns = elems->fns;
long int i = 0;
while ((i<len(fns))) {
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
struct func* ____BAH_COMPILER_VAR_178 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_178->name = "";
____BAH_COMPILER_VAR_178->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_178->args->length = 0;
            ____BAH_COMPILER_VAR_178->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_178->returns= null;
____BAH_COMPILER_VAR_178->isBinding = false;
____BAH_COMPILER_VAR_178->from = "";
____BAH_COMPILER_VAR_178->file = "";
____BAH_COMPILER_VAR_178->line = 1;
____BAH_COMPILER_VAR_178->used = false;
____BAH_COMPILER_VAR_178->code = null;
struct func* nf = ____BAH_COMPILER_VAR_178;
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
struct func* searchFuncByToken(struct Tok t,struct Elems* elems){
if ((t.bahRef!=null)) {
return t.bahRef;
}
struct string ____BAH_COMPILER_VAR_179 =string(t.cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_179,"(");
return searchFunc(fnName,elems,true);
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
struct structMemb* m = members->data[i];
struct string cmpt = string(m->type);
char declared = false;
if ((strlen(m->def)>0)) {
char * ____BAH_COMPILER_VAR_180 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->def);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(sep);
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_180 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, code, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_180+currStrOff, m->def, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_180+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_180;
declared = true;
}
if ((cmpt.hasPrefix(&cmpt,"[]")==1)) {
cmpt.trimLeft(&cmpt,2);
char * cmptstr = cmpt.str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = elemCType.str(&elemCType);
char * ____BAH_COMPILER_VAR_181 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(elemCTypeStr);
long int strLen_1 = strlen(");\n            ");
long int strLen_2 = strlen("->elemSize = sizeof(");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(sep);
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen("->length = 0;\n            ");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen(sep);
long int strLen_9 = strlen(v->name);
long int strLen_10 = strlen(")));\n            ");
long int strLen_11 = strlen(elemCTypeStr);
long int strLen_12 = strlen(" = memoryAlloc(sizeof(array(");
long int strLen_13 = strlen(m->name);
long int strLen_14 = strlen(sep);
long int strLen_15 = strlen(v->name);
long int strLen_16 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_181 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, code, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, v->name, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, sep, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, m->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, " = memoryAlloc(sizeof(array(", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, elemCTypeStr, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, ")));\n            ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, v->name, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, sep, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, "->length = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, "->elemSize = sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_181+currStrOff, elemCTypeStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_181+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_181;
declared = true;
}
else if ((cmpt.hasPrefix(&cmpt,"map:")==1)) {
cmpt.trimLeft(&cmpt,4);
char * ____BAH_COMPILER_VAR_182 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(" = mapWrapper();\n");
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_182 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_182+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_182+currStrOff, " = mapWrapper();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_183 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_182);
;                            
            ____BAH_COMPILER_VAR_183 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_183+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_183+currStrOff, ____BAH_COMPILER_VAR_182, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_183;
declared = true;
}
else if ((cmpt.hasPrefix(&cmpt,"chan:")==1)) {
cmpt.trimLeft(&cmpt,5);
char * ____BAH_COMPILER_VAR_184 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(" = channel();\n");
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_184 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_184+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_184+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_184+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_184+currStrOff, " = channel();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_185 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_184);
;                            
            ____BAH_COMPILER_VAR_185 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_185+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_185+currStrOff, ____BAH_COMPILER_VAR_184, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_185;
declared = true;
}
if (isRCPpointerType(m->type)&&(declared==false)) {
char * ____BAH_COMPILER_VAR_186 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen("= null;\n");
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_186 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_186+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_186+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_186+currStrOff, "= null;\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_186;
}
i = i+1;
};
if ((strlen(s->extendedFrom)>0)) {
struct cStruct* es = searchStruct(s->extendedFrom,elems);
i = 0;
while ((i<len(es->methods))) {
struct func* m = es->methods->data[i];
char * ____BAH_COMPILER_VAR_187 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("__");
long int strLen_3 = strlen(es->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(m->name);
long int strLen_6 = strlen(sep);
long int strLen_7 = strlen(v->name);
long int strLen_8 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_187 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, code, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, sep, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, m->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, es->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, "__", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_187+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_187+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_187;
i = i+1;
};
}
array(struct func*)* methods = s->methods;
i = 0;
while ((i<len(methods))) {
struct func* m = methods->data[i];
char * ____BAH_COMPILER_VAR_188 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("__");
long int strLen_3 = strlen(s->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(m->name);
long int strLen_6 = strlen(sep);
long int strLen_7 = strlen(v->name);
long int strLen_8 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_188 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, code, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, sep, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, m->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, s->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_188+currStrOff, "__", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_188+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_188+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_188;
i = i+1;
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); i++) {
struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char * ____BAH_COMPILER_VAR_189 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(amp);
long int strLen_3 = strlen("(");
long int strLen_4 = strlen(m->name);
long int strLen_5 = strlen(sep);
long int strLen_6 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_189 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_189+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_189+currStrOff, sep, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_189+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_189+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_189+currStrOff, amp, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_189+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_189+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_190 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(NEXT_LINE);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_189);
;                            
            ____BAH_COMPILER_VAR_190 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_190+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_190+currStrOff, ____BAH_COMPILER_VAR_189, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_190;
found++;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char * ____BAH_COMPILER_VAR_191 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen("memoryOnEnd(");
;                            
            ____BAH_COMPILER_VAR_191 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, "memoryOnEnd(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_191+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_191+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_191+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_192 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_191);
;                            
            ____BAH_COMPILER_VAR_192 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_192+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_192+currStrOff, ____BAH_COMPILER_VAR_191, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_192;
}
found++;
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
char * ____BAH_COMPILER_VAR_193 =null;char * ____BAH_COMPILER_VAR_194 =intToStr(NB_COMP_VAR);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("____BAH_COMPILER_VAR_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_194);
;                            
            ____BAH_COMPILER_VAR_193 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_193+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_193+currStrOff, ____BAH_COMPILER_VAR_194, strLen_1);
            currStrOff += strLen_1;
        
        }char * name = ____BAH_COMPILER_VAR_193;
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
for (; (i<len(a)); i++) {
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
char * ____BAH_COMPILER_VAR_195 =null;char * ____BAH_COMPILER_VAR_196 =pathToVarName(compilerState.currentFile);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(name);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_196);
;                            
            ____BAH_COMPILER_VAR_195 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_195+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_195+currStrOff, ____BAH_COMPILER_VAR_196, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_195;
}
char * evals = "";
char * ____BAH_COMPILER_VAR_197 =null;char * ____BAH_COMPILER_VAR_198 =intToStr(len(compilerState.evals));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_198);
long int strLen_1 = strlen("] = {");
long int strLen_2 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
;                            
            ____BAH_COMPILER_VAR_197 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_197+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_197+currStrOff, ____BAH_COMPILER_VAR_198, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_197+currStrOff, "] = {", strLen_1);
            currStrOff += strLen_1;
        
        }char * evalsTMPDecl = ____BAH_COMPILER_VAR_197;
long int i = 0;
for (; (i<len(compilerState.evals)); i++) {
char * e = compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_199 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(e);
long int strLen_1 = strlen("\n        }");
long int strLen_2 = strlen("\",\n            .evalFn = __Bah_eval_");
long int strLen_3 = strlen(e);
long int strLen_4 = strlen("{\n            .name = \"");
;                            
            ____BAH_COMPILER_VAR_199 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, "{\n            .name = \"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_199+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_199+currStrOff, e, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_199+currStrOff, "\n        }", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_200 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_199);
;                            
            ____BAH_COMPILER_VAR_200 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_200+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_200+currStrOff, ____BAH_COMPILER_VAR_199, strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_200;
if ((i+1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_201 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_201 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_201+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_201+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_201;
}
else {
char * ____BAH_COMPILER_VAR_202 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen("};");
;                            
            ____BAH_COMPILER_VAR_202 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_202+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_202+currStrOff, "};", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_202;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_203 =null;char * ____BAH_COMPILER_VAR_204 =intToStr(len(compilerState.evals));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_204);
long int strLen_1 = strlen(";");
long int strLen_2 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
;                            
            ____BAH_COMPILER_VAR_203 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_203+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_203+currStrOff, ____BAH_COMPILER_VAR_204, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_203+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }evals = ____BAH_COMPILER_VAR_203;
}
else {
evalsTMPDecl = "";
}
char * ____BAH_COMPILER_VAR_205 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(name);
long int strLen_1 = strlen("() {\n        ");
long int strLen_2 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
long int strLen_3 = strlen(evalsTMPDecl);
long int strLen_4 = strlen("\n    ");
;                            
            ____BAH_COMPILER_VAR_205 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, "\n    ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, evalsTMPDecl, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_205+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_205+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_205+currStrOff, "() {\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_206 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(evals);
long int strLen_1 = strlen("\n    };\n    ");
long int strLen_2 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_206 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_206+currStrOff, "\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_206+currStrOff, evals, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_206+currStrOff, "\n    };\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_205)->add(rope(____BAH_COMPILER_VAR_205), INIT->add(INIT, rope(____BAH_COMPILER_VAR_206))));
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r = rope("");
if (strHasPrefix(v->type,"[]")) {
char * ____BAH_COMPILER_VAR_207 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_207 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_207+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_207+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_207));
}
else if (strHasPrefix(v->type,"chan:")) {
char * ____BAH_COMPILER_VAR_208 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_208 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_208+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_208+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_208));
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_209 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_209->name = "";
____BAH_COMPILER_VAR_209->type = "";
____BAH_COMPILER_VAR_209->isConst = false;
____BAH_COMPILER_VAR_209->constVal = "";
____BAH_COMPILER_VAR_209->isArray = false;
____BAH_COMPILER_VAR_209->from = "";
____BAH_COMPILER_VAR_209->outterScope = false;
____BAH_COMPILER_VAR_209->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_209;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(s->isBinding==false)) {
if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_210 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_210 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_210+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_210));
}
else {
char * ____BAH_COMPILER_VAR_211 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 1);\n");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_211 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, "), 1);\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_211));
}
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_212 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_212 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_212+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_212+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_212+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_212));
}
}
return r;
};
struct rope* incrVar(struct variable* v,struct Elems* elems){
if ((strCount(v->name,"*")>0)) {
return rope("");
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(isRCPpointerType(v->type)==false)&&(s->isBinding==false)) {
char * ____BAH_COMPILER_VAR_213 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 0);");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_213 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_213+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_213+currStrOff, "), 0);", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_213);
}
char * ____BAH_COMPILER_VAR_214 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(");");
long int strLen_2 = strlen("RCP_incr(");
;                            
            ____BAH_COMPILER_VAR_214 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, "RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_214+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_214+currStrOff, ");", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_214);
};
char RCPavailable(){
return (RCPenabled==true);
};
void beginRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
if ((RCPavailable()==false)) {
return;
}
long int i = 0;
for (; (i<len(elems->vars)); i++) {
struct variable* v = elems->vars->data[i];
if (varInArr(v,excl)) {
continue;
}
if ((v->isGlobal==false)&&isRCPtype(v->type,elems)) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(v,elems));
}
};
};
void beginRCPscopeLeaky(struct Elems* elems){
if ((RCPavailable()==false)) {
return;
}
long int i = 0;
for (; (i<len(elems->vars)); i++) {
struct variable* v = elems->vars->data[i];
if ((v->isGlobal==false)&&(v->outterScope==false)&&isRCPtype(v->type,elems)) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(v,elems));
}
};
};
void removeDefs(struct Elems* elems){
long int i = 0;
for (; (i<len(elems->defined)); i++) {
char * ____BAH_COMPILER_VAR_215 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(elems->defined->data[i]);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("\n#undef ");
;                            
            ____BAH_COMPILER_VAR_215 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_215+currStrOff, "\n#undef ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, elems->defined->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_215));
};
};
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
if ((RCPavailable()==false)) {
removeDefs(elems);
return;
}
long int i = 0;
for (; (i<len(elems->vars)); i++) {
struct variable* v = elems->vars->data[i];
if (varInArr(v,excl)) {
continue;
}
if ((v->isGlobal==false)&&isRCPtype(v->type,elems)) {
OUTPUT = OUTPUT->add(OUTPUT, decrVar(v,elems));
}
};
removeDefs(elems);
};
void endRCPscopeLeaky(struct Elems* elems,struct variable* excl){
if ((RCPavailable()==false)) {
removeDefs(elems);
return;
}
long int i = 0;
for (; (i<len(elems->vars)); i++) {
struct variable* v = elems->vars->data[i];
if ((excl!=null)&&(strcmp(excl->name, v->name) == 0)) {
continue;
}
if ((v->isGlobal==false)&&(v->outterScope==false)&&isRCPtype(v->type,elems)) {
OUTPUT = OUTPUT->add(OUTPUT, decrVar(v,elems));
}
};
removeDefs(elems);
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* ____BAH_COMPILER_VAR_216 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_216->name = "";
____BAH_COMPILER_VAR_216->type = "";
____BAH_COMPILER_VAR_216->isConst = false;
____BAH_COMPILER_VAR_216->constVal = "";
____BAH_COMPILER_VAR_216->isArray = false;
____BAH_COMPILER_VAR_216->from = "";
____BAH_COMPILER_VAR_216->outterScope = false;
____BAH_COMPILER_VAR_216->isGlobal = false;
struct variable* av = ____BAH_COMPILER_VAR_216;
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
char * ____BAH_COMPILER_VAR_217 =null;char * ____BAH_COMPILER_VAR_218 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(c);
long int strLen_1 = strlen(";");
long int strLen_2 = strlen(" =");
long int strLen_3 = strlen(av->name);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_218);
;                            
            ____BAH_COMPILER_VAR_217 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, ____BAH_COMPILER_VAR_218, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_217+currStrOff, " =", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, c, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_217));
return av->name;
};
char RCPselfRef(struct variable* v){
long int i = 0;
while ((i<len(compilerState.RCPvars))) {
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

        char ____BAH_COMPILER_VAR_219 = 0;
        for(int i=noVOfns->length-1; i!=-1;i--) {
            if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                ____BAH_COMPILER_VAR_219=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_219) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_220 = {};
____BAH_COMPILER_VAR_220.markup= null;
____BAH_COMPILER_VAR_220.content= null;
#define rv ____BAH_COMPILER_VAR_220
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_221 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("__Bah_safe_string(");
;                            
            ____BAH_COMPILER_VAR_221 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_221+currStrOff, "__Bah_safe_string(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_221+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_221+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_221;
}
char * ____BAH_COMPILER_VAR_222 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(", ");
long int strLen_1 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_222 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_222+currStrOff, ", ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_222+currStrOff, cont, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_222;
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
char * ____BAH_COMPILER_VAR_223 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ASCII_RESET);
long int strLen_1 = strlen("{");
;                            
            ____BAH_COMPILER_VAR_223 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_223+currStrOff, ASCII_RESET, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_223+currStrOff, "{", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_223;
cont = "";
long int i = 0;
for (; (i<len(s->members)); i++) {
struct variable* m = s->members->data[i];
char * ____BAH_COMPILER_VAR_224 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".");
long int strLen_1 = strlen(m->name);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(ogCont);
long int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_224 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, ogCont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_224+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_224+currStrOff, m->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_224,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_225 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_225 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_225;
}
char * ____BAH_COMPILER_VAR_226 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(mv.markup);
;                            
            ____BAH_COMPILER_VAR_226 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_226+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_226+currStrOff, mv.markup, strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_226;
char * ____BAH_COMPILER_VAR_227 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mv.content);
;                            
            ____BAH_COMPILER_VAR_227 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_227+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_227+currStrOff, mv.content, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_227;
};
char * ____BAH_COMPILER_VAR_228 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen("}");
;                            
            ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_228+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_228+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_228;
}
}
char * ____BAH_COMPILER_VAR_229 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(ASCII_RESET);
long int strLen_2 = strlen(ASCII_MAGENTA);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(ASCII_RESET);
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(ASCII_BLUE);
;                            
            ____BAH_COMPILER_VAR_229 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, ASCII_BLUE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, ASCII_RESET, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_229+currStrOff, ASCII_MAGENTA, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_229+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_229+currStrOff, ASCII_RESET, strLen_1);
            currStrOff += strLen_1;
        
        }rv.markup = ____BAH_COMPILER_VAR_229;
rv.content = cont;
return rv;
};
struct verboseOutVar verboseOutTransformTok(struct Tok t,struct Elems* elems){
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)) {
struct variable* v = searchVar(t.cont,elems);
if ((v==null)) {
return verboseOutTransformVar(v,t.cont,elems);
}
}
struct variable ____BAH_COMPILER_VAR_230 = {};
____BAH_COMPILER_VAR_230.name = "";
____BAH_COMPILER_VAR_230.type = "";
____BAH_COMPILER_VAR_230.isConst = false;
____BAH_COMPILER_VAR_230.constVal = "";
____BAH_COMPILER_VAR_230.isArray = false;
____BAH_COMPILER_VAR_230.from = "";
____BAH_COMPILER_VAR_230.outterScope = false;
____BAH_COMPILER_VAR_230.isGlobal = false;
____BAH_COMPILER_VAR_230.name = "(value)";
____BAH_COMPILER_VAR_230.type = getTypeFromToken(&t,true,elems);
#define v ____BAH_COMPILER_VAR_230
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
for (; (i<len(fn->args)); i++) {
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
for (; (j<len(fn->args)); j++) {
struct variable* a = fn->args->data[j];
if ((j!=0)) {
char * ____BAH_COMPILER_VAR_231 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_231 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_231;
}
struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_232 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(v.markup);
;                            
            ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_232+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_232+currStrOff, v.markup, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_232;
char * ____BAH_COMPILER_VAR_233 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgsValues);
long int strLen_1 = strlen(v.content);
;                            
            ____BAH_COMPILER_VAR_233 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, v.content, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgsValues = ____BAH_COMPILER_VAR_233;
};
char * ____BAH_COMPILER_VAR_234 =null;char * ____BAH_COMPILER_VAR_235 =intToStr(lineNb);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(":");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_235);
long int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_234 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_234+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_234+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_234+currStrOff, ____BAH_COMPILER_VAR_235, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_234;
char * ____BAH_COMPILER_VAR_236 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnArgsValues);
long int strLen_1 = strlen(");\n    //\n    ");
long int strLen_2 = strlen("\\n\"");
long int strLen_3 = strlen(ASCII_RESET);
long int strLen_4 = strlen(line);
long int strLen_5 = strlen(ASCII_GREEN);
long int strLen_6 = strlen(") -> ");
long int strLen_7 = strlen(fnArgs);
long int strLen_8 = strlen("(");
long int strLen_9 = strlen(ASCII_RESET);
long int strLen_10 = strlen(fn->name);
long int strLen_11 = strlen(nameColor);
long int strLen_12 = strlen("\n    //Verbose Runtime\n        printf(\"[VO] calling: ");
;                            
            ____BAH_COMPILER_VAR_236 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, nameColor, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, fn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, ASCII_RESET, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, fnArgs, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, ") -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_236+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_236+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_236);
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
char * ____BAH_COMPILER_VAR_237 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pvo.content);
long int strLen_1 = strlen(nvo.content);
;                            
            ____BAH_COMPILER_VAR_237 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_237+currStrOff, pvo.content, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_237+currStrOff, nvo.content, strLen_1);
            currStrOff += strLen_1;
        
        }char * values = ____BAH_COMPILER_VAR_237;
char * ____BAH_COMPILER_VAR_238 =null;char * ____BAH_COMPILER_VAR_239 =intToStr(lineNb);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(":");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_239);
long int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_238 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_238+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_238+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_238+currStrOff, ____BAH_COMPILER_VAR_239, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_238;
char * ____BAH_COMPILER_VAR_240 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(values);
long int strLen_1 = strlen(");\n    //\n    ");
long int strLen_2 = strlen("\\n\"");
long int strLen_3 = strlen(ASCII_RESET);
long int strLen_4 = strlen(line);
long int strLen_5 = strlen(ASCII_GREEN);
long int strLen_6 = strlen(" -> ");
long int strLen_7 = strlen(nvo.markup);
long int strLen_8 = strlen(" AND ");
long int strLen_9 = strlen(pvo.markup);
long int strLen_10 = strlen("\n    //Verbose Runtime\n        printf(\"[VO]    oper: ");
;                            
            ____BAH_COMPILER_VAR_240 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, pvo.markup, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, " AND ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, nvo.markup, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, " -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_240+currStrOff, values, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_240+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_240);
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
struct fileStream ____BAH_COMPILER_VAR_241 = {};
____BAH_COMPILER_VAR_241.handle= null;
____BAH_COMPILER_VAR_241.name= null;
____BAH_COMPILER_VAR_241.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_241.open = fileStream__open;
____BAH_COMPILER_VAR_241.close = fileStream__close;
____BAH_COMPILER_VAR_241.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_241.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_241.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_241.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_241.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_241.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_241.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_241.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_241.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_241.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_241.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_241.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_241.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_241._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_241
char * ____BAH_COMPILER_VAR_242 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_242 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_242+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_242+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fs.open(&fs,____BAH_COMPILER_VAR_242,"r");
if ((fs.isValid(&fs)==0)) {
char * ____BAH_COMPILER_VAR_243 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache");
;                            
            ____BAH_COMPILER_VAR_243 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_243+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_243+currStrOff, "cache", strLen_1);
            currStrOff += strLen_1;
        
        }mkdir(____BAH_COMPILER_VAR_243,S_IRWXU);
char * ____BAH_COMPILER_VAR_244 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_244 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_244+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_244+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fs.createFile(&fs,____BAH_COMPILER_VAR_244);
return;
}
char * ____BAH_COMPILER_VAR_245 =fs.readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_245);
fs.close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_246 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_247 = 0;
char ** ____BAH_COMPILER_VAR_249 = (char **)((char*)(____BAH_COMPILER_VAR_247) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_250 = __reflect(____BAH_COMPILER_VAR_249, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_251 = (long int*)((char*)(____BAH_COMPILER_VAR_247) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_252 = __reflect(____BAH_COMPILER_VAR_251, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_253 = (char **)((char*)(____BAH_COMPILER_VAR_247) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_254 = __reflect(____BAH_COMPILER_VAR_253, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_255 = (long int*)((char*)(____BAH_COMPILER_VAR_247) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_256 = __reflect(____BAH_COMPILER_VAR_255, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_257 = (long int*)((char*)(____BAH_COMPILER_VAR_247) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_258 = __reflect(____BAH_COMPILER_VAR_257, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_259 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_247) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_260 = 0;
struct reflectElement ____BAH_COMPILER_VAR_261 = __reflect(____BAH_COMPILER_VAR_260, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_262 = ____BAH_COMPILER_VAR_261;
        struct reflectElement ____BAH_COMPILER_VAR_263 = __reflect(____BAH_COMPILER_VAR_259, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_262, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_248 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_248->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_248->length = 6;
        ____BAH_COMPILER_VAR_248->data = memoryAlloc(____BAH_COMPILER_VAR_248->length * ____BAH_COMPILER_VAR_248->elemSize);
        ____BAH_COMPILER_VAR_248->data[0] = ____BAH_COMPILER_VAR_250;
____BAH_COMPILER_VAR_248->data[1] = ____BAH_COMPILER_VAR_252;
____BAH_COMPILER_VAR_248->data[2] = ____BAH_COMPILER_VAR_254;
____BAH_COMPILER_VAR_248->data[3] = ____BAH_COMPILER_VAR_256;
____BAH_COMPILER_VAR_248->data[4] = ____BAH_COMPILER_VAR_258;
____BAH_COMPILER_VAR_248->data[5] = ____BAH_COMPILER_VAR_263;
struct reflectElement ____BAH_COMPILER_VAR_264 = __reflect(____BAH_COMPILER_VAR_247, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_248, 0);

        struct reflectElement ____BAH_COMPILER_VAR_265 = ____BAH_COMPILER_VAR_264;
        struct reflectElement ____BAH_COMPILER_VAR_266 = __reflect(____BAH_COMPILER_VAR_246, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_265, 0, 0, 0);
j->scan(j,____BAH_COMPILER_VAR_266);
if ((cache!=null)) {
}

#undef fs
};
struct cacheFile* getCacheFile(char * s){
if ((cache==null)) {
return null;
}
long int i = 0;
for (; (i<len(cache)); i++) {
struct cacheFile* c = cache->data[i];
if ((strcmp(c->file, s) == 0)&&(c->mem==RCPlevel)) {
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
struct cacheFile* ____BAH_COMPILER_VAR_267 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_267->file= null;
____BAH_COMPILER_VAR_267->ver= null;
____BAH_COMPILER_VAR_267->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_267->files->length = 0;
            ____BAH_COMPILER_VAR_267->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_267;
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
struct fileStream ____BAH_COMPILER_VAR_268 = {};
____BAH_COMPILER_VAR_268.handle= null;
____BAH_COMPILER_VAR_268.name= null;
____BAH_COMPILER_VAR_268.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_268.open = fileStream__open;
____BAH_COMPILER_VAR_268.close = fileStream__close;
____BAH_COMPILER_VAR_268.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_268.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_268.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_268.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_268.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_268.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_268.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_268.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_268.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_268.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_268.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_268.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_268.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_268._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_268
char * ____BAH_COMPILER_VAR_269 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_269 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_269+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_269+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fs.open(&fs,____BAH_COMPILER_VAR_269,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_270 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_271 = 0;
char ** ____BAH_COMPILER_VAR_273 = (char **)((char*)(____BAH_COMPILER_VAR_271) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_274 = __reflect(____BAH_COMPILER_VAR_273, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_275 = (long int*)((char*)(____BAH_COMPILER_VAR_271) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_276 = __reflect(____BAH_COMPILER_VAR_275, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_277 = (char **)((char*)(____BAH_COMPILER_VAR_271) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_278 = __reflect(____BAH_COMPILER_VAR_277, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_279 = (long int*)((char*)(____BAH_COMPILER_VAR_271) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_280 = __reflect(____BAH_COMPILER_VAR_279, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_281 = (long int*)((char*)(____BAH_COMPILER_VAR_271) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_282 = __reflect(____BAH_COMPILER_VAR_281, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
array(char *)** ____BAH_COMPILER_VAR_283 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_271) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_284 = 0;
struct reflectElement ____BAH_COMPILER_VAR_285 = __reflect(____BAH_COMPILER_VAR_284, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_286 = ____BAH_COMPILER_VAR_285;
        struct reflectElement ____BAH_COMPILER_VAR_287 = __reflect(____BAH_COMPILER_VAR_283, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_286, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_272 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_272->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_272->length = 6;
        ____BAH_COMPILER_VAR_272->data = memoryAlloc(____BAH_COMPILER_VAR_272->length * ____BAH_COMPILER_VAR_272->elemSize);
        ____BAH_COMPILER_VAR_272->data[0] = ____BAH_COMPILER_VAR_274;
____BAH_COMPILER_VAR_272->data[1] = ____BAH_COMPILER_VAR_276;
____BAH_COMPILER_VAR_272->data[2] = ____BAH_COMPILER_VAR_278;
____BAH_COMPILER_VAR_272->data[3] = ____BAH_COMPILER_VAR_280;
____BAH_COMPILER_VAR_272->data[4] = ____BAH_COMPILER_VAR_282;
____BAH_COMPILER_VAR_272->data[5] = ____BAH_COMPILER_VAR_287;
struct reflectElement ____BAH_COMPILER_VAR_288 = __reflect(____BAH_COMPILER_VAR_271, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_272, 0);

        struct reflectElement ____BAH_COMPILER_VAR_289 = ____BAH_COMPILER_VAR_288;
        struct reflectElement ____BAH_COMPILER_VAR_290 = __reflect(____BAH_COMPILER_VAR_270, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_289, 0, 0, 0);
char * ____BAH_COMPILER_VAR_291 =toJson(____BAH_COMPILER_VAR_290);fs.writeFile(&fs,____BAH_COMPILER_VAR_291);
fs.close(&fs);

#undef fs
};
char isValidCacheFile(struct cacheFile* cf){
if ((cf==null)||(cf->last!=getLastModified(cf->file))) {
return false;
}
char * ____BAH_COMPILER_VAR_292 =null;char * ____BAH_COMPILER_VAR_293 =intToStr(cf->mem);char * ____BAH_COMPILER_VAR_294 =pathToVarName(cf->file);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_293);
long int strLen_1 = strlen(".o.o");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_294);
long int strLen_3 = strlen("cache/");
long int strLen_4 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_292 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_292+currStrOff, BAH_DIR, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_292+currStrOff, "cache/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_292+currStrOff, ____BAH_COMPILER_VAR_294, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_292+currStrOff, ____BAH_COMPILER_VAR_293, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_292+currStrOff, ".o.o", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_295 =____BAH_COMPILER_VAR_292;if ((fileExists(____BAH_COMPILER_VAR_295)==0)) {
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
struct Tok t = line->data[i];
char * ____BAH_COMPILER_VAR_296 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen("'");
long int strLen_2 = strlen(" '");
long int strLen_3 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_296 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_296+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_296+currStrOff, " '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_296+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_296+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_296;
i++;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_297 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_297->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_297->vars->length = 0;
            ____BAH_COMPILER_VAR_297->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_297->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_297->structs->length = 0;
            ____BAH_COMPILER_VAR_297->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_297->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_297->types->length = 0;
            ____BAH_COMPILER_VAR_297->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_297->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_297->fns->length = 0;
            ____BAH_COMPILER_VAR_297->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_297->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_297->defined->length = 0;
            ____BAH_COMPILER_VAR_297->defined->elemSize = sizeof(char *);
            struct Elems* nElems = ____BAH_COMPILER_VAR_297;
long int j = 0;
for (; (j<len(elems->vars)); j++) {
struct variable* v = elems->vars->data[j];
struct variable* ____BAH_COMPILER_VAR_298 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_298->name = "";
____BAH_COMPILER_VAR_298->type = "";
____BAH_COMPILER_VAR_298->isConst = false;
____BAH_COMPILER_VAR_298->constVal = "";
____BAH_COMPILER_VAR_298->isArray = false;
____BAH_COMPILER_VAR_298->from = "";
____BAH_COMPILER_VAR_298->outterScope = false;
____BAH_COMPILER_VAR_298->isGlobal = false;
struct variable* nv = ____BAH_COMPILER_VAR_298;
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
else if ((strcmp(ft.cont, "continue") == 0)||(strcmp(ft.cont, "break") == 0)) {
return LINE_TYPE_FOR_OPERATOR;
}
else {
return LINE_TYPE_PRE_KEYWORD;
}
}
else if ((ft.type==TOKEN_TYPE_VAR)) {
if ((len(line)>1)) {
struct Tok st = line->data[1];
if ((st.type==TOKEN_TYPE_ENCL)&&(strcmp(st.cont, "(") == 0)) {
struct Tok lt = line->data[len(line)-1];
if ((lt.type==TOKEN_TYPE_ENCL)&&(strcmp(lt.cont, "}") == 0)) {
return LINE_TYPE_FN_DECL;
}
return LINE_TYPE_FN_CALL;
}
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
struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_CAST)) {
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
for (; (i<len(line)); i++) {
struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_CAST)) {
if ((i+1<len(line))) {
struct Tok nnnt = line->data[i+1];
struct string tc = string(t.cont);
tc.trimLeft(&tc,1);
tc.trimRight(&tc,1);
nnnt.bahType = tc.str(&tc);
char * ____BAH_COMPILER_VAR_299 =tc.str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_299,elems);
char * cCastStr = cCast.str(&cCast);
char * ____BAH_COMPILER_VAR_300 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(")");
long int strLen_1 = strlen(nnnt.cont);
long int strLen_2 = strlen(cCastStr);
long int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_300 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_300+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_300+currStrOff, cCastStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_300+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_300+currStrOff, nnnt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }nnnt.cont = ____BAH_COMPILER_VAR_300;

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
i = i+2;
continue;
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
char * ____BAH_COMPILER_VAR_301 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_301);
long int i = len(p)-1;
while ((i>=0)) {
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
char needDisableRCP = false;
if ((strcmp(ccstr, "BAH_MEM_COLLECTOR") == 0)) {
if ((RCPenabled==true)) {
needDisableRCP = true;
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

        char ____BAH_COMPILER_VAR_302 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                ____BAH_COMPILER_VAR_302=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_302) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_303 = {};
____BAH_COMPILER_VAR_303.handle = -1;
____BAH_COMPILER_VAR_303.p= null;
____BAH_COMPILER_VAR_303.open = fileMap__open;
____BAH_COMPILER_VAR_303.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_303.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_303
char * ____BAH_COMPILER_VAR_304 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_304 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_304+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_304+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }char * fileName = ____BAH_COMPILER_VAR_304;
char isBahDir = true;
char * f = fm.open(&fm,fileName);
if ((fm.isValid(&fm)==0)) {
char * ____BAH_COMPILER_VAR_305 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_305 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_305+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_305+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }fileName = absPath(____BAH_COMPILER_VAR_305);
f = fm.open(&fm,fileName);
isBahDir = false;
if ((fm.isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_306 =null;char * ____BAH_COMPILER_VAR_307 =getDirFromFile(ccstr);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_307);
;                            
            ____BAH_COMPILER_VAR_306 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_306+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_306+currStrOff, ____BAH_COMPILER_VAR_307, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_306;
}
else {
char * ____BAH_COMPILER_VAR_308 =null;char * ____BAH_COMPILER_VAR_309 =getDirFromFile(ccstr);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_309);
;                            
            ____BAH_COMPILER_VAR_308 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_308+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_308+currStrOff, ____BAH_COMPILER_VAR_309, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_308;
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
char * ____BAH_COMPILER_VAR_310 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ccstr);
long int strLen_1 = strlen("' not recognized.");
long int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_310 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_310+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_310+currStrOff, ccstr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_310+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_310,"/home/alois/Documents/bah-bah/src/parser.bah:244");
}
char oshd = shouldOnlyDecl;
if ((isObject==true)) {
shouldOnlyDecl = true;
}
else if ((isSubObject==true)) {
shouldOnlyDecl = false;
}
if ((needDisableRCP==true)) {
RCPenabled = false;
}
parseLines(tokens,elems);
if ((needDisableRCP==true)) {
RCPenabled = true;
}
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
char * ____BAH_COMPILER_VAR_311 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn);
long int strLen_1 = strlen("... ");
long int strLen_2 = strlen("compilling: ");
;                            
            ____BAH_COMPILER_VAR_311 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_311+currStrOff, "compilling: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_311+currStrOff, fn, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_311+currStrOff, "... ", strLen_1);
            currStrOff += strLen_1;
        
        }print(____BAH_COMPILER_VAR_311);
char * ____BAH_COMPILER_VAR_312 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" -o ");
long int strLen_1 = strlen(oName);
long int strLen_2 = strlen(verboseCC);
long int strLen_3 = strlen(" -object ");
long int strLen_4 = strlen(rcp);
long int strLen_5 = strlen(" ");
long int strLen_6 = strlen(fn);
long int strLen_7 = strlen(" ");
long int strLen_8 = strlen(execName);
;                            
            ____BAH_COMPILER_VAR_312 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_312+currStrOff, execName, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_312+currStrOff, " ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_312+currStrOff, fn, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_312+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_312+currStrOff, rcp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_312+currStrOff, " -object ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_312+currStrOff, verboseCC, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_312+currStrOff, " -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_312+currStrOff, oName, strLen_1);
            currStrOff += strLen_1;
        
        }struct command cmd = command(____BAH_COMPILER_VAR_312);
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

        char ____BAH_COMPILER_VAR_313 = true;
        done->sendAny(done, &____BAH_COMPILER_VAR_313, sizeof(____BAH_COMPILER_VAR_313));
        };
void parseImport(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
compilerState.hasImports = true;
if ((len(l)!=2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}
struct Tok strt = l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as file name (#import \"file\")");
}
struct string fileName = string(strt.cont);
fileName.trimLeft(&fileName,1);
fileName.trimRight(&fileName,1);

        char ____BAH_COMPILER_VAR_314 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], fileName.str(&fileName)) == 0) {
                ____BAH_COMPILER_VAR_314=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_314) {
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
char * ____BAH_COMPILER_VAR_315 =fileName.str(&fileName);char * fn = absPath(____BAH_COMPILER_VAR_315);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_316 =null;char * ____BAH_COMPILER_VAR_317 =fileName.str(&fileName);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_317);
;                            
            ____BAH_COMPILER_VAR_316 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_316+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_316+currStrOff, ____BAH_COMPILER_VAR_317, strLen_1);
            currStrOff += strLen_1;
        
        }fn = absPath(____BAH_COMPILER_VAR_316);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_318 = {};
____BAH_COMPILER_VAR_318.handle= null;
____BAH_COMPILER_VAR_318.name= null;
____BAH_COMPILER_VAR_318.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_318.open = fileStream__open;
____BAH_COMPILER_VAR_318.close = fileStream__close;
____BAH_COMPILER_VAR_318.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_318.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_318.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_318.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_318.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_318.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_318.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_318.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_318.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_318.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_318.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_318.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_318.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_318._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_318
fs.open(&fs,fn,"r");
char * f = fs.readContent(&fs);
fs.close(&fs);
array(struct Tok)* tokens = lexer(f);
char osod = shouldOnlyDecl;
shouldOnlyDecl = true;
char oiso = isSubObject;
isSubObject = true;
char * ____BAH_COMPILER_VAR_319 =null;char * ____BAH_COMPILER_VAR_320 =intToStr(RCPlevel);char * ____BAH_COMPILER_VAR_321 =pathToVarName(fn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_320);
long int strLen_1 = strlen(".o");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_321);
long int strLen_3 = strlen("cache/");
long int strLen_4 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_319 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_319+currStrOff, BAH_DIR, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_319+currStrOff, "cache/", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_319+currStrOff, ____BAH_COMPILER_VAR_321, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_319+currStrOff, ____BAH_COMPILER_VAR_320, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_319+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }char * oName = ____BAH_COMPILER_VAR_319;
char * ____BAH_COMPILER_VAR_322 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(oName);
long int strLen_1 = strlen(".o");
long int strLen_2 = strlen("w ");
;                            
            ____BAH_COMPILER_VAR_322 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_322+currStrOff, "w ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_322+currStrOff, oName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_322+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }
{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_322;
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_322;
}
};
struct channel * done = channel();
parallelObjCompile(fn,oName,done);
parseLines(tokens,elems);
char ok = *(char*)done->receive(done);
char * ____BAH_COMPILER_VAR_323 =null;char * ____BAH_COMPILER_VAR_324 =pathToVarName(fn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_324);
long int strLen_1 = strlen("();\n");
long int strLen_2 = strlen("__BAH_init");
;                            
            ____BAH_COMPILER_VAR_323 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_323+currStrOff, "__BAH_init", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_323+currStrOff, ____BAH_COMPILER_VAR_324, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_323+currStrOff, "();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_325 =____BAH_COMPILER_VAR_323;INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_325));
writeCache();
shouldOnlyDecl = osod;
isSubObject = oiso;
compilerState.currentFile = of;
compilerState.currentDir = od;

#undef fs
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}
struct Tok strt = l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
char * sc = strt.cont;
strTrimLeft(&sc,1);
strTrimRight(&sc,1);
if (strHasPrefix(sc,"<")||strHasSuffix(sc,".h")||strHasSuffix(sc,".c")) {
char * ____BAH_COMPILER_VAR_326 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sc);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_326 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_326+currStrOff, sc, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_326+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_326));

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
i++;
continue;
}
i++;
struct Tok ____BAH_COMPILER_VAR_327 = {};
____BAH_COMPILER_VAR_327.cont = "";
____BAH_COMPILER_VAR_327.ogCont = "";
____BAH_COMPILER_VAR_327.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_327.pos = 0;
____BAH_COMPILER_VAR_327.line = 1;
____BAH_COMPILER_VAR_327.begLine = 1;
____BAH_COMPILER_VAR_327.bahType = "";
____BAH_COMPILER_VAR_327.isValue = false;
____BAH_COMPILER_VAR_327.isFunc = false;
____BAH_COMPILER_VAR_327.isOper = false;
____BAH_COMPILER_VAR_327.isEqual = false;
____BAH_COMPILER_VAR_327.pass = false;
____BAH_COMPILER_VAR_327.bahRef= null;
____BAH_COMPILER_VAR_327.cont = "";
#define nt ____BAH_COMPILER_VAR_327
if ((i<len(line))) {
nt = line->data[i];
}
if ((i==len(line))||(strcmp(nt.cont, "{") != 0)) {
if ((i-2>=0)) {
struct Tok newTk = line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
struct cStruct* s = searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Cannot initialize new unknown struct {TOKEN}.");
}
t.cont = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_328 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_328->name = "";
____BAH_COMPILER_VAR_328->type = "";
____BAH_COMPILER_VAR_328->isConst = false;
____BAH_COMPILER_VAR_328->constVal = "";
____BAH_COMPILER_VAR_328->isArray = false;
____BAH_COMPILER_VAR_328->from = "";
____BAH_COMPILER_VAR_328->outterScope = false;
____BAH_COMPILER_VAR_328->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_328;
tmpV->name = t.cont;
char * ____BAH_COMPILER_VAR_329 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_329 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_329+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_329+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_329;
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
char * ____BAH_COMPILER_VAR_330 =null;char * ____BAH_COMPILER_VAR_331 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_332 =structType.str(&structType);char * ____BAH_COMPILER_VAR_333 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("));\n");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_331);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_332);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(" ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_333);
;                            
            ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, ____BAH_COMPILER_VAR_333, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, ____BAH_COMPILER_VAR_332, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_330+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_330+currStrOff, ____BAH_COMPILER_VAR_331, strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_330));

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
nt = line->data[i];
if ((strcmp(nt.cont, "{") == 0)) {
char isHeap = false;
char * sep = ".";
if ((i-2>=0)) {
struct Tok newTk = line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
isHeap = true;
sep = "->";
}
}
i++;
struct cStruct* s = searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int nbBraces = 1;
for (; (i<len(line)); i++) {
t = line->data[i];
if ((strcmp(t.cont, "{") == 0)) {
nbBraces++;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbBraces--;
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
struct variable* ____BAH_COMPILER_VAR_334 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_334->name = "";
____BAH_COMPILER_VAR_334->type = "";
____BAH_COMPILER_VAR_334->isConst = false;
____BAH_COMPILER_VAR_334->constVal = "";
____BAH_COMPILER_VAR_334->isArray = false;
____BAH_COMPILER_VAR_334->from = "";
____BAH_COMPILER_VAR_334->outterScope = false;
____BAH_COMPILER_VAR_334->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_334;
tmpV->name = rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_335 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_335 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_335+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_335+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_335;

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
char * ____BAH_COMPILER_VAR_336 =rst.str(&rst);struct string structType = string(____BAH_COMPILER_VAR_336);
structType.trimRight(&structType,1);
char * ____BAH_COMPILER_VAR_337 =null;char * ____BAH_COMPILER_VAR_338 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_339 =structType.str(&structType);char * ____BAH_COMPILER_VAR_340 =rst.str(&rst);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("));\n");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_338);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_339);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(rvn);
long int strLen_5 = strlen(" ");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_340);
;                            
            ____BAH_COMPILER_VAR_337 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, ____BAH_COMPILER_VAR_340, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, rvn, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_337+currStrOff, ____BAH_COMPILER_VAR_339, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_337+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_337+currStrOff, ____BAH_COMPILER_VAR_338, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_337);
}
else {
char * ____BAH_COMPILER_VAR_341 =null;char * ____BAH_COMPILER_VAR_342 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_343 =rst.str(&rst);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = {};\n");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_342);
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_343);
;                            
            ____BAH_COMPILER_VAR_341 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_341+currStrOff, ____BAH_COMPILER_VAR_343, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_341+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_341+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_341+currStrOff, " = {};\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_341+currStrOff, ____BAH_COMPILER_VAR_342, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_341);
}
long int j = 0;
long int k = 0;
while ((k<len(memory))) {
t = memory->data[k];
if ((k+2<len(memory))) {
struct Tok st = memory->data[k+1];
struct Tok vl = memory->data[k+2];
if ((strcmp(st.cont, ":") == 0)) {
if ((declType!=0)&&(declType!=1)) {
throwErr(&t,"Cannot declare member {TOKEN} by name in list declaration.");
}
declType = 1;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as struct member name.");
}
j = 0;
while ((j<len(s->members))) {
struct structMemb* m = s->members->data[j];
if ((strcmp(m->name, t.cont) != 0)) {
j = j+1;
continue;
}
char * vlt = getTypeFromToken(&vl,true,elems);
if ((compTypes(vlt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_344 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->type);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(vlt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_344 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_344+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_344+currStrOff, vlt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_344+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_344+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_344+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&vl,____BAH_COMPILER_VAR_344);
}
char * ____BAH_COMPILER_VAR_345 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(vl.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(sep);
long int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_345 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_345+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_345+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_345+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_345+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_345+currStrOff, vl.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_345+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_345));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_346 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("' has no member called {TOKEN}.");
long int strLen_2 = strlen("Struct '");
;                            
            ____BAH_COMPILER_VAR_346 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_346+currStrOff, "Struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_346+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_346+currStrOff, "' has no member called {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_346);
}
k = k+3;
continue;
}
}
if ((declType!=0)&&(declType!=2)) {
throwErr(&t,"Cannot declare member {TOKEN} without specifying its name.");
}
declType = 2;
if ((j>len(s->members))) {
throwErr(&t,"Too many members {TOKEN}.");
}
struct structMemb* m = s->members->data[j];
j++;
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_347 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->type);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_347 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_347+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_347+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_347);
}
char * ____BAH_COMPILER_VAR_348 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(sep);
long int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_348 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_348+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_348+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_348+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_348+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_348+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_348+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = r->add(r, rope(____BAH_COMPILER_VAR_348));
if ((k+1<len(memory))) {
k++;
struct Tok st = memory->data[k];
if ((strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Need ',' separator between two values, not {TOKEN}.");
}
}
k++;
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
i++;
continue;
}
else {
i--;
}
}

#undef nt
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
i++;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i = 0;
if ((guard==true)) {
for (; (i<len(line)); i++) {
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
for (; (i<len(line)); i++) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
i++;
if ((i<len(line))) {
t = line->data[i];
if ((strcmp(t.cont, "]") == 0)) {
i++;
long int depth = 1;
char * bracks = "[]";
for (; (i<len(line)-1); i++) {
t = line->data[i];
struct Tok nt = line->data[i+1];
if ((strcmp(t.cont, "[") == 0)&&(strcmp(nt.cont, "]") == 0)) {
depth++;
char * ____BAH_COMPILER_VAR_349 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen("[]");
;                            
            ____BAH_COMPILER_VAR_349 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_349+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_349+currStrOff, "[]", strLen_1);
            currStrOff += strLen_1;
        
        }bracks = ____BAH_COMPILER_VAR_349;
i++;
}
else {
break;
}
};
if ((i<len(line))) {
t = line->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem = t.cont;
char * ____BAH_COMPILER_VAR_350 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen(arrElem);
;                            
            ____BAH_COMPILER_VAR_350 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_350+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_350+currStrOff, arrElem, strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_350;
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
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i>0)) {
struct Tok pt = nl->data[len(nl)-1];
if ((pt.type==TOKEN_TYPE_VAR)) {
if ((i+1<len(l))) {
struct Tok nt = l->data[i+1];
if ((nt.isValue==false)&&(strcmp(nt.cont, "(") != 0)) {
char * ____BAH_COMPILER_VAR_351 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_351 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_351+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_351+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_351;

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
char * ____BAH_COMPILER_VAR_352 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_352 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_352+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_352+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_352;

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
struct Tok nt = l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_353 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_353 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_353+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_353+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_353;

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
char * ____BAH_COMPILER_VAR_354 =null;char * ____BAH_COMPILER_VAR_355 =svt.str(&svt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_355);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("sizeof(struct ");
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(e.cont);
long int strLen_5 = strlen("__serialize(&");
;                            
            ____BAH_COMPILER_VAR_354 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, "__serialize(&", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, e.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_354+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_354+currStrOff, ____BAH_COMPILER_VAR_355, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_354+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_354;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_356 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptrRect);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_356 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_356+currStrOff, ptrRect, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_356+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }ptrRect = ____BAH_COMPILER_VAR_356;
ptrLevel = ptrLevel-1;
};
char * ____BAH_COMPILER_VAR_357 =null;char * ____BAH_COMPILER_VAR_358 =svt.str(&svt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_358);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("sizeof(struct ");
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(e.cont);
long int strLen_5 = strlen(ptrRect);
long int strLen_6 = strlen("__serialize(");
;                            
            ____BAH_COMPILER_VAR_357 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, "__serialize(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, ptrRect, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, e.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_357+currStrOff, ____BAH_COMPILER_VAR_358, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_357+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_357;
long int i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_359 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->");
long int strLen_3 = strlen(e.cont);
long int strLen_4 = strlen("+strlen(");
long int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_359 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, "+strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, e.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_359+currStrOff, "->", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_359+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_359+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_359;
}
i = i+1;
};
}
char * ____BAH_COMPILER_VAR_360 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_360 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_360+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_360+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_360;
};
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,char parsedPointer,char * ogName,char * offset){
char * isArr = "0";
if ((t.type!=TOKEN_TYPE_VAR)||(t.type!=TOKEN_TYPE_FUNC)) {
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
char * ____BAH_COMPILER_VAR_361 =null;char * ____BAH_COMPILER_VAR_362 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(v);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_362);
;                            
            ____BAH_COMPILER_VAR_361 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, ____BAH_COMPILER_VAR_362, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_361+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_361+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_361));
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
struct Tok ____BAH_COMPILER_VAR_363 = {};
____BAH_COMPILER_VAR_363.cont = "";
____BAH_COMPILER_VAR_363.ogCont = "";
____BAH_COMPILER_VAR_363.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_363.pos = 0;
____BAH_COMPILER_VAR_363.line = 1;
____BAH_COMPILER_VAR_363.begLine = 1;
____BAH_COMPILER_VAR_363.bahType = "";
____BAH_COMPILER_VAR_363.isValue = false;
____BAH_COMPILER_VAR_363.isFunc = false;
____BAH_COMPILER_VAR_363.isOper = false;
____BAH_COMPILER_VAR_363.isEqual = false;
____BAH_COMPILER_VAR_363.pass = false;
____BAH_COMPILER_VAR_363.bahRef= null;
#define tmpT ____BAH_COMPILER_VAR_363
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_364 =aet.str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_364,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_365 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rt.cont);
long int strLen_1 = strlen(";\n        ");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(aev);
long int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_365 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_365+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_365+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_365+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_365+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_365+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_365));
char * ____BAH_COMPILER_VAR_366 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_366 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_366+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_366+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_366;

#undef tmpT
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
aet.trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_367 = {};
____BAH_COMPILER_VAR_367.cont = "";
____BAH_COMPILER_VAR_367.ogCont = "";
____BAH_COMPILER_VAR_367.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_367.pos = 0;
____BAH_COMPILER_VAR_367.line = 1;
____BAH_COMPILER_VAR_367.begLine = 1;
____BAH_COMPILER_VAR_367.bahType = "";
____BAH_COMPILER_VAR_367.isValue = false;
____BAH_COMPILER_VAR_367.isFunc = false;
____BAH_COMPILER_VAR_367.isOper = false;
____BAH_COMPILER_VAR_367.isEqual = false;
____BAH_COMPILER_VAR_367.pass = false;
____BAH_COMPILER_VAR_367.bahRef= null;
#define tmpT ____BAH_COMPILER_VAR_367
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_368 =aet.str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_368,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_369 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rt.cont);
long int strLen_1 = strlen(";\n        ");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(aev);
long int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_369 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_369+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_369+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_369+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_369));
char * ____BAH_COMPILER_VAR_370 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_370+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_370+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_370;

#undef tmpT
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_371 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_371->name = "";
____BAH_COMPILER_VAR_371->type = "";
____BAH_COMPILER_VAR_371->isConst = false;
____BAH_COMPILER_VAR_371->constVal = "";
____BAH_COMPILER_VAR_371->isArray = false;
____BAH_COMPILER_VAR_371->from = "";
____BAH_COMPILER_VAR_371->outterScope = false;
____BAH_COMPILER_VAR_371->isGlobal = false;
struct variable* slv = ____BAH_COMPILER_VAR_371;
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
for (; (i<len(ts->members)); i++) {
struct structMemb* m = ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_372 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_372->name = "";
____BAH_COMPILER_VAR_372->type = "";
____BAH_COMPILER_VAR_372->isConst = false;
____BAH_COMPILER_VAR_372->constVal = "";
____BAH_COMPILER_VAR_372->isArray = false;
____BAH_COMPILER_VAR_372->from = "";
____BAH_COMPILER_VAR_372->outterScope = false;
____BAH_COMPILER_VAR_372->isGlobal = false;
____BAH_COMPILER_VAR_372->def = "";
____BAH_COMPILER_VAR_372->isFn = false;
struct structMemb* nm = ____BAH_COMPILER_VAR_372;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_373 = {};
____BAH_COMPILER_VAR_373.cont = "";
____BAH_COMPILER_VAR_373.ogCont = "";
____BAH_COMPILER_VAR_373.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_373.pos = 0;
____BAH_COMPILER_VAR_373.line = 1;
____BAH_COMPILER_VAR_373.begLine = 1;
____BAH_COMPILER_VAR_373.bahType = "";
____BAH_COMPILER_VAR_373.isValue = false;
____BAH_COMPILER_VAR_373.isFunc = false;
____BAH_COMPILER_VAR_373.isOper = false;
____BAH_COMPILER_VAR_373.isEqual = false;
____BAH_COMPILER_VAR_373.pass = false;
____BAH_COMPILER_VAR_373.bahRef= null;
#define tmpT ____BAH_COMPILER_VAR_373
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
offsetTT.replace(&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_374 =null;char * ____BAH_COMPILER_VAR_375 =offsetTT.str(&offsetTT);char * ____BAH_COMPILER_VAR_376 =mCtype.str(&mCtype);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_375);
long int strLen_4 = strlen(") + offsetof(struct ");
long int strLen_5 = strlen(t.cont);
long int strLen_6 = strlen("*)((char*)(");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_376);
long int strLen_8 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_374 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, ____BAH_COMPILER_VAR_376, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, "*)((char*)(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, t.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, ") + offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, ____BAH_COMPILER_VAR_375, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_374+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_374+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_374+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }tmpT.cont = ____BAH_COMPILER_VAR_374;
char * ____BAH_COMPILER_VAR_377 =null;char * ____BAH_COMPILER_VAR_378 =offsetTT.str(&offsetTT);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m->name);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_378);
long int strLen_4 = strlen("offsetof(struct ");
;                            
            ____BAH_COMPILER_VAR_377 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, "offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, ____BAH_COMPILER_VAR_378, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_377+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_377+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_377);
char * ____BAH_COMPILER_VAR_379 =null;char * ____BAH_COMPILER_VAR_380 =intToStr(i);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rt.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("] = ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_380);
long int strLen_4 = strlen("->data[");
long int strLen_5 = strlen(structLayout);
;                            
            ____BAH_COMPILER_VAR_379 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, ____BAH_COMPILER_VAR_380, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_379+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_379+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_379+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }dataLayout = dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_379));

#undef tmpT
};
char * ____BAH_COMPILER_VAR_381 =null;char * ____BAH_COMPILER_VAR_382 =intToStr(len(ts->members));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(structLayout);
long int strLen_1 = strlen("->elemSize);\n        ");
long int strLen_2 = strlen("->length * ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen("->data = memoryAlloc(");
long int strLen_5 = strlen(structLayout);
long int strLen_6 = strlen(";\n        ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_382);
long int strLen_8 = strlen("->length = ");
long int strLen_9 = strlen(structLayout);
long int strLen_10 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_11 = strlen(structLayout);
long int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_13 = strlen(structLayout);
long int strLen_14 = strlen("\n        array(struct reflectElement) * ");
;                            
            ____BAH_COMPILER_VAR_381 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, "\n        array(struct reflectElement) * ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, structLayout, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, structLayout, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, structLayout, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, "->length = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, ____BAH_COMPILER_VAR_382, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, ";\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, "->data = memoryAlloc(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, "->length * ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_381+currStrOff, structLayout, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_381+currStrOff, "->elemSize);\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_381)->add(rope(____BAH_COMPILER_VAR_381), dataLayout));
}
char * amp = "";
if ((strCount(tt,"*")==0)&&(strcmp(tt, "cpstring") != 0)&&(strcmp(tt, "ptr") != 0)&&(parsedPointer==false)) {
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
struct variable* ____BAH_COMPILER_VAR_383 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_383->name = "";
____BAH_COMPILER_VAR_383->type = "";
____BAH_COMPILER_VAR_383->isConst = false;
____BAH_COMPILER_VAR_383->constVal = "";
____BAH_COMPILER_VAR_383->isArray = false;
____BAH_COMPILER_VAR_383->from = "";
____BAH_COMPILER_VAR_383->outterScope = false;
____BAH_COMPILER_VAR_383->isGlobal = false;
struct variable* rv = ____BAH_COMPILER_VAR_383;
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
char * ____BAH_COMPILER_VAR_384 =null;char * ____BAH_COMPILER_VAR_385 =name.str(&name);char * ____BAH_COMPILER_VAR_386 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(offset);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(isStruct);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(arrElem);
long int strLen_8 = strlen(", ");
long int strLen_9 = strlen(isArr);
long int strLen_10 = strlen("\", ");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_385);
long int strLen_12 = strlen("\", \"");
long int strLen_13 = strlen(tt);
long int strLen_14 = strlen("), \"");
long int strLen_15 = strlen(____BAH_COMPILER_VAR_386);
long int strLen_16 = strlen(", sizeof(");
long int strLen_17 = strlen(t.cont);
long int strLen_18 = strlen(amp);
long int strLen_19 = strlen(" = __reflect(");
long int strLen_20 = strlen(rv->name);
long int strLen_21 = strlen("struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_384 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20+strLen_21);
            
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, "struct reflectElement ", strLen_21);
                    currStrOff += strLen_21;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, rv->name, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, " = __reflect(", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, amp, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, t.cont, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, ", sizeof(", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, ____BAH_COMPILER_VAR_386, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, "), \"", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, tt, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, "\", \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, ____BAH_COMPILER_VAR_385, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, "\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, isArr, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, ", ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, arrElem, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, isStruct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_384+currStrOff, offset, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_384+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_384));
t.cont = rv->name;
return t;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength = 0;
struct string arrType = getCType(v->type,elems);
arrType.trimRight(&arrType,1);
char * ____BAH_COMPILER_VAR_387 =null;char * ____BAH_COMPILER_VAR_388 =arrType.str(&arrType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_388);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen("memoryAlloc(sizeof(");
;                            
            ____BAH_COMPILER_VAR_387 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, "memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_387+currStrOff, ____BAH_COMPILER_VAR_388, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_387+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_387;
arrType.trimLeft(&arrType,6);
arrType.trimRight(&arrType,1);
char * elemTypeStr = arrType.str(&arrType);
if ((i+1!=max)) {
i++;
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
struct Tok t = memory->data[i];
if ((strcmp(t.cont, "{") == 0)) {
long int j = i-1;
long int nbBraces = 0;
for (; (i<len(memory)); i++) {
struct Tok tmpT = memory->data[i];
if ((strcmp(tmpT.cont, "{") == 0)) {
nbBraces++;
}
else if ((strcmp(tmpT.cont, "}") == 0)) {
nbBraces--;
}
if ((nbBraces==0)) {
break;
}
};
struct variable* ____BAH_COMPILER_VAR_389 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_389->name = "";
____BAH_COMPILER_VAR_389->type = "";
____BAH_COMPILER_VAR_389->isConst = false;
____BAH_COMPILER_VAR_389->constVal = "";
____BAH_COMPILER_VAR_389->isArray = false;
____BAH_COMPILER_VAR_389->from = "";
____BAH_COMPILER_VAR_389->outterScope = false;
____BAH_COMPILER_VAR_389->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_389;
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
char * ____BAH_COMPILER_VAR_390 =elemType.str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_390,elems);
char * ____BAH_COMPILER_VAR_391 =null;char * ____BAH_COMPILER_VAR_392 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(NEXT_LINE);
long int strLen_1 = strlen("\n                ");
long int strLen_2 = strlen(";\n                ");
long int strLen_3 = strlen(innerCode);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(tmpV->name);
long int strLen_6 = strlen(") * ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_392);
long int strLen_8 = strlen("\n                array(");
;                            
            ____BAH_COMPILER_VAR_391 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, "\n                array(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, ____BAH_COMPILER_VAR_392, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, ") * ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, innerCode, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_391+currStrOff, ";\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_391+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_391+currStrOff, "\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_391));
NEXT_LINE = oldNL;
struct Tok ____BAH_COMPILER_VAR_393 = {};
____BAH_COMPILER_VAR_393.cont = "";
____BAH_COMPILER_VAR_393.ogCont = "";
____BAH_COMPILER_VAR_393.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_393.pos = 0;
____BAH_COMPILER_VAR_393.line = 1;
____BAH_COMPILER_VAR_393.begLine = 1;
____BAH_COMPILER_VAR_393.bahType = "";
____BAH_COMPILER_VAR_393.isValue = false;
____BAH_COMPILER_VAR_393.isFunc = false;
____BAH_COMPILER_VAR_393.isOper = false;
____BAH_COMPILER_VAR_393.isEqual = false;
____BAH_COMPILER_VAR_393.pass = false;
____BAH_COMPILER_VAR_393.bahRef= null;
____BAH_COMPILER_VAR_393.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_393.cont = tmpV->name;
____BAH_COMPILER_VAR_393.bahType = elemType.str(&elemType);
____BAH_COMPILER_VAR_393.isValue = true;
t = ____BAH_COMPILER_VAR_393;
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_394 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(") as ");
long int strLen_1 = strlen(elemBahTypeStr);
long int strLen_2 = strlen(tt);
long int strLen_3 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_394 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, "Cannot use {TOKEN} (", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, tt, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_394+currStrOff, ") as ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_394+currStrOff, elemBahTypeStr, strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_394);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char * ____BAH_COMPILER_VAR_395 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("] = ");
long int strLen_3 = strlen(strArrayLength);
long int strLen_4 = strlen("->data[");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(NEXT_LINE);
;                            
            ____BAH_COMPILER_VAR_395 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, NEXT_LINE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_395+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_395+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_395+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_395;
i++;
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
char * ____BAH_COMPILER_VAR_396 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(");");
long int strLen_1 = strlen(NEXT_LINE);
long int strLen_2 = strlen(allocLengthStr);
long int strLen_3 = strlen(") * ");
long int strLen_4 = strlen(elemTypeStr);
long int strLen_5 = strlen("->data = memoryAlloc(sizeof(");
long int strLen_6 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_396 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, "->data = memoryAlloc(sizeof(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, elemTypeStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, ") * ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_396+currStrOff, allocLengthStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_396+currStrOff, ");", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_396+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_396;
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
char * ____BAH_COMPILER_VAR_397 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(");\n");
long int strLen_1 = strlen(NEXT_LINE);
long int strLen_2 = strlen(elemTypeStr);
long int strLen_3 = strlen("->elemSize = sizeof(");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen(";\n");
long int strLen_6 = strlen(strArrayLength);
long int strLen_7 = strlen("->length = ");
long int strLen_8 = strlen(v->name);
long int strLen_9 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_397 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, "\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, "->length = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, strArrayLength, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, "->elemSize = sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, elemTypeStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_397+currStrOff, ");\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_397+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_397;
return code;
};
array(char *)* equalsTokens;
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct Tok ft = l->data[0];
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}
ft = l->data[0];
char parsed = true;
char * ____BAH_COMPILER_VAR_398 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_398 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_398+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_398+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_398));
return;
}
l = parseStructType(l,(lineType)-1,elems);
char isEqual = false;
char toVar = false;
char isPointedVar = false;
char isStruct = false;
char * currentType = "";
char needsDefine = false;
ft = l->data[0];
struct variable* v = searchVar(ft.cont,elems);
char exists = true;
char * ogName= null;
if ((v==null)) {
exists = false;
struct variable* ____BAH_COMPILER_VAR_399 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_399->name = "";
____BAH_COMPILER_VAR_399->type = "";
____BAH_COMPILER_VAR_399->isConst = false;
____BAH_COMPILER_VAR_399->constVal = "";
____BAH_COMPILER_VAR_399->isArray = false;
____BAH_COMPILER_VAR_399->from = "";
____BAH_COMPILER_VAR_399->outterScope = false;
____BAH_COMPILER_VAR_399->isGlobal = false;
v = ____BAH_COMPILER_VAR_399;
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
if ((exists==true)&&isGlobal()) {
throwErr(&ft,"Cannot redeclare global variable {TOKEN}.");
}
if ((len(l)==1)) {
struct Tok t = l->data[0];
struct string c = string(t.cont);
c.trimRight(&c,2);
char * ____BAH_COMPILER_VAR_400 =c.str(&c);v = searchVar(____BAH_COMPILER_VAR_400,elems);
if ((v==null)) {
throwErr(&t,"Cannot increase/decrease not declared variable {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_401 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_401 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_401+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_401+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_401));
return;
}
if ((len(l)<2)) {
throwErr(&ft,"Missing '=' after {TOKEN}.");
}
struct Tok operT = l->data[1];

        char ____BAH_COMPILER_VAR_402 = 0;
        for(int i=equalsTokens->length-1; i!=-1;i--) {
            if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                ____BAH_COMPILER_VAR_402=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_402&&(strcmp(operT.cont, "=") != 0)) {
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
array(struct Tok)* tmpL = memoryAlloc(sizeof(array(struct Tok)));

tmpL->length = 3;
tmpL->elemSize = sizeof(struct Tok);
tmpL->data = memoryAlloc(sizeof(struct Tok) * 50);tmpL->data[0] = ft;
tmpL->data[1] = operTok;
tmpL->data[2] = l->data[2];
tmpL = prePross(tmpL,LINE_TYPE_VAR,elems);
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
for (; (j<len(tmpL)); j++) {

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
char * ____BAH_COMPILER_VAR_403 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentType);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_403 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_403+currStrOff, currentType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_403+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }currentType = ____BAH_COMPILER_VAR_403;
}
else {
if ((t.isEqual==true)&&(exists==false)&&(isGlobal()==false)) {
needsDefine = true;
}
if ((strcmp(t.cont, "chan") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
i++;
struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_404 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("chan:");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_404 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_404+currStrOff, "chan:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_404+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_404;
code = "channel()";
if ((i+1!=len(l))) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after channel declaration.");
}
break;
}
else if ((strcmp(t.cont, "map") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (map <type>).");
}
i++;
struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_405 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("map:");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_405 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_405+currStrOff, "map:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_405+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_405;
code = "mapWrapper()";
if ((i+1!=len(l))) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after map declaration.");
}
break;
}
else if ((strcmp(t.cont, "buffer") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a length (buffer <length>).");
}
i++;
struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_INT)) {
throwErr(&nt,"Expected buffer length, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_406 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("buffer:");
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_406 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_406+currStrOff, "buffer:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_406+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_406;
struct variable* ____BAH_COMPILER_VAR_407 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_407->name = "";
____BAH_COMPILER_VAR_407->type = "";
____BAH_COMPILER_VAR_407->isConst = false;
____BAH_COMPILER_VAR_407->constVal = "";
____BAH_COMPILER_VAR_407->isArray = false;
____BAH_COMPILER_VAR_407->from = "";
____BAH_COMPILER_VAR_407->outterScope = false;
____BAH_COMPILER_VAR_407->isGlobal = false;
struct variable* av = ____BAH_COMPILER_VAR_407;
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
char * ____BAH_COMPILER_VAR_408 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("];");
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(av->name);
long int strLen_4 = strlen("char ");
;                            
            ____BAH_COMPILER_VAR_408 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, "char ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_408+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_408+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_408+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_408));
code = av->name;
if ((i+1!=len(l))) {
struct Tok errT = l->data[i+1];
throwErr(&errT,"{TOKEN} not expected after buffer declaration.");
}
break;
}
char * tp = getTypeFromToken(&t,true,elems);
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_409 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tp);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_409 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_409+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_409+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_409+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_409+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_409+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_409);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_410 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tp);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_410 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_410+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_410+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_410+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_410);
}
}
}
}
if ((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false)) {
char * ____BAH_COMPILER_VAR_411 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_411 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_411+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_411+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_411;
if ((t.isOper==false)&&(RCPavailable()==true)) {
struct variable* iv = searchVar(t.cont,elems);
if ((iv!=null)&&(iv->isConst==false)) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((s!=null)&&(strCount(iv->type,"*")==0)&&(s->isBinding==false)) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_412 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(iv->name);
long int strLen_1 = strlen("), 0)");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(iv->name);
long int strLen_4 = strlen("; RCP_scanStack(&");
long int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_412 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, "; RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, iv->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_412+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_412+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_412+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_412;
}
else {
struct string ivn = string(iv->name);
if ((ivn.count(&ivn,"*")>0)) {
ivn.replace(&ivn,"*","");
char * ____BAH_COMPILER_VAR_413 =null;char * ____BAH_COMPILER_VAR_414 =ivn.str(&ivn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(iv->name);
long int strLen_1 = strlen("), 0)");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_414);
long int strLen_4 = strlen("; RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_413 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, "; RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, ____BAH_COMPILER_VAR_414, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_413+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_413+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_413+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_415 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_413);
;                            
            ____BAH_COMPILER_VAR_415 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_415+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_415+currStrOff, ____BAH_COMPILER_VAR_413, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_415;
}
else {
char * ____BAH_COMPILER_VAR_416 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(iv->name);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("; RCP_incr(");
long int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_416 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_416+currStrOff, "; RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_416+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_416+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_416;
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
char * ____BAH_COMPILER_VAR_417 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_417 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_417+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_417+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_417;
}
i++;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {
struct Tok st = l->data[1];
char * ____BAH_COMPILER_VAR_418 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("' to {TOKEN}.");
long int strLen_2 = strlen("Cannot change the type of already declared var '");
;                            
            ____BAH_COMPILER_VAR_418 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_418+currStrOff, "Cannot change the type of already declared var '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_418+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_418+currStrOff, "' to {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&st,____BAH_COMPILER_VAR_418);
}
char * preCode = "";
if ((isStruct==false)) {
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_419 =null;char * ____BAH_COMPILER_VAR_420 =cType.str(&cType);char * ____BAH_COMPILER_VAR_421 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("*)RCP_incrIL(&");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_420);
long int strLen_4 = strlen(") = *(");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen("*)RCP_decrIL(&");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_421);
long int strLen_8 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_419 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, "*(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ____BAH_COMPILER_VAR_421, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, "*)RCP_decrIL(&", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ") = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ____BAH_COMPILER_VAR_420, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_419+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_419+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_419;
}
else {
struct variable* ____BAH_COMPILER_VAR_422 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_422->name = "";
____BAH_COMPILER_VAR_422->type = "";
____BAH_COMPILER_VAR_422->isConst = false;
____BAH_COMPILER_VAR_422->constVal = "";
____BAH_COMPILER_VAR_422->isArray = false;
____BAH_COMPILER_VAR_422->from = "";
____BAH_COMPILER_VAR_422->outterScope = false;
____BAH_COMPILER_VAR_422->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_422;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_423 =null;char * ____BAH_COMPILER_VAR_424 =dv->toStr(dv);char * ____BAH_COMPILER_VAR_425 =cType.str(&cType);char * ____BAH_COMPILER_VAR_426 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(");");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_424);
long int strLen_2 = strlen(code);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_425);
long int strLen_5 = strlen(" = *(");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen("; ");
long int strLen_8 = strlen(v->name);
long int strLen_9 = strlen(" = ");
long int strLen_10 = strlen(tmpV->name);
long int strLen_11 = strlen(" ");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_426);
;                            
            ____BAH_COMPILER_VAR_423 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, ____BAH_COMPILER_VAR_426, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, tmpV->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, " = ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, "; ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, " = *(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, ____BAH_COMPILER_VAR_425, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_423+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_423+currStrOff, ");", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_423+currStrOff, ____BAH_COMPILER_VAR_424, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_423;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_427 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_427->name = "";
____BAH_COMPILER_VAR_427->type = "";
____BAH_COMPILER_VAR_427->isConst = false;
____BAH_COMPILER_VAR_427->constVal = "";
____BAH_COMPILER_VAR_427->isArray = false;
____BAH_COMPILER_VAR_427->from = "";
____BAH_COMPILER_VAR_427->outterScope = false;
____BAH_COMPILER_VAR_427->isGlobal = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_427;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_428 =null;char * ____BAH_COMPILER_VAR_429 =dv->toStr(dv);char * ____BAH_COMPILER_VAR_430 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(";");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_429);
long int strLen_2 = strlen(code);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = ");
long int strLen_8 = strlen(tmpV->name);
long int strLen_9 = strlen(" ");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_430);
;                            
            ____BAH_COMPILER_VAR_428 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, ____BAH_COMPILER_VAR_430, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, " ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, tmpV->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, " = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_428+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_428+currStrOff, ";", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_428+currStrOff, ____BAH_COMPILER_VAR_429, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_428;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {
if ((strCount(v->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_431 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 1); ");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_431 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_431+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_431+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_431;
}
else {
struct string vn = string(v->name);
vn.replace(&vn,"*","");
char * ____BAH_COMPILER_VAR_432 =null;char * ____BAH_COMPILER_VAR_433 =vn.str(&vn);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("), 1); ");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_433);
long int strLen_4 = strlen("RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_432 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_432+currStrOff, "RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_432+currStrOff, ____BAH_COMPILER_VAR_433, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_432+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_432+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_432+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_432;
}
char * ____BAH_COMPILER_VAR_434 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_434 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_434+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_434+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_434+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_434;
}
else {
char * ____BAH_COMPILER_VAR_435 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_435 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_435+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_435+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_435;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_436 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_436;
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
i++;
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
i--;
};
long int tamm = n.length-i;
n.trimRight(&n,tamm+6);
char * nstr = n.str(&n);
struct string elemType = getCType(v->type,elems);
char * elemTypeStr = elemType.str(&elemType);
char * ____BAH_COMPILER_VAR_437 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n}\n}");
long int strLen_2 = strlen(preCode);
long int strLen_3 = strlen("->length = nLength+1;\n} else {\n");
long int strLen_4 = strlen(nstr);
long int strLen_5 = strlen(";\n");
long int strLen_6 = strlen(code);
long int strLen_7 = strlen("->data = newPtr;\n}\n");
long int strLen_8 = strlen(nstr);
long int strLen_9 = strlen("));\n");
long int strLen_10 = strlen(elemTypeStr);
long int strLen_11 = strlen("->data, (nLength+50)*sizeof(");
long int strLen_12 = strlen(nstr);
long int strLen_13 = strlen("->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(");
long int strLen_14 = strlen(nstr);
long int strLen_15 = strlen(";\nif (");
long int strLen_16 = strlen(nLengthStr);
long int strLen_17 = strlen("\n{\nlong nLength = ");
;                            
            ____BAH_COMPILER_VAR_437 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17);
            
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "\n{\nlong nLength = ", strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, nLengthStr, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, ";\nif (", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, nstr, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, nstr, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "->data, (nLength+50)*sizeof(", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, elemTypeStr, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "));\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, nstr, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "->data = newPtr;\n}\n", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, code, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, nstr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "->length = nLength+1;\n} else {\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, preCode, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_437+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_437+currStrOff, ";\n}\n}", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_437;
}
else {
char * ____BAH_COMPILER_VAR_438 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(preCode);
long int strLen_1 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_438 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_438+currStrOff, preCode, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_438+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_438;
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
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_439 =null;char * ____BAH_COMPILER_VAR_440 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_440);
;                            
            ____BAH_COMPILER_VAR_439 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_439+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_439+currStrOff, ____BAH_COMPILER_VAR_440, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_439;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_441 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_441 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_441+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_441+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_441;
}
};
char * ____BAH_COMPILER_VAR_442 =null;char * ____BAH_COMPILER_VAR_443 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_443);
;                            
            ____BAH_COMPILER_VAR_442 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, ____BAH_COMPILER_VAR_443, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_442+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_442+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_442+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_442;
}
else {
vct = setCType(v,elems);
}
if ((strcmp(code, "") != 0)&&(shouldOnlyDecl==false)) {
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_444 =null;char * ____BAH_COMPILER_VAR_445 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("*)RCP_incrIL(&");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_445);
long int strLen_4 = strlen(" = *(");
long int strLen_5 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_444 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_444+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_444+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_444+currStrOff, ____BAH_COMPILER_VAR_445, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_444+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_444+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_444+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_444));
}
else {
char * ____BAH_COMPILER_VAR_446 =null;char * ____BAH_COMPILER_VAR_447 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("*)RCP_incrIL(&");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_447);
long int strLen_4 = strlen(" = *(");
long int strLen_5 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_446 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, vct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, ____BAH_COMPILER_VAR_447, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_446+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_446+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_446+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_446;
}
}
else {
if ((needsDefine==true)) {

{
long nLength = len(elems->defined);
if (elems->defined->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->defined->data, (nLength+50)*sizeof(char *));
elems->defined->data = newPtr;
}
elems->defined->data[len(elems->defined)] = v->name;
elems->defined->length = nLength+1;
} else {
elems->defined->data[len(elems->defined)] = v->name;
}
};
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_448 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_448 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_448+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_448+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_448));
}
else {
char * ____BAH_COMPILER_VAR_449 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_449 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, "#define ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_449+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_449+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_449;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_450 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_450 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_450+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_450+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_450+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_450+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_450));
}
else {
char * ____BAH_COMPILER_VAR_451 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" = ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_451 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_451+currStrOff, vct, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_451+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_451+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_451;
}
}
}
}
else {
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {
char * ____BAH_COMPILER_VAR_452 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(vct);
long int strLen_1 = strlen("= null");
;                            
            ____BAH_COMPILER_VAR_452 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_452+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_452+currStrOff, "= null", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_452;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_453 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("extern ");
long int strLen_1 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_453+currStrOff, "extern ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_453+currStrOff, vct, strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_453;
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
struct variable* ____BAH_COMPILER_VAR_454 = v;
char ** ____BAH_COMPILER_VAR_456 = (char **)((char*)(____BAH_COMPILER_VAR_454) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_457 = __reflect(____BAH_COMPILER_VAR_456, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_458 = (char **)((char*)(____BAH_COMPILER_VAR_454) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_459 = __reflect(____BAH_COMPILER_VAR_458, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_460 = (char*)((char*)(____BAH_COMPILER_VAR_454) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_461 = __reflect(____BAH_COMPILER_VAR_460, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_462 = (char **)((char*)(____BAH_COMPILER_VAR_454) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_463 = __reflect(____BAH_COMPILER_VAR_462, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_464 = (char*)((char*)(____BAH_COMPILER_VAR_454) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_465 = __reflect(____BAH_COMPILER_VAR_464, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_466 = (char **)((char*)(____BAH_COMPILER_VAR_454) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_467 = __reflect(____BAH_COMPILER_VAR_466, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_468 = (char*)((char*)(____BAH_COMPILER_VAR_454) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_469 = __reflect(____BAH_COMPILER_VAR_468, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_470 = (char*)((char*)(____BAH_COMPILER_VAR_454) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_471 = __reflect(____BAH_COMPILER_VAR_470, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_455 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_455->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_455->length = 8;
        ____BAH_COMPILER_VAR_455->data = memoryAlloc(____BAH_COMPILER_VAR_455->length * ____BAH_COMPILER_VAR_455->elemSize);
        ____BAH_COMPILER_VAR_455->data[0] = ____BAH_COMPILER_VAR_457;
____BAH_COMPILER_VAR_455->data[1] = ____BAH_COMPILER_VAR_459;
____BAH_COMPILER_VAR_455->data[2] = ____BAH_COMPILER_VAR_461;
____BAH_COMPILER_VAR_455->data[3] = ____BAH_COMPILER_VAR_463;
____BAH_COMPILER_VAR_455->data[4] = ____BAH_COMPILER_VAR_465;
____BAH_COMPILER_VAR_455->data[5] = ____BAH_COMPILER_VAR_467;
____BAH_COMPILER_VAR_455->data[6] = ____BAH_COMPILER_VAR_469;
____BAH_COMPILER_VAR_455->data[7] = ____BAH_COMPILER_VAR_471;
struct reflectElement ____BAH_COMPILER_VAR_472 = __reflect(____BAH_COMPILER_VAR_454, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_455, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_472);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_473 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_473 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_473+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_473+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_473));
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
char * ____BAH_COMPILER_VAR_474 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_474 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_474+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_474+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_474));
}
else {
char * ____BAH_COMPILER_VAR_475 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_475 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_475+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_475+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_475));
}
}
};
char * getCfunctionType(struct string cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn = parseFnType(cfrt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
long int j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_476 =null;char * ____BAH_COMPILER_VAR_477 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_477);
;                            
            ____BAH_COMPILER_VAR_476 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_476+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_476+currStrOff, ____BAH_COMPILER_VAR_477, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_476;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_478 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_478 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_478+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_478+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_478;
}
};
char * ____BAH_COMPILER_VAR_479 =null;char * ____BAH_COMPILER_VAR_480 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(elemName);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_480);
;                            
            ____BAH_COMPILER_VAR_479 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, ____BAH_COMPILER_VAR_480, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, elemName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_479+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_479+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_479+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_479;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
long int j = *i;
struct Tok ft = l->data[j];
char * tpdf = "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_481 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(prev);
long int strLen_1 = strlen(ft.cont);
;                            
            ____BAH_COMPILER_VAR_481 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_481+currStrOff, prev, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_481+currStrOff, ft.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fn->name = ____BAH_COMPILER_VAR_481;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_482 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_482 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_482+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_482+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_482;
j = j+2;
struct Tok t = l->data[j];
if ((strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {
t = l->data[j];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as argument name.");
}
char * argName = t.cont;
j = j+1;
if ((j>=len(l))) {
throwErr(&t,"Cannot declare argument {TOKEN} without a type.");
}
t = l->data[j];
char * argType = t.cont;
j = j+1;
char isComa = false;
long int nbPars = 1;
while ((j<len(l))) {
t = l->data[j];
isComa = false;
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, "(") == 0)) {
nbPars = nbPars+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPars = nbPars-1;
}
if ((strcmp(t.cont, ")") == 0)&&(nbPars==0)) {
break;
}
else {
char * ____BAH_COMPILER_VAR_483 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(argType);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_483 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_483+currStrOff, argType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_483+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }argType = ____BAH_COMPILER_VAR_483;
}
}
else {
isComa = true;
break;
}
j = j+1;
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
struct variable* argument = ____BAH_COMPILER_VAR_484;
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
char * ____BAH_COMPILER_VAR_485 =null;char * ____BAH_COMPILER_VAR_486 =cfrt.str(&cfrt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_486);
;                            
            ____BAH_COMPILER_VAR_485 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_485+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_485+currStrOff, ____BAH_COMPILER_VAR_486, strLen_1);
            currStrOff += strLen_1;
        
        }newArgType = ____BAH_COMPILER_VAR_485;
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
char * ____BAH_COMPILER_VAR_487 =null;char * ____BAH_COMPILER_VAR_488 =argCType.str(&argCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(newArgType);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_488);
long int strLen_4 = strlen("typedef ");
long int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_487 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_487+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_487+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_487+currStrOff, ____BAH_COMPILER_VAR_488, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_487+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_487+currStrOff, newArgType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_487+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_487;
}
}
if ((cfrt.hasPrefix(&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_489 =null;char * ____BAH_COMPILER_VAR_490 =getCfunctionType(cfrt,argName,elems);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_490);
;                            
            ____BAH_COMPILER_VAR_489 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_489+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_489+currStrOff, ____BAH_COMPILER_VAR_490, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_489;
}
else {
char * ____BAH_COMPILER_VAR_491 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(argName);
long int strLen_2 = strlen(newArgType);
long int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_491 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_491+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_491+currStrOff, newArgType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_491+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_491+currStrOff, argName, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_491;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_492 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_492 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_492+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_492+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_492;
}
else {
char * ____BAH_COMPILER_VAR_493 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_493 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_493+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_493+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_493;
break;
}
j = j+1;
};
}
else {
char * ____BAH_COMPILER_VAR_494 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_494 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_494+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_494+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_494;
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_495 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_495->name = "";
____BAH_COMPILER_VAR_495->type = "";
____BAH_COMPILER_VAR_495->isConst = false;
____BAH_COMPILER_VAR_495->constVal = "";
____BAH_COMPILER_VAR_495->isArray = false;
____BAH_COMPILER_VAR_495->from = "";
____BAH_COMPILER_VAR_495->outterScope = false;
____BAH_COMPILER_VAR_495->isGlobal = false;
struct variable* returns = ____BAH_COMPILER_VAR_495;
returns->type = "";
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_496 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(returns->type);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_496 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_496+currStrOff, returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_496+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }returns->type = ____BAH_COMPILER_VAR_496;
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
char * ____BAH_COMPILER_VAR_497 =null;char * ____BAH_COMPILER_VAR_498 =cfrt.str(&cfrt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_498);
;                            
            ____BAH_COMPILER_VAR_497 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_497+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_497+currStrOff, ____BAH_COMPILER_VAR_498, strLen_1);
            currStrOff += strLen_1;
        
        }newFnRetType = ____BAH_COMPILER_VAR_497;
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
char * ____BAH_COMPILER_VAR_499 =null;char * ____BAH_COMPILER_VAR_500 =fnRetType.str(&fnRetType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(newFnRetType);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_500);
long int strLen_4 = strlen("typedef ");
long int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_499 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_499+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_499+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_499+currStrOff, ____BAH_COMPILER_VAR_500, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_499+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_499+currStrOff, newFnRetType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_499+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_499;
}
}
char * ____BAH_COMPILER_VAR_501 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(code);
long int strLen_2 = strlen(newFnRetType);
long int strLen_3 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_501 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_501+currStrOff, tpdf, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_501+currStrOff, newFnRetType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_501+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_501+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_501;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_502 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_502->name = "";
____BAH_COMPILER_VAR_502->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_502->members->length = 0;
            ____BAH_COMPILER_VAR_502->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_502->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_502->methods->length = 0;
            ____BAH_COMPILER_VAR_502->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_502->postCode = "";
____BAH_COMPILER_VAR_502->extendedFrom = "";
____BAH_COMPILER_VAR_502->isBinding = false;
____BAH_COMPILER_VAR_502->hasRCPmemb = false;
struct cStruct* s = ____BAH_COMPILER_VAR_502;
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
struct Tok nameToken = l->data[1];
long int i = 2;
char doesOutput = true;
if ((strcmp(nameToken.cont, "!") == 0)) {
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
struct Tok st = l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(st.cont, "extend") == 0)) {
i++;
struct Tok extdSNameTk = l->data[i];
i++;
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
struct structMemb* em = extdsmbs->data[j];
struct string cemt = string(em->type);
char * membDeclStr= null;
if ((cemt.hasPrefix(&cemt,"function(")==1)) {
struct func* tmpfn = parseFnType(cemt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_503 =null;char * ____BAH_COMPILER_VAR_504 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_504);
;                            
            ____BAH_COMPILER_VAR_503 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_503+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_503+currStrOff, ____BAH_COMPILER_VAR_504, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_503;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_505 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_505 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_505+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_505+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_505;
}
};
char * ____BAH_COMPILER_VAR_506 =null;char * ____BAH_COMPILER_VAR_507 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(em->name);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_507);
;                            
            ____BAH_COMPILER_VAR_506 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_506+currStrOff, ____BAH_COMPILER_VAR_507, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_506+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_506+currStrOff, em->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_506+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_506+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_506+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_506;
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
struct func* emt = extdS->methods->data[k];
struct string mthdDecl = getCType(emt->returns->type,elems);
char * ____BAH_COMPILER_VAR_508 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(emt->name);
long int strLen_1 = strlen(")(");
long int strLen_2 = strlen("(*");
;                            
            ____BAH_COMPILER_VAR_508 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_508+currStrOff, "(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_508+currStrOff, emt->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_508+currStrOff, ")(", strLen_1);
            currStrOff += strLen_1;
        
        }mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_508);
j = 0;
while ((j<len(emt->args))) {
struct variable* a = emt->args->data[j];
struct string tp = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_509 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
            ____BAH_COMPILER_VAR_509 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_509+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_509+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }tp.append(&tp,____BAH_COMPILER_VAR_509);
long int max = len(emt->args)-1;
if ((j!=max)) {
tp.append(&tp,",");
}
char * ____BAH_COMPILER_VAR_510 =tp.str(&tp);mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_510);
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
struct Tok braceTk = l->data[i];
i++;
if ((strcmp(braceTk.cont, "{") != 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
struct rope* OOUT = OUTPUT;
char * nextLine = "";
while ((i<len(l))) {
struct Tok t = l->data[i];
long int max = i+2;
if ((max>=len(l))) {
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "}") == 0)) {
break;
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* ____BAH_COMPILER_VAR_511 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_511->name = "";
____BAH_COMPILER_VAR_511->type = "";
____BAH_COMPILER_VAR_511->isConst = false;
____BAH_COMPILER_VAR_511->constVal = "";
____BAH_COMPILER_VAR_511->isArray = false;
____BAH_COMPILER_VAR_511->from = "";
____BAH_COMPILER_VAR_511->outterScope = false;
____BAH_COMPILER_VAR_511->isGlobal = false;
____BAH_COMPILER_VAR_511->def = "";
____BAH_COMPILER_VAR_511->isFn = false;
struct structMemb* memb = ____BAH_COMPILER_VAR_511;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name = t.cont;
long int ii = 0;
while ((ii<len(members))) {
struct structMemb* m = members->data[ii];
if ((strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii = ii+1;
};
i++;
t = l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_512 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_512 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_512+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_512+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnPrefix = ____BAH_COMPILER_VAR_512;
struct func* ____BAH_COMPILER_VAR_513 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_513->name = "";
____BAH_COMPILER_VAR_513->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_513->args->length = 0;
            ____BAH_COMPILER_VAR_513->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_513->returns= null;
____BAH_COMPILER_VAR_513->isBinding = false;
____BAH_COMPILER_VAR_513->from = "";
____BAH_COMPILER_VAR_513->file = "";
____BAH_COMPILER_VAR_513->line = 1;
____BAH_COMPILER_VAR_513->used = false;
____BAH_COMPILER_VAR_513->code = null;
struct func* fn = ____BAH_COMPILER_VAR_513;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int j = i-1;
while ((j<len(l))) {
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
char * ____BAH_COMPILER_VAR_514 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_514 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_514+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_514+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_514;
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
i--;
long int nli = 0;
char * ____BAH_COMPILER_VAR_515 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_515);
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
t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
i++;
}
while ((i<len(l))) {
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
i++;
};
struct func* ____BAH_COMPILER_VAR_516 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_516->name = "";
____BAH_COMPILER_VAR_516->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_516->args->length = 0;
            ____BAH_COMPILER_VAR_516->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_516->returns= null;
____BAH_COMPILER_VAR_516->isBinding = false;
____BAH_COMPILER_VAR_516->from = "";
____BAH_COMPILER_VAR_516->file = "";
____BAH_COMPILER_VAR_516->line = 1;
____BAH_COMPILER_VAR_516->used = false;
____BAH_COMPILER_VAR_516->code = null;
struct func* mfn = ____BAH_COMPILER_VAR_516;
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
char * ____BAH_COMPILER_VAR_517 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("' is not returned.");
long int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_517 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_517+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_517+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_517+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_517);
}
endRCPscope(fnElems,fn->args);
}
code = code->add(code, OUTPUT->add(OUTPUT, rope("};\n")));
}
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_518 =null;char * ____BAH_COMPILER_VAR_519 =code->toStr(code);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nextLine);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_519);
;                            
            ____BAH_COMPILER_VAR_518 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_518+currStrOff, nextLine, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_518+currStrOff, ____BAH_COMPILER_VAR_519, strLen_1);
            currStrOff += strLen_1;
        
        }nextLine = ____BAH_COMPILER_VAR_518;
}
struct string mthdDecl = getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_520 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(mfn->name);
long int strLen_1 = strlen(")(");
long int strLen_2 = strlen("(*");
;                            
            ____BAH_COMPILER_VAR_520 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_520+currStrOff, "(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_520+currStrOff, mfn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_520+currStrOff, ")(", strLen_1);
            currStrOff += strLen_1;
        
        }mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_520);
j = 0;
while ((j<len(arguments))) {
struct variable* a = arguments->data[j];
struct string tp = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_521 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
            ____BAH_COMPILER_VAR_521 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_521+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_521+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }tp.append(&tp,____BAH_COMPILER_VAR_521);
max = len(arguments)-1;
if ((j!=max)) {
tp.append(&tp,",");
}
char * ____BAH_COMPILER_VAR_522 =tp.str(&tp);mthdDecl.append(&mthdDecl,____BAH_COMPILER_VAR_522);
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
i++;
continue;
}
}
i++;
char * mbmType = "";
long int currentLine = t.line;
while ((i<len(l))) {
t = l->data[i];
if ((strcmp(t.cont, "=") == 0)) {
i--;
break;
}
if ((t.line!=currentLine)) {
i--;
break;
}
char * ____BAH_COMPILER_VAR_523 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(mbmType);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_523 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_523+currStrOff, mbmType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_523+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }mbmType = ____BAH_COMPILER_VAR_523;
i++;
};
memb->type = mbmType;
i++;
t = l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
i++;
t = l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char * ____BAH_COMPILER_VAR_524 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(memb->type);
long int strLen_1 = strlen(" for member.");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_524 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_524+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_524+currStrOff, memb->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_524+currStrOff, " for member.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_524);
}
memb->def = t.cont;
}
else {
i--;
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
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_525 =null;char * ____BAH_COMPILER_VAR_526 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_526);
;                            
            ____BAH_COMPILER_VAR_525 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_525+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_525+currStrOff, ____BAH_COMPILER_VAR_526, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_525;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_527 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_527 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_527+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_527+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_527;
}
};
char * ____BAH_COMPILER_VAR_528 =null;char * ____BAH_COMPILER_VAR_529 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(");
long int strLen_3 = strlen(memb->name);
long int strLen_4 = strlen(" (*");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_529);
;                            
            ____BAH_COMPILER_VAR_528 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, ____BAH_COMPILER_VAR_529, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, memb->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_528+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_528+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_528+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_528;
}
else {
struct string membDecl = getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_530 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(memb->name);
;                            
            ____BAH_COMPILER_VAR_530 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_530+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_530+currStrOff, memb->name, strLen_1);
            currStrOff += strLen_1;
        
        }membDecl.append(&membDecl,____BAH_COMPILER_VAR_530);
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
i++;
};
s->members = members;
if ((doesOutput==true)) {
OUTPUT = OOUT;
NEXT_LINE = nextLine;
char * ____BAH_COMPILER_VAR_531 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen(" {\n");
long int strLen_2 = strlen("struct ");
;                            
            ____BAH_COMPILER_VAR_531 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_531+currStrOff, "struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_531+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_531+currStrOff, " {\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* code = rope(____BAH_COMPILER_VAR_531);
i = 0;
while ((i<len(allMembs))) {
char * m = allMembs->data[i];
char * ____BAH_COMPILER_VAR_532 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(m);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_532 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_532+currStrOff, m, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_532+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = code->add(code, rope(____BAH_COMPILER_VAR_532));
i++;
};
code = code->add(code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, code);
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_533 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_533->name= null;
____BAH_COMPILER_VAR_533->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_533->membs->length = 0;
            ____BAH_COMPILER_VAR_533->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_533;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_534 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_534->name = "";
____BAH_COMPILER_VAR_534->type = "";
____BAH_COMPILER_VAR_534->isConst = false;
____BAH_COMPILER_VAR_534->constVal = "";
____BAH_COMPILER_VAR_534->isArray = false;
____BAH_COMPILER_VAR_534->from = "";
____BAH_COMPILER_VAR_534->outterScope = false;
____BAH_COMPILER_VAR_534->isGlobal = false;
struct variable* mv = ____BAH_COMPILER_VAR_534;
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
struct debugStruct* ____BAH_COMPILER_VAR_535 = ds;
char ** ____BAH_COMPILER_VAR_537 = (char **)((char*)(____BAH_COMPILER_VAR_535) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_538 = __reflect(____BAH_COMPILER_VAR_537, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_539 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_535) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_540 = 0;
char ** ____BAH_COMPILER_VAR_542 = (char **)((char*)(____BAH_COMPILER_VAR_540) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_543 = __reflect(____BAH_COMPILER_VAR_542, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_544 = (char **)((char*)(____BAH_COMPILER_VAR_540) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_545 = __reflect(____BAH_COMPILER_VAR_544, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_546 = (char*)((char*)(____BAH_COMPILER_VAR_540) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_547 = __reflect(____BAH_COMPILER_VAR_546, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_548 = (char **)((char*)(____BAH_COMPILER_VAR_540) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_549 = __reflect(____BAH_COMPILER_VAR_548, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_550 = (char*)((char*)(____BAH_COMPILER_VAR_540) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_551 = __reflect(____BAH_COMPILER_VAR_550, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_552 = (char **)((char*)(____BAH_COMPILER_VAR_540) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_553 = __reflect(____BAH_COMPILER_VAR_552, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_554 = (char*)((char*)(____BAH_COMPILER_VAR_540) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_555 = __reflect(____BAH_COMPILER_VAR_554, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_556 = (char*)((char*)(____BAH_COMPILER_VAR_540) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_557 = __reflect(____BAH_COMPILER_VAR_556, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_541 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_541->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_541->length = 8;
        ____BAH_COMPILER_VAR_541->data = memoryAlloc(____BAH_COMPILER_VAR_541->length * ____BAH_COMPILER_VAR_541->elemSize);
        ____BAH_COMPILER_VAR_541->data[0] = ____BAH_COMPILER_VAR_543;
____BAH_COMPILER_VAR_541->data[1] = ____BAH_COMPILER_VAR_545;
____BAH_COMPILER_VAR_541->data[2] = ____BAH_COMPILER_VAR_547;
____BAH_COMPILER_VAR_541->data[3] = ____BAH_COMPILER_VAR_549;
____BAH_COMPILER_VAR_541->data[4] = ____BAH_COMPILER_VAR_551;
____BAH_COMPILER_VAR_541->data[5] = ____BAH_COMPILER_VAR_553;
____BAH_COMPILER_VAR_541->data[6] = ____BAH_COMPILER_VAR_555;
____BAH_COMPILER_VAR_541->data[7] = ____BAH_COMPILER_VAR_557;
struct reflectElement ____BAH_COMPILER_VAR_558 = __reflect(____BAH_COMPILER_VAR_540, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_541, 0);

        struct reflectElement ____BAH_COMPILER_VAR_559 = ____BAH_COMPILER_VAR_558;
        struct reflectElement ____BAH_COMPILER_VAR_560 = __reflect(____BAH_COMPILER_VAR_539, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_559, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_536 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_536->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_536->length = 2;
        ____BAH_COMPILER_VAR_536->data = memoryAlloc(____BAH_COMPILER_VAR_536->length * ____BAH_COMPILER_VAR_536->elemSize);
        ____BAH_COMPILER_VAR_536->data[0] = ____BAH_COMPILER_VAR_538;
____BAH_COMPILER_VAR_536->data[1] = ____BAH_COMPILER_VAR_560;
struct reflectElement ____BAH_COMPILER_VAR_561 = __reflect(____BAH_COMPILER_VAR_535, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_536, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_561);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}
struct Tok ft = l->data[1];
struct Tok st = l->data[2];
long int i = 1;
char doesOutput = true;
if ((strcmp(ft.cont, "!") == 0)) {
ft = l->data[2];
st = l->data[3];
i = 2;
doesOutput = false;
}
if ((strcmp(st.cont, "(") == 0)) {
struct func* ____BAH_COMPILER_VAR_562 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_562->name = "";
____BAH_COMPILER_VAR_562->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_562->args->length = 0;
            ____BAH_COMPILER_VAR_562->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_562->returns= null;
____BAH_COMPILER_VAR_562->isBinding = false;
____BAH_COMPILER_VAR_562->from = "";
____BAH_COMPILER_VAR_562->file = "";
____BAH_COMPILER_VAR_562->line = 1;
____BAH_COMPILER_VAR_562->used = false;
____BAH_COMPILER_VAR_562->code = null;
struct func* fn = ____BAH_COMPILER_VAR_562;
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
char * ____BAH_COMPILER_VAR_563 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_563 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_563+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_563+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_563));
}
}
else {
char * tp = "";
i++;
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_564 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_564 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_564+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_564+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_564;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = cTypeNewType.str(&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_565 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(cTypeNewTypeStr);
long int strLen_4 = strlen("typedef ");
;                            
            ____BAH_COMPILER_VAR_565 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_565+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_565+currStrOff, cTypeNewTypeStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_565+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_565+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_565+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_565));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_566 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_566->name= null;
____BAH_COMPILER_VAR_566->refers= null;
struct debugType* dt = ____BAH_COMPILER_VAR_566;
dt->name = ft.cont;
dt->refers = tp;
struct debugType* ____BAH_COMPILER_VAR_567 = dt;
char ** ____BAH_COMPILER_VAR_569 = (char **)((char*)(____BAH_COMPILER_VAR_567) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_570 = __reflect(____BAH_COMPILER_VAR_569, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_571 = (char **)((char*)(____BAH_COMPILER_VAR_567) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_572 = __reflect(____BAH_COMPILER_VAR_571, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_568 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_568->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_568->length = 2;
        ____BAH_COMPILER_VAR_568->data = memoryAlloc(____BAH_COMPILER_VAR_568->length * ____BAH_COMPILER_VAR_568->elemSize);
        ____BAH_COMPILER_VAR_568->data[0] = ____BAH_COMPILER_VAR_570;
____BAH_COMPILER_VAR_568->data[1] = ____BAH_COMPILER_VAR_572;
struct reflectElement ____BAH_COMPILER_VAR_573 = __reflect(____BAH_COMPILER_VAR_567, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_568, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_573);
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
char * l = clibs->data[j];
if ((strcmp(l, ccstr) == 0)) {
found = true;
break;
}
j = j+1;
};
if ((found==true)) {
i++;
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
i++;
};
};
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
l = parseCast(l,elems,true);
if ((len(l)!=4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}
struct Tok vart = l->data[1];
struct Tok equt = l->data[2];
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
struct variable* ____BAH_COMPILER_VAR_574 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_574->name = "";
____BAH_COMPILER_VAR_574->type = "";
____BAH_COMPILER_VAR_574->isConst = false;
____BAH_COMPILER_VAR_574->constVal = "";
____BAH_COMPILER_VAR_574->isArray = false;
____BAH_COMPILER_VAR_574->from = "";
____BAH_COMPILER_VAR_574->outterScope = false;
____BAH_COMPILER_VAR_574->isGlobal = false;
struct variable* v = ____BAH_COMPILER_VAR_574;
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
char * ____BAH_COMPILER_VAR_575 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(valt.cont);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_575 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_575+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_575+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_575+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_575+currStrOff, valt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_575+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_575));
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
char * ____BAH_COMPILER_VAR_576 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentFn->returns->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Cannot return nothing as ");
;                            
            ____BAH_COMPILER_VAR_576 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_576+currStrOff, "Cannot return nothing as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_576+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_576+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_576);
}
}
else {
struct Tok rvt = l->data[1];
tt = getTypeFromToken(&rvt,true,elems);
rv = rvt.cont;
if ((rvt.isValue==false)) {
throwErr(&rvt,"Must be a value, not {TOKEN}.");
}
else if ((rvt.type==TOKEN_TYPE_VAR)&&(rvt.isOper==false)) {
tmpV = searchVar(rvt.cont,compilerState.currFnElems);
if ((tmpV==null)) {
tmpV = searchVar(rvt.cont,elems);
}
}
else if (RCPavailable()&&(rvt.type==TOKEN_TYPE_FUNC)) {
rv = genCompilerVar();
struct string cType = getCType(tt,elems);
char * ____BAH_COMPILER_VAR_577 =null;char * ____BAH_COMPILER_VAR_578 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rvt.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("=");
long int strLen_3 = strlen(rv);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_578);
;                            
            ____BAH_COMPILER_VAR_577 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, ____BAH_COMPILER_VAR_578, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, rv, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, "=", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_577+currStrOff, rvt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_577+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_577));
}
if ((compTypes(tt,currentFn->returns->type)==false)) {
char * ____BAH_COMPILER_VAR_579 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentFn->returns->type);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot return {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_579 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_579+currStrOff, "Cannot return {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_579+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_579+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_579+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_579+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&rvt,____BAH_COMPILER_VAR_579);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned = true;
}
if ((strlen(rv)>0)) {
char * rvar = rv;
if ((RCPavailable()==true)&&isRCPtype(currentFn->returns->type,elems)) {
rvar = genCompilerVar();
struct string cType = getCType(currentFn->returns->type,elems);
char * ____BAH_COMPILER_VAR_580 =null;char * ____BAH_COMPILER_VAR_581 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rv);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rvar);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_581);
;                            
            ____BAH_COMPILER_VAR_580 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_580+currStrOff, ____BAH_COMPILER_VAR_581, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_580+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_580+currStrOff, rvar, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_580+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_580+currStrOff, rv, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_580+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_580));
if ((tmpV!=null)&&(tmpV->outterScope==true)) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(tmpV,elems));
}
}
if (strHasPrefix(tt,"buffer:")) {
char * ____BAH_COMPILER_VAR_582 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rvar);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("__STR(");
;                            
            ____BAH_COMPILER_VAR_582 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_582+currStrOff, "__STR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_582+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_582+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }rvar = ____BAH_COMPILER_VAR_582;
}
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
long int j = 0;
for (; (j<len(currentFn->args)); j++) {

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
char * ____BAH_COMPILER_VAR_583 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(rvar);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("return ");
;                            
            ____BAH_COMPILER_VAR_583 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_583+currStrOff, "return ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_583+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_583+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_583));
}
else {
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
long int j = 0;
for (; (j<len(currentFn->args)); j++) {

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
struct Tok ft = l->data[0];
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}
struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}
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
i++;
};
char * ____BAH_COMPILER_VAR_584 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(condt.cont);
long int strLen_1 = strlen(") {\n");
long int strLen_2 = strlen("if (");
;                            
            ____BAH_COMPILER_VAR_584 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_584+currStrOff, "if (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_584+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_584+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_584));
struct Elems* ifElems = dupElems(elems);
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
beginRCPscopeLeaky(ifElems);
parseLines(tokens,ifElems);
endRCPscopeLeaky(ifElems,null);
if ((debug==true)) {
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
struct Tok ft = l->data[1];
OUTPUT = OUTPUT->add(OUTPUT, rope("else "));
if ((strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int i = 1;
while ((i<len(l))) {

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
i++;
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
i++;
};
OUTPUT = OUTPUT->add(OUTPUT, rope("{\n"));
struct Elems* ifElems = dupElems(elems);
char oldIB = compilerState.isBranch;
compilerState.isBranch = true;
struct Tok t = l->data[0];
beginRCPscopeLeaky(ifElems);
parseLines(memory,ifElems);
endRCPscopeLeaky(ifElems,null);
if ((debug==true)) {
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
struct Tok t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, ",") == 0)) {
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
struct Tok t = l->data[0];
throwErr(&t,"Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);
struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}
struct Tok st = l->data[2];
if ((st.type!=TOKEN_TYPE_SYNTAX)||(strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Cannot use {TOKEN}, need ',' to split for loop instructions.");
}
i = 3;
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "{") == 0)) {
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
char * ____BAH_COMPILER_VAR_585 =OUTPUT->toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_585);
OUTPUT = oldOut;
instC.trimRight(&instC,2);
struct Tok t = l->data[i];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}
long int max = len(l)-1;
i = i+1;
for (; (i<max); i++) {
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
char * ____BAH_COMPILER_VAR_586 =null;char * ____BAH_COMPILER_VAR_587 =instC.str(&instC);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_587);
long int strLen_1 = strlen(") {\n");
long int strLen_2 = strlen("; ");
long int strLen_3 = strlen(condt.cont);
long int strLen_4 = strlen("for (; ");
;                            
            ____BAH_COMPILER_VAR_586 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_586+currStrOff, "for (; ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_586+currStrOff, condt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_586+currStrOff, "; ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_586+currStrOff, ____BAH_COMPILER_VAR_587, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_586+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_588 =____BAH_COMPILER_VAR_586;OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_588));
}
else {
struct Tok condt = l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}
struct Tok t = l->data[2];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}
long int max = len(l)-1;
i = 3;
for (; (i<max); i++) {
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
char * ____BAH_COMPILER_VAR_589 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(condt.cont);
long int strLen_1 = strlen(") {\n");
long int strLen_2 = strlen("while (");
;                            
            ____BAH_COMPILER_VAR_589 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_589+currStrOff, "while (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_589+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_589+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_589));
}
struct Elems* oForElems = compilerState.currForElems;
struct Elems* ifElems = dupElems(elems);
compilerState.currForElems = ifElems;
char oldIB = compilerState.isBranch;
char oldIF = compilerState.isFor;
compilerState.isBranch = true;
compilerState.isFor = true;
struct Tok t = l->data[0];
beginRCPscopeLeaky(ifElems);
parseLines(tokens,ifElems);
endRCPscopeLeaky(ifElems,null);
if ((debug==true)) {
struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isFor = oldIF;
compilerState.isBranch = oldIB;
compilerState.currForElems = oForElems;
OUTPUT = OUTPUT->add(OUTPUT, rope("};\n"));
};
void parseForOp(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct Tok ft = l->data[0];
if ((compilerState.isFor==false)) {
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}
if ((len(l)!=1)) {
throwErr(&ft,"Nothing expected after {TOKEN}.");
}
endRCPscopeLeaky(elems,null);
endRCPscopeLeaky(compilerState.currForElems,null);
char * ____BAH_COMPILER_VAR_590 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_590 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_590+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_590+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_590));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

        char ____BAH_COMPILER_VAR_591 = 0;
        for(int i=compilerState.evals->length-1; i!=-1;i--) {
            if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                ____BAH_COMPILER_VAR_591=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_591) {
return;
}
char * ____BAH_COMPILER_VAR_592 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("__Bah_eval_");
long int strLen_1 = strlen(fn->name);
;                            
            ____BAH_COMPILER_VAR_592 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_592+currStrOff, "__Bah_eval_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_592+currStrOff, fn->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* ____BAH_COMPILER_VAR_593 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_593->name = "";
____BAH_COMPILER_VAR_593->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_593->args->length = 0;
            ____BAH_COMPILER_VAR_593->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_593->returns= null;
____BAH_COMPILER_VAR_593->isBinding = false;
____BAH_COMPILER_VAR_593->from = "";
____BAH_COMPILER_VAR_593->file = "";
____BAH_COMPILER_VAR_593->line = 1;
____BAH_COMPILER_VAR_593->used = false;
____BAH_COMPILER_VAR_593->code = null;
____BAH_COMPILER_VAR_593->name = ____BAH_COMPILER_VAR_592;
struct func* efn = ____BAH_COMPILER_VAR_593;
struct variable* ____BAH_COMPILER_VAR_594 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_594->name = "";
____BAH_COMPILER_VAR_594->type = "";
____BAH_COMPILER_VAR_594->isConst = false;
____BAH_COMPILER_VAR_594->constVal = "";
____BAH_COMPILER_VAR_594->isArray = false;
____BAH_COMPILER_VAR_594->from = "";
____BAH_COMPILER_VAR_594->outterScope = false;
____BAH_COMPILER_VAR_594->isGlobal = false;
____BAH_COMPILER_VAR_594->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_594;
struct variable* ____BAH_COMPILER_VAR_595 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_595->name = "";
____BAH_COMPILER_VAR_595->type = "";
____BAH_COMPILER_VAR_595->isConst = false;
____BAH_COMPILER_VAR_595->constVal = "";
____BAH_COMPILER_VAR_595->isArray = false;
____BAH_COMPILER_VAR_595->from = "";
____BAH_COMPILER_VAR_595->outterScope = false;
____BAH_COMPILER_VAR_595->isGlobal = false;
____BAH_COMPILER_VAR_595->name = "fnArgs";
____BAH_COMPILER_VAR_595->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);efn->args->data[0] = ____BAH_COMPILER_VAR_595;
char * fnBinding = "";
char * ____BAH_COMPILER_VAR_596 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_596 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_596+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_596+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnCall = ____BAH_COMPILER_VAR_596;
long int i = 0;
for (; (i<len(fn->args)); i++) {
struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
cType.append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_597 =null;char * ____BAH_COMPILER_VAR_598 =intToStr(i);char * ____BAH_COMPILER_VAR_599 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_598);
long int strLen_1 = strlen("];");
long int strLen_2 = strlen(" = fnArgs->data[");
long int strLen_3 = strlen(v);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_599);
;                            
            ____BAH_COMPILER_VAR_597 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_597+currStrOff, ____BAH_COMPILER_VAR_599, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_597+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_597+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_597+currStrOff, " = fnArgs->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_597+currStrOff, ____BAH_COMPILER_VAR_598, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_597+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_600 =null;char * ____BAH_COMPILER_VAR_601 =____BAH_COMPILER_VAR_597;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnBinding);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_601);
;                            
            ____BAH_COMPILER_VAR_600 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_600+currStrOff, fnBinding, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_600+currStrOff, ____BAH_COMPILER_VAR_601, strLen_1);
            currStrOff += strLen_1;
        
        }fnBinding = ____BAH_COMPILER_VAR_600;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_602 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_602 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_602+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_602+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_602;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_603 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_603 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_603+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_603+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_603;
}
else {
char * ____BAH_COMPILER_VAR_604 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("*");
long int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_604 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_604+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_604+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_605 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_604);
;                            
            ____BAH_COMPILER_VAR_605 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_605+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_605+currStrOff, ____BAH_COMPILER_VAR_604, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_605;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(cType.str(&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_606 =null;char * ____BAH_COMPILER_VAR_607 =cType.str(&cType);char * ____BAH_COMPILER_VAR_608 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_607);
long int strLen_1 = strlen("));*r = ");
long int strLen_2 = strlen("* r = memoryAlloc(sizeof(");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_608);
;                            
            ____BAH_COMPILER_VAR_606 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_606+currStrOff, ____BAH_COMPILER_VAR_608, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_606+currStrOff, "* r = memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_606+currStrOff, ____BAH_COMPILER_VAR_607, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_606+currStrOff, "));*r = ", strLen_1);
            currStrOff += strLen_1;
        
        }setReturnValue = ____BAH_COMPILER_VAR_606;
}
}
char * ____BAH_COMPILER_VAR_609 =null;char * ____BAH_COMPILER_VAR_610 =intToStr(len(fn->args));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(");\n        return (void*)r;\n    };");
long int strLen_2 = strlen(setReturnValue);
long int strLen_3 = strlen("\n        ");
long int strLen_4 = strlen(fnBinding);
long int strLen_5 = strlen("() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ");
long int strLen_6 = strlen(fn->name);
long int strLen_7 = strlen(") {\n            __BAH_panic((char*)\"eval: calling function ");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_610);
long int strLen_9 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
long int strLen_10 = strlen(efn->name);
long int strLen_11 = strlen("void* __attribute__((optimize(\"O0\"))) ");
;                            
            ____BAH_COMPILER_VAR_609 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11);
            
                    memcpy(____BAH_COMPILER_VAR_609+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_609+currStrOff, efn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_609+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_609+currStrOff, ____BAH_COMPILER_VAR_610, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_609+currStrOff, ") {\n            __BAH_panic((char*)\"eval: calling function ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_609+currStrOff, fn->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_609+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_609+currStrOff, fnBinding, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_609+currStrOff, "\n        ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_609+currStrOff, setReturnValue, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_609+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_609+currStrOff, ");\n        return (void*)r;\n    };", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_609));

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
struct Tok ft = l->data[0];
if ((strcmp(ft.cont, "#warning") == 0)) {
if ((len(l)!=2)) {
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}
struct Tok mt = l->data[1];
if ((mt.type!=TOKEN_TYPE_STR)) {
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}
struct string msg = string(mt.cont);
msg.trimLeft(&msg,1);
msg.trimRight(&msg,1);
char * ____BAH_COMPILER_VAR_611 =msg.str(&msg);throwWarning(____BAH_COMPILER_VAR_611);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

        char ____BAH_COMPILER_VAR_612 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                ____BAH_COMPILER_VAR_612=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_612==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_613 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
;                            
            ____BAH_COMPILER_VAR_613 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_613+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_613+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_613+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_613);
}
}
if ((len(l)!=2)||(isGlobal()==false)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN} <#eval fnName>.");
}
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
for (; (i<len(elems->fns)); i++) {
struct func* fn = elems->fns->data[i];
fn->used = true;
if ((fn->isBinding==false)&&(strHasPrefix(fn->name,"__Bah_eval_")==false)) {
makeEvalFunc(fn,elems);
}
};
return;
}
if ((len(l)<3)) {
throwErr(&ft,"Invalid usage of keyword {TOKEN}.");
}
if ((strcmp(ft.cont, "#linux") == 0)||(strcmp(ft.cont, "#windows") == 0)||(strcmp(ft.cont, "#darwin") == 0)) {
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
if ((isSubObject==false)||(isObject==false)) {
return;
}
}
else if ((strcmp(ft.cont, "#included") == 0)) {
if ((isSubObject==true)||(isObject==true)) {
return;
}
}
else {
throwErr(&ft,"Undefined token {TOKEN}.");
}
struct Tok st = l->data[1];
struct Tok lt = l->data[len(l)-1];
if ((strcmp(st.cont, "{") != 0)||(strcmp(lt.cont, "}") != 0)) {
throwErr(&st,"Expected code block after keyword {TOKEN}.");
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i = 2;
while ((i<len(l)-1)) {

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
struct Tok ft = l->data[0];
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}
struct Tok fnT = l->data[1];
if ((fnT.isFunc==false)) {
throwErr(&fnT,"Cannot use keyword async on {TOKEN}. Usage: 'async <function call>'.");
}
char found = false;
long int i = 0;
while ((i<len(compilerState.cLibs))) {
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
struct string fnName = fnNameParts->data[0];
char * ____BAH_COMPILER_VAR_614 =fnName.str(&fnName);struct func* fn = searchFunc(____BAH_COMPILER_VAR_614,elems,true);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_615 =null;char * ____BAH_COMPILER_VAR_616 =fnName.str(&fnName);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_616);
long int strLen_1 = strlen("', arround {TOKEN}.");
long int strLen_2 = strlen("Internal compiler error.\n Error parsing async call for function '");
;                            
            ____BAH_COMPILER_VAR_615 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_615+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_615+currStrOff, ____BAH_COMPILER_VAR_616, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_615+currStrOff, "', arround {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_617 =____BAH_COMPILER_VAR_615;throwErr(&fnT,____BAH_COMPILER_VAR_617);
}
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {
struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_618 =null;char * ____BAH_COMPILER_VAR_619 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(a->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_619);
long int strLen_4 = strlen(sMembs);
;                            
            ____BAH_COMPILER_VAR_618 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_618+currStrOff, sMembs, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_618+currStrOff, ____BAH_COMPILER_VAR_619, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_618+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_618+currStrOff, a->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_618+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }sMembs = ____BAH_COMPILER_VAR_618;
char * ____BAH_COMPILER_VAR_620 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("args->");
long int strLen_1 = strlen(a->name);
long int strLen_2 = strlen(unSerMembs);
;                            
            ____BAH_COMPILER_VAR_620 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_620+currStrOff, unSerMembs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_620+currStrOff, "args->", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_620+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_620;
i = i+1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_621 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_621 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_621+currStrOff, unSerMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_621+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_621;
}
};
char * ____BAH_COMPILER_VAR_622 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sMembs);
long int strLen_1 = strlen("}");
long int strLen_2 = strlen("struct {\n");
;                            
            ____BAH_COMPILER_VAR_622 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_622+currStrOff, "struct {\n", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_622+currStrOff, sMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_622+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }char * tmpArgsStruct = ____BAH_COMPILER_VAR_622;
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
char * ____BAH_COMPILER_VAR_623 =null;char * ____BAH_COMPILER_VAR_624 =sFnT.str(&sFnT);char * ____BAH_COMPILER_VAR_625 =fnName.str(&fnName);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpArgs);
long int strLen_1 = strlen(");\n    }; \n    \n    ");
long int strLen_2 = strlen(", &");
long int strLen_3 = strlen(fnWrapper);
long int strLen_4 = strlen("(&id, 0, ");
long int strLen_5 = strlen(tCreate);
long int strLen_6 = strlen("};\n        pthread_t id;\n        ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_624);
long int strLen_8 = strlen(" = {");
long int strLen_9 = strlen(tmpArgs);
long int strLen_10 = strlen(" ");
long int strLen_11 = strlen(tmpArgsStruct);
long int strLen_12 = strlen(");\n    };\n    {\n        ");
long int strLen_13 = strlen(unSerMembs);
long int strLen_14 = strlen("(");
long int strLen_15 = strlen(____BAH_COMPILER_VAR_625);
long int strLen_16 = strlen("* args) {\n        ");
long int strLen_17 = strlen(tmpArgsStruct);
long int strLen_18 = strlen("(");
long int strLen_19 = strlen(fnWrapper);
long int strLen_20 = strlen("\n    void ");
;                            
            ____BAH_COMPILER_VAR_623 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20);
            
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, "\n    void ", strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, fnWrapper, strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, "(", strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, tmpArgsStruct, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, "* args) {\n        ", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, ____BAH_COMPILER_VAR_625, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, "(", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, unSerMembs, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, ");\n    };\n    {\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, tmpArgsStruct, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, tmpArgs, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, " = {", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, ____BAH_COMPILER_VAR_624, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, "};\n        pthread_t id;\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, tCreate, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, "(&id, 0, ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, fnWrapper, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_623+currStrOff, ", &", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_623+currStrOff, tmpArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_623+currStrOff, ");\n    }; \n    \n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_623));
};
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
long int i = 0;
if ((ltp==LINE_TYPE_VAR)) {
i = 1;
}
while ((i<len(l))) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)) {
struct variable* v = searchVarByToken(t,elems);
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
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "->") == 0)||(strcmp(t.cont, "<-") == 0)) {
if ((strcmp(t.cont, "<-") == 0)) {
i++;
if ((i<len(l))) {
struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_626 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_626);
if ((ntt.hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_627 =null;char * ____BAH_COMPILER_VAR_628 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_628);
long int strLen_1 = strlen(") as channel.");
long int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_627 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_627+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_627+currStrOff, ____BAH_COMPILER_VAR_628, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_627+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_629 =____BAH_COMPILER_VAR_627;throwErr(&nt,____BAH_COMPILER_VAR_629);
}
ntt.trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_630 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_630)) {
char * ____BAH_COMPILER_VAR_631 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_631,elems);
char * ____BAH_COMPILER_VAR_632 =null;char * ____BAH_COMPILER_VAR_633 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_633);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_632 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, ____BAH_COMPILER_VAR_633, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_632+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_632+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_632+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_632;
}
else {
char * ____BAH_COMPILER_VAR_634 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_634,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_635 =null;char * ____BAH_COMPILER_VAR_636 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_636);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_635 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_635+currStrOff, ____BAH_COMPILER_VAR_636, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_635+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_637 =null;char * ____BAH_COMPILER_VAR_638 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_638);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_637 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_637+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_637+currStrOff, ____BAH_COMPILER_VAR_638, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_637+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_637+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_637+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_637+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_637+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_639 =____BAH_COMPILER_VAR_635;tmpV = registerRCPvar(____BAH_COMPILER_VAR_639,____BAH_COMPILER_VAR_637,elems);
char * ____BAH_COMPILER_VAR_640 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("*");
long int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_640 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_640+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_640+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_640;
}
else {
char * ____BAH_COMPILER_VAR_641 =null;char * ____BAH_COMPILER_VAR_642 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_642);
long int strLen_6 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_641 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_641+currStrOff, "*(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_641+currStrOff, ____BAH_COMPILER_VAR_642, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_641+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_641+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_641+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_641+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_641+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_641;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_643 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_643)) {
char * ____BAH_COMPILER_VAR_644 =ntt.str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_644,t.cont,elems);
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
struct Tok pt = l->data[i+1];
struct Tok nt = l->data[i-1];
char * ntt = getTypeFromToken(&nt,true,elems);
if ((pt.type!=TOKEN_TYPE_VAR)) {
throwErr(&pt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_645 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_645);
if ((ptt.hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_646 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ntt);
long int strLen_1 = strlen(") as channel.");
long int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_646 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_646+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_646+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_646+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_646);
}
ptt.trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_647 =ptt.str(&ptt);if ((compTypes(____BAH_COMPILER_VAR_647,ntt)==false)) {
char * ____BAH_COMPILER_VAR_648 =null;char * ____BAH_COMPILER_VAR_649 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_649);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") to channel of type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_648 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_648+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_648+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_648+currStrOff, ") to channel of type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_648+currStrOff, ____BAH_COMPILER_VAR_649, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_648+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_650 =____BAH_COMPILER_VAR_648;throwErr(&nt,____BAH_COMPILER_VAR_650);
}
i++;
char * ____BAH_COMPILER_VAR_651 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_651)) {
char * ____BAH_COMPILER_VAR_652 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("->send(");
long int strLen_5 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_652 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, "->send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_652+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_652+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_652+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_652));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_653 =null;char * ____BAH_COMPILER_VAR_654 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV);
long int strLen_1 = strlen("));\n");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(", &");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("->sendAny(");
long int strLen_7 = strlen(pt.cont);
long int strLen_8 = strlen(";\n                    ");
long int strLen_9 = strlen(nt.cont);
long int strLen_10 = strlen(" = ");
long int strLen_11 = strlen(tmpV);
long int strLen_12 = strlen(" ");
long int strLen_13 = strlen(____BAH_COMPILER_VAR_654);
long int strLen_14 = strlen("\n                    ");
;                            
            ____BAH_COMPILER_VAR_653 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, "\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, ____BAH_COMPILER_VAR_654, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, " ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, " = ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, nt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, ";\n                    ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, "->sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_653+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_653+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_653+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_653));
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
long int valueFunc(struct func* fn,struct variable* parent,__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i;
if ((fn==null)) {
if ((i>0)) {
tokPos = i-1;
struct Tok pt = l->data[tokPos];
if ((pt.type==TOKEN_TYPE_VAR)) {
delete(l,tokPos);
fn = searchFunc(pt.cont,elems,true);
if ((fn==null)) {
throwErr(&pt,"Unknown func {TOKEN}.");
}
}
else {
tokPos++;
}
}
else {
return i;
}
}
struct Tok fnt = l->data[tokPos];
if ((fn==null)) {
long int nbEncls = 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i = tokPos+1;
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
nbEncls++;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
nbEncls--;
if ((nbEncls==0)) {
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
deleteRange(l,tokPos+1,i);
array(struct Tok)* memort = prePross(memory,(lineType)-1,elems);
struct Tok ft = memory->data[0];
fnt.cont = "(";
fnt.isOper = true;
fnt.isValue = true;
fnt.bahType = getTypeFromToken(&ft,true,elems);
long int j = 0;
for (; (j<len(memory)); j++) {
struct Tok t = memory->data[j];
char * ____BAH_COMPILER_VAR_655 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_655 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_655+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_655+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_655;
};
char * ____BAH_COMPILER_VAR_656 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_656 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_656+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_656+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_656;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = fnt;
l->length = nLength+1;
} else {
l->data[tokPos] = fnt;
}
};
return tokPos;
}
char * ____BAH_COMPILER_VAR_657 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_657 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_657+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_657+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_657;
if ((fn->returns!=null)&&(strcmp(fn->returns->type, "") != 0)) {
fnt.isValue = true;
fnt.bahType = fn->returns->type;
}
fnt.isFunc = true;
fnt.type = TOKEN_TYPE_FUNC;
long int nbEncls = 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i = tokPos+1;
for (; (i<len(l)); i++) {
struct Tok t = l->data[i];
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
nbEncls++;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
nbEncls--;
if ((nbEncls==0)) {
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
deleteRange(l,tokPos+1,i);
if ((strcmp(fn->name, "noCheck") == 0)) {
fnt.cont = "";
fnt.isOper = true;
fnt.isValue = true;
fnt.bahType = "ptr";
long int j = 0;
for (; (j<len(memory)); j++) {
struct Tok t = memory->data[j];
char * ____BAH_COMPILER_VAR_658 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_658 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_658+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_658+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_658;
};

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = fnt;
l->length = nLength+1;
} else {
l->data[tokPos] = fnt;
}
};
return tokPos;
}
char * ____BAH_COMPILER_VAR_659 =null;char * ____BAH_COMPILER_VAR_660 =intToStr(fnt.line);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_660);
long int strLen_1 = strlen("\"");
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_659 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_659+currStrOff, ____BAH_COMPILER_VAR_660, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_659+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }char * currLine = ____BAH_COMPILER_VAR_659;
if ((strcmp(fn->name, "panic") == 0)) {
struct Tok ____BAH_COMPILER_VAR_661 = {};
____BAH_COMPILER_VAR_661.cont = "";
____BAH_COMPILER_VAR_661.ogCont = "";
____BAH_COMPILER_VAR_661.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_661.pos = 0;
____BAH_COMPILER_VAR_661.line = 1;
____BAH_COMPILER_VAR_661.begLine = 1;
____BAH_COMPILER_VAR_661.bahType = "";
____BAH_COMPILER_VAR_661.isValue = false;
____BAH_COMPILER_VAR_661.isFunc = false;
____BAH_COMPILER_VAR_661.isOper = false;
____BAH_COMPILER_VAR_661.isEqual = false;
____BAH_COMPILER_VAR_661.pass = false;
____BAH_COMPILER_VAR_661.bahRef= null;
____BAH_COMPILER_VAR_661.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_661.cont = ",";
____BAH_COMPILER_VAR_661.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_661;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_661;
}
};
struct Tok ____BAH_COMPILER_VAR_662 = {};
____BAH_COMPILER_VAR_662.cont = "";
____BAH_COMPILER_VAR_662.ogCont = "";
____BAH_COMPILER_VAR_662.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_662.pos = 0;
____BAH_COMPILER_VAR_662.line = 1;
____BAH_COMPILER_VAR_662.begLine = 1;
____BAH_COMPILER_VAR_662.bahType = "";
____BAH_COMPILER_VAR_662.isValue = false;
____BAH_COMPILER_VAR_662.isFunc = false;
____BAH_COMPILER_VAR_662.isOper = false;
____BAH_COMPILER_VAR_662.isEqual = false;
____BAH_COMPILER_VAR_662.pass = false;
____BAH_COMPILER_VAR_662.bahRef= null;
____BAH_COMPILER_VAR_662.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_662.cont = currLine;
____BAH_COMPILER_VAR_662.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_662;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_662;
}
};
fn = searchFunc("__BAH_panic",elems,true);
char * ____BAH_COMPILER_VAR_663 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_663 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_663+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_663+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_663;
}
else if ((strcmp(fn->name, "__dumpSymbols") == 0)) {
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);
long int j = 0;
for (; (j<len(elems->vars)); j++) {
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
struct variable* ____BAH_COMPILER_VAR_664 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_664->name = "";
____BAH_COMPILER_VAR_664->type = "";
____BAH_COMPILER_VAR_664->isConst = false;
____BAH_COMPILER_VAR_664->constVal = "";
____BAH_COMPILER_VAR_664->isArray = false;
____BAH_COMPILER_VAR_664->from = "";
____BAH_COMPILER_VAR_664->outterScope = false;
____BAH_COMPILER_VAR_664->isGlobal = false;
____BAH_COMPILER_VAR_664->name = genCompilerVar();
____BAH_COMPILER_VAR_664->type = "[]reflectElement";
____BAH_COMPILER_VAR_664->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_664;
char * decls = "";
j = 0;
for (; (j<len(symbols)); j++) {
struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_665 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("&");
long int strLen_1 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_665 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_665+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_665+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }vname = ____BAH_COMPILER_VAR_665;
}
struct Tok ____BAH_COMPILER_VAR_666 = {};
____BAH_COMPILER_VAR_666.cont = "";
____BAH_COMPILER_VAR_666.ogCont = "";
____BAH_COMPILER_VAR_666.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_666.pos = 0;
____BAH_COMPILER_VAR_666.line = 1;
____BAH_COMPILER_VAR_666.begLine = 1;
____BAH_COMPILER_VAR_666.bahType = "";
____BAH_COMPILER_VAR_666.isValue = false;
____BAH_COMPILER_VAR_666.isFunc = false;
____BAH_COMPILER_VAR_666.isOper = false;
____BAH_COMPILER_VAR_666.isEqual = false;
____BAH_COMPILER_VAR_666.pass = false;
____BAH_COMPILER_VAR_666.bahRef= null;
____BAH_COMPILER_VAR_666.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_666.cont = vname;
____BAH_COMPILER_VAR_666.bahType = v->type;
____BAH_COMPILER_VAR_666.isValue = true;
#define tmpT ____BAH_COMPILER_VAR_666
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_667 =null;char * ____BAH_COMPILER_VAR_668 =intToStr(j);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpT.cont);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("] = ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_668);
long int strLen_4 = strlen("->data[");
long int strLen_5 = strlen(tmpV->name);
;                            
            ____BAH_COMPILER_VAR_667 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_667+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_667+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_667+currStrOff, ____BAH_COMPILER_VAR_668, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_667+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_667+currStrOff, tmpT.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_667+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_669 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(decls);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_667);
;                            
            ____BAH_COMPILER_VAR_669 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_669+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_669+currStrOff, ____BAH_COMPILER_VAR_667, strLen_1);
            currStrOff += strLen_1;
        
        }decls = ____BAH_COMPILER_VAR_669;

#undef tmpT
};

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
char * ____BAH_COMPILER_VAR_670 =null;char * ____BAH_COMPILER_VAR_671 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_672 =intToStr(len(symbols));
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(decls);
long int strLen_1 = strlen("\n        ");
long int strLen_2 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen(";\n        ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_671);
long int strLen_6 = strlen("->length = ");
long int strLen_7 = strlen(tmpV->name);
long int strLen_8 = strlen(");\n        ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_672);
long int strLen_10 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
long int strLen_11 = strlen(tmpV->name);
long int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_13 = strlen(tmpV->name);
long int strLen_14 = strlen("\n        array(struct reflectElement)* ");
;                            
            ____BAH_COMPILER_VAR_670 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, "\n        array(struct reflectElement)* ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, tmpV->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, tmpV->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, ____BAH_COMPILER_VAR_672, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, ");\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, tmpV->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, "->length = ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, ____BAH_COMPILER_VAR_671, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_670+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_670+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_670+currStrOff, "\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_670));
struct Tok ____BAH_COMPILER_VAR_673 = {};
____BAH_COMPILER_VAR_673.cont = "";
____BAH_COMPILER_VAR_673.ogCont = "";
____BAH_COMPILER_VAR_673.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_673.pos = 0;
____BAH_COMPILER_VAR_673.line = 1;
____BAH_COMPILER_VAR_673.begLine = 1;
____BAH_COMPILER_VAR_673.bahType = "";
____BAH_COMPILER_VAR_673.isValue = false;
____BAH_COMPILER_VAR_673.isFunc = false;
____BAH_COMPILER_VAR_673.isOper = false;
____BAH_COMPILER_VAR_673.isEqual = false;
____BAH_COMPILER_VAR_673.pass = false;
____BAH_COMPILER_VAR_673.bahRef= null;
____BAH_COMPILER_VAR_673.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_673.cont = tmpV->name;
____BAH_COMPILER_VAR_673.line = fnt.line;
____BAH_COMPILER_VAR_673.isValue = true;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[0] = ____BAH_COMPILER_VAR_673;
memory->length = nLength+1;
} else {
memory->data[0] = ____BAH_COMPILER_VAR_673;
}
};
}
else if ((strcmp(fn->name, "breakPoint") == 0)) {
struct Tok ____BAH_COMPILER_VAR_674 = {};
____BAH_COMPILER_VAR_674.cont = "";
____BAH_COMPILER_VAR_674.ogCont = "";
____BAH_COMPILER_VAR_674.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_674.pos = 0;
____BAH_COMPILER_VAR_674.line = 1;
____BAH_COMPILER_VAR_674.begLine = 1;
____BAH_COMPILER_VAR_674.bahType = "";
____BAH_COMPILER_VAR_674.isValue = false;
____BAH_COMPILER_VAR_674.isFunc = false;
____BAH_COMPILER_VAR_674.isOper = false;
____BAH_COMPILER_VAR_674.isEqual = false;
____BAH_COMPILER_VAR_674.pass = false;
____BAH_COMPILER_VAR_674.bahRef= null;
____BAH_COMPILER_VAR_674.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_674.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_674.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_675 = {};
____BAH_COMPILER_VAR_675.cont = "";
____BAH_COMPILER_VAR_675.ogCont = "";
____BAH_COMPILER_VAR_675.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_675.pos = 0;
____BAH_COMPILER_VAR_675.line = 1;
____BAH_COMPILER_VAR_675.begLine = 1;
____BAH_COMPILER_VAR_675.bahType = "";
____BAH_COMPILER_VAR_675.isValue = false;
____BAH_COMPILER_VAR_675.isFunc = false;
____BAH_COMPILER_VAR_675.isOper = false;
____BAH_COMPILER_VAR_675.isEqual = false;
____BAH_COMPILER_VAR_675.pass = false;
____BAH_COMPILER_VAR_675.bahRef= null;
____BAH_COMPILER_VAR_675.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_675.cont = "(";
____BAH_COMPILER_VAR_675.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_676 = {};
____BAH_COMPILER_VAR_676.cont = "";
____BAH_COMPILER_VAR_676.ogCont = "";
____BAH_COMPILER_VAR_676.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_676.pos = 0;
____BAH_COMPILER_VAR_676.line = 1;
____BAH_COMPILER_VAR_676.begLine = 1;
____BAH_COMPILER_VAR_676.bahType = "";
____BAH_COMPILER_VAR_676.isValue = false;
____BAH_COMPILER_VAR_676.isFunc = false;
____BAH_COMPILER_VAR_676.isOper = false;
____BAH_COMPILER_VAR_676.isEqual = false;
____BAH_COMPILER_VAR_676.pass = false;
____BAH_COMPILER_VAR_676.bahRef= null;
____BAH_COMPILER_VAR_676.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_676.cont = ")";
____BAH_COMPILER_VAR_676.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);memory->data[0] = ____BAH_COMPILER_VAR_674;
memory->data[1] = ____BAH_COMPILER_VAR_675;
memory->data[2] = ____BAH_COMPILER_VAR_676;
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);
struct Tok ____BAH_COMPILER_VAR_677 = {};
____BAH_COMPILER_VAR_677.cont = "";
____BAH_COMPILER_VAR_677.ogCont = "";
____BAH_COMPILER_VAR_677.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_677.pos = 0;
____BAH_COMPILER_VAR_677.line = 1;
____BAH_COMPILER_VAR_677.begLine = 1;
____BAH_COMPILER_VAR_677.bahType = "";
____BAH_COMPILER_VAR_677.isValue = false;
____BAH_COMPILER_VAR_677.isFunc = false;
____BAH_COMPILER_VAR_677.isOper = false;
____BAH_COMPILER_VAR_677.isEqual = false;
____BAH_COMPILER_VAR_677.pass = false;
____BAH_COMPILER_VAR_677.bahRef= null;
____BAH_COMPILER_VAR_677.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_677.cont = ",";
____BAH_COMPILER_VAR_677.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_677;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_677;
}
};
struct Tok ____BAH_COMPILER_VAR_678 = {};
____BAH_COMPILER_VAR_678.cont = "";
____BAH_COMPILER_VAR_678.ogCont = "";
____BAH_COMPILER_VAR_678.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_678.pos = 0;
____BAH_COMPILER_VAR_678.line = 1;
____BAH_COMPILER_VAR_678.begLine = 1;
____BAH_COMPILER_VAR_678.bahType = "";
____BAH_COMPILER_VAR_678.isValue = false;
____BAH_COMPILER_VAR_678.isFunc = false;
____BAH_COMPILER_VAR_678.isOper = false;
____BAH_COMPILER_VAR_678.isEqual = false;
____BAH_COMPILER_VAR_678.pass = false;
____BAH_COMPILER_VAR_678.bahRef= null;
____BAH_COMPILER_VAR_678.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_678.cont = currLine;
____BAH_COMPILER_VAR_678.line = fnt.line;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] = ____BAH_COMPILER_VAR_678;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = ____BAH_COMPILER_VAR_678;
}
};
fn = searchFunc("breakPoint__inner",elems,true);
char * ____BAH_COMPILER_VAR_679 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_679 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_679+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_679+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_679;
}
else if ((strcmp(fn->name, "sizeof") == 0)) {
char * tp = "";
long int j = 0;
for (; (j<len(memory)); j++) {
struct Tok tmpT = memory->data[j];
char * ____BAH_COMPILER_VAR_680 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(tmpT.cont);
;                            
            ____BAH_COMPILER_VAR_680 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_680+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_680+currStrOff, tmpT.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_680;
};
struct string cType = getCType(tp,elems);
char * ____BAH_COMPILER_VAR_681 =null;char * ____BAH_COMPILER_VAR_682 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_682);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_681 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_681+currStrOff, ____BAH_COMPILER_VAR_682, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_681+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_683 =null;char * ____BAH_COMPILER_VAR_684 =____BAH_COMPILER_VAR_681;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_684);
;                            
            ____BAH_COMPILER_VAR_683 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_683+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_683+currStrOff, ____BAH_COMPILER_VAR_684, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_683;
fnt.type = TOKEN_TYPE_FUNC;
fnt.isFunc = true;
fnt.bahType = "int";
fnt.bahRef = fn;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = fnt;
l->length = nLength+1;
} else {
l->data[tokPos] = fnt;
}
};
return tokPos;
}
if ((len(memory)>0)) {
memory = prePross(memory,(lineType)-1,elems);
}
long int argIndex = 0;
if ((parent!=null)) {
char * amp = "&";
if (isRCPpointerType(parent->type)) {
amp = "";
}
char * ____BAH_COMPILER_VAR_685 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(amp);
long int strLen_1 = strlen(parent->name);
;                            
            ____BAH_COMPILER_VAR_685 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_685+currStrOff, amp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_685+currStrOff, parent->name, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_686 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_685);
;                            
            ____BAH_COMPILER_VAR_686 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_686+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_686+currStrOff, ____BAH_COMPILER_VAR_685, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_686;
argIndex++;
if ((len(fn->args)>argIndex)) {
char * ____BAH_COMPILER_VAR_687 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_687 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_687+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_687+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_687;
}
}
long int j = 0;
for (; (j<len(memory)); j++) {
struct Tok t = memory->data[j];
if ((argIndex==len(fn->args))) {
throwErr(&t,"Too many arguments, expected ')' not {TOKEN}.");
}
struct variable* arg = fn->args->data[argIndex];
char * tt = getTypeFromToken(&t,true,elems);
if ((strcmp(arg->type, "reflectElement") == 0)&&(strcmp(tt, "reflectElement") != 0)) {
t = parseReflect(t,tt,elems,false,t.cont,"0");
tt = "reflectElement";
}
if ((compTypes(arg->type,tt)==false)) {
char * ____BAH_COMPILER_VAR_688 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(arg->type);
long int strLen_1 = strlen(" in function call.");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(tt);
long int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_688 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_688+currStrOff, arg->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_688+currStrOff, " in function call.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_688);
}
if ((RCPavailable()==true)&&(ltp==LINE_TYPE_VAR)&&(t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(currSetVar!=null)&&(strcmp(t.cont, currSetVar->name) == 0)&&isRCPtype(currSetVar->type,elems)) {
OUTPUT = OUTPUT->add(OUTPUT, incrVar(currSetVar,elems));
}
if ((t.type==TOKEN_TYPE_FUNC)) {
struct func* afn = searchFuncByToken(t,elems);
if ((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true)) {
t.cont = registerRCPvar(afn->returns->type,t.cont,elems);
}
}
char * ____BAH_COMPILER_VAR_689 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_689 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_689+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_689+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_689;
argIndex++;
if ((j+1<len(memory))) {
j++;
t = memory->data[j];
if ((strcmp(t.cont, ",") != 0)) {
throwErr(&t,"Need separator between arguments, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_690 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_690 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_690+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_690+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_690;
}
};
if ((argIndex!=len(fn->args))) {
struct Tok lt = l->data[tokPos];
char * ____BAH_COMPILER_VAR_691 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("Not enough argument {TOKEN}, calling '");
;                            
            ____BAH_COMPILER_VAR_691 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_691+currStrOff, "Not enough argument {TOKEN}, calling '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_691+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_691+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&lt,____BAH_COMPILER_VAR_691);
}
fnt.bahRef = fn;
char * ____BAH_COMPILER_VAR_692 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fnt.cont);
long int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_692 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_692+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_692+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_692;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = fnt;
l->length = nLength+1;
} else {
l->data[tokPos] = fnt;
}
};
return tokPos;
};
long int valueStruct(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok t = l->data[i-1];
char * tt = getTypeFromToken(&t,true,elems);
struct cStruct* s = searchStruct(tt,elems);
if ((s==null)) {
throwErr(&t,"Cannot use {TOKEN} as structure.");
}
struct Tok nt = l->data[i+1];
if ((nt.isValue==false)) {
throwErr(&nt,"Cannot use {TOKEN} as member.");
}
deleteRange(l,i,i+1);
char * sep = ".";
if (isRCPpointerType(tt)) {
sep = "->";
}
if ((i<len(l))) {
struct Tok ntt = l->data[i];
if ((strcmp(ntt.cont, "(") == 0)) {
struct variable* parent= null;
if (((t.type==TOKEN_TYPE_VAR)==true)) {
parent = searchVar(t.cont,elems);
}
else {
char * tmpV = genCompilerVar();
struct string cType = getCType(tt,elems);
char * ____BAH_COMPILER_VAR_693 =null;char * ____BAH_COMPILER_VAR_694 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(";\n                ");
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_694);
long int strLen_6 = strlen("\n                ");
;                            
            ____BAH_COMPILER_VAR_693 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_693+currStrOff, "\n                ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_693+currStrOff, ____BAH_COMPILER_VAR_694, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_693+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_693+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_693+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_693+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_693+currStrOff, ";\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_693));
t.cont = tmpV;
struct variable* ____BAH_COMPILER_VAR_695 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_695->name = "";
____BAH_COMPILER_VAR_695->type = "";
____BAH_COMPILER_VAR_695->isConst = false;
____BAH_COMPILER_VAR_695->constVal = "";
____BAH_COMPILER_VAR_695->isArray = false;
____BAH_COMPILER_VAR_695->from = "";
____BAH_COMPILER_VAR_695->outterScope = false;
____BAH_COMPILER_VAR_695->isGlobal = false;
____BAH_COMPILER_VAR_695->name = tmpV;
____BAH_COMPILER_VAR_695->type = tt;
parent = ____BAH_COMPILER_VAR_695;
if (RCPavailable()) {

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] = parent;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] = parent;
}
};
}
}
struct func* fn = searchStructMethod(nt.cont,s,elems);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_696 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Unknown method {TOKEN} in struct ");
;                            
            ____BAH_COMPILER_VAR_696 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_696+currStrOff, "Unknown method {TOKEN} in struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_696+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_696+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_696);
}
struct func* ____BAH_COMPILER_VAR_697 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_697->name = "";
____BAH_COMPILER_VAR_697->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_697->args->length = 0;
            ____BAH_COMPILER_VAR_697->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_697->returns= null;
____BAH_COMPILER_VAR_697->isBinding = false;
____BAH_COMPILER_VAR_697->from = "";
____BAH_COMPILER_VAR_697->file = "";
____BAH_COMPILER_VAR_697->line = 1;
____BAH_COMPILER_VAR_697->used = false;
____BAH_COMPILER_VAR_697->code = null;
struct func* nfn = ____BAH_COMPILER_VAR_697;
*nfn = *fn;
nfn->name = nt.cont;
valueFunc(nfn,parent,l,i,ltp,elems);
struct Tok fnt = l->data[i];
delete(l,i);
char * ____BAH_COMPILER_VAR_698 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sep);
long int strLen_1 = strlen(fnt.cont);
long int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_698 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_698+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_698+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_698+currStrOff, fnt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_698;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = fnt;
l->length = nLength+1;
} else {
l->data[tokPos] = fnt;
}
};
return tokPos;
}
}
struct structMemb* m = searchStructMemb(nt.cont,s,elems);
if ((m==null)) {
char * ____BAH_COMPILER_VAR_699 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("Unknown struct member {TOKEN} in struct '");
;                            
            ____BAH_COMPILER_VAR_699 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, "Unknown struct member {TOKEN} in struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_699+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_699+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_699);
}
char * ____BAH_COMPILER_VAR_700 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(sep);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_700 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_700+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_700+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_701 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_700);
;                            
            ____BAH_COMPILER_VAR_701 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_701+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_701+currStrOff, ____BAH_COMPILER_VAR_700, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_701;
t.bahType = m->type;
struct variable* ____BAH_COMPILER_VAR_702 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_702->name = "";
____BAH_COMPILER_VAR_702->type = "";
____BAH_COMPILER_VAR_702->isConst = false;
____BAH_COMPILER_VAR_702->constVal = "";
____BAH_COMPILER_VAR_702->isArray = false;
____BAH_COMPILER_VAR_702->from = "";
____BAH_COMPILER_VAR_702->outterScope = false;
____BAH_COMPILER_VAR_702->isGlobal = false;
____BAH_COMPILER_VAR_702->name = t.cont;
____BAH_COMPILER_VAR_702->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_702;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = t;
l->length = nLength+1;
} else {
l->data[tokPos] = t;
}
};
return tokPos;
};
long int valueArr(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok pt = l->data[tokPos];
delete(l,tokPos);
if ((pt.isValue==false)) {
throwErr(&pt,"Cannot use {TOKEN} as value (array).");
}
char * ____BAH_COMPILER_VAR_703 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_703);
struct Tok t = pt;
t.isValue = true;
long int nbEncls = 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i = tokPos+1;
for (; (i<len(l)); i++) {
struct Tok tmpT = l->data[i];
if ((strcmp(tmpT.cont, "(") == 0)||(strcmp(tmpT.cont, "{") == 0)||(strcmp(tmpT.cont, "[") == 0)) {
nbEncls++;
}
else if ((strcmp(tmpT.cont, ")") == 0)||(strcmp(tmpT.cont, "}") == 0)||(strcmp(tmpT.cont, "]") == 0)) {
nbEncls--;
if ((nbEncls==0)) {
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
memory->data[len(memory)] = tmpT;
memory->length = nLength+1;
} else {
memory->data[len(memory)] = tmpT;
}
};
};
deleteRange(l,tokPos+1,i);
memory = prePross(memory,(lineType)-1,elems);
if ((len(memory)==0)) {
throwErr(&pt,"Cannot access empty index of array {TOKEN}.");
}
char split = false;
char * from = "";
char * to = "";
if ((len(memory)>1)) {
split = true;
struct Tok first = memory->data[0];
if ((strcmp(first.cont, ":") == 0)) {
struct Tok second = memory->data[1];
char * secondt = getTypeFromToken(&second,true,elems);
if ((compTypes(secondt,"int")==false)) {
throwErr(&second,"Cannot use {TOKEN} as index (int).");
}
from = "0";
to = second.cont;
}
else {
struct Tok second = memory->data[1];
if ((strcmp(second.cont, ":") == 0)) {
if ((len(memory)==2)) {
char * firstt = getTypeFromToken(&first,true,elems);
if ((compTypes(firstt,"int")==false)) {
throwErr(&first,"Cannot use {TOKEN} as index (int).");
}
from = first.cont;
to = "";
}
else if ((len(memory)==3)) {
char * firstt = getTypeFromToken(&first,true,elems);
if ((compTypes(firstt,"int")==false)) {
throwErr(&first,"Cannot use {TOKEN} as index (int).");
}
struct Tok third = memory->data[1];
char * thirdt = getTypeFromToken(&third,true,elems);
if ((compTypes(thirdt,"int")==false)) {
throwErr(&third,"Cannot use {TOKEN} as index (int).");
}
from = first.cont;
to = third.cont;
}
else {
throwErr(&second,"Cannot substitute by more than 2 values.");
}
}
}
}
if (ptt.hasPrefix(&ptt,"[]")) {
if ((split==false)) {
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_704 =getTypeFromToken(&index,true,elems);if ((compTypes(____BAH_COMPILER_VAR_704,"int")==false)) {
throwErr(&index,"Cannot use {TOKEN} as array index (int).");
}
char * ____BAH_COMPILER_VAR_705 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen("]");
long int strLen_2 = strlen("->data[");
long int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_705 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_705+currStrOff, "->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_705+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_705+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_705;
ptt.trimLeft(&ptt,2);
t.bahType = ptt.str(&ptt);
}
else {
t.bahType = ptt.str(&ptt);
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_706 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen("->length");
;                            
            ____BAH_COMPILER_VAR_706 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_706+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_706+currStrOff, "->length", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_706;
}
char * ____BAH_COMPILER_VAR_707 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(to);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("arraySubstitute(");
;                            
            ____BAH_COMPILER_VAR_707 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, "arraySubstitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_707+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_707+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_707+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_707;
}
}
else if (ptt.hasPrefix(&ptt,"buffer:")) {
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_708 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen("]");
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_708 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_708+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_708+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_708;
}
else {
t.bahType = "cpstring";
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_709 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_709 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_709+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_709+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_709+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_709;
}
char * ____BAH_COMPILER_VAR_710 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(to);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("cpstringSubsitute(");
;                            
            ____BAH_COMPILER_VAR_710 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_710+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_710+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_710+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_710;
}
}
else if (ptt.hasPrefix(&ptt,"map:")) {
if ((split==true)) {
throwErr(&pt,"Cannot do substitution on a map {TOKEN}.");
}
ptt.trimLeft(&ptt,4);
char * ____BAH_COMPILER_VAR_711 =ptt.str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_711,elems);
struct Tok index = memory->data[0];
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {
struct variable* ____BAH_COMPILER_VAR_712 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_712->name = "";
____BAH_COMPILER_VAR_712->type = "";
____BAH_COMPILER_VAR_712->isConst = false;
____BAH_COMPILER_VAR_712->constVal = "";
____BAH_COMPILER_VAR_712->isArray = false;
____BAH_COMPILER_VAR_712->from = "";
____BAH_COMPILER_VAR_712->outterScope = false;
____BAH_COMPILER_VAR_712->isGlobal = false;
____BAH_COMPILER_VAR_712->name = genCompilerVar();
____BAH_COMPILER_VAR_712->type = ptt.str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_712;

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
char * ____BAH_COMPILER_VAR_713 =null;char * ____BAH_COMPILER_VAR_714 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_714);
;                            
            ____BAH_COMPILER_VAR_713 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, ____BAH_COMPILER_VAR_714, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_713+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_713+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_713));
}
else {
char * ____BAH_COMPILER_VAR_715 =null;char * ____BAH_COMPILER_VAR_716 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_716);
;                            
            ____BAH_COMPILER_VAR_715 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_715+currStrOff, ____BAH_COMPILER_VAR_716, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_715+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_715+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_715+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_715));
}
char * ____BAH_COMPILER_VAR_717 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_717)) {
char * ____BAH_COMPILER_VAR_718 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV->name);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(index.cont);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("->set(");
long int strLen_7 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_718 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_718+currStrOff, t.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_718+currStrOff, "->set(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_718+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_718+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_718+currStrOff, index.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_718+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_718+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_718+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_718;
}
else {
char * ____BAH_COMPILER_VAR_719 =null;char * ____BAH_COMPILER_VAR_720 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_720);
long int strLen_1 = strlen("));\n");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen(", &");
long int strLen_5 = strlen(index.cont);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(pt.cont);
long int strLen_8 = strlen("->setAny(");
long int strLen_9 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_719 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, t.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, "->setAny(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, index.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_719+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_719+currStrOff, ____BAH_COMPILER_VAR_720, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_719+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_719;
}
t.cont = tmpV->name;
t.bahType = ptt.str(&ptt);
}
else {
t.isFunc = true;
char * ____BAH_COMPILER_VAR_721 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_721)) {
char * ____BAH_COMPILER_VAR_722 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(t.cont);
long int strLen_4 = strlen("->get(");
;                            
            ____BAH_COMPILER_VAR_722 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_722+currStrOff, "->get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_722+currStrOff, t.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_722+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_722+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_722+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_723 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_722);
;                            
            ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_723+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_723+currStrOff, ____BAH_COMPILER_VAR_722, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_723;
}
else {
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_724 =null;char * ____BAH_COMPILER_VAR_725 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("->get(");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("=");
long int strLen_7 = strlen(tmpV);
long int strLen_8 = strlen("* ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_725);
;                            
            ____BAH_COMPILER_VAR_724 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, ____BAH_COMPILER_VAR_725, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, "* ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, tmpV, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, "=", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, "->get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_724+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_724+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_724+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* res = rope(____BAH_COMPILER_VAR_724);
char * ____BAH_COMPILER_VAR_726 =null;char * ____BAH_COMPILER_VAR_727 =elemType.str(&elemType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(")(*");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_727);
long int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_726 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_726+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_726+currStrOff, ____BAH_COMPILER_VAR_727, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_726+currStrOff, ")(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_726+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_726+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_726;
if (isGlobal()) {
INIT = INIT->add(INIT, res);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, res);
}
}
t.bahType = ptt.str(&ptt);
}
}
else if ((strcmp(ptt.str(&ptt), "cpstring") == 0)) {
t.isFunc = true;
t.type = TOKEN_TYPE_FUNC;
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_728 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(index.cont);
long int strLen_1 = strlen("]");
long int strLen_2 = strlen("[");
long int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_728 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_728+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_728+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_728+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_728;
}
else {
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_729 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_729 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_729+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_729+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_729+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_729;
}
char * ____BAH_COMPILER_VAR_730 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(to);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("cpstringSubsitute(");
;                            
            ____BAH_COMPILER_VAR_730 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_730+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_730+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_730+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_730;
}
}
else {
char * ____BAH_COMPILER_VAR_731 =null;char * ____BAH_COMPILER_VAR_732 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_732);
long int strLen_1 = strlen(") as array.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_731 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_731+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_731+currStrOff, ____BAH_COMPILER_VAR_732, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_731+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_733 =____BAH_COMPILER_VAR_731;throwErr(&pt,____BAH_COMPILER_VAR_733);
}
t.isValue = true;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = t;
l->length = nLength+1;
} else {
l->data[tokPos] = t;
}
};
return tokPos;
};
long int valueBool(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int tokPos = i-2;
struct Tok pt = l->data[tokPos];
char * ptt = getTypeFromToken(&pt,true,elems);
struct Tok t = l->data[tokPos+1];
deleteRange(l,tokPos,tokPos+1);
struct Tok nt = l->data[tokPos];
char * ntt = getTypeFromToken(&nt,true,elems);
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT = string(ntt);
if ((arrT.hasPrefix(&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_734 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ntt);
long int strLen_1 = strlen(") as array.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_734 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_734+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_734+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_734+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_734);
}
arrT.trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_735 =arrT.str(&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_735)==false)) {
char * ____BAH_COMPILER_VAR_736 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ntt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") in ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen("Cannot search for {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_736 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, "Cannot search for {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, ") in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_736+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_736+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_736);
}
char * compVar = genCompilerVar();
char * comp = "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_737 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(") == 0");
long int strLen_2 = strlen("->data[i], ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->data[i] != 0 && strcmp(");
long int strLen_5 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_737 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_737+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_737+currStrOff, "->data[i] != 0 && strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_737+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_737+currStrOff, "->data[i], ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_737+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_737+currStrOff, ") == 0", strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_737;
}
else {
char * ____BAH_COMPILER_VAR_738 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("->data[i] == ");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_738 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_738+currStrOff, nt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_738+currStrOff, "->data[i] == ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_738+currStrOff, pt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_738;
}
char * ____BAH_COMPILER_VAR_739 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compVar);
long int strLen_1 = strlen("=1;\n                break;\n            };\n        }\n        ");
long int strLen_2 = strlen(") {\n                ");
long int strLen_3 = strlen(comp);
long int strLen_4 = strlen("->length-1; i!=-1;i--) {\n            if (");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(" = 0;\n        for(int i=");
long int strLen_7 = strlen(compVar);
long int strLen_8 = strlen("\n        char ");
;                            
            ____BAH_COMPILER_VAR_739 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, "\n        char ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, compVar, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, " = 0;\n        for(int i=", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, "->length-1; i!=-1;i--) {\n            if (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, comp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_739+currStrOff, ") {\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_739+currStrOff, compVar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_739+currStrOff, "=1;\n                break;\n            };\n        }\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_739));
pt.cont = compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_740 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") with type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_740 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_740+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_740+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_740+currStrOff, ") with type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_740+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_740+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_740);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_741 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(") == 0)");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_741 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_741+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_741+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_741+currStrOff, ") == 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_741;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_742 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(") != 0)");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_742 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_742+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_742+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_742+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_742+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_742+currStrOff, ") != 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_742;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_743 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") > srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_743 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_743+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_743+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_743+currStrOff, ") > srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_743+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_743+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_743;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_744 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") < srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_744 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_744+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_744+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_744+currStrOff, ") < srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_744+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_744+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_744;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_745 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") >= srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_745 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_745+currStrOff, ") >= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_745+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_745+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_745;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_746 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("))");
long int strLen_2 = strlen(") <= srtlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_746 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_746+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_746+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_746+currStrOff, ") <= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_746+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_746+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_746;
}
}
else {
char * ____BAH_COMPILER_VAR_747 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_747 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_747+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_747+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_747;
}
}
pt.isOper = true;
pt.bahType = "bool";
pt.isValue = true;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = pt;
l->length = nLength+1;
} else {
l->data[tokPos] = pt;
}
};
return tokPos;
};
long int valueOper(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int tokPos = i-2;
struct Tok pt = l->data[tokPos];
char * ptt = getTypeFromToken(&pt,true,elems);
struct Tok t = l->data[tokPos+1];
deleteRange(l,tokPos,tokPos+1);
struct Tok nt = l->data[tokPos];
if ((strcmp(nt.cont, t.cont) == 0)) {
pt.isOper = true;
char * ____BAH_COMPILER_VAR_748 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_748 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_748+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_748+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_749 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_748);
;                            
            ____BAH_COMPILER_VAR_749 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_749+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_749+currStrOff, ____BAH_COMPILER_VAR_748, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_749;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = pt;
l->length = nLength+1;
} else {
l->data[tokPos] = pt;
}
};
return tokPos;
}
char * ntt = getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_750 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_750 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_750+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_750+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_750+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_750+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_750+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_750);
}
if ((strcmp(ptt, "cpstring") == 0)) {
char * lens = "";
char * totStrLen = "1+strLen_0+strLen_1";
struct rope* cats = rope("");
char * rstr = registerRCPvar("cpstring","null",elems);
if ((pt.isFunc==true)) {
pt.cont = registerRCPvar("cpstring",pt.cont,elems);
}
char * ____BAH_COMPILER_VAR_751 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("long int strLen_0 = strlen(");
;                            
            ____BAH_COMPILER_VAR_751 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_751+currStrOff, "long int strLen_0 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_751+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_751+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_752 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lens);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_751);
;                            
            ____BAH_COMPILER_VAR_752 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_752+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_752+currStrOff, ____BAH_COMPILER_VAR_751, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_752;
char * ____BAH_COMPILER_VAR_753 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(", strLen_0);\n            currStrOff += strLen_0;\n        ");
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_753 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_753+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_753+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_753+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_753+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_753+currStrOff, ", strLen_0);\n            currStrOff += strLen_0;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = cats->add(cats, rope(____BAH_COMPILER_VAR_753));
if ((nt.isFunc==true)) {
nt.cont = registerRCPvar("cpstring",nt.cont,elems);
}
char * ____BAH_COMPILER_VAR_754 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("long int strLen_1 = strlen(");
;                            
            ____BAH_COMPILER_VAR_754 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_754+currStrOff, "long int strLen_1 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_754+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_754+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_755 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lens);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_754);
;                            
            ____BAH_COMPILER_VAR_755 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_755+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_755+currStrOff, ____BAH_COMPILER_VAR_754, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_755;
char * ____BAH_COMPILER_VAR_756 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(", strLen_1);\n            currStrOff += strLen_1;\n        ");
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_756 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_756+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_756+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_756+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, ", strLen_1);\n            currStrOff += strLen_1;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = cats->add(cats, rope(____BAH_COMPILER_VAR_756));
if ((tokPos-1>=0)) {
struct Tok nat = l->data[tokPos-1];
if ((strcmp(nat.cont, "+") == 0)) {
long int rangeEnds = tokPos-1;
i = tokPos-2;
long int nb = 2;
for (; (i>=0); i--) {
tokPos = i;
struct Tok currStrTk = l->data[i];
char * tt = getTypeFromToken(&currStrTk,true,elems);
if ((compTypes(tt,"cpstring")==false)) {
char * ____BAH_COMPILER_VAR_757 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tt);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("Cannot concatenate cpstring with {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_757 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_757+currStrOff, "Cannot concatenate cpstring with {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_757+currStrOff, tt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_757+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&currStrTk,____BAH_COMPILER_VAR_757);
}
if ((currStrTk.isFunc==true)) {
currStrTk.cont = registerRCPvar("cpstring",currStrTk.cont,elems);
}
char * is = intToStr(nb);
nb++;
char * ____BAH_COMPILER_VAR_758 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currStrTk.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(" = strlen(");
long int strLen_3 = strlen(is);
long int strLen_4 = strlen("long int strLen_");
;                            
            ____BAH_COMPILER_VAR_758 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_758+currStrOff, "long int strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_758+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_758+currStrOff, " = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, currStrTk.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_759 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lens);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_758);
;                            
            ____BAH_COMPILER_VAR_759 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_759+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_759+currStrOff, ____BAH_COMPILER_VAR_758, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_759;
char * ____BAH_COMPILER_VAR_760 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("+strLen_");
long int strLen_1 = strlen(is);
;                            
            ____BAH_COMPILER_VAR_760 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_760+currStrOff, "+strLen_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_760+currStrOff, is, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_761 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_760);
;                            
            ____BAH_COMPILER_VAR_761 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_761+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_761+currStrOff, ____BAH_COMPILER_VAR_760, strLen_1);
            currStrOff += strLen_1;
        
        }totStrLen = ____BAH_COMPILER_VAR_761;
char * ____BAH_COMPILER_VAR_762 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(is);
long int strLen_1 = strlen(";\n                    ");
long int strLen_2 = strlen(");\n                    currStrOff += strLen_");
long int strLen_3 = strlen(is);
long int strLen_4 = strlen(", strLen_");
long int strLen_5 = strlen(currStrTk.cont);
long int strLen_6 = strlen("+currStrOff, ");
long int strLen_7 = strlen(rstr);
long int strLen_8 = strlen("\n                    memcpy(");
;                            
            ____BAH_COMPILER_VAR_762 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_762+currStrOff, "\n                    memcpy(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_762+currStrOff, rstr, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_762+currStrOff, "+currStrOff, ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_762+currStrOff, currStrTk.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_762+currStrOff, ", strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_762+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_762+currStrOff, ");\n                    currStrOff += strLen_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_762+currStrOff, is, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_762+currStrOff, ";\n                    ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope(____BAH_COMPILER_VAR_762)->add(rope(____BAH_COMPILER_VAR_762), cats);
if ((i-1>=0)) {
i--;
t = l->data[i];
if ((strcmp(t.cont, "+") != 0)) {

        char ____BAH_COMPILER_VAR_763 = 0;
        for(int i=signs->length-1; i!=-1;i--) {
            if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                ____BAH_COMPILER_VAR_763=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_763) {
throwErr(&t,"Can only do concatenation on cpstring, not {TOKEN}.");
}
else {
i++;
break;
}
}
}
else {
i = 0;
break;
}
};
deleteRange(l,i,rangeEnds);
}
else if (inArrayStr(nat.cont,signs)) {
throwErr(&nat,"Can only do concatenation on cpstring, not {TOKEN}.");
}
}
char * ____BAH_COMPILER_VAR_764 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(");\n            ");
long int strLen_2 = strlen(" = memoryAllocSTR(");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen(";                            \n            ");
long int strLen_5 = strlen(lens);
long int strLen_6 = strlen("\n        {\n            long int currStrOff = 0;\n            ");
;                            
            ____BAH_COMPILER_VAR_764 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_764+currStrOff, "\n        {\n            long int currStrOff = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_764+currStrOff, lens, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_764+currStrOff, ";                            \n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_764+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_764+currStrOff, " = memoryAllocSTR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_764+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_764+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* res = rope(____BAH_COMPILER_VAR_764)->add(rope(____BAH_COMPILER_VAR_764), cats->add(cats, rope("\n        }")));
if (isGlobal()) {
INIT = INIT->add(INIT, res);
}
else {
OUTPUT = OUTPUT->add(OUTPUT, res);
}
pt.cont = rstr;
}
else {
char * sep = ".";
char * amp = "&";
if (isRCPpointerType(ptt)) {
sep = "->";
amp = "";
}
struct cStruct* s = searchStruct(ptt,elems);
if ((s!=null)) {
char * mName = "";
if ((strcmp(t.cont, "+") == 0)) {
mName = "add";
}
else if ((strcmp(t.cont, "-") == 0)) {
mName = "sub";
}
else if ((strcmp(t.cont, "*") == 0)) {
mName = "mult";
}
else if ((strcmp(t.cont, "/") == 0)) {
mName = "div";
}
else {
char * ____BAH_COMPILER_VAR_765 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("Undefined operation on struct {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_765 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_765+currStrOff, "Undefined operation on struct {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_765+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_765+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_765);
}
struct structMemb* methd = searchStructMemb(mName,s,elems);
if ((methd!=null)&&(methd->isFn==true)) {
char * ____BAH_COMPILER_VAR_766 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(amp);
long int strLen_5 = strlen("(");
long int strLen_6 = strlen(mName);
long int strLen_7 = strlen(sep);
;                            
            ____BAH_COMPILER_VAR_766 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_766+currStrOff, sep, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_766+currStrOff, mName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_766+currStrOff, "(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_766+currStrOff, amp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_766+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_766+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_766+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_766+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_767 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_766);
;                            
            ____BAH_COMPILER_VAR_767 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_767+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_767+currStrOff, ____BAH_COMPILER_VAR_766, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_767;
pt.isFunc = true;
}
}
else {
char * ____BAH_COMPILER_VAR_768 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_768 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_768+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_768+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_769 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_768);
;                            
            ____BAH_COMPILER_VAR_769 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_769+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_769+currStrOff, ____BAH_COMPILER_VAR_768, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_769;
}
}
pt.isOper = true;

{
long nLength = tokPos;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[tokPos] = pt;
l->length = nLength+1;
} else {
l->data[tokPos] = pt;
}
};
return tokPos;
};
long int valueSendChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-2;
struct Tok nt = l->data[posTok];
struct Tok pt = l->data[posTok+2];
deleteRange(l,posTok,posTok+2);
char * ntt = getTypeFromToken(&nt,true,elems);
char * ____BAH_COMPILER_VAR_770 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_770);
if ((ptt.hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_771 =null;char * ____BAH_COMPILER_VAR_772 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_772);
long int strLen_1 = strlen(") as chan.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_771 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_771+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_771+currStrOff, ____BAH_COMPILER_VAR_772, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_771+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_773 =____BAH_COMPILER_VAR_771;throwErr(&pt,____BAH_COMPILER_VAR_773);
}
ptt.trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&pt,"Cannot send to channel {TOKEN} of a function.");
}
char * ____BAH_COMPILER_VAR_774 =ptt.str(&ptt);if ((compTypes(ntt,____BAH_COMPILER_VAR_774)==false)) {
char * ____BAH_COMPILER_VAR_775 =null;char * ____BAH_COMPILER_VAR_776 =ptt.str(&ptt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_776);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(") through chan:");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_775 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_775+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_775+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_775+currStrOff, ") through chan:", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_775+currStrOff, ____BAH_COMPILER_VAR_776, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_775+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_777 =____BAH_COMPILER_VAR_775;throwErr(&nt,____BAH_COMPILER_VAR_777);
}
char * ____BAH_COMPILER_VAR_778 =ptt.str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_778)) {
char * ____BAH_COMPILER_VAR_779 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen("->send(");
long int strLen_5 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_779 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_779+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_779+currStrOff, "->send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_779+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_779+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_779+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_779+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_779));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_780 =null;char * ____BAH_COMPILER_VAR_781 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpV);
long int strLen_1 = strlen("));\n        ");
long int strLen_2 = strlen(", sizeof(");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(", &");
long int strLen_5 = strlen(pt.cont);
long int strLen_6 = strlen("->sendAny(");
long int strLen_7 = strlen(pt.cont);
long int strLen_8 = strlen(";\n        ");
long int strLen_9 = strlen(nt.cont);
long int strLen_10 = strlen(" = ");
long int strLen_11 = strlen(tmpV);
long int strLen_12 = strlen(" ");
long int strLen_13 = strlen(____BAH_COMPILER_VAR_781);
long int strLen_14 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_780 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, "\n        ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, ____BAH_COMPILER_VAR_781, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, " ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, " = ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, nt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, ";\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, "->sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_780+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_780+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_780+currStrOff, "));\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_780));
}
return posTok;
};
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-1;
delete(l,posTok);
struct Tok nt = l->data[posTok];
char * ____BAH_COMPILER_VAR_782 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_782);
if ((ntt.hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_783 =null;char * ____BAH_COMPILER_VAR_784 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_784);
long int strLen_1 = strlen(") as chan.");
long int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_783 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_783+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_783+currStrOff, ____BAH_COMPILER_VAR_784, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_783+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_785 =____BAH_COMPILER_VAR_783;throwErr(&nt,____BAH_COMPILER_VAR_785);
}
ntt.trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&nt,"Cannot receive from chan {TOKEN} outside a function body.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_786 =ntt.str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_786,elems);
char * ____BAH_COMPILER_VAR_787 =ntt.str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_787)) {
char * ____BAH_COMPILER_VAR_788 =null;char * ____BAH_COMPILER_VAR_789 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_789);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_788 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, ____BAH_COMPILER_VAR_789, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_788;
}
else {
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_790 =null;char * ____BAH_COMPILER_VAR_791 =ntt.str(&ntt);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_791);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, ____BAH_COMPILER_VAR_791, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_792 =null;char * ____BAH_COMPILER_VAR_793 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_793);
long int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_792 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, ____BAH_COMPILER_VAR_793, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_792+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_792+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_794 =____BAH_COMPILER_VAR_790;tmpV = registerRCPvar(____BAH_COMPILER_VAR_794,____BAH_COMPILER_VAR_792,elems);
char * ____BAH_COMPILER_VAR_795 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("*");
long int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_795 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_795+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_795+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_795;
}
else {
char * ____BAH_COMPILER_VAR_796 =null;char * ____BAH_COMPILER_VAR_797 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen("->receive(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("*)");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_797);
long int strLen_6 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_796 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, "*(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, ____BAH_COMPILER_VAR_797, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_796+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_796+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_796;
}
}
nt.type = TOKEN_TYPE_FUNC;
nt.isFunc = true;
nt.isValue = true;
nt.bahType = ntt.str(&ntt);

{
long nLength = posTok;
if (l->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(l->data, (nLength+50)*sizeof(struct Tok));
l->data = newPtr;
}
l->data[posTok] = nt;
l->length = nLength+1;
} else {
l->data[posTok] = nt;
}
};
return posTok;
};
char isSmallValue(__BAH_ARR_TYPE_Tok l,long int i){
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "(") == 0)) {
return false;
}
else if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value.");
}
if ((i+1<len(l))) {
struct Tok nt = l->data[i+1];
if ((strcmp(nt.cont, "[") == 0)||(strcmp(nt.cont, ".") == 0)||(strcmp(nt.cont, "(") == 0)) {
return false;
}
}
return true;
};
char isValue(__BAH_ARR_TYPE_Tok l,long int i){
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_CAST)||(strcmp(t.cont, "(") == 0)) {
return false;
}
else if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value.");
}
if ((i+1<len(l))) {
struct Tok nt = l->data[i+1];
if ((strcmp(nt.cont, "[") == 0)||(strcmp(nt.cont, ".") == 0)||(strcmp(nt.cont, "(") == 0)||inArrayStr(nt.cont,signs)) {
return false;
}
}
return true;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){
array(struct Tok)* fl = memoryAlloc(sizeof(array(struct Tok)));

fl->length = 0;
fl->elemSize = sizeof(struct Tok);
long int i = 0;
long int sepI = 0;
long int nbPar = 0;
if ((ltp!=(lineType)-1)) {
while ((i<len(line))) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "(") == 0)) {
char isFunc = true;
nbPar = nbPar+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPar = nbPar-1;
}
else if ((nbPar==0)&&(strcmp(t.cont, "{") == 0)) {
struct Tok nt = line->data[i+1];
char isStructType = true;
if ((nt.line!=t.line)) {
break;
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
i++;
};
sepI = i;
}
else {
char isStruct = true;
char isFunc = true;
char isChan = true;
char isArr = true;
char isBool = true;
char isOper = true;
char isCast = true;
char needGuard = true;
fl = line;
}
struct Tok ____BAH_COMPILER_VAR_798 = {};
____BAH_COMPILER_VAR_798.cont = "";
____BAH_COMPILER_VAR_798.ogCont = "";
____BAH_COMPILER_VAR_798.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_798.pos = 0;
____BAH_COMPILER_VAR_798.line = 1;
____BAH_COMPILER_VAR_798.begLine = 1;
____BAH_COMPILER_VAR_798.bahType = "";
____BAH_COMPILER_VAR_798.isValue = false;
____BAH_COMPILER_VAR_798.isFunc = false;
____BAH_COMPILER_VAR_798.isOper = false;
____BAH_COMPILER_VAR_798.isEqual = false;
____BAH_COMPILER_VAR_798.pass = false;
____BAH_COMPILER_VAR_798.bahRef= null;
#define pt ____BAH_COMPILER_VAR_798
long int l = len(fl);
i = 0;
for (; (i<len(fl)); i++) {
struct Tok t = fl->data[i];
if ((i>0)) {
pt = fl->data[i-1];
}
else {
struct Tok ____BAH_COMPILER_VAR_799 = {};
____BAH_COMPILER_VAR_799.cont = "";
____BAH_COMPILER_VAR_799.ogCont = "";
____BAH_COMPILER_VAR_799.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_799.pos = 0;
____BAH_COMPILER_VAR_799.line = 1;
____BAH_COMPILER_VAR_799.begLine = 1;
____BAH_COMPILER_VAR_799.bahType = "";
____BAH_COMPILER_VAR_799.isValue = false;
____BAH_COMPILER_VAR_799.isFunc = false;
____BAH_COMPILER_VAR_799.isOper = false;
____BAH_COMPILER_VAR_799.isEqual = false;
____BAH_COMPILER_VAR_799.pass = false;
____BAH_COMPILER_VAR_799.bahRef= null;
pt = ____BAH_COMPILER_VAR_799;
}
if ((strcmp(t.cont, ".") == 0)&&(i>0)) {
i = valueStruct(fl,i,ltp,elems)-1;
}
else if ((strcmp(t.cont, "(") == 0)&&(strcmp(pt.cont, "function") != 0)) {
i = valueFunc(null,null,fl,i,ltp,elems)-1;
}
else if ((strcmp(t.cont, "[") == 0)&&(pt.isValue==true)) {
i = valueArr(fl,i,ltp,elems)-1;
}
else if ((pt.type==TOKEN_TYPE_CAST)&&isSmallValue(fl,i)) {
delete(fl,i-1);
struct string ptc = string(pt.cont);
ptc.trimLeft(&ptc,1);
ptc.trimRight(&ptc,1);
t.bahType = ptc.str(&ptc);
char * ____BAH_COMPILER_VAR_800 =ptc.str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_800,elems);
char * ____BAH_COMPILER_VAR_801 =null;char * ____BAH_COMPILER_VAR_802 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(")");
long int strLen_1 = strlen(t.cont);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_802);
long int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_801 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, ____BAH_COMPILER_VAR_802, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_801+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_801+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_801;

{
long nLength = i-1;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[i-1] = t;
fl->length = nLength+1;
} else {
fl->data[i-1] = t;
}
};
i = i-2;
}
else if (inArrayStr(pt.cont,signs)) {
if ((strcmp(t.cont, pt.cont) == 0)&&(i>1)) {
struct Tok ppt = fl->data[i-2];
if ((ppt.type==TOKEN_TYPE_VAR)) {
long int posTok = i-2;
deleteRange(fl,i-1,i);
char * ____BAH_COMPILER_VAR_803 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_803 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_803+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_803+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_804 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ppt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_803);
;                            
            ____BAH_COMPILER_VAR_804 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_804+currStrOff, ppt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_804+currStrOff, ____BAH_COMPILER_VAR_803, strLen_1);
            currStrOff += strLen_1;
        
        }ppt.cont = ____BAH_COMPILER_VAR_804;
ppt.isValue = true;
ppt.isOper = true;

{
long nLength = posTok;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[posTok] = ppt;
fl->length = nLength+1;
} else {
fl->data[posTok] = ppt;
}
};
i = posTok-1;
}
else {
throwErr(&ppt,"Cannot increment/decrement non variable value {TOKEN}.");
}
}
else if (isValue(fl,i)) {
i = valueOper(fl,i,elems)-1;
}
}
else if ((t.cont[0]==45)&&(pt.isValue==true)) {
if ((t.type==TOKEN_TYPE_INT)||(t.type==TOKEN_TYPE_FLOAT)) {
delete(fl,i);
char * ptt = getTypeFromToken(&pt,true,elems);
pt.bahType = ptt;
pt.isOper = true;
char * ____BAH_COMPILER_VAR_805 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_805 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_805+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_805+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_805;

{
long nLength = i-1;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[i-1] = pt;
fl->length = nLength+1;
} else {
fl->data[i-1] = pt;
}
};
i--;
}
}
else if (inArrayStr(pt.cont,comparators)&&isValue(fl,i)) {
i = valueBool(fl,i,elems)-1;
}
else if ((strcmp(pt.cont, "<-") == 0)&&isValue(fl,i)) {
i = valueChan(fl,i,elems)-1;
}
else if ((strcmp(pt.cont, "->") == 0)&&isValue(fl,i)) {
if ((i-2>=0)) {
if (isValue(fl,i-2)) {
i = valueSendChan(fl,i,elems)-1;
}
}
else {
throwErr(&t,"Cannot {TOKEN} nothing through chan.");
}
}
};
i = 0;
for (; (i<len(fl)); i++) {
struct Tok t = fl->data[i];
if ((strcmp(t.cont, "||") == 0)||(strcmp(t.cont, "&&") == 0)) {
if ((i==0)||(i+1==len(fl))) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}
pt = fl->data[i-1];
struct Tok nt = fl->data[i+1];
char * ptt = getTypeFromToken(&pt,true,elems);
char * ntt = getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)||(compTypes(ptt,"bool")==false)) {
char * ____BAH_COMPILER_VAR_806 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ptt);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Cannot use {TOKEN} on ");
;                            
            ____BAH_COMPILER_VAR_806 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_806+currStrOff, "Cannot use {TOKEN} on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_806+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_806+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_806);
}
char * ____BAH_COMPILER_VAR_807 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_807 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_807+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_807+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_808 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_807);
;                            
            ____BAH_COMPILER_VAR_808 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_808+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_808+currStrOff, ____BAH_COMPILER_VAR_807, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_808;

{
long nLength = i-1;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[i-1] = pt;
fl->length = nLength+1;
} else {
fl->data[i-1] = pt;
}
};
deleteRange(fl,i,i+1);
i = i-2;
}
else if ((t.type==TOKEN_TYPE_VAR)&&(strcmp(t.bahType, "") != 0)) {
if ((t.cont[0]==38)) {
char * ____BAH_COMPILER_VAR_809 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t.bahType);
long int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_809 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_809+currStrOff, t.bahType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_809+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_809;

{
long nLength = i;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[i] = t;
fl->length = nLength+1;
} else {
fl->data[i] = t;
}
};
}
else if ((t.cont[0]==42)) {
struct string tt = string(t.bahType);
tt.replace(&tt,"*","");
t.bahType = tt.str(&tt);

{
long nLength = i;
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[i] = t;
fl->length = nLength+1;
} else {
fl->data[i] = t;
}
};
}
}
};
fl = parseArrayType(fl,elems,true);
if ((RCPavailable()==true)) {
addRCPvars(fl,ltp,elems);
}
if ((ltp!=(lineType)-1)) {
while ((sepI<len(line))) {

{
long nLength = len(fl);
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[len(fl)] = line->data[sepI];
fl->length = nLength+1;
} else {
fl->data[len(fl)] = line->data[sepI];
}
};
sepI++;
};
}
return fl;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i = 0;
struct func* ____BAH_COMPILER_VAR_810 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_810->name = "";
____BAH_COMPILER_VAR_810->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_810->args->length = 0;
            ____BAH_COMPILER_VAR_810->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_810->returns= null;
____BAH_COMPILER_VAR_810->isBinding = false;
____BAH_COMPILER_VAR_810->from = "";
____BAH_COMPILER_VAR_810->file = "";
____BAH_COMPILER_VAR_810->line = 1;
____BAH_COMPILER_VAR_810->used = false;
____BAH_COMPILER_VAR_810->code = null;
struct func* fn = ____BAH_COMPILER_VAR_810;
if ((RCPavailable()==false)&&(RCPenabled==true)) {
fn->used = true;
}
struct Tok ft = l->data[0];
char * code = parseFnHeader("",l,&i,fn,elems);
fn->line = ft.line;
fn->file = compilerState.currentFile;
struct func* ogFn = searchFunc(fn->name,elems,false);
if ((ogFn!=null)) {
if ((ogFn->isBinding==false)) {
char * lineStr = intToStr(ogFn->line);
char * ____BAH_COMPILER_VAR_811 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(lineStr);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(ogFn->file);
long int strLen_4 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
;                            
            ____BAH_COMPILER_VAR_811 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, ogFn->file, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_811+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_811+currStrOff, lineStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_811+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&ft,____BAH_COMPILER_VAR_811);
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
char * ____BAH_COMPILER_VAR_812 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_812 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_812+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_812+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_812));
return;
}
char * ____BAH_COMPILER_VAR_813 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(code);
long int strLen_1 = strlen("{\n");
;                            
            ____BAH_COMPILER_VAR_813 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_813+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_813+currStrOff, "{\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_813;
fn->code = rope(code);
struct Elems* fnElems = dupElems(elems);
array(struct variable*)* vs = fnElems->vars;
long int j = 0;
while ((j<len(fn->args))) {
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
i++;
long int max = len(l)-1;
while ((i<max)) {
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
i++;
};
if ((len(tokens)==0)) {
fn->code = fn->code->add(fn->code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, fn->code);
return;
}
currentFn = fn;
struct rope* oOut = OUTPUT;
OUTPUT = rope("");
struct Tok t = tokens->data[0];
beginRCPscope(fnElems,fn->args);
struct Elems* ocurrFnElems = compilerState.currFnElems;
compilerState.currFnElems = fnElems;
parseLines(tokens,fnElems);
compilerState.currFnElems = ocurrFnElems;
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_814 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("' is not returned.");
long int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_814 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_814+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_814+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_814);
}
endRCPscope(fnElems,fn->args);
}
fn->code = fn->code->add(fn->code, OUTPUT);
OUTPUT = oOut;
fn->code = fn->code->add(fn->code, rope("};\n"));
OUTPUT = OUTPUT->add(OUTPUT, fn->code);
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_815 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_815->name= null;
____BAH_COMPILER_VAR_815->returns= null;
____BAH_COMPILER_VAR_815->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_815->args->length = 0;
            ____BAH_COMPILER_VAR_815->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_815;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_816 = df;
char ** ____BAH_COMPILER_VAR_818 = (char **)((char*)(____BAH_COMPILER_VAR_816) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_819 = __reflect(____BAH_COMPILER_VAR_818, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_820 = (char **)((char*)(____BAH_COMPILER_VAR_816) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_821 = __reflect(____BAH_COMPILER_VAR_820, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_822 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_816) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_823 = 0;
char ** ____BAH_COMPILER_VAR_825 = (char **)((char*)(____BAH_COMPILER_VAR_823) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_826 = __reflect(____BAH_COMPILER_VAR_825, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_827 = (char **)((char*)(____BAH_COMPILER_VAR_823) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_828 = __reflect(____BAH_COMPILER_VAR_827, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_829 = (char*)((char*)(____BAH_COMPILER_VAR_823) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_830 = __reflect(____BAH_COMPILER_VAR_829, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_831 = (char **)((char*)(____BAH_COMPILER_VAR_823) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_832 = __reflect(____BAH_COMPILER_VAR_831, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_833 = (char*)((char*)(____BAH_COMPILER_VAR_823) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_834 = __reflect(____BAH_COMPILER_VAR_833, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_835 = (char **)((char*)(____BAH_COMPILER_VAR_823) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_836 = __reflect(____BAH_COMPILER_VAR_835, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
char* ____BAH_COMPILER_VAR_837 = (char*)((char*)(____BAH_COMPILER_VAR_823) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_838 = __reflect(____BAH_COMPILER_VAR_837, sizeof(char), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
char* ____BAH_COMPILER_VAR_839 = (char*)((char*)(____BAH_COMPILER_VAR_823) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_840 = __reflect(____BAH_COMPILER_VAR_839, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_824 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_824->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_824->length = 8;
        ____BAH_COMPILER_VAR_824->data = memoryAlloc(____BAH_COMPILER_VAR_824->length * ____BAH_COMPILER_VAR_824->elemSize);
        ____BAH_COMPILER_VAR_824->data[0] = ____BAH_COMPILER_VAR_826;
____BAH_COMPILER_VAR_824->data[1] = ____BAH_COMPILER_VAR_828;
____BAH_COMPILER_VAR_824->data[2] = ____BAH_COMPILER_VAR_830;
____BAH_COMPILER_VAR_824->data[3] = ____BAH_COMPILER_VAR_832;
____BAH_COMPILER_VAR_824->data[4] = ____BAH_COMPILER_VAR_834;
____BAH_COMPILER_VAR_824->data[5] = ____BAH_COMPILER_VAR_836;
____BAH_COMPILER_VAR_824->data[6] = ____BAH_COMPILER_VAR_838;
____BAH_COMPILER_VAR_824->data[7] = ____BAH_COMPILER_VAR_840;
struct reflectElement ____BAH_COMPILER_VAR_841 = __reflect(____BAH_COMPILER_VAR_823, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_824, 0);

        struct reflectElement ____BAH_COMPILER_VAR_842 = ____BAH_COMPILER_VAR_841;
        struct reflectElement ____BAH_COMPILER_VAR_843 = __reflect(____BAH_COMPILER_VAR_822, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_842, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_817 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_817->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_817->length = 3;
        ____BAH_COMPILER_VAR_817->data = memoryAlloc(____BAH_COMPILER_VAR_817->length * ____BAH_COMPILER_VAR_817->elemSize);
        ____BAH_COMPILER_VAR_817->data[0] = ____BAH_COMPILER_VAR_819;
____BAH_COMPILER_VAR_817->data[1] = ____BAH_COMPILER_VAR_821;
____BAH_COMPILER_VAR_817->data[2] = ____BAH_COMPILER_VAR_843;
struct reflectElement ____BAH_COMPILER_VAR_844 = __reflect(____BAH_COMPILER_VAR_816, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_817, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_844);
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
if ((ltp==LINE_TYPE_VAR)&&(len(line)>1)) {
struct Tok ft = line->data[0];
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
struct Tok ft = line->data[0];
if ((ft.isOper==false)&&(ft.isFunc==true)) {
struct func* fn = searchFuncByToken(ft,elems);
if ((fn!=null)&&(fn->returns!=null)&&isRCPtype(fn->returns->type,elems)) {
char * ____BAH_COMPILER_VAR_845 =registerRCPvar(fn->returns->type,ft.cont,elems);return;
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
char * ____BAH_COMPILER_VAR_846 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_846 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_846+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_846+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_846));
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
struct Tok ft = tokens->data[0];
long int currentLine = ft.line;
long int nbEncl = 0;
long int i = 0;
while ((i<len(tokens))) {
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
if ((t.type==TOKEN_TYPE_STR)&&(t.begLine==currentLine)) {
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
struct Tok pt = tokens->data[i-1];
currentLine = pt.line;
}
else {
currentLine = t.line;
}
parseLine(line,elems);
clear(line);
if ((t.type==TOKEN_TYPE_ENCL)) {
i++;
continue;
}
}
else if ((strcmp(t.cont, ";") == 0)) {
currentLine = t.line;
parseLine(line,elems);
clear(line);
i++;
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
i++;
};
if ((len(line)>0)) {
if ((nbEncl==0)) {
parseLine(line,elems);
clear(line);
}
else {
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
struct variable* arg = fn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_847 =null;char * ____BAH_COMPILER_VAR_848 =ct.str(&ct);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(arg->name);
long int strLen_2 = strlen(____BAH_COMPILER_VAR_848);
long int strLen_3 = strlen(tmpfnArgsCType);
;                            
            ____BAH_COMPILER_VAR_847 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, tmpfnArgsCType, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, ____BAH_COMPILER_VAR_848, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_847+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_847+currStrOff, arg->name, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_847;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_849 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_849 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_849+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_849+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_849;
}
};
char * ____BAH_COMPILER_VAR_850 =null;char * ____BAH_COMPILER_VAR_851 =tmpfnRetCType.str(&tmpfnRetCType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(");\n");
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(fn->name);
long int strLen_4 = strlen(" ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_851);
;                            
            ____BAH_COMPILER_VAR_850 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, ____BAH_COMPILER_VAR_851, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, fn->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_850+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_850+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_850));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_852 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->constVal);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_852 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_852+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_852+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_852+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_852+currStrOff, v->constVal, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_852+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_852));
}
else {
struct string cType = getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_853 =null;char * ____BAH_COMPILER_VAR_854 =cType.str(&cType);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_854);
;                            
            ____BAH_COMPILER_VAR_853 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_853+currStrOff, ____BAH_COMPILER_VAR_854, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_853+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_853+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_853+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_853));
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
for (; (i<len(compilerState.cIncludes)); i++) {
char * ____BAH_COMPILER_VAR_855 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(compilerState.cIncludes->data[i]);
long int strLen_1 = strlen("\n");
long int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_855 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_855+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_855+currStrOff, compilerState.cIncludes->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_855+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_855));
};
i = 1;
for (; (i<len(compilerState.arrTypesDecl)); i++) {
char * t = compilerState.arrTypesDecl->data[i];
struct string elemType = string(t);
elemType.trimLeft(&elemType,15);
char * ____BAH_COMPILER_VAR_856 =elemType.str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_856,elems);
char * ____BAH_COMPILER_VAR_857 =null;char * ____BAH_COMPILER_VAR_858 =elemCtype.str(&elemCtype);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(t);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen(")* ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_858);
long int strLen_4 = strlen("typedef array(");
;                            
            ____BAH_COMPILER_VAR_857 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, "typedef array(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, ____BAH_COMPILER_VAR_858, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, ")* ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_857+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_857+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_857));
};
i = 0;
for (; (i<len(elems->vars)); i++) {
struct variable* v = elems->vars->data[i];
declareVar(v,elems);
};
i = 0;
for (; (i<len(elems->fns)); i++) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
declareFunc(fn,elems);
};
};
char * memErrHandle(){
char * ____BAH_COMPILER_VAR_859 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("file: ");
long int strLen_1 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_859 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_859+currStrOff, "file: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_859+currStrOff, compilerState.currentFile, strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_859;
if ((currentFn!=null)) {
char * ____BAH_COMPILER_VAR_860 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(currentFn->name);
long int strLen_1 = strlen("()");
long int strLen_2 = strlen("\nfunction: ");
;                            
            ____BAH_COMPILER_VAR_860 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_860+currStrOff, "\nfunction: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_860+currStrOff, currentFn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_860+currStrOff, "()", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_861 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_860);
;                            
            ____BAH_COMPILER_VAR_861 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_861+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_861+currStrOff, ____BAH_COMPILER_VAR_860, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_861;
}
return r;
};
long int main(__BAH_ARR_TYPE_cpstring args){
onMemoryError = memErrHandle;
execName = args->data[0];
if ((execName[0]==46)||(execName[0]==47)) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_862 = {};
____BAH_COMPILER_VAR_862.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_862.flags->length = 0;
            ____BAH_COMPILER_VAR_862.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_862.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_862.args->length = 0;
            ____BAH_COMPILER_VAR_862.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_862.addString = flags__addString;
____BAH_COMPILER_VAR_862.addBool = flags__addBool;
____BAH_COMPILER_VAR_862.addInt = flags__addInt;
____BAH_COMPILER_VAR_862.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_862.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_862.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_862.get = flags__get;
____BAH_COMPILER_VAR_862.getInt = flags__getInt;
____BAH_COMPILER_VAR_862.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_862.isSet = flags__isSet;
____BAH_COMPILER_VAR_862.parse = flags__parse;
flags = ____BAH_COMPILER_VAR_862;
flags.addString(&flags,"o","Name of the file to output.");
flags.addBool(&flags,"c","Translate bah file to C instead of compiling it.");
flags.addBool(&flags,"v","Show version of the compiler.");
flags.addBool(&flags,"l","Compile as a library.");
flags.addBool(&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");
flags.addBool(&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");
flags.addBool(&flags,"debug","Enables verbose json output.");
flags.addBool(&flags,"verboseRuntime","Enables verbose runtime, a debug mode of the compiled program. (obsolete)");
flags.addBool(&flags,"verboseCC","Enables verbose C compiler output, USE IN LAST RESORT.");
char * ____BAH_COMPILER_VAR_863 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_OS);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
;                            
            ____BAH_COMPILER_VAR_863 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_863+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_863+currStrOff, BAH_OS, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_863+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags.addString(&flags,"target",____BAH_COMPILER_VAR_863);
char * ____BAH_COMPILER_VAR_864 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(").");
long int strLen_2 = strlen("If your Bah directory is not the default one (");
;                            
            ____BAH_COMPILER_VAR_864 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_864+currStrOff, "If your Bah directory is not the default one (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_864+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_864+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }flags.addString(&flags,"bahDir",____BAH_COMPILER_VAR_864);
char * ____BAH_COMPILER_VAR_865 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_CC);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen("To change the C compiler used, default: ");
;                            
            ____BAH_COMPILER_VAR_865 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_865+currStrOff, "To change the C compiler used, default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_865+currStrOff, BAH_CC, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_865+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags.addString(&flags,"CC",____BAH_COMPILER_VAR_865);
flags.addBool(&flags,"object","Compile as an object.");
flags.addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags.parse(&flags,args);
if ((flags.isSet(&flags,"target")==1)) {
BAH_OS = flags.get(&flags,"target");
char * ____BAH_COMPILER_VAR_866 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("Build target: ");
long int strLen_1 = strlen(BAH_OS);
;                            
            ____BAH_COMPILER_VAR_866 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_866+currStrOff, "Build target: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_866+currStrOff, BAH_OS, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_866);
}
if ((flags.isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags.get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);
if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_867 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("/");
;                            
            ____BAH_COMPILER_VAR_867 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_867+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_867+currStrOff, "/", strLen_1);
            currStrOff += strLen_1;
        
        }BAH_DIR = ____BAH_COMPILER_VAR_867;
}
char * ____BAH_COMPILER_VAR_868 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("Bah directory: ");
long int strLen_1 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_868 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_868+currStrOff, "Bah directory: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_868+currStrOff, BAH_DIR, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_868);
}
if ((flags.isSet(&flags,"CC")==1)) {
BAH_CC = flags.get(&flags,"CC");
char * ____BAH_COMPILER_VAR_869 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen("C compiler: ");
long int strLen_1 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_869 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_869+currStrOff, "C compiler: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_869+currStrOff, BAH_CC, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_869);
}
if (flags.isSet(&flags,"verboseRuntime")) {
println("-verboseRuntime is obsolete.");
exit(1);
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
RCPenabled = (flags.isSet(&flags,"rcp")==1)||flags.isSet(&flags,"fastrcp");
if ((flags.isSet(&flags,"v")==1)) {
char * ____BAH_COMPILER_VAR_870 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_VERSION);
long int strLen_1 = strlen(".\n© Alois Laurent Boe");
long int strLen_2 = strlen("Bah compiler version: ");
;                            
            ____BAH_COMPILER_VAR_870 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_870+currStrOff, "Bah compiler version: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_870+currStrOff, BAH_VERSION, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_870+currStrOff, ".\n© Alois Laurent Boe", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_870);
return 0;
}
if ((flags.isSet(&flags,"c")==1)&&(flags.isSet(&flags,"l")==1)) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:135");
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
struct compilerStateTag ____BAH_COMPILER_VAR_871 = {};
____BAH_COMPILER_VAR_871.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_871.includes->length = 0;
            ____BAH_COMPILER_VAR_871.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_871.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_871.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_871.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_871.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_871.cLibs->length = 0;
            ____BAH_COMPILER_VAR_871.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_871.currentFile= null;
____BAH_COMPILER_VAR_871.currentDir = "./";
____BAH_COMPILER_VAR_871.isBranch = false;
____BAH_COMPILER_VAR_871.isFor = false;
____BAH_COMPILER_VAR_871.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_871.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_871.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_871.haveEntryPoint = false;
____BAH_COMPILER_VAR_871.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_871.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_871.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_871.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_871.evals->length = 0;
            ____BAH_COMPILER_VAR_871.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_871.hasImports = false;
____BAH_COMPILER_VAR_871.currForElems= null;
____BAH_COMPILER_VAR_871.currFnElems= null;
compilerState = ____BAH_COMPILER_VAR_871;

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
struct fileMap ____BAH_COMPILER_VAR_872 = {};
____BAH_COMPILER_VAR_872.handle = -1;
____BAH_COMPILER_VAR_872.p= null;
____BAH_COMPILER_VAR_872.open = fileMap__open;
____BAH_COMPILER_VAR_872.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_872.close = fileMap__close;
#define fm ____BAH_COMPILER_VAR_872
char * f = fm.open(&fm,fileName);
if ((fm.isValid(&fm)==0)||(fm.size==0)) {
char * ____BAH_COMPILER_VAR_873 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen("'.");
long int strLen_2 = strlen("Could not open file '");
;                            
            ____BAH_COMPILER_VAR_873 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_873+currStrOff, "Could not open file '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_873+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_873+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_873);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f);
fm.close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_874 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen("' not recognized.");
long int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_874 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_874+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_874+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_874+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_874);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_875 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_875->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_875->vars->length = 0;
            ____BAH_COMPILER_VAR_875->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_875->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_875->structs->length = 0;
            ____BAH_COMPILER_VAR_875->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_875->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_875->types->length = 0;
            ____BAH_COMPILER_VAR_875->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_875->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_875->fns->length = 0;
            ____BAH_COMPILER_VAR_875->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_875->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_875->defined->length = 0;
            ____BAH_COMPILER_VAR_875->defined->elemSize = sizeof(char *);
            struct Elems* elems = ____BAH_COMPILER_VAR_875;
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
char * ____BAH_COMPILER_VAR_876 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("'");
long int strLen_2 = strlen("Could not find std-libs, please check '");
;                            
            ____BAH_COMPILER_VAR_876 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_876+currStrOff, "Could not find std-libs, please check '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_876+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_876+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_876,"/home/alois/Documents/bah-bah/src/main.bah:241");
}
shouldOnlyDecl = false;
if ((flags.isSet(&flags,"l")==1)) {
OUTPUT = rope("");
declareAll(elems);
}
compilerState.currentDir = getDirFromFile(fileName);
parseLines(tokens,elems);
if ((isObject==false)&&(isUnsafe==false)) {
long int l = 0;
long int i = 0;
for (; (i<len(elems->fns)); i++) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
l++;
};
char * ____BAH_COMPILER_VAR_877 =null;char * ____BAH_COMPILER_VAR_878 =intToStr(l);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_878);
long int strLen_1 = strlen("];");
long int strLen_2 = strlen("volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_877 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_877+currStrOff, "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_877+currStrOff, ____BAH_COMPILER_VAR_878, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_877+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_879 =____BAH_COMPILER_VAR_877;OUTPUT = OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_879));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); i++) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char * ____BAH_COMPILER_VAR_880 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->from);
long int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_880 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_880+currStrOff, fn->from, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_880+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }if ((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_880)) {
struct string n = string(name);
n.trimLeft(&n,strlen(fn->from)+2);
char * ____BAH_COMPILER_VAR_881 =null;char * ____BAH_COMPILER_VAR_882 =n.str(&n);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_882);
long int strLen_2 = strlen(fn->from);
;                            
            ____BAH_COMPILER_VAR_881 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_881+currStrOff, fn->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_881+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_881+currStrOff, ____BAH_COMPILER_VAR_882, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_881;
}
char * ____BAH_COMPILER_VAR_883 =null;char * ____BAH_COMPILER_VAR_884 =intToStr(j);char * ____BAH_COMPILER_VAR_885 =intToStr(j);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen(";\n");
long int strLen_2 = strlen("].p = ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_884);
long int strLen_4 = strlen("\";\n            __tmp____Bah_fnNames[");
long int strLen_5 = strlen(name);
long int strLen_6 = strlen("].n = \"");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_885);
long int strLen_8 = strlen("\n            __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_883 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_883+currStrOff, "\n            __tmp____Bah_fnNames[", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_883+currStrOff, ____BAH_COMPILER_VAR_885, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_883+currStrOff, "].n = \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_883+currStrOff, name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_883+currStrOff, "\";\n            __tmp____Bah_fnNames[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_883+currStrOff, ____BAH_COMPILER_VAR_884, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_883+currStrOff, "].p = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_883+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_883+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_883));
j++;
};
char * ____BAH_COMPILER_VAR_886 =null;char * ____BAH_COMPILER_VAR_887 =intToStr(l);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_887);
long int strLen_1 = strlen(";");
long int strLen_2 = strlen("\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ");
;                            
            ____BAH_COMPILER_VAR_886 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_886+currStrOff, "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_886+currStrOff, ____BAH_COMPILER_VAR_887, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_886+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_888 =____BAH_COMPILER_VAR_886;INIT = INIT->add(INIT, rope(____BAH_COMPILER_VAR_888));
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
char * ____BAH_COMPILER_VAR_889 =null;char * ____BAH_COMPILER_VAR_890 =intToStr(totalLexerTime/1000000);char * ____BAH_COMPILER_VAR_891 =intToStr(totalTime/1000000);char * ____BAH_COMPILER_VAR_892 =intToStr(totalLines);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_890);
long int strLen_1 = strlen("ms)\e[0m");
long int strLen_2 = strlen("ms, lexer time: ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_891);
long int strLen_4 = strlen(" lines, total time: ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_892);
long int strLen_6 = strlen("Parsed. (");
;                            
            ____BAH_COMPILER_VAR_889 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_889+currStrOff, "Parsed. (", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_889+currStrOff, ____BAH_COMPILER_VAR_892, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_889+currStrOff, " lines, total time: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_889+currStrOff, ____BAH_COMPILER_VAR_891, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_889+currStrOff, "ms, lexer time: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_889+currStrOff, ____BAH_COMPILER_VAR_890, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_889+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_893 =____BAH_COMPILER_VAR_889;println(____BAH_COMPILER_VAR_893);
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
if ((flags.isSet(&flags,"d")==1)||(strcmp(BAH_OS, "darwin") == 0)) {
isStatic = "";
}
if ((flags.isSet(&flags,"c")==0)) {
char * obj = "";
if ((flags.isSet(&flags,"object")==1)) {
char * ____BAH_COMPILER_VAR_894 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".o");
;                            
            ____BAH_COMPILER_VAR_894 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_894+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_894+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_894;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char * ____BAH_COMPILER_VAR_895 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" -w -O1 -o ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(obj);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(isStatic);
long int strLen_5 = strlen(" ");
long int strLen_6 = strlen(randFileName);
long int strLen_7 = strlen("/\" ");
long int strLen_8 = strlen(BAH_OS);
long int strLen_9 = strlen("libs/");
long int strLen_10 = strlen(BAH_DIR);
long int strLen_11 = strlen("/include/\" -L \"");
long int strLen_12 = strlen(BAH_OS);
long int strLen_13 = strlen("libs/");
long int strLen_14 = strlen(BAH_DIR);
long int strLen_15 = strlen(" -I \"");
long int strLen_16 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_895 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, BAH_CC, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, " -I \"", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, BAH_DIR, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, "libs/", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, BAH_OS, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, "/include/\" -L \"", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, BAH_DIR, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, "libs/", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, "/\" ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, randFileName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, isStatic, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_895+currStrOff, obj, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_895+currStrOff, " -w -O1 -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_895+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_895;
if ((flags.isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_896 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -c");
;                            
            ____BAH_COMPILER_VAR_896 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_896+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_896+currStrOff, " -c", strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_896;
}
array(char *)* cLibs = compilerState.cLibs;
long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_897 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" -");
long int strLen_1 = strlen(l);
long int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_897 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_897+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_897+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_897+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_897;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = OUTPUT->toStr(OUTPUT);
if ((flags.isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_898 =cmd.run(&cmd);println(____BAH_COMPILER_VAR_898);
}
else {
char * ____BAH_COMPILER_VAR_899 =cmd.run(&cmd);}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags.isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_900 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(".a ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(fileName);
long int strLen_3 = strlen("ar rcs ");
;                            
            ____BAH_COMPILER_VAR_900 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_900+currStrOff, "ar rcs ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_900+currStrOff, fileName, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_900+currStrOff, ".a ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_900+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }cmd = command(____BAH_COMPILER_VAR_900);
char * ____BAH_COMPILER_VAR_901 =cmd.run(&cmd);}
}
else {
if ((flags.isSet(&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_902 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".c");
;                            
            ____BAH_COMPILER_VAR_902 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_902+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_902+currStrOff, ".c", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_902;
}
char * ____BAH_COMPILER_VAR_903 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(isStatic);
long int strLen_1 = strlen(" -O1 -w ");
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(fileName);
long int strLen_4 = strlen("/\" ");
long int strLen_5 = strlen(BAH_OS);
long int strLen_6 = strlen("libs/");
long int strLen_7 = strlen(BAH_DIR);
long int strLen_8 = strlen("/include/\" -L \"");
long int strLen_9 = strlen(BAH_OS);
long int strLen_10 = strlen("libs/");
long int strLen_11 = strlen(BAH_DIR);
long int strLen_12 = strlen(" -I \"");
long int strLen_13 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_903 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13);
            
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, BAH_CC, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, " -I \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, BAH_DIR, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, "libs/", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, BAH_OS, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, "/include/\" -L \"", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, BAH_DIR, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, "libs/", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, BAH_OS, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, "/\" ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, fileName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_903+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_903+currStrOff, isStatic, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_903+currStrOff, " -O1 -w ", strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_903;
array(char *)* cLibs = compilerState.cLibs;
long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_904 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(" -");
long int strLen_1 = strlen(l);
long int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_904 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_904+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_904+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_904+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_904;
i = i+1;
};
char * ____BAH_COMPILER_VAR_905 =null;
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen("'\n");
long int strLen_2 = strlen("//COMPILE WITH: '");
;                            
            ____BAH_COMPILER_VAR_905 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_905+currStrOff, "//COMPILE WITH: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_905+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_905+currStrOff, "'\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope(____BAH_COMPILER_VAR_905)->add(rope(____BAH_COMPILER_VAR_905), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_906 = {};
____BAH_COMPILER_VAR_906.handle= null;
____BAH_COMPILER_VAR_906.name= null;
____BAH_COMPILER_VAR_906.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_906.open = fileStream__open;
____BAH_COMPILER_VAR_906.close = fileStream__close;
____BAH_COMPILER_VAR_906.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_906.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_906.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_906.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_906.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_906.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_906.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_906.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_906.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_906.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_906.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_906.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_906.writeBytes = fileStream__writeBytes;
____BAH_COMPILER_VAR_906._end = fileStream___end;
#define fs ____BAH_COMPILER_VAR_906
fs.open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_907 =OUTPUT->toStr(OUTPUT);fs.writeFile(&fs,____BAH_COMPILER_VAR_907);
fs.close(&fs);

#undef fs
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char * ____BAH_COMPILER_VAR_908 =null;char * ____BAH_COMPILER_VAR_909 =intToStr(totalTime/1000000);
        {
            long int currStrOff = 0;
            long int strLen_0 = strlen(____BAH_COMPILER_VAR_909);
long int strLen_1 = strlen("ms)\e[0m");
long int strLen_2 = strlen("\e[1;32mDone. (compiled in ");
;                            
            ____BAH_COMPILER_VAR_908 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_908+currStrOff, "\e[1;32mDone. (compiled in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_908+currStrOff, ____BAH_COMPILER_VAR_909, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_908+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_910 =____BAH_COMPILER_VAR_908;println(____BAH_COMPILER_VAR_910);
}
return 0;
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[293];
    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan = null;
__Bah_fnNames = memoryAlloc(sizeof(array(struct __Bah_fnName_mapper)));

__Bah_fnNames->length = 0;
__Bah_fnNames->elemSize = sizeof(struct __Bah_fnName_mapper);
onMemoryError = null;
__Bah_init_segfaultHandle_OK = __Bah_init_segfaultHandle();
RAND_SEEDED = 0;
BAH_DIR = "/opt/bah/";
BAH_OS = "darwin";
BAH_CC = "clang";
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

intTypes->length = 5;
intTypes->elemSize = sizeof(char *);
intTypes->data = memoryAlloc(sizeof(char *) * 50);intTypes->data[0] = "int";
intTypes->data[1] = "int32";
intTypes->data[2] = "uint";
intTypes->data[3] = "uint32";
intTypes->data[4] = "bool";
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

signs->length = 9;
signs->elemSize = sizeof(char *);
signs->data = memoryAlloc(sizeof(char *) * 50);signs->data[0] = "|";
signs->data[1] = "&";
signs->data[2] = "%";
signs->data[3] = "+";
signs->data[4] = "-";
signs->data[5] = "*";
signs->data[6] = "/";
signs->data[7] = "<<";
signs->data[8] = ">>";
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

            __tmp____Bah_fnNames[20].n = "deleteRange";
            __tmp____Bah_fnNames[20].p = deleteRange;

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

            __tmp____Bah_fnNames[99].n = "strCatOffset";
            __tmp____Bah_fnNames[99].p = strCatOffset;

            __tmp____Bah_fnNames[100].n = "charToString";
            __tmp____Bah_fnNames[100].p = charToString;

            __tmp____Bah_fnNames[101].n = "isUpper";
            __tmp____Bah_fnNames[101].p = isUpper;

            __tmp____Bah_fnNames[102].n = "isLower";
            __tmp____Bah_fnNames[102].p = isLower;

            __tmp____Bah_fnNames[103].n = "isLetter";
            __tmp____Bah_fnNames[103].p = isLetter;

            __tmp____Bah_fnNames[104].n = "isNumber";
            __tmp____Bah_fnNames[104].p = isNumber;

            __tmp____Bah_fnNames[105].n = "isAlphaNumeric";
            __tmp____Bah_fnNames[105].p = isAlphaNumeric;

            __tmp____Bah_fnNames[106].n = "isSpace";
            __tmp____Bah_fnNames[106].p = isSpace;

            __tmp____Bah_fnNames[107].n = "string.set";
            __tmp____Bah_fnNames[107].p = string__set;

            __tmp____Bah_fnNames[108].n = "string.makeEditable";
            __tmp____Bah_fnNames[108].p = string__makeEditable;

            __tmp____Bah_fnNames[109].n = "string.append";
            __tmp____Bah_fnNames[109].p = string__append;

            __tmp____Bah_fnNames[110].n = "string.prepend";
            __tmp____Bah_fnNames[110].p = string__prepend;

            __tmp____Bah_fnNames[111].n = "string.charAt";
            __tmp____Bah_fnNames[111].p = string__charAt;

            __tmp____Bah_fnNames[112].n = "string.compare";
            __tmp____Bah_fnNames[112].p = string__compare;

            __tmp____Bah_fnNames[113].n = "string.str";
            __tmp____Bah_fnNames[113].p = string__str;

            __tmp____Bah_fnNames[114].n = "string.replace";
            __tmp____Bah_fnNames[114].p = string__replace;

            __tmp____Bah_fnNames[115].n = "string.countChar";
            __tmp____Bah_fnNames[115].p = string__countChar;

            __tmp____Bah_fnNames[116].n = "string.count";
            __tmp____Bah_fnNames[116].p = string__count;

            __tmp____Bah_fnNames[117].n = "string.hasPrefix";
            __tmp____Bah_fnNames[117].p = string__hasPrefix;

            __tmp____Bah_fnNames[118].n = "string.hasSuffix";
            __tmp____Bah_fnNames[118].p = string__hasSuffix;

            __tmp____Bah_fnNames[119].n = "string.trim";
            __tmp____Bah_fnNames[119].p = string__trim;

            __tmp____Bah_fnNames[120].n = "string.trimLeft";
            __tmp____Bah_fnNames[120].p = string__trimLeft;

            __tmp____Bah_fnNames[121].n = "string.trimRight";
            __tmp____Bah_fnNames[121].p = string__trimRight;

            __tmp____Bah_fnNames[122].n = "string.add";
            __tmp____Bah_fnNames[122].p = string__add;

            __tmp____Bah_fnNames[123].n = "string";
            __tmp____Bah_fnNames[123].p = string;

            __tmp____Bah_fnNames[124].n = "intToStr";
            __tmp____Bah_fnNames[124].p = intToStr;

            __tmp____Bah_fnNames[125].n = "intToString";
            __tmp____Bah_fnNames[125].p = intToString;

            __tmp____Bah_fnNames[126].n = "floatToStr";
            __tmp____Bah_fnNames[126].p = floatToStr;

            __tmp____Bah_fnNames[127].n = "strToInt";
            __tmp____Bah_fnNames[127].p = strToInt;

            __tmp____Bah_fnNames[128].n = "strToFloat";
            __tmp____Bah_fnNames[128].p = strToFloat;

            __tmp____Bah_fnNames[129].n = "stringToInt";
            __tmp____Bah_fnNames[129].p = stringToInt;

            __tmp____Bah_fnNames[130].n = "splitString";
            __tmp____Bah_fnNames[130].p = splitString;

            __tmp____Bah_fnNames[131].n = "joinString";
            __tmp____Bah_fnNames[131].p = joinString;

            __tmp____Bah_fnNames[132].n = "splitStringBefore";
            __tmp____Bah_fnNames[132].p = splitStringBefore;

            __tmp____Bah_fnNames[133].n = "toLower";
            __tmp____Bah_fnNames[133].p = toLower;

            __tmp____Bah_fnNames[134].n = "strHasPrefix";
            __tmp____Bah_fnNames[134].p = strHasPrefix;

            __tmp____Bah_fnNames[135].n = "strHasSuffix";
            __tmp____Bah_fnNames[135].p = strHasSuffix;

            __tmp____Bah_fnNames[136].n = "strTrim";
            __tmp____Bah_fnNames[136].p = strTrim;

            __tmp____Bah_fnNames[137].n = "strCount";
            __tmp____Bah_fnNames[137].p = strCount;

            __tmp____Bah_fnNames[138].n = "flags.addString";
            __tmp____Bah_fnNames[138].p = flags__addString;

            __tmp____Bah_fnNames[139].n = "flags.addBool";
            __tmp____Bah_fnNames[139].p = flags__addBool;

            __tmp____Bah_fnNames[140].n = "flags.addInt";
            __tmp____Bah_fnNames[140].p = flags__addInt;

            __tmp____Bah_fnNames[141].n = "flags.addFloat";
            __tmp____Bah_fnNames[141].p = flags__addFloat;

            __tmp____Bah_fnNames[142].n = "flags.invalidate";
            __tmp____Bah_fnNames[142].p = flags__invalidate;

            __tmp____Bah_fnNames[143].n = "flags.getFlag";
            __tmp____Bah_fnNames[143].p = flags__getFlag;

            __tmp____Bah_fnNames[144].n = "flags.get";
            __tmp____Bah_fnNames[144].p = flags__get;

            __tmp____Bah_fnNames[145].n = "flags.getInt";
            __tmp____Bah_fnNames[145].p = flags__getInt;

            __tmp____Bah_fnNames[146].n = "flags.getFloat";
            __tmp____Bah_fnNames[146].p = flags__getFloat;

            __tmp____Bah_fnNames[147].n = "flags.isSet";
            __tmp____Bah_fnNames[147].p = flags__isSet;

            __tmp____Bah_fnNames[148].n = "flags.parse";
            __tmp____Bah_fnNames[148].p = flags__parse;

            __tmp____Bah_fnNames[149].n = "time.now";
            __tmp____Bah_fnNames[149].p = time__now;

            __tmp____Bah_fnNames[150].n = "time.format";
            __tmp____Bah_fnNames[150].p = time__format;

            __tmp____Bah_fnNames[151].n = "time.since";
            __tmp____Bah_fnNames[151].p = time__since;

            __tmp____Bah_fnNames[152].n = "getTimeUnix";
            __tmp____Bah_fnNames[152].p = getTimeUnix;

            __tmp____Bah_fnNames[153].n = "seedRandom";
            __tmp____Bah_fnNames[153].p = seedRandom;

            __tmp____Bah_fnNames[154].n = "randomInRange";
            __tmp____Bah_fnNames[154].p = randomInRange;

            __tmp____Bah_fnNames[155].n = "cryptoRand";
            __tmp____Bah_fnNames[155].p = cryptoRand;

            __tmp____Bah_fnNames[156].n = "rope.addStr";
            __tmp____Bah_fnNames[156].p = rope__addStr;

            __tmp____Bah_fnNames[157].n = "rope.toStr";
            __tmp____Bah_fnNames[157].p = rope__toStr;

            __tmp____Bah_fnNames[158].n = "rope.add";
            __tmp____Bah_fnNames[158].p = rope__add;

            __tmp____Bah_fnNames[159].n = "createRopeStructure";
            __tmp____Bah_fnNames[159].p = createRopeStructure;

            __tmp____Bah_fnNames[160].n = "ropeSet";
            __tmp____Bah_fnNames[160].p = ropeSet;

            __tmp____Bah_fnNames[161].n = "concatenateRopes";
            __tmp____Bah_fnNames[161].p = concatenateRopes;

            __tmp____Bah_fnNames[162].n = "rope";
            __tmp____Bah_fnNames[162].p = rope;

            __tmp____Bah_fnNames[163].n = "command.run";
            __tmp____Bah_fnNames[163].p = command__run;

            __tmp____Bah_fnNames[164].n = "command.runBytes";
            __tmp____Bah_fnNames[164].p = command__runBytes;

            __tmp____Bah_fnNames[165].n = "command";
            __tmp____Bah_fnNames[165].p = command;

            __tmp____Bah_fnNames[166].n = "exec";
            __tmp____Bah_fnNames[166].p = exec;

            __tmp____Bah_fnNames[167].n = "inArray";
            __tmp____Bah_fnNames[167].p = inArray;

            __tmp____Bah_fnNames[168].n = "inArrayStr";
            __tmp____Bah_fnNames[168].p = inArrayStr;

            __tmp____Bah_fnNames[169].n = "makeToken";
            __tmp____Bah_fnNames[169].p = makeToken;

            __tmp____Bah_fnNames[170].n = "isMinus";
            __tmp____Bah_fnNames[170].p = isMinus;

            __tmp____Bah_fnNames[171].n = "lexerErr";
            __tmp____Bah_fnNames[171].p = lexerErr;

            __tmp____Bah_fnNames[172].n = "lexer";
            __tmp____Bah_fnNames[172].p = lexer;

            __tmp____Bah_fnNames[173].n = "hasStructSep";
            __tmp____Bah_fnNames[173].p = hasStructSep;

            __tmp____Bah_fnNames[174].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[174].p = splitStructSepBefore;

            __tmp____Bah_fnNames[175].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[175].p = splitStructSepAfter;

            __tmp____Bah_fnNames[176].n = "searchStruct";
            __tmp____Bah_fnNames[176].p = searchStruct;

            __tmp____Bah_fnNames[177].n = "searchStructMemb";
            __tmp____Bah_fnNames[177].p = searchStructMemb;

            __tmp____Bah_fnNames[178].n = "searchFunc";
            __tmp____Bah_fnNames[178].p = searchFunc;

            __tmp____Bah_fnNames[179].n = "parseFnType";
            __tmp____Bah_fnNames[179].p = parseFnType;

            __tmp____Bah_fnNames[180].n = "searchStructMethod";
            __tmp____Bah_fnNames[180].p = searchStructMethod;

            __tmp____Bah_fnNames[181].n = "typeAsStar";
            __tmp____Bah_fnNames[181].p = typeAsStar;

            __tmp____Bah_fnNames[182].n = "isRCPpointerType";
            __tmp____Bah_fnNames[182].p = isRCPpointerType;

            __tmp____Bah_fnNames[183].n = "isRCPtype";
            __tmp____Bah_fnNames[183].p = isRCPtype;

            __tmp____Bah_fnNames[184].n = "getCType";
            __tmp____Bah_fnNames[184].p = getCType;

            __tmp____Bah_fnNames[185].n = "compTypeEquiv";
            __tmp____Bah_fnNames[185].p = compTypeEquiv;

            __tmp____Bah_fnNames[186].n = "compTypes";
            __tmp____Bah_fnNames[186].p = compTypes;

            __tmp____Bah_fnNames[187].n = "reflectElement.calculateOffset";
            __tmp____Bah_fnNames[187].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[188].n = "__reflect";
            __tmp____Bah_fnNames[188].p = __reflect;

            __tmp____Bah_fnNames[189].n = "__dumpSymbols";
            __tmp____Bah_fnNames[189].p = __dumpSymbols;

            __tmp____Bah_fnNames[190].n = "__debug_get_sym";
            __tmp____Bah_fnNames[190].p = __debug_get_sym;

            __tmp____Bah_fnNames[191].n = "toJson";
            __tmp____Bah_fnNames[191].p = toJson;

            __tmp____Bah_fnNames[192].n = "json_scan_inner";
            __tmp____Bah_fnNames[192].p = json_scan_inner;

            __tmp____Bah_fnNames[193].n = "jsonElement.get";
            __tmp____Bah_fnNames[193].p = jsonElement__get;

            __tmp____Bah_fnNames[194].n = "jsonElement.str";
            __tmp____Bah_fnNames[194].p = jsonElement__str;

            __tmp____Bah_fnNames[195].n = "jsonElement.scan";
            __tmp____Bah_fnNames[195].p = jsonElement__scan;

            __tmp____Bah_fnNames[196].n = "parseJson";
            __tmp____Bah_fnNames[196].p = parseJson;

            __tmp____Bah_fnNames[197].n = "jsonEscapeStr";
            __tmp____Bah_fnNames[197].p = jsonEscapeStr;

            __tmp____Bah_fnNames[198].n = "toJson__inner";
            __tmp____Bah_fnNames[198].p = toJson__inner;

            __tmp____Bah_fnNames[199].n = "debugStart";
            __tmp____Bah_fnNames[199].p = debugStart;

            __tmp____Bah_fnNames[200].n = "debugPrint";
            __tmp____Bah_fnNames[200].p = debugPrint;

            __tmp____Bah_fnNames[201].n = "debugError";
            __tmp____Bah_fnNames[201].p = debugError;

            __tmp____Bah_fnNames[202].n = "debugEnd";
            __tmp____Bah_fnNames[202].p = debugEnd;

            __tmp____Bah_fnNames[203].n = "debugExit";
            __tmp____Bah_fnNames[203].p = debugExit;

            __tmp____Bah_fnNames[204].n = "debugEndScope";
            __tmp____Bah_fnNames[204].p = debugEndScope;

            __tmp____Bah_fnNames[205].n = "throwErr";
            __tmp____Bah_fnNames[205].p = throwErr;

            __tmp____Bah_fnNames[206].n = "throwWarning";
            __tmp____Bah_fnNames[206].p = throwWarning;

            __tmp____Bah_fnNames[207].n = "absPath";
            __tmp____Bah_fnNames[207].p = absPath;

            __tmp____Bah_fnNames[208].n = "getCurrentPath";
            __tmp____Bah_fnNames[208].p = getCurrentPath;

            __tmp____Bah_fnNames[209].n = "isInside";
            __tmp____Bah_fnNames[209].p = isInside;

            __tmp____Bah_fnNames[210].n = "setCurrentPath";
            __tmp____Bah_fnNames[210].p = setCurrentPath;

            __tmp____Bah_fnNames[211].n = "isGlobal";
            __tmp____Bah_fnNames[211].p = isGlobal;

            __tmp____Bah_fnNames[212].n = "searchVar";
            __tmp____Bah_fnNames[212].p = searchVar;

            __tmp____Bah_fnNames[213].n = "searchVarByToken";
            __tmp____Bah_fnNames[213].p = searchVarByToken;

            __tmp____Bah_fnNames[214].n = "setCType";
            __tmp____Bah_fnNames[214].p = setCType;

            __tmp____Bah_fnNames[215].n = "getTypeFromToken";
            __tmp____Bah_fnNames[215].p = getTypeFromToken;

            __tmp____Bah_fnNames[216].n = "searchFuncByToken";
            __tmp____Bah_fnNames[216].p = searchFuncByToken;

            __tmp____Bah_fnNames[217].n = "RCPavailable";
            __tmp____Bah_fnNames[217].p = RCPavailable;

            __tmp____Bah_fnNames[218].n = "declareStructMethods";
            __tmp____Bah_fnNames[218].p = declareStructMethods;

            __tmp____Bah_fnNames[219].n = "genCompilerVar";
            __tmp____Bah_fnNames[219].p = genCompilerVar;

            __tmp____Bah_fnNames[220].n = "varInArr";
            __tmp____Bah_fnNames[220].p = varInArr;

            __tmp____Bah_fnNames[221].n = "pathToVarName";
            __tmp____Bah_fnNames[221].p = pathToVarName;

            __tmp____Bah_fnNames[222].n = "makeInit";
            __tmp____Bah_fnNames[222].p = makeInit;

            __tmp____Bah_fnNames[223].n = "decrVar";
            __tmp____Bah_fnNames[223].p = decrVar;

            __tmp____Bah_fnNames[224].n = "incrVar";
            __tmp____Bah_fnNames[224].p = incrVar;

            __tmp____Bah_fnNames[225].n = "beginRCPscope";
            __tmp____Bah_fnNames[225].p = beginRCPscope;

            __tmp____Bah_fnNames[226].n = "beginRCPscopeLeaky";
            __tmp____Bah_fnNames[226].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[227].n = "removeDefs";
            __tmp____Bah_fnNames[227].p = removeDefs;

            __tmp____Bah_fnNames[228].n = "endRCPscope";
            __tmp____Bah_fnNames[228].p = endRCPscope;

            __tmp____Bah_fnNames[229].n = "endRCPscopeLeaky";
            __tmp____Bah_fnNames[229].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[230].n = "registerRCPvar";
            __tmp____Bah_fnNames[230].p = registerRCPvar;

            __tmp____Bah_fnNames[231].n = "RCPselfRef";
            __tmp____Bah_fnNames[231].p = RCPselfRef;

            __tmp____Bah_fnNames[232].n = "verboseOutGuard";
            __tmp____Bah_fnNames[232].p = verboseOutGuard;

            __tmp____Bah_fnNames[233].n = "verboseOutTransformVar";
            __tmp____Bah_fnNames[233].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[234].n = "verboseOutTransformTok";
            __tmp____Bah_fnNames[234].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[235].n = "verboseOutFunc";
            __tmp____Bah_fnNames[235].p = verboseOutFunc;

            __tmp____Bah_fnNames[236].n = "verboseOutOper";
            __tmp____Bah_fnNames[236].p = verboseOutOper;

            __tmp____Bah_fnNames[237].n = "readCache";
            __tmp____Bah_fnNames[237].p = readCache;

            __tmp____Bah_fnNames[238].n = "getCacheFile";
            __tmp____Bah_fnNames[238].p = getCacheFile;

            __tmp____Bah_fnNames[239].n = "updateCacheFile";
            __tmp____Bah_fnNames[239].p = updateCacheFile;

            __tmp____Bah_fnNames[240].n = "makeCacheFile";
            __tmp____Bah_fnNames[240].p = makeCacheFile;

            __tmp____Bah_fnNames[241].n = "writeCache";
            __tmp____Bah_fnNames[241].p = writeCache;

            __tmp____Bah_fnNames[242].n = "isValidCacheFile";
            __tmp____Bah_fnNames[242].p = isValidCacheFile;

            __tmp____Bah_fnNames[243].n = "debugLine";
            __tmp____Bah_fnNames[243].p = debugLine;

            __tmp____Bah_fnNames[244].n = "dupElems";
            __tmp____Bah_fnNames[244].p = dupElems;

            __tmp____Bah_fnNames[245].n = "getLineType";
            __tmp____Bah_fnNames[245].p = getLineType;

            __tmp____Bah_fnNames[246].n = "parseCast";
            __tmp____Bah_fnNames[246].p = parseCast;

            __tmp____Bah_fnNames[247].n = "getDirFromFile";
            __tmp____Bah_fnNames[247].p = getDirFromFile;

            __tmp____Bah_fnNames[248].n = "parseLines";
            __tmp____Bah_fnNames[248].p = parseLines;

            __tmp____Bah_fnNames[249].n = "includeFile";
            __tmp____Bah_fnNames[249].p = includeFile;

            __tmp____Bah_fnNames[250].n = "parallelObjCompile";
            __tmp____Bah_fnNames[250].p = parallelObjCompile;

            __tmp____Bah_fnNames[251].n = "parseImport";
            __tmp____Bah_fnNames[251].p = parseImport;

            __tmp____Bah_fnNames[252].n = "parseInclude";
            __tmp____Bah_fnNames[252].p = parseInclude;

            __tmp____Bah_fnNames[253].n = "prePross";
            __tmp____Bah_fnNames[253].p = prePross;

            __tmp____Bah_fnNames[254].n = "parseStructType";
            __tmp____Bah_fnNames[254].p = parseStructType;

            __tmp____Bah_fnNames[255].n = "parseArrayType";
            __tmp____Bah_fnNames[255].p = parseArrayType;

            __tmp____Bah_fnNames[256].n = "parsePointers";
            __tmp____Bah_fnNames[256].p = parsePointers;

            __tmp____Bah_fnNames[257].n = "parseSerialize";
            __tmp____Bah_fnNames[257].p = parseSerialize;

            __tmp____Bah_fnNames[258].n = "parseReflect";
            __tmp____Bah_fnNames[258].p = parseReflect;

            __tmp____Bah_fnNames[259].n = "parseArrayDecl";
            __tmp____Bah_fnNames[259].p = parseArrayDecl;

            __tmp____Bah_fnNames[260].n = "parseVar";
            __tmp____Bah_fnNames[260].p = parseVar;

            __tmp____Bah_fnNames[261].n = "getCfunctionType";
            __tmp____Bah_fnNames[261].p = getCfunctionType;

            __tmp____Bah_fnNames[262].n = "parseFnHeader";
            __tmp____Bah_fnNames[262].p = parseFnHeader;

            __tmp____Bah_fnNames[263].n = "parseStruct";
            __tmp____Bah_fnNames[263].p = parseStruct;

            __tmp____Bah_fnNames[264].n = "parseDefine";
            __tmp____Bah_fnNames[264].p = parseDefine;

            __tmp____Bah_fnNames[265].n = "parseClib";
            __tmp____Bah_fnNames[265].p = parseClib;

            __tmp____Bah_fnNames[266].n = "parseConst";
            __tmp____Bah_fnNames[266].p = parseConst;

            __tmp____Bah_fnNames[267].n = "parseReturn";
            __tmp____Bah_fnNames[267].p = parseReturn;

            __tmp____Bah_fnNames[268].n = "parseIf";
            __tmp____Bah_fnNames[268].p = parseIf;

            __tmp____Bah_fnNames[269].n = "parseElse";
            __tmp____Bah_fnNames[269].p = parseElse;

            __tmp____Bah_fnNames[270].n = "parseLine";
            __tmp____Bah_fnNames[270].p = parseLine;

            __tmp____Bah_fnNames[271].n = "parseFor";
            __tmp____Bah_fnNames[271].p = parseFor;

            __tmp____Bah_fnNames[272].n = "parseForOp";
            __tmp____Bah_fnNames[272].p = parseForOp;

            __tmp____Bah_fnNames[273].n = "makeEvalFunc";
            __tmp____Bah_fnNames[273].p = makeEvalFunc;

            __tmp____Bah_fnNames[274].n = "parsePreKeyword";
            __tmp____Bah_fnNames[274].p = parsePreKeyword;

            __tmp____Bah_fnNames[275].n = "parseAsync";
            __tmp____Bah_fnNames[275].p = parseAsync;

            __tmp____Bah_fnNames[276].n = "addRCPvars";
            __tmp____Bah_fnNames[276].p = addRCPvars;

            __tmp____Bah_fnNames[277].n = "parseChan";
            __tmp____Bah_fnNames[277].p = parseChan;

            __tmp____Bah_fnNames[278].n = "valueFunc";
            __tmp____Bah_fnNames[278].p = valueFunc;

            __tmp____Bah_fnNames[279].n = "valueStruct";
            __tmp____Bah_fnNames[279].p = valueStruct;

            __tmp____Bah_fnNames[280].n = "valueArr";
            __tmp____Bah_fnNames[280].p = valueArr;

            __tmp____Bah_fnNames[281].n = "valueBool";
            __tmp____Bah_fnNames[281].p = valueBool;

            __tmp____Bah_fnNames[282].n = "valueOper";
            __tmp____Bah_fnNames[282].p = valueOper;

            __tmp____Bah_fnNames[283].n = "valueSendChan";
            __tmp____Bah_fnNames[283].p = valueSendChan;

            __tmp____Bah_fnNames[284].n = "valueChan";
            __tmp____Bah_fnNames[284].p = valueChan;

            __tmp____Bah_fnNames[285].n = "isSmallValue";
            __tmp____Bah_fnNames[285].p = isSmallValue;

            __tmp____Bah_fnNames[286].n = "isValue";
            __tmp____Bah_fnNames[286].p = isValue;

            __tmp____Bah_fnNames[287].n = "parseFnDeclare";
            __tmp____Bah_fnNames[287].p = parseFnDeclare;

            __tmp____Bah_fnNames[288].n = "declareFunc";
            __tmp____Bah_fnNames[288].p = declareFunc;

            __tmp____Bah_fnNames[289].n = "declareVar";
            __tmp____Bah_fnNames[289].p = declareVar;

            __tmp____Bah_fnNames[290].n = "declareAll";
            __tmp____Bah_fnNames[290].p = declareAll;

            __tmp____Bah_fnNames[291].n = "memErrHandle";
            __tmp____Bah_fnNames[291].p = memErrHandle;

            __tmp____Bah_fnNames[292].n = "main";
            __tmp____Bah_fnNames[292].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 293;
        
    };
    