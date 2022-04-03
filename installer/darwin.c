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
char * __Bah_safe_string(char * s);
#define null (void *)0
#define true (int)1
#define false (int)0
long int __bah_strcmp(char * a,char * b){
if (((void *)a==null)) {
a =  "";
}
if (((void *)b==null)) {
b =  "";
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
long int i =  0;
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
//optimized out: append
//optimized out: copy
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_READWRITE 3
#define MAP_SHARED 1
#define MAP_ANONYMOUS 32
//optimized out: sharedMemory
void allocateArray(void * arr,long int nbElems){
array(void*)*a=arr;
a->length=nbElems;
a->data=memoryAlloc(nbElems*a->elemSize);
};
typedef array(char)* __BAH_ARR_TYPE_char;
__BAH_ARR_TYPE_char ser(void * a);
//optimized out: __serialize
long int serlen(__BAH_ARR_TYPE_char data){

                    if (data->length <= 0) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 0, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 1) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 1, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 2) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 2, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 3) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 3, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 4) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 4, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 5) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 5, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 6) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 6, data->length);
                        exit(1);
                    };
                    
                    if (data->length <= 7) {
                        printf("array (/opt/bah/memory.bah:194): data[%d] with length %d\n", 7, data->length);
                        exit(1);
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
//optimized out: unser
char * memoryAllocSTR(long int s){
void * r =  GC_malloc_atomic(s);
memset(r,0,s);
return r;
};
//optimized out: delete
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen =  len(arr);
char * str =  memoryAlloc(strLen + 1);
memcpy(str,arr->data,strLen);
return str;
};
__BAH_ARR_TYPE_char strToArr(char * str){
long int strLen =  strlen(str);
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
long int l =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
arr->length=l;
arr->data=str;
return arr;
};
void strTrimLeft(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i + 1);
memcpy(ns,*s+i,ls - i);
*s =  ns;
};
void strTrimRight(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i + 1);
memcpy(ns,*s,ls - i);
*s =  ns;
};
#define __bah_memory_realloc memoryRealloc
#define __bah_memory_str memoryAllocSTR
//optimized out: concatCPSTRING
char * __STR(char * a){
long int lenA =  strlen(a);
char * r =  memoryAlloc(lenA + 1);
strncpy(r,a,lenA);
return r;
};
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void print(char * s){
write((void *)1,s,strlen(s));
};
//optimized out: cArr
//optimized out: __checkString
#include <pthread.h>
#define __thread_create GC_pthread_create
#define __thread_join GC_pthread_join
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
pthread_mutex_t mid =  m.id;
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
struct mutexCondition m =  ____BAH_COMPILER_VAR_1;
m.init((struct mutexCondition*)&m);
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
struct mutex m =  ____BAH_COMPILER_VAR_2;
m.init((struct mutex*)&m);
return m;
};
struct queueNode {
long int key;
void * data;
struct queueNode* next;
};
struct queue {
long int length;
struct queueNode* head;
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
struct queueNode* node =  ____BAH_COMPILER_VAR_3;
node->key =  this->length;
node->data =  data;
node->next =  this->head;
this->length =  this->length + 1;
this->head =  node;
};
void queue__delete(struct queue* this,long int key){
if ((this->length==0)) {
return;
}
struct queueNode* current =  this->head;
struct queueNode* previous= null;
while ((current->key!=key)) {
if ((current->next==null)) {
return;
}
previous =  current;
current =  current->next;
};
if ((current==this->head)) {
this->head =  current->next;
}
else {
previous->next =  current->next;
}
this->length =  this->length - 1;
};
void * queue__get(struct queue* this,long int key){
long int z =  0;
void * zp =  (void *)z;
if ((this->length==0)) {
return zp;
}
struct queueNode* ptr =  this->head;
while ((ptr->key!=key)) {
if ((ptr->next==null)) {
return zp;
}
ptr =  ptr->next;
};
void * data =  ptr->data;
return data;
};
void queue__set(struct queue* this,long int key,void * data){
this->delete((struct queue*)this,key);
struct queueNode* ____BAH_COMPILER_VAR_4 = memoryAlloc(sizeof(struct queueNode));
____BAH_COMPILER_VAR_4->data= null;
____BAH_COMPILER_VAR_4->next= null;
struct queueNode* node =  ____BAH_COMPILER_VAR_4;
node->key =  key;
node->data =  data;
node->next =  this->head;
this->length =  this->length + 1;
this->head =  node;
};
void * queue__pop(struct queue* this){
long int lastIndex =  this->length - 1;
void * data =  this->get((struct queue*)this,lastIndex);
this->delete((struct queue*)this,lastIndex);
return data;
};
void queue__clear(struct queue* this){
this->head =  (void *)0;
this->length =  0;
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
this->w_waitting =  this->w_waitting+1;
pthread_cond_wait(&this->w_cond,&this->m_mut);
this->w_waitting =  this->w_waitting-1;
};
}
this->queue->insert((struct queue*)this->queue,data);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void channel__sendAny(struct channel* this,void * data,long int len){
pthread_mutex_lock(&this->m_mut);
if ((this->cap!=-1)) {
while ((this->queue->length==this->cap)) {
this->w_waitting =  this->w_waitting+1;
pthread_cond_wait(&this->w_cond,&this->m_mut);
this->w_waitting =  this->w_waitting-1;
};
}
void * p =  memoryAlloc(len);
memcpy(p,data,len);
this->queue->insert((struct queue*)this->queue,p);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void * channel__receive(struct channel* this){
pthread_mutex_lock(&this->m_mut);
while ((this->queue->length==0)) {
this->r_waitting =  this->r_waitting+1;
pthread_cond_wait(&this->r_cond,&this->m_mut);
this->r_waitting =  this->r_waitting-1;
};
void * data =  this->queue->pop((struct queue*)this->queue);
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
long int l =  this->queue->length;
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
struct channel* c =  ____BAH_COMPILER_VAR_5;
pthread_mutex_init(&c->m_mut,0);
pthread_cond_init(&c->w_cond,0);
pthread_cond_init(&c->r_cond,0);
struct queue* ____BAH_COMPILER_VAR_6 = memoryAlloc(sizeof(struct queue));
____BAH_COMPILER_VAR_6->length = 0;
____BAH_COMPILER_VAR_6->head= null;
____BAH_COMPILER_VAR_6->insert = queue__insert;
____BAH_COMPILER_VAR_6->delete = queue__delete;
____BAH_COMPILER_VAR_6->get = queue__get;
____BAH_COMPILER_VAR_6->set = queue__set;
____BAH_COMPILER_VAR_6->pop = queue__pop;
____BAH_COMPILER_VAR_6->clear = queue__clear;
c->queue =  ____BAH_COMPILER_VAR_6;
return c;
};
//optimized out: setChanCap
struct channel * __BAH_panic_chan;
void __Bah_common_panic(char * e){
if (strlen(e)) {
print(e);
print("\n");
cleanShutDown();
}
};
#define panic __Bah_common_panic
void __BAH_panic(char * e,char * line){
if ((__BAH_panic_chan!=null)) {
__BAH_panic_chan->send(__BAH_panic_chan, e);
return;
}
char * ____BAH_COMPILER_VAR_7 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("panic (");
long int strLen_1 = strlen(line);
long int strLen_2 = strlen("): ");
long int strLen_3 = strlen(e);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_7 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_7+currStrOff, "panic (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_7+currStrOff, line, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_7+currStrOff, "): ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_7+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_7+currStrOff, "\n", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                print(____BAH_COMPILER_VAR_7);
cleanShutDown();
};
//optimized out: recover
char * __Bah_safe_string(char * s){
if (((void *)s==null)) {
return "(nil)";
}
if ((strlen(s)>50)) {
s =  __STR(s);
array(char)* a =  strAsArr(s);

{
long nLength = 47;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[47] =  46;
a->length = nLength+1;
} else {
a->data[47] =  46;
}
};

{
long nLength = 48;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[48] =  46;
a->length = nLength+1;
} else {
a->data[48] =  46;
}
};

{
long nLength = 49;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[49] =  46;
a->length = nLength+1;
} else {
a->data[49] =  46;
}
};

{
long nLength = 50;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[50] =  (char)0;
a->length = nLength+1;
} else {
a->data[50] =  (char)0;
}
};
}
char * ____BAH_COMPILER_VAR_8 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(s);
long int strLen_2 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_8 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_8+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_8+currStrOff, s, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_8+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                return ____BAH_COMPILER_VAR_8;
};
char cpstringCharAt(char * s,long int i){
char c =  (char)0;
c=s[i];
return c;
};
char * cpstringSubsitute(char * s,long int i,long int l){
long int size =  l - i;
char * ns =  memoryAllocSTR(size);
memcpy(ns,s+i,size);
return ns;
};
typedef array(void *)* __BAH_ARR_TYPE_ptr;
void * arraySubstitute(__BAH_ARR_TYPE_ptr arr,long int i,long int l){
long int length =  l - i;
long int offset =  i * arr->elemSize;
array(void *)* na = memoryAlloc(sizeof(array(void *)));

na->length = 0;
na->elemSize = sizeof(void *);
na->elemSize=arr->elemSize;
na->length=length;
long int allocLength =  length;
if ((length>50)) {
allocLength =  allocLength + allocLength % 50;
}
else {
allocLength =  50;
}
long int size =  allocLength * arr->elemSize;
long int realSize =  length * arr->elemSize;
void * data =  memoryAlloc(size);
char * oData =  arr->data;
memcpy(data,oData+offset,realSize);
na->data=data;
return na;
};
long int __Bah_map_hash(char * s,long int l){
long int hash =  5381;
long int i =  0;
for (; (i<strlen(s)); i =  i+1) {
hash =  ((long int)hash<<5 + 0) + hash + (long int)cpstringCharAt(s,i);
};
return hash % l;
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
long int l =  len(this->elems);
long int i =  l;
for (; (i<l + nb); i =  i+1) {

{
long nLength = i;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[i] =  null;
this->elems->length = nLength+1;
} else {
this->elems->data[i] =  null;
}
};
};
};
void mapWrapper__set(struct mapWrapper* this,char * k,void * e){
if ((this->length * 2>=len(this->elems))) {
this->grow((struct mapWrapper*)this,this->length);
}
struct mapElem* ____BAH_COMPILER_VAR_9 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_9->key= null;
____BAH_COMPILER_VAR_9->val= null;
____BAH_COMPILER_VAR_9->key = k;
____BAH_COMPILER_VAR_9->val = e;
struct mapElem* elem =  ____BAH_COMPILER_VAR_9;
long int ind =  __Bah_map_hash(k,len(this->elems));
long int i =  0;
for (; (i<len(this->elems)); i =  i+1) {
long int j =  (i + ind) % len(this->elems);

                    if (this->elems->length <= j) {
                        printf("array (/opt/bah/map.bah:37): this->elems[%d] with length %d\n", j, this->elems->length);
                        exit(1);
                    };
                    struct mapElem* ce =  this->elems->data[j];
if ((ce==null)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] =  elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] =  elem;
}
};
this->length =  this->length+1;
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
this->elems->data[j] =  elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] =  elem;
}
};
break;
}
};
};
void mapWrapper__setAny(struct mapWrapper* this,char * k,void * e,long int s){
if ((this->length==0)) {
this->grow((struct mapWrapper*)this,50);
}
if ((this->length * 2>=len(this->elems))) {
this->grow((struct mapWrapper*)this,this->length);
}
void * p =  memoryAlloc(s);
memcpy(p,e,s);
struct mapElem* ____BAH_COMPILER_VAR_10 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_10->key= null;
____BAH_COMPILER_VAR_10->val= null;
____BAH_COMPILER_VAR_10->key = k;
____BAH_COMPILER_VAR_10->val = p;
struct mapElem* elem =  ____BAH_COMPILER_VAR_10;
long int ind =  __Bah_map_hash(k,len(this->elems));
long int i =  0;
for (; (i<len(this->elems)); i =  i+1) {
long int j =  (i + ind) % len(this->elems);

                    if (this->elems->length <= j) {
                        printf("array (/opt/bah/map.bah:65): this->elems[%d] with length %d\n", j, this->elems->length);
                        exit(1);
                    };
                    struct mapElem* ce =  this->elems->data[j];
if ((ce==null)) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] =  elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] =  elem;
}
};
this->length =  this->length+1;
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
this->elems->data[j] =  elem;
this->elems->length = nLength+1;
} else {
this->elems->data[j] =  elem;
}
};
break;
}
};
};
void mapWrapper__delete(struct mapWrapper* this,char * k){
long int ind =  __Bah_map_hash(k,len(this->elems));
long int i =  0;
for (; (i<len(this->elems)); i =  i+1) {
long int j =  (i + ind) % len(this->elems);

                    if (this->elems->length <= j) {
                        printf("array (/opt/bah/map.bah:81): this->elems[%d] with length %d\n", j, this->elems->length);
                        exit(1);
                    };
                    struct mapElem* e =  this->elems->data[j];
if (((e!=null)&&(strcmp(e->key, k) == 0))) {

{
long nLength = j;
if (this->elems->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->elems->data, (nLength+50)*sizeof(struct mapElem*));
this->elems->data = newPtr;
}
this->elems->data[j] =  null;
this->elems->length = nLength+1;
} else {
this->elems->data[j] =  null;
}
};
}
};
};
void * mapWrapper__get(struct mapWrapper* this,char * k){
long int ind =  __Bah_map_hash(k,len(this->elems));
long int i =  0;
for (; (i<len(this->elems)); i =  i+1) {
long int j =  (i + ind) % len(this->elems);

                    if (this->elems->length <= j) {
                        printf("array (/opt/bah/map.bah:92): this->elems[%d] with length %d\n", j, this->elems->length);
                        exit(1);
                    };
                    struct mapElem* e =  this->elems->data[j];
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
struct mapWrapper* m =  ____BAH_COMPILER_VAR_11;
m->grow((struct mapWrapper*)m,50);
return m;
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
//optimized out: stdinput
void println(char * s){
char * ____BAH_COMPILER_VAR_14 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_14 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_14+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_14+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                write((void *)1,____BAH_COMPILER_VAR_14,strlen(s) + 1);
};
struct fileStream {
FILE* handle;
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
};
long int fileStream__isValid(struct fileStream* this){
if ((this->handle==null)) {
return 0;
}
return 1;
};
void fileStream__open(struct fileStream* this,char * path,char * mode){
this->handle =  fopen(path,mode);
};
void fileStream__close(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return;
}
fclose(this->handle);
};
long int fileStream__getPos(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return 0;
}
return ftell(this->handle);
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((this->isValid((struct fileStream*)this)==0)) {
return;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
return -1;
}
long int oldPos =  this->getPos((struct fileStream*)this);
fseek(this->handle,0,2);
long int size =  ftell(this->handle);
this->setPos((struct fileStream*)this,oldPos);
return size;
};
void fileStream__rewind(struct fileStream* this){
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){
char c =  getc(this->handle);
return c;
};
void fileStream__setChar(struct fileStream* this,char c){
fputc(c,this->handle);
};
void fileStream__createFile(struct fileStream* this,char * path){
this->open((struct fileStream*)this,path,"w");
this->close((struct fileStream*)this);
};
long int fileStream__writeFile(struct fileStream* this,char * content){
if ((this->isValid((struct fileStream*)this)==0)) {
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
if ((this->isValid((struct fileStream*)this)==0)) {
return "invalid";
}
long int sz =  this->getSize((struct fileStream*)this);
char * r =  memoryAlloc(sz + 1);
long int l =  fread(r,1,sz,this->handle);
if ((sz!=l)) {
array(char)* rarr =  strAsArr(r);

{
long nLength = l;
if (rarr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(rarr->data, (nLength+50)*sizeof(char));
rarr->data = newPtr;
}
rarr->data[l] =  (char)0;
rarr->length = nLength+1;
} else {
rarr->data[l] =  (char)0;
}
};
}
return r;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,this->getSize((struct fileStream*)this));
this->readPtr((struct fileStream*)this,r->data,len(r));
return r;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
this->writePtr((struct fileStream*)this,d->data,len(d));
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
this->handle =  open(fileName,O_RDWR,S_IRUSR|S_IWUSR);
struct stat ____BAH_COMPILER_VAR_15 = {};
struct stat sb =  ____BAH_COMPILER_VAR_15;
fstat(this->handle,&sb);
this->size =  sb.st_size;
this->p =  mmap(0,sb.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,this->handle,0);
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
//optimized out: listFiles
long int fileExists(char * path){
long int is =  access(path,0);
if ((is==0)) {
return 1;
}
return 0;
};
//optimized out: removeFile
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
char * s =  memoryAlloc(2);
strncpy(s,(char *)&c,1);
return s;
};
long int isUpper(char c){
if ((c>(char)64)) {
if ((c<(char)91)) {
return 1;
}
}
return 0;
};
long int isLower(char c){
if ((c>(char)96)) {
if ((c<(char)123)) {
return 1;
}
}
return 0;
};
long int isLetter(char s){
if (isUpper(s)) {
return 1;
}
if (isLower(s)) {
return 1;
}
return 0;
};
long int isNumber(char c){
if ((c>(char)47)) {
if ((c<(char)58)) {
return 1;
}
}
return 0;
};
long int isAlphaNumeric(char s){
if (isLetter(s)) {
return 1;
}
if (isNumber(s)) {
return 1;
}
return 0;
};
long int isSpace(char c){
if ((c==(char)32)) {
return 1;
}
if ((c==(char)9)) {
return 1;
}
if ((c==(char)10)) {
return 1;
}
if ((c==(char)11)) {
return 1;
}
if ((c==(char)13)) {
return 1;
}
return 0;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr);
void println(char * s);
struct string {
char * content;
long int length;
void(*set)(struct string* this,char * s);
void(*append)(struct string* this,char * s);
void(*prepend)(struct string* this,char * s);
char(*charAt)(struct string* this,long int i);
long int(*compare)(struct string* this,char * s);
char *(*str)(struct string* this);
void(*replace)(struct string* this,char * nd,char * rl);
long int(*count)(struct string* this,char * need);
long int(*hasPrefix)(struct string* this,char * need);
long int(*hasSuffix)(struct string* this,char * need);
void(*trim)(struct string* this);
void(*trimLeft)(struct string* this,long int s);
void(*trimRight)(struct string* this,long int s);
struct string(*add)(struct string* this,struct string s2);
};
void string__set(struct string* this,char * s){
this->length =  strlen(s);
this->content =  (char *)memoryAlloc(this->length + 1);
strncpy(this->content,s,this->length);
};
void string__append(struct string* this,char * s){
long int sl =  strlen(s);
long int nl =  sl + this->length;
void * nc =  memoryRealloc(this->content,nl + 1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:126");
}
this->content =  nc;
strCatOffset(this->content,this->length,s,sl);
this->length =  nl;
};
void string__prepend(struct string* this,char * s){
long int sl =  strlen(s);
long int nl =  this->length + sl;
char * tmpS =  this->content;
void * nc =  memoryAlloc(nl + 1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:140");
}
this->content =  nc;
strncpy(this->content,s,sl);
strCatOffset(this->content,sl,tmpS,this->length);
destroy(tmpS);
this->length =  nl;
};
char string__charAt(struct string* this,long int i){
char c =  (char)0;
if ((i<this->length)) {
c=this->content[i];
return c;
}
return c;
};
long int string__compare(struct string* this,char * s){
long int r =  strcmp(this->content,s);
if ((r==0)) {
return 1;
}
return 0;
};
char * string__str(struct string* this){
char * s =  this->content;
return s;
};
void string__replace(struct string* this,char * nd,char * rl){
struct string ____BAH_COMPILER_VAR_16 = {};
____BAH_COMPILER_VAR_16.content= null;
____BAH_COMPILER_VAR_16.set = string__set;
____BAH_COMPILER_VAR_16.append = string__append;
____BAH_COMPILER_VAR_16.prepend = string__prepend;
____BAH_COMPILER_VAR_16.charAt = string__charAt;
____BAH_COMPILER_VAR_16.compare = string__compare;
____BAH_COMPILER_VAR_16.str = string__str;
____BAH_COMPILER_VAR_16.replace = string__replace;
struct string needle =  ____BAH_COMPILER_VAR_16;
needle.set((struct string*)&needle,nd);
struct string ____BAH_COMPILER_VAR_17 = {};
____BAH_COMPILER_VAR_17.content= null;
____BAH_COMPILER_VAR_17.set = string__set;
____BAH_COMPILER_VAR_17.append = string__append;
____BAH_COMPILER_VAR_17.prepend = string__prepend;
____BAH_COMPILER_VAR_17.charAt = string__charAt;
____BAH_COMPILER_VAR_17.compare = string__compare;
____BAH_COMPILER_VAR_17.str = string__str;
____BAH_COMPILER_VAR_17.replace = string__replace;
struct string repl =  ____BAH_COMPILER_VAR_17;
repl.set((struct string*)&repl,rl);
long int i =  0;
long int si =  0;
long int replcBuffSart =  0;
long int replcBuffLength =  0;
array(char)* buff = memoryAlloc(sizeof(array(char)));

buff->length = 0;
buff->elemSize = sizeof(char);
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char rc =  needle.charAt((struct string*)&needle,si);
if ((c==rc)) {
si =  si + 1;
if ((replcBuffLength==0)) {
replcBuffSart =  i;
}
replcBuffLength =  replcBuffLength + 1;
}
else {
if ((replcBuffLength>0)) {
si =  0;
long int j =  0;
while ((j<replcBuffLength)) {

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  this->charAt((struct string*)this,j + replcBuffSart);
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  this->charAt((struct string*)this,j + replcBuffSart);
}
};
j =  j + 1;
};
replcBuffLength =  0;
}

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  c;
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  c;
}
};
}
if ((si==needle.length)) {
replcBuffLength =  0;
long int ii =  0;
while ((ii<repl.length)) {
long int a =  ii;

{
long nLength = len(buff);
if (buff->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(buff->data, (nLength+50)*sizeof(char));
buff->data = newPtr;
}
buff->data[len(buff)] =  repl.charAt((struct string*)&repl,ii);
buff->length = nLength+1;
} else {
buff->data[len(buff)] =  repl.charAt((struct string*)&repl,ii);
}
};
ii =  ii + 1;
};
si =  0;
}
i =  i + 1;
};
char * r =  arrAsStr(buff);
if ((replcBuffLength>0)) {
array(char)* replbuffStr = memoryAlloc(sizeof(array(char)));

replbuffStr->length = 0;
replbuffStr->elemSize = sizeof(char);
allocateArray(replbuffStr,replcBuffLength + 1);
long int j =  0;
while ((j<replcBuffLength)) {

{
long nLength = j;
if (replbuffStr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(replbuffStr->data, (nLength+50)*sizeof(char));
replbuffStr->data = newPtr;
}
replbuffStr->data[j] =  this->charAt((struct string*)this,j + replcBuffSart);
replbuffStr->length = nLength+1;
} else {
replbuffStr->data[j] =  this->charAt((struct string*)this,j + replcBuffSart);
}
};
j =  j + 1;
};
char * ____BAH_COMPILER_VAR_18 =arrAsStr(replbuffStr);char * ____BAH_COMPILER_VAR_19 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_18);
;                            
                    ____BAH_COMPILER_VAR_19 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_19+currStrOff, r, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_19+currStrOff, ____BAH_COMPILER_VAR_18, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                r =  ____BAH_COMPILER_VAR_19;
}
if (((void *)r!=null)) {
this->set((struct string*)this,r);
}
};
long int string__count(struct string* this,char * need){
long int i =  0;
long int count =  0;
struct string ____BAH_COMPILER_VAR_20 = {};
____BAH_COMPILER_VAR_20.content= null;
____BAH_COMPILER_VAR_20.set = string__set;
____BAH_COMPILER_VAR_20.append = string__append;
____BAH_COMPILER_VAR_20.prepend = string__prepend;
____BAH_COMPILER_VAR_20.charAt = string__charAt;
____BAH_COMPILER_VAR_20.compare = string__compare;
____BAH_COMPILER_VAR_20.str = string__str;
____BAH_COMPILER_VAR_20.replace = string__replace;
____BAH_COMPILER_VAR_20.count = string__count;
struct string needle =  ____BAH_COMPILER_VAR_20;
needle.set((struct string*)&needle,need);
long int countIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  needle.charAt((struct string*)&needle,countIndex);
if ((c==sc)) {
countIndex =  countIndex + 1;
}
else {
countIndex =  0;
}
if ((countIndex==needle.length)) {
count =  count + 1;
countIndex =  0;
}
i =  i + 1;
};
return count;
};
long int string__hasPrefix(struct string* this,char * need){
long int i =  0;
long int nl =  strlen(need);
if ((this->length<nl)) {
return 0;
}
while ((i<nl)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,i);
if ((c!=sc)) {
return 0;
}
i =  i + 1;
};
return 1;
};
long int string__hasSuffix(struct string* this,char * need){
long int nl =  strlen(need);
if ((this->length<nl)) {
return 0;
}
long int i =  this->length - nl;
long int needleIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,needleIndex);
if ((c!=sc)) {
return 0;
}
needleIndex =  needleIndex + 1;
i =  i + 1;
};
return 1;
};
void string__trim(struct string* this){
if ((this->length==0)) {
return;
}
char fc =  this->charAt((struct string*)this,0);
if ((isSpace(fc)==0)) {
return;
}
long int i =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
if ((i>0)) {
this->length =  this->length - i;
char * tmpS =  memoryAlloc(this->length + 1);
memcpy(tmpS,this->content+i,this->length + 1);
this->content =  tmpS;
}
};
void string__trimLeft(struct string* this,long int s){
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,this->content+s,nSize);
this->content =  tmpS;
this->length =  nSize;
};
void string__trimRight(struct string* this,long int s){
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,this->content,nSize);
this->content =  tmpS;
this->length =  nSize;
};
struct string string__add(struct string* this,struct string s2){
struct string ____BAH_COMPILER_VAR_21 = {};
____BAH_COMPILER_VAR_21.content= null;
____BAH_COMPILER_VAR_21.set = string__set;
____BAH_COMPILER_VAR_21.append = string__append;
____BAH_COMPILER_VAR_21.prepend = string__prepend;
____BAH_COMPILER_VAR_21.charAt = string__charAt;
____BAH_COMPILER_VAR_21.compare = string__compare;
____BAH_COMPILER_VAR_21.str = string__str;
____BAH_COMPILER_VAR_21.replace = string__replace;
____BAH_COMPILER_VAR_21.count = string__count;
____BAH_COMPILER_VAR_21.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_21.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_21.trim = string__trim;
____BAH_COMPILER_VAR_21.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_21.trimRight = string__trimRight;
____BAH_COMPILER_VAR_21.add = string__add;
struct string r =  ____BAH_COMPILER_VAR_21;
r.length =  this->length + s2.length;
r.content =  memoryAlloc(r.length + 1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
return r;
};
struct string string(char * s){
struct string ____BAH_COMPILER_VAR_22 = {};
____BAH_COMPILER_VAR_22.content= null;
____BAH_COMPILER_VAR_22.set = string__set;
____BAH_COMPILER_VAR_22.append = string__append;
____BAH_COMPILER_VAR_22.prepend = string__prepend;
____BAH_COMPILER_VAR_22.charAt = string__charAt;
____BAH_COMPILER_VAR_22.compare = string__compare;
____BAH_COMPILER_VAR_22.str = string__str;
____BAH_COMPILER_VAR_22.replace = string__replace;
____BAH_COMPILER_VAR_22.count = string__count;
____BAH_COMPILER_VAR_22.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_22.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_22.trim = string__trim;
____BAH_COMPILER_VAR_22.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_22.trimRight = string__trimRight;
____BAH_COMPILER_VAR_22.add = string__add;
struct string a =  ____BAH_COMPILER_VAR_22;
a.set((struct string*)&a,s);
return a;
};
char * intToStr(long int i){
if ((i==0)) {
return "0";
}
array(char)* s = memoryAlloc(sizeof(array(char)));

s->length = 0;
s->elemSize = sizeof(char);
int subZero =  (i<0);
if ((subZero==true)) {
i =  0 - i;
}
for (; (i!=0); i =  i / 10) {
long int conv =  i % 10;
conv =  conv + 48;

{
long nLength = len(s);
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[len(s)] =  (char)conv;
s->length = nLength+1;
} else {
s->data[len(s)] =  (char)conv;
}
};
};
if ((subZero==true)) {

{
long nLength = len(s);
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[len(s)] =  45;
s->length = nLength+1;
} else {
s->data[len(s)] =  45;
}
};
}
long int ls =  len(s);
i =  0;
for (; (i<ls / 2); i =  i+1) {
long int ii =  ls - i-1;

                    if (s->length <= i) {
                        printf("array (/opt/bah/string.bah:390): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    char osi =  s->data[i];

                    if (s->length <= ii) {
                        printf("array (/opt/bah/string.bah:391): s[%d] with length %d\n", ii, s->length);
                        exit(1);
                    };
                    
{
long nLength = i;
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[i] =  s->data[ii];
s->length = nLength+1;
} else {
s->data[i] =  s->data[ii];
}
};

{
long nLength = ii;
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[ii] =  osi;
s->length = nLength+1;
} else {
s->data[ii] =  osi;
}
};
};

{
long nLength = len(s);
if (s->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(s->data, (nLength+50)*sizeof(char));
s->data = newPtr;
}
s->data[len(s)] =  (char)0;
s->length = nLength+1;
} else {
s->data[len(s)] =  (char)0;
}
};
return arrAsStr(s);
};
//optimized out: intToString
char * floatToStr(double f){
char * buff =  memoryAlloc(50);
sprintf(buff,"%lf",f);
return buff;
};
long int strToInt(char * s){
return atol(s);
};
double strToFloat(char * s){
return strtod(s,null);
};
//optimized out: stringToInt
typedef array(struct string)* __BAH_ARR_TYPE_string;
__BAH_ARR_TYPE_string splitString(struct string s,char * sp){
struct string sep =  string(sp);
array(struct string)* res = memoryAlloc(sizeof(array(struct string)));

res->length = 0;
res->elemSize = sizeof(struct string);
struct string sepBuffer =  string("");
long int sepIndex =  0;
long int i =  0;
struct string replcBuff =  string("");
array(char)* tmpString = memoryAlloc(sizeof(array(char)));

tmpString->length = 0;
tmpString->elemSize = sizeof(char);
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
char sepc =  sep.charAt((struct string*)&sep,sepIndex);
if ((c==sepc)) {
sepIndex =  sepIndex + 1;
char * ____BAH_COMPILER_VAR_24 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_24);
}
else {
if ((sepIndex>0)) {
sepIndex =  0;
char * ____BAH_COMPILER_VAR_25 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_25);
long int ii =  0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
}
};
ii =  ii + 1;
};
replcBuff.set((struct string*)&replcBuff,"");
}
else {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  c;
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  c;
}
};
}
}
if ((sepIndex==sep.length)) {
replcBuff.set((struct string*)&replcBuff,"");
struct string* ____BAH_COMPILER_VAR_26 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_26->content= null;
____BAH_COMPILER_VAR_26->set = string__set;
____BAH_COMPILER_VAR_26->append = string__append;
____BAH_COMPILER_VAR_26->prepend = string__prepend;
____BAH_COMPILER_VAR_26->charAt = string__charAt;
____BAH_COMPILER_VAR_26->compare = string__compare;
____BAH_COMPILER_VAR_26->str = string__str;
____BAH_COMPILER_VAR_26->replace = string__replace;
____BAH_COMPILER_VAR_26->count = string__count;
____BAH_COMPILER_VAR_26->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_26->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_26->trim = string__trim;
____BAH_COMPILER_VAR_26->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_26->trimRight = string__trimRight;
____BAH_COMPILER_VAR_26->add = string__add;
struct string* elem =  ____BAH_COMPILER_VAR_26;
char * ____BAH_COMPILER_VAR_27 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_27);
long int lenRes =  len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] =  *elem;
res->length = nLength+1;
} else {
res->data[lenRes] =  *elem;
}
};
clear(tmpString);
sepIndex =  0;
}
i =  i + 1;
};
if ((replcBuff.length>0)) {
long int ii =  0;
while ((ii<replcBuff.length)) {

{
long nLength = len(tmpString);
if (tmpString->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tmpString->data, (nLength+50)*sizeof(char));
tmpString->data = newPtr;
}
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
tmpString->length = nLength+1;
} else {
tmpString->data[len(tmpString)] =  replcBuff.charAt((struct string*)&replcBuff,ii);
}
};
ii =  ii + 1;
};
}
if ((len(tmpString)>0)) {
struct string* ____BAH_COMPILER_VAR_28 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_28->content= null;
____BAH_COMPILER_VAR_28->set = string__set;
____BAH_COMPILER_VAR_28->append = string__append;
____BAH_COMPILER_VAR_28->prepend = string__prepend;
____BAH_COMPILER_VAR_28->charAt = string__charAt;
____BAH_COMPILER_VAR_28->compare = string__compare;
____BAH_COMPILER_VAR_28->str = string__str;
____BAH_COMPILER_VAR_28->replace = string__replace;
____BAH_COMPILER_VAR_28->count = string__count;
____BAH_COMPILER_VAR_28->hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_28->hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_28->trim = string__trim;
____BAH_COMPILER_VAR_28->trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_28->trimRight = string__trimRight;
____BAH_COMPILER_VAR_28->add = string__add;
struct string* elem =  ____BAH_COMPILER_VAR_28;
char * ____BAH_COMPILER_VAR_29 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_29);
long int lenRes =  len(res);

{
long nLength = lenRes;
if (res->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(res->data, (nLength+50)*sizeof(struct string));
res->data = newPtr;
}
res->data[lenRes] =  *elem;
res->length = nLength+1;
} else {
res->data[lenRes] =  *elem;
}
};
}
return res;
};
//optimized out: joinString
char * splitStringBefore(struct string s,char * sp){
struct string sep =  string(sp);
if ((sep.length>=s.length)) {
return "";
}
long int sepIndex =  0;
long int foundIndex =  0;
long int i =  0;
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
char sc =  sep.charAt((struct string*)&sep,sepIndex);
if ((c==sc)) {
if ((sepIndex==0)) {
foundIndex =  i - 1;
}
sepIndex =  sepIndex + 1;
if ((sepIndex==sep.length)) {
long int max =  s.length - foundIndex - 1;
s.trimRight((struct string*)&s,max);
return s.str((struct string*)&s);
}
}
else {
foundIndex =  0;
sepIndex =  0;
}
i =  i + 1;
};
return "";
};
//optimized out: toLower
int strHasPrefix(char * s,char * need){
long int i =  0;
long int nl =  strlen(need);
long int sl =  strlen(s);
if ((sl<nl)) {
return false;
}
while ((i<nl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
return false;
}
i =  i + 1;
};
return true;
};
int strHasSuffix(char * s,char * need){
long int sl =  strlen(s);
long int nl =  strlen(need);
if ((nl>sl)) {
return false;
}
long int i =  sl - nl;
while ((i<sl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
return false;
}
i =  i + 1;
};
return true;
};
void strTrim(char ** s){
long int l =  strlen(*s);
long int i =  0;
while ((i<l)) {
char c =  cpstringCharAt(*s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
*s =  *s+i;
};
long int strCount(char * src,char * needle){
long int i =  0;
long int count =  0;
long int countIndex =  0;
long int sl =  strlen(src);
long int nl =  strlen(needle);
while ((i<sl)) {
char c =  cpstringCharAt(src,i);
char sc =  cpstringCharAt(needle,countIndex);
if ((c==sc)) {
countIndex =  countIndex + 1;
}
else {
countIndex =  0;
}
if ((countIndex==nl)) {
count =  count + 1;
countIndex =  0;
}
i =  i + 1;
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
struct flag* ____BAH_COMPILER_VAR_33 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_33->name= null;
____BAH_COMPILER_VAR_33->help= null;
____BAH_COMPILER_VAR_33->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_33;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_CPSTRING;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_34 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_34->name= null;
____BAH_COMPILER_VAR_34->help= null;
____BAH_COMPILER_VAR_34->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_34;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_BOOL;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_35 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_35->name= null;
____BAH_COMPILER_VAR_35->help= null;
____BAH_COMPILER_VAR_35->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_35;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_INT;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_36 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_36->name= null;
____BAH_COMPILER_VAR_36->help= null;
____BAH_COMPILER_VAR_36->content= null;
struct flag* f =  ____BAH_COMPILER_VAR_36;
f->name =  name;
f->help =  help;
f->type =  FLAG_TYPE_FLOAT;
long int lf =  len(this->flags);

{
long nLength = lf;
if (this->flags->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(this->flags->data, (nLength+50)*sizeof(struct flag*));
this->flags->data = newPtr;
}
this->flags->data[lf] =  f;
this->flags->length = nLength+1;
} else {
this->flags->data[lf] =  f;
}
};
};
void flags__invalidate(struct flags* this){
print("Usage of ");
print(this->args->data[0]);
println(":");
long int i =  0;
while ((i<len(this->flags))) {

                    if (this->flags->length <= i) {
                        printf("array (/opt/bah/flags.bah:75): this->flags[%d] with length %d\n", i, this->flags->length);
                        exit(1);
                    };
                    struct flag* flag =  this->flags->data[i];
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
i =  i + 1;
};
exit(1);
};
struct flag* flags__getFlag(struct flags* this,struct string name){
long int i =  0;
while ((i<len(this->flags))) {

                    if (this->flags->length <= i) {
                        printf("array (/opt/bah/flags.bah:98): this->flags[%d] with length %d\n", i, this->flags->length);
                        exit(1);
                    };
                    struct flag* flag =  this->flags->data[i];
if (name.compare((struct string*)&name,flag->name)) {
return flag;
}
i =  i + 1;
};
struct flag* ____BAH_COMPILER_VAR_37 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_37->name= null;
____BAH_COMPILER_VAR_37->help= null;
____BAH_COMPILER_VAR_37->content= null;
struct flag* z =  ____BAH_COMPILER_VAR_37;
z->isSet =  0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_38 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_38);
char * ctn =  flag->content;
return ctn;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_39 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_39);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_40 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not int.");
;                            
                    ____BAH_COMPILER_VAR_40 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_40+currStrOff, "Flag '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_40+currStrOff, flag->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_40+currStrOff, "' is not int.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                char * error =  ____BAH_COMPILER_VAR_40;
__BAH_panic(error,"/opt/bah/flags.bah:124");
}
long int ctn =  flag->cont_int;
return ctn;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_41 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_41);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_42 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not float.");
;                            
                    ____BAH_COMPILER_VAR_42 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_42+currStrOff, "Flag '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_42+currStrOff, flag->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_42+currStrOff, "' is not float.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                char * error =  ____BAH_COMPILER_VAR_42;
__BAH_panic(error,"/opt/bah/flags.bah:136");
}
double ctn =  flag->cont_float;
return ctn;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_43 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_43);
long int ctn =  flag->isSet;
return ctn;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){
struct flag* currentFlag= null;
int isVal =  false;
this->args =  args;
long int i =  1;
while ((i<len(args))) {
struct string argName =  string(args->data[i]);
if ((isVal==true)) {
currentFlag->content =  argName.str((struct string*)&argName);
if ((currentFlag->type==FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_44 =argName.str((struct string*)&argName);currentFlag->cont_int =  atoi(____BAH_COMPILER_VAR_44);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_45 =argName.str((struct string*)&argName);currentFlag->cont_float =  strtod(____BAH_COMPILER_VAR_45,0);
}
isVal =  false;
}
else {
if ((argName.charAt((struct string*)&argName,0)!=45)) {
i =  i + 1;
continue;
}
argName.trimLeft((struct string*)&argName,1);
if (argName.compare((struct string*)&argName,"help")) {
this->invalidate((struct flags*)this);
}
else if (argName.compare((struct string*)&argName,"h")) {
this->invalidate((struct flags*)this);
}
currentFlag =  this->getFlag((struct flags*)this,argName);
if ((currentFlag==null)) {
this->invalidate((struct flags*)this);
}
currentFlag->isSet =  1;
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
isVal =  true;
}
}
i =  i + 1;
};
if ((isVal==true)) {
if ((currentFlag->type!=FLAG_TYPE_BOOL)) {
this->invalidate((struct flags*)this);
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
this->timestamp =  time(0);
};
char * time__format(struct time* this,char * a){
long int lt =  localtime(&this->timestamp);
char * date =  memoryAlloc(1024);
strftime(date,1024,a,lt);
return date;
};
long int time__since(struct time* this){
long int nt =  time(0);
long int r =  nt - this->timestamp;
return r;
};
long int getTimeUnix(){
struct timespec ____BAH_COMPILER_VAR_46 = {};
struct timespec ts =  ____BAH_COMPILER_VAR_46;
clock_serv_t cclock;
mach_timespec_t mts;
void * ____BAH_COMPILER_VAR_47 =mach_host_self();host_get_clock_service(____BAH_COMPILER_VAR_47,CALENDAR_CLOCK,&cclock);
clock_get_time(cclock,&mts);
void * ____BAH_COMPILER_VAR_48 =mach_task_self();mach_port_deallocate(____BAH_COMPILER_VAR_48,cclock);
mach_timespec_t* mtsp =  &mts;
ts.tv_sec =  mtsp->tv_sec;
ts.tv_nsec =  mtsp->tv_nsec;
long int s =  ts.tv_sec * 1000000000 + ts.tv_nsec;
return s;
};
long int RAND_SEEDED;
//optimized out: seedRandom
//optimized out: randomInRange
//optimized out: cryptoRand
#define ROPE_LEAF_LEN 50
struct rope {
struct rope* left;
struct rope* right;
struct rope* parent;
char * str;
long int lCount;
long int len;
long int totalLen;
struct rope*(*getParent)(struct rope* this);
void(*addStr)(struct rope* this,char ** s);
char *(*toStr)(struct rope* this);
struct rope*(*add)(struct rope* this,struct rope* root2);
};
struct rope* rope__getParent(struct rope* this){
if ((this->parent==null)) {
return this;
}
return this->parent->getParent((struct rope*)this->parent);
};
void rope__addStr(struct rope* this,char ** s){
if (((this->left==null)&&(this->right==null))) {
strcat(*s,this->str);
return;
}
this->left->addStr((struct rope*)this->left,s);
this->right->addStr((struct rope*)this->right,s);
};
char * rope__toStr(struct rope* this){
if (((this->left==null)&&(this->right==null))) {
return this->str;
}
char * s =  memoryAlloc(this->totalLen + 1);
this->left->addStr((struct rope*)this->left,&s);
this->right->addStr((struct rope*)this->right,&s);
return s;
};
struct rope* rope__add(struct rope* this,struct rope* root2){
long int n1 =  this->len;
struct rope* ____BAH_COMPILER_VAR_50 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_50->left= null;
____BAH_COMPILER_VAR_50->right= null;
____BAH_COMPILER_VAR_50->parent= null;
____BAH_COMPILER_VAR_50->str= null;
____BAH_COMPILER_VAR_50->getParent = rope__getParent;
____BAH_COMPILER_VAR_50->addStr = rope__addStr;
____BAH_COMPILER_VAR_50->toStr = rope__toStr;
____BAH_COMPILER_VAR_50->add = rope__add;
struct rope* tmp =  ____BAH_COMPILER_VAR_50;
tmp->parent =  null;
tmp->left =  this;
tmp->right =  root2;
root2->parent =  tmp;
this->parent =  root2->parent;
tmp->totalLen =  this->totalLen + root2->totalLen;
tmp->str =  null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_51 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_51->left= null;
____BAH_COMPILER_VAR_51->right= null;
____BAH_COMPILER_VAR_51->parent= null;
____BAH_COMPILER_VAR_51->str= null;
____BAH_COMPILER_VAR_51->getParent = rope__getParent;
____BAH_COMPILER_VAR_51->addStr = rope__addStr;
____BAH_COMPILER_VAR_51->toStr = rope__toStr;
____BAH_COMPILER_VAR_51->add = rope__add;
struct rope* tmp =  ____BAH_COMPILER_VAR_51;
tmp->left =  null;
tmp->right =  null;
tmp->parent =  par;
if ((r - l>ROPE_LEAF_LEN)) {
tmp->str =  null;
tmp->lCount =  r - l;
tmp->lCount =  tmp->lCount / 2;
struct rope* node =  tmp;
long int m =  l + r;
m =  m / 2;
node->left =  createRopeStructure(node,a,l,m);
node->right =  createRopeStructure(node,a,m + 1,r);
}
else {
struct rope* node =  tmp;
tmp->lCount =  r - l;
long int j =  0;
long int i =  l;
char * arr =  memoryAlloc(ROPE_LEAF_LEN + 1);
while ((i<=r)) {
arr[j]=a[i];
j =  j + 1;
i =  i + 1;
};
tmp->str =  arr;
}
return tmp;
};
void ropeSet(struct rope* r,char * a){
long int n1 =  strlen(a);
struct rope* nr =  createRopeStructure(null,a,0,n1-1);
nr->totalLen =  n1;
nr->len =  n1;
*r =  *nr;
};
//optimized out: concatenateRopes
struct rope* rope(char * a){
long int n1 =  strlen(a);
struct rope* r =  createRopeStructure(null,a,0,n1-1);
r->totalLen =  n1;
r->len =  n1;
return r;
};
struct command {
char * command;
int error;
long int status;
char * input;
FILE* handle;
char *(*run)(struct command* this);
array(char)*(*runBytes)(struct command* this);
};
char * command__run(struct command* this){
char * cm =  this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_53 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                    ____BAH_COMPILER_VAR_53 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_53+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_53+currStrOff, " 2>/dev/null", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                cm =  ____BAH_COMPILER_VAR_53;
}
else {
char * ____BAH_COMPILER_VAR_54 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                    ____BAH_COMPILER_VAR_54 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_54+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_54+currStrOff, " 2>&1", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                cm =  ____BAH_COMPILER_VAR_54;
}
this->handle =  popen(cm,"w");
if ((this->handle==null)) {
return "";
}
if ((strcmp(this->input, null) != 0)) {
fputs(this->input,(void *)this->handle);
}
char * buff =  memoryAlloc(1025);
char * res =  "";
while (((void *)fgets(buff,1024,this->handle)!=null)) {
char * ____BAH_COMPILER_VAR_55 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(res);
long int strLen_1 = strlen(buff);
;                            
                    ____BAH_COMPILER_VAR_55 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_55+currStrOff, res, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_55+currStrOff, buff, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                res =  ____BAH_COMPILER_VAR_55;
};
this->status =  pclose(this->handle);
return res;
};
__BAH_ARR_TYPE_char command__runBytes(struct command* this){
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
char * cm =  this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_56 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                    ____BAH_COMPILER_VAR_56 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_56+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_56+currStrOff, " 2>/dev/null", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                cm =  ____BAH_COMPILER_VAR_56;
}
else {
char * ____BAH_COMPILER_VAR_57 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                    ____BAH_COMPILER_VAR_57 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_57+currStrOff, cm, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_57+currStrOff, " 2>&1", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                cm =  ____BAH_COMPILER_VAR_57;
}
this->handle =  popen(cm,"r");
if ((this->handle==null)) {
return arr;
}
char * buffer =  memoryAlloc(1025);
long int total =  0;
long int fd =  fileno(this->handle);
char * buff =  memoryAlloc(1024);
char * response =  "";
void * res =  fgets(buff,1023,this->handle);
while ((res!=null)) {
char * ____BAH_COMPILER_VAR_58 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(response);
long int strLen_1 = strlen(buff);
;                            
                    ____BAH_COMPILER_VAR_58 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_58+currStrOff, response, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_58+currStrOff, buff, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                response =  ____BAH_COMPILER_VAR_58;
res =  fgets(buff,1023,this->handle);
};
this->status =  pclose(this->handle);
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
struct command cmd =  ____BAH_COMPILER_VAR_59;
cmd.command =  s;
return cmd;
};
//optimized out: exec
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.1 (build 70)"
int debug;
int verboseRuntime;
int isObject;
char * execName;
int isSubObject;
struct rope* OUTPUT;
char * NEXT_LINE;
struct rope* INIT;
struct variable {
char * name;
char * type;
int isConst;
char * constVal;
int isArray;
char * from;
int outterScope;
int isGlobal;
};
struct structMemb {
char * name;
char * type;
int isConst;
char * constVal;
int isArray;
char * from;
int outterScope;
int isGlobal;
char * def;
int isFn;
};
struct func {
char * name;
array(struct variable*)* args;
struct variable* returns;
int returned;
int isBinding;
char * from;
char * file;
long int line;
int used;
struct rope* code;
};
struct cStruct {
char * name;
array(struct structMemb*)* members;
array(struct func*)* methods;
char * postCode;
int print;
char * extendedFrom;
int isBinding;
int hasRCPmemb;
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
int isBranch;
int isFor;
array(char *)* arrTypesDecl;
int haveEntryPoint;
array(struct variable*)* RCPvars;
array(char *)* evals;
int hasImports;
};
int shouldOnlyDecl;
struct compilerStateTag compilerState;
struct cStruct* currentCStruct;
long int threadCount;
struct func* currentFn;
long int totalLines;
long int totalLexerTime;
int RCPenabled;
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
int isValue;
int isFunc;
int isOper;
};
int inArray(char needle,__BAH_ARR_TYPE_char arr){
long int i =  0;
while ((i<len(arr))) {

                    if (arr->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:38): arr[%d] with length %d\n", i, arr->length);
                        exit(1);
                    };
                    if ((needle==arr->data[i])) {
return true;
}
i =  i + 1;
};
return false;
};
int inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){
long int i =  0;
while ((i<len(arr))) {

                    if (arr->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:48): arr[%d] with length %d\n", i, arr->length);
                        exit(1);
                    };
                    if ((strcmp(needle, arr->data[i]) == 0)) {
return true;
}
i =  i + 1;
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
struct Tok t =  ____BAH_COMPILER_VAR_60;
t.cont =  arrToStr(cont);
t.ogCont =  t.cont;
clear(cont);
t.pos =  pos;
t.line =  lineNb;
t.type =  type;
if ((type==TOKEN_TYPE_INT)) {
t.isValue =  true;
}
else if ((type==TOKEN_TYPE_STR)) {
t.isValue =  true;
}
else if ((type==TOKEN_TYPE_FLOAT)) {
t.isValue =  true;
}
else if ((type==TOKEN_TYPE_VAR)) {
t.isValue =  true;
}
if ((type==TOKEN_TYPE_BOOL)) {
t.isValue =  true;
}
else if ((type==TOKEN_TYPE_CHAR)) {
t.isValue =  true;
}
return t;
};
int isMinus(char c,char nc){
return ((c==45)&&isNumber(nc));
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr =  intToStr(line);
char * posStr =  intToStr(pos);
char * ____BAH_COMPILER_VAR_61 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[LEXER-ERROR]\e[0m ");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(lineStr);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(posStr);
long int strLen_6 = strlen("\n\e[0m\n");
long int strLen_7 = strlen(msg);
;                            
                    ____BAH_COMPILER_VAR_61 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    strncpy(____BAH_COMPILER_VAR_61+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_61+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_61+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_61+currStrOff, lineStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_61+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_61+currStrOff, posStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_61+currStrOff, "\n\e[0m\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_61+currStrOff, msg, strLen_7);
                    currStrOff += strLen_7;
                    
                }
                println(____BAH_COMPILER_VAR_61);
exit(1);
};
array(char)* enclavers;
array(char)* syntaxes;
array(char *)* keywords;
array(char)* varChars;
array(char)* seps;
typedef array(struct Tok)* __BAH_ARR_TYPE_Tok;
__BAH_ARR_TYPE_Tok lexer(char * os){
long int dur =  getTimeUnix();
array(char)* s =  strAsArr(os);
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int codeLength =  len(s);
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);
long int lineNb =  1;
long int i =  0;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:114): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    char c =  s->data[i];
char nc =  (char)0;
if ((i + 1<codeLength)) {

                    if (s->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:117): s[%d] with length %d\n", i + 1, s->length);
                        exit(1);
                    };
                    nc =  s->data[i + 1];
}
if ((c==47)) {

                    if (s->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:121): s[%d] with length %d\n", i + 1, s->length);
                        exit(1);
                    };
                    nc =  s->data[i + 1];
if ((nc==47)) {
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:125): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
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
lineNb =  lineNb+1;
}
if ((c==(char)34)) {
long int pos =  i;
long int begLine =  lineNb;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};
i =  i + 1;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:149): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];

                    if (s->length <= i-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:150): s[%d] with length %d\n", i-1, s->length);
                        exit(1);
                    };
                    char pc =  s->data[i-1];
if ((c==(char)34)) {
if ((pc!=(char)92)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
break;
}
}
if ((c==(char)10)) {
lineNb =  lineNb + 1;
if ((pc!=(char)92)) {

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  (char)92;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  (char)92;
}
};
c =  110;
}
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
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
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
}
};

                    if (tokens->length <= len(tokens) - 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:170): tokens[%d] with length %d\n", len(tokens) - 1, tokens->length);
                        exit(1);
                    };
                    struct Tok lt =  tokens->data[len(tokens) - 1];
lt.begLine =  begLine;

{
long nLength = len(tokens) - 1;
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens) - 1] =  lt;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens) - 1] =  lt;
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
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};
long int pos =  i;
i =  i + 1;
tokenType currentType =  TOKEN_TYPE_INT;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:179): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
if ((c==(char)46)) {
currentType =  TOKEN_TYPE_FLOAT;
}
else if ((isNumber(c)==0)) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
};
i =  i-1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
}
};
}
else if ((c==(char)39)) {
i =  i+1;

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:191): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    char n =  s->data[i];
char * toInt =  intToStr((long int)nc);
memory =  strToArr(toInt);
i =  i+1;

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:195): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
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
tokens->data[len(tokens)] =  makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
}
};
}
else if ((c==(char)35)) {
long int pos =  i;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};
i =  i+1;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:205): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
if ((isAlphaNumeric(c)==0)) {
break;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
};
i =  i-1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
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
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
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
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};
long int pos =  i;
i =  i+1;
char fc =  c;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:222): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];

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
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
};
i =  i-1;

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
}
};
}
else if (inArray(c,seps)) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
}
};
}
else if ((isAlphaNumeric(c)||inArray(c,varChars))) {

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[0] =  c;
memory->length = nLength+1;
} else {
memory->data[0] =  c;
}
};
long int pos =  i;
i =  i+1;
for (; (i<codeLength); i =  i+1) {

                    if (s->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:257): s[%d] with length %d\n", i, s->length);
                        exit(1);
                    };
                    c =  s->data[i];
if ((isAlphaNumeric(c)==0)) {

                int ____BAH_COMPILER_VAR_63 = 0;
                for(int i=len(varChars)-1; i != -1; i--) {
                    if (varChars->data[i] == c) {
                        ____BAH_COMPILER_VAR_63 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_63==false)) {
if ((c==62)) {

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:261): memory[%d] with length %d\n", len(memory)-1, memory->length);
                        exit(1);
                    };
                    char lc =  memory->data[len(memory)-1];
if ((lc==45)) {

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)-1] =  (char)0;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] =  (char)0;
}
};
i =  i-1;
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
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
};
i =  i-1;
tokenType currentType =  TOKEN_TYPE_VAR;
char * memstr =  arrAsStr(memory);

                int ____BAH_COMPILER_VAR_64 = 0;
                for(int i=len(keywords)-1; i != -1; i--) {
                    if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                        ____BAH_COMPILER_VAR_64 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_64) {
currentType =  TOKEN_TYPE_KEYWORD;
}

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  makeToken(pos,lineNb,memory,currentType);
}
};
}
};
totalLines =  totalLines + lineNb - 1;
dur =  getTimeUnix() - dur;
totalLexerTime =  totalLexerTime + dur;
return tokens;
};
int hasStructSep(struct string n){
if (n.count((struct string*)&n,".")) {
return true;
}
if (n.count((struct string*)&n,"->")) {
return true;
}
return false;
};
struct string splitStructSepBefore(struct string n){
if (n.count((struct string*)&n,".")) {
char * ____BAH_COMPILER_VAR_65 =splitStringBefore(n,".");struct string res =  string(____BAH_COMPILER_VAR_65);
return res;
}
if (n.count((struct string*)&n,"->")) {
char * ____BAH_COMPILER_VAR_66 =splitStringBefore(n,"->");struct string res =  string(____BAH_COMPILER_VAR_66);
return res;
}
return string("");
};
struct string splitStructSepAfter(struct string n){
long int i =  n.length;
while ((i>0)) {
char c =  n.charAt((struct string*)&n,i);
if ((c==46)) {
break;
}
else if ((c==62)) {
char pc =  n.charAt((struct string*)&n,i-1);
if ((pc==45)) {
break;
}
}
i =  i - 1;
};
i =  i + 1;
n.trimLeft((struct string*)&n,i);
return n;
};
struct cStruct* searchStruct(char * name,struct Elems* elems){
struct string n =  string(name);
n.replace((struct string*)&n,"&","");
n.replace((struct string*)&n,"*","");
name =  n.content;
long int i =  0;
while ((i<len(elems->structs))) {

                    if (elems->structs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/struct.bah:54): elems->structs[%d] with length %d\n", i, elems->structs->length);
                        exit(1);
                    };
                    struct cStruct* s =  elems->structs->data[i];
if ((strcmp(s->name, name) == 0)) {
return s;
}
i =  i + 1;
};
return null;
};
struct structMemb* searchStructMemb(char * name,struct cStruct* s,struct Elems* elems){
struct string n =  string(name);
if (hasStructSep(n)) {
struct string rn =  splitStructSepBefore(n);
name =  rn.content;
n.trimLeft((struct string*)&n,rn.length);
if (n.hasPrefix((struct string*)&n,".")) {
n.trimLeft((struct string*)&n,1);
}
else {
n.trimLeft((struct string*)&n,2);
}
char * membs =  n.content;
struct structMemb* memb =  searchStructMemb(name,s,elems);
if ((n.length>0)) {
s =  searchStruct(memb->type,elems);
char * nstr =  n.str((struct string*)&n);
memb =  searchStructMemb(nstr,s,elems);
}
return memb;
}
array(struct structMemb*)* members =  s->members;
long int i =  0;
while ((i<len(members))) {

                    if (members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/struct.bah:86): members[%d] with length %d\n", i, members->length);
                        exit(1);
                    };
                    struct structMemb* m =  members->data[i];
if ((strcmp(m->name, name) == 0)) {
return m;
}
i =  i + 1;
};
array(struct func*)* mthds =  s->methods;
i =  0;
while ((i<len(mthds))) {

                    if (mthds->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/struct.bah:94): mthds[%d] with length %d\n", i, mthds->length);
                        exit(1);
                    };
                    struct func* m =  mthds->data[i];
if ((strcmp(m->name, name) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_67 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_67->name = "";
____BAH_COMPILER_VAR_67->type = "";
____BAH_COMPILER_VAR_67->isConst = false;
____BAH_COMPILER_VAR_67->constVal = "";
____BAH_COMPILER_VAR_67->isArray = false;
____BAH_COMPILER_VAR_67->from = "";
____BAH_COMPILER_VAR_67->outterScope = false;
____BAH_COMPILER_VAR_67->isGlobal = false;
____BAH_COMPILER_VAR_67->def = "";
____BAH_COMPILER_VAR_67->isFn = false;
struct structMemb* sm =  ____BAH_COMPILER_VAR_67;
sm->name =  m->name;
sm->from =  m->from;
sm->type =  m->returns->type;
sm->isFn =  true;
return sm;
}
i =  i + 1;
};
if ((strlen(s->extendedFrom)==0)) {
return null;
}
struct cStruct* es =  searchStruct(s->extendedFrom,elems);
return searchStructMemb(name,es,elems);
};
int isRCPpointerType(char * t){
if (strHasPrefix(t,"function(")) {
return false;
}
if (((((((strcmp(t, "cpstring") == 0)||(strcmp(t, "ptr") == 0))||(strCount(t,"*")>0))||(strHasPrefix(t,"[]")==true))||(strHasPrefix(t,"chan:")==true))||(strHasPrefix(t,"map:")==true))) {
return true;
}
return false;
};
int isRCPtype(char * t,struct Elems* elems){
if ((isRCPpointerType(t)==true)) {
return true;
}
struct cStruct* s =  searchStruct(t,elems);
if ((((s!=null)&&(s->isBinding==false))&&(s->hasRCPmemb==true))) {
return true;
}
return false;
};
struct string getCType(char * t,struct Elems* elems){
if ((strlen(t)==0)) {
return string("void");
}
struct string tp =  string(t);
tp.replace((struct string*)&tp," ","");
if (tp.hasPrefix((struct string*)&tp,"[]")) {
tp.trimLeft((struct string*)&tp,2);
char * tpstr =  tp.str((struct string*)&tp);
tp =  getCType(tpstr,elems);
t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_68 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("array(");
long int strLen_1 = strlen(t);
long int strLen_2 = strlen(")*");
;                            
                    ____BAH_COMPILER_VAR_68 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_68+currStrOff, "array(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_68+currStrOff, t, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_68+currStrOff, ")*", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                char * r =  ____BAH_COMPILER_VAR_68;
return string(r);
}
struct string ctp =  tp;
ctp.replace((struct string*)&ctp,"*","");
if ((tp.hasPrefix((struct string*)&tp,"chan:")==1)) {
tp.set((struct string*)&tp,"struct channel *");
}
else if ((tp.hasPrefix((struct string*)&tp,"map:")==1)) {
tp.set((struct string*)&tp,"struct mapWrapper *");
}
else if (ctp.compare((struct string*)&ctp,"int")) {
tp.replace((struct string*)&tp,"int","long int");
}
else if (ctp.compare((struct string*)&ctp,"int32")) {
tp.replace((struct string*)&tp,"int32","int");
}
else if (ctp.compare((struct string*)&ctp,"uint32")) {
tp.replace((struct string*)&tp,"uint32","unsigned int");
}
else if (ctp.compare((struct string*)&ctp,"uint")) {
tp.replace((struct string*)&tp,"uint","unsigned long int");
}
else if (ctp.compare((struct string*)&ctp,"float32")) {
tp.replace((struct string*)&tp,"float32","float");
}
else if (ctp.compare((struct string*)&ctp,"ufloat32")) {
tp.replace((struct string*)&tp,"ufloat32","unsigned float");
}
else if (ctp.compare((struct string*)&ctp,"ufloat")) {
tp.replace((struct string*)&tp,"ufloat","unsigned double");
}
else if (ctp.compare((struct string*)&ctp,"float")) {
tp.replace((struct string*)&tp,"float","double");
}
else if (ctp.compare((struct string*)&ctp,"long")) {
tp.replace((struct string*)&tp,"long","long long");
}
else if (ctp.compare((struct string*)&ctp,"ulong")) {
tp.replace((struct string*)&tp,"ulong","unsigned long long");
}
else if (ctp.compare((struct string*)&ctp,"cpstring")) {
tp.replace((struct string*)&tp,"cpstring","char *");
}
else if (ctp.compare((struct string*)&ctp,"ptr")) {
tp.replace((struct string*)&tp,"ptr","void *");
}
else if (ctp.compare((struct string*)&ctp,"ushort")) {
tp.replace((struct string*)&tp,"ushort","unsigned short");
}
else if (ctp.compare((struct string*)&ctp,"byte")) {
tp.replace((struct string*)&tp,"byte","unsigned char");
}
else if (ctp.compare((struct string*)&ctp,"bool")) {
tp.replace((struct string*)&tp,"bool","int");
}
else if (ctp.compare((struct string*)&ctp,"char")) {
}
else {
char * ctpstr =  ctp.str((struct string*)&ctp);
struct cStruct* s =  searchStruct(ctpstr,elems);
if ((s!=null)) {
tp.prepend((struct string*)&tp,"struct ");
}
else {
long int i =  0;
while ((i<len(elems->types))) {

                    if (elems->types->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/type.bah:95): elems->types[%d] with length %d\n", i, elems->types->length);
                        exit(1);
                    };
                    char * ct =  elems->types->data[i];
if (ctp.compare((struct string*)&ctp,ct)) {
return tp;
}
i =  i + 1;
};
return string("");
}
}
return tp;
};
int compTypes(char * a,char * b){
if ((strcmp(a, "ptr") == 0)) {
return true;
}
if ((strcmp(b, "ptr") == 0)) {
return true;
}
if ((strcmp(a, b) == 0)) {
return true;
}
return false;
};
#include <stddef.h>
struct reflectElement {
long int size;
char * type;
char * name;
int isArray;
struct reflectElement* arrayElem;
int isStruct;
array(struct reflectElement)* structLayout;
long int offset;
void * value;
void *(*calculateOffset)(struct reflectElement* this,void * origin);
};
void * reflectElement__calculateOffset(struct reflectElement* this,void * origin){
char * base =  origin;
return base+this->offset;
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,int isArr,struct reflectElement* ae,int isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement ____BAH_COMPILER_VAR_69 = {};
____BAH_COMPILER_VAR_69.type= null;
____BAH_COMPILER_VAR_69.name= null;
____BAH_COMPILER_VAR_69.arrayElem= null;
____BAH_COMPILER_VAR_69.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_69.structLayout->length = 0;
            ____BAH_COMPILER_VAR_69.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_69.value= null;
____BAH_COMPILER_VAR_69.calculateOffset = reflectElement__calculateOffset;
struct reflectElement re =  ____BAH_COMPILER_VAR_69;
re.size =  s;
re.type =  t;
re.name =  n;
re.isArray =  isArr;
re.arrayElem =  ae;
re.isStruct =  isStruct;
re.structLayout =  sl;
re.value =  v;
re.offset =  offset;
return re;
};
typedef void * reflectSymbols;
__BAH_ARR_TYPE_reflectElement __dumpSymbols(__BAH_ARR_TYPE_reflectElement syms){
return syms;
};
struct reflectElement __debug_get_sym(__BAH_ARR_TYPE_reflectElement syms,struct string a){
if ((a.count((struct string*)&a,".")>0)) {
array(struct string)* parts =  splitString(a,".");

                    if (parts->length <= 0) {
                        printf("array (/opt/bah/reflect.bah:63): parts[%d] with length %d\n", 0, parts->length);
                        exit(1);
                    };
                    struct string p1 =  parts->data[0];

                    if (parts->length <= 1) {
                        printf("array (/opt/bah/reflect.bah:64): parts[%d] with length %d\n", 1, parts->length);
                        exit(1);
                    };
                    struct string p2 =  parts->data[1];
long int j =  0;
for (; (j<len(syms)); j =  j+1) {

                    if (syms->length <= j) {
                        printf("array (/opt/bah/reflect.bah:66): syms[%d] with length %d\n", j, syms->length);
                        exit(1);
                    };
                    struct reflectElement s =  syms->data[j];
if ((strcmp(s.name, p1.str((struct string*)&p1)) == 0)) {
long int k =  0;
for (; (k<len(s.structLayout)); k =  k+1) {

                    if (s.structLayout->length <= k) {
                        printf("array (/opt/bah/reflect.bah:69): s.structLayout[%d] with length %d\n", k, s.structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  s.structLayout->data[k];
if ((strcmp(m.name, p2.str((struct string*)&p2)) == 0)) {
m.value =  m.calculateOffset((struct reflectElement*)&m,s.value);
return m;
}
};
break;
}
};
}
else {
long int j =  0;
for (; (j<len(syms)); j =  j+1) {

                    if (syms->length <= j) {
                        printf("array (/opt/bah/reflect.bah:80): syms[%d] with length %d\n", j, syms->length);
                        exit(1);
                    };
                    struct reflectElement s =  syms->data[j];
if ((strcmp(s.name, a.str((struct string*)&a)) == 0)) {
return s;
}
};
}
struct reflectElement ____BAH_COMPILER_VAR_70 = {};
____BAH_COMPILER_VAR_70.type= null;
____BAH_COMPILER_VAR_70.name= null;
____BAH_COMPILER_VAR_70.arrayElem= null;
____BAH_COMPILER_VAR_70.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_70.structLayout->length = 0;
            ____BAH_COMPILER_VAR_70.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_70.value= null;
____BAH_COMPILER_VAR_70.calculateOffset = reflectElement__calculateOffset;
struct reflectElement ns =  ____BAH_COMPILER_VAR_70;
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
void json_scan_inner(void * this,struct reflectElement e,int isMember);
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
long int l =  len(this->children);
long int i =  0;
while ((i<l)) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:29): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* elem =  this->children->data[i];
char fc =  cpstringCharAt(elem->key,0);
if ((fc==(char)34)) {
array(char)* nk = memoryAlloc(sizeof(array(char)));

nk->length = 0;
nk->elemSize = sizeof(char);
long int lk =  strlen(elem->key);
long int j =  1;
while ((j<lk - 1)) {
char c =  cpstringCharAt(elem->key,j);

{
long nLength = j-1;
if (nk->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nk->data, (nLength+50)*sizeof(char));
nk->data = newPtr;
}
nk->data[j-1] =  c;
nk->length = nLength+1;
} else {
nk->data[j-1] =  c;
}
};
j =  j + 1;
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
i =  i + 1;
};
void * z =  (void *)0;
return z;
};
char * jsonElement__str(struct jsonElement* this){
char * ctn =  this->content;
return ctn;
};
void jsonElement__scan(struct jsonElement* this,struct reflectElement e){
json_scan_inner(this,e,false);
};
void json_scan_inner(void * thisp,struct reflectElement e,int isMember){
struct jsonElement* this =  thisp;
if ((e.isStruct==true)) {
long int i =  0;
while ((i<len(e.structLayout))) {

                    if (e.structLayout->length <= i) {
                        printf("array (/opt/bah/json.bah:71): e.structLayout[%d] with length %d\n", i, e.structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  e.structLayout->data[i];
struct jsonElement* ov =  this->get((struct jsonElement*)this,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
i =  i + 1;
};
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ep =  e.value;
*ep =  strToInt(this->content);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
char ** ep =  e.value;
*ep =  memoryAlloc(strlen(this->content) + 1);
strcpy(*ep,this->content);
}
else if ((strcmp(e.type, "float") == 0)) {
double* ep =  e.value;
*ep =  strToFloat(this->content);
}
else if ((strcmp(e.type, "bool") == 0)) {
int* ep =  e.value;
if (((strcmp(this->content, "1") == 0)||(strcmp(this->content, "true") == 0))) {
*ep =  true;
}
else {
*ep =  false;
}
}
else if ((e.isArray==true)) {
if ((len(this->children)==0)) {
return;
}
struct reflectElement* ae =  e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:106): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(long int));
arr->data = newPtr;
}
arr->data[i] =  strToInt(c->content);
arr->length = nLength+1;
} else {
arr->data[i] =  strToInt(c->content);
}
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
if ((isMember==true)) {
void ** arrPtr =  e.value;
arr =  *arrPtr;
}
else {
arr =  e.value;
}
long int i =  0;
while ((i<len(this->children))) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:119): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(double));
arr->data = newPtr;
}
arr->data[i] =  strToFloat(c->content);
arr->length = nLength+1;
} else {
arr->data[i] =  strToFloat(c->content);
}
};
i =  i + 1;
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:128): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* c =  this->children->data[i];

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(char *));
arr->data = newPtr;
}
arr->data[i] =  memoryAlloc(strlen(c->content) + 1);
arr->length = nLength+1;
} else {
arr->data[i] =  memoryAlloc(strlen(c->content) + 1);
}
};
strcpy(arr->data[i],c->content);
i =  i + 1;
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:138): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* c =  this->children->data[i];
void * ne =  memoryAlloc(ae->size);
long int j =  0;
while ((j<len(ae->structLayout))) {

                    if (ae->structLayout->length <= j) {
                        printf("array (/opt/bah/json.bah:141): ae->structLayout[%d] with length %d\n", j, ae->structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,ne);
struct jsonElement* ov =  c->get((struct jsonElement*)c,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
j =  j + 1;
};

{
long nLength = i;
if (arr->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arr->data, (nLength+50)*sizeof(void *));
arr->data = newPtr;
}
arr->data[i] =  ne;
arr->length = nLength+1;
} else {
arr->data[i] =  ne;
}
};
i =  i + 1;
};
}
}
else if (strHasPrefix(e.type,"map:")) {
struct mapWrapper** p =  e.value;
long int i =  0;
for (; (i<len(this->children)); i =  i+1) {

                    if (this->children->length <= i) {
                        printf("array (/opt/bah/json.bah:156): this->children[%d] with length %d\n", i, this->children->length);
                        exit(1);
                    };
                    struct jsonElement* c =  this->children->data[i];
struct reflectElement* ae =  e.arrayElem;
void * v =  memoryAlloc(ae->size);
ae->value =  &v;
long int j =  0;
for (; (j<len(ae->structLayout)); j =  j+1) {

                    if (ae->structLayout->length <= j) {
                        printf("array (/opt/bah/json.bah:161): ae->structLayout[%d] with length %d\n", j, ae->structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,&v);

{
long nLength = j;
if (ae->structLayout->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ae->structLayout->data, (nLength+50)*sizeof(struct reflectElement));
ae->structLayout->data = newPtr;
}
ae->structLayout->data[j] =  m;
ae->structLayout->length = nLength+1;
} else {
ae->structLayout->data[j] =  m;
}
};
};
json_scan_inner(c,*ae,true);
struct string k =  string(c->key);
k.trimLeft((struct string*)&k,1);
k.trimRight((struct string*)&k,1);
if (((((strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0))||(strcmp(ae->type, "cpstring") == 0))||strHasPrefix(ae->type,"[]"))||strHasPrefix(ae->type,"map:"))) {
char * ____BAH_COMPILER_VAR_71 =k.str((struct string*)&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_71,v);
}
else {
char * ____BAH_COMPILER_VAR_72 =k.str((struct string*)&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_72,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_73 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_73->key= null;
____BAH_COMPILER_VAR_73->content= null;
____BAH_COMPILER_VAR_73->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_73->children->length = 0;
            ____BAH_COMPILER_VAR_73->children->elemSize = sizeof(struct jsonElement*);
            ____BAH_COMPILER_VAR_73->get = jsonElement__get;
____BAH_COMPILER_VAR_73->str = jsonElement__str;
____BAH_COMPILER_VAR_73->scan = jsonElement__scan;
struct jsonElement* jsonElem =  ____BAH_COMPILER_VAR_73;
long int lenS =  strlen(s);
long int i =  0;
while ((i<lenS)) {
if ((isSpace(cpstringCharAt(s,i))==0)) {
break;
}
i =  i + 1;
};
char fc =  cpstringCharAt(s,i);
if ((fc==91)) {
jsonElem->type =  JSON_TYPE_ARRAY;
}
else if ((fc==123)) {
jsonElem->type =  JSON_TYPE_MAP;
}
else if ((fc==(char)34)) {
jsonElem->type =  JSON_TYPE_STRING;
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
i =  i + 1;
long int start =  i;
while ((i<lenS - 1)) {
char c =  cpstringCharAt(s,i);
if (((i>start)&&(cpstringCharAt(s,i-1)==(char)92))) {
if ((c==110)) {
c =  (char)10;
}
else if ((c==114)) {
c =  (char)13;
}

{
long nLength = len(ns)-1;
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)-1] =  c;
ns->length = nLength+1;
} else {
ns->data[len(ns)-1] =  c;
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
ns->data[len(ns)] =  c;
ns->length = nLength+1;
} else {
ns->data[len(ns)] =  c;
}
};
}
i =  i + 1;
};
jsonElem->content =  arrToStr(ns);
}
else if (isNumber(cpstringCharAt(s,strlen(s)-1))) {
int isFloat =  false;
while ((i<lenS)) {
if ((cpstringCharAt(s,i)==46)) {
isFloat =  true;
break;
}
i =  i + 1;
};
if ((isFloat==true)) {
jsonElem->type =  JSON_TYPE_FLOAT;
}
else {
jsonElem->type =  JSON_TYPE_INT;
}
jsonElem->content =  s;
}
else {
return null;
}
if ((jsonElem->type==JSON_TYPE_ARRAY)) {
i =  i + 1;
long int trim =  1;
long int j =  lenS-1;
while ((j>=0)) {
char c =  cpstringCharAt(s,j);
if (isSpace(c)) {
trim =  trim + 1;
}
else {
break;
}
j =  j - 1;
};
while ((i<lenS - 1)) {
char c =  cpstringCharAt(s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
long int currentBracks =  0;
long int currentBraces =  0;
long int currentQuotes =  0;
long int elemIndex =  0;
while ((i<lenS - trim)) {
char c =  cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes =  1;
}
else {
currentQuotes =  0;
}
}
else if ((c==91)) {
currentBracks =  currentBracks + 1;
}
else if ((c==93)) {
currentBracks =  currentBracks - 1;
}
else if ((c==123)) {
currentBraces =  currentBraces + 1;
}
else if ((c==125)) {
currentBraces =  currentBraces - 1;
}
long int total =  currentBracks + currentBraces + currentQuotes;
if ((total>0)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
}
};
i =  i + 1;
continue;
}
if ((c==44)) {
char * ____BAH_COMPILER_VAR_74 =arrToStr(currentElem);struct jsonElement* child =  parseJson(____BAH_COMPILER_VAR_74);
if ((child!=null)) {

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  child;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  child;
}
};
}
clear(currentElem);
elemIndex =  elemIndex + 1;
}
else {
if (isSpace(c)) {
i =  i + 1;
continue;
}

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
}
};
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_75 =arrToStr(currentElem);struct jsonElement* child =  parseJson(____BAH_COMPILER_VAR_75);
if ((child!=null)) {

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  child;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  child;
}
};
}
}
else if ((jsonElem->type==JSON_TYPE_MAP)) {
i =  i + 1;
long int trim =  1;
long int j =  lenS-1;
while ((j>=0)) {
char c =  cpstringCharAt(s,j);
if (isSpace(c)) {
trim =  trim + 1;
}
else {
break;
}
j =  j - 1;
};
while ((i<lenS - 1)) {
char c =  cpstringCharAt(s,i);
if ((isSpace(c)==0)) {
break;
}
i =  i + 1;
};
array(char)* currentElem = memoryAlloc(sizeof(array(char)));

currentElem->length = 0;
currentElem->elemSize = sizeof(char);
array(char)* currentKey = memoryAlloc(sizeof(array(char)));

currentKey->length = 0;
currentKey->elemSize = sizeof(char);
long int isVal =  0;
long int currentBracks =  0;
long int currentBraces =  0;
long int currentQuotes =  0;
long int elemIndex =  0;
while ((i<lenS - trim)) {
char c =  cpstringCharAt(s,i);
if ((c==(char)34)) {
if ((currentQuotes==0)) {
currentQuotes =  1;
}
else {
currentQuotes =  0;
}
}
else if ((c==91)) {
currentBracks =  currentBracks + 1;
}
else if ((c==93)) {
currentBracks =  currentBracks - 1;
}
else if ((c==123)) {
currentBraces =  currentBraces + 1;
}
else if ((c==125)) {
currentBraces =  currentBraces - 1;
}
long int total =  currentBracks + currentBraces + currentQuotes;
if ((total>0)) {
if ((isVal==1)) {

{
long nLength = len(currentElem);
if (currentElem->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(currentElem->data, (nLength+50)*sizeof(char));
currentElem->data = newPtr;
}
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
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
currentKey->data[len(currentKey)] =  c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] =  c;
}
};
}
i =  i + 1;
continue;
}
if ((c==58)) {
isVal =  1;
}
else if ((c==44)) {
char * ____BAH_COMPILER_VAR_76 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_76);
if ((elem!=null)) {
elem->key =  arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  elem;
}
};
elemIndex =  elemIndex + 1;
}
clear(currentElem);
clear(currentKey);
isVal =  0;
}
else {
if (isSpace(c)) {
i =  i + 1;
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
currentElem->data[len(currentElem)] =  c;
currentElem->length = nLength+1;
} else {
currentElem->data[len(currentElem)] =  c;
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
currentKey->data[len(currentKey)] =  c;
currentKey->length = nLength+1;
} else {
currentKey->data[len(currentKey)] =  c;
}
};
}
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_77 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_77);
if ((elem!=null)) {
elem->key =  arrToStr(currentKey);

{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  elem;
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  elem;
}
};
}
}
return jsonElem;
};
char * jsonEscapeStr(char * s){
array(char)* a =  strAsArr(s);
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
long int i =  0;
while ((i<len(a))) {

                    if (a->length <= i) {
                        printf("array (/opt/bah/json.bah:399): a[%d] with length %d\n", i, a->length);
                        exit(1);
                    };
                    char c =  a->data[i];
if ((c==(char)34)) {

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] =  (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] =  (char)92;
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
r->data[len(r)] =  (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] =  (char)92;
}
};

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] =  110;
r->length = nLength+1;
} else {
r->data[len(r)] =  110;
}
};
i =  i + 1;
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
r->data[len(r)] =  (char)92;
r->length = nLength+1;
} else {
r->data[len(r)] =  (char)92;
}
};

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] =  114;
r->length = nLength+1;
} else {
r->data[len(r)] =  114;
}
};
i =  i + 1;
continue;
}

{
long nLength = len(r);
if (r->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(r->data, (nLength+50)*sizeof(char));
r->data = newPtr;
}
r->data[len(r)] =  c;
r->length = nLength+1;
} else {
r->data[len(r)] =  c;
}
};
i =  i + 1;
};
return arrToStr(r);
};
char * toJson__inner(struct reflectElement e,int isMember,long int tabs){
void ** v =  e.value;
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
tabs =  tabs + 1;
char * tabsStr =  "";
long int i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_78 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                    ____BAH_COMPILER_VAR_78 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_78+currStrOff, tabsStr, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_78+currStrOff, "\t", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tabsStr =  ____BAH_COMPILER_VAR_78;
i =  i + 1;
};
char * s =  "{\n";
i =  0;
while ((i<len(e.structLayout))) {

                    if (e.structLayout->length <= i) {
                        printf("array (/opt/bah/json.bah:444): e.structLayout[%d] with length %d\n", i, e.structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  e.structLayout->data[i];
i =  i + 1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_79 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_80 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_79);
long int strLen_6 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_80 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_80+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_80+currStrOff, tabsStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_80+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_80+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_80+currStrOff, "\": ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_80+currStrOff, ____BAH_COMPILER_VAR_79, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_80+currStrOff, ",\n", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                s =  ____BAH_COMPILER_VAR_80;
}
else {
char * ____BAH_COMPILER_VAR_81 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_82 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_81);
long int strLen_6 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_82 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_82+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_82+currStrOff, tabsStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_82+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_82+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_82+currStrOff, "\": ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_82+currStrOff, ____BAH_COMPILER_VAR_81, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_82+currStrOff, "\n", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                s =  ____BAH_COMPILER_VAR_82;
}
};
tabs =  tabs - 1;
tabsStr =  "";
i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_83 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                    ____BAH_COMPILER_VAR_83 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_83+currStrOff, tabsStr, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_83+currStrOff, "\t", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tabsStr =  ____BAH_COMPILER_VAR_83;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_84 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_84 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_84+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_84+currStrOff, tabsStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_84+currStrOff, "}", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                s =  ____BAH_COMPILER_VAR_84;
return s;
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ip =  e.value;
return intToStr(*ip);
}
else if ((strcmp(e.type, "float") == 0)) {
double* fp =  e.value;
return floatToStr(*fp);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
if ((isMember==false)) {
void * s =  e.value;
char * ____BAH_COMPILER_VAR_85 =jsonEscapeStr(s);char * ____BAH_COMPILER_VAR_86 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_85);
long int strLen_2 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_86 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_86+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_86+currStrOff, ____BAH_COMPILER_VAR_85, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_86+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                return ____BAH_COMPILER_VAR_86;
}
else {
char ** sp =  e.value;
char * s =  *sp;
char * ____BAH_COMPILER_VAR_87 =jsonEscapeStr(s);char * ____BAH_COMPILER_VAR_88 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_87);
long int strLen_2 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_88 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_88+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_88+currStrOff, ____BAH_COMPILER_VAR_87, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_88+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                return ____BAH_COMPILER_VAR_88;
}
}
else if ((strcmp(e.type, "bool") == 0)) {
int* bp =  e.value;
if ((*bp==true)) {
return "true";
}
return "false";
}
else if ((e.isArray==true)) {
char * s =  "[";
struct reflectElement* ae =  e.arrayElem;
if ((strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_89 =intToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_90 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_89);
;                            
                    ____BAH_COMPILER_VAR_90 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_90+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_90+currStrOff, ____BAH_COMPILER_VAR_89, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_90;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_91 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_91 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_91+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_91+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_91;
}
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_92 =floatToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_93 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_92);
;                            
                    ____BAH_COMPILER_VAR_93 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_93+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_93+currStrOff, ____BAH_COMPILER_VAR_92, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_93;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_94 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_94 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_94+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_94+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_94;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
char * ____BAH_COMPILER_VAR_95 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_95 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_95+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_95+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_95;
long int i =  0;
while ((i<len(arr))) {

                    if (arr->length <= i) {
                        printf("array (/opt/bah/json.bah:512): arr[%d] with length %d\n", i, arr->length);
                        exit(1);
                    };
                    char * ____BAH_COMPILER_VAR_96 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(arr->data[i]);
;                            
                    ____BAH_COMPILER_VAR_96 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_96+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_96+currStrOff, arr->data[i], strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_96;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_97 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_97 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_97+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_97+currStrOff, ",\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_97;
}
else {
char * ____BAH_COMPILER_VAR_98 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_98 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_98+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_98+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_98;
}
};
}
else if ((ae->isStruct==true)) {
array(void *)* arr = memoryAlloc(sizeof(array(void *)));

arr->length = 0;
arr->elemSize = sizeof(void *);
if ((isMember==false)) {
arr =  e.value;
}
else {
void ** ev =  e.value;
arr =  *ev;
}
long int i =  0;
while ((i<len(arr))) {

                    if (arr->length <= i) {
                        printf("array (/opt/bah/json.bah:532): arr[%d] with length %d\n", i, arr->length);
                        exit(1);
                    };
                    void * arrElem =  arr->data[i];
ae->value =  arrElem;
long int j =  0;
while ((j<len(ae->structLayout))) {

                    if (ae->structLayout->length <= j) {
                        printf("array (/opt/bah/json.bah:535): ae->structLayout[%d] with length %d\n", j, ae->structLayout->length);
                        exit(1);
                    };
                    struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,ae->value);

{
long nLength = j;
if (ae->structLayout->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ae->structLayout->data, (nLength+50)*sizeof(struct reflectElement));
ae->structLayout->data = newPtr;
}
ae->structLayout->data[j] =  m;
ae->structLayout->length = nLength+1;
} else {
ae->structLayout->data[j] =  m;
}
};
j =  j + 1;
};
char * ____BAH_COMPILER_VAR_99 =toJson__inner(*ae,false,tabs);char * ____BAH_COMPILER_VAR_100 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_99);
;                            
                    ____BAH_COMPILER_VAR_100 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_100+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_100+currStrOff, ____BAH_COMPILER_VAR_99, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_100;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_101 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_101 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_101+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_101+currStrOff, ",\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_101;
}
else {
char * ____BAH_COMPILER_VAR_102 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_102 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_102+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_102+currStrOff, "\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_102;
}
};
}
char * ____BAH_COMPILER_VAR_103 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s);
long int strLen_1 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_103 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_103+currStrOff, s, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_103+currStrOff, "]", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                s =  ____BAH_COMPILER_VAR_103;
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
char * ____BAH_COMPILER_VAR_104 = name;
struct reflectElement ____BAH_COMPILER_VAR_105 = __reflect(____BAH_COMPILER_VAR_104, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_106 =toJson(____BAH_COMPILER_VAR_105);char * ____BAH_COMPILER_VAR_107 =intToStr(line);char * ____BAH_COMPILER_VAR_108 =toJson(e);char * ____BAH_COMPILER_VAR_109 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_106);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_107);
long int strLen_6 = strlen("\",\n        \"element\": ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_108);
long int strLen_8 = strlen("\n    },\n    ");
;                            
                    ____BAH_COMPILER_VAR_109 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    strncpy(____BAH_COMPILER_VAR_109+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_109+currStrOff, ____BAH_COMPILER_VAR_106, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_109+currStrOff, ",\n        \"path\": \"", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_109+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_109+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_109+currStrOff, ____BAH_COMPILER_VAR_107, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_109+currStrOff, "\",\n        \"element\": ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_109+currStrOff, ____BAH_COMPILER_VAR_108, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_109+currStrOff, "\n    },\n    ", strLen_8);
                    currStrOff += strLen_8;
                    
                }
                println(____BAH_COMPILER_VAR_109);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_110 = name;
struct reflectElement ____BAH_COMPILER_VAR_111 = __reflect(____BAH_COMPILER_VAR_110, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_112 =toJson(____BAH_COMPILER_VAR_111);char * ____BAH_COMPILER_VAR_113 =intToStr(line);char * ____BAH_COMPILER_VAR_114 =intToStr(from);char * ____BAH_COMPILER_VAR_115 =intToStr(to);char * ____BAH_COMPILER_VAR_116 =toJson(e);char * ____BAH_COMPILER_VAR_117 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_112);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_113);
long int strLen_6 = strlen("\",\n        \"range\": [\n            ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_114);
long int strLen_8 = strlen(",\n            ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_115);
long int strLen_10 = strlen("\n        ],\n        \"element\": ");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_116);
long int strLen_12 = strlen("\n    },\n    ");
;                            
                    ____BAH_COMPILER_VAR_117 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, ____BAH_COMPILER_VAR_112, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, ",\n        \"path\": \"", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, ____BAH_COMPILER_VAR_113, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, ____BAH_COMPILER_VAR_114, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, ",\n            ", strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, ____BAH_COMPILER_VAR_115, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, "\n        ],\n        \"element\": ", strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, ____BAH_COMPILER_VAR_116, strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_117+currStrOff, "\n    },\n    ", strLen_12);
                    currStrOff += strLen_12;
                    
                }
                println(____BAH_COMPILER_VAR_117);
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
long int i =  0;
while ((i<len(elems->vars))) {

                    if (elems->vars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/logger.bah:83): elems->vars[%d] with length %d\n", i, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[i];
if (((v->outterScope==false)&&(v->isConst==false))) {
struct variable* ____BAH_COMPILER_VAR_118 = v;
char ** ____BAH_COMPILER_VAR_120 = (char **)((char*)(____BAH_COMPILER_VAR_118) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_121 = __reflect(____BAH_COMPILER_VAR_120, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_122 = (char **)((char*)(____BAH_COMPILER_VAR_118) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_123 = __reflect(____BAH_COMPILER_VAR_122, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
int* ____BAH_COMPILER_VAR_124 = (int*)((char*)(____BAH_COMPILER_VAR_118) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_125 = __reflect(____BAH_COMPILER_VAR_124, sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_126 = (char **)((char*)(____BAH_COMPILER_VAR_118) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_127 = __reflect(____BAH_COMPILER_VAR_126, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
int* ____BAH_COMPILER_VAR_128 = (int*)((char*)(____BAH_COMPILER_VAR_118) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_129 = __reflect(____BAH_COMPILER_VAR_128, sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_130 = (char **)((char*)(____BAH_COMPILER_VAR_118) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_131 = __reflect(____BAH_COMPILER_VAR_130, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
int* ____BAH_COMPILER_VAR_132 = (int*)((char*)(____BAH_COMPILER_VAR_118) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_133 = __reflect(____BAH_COMPILER_VAR_132, sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
int* ____BAH_COMPILER_VAR_134 = (int*)((char*)(____BAH_COMPILER_VAR_118) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_135 = __reflect(____BAH_COMPILER_VAR_134, sizeof(int), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_119 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_119->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_119->length = 8;
        ____BAH_COMPILER_VAR_119->data = memoryAlloc(____BAH_COMPILER_VAR_119->length * ____BAH_COMPILER_VAR_119->elemSize);
        ____BAH_COMPILER_VAR_119->data[0] = ____BAH_COMPILER_VAR_121;
____BAH_COMPILER_VAR_119->data[1] = ____BAH_COMPILER_VAR_123;
____BAH_COMPILER_VAR_119->data[2] = ____BAH_COMPILER_VAR_125;
____BAH_COMPILER_VAR_119->data[3] = ____BAH_COMPILER_VAR_127;
____BAH_COMPILER_VAR_119->data[4] = ____BAH_COMPILER_VAR_129;
____BAH_COMPILER_VAR_119->data[5] = ____BAH_COMPILER_VAR_131;
____BAH_COMPILER_VAR_119->data[6] = ____BAH_COMPILER_VAR_133;
____BAH_COMPILER_VAR_119->data[7] = ____BAH_COMPILER_VAR_135;
struct reflectElement ____BAH_COMPILER_VAR_136 = __reflect(____BAH_COMPILER_VAR_118, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_119, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_136);
}
i =  i + 1;
};
};
void throwErr(void * tp,char * format){
char * str =  "";
char * info =  "";
long int pos =  0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_137 = {};
____BAH_COMPILER_VAR_137.handle = -1;
____BAH_COMPILER_VAR_137.p= null;
____BAH_COMPILER_VAR_137.open = fileMap__open;
____BAH_COMPILER_VAR_137.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_137.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_137;
char * fileSrcStr =  fm.open((struct fileMap*)&fm,compilerState.currentFile);
struct string fileSrc =  string(fileSrcStr);
fm.close((struct fileMap*)&fm);
struct Tok* t =  tp;
struct string ffmt =  string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont =  t->cont;
}
char * ____BAH_COMPILER_VAR_138 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("'");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_138 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_138+currStrOff, "'", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_138+currStrOff, t->ogCont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_138+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                ffmt.replace((struct string*)&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_138);
format =  ffmt.str((struct string*)&ffmt);
array(char)* line = memoryAlloc(sizeof(array(char)));

line->length = 0;
line->elemSize = sizeof(char);
long int beg =  t->pos;
while ((beg>0)) {
char c =  fileSrc.charAt((struct string*)&fileSrc,beg);
if ((c==(char)10)) {
beg =  beg + 1;
break;
}
beg =  beg - 1;
};
pos =  t->pos - beg + 1;
long int i =  beg;
while ((i<fileSrc.length)) {
char c =  fileSrc.charAt((struct string*)&fileSrc,i);
if ((c==(char)10)) {
break;
}
if ((i==t->pos)) {
char * ____BAH_COMPILER_VAR_139 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("\e[1;37m");
;                            
                    ____BAH_COMPILER_VAR_139 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_139+currStrOff, "\e[1;31m", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_139+currStrOff, t->ogCont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_139+currStrOff, "\e[1;37m", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                array(char)* errTk =  strToArr(____BAH_COMPILER_VAR_139);
long int ii =  0;
while ((ii<len(errTk))) {

                    if (errTk->length <= ii) {
                        printf("array (/home/alois/Documents/bah-bah/src/errors.bah:46): errTk[%d] with length %d\n", ii, errTk->length);
                        exit(1);
                    };
                    
{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(char));
line->data = newPtr;
}
line->data[len(line)] =  errTk->data[ii];
line->length = nLength+1;
} else {
line->data[len(line)] =  errTk->data[ii];
}
};
ii =  ii + 1;
};
i =  i + strlen(t->ogCont);
continue;
}

{
long nLength = len(line);
if (line->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(line->data, (nLength+50)*sizeof(char));
line->data = newPtr;
}
line->data[len(line)] =  c;
line->length = nLength+1;
} else {
line->data[len(line)] =  c;
}
};
i =  i + 1;
};
str =  arrToStr(line);
char * ____BAH_COMPILER_VAR_140 =intToStr(t->line);char * ____BAH_COMPILER_VAR_141 =intToStr(pos);char * ____BAH_COMPILER_VAR_142 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_140);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_141);
;                            
                    ____BAH_COMPILER_VAR_142 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_142+currStrOff, ____BAH_COMPILER_VAR_140, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_142+currStrOff, ":", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_142+currStrOff, ____BAH_COMPILER_VAR_141, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                info =  ____BAH_COMPILER_VAR_142;
}
if ((debug==true)) {
struct Tok* t =  tp;
char * ____BAH_COMPILER_VAR_143 = format;
struct reflectElement ____BAH_COMPILER_VAR_144 = __reflect(____BAH_COMPILER_VAR_143, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos + strlen(t->ogCont),____BAH_COMPILER_VAR_144);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_145 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[ERROR]\e[0m ");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(info);
long int strLen_4 = strlen("\n\e[1;37m\t");
long int strLen_5 = strlen(str);
long int strLen_6 = strlen("\e[0m\n");
long int strLen_7 = strlen(format);
;                            
                    ____BAH_COMPILER_VAR_145 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    strncpy(____BAH_COMPILER_VAR_145+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_145+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_145+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_145+currStrOff, info, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_145+currStrOff, "\n\e[1;37m\t", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_145+currStrOff, str, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_145+currStrOff, "\e[0m\n", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_145+currStrOff, format, strLen_7);
                    currStrOff += strLen_7;
                    
                }
                println(____BAH_COMPILER_VAR_145);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_146 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;33m[WARNING]\e[0m ");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen("\n\e[1;37m\t");
long int strLen_3 = strlen(s);
long int strLen_4 = strlen("\e[0m");
;                            
                    ____BAH_COMPILER_VAR_146 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_146+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_146+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_146+currStrOff, "\n\e[1;37m\t", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_146+currStrOff, s, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_146+currStrOff, "\e[0m", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                println(____BAH_COMPILER_VAR_146);
};
#include <stdlib.h>
char * absPath(char * path){
char * p =  realpath(path,null);
return p;
};
char * getCurrentPath(){
char * cwd =  memoryAlloc(4096);
getcwd(cwd,4096);
return cwd;
};
//optimized out: isInside
void setCurrentPath(char * s){
chdir(s);
};
int isGlobal(){
return (currentFn==null);
};
struct variable* searchVar(char * name,struct Elems* elems){
char * ogName =  name;
struct string n =  string(name);
n.replace((struct string*)&n,"&","");
n.replace((struct string*)&n,"*","");
if (n.hasSuffix((struct string*)&n,"]")) {
long int i =  n.length;
while ((i>0)) {
char c =  n.charAt((struct string*)&n,i);
if ((c==91)) {
break;
}
i =  i - 1;
};
long int tamm =  n.length - i;
n.trimRight((struct string*)&n,tamm + 6);
name =  n.str((struct string*)&n);
struct variable* v =  searchVar(name,elems);
struct string vt =  string(v->type);
vt.trimLeft((struct string*)&vt,2);
char * vtstr =  vt.str((struct string*)&vt);
struct variable* ____BAH_COMPILER_VAR_147 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_147->name = "";
____BAH_COMPILER_VAR_147->type = "";
____BAH_COMPILER_VAR_147->isConst = false;
____BAH_COMPILER_VAR_147->constVal = "";
____BAH_COMPILER_VAR_147->isArray = false;
____BAH_COMPILER_VAR_147->from = "";
____BAH_COMPILER_VAR_147->outterScope = false;
____BAH_COMPILER_VAR_147->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_147;
nv->type =  vtstr;
nv->name =  ogName;
nv->isArray =  true;
return nv;
}
name =  n.content;
if ((hasStructSep(n)&&(n.count((struct string*)&n,")")==0))) {
struct string rn =  splitStructSepBefore(n);
name =  rn.content;
n.trimLeft((struct string*)&n,rn.length);
if (n.hasPrefix((struct string*)&n,".")) {
n.trimLeft((struct string*)&n,1);
}
else {
n.trimLeft((struct string*)&n,2);
}
char * membs =  n.content;
struct variable* v =  searchVar(name,elems);
if ((v==null)) {
return null;
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
return null;
}
struct structMemb* memb =  searchStructMemb(membs,s,elems);
if ((memb==null)) {
return null;
}
struct variable* ____BAH_COMPILER_VAR_148 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_148->name = "";
____BAH_COMPILER_VAR_148->type = "";
____BAH_COMPILER_VAR_148->isConst = false;
____BAH_COMPILER_VAR_148->constVal = "";
____BAH_COMPILER_VAR_148->isArray = false;
____BAH_COMPILER_VAR_148->from = "";
____BAH_COMPILER_VAR_148->outterScope = false;
____BAH_COMPILER_VAR_148->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_148;
nv->from =  memb->from;
nv->name =  memb->name;
nv->type =  memb->type;
nv->name =  ogName;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
char * ____BAH_COMPILER_VAR_149 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_149 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_149+currStrOff, r, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_149+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                r =  ____BAH_COMPILER_VAR_149;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_150 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(nv->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                    ____BAH_COMPILER_VAR_150 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_150+currStrOff, "Cannot use '*' on ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_150+currStrOff, nv->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_150+currStrOff, " because it is not pointer.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(null,____BAH_COMPILER_VAR_150);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
return nv;
}
long int i =  len(elems->vars)-1;
for (; (i!=-1); i =  i-1) {

                    if (elems->vars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:96): elems->vars[%d] with length %d\n", i, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[i];
if ((v==null)) {
char * ____BAH_COMPILER_VAR_151 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null var'.");
;                            
                    ____BAH_COMPILER_VAR_151 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_151+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_151+currStrOff, name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_151+currStrOff, "' resulting in null var'.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                __BAH_panic(____BAH_COMPILER_VAR_151,"/home/alois/Documents/bah-bah/src/var.bah:98");
}
if ((strcmp(v->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_152 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_152->name = "";
____BAH_COMPILER_VAR_152->type = "";
____BAH_COMPILER_VAR_152->isConst = false;
____BAH_COMPILER_VAR_152->constVal = "";
____BAH_COMPILER_VAR_152->isArray = false;
____BAH_COMPILER_VAR_152->from = "";
____BAH_COMPILER_VAR_152->outterScope = false;
____BAH_COMPILER_VAR_152->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_152;
nv->type =  v->type;
nv->name =  v->name;
nv->isConst =  v->isConst;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
char * ____BAH_COMPILER_VAR_153 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_153 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_153+currStrOff, r, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_153+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                r =  ____BAH_COMPILER_VAR_153;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_154 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                    ____BAH_COMPILER_VAR_154 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_154+currStrOff, "Cannot use '*' on ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_154+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_154+currStrOff, " because it is not pointer.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(null,____BAH_COMPILER_VAR_154);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
return nv;
}
};
i =  0;
while ((i<len(elems->fns))) {

                    if (elems->fns->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:129): elems->fns[%d] with length %d\n", i, elems->fns->length);
                        exit(1);
                    };
                    struct func* fn =  elems->fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_155 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_155->name = "";
____BAH_COMPILER_VAR_155->type = "";
____BAH_COMPILER_VAR_155->isConst = false;
____BAH_COMPILER_VAR_155->constVal = "";
____BAH_COMPILER_VAR_155->isArray = false;
____BAH_COMPILER_VAR_155->from = "";
____BAH_COMPILER_VAR_155->outterScope = false;
____BAH_COMPILER_VAR_155->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_155;
nv->name =  name;
nv->type =  "function(";
long int j =  0;
while ((j<len(fn->args))) {

                    if (fn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:135): fn->args[%d] with length %d\n", j, fn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  fn->args->data[j];
char * ____BAH_COMPILER_VAR_156 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(arg->type);
;                            
                    ____BAH_COMPILER_VAR_156 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_156+currStrOff, nv->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_156+currStrOff, arg->type, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                nv->type =  ____BAH_COMPILER_VAR_156;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_157 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_157 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_157+currStrOff, nv->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_157+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                nv->type =  ____BAH_COMPILER_VAR_157;
}
};
fn->used =  true;
char * ____BAH_COMPILER_VAR_158 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(fn->returns->type);
;                            
                    ____BAH_COMPILER_VAR_158 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_158+currStrOff, nv->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_158+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_158+currStrOff, fn->returns->type, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                nv->type =  ____BAH_COMPILER_VAR_158;
return nv;
}
i =  i + 1;
};
return null;
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp =  getCType(v->type,elems);
char * t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_159 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
;                            
                    ____BAH_COMPILER_VAR_159 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_159+currStrOff, t, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_159+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_159+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                t =  ____BAH_COMPILER_VAR_159;
return t;
};
char * getTypeFromToken(struct Tok* t,int strict,struct Elems* elems){
if ((strlen(t->bahType)>0)) {
char * r =  t->bahType;
return r;
}
if ((t->type==TOKEN_TYPE_VAR)) {
struct variable* v =  searchVar(t->cont,elems);
if ((v==null)) {
if ((strict==true)) {
throwErr(t,"Unknown var {TOKEN}.");
}
else {
return "";
}
}
if ((strict==true)) {
if ((strlen(v->type)==0)) {
throwErr(t,"Cannot use {TOKEN} because it does not have any type.");
}
}
char * r =  v->type;
return r;
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
struct func* ____BAH_COMPILER_VAR_160 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_160->name = "";
____BAH_COMPILER_VAR_160->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_160->args->length = 0;
            ____BAH_COMPILER_VAR_160->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_160->returns= null;
____BAH_COMPILER_VAR_160->isBinding = false;
____BAH_COMPILER_VAR_160->from = "";
____BAH_COMPILER_VAR_160->file = "";
____BAH_COMPILER_VAR_160->line = 1;
____BAH_COMPILER_VAR_160->used = false;
____BAH_COMPILER_VAR_160->code = null;
struct func* nf =  ____BAH_COMPILER_VAR_160;
cvt.trimLeft((struct string*)&cvt,9);
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);
long int j =  0;
while ((j<cvt.length)) {
char c =  cvt.charAt((struct string*)&cvt,j);
if ((c==41)) {
break;
}
struct variable* ____BAH_COMPILER_VAR_161 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_161->name = "";
____BAH_COMPILER_VAR_161->type = "";
____BAH_COMPILER_VAR_161->isConst = false;
____BAH_COMPILER_VAR_161->constVal = "";
____BAH_COMPILER_VAR_161->isArray = false;
____BAH_COMPILER_VAR_161->from = "";
____BAH_COMPILER_VAR_161->outterScope = false;
____BAH_COMPILER_VAR_161->isGlobal = false;
struct variable* arg =  ____BAH_COMPILER_VAR_161;
char * ____BAH_COMPILER_VAR_162 =intToStr(len(nf->args));char * ____BAH_COMPILER_VAR_163 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("arg_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_162);
;                            
                    ____BAH_COMPILER_VAR_163 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_163+currStrOff, "arg_", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_163+currStrOff, ____BAH_COMPILER_VAR_162, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                arg->name =  ____BAH_COMPILER_VAR_163;
while ((j<cvt.length)) {
c =  cvt.charAt((struct string*)&cvt,j);
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
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
j =  j + 1;
};
arg->type =  arrToStr(memory);
clear(memory);

{
long nLength = len(nf->args);
if (nf->args->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nf->args->data, (nLength+50)*sizeof(struct variable*));
nf->args->data = newPtr;
}
nf->args->data[len(nf->args)] =  arg;
nf->args->length = nLength+1;
} else {
nf->args->data[len(nf->args)] =  arg;
}
};
if ((c==41)) {
break;
}
j =  j + 1;
};
j =  j + 1;
while ((j<cvt.length)) {
char c =  cvt.charAt((struct string*)&cvt,j);

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(char));
memory->data = newPtr;
}
memory->data[len(memory)] =  c;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  c;
}
};
j =  j + 1;
};
struct variable* ____BAH_COMPILER_VAR_164 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_164->name = "";
____BAH_COMPILER_VAR_164->type = "";
____BAH_COMPILER_VAR_164->isConst = false;
____BAH_COMPILER_VAR_164->constVal = "";
____BAH_COMPILER_VAR_164->isArray = false;
____BAH_COMPILER_VAR_164->from = "";
____BAH_COMPILER_VAR_164->outterScope = false;
____BAH_COMPILER_VAR_164->isGlobal = false;
nf->returns =  ____BAH_COMPILER_VAR_164;
nf->returns->name =  "_return";
nf->returns->type =  arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,int inclCurr){
char * ogName =  name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_165 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_165->name = "";
____BAH_COMPILER_VAR_165->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_165->args->length = 0;
            ____BAH_COMPILER_VAR_165->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_165->returns= null;
____BAH_COMPILER_VAR_165->isBinding = false;
____BAH_COMPILER_VAR_165->from = "";
____BAH_COMPILER_VAR_165->file = "";
____BAH_COMPILER_VAR_165->line = 1;
____BAH_COMPILER_VAR_165->used = false;
____BAH_COMPILER_VAR_165->code = null;
struct func* fn =  ____BAH_COMPILER_VAR_165;
fn->name =  "noCheck";
return fn;
}
struct string n =  string(name);
if (hasStructSep(n)) {
struct string fnName =  splitStructSepAfter(n);
n.trimRight((struct string*)&n,fnName.length);
char c =  n.charAt((struct string*)&n,n.length-1);
if ((c==46)) {
n.trimRight((struct string*)&n,1);
}
else {
n.trimRight((struct string*)&n,2);
}
name =  n.str((struct string*)&n);
struct variable* v =  searchVar(name,elems);
struct cStruct* s =  searchStruct(v->type,elems);
char * ____BAH_COMPILER_VAR_166 =fnName.str((struct string*)&fnName);struct structMemb* memb =  searchStructMemb(____BAH_COMPILER_VAR_166,s,elems);
name =  fnName.content;
char * ____BAH_COMPILER_VAR_167 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(memb->from);
long int strLen_1 = strlen("__");
long int strLen_2 = strlen(name);
;                            
                    ____BAH_COMPILER_VAR_167 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_167+currStrOff, memb->from, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_167+currStrOff, "__", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_167+currStrOff, name, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                name =  ____BAH_COMPILER_VAR_167;
}
array(struct func*)* fns =  elems->fns;
long int i =  0;
while ((i<len(fns))) {

                    if (fns->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:274): fns[%d] with length %d\n", i, fns->length);
                        exit(1);
                    };
                    struct func* fn =  fns->data[i];
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_168 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null func'.");
;                            
                    ____BAH_COMPILER_VAR_168 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_168+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_168+currStrOff, name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_168+currStrOff, "' resulting in null func'.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                __BAH_panic(____BAH_COMPILER_VAR_168,"/home/alois/Documents/bah-bah/src/var.bah:276");
}
if ((strcmp(fn->name, name) == 0)) {
fn->used =  true;
return fn;
}
i =  i + 1;
};
if ((inclCurr==true)) {
if ((strcmp(currentFn->name, name) == 0)) {
currentFn->used =  true;
return currentFn;
}
}
struct variable* v =  searchVar(ogName,elems);
if ((v==null)) {
return null;
}
struct func* ____BAH_COMPILER_VAR_169 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_169->name = "";
____BAH_COMPILER_VAR_169->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_169->args->length = 0;
            ____BAH_COMPILER_VAR_169->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_169->returns= null;
____BAH_COMPILER_VAR_169->isBinding = false;
____BAH_COMPILER_VAR_169->from = "";
____BAH_COMPILER_VAR_169->file = "";
____BAH_COMPILER_VAR_169->line = 1;
____BAH_COMPILER_VAR_169->used = false;
____BAH_COMPILER_VAR_169->code = null;
struct func* nf =  ____BAH_COMPILER_VAR_169;
nf->name =  ogName;
struct string cvt =  string(v->type);
if ((cvt.hasPrefix((struct string*)&cvt,"function(")==0)) {
return null;
}
struct func* pfn =  parseFnType(cvt);
nf->returns =  pfn->returns;
nf->args =  pfn->args;
return nf;
};
int RCPavailable();
char * declareStructMethods(struct variable* v,struct cStruct* s,struct Elems* elems){
char * code =  "";
array(struct structMemb*)* members =  s->members;
struct string typec =  string(v->type);
char * sep =  ".";
if (typec.count((struct string*)&typec,"*")) {
sep =  "->";
}
long int i =  0;
while ((i<len(members))) {

                    if (members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:319): members[%d] with length %d\n", i, members->length);
                        exit(1);
                    };
                    struct structMemb* m =  members->data[i];
struct string cmpt =  string(m->type);
int declared =  false;
if ((strlen(m->def)>0)) {
char * ____BAH_COMPILER_VAR_170 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(m->def);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_170 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_170+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_170+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_170+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_170+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_170+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_170+currStrOff, m->def, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_170+currStrOff, ";\n", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                code =  ____BAH_COMPILER_VAR_170;
declared =  true;
}
if ((cmpt.hasPrefix((struct string*)&cmpt,"[]")==1)) {
cmpt.trimLeft((struct string*)&cmpt,2);
char * cmptstr =  cmpt.str((struct string*)&cmpt);
struct string elemCType =  getCType(cmptstr,elems);
char * elemCTypeStr =  elemCType.str((struct string*)&elemCType);
char * ____BAH_COMPILER_VAR_171 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(" = memoryAlloc(sizeof(array(");
long int strLen_5 = strlen(elemCTypeStr);
long int strLen_6 = strlen(")));\n            ");
long int strLen_7 = strlen(v->name);
long int strLen_8 = strlen(sep);
long int strLen_9 = strlen(m->name);
long int strLen_10 = strlen("->length = 0;\n            ");
long int strLen_11 = strlen(v->name);
long int strLen_12 = strlen(sep);
long int strLen_13 = strlen(m->name);
long int strLen_14 = strlen("->elemSize = sizeof(");
long int strLen_15 = strlen(elemCTypeStr);
long int strLen_16 = strlen(");\n            ");
;                            
                    ____BAH_COMPILER_VAR_171 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, " = memoryAlloc(sizeof(array(", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, elemCTypeStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, ")));\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, sep, strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, m->name, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, "->length = 0;\n            ", strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, v->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, sep, strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, m->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, "->elemSize = sizeof(", strLen_14);
                    currStrOff += strLen_14;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, elemCTypeStr, strLen_15);
                    currStrOff += strLen_15;
                    
                    strncpy(____BAH_COMPILER_VAR_171+currStrOff, ");\n            ", strLen_16);
                    currStrOff += strLen_16;
                    
                }
                code =  ____BAH_COMPILER_VAR_171;
declared =  true;
}
else if ((cmpt.hasPrefix((struct string*)&cmpt,"map:")==1)) {
cmpt.trimLeft((struct string*)&cmpt,4);
char * ____BAH_COMPILER_VAR_172 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = mapWrapper();\n");
;                            
                    ____BAH_COMPILER_VAR_172 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_172+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_172+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_172+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_172+currStrOff, " = mapWrapper();\n", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                char * ____BAH_COMPILER_VAR_173 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_172);
;                            
                    ____BAH_COMPILER_VAR_173 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_173+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_173+currStrOff, ____BAH_COMPILER_VAR_172, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                code =  ____BAH_COMPILER_VAR_173;
declared =  true;
}
else if ((cmpt.hasPrefix((struct string*)&cmpt,"chan:")==1)) {
cmpt.trimLeft((struct string*)&cmpt,5);
char * ____BAH_COMPILER_VAR_174 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = channel();\n");
;                            
                    ____BAH_COMPILER_VAR_174 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_174+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_174+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_174+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_174+currStrOff, " = channel();\n", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                char * ____BAH_COMPILER_VAR_175 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_174);
;                            
                    ____BAH_COMPILER_VAR_175 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_175+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_175+currStrOff, ____BAH_COMPILER_VAR_174, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                code =  ____BAH_COMPILER_VAR_175;
declared =  true;
}
if ((isRCPpointerType(m->type)&&(declared==false))) {
char * ____BAH_COMPILER_VAR_176 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("= null;\n");
;                            
                    ____BAH_COMPILER_VAR_176 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_176+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_176+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_176+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_176+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_176+currStrOff, "= null;\n", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                code =  ____BAH_COMPILER_VAR_176;
}
i =  i + 1;
};
if ((strlen(s->extendedFrom)>0)) {
struct cStruct* es =  searchStruct(s->extendedFrom,elems);
i =  0;
while ((i<len(es->methods))) {

                    if (es->methods->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:356): es->methods[%d] with length %d\n", i, es->methods->length);
                        exit(1);
                    };
                    struct func* m =  es->methods->data[i];
char * ____BAH_COMPILER_VAR_177 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(es->name);
long int strLen_6 = strlen("__");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_177 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    strncpy(____BAH_COMPILER_VAR_177+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_177+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_177+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_177+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_177+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_177+currStrOff, es->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_177+currStrOff, "__", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_177+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_177+currStrOff, ";\n", strLen_8);
                    currStrOff += strLen_8;
                    
                }
                code =  ____BAH_COMPILER_VAR_177;
i =  i + 1;
};
}
array(struct func*)* methods =  s->methods;
i =  0;
while ((i<len(methods))) {

                    if (methods->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:364): methods[%d] with length %d\n", i, methods->length);
                        exit(1);
                    };
                    struct func* m =  methods->data[i];
char * ____BAH_COMPILER_VAR_178 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(s->name);
long int strLen_6 = strlen("__");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_178 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    strncpy(____BAH_COMPILER_VAR_178+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_178+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_178+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_178+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_178+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_178+currStrOff, s->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_178+currStrOff, "__", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_178+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_178+currStrOff, ";\n", strLen_8);
                    currStrOff += strLen_8;
                    
                }
                code =  ____BAH_COMPILER_VAR_178;
i =  i + 1;
};
if ((((s->isBinding==false)&&RCPavailable())&&(s->hasRCPmemb==true))) {
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_179 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter = malloc(sizeof(int));*(int*)");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(".__RCP_counter = 1;\n");
;                            
                    ____BAH_COMPILER_VAR_179 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_179+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_179+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_179+currStrOff, ".__RCP_counter = malloc(sizeof(int));*(int*)", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_179+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_179+currStrOff, ".__RCP_counter = 1;\n", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                code =  ____BAH_COMPILER_VAR_179;
}
else {
char * ____BAH_COMPILER_VAR_180 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen("->__RCP_counter = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_180 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_180+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_180+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_180+currStrOff, "->__RCP_counter = RCP_request(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_180+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_180+currStrOff, ");\n", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                code =  ____BAH_COMPILER_VAR_180;
}
}
return code;
};
long int NB_COMP_VAR;
char * genCompilerVar(){
char * ____BAH_COMPILER_VAR_181 =intToStr(NB_COMP_VAR);char * ____BAH_COMPILER_VAR_182 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("____BAH_COMPILER_VAR_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_181);
;                            
                    ____BAH_COMPILER_VAR_182 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_182+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_182+currStrOff, ____BAH_COMPILER_VAR_181, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * name =  ____BAH_COMPILER_VAR_182;
NB_COMP_VAR =  NB_COMP_VAR + 1;
return name;
};
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
int varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){
if ((arr==null)) {
return false;
}
long int j =  0;
while ((j<len(arr))) {

                    if (arr->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:393): arr[%d] with length %d\n", j, arr->length);
                        exit(1);
                    };
                    struct variable* ev =  arr->data[j];
if ((strcmp(ev->name, v->name) == 0)) {
return true;
}
j =  j + 1;
};
return false;
};
char * pathToVarName(char * p){
array(char)* a =  strToArr(p);
long int i =  0;
for (; (i<len(a)); i =  i+1) {

                    if (a->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:405): a[%d] with length %d\n", i, a->length);
                        exit(1);
                    };
                    long int c =  a->data[i];
c =  c - (long int)97;
if ((c<0)) {
c =  0 - c;
}
c =  c % ((long int)122 - (long int)97);
c =  c + (long int)97;

{
long nLength = i;
if (a->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(a->data, (nLength+50)*sizeof(char));
a->data = newPtr;
}
a->data[i] =  (char)c;
a->length = nLength+1;
} else {
a->data[i] =  (char)c;
}
};
};
return arrToStr(a);
};
void makeInit(){
char * name =  "__BAH_init";
if ((isObject==true)) {
char * ____BAH_COMPILER_VAR_183 =pathToVarName(compilerState.currentFile);char * ____BAH_COMPILER_VAR_184 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(name);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_183);
;                            
                    ____BAH_COMPILER_VAR_184 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_184+currStrOff, name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_184+currStrOff, ____BAH_COMPILER_VAR_183, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                name =  ____BAH_COMPILER_VAR_184;
}
char * evals =  "";
char * ____BAH_COMPILER_VAR_185 =intToStr(len(compilerState.evals));char * ____BAH_COMPILER_VAR_186 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_185);
long int strLen_2 = strlen("] = {");
;                            
                    ____BAH_COMPILER_VAR_186 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_186+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_186+currStrOff, ____BAH_COMPILER_VAR_185, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_186+currStrOff, "] = {", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                char * evalsTMPDecl =  ____BAH_COMPILER_VAR_186;
long int i =  0;
for (; (i<len(compilerState.evals)); i =  i+1) {

                    if (compilerState.evals->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/var.bah:427): compilerState.evals[%d] with length %d\n", i, compilerState.evals->length);
                        exit(1);
                    };
                    char * e =  compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_187 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("{\n            .name = \"");
long int strLen_1 = strlen(e);
long int strLen_2 = strlen("\",\n            .evalFn = __Bah_eval_");
long int strLen_3 = strlen(e);
long int strLen_4 = strlen("\n        }");
;                            
                    ____BAH_COMPILER_VAR_187 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_187+currStrOff, "{\n            .name = \"", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_187+currStrOff, e, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_187+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_187+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_187+currStrOff, "\n        }", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                char * ____BAH_COMPILER_VAR_188 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_187);
;                            
                    ____BAH_COMPILER_VAR_188 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_188+currStrOff, evalsTMPDecl, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_188+currStrOff, ____BAH_COMPILER_VAR_187, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                evalsTMPDecl =  ____BAH_COMPILER_VAR_188;
if ((i + 1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_189 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen(",\n");
;                            
                    ____BAH_COMPILER_VAR_189 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_189+currStrOff, evalsTMPDecl, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_189+currStrOff, ",\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                evalsTMPDecl =  ____BAH_COMPILER_VAR_189;
}
else {
char * ____BAH_COMPILER_VAR_190 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(evalsTMPDecl);
long int strLen_1 = strlen("};");
;                            
                    ____BAH_COMPILER_VAR_190 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_190+currStrOff, evalsTMPDecl, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_190+currStrOff, "};", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                evalsTMPDecl =  ____BAH_COMPILER_VAR_190;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_191 =intToStr(len(compilerState.evals));char * ____BAH_COMPILER_VAR_192 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_191);
long int strLen_2 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_192 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_192+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_192+currStrOff, ____BAH_COMPILER_VAR_191, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_192+currStrOff, ";", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                evals =  ____BAH_COMPILER_VAR_192;
}
else {
evalsTMPDecl =  "";
}
char * ____BAH_COMPILER_VAR_193 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    ");
long int strLen_1 = strlen(evalsTMPDecl);
long int strLen_2 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
long int strLen_3 = strlen(name);
long int strLen_4 = strlen("() {\n        ");
;                            
                    ____BAH_COMPILER_VAR_193 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_193+currStrOff, "\n    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_193+currStrOff, evalsTMPDecl, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_193+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_193+currStrOff, name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_193+currStrOff, "() {\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                char * ____BAH_COMPILER_VAR_194 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        ");
long int strLen_1 = strlen(evals);
long int strLen_2 = strlen("\n    };\n    ");
;                            
                    ____BAH_COMPILER_VAR_194 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_194+currStrOff, "\n        ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_194+currStrOff, evals, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_194+currStrOff, "\n    };\n    ", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_193))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_193)), INIT)->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_193))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_193)), INIT), rope(____BAH_COMPILER_VAR_194));
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r =  rope("");
if (strHasPrefix(v->type,"[]")) {
struct string at =  string(v->type);
at.trimLeft((struct string*)&at,2);
char * ____BAH_COMPILER_VAR_195 =at.str((struct string*)&at);if (isRCPtype(____BAH_COMPILER_VAR_195,elems)) {
struct variable* ____BAH_COMPILER_VAR_196 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_196->name = "";
____BAH_COMPILER_VAR_196->type = "";
____BAH_COMPILER_VAR_196->isConst = false;
____BAH_COMPILER_VAR_196->constVal = "";
____BAH_COMPILER_VAR_196->isArray = false;
____BAH_COMPILER_VAR_196->from = "";
____BAH_COMPILER_VAR_196->outterScope = false;
____BAH_COMPILER_VAR_196->isGlobal = false;
struct variable* arrElem =  ____BAH_COMPILER_VAR_196;
arrElem->type =  at.str((struct string*)&at);
char * ____BAH_COMPILER_VAR_197 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("->data[arrElemIndex]");
;                            
                    ____BAH_COMPILER_VAR_197 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_197+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_197+currStrOff, "->data[arrElemIndex]", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                arrElem->name =  ____BAH_COMPILER_VAR_197;
char * ____BAH_COMPILER_VAR_198 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n            {\n            struct RCP * arrRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (arrRCP != null && arrRCP->c == 1) {\n                struct RCP * arrDataRCP = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->data);\n                if (arrDataRCP != null && arrDataRCP->c == 1) {\n                    for(int arrElemIndex=len(");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(")-1; arrElemIndex >= 0; arrElemIndex--) {\n                        ");
;                            
                    ____BAH_COMPILER_VAR_198 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_198+currStrOff, "\n            {\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_198+currStrOff, ");\n            if (arrRCP != null && arrRCP->c == 1) {\n                struct RCP * arrDataRCP = RCP_request(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_198+currStrOff, "->data);\n                if (arrDataRCP != null && arrDataRCP->c == 1) {\n                    for(int arrElemIndex=len(", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_198+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_198+currStrOff, ")-1; arrElemIndex >= 0; arrElemIndex--) {\n                        ", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                r =  rope(____BAH_COMPILER_VAR_198)->add(rope(____BAH_COMPILER_VAR_198), decrVar(arrElem,elems))->add(rope(____BAH_COMPILER_VAR_198)->add(rope(____BAH_COMPILER_VAR_198), decrVar(arrElem,elems)), rope("\n                    };\n                }\n                RCP_decrRCP(arrDataRCP);\n            }\n            RCP_decrRCP(arrRCP);\n            };\n            "));
}
else {
char * ____BAH_COMPILER_VAR_199 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n            {\n            struct RCP * arrRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };\n            ");
;                            
                    ____BAH_COMPILER_VAR_199 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_199+currStrOff, "\n            {\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_199+currStrOff, ");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_199+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_199+currStrOff, "->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };\n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                r =  rope(____BAH_COMPILER_VAR_199);
}
}
else if (strHasPrefix(v->type,"chan:")) {
char * ____BAH_COMPILER_VAR_200 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("{\n            struct RCP * chanRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (chanRCP != null && chanRCP->c == 1) {\n                ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->destroy(");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(");\n                RCP_decr(");
long int strLen_7 = strlen(v->name);
long int strLen_8 = strlen("->queue);\n            };\n            RCP_decrRCP(chanRCP);\n        };");
;                            
                    ____BAH_COMPILER_VAR_200 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    strncpy(____BAH_COMPILER_VAR_200+currStrOff, "{\n            struct RCP * chanRCP = RCP_request(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_200+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_200+currStrOff, ");\n            if (chanRCP != null && chanRCP->c == 1) {\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_200+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_200+currStrOff, "->destroy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_200+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_200+currStrOff, ");\n                RCP_decr(", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_200+currStrOff, v->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_200+currStrOff, "->queue);\n            };\n            RCP_decrRCP(chanRCP);\n        };", strLen_8);
                    currStrOff += strLen_8;
                    
                }
                r =  rope(____BAH_COMPILER_VAR_200);
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_201 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_201->name = "";
____BAH_COMPILER_VAR_201->type = "";
____BAH_COMPILER_VAR_201->isConst = false;
____BAH_COMPILER_VAR_201->constVal = "";
____BAH_COMPILER_VAR_201->isArray = false;
____BAH_COMPILER_VAR_201->from = "";
____BAH_COMPILER_VAR_201->outterScope = false;
____BAH_COMPILER_VAR_201->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_201;
*nv =  *v;
v =  nv;
v->type =  "mapWrapper*";
}
int isPointer =  isRCPpointerType(v->type);
struct cStruct* s =  searchStruct(v->type,elems);
if (((s!=null)&&(s->isBinding==false))) {
char * amp =  "&";
char * heap =  "0";
if ((isPointer==true)) {
amp =  "";
heap =  "1";
}
char * ____BAH_COMPILER_VAR_202 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__RCP_clean_");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(heap);
long int strLen_7 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_202 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    strncpy(____BAH_COMPILER_VAR_202+currStrOff, "__RCP_clean_", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_202+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_202+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_202+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_202+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_202+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_202+currStrOff, heap, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_202+currStrOff, ");\n", strLen_7);
                    currStrOff += strLen_7;
                    
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_202));
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_203 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_decr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_203 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_203+currStrOff, "RCP_decr(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_203+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_203+currStrOff, ");\n", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_203));
}
}
return r;
};
struct rope* incrVar(struct variable* v,struct Elems* elems){
if ((strCount(v->name,"*")>0)) {
return rope("");
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((((s!=null)&&(isRCPpointerType(v->type)==false))&&(s->isBinding==false))) {
char * ____BAH_COMPILER_VAR_204 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_incrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter);");
;                            
                    ____BAH_COMPILER_VAR_204 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_204+currStrOff, "RCP_incrCounter(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_204+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_204+currStrOff, ".__RCP_counter);", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                return rope(____BAH_COMPILER_VAR_204);
}
char * ____BAH_COMPILER_VAR_205 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_incr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");");
;                            
                    ____BAH_COMPILER_VAR_205 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_205+currStrOff, "RCP_incr(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_205+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_205+currStrOff, ");", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                return rope(____BAH_COMPILER_VAR_205);
};
int RCPavailable(){
char * ____BAH_COMPILER_VAR_206 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("rcp.bah");
;                            
                    ____BAH_COMPILER_VAR_206 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_206+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_206+currStrOff, "rcp.bah", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * ____BAH_COMPILER_VAR_207 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("fastrcp.bah");
;                            
                    ____BAH_COMPILER_VAR_207 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_207+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_207+currStrOff, "fastrcp.bah", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                return (((strcmp(absPath(compilerState.currentFile), absPath(____BAH_COMPILER_VAR_206)) != 0)&&(strcmp(absPath(compilerState.currentFile), absPath(____BAH_COMPILER_VAR_207)) != 0))&&(RCPenabled==true));
};
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable exc){
if ((RCPavailable()==false)) {
return;
}
long int i =  0;
for (; (i<len(elems->vars)); i =  i+1) {

                    if (elems->vars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/mem.bah:100): elems->vars[%d] with length %d\n", i, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[i];
if (((v->outterScope==false)&&(isRCPtype(v->type,elems)==true))) {
if ((varInArr(v,exc)==false)) {
OUTPUT =  OUTPUT->add(OUTPUT, decrVar(v,elems));
}
}
};
};
void endRCPnonGlobScope(struct Elems* elems,__BAH_ARR_TYPE_variable exc){
if ((RCPavailable()==false)) {
return;
}
long int i =  0;
for (; (i<len(elems->vars)); i =  i+1) {

                    if (elems->vars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/mem.bah:114): elems->vars[%d] with length %d\n", i, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[i];
if ((isRCPtype(v->type,elems)==true)) {
if (((v->isGlobal==false)&&(varInArr(v,exc)==false))) {
OUTPUT =  OUTPUT->add(OUTPUT, decrVar(v,elems));
}
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
struct variable* av =  ____BAH_COMPILER_VAR_208;
av->type =  t;
av->name =  genCompilerVar();

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  av;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  av;
}
};
struct string cType =  getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_209 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_210 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_209);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(av->name);
long int strLen_3 = strlen(" =");
long int strLen_4 = strlen(c);
long int strLen_5 = strlen(";");
;                            
                    ____BAH_COMPILER_VAR_210 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_210+currStrOff, ____BAH_COMPILER_VAR_209, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_210+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_210+currStrOff, av->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_210+currStrOff, " =", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_210+currStrOff, c, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_210+currStrOff, ";", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_210));
return av->name;
};
struct rope* makeRCPfuncFromStruct(struct cStruct* s,struct Elems* elems){
if (((s->isBinding==true)||(RCPavailable()==false))) {
return rope("");
}
struct rope* decrMembs =  rope("");
long int i =  0;
while ((i<len(s->members))) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/mem.bah:141): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[i];
struct string rm =  string(m->type);
rm.replace((struct string*)&rm,"*","");
if (isRCPtype(m->type,elems)) {
if ((strcmp(rm.str((struct string*)&rm), s->name) != 0)) {
struct variable* ____BAH_COMPILER_VAR_211 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_211->name = "";
____BAH_COMPILER_VAR_211->type = "";
____BAH_COMPILER_VAR_211->isConst = false;
____BAH_COMPILER_VAR_211->constVal = "";
____BAH_COMPILER_VAR_211->isArray = false;
____BAH_COMPILER_VAR_211->from = "";
____BAH_COMPILER_VAR_211->outterScope = false;
____BAH_COMPILER_VAR_211->isGlobal = false;
struct variable* mv =  ____BAH_COMPILER_VAR_211;
char * ____BAH_COMPILER_VAR_212 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("e->");
long int strLen_1 = strlen(m->name);
;                            
                    ____BAH_COMPILER_VAR_212 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_212+currStrOff, "e->", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_212+currStrOff, m->name, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                mv->name =  ____BAH_COMPILER_VAR_212;
mv->type =  m->type;
decrMembs =  decrMembs->add(decrMembs, decrVar(mv,elems));
}
else {
char * ____BAH_COMPILER_VAR_213 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Strcture '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has a self-referenced member '");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.");
;                            
                    ____BAH_COMPILER_VAR_213 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_213+currStrOff, "Strcture '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_213+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_213+currStrOff, "' has a self-referenced member '", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_213+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_213+currStrOff, "'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwWarning(____BAH_COMPILER_VAR_213);
char * amp =  "&";
char * heap =  "0";
if ((strCount(m->type,"*")>0)) {
amp =  "";
heap =  "1";
}
char * ____BAH_COMPILER_VAR_214 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__RCP_clean_");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen("e->");
long int strLen_5 = strlen(m->name);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(heap);
long int strLen_8 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_214 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    strncpy(____BAH_COMPILER_VAR_214+currStrOff, "__RCP_clean_", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_214+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_214+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_214+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_214+currStrOff, "e->", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_214+currStrOff, m->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_214+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_214+currStrOff, heap, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_214+currStrOff, ");\n", strLen_8);
                    currStrOff += strLen_8;
                    
                }
                decrMembs =  decrMembs->add(decrMembs, rope(____BAH_COMPILER_VAR_214));
}
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_215 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("void* __RCP_clean_");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("(struct ");
long int strLen_3 = strlen(s->name);
long int strLen_4 = strlen("* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ");
;                            
                    ____BAH_COMPILER_VAR_215 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_215+currStrOff, "void* __RCP_clean_", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_215+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_215+currStrOff, "(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_215+currStrOff, s->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_215+currStrOff, "* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                struct rope* r =  rope(____BAH_COMPILER_VAR_215)->add(rope(____BAH_COMPILER_VAR_215), decrMembs)->add(rope(____BAH_COMPILER_VAR_215)->add(rope(____BAH_COMPILER_VAR_215), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_215)->add(rope(____BAH_COMPILER_VAR_215), decrMembs)->add(rope(____BAH_COMPILER_VAR_215)->add(rope(____BAH_COMPILER_VAR_215), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs)->add(rope(____BAH_COMPILER_VAR_215)->add(rope(____BAH_COMPILER_VAR_215), decrMembs)->add(rope(____BAH_COMPILER_VAR_215)->add(rope(____BAH_COMPILER_VAR_215), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_215)->add(rope(____BAH_COMPILER_VAR_215), decrMembs)->add(rope(____BAH_COMPILER_VAR_215)->add(rope(____BAH_COMPILER_VAR_215), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs), rope("\n        }\n    };\n"));
return r;
};
int RCPselfRef(struct variable* v){
long int i =  0;
while ((i<len(compilerState.RCPvars))) {

                    if (compilerState.RCPvars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/mem.bah:183): compilerState.RCPvars[%d] with length %d\n", i, compilerState.RCPvars->length);
                        exit(1);
                    };
                    struct variable* r =  compilerState.RCPvars->data[i];
if ((strcmp(r->name, v->name) == 0)) {
return true;
}
i =  i + 1;
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
int verboseOutGuard(){
if ((currentFn!=null)) {

                int ____BAH_COMPILER_VAR_216 = 0;
                for(int i=len(noVOfns)-1; i != -1; i--) {
                    if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                        ____BAH_COMPILER_VAR_216 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_216) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_217 = {};
____BAH_COMPILER_VAR_217.markup= null;
____BAH_COMPILER_VAR_217.content= null;
struct verboseOutVar rv =  ____BAH_COMPILER_VAR_217;
char * ogCont =  cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_218 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__Bah_safe_string(");
long int strLen_1 = strlen(cont);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_218 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_218+currStrOff, "__Bah_safe_string(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_218+currStrOff, cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_218+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                cont =  ____BAH_COMPILER_VAR_218;
}
char * ____BAH_COMPILER_VAR_219 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(", ");
long int strLen_1 = strlen(cont);
;                            
                    ____BAH_COMPILER_VAR_219 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_219+currStrOff, ", ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_219+currStrOff, cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                cont =  ____BAH_COMPILER_VAR_219;
char * ct =  "";
if ((strcmp(v->type, "cpstring") == 0)) {
ct =  "%s";
}
else if ((strcmp(v->type, "int") == 0)) {
ct =  "%li";
}
else if ((strcmp(v->type, "float") == 0)) {
ct =  "%d";
}
else if ((isRCPpointerType(v->type)==true)) {
ct =  "%p";
}
else {
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
ct =  "%li";
}
else {
char * ____BAH_COMPILER_VAR_220 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ASCII_RESET);
long int strLen_1 = strlen("{");
;                            
                    ____BAH_COMPILER_VAR_220 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_220+currStrOff, ASCII_RESET, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_220+currStrOff, "{", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ct =  ____BAH_COMPILER_VAR_220;
cont =  "";
long int i =  0;
for (; (i<len(s->members)); i =  i+1) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:53): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct variable* m =  s->members->data[i];
char * ____BAH_COMPILER_VAR_221 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(ogCont);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(".");
long int strLen_4 = strlen(m->name);
;                            
                    ____BAH_COMPILER_VAR_221 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_221+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_221+currStrOff, ogCont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_221+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_221+currStrOff, ".", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_221+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                }
                struct verboseOutVar mv =  verboseOutTransformVar(m,____BAH_COMPILER_VAR_221,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_222 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_222 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_222+currStrOff, ct, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_222+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ct =  ____BAH_COMPILER_VAR_222;
}
char * ____BAH_COMPILER_VAR_223 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ct);
long int strLen_1 = strlen(mv.markup);
;                            
                    ____BAH_COMPILER_VAR_223 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_223+currStrOff, ct, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_223+currStrOff, mv.markup, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ct =  ____BAH_COMPILER_VAR_223;
char * ____BAH_COMPILER_VAR_224 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mv.content);
;                            
                    ____BAH_COMPILER_VAR_224 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_224+currStrOff, cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_224+currStrOff, mv.content, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                cont =  ____BAH_COMPILER_VAR_224;
};
char * ____BAH_COMPILER_VAR_225 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ct);
long int strLen_1 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_225 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_225+currStrOff, ct, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_225+currStrOff, "}", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ct =  ____BAH_COMPILER_VAR_225;
}
}
char * ____BAH_COMPILER_VAR_226 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ASCII_BLUE);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(ASCII_RESET);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(ASCII_MAGENTA);
long int strLen_5 = strlen(ct);
long int strLen_6 = strlen(ASCII_RESET);
;                            
                    ____BAH_COMPILER_VAR_226 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_226+currStrOff, ASCII_BLUE, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_226+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_226+currStrOff, ASCII_RESET, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_226+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_226+currStrOff, ASCII_MAGENTA, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_226+currStrOff, ct, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_226+currStrOff, ASCII_RESET, strLen_6);
                    currStrOff += strLen_6;
                    
                }
                rv.markup =  ____BAH_COMPILER_VAR_226;
rv.content =  cont;
return rv;
};
struct verboseOutVar verboseOutTransformTok(struct Tok t,struct Elems* elems){
if (((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false))) {
struct variable* v =  searchVar(t.cont,elems);
if ((v==null)) {
return verboseOutTransformVar(v,t.cont,elems);
}
}
struct variable ____BAH_COMPILER_VAR_227 = {};
____BAH_COMPILER_VAR_227.name = "";
____BAH_COMPILER_VAR_227.type = "";
____BAH_COMPILER_VAR_227.isConst = false;
____BAH_COMPILER_VAR_227.constVal = "";
____BAH_COMPILER_VAR_227.isArray = false;
____BAH_COMPILER_VAR_227.from = "";
____BAH_COMPILER_VAR_227.outterScope = false;
____BAH_COMPILER_VAR_227.isGlobal = false;
____BAH_COMPILER_VAR_227.name = "(value)";
____BAH_COMPILER_VAR_227.type = getTypeFromToken(&t,true,elems);
struct variable v =  ____BAH_COMPILER_VAR_227;
return verboseOutTransformVar(&v,t.cont,elems);
};
void verboseOutFunc(struct func* fn,__BAH_ARR_TYPE_Tok args,long int lineNb,struct Elems* elems){
if ((verboseOutGuard()==false)) {
return;
}
char * nameColor =  ASCII_YELLOW;
if ((fn->isBinding==true)) {
if (strHasPrefix(compilerState.currentFile,BAH_DIR)) {
return;
}
nameColor =  ASCII_GREY;
}
if (strHasPrefix(fn->file,BAH_DIR)) {
int hasPtr =  false;
long int i =  0;
for (; (i<len(fn->args)); i =  i+1) {

                    if (fn->args->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:101): fn->args[%d] with length %d\n", i, fn->args->length);
                        exit(1);
                    };
                    struct variable* a =  fn->args->data[i];
if ((isRCPpointerType(a->type)==true)) {
hasPtr =  true;
break;
}
};
if ((hasPtr==false)) {
return;
}
}
char * fnArgs =  "";
char * fnArgsValues =  "";
long int j =  0;
for (; (j<len(fn->args)); j =  j+1) {

                    if (fn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:115): fn->args[%d] with length %d\n", j, fn->args->length);
                        exit(1);
                    };
                    struct variable* a =  fn->args->data[j];
if ((j!=0)) {
char * ____BAH_COMPILER_VAR_228 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_228+currStrOff, fnArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_228+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fnArgs =  ____BAH_COMPILER_VAR_228;
}

                    if (args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/verboseOut.bah:120): args[%d] with length %d\n", j, args->length);
                        exit(1);
                    };
                    struct Tok t =  args->data[j];
struct verboseOutVar v =  verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_229 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnArgs);
long int strLen_1 = strlen(v.markup);
;                            
                    ____BAH_COMPILER_VAR_229 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_229+currStrOff, fnArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_229+currStrOff, v.markup, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fnArgs =  ____BAH_COMPILER_VAR_229;
char * ____BAH_COMPILER_VAR_230 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnArgsValues);
long int strLen_1 = strlen(v.content);
;                            
                    ____BAH_COMPILER_VAR_230 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_230+currStrOff, fnArgsValues, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_230+currStrOff, v.content, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fnArgsValues =  ____BAH_COMPILER_VAR_230;
};
char * ____BAH_COMPILER_VAR_231 =intToStr(lineNb);char * ____BAH_COMPILER_VAR_232 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentFile);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_231);
;                            
                    ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_232+currStrOff, compilerState.currentFile, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_232+currStrOff, ":", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_232+currStrOff, ____BAH_COMPILER_VAR_231, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                char * line =  ____BAH_COMPILER_VAR_232;
char * ____BAH_COMPILER_VAR_233 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    //Verbose Runtime\n        printf(\"[VO] calling: ");
long int strLen_1 = strlen(nameColor);
long int strLen_2 = strlen(fn->name);
long int strLen_3 = strlen(ASCII_RESET);
long int strLen_4 = strlen("(");
long int strLen_5 = strlen(fnArgs);
long int strLen_6 = strlen(") -> ");
long int strLen_7 = strlen(ASCII_GREEN);
long int strLen_8 = strlen(line);
long int strLen_9 = strlen(ASCII_RESET);
long int strLen_10 = strlen("\\n\"");
long int strLen_11 = strlen(fnArgsValues);
long int strLen_12 = strlen(");\n    //\n    ");
;                            
                    ____BAH_COMPILER_VAR_233 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, nameColor, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, fn->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, fnArgs, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, ") -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, ASCII_GREEN, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, line, strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, ASCII_RESET, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, "\\n\"", strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, fnArgsValues, strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_233+currStrOff, ");\n    //\n    ", strLen_12);
                    currStrOff += strLen_12;
                    
                }
                struct rope* verboseOut =  rope(____BAH_COMPILER_VAR_233);
if (isGlobal()) {
INIT =  INIT->add(INIT, verboseOut);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, verboseOut);
}
};
void verboseOutOper(struct Tok pt,struct Tok nt,long int lineNb,struct Elems* elems){
if ((verboseOutGuard()==false)) {
return;
}
struct verboseOutVar pvo =  verboseOutTransformTok(pt,elems);
struct verboseOutVar nvo =  verboseOutTransformTok(nt,elems);
char * ____BAH_COMPILER_VAR_234 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pvo.content);
long int strLen_1 = strlen(nvo.content);
;                            
                    ____BAH_COMPILER_VAR_234 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_234+currStrOff, pvo.content, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_234+currStrOff, nvo.content, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * values =  ____BAH_COMPILER_VAR_234;
char * ____BAH_COMPILER_VAR_235 =intToStr(lineNb);char * ____BAH_COMPILER_VAR_236 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentFile);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_235);
;                            
                    ____BAH_COMPILER_VAR_236 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_236+currStrOff, compilerState.currentFile, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_236+currStrOff, ":", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_236+currStrOff, ____BAH_COMPILER_VAR_235, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                char * line =  ____BAH_COMPILER_VAR_236;
char * ____BAH_COMPILER_VAR_237 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    //Verbose Runtime\n        printf(\"[VO]    oper: ");
long int strLen_1 = strlen(pvo.markup);
long int strLen_2 = strlen(" AND ");
long int strLen_3 = strlen(nvo.markup);
long int strLen_4 = strlen(" -> ");
long int strLen_5 = strlen(ASCII_GREEN);
long int strLen_6 = strlen(line);
long int strLen_7 = strlen(ASCII_RESET);
long int strLen_8 = strlen("\\n\"");
long int strLen_9 = strlen(values);
long int strLen_10 = strlen(");\n    //\n    ");
;                            
                    ____BAH_COMPILER_VAR_237 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10);
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, pvo.markup, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, " AND ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, nvo.markup, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, " -> ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, line, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, ASCII_RESET, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, "\\n\"", strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, values, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_237+currStrOff, ");\n    //\n    ", strLen_10);
                    currStrOff += strLen_10;
                    
                }
                struct rope* verboseOut =  rope(____BAH_COMPILER_VAR_237);
if (isGlobal()) {
INIT =  INIT->add(INIT, verboseOut);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, verboseOut);
}
};
struct cacheFile {
char * file;
long int last;
char * ver;
long int date;
array(char *)* files;
};
array(struct cacheFile*)* cache;
void readCache(){
struct fileStream ____BAH_COMPILER_VAR_238 = {};
____BAH_COMPILER_VAR_238.handle= null;
____BAH_COMPILER_VAR_238.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_238.open = fileStream__open;
____BAH_COMPILER_VAR_238.close = fileStream__close;
____BAH_COMPILER_VAR_238.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_238.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_238.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_238.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_238.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_238.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_238.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_238.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_238.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_238.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_238.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_238.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_238.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_238;
char * ____BAH_COMPILER_VAR_239 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_239 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_239+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_239+currStrOff, "cache/cache.json", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fs.open((struct fileStream*)&fs,____BAH_COMPILER_VAR_239,"r");
if ((fs.isValid((struct fileStream*)&fs)==0)) {
char * ____BAH_COMPILER_VAR_240 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache");
;                            
                    ____BAH_COMPILER_VAR_240 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_240+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_240+currStrOff, "cache", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                mkdir(____BAH_COMPILER_VAR_240,S_IRWXU);
char * ____BAH_COMPILER_VAR_241 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_241 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_241+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_241+currStrOff, "cache/cache.json", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fs.createFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_241);
return;
}
char * ____BAH_COMPILER_VAR_242 =fs.readContent((struct fileStream*)&fs);struct jsonElement* j =  parseJson(____BAH_COMPILER_VAR_242);
fs.close((struct fileStream*)&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_243 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_244 = 0;
char ** ____BAH_COMPILER_VAR_246 = (char **)((char*)(____BAH_COMPILER_VAR_244) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_247 = __reflect(____BAH_COMPILER_VAR_246, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_248 = (long int*)((char*)(____BAH_COMPILER_VAR_244) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_249 = __reflect(____BAH_COMPILER_VAR_248, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_250 = (char **)((char*)(____BAH_COMPILER_VAR_244) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_251 = __reflect(____BAH_COMPILER_VAR_250, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_252 = (long int*)((char*)(____BAH_COMPILER_VAR_244) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_253 = __reflect(____BAH_COMPILER_VAR_252, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
array(char *)** ____BAH_COMPILER_VAR_254 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_244) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_255 = 0;
struct reflectElement ____BAH_COMPILER_VAR_256 = __reflect(____BAH_COMPILER_VAR_255, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_257 = ____BAH_COMPILER_VAR_256;
        struct reflectElement ____BAH_COMPILER_VAR_258 = __reflect(____BAH_COMPILER_VAR_254, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_257, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_245 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_245->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_245->length = 5;
        ____BAH_COMPILER_VAR_245->data = memoryAlloc(____BAH_COMPILER_VAR_245->length * ____BAH_COMPILER_VAR_245->elemSize);
        ____BAH_COMPILER_VAR_245->data[0] = ____BAH_COMPILER_VAR_247;
____BAH_COMPILER_VAR_245->data[1] = ____BAH_COMPILER_VAR_249;
____BAH_COMPILER_VAR_245->data[2] = ____BAH_COMPILER_VAR_251;
____BAH_COMPILER_VAR_245->data[3] = ____BAH_COMPILER_VAR_253;
____BAH_COMPILER_VAR_245->data[4] = ____BAH_COMPILER_VAR_258;
struct reflectElement ____BAH_COMPILER_VAR_259 = __reflect(____BAH_COMPILER_VAR_244, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_245, 0);

        struct reflectElement ____BAH_COMPILER_VAR_260 = ____BAH_COMPILER_VAR_259;
        struct reflectElement ____BAH_COMPILER_VAR_261 = __reflect(____BAH_COMPILER_VAR_243, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_260, 0, 0, 0);
j->scan((struct jsonElement*)j,____BAH_COMPILER_VAR_261);
if ((cache!=null)) {
}
};
struct cacheFile* getCacheFile(char * s){
if ((cache==null)) {
return null;
}
long int i =  0;
for (; (i<len(cache)); i =  i+1) {

                    if (cache->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/cache.bah:43): cache[%d] with length %d\n", i, cache->length);
                        exit(1);
                    };
                    struct cacheFile* c =  cache->data[i];
if ((strcmp(c->file, s) == 0)) {
return c;
}
};
return null;
};
void updateCacheFile(struct cacheFile* c){
c->last =  getLastModified(c->file);
c->ver =  BAH_VERSION;
c->date =  getTimeUnix();
};
void makeCacheFile(char * f){
struct cacheFile* ____BAH_COMPILER_VAR_262 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_262->file= null;
____BAH_COMPILER_VAR_262->ver= null;
____BAH_COMPILER_VAR_262->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_262->files->length = 0;
            ____BAH_COMPILER_VAR_262->files->elemSize = sizeof(char *);
            struct cacheFile* c =  ____BAH_COMPILER_VAR_262;
c->file =  f;
c->ver =  BAH_VERSION;
c->date =  getTimeUnix();
c->last =  getLastModified(f);
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
cache->data[len(cache)] =  c;
cache->length = nLength+1;
} else {
cache->data[len(cache)] =  c;
}
};
};
void writeCache(){
struct fileStream ____BAH_COMPILER_VAR_263 = {};
____BAH_COMPILER_VAR_263.handle= null;
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
struct fileStream fs =  ____BAH_COMPILER_VAR_263;
char * ____BAH_COMPILER_VAR_264 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/cache.json");
;                            
                    ____BAH_COMPILER_VAR_264 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_264+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_264+currStrOff, "cache/cache.json", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fs.open((struct fileStream*)&fs,____BAH_COMPILER_VAR_264,"w");
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
array(char *)** ____BAH_COMPILER_VAR_276 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_266) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_277 = 0;
struct reflectElement ____BAH_COMPILER_VAR_278 = __reflect(____BAH_COMPILER_VAR_277, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_279 = ____BAH_COMPILER_VAR_278;
        struct reflectElement ____BAH_COMPILER_VAR_280 = __reflect(____BAH_COMPILER_VAR_276, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_279, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_267 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_267->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_267->length = 5;
        ____BAH_COMPILER_VAR_267->data = memoryAlloc(____BAH_COMPILER_VAR_267->length * ____BAH_COMPILER_VAR_267->elemSize);
        ____BAH_COMPILER_VAR_267->data[0] = ____BAH_COMPILER_VAR_269;
____BAH_COMPILER_VAR_267->data[1] = ____BAH_COMPILER_VAR_271;
____BAH_COMPILER_VAR_267->data[2] = ____BAH_COMPILER_VAR_273;
____BAH_COMPILER_VAR_267->data[3] = ____BAH_COMPILER_VAR_275;
____BAH_COMPILER_VAR_267->data[4] = ____BAH_COMPILER_VAR_280;
struct reflectElement ____BAH_COMPILER_VAR_281 = __reflect(____BAH_COMPILER_VAR_266, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_267, 0);

        struct reflectElement ____BAH_COMPILER_VAR_282 = ____BAH_COMPILER_VAR_281;
        struct reflectElement ____BAH_COMPILER_VAR_283 = __reflect(____BAH_COMPILER_VAR_265, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_282, 0, 0, 0);
char * ____BAH_COMPILER_VAR_284 =toJson(____BAH_COMPILER_VAR_283);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_284);
fs.close((struct fileStream*)&fs);
};
int isValidCacheFile(struct cacheFile* cf){
if (((cf==null)||(cf->last!=getLastModified(cf->file)))) {
return false;
}
char * ____BAH_COMPILER_VAR_285 =pathToVarName(cf->file);char * ____BAH_COMPILER_VAR_286 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_285);
long int strLen_3 = strlen(".o.o");
;                            
                    ____BAH_COMPILER_VAR_286 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_286+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_286+currStrOff, "cache/", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_286+currStrOff, ____BAH_COMPILER_VAR_285, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_286+currStrOff, ".o.o", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                if ((fileExists(____BAH_COMPILER_VAR_286)==0)) {
return false;
}
return true;
};
//optimized out: debugLine
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
            struct Elems* nElems =  ____BAH_COMPILER_VAR_288;
long int j =  0;
for (; (j<len(elems->vars)); j =  j+1) {

                    if (elems->vars->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:29): elems->vars[%d] with length %d\n", j, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[j];
struct variable* ____BAH_COMPILER_VAR_289 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_289->name = "";
____BAH_COMPILER_VAR_289->type = "";
____BAH_COMPILER_VAR_289->isConst = false;
____BAH_COMPILER_VAR_289->constVal = "";
____BAH_COMPILER_VAR_289->isArray = false;
____BAH_COMPILER_VAR_289->from = "";
____BAH_COMPILER_VAR_289->outterScope = false;
____BAH_COMPILER_VAR_289->isGlobal = false;
struct variable* nv =  ____BAH_COMPILER_VAR_289;
*nv =  *v;
nv->outterScope =  true;

{
long nLength = j;
if (nElems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nElems->vars->data, (nLength+50)*sizeof(struct variable*));
nElems->vars->data = newPtr;
}
nElems->vars->data[j] =  nv;
nElems->vars->length = nLength+1;
} else {
nElems->vars->data[j] =  nv;
}
};
};
nElems->structs =  elems->structs;
nElems->types =  elems->types;
nElems->fns =  elems->fns;
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
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:73): line[%d] with length %d\n", 0, line->length);
                        exit(1);
                    };
                    struct Tok ft =  line->data[0];
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
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:112): line[%d] with length %d\n", 1, line->length);
                        exit(1);
                    };
                    struct Tok st =  line->data[1];
if (((st.type==TOKEN_TYPE_ENCL)&&(strcmp(st.cont, "(") == 0))) {

                    if (line->length <= len(line)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:114): line[%d] with length %d\n", len(line)-1, line->length);
                        exit(1);
                    };
                    struct Tok lt =  line->data[len(line)-1];
if (((lt.type==TOKEN_TYPE_ENCL)&&(strcmp(lt.cont, "}") == 0))) {
return LINE_TYPE_FN_DECL;
}
return LINE_TYPE_FN_CALL;
}
return LINE_TYPE_VAR;
}
return (lineType)-1;
};
__BAH_ARR_TYPE_Tok parseCast(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:133): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
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
nl->data[i] =  t;
nl->length = nLength+1;
} else {
nl->data[i] =  t;
}
};
i =  i + 1;
};
if ((i==len(line))) {
return line;
}
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:145): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "<") == 0)) {
if ((i + 3<len(line))) {

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:149): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];

                    if (line->length <= i + 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:150): line[%d] with length %d\n", i + 2, line->length);
                        exit(1);
                    };
                    struct Tok nnt =  line->data[i + 2];

                    if (line->length <= i + 3) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:151): line[%d] with length %d\n", i + 3, line->length);
                        exit(1);
                    };
                    struct Tok nnnt =  line->data[i + 3];
if ((nt.type==TOKEN_TYPE_VAR)) {
if ((nnt.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(nnt.cont, ">") == 0)) {
nnnt.bahType =  nt.cont;
struct string cCast =  getCType(nt.cont,elems);
char * cCastStr =  cCast.str((struct string*)&cCast);
char * ____BAH_COMPILER_VAR_290 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(cCastStr);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nnnt.cont);
;                            
                    ____BAH_COMPILER_VAR_290 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_290+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_290+currStrOff, cCastStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_290+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_290+currStrOff, nnnt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                }
                nnnt.cont =  ____BAH_COMPILER_VAR_290;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  nnnt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  nnnt;
}
};
i =  i + 3;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
};
return nl;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_291 =__STR(f);array(char)* p =  strAsArr(____BAH_COMPILER_VAR_291);
long int i =  len(p)-1;
while ((i>=0)) {

                    if (p->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:179): p[%d] with length %d\n", i, p->length);
                        exit(1);
                    };
                    char c =  p->data[i];
if ((c==47)) {

{
long nLength = i + 1;
if (p->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(p->data, (nLength+50)*sizeof(char));
p->data = newPtr;
}
p->data[i + 1] =  (char)0;
p->length = nLength+1;
} else {
p->data[i + 1] =  (char)0;
}
};
break;
}
i =  i - 1;
};
if ((i<=0)) {
return "";
}
return arrAsStr(p);
};
void parseLines(__BAH_ARR_TYPE_Tok ts,struct Elems* elems);
int includeFile(char * ccstr,struct Elems* elems){
if ((strcmp(ccstr, "BAH_MEM_COLLECTOR") == 0)) {
if ((RCPenabled==true)) {
if (flags.isSet((struct flags*)&flags,"rcp")) {
ccstr =  "rcp.bah";
}
else if (flags.isSet((struct flags*)&flags,"fastrcp")) {
ccstr =  "fastrcp.bah";
}
}
else {
ccstr =  "gc.bah";
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
struct fileMap fm =  ____BAH_COMPILER_VAR_293;
char * ____BAH_COMPILER_VAR_294 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(ccstr);
;                            
                    ____BAH_COMPILER_VAR_294 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_294+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_294+currStrOff, ccstr, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * fileName =  ____BAH_COMPILER_VAR_294;
int isBahDir =  true;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_295 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(ccstr);
;                            
                    ____BAH_COMPILER_VAR_295 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_295+currStrOff, compilerState.currentDir, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_295+currStrOff, ccstr, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fileName =  absPath(____BAH_COMPILER_VAR_295);
f =  fm.open((struct fileMap*)&fm,fileName);
isBahDir =  false;
if ((fm.isValid((struct fileMap*)&fm)==0)) {
return false;
}
}
char * oDir =  compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_296 =getDirFromFile(ccstr);char * ____BAH_COMPILER_VAR_297 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_296);
;                            
                    ____BAH_COMPILER_VAR_297 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_297+currStrOff, compilerState.currentDir, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_297+currStrOff, ____BAH_COMPILER_VAR_296, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                compilerState.currentDir =  ____BAH_COMPILER_VAR_297;
}
else {
char * ____BAH_COMPILER_VAR_298 =getDirFromFile(ccstr);char * ____BAH_COMPILER_VAR_299 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_298);
;                            
                    ____BAH_COMPILER_VAR_299 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_299+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_299+currStrOff, ____BAH_COMPILER_VAR_298, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                compilerState.currentDir =  ____BAH_COMPILER_VAR_299;
}
char * oFile =  compilerState.currentFile;
compilerState.currentFile =  fileName;

{
long nLength = len(compilerState.includes);
if (compilerState.includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.includes->data, (nLength+50)*sizeof(char *));
compilerState.includes->data = newPtr;
}
compilerState.includes->data[len(compilerState.includes)] =  ccstr;
compilerState.includes->length = nLength+1;
} else {
compilerState.includes->data[len(compilerState.includes)] =  ccstr;
}
};
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_300 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(ccstr);
long int strLen_2 = strlen("' not recognized.");
;                            
                    ____BAH_COMPILER_VAR_300 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_300+currStrOff, "File '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_300+currStrOff, ccstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_300+currStrOff, "' not recognized.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                __BAH_panic(____BAH_COMPILER_VAR_300,"/home/alois/Documents/bah-bah/src/parser.bah:246");
}
int oshd =  shouldOnlyDecl;
if ((isObject==true)) {
shouldOnlyDecl =  true;
}
else if ((isSubObject==true)) {
shouldOnlyDecl =  false;
}
parseLines(tokens,elems);
shouldOnlyDecl =  oshd;
compilerState.currentFile =  oFile;
compilerState.currentDir =  oDir;
return true;
};
void parseImport(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
compilerState.hasImports =  true;
if ((len(l)!=2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:273): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok strt =  l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as file name (#import \"file\")");
}
struct string fileName =  string(strt.cont);
fileName.trimLeft((struct string*)&fileName,1);
fileName.trimRight((struct string*)&fileName,1);

                int ____BAH_COMPILER_VAR_301 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], fileName.str((struct string*)&fileName)) == 0) {
                        ____BAH_COMPILER_VAR_301 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_301) {
char * ____BAH_COMPILER_VAR_302 =fileName.str((struct string*)&fileName);char * ____BAH_COMPILER_VAR_303 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Imported object '");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_302);
long int strLen_2 = strlen("' has already been include/imported.");
;                            
                    ____BAH_COMPILER_VAR_303 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_303+currStrOff, "Imported object '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_303+currStrOff, ____BAH_COMPILER_VAR_302, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_303+currStrOff, "' has already been include/imported.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwWarning(____BAH_COMPILER_VAR_303);
return;
}

{
long nLength = len(compilerState.includes);
if (compilerState.includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.includes->data, (nLength+50)*sizeof(char *));
compilerState.includes->data = newPtr;
}
compilerState.includes->data[len(compilerState.includes)] =  fileName.str((struct string*)&fileName);
compilerState.includes->length = nLength+1;
} else {
compilerState.includes->data[len(compilerState.includes)] =  fileName.str((struct string*)&fileName);
}
};
char * ____BAH_COMPILER_VAR_304 =fileName.str((struct string*)&fileName);char * fn =  absPath(____BAH_COMPILER_VAR_304);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_305 =fileName.str((struct string*)&fileName);char * ____BAH_COMPILER_VAR_306 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_305);
;                            
                    ____BAH_COMPILER_VAR_306 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_306+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_306+currStrOff, ____BAH_COMPILER_VAR_305, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fn =  absPath(____BAH_COMPILER_VAR_306);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of =  compilerState.currentFile;
char * od =  compilerState.currentDir;
compilerState.currentFile =  fn;
compilerState.currentDir =  getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_307 = {};
____BAH_COMPILER_VAR_307.handle= null;
____BAH_COMPILER_VAR_307.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_307.open = fileStream__open;
____BAH_COMPILER_VAR_307.close = fileStream__close;
____BAH_COMPILER_VAR_307.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_307.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_307.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_307.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_307.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_307.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_307.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_307.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_307.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_307.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_307.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_307.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_307.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_307;
fs.open((struct fileStream*)&fs,fn,"r");
char * f =  fs.readContent((struct fileStream*)&fs);
fs.close((struct fileStream*)&fs);
array(struct Tok)* tokens =  lexer(f);
int osod =  shouldOnlyDecl;
shouldOnlyDecl =  true;
int oiso =  isSubObject;
isSubObject =  true;
char * ____BAH_COMPILER_VAR_308 =pathToVarName(fn);char * ____BAH_COMPILER_VAR_309 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("cache/");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_308);
long int strLen_3 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_309 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_309+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_309+currStrOff, "cache/", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_309+currStrOff, ____BAH_COMPILER_VAR_308, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_309+currStrOff, ".o", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                char * oName =  ____BAH_COMPILER_VAR_309;
char * ____BAH_COMPILER_VAR_310 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("w ");
long int strLen_1 = strlen(oName);
long int strLen_2 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_310 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_310+currStrOff, "w ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_310+currStrOff, oName, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_310+currStrOff, ".o", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                
{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] =  ____BAH_COMPILER_VAR_310;
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] =  ____BAH_COMPILER_VAR_310;
}
};
parseLines(tokens,elems);
readCache();
struct cacheFile* cf =  getCacheFile(fn);
char * wrkd =  getCurrentPath();
if ((isValidCacheFile(cf)==false)) {
setCurrentPath(compilerState.currentDir);
char * verboseCC =  "";
if ((flags.isSet((struct flags*)&flags,"verboseCC")==1)) {
verboseCC =  "-verboseCC";
}
char * ____BAH_COMPILER_VAR_311 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(execName);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(fn);
long int strLen_3 = strlen(" -object ");
long int strLen_4 = strlen(verboseCC);
long int strLen_5 = strlen(" -o ");
long int strLen_6 = strlen(oName);
;                            
                    ____BAH_COMPILER_VAR_311 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_311+currStrOff, execName, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_311+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_311+currStrOff, fn, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_311+currStrOff, " -object ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_311+currStrOff, verboseCC, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_311+currStrOff, " -o ", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_311+currStrOff, oName, strLen_6);
                    currStrOff += strLen_6;
                    
                }
                struct command cmd =  command(____BAH_COMPILER_VAR_311);
char * res =  cmd.run((struct command*)&cmd);
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
char * ____BAH_COMPILER_VAR_312 =pathToVarName(fn);char * ____BAH_COMPILER_VAR_313 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_init");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_312);
long int strLen_2 = strlen("();\n");
;                            
                    ____BAH_COMPILER_VAR_313 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_313+currStrOff, "__BAH_init", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_313+currStrOff, ____BAH_COMPILER_VAR_312, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_313+currStrOff, "();\n", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_313));
writeCache();
shouldOnlyDecl =  osod;
isSubObject =  oiso;
compilerState.currentFile =  of;
compilerState.currentDir =  od;
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:368): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok strt =  l->data[1];
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
char * sc =  strt.cont;
strTrimLeft(&sc,1);
strTrimRight(&sc,1);
if (((strHasPrefix(sc,"<")||strHasSuffix(sc,".h"))||strHasSuffix(sc,".c"))) {
char * ____BAH_COMPILER_VAR_314 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(sc);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_314 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_314+currStrOff, "#include ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_314+currStrOff, sc, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_314+currStrOff, "\n", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_314));

{
long nLength = len(compilerState.cIncludes);
if (compilerState.cIncludes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cIncludes->data, (nLength+50)*sizeof(char *));
compilerState.cIncludes->data = newPtr;
}
compilerState.cIncludes->data[len(compilerState.cIncludes)] =  sc;
compilerState.cIncludes->length = nLength+1;
} else {
compilerState.cIncludes->data[len(compilerState.cIncludes)] =  sc;
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
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:390): line[%d] with length %d\n", 0, line->length);
                        exit(1);
                    };
                    array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = line->data[0];

                    if (line->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:391): line[%d] with length %d\n", 0, line->length);
                        exit(1);
                    };
                    array(struct Tok)* unNestedLine = memoryAlloc(sizeof(array(struct Tok)));

unNestedLine->length = 1;
unNestedLine->elemSize = sizeof(struct Tok);
unNestedLine->data = memoryAlloc(sizeof(struct Tok) * 50);unNestedLine->data[0] = line->data[0];
long int i =  1;
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:394): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];

                    if (line->length <= i-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:395): line[%d] with length %d\n", i-1, line->length);
                        exit(1);
                    };
                    struct Tok pt =  line->data[i-1];
if (((strcmp(t.cont, "(") == 0)&&(pt.type!=TOKEN_TYPE_KEYWORD))) {
long int nbPars =  1;
i =  i+1;
array(struct Tok)* mem = memoryAlloc(sizeof(array(struct Tok)));

mem->length = 0;
mem->elemSize = sizeof(struct Tok);
struct Tok ft =  t;
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:403): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    t =  line->data[i];

                    if (line->length <= i-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:404): line[%d] with length %d\n", i-1, line->length);
                        exit(1);
                    };
                    pt =  line->data[i-1];
if (((strcmp(t.cont, "(") == 0)&&(pt.type!=TOKEN_TYPE_KEYWORD))) {
nbPars =  nbPars+1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPars =  nbPars-1;
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
mem->data[len(mem)] =  t;
mem->length = nLength+1;
} else {
mem->data[len(mem)] =  t;
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
unNestedLine->data[len(unNestedLine)] =  ft;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] =  ft;
}
};

{
long nLength = len(unNestedLine);
if (unNestedLine->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(unNestedLine->data, (nLength+50)*sizeof(struct Tok));
unNestedLine->data = newPtr;
}
unNestedLine->data[len(unNestedLine)] =  t;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] =  t;
}
};
continue;
}
array(struct Tok)* tmpL =  parseOperations(mem,ltp,elems);

                    if (tmpL->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:423): tmpL[%d] with length %d\n", 0, tmpL->length);
                        exit(1);
                    };
                    struct Tok nestedT =  tmpL->data[0];
char * ____BAH_COMPILER_VAR_315 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(nestedT.cont);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_315 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_315+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_315+currStrOff, nestedT.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_315+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                nestedT.cont =  ____BAH_COMPILER_VAR_315;

{
long nLength = len(unNestedLine);
if (unNestedLine->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(unNestedLine->data, (nLength+50)*sizeof(struct Tok));
unNestedLine->data = newPtr;
}
unNestedLine->data[len(unNestedLine)] =  nestedT;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] =  nestedT;
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
unNestedLine->data[len(unNestedLine)] =  t;
unNestedLine->length = nLength+1;
} else {
unNestedLine->data[len(unNestedLine)] =  t;
}
};
};
line =  unNestedLine;
i =  1;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:433): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];

                int ____BAH_COMPILER_VAR_316 = 0;
                for(int i=len(signs)-1; i != -1; i--) {
                    if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                        ____BAH_COMPILER_VAR_316 = 1;
                        break;
                    };
                };
                if (((t.type==TOKEN_TYPE_SYNTAX)&&____BAH_COMPILER_VAR_316)) {
if ((i + 1>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:439): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:440): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];
if ((((strcmp(t.cont, "-") == 0)&&(pt.isValue==false))&&(nt.type==TOKEN_TYPE_INT))) {
char * ____BAH_COMPILER_VAR_317 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_317 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_317+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_317+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                nt.cont =  ____BAH_COMPILER_VAR_317;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  nt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  nt;
}
};
i =  i + 2;
continue;
}
if (((nt.type==TOKEN_TYPE_SYNTAX)&&(strcmp(nt.cont, t.cont) == 0))) {
char * ____BAH_COMPILER_VAR_318 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_318 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_318+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_318+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * c =  ____BAH_COMPILER_VAR_318;
long int tl =  t.line;
long int tp =  t.pos;
struct Tok ____BAH_COMPILER_VAR_319 = {};
____BAH_COMPILER_VAR_319.cont = "";
____BAH_COMPILER_VAR_319.ogCont = "";
____BAH_COMPILER_VAR_319.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_319.pos = 0;
____BAH_COMPILER_VAR_319.line = 1;
____BAH_COMPILER_VAR_319.begLine = 1;
____BAH_COMPILER_VAR_319.bahType = "";
____BAH_COMPILER_VAR_319.isValue = false;
____BAH_COMPILER_VAR_319.isFunc = false;
____BAH_COMPILER_VAR_319.isOper = false;
____BAH_COMPILER_VAR_319.cont = c;
____BAH_COMPILER_VAR_319.ogCont = c;
____BAH_COMPILER_VAR_319.isValue = false;
____BAH_COMPILER_VAR_319.line = tl;
____BAH_COMPILER_VAR_319.pos = tp;
____BAH_COMPILER_VAR_319.type = TOKEN_TYPE_SYNTAX;
struct Tok tmpT =  ____BAH_COMPILER_VAR_319;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  tmpT;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  tmpT;
}
};
i =  i + 2;
continue;
}
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_320 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_320 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_320+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_320+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_320+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_320+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_320+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&nt,____BAH_COMPILER_VAR_320);
}
t.isValue =  true;
if (((verboseRuntime==true)&&(ltp!=LINE_TYPE_ELSE))) {
if ((isRCPpointerType(ntt)||isRCPpointerType(ptt))) {
verboseOutOper(pt,nt,pt.line,elems);
}
}
if (compTypes(ptt,"cpstring")) {
if ((strcmp(t.cont, "+") != 0)) {
throwErr(&t,"Can only do concatenation (+) on cpstrings, not {TOKEN}.");
}
long int j =  i - 1;
int wasAdd =  true;
array(char *)* strConts = memoryAlloc(sizeof(array(char *)));

strConts->length = 0;
strConts->elemSize = sizeof(char *);
for (; (j<len(line)); j =  j+1) {

                    if (line->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:492): line[%d] with length %d\n", j, line->length);
                        exit(1);
                    };
                    struct Tok strAddTk =  line->data[j];
if ((wasAdd==false)) {
if ((strcmp(strAddTk.cont, "+") != 0)) {
break;
}
wasAdd =  true;
}
else {
char * strAddTkT =  getTypeFromToken(&strAddTk,true,elems);
if ((compTypes(strAddTkT,"cpstring")==false)) {
char * ____BAH_COMPILER_VAR_321 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_321 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_321+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_321+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_321+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_321+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_321+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&strAddTkT,____BAH_COMPILER_VAR_321);
break;
}
if ((((strAddTk.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(strAddTk.cont,"noCheck(")==false))&&(isRCPtype(strAddTkT,elems)==true))) {

{
long nLength = len(strConts);
if (strConts->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(strConts->data, (nLength+50)*sizeof(char *));
strConts->data = newPtr;
}
strConts->data[len(strConts)] =  registerRCPvar(strAddTkT,strAddTk.cont,elems);
strConts->length = nLength+1;
} else {
strConts->data[len(strConts)] =  registerRCPvar(strAddTkT,strAddTk.cont,elems);
}
};
}
else {

{
long nLength = len(strConts);
if (strConts->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(strConts->data, (nLength+50)*sizeof(char *));
strConts->data = newPtr;
}
strConts->data[len(strConts)] =  strAddTk.cont;
strConts->length = nLength+1;
} else {
strConts->data[len(strConts)] =  strAddTk.cont;
}
};
}
wasAdd =  false;
}
};
i =  j;
char * rstr =  registerRCPvar("cpstring","null",elems);
char * lens =  "";
char * totStrLen =  "1";
j =  0;
for (; (j<len(strConts)); j =  j+1) {
char * js =  intToStr(j);

                    if (strConts->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:522): strConts[%d] with length %d\n", j, strConts->length);
                        exit(1);
                    };
                    char * ____BAH_COMPILER_VAR_322 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lens);
long int strLen_1 = strlen("long int strLen_");
long int strLen_2 = strlen(js);
long int strLen_3 = strlen(" = strlen(");
long int strLen_4 = strlen(strConts->data[j]);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_322 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_322+currStrOff, lens, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_322+currStrOff, "long int strLen_", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_322+currStrOff, js, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_322+currStrOff, " = strlen(", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_322+currStrOff, strConts->data[j], strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_322+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                lens =  ____BAH_COMPILER_VAR_322;
char * ____BAH_COMPILER_VAR_323 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(" + strLen_");
long int strLen_2 = strlen(js);
;                            
                    ____BAH_COMPILER_VAR_323 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_323+currStrOff, totStrLen, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_323+currStrOff, " + strLen_", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_323+currStrOff, js, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                totStrLen =  ____BAH_COMPILER_VAR_323;
};
struct rope* cats =  rope("");
j =  0;
for (; (j<len(strConts)); j =  j+1) {
char * js =  intToStr(j);

                    if (strConts->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:530): strConts[%d] with length %d\n", j, strConts->length);
                        exit(1);
                    };
                    char * ____BAH_COMPILER_VAR_324 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    strncpy(");
long int strLen_1 = strlen(rstr);
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(strConts->data[j]);
long int strLen_4 = strlen(", strLen_");
long int strLen_5 = strlen(js);
long int strLen_6 = strlen(");\n                    currStrOff += strLen_");
long int strLen_7 = strlen(js);
long int strLen_8 = strlen(";\n                    ");
;                            
                    ____BAH_COMPILER_VAR_324 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    strncpy(____BAH_COMPILER_VAR_324+currStrOff, "\n                    strncpy(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_324+currStrOff, rstr, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_324+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_324+currStrOff, strConts->data[j], strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_324+currStrOff, ", strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_324+currStrOff, js, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_324+currStrOff, ");\n                    currStrOff += strLen_", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_324+currStrOff, js, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_324+currStrOff, ";\n                    ", strLen_8);
                    currStrOff += strLen_8;
                    
                }
                cats =  cats->add(cats, rope(____BAH_COMPILER_VAR_324));
};
char * ____BAH_COMPILER_VAR_325 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                {\n                    long int currStrOff = 0;\n                    ");
long int strLen_1 = strlen(lens);
long int strLen_2 = strlen(";                            \n                    ");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen(" = memoryAllocSTR(");
long int strLen_5 = strlen(totStrLen);
long int strLen_6 = strlen(");\n                    ");
;                            
                    ____BAH_COMPILER_VAR_325 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_325+currStrOff, "\n                {\n                    long int currStrOff = 0;\n                    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_325+currStrOff, lens, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_325+currStrOff, ";                            \n                    ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_325+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_325+currStrOff, " = memoryAllocSTR(", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_325+currStrOff, totStrLen, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_325+currStrOff, ");\n                    ", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                struct rope* res =  rope(____BAH_COMPILER_VAR_325)->add(rope(____BAH_COMPILER_VAR_325), cats)->add(rope(____BAH_COMPILER_VAR_325)->add(rope(____BAH_COMPILER_VAR_325), cats), rope("\n                }\n                "));
if (isGlobal()) {
INIT =  INIT->add(INIT, res);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, res);
}
t.cont =  rstr;
t.type =  TOKEN_TYPE_VAR;
t.bahType =  ptt;
t.isOper =  false;
t.pos =  pt.pos;
t.ogCont =  pt.cont;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
}
};
continue;
}
else {
struct cStruct* s =  searchStruct(ptt,elems);
if ((s!=null)) {
struct structMemb* addMthd =  searchStructMemb("add",s,elems);
struct structMemb* subMthd =  searchStructMemb("sub",s,elems);
struct structMemb* multMthd =  searchStructMemb("mult",s,elems);
struct structMemb* divMthd =  searchStructMemb("div",s,elems);
char * sep =  ".";
char * amp =  "&";
if ((strCount(ptt,"*")>0)) {
sep =  "->";
amp =  "";
}
if ((((strcmp(t.cont, "+") == 0)&&(addMthd!=null))&&(addMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_326 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen("add(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(nt.cont);
long int strLen_7 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_326 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    strncpy(____BAH_COMPILER_VAR_326+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_326+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_326+currStrOff, "add(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_326+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_326+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_326+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_326+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_326+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_326;
}
else if ((((strcmp(t.cont, "-") == 0)&&(subMthd!=null))&&(subMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_327 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen("sub(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(nt.cont);
long int strLen_7 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_327 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    strncpy(____BAH_COMPILER_VAR_327+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_327+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_327+currStrOff, "sub(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_327+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_327+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_327+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_327+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_327+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_327;
}
else if ((((strcmp(t.cont, "*") == 0)&&(multMthd!=null))&&(multMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_328 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen("mult(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(nt.cont);
long int strLen_7 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_328 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    strncpy(____BAH_COMPILER_VAR_328+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_328+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_328+currStrOff, "mult(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_328+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_328+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_328+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_328+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_328+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_328;
}
else if ((((strcmp(t.cont, "/") == 0)&&(divMthd!=null))&&(divMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_329 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen("div(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(nt.cont);
long int strLen_7 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_329 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    strncpy(____BAH_COMPILER_VAR_329+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_329+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_329+currStrOff, "div(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_329+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_329+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_329+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_329+currStrOff, nt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_329+currStrOff, ")", strLen_7);
                    currStrOff += strLen_7;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_329;
}
else {
char * ____BAH_COMPILER_VAR_330 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Undefined operation on {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_330+currStrOff, "Undefined operation on {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_330+currStrOff, ptt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_330+currStrOff, ").", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&pt,____BAH_COMPILER_VAR_330);
}
}
else {
char * ____BAH_COMPILER_VAR_331 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_331 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_331+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_331+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_331+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_331+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_331+currStrOff, nt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_331;
}
}
t.type =  TOKEN_TYPE_VAR;
t.bahType =  ptt;
t.pos =  pt.pos;
t.isOper =  true;
t.ogCont =  pt.cont;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
}
};
i =  i + 2;
continue;
}
else if ((t.isValue==true)) {
if (strHasPrefix(t.cont,"-")) {

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:605): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];
if ((pt.isValue==true)) {
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&t,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_332 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_332 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_332+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_332+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_332+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_332+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_332+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&t,____BAH_COMPILER_VAR_332);
}
t.type =  TOKEN_TYPE_VAR;
t.isOper =  true;
char * ____BAH_COMPILER_VAR_333 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_333 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_333+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_333+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_333;
t.bahType =  ptt;
t.pos =  pt.pos;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
}
};
i =  i+1;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
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
long int i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:641): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
if (strHasPrefix(t.bahType,"[]")) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
continue;
}
i =  i+1;
struct Tok ____BAH_COMPILER_VAR_334 = {};
____BAH_COMPILER_VAR_334.cont = "";
____BAH_COMPILER_VAR_334.ogCont = "";
____BAH_COMPILER_VAR_334.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_334.pos = 0;
____BAH_COMPILER_VAR_334.line = 1;
____BAH_COMPILER_VAR_334.begLine = 1;
____BAH_COMPILER_VAR_334.bahType = "";
____BAH_COMPILER_VAR_334.isValue = false;
____BAH_COMPILER_VAR_334.isFunc = false;
____BAH_COMPILER_VAR_334.isOper = false;
____BAH_COMPILER_VAR_334.cont = "";
struct Tok nt =  ____BAH_COMPILER_VAR_334;
if ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:654): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    nt =  line->data[i];
}
if (((i==len(line))||(strcmp(nt.cont, "{") != 0))) {
if ((i-2>=0)) {

                    if (line->length <= i-2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:658): line[%d] with length %d\n", i-2, line->length);
                        exit(1);
                    };
                    struct Tok newTk =  line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
struct cStruct* s =  searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Cannot initialize new unknown struct {TOKEN}.");
}
t.cont =  genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_335 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_335->name = "";
____BAH_COMPILER_VAR_335->type = "";
____BAH_COMPILER_VAR_335->isConst = false;
____BAH_COMPILER_VAR_335->constVal = "";
____BAH_COMPILER_VAR_335->isArray = false;
____BAH_COMPILER_VAR_335->from = "";
____BAH_COMPILER_VAR_335->outterScope = false;
____BAH_COMPILER_VAR_335->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_335;
tmpV->name =  t.cont;
char * ____BAH_COMPILER_VAR_336 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_336 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_336+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_336+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpV->type =  ____BAH_COMPILER_VAR_336;
struct string cType =  getCType(tmpV->type,elems);
struct string structType =  getCType(s->name,elems);

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  tmpV;
}
};
char * ____BAH_COMPILER_VAR_337 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_338 =structType.str((struct string*)&structType);char * ____BAH_COMPILER_VAR_339 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_340 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_337);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_338);
long int strLen_5 = strlen("));\n");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_339);
;                            
                    ____BAH_COMPILER_VAR_340 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_340+currStrOff, ____BAH_COMPILER_VAR_337, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_340+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_340+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_340+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_340+currStrOff, ____BAH_COMPILER_VAR_338, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_340+currStrOff, "));\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_340+currStrOff, ____BAH_COMPILER_VAR_339, strLen_6);
                    currStrOff += strLen_6;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_340));

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
}
};
continue;
}
}
}
if ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:682): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    nt =  line->data[i];
if ((strcmp(nt.cont, "{") == 0)) {
int isHeap =  false;
char * sep =  ".";
if ((i-2>=0)) {

                    if (line->length <= i-2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:687): line[%d] with length %d\n", i-2, line->length);
                        exit(1);
                    };
                    struct Tok newTk =  line->data[i-2];
if ((strcmp(newTk.cont, "new") == 0)) {
isHeap =  true;
sep =  "->";
}
}
i =  i+1;
struct cStruct* s =  searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int nbBraces =  1;
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:702): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    t =  line->data[i];
if ((strcmp(t.cont, "{") == 0)) {
nbBraces =  nbBraces+1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbBraces =  nbBraces-1;
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
memory->data[len(memory)] =  t;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  t;
}
};
};
if ((len(memory)>0)) {
memory =  prePross(memory,(lineType)-1,elems);
}
long int declType =  0;
char * rvn =  genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_341 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_341->name = "";
____BAH_COMPILER_VAR_341->type = "";
____BAH_COMPILER_VAR_341->isConst = false;
____BAH_COMPILER_VAR_341->constVal = "";
____BAH_COMPILER_VAR_341->isArray = false;
____BAH_COMPILER_VAR_341->from = "";
____BAH_COMPILER_VAR_341->outterScope = false;
____BAH_COMPILER_VAR_341->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_341;
tmpV->name =  rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_342 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_342 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_342+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_342+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpV->type =  ____BAH_COMPILER_VAR_342;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  tmpV;
}
};
}
else {
tmpV->type =  s->name;
}
struct string rst =  getCType(tmpV->type,elems);
struct rope* r= null;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_343 =rst.str((struct string*)&rst);struct string structType =  string(____BAH_COMPILER_VAR_343);
structType.trimRight((struct string*)&structType,1);
char * ____BAH_COMPILER_VAR_344 =rst.str((struct string*)&rst);char * ____BAH_COMPILER_VAR_345 =structType.str((struct string*)&structType);char * ____BAH_COMPILER_VAR_346 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_347 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_344);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" = memoryAlloc(sizeof(");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_345);
long int strLen_5 = strlen("));\n");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_346);
;                            
                    ____BAH_COMPILER_VAR_347 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_347+currStrOff, ____BAH_COMPILER_VAR_344, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_347+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_347+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_347+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_347+currStrOff, ____BAH_COMPILER_VAR_345, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_347+currStrOff, "));\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_347+currStrOff, ____BAH_COMPILER_VAR_346, strLen_6);
                    currStrOff += strLen_6;
                    
                }
                r =  rope(____BAH_COMPILER_VAR_347);
}
else {
char * ____BAH_COMPILER_VAR_348 =rst.str((struct string*)&rst);char * ____BAH_COMPILER_VAR_349 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_350 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_348);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" = {};\n");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_349);
;                            
                    ____BAH_COMPILER_VAR_350 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_350+currStrOff, ____BAH_COMPILER_VAR_348, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_350+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_350+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_350+currStrOff, " = {};\n", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_350+currStrOff, ____BAH_COMPILER_VAR_349, strLen_4);
                    currStrOff += strLen_4;
                    
                }
                r =  rope(____BAH_COMPILER_VAR_350);
}
long int j =  0;
long int k =  0;
while ((k<len(memory))) {

                    if (memory->length <= k) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:743): memory[%d] with length %d\n", k, memory->length);
                        exit(1);
                    };
                    t =  memory->data[k];
if ((k + 2<len(memory))) {

                    if (memory->length <= k + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:746): memory[%d] with length %d\n", k + 1, memory->length);
                        exit(1);
                    };
                    struct Tok st =  memory->data[k + 1];

                    if (memory->length <= k + 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:747): memory[%d] with length %d\n", k + 2, memory->length);
                        exit(1);
                    };
                    struct Tok vl =  memory->data[k + 2];
if ((strcmp(st.cont, ":") == 0)) {
if (((declType!=0)&&(declType!=1))) {
throwErr(&t,"Cannot declare member {TOKEN} by name in list declaration.");
}
declType =  1;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as struct member name.");
}
j =  0;
while ((j<len(s->members))) {

                    if (s->members->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:757): s->members[%d] with length %d\n", j, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[j];
if ((strcmp(m->name, t.cont) != 0)) {
j =  j + 1;
continue;
}
char * vlt =  getTypeFromToken(&vl,true,elems);
if ((compTypes(vlt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_351 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(vlt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_351 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_351+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_351+currStrOff, vlt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_351+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_351+currStrOff, m->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_351+currStrOff, "'.", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&vl,____BAH_COMPILER_VAR_351);
}
char * ____BAH_COMPILER_VAR_352 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(vl.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_352 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_352+currStrOff, rvn, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_352+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_352+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_352+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_352+currStrOff, vl.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_352+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_352));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_353 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Struct '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has no member called {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_353 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_353+currStrOff, "Struct '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_353+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_353+currStrOff, "' has no member called {TOKEN}.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&t,____BAH_COMPILER_VAR_353);
}
k =  k + 3;
continue;
}
}
if (((declType!=0)&&(declType!=2))) {
throwErr(&t,"Cannot declare member {TOKEN} without specifying its name.");
}
declType =  2;
if ((j>len(s->members))) {
throwErr(&t,"Too many members {TOKEN}.");
}

                    if (s->members->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:784): s->members[%d] with length %d\n", j, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[j];
j =  j+1;
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_354 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_354 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_354+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_354+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_354+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_354+currStrOff, m->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_354+currStrOff, "'.", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&t,____BAH_COMPILER_VAR_354);
}
char * ____BAH_COMPILER_VAR_355 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_355 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_355+currStrOff, rvn, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_355+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_355+currStrOff, m->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_355+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_355+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_355+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                r =  r->add(r, rope(____BAH_COMPILER_VAR_355));
if ((k + 1<len(memory))) {
k =  k+1;

                    if (memory->length <= k) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:796): memory[%d] with length %d\n", k, memory->length);
                        exit(1);
                    };
                    struct Tok st =  memory->data[k];
if ((strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Need ',' separator between two values, not {TOKEN}.");
}
}
k =  k+1;
};
if (isGlobal()) {
INIT =  INIT->add(INIT, r);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, r);
}
t.bahType =  tmpV->type;
t.cont =  rvn;
t.isValue =  true;
if ((isHeap==true)) {

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  t;
}
};
}
else {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
}
i =  i+1;
continue;
}
else {
i =  i-1;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseStructVars(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:840): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((strcmp(t.cont, ".") == 0)) {
break;
}
i =  i + 1;
};
if ((i==len(line))) {
return line;
}
i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:852): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i+1;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:856): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok it =  line->data[i];
if ((strcmp(it.cont, ".") != 0)) {
break;
}
struct variable* v =  searchVar(t.cont,elems);
if ((v==null)) {
throwErr(&t,"Unknown var {TOKEN}.");
}
char * sep =  ".";
if (strCount(v->type,"*")) {
sep =  "->";
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
char * ____BAH_COMPILER_VAR_356 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(v->type);
long int strLen_2 = strlen(") as a structure.");
;                            
                    ____BAH_COMPILER_VAR_356 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_356+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_356+currStrOff, v->type, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_356+currStrOff, ") as a structure.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&t,____BAH_COMPILER_VAR_356);
}
i =  i+1;

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:873): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as struct member name.");
}
struct structMemb* memb =  searchStructMemb(nt.cont,s,elems);
if ((memb==null)) {
throwErr(&nt,"Unknown struct member {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_357 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(memb->name);
;                            
                    ____BAH_COMPILER_VAR_357 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_357+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_357+currStrOff, sep, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_357+currStrOff, memb->name, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_357;
i =  i+1;
};

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:901): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
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
nl->data[i] =  t;
nl->length = nLength+1;
} else {
nl->data[i] =  t;
}
};
};
if ((i==len(line))) {
return line;
}
for (; (i<len(line)); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:912): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
i =  i+1;
if ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:916): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    t =  line->data[i];
if ((strcmp(t.cont, "]") == 0)) {
i =  i+1;
long int depth =  1;
char * bracks =  "[]";
for (; (i<len(line) - 1); i =  i+1) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:922): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    t =  line->data[i];

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:923): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];
if (((strcmp(t.cont, "[") == 0)&&(strcmp(nt.cont, "]") == 0))) {
depth =  depth+1;
char * ____BAH_COMPILER_VAR_358 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen("[]");
;                            
                    ____BAH_COMPILER_VAR_358 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_358+currStrOff, bracks, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_358+currStrOff, "[]", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                bracks =  ____BAH_COMPILER_VAR_358;
i =  i+1;
}
else {
break;
}
};
if ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:933): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    t =  line->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem =  t.cont;
char * ____BAH_COMPILER_VAR_359 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(bracks);
long int strLen_1 = strlen(arrElem);
;                            
                    ____BAH_COMPILER_VAR_359 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_359+currStrOff, bracks, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_359+currStrOff, arrElem, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                t.bahType =  ____BAH_COMPILER_VAR_359;
t.cont =  "";
t.isValue =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
};
return nl;
};
array(char *)* comparators;
array(char *)* compSep;
__BAH_ARR_TYPE_Tok parseBool(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:963): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
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
nl->data[i] =  t;
nl->length = nLength+1;
} else {
nl->data[i] =  t;
}
};
i =  i + 1;
};
if ((i==len(line))) {
return line;
}
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:975): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if (inArrayStr(t.cont,comparators)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:981): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:986): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT =  string(ntt);
if ((arrT.hasPrefix((struct string*)&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_360 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as an array.");
;                            
                    ____BAH_COMPILER_VAR_360 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_360+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_360+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_360+currStrOff, ") as an array.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&nt,____BAH_COMPILER_VAR_360);
}
arrT.trimLeft((struct string*)&arrT,2);
char * ____BAH_COMPILER_VAR_361 =arrT.str((struct string*)&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_361)==false)) {
char * ____BAH_COMPILER_VAR_362 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot search for {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(") inside array of type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_362 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_362+currStrOff, "Cannot search for {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_362+currStrOff, ptt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_362+currStrOff, ") inside array of type ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_362+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_362+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&pt,____BAH_COMPILER_VAR_362);
}
char * compVar =  genCompilerVar();
char * comp =  "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_363 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] != 0 && strcmp(");
long int strLen_2 = strlen(nt.cont);
long int strLen_3 = strlen("->data[i], ");
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(") == 0");
;                            
                    ____BAH_COMPILER_VAR_363 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_363+currStrOff, nt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_363+currStrOff, "->data[i] != 0 && strcmp(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_363+currStrOff, nt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_363+currStrOff, "->data[i], ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_363+currStrOff, pt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_363+currStrOff, ") == 0", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                comp =  ____BAH_COMPILER_VAR_363;
}
else {
char * ____BAH_COMPILER_VAR_364 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] == ");
long int strLen_2 = strlen(pt.cont);
;                            
                    ____BAH_COMPILER_VAR_364 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_364+currStrOff, nt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_364+currStrOff, "->data[i] == ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_364+currStrOff, pt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                comp =  ____BAH_COMPILER_VAR_364;
}
char * ____BAH_COMPILER_VAR_365 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                int ");
long int strLen_1 = strlen(compVar);
long int strLen_2 = strlen(" = 0;\n                for(int i=len(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")-1; i != -1; i--) {\n                    if (");
long int strLen_5 = strlen(comp);
long int strLen_6 = strlen(") {\n                        ");
long int strLen_7 = strlen(compVar);
long int strLen_8 = strlen(" = 1;\n                        break;\n                    };\n                };\n                ");
;                            
                    ____BAH_COMPILER_VAR_365 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    strncpy(____BAH_COMPILER_VAR_365+currStrOff, "\n                int ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_365+currStrOff, compVar, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_365+currStrOff, " = 0;\n                for(int i=len(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_365+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_365+currStrOff, ")-1; i != -1; i--) {\n                    if (", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_365+currStrOff, comp, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_365+currStrOff, ") {\n                        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_365+currStrOff, compVar, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_365+currStrOff, " = 1;\n                        break;\n                    };\n                };\n                ", strLen_8);
                    currStrOff += strLen_8;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_365));
pt.cont =  compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_366 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot compare {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_366 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_366+currStrOff, "Cannot compare {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_366+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_366+currStrOff, ") to ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_366+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_366+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&nt,____BAH_COMPILER_VAR_366);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_367 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strcmp(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(") == 0)");
;                            
                    ____BAH_COMPILER_VAR_367 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_367+currStrOff, "(strcmp(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_367+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_367+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_367+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_367+currStrOff, ") == 0)", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                pt.cont =  ____BAH_COMPILER_VAR_367;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_368 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strcmp(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(") != 0)");
;                            
                    ____BAH_COMPILER_VAR_368 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_368+currStrOff, "(strcmp(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_368+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_368+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_368+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_368+currStrOff, ") != 0)", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                pt.cont =  ____BAH_COMPILER_VAR_368;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_369 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") > srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_369 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_369+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_369+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_369+currStrOff, ") > srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_369+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_369+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                pt.cont =  ____BAH_COMPILER_VAR_369;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_370 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") < srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_370+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_370+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_370+currStrOff, ") < srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_370+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_370+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                pt.cont =  ____BAH_COMPILER_VAR_370;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_371 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") >= srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_371 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_371+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_371+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_371+currStrOff, ") >= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_371+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_371+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                pt.cont =  ____BAH_COMPILER_VAR_371;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_372 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") <= srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_372 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_372+currStrOff, "(strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_372+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_372+currStrOff, ") <= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_372+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_372+currStrOff, "))", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                pt.cont =  ____BAH_COMPILER_VAR_372;
}
}
else {
char * ____BAH_COMPILER_VAR_373 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_373 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_373+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_373+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_373+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_373+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_373+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                pt.cont =  ____BAH_COMPILER_VAR_373;
}
}
pt.bahType =  "bool";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
}
};
i =  i + 2;
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
};
line =  nl;
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
i =  0;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1062): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if (inArrayStr(t.cont,compSep)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1067): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1072): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
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
char * ____BAH_COMPILER_VAR_374 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_374 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_374+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_374+currStrOff, pt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_374+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_374+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_374+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                pt.cont =  ____BAH_COMPILER_VAR_374;
pt.bahType =  "bool";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
}
};
i =  i + 2;
continue;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i+1;
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
long int i =  0;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1108): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i>0)) {

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1113): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];
if ((pt.type==TOKEN_TYPE_VAR)) {
if ((i + 1<len(l))) {

                    if (l->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1116): l[%d] with length %d\n", i + 1, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i + 1];
if ((nt.isValue==false)) {
char * ____BAH_COMPILER_VAR_375 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_375 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_375+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_375+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                pt.cont =  ____BAH_COMPILER_VAR_375;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
}
};
i =  i + 1;
continue;
}
}
else {
char * ____BAH_COMPILER_VAR_376 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_376 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_376+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_376+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                pt.cont =  ____BAH_COMPILER_VAR_376;

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  pt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  pt;
}
};
i =  i + 1;
continue;
}
}
}
}
if (inArrayStr(t.cont,ptrOpers)) {
if ((i>0)) {

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1135): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok pt =  nl->data[len(nl)-1];
if ((pt.isValue==true)) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i + 1;
continue;
}
}
i =  i + 1;
if ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1144): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_377 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_377 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_377+currStrOff, t.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_377+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                nt.cont =  ____BAH_COMPILER_VAR_377;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  nt;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  nt;
}
};
i =  i + 1;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
i =  i + 1;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayVars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
long int i =  0;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1170): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1174): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, "[") == 0)) {
found =  true;
break;
}
}
}
i =  i + 1;
};
if ((found==false)) {
return l;
}

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1187): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
i =  0;
for (; (i<len(l)); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1190): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((strcmp(t.cont, "[") == 0)) {
long int ti =  i-1;

                    if (nl->length <= len(nl)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1194): nl[%d] with length %d\n", len(nl)-1, nl->length);
                        exit(1);
                    };
                    struct Tok lt =  nl->data[len(nl)-1];
if (((lt.type!=TOKEN_TYPE_VAR)&&(lt.type!=TOKEN_TYPE_FUNC))) {

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
continue;
}
char * tt =  getTypeFromToken(&lt,true,elems);
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i =  i+1;
long int nbBracks =  1;
for (; (i<len(l)); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1206): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok it =  l->data[i];
if ((strcmp(it.cont, "[") == 0)) {
nbBracks =  nbBracks + 1;
}
else if ((strcmp(it.cont, "]") == 0)) {
nbBracks =  nbBracks - 1;
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
memory->data[len(memory)] =  it;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  it;
}
};
};
if ((len(memory)==0)) {
throwErr(&l->data[i],"Expected index not {TOKEN}.");
}
memory =  prePross(memory,(lineType)-1,elems);
int split =  false;
long int sepPos =  0;
char * cont =  "";
long int j =  0;
for (; (j<len(memory)); j =  j+1) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1227): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok mt =  memory->data[j];
if ((strcmp(mt.cont, ":") == 0)) {
sepPos =  j;
split =  true;
}
char * ____BAH_COMPILER_VAR_378 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_378 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_378+currStrOff, cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_378+currStrOff, mt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                cont =  ____BAH_COMPILER_VAR_378;
};
char * from =  "";
char * to =  "";
if ((split==true)) {
if ((sepPos==0)) {
from =  "0";
}
else {
j =  0;
for (; (j<sepPos); j =  j+1) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1241): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok mt =  memory->data[j];
char * ____BAH_COMPILER_VAR_379 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(from);
long int strLen_1 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_379 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_379+currStrOff, from, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_379+currStrOff, mt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                from =  ____BAH_COMPILER_VAR_379;
};
}
if ((sepPos==len(memory) - 1)) {
char * ____BAH_COMPILER_VAR_380 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("strlen(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_380 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_380+currStrOff, "strlen(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_380+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_380+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                to =  ____BAH_COMPILER_VAR_380;
}
else {
j =  sepPos + 1;
for (; (j<len(memory)); j =  j+1) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1249): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok mt =  memory->data[j];
char * ____BAH_COMPILER_VAR_381 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(to);
long int strLen_1 = strlen(mt.cont);
;                            
                    ____BAH_COMPILER_VAR_381 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_381+currStrOff, to, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_381+currStrOff, mt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                to =  ____BAH_COMPILER_VAR_381;
};
}
}
if ((strcmp(tt, "cpstring") == 0)) {
if ((split==false)) {
char * ____BAH_COMPILER_VAR_382 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("cpstringCharAt(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(",");
long int strLen_3 = strlen(cont);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_382 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_382+currStrOff, "cpstringCharAt(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_382+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_382+currStrOff, ",", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_382+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_382+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                lt.cont =  ____BAH_COMPILER_VAR_382;
lt.isFunc =  true;
lt.bahType =  "char";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  lt;
}
};
}
else {
char * ____BAH_COMPILER_VAR_383 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("cpstringSubsitute(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(to);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_383 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_383+currStrOff, "cpstringSubsitute(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_383+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_383+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_383+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_383+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_383+currStrOff, to, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_383+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                lt.cont =  ____BAH_COMPILER_VAR_383;
lt.isFunc =  true;
lt.bahType =  "cpstring";

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  lt;
}
};
}
continue;
}
if (strHasPrefix(tt,"map:")) {
strTrimLeft(&tt,4);
struct string elemType =  getCType(tt,elems);
if (((ti==0)&&(ltp==LINE_TYPE_VAR))) {
struct variable* ____BAH_COMPILER_VAR_384 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_384->name = "";
____BAH_COMPILER_VAR_384->type = "";
____BAH_COMPILER_VAR_384->isConst = false;
____BAH_COMPILER_VAR_384->constVal = "";
____BAH_COMPILER_VAR_384->isArray = false;
____BAH_COMPILER_VAR_384->from = "";
____BAH_COMPILER_VAR_384->outterScope = false;
____BAH_COMPILER_VAR_384->isGlobal = false;
____BAH_COMPILER_VAR_384->name = genCompilerVar();
____BAH_COMPILER_VAR_384->type = tt;
struct variable* tmpV =  ____BAH_COMPILER_VAR_384;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  tmpV;
}
};
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_385 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_386 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_385);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_386 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_386+currStrOff, ____BAH_COMPILER_VAR_385, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_386+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_386+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_386+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_386));
}
else {
char * ____BAH_COMPILER_VAR_387 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_388 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_387);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_388 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_388+currStrOff, ____BAH_COMPILER_VAR_387, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_388+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_388+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_388+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_388));
}
if (isRCPpointerType(tt)) {
char * ____BAH_COMPILER_VAR_389 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->set(");
long int strLen_2 = strlen(lt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(cont);
long int strLen_5 = strlen(", ");
long int strLen_6 = strlen(tmpV->name);
long int strLen_7 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_389 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                    
                    strncpy(____BAH_COMPILER_VAR_389+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_389+currStrOff, "->set(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_389+currStrOff, lt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_389+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_389+currStrOff, cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_389+currStrOff, ", ", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_389+currStrOff, tmpV->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_389+currStrOff, ");\n", strLen_7);
                    currStrOff += strLen_7;
                    
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_389;
}
else {
char * ____BAH_COMPILER_VAR_390 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->setAny(");
long int strLen_2 = strlen(lt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(cont);
long int strLen_5 = strlen(", &");
long int strLen_6 = strlen(tmpV->name);
long int strLen_7 = strlen(", sizeof(");
long int strLen_8 = strlen(tmpV->name);
long int strLen_9 = strlen("));\n");
;                            
                    ____BAH_COMPILER_VAR_390 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                    
                    strncpy(____BAH_COMPILER_VAR_390+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_390+currStrOff, "->setAny(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_390+currStrOff, lt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_390+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_390+currStrOff, cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_390+currStrOff, ", &", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_390+currStrOff, tmpV->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_390+currStrOff, ", sizeof(", strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_390+currStrOff, tmpV->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_390+currStrOff, "));\n", strLen_9);
                    currStrOff += strLen_9;
                    
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_390;
}
lt.cont =  tmpV->name;
}
else {
if (isRCPpointerType(tt)) {
char * ____BAH_COMPILER_VAR_391 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->get(");
long int strLen_2 = strlen(lt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(cont);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_391 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_391+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_391+currStrOff, "->get(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_391+currStrOff, lt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_391+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_391+currStrOff, cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_391+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                lt.cont =  ____BAH_COMPILER_VAR_391;
}
else {
char * tmpV =  genCompilerVar();
char * ____BAH_COMPILER_VAR_392 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_393 =intToStr(lt.line);char * ____BAH_COMPILER_VAR_394 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_392);
long int strLen_1 = strlen("* ");
long int strLen_2 = strlen(tmpV);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(lt.cont);
long int strLen_5 = strlen("->get(");
long int strLen_6 = strlen(lt.cont);
long int strLen_7 = strlen(", ");
long int strLen_8 = strlen(cont);
long int strLen_9 = strlen(");\n                        if(");
long int strLen_10 = strlen(tmpV);
long int strLen_11 = strlen(" == null) {\n                            printf(\"map (");
long int strLen_12 = strlen(compilerState.currentFile);
long int strLen_13 = strlen(":");
long int strLen_14 = strlen(____BAH_COMPILER_VAR_393);
long int strLen_15 = strlen("): ");
long int strLen_16 = strlen(lt.cont);
long int strLen_17 = strlen("[\\\"%s\\\"] does not exist\\n\", ");
long int strLen_18 = strlen(cont);
long int strLen_19 = strlen(");\n                            exit(1);\n                        };");
;                            
                    ____BAH_COMPILER_VAR_394 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19);
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, ____BAH_COMPILER_VAR_392, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, "* ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, tmpV, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, lt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, "->get(", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, lt.cont, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, ", ", strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, cont, strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, ");\n                        if(", strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, tmpV, strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, " == null) {\n                            printf(\"map (", strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, compilerState.currentFile, strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, ":", strLen_13);
                    currStrOff += strLen_13;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, ____BAH_COMPILER_VAR_393, strLen_14);
                    currStrOff += strLen_14;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, "): ", strLen_15);
                    currStrOff += strLen_15;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, lt.cont, strLen_16);
                    currStrOff += strLen_16;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, "[\\\"%s\\\"] does not exist\\n\", ", strLen_17);
                    currStrOff += strLen_17;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, cont, strLen_18);
                    currStrOff += strLen_18;
                    
                    strncpy(____BAH_COMPILER_VAR_394+currStrOff, ");\n                            exit(1);\n                        };", strLen_19);
                    currStrOff += strLen_19;
                    
                }
                struct rope* res =  rope(____BAH_COMPILER_VAR_394);
char * ____BAH_COMPILER_VAR_395 =elemType.str((struct string*)&elemType);char * ____BAH_COMPILER_VAR_396 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_395);
long int strLen_2 = strlen(")(*");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_396 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_396+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_396+currStrOff, ____BAH_COMPILER_VAR_395, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_396+currStrOff, ")(*", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_396+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_396+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                lt.cont =  ____BAH_COMPILER_VAR_396;
if (isGlobal()) {
INIT =  INIT->add(INIT, res);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, res);
}
}
lt.bahType =  tt;
}

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  lt;
}
};
continue;
}
else if ((strHasPrefix(tt,"[]")==false)) {
char * ____BAH_COMPILER_VAR_397 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as an array.");
;                            
                    ____BAH_COMPILER_VAR_397 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_397+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_397+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_397+currStrOff, ") as an array.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&lt,____BAH_COMPILER_VAR_397);
}
strTrimLeft(&tt,2);
if ((split==false)) {
if (((ti>0)&&(strcmp(ft.cont, "else") != 0))) {
char * ____BAH_COMPILER_VAR_398 =intToStr(lt.line);char * ____BAH_COMPILER_VAR_399 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    if (");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen("->length <= ");
long int strLen_3 = strlen(cont);
long int strLen_4 = strlen(") {\n                        printf(\"array (");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_398);
long int strLen_8 = strlen("): ");
long int strLen_9 = strlen(lt.cont);
long int strLen_10 = strlen("[%d] with length %d\\n\", ");
long int strLen_11 = strlen(cont);
long int strLen_12 = strlen(", ");
long int strLen_13 = strlen(lt.cont);
long int strLen_14 = strlen("->length);\n                        exit(1);\n                    };\n                    ");
;                            
                    ____BAH_COMPILER_VAR_399 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, "\n                    if (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, "->length <= ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, ") {\n                        printf(\"array (", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, ":", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, ____BAH_COMPILER_VAR_398, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, "): ", strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, lt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, "[%d] with length %d\\n\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, cont, strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, ", ", strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, lt.cont, strLen_13);
                    currStrOff += strLen_13;
                    
                    strncpy(____BAH_COMPILER_VAR_399+currStrOff, "->length);\n                        exit(1);\n                    };\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_399));
}
char * ____BAH_COMPILER_VAR_400 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(lt.cont);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(cont);
long int strLen_3 = strlen("]");
;                            
                    ____BAH_COMPILER_VAR_400 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_400+currStrOff, lt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_400+currStrOff, "->data[", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_400+currStrOff, cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_400+currStrOff, "]", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                lt.cont =  ____BAH_COMPILER_VAR_400;
lt.bahType =  tt;
}
else {
char * ____BAH_COMPILER_VAR_401 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("[]");
long int strLen_1 = strlen(tt);
;                            
                    ____BAH_COMPILER_VAR_401 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_401+currStrOff, "[]", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_401+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                lt.bahType =  ____BAH_COMPILER_VAR_401;
char * ____BAH_COMPILER_VAR_402 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("arraySubstitute(");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(from);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(to);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_402 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_402+currStrOff, "arraySubstitute(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_402+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_402+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_402+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_402+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_402+currStrOff, to, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_402+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                lt.cont =  ____BAH_COMPILER_VAR_402;
}

{
long nLength = len(nl)-1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)-1] =  lt;
nl->length = nLength+1;
} else {
nl->data[len(nl)-1] =  lt;
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
};
return nl;
};
char * parseSerialize(struct Tok e,struct Elems* elems){
struct variable* v =  searchVar(e.cont,elems);
if ((v==null)) {
throwErr(&e,"Must be a var, not {TOKEN}.");
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
throwErr(&e,"Must be a struct, not {TOKEN}.");
}
struct string svt =  string(v->type);
long int ptrLevel =  svt.count((struct string*)&svt,"*");
svt.replace((struct string*)&svt,"*","");
char * code= null;
if ((ptrLevel==0)) {
char * ____BAH_COMPILER_VAR_403 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_404 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__serialize(&");
long int strLen_1 = strlen(e.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen("sizeof(struct ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_403);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_404 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_404+currStrOff, "__serialize(&", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_404+currStrOff, e.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_404+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_404+currStrOff, "sizeof(struct ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_404+currStrOff, ____BAH_COMPILER_VAR_403, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_404+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                code =  ____BAH_COMPILER_VAR_404;
}
else {
char * ptrRect =  "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_405 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ptrRect);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_405 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_405+currStrOff, ptrRect, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_405+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ptrRect =  ____BAH_COMPILER_VAR_405;
ptrLevel =  ptrLevel - 1;
};
char * ____BAH_COMPILER_VAR_406 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_407 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__serialize(");
long int strLen_1 = strlen(ptrRect);
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen("sizeof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_406);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_407 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_407+currStrOff, "__serialize(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_407+currStrOff, ptrRect, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_407+currStrOff, e.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_407+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_407+currStrOff, "sizeof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_407+currStrOff, ____BAH_COMPILER_VAR_406, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_407+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                code =  ____BAH_COMPILER_VAR_407;
long int i =  0;
while ((i<len(s->members))) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1376): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_408 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("+strlen(");
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen("->");
long int strLen_4 = strlen(m->name);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_408 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_408+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_408+currStrOff, "+strlen(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_408+currStrOff, e.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_408+currStrOff, "->", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_408+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_408+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                code =  ____BAH_COMPILER_VAR_408;
}
i =  i + 1;
};
}
char * ____BAH_COMPILER_VAR_409 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_409 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_409+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_409+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                return ____BAH_COMPILER_VAR_409;
};
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,int parsedPointer,char * ogName,char * offset){
char * isArr =  "0";
if (((t.type!=TOKEN_TYPE_VAR)||(t.type!=TOKEN_TYPE_FUNC))) {
struct string cType;
if (strHasPrefix(tt,"function(")) {
cType =  string("void*");
}
else {
cType =  getCType(tt,elems);
}
char * v =  genCompilerVar();
if ((parsedPointer==true)) {
cType.append((struct string*)&cType,"*");
}
char * ____BAH_COMPILER_VAR_410 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_411 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_410);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_411 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_411+currStrOff, ____BAH_COMPILER_VAR_410, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_411+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_411+currStrOff, v, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_411+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_411+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_411+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_411));
t.cont =  v;
if ((t.type==TOKEN_TYPE_STR)) {
ogName =  "[bah cpstring]";
}
}
char * arrElem =  "0";
if (strHasPrefix(tt,"[]")) {
isArr =  "1";
struct string aet =  string(tt);
aet.trimLeft((struct string*)&aet,2);
struct Tok ____BAH_COMPILER_VAR_412 = {};
____BAH_COMPILER_VAR_412.cont = "";
____BAH_COMPILER_VAR_412.ogCont = "";
____BAH_COMPILER_VAR_412.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_412.pos = 0;
____BAH_COMPILER_VAR_412.line = 1;
____BAH_COMPILER_VAR_412.begLine = 1;
____BAH_COMPILER_VAR_412.bahType = "";
____BAH_COMPILER_VAR_412.isValue = false;
____BAH_COMPILER_VAR_412.isFunc = false;
____BAH_COMPILER_VAR_412.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_412;
tmpT.type =  TOKEN_TYPE_VAR;
tmpT.cont =  "0";
char * ____BAH_COMPILER_VAR_413 =aet.str((struct string*)&aet);struct Tok rt =  parseReflect(tmpT,____BAH_COMPILER_VAR_413,elems,true,"","0");
char * aev =  genCompilerVar();
char * ____BAH_COMPILER_VAR_414 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_1 = strlen(aev);
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rt.cont);
long int strLen_4 = strlen(";\n        ");
;                            
                    ____BAH_COMPILER_VAR_414 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_414+currStrOff, "\n        struct reflectElement ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_414+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_414+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_414+currStrOff, rt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_414+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_414));
char * ____BAH_COMPILER_VAR_415 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
                    ____BAH_COMPILER_VAR_415 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_415+currStrOff, "&", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_415+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                arrElem =  ____BAH_COMPILER_VAR_415;
}
else if (strHasPrefix(tt,"map:")) {
struct string aet =  string(tt);
aet.trimLeft((struct string*)&aet,4);
struct Tok ____BAH_COMPILER_VAR_416 = {};
____BAH_COMPILER_VAR_416.cont = "";
____BAH_COMPILER_VAR_416.ogCont = "";
____BAH_COMPILER_VAR_416.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_416.pos = 0;
____BAH_COMPILER_VAR_416.line = 1;
____BAH_COMPILER_VAR_416.begLine = 1;
____BAH_COMPILER_VAR_416.bahType = "";
____BAH_COMPILER_VAR_416.isValue = false;
____BAH_COMPILER_VAR_416.isFunc = false;
____BAH_COMPILER_VAR_416.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_416;
tmpT.type =  TOKEN_TYPE_VAR;
tmpT.cont =  "0";
char * ____BAH_COMPILER_VAR_417 =aet.str((struct string*)&aet);struct Tok rt =  parseReflect(tmpT,____BAH_COMPILER_VAR_417,elems,true,"","0");
char * aev =  genCompilerVar();
char * ____BAH_COMPILER_VAR_418 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_1 = strlen(aev);
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rt.cont);
long int strLen_4 = strlen(";\n        ");
;                            
                    ____BAH_COMPILER_VAR_418 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_418+currStrOff, "\n        struct reflectElement ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_418+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_418+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_418+currStrOff, rt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_418+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_418));
char * ____BAH_COMPILER_VAR_419 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
                    ____BAH_COMPILER_VAR_419 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_419+currStrOff, "&", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_419+currStrOff, aev, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                arrElem =  ____BAH_COMPILER_VAR_419;
}
char * isStruct =  "0";
struct cStruct* ts =  searchStruct(tt,elems);
char * structLayout =  "0";
if ((ts!=null)) {
isStruct =  "1";
structLayout =  genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_420 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_420->name = "";
____BAH_COMPILER_VAR_420->type = "";
____BAH_COMPILER_VAR_420->isConst = false;
____BAH_COMPILER_VAR_420->constVal = "";
____BAH_COMPILER_VAR_420->isArray = false;
____BAH_COMPILER_VAR_420->from = "";
____BAH_COMPILER_VAR_420->outterScope = false;
____BAH_COMPILER_VAR_420->isGlobal = false;
struct variable* slv =  ____BAH_COMPILER_VAR_420;
slv->name =  structLayout;
slv->type =  "[]reflectElement";

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  slv;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  slv;
}
};
struct rope* dataLayout =  rope("");
long int i =  0;
for (; (i<len(ts->members)); i =  i+1) {

                    if (ts->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1459): ts->members[%d] with length %d\n", i, ts->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_421 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_421->name = "";
____BAH_COMPILER_VAR_421->type = "";
____BAH_COMPILER_VAR_421->isConst = false;
____BAH_COMPILER_VAR_421->constVal = "";
____BAH_COMPILER_VAR_421->isArray = false;
____BAH_COMPILER_VAR_421->from = "";
____BAH_COMPILER_VAR_421->outterScope = false;
____BAH_COMPILER_VAR_421->isGlobal = false;
____BAH_COMPILER_VAR_421->def = "";
____BAH_COMPILER_VAR_421->isFn = false;
struct structMemb* nm =  ____BAH_COMPILER_VAR_421;
*nm =  *m;
m =  nm;
m->type =  "ptr";
}
struct Tok ____BAH_COMPILER_VAR_422 = {};
____BAH_COMPILER_VAR_422.cont = "";
____BAH_COMPILER_VAR_422.ogCont = "";
____BAH_COMPILER_VAR_422.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_422.pos = 0;
____BAH_COMPILER_VAR_422.line = 1;
____BAH_COMPILER_VAR_422.begLine = 1;
____BAH_COMPILER_VAR_422.bahType = "";
____BAH_COMPILER_VAR_422.isValue = false;
____BAH_COMPILER_VAR_422.isFunc = false;
____BAH_COMPILER_VAR_422.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_422;
tmpT.type =  TOKEN_TYPE_VAR;
char * sep =  "->";
if ((strCount(tt,"*")==0)) {
sep =  ".";
}
struct string mCtype =  getCType(m->type,elems);
struct string offsetTT =  string(tt);
offsetTT.replace((struct string*)&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_423 =mCtype.str((struct string*)&mCtype);char * ____BAH_COMPILER_VAR_424 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_425 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_423);
long int strLen_2 = strlen("*)((char*)(");
long int strLen_3 = strlen(t.cont);
long int strLen_4 = strlen(") + offsetof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_424);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_425 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    strncpy(____BAH_COMPILER_VAR_425+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_425+currStrOff, ____BAH_COMPILER_VAR_423, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_425+currStrOff, "*)((char*)(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_425+currStrOff, t.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_425+currStrOff, ") + offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_425+currStrOff, ____BAH_COMPILER_VAR_424, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_425+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_425+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_425+currStrOff, "))", strLen_8);
                    currStrOff += strLen_8;
                    
                }
                tmpT.cont =  ____BAH_COMPILER_VAR_425;
char * ____BAH_COMPILER_VAR_426 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_427 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("offsetof(struct ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_426);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_427 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_427+currStrOff, "offsetof(struct ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_427+currStrOff, ____BAH_COMPILER_VAR_426, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_427+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_427+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_427+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                struct Tok rt =  parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_427);
char * ____BAH_COMPILER_VAR_428 =intToStr(i);char * ____BAH_COMPILER_VAR_429 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(structLayout);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_428);
long int strLen_3 = strlen("] = ");
long int strLen_4 = strlen(rt.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_429 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_429+currStrOff, structLayout, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_429+currStrOff, "->data[", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_429+currStrOff, ____BAH_COMPILER_VAR_428, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_429+currStrOff, "] = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_429+currStrOff, rt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_429+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                dataLayout =  dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_429));
};
char * ____BAH_COMPILER_VAR_430 =intToStr(len(ts->members));char * ____BAH_COMPILER_VAR_431 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n        array(struct reflectElement) * ");
long int strLen_1 = strlen(structLayout);
long int strLen_2 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_5 = strlen(structLayout);
long int strLen_6 = strlen("->length = ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_430);
long int strLen_8 = strlen(";\n        ");
long int strLen_9 = strlen(structLayout);
long int strLen_10 = strlen("->data = memoryAlloc(");
long int strLen_11 = strlen(structLayout);
long int strLen_12 = strlen("->length * ");
long int strLen_13 = strlen(structLayout);
long int strLen_14 = strlen("->elemSize);\n        ");
;                            
                    ____BAH_COMPILER_VAR_431 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, "\n        array(struct reflectElement) * ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, structLayout, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, "->length = ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, ____BAH_COMPILER_VAR_430, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, ";\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, structLayout, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, "->data = memoryAlloc(", strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, structLayout, strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, "->length * ", strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, structLayout, strLen_13);
                    currStrOff += strLen_13;
                    
                    strncpy(____BAH_COMPILER_VAR_431+currStrOff, "->elemSize);\n        ", strLen_14);
                    currStrOff += strLen_14;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_431))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_431)), dataLayout);
}
char * amp =  "";
if (((((strCount(tt,"*")==0)&&(strcmp(tt, "cpstring") != 0))&&(strcmp(tt, "ptr") != 0))&&(parsedPointer==false))) {
amp =  "&";
}
struct string name =  string(ogName);
if ((hasStructSep(name)==true)) {
name =  splitStructSepAfter(name);
}
struct string cType;
if (strHasPrefix(tt,"function(")) {
cType =  string("void*");
}
else {
cType =  getCType(tt,elems);
}
if (cType.hasPrefix((struct string*)&cType,"struct ")) {
cType.replace((struct string*)&cType,"*","");
}
if ((cType.length==0)) {
cType.set((struct string*)&cType,"0");
}
struct variable* ____BAH_COMPILER_VAR_432 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_432->name = "";
____BAH_COMPILER_VAR_432->type = "";
____BAH_COMPILER_VAR_432->isConst = false;
____BAH_COMPILER_VAR_432->constVal = "";
____BAH_COMPILER_VAR_432->isArray = false;
____BAH_COMPILER_VAR_432->from = "";
____BAH_COMPILER_VAR_432->outterScope = false;
____BAH_COMPILER_VAR_432->isGlobal = false;
struct variable* rv =  ____BAH_COMPILER_VAR_432;
rv->name =  genCompilerVar();
rv->type =  "reflectElement";

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  rv;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  rv;
}
};
char * ____BAH_COMPILER_VAR_433 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_434 =name.str((struct string*)&name);char * ____BAH_COMPILER_VAR_435 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct reflectElement ");
long int strLen_1 = strlen(rv->name);
long int strLen_2 = strlen(" = __reflect(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(", sizeof(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_433);
long int strLen_7 = strlen("), \"");
long int strLen_8 = strlen(tt);
long int strLen_9 = strlen("\", \"");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_434);
long int strLen_11 = strlen("\", ");
long int strLen_12 = strlen(isArr);
long int strLen_13 = strlen(", ");
long int strLen_14 = strlen(arrElem);
long int strLen_15 = strlen(", ");
long int strLen_16 = strlen(isStruct);
long int strLen_17 = strlen(", ");
long int strLen_18 = strlen(structLayout);
long int strLen_19 = strlen(", ");
long int strLen_20 = strlen(offset);
long int strLen_21 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_435 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20 + strLen_21);
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, "struct reflectElement ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, rv->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, " = __reflect(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, amp, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, ", sizeof(", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, ____BAH_COMPILER_VAR_433, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, "), \"", strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, tt, strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, "\", \"", strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, ____BAH_COMPILER_VAR_434, strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, "\", ", strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, isArr, strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, ", ", strLen_13);
                    currStrOff += strLen_13;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, arrElem, strLen_14);
                    currStrOff += strLen_14;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, ", ", strLen_15);
                    currStrOff += strLen_15;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, isStruct, strLen_16);
                    currStrOff += strLen_16;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, ", ", strLen_17);
                    currStrOff += strLen_17;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, structLayout, strLen_18);
                    currStrOff += strLen_18;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, ", ", strLen_19);
                    currStrOff += strLen_19;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, offset, strLen_20);
                    currStrOff += strLen_20;
                    
                    strncpy(____BAH_COMPILER_VAR_435+currStrOff, ");\n", strLen_21);
                    currStrOff += strLen_21;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_435));
t.cont =  rv->name;
return t;
};
__BAH_ARR_TYPE_Tok parseFnCall(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
long int i =  0;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1534): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i+1;
if ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1538): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, "(") == 0)) {
found =  true;
break;
}
}
}
i =  i+1;
};
if ((found==false)) {
return l;
}
i =  0;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1553): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok ot =  l->data[i];
if ((ot.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1558): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
if ((strcmp(nt.cont, "(") == 0)) {
long int nbPar =  1;
i =  i + 1;
char * fnName =  ot.cont;
struct func* fn =  searchFunc(fnName,elems,true);
if ((fn==null)) {
throwErr(&ot,"Unknown function {TOKEN}.");
}
struct string varName =  string("");
struct string fnStr =  string(fnName);
struct variable* arg1= null;
if (hasStructSep(fnStr)) {

                    if (fn->args->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1571): fn->args[%d] with length %d\n", 0, fn->args->length);
                        exit(1);
                    };
                    arg1 =  fn->args->data[0];
struct string fnarg1t =  getCType(arg1->type,elems);
varName =  fnStr;
struct string realFn =  splitStructSepAfter(fnStr);
varName.trimRight((struct string*)&varName,realFn.length);
char c =  varName.charAt((struct string*)&varName,varName.length - 1);
if ((c==46)) {
varName.trimRight((struct string*)&varName,1);
}
else {
varName.trimRight((struct string*)&varName,2);
}
char * varNameStr =  varName.str((struct string*)&varName);
struct variable* v =  searchVar(varNameStr,elems);
if ((v==null)) {
throwErr(&ot,"Cannot use {TOKEN} as a struct.");
}
if ((strCount(v->type,"*")==0)) {
varName.prepend((struct string*)&varName,"&");
}
char * ____BAH_COMPILER_VAR_436 =fnarg1t.str((struct string*)&fnarg1t);char * ____BAH_COMPILER_VAR_437 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_436);
long int strLen_2 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_437 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_437+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_437+currStrOff, ____BAH_COMPILER_VAR_436, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_437+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                varName.prepend((struct string*)&varName,____BAH_COMPILER_VAR_437);
}
char * ____BAH_COMPILER_VAR_438 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_438 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_438+currStrOff, fnName, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_438+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ot.cont =  ____BAH_COMPILER_VAR_438;
long int paramIndex =  0;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
if ((varName.length>0)) {
struct Tok ____BAH_COMPILER_VAR_439 = {};
____BAH_COMPILER_VAR_439.cont = "";
____BAH_COMPILER_VAR_439.ogCont = "";
____BAH_COMPILER_VAR_439.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_439.pos = 0;
____BAH_COMPILER_VAR_439.line = 1;
____BAH_COMPILER_VAR_439.begLine = 1;
____BAH_COMPILER_VAR_439.bahType = "";
____BAH_COMPILER_VAR_439.isValue = false;
____BAH_COMPILER_VAR_439.isFunc = false;
____BAH_COMPILER_VAR_439.isOper = false;
struct Tok tk =  ____BAH_COMPILER_VAR_439;
tk.cont =  varName.str((struct string*)&varName);
tk.bahType =  arg1->type;
tk.type =  TOKEN_TYPE_VAR;
tk.isValue =  true;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  tk;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  tk;
}
};

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1604): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    nt =  l->data[i];
if ((strcmp(nt.cont, ")") != 0)) {
struct Tok ____BAH_COMPILER_VAR_440 = {};
____BAH_COMPILER_VAR_440.cont = "";
____BAH_COMPILER_VAR_440.ogCont = "";
____BAH_COMPILER_VAR_440.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_440.pos = 0;
____BAH_COMPILER_VAR_440.line = 1;
____BAH_COMPILER_VAR_440.begLine = 1;
____BAH_COMPILER_VAR_440.bahType = "";
____BAH_COMPILER_VAR_440.isValue = false;
____BAH_COMPILER_VAR_440.isFunc = false;
____BAH_COMPILER_VAR_440.isOper = false;
tk =  ____BAH_COMPILER_VAR_440;
tk.cont =  ",";
tk.type =  TOKEN_TYPE_SYNTAX;
tk.isValue =  false;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  tk;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  tk;
}
};
}
}
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1614): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((strcmp(t.cont, "(") == 0)) {
nbPar =  nbPar + 1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPar =  nbPar - 1;
}

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  t;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  t;
}
};
if ((nbPar==0)) {
i =  i + 1;
break;
}
i =  i + 1;
};
if ((strcmp(fnName, "noCheck") == 0)) {
ot.cont =  "";
long int j =  0;
while ((j<len(memory)-1)) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1631): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok t =  memory->data[j];
char * ____BAH_COMPILER_VAR_441 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_441 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_441+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_441+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ot.cont =  ____BAH_COMPILER_VAR_441;
j =  j + 1;
};
ot.cont =  ot.cont;
ot.type =  TOKEN_TYPE_FUNC;
ot.isFunc =  true;
ot.bahType =  "ptr";

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
}
};
continue;
}
if ((strcmp(fnName, "panic") == 0)) {
char * ____BAH_COMPILER_VAR_442 =intToStr(ot.line);char * ____BAH_COMPILER_VAR_443 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_442);
long int strLen_4 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_443 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_443+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_443+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_443+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_443+currStrOff, ____BAH_COMPILER_VAR_442, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_443+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                char * currLine =  ____BAH_COMPILER_VAR_443;

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1645): memory[%d] with length %d\n", len(memory)-1, memory->length);
                        exit(1);
                    };
                    struct Tok par =  memory->data[len(memory)-1];
long int cl =  par.line;
struct Tok ____BAH_COMPILER_VAR_444 = {};
____BAH_COMPILER_VAR_444.cont = "";
____BAH_COMPILER_VAR_444.ogCont = "";
____BAH_COMPILER_VAR_444.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_444.pos = 0;
____BAH_COMPILER_VAR_444.line = 1;
____BAH_COMPILER_VAR_444.begLine = 1;
____BAH_COMPILER_VAR_444.bahType = "";
____BAH_COMPILER_VAR_444.isValue = false;
____BAH_COMPILER_VAR_444.isFunc = false;
____BAH_COMPILER_VAR_444.isOper = false;
____BAH_COMPILER_VAR_444.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_444.cont = ",";
____BAH_COMPILER_VAR_444.line = cl;

{
long nLength = len(memory)-1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)-1] =  ____BAH_COMPILER_VAR_444;
memory->length = nLength+1;
} else {
memory->data[len(memory)-1] =  ____BAH_COMPILER_VAR_444;
}
};
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
____BAH_COMPILER_VAR_445.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_445.cont = currLine;
____BAH_COMPILER_VAR_445.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_445;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_445;
}
};

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  par;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  par;
}
};
fnName =  "__BAH_panic";
char * ____BAH_COMPILER_VAR_446 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_446 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_446+currStrOff, fnName, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_446+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ot.cont =  ____BAH_COMPILER_VAR_446;
fn =  searchFunc(fnName,elems,true);
}
else if ((strcmp(fnName, "__dumpSymbols") == 0)) {
char * ____BAH_COMPILER_VAR_447 =intToStr(ot.line);char * ____BAH_COMPILER_VAR_448 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_447);
long int strLen_4 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_448 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_448+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_448+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_448+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_448+currStrOff, ____BAH_COMPILER_VAR_447, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_448+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                char * currLine =  ____BAH_COMPILER_VAR_448;

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1663): memory[%d] with length %d\n", len(memory)-1, memory->length);
                        exit(1);
                    };
                    struct Tok par =  memory->data[len(memory)-1];
long int cl =  par.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);
long int j =  0;
for (; (j<len(elems->vars)); j =  j+1) {

                    if (elems->vars->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1669): elems->vars[%d] with length %d\n", j, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[j];
if ((v->isConst==false)) {

{
long nLength = len(symbols);
if (symbols->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(symbols->data, (nLength+50)*sizeof(struct variable*));
symbols->data = newPtr;
}
symbols->data[len(symbols)] =  v;
symbols->length = nLength+1;
} else {
symbols->data[len(symbols)] =  v;
}
};
}
};
struct variable* ____BAH_COMPILER_VAR_449 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_449->name = "";
____BAH_COMPILER_VAR_449->type = "";
____BAH_COMPILER_VAR_449->isConst = false;
____BAH_COMPILER_VAR_449->constVal = "";
____BAH_COMPILER_VAR_449->isArray = false;
____BAH_COMPILER_VAR_449->from = "";
____BAH_COMPILER_VAR_449->outterScope = false;
____BAH_COMPILER_VAR_449->isGlobal = false;
____BAH_COMPILER_VAR_449->name = genCompilerVar();
____BAH_COMPILER_VAR_449->type = "[]reflectElement";
____BAH_COMPILER_VAR_449->isArray = true;
struct variable* tmpV =  ____BAH_COMPILER_VAR_449;

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  tmpV;
}
};
char * decls =  "";
j =  0;
for (; (j<len(symbols)); j =  j+1) {

                    if (symbols->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1684): symbols[%d] with length %d\n", j, symbols->length);
                        exit(1);
                    };
                    struct variable* v =  symbols->data[j];
char * vname =  v->name;
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_450 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("&");
long int strLen_1 = strlen(v->name);
;                            
                    ____BAH_COMPILER_VAR_450 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_450+currStrOff, "&", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_450+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                vname =  ____BAH_COMPILER_VAR_450;
}
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
____BAH_COMPILER_VAR_451.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_451.cont = vname;
____BAH_COMPILER_VAR_451.bahType = v->type;
____BAH_COMPILER_VAR_451.isValue = true;
struct Tok tmpT =  ____BAH_COMPILER_VAR_451;
tmpT =  parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_452 =intToStr(j);char * ____BAH_COMPILER_VAR_453 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpV->name);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_452);
long int strLen_3 = strlen("] = ");
long int strLen_4 = strlen(tmpT.cont);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_453+currStrOff, tmpV->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_453+currStrOff, "->data[", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_453+currStrOff, ____BAH_COMPILER_VAR_452, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_453+currStrOff, "] = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_453+currStrOff, tmpT.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_453+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                char * ____BAH_COMPILER_VAR_454 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(decls);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_453);
;                            
                    ____BAH_COMPILER_VAR_454 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_454+currStrOff, decls, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_454+currStrOff, ____BAH_COMPILER_VAR_453, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                decls =  ____BAH_COMPILER_VAR_454;
};
char * ____BAH_COMPILER_VAR_455 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_456 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_457 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                        array(struct reflectElement)* ");
long int strLen_1 = strlen(tmpV->name);
long int strLen_2 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n                        ");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_455);
long int strLen_6 = strlen(");\n                        ");
long int strLen_7 = strlen(tmpV->name);
long int strLen_8 = strlen("->length = ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_456);
long int strLen_10 = strlen(";\n                        ");
long int strLen_11 = strlen(tmpV->name);
long int strLen_12 = strlen("->elemSize = sizeof(struct reflectElement);\n                        ");
long int strLen_13 = strlen(decls);
long int strLen_14 = strlen("\n                        ");
;                            
                    ____BAH_COMPILER_VAR_457 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, "\n                        array(struct reflectElement)* ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, tmpV->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n                        ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, ____BAH_COMPILER_VAR_455, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, ");\n                        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, tmpV->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, "->length = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, ____BAH_COMPILER_VAR_456, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, ";\n                        ", strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, tmpV->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, "->elemSize = sizeof(struct reflectElement);\n                        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, decls, strLen_13);
                    currStrOff += strLen_13;
                    
                    strncpy(____BAH_COMPILER_VAR_457+currStrOff, "\n                        ", strLen_14);
                    currStrOff += strLen_14;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_457));
struct Tok ____BAH_COMPILER_VAR_458 = {};
____BAH_COMPILER_VAR_458.cont = "";
____BAH_COMPILER_VAR_458.ogCont = "";
____BAH_COMPILER_VAR_458.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_458.pos = 0;
____BAH_COMPILER_VAR_458.line = 1;
____BAH_COMPILER_VAR_458.begLine = 1;
____BAH_COMPILER_VAR_458.bahType = "";
____BAH_COMPILER_VAR_458.isValue = false;
____BAH_COMPILER_VAR_458.isFunc = false;
____BAH_COMPILER_VAR_458.isOper = false;
____BAH_COMPILER_VAR_458.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_458.cont = tmpV->name;
____BAH_COMPILER_VAR_458.line = cl;
____BAH_COMPILER_VAR_458.isValue = true;

{
long nLength = 0;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[0] =  ____BAH_COMPILER_VAR_458;
memory->length = nLength+1;
} else {
memory->data[0] =  ____BAH_COMPILER_VAR_458;
}
};

{
long nLength = 1;
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[1] =  par;
memory->length = nLength+1;
} else {
memory->data[1] =  par;
}
};
}
else if ((strcmp(fnName, "breakPoint") == 0)) {
char * ____BAH_COMPILER_VAR_459 =intToStr(ot.line);char * ____BAH_COMPILER_VAR_460 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_459);
long int strLen_4 = strlen("\"");
;                            
                    ____BAH_COMPILER_VAR_460 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_460+currStrOff, "\"", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_460+currStrOff, compilerState.currentFile, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_460+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_460+currStrOff, ____BAH_COMPILER_VAR_459, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_460+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                char * currLine =  ____BAH_COMPILER_VAR_460;

                    if (memory->length <= len(memory)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1718): memory[%d] with length %d\n", len(memory)-1, memory->length);
                        exit(1);
                    };
                    struct Tok par =  memory->data[len(memory)-1];
long int cl =  par.line;
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
____BAH_COMPILER_VAR_461.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_461.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_461.line = cl;
struct Tok ____BAH_COMPILER_VAR_462 = {};
____BAH_COMPILER_VAR_462.cont = "";
____BAH_COMPILER_VAR_462.ogCont = "";
____BAH_COMPILER_VAR_462.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_462.pos = 0;
____BAH_COMPILER_VAR_462.line = 1;
____BAH_COMPILER_VAR_462.begLine = 1;
____BAH_COMPILER_VAR_462.bahType = "";
____BAH_COMPILER_VAR_462.isValue = false;
____BAH_COMPILER_VAR_462.isFunc = false;
____BAH_COMPILER_VAR_462.isOper = false;
____BAH_COMPILER_VAR_462.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_462.cont = "(";
____BAH_COMPILER_VAR_462.line = cl;
struct Tok ____BAH_COMPILER_VAR_463 = {};
____BAH_COMPILER_VAR_463.cont = "";
____BAH_COMPILER_VAR_463.ogCont = "";
____BAH_COMPILER_VAR_463.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_463.pos = 0;
____BAH_COMPILER_VAR_463.line = 1;
____BAH_COMPILER_VAR_463.begLine = 1;
____BAH_COMPILER_VAR_463.bahType = "";
____BAH_COMPILER_VAR_463.isValue = false;
____BAH_COMPILER_VAR_463.isFunc = false;
____BAH_COMPILER_VAR_463.isOper = false;
____BAH_COMPILER_VAR_463.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_463.cont = ")";
____BAH_COMPILER_VAR_463.line = cl;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);memory->data[0] = ____BAH_COMPILER_VAR_461;
memory->data[1] = ____BAH_COMPILER_VAR_462;
memory->data[2] = ____BAH_COMPILER_VAR_463;
memory =  parseFnCall(memory,(lineType)-1,elems);
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
____BAH_COMPILER_VAR_464.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_464.cont = ",";
____BAH_COMPILER_VAR_464.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_464;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_464;
}
};
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
____BAH_COMPILER_VAR_465.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_465.cont = currLine;
____BAH_COMPILER_VAR_465.line = cl;

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_465;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  ____BAH_COMPILER_VAR_465;
}
};

{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  par;
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  par;
}
};
fnName =  "breakPoint__inner";
char * ____BAH_COMPILER_VAR_466 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_466 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_466+currStrOff, fnName, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_466+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ot.cont =  ____BAH_COMPILER_VAR_466;
fn =  searchFunc(fnName,elems,true);
}
else if ((strcmp(fnName, "sizeof") == 0)) {
char * tp =  "";
long int j =  0;
for (; (j<len(memory)-1); j =  j+1) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1759): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok t =  memory->data[j];
char * ____BAH_COMPILER_VAR_467 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_467 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_467+currStrOff, tp, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_467+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tp =  ____BAH_COMPILER_VAR_467;
};
struct string cType =  getCType(tp,elems);
char * ____BAH_COMPILER_VAR_468 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_469 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_468);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_469 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_469+currStrOff, ____BAH_COMPILER_VAR_468, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_469+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * ____BAH_COMPILER_VAR_470 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_469);
;                            
                    ____BAH_COMPILER_VAR_470 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_470+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_470+currStrOff, ____BAH_COMPILER_VAR_469, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ot.cont =  ____BAH_COMPILER_VAR_470;
ot.type =  TOKEN_TYPE_FUNC;
ot.isFunc =  true;
ot.bahType =  "int";

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
}
};
continue;
}
memory =  prePross(memory,ltp,elems);

                    if (memory->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1784): memory[%d] with length %d\n", 0, memory->length);
                        exit(1);
                    };
                    struct Tok ft =  memory->data[0];
array(struct Tok)* fnArgs = memoryAlloc(sizeof(array(struct Tok)));

fnArgs->length = 0;
fnArgs->elemSize = sizeof(struct Tok);
if ((strcmp(ft.cont, ")") != 0)) {
long int j =  0;
while ((j<len(memory))) {

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1791): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    struct Tok t =  memory->data[j];
if ((paramIndex>=len(fn->args))) {
throwErr(&t,"Too many arguments in function call.");
}

                    if (fn->args->length <= paramIndex) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1796): fn->args[%d] with length %d\n", paramIndex, fn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  fn->args->data[paramIndex];
char * tt =  getTypeFromToken(&t,true,elems);
if (((strcmp(arg->type, "reflectElement") == 0)&&(strcmp(tt, "reflectElement") != 0))) {
t =  parseReflect(t,tt,elems,false,t.cont,"0");
tt =  "reflectElement";
}
if ((compTypes(tt,arg->type)==false)) {
char * ____BAH_COMPILER_VAR_471 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(arg->type);
long int strLen_4 = strlen(" in function call.");
;                            
                    ____BAH_COMPILER_VAR_471 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_471+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_471+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_471+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_471+currStrOff, arg->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_471+currStrOff, " in function call.", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&t,____BAH_COMPILER_VAR_471);
}
if (((t.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(t.cont,"noCheck(")==false))) {
struct string ____BAH_COMPILER_VAR_472 =string(t.cont);char * afnName =  splitStringBefore(____BAH_COMPILER_VAR_472,"(");
struct func* afn =  searchFunc(afnName,elems,true);
if (((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true))) {
t.cont =  registerRCPvar(afn->returns->type,t.cont,elems);
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
fnArgs->data[len(fnArgs)] =  t;
fnArgs->length = nLength+1;
} else {
fnArgs->data[len(fnArgs)] =  t;
}
};
}
char * ____BAH_COMPILER_VAR_473 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_473 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_473+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_473+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ot.cont =  ____BAH_COMPILER_VAR_473;
j =  j + 1;

                    if (memory->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1822): memory[%d] with length %d\n", j, memory->length);
                        exit(1);
                    };
                    t =  memory->data[j];
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, ")") == 0)) {
j =  j + 1;
paramIndex =  paramIndex + 1;
break;
}
else {
throwErr(&t,"Expected separator between values, not {TOKEN} in function call.");
}
}
else {
paramIndex =  paramIndex + 1;
char * ____BAH_COMPILER_VAR_474 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_474 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_474+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_474+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ot.cont =  ____BAH_COMPILER_VAR_474;
}
j =  j + 1;
};
}
if ((paramIndex<len(fn->args))) {
ot.cont =  fnName;
throwErr(&ot,"Not enough arguments in function call, ending by {TOKEN}.");
}
if ((strcmp(fn->name, "ser") == 0)) {
ot.cont =  parseSerialize(memory->data[0],elems);
}
else {
char * ____BAH_COMPILER_VAR_475 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_475 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_475+currStrOff, ot.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_475+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                ot.cont =  ____BAH_COMPILER_VAR_475;
}
ot.type =  TOKEN_TYPE_FUNC;
ot.bahType =  fn->returns->type;
ot.isFunc =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
}
};

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1858): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    ft =  l->data[0];
if (((verboseRuntime==true)&&(ltp!=LINE_TYPE_ELSE))) {
verboseOutFunc(fn,fnArgs,ft.line,elems);
}
continue;
}
}
i =  i-1;
}

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  ot;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  ot;
}
};
i =  i+1;
};
return nl;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength =  0;
struct string arrType =  getCType(v->type,elems);
arrType.trimRight((struct string*)&arrType,1);
char * ____BAH_COMPILER_VAR_476 =arrType.str((struct string*)&arrType);char * ____BAH_COMPILER_VAR_477 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("memoryAlloc(sizeof(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_476);
long int strLen_2 = strlen("))");
;                            
                    ____BAH_COMPILER_VAR_477 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_477+currStrOff, "memoryAlloc(sizeof(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_477+currStrOff, ____BAH_COMPILER_VAR_476, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_477+currStrOff, "))", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                char * code =  ____BAH_COMPILER_VAR_477;
arrType.trimLeft((struct string*)&arrType,6);
arrType.trimRight((struct string*)&arrType,1);
char * elemTypeStr =  arrType.str((struct string*)&arrType);
if ((i + 1!=max)) {
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1888): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
if ((strcmp(nt.cont, "{") != 0)) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after array initialization.");
}
struct string elemBahType =  string(v->type);
elemBahType.trimLeft((struct string*)&elemBahType,2);
char * elemBahTypeStr =  elemBahType.str((struct string*)&elemBahType);
i =  i + 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
while ((i<max)) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1898): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    
{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  l->data[i];
}
};
i =  i + 1;
};
memory =  prePross(memory,(lineType)-1,elems);
i =  0;
while ((i<len(memory))) {

                    if (memory->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1903): memory[%d] with length %d\n", i, memory->length);
                        exit(1);
                    };
                    struct Tok t =  memory->data[i];
if ((strcmp(t.cont, "{") == 0)) {
long int j =  i-1;
long int nbBraces =  0;
for (; (i<len(memory)); i =  i+1) {

                    if (memory->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1909): memory[%d] with length %d\n", i, memory->length);
                        exit(1);
                    };
                    struct Tok tmpT =  memory->data[i];
if ((strcmp(tmpT.cont, "{") == 0)) {
nbBraces =  nbBraces+1;
}
else if ((strcmp(tmpT.cont, "}") == 0)) {
nbBraces =  nbBraces-1;
}
if ((nbBraces==0)) {
break;
}
};
struct variable* ____BAH_COMPILER_VAR_478 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_478->name = "";
____BAH_COMPILER_VAR_478->type = "";
____BAH_COMPILER_VAR_478->isConst = false;
____BAH_COMPILER_VAR_478->constVal = "";
____BAH_COMPILER_VAR_478->isArray = false;
____BAH_COMPILER_VAR_478->from = "";
____BAH_COMPILER_VAR_478->outterScope = false;
____BAH_COMPILER_VAR_478->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_478;
tmpV->name =  genCompilerVar();
struct string elemType =  string(v->type);
elemType.trimLeft((struct string*)&elemType,2);
tmpV->type =  elemType.str((struct string*)&elemType);

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  tmpV;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  tmpV;
}
};
char * oldNL =  NEXT_LINE;
NEXT_LINE =  "";
char * innerCode =  parseArrayDecl(tmpV,memory,j,i + 1,elems);
char * ____BAH_COMPILER_VAR_479 =elemType.str((struct string*)&elemType);struct string cType =  getCType(____BAH_COMPILER_VAR_479,elems);
char * ____BAH_COMPILER_VAR_480 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_481 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                array(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_480);
long int strLen_2 = strlen(") * ");
long int strLen_3 = strlen(tmpV->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(innerCode);
long int strLen_6 = strlen(";\n                ");
long int strLen_7 = strlen(NEXT_LINE);
long int strLen_8 = strlen("\n                ");
;                            
                    ____BAH_COMPILER_VAR_481 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    strncpy(____BAH_COMPILER_VAR_481+currStrOff, "\n                array(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_481+currStrOff, ____BAH_COMPILER_VAR_480, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_481+currStrOff, ") * ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_481+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_481+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_481+currStrOff, innerCode, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_481+currStrOff, ";\n                ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_481+currStrOff, NEXT_LINE, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_481+currStrOff, "\n                ", strLen_8);
                    currStrOff += strLen_8;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_481));
NEXT_LINE =  oldNL;
struct Tok ____BAH_COMPILER_VAR_482 = {};
____BAH_COMPILER_VAR_482.cont = "";
____BAH_COMPILER_VAR_482.ogCont = "";
____BAH_COMPILER_VAR_482.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_482.pos = 0;
____BAH_COMPILER_VAR_482.line = 1;
____BAH_COMPILER_VAR_482.begLine = 1;
____BAH_COMPILER_VAR_482.bahType = "";
____BAH_COMPILER_VAR_482.isValue = false;
____BAH_COMPILER_VAR_482.isFunc = false;
____BAH_COMPILER_VAR_482.isOper = false;
____BAH_COMPILER_VAR_482.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_482.cont = tmpV->name;
____BAH_COMPILER_VAR_482.bahType = elemType.str((struct string*)&elemType);
____BAH_COMPILER_VAR_482.isValue = true;
t =  ____BAH_COMPILER_VAR_482;
}
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_483 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(elemBahTypeStr);
;                            
                    ____BAH_COMPILER_VAR_483 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_483+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_483+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_483+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_483+currStrOff, elemBahTypeStr, strLen_3);
                    currStrOff += strLen_3;
                    
                }
                throwErr(&t,____BAH_COMPILER_VAR_483);
}
char * strArrayLength =  intToStr(arrayLength);
arrayLength =  arrayLength + 1;
char * ____BAH_COMPILER_VAR_484 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(NEXT_LINE);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen("->data[");
long int strLen_3 = strlen(strArrayLength);
long int strLen_4 = strlen("] = ");
long int strLen_5 = strlen(t.cont);
long int strLen_6 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_484 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_484+currStrOff, NEXT_LINE, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_484+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_484+currStrOff, "->data[", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_484+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_484+currStrOff, "] = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_484+currStrOff, t.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_484+currStrOff, ";\n", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_484;
i =  i+1;

                    if (memory->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1954): memory[%d] with length %d\n", i, memory->length);
                        exit(1);
                    };
                    t =  memory->data[i];
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, "}") == 0)) {
long int allocLength =  arrayLength;
if ((allocLength>50)) {
long int modAllocAmm =  allocLength % 50;
allocLength =  allocLength + modAllocAmm;
}
else {
allocLength =  50;
}
char * allocLengthStr =  intToStr(allocLength);
char * ____BAH_COMPILER_VAR_485 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("->data = memoryAlloc(sizeof(");
long int strLen_2 = strlen(elemTypeStr);
long int strLen_3 = strlen(") * ");
long int strLen_4 = strlen(allocLengthStr);
long int strLen_5 = strlen(");");
long int strLen_6 = strlen(NEXT_LINE);
;                            
                    ____BAH_COMPILER_VAR_485 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_485+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_485+currStrOff, "->data = memoryAlloc(sizeof(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_485+currStrOff, elemTypeStr, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_485+currStrOff, ") * ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_485+currStrOff, allocLengthStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_485+currStrOff, ");", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_485+currStrOff, NEXT_LINE, strLen_6);
                    currStrOff += strLen_6;
                    
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_485;
break;
}
else {
throwErr(&t,"Expected ',' got {TOKEN}.");
}
}
i =  i + 1;
};
}
char * strArrayLength =  intToStr(arrayLength);
char * ____BAH_COMPILER_VAR_486 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen("->length = ");
long int strLen_3 = strlen(strArrayLength);
long int strLen_4 = strlen(";\n");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen("->elemSize = sizeof(");
long int strLen_7 = strlen(elemTypeStr);
long int strLen_8 = strlen(");\n");
long int strLen_9 = strlen(NEXT_LINE);
;                            
                    ____BAH_COMPILER_VAR_486 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                    
                    strncpy(____BAH_COMPILER_VAR_486+currStrOff, "\n", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_486+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_486+currStrOff, "->length = ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_486+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_486+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_486+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_486+currStrOff, "->elemSize = sizeof(", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_486+currStrOff, elemTypeStr, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_486+currStrOff, ");\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_486+currStrOff, NEXT_LINE, strLen_9);
                    currStrOff += strLen_9;
                    
                }
                NEXT_LINE =  ____BAH_COMPILER_VAR_486;
return code;
};
array(char *)* equalsTokens;
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1986): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1991): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    ft =  l->data[0];
int parsed =  true;
char * ____BAH_COMPILER_VAR_487 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_487 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_487+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_487+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_487));
return;
}
l =  parseStructType(l,(lineType)-1,elems);
int isEqual =  false;
int toVar =  false;
int isPointedVar =  false;
int isStruct =  false;
char * currentType =  "";

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2002): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    ft =  l->data[0];
struct variable* v =  searchVar(ft.cont,elems);
int exists =  true;
char * ogName= null;
if ((v==null)) {
exists =  false;
struct variable* ____BAH_COMPILER_VAR_488 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_488->name = "";
____BAH_COMPILER_VAR_488->type = "";
____BAH_COMPILER_VAR_488->isConst = false;
____BAH_COMPILER_VAR_488->constVal = "";
____BAH_COMPILER_VAR_488->isArray = false;
____BAH_COMPILER_VAR_488->from = "";
____BAH_COMPILER_VAR_488->outterScope = false;
____BAH_COMPILER_VAR_488->isGlobal = false;
v =  ____BAH_COMPILER_VAR_488;
v->name =  ft.cont;
v->type =  "";
}
else {
ogName =  v->name;
}
if ((v->isConst==true)) {
throwErr(&ft,"Cannot set the value of const {TOKEN}.");
}
char * code =  "";
if (((exists==true)&&isGlobal())) {
throwErr(&ft,"Cannot redeclare global variable {TOKEN}.");
}
if ((len(l)==2)) {

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2024): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[1];
if ((((lt.type==TOKEN_TYPE_SYNTAX)&&(strcmp(lt.cont, "++") == 0))||(strcmp(lt.cont, "--") == 0))) {
if ((exists==false)) {
char * ____BAH_COMPILER_VAR_489 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use '");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen("' on non declared {TOKEN} variable.");
;                            
                    ____BAH_COMPILER_VAR_489 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_489+currStrOff, "Cannot use '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_489+currStrOff, lt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_489+currStrOff, "' on non declared {TOKEN} variable.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&ft,____BAH_COMPILER_VAR_489);
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2030): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    
{
long nLength = 0;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[0] =  l->data[0];
nl->length = nLength+1;
} else {
nl->data[0] =  l->data[0];
}
};
struct Tok ____BAH_COMPILER_VAR_490 = {};
____BAH_COMPILER_VAR_490.cont = "";
____BAH_COMPILER_VAR_490.ogCont = "";
____BAH_COMPILER_VAR_490.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_490.pos = 0;
____BAH_COMPILER_VAR_490.line = 1;
____BAH_COMPILER_VAR_490.begLine = 1;
____BAH_COMPILER_VAR_490.bahType = "";
____BAH_COMPILER_VAR_490.isValue = false;
____BAH_COMPILER_VAR_490.isFunc = false;
____BAH_COMPILER_VAR_490.isOper = false;
____BAH_COMPILER_VAR_490.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_490.cont = "=";
____BAH_COMPILER_VAR_490.isValue = false;

{
long nLength = 1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[1] =  ____BAH_COMPILER_VAR_490;
nl->length = nLength+1;
} else {
nl->data[1] =  ____BAH_COMPILER_VAR_490;
}
};
char * c =  "";
if ((strcmp(lt.cont, "++") == 0)) {
char * ____BAH_COMPILER_VAR_491 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("+1");
;                            
                    ____BAH_COMPILER_VAR_491 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_491+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_491+currStrOff, "+1", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                c =  ____BAH_COMPILER_VAR_491;
}
else if ((strcmp(lt.cont, "--") == 0)) {
char * ____BAH_COMPILER_VAR_492 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("-1");
;                            
                    ____BAH_COMPILER_VAR_492 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_492+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_492+currStrOff, "-1", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                c =  ____BAH_COMPILER_VAR_492;
}
long int ltl =  lt.line;
long int ltp =  lt.pos;
char * ltc =  lt.cont;
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
____BAH_COMPILER_VAR_493.type = TOKEN_TYPE_INT;
____BAH_COMPILER_VAR_493.cont = c;
____BAH_COMPILER_VAR_493.line = ltl;
____BAH_COMPILER_VAR_493.ogCont = ltc;
____BAH_COMPILER_VAR_493.pos = ltp;
____BAH_COMPILER_VAR_493.isOper = true;
____BAH_COMPILER_VAR_493.isValue = true;

{
long nLength = 2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[2] =  ____BAH_COMPILER_VAR_493;
nl->length = nLength+1;
} else {
nl->data[2] =  ____BAH_COMPILER_VAR_493;
}
};
l =  nl;
}
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2062): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok operT =  l->data[1];

                int ____BAH_COMPILER_VAR_494 = 0;
                for(int i=len(equalsTokens)-1; i != -1; i--) {
                    if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                        ____BAH_COMPILER_VAR_494 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_494&&(strcmp(operT.cont, "=") != 0))) {

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2064): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = l->data[0];
if ((2==len(l))) {
throwErr(&operT,"Cannot use {TOKEN} on nothing.");
}
struct string oper =  string(operT.cont);
oper.trimRight((struct string*)&oper,1);
struct Tok operTok =  operT;
operTok.cont =  oper.str((struct string*)&oper);

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2076): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    array(struct Tok)* tmpL = memoryAlloc(sizeof(array(struct Tok)));

tmpL->length = 3;
tmpL->elemSize = sizeof(struct Tok);
tmpL->data = memoryAlloc(sizeof(struct Tok) * 50);tmpL->data[0] = ft;
tmpL->data[1] = operTok;
tmpL->data[2] = l->data[2];
tmpL =  parseOperations(tmpL,LINE_TYPE_VAR,elems);
operT.cont =  "=";

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  operT;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  operT;
}
};
long int j =  0;
for (; (j<len(tmpL)); j =  j+1) {

                    if (tmpL->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2085): tmpL[%d] with length %d\n", j, tmpL->length);
                        exit(1);
                    };
                    
{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  tmpL->data[j];
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  tmpL->data[j];
}
};
};
l =  nl;
}
long int i =  1;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2093): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "=") == 0)) {
if ((strlen(currentType)>0)) {
struct string sct =  string(currentType);
sct.replace((struct string*)&sct," ","");
v->type =  sct.str((struct string*)&sct);
}
isEqual =  true;
i =  i + 1;
continue;
}
}
if ((isEqual==false)) {
char * ____BAH_COMPILER_VAR_495 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(currentType);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_495 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_495+currStrOff, currentType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_495+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_495+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                currentType =  ____BAH_COMPILER_VAR_495;
}
else {
if ((strcmp(t.cont, "chan") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2114): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
char * ____BAH_COMPILER_VAR_496 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("chan:");
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_496 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_496+currStrOff, "chan:", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_496+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                v->type =  ____BAH_COMPILER_VAR_496;
code =  "channel()";
if ((i + 1!=len(l))) {

                    if (l->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2118): l[%d] with length %d\n", i + 1, l->length);
                        exit(1);
                    };
                    struct Tok errT =  l->data[i + 1];
throwErr(&errT,"{TOKEN} not expected after channel declaration.");
}
break;
}
else if ((strcmp(t.cont, "map") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (map <type>).");
}
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2128): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
char * ____BAH_COMPILER_VAR_497 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("map:");
long int strLen_1 = strlen(nt.cont);
;                            
                    ____BAH_COMPILER_VAR_497 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_497+currStrOff, "map:", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_497+currStrOff, nt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                v->type =  ____BAH_COMPILER_VAR_497;
code =  "mapWrapper()";
if ((i + 1!=len(l))) {

                    if (l->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2132): l[%d] with length %d\n", i + 1, l->length);
                        exit(1);
                    };
                    struct Tok errT =  l->data[i + 1];
throwErr(&errT,"{TOKEN} not expected after map declaration.");
}
break;
}
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value in var declaration.");
}
char * tp =  getTypeFromToken(&t,true,elems);
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_498 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_498 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_498+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_498+currStrOff, tp, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_498+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_498+currStrOff, v->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_498+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&t,____BAH_COMPILER_VAR_498);
}
}
else {
if ((strlen(currentType)==0)) {
if ((strlen(v->type)==0)) {
v->type =  tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_499 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_499 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_499+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_499+currStrOff, tp, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_499+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_499+currStrOff, v->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_499+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&t,____BAH_COMPILER_VAR_499);
}
}
}
}
if (((strlen(t.cont)>0)&&(strHasPrefix(t.cont,"{")==false))) {
char * ____BAH_COMPILER_VAR_500 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_500 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_500+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_500+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_500+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                code =  ____BAH_COMPILER_VAR_500;
if (((t.isOper==false)&&(RCPavailable()==true))) {
struct variable* iv =  searchVar(t.cont,elems);
if (((iv!=null)&&(iv->isConst==false))) {
toVar =  true;
isPointedVar =  strHasPrefix(t.cont,"&");
struct cStruct* s =  searchStruct(iv->type,elems);
if ((((s!=null)&&(strCount(iv->type,"*")==0))&&(s->isBinding==false))) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_501 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incrCounter(");
long int strLen_2 = strlen(iv->name);
long int strLen_3 = strlen(".__RCP_counter)");
;                            
                    ____BAH_COMPILER_VAR_501 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_501+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_501+currStrOff, "; RCP_incrCounter(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_501+currStrOff, iv->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_501+currStrOff, ".__RCP_counter)", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                code =  ____BAH_COMPILER_VAR_501;
}
else {
struct string ivn =  string(iv->name);
ivn.replace((struct string*)&ivn,"*","");
char * ____BAH_COMPILER_VAR_502 =ivn.str((struct string*)&ivn);char * ____BAH_COMPILER_VAR_503 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incr(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_502);
long int strLen_3 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_503 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_503+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_503+currStrOff, "; RCP_incr(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_503+currStrOff, ____BAH_COMPILER_VAR_502, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_503+currStrOff, ")", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                code =  ____BAH_COMPILER_VAR_503;
}
}
}
}
break;
}
if (strHasPrefix(v->type,"[]")) {
code =  parseArrayDecl(v,l,i,len(l),elems);
break;
}
isStruct =  true;
long int max =  i + 1;
if ((max!=len(l))) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after struct initialization.");
}
char * ____BAH_COMPILER_VAR_504 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_504 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_504+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_504+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_504+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                code =  ____BAH_COMPILER_VAR_504;
}
i =  i+1;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2202): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok st =  l->data[1];
char * ____BAH_COMPILER_VAR_505 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot change the type of already declared var '");
long int strLen_1 = strlen(ft.cont);
long int strLen_2 = strlen("' to {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_505 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_505+currStrOff, "Cannot change the type of already declared var '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_505+currStrOff, ft.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_505+currStrOff, "' to {TOKEN}.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&st,____BAH_COMPILER_VAR_505);
}
if ((isStruct==false)) {
if (((isRCPpointerType(v->type)&&(isPointedVar==false))&&(RCPavailable()==true))) {
struct string cType =  getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_506 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_507 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_508 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_506);
long int strLen_2 = strlen("*)RCP_decrIL(&");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(") = *(");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_507);
long int strLen_6 = strlen("*)RCP_incrIL(&");
long int strLen_7 = strlen(code);
long int strLen_8 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_508 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                    
                    strncpy(____BAH_COMPILER_VAR_508+currStrOff, "*(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_508+currStrOff, ____BAH_COMPILER_VAR_506, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_508+currStrOff, "*)RCP_decrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_508+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_508+currStrOff, ") = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_508+currStrOff, ____BAH_COMPILER_VAR_507, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_508+currStrOff, "*)RCP_incrIL(&", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_508+currStrOff, code, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_508+currStrOff, ")", strLen_8);
                    currStrOff += strLen_8;
                    
                }
                code =  ____BAH_COMPILER_VAR_508;
}
else {
struct variable* ____BAH_COMPILER_VAR_509 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_509->name = "";
____BAH_COMPILER_VAR_509->type = "";
____BAH_COMPILER_VAR_509->isConst = false;
____BAH_COMPILER_VAR_509->constVal = "";
____BAH_COMPILER_VAR_509->isArray = false;
____BAH_COMPILER_VAR_509->from = "";
____BAH_COMPILER_VAR_509->outterScope = false;
____BAH_COMPILER_VAR_509->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_509;
tmpV->name =  genCompilerVar();
tmpV->type =  v->type;
struct rope* dv =  decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_510 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_511 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_512 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_513 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_510);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = *(");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_511);
long int strLen_9 = strlen("*)RCP_incrIL(&");
long int strLen_10 = strlen(code);
long int strLen_11 = strlen(");");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_512);
;                            
                    ____BAH_COMPILER_VAR_513 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, ____BAH_COMPILER_VAR_510, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, " = *(", strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, ____BAH_COMPILER_VAR_511, strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, "*)RCP_incrIL(&", strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, code, strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, ");", strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_513+currStrOff, ____BAH_COMPILER_VAR_512, strLen_12);
                    currStrOff += strLen_12;
                    
                }
                code =  ____BAH_COMPILER_VAR_513;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_514 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_514->name = "";
____BAH_COMPILER_VAR_514->type = "";
____BAH_COMPILER_VAR_514->isConst = false;
____BAH_COMPILER_VAR_514->constVal = "";
____BAH_COMPILER_VAR_514->isArray = false;
____BAH_COMPILER_VAR_514->from = "";
____BAH_COMPILER_VAR_514->outterScope = false;
____BAH_COMPILER_VAR_514->isGlobal = false;
struct variable* tmpV =  ____BAH_COMPILER_VAR_514;
tmpV->name =  genCompilerVar();
tmpV->type =  v->type;
struct rope* dv =  decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_515 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_516 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_517 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_515);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = ");
long int strLen_8 = strlen(code);
long int strLen_9 = strlen(";");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_516);
;                            
                    ____BAH_COMPILER_VAR_517 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10);
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, ____BAH_COMPILER_VAR_515, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, tmpV->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, " = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, code, strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, ";", strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_517+currStrOff, ____BAH_COMPILER_VAR_516, strLen_10);
                    currStrOff += strLen_10;
                    
                }
                code =  ____BAH_COMPILER_VAR_517;
}
}
else {
struct cStruct* s =  searchStruct(v->type,elems);
if ((((((s!=null)&&(RCPavailable()==true))&&(RCPselfRef(v)==false))&&(s->isBinding==false))&&(strCount(v->name,"*")==0))) {
char * ____BAH_COMPILER_VAR_518 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("RCP_decrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter); ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_518 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_518+currStrOff, "RCP_decrCounter(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_518+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_518+currStrOff, ".__RCP_counter); ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_518+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_518+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_518+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                }
                code =  ____BAH_COMPILER_VAR_518;
}
else {
char * ____BAH_COMPILER_VAR_519 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_519 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_519+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_519+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_519+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                code =  ____BAH_COMPILER_VAR_519;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_520 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_520 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_520+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_520+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_520+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                code =  ____BAH_COMPILER_VAR_520;
}
}
if ((v->isArray==true)) {
struct string nLength =  string(v->name);
struct string n =  string(v->name);
i =  0;
while ((i<nLength.length)) {
char c =  nLength.charAt((struct string*)&nLength,i);
if ((c==91)) {
break;
}
i =  i+1;
};
nLength.trimLeft((struct string*)&nLength,i + 1);
nLength.trimRight((struct string*)&nLength,1);
char * nLengthStr =  nLength.str((struct string*)&nLength);
i =  n.length;
while ((i>0)) {
char c =  n.charAt((struct string*)&n,i);
if ((c==91)) {
break;
}
i =  i-1;
};
long int tamm =  n.length - i;
n.trimRight((struct string*)&n,tamm + 6);
char * nstr =  n.str((struct string*)&n);
struct string elemType =  getCType(v->type,elems);
char * elemTypeStr =  elemType.str((struct string*)&elemType);
char * ____BAH_COMPILER_VAR_521 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n{\nlong nLength = ");
long int strLen_1 = strlen(nLengthStr);
long int strLen_2 = strlen(";\nif (");
long int strLen_3 = strlen(nstr);
long int strLen_4 = strlen("->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(");
long int strLen_5 = strlen(nstr);
long int strLen_6 = strlen("->data, (nLength+50)*sizeof(");
long int strLen_7 = strlen(elemTypeStr);
long int strLen_8 = strlen("));\n");
long int strLen_9 = strlen(nstr);
long int strLen_10 = strlen("->data = newPtr;\n}\n");
long int strLen_11 = strlen(code);
long int strLen_12 = strlen(";\n");
long int strLen_13 = strlen(nstr);
long int strLen_14 = strlen("->length = nLength+1;\n} else {\n");
long int strLen_15 = strlen(code);
long int strLen_16 = strlen(";\n}\n}");
;                            
                    ____BAH_COMPILER_VAR_521 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, "\n{\nlong nLength = ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, nLengthStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, ";\nif (", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, nstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, nstr, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, "->data, (nLength+50)*sizeof(", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, elemTypeStr, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, "));\n", strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, nstr, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, "->data = newPtr;\n}\n", strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, code, strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, ";\n", strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, nstr, strLen_13);
                    currStrOff += strLen_13;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, "->length = nLength+1;\n} else {\n", strLen_14);
                    currStrOff += strLen_14;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, code, strLen_15);
                    currStrOff += strLen_15;
                    
                    strncpy(____BAH_COMPILER_VAR_521+currStrOff, ";\n}\n}", strLen_16);
                    currStrOff += strLen_16;
                    
                }
                code =  ____BAH_COMPILER_VAR_521;
}
}
else {
if ((strlen(currentType)>0)) {
v->type =  currentType;
}
struct string vts =  string(v->type);
vts.replace((struct string*)&vts," ","");
v->type =  vts.content;
if ((strlen(v->type)==0)) {
throwErr(&ft,"Cannot declare {TOKEN} without a type.");
}
char * vct= null;
if (vts.hasPrefix((struct string*)&vts,"function(")) {
struct func* tmpfn =  parseFnType(vts);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {

                    if (tmpfn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2301): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_522 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_523 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_522);
;                            
                    ____BAH_COMPILER_VAR_523 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_523+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_523+currStrOff, ____BAH_COMPILER_VAR_522, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_523;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_524 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_524 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_524+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_524+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_524;
}
};
char * ____BAH_COMPILER_VAR_525 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_526 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_525);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_526 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_526+currStrOff, ____BAH_COMPILER_VAR_525, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_526+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_526+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_526+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_526+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_526+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                vct =  ____BAH_COMPILER_VAR_526;
}
else {
vct =  setCType(v,elems);
}
if (((strlen(code)>0)&&(shouldOnlyDecl==false))) {
if ((((isRCPpointerType(v->type)&&(RCPavailable()==true))&&(toVar==true))&&(isPointedVar==false))) {
struct string cType =  getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_527 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_528 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_527);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_528 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_528+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_528+currStrOff, " = *(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_528+currStrOff, ____BAH_COMPILER_VAR_527, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_528+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_528+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_528+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_528));
}
else {
char * ____BAH_COMPILER_VAR_529 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_530 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_529);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_530 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_530+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_530+currStrOff, " = *(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_530+currStrOff, ____BAH_COMPILER_VAR_529, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_530+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_530+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_530+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                code =  ____BAH_COMPILER_VAR_530;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_531 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_531 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_531+currStrOff, v->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_531+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_531+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_531+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_531));
}
else {
char * ____BAH_COMPILER_VAR_532 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_532 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_532+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_532+currStrOff, " = ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_532+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                code =  ____BAH_COMPILER_VAR_532;
}
}
}
else {
if ((isRCPpointerType(v->type)&&(shouldOnlyDecl==false))) {
char * ____BAH_COMPILER_VAR_533 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen("= null");
;                            
                    ____BAH_COMPILER_VAR_533 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_533+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_533+currStrOff, "= null", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                code =  ____BAH_COMPILER_VAR_533;
}
else {
code =  vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_534 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("extern ");
long int strLen_1 = strlen(vct);
;                            
                    ____BAH_COMPILER_VAR_534 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_534+currStrOff, "extern ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_534+currStrOff, vct, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                vct =  ____BAH_COMPILER_VAR_534;
}
if (isGlobal()) {
v->isGlobal =  true;
}
else {
v->isGlobal =  false;
}

{
long nLength = len(elems->vars);
if (elems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->vars->data, (nLength+50)*sizeof(struct variable*));
elems->vars->data = newPtr;
}
elems->vars->data[len(elems->vars)] =  v;
elems->vars->length = nLength+1;
} else {
elems->vars->data[len(elems->vars)] =  v;
}
};
struct variable* ____BAH_COMPILER_VAR_535 = v;
char ** ____BAH_COMPILER_VAR_537 = (char **)((char*)(____BAH_COMPILER_VAR_535) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_538 = __reflect(____BAH_COMPILER_VAR_537, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_539 = (char **)((char*)(____BAH_COMPILER_VAR_535) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_540 = __reflect(____BAH_COMPILER_VAR_539, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
int* ____BAH_COMPILER_VAR_541 = (int*)((char*)(____BAH_COMPILER_VAR_535) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_542 = __reflect(____BAH_COMPILER_VAR_541, sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_543 = (char **)((char*)(____BAH_COMPILER_VAR_535) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_544 = __reflect(____BAH_COMPILER_VAR_543, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
int* ____BAH_COMPILER_VAR_545 = (int*)((char*)(____BAH_COMPILER_VAR_535) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_546 = __reflect(____BAH_COMPILER_VAR_545, sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_547 = (char **)((char*)(____BAH_COMPILER_VAR_535) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_548 = __reflect(____BAH_COMPILER_VAR_547, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
int* ____BAH_COMPILER_VAR_549 = (int*)((char*)(____BAH_COMPILER_VAR_535) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_550 = __reflect(____BAH_COMPILER_VAR_549, sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
int* ____BAH_COMPILER_VAR_551 = (int*)((char*)(____BAH_COMPILER_VAR_535) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_552 = __reflect(____BAH_COMPILER_VAR_551, sizeof(int), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_536 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_536->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_536->length = 8;
        ____BAH_COMPILER_VAR_536->data = memoryAlloc(____BAH_COMPILER_VAR_536->length * ____BAH_COMPILER_VAR_536->elemSize);
        ____BAH_COMPILER_VAR_536->data[0] = ____BAH_COMPILER_VAR_538;
____BAH_COMPILER_VAR_536->data[1] = ____BAH_COMPILER_VAR_540;
____BAH_COMPILER_VAR_536->data[2] = ____BAH_COMPILER_VAR_542;
____BAH_COMPILER_VAR_536->data[3] = ____BAH_COMPILER_VAR_544;
____BAH_COMPILER_VAR_536->data[4] = ____BAH_COMPILER_VAR_546;
____BAH_COMPILER_VAR_536->data[5] = ____BAH_COMPILER_VAR_548;
____BAH_COMPILER_VAR_536->data[6] = ____BAH_COMPILER_VAR_550;
____BAH_COMPILER_VAR_536->data[7] = ____BAH_COMPILER_VAR_552;
struct reflectElement ____BAH_COMPILER_VAR_553 = __reflect(____BAH_COMPILER_VAR_535, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_536, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_553);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_554 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_554 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_554+currStrOff, vct, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_554+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_554));
}
}
if (isGlobal()) {
if ((isSubObject==false)) {
INIT =  INIT->add(INIT, rope(NEXT_LINE));
}
NEXT_LINE =  "";
}
else {
char * ____BAH_COMPILER_VAR_555 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_555 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_555+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_555+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_555));
}
};
char * getCfunctionType(struct string cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn =  parseFnType(cfrt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {

                    if (tmpfn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2377): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_556 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_557 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_556);
;                            
                    ____BAH_COMPILER_VAR_557 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_557+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_557+currStrOff, ____BAH_COMPILER_VAR_556, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_557;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_558 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_558 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_558+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_558+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_558;
}
};
char * ____BAH_COMPILER_VAR_559 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_560 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_559);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(elemName);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_560 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_560+currStrOff, ____BAH_COMPILER_VAR_559, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_560+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_560+currStrOff, elemName, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_560+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_560+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_560+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                return ____BAH_COMPILER_VAR_560;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
long int j =  *i;

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2393): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[j];
char * tpdf =  "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_561 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(prev);
long int strLen_1 = strlen(ft.cont);
;                            
                    ____BAH_COMPILER_VAR_561 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_561+currStrOff, prev, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_561+currStrOff, ft.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fn->name =  ____BAH_COMPILER_VAR_561;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_562 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_562 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_562+currStrOff, fn->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_562+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * code =  ____BAH_COMPILER_VAR_562;
j =  j + 2;

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2407): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[j];
if ((strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2411): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    t =  l->data[j];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as argument name.");
}
char * argName =  t.cont;
j =  j + 1;
if ((j>=len(l))) {
throwErr(&t,"Cannot declare argument {TOKEN} without a type.");
}

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2421): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    t =  l->data[j];
char * argType =  t.cont;
j =  j + 1;
int isComa =  false;
long int nbPars =  1;
while ((j<len(l))) {

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2428): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    t =  l->data[j];
isComa =  false;
if ((strcmp(t.cont, ",") != 0)) {
if ((strcmp(t.cont, "(") == 0)) {
nbPars =  nbPars + 1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPars =  nbPars - 1;
}
if (((strcmp(t.cont, ")") == 0)&&(nbPars==0))) {
break;
}
else {
char * ____BAH_COMPILER_VAR_563 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(argType);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_563 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_563+currStrOff, argType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_563+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                argType =  ____BAH_COMPILER_VAR_563;
}
}
else {
isComa =  true;
break;
}
j =  j + 1;
};
struct variable* ____BAH_COMPILER_VAR_564 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_564->name = "";
____BAH_COMPILER_VAR_564->type = "";
____BAH_COMPILER_VAR_564->isConst = false;
____BAH_COMPILER_VAR_564->constVal = "";
____BAH_COMPILER_VAR_564->isArray = false;
____BAH_COMPILER_VAR_564->from = "";
____BAH_COMPILER_VAR_564->outterScope = false;
____BAH_COMPILER_VAR_564->isGlobal = false;
struct variable* argument =  ____BAH_COMPILER_VAR_564;
argument->name =  argName;
argument->type =  argType;

{
long nLength = len(arguments);
if (arguments->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(arguments->data, (nLength+50)*sizeof(struct variable*));
arguments->data = newPtr;
}
arguments->data[len(arguments)] =  argument;
arguments->length = nLength+1;
} else {
arguments->data[len(arguments)] =  argument;
}
};
struct string argCType =  getCType(argType,elems);
struct string cfrt =  string(argType);
char * newArgType =  argCType.str((struct string*)&argCType);
if ((cfrt.hasPrefix((struct string*)&cfrt,"[]")==1)) {
cfrt.trimLeft((struct string*)&cfrt,2);
if (cfrt.hasSuffix((struct string*)&cfrt,"*")) {
long int nbast =  cfrt.count((struct string*)&cfrt,"*");
cfrt.trimRight((struct string*)&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_565 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_566 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_565);
;                            
                    ____BAH_COMPILER_VAR_566 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_566+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_566+currStrOff, ____BAH_COMPILER_VAR_565, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                newArgType =  ____BAH_COMPILER_VAR_566;
array(char *)* csatd =  compilerState.arrTypesDecl;
if ((inArrayStr(newArgType,csatd)==false)) {

{
long nLength = len(csatd);
if (csatd->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(csatd->data, (nLength+50)*sizeof(char *));
csatd->data = newPtr;
}
csatd->data[len(csatd)] =  newArgType;
csatd->length = nLength+1;
} else {
csatd->data[len(csatd)] =  newArgType;
}
};
char * ____BAH_COMPILER_VAR_567 =argCType.str((struct string*)&argCType);char * ____BAH_COMPILER_VAR_568 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_567);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newArgType);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_568+currStrOff, tpdf, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_568+currStrOff, "typedef ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_568+currStrOff, ____BAH_COMPILER_VAR_567, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_568+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_568+currStrOff, newArgType, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_568+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                tpdf =  ____BAH_COMPILER_VAR_568;
}
}
if ((cfrt.hasPrefix((struct string*)&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_569 =getCfunctionType(cfrt,argName,elems);char * ____BAH_COMPILER_VAR_570 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_569);
;                            
                    ____BAH_COMPILER_VAR_570 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_570+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_570+currStrOff, ____BAH_COMPILER_VAR_569, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                code =  ____BAH_COMPILER_VAR_570;
}
else {
char * ____BAH_COMPILER_VAR_571 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(newArgType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(argName);
;                            
                    ____BAH_COMPILER_VAR_571 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_571+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_571+currStrOff, newArgType, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_571+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_571+currStrOff, argName, strLen_3);
                    currStrOff += strLen_3;
                    
                }
                code =  ____BAH_COMPILER_VAR_571;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_572 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_572 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_572+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_572+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                code =  ____BAH_COMPILER_VAR_572;
}
else {
char * ____BAH_COMPILER_VAR_573 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_573 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_573+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_573+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                code =  ____BAH_COMPILER_VAR_573;
break;
}
j =  j + 1;
};
}
else {
char * ____BAH_COMPILER_VAR_574 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_574 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_574+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_574+currStrOff, ")", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                code =  ____BAH_COMPILER_VAR_574;
}
j =  j + 1;
struct variable* ____BAH_COMPILER_VAR_575 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_575->name = "";
____BAH_COMPILER_VAR_575->type = "";
____BAH_COMPILER_VAR_575->isConst = false;
____BAH_COMPILER_VAR_575->constVal = "";
____BAH_COMPILER_VAR_575->isArray = false;
____BAH_COMPILER_VAR_575->from = "";
____BAH_COMPILER_VAR_575->outterScope = false;
____BAH_COMPILER_VAR_575->isGlobal = false;
struct variable* returns =  ____BAH_COMPILER_VAR_575;
returns->type =  "";
while ((j<len(l))) {

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2493): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    t =  l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_576 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(returns->type);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_576 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_576+currStrOff, returns->type, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_576+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                returns->type =  ____BAH_COMPILER_VAR_576;
j =  j + 1;
};
if (strlen(returns->type)) {
struct string rts =  string(returns->type);
rts.replace((struct string*)&rts," ","");
returns->type =  rts.content;
}
*i =  j;
returns->name =  fn->name;
fn->returns =  returns;
fn->args =  arguments;
struct string fnRetType =  getCType(returns->type,elems);
char * newFnRetType =  fnRetType.str((struct string*)&fnRetType);
struct string cfrt =  string(returns->type);
if ((cfrt.hasPrefix((struct string*)&cfrt,"[]")==1)) {
cfrt.trimLeft((struct string*)&cfrt,2);
if (cfrt.hasSuffix((struct string*)&cfrt,"*")) {
long int nbast =  cfrt.count((struct string*)&cfrt,"*");
cfrt.trimRight((struct string*)&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_577 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_578 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_577);
;                            
                    ____BAH_COMPILER_VAR_578 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_578+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_578+currStrOff, ____BAH_COMPILER_VAR_577, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                newFnRetType =  ____BAH_COMPILER_VAR_578;
array(char *)* csatd =  compilerState.arrTypesDecl;
if ((inArrayStr(newFnRetType,csatd)==false)) {

{
long nLength = len(csatd);
if (csatd->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(csatd->data, (nLength+50)*sizeof(char *));
csatd->data = newPtr;
}
csatd->data[len(csatd)] =  newFnRetType;
csatd->length = nLength+1;
} else {
csatd->data[len(csatd)] =  newFnRetType;
}
};
char * ____BAH_COMPILER_VAR_579 =fnRetType.str((struct string*)&fnRetType);char * ____BAH_COMPILER_VAR_580 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_579);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newFnRetType);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_580 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_580+currStrOff, tpdf, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_580+currStrOff, "typedef ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_580+currStrOff, ____BAH_COMPILER_VAR_579, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_580+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_580+currStrOff, newFnRetType, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_580+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                tpdf =  ____BAH_COMPILER_VAR_580;
}
}
char * ____BAH_COMPILER_VAR_581 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen(newFnRetType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(code);
;                            
                    ____BAH_COMPILER_VAR_581 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_581+currStrOff, tpdf, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_581+currStrOff, newFnRetType, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_581+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_581+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                }
                code =  ____BAH_COMPILER_VAR_581;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_582 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_582->name = "";
____BAH_COMPILER_VAR_582->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_582->members->length = 0;
            ____BAH_COMPILER_VAR_582->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_582->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_582->methods->length = 0;
            ____BAH_COMPILER_VAR_582->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_582->postCode = "";
____BAH_COMPILER_VAR_582->extendedFrom = "";
____BAH_COMPILER_VAR_582->isBinding = false;
____BAH_COMPILER_VAR_582->hasRCPmemb = false;
struct cStruct* s =  ____BAH_COMPILER_VAR_582;
array(struct cStruct*)* structs =  elems->structs;

{
long nLength = len(structs);
if (structs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(structs->data, (nLength+50)*sizeof(struct cStruct*));
structs->data = newPtr;
}
structs->data[len(structs)] =  s;
structs->length = nLength+1;
} else {
structs->data[len(structs)] =  s;
}
};
array(struct func*)* methds =  s->methods;
if ((len(l)<4)) {
throwErr(&l->data[len(l)-1],"Cannot declare struct has such, please do 'struct <name> { <memberName>:<memberType> }'.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2543): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok nameToken =  l->data[1];
long int i =  2;
int doesOutput =  true;
if ((strcmp(nameToken.cont, "!") == 0)) {

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2547): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    nameToken =  l->data[2];
i =  3;
doesOutput =  false;
s->isBinding =  true;
}
if ((nameToken.type!=TOKEN_TYPE_VAR)) {
throwErr(&nameToken,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* os =  searchStruct(nameToken.cont,elems);
if ((os!=null)) {
throwErr(&nameToken,"Struct {TOKEN} already exists.");
}
s->name =  nameToken.cont;
array(struct structMemb*)* members =  s->members;
currentCStruct =  s;
array(char *)* allMembs = memoryAlloc(sizeof(array(char *)));

allMembs->length = 0;
allMembs->elemSize = sizeof(char *);

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2563): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok st =  l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(st.cont, "extend") == 0)) {
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2567): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok extdSNameTk =  l->data[i];
i =  i+1;
if ((extdSNameTk.type!=TOKEN_TYPE_VAR)) {
throwErr(&extdSNameTk,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* extdS =  searchStruct(extdSNameTk.cont,elems);
s->extendedFrom =  extdS->name;
if ((extdS==null)) {
throwErr(&extdSNameTk,"Struct {TOKEN} does not exist.");
}
array(struct structMemb*)* extdsmbs =  extdS->members;
long int j =  0;
while ((j<len(extdsmbs))) {

                    if (extdsmbs->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2579): extdsmbs[%d] with length %d\n", j, extdsmbs->length);
                        exit(1);
                    };
                    struct structMemb* em =  extdsmbs->data[j];
struct string cemt =  string(em->type);
char * membDeclStr= null;
if ((cemt.hasPrefix((struct string*)&cemt,"function(")==1)) {
struct func* tmpfn =  parseFnType(cemt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
j =  0;
while ((j<len(tmpfn->args))) {

                    if (tmpfn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2587): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_583 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_584 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_583);
;                            
                    ____BAH_COMPILER_VAR_584 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_584+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_584+currStrOff, ____BAH_COMPILER_VAR_583, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_584;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_585 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_585 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_585+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_585+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_585;
}
};
char * ____BAH_COMPILER_VAR_586 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_587 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_586);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(em->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_587 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_587+currStrOff, ____BAH_COMPILER_VAR_586, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_587+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_587+currStrOff, em->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_587+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_587+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_587+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                membDeclStr =  ____BAH_COMPILER_VAR_587;
}
else {
if (isRCPpointerType(em->type)) {
s->hasRCPmemb =  true;
}
struct string membDecl =  getCType(em->type,elems);
membDecl.append((struct string*)&membDecl," ");
membDecl.append((struct string*)&membDecl,em->name);
membDeclStr =  membDecl.content;
}

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  membDeclStr;
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  membDeclStr;
}
};

{
long nLength = len(members);
if (members->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(members->data, (nLength+50)*sizeof(struct structMemb*));
members->data = newPtr;
}
members->data[len(members)] =  em;
members->length = nLength+1;
} else {
members->data[len(members)] =  em;
}
};
j =  j + 1;
};
long int k =  0;
while ((k<len(extdS->methods))) {

                    if (extdS->methods->length <= k) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2611): extdS->methods[%d] with length %d\n", k, extdS->methods->length);
                        exit(1);
                    };
                    struct func* emt =  extdS->methods->data[k];
struct string mthdDecl =  getCType(emt->returns->type,elems);
char * ____BAH_COMPILER_VAR_588 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(emt->name);
long int strLen_2 = strlen(")(");
;                            
                    ____BAH_COMPILER_VAR_588 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_588+currStrOff, "(*", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_588+currStrOff, emt->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_588+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_588);
j =  0;
while ((j<len(emt->args))) {

                    if (emt->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2616): emt->args[%d] with length %d\n", j, emt->args->length);
                        exit(1);
                    };
                    struct variable* a =  emt->args->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_589 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_589 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_589+currStrOff, " ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_589+currStrOff, a->name, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tp.append((struct string*)&tp,____BAH_COMPILER_VAR_589);
long int max =  len(emt->args) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_590 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_590);
j =  j + 1;
};
mthdDecl.append((struct string*)&mthdDecl,")");

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
}
};
k =  k + 1;
};
}
else {
throwErr(&st,"Cannot use keyword {TOKEN} in struct declaration.");
}
}

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2635): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok braceTk =  l->data[i];
i =  i+1;
if ((strcmp(braceTk.cont, "{") != 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
struct rope* OOUT =  OUTPUT;
char * nextLine =  "";
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2643): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
long int max =  i + 2;
if ((max>=len(l))) {
if (((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "}") == 0))) {
break;
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* ____BAH_COMPILER_VAR_591 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_591->name = "";
____BAH_COMPILER_VAR_591->type = "";
____BAH_COMPILER_VAR_591->isConst = false;
____BAH_COMPILER_VAR_591->constVal = "";
____BAH_COMPILER_VAR_591->isArray = false;
____BAH_COMPILER_VAR_591->from = "";
____BAH_COMPILER_VAR_591->outterScope = false;
____BAH_COMPILER_VAR_591->isGlobal = false;
____BAH_COMPILER_VAR_591->def = "";
____BAH_COMPILER_VAR_591->isFn = false;
struct structMemb* memb =  ____BAH_COMPILER_VAR_591;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name =  t.cont;
long int ii =  0;
while ((ii<len(members))) {

                    if (members->length <= ii) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2657): members[%d] with length %d\n", ii, members->length);
                        exit(1);
                    };
                    struct structMemb* m =  members->data[ii];
if ((strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii =  ii + 1;
};
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2664): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_592 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("__");
;                            
                    ____BAH_COMPILER_VAR_592 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_592+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_592+currStrOff, "__", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * fnPrefix =  ____BAH_COMPILER_VAR_592;
struct func* ____BAH_COMPILER_VAR_593 = memoryAlloc(sizeof(struct func));
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
struct func* fn =  ____BAH_COMPILER_VAR_593;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int j =  i-1;
while ((j<len(l))) {

                    if (l->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2673): l[%d] with length %d\n", j, l->length);
                        exit(1);
                    };
                    t =  l->data[j];
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
if ((j==i)) {
t.type =  TOKEN_TYPE_VAR;
t.cont =  "this";
t.isValue =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
t.type =  TOKEN_TYPE_VAR;
char * ____BAH_COMPILER_VAR_594 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_594 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_594+currStrOff, s->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_594+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_594;
t.isValue =  true;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};

                    if (l->length <= j + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2689): l[%d] with length %d\n", j + 1, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[j + 1];
if ((strcmp(nt.cont, ")") != 0)) {
t.type =  TOKEN_TYPE_SYNTAX;
t.cont =  ",";
t.isValue =  false;

{
long nLength = len(nl);
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
}
}
j =  j + 1;
};
i =  i-1;
long int nli =  0;
char * ____BAH_COMPILER_VAR_595 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code =  rope(____BAH_COMPILER_VAR_595);
i =  i + nli;
i =  i - 2;
struct variable* returns =  fn->returns;
array(struct variable*)* arguments =  fn->args;
fn->from =  s->name;
if ((shouldOnlyDecl==true)) {
code =  code->add(code, rope(";\n"));
}
else {
code =  code->add(code, rope("{\n"));
}
struct Elems* fnElems =  dupElems(elems);
j =  0;
while ((j<len(arguments))) {

                    if (arguments->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2718): arguments[%d] with length %d\n", j, arguments->length);
                        exit(1);
                    };
                    struct variable* a =  arguments->data[j];
a->outterScope =  true;

{
long nLength = len(fnElems->vars);
if (fnElems->vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fnElems->vars->data, (nLength+50)*sizeof(struct variable*));
fnElems->vars->data = newPtr;
}
fnElems->vars->data[len(fnElems->vars)] =  a;
fnElems->vars->length = nLength+1;
} else {
fnElems->vars->data[len(fnElems->vars)] =  a;
}
};
j =  j + 1;
};
array(struct func*)* fns =  elems->fns;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] =  fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] =  fn;
}
};
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int nbBraces =  1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2729): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
i =  i+1;
}
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2734): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
nbBraces =  nbBraces + 1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbBraces =  nbBraces - 1;
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
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
}
};
i =  i+1;
};
struct func* ____BAH_COMPILER_VAR_596 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_596->name = "";
____BAH_COMPILER_VAR_596->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_596->args->length = 0;
            ____BAH_COMPILER_VAR_596->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_596->returns= null;
____BAH_COMPILER_VAR_596->isBinding = false;
____BAH_COMPILER_VAR_596->from = "";
____BAH_COMPILER_VAR_596->file = "";
____BAH_COMPILER_VAR_596->line = 1;
____BAH_COMPILER_VAR_596->used = false;
____BAH_COMPILER_VAR_596->code = null;
struct func* mfn =  ____BAH_COMPILER_VAR_596;
mfn->args =  fn->args;
mfn->name =  fn->name;
mfn->returns =  fn->returns;
mfn->from =  s->name;
strTrimLeft(&mfn->name,strlen(fnPrefix));

{
long nLength = len(methds);
if (methds->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(methds->data, (nLength+50)*sizeof(struct func*));
methds->data = newPtr;
}
methds->data[len(methds)] =  mfn;
methds->length = nLength+1;
} else {
methds->data[len(methds)] =  mfn;
}
};
if ((shouldOnlyDecl==false)) {
if ((len(tokens)==0)) {
code =  code->add(code, rope("};\n"));
}
else {
OUTPUT =  rope("");
currentFn =  fn;
parseLines(tokens,fnElems);
currentFn =  null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_597 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                    ____BAH_COMPILER_VAR_597 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_597+currStrOff, "Function '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_597+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_597+currStrOff, "' is not returned.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_597);
}
endRCPscope(fnElems,null);
}
code =  code->add(code, OUTPUT)->add(code->add(code, OUTPUT), rope("};\n"));
}
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_598 =code->toStr((struct rope*)code);char * ____BAH_COMPILER_VAR_599 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(nextLine);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_598);
;                            
                    ____BAH_COMPILER_VAR_599 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_599+currStrOff, nextLine, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_599+currStrOff, ____BAH_COMPILER_VAR_598, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                nextLine =  ____BAH_COMPILER_VAR_599;
}
struct string mthdDecl =  getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_600 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(mfn->name);
long int strLen_2 = strlen(")(");
;                            
                    ____BAH_COMPILER_VAR_600 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_600+currStrOff, "(*", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_600+currStrOff, mfn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_600+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_600);
j =  0;
while ((j<len(arguments))) {

                    if (arguments->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2784): arguments[%d] with length %d\n", j, arguments->length);
                        exit(1);
                    };
                    struct variable* a =  arguments->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_601 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_601 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_601+currStrOff, " ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_601+currStrOff, a->name, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tp.append((struct string*)&tp,____BAH_COMPILER_VAR_601);
max =  len(arguments) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_602 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_602);
j =  j + 1;
};
mthdDecl.append((struct string*)&mthdDecl,")");

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  mthdDecl.str((struct string*)&mthdDecl);
}
};
i =  i+1;
continue;
}
}
i =  i+1;
char * mbmType =  "";
long int currentLine =  t.line;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2806): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((strcmp(t.cont, "=") == 0)) {
i =  i-1;
break;
}
if ((t.line!=currentLine)) {
i =  i-1;
break;
}
char * ____BAH_COMPILER_VAR_603 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(mbmType);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_603 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_603+currStrOff, mbmType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_603+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                mbmType =  ____BAH_COMPILER_VAR_603;
i =  i+1;
};
memb->type =  mbmType;
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2821): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
i =  i+1;

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2825): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char * ____BAH_COMPILER_VAR_604 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(memb->type);
long int strLen_4 = strlen(" for member.");
;                            
                    ____BAH_COMPILER_VAR_604 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_604+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_604+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_604+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_604+currStrOff, memb->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_604+currStrOff, " for member.", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&t,____BAH_COMPILER_VAR_604);
}
memb->def =  t.cont;
}
else {
i =  i-1;
}
}
if (isRCPpointerType(memb->type)) {
s->hasRCPmemb =  true;
}

{
long nLength = len(members);
if (members->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(members->data, (nLength+50)*sizeof(struct structMemb*));
members->data = newPtr;
}
members->data[len(members)] =  memb;
members->length = nLength+1;
} else {
members->data[len(members)] =  memb;
}
};
char * membDeclStr= null;
struct string cmt =  string(memb->type);
if ((cmt.hasPrefix((struct string*)&cmt,"function(")==1)) {
struct func* tmpfn =  parseFnType(cmt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {

                    if (tmpfn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2851): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_605 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_606 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_605);
;                            
                    ____BAH_COMPILER_VAR_606 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_606+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_606+currStrOff, ____BAH_COMPILER_VAR_605, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_606;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_607 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                    ____BAH_COMPILER_VAR_607 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_607+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_607+currStrOff, ",", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_607;
}
};
char * ____BAH_COMPILER_VAR_608 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_609 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_608);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(memb->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_609 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_609+currStrOff, ____BAH_COMPILER_VAR_608, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_609+currStrOff, " (*", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_609+currStrOff, memb->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_609+currStrOff, ")(", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_609+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_609+currStrOff, ")", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                membDeclStr =  ____BAH_COMPILER_VAR_609;
}
else {
struct string membDecl =  getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_610 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(memb->name);
;                            
                    ____BAH_COMPILER_VAR_610 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_610+currStrOff, " ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_610+currStrOff, memb->name, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                membDecl.append((struct string*)&membDecl,____BAH_COMPILER_VAR_610);
membDeclStr =  membDecl.str((struct string*)&membDecl);
}

{
long nLength = len(allMembs);
if (allMembs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(allMembs->data, (nLength+50)*sizeof(char *));
allMembs->data = newPtr;
}
allMembs->data[len(allMembs)] =  membDeclStr;
allMembs->length = nLength+1;
} else {
allMembs->data[len(allMembs)] =  membDeclStr;
}
};
i =  i+1;
};
s->members =  members;
if ((doesOutput==true)) {
OUTPUT =  OOUT;
NEXT_LINE =  nextLine;
char * ____BAH_COMPILER_VAR_611 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct ");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen(" {\n");
;                            
                    ____BAH_COMPILER_VAR_611 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_611+currStrOff, "struct ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_611+currStrOff, s->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_611+currStrOff, " {\n", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                struct rope* code =  rope(____BAH_COMPILER_VAR_611);
i =  0;
while ((i<len(allMembs))) {

                    if (allMembs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2874): allMembs[%d] with length %d\n", i, allMembs->length);
                        exit(1);
                    };
                    char * m =  allMembs->data[i];
char * ____BAH_COMPILER_VAR_612 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(m);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_612 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_612+currStrOff, m, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_612+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                code =  code->add(code, rope(____BAH_COMPILER_VAR_612));
i =  i+1;
};
if ((RCPavailable()==true)) {
code =  code->add(code, rope("void * __RCP_counter;\n"));
}
code =  code->add(code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, code)->add(OUTPUT->add(OUTPUT, code), makeRCPfuncFromStruct(s,elems));
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_613 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_613->name= null;
____BAH_COMPILER_VAR_613->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_613->membs->length = 0;
            ____BAH_COMPILER_VAR_613->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds =  ____BAH_COMPILER_VAR_613;
ds->name =  s->name;
i =  0;
while ((i<len(s->members))) {

                    if (s->members->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2891): s->members[%d] with length %d\n", i, s->members->length);
                        exit(1);
                    };
                    struct structMemb* m =  s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_614 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_614->name = "";
____BAH_COMPILER_VAR_614->type = "";
____BAH_COMPILER_VAR_614->isConst = false;
____BAH_COMPILER_VAR_614->constVal = "";
____BAH_COMPILER_VAR_614->isArray = false;
____BAH_COMPILER_VAR_614->from = "";
____BAH_COMPILER_VAR_614->outterScope = false;
____BAH_COMPILER_VAR_614->isGlobal = false;
struct variable* mv =  ____BAH_COMPILER_VAR_614;
mv->name =  m->name;
mv->type =  m->type;
mv->isConst =  false;
mv->isArray =  m->isArray;

{
long nLength = i;
if (ds->membs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ds->membs->data, (nLength+50)*sizeof(struct variable*));
ds->membs->data = newPtr;
}
ds->membs->data[i] =  mv;
ds->membs->length = nLength+1;
} else {
ds->membs->data[i] =  mv;
}
};
i =  i + 1;
};
struct debugStruct* ____BAH_COMPILER_VAR_615 = ds;
char ** ____BAH_COMPILER_VAR_617 = (char **)((char*)(____BAH_COMPILER_VAR_615) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_618 = __reflect(____BAH_COMPILER_VAR_617, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_619 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_615) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_620 = 0;
char ** ____BAH_COMPILER_VAR_622 = (char **)((char*)(____BAH_COMPILER_VAR_620) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_623 = __reflect(____BAH_COMPILER_VAR_622, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_624 = (char **)((char*)(____BAH_COMPILER_VAR_620) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_625 = __reflect(____BAH_COMPILER_VAR_624, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
int* ____BAH_COMPILER_VAR_626 = (int*)((char*)(____BAH_COMPILER_VAR_620) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_627 = __reflect(____BAH_COMPILER_VAR_626, sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_628 = (char **)((char*)(____BAH_COMPILER_VAR_620) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_629 = __reflect(____BAH_COMPILER_VAR_628, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
int* ____BAH_COMPILER_VAR_630 = (int*)((char*)(____BAH_COMPILER_VAR_620) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_631 = __reflect(____BAH_COMPILER_VAR_630, sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_632 = (char **)((char*)(____BAH_COMPILER_VAR_620) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_633 = __reflect(____BAH_COMPILER_VAR_632, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
int* ____BAH_COMPILER_VAR_634 = (int*)((char*)(____BAH_COMPILER_VAR_620) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_635 = __reflect(____BAH_COMPILER_VAR_634, sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
int* ____BAH_COMPILER_VAR_636 = (int*)((char*)(____BAH_COMPILER_VAR_620) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_637 = __reflect(____BAH_COMPILER_VAR_636, sizeof(int), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_621 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_621->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_621->length = 8;
        ____BAH_COMPILER_VAR_621->data = memoryAlloc(____BAH_COMPILER_VAR_621->length * ____BAH_COMPILER_VAR_621->elemSize);
        ____BAH_COMPILER_VAR_621->data[0] = ____BAH_COMPILER_VAR_623;
____BAH_COMPILER_VAR_621->data[1] = ____BAH_COMPILER_VAR_625;
____BAH_COMPILER_VAR_621->data[2] = ____BAH_COMPILER_VAR_627;
____BAH_COMPILER_VAR_621->data[3] = ____BAH_COMPILER_VAR_629;
____BAH_COMPILER_VAR_621->data[4] = ____BAH_COMPILER_VAR_631;
____BAH_COMPILER_VAR_621->data[5] = ____BAH_COMPILER_VAR_633;
____BAH_COMPILER_VAR_621->data[6] = ____BAH_COMPILER_VAR_635;
____BAH_COMPILER_VAR_621->data[7] = ____BAH_COMPILER_VAR_637;
struct reflectElement ____BAH_COMPILER_VAR_638 = __reflect(____BAH_COMPILER_VAR_620, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_621, 0);

        struct reflectElement ____BAH_COMPILER_VAR_639 = ____BAH_COMPILER_VAR_638;
        struct reflectElement ____BAH_COMPILER_VAR_640 = __reflect(____BAH_COMPILER_VAR_619, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_639, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_616 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_616->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_616->length = 2;
        ____BAH_COMPILER_VAR_616->data = memoryAlloc(____BAH_COMPILER_VAR_616->length * ____BAH_COMPILER_VAR_616->elemSize);
        ____BAH_COMPILER_VAR_616->data[0] = ____BAH_COMPILER_VAR_618;
____BAH_COMPILER_VAR_616->data[1] = ____BAH_COMPILER_VAR_640;
struct reflectElement ____BAH_COMPILER_VAR_641 = __reflect(____BAH_COMPILER_VAR_615, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_616, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_641);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2913): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[1];

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2914): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    struct Tok st =  l->data[2];
long int i =  1;
int doesOutput =  true;
if ((strcmp(ft.cont, "!") == 0)) {

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2919): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    ft =  l->data[2];

                    if (l->length <= 3) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2920): l[%d] with length %d\n", 3, l->length);
                        exit(1);
                    };
                    st =  l->data[3];
i =  2;
doesOutput =  false;
}
if ((strcmp(st.cont, "(") == 0)) {
struct func* ____BAH_COMPILER_VAR_642 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_642->name = "";
____BAH_COMPILER_VAR_642->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_642->args->length = 0;
            ____BAH_COMPILER_VAR_642->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_642->returns= null;
____BAH_COMPILER_VAR_642->isBinding = false;
____BAH_COMPILER_VAR_642->from = "";
____BAH_COMPILER_VAR_642->file = "";
____BAH_COMPILER_VAR_642->line = 1;
____BAH_COMPILER_VAR_642->used = false;
____BAH_COMPILER_VAR_642->code = null;
struct func* fn =  ____BAH_COMPILER_VAR_642;
char * code =  parseFnHeader("",l,&i,fn,elems);
array(struct func*)* fns =  elems->fns;
fn->isBinding =  true;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] =  fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] =  fn;
}
};
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_643 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_643 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_643+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_643+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_643));
}
}
else {
char * tp =  "";
i =  i+1;
for (; (i<len(l)); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2939): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
char * ____BAH_COMPILER_VAR_644 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
                    ____BAH_COMPILER_VAR_644 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_644+currStrOff, tp, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_644+currStrOff, t.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tp =  ____BAH_COMPILER_VAR_644;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType =  getCType(tp,elems);
char * cTypeNewTypeStr =  cTypeNewType.str((struct string*)&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_645 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("typedef ");
long int strLen_1 = strlen(cTypeNewTypeStr);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(ft.cont);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_645 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_645+currStrOff, "typedef ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_645+currStrOff, cTypeNewTypeStr, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_645+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_645+currStrOff, ft.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_645+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_645));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_646 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_646->name= null;
____BAH_COMPILER_VAR_646->refers= null;
struct debugType* dt =  ____BAH_COMPILER_VAR_646;
dt->name =  ft.cont;
dt->refers =  tp;
struct debugType* ____BAH_COMPILER_VAR_647 = dt;
char ** ____BAH_COMPILER_VAR_649 = (char **)((char*)(____BAH_COMPILER_VAR_647) + offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_650 = __reflect(____BAH_COMPILER_VAR_649, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
char ** ____BAH_COMPILER_VAR_651 = (char **)((char*)(____BAH_COMPILER_VAR_647) + offsetof(struct debugType, refers));
struct reflectElement ____BAH_COMPILER_VAR_652 = __reflect(____BAH_COMPILER_VAR_651, sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_648 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_648->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_648->length = 2;
        ____BAH_COMPILER_VAR_648->data = memoryAlloc(____BAH_COMPILER_VAR_648->length * ____BAH_COMPILER_VAR_648->elemSize);
        ____BAH_COMPILER_VAR_648->data[0] = ____BAH_COMPILER_VAR_650;
____BAH_COMPILER_VAR_648->data[1] = ____BAH_COMPILER_VAR_652;
struct reflectElement ____BAH_COMPILER_VAR_653 = __reflect(____BAH_COMPILER_VAR_647, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_648, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_653);
}
array(char *)* tps =  elems->types;

{
long nLength = len(tps);
if (tps->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tps->data, (nLength+50)*sizeof(char *));
tps->data = newPtr;
}
tps->data[len(tps)] =  ft.cont;
tps->length = nLength+1;
} else {
tps->data[len(tps)] =  ft.cont;
}
};
}
};
void parseClib(__BAH_ARR_TYPE_Tok line){
array(char *)* clibs =  compilerState.cLibs;
long int i =  1;
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2969): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((t.type!=TOKEN_TYPE_STR)) {
throwErr(&t,"Cannot use {TOKEN} as C library name.");
}
struct string cc =  string(t.cont);
cc.trimLeft((struct string*)&cc,1);
cc.trimRight((struct string*)&cc,1);
char * ccstr =  cc.str((struct string*)&cc);
int found =  false;
long int j =  0;
while ((j<len(clibs))) {

                    if (clibs->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2981): clibs[%d] with length %d\n", j, clibs->length);
                        exit(1);
                    };
                    char * l =  clibs->data[j];
if ((strcmp(l, ccstr) == 0)) {
found =  true;
break;
}
j =  j + 1;
};
if ((found==true)) {
i =  i+1;
continue;
}

{
long nLength = len(clibs);
if (clibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(clibs->data, (nLength+50)*sizeof(char *));
clibs->data = newPtr;
}
clibs->data[len(clibs)] =  ccstr;
clibs->length = nLength+1;
} else {
clibs->data[len(clibs)] =  ccstr;
}
};
i =  i+1;
};
};
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
l =  parseCast(l,elems);
if ((len(l)!=4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3004): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok vart =  l->data[1];

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3005): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    struct Tok equt =  l->data[2];

                    if (l->length <= 3) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3006): l[%d] with length %d\n", 3, l->length);
                        exit(1);
                    };
                    struct Tok valt =  l->data[3];
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
struct func* fn =  searchFunc(valt.cont,elems,true);
if ((fn!=null)) {
fn->used =  true;
}
}
struct variable* ____BAH_COMPILER_VAR_654 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_654->name = "";
____BAH_COMPILER_VAR_654->type = "";
____BAH_COMPILER_VAR_654->isConst = false;
____BAH_COMPILER_VAR_654->constVal = "";
____BAH_COMPILER_VAR_654->isArray = false;
____BAH_COMPILER_VAR_654->from = "";
____BAH_COMPILER_VAR_654->outterScope = false;
____BAH_COMPILER_VAR_654->isGlobal = false;
struct variable* v =  ____BAH_COMPILER_VAR_654;
if (isGlobal()) {
v->isGlobal =  true;
}
v->isConst =  true;
v->constVal =  valt.cont;
v->name =  vart.cont;
v->type =  getTypeFromToken(&valt,true,elems);
array(struct variable*)* vars =  elems->vars;

{
long nLength = len(vars);
if (vars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(vars->data, (nLength+50)*sizeof(struct variable*));
vars->data = newPtr;
}
vars->data[len(vars)] =  v;
vars->length = nLength+1;
} else {
vars->data[len(vars)] =  v;
}
};
char * ____BAH_COMPILER_VAR_655 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(valt.cont);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_655 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_655+currStrOff, "#define ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_655+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_655+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_655+currStrOff, valt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_655+currStrOff, "\n", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_655));
};
void parseReturn(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'return <returnValue>'");
}
if ((currentFn==null)) {
throwErr(&l->data[0],"Cannot return a value outside of a function.");
}
char * rv =  "";
if ((len(l)==1)) {
if ((strlen(currentFn->returns->type)!=0)) {
char * ____BAH_COMPILER_VAR_656 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot return nothing as ");
long int strLen_1 = strlen(currentFn->returns->type);
long int strLen_2 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_656 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_656+currStrOff, "Cannot return nothing as ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_656+currStrOff, currentFn->returns->type, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_656+currStrOff, ".", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&l->data[0],____BAH_COMPILER_VAR_656);
}
}
else {

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3056): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok rvt =  l->data[1];
if ((rvt.isValue==false)) {
throwErr(&rvt,"Must be a value, not {TOKEN}.");
}
else if (((rvt.type==TOKEN_TYPE_VAR)&&(rvt.isOper==false))) {
struct variable* v =  searchVar(rvt.cont,elems);
if (((((v!=null)&&(isRCPtype(v->type,elems)==true))&&(v->outterScope==false))&&(RCPavailable()==true))) {
OUTPUT =  OUTPUT->add(OUTPUT, incrVar(v,elems));
}
}
rv =  rvt.cont;
char * tt =  getTypeFromToken(&rvt,true,elems);
if ((compTypes(tt,currentFn->returns->type)==false)) {
char * ____BAH_COMPILER_VAR_657 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot return {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(currentFn->returns->type);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_657 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_657+currStrOff, "Cannot return {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_657+currStrOff, tt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_657+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_657+currStrOff, currentFn->returns->type, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_657+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&rvt,____BAH_COMPILER_VAR_657);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned =  true;
}
if ((strlen(rv)>0)) {
char * rvar =  rv;
if (((RCPavailable()==true)&&isRCPpointerType(currentFn->returns->type))) {
rvar =  genCompilerVar();
struct string cType =  getCType(currentFn->returns->type,elems);
char * ____BAH_COMPILER_VAR_658 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_659 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_658);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvar);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(rv);
long int strLen_5 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_659 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_659+currStrOff, ____BAH_COMPILER_VAR_658, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_659+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_659+currStrOff, rvar, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_659+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_659+currStrOff, rv, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_659+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_659));
}
endRCPnonGlobScope(elems,currentFn->args);
char * ____BAH_COMPILER_VAR_660 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("return ");
long int strLen_1 = strlen(rvar);
long int strLen_2 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_660 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_660+currStrOff, "return ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_660+currStrOff, rvar, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_660+currStrOff, ";\n", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_660));
}
else {
endRCPnonGlobScope(elems,currentFn->args);
OUTPUT =  OUTPUT->add(OUTPUT, rope("return;\n"));
}
};
void parseIf(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3093): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3096): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3102): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[2];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in if statement.");
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
long int i =  3;
while ((i<max)) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3109): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
}
};
i =  i+1;
};
char * ____BAH_COMPILER_VAR_661 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("if (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_661 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_661+currStrOff, "if (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_661+currStrOff, condt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_661+currStrOff, ") {\n", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_661));
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(tokens,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                    if (l->length <= len(l)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3122): l[%d] with length %d\n", len(l)-1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isBranch =  oldIB;
OUTPUT =  OUTPUT->add(OUTPUT, rope("}\n"));
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
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3141): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[1];
OUTPUT =  OUTPUT->add(OUTPUT, rope("else "));
if ((strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int i =  1;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3146): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    
{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  l->data[i];
}
};
i =  i+1;
};
parseIf(memory,elems);
prevLine =  LINE_TYPE_IF;
}
else {
if ((strcmp(ft.cont, "{") != 0)) {
throwErr(&ft,"Expected 'if' or '{' not {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
long int i =  2;
while ((i<max)) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3159): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    
{
long nLength = len(memory);
if (memory->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(memory->data, (nLength+50)*sizeof(struct Tok));
memory->data = newPtr;
}
memory->data[len(memory)] =  l->data[i];
memory->length = nLength+1;
} else {
memory->data[len(memory)] =  l->data[i];
}
};
i =  i+1;
};
OUTPUT =  OUTPUT->add(OUTPUT, rope("{\n"));
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(memory,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                    if (l->length <= len(l)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3170): l[%d] with length %d\n", len(l)-1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isBranch =  oldIB;
OUTPUT =  OUTPUT->add(OUTPUT, rope("}\n"));
}
};
void parseLine(__BAH_ARR_TYPE_Tok l,struct Elems* elems);
void parseFor(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}
long int nbComas =  0;
long int i =  1;
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3189): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
if (((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, ",") == 0))) {
if ((nbComas==1)) {
throwErr(&t,"Invalid line separation of for, cannot set more than 2 lines: {TOKEN}.");
}
nbComas =  nbComas + 1;
}
i =  i + 1;
};
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
if ((nbComas>0)) {
if ((nbComas!=1)) {

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3205): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[0];
throwErr(&t,"Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3210): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3218): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    struct Tok st =  l->data[2];
if (((st.type!=TOKEN_TYPE_SYNTAX)||(strcmp(st.cont, ",") != 0))) {
throwErr(&st,"Cannot use {TOKEN}, need ',' to split for loop instructions.");
}
i =  3;
for (; (i<len(l)); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3225): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
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
inst->data[len(inst)] =  t;
inst->length = nLength+1;
} else {
inst->data[len(inst)] =  t;
}
};
};
struct rope* oldOut =  OUTPUT;
OUTPUT =  rope("");
parseLine(inst,elems);
char * ____BAH_COMPILER_VAR_662 =OUTPUT->toStr((struct rope*)OUTPUT);struct string instC =  string(____BAH_COMPILER_VAR_662);
OUTPUT =  oldOut;
instC.trimRight((struct string*)&instC,2);

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3241): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}
long int max =  len(l) - 1;
i =  i + 1;
for (; (i<max); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3248): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
}
};
};
char * ____BAH_COMPILER_VAR_663 =instC.str((struct string*)&instC);char * ____BAH_COMPILER_VAR_664 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("for (; ");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen("; ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_663);
long int strLen_4 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_664 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_664+currStrOff, "for (; ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_664+currStrOff, condt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_664+currStrOff, "; ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_664+currStrOff, ____BAH_COMPILER_VAR_663, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_664+currStrOff, ") {\n", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_664));
}
else {

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3255): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                    if (l->length <= 2) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3261): l[%d] with length %d\n", 2, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[2];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}
long int max =  len(l) - 1;
i =  3;
for (; (i<max); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3267): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
}
};
};
char * ____BAH_COMPILER_VAR_665 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("while (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                    ____BAH_COMPILER_VAR_665 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_665+currStrOff, "while (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_665+currStrOff, condt.cont, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_665+currStrOff, ") {\n", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_665));
}
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
int oldIF =  compilerState.isFor;
compilerState.isBranch =  true;
compilerState.isFor =  true;
parseLines(tokens,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                    if (l->length <= len(l)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3281): l[%d] with length %d\n", len(l)-1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[len(l)-1];
debugEndScope(lt.line,ifElems);
}
compilerState.isFor =  oldIF;
compilerState.isBranch =  oldIB;
OUTPUT =  OUTPUT->add(OUTPUT, rope("};\n"));
};
void parseForOp(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3292): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
if ((compilerState.isFor==false)) {
throwErr(&ft,"Cannot {TOKEN} outside of for statement.");
}
if ((len(l)!=1)) {
throwErr(&ft,"Nothing expected after {TOKEN}.");
}
endRCPscope(elems,null);
char * ____BAH_COMPILER_VAR_666 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_666 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_666+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_666+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_666));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

                int ____BAH_COMPILER_VAR_667 = 0;
                for(int i=len(compilerState.evals)-1; i != -1; i--) {
                    if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                        ____BAH_COMPILER_VAR_667 = 1;
                        break;
                    };
                };
                if (____BAH_COMPILER_VAR_667) {
return;
}
char * ____BAH_COMPILER_VAR_668 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("__Bah_eval_");
long int strLen_1 = strlen(fn->name);
;                            
                    ____BAH_COMPILER_VAR_668 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_668+currStrOff, "__Bah_eval_", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_668+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                struct func* ____BAH_COMPILER_VAR_669 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_669->name = "";
____BAH_COMPILER_VAR_669->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_669->args->length = 0;
            ____BAH_COMPILER_VAR_669->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_669->returns= null;
____BAH_COMPILER_VAR_669->isBinding = false;
____BAH_COMPILER_VAR_669->from = "";
____BAH_COMPILER_VAR_669->file = "";
____BAH_COMPILER_VAR_669->line = 1;
____BAH_COMPILER_VAR_669->used = false;
____BAH_COMPILER_VAR_669->code = null;
____BAH_COMPILER_VAR_669->name = ____BAH_COMPILER_VAR_668;
struct func* efn =  ____BAH_COMPILER_VAR_669;
struct variable* ____BAH_COMPILER_VAR_670 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_670->name = "";
____BAH_COMPILER_VAR_670->type = "";
____BAH_COMPILER_VAR_670->isConst = false;
____BAH_COMPILER_VAR_670->constVal = "";
____BAH_COMPILER_VAR_670->isArray = false;
____BAH_COMPILER_VAR_670->from = "";
____BAH_COMPILER_VAR_670->outterScope = false;
____BAH_COMPILER_VAR_670->isGlobal = false;
____BAH_COMPILER_VAR_670->type = "ptr";
efn->returns =  ____BAH_COMPILER_VAR_670;
struct variable* ____BAH_COMPILER_VAR_671 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_671->name = "";
____BAH_COMPILER_VAR_671->type = "";
____BAH_COMPILER_VAR_671->isConst = false;
____BAH_COMPILER_VAR_671->constVal = "";
____BAH_COMPILER_VAR_671->isArray = false;
____BAH_COMPILER_VAR_671->from = "";
____BAH_COMPILER_VAR_671->outterScope = false;
____BAH_COMPILER_VAR_671->isGlobal = false;
____BAH_COMPILER_VAR_671->name = "fnArgs";
____BAH_COMPILER_VAR_671->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);efn->args->data[0] = ____BAH_COMPILER_VAR_671;
char * fnBinding =  "";
char * ____BAH_COMPILER_VAR_672 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
                    ____BAH_COMPILER_VAR_672 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_672+currStrOff, fn->name, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_672+currStrOff, "(", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * fnCall =  ____BAH_COMPILER_VAR_672;
long int i =  0;
for (; (i<len(fn->args)); i =  i+1) {

                    if (fn->args->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3327): fn->args[%d] with length %d\n", i, fn->args->length);
                        exit(1);
                    };
                    struct variable* a =  fn->args->data[i];
char * v =  genCompilerVar();
struct string cType =  getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
cType.append((struct string*)&cType,"*");
}
char * ____BAH_COMPILER_VAR_673 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_674 =intToStr(i);char * ____BAH_COMPILER_VAR_675 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_673);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v);
long int strLen_3 = strlen(" = fnArgs->data[");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_674);
long int strLen_5 = strlen("];");
;                            
                    ____BAH_COMPILER_VAR_675 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_675+currStrOff, ____BAH_COMPILER_VAR_673, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_675+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_675+currStrOff, v, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_675+currStrOff, " = fnArgs->data[", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_675+currStrOff, ____BAH_COMPILER_VAR_674, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_675+currStrOff, "];", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                char * ____BAH_COMPILER_VAR_676 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnBinding);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_675);
;                            
                    ____BAH_COMPILER_VAR_676 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_676+currStrOff, fnBinding, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_676+currStrOff, ____BAH_COMPILER_VAR_675, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fnBinding =  ____BAH_COMPILER_VAR_676;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_677 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_677 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_677+currStrOff, fnCall, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_677+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fnCall =  ____BAH_COMPILER_VAR_677;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_678 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(v);
;                            
                    ____BAH_COMPILER_VAR_678 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_678+currStrOff, fnCall, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_678+currStrOff, v, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fnCall =  ____BAH_COMPILER_VAR_678;
}
else {
char * ____BAH_COMPILER_VAR_679 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*");
long int strLen_1 = strlen(v);
;                            
                    ____BAH_COMPILER_VAR_679 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_679+currStrOff, "*", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_679+currStrOff, v, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * ____BAH_COMPILER_VAR_680 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fnCall);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_679);
;                            
                    ____BAH_COMPILER_VAR_680 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_680+currStrOff, fnCall, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_680+currStrOff, ____BAH_COMPILER_VAR_679, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fnCall =  ____BAH_COMPILER_VAR_680;
}
};
char * setReturnValue =  "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue =  "void* r = ";
}
else {
struct string cType =  getCType(fn->returns->type,elems);
if ((strcmp(cType.str((struct string*)&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_681 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_682 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_683 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_681);
long int strLen_1 = strlen("* r = memoryAlloc(sizeof(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_682);
long int strLen_3 = strlen("));*r = ");
;                            
                    ____BAH_COMPILER_VAR_683 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_683+currStrOff, ____BAH_COMPILER_VAR_681, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_683+currStrOff, "* r = memoryAlloc(sizeof(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_683+currStrOff, ____BAH_COMPILER_VAR_682, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_683+currStrOff, "));*r = ", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                setReturnValue =  ____BAH_COMPILER_VAR_683;
}
}
char * ____BAH_COMPILER_VAR_684 =intToStr(len(fn->args));char * ____BAH_COMPILER_VAR_685 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("void* __attribute__((optimize(\"O0\"))) ");
long int strLen_1 = strlen(efn->name);
long int strLen_2 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_684);
long int strLen_4 = strlen(") {\n            __BAH_panic(\"eval: calling function ");
long int strLen_5 = strlen(fn->name);
long int strLen_6 = strlen("() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ");
long int strLen_7 = strlen(fnBinding);
long int strLen_8 = strlen("\n        ");
long int strLen_9 = strlen(setReturnValue);
long int strLen_10 = strlen(fnCall);
long int strLen_11 = strlen(");\n        return (void*)r;\n    };");
;                            
                    ____BAH_COMPILER_VAR_685 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11);
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, efn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, ____BAH_COMPILER_VAR_684, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, ") {\n            __BAH_panic(\"eval: calling function ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, fn->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, fnBinding, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, "\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, setReturnValue, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, fnCall, strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_685+currStrOff, ");\n        return (void*)r;\n    };", strLen_11);
                    currStrOff += strLen_11;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_685));

{
long nLength = len(compilerState.evals);
if (compilerState.evals->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.evals->data, (nLength+50)*sizeof(char *));
compilerState.evals->data = newPtr;
}
compilerState.evals->data[len(compilerState.evals)] =  fn->name;
compilerState.evals->length = nLength+1;
} else {
compilerState.evals->data[len(compilerState.evals)] =  fn->name;
}
};

{
long nLength = len(elems->fns);
if (elems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->fns->data, (nLength+50)*sizeof(struct func*));
elems->fns->data = newPtr;
}
elems->fns->data[len(elems->fns)] =  efn;
elems->fns->length = nLength+1;
} else {
elems->fns->data[len(elems->fns)] =  efn;
}
};
};
void parsePreKeyword(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3369): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
if ((strcmp(ft.cont, "#warning") == 0)) {
if ((len(l)!=2)) {
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3375): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok mt =  l->data[1];
if ((mt.type!=TOKEN_TYPE_STR)) {
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}
struct string msg =  string(mt.cont);
msg.trimLeft((struct string*)&msg,1);
msg.trimRight((struct string*)&msg,1);
char * ____BAH_COMPILER_VAR_686 =msg.str((struct string*)&msg);throwWarning(____BAH_COMPILER_VAR_686);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

                int ____BAH_COMPILER_VAR_687 = 0;
                for(int i=len(compilerState.includes)-1; i != -1; i--) {
                    if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                        ____BAH_COMPILER_VAR_687 = 1;
                        break;
                    };
                };
                if ((____BAH_COMPILER_VAR_687==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_688 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_688 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_688+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_688+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_688+currStrOff, ").", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&l->data[0],____BAH_COMPILER_VAR_688);
}
}
if (((len(l)!=2)||(isGlobal()==false))) {
throwErr(&l->data[0],"Invalid usage of {TOKEN} <#eval fnName>.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3402): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok fnT =  l->data[1];
struct func* fn =  searchFunc(fnT.cont,elems,false);
if ((fn==null)) {
throwErr(&fnT,"Unknown function {TOKEN}.");
}
fn->used =  true;
makeEvalFunc(fn,elems);
return;
}
if ((strcmp(ft.cont, "#evalAll") == 0)) {
long int i =  0;
for (; (i<len(elems->fns)); i =  i+1) {

                    if (elems->fns->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3416): elems->fns[%d] with length %d\n", i, elems->fns->length);
                        exit(1);
                    };
                    struct func* fn =  elems->fns->data[i];
fn->used =  true;
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
struct string isOS =  string(ft.cont);
isOS.trimLeft((struct string*)&isOS,1);
if ((strcmp(isOS.str((struct string*)&isOS), BAH_OS) != 0)) {
return;
}
}
else if ((strcmp(ft.cont, "#static") == 0)) {
if ((flags.isSet((struct flags*)&flags,"d")==1)) {
return;
}
}
else if ((strcmp(ft.cont, "#dynamic") == 0)) {
if ((flags.isSet((struct flags*)&flags,"d")==0)) {
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
if ((flags.isSet((struct flags*)&flags,"l")==0)) {
return;
}
}
else if ((strcmp(ft.cont, "#exec") == 0)) {
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
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
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3471): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok st =  l->data[1];

                    if (l->length <= len(l)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3472): l[%d] with length %d\n", len(l)-1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[len(l)-1];
if (((strcmp(st.cont, "{") != 0)||(strcmp(lt.cont, "}") != 0))) {
throwErr(&st,"Expected code block after keyword {TOKEN}.");
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  2;
while ((i<len(l) - 1)) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3479): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    
{
long nLength = i-2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[i-2] =  l->data[i];
nl->length = nLength+1;
} else {
nl->data[i-2] =  l->data[i];
}
};
i =  i + 1;
};
parseLines(nl,elems);
};
void parseAsync(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)!=2)) {

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3489): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}

                    if (l->length <= 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3492): l[%d] with length %d\n", 1, l->length);
                        exit(1);
                    };
                    struct Tok fnT =  l->data[1];
if ((fnT.isFunc==false)) {
throwErr(&fnT,"Cannot use keyword async on {TOKEN}. Usage: 'async <function call>'.");
}
int found =  false;
long int i =  0;
while ((i<len(compilerState.cLibs))) {

                    if (compilerState.cLibs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3499): compilerState.cLibs[%d] with length %d\n", i, compilerState.cLibs->length);
                        exit(1);
                    };
                    if ((strcmp(compilerState.cLibs->data[i], "lpthread") == 0)) {
found =  true;
break;
}
i =  i + 1;
};
if ((found==false)) {

{
long nLength = len(compilerState.cLibs);
if (compilerState.cLibs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.cLibs->data, (nLength+50)*sizeof(char *));
compilerState.cLibs->data = newPtr;
}
compilerState.cLibs->data[len(compilerState.cLibs)] =  "lpthread";
compilerState.cLibs->length = nLength+1;
} else {
compilerState.cLibs->data[len(compilerState.cLibs)] =  "lpthread";
}
};
}
struct string sFnT =  string(fnT.cont);
array(struct string)* fnNameParts =  splitString(sFnT,"(");

                    if (fnNameParts->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3512): fnNameParts[%d] with length %d\n", 0, fnNameParts->length);
                        exit(1);
                    };
                    struct string fnName =  fnNameParts->data[0];
char * ____BAH_COMPILER_VAR_689 =fnName.str((struct string*)&fnName);struct func* fn =  searchFunc(____BAH_COMPILER_VAR_689,elems,true);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_690 =fnName.str((struct string*)&fnName);char * ____BAH_COMPILER_VAR_691 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Internal compiler error.\n Error parsing async call for function '");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_690);
long int strLen_2 = strlen("', arround {TOKEN}.");
;                            
                    ____BAH_COMPILER_VAR_691 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_691+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_691+currStrOff, ____BAH_COMPILER_VAR_690, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_691+currStrOff, "', arround {TOKEN}.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&fnT,____BAH_COMPILER_VAR_691);
}
char * sMembs =  "";
char * unSerMembs =  "";
i =  0;
while ((i<len(fn->args))) {

                    if (fn->args->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3523): fn->args[%d] with length %d\n", i, fn->args->length);
                        exit(1);
                    };
                    struct variable* a =  fn->args->data[i];
struct string cType =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_692 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_693 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(sMembs);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_692);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(a->name);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_693 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_693+currStrOff, sMembs, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_693+currStrOff, ____BAH_COMPILER_VAR_692, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_693+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_693+currStrOff, a->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_693+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                sMembs =  ____BAH_COMPILER_VAR_693;
char * ____BAH_COMPILER_VAR_694 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen("args->");
long int strLen_2 = strlen(a->name);
;                            
                    ____BAH_COMPILER_VAR_694 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_694+currStrOff, unSerMembs, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_694+currStrOff, "args->", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_694+currStrOff, a->name, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                unSerMembs =  ____BAH_COMPILER_VAR_694;
i =  i + 1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_695 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_695 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_695+currStrOff, unSerMembs, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_695+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                unSerMembs =  ____BAH_COMPILER_VAR_695;
}
};
char * ____BAH_COMPILER_VAR_696 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("struct {\n");
long int strLen_1 = strlen(sMembs);
long int strLen_2 = strlen("}");
;                            
                    ____BAH_COMPILER_VAR_696 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_696+currStrOff, "struct {\n", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_696+currStrOff, sMembs, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_696+currStrOff, "}", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                char * tmpArgsStruct =  ____BAH_COMPILER_VAR_696;
char * fnWrapper =  genCompilerVar();
char * tmpArgs =  genCompilerVar();
sFnT.trimLeft((struct string*)&sFnT,fnName.length + 1);
sFnT.trimRight((struct string*)&sFnT,1);
char * tCreate =  "";
if ((strcmp(BAH_OS, "windows") == 0)) {
tCreate =  "pthread_create";
}
else {
if (RCPavailable()) {
tCreate =  "pthread_create";
}
else {
tCreate =  "GC_pthread_create";
}
}
char * ____BAH_COMPILER_VAR_697 =fnName.str((struct string*)&fnName);char * ____BAH_COMPILER_VAR_698 =sFnT.str((struct string*)&sFnT);char * ____BAH_COMPILER_VAR_699 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n    void ");
long int strLen_1 = strlen(fnWrapper);
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(tmpArgsStruct);
long int strLen_4 = strlen("* args) {\n        ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_697);
long int strLen_6 = strlen("(");
long int strLen_7 = strlen(unSerMembs);
long int strLen_8 = strlen(");\n    };\n    {\n        ");
long int strLen_9 = strlen(tmpArgsStruct);
long int strLen_10 = strlen(" ");
long int strLen_11 = strlen(tmpArgs);
long int strLen_12 = strlen(" = {");
long int strLen_13 = strlen(____BAH_COMPILER_VAR_698);
long int strLen_14 = strlen("};\n        pthread_t id;\n        ");
long int strLen_15 = strlen(tCreate);
long int strLen_16 = strlen("(&id, 0, ");
long int strLen_17 = strlen(fnWrapper);
long int strLen_18 = strlen(", &");
long int strLen_19 = strlen(tmpArgs);
long int strLen_20 = strlen(");\n    }; \n    \n    ");
;                            
                    ____BAH_COMPILER_VAR_699 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20);
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, "\n    void ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, fnWrapper, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, tmpArgsStruct, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, "* args) {\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, ____BAH_COMPILER_VAR_697, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, unSerMembs, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, ");\n    };\n    {\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, tmpArgsStruct, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, tmpArgs, strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, " = {", strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, ____BAH_COMPILER_VAR_698, strLen_13);
                    currStrOff += strLen_13;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, "};\n        pthread_t id;\n        ", strLen_14);
                    currStrOff += strLen_14;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, tCreate, strLen_15);
                    currStrOff += strLen_15;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, "(&id, 0, ", strLen_16);
                    currStrOff += strLen_16;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, fnWrapper, strLen_17);
                    currStrOff += strLen_17;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, ", &", strLen_18);
                    currStrOff += strLen_18;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, tmpArgs, strLen_19);
                    currStrOff += strLen_19;
                    
                    strncpy(____BAH_COMPILER_VAR_699+currStrOff, ");\n    }; \n    \n    ", strLen_20);
                    currStrOff += strLen_20;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_699));
};
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
long int i =  0;
if ((ltp==LINE_TYPE_VAR)) {
i =  1;
}
while ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3570): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
struct variable* v =  searchVar(t.cont,elems);
if ((v!=null)) {

{
long nLength = len(compilerState.RCPvars);
if (compilerState.RCPvars->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.RCPvars->data, (nLength+50)*sizeof(struct variable*));
compilerState.RCPvars->data = newPtr;
}
compilerState.RCPvars->data[len(compilerState.RCPvars)] =  v;
compilerState.RCPvars->length = nLength+1;
} else {
compilerState.RCPvars->data[len(compilerState.RCPvars)] =  v;
}
};
}
}
i =  i + 1;
};
};
__BAH_ARR_TYPE_Tok parseChan(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
for (; (i<len(l)); i =  i+1) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3586): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];
if ((((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "->") == 0))||(strcmp(t.cont, "<-") == 0))) {
if ((strcmp(t.cont, "<-") == 0)) {
i =  i+1;
if ((i<len(l))) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3592): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_700 =getTypeFromToken(&nt,true,elems);struct string ntt =  string(____BAH_COMPILER_VAR_700);
if ((ntt.hasPrefix((struct string*)&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_701 =ntt.str((struct string*)&ntt);char * ____BAH_COMPILER_VAR_702 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use var {TOKEN} (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_701);
long int strLen_2 = strlen(") as channel.");
;                            
                    ____BAH_COMPILER_VAR_702 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_702+currStrOff, "Cannot use var {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_702+currStrOff, ____BAH_COMPILER_VAR_701, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_702+currStrOff, ") as channel.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&nt,____BAH_COMPILER_VAR_702);
}
ntt.trimLeft((struct string*)&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV =  "";
char * ____BAH_COMPILER_VAR_703 =ntt.str((struct string*)&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_703)) {
char * ____BAH_COMPILER_VAR_704 =ntt.str((struct string*)&ntt);struct string ct =  getCType(____BAH_COMPILER_VAR_704,elems);
char * ____BAH_COMPILER_VAR_705 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_706 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_705);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_706 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_706+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_706+currStrOff, ____BAH_COMPILER_VAR_705, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_706+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_706+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_706+currStrOff, "->receive(", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_706+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_706+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_706;
}
else {
char * ____BAH_COMPILER_VAR_707 =ntt.str((struct string*)&ntt);struct string ct =  getCType(____BAH_COMPILER_VAR_707,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_708 =ntt.str((struct string*)&ntt);char * ____BAH_COMPILER_VAR_709 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_708);
long int strLen_1 = strlen("*");
;                            
                    ____BAH_COMPILER_VAR_709 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_709+currStrOff, ____BAH_COMPILER_VAR_708, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_709+currStrOff, "*", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                char * ____BAH_COMPILER_VAR_710 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_711 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_710);
long int strLen_2 = strlen("*)");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_711 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_711+currStrOff, "(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_711+currStrOff, ____BAH_COMPILER_VAR_710, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_711+currStrOff, "*)", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_711+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_711+currStrOff, "->receive(", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_711+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_711+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                tmpV =  registerRCPvar(____BAH_COMPILER_VAR_709,____BAH_COMPILER_VAR_711,elems);
char * ____BAH_COMPILER_VAR_712 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*");
long int strLen_1 = strlen(tmpV);
;                            
                    ____BAH_COMPILER_VAR_712 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_712+currStrOff, "*", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_712+currStrOff, tmpV, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_712;
}
else {
char * ____BAH_COMPILER_VAR_713 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_714 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_713);
long int strLen_2 = strlen("*)");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                    ____BAH_COMPILER_VAR_714 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_714+currStrOff, "*(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_714+currStrOff, ____BAH_COMPILER_VAR_713, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_714+currStrOff, "*)", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_714+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_714+currStrOff, "->receive(", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_714+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_714+currStrOff, ")", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                t.cont =  ____BAH_COMPILER_VAR_714;
}
}
t.type =  TOKEN_TYPE_FUNC;
t.isFunc =  true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_715 =ntt.str((struct string*)&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_715)) {
char * ____BAH_COMPILER_VAR_716 =ntt.str((struct string*)&ntt);tmpV =  registerRCPvar(____BAH_COMPILER_VAR_716,t.cont,elems);
t.type =  TOKEN_TYPE_VAR;
t.isFunc =  false;
t.cont =  tmpV;
}
else {
}
}
t.isValue =  true;
t.bahType =  ntt.str((struct string*)&ntt);
}
else {
throwErr(&t,"Cannot use {TOKEN} on nothing");
}
}
else {
if ((i==0)) {
throwErr(&t,"Cannot une {TOKEN} on nothing.");
}
if ((i + 1>=len(l))) {
throwErr(&t,"Cannot send ({TOKEN}) to nothing.");
}

                    if (l->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3646): l[%d] with length %d\n", i + 1, l->length);
                        exit(1);
                    };
                    struct Tok pt =  l->data[i + 1];

                    if (l->length <= i-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3647): l[%d] with length %d\n", i-1, l->length);
                        exit(1);
                    };
                    struct Tok nt =  l->data[i-1];
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((pt.type!=TOKEN_TYPE_VAR)) {
throwErr(&pt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_717 =getTypeFromToken(&pt,true,elems);struct string ptt =  string(____BAH_COMPILER_VAR_717);
if ((ptt.hasPrefix((struct string*)&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_718 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot use var {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as channel.");
;                            
                    ____BAH_COMPILER_VAR_718 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_718+currStrOff, "Cannot use var {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_718+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_718+currStrOff, ") as channel.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&pt,____BAH_COMPILER_VAR_718);
}
ptt.trimLeft((struct string*)&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_719 =ptt.str((struct string*)&ptt);if ((compTypes(____BAH_COMPILER_VAR_719,ntt)==false)) {
char * ____BAH_COMPILER_VAR_720 =ptt.str((struct string*)&ptt);char * ____BAH_COMPILER_VAR_721 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot send {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to channel of type ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_720);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_721 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_721+currStrOff, "Cannot send {TOKEN} (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_721+currStrOff, ntt, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_721+currStrOff, ") to channel of type ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_721+currStrOff, ____BAH_COMPILER_VAR_720, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_721+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&nt,____BAH_COMPILER_VAR_721);
}
i =  i+1;
char * ____BAH_COMPILER_VAR_722 =ptt.str((struct string*)&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_722)) {
char * ____BAH_COMPILER_VAR_723 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen("->send(");
long int strLen_2 = strlen(pt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(nt.cont);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_723+currStrOff, pt.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_723+currStrOff, "->send(", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_723+currStrOff, pt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_723+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_723+currStrOff, nt.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_723+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_723));
}
else {
struct string ct =  getCType(ntt,elems);
char * tmpV =  genCompilerVar();
char * ____BAH_COMPILER_VAR_724 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_725 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\n                    ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_724);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(tmpV);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(";\n                    ");
long int strLen_7 = strlen(pt.cont);
long int strLen_8 = strlen("->sendAny(");
long int strLen_9 = strlen(pt.cont);
long int strLen_10 = strlen(", &");
long int strLen_11 = strlen(tmpV);
long int strLen_12 = strlen(", sizeof(");
long int strLen_13 = strlen(tmpV);
long int strLen_14 = strlen("));\n");
;                            
                    ____BAH_COMPILER_VAR_725 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, "\n                    ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, ____BAH_COMPILER_VAR_724, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, ";\n                    ", strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, "->sendAny(", strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, pt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, ", &", strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, ", sizeof(", strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, tmpV, strLen_13);
                    currStrOff += strLen_13;
                    
                    strncpy(____BAH_COMPILER_VAR_725+currStrOff, "));\n", strLen_14);
                    currStrOff += strLen_14;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_725));
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
nl->data[len(nl)] =  t;
nl->length = nLength+1;
} else {
nl->data[len(nl)] =  t;
}
};
};
return nl;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){
array(struct Tok)* fl = memoryAlloc(sizeof(array(struct Tok)));

fl->length = 0;
fl->elemSize = sizeof(struct Tok);
long int i =  0;
long int nbPar =  0;
if ((ltp!=(lineType)-1)) {
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3694): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    struct Tok t =  line->data[i];
if ((strcmp(t.cont, "(") == 0)) {
nbPar =  nbPar + 1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbPar =  nbPar - 1;
}
else if (((nbPar==0)&&(strcmp(t.cont, "{") == 0))) {

                    if (line->length <= i + 1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3700): line[%d] with length %d\n", i + 1, line->length);
                        exit(1);
                    };
                    struct Tok nt =  line->data[i + 1];
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
fl->data[len(fl)] =  t;
fl->length = nLength+1;
} else {
fl->data[len(fl)] =  t;
}
};
i =  i+1;
};
}
else {
fl =  line;
}
fl =  parseStructVars(fl,elems);
fl =  parseFnCall(fl,ltp,elems);
fl =  parseArrayVars(fl,ltp,elems);
fl =  parseArrayType(fl,elems);
fl =  parseStructType(fl,ltp,elems);
fl =  parseCast(fl,elems);
addRCPvars(fl,ltp,elems);
fl =  parseOperations(fl,ltp,elems);
fl =  parseBool(fl,elems);
fl =  parseChan(fl,elems);
if ((ltp!=(lineType)-1)) {
while ((i<len(line))) {

                    if (line->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3725): line[%d] with length %d\n", i, line->length);
                        exit(1);
                    };
                    
{
long nLength = len(fl);
if (fl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fl->data, (nLength+50)*sizeof(struct Tok));
fl->data = newPtr;
}
fl->data[len(fl)] =  line->data[i];
fl->length = nLength+1;
} else {
fl->data[len(fl)] =  line->data[i];
}
};
i =  i+1;
};
}
return fl;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i =  0;
struct func* ____BAH_COMPILER_VAR_726 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_726->name = "";
____BAH_COMPILER_VAR_726->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_726->args->length = 0;
            ____BAH_COMPILER_VAR_726->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_726->returns= null;
____BAH_COMPILER_VAR_726->isBinding = false;
____BAH_COMPILER_VAR_726->from = "";
____BAH_COMPILER_VAR_726->file = "";
____BAH_COMPILER_VAR_726->line = 1;
____BAH_COMPILER_VAR_726->used = false;
____BAH_COMPILER_VAR_726->code = null;
struct func* fn =  ____BAH_COMPILER_VAR_726;
if (((RCPavailable()==false)&&(RCPenabled==true))) {
fn->used =  true;
}

                    if (l->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3742): l[%d] with length %d\n", 0, l->length);
                        exit(1);
                    };
                    struct Tok ft =  l->data[0];
char * code =  parseFnHeader("",l,&i,fn,elems);
fn->line =  ft.line;
fn->file =  compilerState.currentFile;
struct func* ogFn =  searchFunc(fn->name,elems,false);
if ((ogFn!=null)) {
if ((ogFn->isBinding==false)) {
char * lineStr =  intToStr(ogFn->line);
char * ____BAH_COMPILER_VAR_727 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
long int strLen_1 = strlen(ogFn->file);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(lineStr);
long int strLen_4 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_727 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_727+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_727+currStrOff, ogFn->file, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_727+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_727+currStrOff, lineStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_727+currStrOff, ".", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                throwErr(&ft,____BAH_COMPILER_VAR_727);
}
}
if ((strcmp(fn->name, "main") == 0)) {
compilerState.haveEntryPoint =  true;
if ((compTypes(fn->returns->type,"int")==false)) {
throwErr(&ft,"{TOKEN} function should return 'int'.");
}
if ((len(fn->args)!=1)) {
throwErr(&ft,"{TOKEN} function should take one []cpstring argument. Should be: \n            'main(args []cpstring) int'");
}

                    if (fn->args->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3763): fn->args[%d] with length %d\n", 0, fn->args->length);
                        exit(1);
                    };
                    struct variable* fa =  fn->args->data[0];
if ((compTypes(fa->type,"[]cpstring")==false)) {
throwErr(&ft,"{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}
if ((shouldOnlyDecl==true)) {
if ((ogFn!=null)) {
fn->isBinding =  false;
}

{
long nLength = len(elems->fns);
if (elems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(elems->fns->data, (nLength+50)*sizeof(struct func*));
elems->fns->data = newPtr;
}
elems->fns->data[len(elems->fns)] =  fn;
elems->fns->length = nLength+1;
} else {
elems->fns->data[len(elems->fns)] =  fn;
}
};
char * ____BAH_COMPILER_VAR_728 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_728 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_728+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_728+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_728));
return;
}
char * ____BAH_COMPILER_VAR_729 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(code);
long int strLen_1 = strlen("{\n");
;                            
                    ____BAH_COMPILER_VAR_729 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_729+currStrOff, code, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_729+currStrOff, "{\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                code =  ____BAH_COMPILER_VAR_729;
fn->code =  rope(code);
struct Elems* fnElems =  dupElems(elems);
array(struct variable*)* vs =  fnElems->vars;
long int j =  0;
while ((j<len(fn->args))) {

                    if (fn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3788): fn->args[%d] with length %d\n", j, fn->args->length);
                        exit(1);
                    };
                    struct variable* a =  fn->args->data[j];
a->outterScope =  true;

{
long nLength = len(vs);
if (vs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(vs->data, (nLength+50)*sizeof(struct variable*));
vs->data = newPtr;
}
vs->data[len(vs)] =  a;
vs->length = nLength+1;
} else {
vs->data[len(vs)] =  a;
}
};
j =  j + 1;
};
fnElems->vars =  vs;
if ((ogFn!=null)) {
ogFn->isBinding =  false;
ogFn->used =  true;
ogFn =  fn;
}
else {
array(struct func*)* fns =  elems->fns;

{
long nLength = len(fns);
if (fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(fns->data, (nLength+50)*sizeof(struct func*));
fns->data = newPtr;
}
fns->data[len(fns)] =  fn;
fns->length = nLength+1;
} else {
fns->data[len(fns)] =  fn;
}
};
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
i =  i+1;
long int max =  len(l)-1;
while ((i<max)) {

                    if (l->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3808): l[%d] with length %d\n", i, l->length);
                        exit(1);
                    };
                    struct Tok t =  l->data[i];

{
long nLength = len(tokens);
if (tokens->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(tokens->data, (nLength+50)*sizeof(struct Tok));
tokens->data = newPtr;
}
tokens->data[len(tokens)] =  t;
tokens->length = nLength+1;
} else {
tokens->data[len(tokens)] =  t;
}
};
i =  i+1;
};
if ((len(tokens)==0)) {
fn->code =  fn->code->add(fn->code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, fn->code);
return;
}
currentFn =  fn;
struct rope* oOut =  OUTPUT;
OUTPUT =  rope("");
parseLines(tokens,fnElems);
currentFn =  null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_730 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                    ____BAH_COMPILER_VAR_730 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_730+currStrOff, "Function '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_730+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_730+currStrOff, "' is not returned.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_730);
}
endRCPscope(fnElems,null);
}
fn->code =  fn->code->add(fn->code, OUTPUT);
OUTPUT =  oOut;
fn->code =  fn->code->add(fn->code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, fn->code);
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_731 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_731->name= null;
____BAH_COMPILER_VAR_731->returns= null;
____BAH_COMPILER_VAR_731->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_731->args->length = 0;
            ____BAH_COMPILER_VAR_731->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df =  ____BAH_COMPILER_VAR_731;
df->name =  fn->name;
df->args =  fn->args;
df->returns =  fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_732 = df;
char ** ____BAH_COMPILER_VAR_734 = (char **)((char*)(____BAH_COMPILER_VAR_732) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_735 = __reflect(____BAH_COMPILER_VAR_734, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_736 = (char **)((char*)(____BAH_COMPILER_VAR_732) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_737 = __reflect(____BAH_COMPILER_VAR_736, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_738 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_732) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_739 = 0;
char ** ____BAH_COMPILER_VAR_741 = (char **)((char*)(____BAH_COMPILER_VAR_739) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_742 = __reflect(____BAH_COMPILER_VAR_741, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_743 = (char **)((char*)(____BAH_COMPILER_VAR_739) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_744 = __reflect(____BAH_COMPILER_VAR_743, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
int* ____BAH_COMPILER_VAR_745 = (int*)((char*)(____BAH_COMPILER_VAR_739) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_746 = __reflect(____BAH_COMPILER_VAR_745, sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_747 = (char **)((char*)(____BAH_COMPILER_VAR_739) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_748 = __reflect(____BAH_COMPILER_VAR_747, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
int* ____BAH_COMPILER_VAR_749 = (int*)((char*)(____BAH_COMPILER_VAR_739) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_750 = __reflect(____BAH_COMPILER_VAR_749, sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_751 = (char **)((char*)(____BAH_COMPILER_VAR_739) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_752 = __reflect(____BAH_COMPILER_VAR_751, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
int* ____BAH_COMPILER_VAR_753 = (int*)((char*)(____BAH_COMPILER_VAR_739) + offsetof(struct variable, outterScope));
struct reflectElement ____BAH_COMPILER_VAR_754 = __reflect(____BAH_COMPILER_VAR_753, sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));
int* ____BAH_COMPILER_VAR_755 = (int*)((char*)(____BAH_COMPILER_VAR_739) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_756 = __reflect(____BAH_COMPILER_VAR_755, sizeof(int), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_740 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_740->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_740->length = 8;
        ____BAH_COMPILER_VAR_740->data = memoryAlloc(____BAH_COMPILER_VAR_740->length * ____BAH_COMPILER_VAR_740->elemSize);
        ____BAH_COMPILER_VAR_740->data[0] = ____BAH_COMPILER_VAR_742;
____BAH_COMPILER_VAR_740->data[1] = ____BAH_COMPILER_VAR_744;
____BAH_COMPILER_VAR_740->data[2] = ____BAH_COMPILER_VAR_746;
____BAH_COMPILER_VAR_740->data[3] = ____BAH_COMPILER_VAR_748;
____BAH_COMPILER_VAR_740->data[4] = ____BAH_COMPILER_VAR_750;
____BAH_COMPILER_VAR_740->data[5] = ____BAH_COMPILER_VAR_752;
____BAH_COMPILER_VAR_740->data[6] = ____BAH_COMPILER_VAR_754;
____BAH_COMPILER_VAR_740->data[7] = ____BAH_COMPILER_VAR_756;
struct reflectElement ____BAH_COMPILER_VAR_757 = __reflect(____BAH_COMPILER_VAR_739, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_740, 0);

        struct reflectElement ____BAH_COMPILER_VAR_758 = ____BAH_COMPILER_VAR_757;
        struct reflectElement ____BAH_COMPILER_VAR_759 = __reflect(____BAH_COMPILER_VAR_738, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_758, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_733 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_733->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_733->length = 3;
        ____BAH_COMPILER_VAR_733->data = memoryAlloc(____BAH_COMPILER_VAR_733->length * ____BAH_COMPILER_VAR_733->elemSize);
        ____BAH_COMPILER_VAR_733->data[0] = ____BAH_COMPILER_VAR_735;
____BAH_COMPILER_VAR_733->data[1] = ____BAH_COMPILER_VAR_737;
____BAH_COMPILER_VAR_733->data[2] = ____BAH_COMPILER_VAR_759;
struct reflectElement ____BAH_COMPILER_VAR_760 = __reflect(____BAH_COMPILER_VAR_732, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_733, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_760);

                    if (l->length <= len(l)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3848): l[%d] with length %d\n", len(l)-1, l->length);
                        exit(1);
                    };
                    struct Tok lt =  l->data[len(l)-1];
debugEndScope(lt.line,fnElems);
}
};
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
if ((len(line)==0)) {
return;
}
line =  parsePointers(line);
lineType ltp =  getLineType(line);
compilerState.RCPvars = memoryAlloc(sizeof(array(struct variable*)));

compilerState.RCPvars->length = 0;
compilerState.RCPvars->elemSize = sizeof(struct variable*);
int parsed =  false;
if ((ltp==LINE_TYPE_INCLUDE)) {
parsed =  true;
parseInclude(line,elems);
}
else if ((ltp==LINE_TYPE_IMPORT)) {
parsed =  true;
parseImport(line,elems);
}
else if ((ltp==LINE_TYPE_DEFINE)) {
parsed =  true;
parseDefine(line,elems);
}
else if ((ltp==LINE_TYPE_CLIB)) {
parsed =  true;
parseClib(line);
}
else if ((ltp==LINE_TYPE_STRUCT)) {
parsed =  true;
parseStruct(line,elems);
}
else if ((ltp==LINE_TYPE_CONST)) {
parsed =  true;
parseConst(line,elems);
}
else if ((ltp==LINE_TYPE_MACRO)) {
return;
}
else if ((ltp!=LINE_TYPE_FN_DECL)) {
line =  prePross(line,ltp,elems);
if ((len(line)==0)) {
return;
}
}
if ((ltp==LINE_TYPE_VAR)) {
parsed =  true;
parseVar(line,elems);
}
else if ((ltp==LINE_TYPE_FN_CALL)) {
if ((len(line)>1)) {
throwErr(&line->data[len(line)-1],"Not expecting {TOKEN} after function call.");
}

                    if (line->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3902): line[%d] with length %d\n", 0, line->length);
                        exit(1);
                    };
                    struct Tok ft =  line->data[0];
parsed =  true;
char * ____BAH_COMPILER_VAR_761 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_761 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_761+currStrOff, ft.cont, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_761+currStrOff, ";\n", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_761));
}
else if ((ltp==LINE_TYPE_FN_DECL)) {
parsed =  true;
parseFnDeclare(line,elems);
}
else if ((ltp==LINE_TYPE_RETURN)) {
parsed =  true;
parseReturn(line,elems);
}
else if ((ltp==LINE_TYPE_IF)) {
parsed =  true;
parseIf(line,elems);
}
else if ((ltp==LINE_TYPE_ELSE)) {
parsed =  true;
parseElse(line,elems);
}
else if ((ltp==LINE_TYPE_FOR)) {
parsed =  true;
parseFor(line,elems);
}
else if ((ltp==LINE_TYPE_FOR_OPERATOR)) {
parsed =  true;
parseForOp(line,elems);
}
else if ((ltp==LINE_TYPE_PRE_KEYWORD)) {
parsePreKeyword(line,elems);
parsed =  true;
}
else if ((ltp==LINE_TYPE_ASYNC)) {
parseAsync(line,elems);
parsed =  true;
}
if ((parsed==false)) {

                    if (line->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3932): line[%d] with length %d\n", 0, line->length);
                        exit(1);
                    };
                    struct Tok ft =  line->data[0];
throwErr(&ft,"{TOKEN} not expected.");
}
if ((strlen(NEXT_LINE)>0)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope(NEXT_LINE));
NEXT_LINE =  "";
}
prevLine =  ltp;
};
void parseLines(__BAH_ARR_TYPE_Tok tokens,struct Elems* elems){
if ((len(tokens)==0)) {
return;
}
array(struct Tok)* line = memoryAlloc(sizeof(array(struct Tok)));

line->length = 0;
line->elemSize = sizeof(struct Tok);

                    if (tokens->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3951): tokens[%d] with length %d\n", 0, tokens->length);
                        exit(1);
                    };
                    struct Tok ft =  tokens->data[0];
long int currentLine =  ft.line;
long int nbEncl =  0;
long int i =  0;
while ((i<len(tokens))) {

                    if (tokens->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3955): tokens[%d] with length %d\n", i, tokens->length);
                        exit(1);
                    };
                    struct Tok t =  tokens->data[i];
if ((t.type==TOKEN_TYPE_ENCL)) {
if ((strcmp(t.cont, "(") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((strcmp(t.cont, ")") == 0)) {
nbEncl =  nbEncl - 1;
}
else if ((strcmp(t.cont, "{") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((strcmp(t.cont, "}") == 0)) {
nbEncl =  nbEncl - 1;
}
else if ((strcmp(t.cont, "[") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((strcmp(t.cont, "]") == 0)) {
nbEncl =  nbEncl - 1;
}
}
if (((t.type==TOKEN_TYPE_STR)&&(t.begLine==currentLine))) {
currentLine =  t.line;
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
line->data[len(line)] =  t;
line->length = nLength+1;
} else {
line->data[len(line)] =  t;
}
};

                    if (tokens->length <= i-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3981): tokens[%d] with length %d\n", i-1, tokens->length);
                        exit(1);
                    };
                    struct Tok pt =  tokens->data[i-1];
currentLine =  pt.line;
}
else {
currentLine =  t.line;
}
parseLine(line,elems);
clear(line);
if ((t.type==TOKEN_TYPE_ENCL)) {
i =  i+1;
continue;
}
}
else if ((strcmp(t.cont, ";") == 0)) {
currentLine =  t.line;
parseLine(line,elems);
clear(line);
i =  i+1;
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
line->data[len(line)] =  t;
line->length = nLength+1;
} else {
line->data[len(line)] =  t;
}
};
i =  i+1;
};
if ((len(line)>0)) {
if ((nbEncl==0)) {
parseLine(line,elems);
clear(line);
}
else {

                    if (line->length <= len(line)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/parser.bah:4010): line[%d] with length %d\n", len(line)-1, line->length);
                        exit(1);
                    };
                    ft =  line->data[len(line)-1];
throwErr(&ft,"Missing closing token, line ending by {TOKEN}.");
}
}
};
void declareFunc(struct func* fn,struct Elems* elems){
struct string tmpfnRetCType =  getCType(fn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(fn->args))) {

                    if (fn->args->length <= j) {
                        printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:6): fn->args[%d] with length %d\n", j, fn->args->length);
                        exit(1);
                    };
                    struct variable* arg =  fn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_762 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_763 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_762);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(arg->name);
;                            
                    ____BAH_COMPILER_VAR_763 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_763+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_763+currStrOff, ____BAH_COMPILER_VAR_762, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_763+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_763+currStrOff, arg->name, strLen_3);
                    currStrOff += strLen_3;
                    
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_763;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_764 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(", ");
;                            
                    ____BAH_COMPILER_VAR_764 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_764+currStrOff, tmpfnArgsCType, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_764+currStrOff, ", ", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                tmpfnArgsCType =  ____BAH_COMPILER_VAR_764;
}
};
char * ____BAH_COMPILER_VAR_765 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_766 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_765);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(fn->name);
long int strLen_3 = strlen("(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(");\n");
;                            
                    ____BAH_COMPILER_VAR_766 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                    
                    strncpy(____BAH_COMPILER_VAR_766+currStrOff, ____BAH_COMPILER_VAR_765, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_766+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_766+currStrOff, fn->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_766+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_766+currStrOff, tmpfnArgsCType, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_766+currStrOff, ");\n", strLen_5);
                    currStrOff += strLen_5;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_766));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_767 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->constVal);
long int strLen_4 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_767 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_767+currStrOff, "#define ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_767+currStrOff, v->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_767+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_767+currStrOff, v->constVal, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_767+currStrOff, "\n", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_767));
}
else {
struct string cType =  getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_768 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_769 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(____BAH_COMPILER_VAR_768);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_769 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_769+currStrOff, ____BAH_COMPILER_VAR_768, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_769+currStrOff, " ", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_769+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_769+currStrOff, ";\n", strLen_3);
                    currStrOff += strLen_3;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_769));
}
};
void declareAll(struct Elems* elems){
OUTPUT =  rope("\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\ntypedef array(char*)* __BAH_ARR_TYPE_cpstring;\nlong int __BAH__main(__BAH_ARR_TYPE_cpstring);\n");
long int i =  0;
for (; (i<len(compilerState.cIncludes)); i =  i+1) {

                    if (compilerState.cIncludes->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:42): compilerState.cIncludes[%d] with length %d\n", i, compilerState.cIncludes->length);
                        exit(1);
                    };
                    char * ____BAH_COMPILER_VAR_770 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(compilerState.cIncludes->data[i]);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_770 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_770+currStrOff, "#include ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_770+currStrOff, compilerState.cIncludes->data[i], strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_770+currStrOff, "\n", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_770));
};
i =  1;
for (; (i<len(compilerState.arrTypesDecl)); i =  i+1) {

                    if (compilerState.arrTypesDecl->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:46): compilerState.arrTypesDecl[%d] with length %d\n", i, compilerState.arrTypesDecl->length);
                        exit(1);
                    };
                    char * t =  compilerState.arrTypesDecl->data[i];
struct string elemType =  string(t);
elemType.trimLeft((struct string*)&elemType,15);
char * ____BAH_COMPILER_VAR_771 =elemType.str((struct string*)&elemType);struct string elemCtype =  getCType(____BAH_COMPILER_VAR_771,elems);
char * ____BAH_COMPILER_VAR_772 =elemCtype.str((struct string*)&elemCtype);char * ____BAH_COMPILER_VAR_773 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("typedef array(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_772);
long int strLen_2 = strlen(")* ");
long int strLen_3 = strlen(t);
long int strLen_4 = strlen(";\n");
;                            
                    ____BAH_COMPILER_VAR_773 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                    
                    strncpy(____BAH_COMPILER_VAR_773+currStrOff, "typedef array(", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_773+currStrOff, ____BAH_COMPILER_VAR_772, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_773+currStrOff, ")* ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_773+currStrOff, t, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_773+currStrOff, ";\n", strLen_4);
                    currStrOff += strLen_4;
                    
                }
                OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_773));
};
i =  0;
for (; (i<len(elems->vars)); i =  i+1) {

                    if (elems->vars->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:54): elems->vars[%d] with length %d\n", i, elems->vars->length);
                        exit(1);
                    };
                    struct variable* v =  elems->vars->data[i];
declareVar(v,elems);
};
i =  0;
for (; (i<len(elems->fns)); i =  i+1) {

                    if (elems->fns->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:59): elems->fns[%d] with length %d\n", i, elems->fns->length);
                        exit(1);
                    };
                    struct func* fn =  elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
declareFunc(fn,elems);
};
};
long int main(__BAH_ARR_TYPE_cpstring args){

                    if (args->length <= 0) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:46): args[%d] with length %d\n", 0, args->length);
                        exit(1);
                    };
                    execName =  args->data[0];
struct flags ____BAH_COMPILER_VAR_774 = {};
____BAH_COMPILER_VAR_774.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_774.flags->length = 0;
            ____BAH_COMPILER_VAR_774.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_774.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_774.args->length = 0;
            ____BAH_COMPILER_VAR_774.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_774.addString = flags__addString;
____BAH_COMPILER_VAR_774.addBool = flags__addBool;
____BAH_COMPILER_VAR_774.addInt = flags__addInt;
____BAH_COMPILER_VAR_774.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_774.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_774.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_774.get = flags__get;
____BAH_COMPILER_VAR_774.getInt = flags__getInt;
____BAH_COMPILER_VAR_774.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_774.isSet = flags__isSet;
____BAH_COMPILER_VAR_774.parse = flags__parse;
flags =  ____BAH_COMPILER_VAR_774;
flags.addString((struct flags*)&flags,"o","Name of the file to output.");
flags.addBool((struct flags*)&flags,"c","Translate bah file to C instead of compiling it.");
flags.addBool((struct flags*)&flags,"v","Show version of the compiler.");
flags.addBool((struct flags*)&flags,"l","Compile as a library.");
flags.addBool((struct flags*)&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");
flags.addBool((struct flags*)&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");
flags.addBool((struct flags*)&flags,"debug","Enables verbose json output.");
flags.addBool((struct flags*)&flags,"verboseRuntime","Enables verbose runtime, a debug mode of the compiled program.");
flags.addBool((struct flags*)&flags,"verboseCC","Enables verbose C compiler output, USE IN LAST RESORT.");
char * ____BAH_COMPILER_VAR_775 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
long int strLen_1 = strlen(BAH_OS);
long int strLen_2 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_775 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_775+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_775+currStrOff, BAH_OS, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_775+currStrOff, ".", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                flags.addString((struct flags*)&flags,"target",____BAH_COMPILER_VAR_775);
char * ____BAH_COMPILER_VAR_776 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("If your Bah directory is not the default one (");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen(").");
;                            
                    ____BAH_COMPILER_VAR_776 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_776+currStrOff, "If your Bah directory is not the default one (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_776+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_776+currStrOff, ").", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                flags.addString((struct flags*)&flags,"bahDir",____BAH_COMPILER_VAR_776);
char * ____BAH_COMPILER_VAR_777 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("To change the C compiler used, default: ");
long int strLen_1 = strlen(BAH_CC);
long int strLen_2 = strlen(".");
;                            
                    ____BAH_COMPILER_VAR_777 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_777+currStrOff, "To change the C compiler used, default: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_777+currStrOff, BAH_CC, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_777+currStrOff, ".", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                flags.addString((struct flags*)&flags,"CC",____BAH_COMPILER_VAR_777);
flags.addBool((struct flags*)&flags,"object","Compile as an object.");
flags.parse((struct flags*)&flags,args);
if ((flags.isSet((struct flags*)&flags,"target")==1)) {
BAH_OS =  flags.get((struct flags*)&flags,"target");
char * ____BAH_COMPILER_VAR_778 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Build target: ");
long int strLen_1 = strlen(BAH_OS);
;                            
                    ____BAH_COMPILER_VAR_778 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_778+currStrOff, "Build target: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_778+currStrOff, BAH_OS, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                println(____BAH_COMPILER_VAR_778);
}
if ((flags.isSet((struct flags*)&flags,"bahDir")==1)) {
BAH_DIR =  flags.get((struct flags*)&flags,"bahDir");
array(char)* bahDirArr =  strAsArr(BAH_DIR);

                    if (bahDirArr->length <= len(bahDirArr)-1) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:79): bahDirArr[%d] with length %d\n", len(bahDirArr)-1, bahDirArr->length);
                        exit(1);
                    };
                    if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_779 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("/");
;                            
                    ____BAH_COMPILER_VAR_779 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_779+currStrOff, BAH_DIR, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_779+currStrOff, "/", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                BAH_DIR =  ____BAH_COMPILER_VAR_779;
}
char * ____BAH_COMPILER_VAR_780 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Bah directory: ");
long int strLen_1 = strlen(BAH_DIR);
;                            
                    ____BAH_COMPILER_VAR_780 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_780+currStrOff, "Bah directory: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_780+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                println(____BAH_COMPILER_VAR_780);
}
if ((flags.isSet((struct flags*)&flags,"CC")==1)) {
BAH_CC =  flags.get((struct flags*)&flags,"CC");
char * ____BAH_COMPILER_VAR_781 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("C compiler: ");
long int strLen_1 = strlen(BAH_CC);
;                            
                    ____BAH_COMPILER_VAR_781 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_781+currStrOff, "C compiler: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_781+currStrOff, BAH_CC, strLen_1);
                    currStrOff += strLen_1;
                    
                }
                println(____BAH_COMPILER_VAR_781);
}
verboseRuntime =  (flags.isSet((struct flags*)&flags,"verboseRuntime")==1);
debug =  (flags.isSet((struct flags*)&flags,"debug")==1);
isObject =  (flags.isSet((struct flags*)&flags,"object")==1);
if ((debug==true)) {
debugStart();
}
RCPenabled =  ((flags.isSet((struct flags*)&flags,"rcp")==1)||flags.isSet((struct flags*)&flags,"fastrcp"));
if ((flags.isSet((struct flags*)&flags,"v")==1)) {
char * ____BAH_COMPILER_VAR_782 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Bah compiler version: ");
long int strLen_1 = strlen(BAH_VERSION);
long int strLen_2 = strlen(".\n© Alois Laurent Boe");
;                            
                    ____BAH_COMPILER_VAR_782 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_782+currStrOff, "Bah compiler version: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_782+currStrOff, BAH_VERSION, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_782+currStrOff, ".\n© Alois Laurent Boe", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                println(____BAH_COMPILER_VAR_782);
return 0;
}
if (((flags.isSet((struct flags*)&flags,"c")==1)&&(flags.isSet((struct flags*)&flags,"l")==1))) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:106");
}
INIT =  rope("");
OUTPUT =  rope("\n    void __BAH_init();\n    #define noCheck(v) v\n    #define array(type)	\
    struct{	\
    type *data; \
    long int length; \
    long int elemSize; \
    }\n    typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n    long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n    ");
if ((flags.isSet((struct flags*)&flags,"l")==0)) {
if ((RCPenabled==true)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope("\n            void RCP_init();\n            void RCP_shutdown();\n            void free(void*);\n            int main(int argc, char ** argv) {\n            RCP_init();\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            RCP_shutdown();\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, rope("\n            #include <gc.h>\n            int main(int argc, char ** argv) {\n            GC_INIT();\n            array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n            args->data = GC_MALLOC(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            GC_FREE(args->data);\n            GC_FREE(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
}
struct compilerStateTag ____BAH_COMPILER_VAR_783 = {};
____BAH_COMPILER_VAR_783.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_783.includes->length = 0;
            ____BAH_COMPILER_VAR_783.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_783.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_783.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_783.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_783.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_783.cLibs->length = 0;
            ____BAH_COMPILER_VAR_783.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_783.currentFile= null;
____BAH_COMPILER_VAR_783.currentDir = "./";
____BAH_COMPILER_VAR_783.isBranch = false;
____BAH_COMPILER_VAR_783.isFor = false;
____BAH_COMPILER_VAR_783.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_783.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_783.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_783.haveEntryPoint = false;
____BAH_COMPILER_VAR_783.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_783.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_783.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_783.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_783.evals->length = 0;
            ____BAH_COMPILER_VAR_783.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_783.hasImports = false;
compilerState =  ____BAH_COMPILER_VAR_783;

{
long nLength = 0;
if (compilerState.arrTypesDecl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(compilerState.arrTypesDecl->data, (nLength+50)*sizeof(char *));
compilerState.arrTypesDecl->data = newPtr;
}
compilerState.arrTypesDecl->data[0] =  "__BAH_ARR_TYPE_cpstring";
compilerState.arrTypesDecl->length = nLength+1;
} else {
compilerState.arrTypesDecl->data[0] =  "__BAH_ARR_TYPE_cpstring";
}
};
char * fileName =  absPath(args->data[1]);
compilerState.currentFile =  fileName;
struct fileMap ____BAH_COMPILER_VAR_784 = {};
____BAH_COMPILER_VAR_784.handle = -1;
____BAH_COMPILER_VAR_784.p= null;
____BAH_COMPILER_VAR_784.open = fileMap__open;
____BAH_COMPILER_VAR_784.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_784.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_784;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_785 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not open file '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("'.");
;                            
                    ____BAH_COMPILER_VAR_785 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_785+currStrOff, "Could not open file '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_785+currStrOff, fileName, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_785+currStrOff, "'.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                __BAH_panic(____BAH_COMPILER_VAR_785,"/home/alois/Documents/bah-bah/src/main.bah:179");
}
long int startTime =  getTimeUnix();
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_786 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("' not recognized.");
;                            
                    ____BAH_COMPILER_VAR_786 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_786+currStrOff, "File '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_786+currStrOff, fileName, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_786+currStrOff, "' not recognized.", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                __BAH_panic(____BAH_COMPILER_VAR_786,"/home/alois/Documents/bah-bah/src/main.bah:187");
}
struct Elems* ____BAH_COMPILER_VAR_787 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_787->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_787->vars->length = 0;
            ____BAH_COMPILER_VAR_787->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_787->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_787->structs->length = 0;
            ____BAH_COMPILER_VAR_787->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_787->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_787->types->length = 0;
            ____BAH_COMPILER_VAR_787->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_787->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_787->fns->length = 0;
            ____BAH_COMPILER_VAR_787->fns->elemSize = sizeof(struct func*);
            struct Elems* elems =  ____BAH_COMPILER_VAR_787;
if ((isObject==true)) {
OUTPUT =  rope("\n        #define noCheck(v) v\n        #define array(type)	\
        struct{	\
        type *data; \
        long int length; \
        long int elemSize; \
        }\n        typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n        long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n        ");
shouldOnlyDecl =  true;
}
if ((includeFile("builtin.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_788 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Could not find std-libs, please check '");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen("'");
;                            
                    ____BAH_COMPILER_VAR_788 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_788+currStrOff, "Could not find std-libs, please check '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_788+currStrOff, BAH_DIR, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_788+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                __BAH_panic(____BAH_COMPILER_VAR_788,"/home/alois/Documents/bah-bah/src/main.bah:210");
}
shouldOnlyDecl =  false;
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
OUTPUT =  rope("");
declareAll(elems);
}
compilerState.currentDir =  getDirFromFile(fileName);
parseLines(tokens,elems);
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
if (((isObject==false)&&(compilerState.hasImports==false))) {
long int i =  0;
for (; (i<len(elems->fns)); i =  i+1) {

                    if (elems->fns->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:237): elems->fns[%d] with length %d\n", i, elems->fns->length);
                        exit(1);
                    };
                    struct func* fn =  elems->fns->data[i];

                int ____BAH_COMPILER_VAR_789 = 0;
                for(int i=len(excludeFns)-1; i != -1; i--) {
                    if (excludeFns->data[i] != 0 && strcmp(excludeFns->data[i], fn->name) == 0) {
                        ____BAH_COMPILER_VAR_789 = 1;
                        break;
                    };
                };
                if ((((fn->used==false)&&(fn->code!=null))&&(____BAH_COMPILER_VAR_789==false))) {
char * ____BAH_COMPILER_VAR_790 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("//optimized out: ");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("\n");
;                            
                    ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_790+currStrOff, "//optimized out: ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_790+currStrOff, fn->name, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_790+currStrOff, "\n", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                ropeSet(fn->code,____BAH_COMPILER_VAR_790);
}
};
}
if ((debug==true)) {
debugEnd();
return 0;
}
if ((isObject==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_791 =intToStr(totalLines);char * ____BAH_COMPILER_VAR_792 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_793 =intToStr(totalLexerTime / 1000000);char * ____BAH_COMPILER_VAR_794 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("Parsed. (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_791);
long int strLen_2 = strlen(" lines, total time: ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_792);
long int strLen_4 = strlen("ms, lexer time: ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_793);
long int strLen_6 = strlen("ms)\e[0m");
;                            
                    ____BAH_COMPILER_VAR_794 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                    
                    strncpy(____BAH_COMPILER_VAR_794+currStrOff, "Parsed. (", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_794+currStrOff, ____BAH_COMPILER_VAR_791, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_794+currStrOff, " lines, total time: ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_794+currStrOff, ____BAH_COMPILER_VAR_792, strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_794+currStrOff, "ms, lexer time: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_794+currStrOff, ____BAH_COMPILER_VAR_793, strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_794+currStrOff, "ms)\e[0m", strLen_6);
                    currStrOff += strLen_6;
                    
                }
                println(____BAH_COMPILER_VAR_794);
}
if ((flags.isSet((struct flags*)&flags,"o")==1)) {
fileName =  flags.get((struct flags*)&flags,"o");
}
else {
struct string outFileName =  string(args->data[1]);
outFileName.trimRight((struct string*)&outFileName,4);
fileName =  outFileName.str((struct string*)&outFileName);
}
char * isStatic =  "-static";
if (((flags.isSet((struct flags*)&flags,"d")==1)||(strcmp(BAH_OS, "darwin") == 0))) {
isStatic =  "";
}
if ((flags.isSet((struct flags*)&flags,"c")==0)) {
char * obj =  "";
if ((flags.isSet((struct flags*)&flags,"object")==1)) {
char * ____BAH_COMPILER_VAR_795 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".o");
;                            
                    ____BAH_COMPILER_VAR_795 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_795+currStrOff, fileName, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_795+currStrOff, ".o", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fileName =  ____BAH_COMPILER_VAR_795;
obj =  "-c";
}
char * randFileName =  "-x c - -x none";
char * ____BAH_COMPILER_VAR_796 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_CC);
long int strLen_1 = strlen(" -I \"");
long int strLen_2 = strlen(BAH_DIR);
long int strLen_3 = strlen("libs/");
long int strLen_4 = strlen(BAH_OS);
long int strLen_5 = strlen("/include/\" -L \"");
long int strLen_6 = strlen(BAH_DIR);
long int strLen_7 = strlen("libs/");
long int strLen_8 = strlen(BAH_OS);
long int strLen_9 = strlen("/\" ");
long int strLen_10 = strlen(randFileName);
long int strLen_11 = strlen(" ");
long int strLen_12 = strlen(isStatic);
long int strLen_13 = strlen(" ");
long int strLen_14 = strlen(obj);
long int strLen_15 = strlen(" -w -O1 -o ");
long int strLen_16 = strlen(fileName);
;                            
                    ____BAH_COMPILER_VAR_796 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, BAH_CC, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, " -I \"", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, BAH_DIR, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, "libs/", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, BAH_OS, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, "/include/\" -L \"", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, BAH_DIR, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, "libs/", strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, "/\" ", strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, randFileName, strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, isStatic, strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, " ", strLen_13);
                    currStrOff += strLen_13;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, obj, strLen_14);
                    currStrOff += strLen_14;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, " -w -O1 -o ", strLen_15);
                    currStrOff += strLen_15;
                    
                    strncpy(____BAH_COMPILER_VAR_796+currStrOff, fileName, strLen_16);
                    currStrOff += strLen_16;
                    
                }
                char * gccArgs =  ____BAH_COMPILER_VAR_796;
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_797 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -c");
;                            
                    ____BAH_COMPILER_VAR_797 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_797+currStrOff, gccArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_797+currStrOff, " -c", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                gccArgs =  ____BAH_COMPILER_VAR_797;
}
array(char *)* cLibs =  compilerState.cLibs;
long int i =  0;
while ((i<len(cLibs))) {

                    if (cLibs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:290): cLibs[%d] with length %d\n", i, cLibs->length);
                        exit(1);
                    };
                    char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_798 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                    ____BAH_COMPILER_VAR_798 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_798+currStrOff, gccArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_798+currStrOff, " -", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_798+currStrOff, l, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                gccArgs =  ____BAH_COMPILER_VAR_798;
i =  i + 1;
};
struct command cmd =  command(gccArgs);
cmd.input =  OUTPUT->toStr((struct rope*)OUTPUT);
if ((flags.isSet((struct flags*)&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_799 =cmd.run((struct command*)&cmd);println(____BAH_COMPILER_VAR_799);
}
else {
cmd.run((struct command*)&cmd);
}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_800 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("ar rcs ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(".a ");
long int strLen_3 = strlen(fileName);
;                            
                    ____BAH_COMPILER_VAR_800 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                    
                    strncpy(____BAH_COMPILER_VAR_800+currStrOff, "ar rcs ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_800+currStrOff, fileName, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_800+currStrOff, ".a ", strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_800+currStrOff, fileName, strLen_3);
                    currStrOff += strLen_3;
                    
                }
                cmd =  command(____BAH_COMPILER_VAR_800);
cmd.run((struct command*)&cmd);
}
}
else {
if ((flags.isSet((struct flags*)&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_801 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".c");
;                            
                    ____BAH_COMPILER_VAR_801 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                    
                    strncpy(____BAH_COMPILER_VAR_801+currStrOff, fileName, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_801+currStrOff, ".c", strLen_1);
                    currStrOff += strLen_1;
                    
                }
                fileName =  ____BAH_COMPILER_VAR_801;
}
char * ____BAH_COMPILER_VAR_802 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(BAH_CC);
long int strLen_1 = strlen(" -I \"");
long int strLen_2 = strlen(BAH_DIR);
long int strLen_3 = strlen("libs/");
long int strLen_4 = strlen(BAH_OS);
long int strLen_5 = strlen("/include/\" -L \"");
long int strLen_6 = strlen(BAH_DIR);
long int strLen_7 = strlen("libs/");
long int strLen_8 = strlen(BAH_OS);
long int strLen_9 = strlen("/\" ");
long int strLen_10 = strlen(fileName);
long int strLen_11 = strlen(" ");
long int strLen_12 = strlen(isStatic);
long int strLen_13 = strlen(" -O1 -w ");
;                            
                    ____BAH_COMPILER_VAR_802 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13);
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, BAH_CC, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, " -I \"", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, BAH_DIR, strLen_2);
                    currStrOff += strLen_2;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, "libs/", strLen_3);
                    currStrOff += strLen_3;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, BAH_OS, strLen_4);
                    currStrOff += strLen_4;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, "/include/\" -L \"", strLen_5);
                    currStrOff += strLen_5;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, BAH_DIR, strLen_6);
                    currStrOff += strLen_6;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, "libs/", strLen_7);
                    currStrOff += strLen_7;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, "/\" ", strLen_9);
                    currStrOff += strLen_9;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, fileName, strLen_10);
                    currStrOff += strLen_10;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, isStatic, strLen_12);
                    currStrOff += strLen_12;
                    
                    strncpy(____BAH_COMPILER_VAR_802+currStrOff, " -O1 -w ", strLen_13);
                    currStrOff += strLen_13;
                    
                }
                char * gccArgs =  ____BAH_COMPILER_VAR_802;
array(char *)* cLibs =  compilerState.cLibs;
long int i =  0;
while ((i<len(cLibs))) {

                    if (cLibs->length <= i) {
                        printf("array (/home/alois/Documents/bah-bah/src/main.bah:328): cLibs[%d] with length %d\n", i, cLibs->length);
                        exit(1);
                    };
                    char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_803 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                    ____BAH_COMPILER_VAR_803 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_803+currStrOff, gccArgs, strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_803+currStrOff, " -", strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_803+currStrOff, l, strLen_2);
                    currStrOff += strLen_2;
                    
                }
                gccArgs =  ____BAH_COMPILER_VAR_803;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_804 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("//COMPILE WITH: '");
long int strLen_1 = strlen(gccArgs);
long int strLen_2 = strlen("'\n");
;                            
                    ____BAH_COMPILER_VAR_804 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_804+currStrOff, "//COMPILE WITH: '", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_804+currStrOff, gccArgs, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_804+currStrOff, "'\n", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                OUTPUT =  rope(____BAH_COMPILER_VAR_804)->add(rope(____BAH_COMPILER_VAR_804), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_805 = {};
____BAH_COMPILER_VAR_805.handle= null;
____BAH_COMPILER_VAR_805.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_805.open = fileStream__open;
____BAH_COMPILER_VAR_805.close = fileStream__close;
____BAH_COMPILER_VAR_805.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_805.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_805.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_805.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_805.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_805.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_805.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_805.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_805.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_805.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_805.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_805.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_805.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_805;
fs.open((struct fileStream*)&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_806 =OUTPUT->toStr((struct rope*)OUTPUT);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_806);
fs.close((struct fileStream*)&fs);
}
if ((isObject==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_807 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_808 =null;
                {
                    long int currStrOff = 0;
                    long int strLen_0 = strlen("\e[1;32mDone. (compiled in ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_807);
long int strLen_2 = strlen("ms)\e[0m");
;                            
                    ____BAH_COMPILER_VAR_808 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                    
                    strncpy(____BAH_COMPILER_VAR_808+currStrOff, "\e[1;32mDone. (compiled in ", strLen_0);
                    currStrOff += strLen_0;
                    
                    strncpy(____BAH_COMPILER_VAR_808+currStrOff, ____BAH_COMPILER_VAR_807, strLen_1);
                    currStrOff += strLen_1;
                    
                    strncpy(____BAH_COMPILER_VAR_808+currStrOff, "ms)\e[0m", strLen_2);
                    currStrOff += strLen_2;
                    
                }
                println(____BAH_COMPILER_VAR_808);
}
return 0;
};

    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan =  null;
RAND_SEEDED =  0;
BAH_DIR =  "/opt/bah/";
BAH_OS =  "darwin";
BAH_CC =  "clang";
debug =  false;
verboseRuntime =  false;
isObject =  false;
execName =  "bah";
isSubObject =  false;
NEXT_LINE =  "";
shouldOnlyDecl =  false;
threadCount =  0;
currentFn =  null;
totalLines =  0;
totalLexerTime =  0;
RCPenabled =  false;
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

keywords->length = 20;
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
varChars = memoryAlloc(sizeof(array(char)));

varChars->length = 1;
varChars->elemSize = sizeof(char);
varChars->data = memoryAlloc(sizeof(char) * 50);varChars->data[0] = 95;
seps = memoryAlloc(sizeof(array(char)));

seps->length = 1;
seps->elemSize = sizeof(char);
seps->data = memoryAlloc(sizeof(char) * 50);seps->data[0] = 46;
NB_COMP_VAR =  0;
noVOfns = memoryAlloc(sizeof(array(char *)));

noVOfns->length = 1;
noVOfns->elemSize = sizeof(char *);
noVOfns->data = memoryAlloc(sizeof(char *) * 50);noVOfns->data[0] = "__Bah_safe_string";
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
prevLine =  (lineType)-1;
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

        
    };
    