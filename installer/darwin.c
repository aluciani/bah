//COMPILE WITH: '../builder/osxcross/target/bin/x86_64h-apple-darwin14-clang -I "/opt/bah/libs/darwin/include/" -L "/opt/bah/libs/darwin/" ../installer/darwin.c  -O1 -w  -lgc -lpthread -lm'

    void __BAH_init();
    #define noCheck(v) v
    #define array(type)	    struct{	    type *data;     long int length;     long int realLength;     long int elemSize;     }
    typedef array(char*)* __BAH_ARR_TYPE_cpstring;
    long int __BAH__main(__BAH_ARR_TYPE_cpstring);
    
            #include <gc.h>
            #include <string.h>
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
long int ai = (long int)a;
long int bi = (long int)b;
if ((ai*bi==0)) {
return 1;
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
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void print(char * s){
write((void *)1,s,strlen(s));
};
void __BAH_memcpy(char * dest,char * source,long int l);
#define memcpy __BAH_memcpy
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
array(void*)*arr=a;
return arr->length;
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
memset(arr->data,null,arr->realLength*arr->elemSize);
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
void __BAH_memcpy(char * dest,char * source,long int l){
register long int lm = l%sizeof(long int);
if ((lm!=0)) {
for (; (lm!=0); --lm) {
long int i = l-lm;
dest[i]=source[i];
};
}
long int* destI = (void *)((long int)dest-sizeof(long int));
long int* sourceI = (void *)((long int)source-sizeof(long int));
register long int i = l/sizeof(long int);
for (; (i!=0); --i) {
destI[i]=sourceI[i];
};
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
a->realLength=nbElems;
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
sarr->data = memoryAlloc(sizeof(char) * 50);
                    sarr->realLength = 50;
sarr->data[0] = data->data[0];
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
++i;
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
void * cArr(void * arr){
array(void*)*a=arr;
return a->data;
};
char __checkString(char * s,char * l){
if (((void *)s==null)) {
char * ____BAH_COMPILER_VAR_0 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(l);
unsigned int strLen_1 = strlen(") is null \n");
unsigned int strLen_2 = strlen("cpstring (");
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
#define m ____BAH_COMPILER_VAR_1
mutexCondition__init(&m);
return m;

#undef m
};
struct thread {
pthread_t id;
void (*handle)(void *);
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
#define m ____BAH_COMPILER_VAR_2
mutex__init(&m);
return m;

#undef m
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
++this->length;
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
queue__delete(this,key);
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
--this->length;
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
};
void channel__send(struct channel* this,void * data){
pthread_mutex_lock(&this->m_mut);
if ((this->cap!=-1)) {
while ((this->queue->length==this->cap)) {
++this->w_waitting;
pthread_cond_wait(&this->w_cond,&this->m_mut);
--this->w_waitting;
};
}
queue__insert(this->queue,data);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void channel__sendAny(struct channel* this,void * data,long int len){
pthread_mutex_lock(&this->m_mut);
if ((this->cap!=-1)) {
while ((this->queue->length==this->cap)) {
++this->w_waitting;
pthread_cond_wait(&this->w_cond,&this->m_mut);
--this->w_waitting;
};
}
void * p = memoryAlloc(len);
memcpy(p,data,len);
queue__insert(this->queue,p);
if ((this->r_waitting>0)) {
pthread_cond_signal(&this->r_cond);
}
pthread_mutex_unlock(&this->m_mut);
};
void * channel__receive(struct channel* this){
pthread_mutex_lock(&this->m_mut);
while ((this->queue->length==0)) {
++this->r_waitting;
pthread_cond_wait(&this->r_cond,&this->m_mut);
--this->r_waitting;
};
void * data = queue__pop(this->queue);
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
struct channel* c = ____BAH_COMPILER_VAR_5;
pthread_mutex_init(&c->m_mut,0);
pthread_cond_init(&c->w_cond,0);
pthread_cond_init(&c->r_cond,0);
struct queue* ____BAH_COMPILER_VAR_6 = memoryAlloc(sizeof(struct queue));
____BAH_COMPILER_VAR_6->length = 0;
____BAH_COMPILER_VAR_6->head = null;
____BAH_COMPILER_VAR_6->end = null;
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
        unsigned long nLength = len(__Bah_fnNames);
        if (nLength >= __Bah_fnNames->length) {
            if (nLength >= __Bah_fnNames->realLength) {
                if (__Bah_fnNames->realLength != 0) {
                    __Bah_fnNames->realLength *= 2;
                } else {
                    __Bah_fnNames->realLength = 50;
                }
                void * newPtr = memoryRealloc(__Bah_fnNames->data, (__Bah_fnNames->realLength)*sizeof(struct __Bah_fnName_mapper));
                __Bah_fnNames->data = newPtr;
            }
            __Bah_fnNames->data[len(__Bah_fnNames)] = fnn;
            __Bah_fnNames->length = nLength+1;
        } else {
            __Bah_fnNames->data[len(__Bah_fnNames)] = fnn;
        }
    }
    ;
};
void __BAH_panic(char * e,char * line){
if ((__BAH_panic_chan!=null)) {
channel__send(__BAH_panic_chan, e);
return;
}
char * ____BAH_COMPILER_VAR_7 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(e);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("): ");
unsigned int strLen_3 = strlen(line);
unsigned int strLen_4 = strlen("panic (");
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
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("Memory error (segfault).\n");
unsigned int strLen_1 = strlen(res);
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
char * ____BAH_COMPILER_VAR_9 =channel__receive(__BAH_panic_chan);char * err = ____BAH_COMPILER_VAR_9;
if ((s!=null)) {
*s = err;
}
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
        unsigned long nLength = 47;
        if (nLength >= a->length) {
            if (nLength >= a->realLength) {
                if (a->realLength != 0) {
                    a->realLength *= 2;
                } else {
                    a->realLength = 50;
                }
                void * newPtr = memoryRealloc(a->data, (a->realLength)*sizeof(char));
                a->data = newPtr;
            }
            a->data[47] = 46;
            a->length = nLength+1;
        } else {
            a->data[47] = 46;
        }
    }
    ;

    {
        unsigned long nLength = 48;
        if (nLength >= a->length) {
            if (nLength >= a->realLength) {
                if (a->realLength != 0) {
                    a->realLength *= 2;
                } else {
                    a->realLength = 50;
                }
                void * newPtr = memoryRealloc(a->data, (a->realLength)*sizeof(char));
                a->data = newPtr;
            }
            a->data[48] = 46;
            a->length = nLength+1;
        } else {
            a->data[48] = 46;
        }
    }
    ;

    {
        unsigned long nLength = 49;
        if (nLength >= a->length) {
            if (nLength >= a->realLength) {
                if (a->realLength != 0) {
                    a->realLength *= 2;
                } else {
                    a->realLength = 50;
                }
                void * newPtr = memoryRealloc(a->data, (a->realLength)*sizeof(char));
                a->data = newPtr;
            }
            a->data[49] = 46;
            a->length = nLength+1;
        } else {
            a->data[49] = 46;
        }
    }
    ;

    {
        unsigned long nLength = 50;
        if (nLength >= a->length) {
            if (nLength >= a->realLength) {
                if (a->realLength != 0) {
                    a->realLength *= 2;
                } else {
                    a->realLength = 50;
                }
                void * newPtr = memoryRealloc(a->data, (a->realLength)*sizeof(char));
                a->data = newPtr;
            }
            a->data[50] = (char)0;
            a->length = nLength+1;
        } else {
            a->data[50] = (char)0;
        }
    }
    ;
}
char * ____BAH_COMPILER_VAR_10 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_10 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_10+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_10+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_10+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_10;
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
register long int i = 0;
for (; (i<strlen(s)); ++i) {
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
};
void mapWrapper__grow(struct mapWrapper* this,long int nb){
long int l = len(this->elems);
register long int i = l;
for (; (i<l+nb); ++i) {

    {
        unsigned long nLength = i;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[i] = null;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[i] = null;
        }
    }
    ;
};
};
void mapWrapper__set(struct mapWrapper* this,char * k,void * e){
if ((this->length*2>=len(this->elems))) {
mapWrapper__grow(this,this->length);
}
struct mapElem* ____BAH_COMPILER_VAR_11 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_11->key= null;
____BAH_COMPILER_VAR_11->val= null;
____BAH_COMPILER_VAR_11->key = k;
____BAH_COMPILER_VAR_11->val = e;
struct mapElem* elem = ____BAH_COMPILER_VAR_11;
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = elem;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = elem;
        }
    }
    ;
++this->length;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = elem;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = elem;
        }
    }
    ;
break;
}
};
};
void mapWrapper__setAny(struct mapWrapper* this,char * k,void * e,long int s){
if ((this->length==0)) {
mapWrapper__grow(this,50);
}
if ((this->length*2>=len(this->elems))) {
mapWrapper__grow(this,this->length);
}
void * p = memoryAlloc(s);
memcpy(p,e,s);
struct mapElem* ____BAH_COMPILER_VAR_12 = memoryAlloc(sizeof(struct mapElem));
____BAH_COMPILER_VAR_12->key= null;
____BAH_COMPILER_VAR_12->val= null;
____BAH_COMPILER_VAR_12->key = k;
____BAH_COMPILER_VAR_12->val = p;
struct mapElem* elem = ____BAH_COMPILER_VAR_12;
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* ce = this->elems->data[j];
if ((ce==null)) {

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = elem;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = elem;
        }
    }
    ;
++this->length;
break;
}
else if ((strcmp(ce->key, k) == 0)) {

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = elem;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = elem;
        }
    }
    ;
break;
}
};
};
void mapWrapper__delete(struct mapWrapper* this,char * k){
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* e = this->elems->data[j];
if ((e!=null)&&(strcmp(e->key, k) == 0)) {

    {
        unsigned long nLength = j;
        if (nLength >= this->elems->length) {
            if (nLength >= this->elems->realLength) {
                if (this->elems->realLength != 0) {
                    this->elems->realLength *= 2;
                } else {
                    this->elems->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->elems->data, (this->elems->realLength)*sizeof(struct mapElem*));
                this->elems->data = newPtr;
            }
            this->elems->data[j] = null;
            this->elems->length = nLength+1;
        } else {
            this->elems->data[j] = null;
        }
    }
    ;
}
};
};
void * mapWrapper__get(struct mapWrapper* this,char * k){
long int ind = __Bah_map_hash(k,len(this->elems));
register long int i = 0;
for (; (i<len(this->elems)); ++i) {
long int j = (i+ind)%len(this->elems);
struct mapElem* e = this->elems->data[j];
if ((e!=null)&&(strcmp(e->key, k) == 0)) {
return e->val;
}
};
return null;
};
struct mapWrapper* mapWrapper(){
struct mapWrapper* ____BAH_COMPILER_VAR_13 = memoryAlloc(sizeof(struct mapWrapper));
____BAH_COMPILER_VAR_13->elems = memoryAlloc(sizeof(array(struct mapElem*)));
            ____BAH_COMPILER_VAR_13->elems->length = 0;
            ____BAH_COMPILER_VAR_13->elems->elemSize = sizeof(struct mapElem*);
            struct mapWrapper* m = ____BAH_COMPILER_VAR_13;
mapWrapper__grow(m,50);
return m;
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
char * stdinput(){
char * buff = memoryAlloc(1025);
char * response = "";
register long int nDataLength = read((void *)0,buff,1024);
if ((nDataLength<1024)) {
char * ____BAH_COMPILER_VAR_14 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(response);
unsigned int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_14 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_14+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_14+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_14;
}
else {
while ((nDataLength>0)) {
char * ____BAH_COMPILER_VAR_15 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(response);
unsigned int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_15 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_15+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_15+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_15;
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
char * ____BAH_COMPILER_VAR_16 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_16 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_16+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_16+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }write((void *)1,____BAH_COMPILER_VAR_16,strlen(s)+1);
};
struct fileStream {
FILE* handle;
char * name;
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
if ((fileStream__isValid(this)==0)) {
return;
}
fclose(this->handle);
this->handle = null;
};
long int fileStream__getPos(struct fileStream* this){
if ((fileStream__isValid(this)==0)) {
return 0;
}
return ftell(this->handle);
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((fileStream__isValid(this)==0)) {
return;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((fileStream__isValid(this)==0)) {
return -1;
}
long int oldPos = fileStream__getPos(this);
fseek(this->handle,0,2);
long int size = ftell(this->handle);
fileStream__setPos(this,oldPos);
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
fileStream__open(this,path,"w");
fileStream__close(this);
};
long int fileStream__writeFile(struct fileStream* this,char * content){
if ((fileStream__isValid(this)==0)) {
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
if ((fileStream__isValid(this)==0)) {
return "invalid";
}
long int sz = fileStream__getSize(this);
char * r = memoryAllocSTR(sz+1);
long int l = fread(r,1,sz,this->handle);
if ((sz!=l)) {
array(char)* rarr = strAsArr(r);

    {
        unsigned long nLength = l;
        if (nLength >= rarr->length) {
            if (nLength >= rarr->realLength) {
                if (rarr->realLength != 0) {
                    rarr->realLength *= 2;
                } else {
                    rarr->realLength = 50;
                }
                void * newPtr = memoryRealloc(rarr->data, (rarr->realLength)*sizeof(char));
                rarr->data = newPtr;
            }
            rarr->data[l] = (char)0;
            rarr->length = nLength+1;
        } else {
            rarr->data[l] = (char)0;
        }
    }
    ;
}
return r;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,fileStream__getSize(this));
fileStream__readPtr(this,r->data,len(r));
return r;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
fileStream__writePtr(this,d->data,len(d));
};
void fileStream___end(struct fileStream* this){
if (fileStream__isValid(this)) {
char * ____BAH_COMPILER_VAR_17 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(this->name);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("iostream: warning, auto-closing file: '");
;                            
            ____BAH_COMPILER_VAR_17 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_17+currStrOff, "iostream: warning, auto-closing file: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_17+currStrOff, this->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_17+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_17);
fileStream__close(this);
}
};
struct fileMap {
long int handle;
long int size;
void * p;
};
char * fileMap__open(struct fileMap* this,char * fileName){
this->handle = open(fileName,O_RDWR,S_IRUSR|S_IWUSR);
struct stat ____BAH_COMPILER_VAR_18 = {};
#define sb ____BAH_COMPILER_VAR_18
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
        unsigned long nLength = lf;
        if (nLength >= files->length) {
            if (nLength >= files->realLength) {
                if (files->realLength != 0) {
                    files->realLength *= 2;
                } else {
                    files->realLength = 50;
                }
                void * newPtr = memoryRealloc(files->data, (files->realLength)*sizeof(char *));
                files->data = newPtr;
            }
            files->data[lf] = __STR(file->d_name);
            files->length = nLength+1;
        } else {
            files->data[lf] = __STR(file->d_name);
        }
    }
    ;
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
char isFolder(char * path){
struct stat s;
if ((stat(path,&s)!=0)) {
return false;
}
if (s.st_mode&S_IFDIR) {
return true;
}
return false;
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
string__makeEditable(this);
}
long int sl = strlen(s);
long int nl = sl+this->length;
void * nc = memoryRealloc(this->content,nl+1);
if ((nc==null)) {
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:95");
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
__BAH_panic("Error appending to string, possibly due to memory shortage.","/opt/bah/string.bah:110");
}
this->content = nc;
strncpy(this->content,s,sl);
strCatOffset(this->content,sl,tmpS,this->length);
this->length = nl;
};
char string__charAt(struct string* this,long int i){
return this->content[i];
};
long int string__compare(struct string* this,char * s){
return (strcmp(this->content,s)==0);
};
char * string__str(struct string* this){
return this->content;
};
void string__replace(struct string* this,char * nd,char * rl){
if ((this->editable==false)) {
string__makeEditable(this);
}
struct string ____BAH_COMPILER_VAR_19 = {};
____BAH_COMPILER_VAR_19.content= null;
#define needle ____BAH_COMPILER_VAR_19
string__set(&needle,nd);
struct string ____BAH_COMPILER_VAR_20 = {};
____BAH_COMPILER_VAR_20.content= null;
#define repl ____BAH_COMPILER_VAR_20
string__set(&repl,rl);
register long int i = 0;
long int si = 0;
long int replcBuffSart = 0;
long int replcBuffLength = 0;
array(char)* buff = memoryAlloc(sizeof(array(char)));

buff->length = 0;
buff->elemSize = sizeof(char);
while ((i<this->length)) {
char c = string__charAt(this,i);
char rc = string__charAt(&needle,si);
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
register long int j = 0;
while ((j<replcBuffLength)) {

    {
        unsigned long nLength = len(buff);
        if (nLength >= buff->length) {
            if (nLength >= buff->realLength) {
                if (buff->realLength != 0) {
                    buff->realLength *= 2;
                } else {
                    buff->realLength = 50;
                }
                void * newPtr = memoryRealloc(buff->data, (buff->realLength)*sizeof(char));
                buff->data = newPtr;
            }
            buff->data[len(buff)] = string__charAt(this,j+replcBuffSart);
            buff->length = nLength+1;
        } else {
            buff->data[len(buff)] = string__charAt(this,j+replcBuffSart);
        }
    }
    ;
j = j+1;
};
replcBuffLength = 0;
}

    {
        unsigned long nLength = len(buff);
        if (nLength >= buff->length) {
            if (nLength >= buff->realLength) {
                if (buff->realLength != 0) {
                    buff->realLength *= 2;
                } else {
                    buff->realLength = 50;
                }
                void * newPtr = memoryRealloc(buff->data, (buff->realLength)*sizeof(char));
                buff->data = newPtr;
            }
            buff->data[len(buff)] = c;
            buff->length = nLength+1;
        } else {
            buff->data[len(buff)] = c;
        }
    }
    ;
}
if ((si==needle.length)) {
replcBuffLength = 0;
register long int ii = 0;
while ((ii<repl.length)) {
long int a = ii;

    {
        unsigned long nLength = len(buff);
        if (nLength >= buff->length) {
            if (nLength >= buff->realLength) {
                if (buff->realLength != 0) {
                    buff->realLength *= 2;
                } else {
                    buff->realLength = 50;
                }
                void * newPtr = memoryRealloc(buff->data, (buff->realLength)*sizeof(char));
                buff->data = newPtr;
            }
            buff->data[len(buff)] = string__charAt(&repl,ii);
            buff->length = nLength+1;
        } else {
            buff->data[len(buff)] = string__charAt(&repl,ii);
        }
    }
    ;
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
register long int j = 0;
while ((j<replcBuffLength)) {

    {
        unsigned long nLength = j;
        if (nLength >= replbuffStr->length) {
            if (nLength >= replbuffStr->realLength) {
                if (replbuffStr->realLength != 0) {
                    replbuffStr->realLength *= 2;
                } else {
                    replbuffStr->realLength = 50;
                }
                void * newPtr = memoryRealloc(replbuffStr->data, (replbuffStr->realLength)*sizeof(char));
                replbuffStr->data = newPtr;
            }
            replbuffStr->data[j] = string__charAt(this,j+replcBuffSart);
            replbuffStr->length = nLength+1;
        } else {
            replbuffStr->data[j] = string__charAt(this,j+replcBuffSart);
        }
    }
    ;
j = j+1;
};
char * ____BAH_COMPILER_VAR_21 =null;char * ____BAH_COMPILER_VAR_22 =arrAsStr(replbuffStr);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_22);
;                            
            ____BAH_COMPILER_VAR_21 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_21+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_21+currStrOff, ____BAH_COMPILER_VAR_22, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_21;
}
if (((void *)r!=null)) {
string__set(this,r);
}

#undef needle

#undef repl
};
long int string__countChar(struct string* this,char need){
long int c = 0;
register long int i = 0;
for (; (i<this->length); ++i) {
if ((string__charAt(this,i)==need)) {
++c;
}
};
return c;
};
long int string__count(struct string* this,char * need){
if ((strlen(need)==1)) {
return string__countChar(this,need[0]);
}
register long int i = 0;
long int count = 0;
struct string ____BAH_COMPILER_VAR_23 = {};
____BAH_COMPILER_VAR_23.content= null;
#define needle ____BAH_COMPILER_VAR_23
string__set(&needle,need);
long int countIndex = 0;
while ((i<this->length)) {
char c = string__charAt(this,i);
char sc = string__charAt(&needle,countIndex);
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
register long int i = 0;
long int nl = strlen(need);
if ((this->length<nl)) {
return 0;
}
while ((i<nl)) {
char c = string__charAt(this,i);
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
register long int i = this->length-nl;
long int needleIndex = 0;
while ((i<this->length)) {
char c = string__charAt(this,i);
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
char fc = string__charAt(this,0);
if ((isSpace(fc)==false)) {
return;
}
register long int i = 0;
for (; (i<this->length); ++i) {
if ((isSpace(string__charAt(this,i))==false)) {
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
if ((s>this->length)) {
return;
}
long int nSize = this->length-s;
void * tmpS = memoryAlloc(nSize+1);
memcpy(tmpS,this->content+s,nSize);
this->content = tmpS;
this->editable = true;
this->length = nSize;
};
void string__trimRight(struct string* this,long int s){
if ((s>this->length)) {
return;
}
long int nSize = this->length-s;
void * tmpS = memoryAlloc(nSize+1);
memcpy(tmpS,this->content,nSize);
this->content = tmpS;
this->editable = true;
this->length = nSize;
};
struct string string__add(struct string* this,struct string s2){
struct string ____BAH_COMPILER_VAR_24 = {};
____BAH_COMPILER_VAR_24.content= null;
#define r ____BAH_COMPILER_VAR_24
r.length = this->length+s2.length;
r.content = memoryAlloc(r.length+1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
return r;
};
__BAH_ARR_TYPE_char string__asArr(struct string* this){
if ((this->editable==false)) {
string__makeEditable(this);
}
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
arr->data=this->content;
arr->length=this->length;
arr->realLength=this->length;
return arr;
};
struct string string(char * s){
struct string ____BAH_COMPILER_VAR_25 = {};
____BAH_COMPILER_VAR_25.content= null;
#define a ____BAH_COMPILER_VAR_25
string__set(&a,s);
return a;

#undef a
};
char * intToStr(long int i){
if ((i==0)) {
return "0";
}
char ____BAH_COMPILER_VAR_26[66];char* s = ____BAH_COMPILER_VAR_26;
long int ind = -1;
char subZero = (i<0);
if ((subZero==true)) {
i = 0-i;
}
for (; (i!=0); i = i/10) {
long int conv = i%10;
conv = conv+48;
s[ind+1] = (char)conv;
++ind;
};
if ((subZero==true)) {
s[ind+1] = 45;
++ind;
}
long int ls = ind+1;
i = 0;
for (; (i<ls/2); ++i) {
long int ii = ls-i-1;
char osi = s[i];
s[i] = s[ii];
s[ii] = osi;
};
s[ind+1] = (char)0;
return __STR(s);
};
struct string intToString(long int i){
char * ____BAH_COMPILER_VAR_27 =intToStr(i);struct string r = string(____BAH_COMPILER_VAR_27);
return r;
};
char * floatToStr(double f){
char ____BAH_COMPILER_VAR_28[50];char* buff = ____BAH_COMPILER_VAR_28;
sprintf(buff,"%lf",f);
return __STR(buff);
};
long int strToInt(char * s){
register long int l = strlen(s)-1;
long int offset = 1;
long int r = 0;
long int end = 0;
if ((s[0]==45)) {
end = 1;
}
for (; (l>=end); --l) {
if ((s[l]<48)||(s[l]>57)) {
continue;
}
r = r+((long int)s[l]-48)*offset;
offset = offset*10;
};
if ((end==1)) {
r = 0-r;
}
return r;
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
register long int i = 0;
struct string replcBuff = string("");
array(char)* tmpString = memoryAlloc(sizeof(array(char)));

tmpString->length = 0;
tmpString->elemSize = sizeof(char);
while ((i<s.length)) {
char c = string__charAt(&s,i);
char sepc = string__charAt(&sep,sepIndex);
if ((c==sepc)) {
sepIndex = sepIndex+1;
char * ____BAH_COMPILER_VAR_29 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_29);
}
else {
if ((sepIndex>0)) {
sepIndex = 0;
char * ____BAH_COMPILER_VAR_30 =charToString(c);string__append(&replcBuff,____BAH_COMPILER_VAR_30);
register long int ii = 0;
while ((ii<replcBuff.length)) {

    {
        unsigned long nLength = len(tmpString);
        if (nLength >= tmpString->length) {
            if (nLength >= tmpString->realLength) {
                if (tmpString->realLength != 0) {
                    tmpString->realLength *= 2;
                } else {
                    tmpString->realLength = 50;
                }
                void * newPtr = memoryRealloc(tmpString->data, (tmpString->realLength)*sizeof(char));
                tmpString->data = newPtr;
            }
            tmpString->data[len(tmpString)] = string__charAt(&replcBuff,ii);
            tmpString->length = nLength+1;
        } else {
            tmpString->data[len(tmpString)] = string__charAt(&replcBuff,ii);
        }
    }
    ;
ii = ii+1;
};
string__set(&replcBuff,"");
}
else {

    {
        unsigned long nLength = len(tmpString);
        if (nLength >= tmpString->length) {
            if (nLength >= tmpString->realLength) {
                if (tmpString->realLength != 0) {
                    tmpString->realLength *= 2;
                } else {
                    tmpString->realLength = 50;
                }
                void * newPtr = memoryRealloc(tmpString->data, (tmpString->realLength)*sizeof(char));
                tmpString->data = newPtr;
            }
            tmpString->data[len(tmpString)] = c;
            tmpString->length = nLength+1;
        } else {
            tmpString->data[len(tmpString)] = c;
        }
    }
    ;
}
}
if ((sepIndex==sep.length)) {
string__set(&replcBuff,"");
struct string* ____BAH_COMPILER_VAR_31 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_31->content= null;
struct string* elem = ____BAH_COMPILER_VAR_31;
char * ____BAH_COMPILER_VAR_32 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_32);
long int lenRes = len(res);

    {
        unsigned long nLength = lenRes;
        if (nLength >= res->length) {
            if (nLength >= res->realLength) {
                if (res->realLength != 0) {
                    res->realLength *= 2;
                } else {
                    res->realLength = 50;
                }
                void * newPtr = memoryRealloc(res->data, (res->realLength)*sizeof(struct string));
                res->data = newPtr;
            }
            res->data[lenRes] = *elem;
            res->length = nLength+1;
        } else {
            res->data[lenRes] = *elem;
        }
    }
    ;
clear(tmpString);
sepIndex = 0;
}
i = i+1;
};
if ((replcBuff.length>0)) {
register long int ii = 0;
while ((ii<replcBuff.length)) {

    {
        unsigned long nLength = len(tmpString);
        if (nLength >= tmpString->length) {
            if (nLength >= tmpString->realLength) {
                if (tmpString->realLength != 0) {
                    tmpString->realLength *= 2;
                } else {
                    tmpString->realLength = 50;
                }
                void * newPtr = memoryRealloc(tmpString->data, (tmpString->realLength)*sizeof(char));
                tmpString->data = newPtr;
            }
            tmpString->data[len(tmpString)] = string__charAt(&replcBuff,ii);
            tmpString->length = nLength+1;
        } else {
            tmpString->data[len(tmpString)] = string__charAt(&replcBuff,ii);
        }
    }
    ;
ii = ii+1;
};
}
if ((len(tmpString)>0)) {
struct string* ____BAH_COMPILER_VAR_33 = memoryAlloc(sizeof(struct string));
____BAH_COMPILER_VAR_33->content= null;
struct string* elem = ____BAH_COMPILER_VAR_33;
char * ____BAH_COMPILER_VAR_34 =arrToStr(tmpString);string__set(elem,____BAH_COMPILER_VAR_34);
long int lenRes = len(res);

    {
        unsigned long nLength = lenRes;
        if (nLength >= res->length) {
            if (nLength >= res->realLength) {
                if (res->realLength != 0) {
                    res->realLength *= 2;
                } else {
                    res->realLength = 50;
                }
                void * newPtr = memoryRealloc(res->data, (res->realLength)*sizeof(struct string));
                res->data = newPtr;
            }
            res->data[lenRes] = *elem;
            res->length = nLength+1;
        } else {
            res->data[lenRes] = *elem;
        }
    }
    ;
}
return res;
};
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){
register long int i = 0;
struct string s = string("");
long int max = len(a)-1;
while ((i<len(a))) {
struct string e = a->data[i];
if ((e.length==0)) {
i = i+1;
continue;
}
char * ____BAH_COMPILER_VAR_35 =string__str(&e);struct string tmpS = string(____BAH_COMPILER_VAR_35);
if ((i!=max)) {
string__append(&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_36 =string__str(&tmpS);string__append(&s,____BAH_COMPILER_VAR_36);
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
register long int i = 0;
while ((i<s.length)) {
char c = string__charAt(&s,i);
char sc = string__charAt(&sep,sepIndex);
if ((c==sc)) {
if ((sepIndex==0)) {
foundIndex = i-1;
}
sepIndex = sepIndex+1;
if ((sepIndex==sep.length)) {
long int max = s.length-foundIndex-1;
string__trimRight(&s,max);
return string__str(&s);
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
register long int i = 0;
while ((i<s.length)) {
char c = string__charAt(&s,i);
if (isUpper(c)) {
c = c+(char)32;
}

    {
        unsigned long nLength = len(ns);
        if (nLength >= ns->length) {
            if (nLength >= ns->realLength) {
                if (ns->realLength != 0) {
                    ns->realLength *= 2;
                } else {
                    ns->realLength = 50;
                }
                void * newPtr = memoryRealloc(ns->data, (ns->realLength)*sizeof(char));
                ns->data = newPtr;
            }
            ns->data[len(ns)] = c;
            ns->length = nLength+1;
        } else {
            ns->data[len(ns)] = c;
        }
    }
    ;
i = i+1;
};
char * ____BAH_COMPILER_VAR_37 =arrToStr(ns);return string(____BAH_COMPILER_VAR_37);
};
char strHasPrefix(char * s,char * need){
register long int i = 0;
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
register long int i = sl-nl;
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
register long int i = 0;
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
register long int i = 0;
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
};
void flags__addString(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_38 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_38->name= null;
____BAH_COMPILER_VAR_38->help= null;
____BAH_COMPILER_VAR_38->content= null;
struct flag* f = ____BAH_COMPILER_VAR_38;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_CPSTRING;
long int lf = len(this->flags);

    {
        unsigned long nLength = lf;
        if (nLength >= this->flags->length) {
            if (nLength >= this->flags->realLength) {
                if (this->flags->realLength != 0) {
                    this->flags->realLength *= 2;
                } else {
                    this->flags->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->flags->data, (this->flags->realLength)*sizeof(struct flag*));
                this->flags->data = newPtr;
            }
            this->flags->data[lf] = f;
            this->flags->length = nLength+1;
        } else {
            this->flags->data[lf] = f;
        }
    }
    ;
};
void flags__addBool(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_39 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_39->name= null;
____BAH_COMPILER_VAR_39->help= null;
____BAH_COMPILER_VAR_39->content= null;
struct flag* f = ____BAH_COMPILER_VAR_39;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_BOOL;
long int lf = len(this->flags);

    {
        unsigned long nLength = lf;
        if (nLength >= this->flags->length) {
            if (nLength >= this->flags->realLength) {
                if (this->flags->realLength != 0) {
                    this->flags->realLength *= 2;
                } else {
                    this->flags->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->flags->data, (this->flags->realLength)*sizeof(struct flag*));
                this->flags->data = newPtr;
            }
            this->flags->data[lf] = f;
            this->flags->length = nLength+1;
        } else {
            this->flags->data[lf] = f;
        }
    }
    ;
};
void flags__addInt(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_40 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_40->name= null;
____BAH_COMPILER_VAR_40->help= null;
____BAH_COMPILER_VAR_40->content= null;
struct flag* f = ____BAH_COMPILER_VAR_40;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_INT;
long int lf = len(this->flags);

    {
        unsigned long nLength = lf;
        if (nLength >= this->flags->length) {
            if (nLength >= this->flags->realLength) {
                if (this->flags->realLength != 0) {
                    this->flags->realLength *= 2;
                } else {
                    this->flags->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->flags->data, (this->flags->realLength)*sizeof(struct flag*));
                this->flags->data = newPtr;
            }
            this->flags->data[lf] = f;
            this->flags->length = nLength+1;
        } else {
            this->flags->data[lf] = f;
        }
    }
    ;
};
void flags__addFloat(struct flags* this,char * name,char * help){
struct flag* ____BAH_COMPILER_VAR_41 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_41->name= null;
____BAH_COMPILER_VAR_41->help= null;
____BAH_COMPILER_VAR_41->content= null;
struct flag* f = ____BAH_COMPILER_VAR_41;
f->name = name;
f->help = help;
f->type = FLAG_TYPE_FLOAT;
long int lf = len(this->flags);

    {
        unsigned long nLength = lf;
        if (nLength >= this->flags->length) {
            if (nLength >= this->flags->realLength) {
                if (this->flags->realLength != 0) {
                    this->flags->realLength *= 2;
                } else {
                    this->flags->realLength = 50;
                }
                void * newPtr = memoryRealloc(this->flags->data, (this->flags->realLength)*sizeof(struct flag*));
                this->flags->data = newPtr;
            }
            this->flags->data[lf] = f;
            this->flags->length = nLength+1;
        } else {
            this->flags->data[lf] = f;
        }
    }
    ;
};
void flags__invalidate(struct flags* this){
print("Usage of ");
print(this->args->data[0]);
println(":");
register long int i = 0;
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
register long int i = 0;
while ((i<len(this->flags))) {
struct flag* flag = this->flags->data[i];
if (string__compare(&name,flag->name)) {
return flag;
}
i = i+1;
};
struct flag* ____BAH_COMPILER_VAR_42 = memoryAlloc(sizeof(struct flag));
____BAH_COMPILER_VAR_42->name= null;
____BAH_COMPILER_VAR_42->help= null;
____BAH_COMPILER_VAR_42->content= null;
struct flag* z = ____BAH_COMPILER_VAR_42;
z->isSet = 0;
return z;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_43 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_43);
return flag->content;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_44 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_44);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_45 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(flag->name);
unsigned int strLen_1 = strlen("' is not int.");
unsigned int strLen_2 = strlen("Flag '");
;                            
            ____BAH_COMPILER_VAR_45 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_45+currStrOff, "Flag '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_45+currStrOff, flag->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_45+currStrOff, "' is not int.", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_45,"/opt/bah/flags.bah:122");
}
return flag->cont_int;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_46 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_46);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_47 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(flag->name);
unsigned int strLen_1 = strlen("' is not float.");
unsigned int strLen_2 = strlen("Flag '");
;                            
            ____BAH_COMPILER_VAR_47 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_47+currStrOff, "Flag '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_47+currStrOff, flag->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_47+currStrOff, "' is not float.", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_47,"/opt/bah/flags.bah:132");
}
return flag->cont_float;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_48 =string(name);struct flag* flag = flags__getFlag(this,____BAH_COMPILER_VAR_48);
return flag->isSet;
};
void flags__parse(struct flags* this,__BAH_ARR_TYPE_cpstring args){
struct flag* currentFlag= null;
char isVal = false;
this->args = args;
register long int i = 1;
while ((i<len(args))) {
struct string argName = string(args->data[i]);
if ((isVal==true)) {
currentFlag->content = string__str(&argName);
if ((currentFlag->type==FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_49 =string__str(&argName);currentFlag->cont_int = strToInt(____BAH_COMPILER_VAR_49);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_50 =string__str(&argName);currentFlag->cont_float = strToFloat(____BAH_COMPILER_VAR_50);
}
isVal = false;
}
else {
if ((string__charAt(&argName,0)!=45)) {
i = i+1;
continue;
}
string__trimLeft(&argName,1);
if (string__compare(&argName,"help")) {
flags__invalidate(this);
}
else if (string__compare(&argName,"h")) {
flags__invalidate(this);
}
currentFlag = flags__getFlag(this,argName);
if ((currentFlag==null)) {
flags__invalidate(this);
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
flags__invalidate(this);
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
struct timespec ____BAH_COMPILER_VAR_51 = {};
#define ts ____BAH_COMPILER_VAR_51
clock_serv_t cclock;
mach_timespec_t mts;
void * ____BAH_COMPILER_VAR_52 =mach_host_self();host_get_clock_service(____BAH_COMPILER_VAR_52,CALENDAR_CLOCK,&cclock);
clock_get_time(cclock,&mts);
void * ____BAH_COMPILER_VAR_53 =mach_task_self();mach_port_deallocate(____BAH_COMPILER_VAR_53,cclock);
mach_timespec_t* mtsp = &mts;
ts.tv_sec = mtsp->tv_sec;
ts.tv_nsec = mtsp->tv_nsec;
long int s = ts.tv_sec*1000000000+ts.tv_nsec;
return s;

#undef ts
};
char RAND_SEEDED;
void seedRandom(long int i){
srand(i);
RAND_SEEDED = 1;
};
long int randomInRange(long int min,long int max){
if ((RAND_SEEDED==false)) {
srand(time(0)+getTimeUnix());
RAND_SEEDED = true;
}
long int range = max-min;
long int i = rand()%range+1;
i = i+min;
return i;
};
long int cryptoRand(){
struct fileStream ____BAH_COMPILER_VAR_54 = {};
____BAH_COMPILER_VAR_54.handle= null;
____BAH_COMPILER_VAR_54.name= null;
#define fs ____BAH_COMPILER_VAR_54
fileStream__open(&fs,"/dev/urandom","r");
char c = fileStream__getChar(&fs);
fileStream__close(&fs);
long int i = (long int)c;
return i;

#undef fs
};
#define ROPE_LEAF_LEN 200
struct rope {
struct rope* left;
struct rope* right;
char * str;
int lCount;
int len;
int totalLen;
};
void rope__addStr(struct rope* this,char * s,long int* offset){
if ((this->left==null)&&(this->right==null)) {
long int off = *offset;
memcpy(s+off,this->str,this->lCount+1);
*offset = *offset+this->lCount+1;
return;
}
long int l = *offset;
rope__addStr(this->left,s,offset);
rope__addStr(this->right,s,offset);
};
char * rope__toStr(struct rope* this){
if ((this->left==null)&&(this->right==null)) {
return this->str;
}
char * s = memoryAlloc(this->totalLen+1);
long int offset = 0;
rope__addStr(this->left,s,&offset);
rope__addStr(this->right,s,&offset);
return s;
};
struct rope* rope__add(struct rope* this,struct rope* root2){
int n1 = this->len;
struct rope* ____BAH_COMPILER_VAR_55 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_55->left= null;
____BAH_COMPILER_VAR_55->right= null;
____BAH_COMPILER_VAR_55->str= null;
____BAH_COMPILER_VAR_55->len = 0;
struct rope* tmp = ____BAH_COMPILER_VAR_55;
tmp->left = this;
tmp->right = root2;
tmp->totalLen = this->totalLen+root2->totalLen;
tmp->str = null;
return tmp;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* ____BAH_COMPILER_VAR_56 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_56->left= null;
____BAH_COMPILER_VAR_56->right= null;
____BAH_COMPILER_VAR_56->str= null;
____BAH_COMPILER_VAR_56->len = 0;
struct rope* tmp = ____BAH_COMPILER_VAR_56;
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
register long int i = l;
char * arr = memoryAlloc(r+1);
while ((i<=r)) {
arr[j]=a[i];
++j;
++i;
};
tmp->str = arr;
}
return tmp;
};
long int ropeSet(struct rope* r,char * a){
long int n1 = strlen(a);
long int diff = n1-r->totalLen;
struct rope* nr = createRopeStructure(null,a,0,n1-1);
nr->totalLen = n1;
nr->len = n1;
*r = *nr;
return diff;
};
struct rope* concatenateRopes(struct rope* root1,struct rope* root2){
int n1 = root1->len;
struct rope* ____BAH_COMPILER_VAR_57 = memoryAlloc(sizeof(struct rope));
____BAH_COMPILER_VAR_57->left= null;
____BAH_COMPILER_VAR_57->right= null;
____BAH_COMPILER_VAR_57->str= null;
____BAH_COMPILER_VAR_57->len = 0;
struct rope* tmp = ____BAH_COMPILER_VAR_57;
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
};
char * command__run(struct command* this){
char * cm = this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_58 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_58 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_58+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_58;
}
else {
char * ____BAH_COMPILER_VAR_59 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_59 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_59+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_59;
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
char * ____BAH_COMPILER_VAR_60 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(res);
unsigned int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_60 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_60+currStrOff, res, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_60+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }res = ____BAH_COMPILER_VAR_60;
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
char * ____BAH_COMPILER_VAR_61 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>/dev/null");
;                            
            ____BAH_COMPILER_VAR_61 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_61+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_61+currStrOff, " 2>/dev/null", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_61;
}
else {
char * ____BAH_COMPILER_VAR_62 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cm);
unsigned int strLen_1 = strlen(" 2>&1");
;                            
            ____BAH_COMPILER_VAR_62 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_62+currStrOff, cm, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_62+currStrOff, " 2>&1", strLen_1);
            currStrOff += strLen_1;
        
        }cm = ____BAH_COMPILER_VAR_62;
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
char * ____BAH_COMPILER_VAR_63 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(response);
unsigned int strLen_1 = strlen(buff);
;                            
            ____BAH_COMPILER_VAR_63 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_63+currStrOff, response, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_63+currStrOff, buff, strLen_1);
            currStrOff += strLen_1;
        
        }response = ____BAH_COMPILER_VAR_63;
res = fgets(buff,1023,this->handle);
};
this->status = pclose(this->handle);
arr->data=response;
arr->length=strlen(response);
return arr;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_64 = {};
____BAH_COMPILER_VAR_64.command= null;
____BAH_COMPILER_VAR_64.error = true;
____BAH_COMPILER_VAR_64.status = 0;
____BAH_COMPILER_VAR_64.input = null;
____BAH_COMPILER_VAR_64.handle= null;
#define cmd ____BAH_COMPILER_VAR_64
cmd.command = s;
return cmd;

#undef cmd
};
long int exec(char * s,__BAH_ARR_TYPE_cpstring args){
long int r;
array(char *)* nArgs = memoryAlloc(sizeof(array(char *)));

nArgs->length = 0;
nArgs->elemSize = sizeof(char *);

    {
        unsigned long nLength = 0;
        if (nLength >= nArgs->length) {
            if (nLength >= nArgs->realLength) {
                if (nArgs->realLength != 0) {
                    nArgs->realLength *= 2;
                } else {
                    nArgs->realLength = 50;
                }
                void * newPtr = memoryRealloc(nArgs->data, (nArgs->realLength)*sizeof(char *));
                nArgs->data = newPtr;
            }
            nArgs->data[0] = s;
            nArgs->length = nLength+1;
        } else {
            nArgs->data[0] = s;
        }
    }
    ;
register long int i = 0;
while ((i<len(args))) {

    {
        unsigned long nLength = i+1;
        if (nLength >= nArgs->length) {
            if (nLength >= nArgs->realLength) {
                if (nArgs->realLength != 0) {
                    nArgs->realLength *= 2;
                } else {
                    nArgs->realLength = 50;
                }
                void * newPtr = memoryRealloc(nArgs->data, (nArgs->realLength)*sizeof(char *));
                nArgs->data = newPtr;
            }
            nArgs->data[i+1] = args->data[i];
            nArgs->length = nLength+1;
        } else {
            nArgs->data[i+1] = args->data[i];
        }
    }
    ;
i = i+1;
};

    {
        unsigned long nLength = i+2;
        if (nLength >= nArgs->length) {
            if (nLength >= nArgs->realLength) {
                if (nArgs->realLength != 0) {
                    nArgs->realLength *= 2;
                } else {
                    nArgs->realLength = 50;
                }
                void * newPtr = memoryRealloc(nArgs->data, (nArgs->realLength)*sizeof(char *));
                nArgs->data = newPtr;
            }
            nArgs->data[i+2] = (char *)0;
            nArgs->length = nLength+1;
        } else {
            nArgs->data[i+2] = (char *)0;
        }
    }
    ;
r=execvp(s,nArgs->data);
return r;
};
char * BAH_DIR;
char * BAH_OS;
char * BAH_CC;
#define BAH_VERSION "v1.2 (build 106)"
char debug;
char verboseRuntime;
char isObject;
char isUnsafe;
char isOptimized;
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
void * declScope;
char isGlobal;
struct rope* declRope;
char canBeReg;
char isReg;
void * lastSet;
char isArg;
};
struct structMemb {
char * name;
char * type;
char isConst;
char * constVal;
char isArray;
char * from;
void * declScope;
char isGlobal;
struct rope* declRope;
char canBeReg;
char isReg;
void * lastSet;
char isArg;
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
unsigned int line;
char isVar;
char used;
struct rope* code;
char isMut;
char isImported;
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
struct Elems* parent;
unsigned int id;
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
typedef char tokenType;
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
unsigned int pos;
unsigned int line;
unsigned int begLine;
char * bahType;
char isValue;
char isFunc;
char isOper;
char isEqual;
char pass;
void * bahRef;
struct variable* parent;
};
char inArray(char needle,__BAH_ARR_TYPE_char arr){
register long int i = 0;
while ((i<len(arr))) {
if ((needle==arr->data[i])) {
return true;
}
i = i+1;
};
return false;
};
char inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){
register long int i = 0;
while ((i<len(arr))) {
if ((strcmp(needle, arr->data[i]) == 0)) {
return true;
}
i = i+1;
};
return false;
};
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){
struct Tok ____BAH_COMPILER_VAR_65 = {};
____BAH_COMPILER_VAR_65.cont = "";
____BAH_COMPILER_VAR_65.ogCont = "";
____BAH_COMPILER_VAR_65.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_65.pos = 0;
____BAH_COMPILER_VAR_65.line = 1;
____BAH_COMPILER_VAR_65.begLine = 1;
____BAH_COMPILER_VAR_65.bahType = "";
____BAH_COMPILER_VAR_65.isValue = false;
____BAH_COMPILER_VAR_65.isFunc = false;
____BAH_COMPILER_VAR_65.isOper = false;
____BAH_COMPILER_VAR_65.isEqual = false;
____BAH_COMPILER_VAR_65.pass = false;
____BAH_COMPILER_VAR_65.bahRef= null;
____BAH_COMPILER_VAR_65.parent= null;
#define t ____BAH_COMPILER_VAR_65
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

#undef t
};
char isMinus(char c,char nc){
return (c==45)&&isNumber(nc);
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr = intToStr(line);
char * posStr = intToStr(pos);
char * ____BAH_COMPILER_VAR_66 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("\n\e[0m\n");
unsigned int strLen_1 = strlen(msg);
unsigned int strLen_2 = strlen(posStr);
unsigned int strLen_3 = strlen(":");
unsigned int strLen_4 = strlen(lineStr);
unsigned int strLen_5 = strlen(":");
unsigned int strLen_6 = strlen(compilerState.currentFile);
unsigned int strLen_7 = strlen("\e[1;31m[LEXER-ERROR]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_66 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_66+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_66+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_66+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_66+currStrOff, lineStr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_66+currStrOff, ":", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_66+currStrOff, posStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_66+currStrOff, "\n\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_66+currStrOff, msg, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_66);
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
register long int i = 0;
for (; (i<codeLength); ++i) {
char c = s[i];
char nc = (char)0;
if ((i+1<codeLength)) {
nc = s[i+1];
}
if ((c==47)) {
nc = s[i+1];
if ((nc==47)) {
for (; (i<codeLength); ++i) {
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
++lineNb;
}
if ((c==(char)34)) {
long int pos = i;
long int begLine = lineNb;

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
i = i+1;
for (; (i<codeLength); ++i) {
c = s[i];
char pc = s[i-1];
if ((c==(char)34)) {
if ((pc!=(char)92)) {

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
break;
}
}
if ((c==(char)10)) {
lineNb = lineNb+1;
if ((pc!=(char)92)) {

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = (char)92;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = (char)92;
        }
    }
    ;
c = 110;
}
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_STR);
        }
    }
    ;
struct Tok lt = tokens->data[len(tokens)-1];
lt.begLine = begLine;

    {
        unsigned long nLength = len(tokens)-1;
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)-1] = lt;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)-1] = lt;
        }
    }
    ;
}
else if (isNumber(c)||isMinus(c,nc)) {

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
long int pos = i;
i = i+1;
tokenType currentType = TOKEN_TYPE_INT;
char isHex = false;
for (; (i<codeLength); ++i) {
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
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};
--i;

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
        }
    }
    ;
}
else if ((c==(char)39)) {
++i;
char n = s[i];
char * toInt = intToStr((long int)nc);
memory = strToArr(toInt);
++i;
c = s[i];
if ((c!=(char)39)) {
lexerErr(lineNb,i,"Missing closing tag in char declaration.");
}

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(i-1,lineNb,memory,TOKEN_TYPE_CHAR);
        }
    }
    ;
}
else if ((c==(char)35)) {
long int pos = i;

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
break;
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};
--i;

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_KEYWORD);
        }
    }
    ;
}
else if (inArray(c,enclavers)) {

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_ENCL);
        }
    }
    ;
}
else if (inArray(c,syntaxes)) {
if ((c==60)) {
long int pos = i;
char isCast = false;

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((c==62)) {
isCast = true;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
break;
}
if ((isAlphaNumeric(c)==false)&&(c!=42)&&(c!=58)&&(c!=95)&&(c!=91)&&(c!=93)) {
break;
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};
if ((isCast==true)) {

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_CAST);
        }
    }
    ;
continue;
}
i = pos;
c = 60;
clear(memory);
}

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
long int pos = i;
++i;
char fc = c;
for (; (i<codeLength); ++i) {
c = s[i];

        char ____BAH_COMPILER_VAR_67 = 0;
        for(int i=syntaxes->length-1; i!=-1;i--) {
            if (syntaxes->data[i] == c) {
                ____BAH_COMPILER_VAR_67=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_67==false)) {
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
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};
--i;

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,TOKEN_TYPE_SYNTAX);
        }
    }
    ;
}
else if ((c==46)) {

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(i,lineNb,memory,TOKEN_TYPE_SEP);
        }
    }
    ;
}
else if (isAlphaNumeric(c)||(c==95)) {

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[0] = c;
            memory->length = nLength+1;
        } else {
            memory->data[0] = c;
        }
    }
    ;
long int pos = i;
++i;
for (; (i<codeLength); ++i) {
c = s[i];
if ((isAlphaNumeric(c)==false)) {
if ((c!=95)) {
if ((c==62)) {
char lc = memory->data[len(memory)-1];
if ((lc==45)) {

    {
        unsigned long nLength = len(memory)-1;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)-1] = (char)0;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)-1] = (char)0;
        }
    }
    ;
--i;
break;
}
}
break;
}
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
};
--i;
tokenType currentType = TOKEN_TYPE_VAR;
char * memstr = arrAsStr(memory);

        char ____BAH_COMPILER_VAR_68 = 0;
        for(int i=keywords->length-1; i!=-1;i--) {
            if (keywords->data[i] != 0 && strcmp(keywords->data[i], memstr) == 0) {
                ____BAH_COMPILER_VAR_68=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_68) {
currentType = TOKEN_TYPE_KEYWORD;
}

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = makeToken(pos,lineNb,memory,currentType);
        }
    }
    ;
}
};
totalLines = totalLines+lineNb-1;
dur = getTimeUnix()-dur;
totalLexerTime = totalLexerTime+dur;
return tokens;
};
char hasStructSep(struct string* n){
if (string__count(n,".")) {
return true;
}
if (string__count(n,"->")) {
return true;
}
return false;
};
struct string splitStructSepBefore(struct string* n){
if (string__count(n,".")) {
char * ____BAH_COMPILER_VAR_69 =splitStringBefore(*n,".");struct string res = string(____BAH_COMPILER_VAR_69);
return res;
}
if (string__count(n,"->")) {
char * ____BAH_COMPILER_VAR_70 =splitStringBefore(*n,"->");struct string res = string(____BAH_COMPILER_VAR_70);
return res;
}
return string("");
};
struct string splitStructSepAfter(struct string n){
register long int i = n.length;
while ((i>0)) {
char c = string__charAt(&n,i);
if ((c==46)) {
break;
}
else if ((c==62)) {
char pc = string__charAt(&n,i-1);
if ((pc==45)) {
break;
}
}
i = i-1;
};
i = i+1;
string__trimLeft(&n,i);
return n;
};
struct cStruct* searchStruct(char * name,struct Elems* elems){
struct string n = string(name);
string__replace(&n,"&","");
string__replace(&n,"*","");
name = n.content;
register long int i = len(elems->structs)-1;
for (; (i!=-1); --i) {
struct cStruct* s = elems->structs->data[i];
if ((strcmp(s->name, name) == 0)) {
return s;
}
};
return null;
};
struct structMemb* searchStructMemb(char * name,struct cStruct* s,struct Elems* elems){
struct string n = string(name);
if (hasStructSep(&n)) {
struct string rn = splitStructSepBefore(&n);
name = rn.content;
string__trimLeft(&n,rn.length);
if (string__hasPrefix(&n,".")) {
string__trimLeft(&n,1);
}
else {
string__trimLeft(&n,2);
}
char * membs = n.content;
struct structMemb* memb = searchStructMemb(name,s,elems);
if ((n.length>0)) {
s = searchStruct(memb->type,elems);
char * nstr = string__str(&n);
memb = searchStructMemb(nstr,s,elems);
}
return memb;
}
array(struct structMemb*)* members = s->members;
register long int i = 0;
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
struct structMemb* ____BAH_COMPILER_VAR_71 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_71->name = "";
____BAH_COMPILER_VAR_71->type = "";
____BAH_COMPILER_VAR_71->isConst = false;
____BAH_COMPILER_VAR_71->constVal = "";
____BAH_COMPILER_VAR_71->isArray = false;
____BAH_COMPILER_VAR_71->from = "";
____BAH_COMPILER_VAR_71->declScope= null;
____BAH_COMPILER_VAR_71->isGlobal = false;
____BAH_COMPILER_VAR_71->declRope= null;
____BAH_COMPILER_VAR_71->isReg = false;
____BAH_COMPILER_VAR_71->lastSet= null;
____BAH_COMPILER_VAR_71->isArg = false;
____BAH_COMPILER_VAR_71->def = "";
____BAH_COMPILER_VAR_71->isFn = false;
struct structMemb* sm = ____BAH_COMPILER_VAR_71;
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
char * ____BAH_COMPILER_VAR_72 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__");
unsigned int strLen_1 = strlen(name);
unsigned int strLen_2 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_72 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_72+currStrOff, s->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_72+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_72+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* fn = searchFunc(____BAH_COMPILER_VAR_72,elems,true);
if ((fn!=null)) {
return fn;
}
register long int i = 0;
for (; (i<len(s->members)); ++i) {
if ((strcmp(s->members->data[i]->name, name) == 0)) {
struct string ____BAH_COMPILER_VAR_73 =string(s->members->data[i]->type);fn = parseFnType(____BAH_COMPILER_VAR_73);
fn->name = name;
fn->isVar = true;
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
return (strcmp(t, "cpstring") == 0)||(strcmp(t, "ptr") == 0)||typeAsStar(t)||strHasPrefix(t,"[]")||strHasPrefix(t,"chan:")||strHasPrefix(t,"map:");
};
char isRCPtype(char * t,struct Elems* elems){
if ((isRCPpointerType(t)==true)) {
return true;
}
struct cStruct* s = searchStruct(t,elems);
return (s!=null)&&(s->isBinding==false);
};
struct string getCType(char * t,struct Elems* elems){
if ((strlen(t)==0)) {
return string("void");
}
struct string tp = string(t);
string__replace(&tp," ","");
if (string__hasPrefix(&tp,"[]")) {
string__trimLeft(&tp,2);
char * tpstr = string__str(&tp);
tp = getCType(tpstr,elems);
t = string__str(&tp);
char * ____BAH_COMPILER_VAR_74 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t);
unsigned int strLen_1 = strlen(")*");
unsigned int strLen_2 = strlen("array(");
;                            
            ____BAH_COMPILER_VAR_74 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_74+currStrOff, "array(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_74+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_74+currStrOff, ")*", strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_74;
return string(r);
}
struct string ctp = tp;
string__replace(&ctp,"*","");
if ((string__hasPrefix(&tp,"chan:")==1)) {
string__set(&tp,"struct channel *");
}
else if ((string__hasPrefix(&tp,"map:")==1)) {
string__set(&tp,"struct mapWrapper *");
}
else if ((string__hasPrefix(&tp,"buffer:")==1)) {
string__set(&tp,"char*");
}
else if ((strcmp(string__str(&ctp), "int") == 0)) {
string__replace(&tp,"int","long int");
}
else if ((strcmp(string__str(&ctp), "int32") == 0)) {
string__replace(&tp,"int32","int");
}
else if ((strcmp(string__str(&ctp), "uint32") == 0)) {
string__replace(&tp,"uint32","unsigned int");
}
else if ((strcmp(string__str(&ctp), "uint") == 0)) {
string__replace(&tp,"uint","unsigned long int");
}
else if ((strcmp(string__str(&ctp), "float32") == 0)) {
string__replace(&tp,"float32","float");
}
else if ((strcmp(string__str(&ctp), "ufloat32") == 0)) {
string__replace(&tp,"ufloat32","unsigned float");
}
else if ((strcmp(string__str(&ctp), "ufloat") == 0)) {
string__replace(&tp,"ufloat","unsigned double");
}
else if ((strcmp(string__str(&ctp), "float") == 0)) {
string__replace(&tp,"float","double");
}
else if ((strcmp(string__str(&ctp), "long") == 0)) {
string__replace(&tp,"long","long long");
}
else if ((strcmp(string__str(&ctp), "ulong") == 0)) {
string__replace(&tp,"ulong","unsigned long long");
}
else if ((strcmp(string__str(&ctp), "cpstring") == 0)) {
string__replace(&tp,"cpstring","char *");
}
else if ((strcmp(string__str(&ctp), "ptr") == 0)) {
string__replace(&tp,"ptr","void *");
}
else if ((strcmp(string__str(&ctp), "ushort") == 0)) {
string__replace(&tp,"ushort","unsigned short");
}
else if ((strcmp(string__str(&ctp), "byte") == 0)) {
string__replace(&tp,"byte","unsigned char");
}
else if ((strcmp(string__str(&ctp), "bool") == 0)) {
string__replace(&tp,"bool","char");
}
else if ((strcmp(string__str(&ctp), "char") == 0)) {
}
else {
char * ctpstr = string__str(&ctp);
struct cStruct* s = searchStruct(ctpstr,elems);
if ((s!=null)) {
string__prepend(&tp,"struct ");
}
else {
register long int i = 0;
while ((i<len(elems->types))) {
char * ct = elems->types->data[i];
if (string__compare(&ctp,ct)) {
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
if ((first==false)) {
return false;
}
if (compTypeEquiv(b,a,false)) {
return true;
}
return (strcmp(a, b) == 0);
};
char compTypes(char * a,char * b){
if ((strcmp(a, b) == 0)||(strcmp(a, "ptr") == 0)||(strcmp(b, "ptr") == 0)) {
return true;
}

        char ____BAH_COMPILER_VAR_75 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_75=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_76 = 0;
        for(int i=intTypes->length-1; i!=-1;i--) {
            if (intTypes->data[i] != 0 && strcmp(intTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_76=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_75&&____BAH_COMPILER_VAR_76) {
return true;
}

        char ____BAH_COMPILER_VAR_77 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], a) == 0) {
                ____BAH_COMPILER_VAR_77=1;
                break;
            };
        }
        
        char ____BAH_COMPILER_VAR_78 = 0;
        for(int i=floatTypes->length-1; i!=-1;i--) {
            if (floatTypes->data[i] != 0 && strcmp(floatTypes->data[i], b) == 0) {
                ____BAH_COMPILER_VAR_78=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_77&&____BAH_COMPILER_VAR_78) {
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
};
void * reflectElement__calculateOffset(struct reflectElement* this,void * origin){
char * base = origin;
return base+this->offset;
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,char isArr,struct reflectElement* ae,char isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement ____BAH_COMPILER_VAR_79 = {};
____BAH_COMPILER_VAR_79.type= null;
____BAH_COMPILER_VAR_79.name= null;
____BAH_COMPILER_VAR_79.arrayElem= null;
____BAH_COMPILER_VAR_79.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_79.structLayout->length = 0;
            ____BAH_COMPILER_VAR_79.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_79.value= null;
#define re ____BAH_COMPILER_VAR_79
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

#undef re
};
typedef void * reflectSymbols;
__BAH_ARR_TYPE_reflectElement __dumpSymbols(__BAH_ARR_TYPE_reflectElement syms){
return syms;
};
struct reflectElement __debug_get_sym(__BAH_ARR_TYPE_reflectElement syms,struct string a){
if ((string__count(&a,".")>0)) {
array(struct string)* parts = splitString(a,".");
struct string p1 = parts->data[0];
struct string p2 = parts->data[1];
register long int j = 0;
for (; (j<len(syms)); ++j) {
struct reflectElement s = syms->data[j];
if ((strcmp(s.name, string__str(&p1)) == 0)) {
register long int k = 0;
for (; (k<len(s.structLayout)); ++k) {
struct reflectElement m = s.structLayout->data[k];
if ((strcmp(m.name, string__str(&p2)) == 0)) {
m.value = reflectElement__calculateOffset(&m,s.value);
return m;
}
};
break;
}
};
}
else {
register long int j = 0;
for (; (j<len(syms)); ++j) {
struct reflectElement s = syms->data[j];
if ((strcmp(s.name, string__str(&a)) == 0)) {
return s;
}
};
}
struct reflectElement ____BAH_COMPILER_VAR_80 = {};
____BAH_COMPILER_VAR_80.type= null;
____BAH_COMPILER_VAR_80.name= null;
____BAH_COMPILER_VAR_80.arrayElem= null;
____BAH_COMPILER_VAR_80.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_80.structLayout->length = 0;
            ____BAH_COMPILER_VAR_80.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_80.value= null;
#define ns ____BAH_COMPILER_VAR_80
return ns;

#undef ns
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
};
struct jsonElement* jsonElement__get(struct jsonElement* this,char * key){
long int l = len(this->children);
register long int i = 0;
while ((i<l)) {
struct jsonElement* elem = this->children->data[i];
char fc = cpstringCharAt(elem->key,0);
if ((fc==(char)34)) {
array(char)* nk = memoryAlloc(sizeof(array(char)));

nk->length = 0;
nk->elemSize = sizeof(char);
long int lk = strlen(elem->key);
register long int j = 1;
while ((j<lk-1)) {
char c = cpstringCharAt(elem->key,j);

    {
        unsigned long nLength = j-1;
        if (nLength >= nk->length) {
            if (nLength >= nk->realLength) {
                if (nk->realLength != 0) {
                    nk->realLength *= 2;
                } else {
                    nk->realLength = 50;
                }
                void * newPtr = memoryRealloc(nk->data, (nk->realLength)*sizeof(char));
                nk->data = newPtr;
            }
            nk->data[j-1] = c;
            nk->length = nLength+1;
        } else {
            nk->data[j-1] = c;
        }
    }
    ;
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
register long int i = 0;
while ((i<len(e.structLayout))) {
struct reflectElement m = e.structLayout->data[i];
struct jsonElement* ov = jsonElement__get(this,m.name);
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
register long int i = 0;
while ((i<len(this->children))) {
struct jsonElement* c = this->children->data[i];

    {
        unsigned long nLength = i;
        if (nLength >= arr->length) {
            if (nLength >= arr->realLength) {
                if (arr->realLength != 0) {
                    arr->realLength *= 2;
                } else {
                    arr->realLength = 50;
                }
                void * newPtr = memoryRealloc(arr->data, (arr->realLength)*sizeof(long int));
                arr->data = newPtr;
            }
            arr->data[i] = strToInt(c->content);
            arr->length = nLength+1;
        } else {
            arr->data[i] = strToInt(c->content);
        }
    }
    ;
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
register long int i = 0;
while ((i<len(this->children))) {
struct jsonElement* c = this->children->data[i];

    {
        unsigned long nLength = i;
        if (nLength >= arr->length) {
            if (nLength >= arr->realLength) {
                if (arr->realLength != 0) {
                    arr->realLength *= 2;
                } else {
                    arr->realLength = 50;
                }
                void * newPtr = memoryRealloc(arr->data, (arr->realLength)*sizeof(double));
                arr->data = newPtr;
            }
            arr->data[i] = strToFloat(c->content);
            arr->length = nLength+1;
        } else {
            arr->data[i] = strToFloat(c->content);
        }
    }
    ;
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
register long int i = 0;
while ((i<len(this->children))) {
struct jsonElement* c = this->children->data[i];

    {
        unsigned long nLength = i;
        if (nLength >= arr->length) {
            if (nLength >= arr->realLength) {
                if (arr->realLength != 0) {
                    arr->realLength *= 2;
                } else {
                    arr->realLength = 50;
                }
                void * newPtr = memoryRealloc(arr->data, (arr->realLength)*sizeof(char *));
                arr->data = newPtr;
            }
            arr->data[i] = memoryAlloc(strlen(c->content)+1);
            arr->length = nLength+1;
        } else {
            arr->data[i] = memoryAlloc(strlen(c->content)+1);
        }
    }
    ;
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
register long int i = 0;
while ((i<len(this->children))) {
struct jsonElement* c = this->children->data[i];
void * ne = memoryAlloc(ae->size);
register long int j = 0;
while ((j<len(ae->structLayout))) {
struct reflectElement m = ae->structLayout->data[j];
m.value = reflectElement__calculateOffset(&m,ne);
struct jsonElement* ov = jsonElement__get(c,m.name);
if ((ov!=null)) {
json_scan_inner(ov,m,true);
}
j = j+1;
};

    {
        unsigned long nLength = i;
        if (nLength >= arr->length) {
            if (nLength >= arr->realLength) {
                if (arr->realLength != 0) {
                    arr->realLength *= 2;
                } else {
                    arr->realLength = 50;
                }
                void * newPtr = memoryRealloc(arr->data, (arr->realLength)*sizeof(void *));
                arr->data = newPtr;
            }
            arr->data[i] = ne;
            arr->length = nLength+1;
        } else {
            arr->data[i] = ne;
        }
    }
    ;
i = i+1;
};
}
}
else if (strHasPrefix(e.type,"map:")) {
struct mapWrapper** p = e.value;
register long int i = 0;
for (; (i<len(this->children)); ++i) {
struct jsonElement* c = this->children->data[i];
struct reflectElement* ae = e.arrayElem;
void * v = memoryAlloc(ae->size);
ae->value = &v;
register long int j = 0;
for (; (j<len(ae->structLayout)); ++j) {
struct reflectElement m = ae->structLayout->data[j];
m.value = reflectElement__calculateOffset(&m,&v);

    {
        unsigned long nLength = j;
        if (nLength >= ae->structLayout->length) {
            if (nLength >= ae->structLayout->realLength) {
                if (ae->structLayout->realLength != 0) {
                    ae->structLayout->realLength *= 2;
                } else {
                    ae->structLayout->realLength = 50;
                }
                void * newPtr = memoryRealloc(ae->structLayout->data, (ae->structLayout->realLength)*sizeof(struct reflectElement));
                ae->structLayout->data = newPtr;
            }
            ae->structLayout->data[j] = m;
            ae->structLayout->length = nLength+1;
        } else {
            ae->structLayout->data[j] = m;
        }
    }
    ;
};
json_scan_inner(c,*ae,true);
struct string k = string(c->key);
string__trimLeft(&k,1);
string__trimRight(&k,1);
if (strCount(ae->type,"*")||(strcmp(ae->type, "ptr") == 0)||(strcmp(ae->type, "cpstring") == 0)||strHasPrefix(ae->type,"[]")||strHasPrefix(ae->type,"map:")) {
char * ____BAH_COMPILER_VAR_81 =string__str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_81,v);
}
else {
char * ____BAH_COMPILER_VAR_82 =string__str(&k);mapWrapper__set(*p,____BAH_COMPILER_VAR_82,&v);
}
};
}
};
struct jsonElement* parseJson(char * s){
struct jsonElement* ____BAH_COMPILER_VAR_83 = memoryAlloc(sizeof(struct jsonElement));
____BAH_COMPILER_VAR_83->key= null;
____BAH_COMPILER_VAR_83->content= null;
____BAH_COMPILER_VAR_83->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            ____BAH_COMPILER_VAR_83->children->length = 0;
            ____BAH_COMPILER_VAR_83->children->elemSize = sizeof(struct jsonElement*);
            struct jsonElement* jsonElem = ____BAH_COMPILER_VAR_83;
long int lenS = strlen(s);
register long int i = 0;
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
        unsigned long nLength = len(ns)-1;
        if (nLength >= ns->length) {
            if (nLength >= ns->realLength) {
                if (ns->realLength != 0) {
                    ns->realLength *= 2;
                } else {
                    ns->realLength = 50;
                }
                void * newPtr = memoryRealloc(ns->data, (ns->realLength)*sizeof(char));
                ns->data = newPtr;
            }
            ns->data[len(ns)-1] = c;
            ns->length = nLength+1;
        } else {
            ns->data[len(ns)-1] = c;
        }
    }
    ;
}
else {

    {
        unsigned long nLength = len(ns);
        if (nLength >= ns->length) {
            if (nLength >= ns->realLength) {
                if (ns->realLength != 0) {
                    ns->realLength *= 2;
                } else {
                    ns->realLength = 50;
                }
                void * newPtr = memoryRealloc(ns->data, (ns->realLength)*sizeof(char));
                ns->data = newPtr;
            }
            ns->data[len(ns)] = c;
            ns->length = nLength+1;
        } else {
            ns->data[len(ns)] = c;
        }
    }
    ;
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
register long int j = lenS-1;
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
        unsigned long nLength = len(currentElem);
        if (nLength >= currentElem->length) {
            if (nLength >= currentElem->realLength) {
                if (currentElem->realLength != 0) {
                    currentElem->realLength *= 2;
                } else {
                    currentElem->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentElem->data, (currentElem->realLength)*sizeof(char));
                currentElem->data = newPtr;
            }
            currentElem->data[len(currentElem)] = c;
            currentElem->length = nLength+1;
        } else {
            currentElem->data[len(currentElem)] = c;
        }
    }
    ;
i = i+1;
continue;
}
if ((c==44)) {
char * ____BAH_COMPILER_VAR_84 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_84);
if ((child!=null)) {

    {
        unsigned long nLength = elemIndex;
        if (nLength >= jsonElem->children->length) {
            if (nLength >= jsonElem->children->realLength) {
                if (jsonElem->children->realLength != 0) {
                    jsonElem->children->realLength *= 2;
                } else {
                    jsonElem->children->realLength = 50;
                }
                void * newPtr = memoryRealloc(jsonElem->children->data, (jsonElem->children->realLength)*sizeof(struct jsonElement*));
                jsonElem->children->data = newPtr;
            }
            jsonElem->children->data[elemIndex] = child;
            jsonElem->children->length = nLength+1;
        } else {
            jsonElem->children->data[elemIndex] = child;
        }
    }
    ;
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
        unsigned long nLength = len(currentElem);
        if (nLength >= currentElem->length) {
            if (nLength >= currentElem->realLength) {
                if (currentElem->realLength != 0) {
                    currentElem->realLength *= 2;
                } else {
                    currentElem->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentElem->data, (currentElem->realLength)*sizeof(char));
                currentElem->data = newPtr;
            }
            currentElem->data[len(currentElem)] = c;
            currentElem->length = nLength+1;
        } else {
            currentElem->data[len(currentElem)] = c;
        }
    }
    ;
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_85 =arrToStr(currentElem);struct jsonElement* child = parseJson(____BAH_COMPILER_VAR_85);
if ((child!=null)) {

    {
        unsigned long nLength = elemIndex;
        if (nLength >= jsonElem->children->length) {
            if (nLength >= jsonElem->children->realLength) {
                if (jsonElem->children->realLength != 0) {
                    jsonElem->children->realLength *= 2;
                } else {
                    jsonElem->children->realLength = 50;
                }
                void * newPtr = memoryRealloc(jsonElem->children->data, (jsonElem->children->realLength)*sizeof(struct jsonElement*));
                jsonElem->children->data = newPtr;
            }
            jsonElem->children->data[elemIndex] = child;
            jsonElem->children->length = nLength+1;
        } else {
            jsonElem->children->data[elemIndex] = child;
        }
    }
    ;
}
}
else if ((jsonElem->type==JSON_TYPE_MAP)) {
i = i+1;
long int trim = 1;
register long int j = lenS-1;
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
        unsigned long nLength = len(currentElem);
        if (nLength >= currentElem->length) {
            if (nLength >= currentElem->realLength) {
                if (currentElem->realLength != 0) {
                    currentElem->realLength *= 2;
                } else {
                    currentElem->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentElem->data, (currentElem->realLength)*sizeof(char));
                currentElem->data = newPtr;
            }
            currentElem->data[len(currentElem)] = c;
            currentElem->length = nLength+1;
        } else {
            currentElem->data[len(currentElem)] = c;
        }
    }
    ;
}
else {

    {
        unsigned long nLength = len(currentKey);
        if (nLength >= currentKey->length) {
            if (nLength >= currentKey->realLength) {
                if (currentKey->realLength != 0) {
                    currentKey->realLength *= 2;
                } else {
                    currentKey->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentKey->data, (currentKey->realLength)*sizeof(char));
                currentKey->data = newPtr;
            }
            currentKey->data[len(currentKey)] = c;
            currentKey->length = nLength+1;
        } else {
            currentKey->data[len(currentKey)] = c;
        }
    }
    ;
}
i = i+1;
continue;
}
if ((c==58)) {
isVal = 1;
}
else if ((c==44)) {
char * ____BAH_COMPILER_VAR_86 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_86);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

    {
        unsigned long nLength = elemIndex;
        if (nLength >= jsonElem->children->length) {
            if (nLength >= jsonElem->children->realLength) {
                if (jsonElem->children->realLength != 0) {
                    jsonElem->children->realLength *= 2;
                } else {
                    jsonElem->children->realLength = 50;
                }
                void * newPtr = memoryRealloc(jsonElem->children->data, (jsonElem->children->realLength)*sizeof(struct jsonElement*));
                jsonElem->children->data = newPtr;
            }
            jsonElem->children->data[elemIndex] = elem;
            jsonElem->children->length = nLength+1;
        } else {
            jsonElem->children->data[elemIndex] = elem;
        }
    }
    ;
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
        unsigned long nLength = len(currentElem);
        if (nLength >= currentElem->length) {
            if (nLength >= currentElem->realLength) {
                if (currentElem->realLength != 0) {
                    currentElem->realLength *= 2;
                } else {
                    currentElem->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentElem->data, (currentElem->realLength)*sizeof(char));
                currentElem->data = newPtr;
            }
            currentElem->data[len(currentElem)] = c;
            currentElem->length = nLength+1;
        } else {
            currentElem->data[len(currentElem)] = c;
        }
    }
    ;
}
else {

    {
        unsigned long nLength = len(currentKey);
        if (nLength >= currentKey->length) {
            if (nLength >= currentKey->realLength) {
                if (currentKey->realLength != 0) {
                    currentKey->realLength *= 2;
                } else {
                    currentKey->realLength = 50;
                }
                void * newPtr = memoryRealloc(currentKey->data, (currentKey->realLength)*sizeof(char));
                currentKey->data = newPtr;
            }
            currentKey->data[len(currentKey)] = c;
            currentKey->length = nLength+1;
        } else {
            currentKey->data[len(currentKey)] = c;
        }
    }
    ;
}
}
i = i+1;
};
char * ____BAH_COMPILER_VAR_87 =arrToStr(currentElem);struct jsonElement* elem = parseJson(____BAH_COMPILER_VAR_87);
if ((elem!=null)) {
elem->key = arrToStr(currentKey);

    {
        unsigned long nLength = elemIndex;
        if (nLength >= jsonElem->children->length) {
            if (nLength >= jsonElem->children->realLength) {
                if (jsonElem->children->realLength != 0) {
                    jsonElem->children->realLength *= 2;
                } else {
                    jsonElem->children->realLength = 50;
                }
                void * newPtr = memoryRealloc(jsonElem->children->data, (jsonElem->children->realLength)*sizeof(struct jsonElement*));
                jsonElem->children->data = newPtr;
            }
            jsonElem->children->data[elemIndex] = elem;
            jsonElem->children->length = nLength+1;
        } else {
            jsonElem->children->data[elemIndex] = elem;
        }
    }
    ;
}
}
return jsonElem;
};
char json_isPrintable(unsigned int c){
if ((c<32)||(c>255)) {
return false;
}
return (c!=127)&&(c!=129)&&(c!=141)&&(c!=143)&&(c!=144)&&(c!=157);
};
char * jsonEscapeStr(char * s){
array(char)* a = strAsArr(s);
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
register long int i = 0;
while ((i<len(a))) {
char c = a->data[i];
if ((json_isPrintable((unsigned int)c)==false)) {
++i;
continue;
}
if ((c==(char)34)) {

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = (char)92;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = (char)92;
        }
    }
    ;
}
else if ((c==(char)10)) {

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = (char)92;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = (char)92;
        }
    }
    ;

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = 110;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = 110;
        }
    }
    ;
i = i+1;
continue;
}
else if ((c==(char)13)) {

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = (char)92;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = (char)92;
        }
    }
    ;

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = 114;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = 114;
        }
    }
    ;
i = i+1;
continue;
}

    {
        unsigned long nLength = len(r);
        if (nLength >= r->length) {
            if (nLength >= r->realLength) {
                if (r->realLength != 0) {
                    r->realLength *= 2;
                } else {
                    r->realLength = 50;
                }
                void * newPtr = memoryRealloc(r->data, (r->realLength)*sizeof(char));
                r->data = newPtr;
            }
            r->data[len(r)] = c;
            r->length = nLength+1;
        } else {
            r->data[len(r)] = c;
        }
    }
    ;
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
register long int i = 0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_88 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tabsStr);
unsigned int strLen_1 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_88 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_88+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_88+currStrOff, "\t", strLen_1);
            currStrOff += strLen_1;
        
        }tabsStr = ____BAH_COMPILER_VAR_88;
i = i+1;
};
char * s = "{\n";
i = 0;
while ((i<len(e.structLayout))) {
struct reflectElement m = e.structLayout->data[i];
i = i+1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_89 =null;char * ____BAH_COMPILER_VAR_90 =toJson__inner(m,true,tabs);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_90);
unsigned int strLen_1 = strlen(",\n");
unsigned int strLen_2 = strlen("\": ");
unsigned int strLen_3 = strlen(m.name);
unsigned int strLen_4 = strlen("\"");
unsigned int strLen_5 = strlen(tabsStr);
unsigned int strLen_6 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_89 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, s, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, tabsStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_89+currStrOff, "\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_89+currStrOff, ____BAH_COMPILER_VAR_90, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_89+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_89;
}
else {
char * ____BAH_COMPILER_VAR_91 =null;char * ____BAH_COMPILER_VAR_92 =toJson__inner(m,true,tabs);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_92);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("\": ");
unsigned int strLen_3 = strlen(m.name);
unsigned int strLen_4 = strlen("\"");
unsigned int strLen_5 = strlen(tabsStr);
unsigned int strLen_6 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_91 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_91+currStrOff, s, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_91+currStrOff, tabsStr, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_91+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_91+currStrOff, m.name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_91+currStrOff, "\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_91+currStrOff, ____BAH_COMPILER_VAR_92, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_91+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_91;
}
};
tabs = tabs-1;
tabsStr = "";
i = 0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_93 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tabsStr);
unsigned int strLen_1 = strlen("\t");
;                            
            ____BAH_COMPILER_VAR_93 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_93+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_93+currStrOff, "\t", strLen_1);
            currStrOff += strLen_1;
        
        }tabsStr = ____BAH_COMPILER_VAR_93;
i = i+1;
};
char * ____BAH_COMPILER_VAR_94 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tabsStr);
unsigned int strLen_1 = strlen("}");
unsigned int strLen_2 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_94 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_94+currStrOff, s, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_94+currStrOff, tabsStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_94+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_94;
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
char * ____BAH_COMPILER_VAR_95 =null;char * ____BAH_COMPILER_VAR_96 =jsonEscapeStr(s);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_96);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_95 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_95+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_95+currStrOff, ____BAH_COMPILER_VAR_96, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_95+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_95;
}
else {
char ** sp = e.value;
char * s = *sp;
char * ____BAH_COMPILER_VAR_97 =null;char * ____BAH_COMPILER_VAR_98 =jsonEscapeStr(s);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_98);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_97 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_97+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_97+currStrOff, ____BAH_COMPILER_VAR_98, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_97+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_97;
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
register long int i = 0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_99 =null;char * ____BAH_COMPILER_VAR_100 =intToStr(arr->data[i]);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_100);
;                            
            ____BAH_COMPILER_VAR_99 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_99+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_99+currStrOff, ____BAH_COMPILER_VAR_100, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_99;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_101 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_101 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_101+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_101+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_101;
}
};
}
else if ((strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr = e.value;
arr = *arrPtr;
register long int i = 0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_102 =null;char * ____BAH_COMPILER_VAR_103 =floatToStr(arr->data[i]);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_103);
;                            
            ____BAH_COMPILER_VAR_102 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_102+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_102+currStrOff, ____BAH_COMPILER_VAR_103, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_102;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_104 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_104 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_104+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_104+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_104;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr = e.value;
arr = *arrPtr;
char * ____BAH_COMPILER_VAR_105 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_105 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_105+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_105;
register long int i = 0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_106 =null;char * ____BAH_COMPILER_VAR_107 =jsonEscapeStr(arr->data[i]);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_107);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen("\"");
unsigned int strLen_3 = strlen(s);
;                            
            ____BAH_COMPILER_VAR_106 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_106+currStrOff, s, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_106+currStrOff, "\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_106+currStrOff, ____BAH_COMPILER_VAR_107, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_106+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_106;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_108 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_108 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_108+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_108+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_108;
}
else {
char * ____BAH_COMPILER_VAR_109 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_109 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_109+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_109+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_109;
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
register long int i = 0;
while ((i<len(arr))) {
void * arrElem = arr->data[i];
ae->value = arrElem;
register long int j = 0;
while ((j<len(ae->structLayout))) {
struct reflectElement m = ae->structLayout->data[j];
m.value = reflectElement__calculateOffset(&m,ae->value);

    {
        unsigned long nLength = j;
        if (nLength >= ae->structLayout->length) {
            if (nLength >= ae->structLayout->realLength) {
                if (ae->structLayout->realLength != 0) {
                    ae->structLayout->realLength *= 2;
                } else {
                    ae->structLayout->realLength = 50;
                }
                void * newPtr = memoryRealloc(ae->structLayout->data, (ae->structLayout->realLength)*sizeof(struct reflectElement));
                ae->structLayout->data = newPtr;
            }
            ae->structLayout->data[j] = m;
            ae->structLayout->length = nLength+1;
        } else {
            ae->structLayout->data[j] = m;
        }
    }
    ;
j = j+1;
};
char * ____BAH_COMPILER_VAR_110 =null;char * ____BAH_COMPILER_VAR_111 =toJson__inner(*ae,false,tabs);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_111);
;                            
            ____BAH_COMPILER_VAR_110 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_110+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_110+currStrOff, ____BAH_COMPILER_VAR_111, strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_110;
i = i+1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_112 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_112 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_112+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_112+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_112;
}
else {
char * ____BAH_COMPILER_VAR_113 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_113 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_113+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_113+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_113;
}
};
}
char * ____BAH_COMPILER_VAR_114 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_114 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_114+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_114+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }s = ____BAH_COMPILER_VAR_114;
return s;
}
return "0";
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
char * ____BAH_COMPILER_VAR_115 = name;
struct reflectElement ____BAH_COMPILER_VAR_116 = __reflect(____BAH_COMPILER_VAR_115, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_117 =null;char * ____BAH_COMPILER_VAR_118 =toJson(e);char * ____BAH_COMPILER_VAR_119 =intToStr(line);char * ____BAH_COMPILER_VAR_120 =toJson(____BAH_COMPILER_VAR_116);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_118);
unsigned int strLen_1 = strlen("\n    },\n    ");
unsigned int strLen_2 = strlen("\",\n        \"element\": ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_119);
unsigned int strLen_4 = strlen(":");
unsigned int strLen_5 = strlen(compilerState.currentFile);
unsigned int strLen_6 = strlen(",\n        \"path\": \"");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_120);
unsigned int strLen_8 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_117 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_117+currStrOff, "\n    {\n        \"name\": ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_117+currStrOff, ____BAH_COMPILER_VAR_120, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_117+currStrOff, ",\n        \"path\": \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_117+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_117+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_117+currStrOff, ____BAH_COMPILER_VAR_119, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_117+currStrOff, "\",\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_117+currStrOff, ____BAH_COMPILER_VAR_118, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_117+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_117);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
char * ____BAH_COMPILER_VAR_121 = name;
struct reflectElement ____BAH_COMPILER_VAR_122 = __reflect(____BAH_COMPILER_VAR_121, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_123 =null;char * ____BAH_COMPILER_VAR_124 =toJson(e);char * ____BAH_COMPILER_VAR_125 =intToStr(to);char * ____BAH_COMPILER_VAR_126 =intToStr(from);char * ____BAH_COMPILER_VAR_127 =intToStr(line);char * ____BAH_COMPILER_VAR_128 =toJson(____BAH_COMPILER_VAR_122);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_124);
unsigned int strLen_1 = strlen("\n    },\n    ");
unsigned int strLen_2 = strlen("\n        ],\n        \"element\": ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_125);
unsigned int strLen_4 = strlen(",\n            ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_126);
unsigned int strLen_6 = strlen("\",\n        \"range\": [\n            ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_127);
unsigned int strLen_8 = strlen(":");
unsigned int strLen_9 = strlen(compilerState.currentFile);
unsigned int strLen_10 = strlen(",\n        \"path\": \"");
unsigned int strLen_11 = strlen(____BAH_COMPILER_VAR_128);
unsigned int strLen_12 = strlen("\n    {\n        \"name\": ");
;                            
            ____BAH_COMPILER_VAR_123 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, "\n    {\n        \"name\": ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, ____BAH_COMPILER_VAR_128, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, ",\n        \"path\": \"", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, compilerState.currentFile, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, ":", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, ____BAH_COMPILER_VAR_127, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, ____BAH_COMPILER_VAR_126, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, ",\n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, ____BAH_COMPILER_VAR_125, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_123+currStrOff, "\n        ],\n        \"element\": ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_123+currStrOff, ____BAH_COMPILER_VAR_124, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_123+currStrOff, "\n    },\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_123);
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
register long int i = 0;
while ((i<len(elems->vars))) {
struct variable* v = elems->vars->data[i];
if ((v->declScope==elems)&&(v->isConst==false)) {
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
void ** ____BAH_COMPILER_VAR_143 = (void **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_144 = __reflect(____BAH_COMPILER_VAR_143, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_145 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_146 = __reflect(____BAH_COMPILER_VAR_145, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_147 = (struct rope**)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_149 = (void **)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_150 = __reflect(____BAH_COMPILER_VAR_149, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_151 = (void **)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_152 = __reflect(____BAH_COMPILER_VAR_151, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_153 = (char **)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_154 = __reflect(____BAH_COMPILER_VAR_153, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_155 = (int*)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_156 = __reflect(____BAH_COMPILER_VAR_155, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_157 = (int*)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_158 = __reflect(____BAH_COMPILER_VAR_157, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_159 = (int*)((char*)(____BAH_COMPILER_VAR_147) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_160 = __reflect(____BAH_COMPILER_VAR_159, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_148 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_148->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_148->length = 6;
        ____BAH_COMPILER_VAR_148->data = memoryAlloc(____BAH_COMPILER_VAR_148->length * ____BAH_COMPILER_VAR_148->elemSize);
        ____BAH_COMPILER_VAR_148->data[0] = ____BAH_COMPILER_VAR_150;
____BAH_COMPILER_VAR_148->data[1] = ____BAH_COMPILER_VAR_152;
____BAH_COMPILER_VAR_148->data[2] = ____BAH_COMPILER_VAR_154;
____BAH_COMPILER_VAR_148->data[3] = ____BAH_COMPILER_VAR_156;
____BAH_COMPILER_VAR_148->data[4] = ____BAH_COMPILER_VAR_158;
____BAH_COMPILER_VAR_148->data[5] = ____BAH_COMPILER_VAR_160;
struct reflectElement ____BAH_COMPILER_VAR_161 = __reflect(____BAH_COMPILER_VAR_147, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_148, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_162 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_163 = __reflect(____BAH_COMPILER_VAR_162, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_164 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_165 = __reflect(____BAH_COMPILER_VAR_164, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_166 = (void **)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_167 = __reflect(____BAH_COMPILER_VAR_166, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_168 = (char*)((char*)(____BAH_COMPILER_VAR_129) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_169 = __reflect(____BAH_COMPILER_VAR_168, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_130 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_130->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_130->length = 13;
        ____BAH_COMPILER_VAR_130->data = memoryAlloc(____BAH_COMPILER_VAR_130->length * ____BAH_COMPILER_VAR_130->elemSize);
        ____BAH_COMPILER_VAR_130->data[0] = ____BAH_COMPILER_VAR_132;
____BAH_COMPILER_VAR_130->data[1] = ____BAH_COMPILER_VAR_134;
____BAH_COMPILER_VAR_130->data[2] = ____BAH_COMPILER_VAR_136;
____BAH_COMPILER_VAR_130->data[3] = ____BAH_COMPILER_VAR_138;
____BAH_COMPILER_VAR_130->data[4] = ____BAH_COMPILER_VAR_140;
____BAH_COMPILER_VAR_130->data[5] = ____BAH_COMPILER_VAR_142;
____BAH_COMPILER_VAR_130->data[6] = ____BAH_COMPILER_VAR_144;
____BAH_COMPILER_VAR_130->data[7] = ____BAH_COMPILER_VAR_146;
____BAH_COMPILER_VAR_130->data[8] = ____BAH_COMPILER_VAR_161;
____BAH_COMPILER_VAR_130->data[9] = ____BAH_COMPILER_VAR_163;
____BAH_COMPILER_VAR_130->data[10] = ____BAH_COMPILER_VAR_165;
____BAH_COMPILER_VAR_130->data[11] = ____BAH_COMPILER_VAR_167;
____BAH_COMPILER_VAR_130->data[12] = ____BAH_COMPILER_VAR_169;
struct reflectElement ____BAH_COMPILER_VAR_170 = __reflect(____BAH_COMPILER_VAR_129, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_130, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_170);
}
i = i+1;
};
};
void throwErr(void * tp,char * format){
char * str = "";
char * info = "";
long int pos = 0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_171 = {};
____BAH_COMPILER_VAR_171.handle = -1;
____BAH_COMPILER_VAR_171.p= null;
#define fm ____BAH_COMPILER_VAR_171
char * fileSrcStr = fileMap__open(&fm,compilerState.currentFile);
struct Tok* t = tp;
struct string ffmt = string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont = t->cont;
}
char * ____BAH_COMPILER_VAR_172 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t->ogCont);
unsigned int strLen_1 = strlen("'");
unsigned int strLen_2 = strlen("'");
;                            
            ____BAH_COMPILER_VAR_172 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_172+currStrOff, "'", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_172+currStrOff, t->ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_172+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }string__replace(&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_172);
format = string__str(&ffmt);
array(char)* line = memoryAlloc(sizeof(array(char)));

line->length = 0;
line->elemSize = sizeof(char);
unsigned int beg = t->pos;
while ((beg>0)) {
char c = fileSrcStr[beg];
if ((c==(char)10)) {
beg = beg+1;
break;
}
beg = beg-1;
};
pos = t->pos-beg+1;
unsigned int i = beg;
for (; (i<fm.size); ++i) {
char c = fileSrcStr[i];
if ((c==(char)10)) {
break;
}
if ((i==t->pos)) {
array(char)* errCont = memoryAlloc(sizeof(array(char)));

errCont->length = 0;
errCont->elemSize = sizeof(char);
unsigned int offset = i;
for (; (i<fm.size); ++i) {
if ((i-offset>=strlen(t->ogCont))) {
break;
}
if ((fileSrcStr[i]!=t->ogCont[i-offset])) {
if ((isSpace(fileSrcStr[i])==false)) {
break;
}
++offset;
}

    {
        unsigned long nLength = len(errCont);
        if (nLength >= errCont->length) {
            if (nLength >= errCont->realLength) {
                if (errCont->realLength != 0) {
                    errCont->realLength *= 2;
                } else {
                    errCont->realLength = 50;
                }
                void * newPtr = memoryRealloc(errCont->data, (errCont->realLength)*sizeof(char));
                errCont->data = newPtr;
            }
            errCont->data[len(errCont)] = fileSrcStr[i];
            errCont->length = nLength+1;
        } else {
            errCont->data[len(errCont)] = fileSrcStr[i];
        }
    }
    ;
};
char * ____BAH_COMPILER_VAR_173 =null;char * ____BAH_COMPILER_VAR_174 =arrToStr(errCont);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_174);
unsigned int strLen_1 = strlen("\e[1;37m");
unsigned int strLen_2 = strlen("\e[1;31m");
;                            
            ____BAH_COMPILER_VAR_173 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_173+currStrOff, "\e[1;31m", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_173+currStrOff, ____BAH_COMPILER_VAR_174, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_173+currStrOff, "\e[1;37m", strLen_1);
            currStrOff += strLen_1;
        
        }array(char)* errTk = strToArr(____BAH_COMPILER_VAR_173);
register long int ii = 0;
for (; (ii<len(errTk)); ++ii) {

    {
        unsigned long nLength = len(line);
        if (nLength >= line->length) {
            if (nLength >= line->realLength) {
                if (line->realLength != 0) {
                    line->realLength *= 2;
                } else {
                    line->realLength = 50;
                }
                void * newPtr = memoryRealloc(line->data, (line->realLength)*sizeof(char));
                line->data = newPtr;
            }
            line->data[len(line)] = errTk->data[ii];
            line->length = nLength+1;
        } else {
            line->data[len(line)] = errTk->data[ii];
        }
    }
    ;
};
--i;
continue;
}

    {
        unsigned long nLength = len(line);
        if (nLength >= line->length) {
            if (nLength >= line->realLength) {
                if (line->realLength != 0) {
                    line->realLength *= 2;
                } else {
                    line->realLength = 50;
                }
                void * newPtr = memoryRealloc(line->data, (line->realLength)*sizeof(char));
                line->data = newPtr;
            }
            line->data[len(line)] = c;
            line->length = nLength+1;
        } else {
            line->data[len(line)] = c;
        }
    }
    ;
};
fileMap__close(&fm);
str = arrToStr(line);
char * ____BAH_COMPILER_VAR_175 =null;char * ____BAH_COMPILER_VAR_176 =intToStr(pos);char * ____BAH_COMPILER_VAR_177 =intToStr(t->line);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(":");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_176);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_177);
;                            
            ____BAH_COMPILER_VAR_175 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_175+currStrOff, ____BAH_COMPILER_VAR_177, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_175+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_175+currStrOff, ____BAH_COMPILER_VAR_176, strLen_1);
            currStrOff += strLen_1;
        
        }info = ____BAH_COMPILER_VAR_175;

#undef fm
}
if ((debug==true)) {
struct Tok* t = tp;
char * ____BAH_COMPILER_VAR_178 = format;
struct reflectElement ____BAH_COMPILER_VAR_179 = __reflect(____BAH_COMPILER_VAR_178, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos+strlen(t->ogCont),____BAH_COMPILER_VAR_179);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_180 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("\e[0m\n");
unsigned int strLen_1 = strlen(format);
unsigned int strLen_2 = strlen(str);
unsigned int strLen_3 = strlen("\n\e[1;37m\t");
unsigned int strLen_4 = strlen(info);
unsigned int strLen_5 = strlen(":");
unsigned int strLen_6 = strlen(compilerState.currentFile);
unsigned int strLen_7 = strlen("\e[1;31m[ERROR]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_180 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, compilerState.currentFile, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, ":", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, info, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, "\n\e[1;37m\t", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_180+currStrOff, str, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_180+currStrOff, "\e[0m\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_180+currStrOff, format, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_180);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_181 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\e[0m");
unsigned int strLen_2 = strlen("\n\e[0m\t");
unsigned int strLen_3 = strlen(compilerState.currentFile);
unsigned int strLen_4 = strlen("\e[1;33m[WARNING]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_181 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_181+currStrOff, "\n\e[0m\t", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_181+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_181+currStrOff, "\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_181);
};
void throwWarningLine(char * s,long int l){
char * ____BAH_COMPILER_VAR_182 =null;char * ____BAH_COMPILER_VAR_183 =intToStr(l);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s);
unsigned int strLen_1 = strlen("\e[0m");
unsigned int strLen_2 = strlen("\n\e[0m\t");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_183);
unsigned int strLen_4 = strlen(":");
unsigned int strLen_5 = strlen(compilerState.currentFile);
unsigned int strLen_6 = strlen("\e[1;33m[WARNING]\e[0m ");
;                            
            ____BAH_COMPILER_VAR_182 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, compilerState.currentFile, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, ":", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, ____BAH_COMPILER_VAR_183, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_182+currStrOff, "\n\e[0m\t", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_182+currStrOff, s, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_182+currStrOff, "\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_182);
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
struct variable* getRealVar(char * n,struct Elems* elems){
register long int i = len(elems->vars)-1;
for (; (i!=-1); --i) {
if ((strcmp(elems->vars->data[i]->name, n) == 0)) {
return elems->vars->data[i];
}
};
return null;
};
void removeVarUnar(struct string* s){
array(char)* arr = string__asArr(s);
register long int i = 0;
for (; (i<len(arr)); ++i) {
char c = arr->data[i];
if ((c==38)||(c==42)) {
delete(arr,i);
--i;
continue;
}
};
};
struct variable* searchVar(char * name,struct Elems* elems){
char * ogName = name;
struct string n = string(name);
removeVarUnar(&n);
if ((string__charAt(&n,n.length-1)==93)) {
register long int i = n.length;
while ((i>0)) {
char c = string__charAt(&n,i);
if ((c==91)) {
break;
}
i = i-1;
};
long int tamm = n.length-i;
string__trimRight(&n,tamm);
char isArr = (string__hasSuffix(&n,"->data")==1);
if ((isArr==true)) {
string__trimRight(&n,6);
}
name = string__str(&n);
struct variable* v = searchVar(name,elems);
struct string vt = string(v->type);
if ((isArr==true)) {
string__trimLeft(&vt,2);
}
else {
string__set(&vt,"char");
}
char * vtstr = string__str(&vt);
struct variable* ____BAH_COMPILER_VAR_184 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_184->name = "";
____BAH_COMPILER_VAR_184->type = "";
____BAH_COMPILER_VAR_184->isConst = false;
____BAH_COMPILER_VAR_184->constVal = "";
____BAH_COMPILER_VAR_184->isArray = false;
____BAH_COMPILER_VAR_184->from = "";
____BAH_COMPILER_VAR_184->declScope= null;
____BAH_COMPILER_VAR_184->isGlobal = false;
____BAH_COMPILER_VAR_184->declRope= null;
____BAH_COMPILER_VAR_184->isReg = false;
____BAH_COMPILER_VAR_184->lastSet= null;
____BAH_COMPILER_VAR_184->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_184;
*nv = *v;
nv->type = vtstr;
nv->name = ogName;
nv->isArray = isArr;
return nv;
}
name = n.content;
if (hasStructSep(&n)&&(string__count(&n,")")==0)) {
struct string rn = splitStructSepBefore(&n);
name = rn.content;
string__trimLeft(&n,rn.length);
if (string__hasPrefix(&n,".")) {
string__trimLeft(&n,1);
}
else {
string__trimLeft(&n,2);
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
struct variable* ____BAH_COMPILER_VAR_185 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_185->name = "";
____BAH_COMPILER_VAR_185->type = "";
____BAH_COMPILER_VAR_185->isConst = false;
____BAH_COMPILER_VAR_185->constVal = "";
____BAH_COMPILER_VAR_185->isArray = false;
____BAH_COMPILER_VAR_185->from = "";
____BAH_COMPILER_VAR_185->declScope= null;
____BAH_COMPILER_VAR_185->isGlobal = false;
____BAH_COMPILER_VAR_185->declRope= null;
____BAH_COMPILER_VAR_185->isReg = false;
____BAH_COMPILER_VAR_185->lastSet= null;
____BAH_COMPILER_VAR_185->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_185;
nv->from = memb->from;
nv->name = memb->name;
nv->type = memb->type;
nv->declScope = v->declScope;
nv->name = ogName;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_186 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_186 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_186+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_186+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_186;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_187 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nv->name);
unsigned int strLen_1 = strlen(" because it is not pointer.");
unsigned int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_187 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_187+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_187+currStrOff, nv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_187+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_187);
}
string__trimRight(&ct,nbUnaries);
r = string__str(&ct);
}
nv->type = r;
nv->name = ogName;
return nv;
}
register long int i = len(elems->vars)-1;
for (; (i!=-1); --i) {
struct variable* v = elems->vars->data[i];
if ((strcmp(v->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_188 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_188->name = "";
____BAH_COMPILER_VAR_188->type = "";
____BAH_COMPILER_VAR_188->isConst = false;
____BAH_COMPILER_VAR_188->constVal = "";
____BAH_COMPILER_VAR_188->isArray = false;
____BAH_COMPILER_VAR_188->from = "";
____BAH_COMPILER_VAR_188->declScope= null;
____BAH_COMPILER_VAR_188->isGlobal = false;
____BAH_COMPILER_VAR_188->declRope= null;
____BAH_COMPILER_VAR_188->isReg = false;
____BAH_COMPILER_VAR_188->lastSet= null;
____BAH_COMPILER_VAR_188->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_188;
*nv = *v;
char * r = nv->type;
struct string tcc = string(ogName);
if (string__count(&tcc,"&")) {
char * ____BAH_COMPILER_VAR_189 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_189 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_189+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_189+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_189;
}
long int nbUnaries = string__count(&tcc,"*");
if ((nbUnaries>0)) {
struct string ct = string(r);
long int pointerLevel = string__count(&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_190 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(" because it is not pointer.");
unsigned int strLen_2 = strlen("Cannot use '*' on ");
;                            
            ____BAH_COMPILER_VAR_190 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_190+currStrOff, "Cannot use '*' on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_190+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_190+currStrOff, " because it is not pointer.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(null,____BAH_COMPILER_VAR_190);
}
string__trimRight(&ct,nbUnaries);
r = string__str(&ct);
}
nv->type = r;
nv->name = ogName;
return nv;
}
};
i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((strcmp(fn->name, name) == 0)) {
struct variable* ____BAH_COMPILER_VAR_191 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_191->name = "";
____BAH_COMPILER_VAR_191->type = "";
____BAH_COMPILER_VAR_191->isConst = false;
____BAH_COMPILER_VAR_191->constVal = "";
____BAH_COMPILER_VAR_191->isArray = false;
____BAH_COMPILER_VAR_191->from = "";
____BAH_COMPILER_VAR_191->declScope= null;
____BAH_COMPILER_VAR_191->isGlobal = false;
____BAH_COMPILER_VAR_191->declRope= null;
____BAH_COMPILER_VAR_191->isReg = false;
____BAH_COMPILER_VAR_191->lastSet= null;
____BAH_COMPILER_VAR_191->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_191;
nv->name = name;
nv->type = "function(";
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
char * ____BAH_COMPILER_VAR_192 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nv->type);
unsigned int strLen_1 = strlen(arg->type);
;                            
            ____BAH_COMPILER_VAR_192 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_192+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_192+currStrOff, arg->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_192;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_193 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nv->type);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_193 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_193+currStrOff, nv->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_193+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_193;
}
};
fn->used = true;
char * ____BAH_COMPILER_VAR_194 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(")");
unsigned int strLen_1 = strlen(fn->returns->type);
unsigned int strLen_2 = strlen(nv->type);
;                            
            ____BAH_COMPILER_VAR_194 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_194+currStrOff, nv->type, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_194+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_194+currStrOff, fn->returns->type, strLen_1);
            currStrOff += strLen_1;
        
        }nv->type = ____BAH_COMPILER_VAR_194;
return nv;
}
};
return null;
};
struct variable* searchVarByToken(struct Tok* t,struct Elems* elems){
if ((t->bahRef!=null)) {
return t->bahRef;
}
struct string cont = string(t->cont);
removeVarUnar(&cont);
char * ____BAH_COMPILER_VAR_195 =string__str(&cont);return getRealVar(____BAH_COMPILER_VAR_195,elems);
};
struct variable* searchVirtVarByToken(struct Tok* t,struct Elems* elems){
if ((t->bahRef!=null)) {
return t->bahRef;
}
return searchVar(t->cont,elems);
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp = getCType(v->type,elems);
char * t = string__str(&tp);
char * ____BAH_COMPILER_VAR_196 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(v->name);
unsigned int strLen_2 = strlen(t);
;                            
            ____BAH_COMPILER_VAR_196 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_196+currStrOff, t, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_196+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_196+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }t = ____BAH_COMPILER_VAR_196;
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
struct func* ____BAH_COMPILER_VAR_197 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_197->name = "";
____BAH_COMPILER_VAR_197->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_197->args->length = 0;
            ____BAH_COMPILER_VAR_197->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_197->returns= null;
____BAH_COMPILER_VAR_197->isBinding = false;
____BAH_COMPILER_VAR_197->from = "";
____BAH_COMPILER_VAR_197->file = "";
____BAH_COMPILER_VAR_197->line = 1;
____BAH_COMPILER_VAR_197->isVar = false;
____BAH_COMPILER_VAR_197->used = false;
____BAH_COMPILER_VAR_197->code = null;
____BAH_COMPILER_VAR_197->isMut = false;
____BAH_COMPILER_VAR_197->isImported = false;
struct func* nf = ____BAH_COMPILER_VAR_197;
string__trimLeft(&cvt,9);
array(char)* memory = memoryAlloc(sizeof(array(char)));

memory->length = 0;
memory->elemSize = sizeof(char);
register long int j = 0;
while ((j<cvt.length)) {
char c = string__charAt(&cvt,j);
if ((c==41)) {
break;
}
struct variable* ____BAH_COMPILER_VAR_198 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_198->name = "";
____BAH_COMPILER_VAR_198->type = "";
____BAH_COMPILER_VAR_198->isConst = false;
____BAH_COMPILER_VAR_198->constVal = "";
____BAH_COMPILER_VAR_198->isArray = false;
____BAH_COMPILER_VAR_198->from = "";
____BAH_COMPILER_VAR_198->declScope= null;
____BAH_COMPILER_VAR_198->isGlobal = false;
____BAH_COMPILER_VAR_198->declRope= null;
____BAH_COMPILER_VAR_198->isReg = false;
____BAH_COMPILER_VAR_198->lastSet= null;
____BAH_COMPILER_VAR_198->isArg = false;
struct variable* arg = ____BAH_COMPILER_VAR_198;
char * ____BAH_COMPILER_VAR_199 =null;char * ____BAH_COMPILER_VAR_200 =intToStr(len(nf->args));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("arg_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_200);
;                            
            ____BAH_COMPILER_VAR_199 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_199+currStrOff, "arg_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_199+currStrOff, ____BAH_COMPILER_VAR_200, strLen_1);
            currStrOff += strLen_1;
        
        }arg->name = ____BAH_COMPILER_VAR_199;
while ((j<cvt.length)) {
c = string__charAt(&cvt,j);
if ((c==44)||(c==41)) {
break;
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
j = j+1;
};
arg->type = arrToStr(memory);
clear(memory);

    {
        unsigned long nLength = len(nf->args);
        if (nLength >= nf->args->length) {
            if (nLength >= nf->args->realLength) {
                if (nf->args->realLength != 0) {
                    nf->args->realLength *= 2;
                } else {
                    nf->args->realLength = 50;
                }
                void * newPtr = memoryRealloc(nf->args->data, (nf->args->realLength)*sizeof(struct variable*));
                nf->args->data = newPtr;
            }
            nf->args->data[len(nf->args)] = arg;
            nf->args->length = nLength+1;
        } else {
            nf->args->data[len(nf->args)] = arg;
        }
    }
    ;
if ((c==41)) {
break;
}
j = j+1;
};
j = j+1;
while ((j<cvt.length)) {
char c = string__charAt(&cvt,j);

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(char));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = c;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = c;
        }
    }
    ;
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_201 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_201->name = "";
____BAH_COMPILER_VAR_201->type = "";
____BAH_COMPILER_VAR_201->isConst = false;
____BAH_COMPILER_VAR_201->constVal = "";
____BAH_COMPILER_VAR_201->isArray = false;
____BAH_COMPILER_VAR_201->from = "";
____BAH_COMPILER_VAR_201->declScope= null;
____BAH_COMPILER_VAR_201->isGlobal = false;
____BAH_COMPILER_VAR_201->declRope= null;
____BAH_COMPILER_VAR_201->isReg = false;
____BAH_COMPILER_VAR_201->lastSet= null;
____BAH_COMPILER_VAR_201->isArg = false;
nf->returns = ____BAH_COMPILER_VAR_201;
nf->returns->name = "_return";
nf->returns->type = arrToStr(memory);
return nf;
};
struct func* searchFunc(char * name,struct Elems* elems,char inclCurr){
char * ogName = name;
if ((strcmp(name, "noCheck") == 0)) {
struct func* ____BAH_COMPILER_VAR_202 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_202->name = "";
____BAH_COMPILER_VAR_202->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_202->args->length = 0;
            ____BAH_COMPILER_VAR_202->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_202->returns= null;
____BAH_COMPILER_VAR_202->isBinding = false;
____BAH_COMPILER_VAR_202->from = "";
____BAH_COMPILER_VAR_202->file = "";
____BAH_COMPILER_VAR_202->line = 1;
____BAH_COMPILER_VAR_202->isVar = false;
____BAH_COMPILER_VAR_202->used = false;
____BAH_COMPILER_VAR_202->code = null;
____BAH_COMPILER_VAR_202->isMut = false;
____BAH_COMPILER_VAR_202->isImported = false;
struct func* fn = ____BAH_COMPILER_VAR_202;
fn->name = "noCheck";
return fn;
}
struct string n = string(name);
if (hasStructSep(&n)) {
struct string fnName = splitStructSepAfter(n);
string__trimRight(&n,fnName.length);
char c = string__charAt(&n,n.length-1);
if ((c==46)) {
string__trimRight(&n,1);
}
else {
string__trimRight(&n,2);
}
name = string__str(&n);
struct variable* v = searchVar(name,elems);
struct cStruct* s = searchStruct(v->type,elems);
char * ____BAH_COMPILER_VAR_203 =string__str(&fnName);struct structMemb* memb = searchStructMemb(____BAH_COMPILER_VAR_203,s,elems);
name = fnName.content;
char * ____BAH_COMPILER_VAR_204 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__");
unsigned int strLen_1 = strlen(name);
unsigned int strLen_2 = strlen(memb->from);
;                            
            ____BAH_COMPILER_VAR_204 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_204+currStrOff, memb->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_204+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_204+currStrOff, name, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_204;
}
array(struct func*)* fns = elems->fns;
register long int i = 0;
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
struct func* ____BAH_COMPILER_VAR_205 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_205->name = "";
____BAH_COMPILER_VAR_205->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_205->args->length = 0;
            ____BAH_COMPILER_VAR_205->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_205->returns= null;
____BAH_COMPILER_VAR_205->isBinding = false;
____BAH_COMPILER_VAR_205->from = "";
____BAH_COMPILER_VAR_205->file = "";
____BAH_COMPILER_VAR_205->line = 1;
____BAH_COMPILER_VAR_205->isVar = false;
____BAH_COMPILER_VAR_205->used = false;
____BAH_COMPILER_VAR_205->code = null;
____BAH_COMPILER_VAR_205->isMut = false;
____BAH_COMPILER_VAR_205->isImported = false;
struct func* nf = ____BAH_COMPILER_VAR_205;
nf->name = ogName;
struct string cvt = string(v->type);
if ((string__hasPrefix(&cvt,"function(")==0)) {
return null;
}
struct func* pfn = parseFnType(cvt);
nf->returns = pfn->returns;
nf->args = pfn->args;
return nf;
};
struct func* searchFuncByToken(struct Tok* t,struct Elems* elems){
if ((t->bahRef!=null)) {
return t->bahRef;
}
struct string ____BAH_COMPILER_VAR_206 =string(t->cont);char * fnName = splitStringBefore(____BAH_COMPILER_VAR_206,"(");
return searchFunc(fnName,elems,true);
};
char RCPavailable();
char * declareStructMethods(struct variable* v,struct cStruct* s,struct Elems* elems){
char * code = "";
array(struct structMemb*)* members = s->members;
struct string typec = string(v->type);
char * sep = ".";
char * amp = "&";
if (string__count(&typec,"*")) {
sep = "->";
amp = "";
}
register long int i = 0;
while ((i<len(members))) {
struct structMemb* m = members->data[i];
struct string cmpt = string(m->type);
char declared = false;
if ((strlen(m->def)>0)) {
char * ____BAH_COMPILER_VAR_207 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->def);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(m->name);
unsigned int strLen_4 = strlen(sep);
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_207 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, code, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_207+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_207+currStrOff, m->def, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_207+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_207;
declared = true;
}
if ((string__hasPrefix(&cmpt,"[]")==1)) {
string__trimLeft(&cmpt,2);
char * cmptstr = string__str(&cmpt);
struct string elemCType = getCType(cmptstr,elems);
char * elemCTypeStr = string__str(&elemCType);
char * ____BAH_COMPILER_VAR_208 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(elemCTypeStr);
unsigned int strLen_1 = strlen(");\n            ");
unsigned int strLen_2 = strlen("->elemSize = sizeof(");
unsigned int strLen_3 = strlen(m->name);
unsigned int strLen_4 = strlen(sep);
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen("->length = 0;\n            ");
unsigned int strLen_7 = strlen(m->name);
unsigned int strLen_8 = strlen(sep);
unsigned int strLen_9 = strlen(v->name);
unsigned int strLen_10 = strlen(")));\n            ");
unsigned int strLen_11 = strlen(elemCTypeStr);
unsigned int strLen_12 = strlen(" = memoryAlloc(sizeof(array(");
unsigned int strLen_13 = strlen(m->name);
unsigned int strLen_14 = strlen(sep);
unsigned int strLen_15 = strlen(v->name);
unsigned int strLen_16 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_208 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, code, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, v->name, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, sep, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, m->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, " = memoryAlloc(sizeof(array(", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, elemCTypeStr, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, ")));\n            ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, v->name, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, sep, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, m->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, "->length = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_208+currStrOff, "->elemSize = sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_208+currStrOff, elemCTypeStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_208+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_208;
declared = true;
}
else if ((string__hasPrefix(&cmpt,"map:")==1)) {
string__trimLeft(&cmpt,4);
char * ____BAH_COMPILER_VAR_209 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(" = mapWrapper();\n");
unsigned int strLen_2 = strlen(sep);
unsigned int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_209 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_209+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_209+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_209+currStrOff, " = mapWrapper();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_210 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_209);
;                            
            ____BAH_COMPILER_VAR_210 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_210+currStrOff, ____BAH_COMPILER_VAR_209, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_210;
declared = true;
}
else if ((string__hasPrefix(&cmpt,"chan:")==1)) {
string__trimLeft(&cmpt,5);
char * ____BAH_COMPILER_VAR_211 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(" = channel();\n");
unsigned int strLen_2 = strlen(sep);
unsigned int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_211 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_211+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_211+currStrOff, " = channel();\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_212 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_211);
;                            
            ____BAH_COMPILER_VAR_212 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_212+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_212+currStrOff, ____BAH_COMPILER_VAR_211, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_212;
declared = true;
}
if (isRCPpointerType(m->type)&&(declared==false)) {
char * ____BAH_COMPILER_VAR_213 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen("= null;\n");
unsigned int strLen_2 = strlen(sep);
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_213 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, code, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_213+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_213+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_213+currStrOff, "= null;\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_213;
}
i = i+1;
};
if ((s->isBinding==false)) {
long int found = 0;
i = 0;
for (; (i<len(s->methods)); ++i) {
struct func* m = s->methods->data[i];
if ((strcmp(m->name, "_init") == 0)) {
char * ____BAH_COMPILER_VAR_214 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(amp);
unsigned int strLen_3 = strlen("(");
unsigned int strLen_4 = strlen(m->name);
unsigned int strLen_5 = strlen(sep);
unsigned int strLen_6 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_214 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, sep, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, m->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_214+currStrOff, amp, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_214+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_214+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_215 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(NEXT_LINE);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_214);
;                            
            ____BAH_COMPILER_VAR_215 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_215+currStrOff, ____BAH_COMPILER_VAR_214, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_215;
++found;
}
else if ((strcmp(m->name, "_end") == 0)) {
if ((strcmp(sep, "->") == 0)) {
char * ____BAH_COMPILER_VAR_216 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(sep);
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen("memoryOnEnd(");
;                            
            ____BAH_COMPILER_VAR_216 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, "memoryOnEnd(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_216+currStrOff, sep, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_216+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_216+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_217 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_216);
;                            
            ____BAH_COMPILER_VAR_217 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_217+currStrOff, ____BAH_COMPILER_VAR_216, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_217;
}
++found;
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
char * ____BAH_COMPILER_VAR_218 =null;char * ____BAH_COMPILER_VAR_219 =intToStr(NB_COMP_VAR);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("____BAH_COMPILER_VAR_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_219);
;                            
            ____BAH_COMPILER_VAR_218 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_218+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_218+currStrOff, ____BAH_COMPILER_VAR_219, strLen_1);
            currStrOff += strLen_1;
        
        }char * name = ____BAH_COMPILER_VAR_218;
NB_COMP_VAR = NB_COMP_VAR+1;
return name;
};
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
char varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){
if ((arr==null)) {
return false;
}
register long int j = 0;
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
register long int i = 0;
for (; (i<len(a)); ++i) {
long int c = a->data[i];
c = c-(long int)97;
if ((c<0)) {
c = 0-c;
}
c = c%((long int)122-(long int)97);
c = c+(long int)97;

    {
        unsigned long nLength = i;
        if (nLength >= a->length) {
            if (nLength >= a->realLength) {
                if (a->realLength != 0) {
                    a->realLength *= 2;
                } else {
                    a->realLength = 50;
                }
                void * newPtr = memoryRealloc(a->data, (a->realLength)*sizeof(char));
                a->data = newPtr;
            }
            a->data[i] = (char)c;
            a->length = nLength+1;
        } else {
            a->data[i] = (char)c;
        }
    }
    ;
};
return arrToStr(a);
};
void makeInit(){
char * name = "__BAH_init";
if ((isObject==true)) {
char * ____BAH_COMPILER_VAR_220 =null;char * ____BAH_COMPILER_VAR_221 =pathToVarName(compilerState.currentFile);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(name);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_221);
;                            
            ____BAH_COMPILER_VAR_220 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_220+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_220+currStrOff, ____BAH_COMPILER_VAR_221, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_220;
}
char * evals = "";
char * ____BAH_COMPILER_VAR_222 =null;char * ____BAH_COMPILER_VAR_223 =intToStr(len(compilerState.evals));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_223);
unsigned int strLen_1 = strlen("] = {");
unsigned int strLen_2 = strlen("volatile struct __eval_binding __tmp__evals_bindings[");
;                            
            ____BAH_COMPILER_VAR_222 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_222+currStrOff, "volatile struct __eval_binding __tmp__evals_bindings[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_222+currStrOff, ____BAH_COMPILER_VAR_223, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_222+currStrOff, "] = {", strLen_1);
            currStrOff += strLen_1;
        
        }char * evalsTMPDecl = ____BAH_COMPILER_VAR_222;
register long int i = 0;
for (; (i<len(compilerState.evals)); ++i) {
char * e = compilerState.evals->data[i];
char * ____BAH_COMPILER_VAR_224 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(e);
unsigned int strLen_1 = strlen("\n        }");
unsigned int strLen_2 = strlen("\",\n            .evalFn = __Bah_eval_");
unsigned int strLen_3 = strlen(e);
unsigned int strLen_4 = strlen("{\n            .name = \"");
;                            
            ____BAH_COMPILER_VAR_224 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, "{\n            .name = \"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, e, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_224+currStrOff, "\",\n            .evalFn = __Bah_eval_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_224+currStrOff, e, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_224+currStrOff, "\n        }", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_225 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evalsTMPDecl);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_224);
;                            
            ____BAH_COMPILER_VAR_225 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_225+currStrOff, ____BAH_COMPILER_VAR_224, strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_225;
if ((i+1!=len(compilerState.evals))) {
char * ____BAH_COMPILER_VAR_226 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evalsTMPDecl);
unsigned int strLen_1 = strlen(",\n");
;                            
            ____BAH_COMPILER_VAR_226 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_226+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_226+currStrOff, ",\n", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_226;
}
else {
char * ____BAH_COMPILER_VAR_227 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evalsTMPDecl);
unsigned int strLen_1 = strlen("};");
;                            
            ____BAH_COMPILER_VAR_227 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_227+currStrOff, evalsTMPDecl, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_227+currStrOff, "};", strLen_1);
            currStrOff += strLen_1;
        
        }evalsTMPDecl = ____BAH_COMPILER_VAR_227;
}
};
if ((len(compilerState.evals)!=0)) {
char * ____BAH_COMPILER_VAR_228 =null;char * ____BAH_COMPILER_VAR_229 =intToStr(len(compilerState.evals));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_229);
unsigned int strLen_1 = strlen(";");
unsigned int strLen_2 = strlen("__evals_bindings = __tmp__evals_bindings; __evals_length = ");
;                            
            ____BAH_COMPILER_VAR_228 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_228+currStrOff, "__evals_bindings = __tmp__evals_bindings; __evals_length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_228+currStrOff, ____BAH_COMPILER_VAR_229, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_228+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }evals = ____BAH_COMPILER_VAR_228;
}
else {
evalsTMPDecl = "";
}
char * ____BAH_COMPILER_VAR_230 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(name);
unsigned int strLen_1 = strlen("() {\n        ");
unsigned int strLen_2 = strlen("\n    void __attribute__((optimize(\"O0\"))) ");
unsigned int strLen_3 = strlen(evalsTMPDecl);
unsigned int strLen_4 = strlen("\n    ");
;                            
            ____BAH_COMPILER_VAR_230 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_230+currStrOff, "\n    ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_230+currStrOff, evalsTMPDecl, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_230+currStrOff, "\n    void __attribute__((optimize(\"O0\"))) ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_230+currStrOff, name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_230+currStrOff, "() {\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_231 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(evals);
unsigned int strLen_1 = strlen("\n    };\n    ");
unsigned int strLen_2 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_231 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_231+currStrOff, "\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, evals, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_231+currStrOff, "\n    };\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_230), rope__add(INIT, rope(____BAH_COMPILER_VAR_231))));
};
char isOutterScope(void * ce,struct Elems* e){
while ((e!=null)) {
if ((ce==e)) {
return true;
}
e = e->parent;
};
return false;
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r = rope("");
if (strHasPrefix(v->type,"[]")) {
char * ____BAH_COMPILER_VAR_232 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_232+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_232+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_232+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_232));
}
else if (strHasPrefix(v->type,"chan:")) {
char * ____BAH_COMPILER_VAR_233 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_233 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_233+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_233+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_233));
}
else {
if (strHasPrefix(v->type,"map:")) {
struct variable* ____BAH_COMPILER_VAR_234 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_234->name = "";
____BAH_COMPILER_VAR_234->type = "";
____BAH_COMPILER_VAR_234->isConst = false;
____BAH_COMPILER_VAR_234->constVal = "";
____BAH_COMPILER_VAR_234->isArray = false;
____BAH_COMPILER_VAR_234->from = "";
____BAH_COMPILER_VAR_234->declScope= null;
____BAH_COMPILER_VAR_234->isGlobal = false;
____BAH_COMPILER_VAR_234->declRope= null;
____BAH_COMPILER_VAR_234->isReg = false;
____BAH_COMPILER_VAR_234->lastSet= null;
____BAH_COMPILER_VAR_234->isArg = false;
struct variable* nv = ____BAH_COMPILER_VAR_234;
*nv = *v;
v = nv;
v->type = "mapWrapper*";
}
char isPointer = isRCPpointerType(v->type);
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(s->isBinding==false)) {
if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_235 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_235 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_235+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_235+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_235+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_235));
}
else {
char * ____BAH_COMPILER_VAR_236 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 1);\n");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_236 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_236+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_236+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_236+currStrOff, "), 1);\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_236));
}
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_237 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("RCP_decr(");
;                            
            ____BAH_COMPILER_VAR_237 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_237+currStrOff, "RCP_decr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_237+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_237+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_237));
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
char * ____BAH_COMPILER_VAR_238 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 0);");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_238 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_238+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_238+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_238+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_238+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_238+currStrOff, "), 0);", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_238);
}
char * ____BAH_COMPILER_VAR_239 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(");");
unsigned int strLen_2 = strlen("RCP_incr(");
;                            
            ____BAH_COMPILER_VAR_239 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_239+currStrOff, "RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_239+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_239+currStrOff, ");", strLen_1);
            currStrOff += strLen_1;
        
        }return rope(____BAH_COMPILER_VAR_239);
};
char RCPavailable(){
return (RCPenabled==true);
};
void beginRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
if ((RCPavailable()==false)) {
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if (varInArr(v,excl)) {
continue;
}
if ((v->isGlobal==false)&&isRCPtype(v->type,elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(v,elems));
}
};
};
void beginRCPscopeLeaky(struct Elems* elems){
if ((RCPavailable()==false)) {
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if ((v->isGlobal==false)&&(v->declScope==elems)&&isRCPtype(v->type,elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(v,elems));
}
};
};
void removeDefs(struct Elems* elems){
register long int i = 0;
for (; (i<len(elems->defined)); ++i) {
char * ____BAH_COMPILER_VAR_240 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(elems->defined->data[i]);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("\n#undef ");
;                            
            ____BAH_COMPILER_VAR_240 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_240+currStrOff, "\n#undef ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_240+currStrOff, elems->defined->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_240+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_240));
};
};
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable excl){
if ((RCPavailable()==false)) {
removeDefs(elems);
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if (varInArr(v,excl)) {
continue;
}
if ((v->isGlobal==false)&&isRCPtype(v->type,elems)) {
OUTPUT = rope__add(OUTPUT, decrVar(v,elems));
}
};
removeDefs(elems);
};
void endRCPscopeLeaky(struct Elems* elems,struct variable* excl){
if ((RCPavailable()==false)) {
removeDefs(elems);
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if ((excl!=null)&&(strcmp(excl->name, v->name) == 0)) {
continue;
}
if ((v->isGlobal==false)&&(v->declScope==elems)&&isRCPtype(v->type,elems)) {
OUTPUT = rope__add(OUTPUT, decrVar(v,elems));
}
};
removeDefs(elems);
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* ____BAH_COMPILER_VAR_241 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_241->name = "";
____BAH_COMPILER_VAR_241->type = "";
____BAH_COMPILER_VAR_241->isConst = false;
____BAH_COMPILER_VAR_241->constVal = "";
____BAH_COMPILER_VAR_241->isArray = false;
____BAH_COMPILER_VAR_241->from = "";
____BAH_COMPILER_VAR_241->declScope= null;
____BAH_COMPILER_VAR_241->isGlobal = false;
____BAH_COMPILER_VAR_241->declRope= null;
____BAH_COMPILER_VAR_241->isReg = false;
____BAH_COMPILER_VAR_241->lastSet= null;
____BAH_COMPILER_VAR_241->isArg = false;
struct variable* av = ____BAH_COMPILER_VAR_241;
av->type = t;
av->declScope = elems;
av->name = genCompilerVar();

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = av;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = av;
        }
    }
    ;
struct string cType = getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_242 =null;char * ____BAH_COMPILER_VAR_243 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(c);
unsigned int strLen_1 = strlen(";");
unsigned int strLen_2 = strlen(" =");
unsigned int strLen_3 = strlen(av->name);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_243);
;                            
            ____BAH_COMPILER_VAR_242 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_242+currStrOff, ____BAH_COMPILER_VAR_243, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_242+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_242+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_242+currStrOff, " =", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_242+currStrOff, c, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_242+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_242));
return av->name;
};
char RCPselfRef(struct variable* v){
register long int i = 0;
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

        char ____BAH_COMPILER_VAR_244 = 0;
        for(int i=noVOfns->length-1; i!=-1;i--) {
            if (noVOfns->data[i] != 0 && strcmp(noVOfns->data[i], currentFn->name) == 0) {
                ____BAH_COMPILER_VAR_244=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_244) {
return false;
}
}
return true;
};
struct verboseOutVar verboseOutTransformVar(struct variable* v,char * cont,struct Elems* elems){
struct verboseOutVar ____BAH_COMPILER_VAR_245 = {};
____BAH_COMPILER_VAR_245.markup= null;
____BAH_COMPILER_VAR_245.content= null;
#define rv ____BAH_COMPILER_VAR_245
char * ogCont = cont;
if ((strcmp(v->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_246 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("__Bah_safe_string(");
;                            
            ____BAH_COMPILER_VAR_246 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_246+currStrOff, "__Bah_safe_string(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_246+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_246+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_246;
}
char * ____BAH_COMPILER_VAR_247 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(", ");
unsigned int strLen_1 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_247 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_247+currStrOff, ", ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_247+currStrOff, cont, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_247;
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
char * ____BAH_COMPILER_VAR_248 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ASCII_RESET);
unsigned int strLen_1 = strlen("{");
;                            
            ____BAH_COMPILER_VAR_248 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_248+currStrOff, ASCII_RESET, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_248+currStrOff, "{", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_248;
cont = "";
register long int i = 0;
for (; (i<len(s->members)); ++i) {
struct variable* m = s->members->data[i];
char * ____BAH_COMPILER_VAR_249 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(m->name);
unsigned int strLen_2 = strlen(")");
unsigned int strLen_3 = strlen(ogCont);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_249 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_249+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_249+currStrOff, ogCont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_249+currStrOff, ")", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_249+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_249+currStrOff, m->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct verboseOutVar mv = verboseOutTransformVar(m,____BAH_COMPILER_VAR_249,elems);
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_250 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_250 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_250+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_250+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_250;
}
char * ____BAH_COMPILER_VAR_251 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen(mv.markup);
;                            
            ____BAH_COMPILER_VAR_251 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_251+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_251+currStrOff, mv.markup, strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_251;
char * ____BAH_COMPILER_VAR_252 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(cont);
unsigned int strLen_1 = strlen(mv.content);
;                            
            ____BAH_COMPILER_VAR_252 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_252+currStrOff, cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_252+currStrOff, mv.content, strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_252;
};
char * ____BAH_COMPILER_VAR_253 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen("}");
;                            
            ____BAH_COMPILER_VAR_253 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_253+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_253+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }ct = ____BAH_COMPILER_VAR_253;
}
}
char * ____BAH_COMPILER_VAR_254 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ct);
unsigned int strLen_1 = strlen(ASCII_RESET);
unsigned int strLen_2 = strlen(ASCII_MAGENTA);
unsigned int strLen_3 = strlen(" = ");
unsigned int strLen_4 = strlen(ASCII_RESET);
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen(ASCII_BLUE);
;                            
            ____BAH_COMPILER_VAR_254 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, ASCII_BLUE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, ASCII_RESET, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_254+currStrOff, ASCII_MAGENTA, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_254+currStrOff, ct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_254+currStrOff, ASCII_RESET, strLen_1);
            currStrOff += strLen_1;
        
        }rv.markup = ____BAH_COMPILER_VAR_254;
rv.content = cont;
return rv;

#undef rv
};
struct verboseOutVar verboseOutTransformTok(struct Tok* t,struct Elems* elems){
if ((t->type==TOKEN_TYPE_VAR)&&(t->isOper==false)) {
struct variable* v = searchVar(t->cont,elems);
if ((v==null)) {
return verboseOutTransformVar(v,t->cont,elems);
}
}
struct variable ____BAH_COMPILER_VAR_255 = {};
____BAH_COMPILER_VAR_255.name = "";
____BAH_COMPILER_VAR_255.type = "";
____BAH_COMPILER_VAR_255.isConst = false;
____BAH_COMPILER_VAR_255.constVal = "";
____BAH_COMPILER_VAR_255.isArray = false;
____BAH_COMPILER_VAR_255.from = "";
____BAH_COMPILER_VAR_255.declScope= null;
____BAH_COMPILER_VAR_255.isGlobal = false;
____BAH_COMPILER_VAR_255.declRope= null;
____BAH_COMPILER_VAR_255.isReg = false;
____BAH_COMPILER_VAR_255.lastSet= null;
____BAH_COMPILER_VAR_255.isArg = false;
____BAH_COMPILER_VAR_255.name = "(value)";
____BAH_COMPILER_VAR_255.type = getTypeFromToken(t,true,elems);
#define v ____BAH_COMPILER_VAR_255
return verboseOutTransformVar(&v,t->cont,elems);

#undef v
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
register long int i = 0;
for (; (i<len(fn->args)); ++i) {
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
register long int j = 0;
for (; (j<len(fn->args)); ++j) {
struct variable* a = fn->args->data[j];
if ((j!=0)) {
char * ____BAH_COMPILER_VAR_256 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgs);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_256 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_256+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_256+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_256;
}
struct Tok t = args->data[j];
struct verboseOutVar v = verboseOutTransformVar(a,t.cont,elems);
char * ____BAH_COMPILER_VAR_257 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgs);
unsigned int strLen_1 = strlen(v.markup);
;                            
            ____BAH_COMPILER_VAR_257 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_257+currStrOff, fnArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_257+currStrOff, v.markup, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgs = ____BAH_COMPILER_VAR_257;
char * ____BAH_COMPILER_VAR_258 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgsValues);
unsigned int strLen_1 = strlen(v.content);
;                            
            ____BAH_COMPILER_VAR_258 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_258+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_258+currStrOff, v.content, strLen_1);
            currStrOff += strLen_1;
        
        }fnArgsValues = ____BAH_COMPILER_VAR_258;
};
char * ____BAH_COMPILER_VAR_259 =null;char * ____BAH_COMPILER_VAR_260 =intToStr(lineNb);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(":");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_260);
unsigned int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_259 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_259+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_259+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_259+currStrOff, ____BAH_COMPILER_VAR_260, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_259;
char * ____BAH_COMPILER_VAR_261 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnArgsValues);
unsigned int strLen_1 = strlen(");\n    //\n    ");
unsigned int strLen_2 = strlen("\\n\"");
unsigned int strLen_3 = strlen(ASCII_RESET);
unsigned int strLen_4 = strlen(line);
unsigned int strLen_5 = strlen(ASCII_GREEN);
unsigned int strLen_6 = strlen(") -> ");
unsigned int strLen_7 = strlen(fnArgs);
unsigned int strLen_8 = strlen("(");
unsigned int strLen_9 = strlen(ASCII_RESET);
unsigned int strLen_10 = strlen(fn->name);
unsigned int strLen_11 = strlen(nameColor);
unsigned int strLen_12 = strlen("\n    //Verbose Runtime\n        printf(\"[VO] calling: ");
;                            
            ____BAH_COMPILER_VAR_261 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO] calling: ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, nameColor, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, fn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, ASCII_RESET, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, fnArgs, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, ") -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_261+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_261+currStrOff, fnArgsValues, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_261+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_261);
if (isGlobal()) {
INIT = rope__add(INIT, verboseOut);
}
else {
OUTPUT = rope__add(OUTPUT, verboseOut);
}
};
void verboseOutOper(struct Tok* pt,struct Tok* nt,long int lineNb,struct Elems* elems){
if ((verboseOutGuard()==false)) {
return;
}
struct verboseOutVar pvo = verboseOutTransformTok(pt,elems);
struct verboseOutVar nvo = verboseOutTransformTok(nt,elems);
char * ____BAH_COMPILER_VAR_262 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pvo.content);
unsigned int strLen_1 = strlen(nvo.content);
;                            
            ____BAH_COMPILER_VAR_262 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_262+currStrOff, pvo.content, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_262+currStrOff, nvo.content, strLen_1);
            currStrOff += strLen_1;
        
        }char * values = ____BAH_COMPILER_VAR_262;
char * ____BAH_COMPILER_VAR_263 =null;char * ____BAH_COMPILER_VAR_264 =intToStr(lineNb);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(":");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_264);
unsigned int strLen_2 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_263 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_263+currStrOff, compilerState.currentFile, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_263+currStrOff, ":", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_263+currStrOff, ____BAH_COMPILER_VAR_264, strLen_1);
            currStrOff += strLen_1;
        
        }char * line = ____BAH_COMPILER_VAR_263;
char * ____BAH_COMPILER_VAR_265 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(values);
unsigned int strLen_1 = strlen(");\n    //\n    ");
unsigned int strLen_2 = strlen("\\n\"");
unsigned int strLen_3 = strlen(ASCII_RESET);
unsigned int strLen_4 = strlen(line);
unsigned int strLen_5 = strlen(ASCII_GREEN);
unsigned int strLen_6 = strlen(" -> ");
unsigned int strLen_7 = strlen(nvo.markup);
unsigned int strLen_8 = strlen(" AND ");
unsigned int strLen_9 = strlen(pvo.markup);
unsigned int strLen_10 = strlen("\n    //Verbose Runtime\n        printf(\"[VO]    oper: ");
;                            
            ____BAH_COMPILER_VAR_265 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, "\n    //Verbose Runtime\n        printf(\"[VO]    oper: ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, pvo.markup, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, " AND ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, nvo.markup, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, " -> ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, ASCII_GREEN, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, line, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, ASCII_RESET, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_265+currStrOff, "\\n\"", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_265+currStrOff, values, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_265+currStrOff, ");\n    //\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* verboseOut = rope(____BAH_COMPILER_VAR_265);
if (isGlobal()) {
INIT = rope__add(INIT, verboseOut);
}
else {
OUTPUT = rope__add(OUTPUT, verboseOut);
}
};
struct cacheFile {
char * file;
long int last;
char * ver;
long int date;
long int mem;
long int opti;
array(char *)* files;
};
array(struct cacheFile*)* cache;
void readCache(){
struct fileStream ____BAH_COMPILER_VAR_266 = {};
____BAH_COMPILER_VAR_266.handle= null;
____BAH_COMPILER_VAR_266.name= null;
#define fs ____BAH_COMPILER_VAR_266
char * ____BAH_COMPILER_VAR_267 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_267 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_267+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_267+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fileStream__open(&fs,____BAH_COMPILER_VAR_267,"r");
if ((fileStream__isValid(&fs)==0)||(fileStream__getSize(&fs)==0)) {
char * ____BAH_COMPILER_VAR_268 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache");
;                            
            ____BAH_COMPILER_VAR_268 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_268+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_268+currStrOff, "cache", strLen_1);
            currStrOff += strLen_1;
        
        }mkdir(____BAH_COMPILER_VAR_268,S_IRWXU);
char * ____BAH_COMPILER_VAR_269 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_269 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_269+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_269+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fileStream__createFile(&fs,____BAH_COMPILER_VAR_269);
return;
}
char * ____BAH_COMPILER_VAR_270 =fileStream__readContent(&fs);struct jsonElement* j = parseJson(____BAH_COMPILER_VAR_270);
fileStream__close(&fs);
array(struct cacheFile**)* ____BAH_COMPILER_VAR_271 = &cache;
struct cacheFile*** ____BAH_COMPILER_VAR_272 = 0;
char ** ____BAH_COMPILER_VAR_274 = (char **)((char*)(____BAH_COMPILER_VAR_272) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_275 = __reflect(____BAH_COMPILER_VAR_274, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_276 = (long int*)((char*)(____BAH_COMPILER_VAR_272) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_277 = __reflect(____BAH_COMPILER_VAR_276, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_278 = (char **)((char*)(____BAH_COMPILER_VAR_272) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_279 = __reflect(____BAH_COMPILER_VAR_278, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_280 = (long int*)((char*)(____BAH_COMPILER_VAR_272) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_281 = __reflect(____BAH_COMPILER_VAR_280, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_282 = (long int*)((char*)(____BAH_COMPILER_VAR_272) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_283 = __reflect(____BAH_COMPILER_VAR_282, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_284 = (long int*)((char*)(____BAH_COMPILER_VAR_272) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_285 = __reflect(____BAH_COMPILER_VAR_284, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_286 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_272) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_287 = 0;
struct reflectElement ____BAH_COMPILER_VAR_288 = __reflect(____BAH_COMPILER_VAR_287, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_289 = ____BAH_COMPILER_VAR_288;
        struct reflectElement ____BAH_COMPILER_VAR_290 = __reflect(____BAH_COMPILER_VAR_286, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_289, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_273 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_273->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_273->length = 7;
        ____BAH_COMPILER_VAR_273->data = memoryAlloc(____BAH_COMPILER_VAR_273->length * ____BAH_COMPILER_VAR_273->elemSize);
        ____BAH_COMPILER_VAR_273->data[0] = ____BAH_COMPILER_VAR_275;
____BAH_COMPILER_VAR_273->data[1] = ____BAH_COMPILER_VAR_277;
____BAH_COMPILER_VAR_273->data[2] = ____BAH_COMPILER_VAR_279;
____BAH_COMPILER_VAR_273->data[3] = ____BAH_COMPILER_VAR_281;
____BAH_COMPILER_VAR_273->data[4] = ____BAH_COMPILER_VAR_283;
____BAH_COMPILER_VAR_273->data[5] = ____BAH_COMPILER_VAR_285;
____BAH_COMPILER_VAR_273->data[6] = ____BAH_COMPILER_VAR_290;
struct reflectElement ____BAH_COMPILER_VAR_291 = __reflect(____BAH_COMPILER_VAR_272, sizeof(struct cacheFile), "cacheFile**", "", 0, 0, 1, ____BAH_COMPILER_VAR_273, 0);

        struct reflectElement ____BAH_COMPILER_VAR_292 = ____BAH_COMPILER_VAR_291;
        struct reflectElement ____BAH_COMPILER_VAR_293 = __reflect(____BAH_COMPILER_VAR_271, sizeof(array(struct cacheFile**)*), "[]cacheFile**", "&cache", 1, &____BAH_COMPILER_VAR_292, 0, 0, 0);
jsonElement__scan(j,____BAH_COMPILER_VAR_293);
if ((cache!=null)) {
}

#undef fs
};
struct cacheFile* getCacheFile(char * s){
if ((cache==null)) {
return null;
}
register long int i = 0;
for (; (i<len(cache)); ++i) {
struct cacheFile* c = cache->data[i];
if ((strcmp(c->file, s) == 0)&&(c->mem==RCPlevel)&&(c->opti==isOptimized)) {
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
struct cacheFile* ____BAH_COMPILER_VAR_294 = memoryAlloc(sizeof(struct cacheFile));
____BAH_COMPILER_VAR_294->file= null;
____BAH_COMPILER_VAR_294->ver= null;
____BAH_COMPILER_VAR_294->files = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_294->files->length = 0;
            ____BAH_COMPILER_VAR_294->files->elemSize = sizeof(char *);
            struct cacheFile* c = ____BAH_COMPILER_VAR_294;
c->file = f;
c->ver = BAH_VERSION;
c->mem = RCPlevel;
c->opti = isOptimized;
c->date = getTimeUnix();
c->last = getLastModified(f);
if ((cache==null)) {
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
}

    {
        unsigned long nLength = len(cache);
        if (nLength >= cache->length) {
            if (nLength >= cache->realLength) {
                if (cache->realLength != 0) {
                    cache->realLength *= 2;
                } else {
                    cache->realLength = 50;
                }
                void * newPtr = memoryRealloc(cache->data, (cache->realLength)*sizeof(struct cacheFile*));
                cache->data = newPtr;
            }
            cache->data[len(cache)] = c;
            cache->length = nLength+1;
        } else {
            cache->data[len(cache)] = c;
        }
    }
    ;
};
void writeCache(){
struct fileStream ____BAH_COMPILER_VAR_295 = {};
____BAH_COMPILER_VAR_295.handle= null;
____BAH_COMPILER_VAR_295.name= null;
#define fs ____BAH_COMPILER_VAR_295
char * ____BAH_COMPILER_VAR_296 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("cache/cache.json");
;                            
            ____BAH_COMPILER_VAR_296 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_296+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_296+currStrOff, "cache/cache.json", strLen_1);
            currStrOff += strLen_1;
        
        }fileStream__open(&fs,____BAH_COMPILER_VAR_296,"w");
array(struct cacheFile*)* ____BAH_COMPILER_VAR_297 = cache;
struct cacheFile** ____BAH_COMPILER_VAR_298 = 0;
char ** ____BAH_COMPILER_VAR_300 = (char **)((char*)(____BAH_COMPILER_VAR_298) + offsetof(struct cacheFile, file));
struct reflectElement ____BAH_COMPILER_VAR_301 = __reflect(____BAH_COMPILER_VAR_300, sizeof(char *), "cpstring", "file", 0, 0, 0, 0, offsetof(struct cacheFile, file));
long int* ____BAH_COMPILER_VAR_302 = (long int*)((char*)(____BAH_COMPILER_VAR_298) + offsetof(struct cacheFile, last));
struct reflectElement ____BAH_COMPILER_VAR_303 = __reflect(____BAH_COMPILER_VAR_302, sizeof(long int), "int", "last", 0, 0, 0, 0, offsetof(struct cacheFile, last));
char ** ____BAH_COMPILER_VAR_304 = (char **)((char*)(____BAH_COMPILER_VAR_298) + offsetof(struct cacheFile, ver));
struct reflectElement ____BAH_COMPILER_VAR_305 = __reflect(____BAH_COMPILER_VAR_304, sizeof(char *), "cpstring", "ver", 0, 0, 0, 0, offsetof(struct cacheFile, ver));
long int* ____BAH_COMPILER_VAR_306 = (long int*)((char*)(____BAH_COMPILER_VAR_298) + offsetof(struct cacheFile, date));
struct reflectElement ____BAH_COMPILER_VAR_307 = __reflect(____BAH_COMPILER_VAR_306, sizeof(long int), "int", "date", 0, 0, 0, 0, offsetof(struct cacheFile, date));
long int* ____BAH_COMPILER_VAR_308 = (long int*)((char*)(____BAH_COMPILER_VAR_298) + offsetof(struct cacheFile, mem));
struct reflectElement ____BAH_COMPILER_VAR_309 = __reflect(____BAH_COMPILER_VAR_308, sizeof(long int), "int", "mem", 0, 0, 0, 0, offsetof(struct cacheFile, mem));
long int* ____BAH_COMPILER_VAR_310 = (long int*)((char*)(____BAH_COMPILER_VAR_298) + offsetof(struct cacheFile, opti));
struct reflectElement ____BAH_COMPILER_VAR_311 = __reflect(____BAH_COMPILER_VAR_310, sizeof(long int), "int", "opti", 0, 0, 0, 0, offsetof(struct cacheFile, opti));
array(char *)** ____BAH_COMPILER_VAR_312 = (array(char *)**)((char*)(____BAH_COMPILER_VAR_298) + offsetof(struct cacheFile, files));
char ** ____BAH_COMPILER_VAR_313 = 0;
struct reflectElement ____BAH_COMPILER_VAR_314 = __reflect(____BAH_COMPILER_VAR_313, sizeof(char *), "cpstring", "", 0, 0, 0, 0, 0);

        struct reflectElement ____BAH_COMPILER_VAR_315 = ____BAH_COMPILER_VAR_314;
        struct reflectElement ____BAH_COMPILER_VAR_316 = __reflect(____BAH_COMPILER_VAR_312, sizeof(array(char *)*), "[]cpstring", "files", 1, &____BAH_COMPILER_VAR_315, 0, 0, offsetof(struct cacheFile, files));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_299 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_299->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_299->length = 7;
        ____BAH_COMPILER_VAR_299->data = memoryAlloc(____BAH_COMPILER_VAR_299->length * ____BAH_COMPILER_VAR_299->elemSize);
        ____BAH_COMPILER_VAR_299->data[0] = ____BAH_COMPILER_VAR_301;
____BAH_COMPILER_VAR_299->data[1] = ____BAH_COMPILER_VAR_303;
____BAH_COMPILER_VAR_299->data[2] = ____BAH_COMPILER_VAR_305;
____BAH_COMPILER_VAR_299->data[3] = ____BAH_COMPILER_VAR_307;
____BAH_COMPILER_VAR_299->data[4] = ____BAH_COMPILER_VAR_309;
____BAH_COMPILER_VAR_299->data[5] = ____BAH_COMPILER_VAR_311;
____BAH_COMPILER_VAR_299->data[6] = ____BAH_COMPILER_VAR_316;
struct reflectElement ____BAH_COMPILER_VAR_317 = __reflect(____BAH_COMPILER_VAR_298, sizeof(struct cacheFile), "cacheFile*", "", 0, 0, 1, ____BAH_COMPILER_VAR_299, 0);

        struct reflectElement ____BAH_COMPILER_VAR_318 = ____BAH_COMPILER_VAR_317;
        struct reflectElement ____BAH_COMPILER_VAR_319 = __reflect(____BAH_COMPILER_VAR_297, sizeof(array(struct cacheFile*)*), "[]cacheFile*", "cache", 1, &____BAH_COMPILER_VAR_318, 0, 0, 0);
char * ____BAH_COMPILER_VAR_320 =toJson(____BAH_COMPILER_VAR_319);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_320);
fileStream__close(&fs);

#undef fs
};
char isValidCacheFile(struct cacheFile* cf){
if ((cf==null)||(cf->last!=getLastModified(cf->file))) {
return false;
}
char * ____BAH_COMPILER_VAR_321 =null;char * ____BAH_COMPILER_VAR_322 =intToStr(cf->opti);char * ____BAH_COMPILER_VAR_323 =intToStr(cf->mem);char * ____BAH_COMPILER_VAR_324 =pathToVarName(cf->file);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_322);
unsigned int strLen_1 = strlen(".o.o");
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_323);
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_324);
unsigned int strLen_4 = strlen("cache/");
unsigned int strLen_5 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_321 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_321+currStrOff, BAH_DIR, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_321+currStrOff, "cache/", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_321+currStrOff, ____BAH_COMPILER_VAR_324, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_321+currStrOff, ____BAH_COMPILER_VAR_323, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_321+currStrOff, ____BAH_COMPILER_VAR_322, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_321+currStrOff, ".o.o", strLen_1);
            currStrOff += strLen_1;
        
        }if ((fileExists(____BAH_COMPILER_VAR_321)==0)) {
return false;
}
if ((strcmp(cf->ver, BAH_VERSION) != 0)) {
return false;
}
return true;
};
char * genArrRealloc(struct variable* v,char * preVal,char * val,struct Elems* elems){
struct string vn = string(v->name);
char * nstr = splitStringBefore(vn,"->data[");
string__trimLeft(&vn,strlen(nstr)+7);
string__trimRight(&vn,1);
char * nLengthStr = string__str(&vn);

                struct string ____BAH_COMPILER_VAR_325 = getCType(v->type,elems);
                char * ____BAH_COMPILER_VAR_326 =null;char * ____BAH_COMPILER_VAR_327 =string__str(&____BAH_COMPILER_VAR_325);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(val);
unsigned int strLen_1 = strlen(";\n        }\n    }\n    ");
unsigned int strLen_2 = strlen(preVal);
unsigned int strLen_3 = strlen("->length = nLength+1;\n        } else {\n            ");
unsigned int strLen_4 = strlen(nstr);
unsigned int strLen_5 = strlen(";\n            ");
unsigned int strLen_6 = strlen(val);
unsigned int strLen_7 = strlen("->data = newPtr;\n            }\n            ");
unsigned int strLen_8 = strlen(nstr);
unsigned int strLen_9 = strlen("));\n                ");
unsigned int strLen_10 = strlen(____BAH_COMPILER_VAR_327);
unsigned int strLen_11 = strlen("->realLength)*sizeof(");
unsigned int strLen_12 = strlen(nstr);
unsigned int strLen_13 = strlen("->data, (");
unsigned int strLen_14 = strlen(nstr);
unsigned int strLen_15 = strlen("->realLength = 50;\n                }\n                void * newPtr = memoryRealloc(");
unsigned int strLen_16 = strlen(nstr);
unsigned int strLen_17 = strlen("->realLength *= 2;\n                } else {\n                    ");
unsigned int strLen_18 = strlen(nstr);
unsigned int strLen_19 = strlen("->realLength != 0) {\n                    ");
unsigned int strLen_20 = strlen(nstr);
unsigned int strLen_21 = strlen("->realLength) {\n                if (");
unsigned int strLen_22 = strlen(nstr);
unsigned int strLen_23 = strlen("->length) {\n            if (nLength >= ");
unsigned int strLen_24 = strlen(nstr);
unsigned int strLen_25 = strlen(";\n        if (nLength >= ");
unsigned int strLen_26 = strlen(nLengthStr);
unsigned int strLen_27 = strlen("\n    {\n        unsigned long nLength = ");
;                            
            ____BAH_COMPILER_VAR_326 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20+strLen_21+strLen_22+strLen_23+strLen_24+strLen_25+strLen_26+strLen_27);
            
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "\n    {\n        unsigned long nLength = ", strLen_27);
                    currStrOff += strLen_27;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, nLengthStr, strLen_26);
                    currStrOff += strLen_26;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, ";\n        if (nLength >= ", strLen_25);
                    currStrOff += strLen_25;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, nstr, strLen_24);
                    currStrOff += strLen_24;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "->length) {\n            if (nLength >= ", strLen_23);
                    currStrOff += strLen_23;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, nstr, strLen_22);
                    currStrOff += strLen_22;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "->realLength) {\n                if (", strLen_21);
                    currStrOff += strLen_21;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, nstr, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "->realLength != 0) {\n                    ", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, nstr, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "->realLength *= 2;\n                } else {\n                    ", strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, nstr, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "->realLength = 50;\n                }\n                void * newPtr = memoryRealloc(", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, nstr, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "->data, (", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, nstr, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "->realLength)*sizeof(", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, ____BAH_COMPILER_VAR_327, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "));\n                ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, nstr, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "->data = newPtr;\n            }\n            ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, val, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, ";\n            ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, nstr, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, "->length = nLength+1;\n        } else {\n            ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_326+currStrOff, preVal, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_326+currStrOff, val, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_326+currStrOff, ";\n        }\n    }\n    ", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_326;
};
void OPTI_checkFuncScopeRef(struct Elems* elems){
if ((strHasPrefix(compilerState.currentFile,BAH_DIR)==true)) {
return;
}
register long int i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
if ((v->isArg==false)) {
continue;
}
if ((v->lastSet!=elems)) {

                struct string ____BAH_COMPILER_VAR_328 = string(v->name);
                if ((isRCPpointerType(v->type)==false)&&(strcmp(v->type, "reflectElement") != 0)&&(string__hasPrefix(&____BAH_COMPILER_VAR_328,"____BAH_COMPILER_VAR_")==false)) {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)) {
char * ____BAH_COMPILER_VAR_329 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->type);
unsigned int strLen_1 = strlen(") could be passed by reference.");
unsigned int strLen_2 = strlen("\e[0m (");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("()\e[0m: argument \e[1;37m");
unsigned int strLen_5 = strlen(currentFn->name);
unsigned int strLen_6 = strlen("in \e[1;37m");
;                            
            ____BAH_COMPILER_VAR_329 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, "in \e[1;37m", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, currentFn->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, "()\e[0m: argument \e[1;37m", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_329+currStrOff, "\e[0m (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_329+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_329+currStrOff, ") could be passed by reference.", strLen_1);
            currStrOff += strLen_1;
        
        }throwWarningLine(____BAH_COMPILER_VAR_329,currentFn->line);
}
}
}
};
};
void debugLine(__BAH_ARR_TYPE_Tok line){
char * cont = "";
register long int i = 0;
while ((i<len(line))) {
struct Tok t = line->data[i];
char * ____BAH_COMPILER_VAR_330 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen("'");
unsigned int strLen_2 = strlen(" '");
unsigned int strLen_3 = strlen(cont);
;                            
            ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_330+currStrOff, " '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_330+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_330+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }cont = ____BAH_COMPILER_VAR_330;
++i;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* ____BAH_COMPILER_VAR_331 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_331->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_331->vars->length = 0;
            ____BAH_COMPILER_VAR_331->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_331->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_331->structs->length = 0;
            ____BAH_COMPILER_VAR_331->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_331->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_331->types->length = 0;
            ____BAH_COMPILER_VAR_331->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_331->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_331->fns->length = 0;
            ____BAH_COMPILER_VAR_331->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_331->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_331->defined->length = 0;
            ____BAH_COMPILER_VAR_331->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_331->parent= null;
struct Elems* nElems = ____BAH_COMPILER_VAR_331;
nElems->parent = elems;
allocateArray(nElems->vars,len(elems->vars));
register long int j = 0;
for (; (j<len(elems->vars)); ++j) {

    {
        unsigned long nLength = j;
        if (nLength >= nElems->vars->length) {
            if (nLength >= nElems->vars->realLength) {
                if (nElems->vars->realLength != 0) {
                    nElems->vars->realLength *= 2;
                } else {
                    nElems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(nElems->vars->data, (nElems->vars->realLength)*sizeof(struct variable*));
                nElems->vars->data = newPtr;
            }
            nElems->vars->data[j] = elems->vars->data[j];
            nElems->vars->length = nLength+1;
        } else {
            nElems->vars->data[j] = elems->vars->data[j];
        }
    }
    ;
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
register long int i = 0;
if ((guard==true)) {
while ((i<len(line))) {
struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_CAST)) {
break;
}

    {
        unsigned long nLength = i;
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[i] = t;
            nl->length = nLength+1;
        } else {
            nl->data[i] = t;
        }
    }
    ;
i = i+1;
};
if ((i==len(line))) {
return line;
}
}
for (; (i<len(line)); ++i) {
struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_CAST)) {
if ((i+1<len(line))) {
struct Tok nnnt = line->data[i+1];
struct string tc = string(t.cont);
string__trimLeft(&tc,1);
string__trimRight(&tc,1);
nnnt.bahType = string__str(&tc);
char * ____BAH_COMPILER_VAR_332 =string__str(&tc);struct string cCast = getCType(____BAH_COMPILER_VAR_332,elems);
char * cCastStr = string__str(&cCast);
char * ____BAH_COMPILER_VAR_333 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(")");
unsigned int strLen_1 = strlen(nnnt.cont);
unsigned int strLen_2 = strlen(cCastStr);
unsigned int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_333 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_333+currStrOff, cCastStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_333+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_333+currStrOff, nnnt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }nnnt.cont = ____BAH_COMPILER_VAR_333;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = nnnt;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = nnnt;
        }
    }
    ;
i = i+2;
continue;
}
}

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
};
return nl;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_334 =__STR(f);array(char)* p = strAsArr(____BAH_COMPILER_VAR_334);
register long int i = len(p)-1;
while ((i>=0)) {
char c = p->data[i];
if ((c==47)) {

    {
        unsigned long nLength = i+1;
        if (nLength >= p->length) {
            if (nLength >= p->realLength) {
                if (p->realLength != 0) {
                    p->realLength *= 2;
                } else {
                    p->realLength = 50;
                }
                void * newPtr = memoryRealloc(p->data, (p->realLength)*sizeof(char));
                p->data = newPtr;
            }
            p->data[i+1] = (char)0;
            p->length = nLength+1;
        } else {
            p->data[i+1] = (char)0;
        }
    }
    ;
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
if (flags__isSet(&flags,"rcp")) {
ccstr = "rcp.bah";
}
else if (flags__isSet(&flags,"fastrcp")) {
ccstr = "fastrcp.bah";
}
}
else {
ccstr = "gc.bah";
}
}

        char ____BAH_COMPILER_VAR_335 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], ccstr) == 0) {
                ____BAH_COMPILER_VAR_335=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_335) {
return true;
}
struct fileMap ____BAH_COMPILER_VAR_336 = {};
____BAH_COMPILER_VAR_336.handle = -1;
____BAH_COMPILER_VAR_336.p= null;
#define fm ____BAH_COMPILER_VAR_336
char * ____BAH_COMPILER_VAR_337 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_337 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_337+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_337+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }char * fileName = ____BAH_COMPILER_VAR_337;
char isBahDir = true;
char * f = fileMap__open(&fm,fileName);
if ((fileMap__isValid(&fm)==0)) {
char * ____BAH_COMPILER_VAR_338 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.currentDir);
unsigned int strLen_1 = strlen(ccstr);
;                            
            ____BAH_COMPILER_VAR_338 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_338+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_338+currStrOff, ccstr, strLen_1);
            currStrOff += strLen_1;
        
        }fileName = absPath(____BAH_COMPILER_VAR_338);
f = fileMap__open(&fm,fileName);
isBahDir = false;
if ((fileMap__isValid(&fm)==0)) {
return false;
}
}
char * oDir = compilerState.currentDir;
if ((isBahDir==false)) {
char * ____BAH_COMPILER_VAR_339 =null;char * ____BAH_COMPILER_VAR_340 =getDirFromFile(ccstr);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.currentDir);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_340);
;                            
            ____BAH_COMPILER_VAR_339 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_339+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_339+currStrOff, ____BAH_COMPILER_VAR_340, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_339;
}
else {
char * ____BAH_COMPILER_VAR_341 =null;char * ____BAH_COMPILER_VAR_342 =getDirFromFile(ccstr);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_342);
;                            
            ____BAH_COMPILER_VAR_341 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_341+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_341+currStrOff, ____BAH_COMPILER_VAR_342, strLen_1);
            currStrOff += strLen_1;
        
        }compilerState.currentDir = ____BAH_COMPILER_VAR_341;
}
char * oFile = compilerState.currentFile;
compilerState.currentFile = fileName;

    {
        unsigned long nLength = len(compilerState.includes);
        if (nLength >= compilerState.includes->length) {
            if (nLength >= compilerState.includes->realLength) {
                if (compilerState.includes->realLength != 0) {
                    compilerState.includes->realLength *= 2;
                } else {
                    compilerState.includes->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.includes->data, (compilerState.includes->realLength)*sizeof(char *));
                compilerState.includes->data = newPtr;
            }
            compilerState.includes->data[len(compilerState.includes)] = ccstr;
            compilerState.includes->length = nLength+1;
        } else {
            compilerState.includes->data[len(compilerState.includes)] = ccstr;
        }
    }
    ;
array(struct Tok)* tokens = lexer(f);
fileMap__close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_343 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ccstr);
unsigned int strLen_1 = strlen("' not recognized.");
unsigned int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_343 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_343+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_343+currStrOff, ccstr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_343+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_343,"/home/alois/Documents/bah-bah/src/parser.bah:244");
}
char oshd = shouldOnlyDecl;
if ((isObject==true)) {

                struct string ____BAH_COMPILER_VAR_344 = string(compilerState.currentFile);
                if ((isBahDir==true)||string__hasPrefix(&____BAH_COMPILER_VAR_344,oDir)) {
shouldOnlyDecl = true;
}
else {
shouldOnlyDecl = false;
}
}
else if ((isSubObject==true)) {

                struct string ____BAH_COMPILER_VAR_345 = string(compilerState.currentFile);
                if ((isBahDir==true)||string__hasPrefix(&____BAH_COMPILER_VAR_345,oDir)) {
shouldOnlyDecl = false;
}
else {
shouldOnlyDecl = true;
}
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

#undef fm
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
if ((flags__isSet(&flags,"verboseCC")==1)) {
verboseCC = "-verboseCC";
}
if ((debug==false)) {
char * ____BAH_COMPILER_VAR_346 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn);
unsigned int strLen_1 = strlen("...");
unsigned int strLen_2 = strlen("compilling: ");
;                            
            ____BAH_COMPILER_VAR_346 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_346+currStrOff, "compilling: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_346+currStrOff, fn, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_346+currStrOff, "...", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_346);
}
char * opti = "";
if ((isOptimized==true)) {
opti = "-optimize";
}
char * ____BAH_COMPILER_VAR_347 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -o ");
unsigned int strLen_1 = strlen(oName);
unsigned int strLen_2 = strlen(verboseCC);
unsigned int strLen_3 = strlen(" -object ");
unsigned int strLen_4 = strlen(opti);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(rcp);
unsigned int strLen_7 = strlen(" ");
unsigned int strLen_8 = strlen(fn);
unsigned int strLen_9 = strlen(" ");
unsigned int strLen_10 = strlen(execName);
;                            
            ____BAH_COMPILER_VAR_347 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, execName, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, " ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, fn, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, " ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, rcp, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, opti, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, " -object ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_347+currStrOff, verboseCC, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_347+currStrOff, " -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_347+currStrOff, oName, strLen_1);
            currStrOff += strLen_1;
        
        }struct command cmd = command(____BAH_COMPILER_VAR_347);
array(char)* res = command__runBytes(&cmd);
if ((debug==false)) {
char * ____BAH_COMPILER_VAR_348 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("done: ");
unsigned int strLen_1 = strlen(fn);
;                            
            ____BAH_COMPILER_VAR_348 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_348+currStrOff, "done: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_348+currStrOff, fn, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_348);
}
setCurrentPath(wrkd);
if ((cmd.status!=0)) {
char * ____BAH_COMPILER_VAR_349 =arrToStr(res);print(____BAH_COMPILER_VAR_349);
exit(1);
}
if ((cf==null)) {
makeCacheFile(fn);
}
else {
updateCacheFile(cf);
}
}

        char ____BAH_COMPILER_VAR_350 = true;
        channel__sendAny(done, &____BAH_COMPILER_VAR_350, sizeof(____BAH_COMPILER_VAR_350));
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
string__trimLeft(&fileName,1);
string__trimRight(&fileName,1);

        char ____BAH_COMPILER_VAR_351 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], string__str(&fileName)) == 0) {
                ____BAH_COMPILER_VAR_351=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_351) {
return;
}

    {
        unsigned long nLength = len(compilerState.includes);
        if (nLength >= compilerState.includes->length) {
            if (nLength >= compilerState.includes->realLength) {
                if (compilerState.includes->realLength != 0) {
                    compilerState.includes->realLength *= 2;
                } else {
                    compilerState.includes->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.includes->data, (compilerState.includes->realLength)*sizeof(char *));
                compilerState.includes->data = newPtr;
            }
            compilerState.includes->data[len(compilerState.includes)] = string__str(&fileName);
            compilerState.includes->length = nLength+1;
        } else {
            compilerState.includes->data[len(compilerState.includes)] = string__str(&fileName);
        }
    }
    ;
char * ____BAH_COMPILER_VAR_352 =null;char * ____BAH_COMPILER_VAR_353 =string__str(&fileName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.currentDir);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_353);
;                            
            ____BAH_COMPILER_VAR_352 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_352+currStrOff, compilerState.currentDir, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_352+currStrOff, ____BAH_COMPILER_VAR_353, strLen_1);
            currStrOff += strLen_1;
        
        }char * fn = absPath(____BAH_COMPILER_VAR_352);
if (((void *)fn==null)) {
char * ____BAH_COMPILER_VAR_354 =null;char * ____BAH_COMPILER_VAR_355 =string__str(&fileName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_355);
;                            
            ____BAH_COMPILER_VAR_354 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_354+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_354+currStrOff, ____BAH_COMPILER_VAR_355, strLen_1);
            currStrOff += strLen_1;
        
        }fn = absPath(____BAH_COMPILER_VAR_354);
if (((void *)fn==null)) {
throwErr(&strt,"Unknown file {TOKEN}.");
}
}
char * of = compilerState.currentFile;
char * od = compilerState.currentDir;
compilerState.currentFile = fn;
compilerState.currentDir = getDirFromFile(fn);
struct fileStream ____BAH_COMPILER_VAR_356 = {};
____BAH_COMPILER_VAR_356.handle= null;
____BAH_COMPILER_VAR_356.name= null;
#define fs ____BAH_COMPILER_VAR_356
fileStream__open(&fs,fn,"r");
char * f = fileStream__readContent(&fs);
fileStream__close(&fs);
array(struct Tok)* tokens = lexer(f);
char osod = shouldOnlyDecl;
shouldOnlyDecl = true;
char oiso = isSubObject;
isSubObject = true;
char * ____BAH_COMPILER_VAR_357 =null;char * ____BAH_COMPILER_VAR_358 =intToStr(isOptimized);char * ____BAH_COMPILER_VAR_359 =intToStr(RCPlevel);char * ____BAH_COMPILER_VAR_360 =pathToVarName(fn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_358);
unsigned int strLen_1 = strlen(".o");
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_359);
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_360);
unsigned int strLen_4 = strlen("cache/");
unsigned int strLen_5 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_357 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, BAH_DIR, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, "cache/", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, ____BAH_COMPILER_VAR_360, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_357+currStrOff, ____BAH_COMPILER_VAR_359, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_357+currStrOff, ____BAH_COMPILER_VAR_358, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_357+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }char * oName = ____BAH_COMPILER_VAR_357;
char * ____BAH_COMPILER_VAR_361 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(oName);
unsigned int strLen_1 = strlen(".o");
unsigned int strLen_2 = strlen("w ");
;                            
            ____BAH_COMPILER_VAR_361 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_361+currStrOff, "w ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_361+currStrOff, oName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_361+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }
    {
        unsigned long nLength = len(compilerState.cLibs);
        if (nLength >= compilerState.cLibs->length) {
            if (nLength >= compilerState.cLibs->realLength) {
                if (compilerState.cLibs->realLength != 0) {
                    compilerState.cLibs->realLength *= 2;
                } else {
                    compilerState.cLibs->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.cLibs->data, (compilerState.cLibs->realLength)*sizeof(char *));
                compilerState.cLibs->data = newPtr;
            }
            compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_361;
            compilerState.cLibs->length = nLength+1;
        } else {
            compilerState.cLibs->data[len(compilerState.cLibs)] = ____BAH_COMPILER_VAR_361;
        }
    }
    ;
struct channel * done = channel();

    void ____BAH_COMPILER_VAR_362(struct {
char * fn;
char * oName;
struct channel * done;
}* args) {
        parallelObjCompile(args->fn, args->oName, args->done);
    };
    {
        struct {
char * fn;
char * oName;
struct channel * done;
} ____BAH_COMPILER_VAR_363 = {fn,oName,done};
        pthread_t id;
        GC_pthread_create(&id, 0, ____BAH_COMPILER_VAR_362, &____BAH_COMPILER_VAR_363);
    }; 
    
    parseLines(tokens,elems);
char ok = *(char*)channel__receive(done);
char * ____BAH_COMPILER_VAR_364 =null;char * ____BAH_COMPILER_VAR_365 =pathToVarName(fn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_365);
unsigned int strLen_1 = strlen("();\n");
unsigned int strLen_2 = strlen("__BAH_init");
;                            
            ____BAH_COMPILER_VAR_364 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_364+currStrOff, "__BAH_init", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_364+currStrOff, ____BAH_COMPILER_VAR_365, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_364+currStrOff, "();\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_364));
writeCache();
shouldOnlyDecl = osod;
isSubObject = oiso;
compilerState.currentFile = of;
compilerState.currentDir = od;

#undef fs
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)!=2)&&(len(l)!=3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}
struct Tok strt = l->data[1];
char isSupressed = false;
if ((strcmp(strt.cont, "!") == 0)&&(len(l)>2)) {
isSupressed = true;
strt = l->data[2];
}
if ((strt.type!=TOKEN_TYPE_STR)) {
throwErr(&strt,"Cannot use {TOKEN} as string in include.");
}
char * sc = strt.cont;
strTrimLeft(&sc,1);
strTrimRight(&sc,1);
if (strHasPrefix(sc,"<")||strHasSuffix(sc,".h")||strHasSuffix(sc,".c")) {
if ((isSubObject==false)||(isSupressed==false)) {
char * ____BAH_COMPILER_VAR_366 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sc);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_366 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_366+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_366+currStrOff, sc, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_366+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_366));

    {
        unsigned long nLength = len(compilerState.cIncludes);
        if (nLength >= compilerState.cIncludes->length) {
            if (nLength >= compilerState.cIncludes->realLength) {
                if (compilerState.cIncludes->realLength != 0) {
                    compilerState.cIncludes->realLength *= 2;
                } else {
                    compilerState.cIncludes->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.cIncludes->data, (compilerState.cIncludes->realLength)*sizeof(char *));
                compilerState.cIncludes->data = newPtr;
            }
            compilerState.cIncludes->data[len(compilerState.cIncludes)] = sc;
            compilerState.cIncludes->length = nLength+1;
        } else {
            compilerState.cIncludes->data[len(compilerState.cIncludes)] = sc;
        }
    }
    ;
}
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
register long int i = 0;
while ((i<len(line))) {
struct Tok t = line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
if (strHasPrefix(t.bahType,"[]")) {

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
++i;
continue;
}
++i;
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
____BAH_COMPILER_VAR_367.parent= null;
____BAH_COMPILER_VAR_367.cont = "";
#define nt ____BAH_COMPILER_VAR_367
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
struct variable* ____BAH_COMPILER_VAR_368 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_368->name = "";
____BAH_COMPILER_VAR_368->type = "";
____BAH_COMPILER_VAR_368->isConst = false;
____BAH_COMPILER_VAR_368->constVal = "";
____BAH_COMPILER_VAR_368->isArray = false;
____BAH_COMPILER_VAR_368->from = "";
____BAH_COMPILER_VAR_368->declScope= null;
____BAH_COMPILER_VAR_368->isGlobal = false;
____BAH_COMPILER_VAR_368->declRope= null;
____BAH_COMPILER_VAR_368->isReg = false;
____BAH_COMPILER_VAR_368->lastSet= null;
____BAH_COMPILER_VAR_368->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_368;
tmpV->name = t.cont;
char * ____BAH_COMPILER_VAR_369 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_369 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_369+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_369+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_369;
struct string cType = getCType(tmpV->type,elems);
struct string structType = getCType(s->name,elems);

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = tmpV;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = tmpV;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_370 =null;char * ____BAH_COMPILER_VAR_371 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_372 =string__str(&structType);char * ____BAH_COMPILER_VAR_373 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("));\n");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_371);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_372);
unsigned int strLen_3 = strlen(" = memoryAlloc(sizeof(");
unsigned int strLen_4 = strlen(t.cont);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(____BAH_COMPILER_VAR_373);
;                            
            ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, ____BAH_COMPILER_VAR_373, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, t.cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_370+currStrOff, ____BAH_COMPILER_VAR_372, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_370+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_370+currStrOff, ____BAH_COMPILER_VAR_371, strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_370));

    {
        unsigned long nLength = len(nl)-1;
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)-1] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)-1] = t;
        }
    }
    ;
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
++i;
struct cStruct* s = searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int nbBraces = 1;
for (; (i<len(line)); ++i) {
t = line->data[i];
if ((strcmp(t.cont, "{") == 0)) {
++nbBraces;
}
else if ((strcmp(t.cont, "}") == 0)) {
--nbBraces;
if ((nbBraces==0)) {
break;
}
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = t;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = t;
        }
    }
    ;
};
if ((len(memory)>0)) {
memory = prePross(memory,(lineType)-1,elems);
}
long int declType = 0;
char * rvn = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_374 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_374->name = "";
____BAH_COMPILER_VAR_374->type = "";
____BAH_COMPILER_VAR_374->isConst = false;
____BAH_COMPILER_VAR_374->constVal = "";
____BAH_COMPILER_VAR_374->isArray = false;
____BAH_COMPILER_VAR_374->from = "";
____BAH_COMPILER_VAR_374->declScope= null;
____BAH_COMPILER_VAR_374->isGlobal = false;
____BAH_COMPILER_VAR_374->declRope= null;
____BAH_COMPILER_VAR_374->isReg = false;
____BAH_COMPILER_VAR_374->lastSet= null;
____BAH_COMPILER_VAR_374->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_374;
tmpV->name = rvn;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_375 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_375 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_375+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_375+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV->type = ____BAH_COMPILER_VAR_375;

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = tmpV;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = tmpV;
        }
    }
    ;
}
else {
tmpV->type = s->name;
}
struct string rst = getCType(tmpV->type,elems);
struct rope* r= null;
if ((isHeap==true)) {
char * ____BAH_COMPILER_VAR_376 =string__str(&rst);struct string structType = string(____BAH_COMPILER_VAR_376);
string__trimRight(&structType,1);
char * ____BAH_COMPILER_VAR_377 =null;char * ____BAH_COMPILER_VAR_378 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_379 =string__str(&structType);char * ____BAH_COMPILER_VAR_380 =string__str(&rst);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("));\n");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_378);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_379);
unsigned int strLen_3 = strlen(" = memoryAlloc(sizeof(");
unsigned int strLen_4 = strlen(rvn);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(____BAH_COMPILER_VAR_380);
;                            
            ____BAH_COMPILER_VAR_377 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, ____BAH_COMPILER_VAR_380, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, rvn, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, " = memoryAlloc(sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_377+currStrOff, ____BAH_COMPILER_VAR_379, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_377+currStrOff, "));\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_377+currStrOff, ____BAH_COMPILER_VAR_378, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_377);
}
else {
char * ____BAH_COMPILER_VAR_381 =null;char * ____BAH_COMPILER_VAR_382 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_383 =string__str(&rst);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = {};\n");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_382);
unsigned int strLen_2 = strlen(rvn);
unsigned int strLen_3 = strlen(" ");
unsigned int strLen_4 = strlen(____BAH_COMPILER_VAR_383);
;                            
            ____BAH_COMPILER_VAR_381 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, ____BAH_COMPILER_VAR_383, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_381+currStrOff, rvn, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_381+currStrOff, " = {};\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_381+currStrOff, ____BAH_COMPILER_VAR_382, strLen_1);
            currStrOff += strLen_1;
        
        }r = rope(____BAH_COMPILER_VAR_381);
}
register long int j = 0;
register long int k = 0;
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
char * ____BAH_COMPILER_VAR_384 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->type);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen(") as '");
unsigned int strLen_3 = strlen(vlt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_384 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, vlt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_384+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_384+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_384+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&vl,____BAH_COMPILER_VAR_384);
}
char * ____BAH_COMPILER_VAR_385 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(vl.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(m->name);
unsigned int strLen_4 = strlen(sep);
unsigned int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_385 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_385+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_385+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_385+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_385+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_385+currStrOff, vl.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_385+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_385));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_386 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("' has no member called {TOKEN}.");
unsigned int strLen_2 = strlen("Struct '");
;                            
            ____BAH_COMPILER_VAR_386 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_386+currStrOff, "Struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_386+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_386+currStrOff, "' has no member called {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_386);
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
++j;
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_387 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->type);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen(") as '");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_387 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_387+currStrOff, ") as '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_387+currStrOff, m->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_387+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_387);
}
char * ____BAH_COMPILER_VAR_388 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(m->name);
unsigned int strLen_4 = strlen(sep);
unsigned int strLen_5 = strlen(rvn);
;                            
            ____BAH_COMPILER_VAR_388 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_388+currStrOff, rvn, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_388+currStrOff, sep, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_388+currStrOff, m->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_388+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_388+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_388+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }r = rope__add(r, rope(____BAH_COMPILER_VAR_388));
if ((k+1<len(memory))) {
++k;
struct Tok st = memory->data[k];
if ((strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Need ',' separator between two values, not {TOKEN}.");
}
}
++k;
};
if (isGlobal()) {
INIT = rope__add(INIT, r);
}
else {
OUTPUT = rope__add(OUTPUT, r);
}
t.bahType = tmpV->type;
t.cont = rvn;
t.isValue = true;
if ((isHeap==true)) {

    {
        unsigned long nLength = len(nl)-1;
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)-1] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)-1] = t;
        }
    }
    ;
}
else {
t.isEqual = true;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
}
++i;
continue;
}
else {
--i;
}
}

#undef nt
}

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
++i;
};
return nl;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems,char guard){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int i = 0;
if ((guard==true)) {
for (; (i<len(line)); ++i) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
break;
}

    {
        unsigned long nLength = i;
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[i] = t;
            nl->length = nLength+1;
        } else {
            nl->data[i] = t;
        }
    }
    ;
};
if ((i==len(line))) {
return line;
}
}
for (; (i<len(line)); ++i) {
struct Tok t = line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
++i;
if ((i<len(line))) {
t = line->data[i];
if ((strcmp(t.cont, "]") == 0)) {
++i;
long int depth = 1;
char * bracks = "[]";
for (; (i<len(line)-1); ++i) {
t = line->data[i];
struct Tok nt = line->data[i+1];
if ((strcmp(t.cont, "[") == 0)&&(strcmp(nt.cont, "]") == 0)) {
++depth;
char * ____BAH_COMPILER_VAR_389 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(bracks);
unsigned int strLen_1 = strlen("[]");
;                            
            ____BAH_COMPILER_VAR_389 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_389+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_389+currStrOff, "[]", strLen_1);
            currStrOff += strLen_1;
        
        }bracks = ____BAH_COMPILER_VAR_389;
++i;
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
char * ____BAH_COMPILER_VAR_390 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(bracks);
unsigned int strLen_1 = strlen(arrElem);
;                            
            ____BAH_COMPILER_VAR_390 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_390+currStrOff, bracks, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_390+currStrOff, arrElem, strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_390;
t.cont = "";
t.isValue = true;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
continue;
}
}
}
}

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
};
return nl;
};
array(char *)* comparators;
array(char *)* compSep;
__BAH_ARR_TYPE_Tok parsePointers(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
register long int i = 0;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
if ((strcmp(t.cont, "&") == 0)||(strcmp(t.cont, "*") == 0)) {
if ((i>0)) {
if ((l->data[i-1].type==TOKEN_TYPE_VAR)||(l->data[i-1].isValue==true)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i+1<len(l))) {
if ((strcmp(l->data[i+1].cont, "(") != 0)&&(strcmp(l->data[i+1].cont, "<") != 0)&&(l->data[i+1].isValue!=true)) {
char * ____BAH_COMPILER_VAR_391 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(l->data[i-1].cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_391 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_391+currStrOff, l->data[i-1].cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_391+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }l->data[i-1].cont = ____BAH_COMPILER_VAR_391;
delete(l,i);
--i;
}
}
else {
char * ____BAH_COMPILER_VAR_392 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(l->data[i-1].cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_392 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_392+currStrOff, l->data[i-1].cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_392+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }l->data[i-1].cont = ____BAH_COMPILER_VAR_392;
delete(l,i);
--i;
}
}
continue;
}
}
}
if ((strcmp(t.cont, "&") == 0)||(strcmp(t.cont, "*") == 0)) {
if ((i+1<len(l))) {
if ((i>0)) {
if ((strcmp(l->data[i-1].cont, ")") == 0)||(l->data[i-1].isValue==true)) {
continue;
}
}
if ((l->data[i+1].type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_393 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(l->data[i+1].cont);
;                            
            ____BAH_COMPILER_VAR_393 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_393+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_393+currStrOff, l->data[i+1].cont, strLen_1);
            currStrOff += strLen_1;
        
        }l->data[i+1].cont = ____BAH_COMPILER_VAR_393;
delete(l,i);
--i;
}
}
}
};
return l;
};
char * parseSerialize(struct Tok* e,struct Elems* elems){
struct variable* v = searchVar(e->cont,elems);
if ((v==null)) {
throwErr(&e,"Must be a var, not {TOKEN}.");
}
struct cStruct* s = searchStruct(v->type,elems);
if ((s==null)) {
throwErr(&e,"Must be a struct, not {TOKEN}.");
}
struct string svt = string(v->type);
register long int ptrLevel = string__count(&svt,"*");
string__replace(&svt,"*","");
char * code= null;
if ((ptrLevel==0)) {
char * ____BAH_COMPILER_VAR_394 =null;char * ____BAH_COMPILER_VAR_395 =string__str(&svt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_395);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("sizeof(struct ");
unsigned int strLen_3 = strlen(", ");
unsigned int strLen_4 = strlen(e->cont);
unsigned int strLen_5 = strlen("__serialize(&");
;                            
            ____BAH_COMPILER_VAR_394 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, "__serialize(&", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, e->cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_394+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_394+currStrOff, ____BAH_COMPILER_VAR_395, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_394+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_394;
}
else {
char * ptrRect = "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_396 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptrRect);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_396 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_396+currStrOff, ptrRect, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_396+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }ptrRect = ____BAH_COMPILER_VAR_396;
ptrLevel = ptrLevel-1;
};
char * ____BAH_COMPILER_VAR_397 =null;char * ____BAH_COMPILER_VAR_398 =string__str(&svt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_398);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("sizeof(struct ");
unsigned int strLen_3 = strlen(", ");
unsigned int strLen_4 = strlen(e->cont);
unsigned int strLen_5 = strlen(ptrRect);
unsigned int strLen_6 = strlen("__serialize(");
;                            
            ____BAH_COMPILER_VAR_397 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, "__serialize(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, ptrRect, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, e->cont, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, ", ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_397+currStrOff, "sizeof(struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_397+currStrOff, ____BAH_COMPILER_VAR_398, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_397+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_397;
register long int i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_399 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->");
unsigned int strLen_3 = strlen(e->cont);
unsigned int strLen_4 = strlen("+strlen(");
unsigned int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_399 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_399+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_399+currStrOff, "+strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_399+currStrOff, e->cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_399+currStrOff, "->", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_399+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_399+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_399;
}
i = i+1;
};
}
char * ____BAH_COMPILER_VAR_400 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_400 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_400+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_400+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_400;
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
string__append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_401 =null;char * ____BAH_COMPILER_VAR_402 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(v);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_402);
;                            
            ____BAH_COMPILER_VAR_401 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, ____BAH_COMPILER_VAR_402, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_401+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_401+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_401+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_401));
t.cont = v;
if ((t.type==TOKEN_TYPE_STR)) {
ogName = "[bah cpstring]";
}
}
char * arrElem = "0";
if (strHasPrefix(tt,"[]")) {
isArr = "1";
struct string aet = string(tt);
string__trimLeft(&aet,2);
struct Tok ____BAH_COMPILER_VAR_403 = {};
____BAH_COMPILER_VAR_403.cont = "";
____BAH_COMPILER_VAR_403.ogCont = "";
____BAH_COMPILER_VAR_403.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_403.pos = 0;
____BAH_COMPILER_VAR_403.line = 1;
____BAH_COMPILER_VAR_403.begLine = 1;
____BAH_COMPILER_VAR_403.bahType = "";
____BAH_COMPILER_VAR_403.isValue = false;
____BAH_COMPILER_VAR_403.isFunc = false;
____BAH_COMPILER_VAR_403.isOper = false;
____BAH_COMPILER_VAR_403.isEqual = false;
____BAH_COMPILER_VAR_403.pass = false;
____BAH_COMPILER_VAR_403.bahRef= null;
____BAH_COMPILER_VAR_403.parent= null;
#define tmpT ____BAH_COMPILER_VAR_403
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_404 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_404,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_405 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rt.cont);
unsigned int strLen_1 = strlen(";\n        ");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(aev);
unsigned int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_405 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_405+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_405+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_405+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_405));
char * ____BAH_COMPILER_VAR_406 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("&");
unsigned int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_406 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_406+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_406+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_406;

#undef tmpT
}
else if (strHasPrefix(tt,"map:")) {
struct string aet = string(tt);
string__trimLeft(&aet,4);
struct Tok ____BAH_COMPILER_VAR_407 = {};
____BAH_COMPILER_VAR_407.cont = "";
____BAH_COMPILER_VAR_407.ogCont = "";
____BAH_COMPILER_VAR_407.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_407.pos = 0;
____BAH_COMPILER_VAR_407.line = 1;
____BAH_COMPILER_VAR_407.begLine = 1;
____BAH_COMPILER_VAR_407.bahType = "";
____BAH_COMPILER_VAR_407.isValue = false;
____BAH_COMPILER_VAR_407.isFunc = false;
____BAH_COMPILER_VAR_407.isOper = false;
____BAH_COMPILER_VAR_407.isEqual = false;
____BAH_COMPILER_VAR_407.pass = false;
____BAH_COMPILER_VAR_407.bahRef= null;
____BAH_COMPILER_VAR_407.parent= null;
#define tmpT ____BAH_COMPILER_VAR_407
tmpT.type = TOKEN_TYPE_VAR;
tmpT.cont = "0";
char * ____BAH_COMPILER_VAR_408 =string__str(&aet);struct Tok rt = parseReflect(tmpT,____BAH_COMPILER_VAR_408,elems,true,"","0");
char * aev = genCompilerVar();
char * ____BAH_COMPILER_VAR_409 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rt.cont);
unsigned int strLen_1 = strlen(";\n        ");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(aev);
unsigned int strLen_4 = strlen("\n        struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_409 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_409+currStrOff, "\n        struct reflectElement ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_409+currStrOff, aev, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_409+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_409+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_409+currStrOff, ";\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_409));
char * ____BAH_COMPILER_VAR_410 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("&");
unsigned int strLen_1 = strlen(aev);
;                            
            ____BAH_COMPILER_VAR_410 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_410+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_410+currStrOff, aev, strLen_1);
            currStrOff += strLen_1;
        
        }arrElem = ____BAH_COMPILER_VAR_410;

#undef tmpT
}
char * isStruct = "0";
struct cStruct* ts = searchStruct(tt,elems);
char * structLayout = "0";
if ((ts!=null)) {
isStruct = "1";
structLayout = genCompilerVar();
struct variable* ____BAH_COMPILER_VAR_411 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_411->name = "";
____BAH_COMPILER_VAR_411->type = "";
____BAH_COMPILER_VAR_411->isConst = false;
____BAH_COMPILER_VAR_411->constVal = "";
____BAH_COMPILER_VAR_411->isArray = false;
____BAH_COMPILER_VAR_411->from = "";
____BAH_COMPILER_VAR_411->declScope= null;
____BAH_COMPILER_VAR_411->isGlobal = false;
____BAH_COMPILER_VAR_411->declRope= null;
____BAH_COMPILER_VAR_411->isReg = false;
____BAH_COMPILER_VAR_411->lastSet= null;
____BAH_COMPILER_VAR_411->isArg = false;
struct variable* slv = ____BAH_COMPILER_VAR_411;
slv->name = structLayout;
slv->type = "[]reflectElement";

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = slv;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = slv;
        }
    }
    ;
struct rope* dataLayout = rope("");
register long int i = 0;
for (; (i<len(ts->members)); ++i) {
struct structMemb* m = ts->members->data[i];
if ((strcmp(m->type, tt) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_412 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_412->name = "";
____BAH_COMPILER_VAR_412->type = "";
____BAH_COMPILER_VAR_412->isConst = false;
____BAH_COMPILER_VAR_412->constVal = "";
____BAH_COMPILER_VAR_412->isArray = false;
____BAH_COMPILER_VAR_412->from = "";
____BAH_COMPILER_VAR_412->declScope= null;
____BAH_COMPILER_VAR_412->isGlobal = false;
____BAH_COMPILER_VAR_412->declRope= null;
____BAH_COMPILER_VAR_412->isReg = false;
____BAH_COMPILER_VAR_412->lastSet= null;
____BAH_COMPILER_VAR_412->isArg = false;
____BAH_COMPILER_VAR_412->def = "";
____BAH_COMPILER_VAR_412->isFn = false;
struct structMemb* nm = ____BAH_COMPILER_VAR_412;
*nm = *m;
m = nm;
m->type = "ptr";
}
struct Tok ____BAH_COMPILER_VAR_413 = {};
____BAH_COMPILER_VAR_413.cont = "";
____BAH_COMPILER_VAR_413.ogCont = "";
____BAH_COMPILER_VAR_413.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_413.pos = 0;
____BAH_COMPILER_VAR_413.line = 1;
____BAH_COMPILER_VAR_413.begLine = 1;
____BAH_COMPILER_VAR_413.bahType = "";
____BAH_COMPILER_VAR_413.isValue = false;
____BAH_COMPILER_VAR_413.isFunc = false;
____BAH_COMPILER_VAR_413.isOper = false;
____BAH_COMPILER_VAR_413.isEqual = false;
____BAH_COMPILER_VAR_413.pass = false;
____BAH_COMPILER_VAR_413.bahRef= null;
____BAH_COMPILER_VAR_413.parent= null;
#define tmpT ____BAH_COMPILER_VAR_413
tmpT.type = TOKEN_TYPE_VAR;
char * sep = "->";
if ((strCount(tt,"*")==0)) {
sep = ".";
}
struct string mCtype = getCType(m->type,elems);
struct string offsetTT = string(tt);
string__replace(&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_414 =null;char * ____BAH_COMPILER_VAR_415 =string__str(&offsetTT);char * ____BAH_COMPILER_VAR_416 =string__str(&mCtype);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_415);
unsigned int strLen_4 = strlen(") + offsetof(struct ");
unsigned int strLen_5 = strlen(t.cont);
unsigned int strLen_6 = strlen("*)((char*)(");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_416);
unsigned int strLen_8 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_414 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, ____BAH_COMPILER_VAR_416, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, "*)((char*)(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, t.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, ") + offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, ____BAH_COMPILER_VAR_415, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_414+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_414+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_414+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }tmpT.cont = ____BAH_COMPILER_VAR_414;
char * ____BAH_COMPILER_VAR_417 =null;char * ____BAH_COMPILER_VAR_418 =string__str(&offsetTT);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m->name);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_418);
unsigned int strLen_4 = strlen("offsetof(struct ");
;                            
            ____BAH_COMPILER_VAR_417 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, "offsetof(struct ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, ____BAH_COMPILER_VAR_418, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_417+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_417+currStrOff, m->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_417+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }struct Tok rt = parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_417);
char * ____BAH_COMPILER_VAR_419 =null;char * ____BAH_COMPILER_VAR_420 =intToStr(i);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rt.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("] = ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_420);
unsigned int strLen_4 = strlen("->data[");
unsigned int strLen_5 = strlen(structLayout);
;                            
            ____BAH_COMPILER_VAR_419 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, ____BAH_COMPILER_VAR_420, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_419+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_419+currStrOff, rt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_419+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }dataLayout = rope__add(dataLayout, rope(____BAH_COMPILER_VAR_419));

#undef tmpT
};
char * ____BAH_COMPILER_VAR_421 =null;char * ____BAH_COMPILER_VAR_422 =intToStr(len(ts->members));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(structLayout);
unsigned int strLen_1 = strlen("->elemSize);\n        ");
unsigned int strLen_2 = strlen("->length * ");
unsigned int strLen_3 = strlen(structLayout);
unsigned int strLen_4 = strlen("->data = memoryAlloc(");
unsigned int strLen_5 = strlen(structLayout);
unsigned int strLen_6 = strlen(";\n        ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_422);
unsigned int strLen_8 = strlen("->length = ");
unsigned int strLen_9 = strlen(structLayout);
unsigned int strLen_10 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
unsigned int strLen_11 = strlen(structLayout);
unsigned int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
unsigned int strLen_13 = strlen(structLayout);
unsigned int strLen_14 = strlen("\n        array(struct reflectElement) * ");
;                            
            ____BAH_COMPILER_VAR_421 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, "\n        array(struct reflectElement) * ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, structLayout, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, structLayout, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, structLayout, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, "->length = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, ____BAH_COMPILER_VAR_422, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, ";\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, structLayout, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, "->data = memoryAlloc(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_421+currStrOff, "->length * ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_421+currStrOff, structLayout, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_421+currStrOff, "->elemSize);\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope__add(rope(____BAH_COMPILER_VAR_421), dataLayout));
}
char * amp = "";
if ((strCount(tt,"*")==0)&&(strcmp(tt, "cpstring") != 0)&&(strcmp(tt, "ptr") != 0)&&(parsedPointer==false)) {
amp = "&";
}
struct string name = string(ogName);
if ((hasStructSep(&name)==true)) {
name = splitStructSepAfter(name);
}
struct string cType;
if (strHasPrefix(tt,"function(")) {
cType = string("void*");
}
else {
cType = getCType(tt,elems);
}
if (string__hasPrefix(&cType,"struct ")) {
string__replace(&cType,"*","");
}
if ((cType.length==0)) {
string__set(&cType,"0");
}
struct variable* ____BAH_COMPILER_VAR_423 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_423->name = "";
____BAH_COMPILER_VAR_423->type = "";
____BAH_COMPILER_VAR_423->isConst = false;
____BAH_COMPILER_VAR_423->constVal = "";
____BAH_COMPILER_VAR_423->isArray = false;
____BAH_COMPILER_VAR_423->from = "";
____BAH_COMPILER_VAR_423->declScope= null;
____BAH_COMPILER_VAR_423->isGlobal = false;
____BAH_COMPILER_VAR_423->declRope= null;
____BAH_COMPILER_VAR_423->isReg = false;
____BAH_COMPILER_VAR_423->lastSet= null;
____BAH_COMPILER_VAR_423->isArg = false;
struct variable* rv = ____BAH_COMPILER_VAR_423;
rv->name = genCompilerVar();
rv->type = "reflectElement";

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = rv;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = rv;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_424 =null;char * ____BAH_COMPILER_VAR_425 =string__str(&name);char * ____BAH_COMPILER_VAR_426 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(offset);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(structLayout);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(isStruct);
unsigned int strLen_6 = strlen(", ");
unsigned int strLen_7 = strlen(arrElem);
unsigned int strLen_8 = strlen(", ");
unsigned int strLen_9 = strlen(isArr);
unsigned int strLen_10 = strlen("\", ");
unsigned int strLen_11 = strlen(____BAH_COMPILER_VAR_425);
unsigned int strLen_12 = strlen("\", \"");
unsigned int strLen_13 = strlen(tt);
unsigned int strLen_14 = strlen("), \"");
unsigned int strLen_15 = strlen(____BAH_COMPILER_VAR_426);
unsigned int strLen_16 = strlen(", sizeof(");
unsigned int strLen_17 = strlen(t.cont);
unsigned int strLen_18 = strlen(amp);
unsigned int strLen_19 = strlen(" = __reflect(");
unsigned int strLen_20 = strlen(rv->name);
unsigned int strLen_21 = strlen("struct reflectElement ");
;                            
            ____BAH_COMPILER_VAR_424 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20+strLen_21);
            
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, "struct reflectElement ", strLen_21);
                    currStrOff += strLen_21;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, rv->name, strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, " = __reflect(", strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, amp, strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, t.cont, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ", sizeof(", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ____BAH_COMPILER_VAR_426, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, "), \"", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, tt, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, "\", \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ____BAH_COMPILER_VAR_425, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, "\", ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, isArr, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ", ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, arrElem, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, isStruct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, structLayout, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_424+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_424+currStrOff, offset, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_424+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_424));
t.cont = rv->name;
return t;
};
char * parseArrayDecl(struct variable* v,__BAH_ARR_TYPE_Tok l,long int i,long int max,struct Elems* elems){
long int arrayLength = 0;
struct string arrType = getCType(v->type,elems);
string__trimRight(&arrType,1);
char * ____BAH_COMPILER_VAR_427 =null;char * ____BAH_COMPILER_VAR_428 =string__str(&arrType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_428);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen("memoryAlloc(sizeof(");
;                            
            ____BAH_COMPILER_VAR_427 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_427+currStrOff, "memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_427+currStrOff, ____BAH_COMPILER_VAR_428, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_427+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_427;
string__trimLeft(&arrType,6);
string__trimRight(&arrType,1);
char * elemTypeStr = string__str(&arrType);
if ((i+1!=max)) {
++i;
struct Tok nt = l->data[i];
if ((strcmp(nt.cont, "{") != 0)) {
throwErr(&l->data[i+1],"{TOKEN} not expected after array initialization.");
}
struct string elemBahType = string(v->type);
string__trimLeft(&elemBahType,2);
char * elemBahTypeStr = string__str(&elemBahType);
i = i+1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
while ((i<max)) {

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = l->data[i];
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = l->data[i];
        }
    }
    ;
i = i+1;
};
memory = prePross(memory,(lineType)-1,elems);
i = 0;
while ((i<len(memory))) {
struct Tok t = memory->data[i];
if ((strcmp(t.cont, "{") == 0)) {
long int j = i-1;
long int nbBraces = 0;
for (; (i<len(memory)); ++i) {
struct Tok tmpT = memory->data[i];
if ((strcmp(tmpT.cont, "{") == 0)) {
++nbBraces;
}
else if ((strcmp(tmpT.cont, "}") == 0)) {
--nbBraces;
}
if ((nbBraces==0)) {
break;
}
};
struct variable* ____BAH_COMPILER_VAR_429 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_429->name = "";
____BAH_COMPILER_VAR_429->type = "";
____BAH_COMPILER_VAR_429->isConst = false;
____BAH_COMPILER_VAR_429->constVal = "";
____BAH_COMPILER_VAR_429->isArray = false;
____BAH_COMPILER_VAR_429->from = "";
____BAH_COMPILER_VAR_429->declScope= null;
____BAH_COMPILER_VAR_429->isGlobal = false;
____BAH_COMPILER_VAR_429->declRope= null;
____BAH_COMPILER_VAR_429->isReg = false;
____BAH_COMPILER_VAR_429->lastSet= null;
____BAH_COMPILER_VAR_429->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_429;
tmpV->name = genCompilerVar();
struct string elemType = string(v->type);
string__trimLeft(&elemType,2);
tmpV->type = string__str(&elemType);

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = tmpV;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = tmpV;
        }
    }
    ;
char * oldNL = NEXT_LINE;
NEXT_LINE = "";
char * innerCode = parseArrayDecl(tmpV,memory,j,i+1,elems);
char * ____BAH_COMPILER_VAR_430 =string__str(&elemType);struct string cType = getCType(____BAH_COMPILER_VAR_430,elems);
char * ____BAH_COMPILER_VAR_431 =null;char * ____BAH_COMPILER_VAR_432 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(NEXT_LINE);
unsigned int strLen_1 = strlen("\n                ");
unsigned int strLen_2 = strlen(";\n                ");
unsigned int strLen_3 = strlen(innerCode);
unsigned int strLen_4 = strlen(" = ");
unsigned int strLen_5 = strlen(tmpV->name);
unsigned int strLen_6 = strlen(") * ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_432);
unsigned int strLen_8 = strlen("\n                array(");
;                            
            ____BAH_COMPILER_VAR_431 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, "\n                array(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, ____BAH_COMPILER_VAR_432, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, ") * ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, " = ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, innerCode, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_431+currStrOff, ";\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_431+currStrOff, NEXT_LINE, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_431+currStrOff, "\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_431));
NEXT_LINE = oldNL;
struct Tok ____BAH_COMPILER_VAR_433 = {};
____BAH_COMPILER_VAR_433.cont = "";
____BAH_COMPILER_VAR_433.ogCont = "";
____BAH_COMPILER_VAR_433.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_433.pos = 0;
____BAH_COMPILER_VAR_433.line = 1;
____BAH_COMPILER_VAR_433.begLine = 1;
____BAH_COMPILER_VAR_433.bahType = "";
____BAH_COMPILER_VAR_433.isValue = false;
____BAH_COMPILER_VAR_433.isFunc = false;
____BAH_COMPILER_VAR_433.isOper = false;
____BAH_COMPILER_VAR_433.isEqual = false;
____BAH_COMPILER_VAR_433.pass = false;
____BAH_COMPILER_VAR_433.bahRef= null;
____BAH_COMPILER_VAR_433.parent= null;
____BAH_COMPILER_VAR_433.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_433.cont = tmpV->name;
____BAH_COMPILER_VAR_433.bahType = string__str(&elemType);
____BAH_COMPILER_VAR_433.isValue = true;
t = ____BAH_COMPILER_VAR_433;
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_434 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(") as ");
unsigned int strLen_1 = strlen(elemBahTypeStr);
unsigned int strLen_2 = strlen(tt);
unsigned int strLen_3 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_434 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_434+currStrOff, "Cannot use {TOKEN} (", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_434+currStrOff, tt, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_434+currStrOff, ") as ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_434+currStrOff, elemBahTypeStr, strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_434);
}
char * strArrayLength = intToStr(arrayLength);
arrayLength = arrayLength+1;
char * ____BAH_COMPILER_VAR_435 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("] = ");
unsigned int strLen_3 = strlen(strArrayLength);
unsigned int strLen_4 = strlen("->data[");
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen(NEXT_LINE);
;                            
            ____BAH_COMPILER_VAR_435 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, NEXT_LINE, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, strArrayLength, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_435+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_435+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_435+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_435;
++i;
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
char * ____BAH_COMPILER_VAR_436 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(";\n");
unsigned int strLen_1 = strlen(NEXT_LINE);
unsigned int strLen_2 = strlen(allocLengthStr);
unsigned int strLen_3 = strlen("->realLength = ");
unsigned int strLen_4 = strlen(v->name);
unsigned int strLen_5 = strlen(");\n                    ");
unsigned int strLen_6 = strlen(allocLengthStr);
unsigned int strLen_7 = strlen(") * ");
unsigned int strLen_8 = strlen(elemTypeStr);
unsigned int strLen_9 = strlen("->data = memoryAlloc(sizeof(");
unsigned int strLen_10 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, v->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, "->data = memoryAlloc(sizeof(", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, elemTypeStr, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ") * ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, allocLengthStr, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, ");\n                    ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, "->realLength = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_436+currStrOff, allocLengthStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, ";\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_436+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_436;
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
char * ____BAH_COMPILER_VAR_437 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(");\n");
unsigned int strLen_1 = strlen(NEXT_LINE);
unsigned int strLen_2 = strlen(elemTypeStr);
unsigned int strLen_3 = strlen("->elemSize = sizeof(");
unsigned int strLen_4 = strlen(v->name);
unsigned int strLen_5 = strlen(";\n");
unsigned int strLen_6 = strlen(strArrayLength);
unsigned int strLen_7 = strlen("->length = ");
unsigned int strLen_8 = strlen(v->name);
unsigned int strLen_9 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_437 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9);
            
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "\n", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "->length = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, strArrayLength, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, ";\n", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, "->elemSize = sizeof(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_437+currStrOff, elemTypeStr, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_437+currStrOff, ");\n", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_437+currStrOff, NEXT_LINE, strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_437;
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
char * ____BAH_COMPILER_VAR_438 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_438 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_438+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_438+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_438));
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
struct variable* ____BAH_COMPILER_VAR_439 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_439->name = "";
____BAH_COMPILER_VAR_439->type = "";
____BAH_COMPILER_VAR_439->isConst = false;
____BAH_COMPILER_VAR_439->constVal = "";
____BAH_COMPILER_VAR_439->isArray = false;
____BAH_COMPILER_VAR_439->from = "";
____BAH_COMPILER_VAR_439->declScope= null;
____BAH_COMPILER_VAR_439->isGlobal = false;
____BAH_COMPILER_VAR_439->declRope= null;
____BAH_COMPILER_VAR_439->isReg = false;
____BAH_COMPILER_VAR_439->lastSet= null;
____BAH_COMPILER_VAR_439->isArg = false;
v = ____BAH_COMPILER_VAR_439;
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
string__trimLeft(&c,2);
char * ____BAH_COMPILER_VAR_440 =string__str(&c);v = searchVar(____BAH_COMPILER_VAR_440,elems);
if ((v==null)) {
throwErr(&t,"Cannot increase/decrease not declared variable {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_441 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_441 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_441+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_441+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_441));
return;
}
if ((len(l)<2)) {
throwErr(&ft,"Missing '=' after {TOKEN}.");
}
struct Tok operT = l->data[1];

        char ____BAH_COMPILER_VAR_442 = 0;
        for(int i=equalsTokens->length-1; i!=-1;i--) {
            if (equalsTokens->data[i] != 0 && strcmp(equalsTokens->data[i], operT.cont) == 0) {
                ____BAH_COMPILER_VAR_442=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_442&&(strcmp(operT.cont, "=") != 0)) {
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);
                    nl->realLength = 50;
nl->data[0] = l->data[0];
if ((2==len(l))) {
throwErr(&operT,"Cannot use {TOKEN} on nothing.");
}
struct string oper = string(operT.cont);
string__trimRight(&oper,1);
struct Tok operTok = operT;
operTok.cont = string__str(&oper);
array(struct Tok)* tmpL = memoryAlloc(sizeof(array(struct Tok)));

tmpL->length = 3;
tmpL->elemSize = sizeof(struct Tok);
tmpL->data = memoryAlloc(sizeof(struct Tok) * 50);
                    tmpL->realLength = 50;
tmpL->data[0] = ft;
tmpL->data[1] = operTok;
tmpL->data[2] = l->data[2];
tmpL = prePross(tmpL,LINE_TYPE_VAR,elems);
operT.cont = "=";

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = operT;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = operT;
        }
    }
    ;
register long int j = 0;
for (; (j<len(tmpL)); ++j) {

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = tmpL->data[j];
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = tmpL->data[j];
        }
    }
    ;
};
l = nl;
}
register long int i = 1;
while ((i<len(l))) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "=") == 0)) {
if ((strlen(currentType)>0)) {
struct string sct = string(currentType);
string__replace(&sct," ","");
v->type = string__str(&sct);
}
isEqual = true;
i = i+1;
continue;
}
}
if ((isEqual==false)) {
char * ____BAH_COMPILER_VAR_443 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentType);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_443 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_443+currStrOff, currentType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_443+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }currentType = ____BAH_COMPILER_VAR_443;
}
else {
if ((t.isEqual==true)&&(exists==false)&&(isGlobal()==false)) {
needsDefine = true;
}
if ((strcmp(t.cont, "chan") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
++i;
struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_444 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("chan:");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_444 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_444+currStrOff, "chan:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_444+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_444;
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
++i;
struct Tok nt = l->data[i];
char * ____BAH_COMPILER_VAR_445 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("map:");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_445 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_445+currStrOff, "map:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_445+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_445;
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
++i;
struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_INT)) {
throwErr(&nt,"Expected buffer length, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_446 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("buffer:");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_446 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_446+currStrOff, "buffer:", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_446+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }v->type = ____BAH_COMPILER_VAR_446;
struct variable* ____BAH_COMPILER_VAR_447 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_447->name = "";
____BAH_COMPILER_VAR_447->type = "";
____BAH_COMPILER_VAR_447->isConst = false;
____BAH_COMPILER_VAR_447->constVal = "";
____BAH_COMPILER_VAR_447->isArray = false;
____BAH_COMPILER_VAR_447->from = "";
____BAH_COMPILER_VAR_447->declScope= null;
____BAH_COMPILER_VAR_447->isGlobal = false;
____BAH_COMPILER_VAR_447->declRope= null;
____BAH_COMPILER_VAR_447->isReg = false;
____BAH_COMPILER_VAR_447->lastSet= null;
____BAH_COMPILER_VAR_447->isArg = false;
struct variable* av = ____BAH_COMPILER_VAR_447;
av->type = "char*";
av->name = genCompilerVar();

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = av;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = av;
        }
    }
    ;
struct string cType = getCType(av->type,elems);
char * ____BAH_COMPILER_VAR_448 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("];");
unsigned int strLen_2 = strlen("[");
unsigned int strLen_3 = strlen(av->name);
unsigned int strLen_4 = strlen("char ");
;                            
            ____BAH_COMPILER_VAR_448 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, "char ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, av->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_448+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_448+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_448+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_448));
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
char * ____BAH_COMPILER_VAR_449 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tp);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_449 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_449+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_449+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_449+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_449);
}
}
else {
if ((strcmp(currentType, "") == 0)) {
if ((strcmp(v->type, "") == 0)) {
v->type = tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_450 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tp);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_450 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_450+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_450+currStrOff, tp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_450+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_450+currStrOff, v->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_450+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_450);
}
}
}
}
if ((strcmp(t.cont, "") != 0)&&(strHasPrefix(t.cont,"{")==false)) {
char * ____BAH_COMPILER_VAR_451 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_451 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_451+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_451+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_451;
if ((t.isOper==false)&&(RCPavailable()==true)) {
struct variable* iv = searchVar(t.cont,elems);
if ((iv!=null)&&(iv->isConst==false)) {
toVar = true;
isPointedVar = strHasPrefix(t.cont,"&");
struct cStruct* s = searchStruct(iv->type,elems);
if ((s!=null)&&(strCount(iv->type,"*")==0)&&(s->isBinding==false)) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_452 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(iv->name);
unsigned int strLen_1 = strlen("), 0)");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(iv->name);
unsigned int strLen_4 = strlen("; RCP_scanStack(&");
unsigned int strLen_5 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_452 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_452+currStrOff, code, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_452+currStrOff, "; RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_452+currStrOff, iv->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_452+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_452+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_452+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_452;
}
else {
struct string ivn = string(iv->name);
if ((string__count(&ivn,"*")>0)) {
string__replace(&ivn,"*","");
char * ____BAH_COMPILER_VAR_453 =null;char * ____BAH_COMPILER_VAR_454 =string__str(&ivn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(iv->name);
unsigned int strLen_1 = strlen("), 0)");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_454);
unsigned int strLen_4 = strlen("; RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, "; RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, ____BAH_COMPILER_VAR_454, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_453+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_453+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_453+currStrOff, "), 0)", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_455 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_453);
;                            
            ____BAH_COMPILER_VAR_455 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_455+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_455+currStrOff, ____BAH_COMPILER_VAR_453, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_455;
}
else {
char * ____BAH_COMPILER_VAR_456 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(iv->name);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("; RCP_incr(");
unsigned int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_456 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_456+currStrOff, "; RCP_incr(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_456+currStrOff, iv->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_456+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_456;
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
char * ____BAH_COMPILER_VAR_457 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_457 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_457+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_457+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_457;
}
++i;
};
if ((exists==true)) {
v->lastSet = elems;
if ((ft.parent!=null)) {
ft.parent->lastSet = elems;
}
if ((currentFn!=null)) {

                struct string ____BAH_COMPILER_VAR_458 = string(v->name);
                if ((strcmp(v->name, "this") == 0)||string__hasPrefix(&____BAH_COMPILER_VAR_458,"this->")) {
currentFn->isMut = true;
}
}
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {
struct Tok st = l->data[1];
char * ____BAH_COMPILER_VAR_459 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen("' to {TOKEN}.");
unsigned int strLen_2 = strlen("Cannot change the type of already declared var '");
;                            
            ____BAH_COMPILER_VAR_459 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_459+currStrOff, "Cannot change the type of already declared var '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_459+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_459+currStrOff, "' to {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&st,____BAH_COMPILER_VAR_459);
}
char * preCode = "";
if ((isStruct==false)) {
if (isRCPpointerType(v->type)&&(isPointedVar==false)&&(RCPavailable()==true)) {
struct string cType = getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_460 =null;char * ____BAH_COMPILER_VAR_461 =string__str(&cType);char * ____BAH_COMPILER_VAR_462 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)RCP_incrIL(&");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_461);
unsigned int strLen_4 = strlen(") = *(");
unsigned int strLen_5 = strlen(v->name);
unsigned int strLen_6 = strlen("*)RCP_decrIL(&");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_462);
unsigned int strLen_8 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_460 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_460+currStrOff, "*(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_460+currStrOff, ____BAH_COMPILER_VAR_462, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_460+currStrOff, "*)RCP_decrIL(&", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_460+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_460+currStrOff, ") = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_460+currStrOff, ____BAH_COMPILER_VAR_461, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_460+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_460+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_460+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_460;
}
else {
struct variable* ____BAH_COMPILER_VAR_463 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_463->name = "";
____BAH_COMPILER_VAR_463->type = "";
____BAH_COMPILER_VAR_463->isConst = false;
____BAH_COMPILER_VAR_463->constVal = "";
____BAH_COMPILER_VAR_463->isArray = false;
____BAH_COMPILER_VAR_463->from = "";
____BAH_COMPILER_VAR_463->declScope= null;
____BAH_COMPILER_VAR_463->isGlobal = false;
____BAH_COMPILER_VAR_463->declRope= null;
____BAH_COMPILER_VAR_463->isReg = false;
____BAH_COMPILER_VAR_463->lastSet= null;
____BAH_COMPILER_VAR_463->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_463;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_464 =null;char * ____BAH_COMPILER_VAR_465 =rope__toStr(dv);char * ____BAH_COMPILER_VAR_466 =string__str(&cType);char * ____BAH_COMPILER_VAR_467 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(");");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_465);
unsigned int strLen_2 = strlen(code);
unsigned int strLen_3 = strlen("*)RCP_incrIL(&");
unsigned int strLen_4 = strlen(____BAH_COMPILER_VAR_466);
unsigned int strLen_5 = strlen(" = *(");
unsigned int strLen_6 = strlen(v->name);
unsigned int strLen_7 = strlen("; ");
unsigned int strLen_8 = strlen(v->name);
unsigned int strLen_9 = strlen(" = ");
unsigned int strLen_10 = strlen(tmpV->name);
unsigned int strLen_11 = strlen(" ");
unsigned int strLen_12 = strlen(____BAH_COMPILER_VAR_467);
;                            
            ____BAH_COMPILER_VAR_464 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, ____BAH_COMPILER_VAR_467, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, " ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, tmpV->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, " = ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, v->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, "; ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, " = *(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, ____BAH_COMPILER_VAR_466, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, "*)RCP_incrIL(&", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_464+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_464+currStrOff, ");", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_464+currStrOff, ____BAH_COMPILER_VAR_465, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_464;
}
}
else {
struct variable* ____BAH_COMPILER_VAR_468 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_468->name = "";
____BAH_COMPILER_VAR_468->type = "";
____BAH_COMPILER_VAR_468->isConst = false;
____BAH_COMPILER_VAR_468->constVal = "";
____BAH_COMPILER_VAR_468->isArray = false;
____BAH_COMPILER_VAR_468->from = "";
____BAH_COMPILER_VAR_468->declScope= null;
____BAH_COMPILER_VAR_468->isGlobal = false;
____BAH_COMPILER_VAR_468->declRope= null;
____BAH_COMPILER_VAR_468->isReg = false;
____BAH_COMPILER_VAR_468->lastSet= null;
____BAH_COMPILER_VAR_468->isArg = false;
struct variable* tmpV = ____BAH_COMPILER_VAR_468;
tmpV->name = genCompilerVar();
tmpV->type = v->type;
struct rope* dv = decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_469 =null;char * ____BAH_COMPILER_VAR_470 =rope__toStr(dv);char * ____BAH_COMPILER_VAR_471 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(";");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_470);
unsigned int strLen_2 = strlen(code);
unsigned int strLen_3 = strlen(" = ");
unsigned int strLen_4 = strlen(v->name);
unsigned int strLen_5 = strlen("; ");
unsigned int strLen_6 = strlen(v->name);
unsigned int strLen_7 = strlen(" = ");
unsigned int strLen_8 = strlen(tmpV->name);
unsigned int strLen_9 = strlen(" ");
unsigned int strLen_10 = strlen(____BAH_COMPILER_VAR_471);
;                            
            ____BAH_COMPILER_VAR_469 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10);
            
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, ____BAH_COMPILER_VAR_471, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, " ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, tmpV->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, " = ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, v->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, "; ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, v->name, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, " = ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_469+currStrOff, code, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_469+currStrOff, ";", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_469+currStrOff, ____BAH_COMPILER_VAR_470, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_469;
}
}
else {
struct cStruct* s = searchStruct(v->type,elems);
if ((s!=null)&&(RCPavailable()==true)&&(RCPselfRef(v)==false)&&(s->isBinding==false)) {
if ((strCount(v->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_472 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 1); ");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("RCP_scanStack(&");
;                            
            ____BAH_COMPILER_VAR_472 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_472+currStrOff, "RCP_scanStack(&", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_472+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_472+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_472+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_472+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_472;
}
else {
struct string vn = string(v->name);
string__replace(&vn,"*","");
char * ____BAH_COMPILER_VAR_473 =null;char * ____BAH_COMPILER_VAR_474 =string__str(&vn);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen("), 1); ");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_474);
unsigned int strLen_4 = strlen("RCP_scanStack(");
;                            
            ____BAH_COMPILER_VAR_473 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_473+currStrOff, "RCP_scanStack(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_473+currStrOff, ____BAH_COMPILER_VAR_474, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_473+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_473+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_473+currStrOff, "), 1); ", strLen_1);
            currStrOff += strLen_1;
        
        }preCode = ____BAH_COMPILER_VAR_473;
}
char * ____BAH_COMPILER_VAR_475 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_475 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_475+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_475+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_475+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_475;
}
else {
char * ____BAH_COMPILER_VAR_476 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_476 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_476+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_476+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_476+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_476;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_477 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_477 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_477+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_477+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_477+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_477;
}
}
if ((v->isArray==true)) {
code = genArrRealloc(v,preCode,code,elems);
}
else {
char * ____BAH_COMPILER_VAR_478 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(preCode);
unsigned int strLen_1 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_478 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_478+currStrOff, preCode, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_478+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_478;
}
}
else {
if ((strcmp(currentType, "") != 0)) {
v->type = currentType;
}
struct string vts = string(v->type);
string__replace(&vts," ","");
v->type = string__str(&vts);
if ((strlen(v->type)==0)) {
throwErr(&ft,"Cannot declare {TOKEN} without a type.");
}
char * vct= null;
if (string__hasPrefix(&vts,"function(")) {
struct func* tmpfn = parseFnType(vts);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
register long int j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_479 =null;char * ____BAH_COMPILER_VAR_480 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_480);
;                            
            ____BAH_COMPILER_VAR_479 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_479+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_479+currStrOff, ____BAH_COMPILER_VAR_480, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_479;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_481 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_481 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_481+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_481+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_481;
}
};
char * ____BAH_COMPILER_VAR_482 =null;char * ____BAH_COMPILER_VAR_483 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_483);
;                            
            ____BAH_COMPILER_VAR_482 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, ____BAH_COMPILER_VAR_483, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_482+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_482+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_482+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_482;
}
else {
vct = setCType(v,elems);
}
if ((strcmp(code, "") != 0)&&(shouldOnlyDecl==false)) {
if (isRCPpointerType(v->type)&&(RCPavailable()==true)&&(toVar==true)&&(isPointedVar==false)) {
struct string cType = getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_484 =null;char * ____BAH_COMPILER_VAR_485 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("*)RCP_incrIL(&");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_485);
unsigned int strLen_4 = strlen(" = *(");
unsigned int strLen_5 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_484 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_484+currStrOff, v->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_484+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_484+currStrOff, ____BAH_COMPILER_VAR_485, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_484+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_484+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_484+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_484));
}
else {
char * ____BAH_COMPILER_VAR_486 =null;char * ____BAH_COMPILER_VAR_487 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)RCP_incrIL(&");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_487);
unsigned int strLen_4 = strlen(" = *(");
unsigned int strLen_5 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_486 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_486+currStrOff, vct, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_486+currStrOff, " = *(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_486+currStrOff, ____BAH_COMPILER_VAR_487, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_486+currStrOff, "*)RCP_incrIL(&", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_486+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_486+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_486;
}
}
else {
if ((needsDefine==true)) {

    {
        unsigned long nLength = len(elems->defined);
        if (nLength >= elems->defined->length) {
            if (nLength >= elems->defined->realLength) {
                if (elems->defined->realLength != 0) {
                    elems->defined->realLength *= 2;
                } else {
                    elems->defined->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->defined->data, (elems->defined->realLength)*sizeof(char *));
                elems->defined->data = newPtr;
            }
            elems->defined->data[len(elems->defined)] = v->name;
            elems->defined->length = nLength+1;
        } else {
            elems->defined->data[len(elems->defined)] = v->name;
        }
    }
    ;
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_488 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_488 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_488+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_488+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_488+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_488+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_488+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_488));
}
else {
char * ____BAH_COMPILER_VAR_489 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(v->name);
unsigned int strLen_3 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_489 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, "#define ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_489+currStrOff, v->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_489+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_489+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_489;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_490 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_490 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_490+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_490+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_490+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_490+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_490));
}
else {
char * ____BAH_COMPILER_VAR_491 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" = ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_491 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_491+currStrOff, vct, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_491+currStrOff, " = ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_491+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_491;
}
}
}
}
else {
if (isRCPpointerType(v->type)&&(shouldOnlyDecl==false)) {
char * ____BAH_COMPILER_VAR_492 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(vct);
unsigned int strLen_1 = strlen("= null");
;                            
            ____BAH_COMPILER_VAR_492 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_492+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_492+currStrOff, "= null", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_492;
}
else {
code = vct;
}
}
if ((shouldOnlyDecl==true)) {
char * ____BAH_COMPILER_VAR_493 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("extern ");
unsigned int strLen_1 = strlen(vct);
;                            
            ____BAH_COMPILER_VAR_493 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_493+currStrOff, "extern ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_493+currStrOff, vct, strLen_1);
            currStrOff += strLen_1;
        
        }vct = ____BAH_COMPILER_VAR_493;
}
if (isGlobal()) {
v->isGlobal = true;
}
else {
v->isGlobal = false;
}
v->declScope = elems;

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = v;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = v;
        }
    }
    ;
struct variable* ____BAH_COMPILER_VAR_494 = v;
char ** ____BAH_COMPILER_VAR_496 = (char **)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_497 = __reflect(____BAH_COMPILER_VAR_496, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_498 = (char **)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_499 = __reflect(____BAH_COMPILER_VAR_498, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_500 = (char*)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_501 = __reflect(____BAH_COMPILER_VAR_500, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_502 = (char **)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_503 = __reflect(____BAH_COMPILER_VAR_502, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_504 = (char*)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_505 = __reflect(____BAH_COMPILER_VAR_504, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_506 = (char **)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_507 = __reflect(____BAH_COMPILER_VAR_506, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_508 = (void **)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_509 = __reflect(____BAH_COMPILER_VAR_508, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_510 = (char*)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_511 = __reflect(____BAH_COMPILER_VAR_510, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_512 = (struct rope**)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_514 = (void **)((char*)(____BAH_COMPILER_VAR_512) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_515 = __reflect(____BAH_COMPILER_VAR_514, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_516 = (void **)((char*)(____BAH_COMPILER_VAR_512) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_517 = __reflect(____BAH_COMPILER_VAR_516, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_518 = (char **)((char*)(____BAH_COMPILER_VAR_512) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_519 = __reflect(____BAH_COMPILER_VAR_518, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_520 = (int*)((char*)(____BAH_COMPILER_VAR_512) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_521 = __reflect(____BAH_COMPILER_VAR_520, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_522 = (int*)((char*)(____BAH_COMPILER_VAR_512) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_523 = __reflect(____BAH_COMPILER_VAR_522, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_524 = (int*)((char*)(____BAH_COMPILER_VAR_512) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_525 = __reflect(____BAH_COMPILER_VAR_524, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_513 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_513->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_513->length = 6;
        ____BAH_COMPILER_VAR_513->data = memoryAlloc(____BAH_COMPILER_VAR_513->length * ____BAH_COMPILER_VAR_513->elemSize);
        ____BAH_COMPILER_VAR_513->data[0] = ____BAH_COMPILER_VAR_515;
____BAH_COMPILER_VAR_513->data[1] = ____BAH_COMPILER_VAR_517;
____BAH_COMPILER_VAR_513->data[2] = ____BAH_COMPILER_VAR_519;
____BAH_COMPILER_VAR_513->data[3] = ____BAH_COMPILER_VAR_521;
____BAH_COMPILER_VAR_513->data[4] = ____BAH_COMPILER_VAR_523;
____BAH_COMPILER_VAR_513->data[5] = ____BAH_COMPILER_VAR_525;
struct reflectElement ____BAH_COMPILER_VAR_526 = __reflect(____BAH_COMPILER_VAR_512, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_513, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_527 = (char*)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_528 = __reflect(____BAH_COMPILER_VAR_527, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_529 = (char*)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_530 = __reflect(____BAH_COMPILER_VAR_529, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_531 = (void **)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_532 = __reflect(____BAH_COMPILER_VAR_531, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_533 = (char*)((char*)(____BAH_COMPILER_VAR_494) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_534 = __reflect(____BAH_COMPILER_VAR_533, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_495 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_495->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_495->length = 13;
        ____BAH_COMPILER_VAR_495->data = memoryAlloc(____BAH_COMPILER_VAR_495->length * ____BAH_COMPILER_VAR_495->elemSize);
        ____BAH_COMPILER_VAR_495->data[0] = ____BAH_COMPILER_VAR_497;
____BAH_COMPILER_VAR_495->data[1] = ____BAH_COMPILER_VAR_499;
____BAH_COMPILER_VAR_495->data[2] = ____BAH_COMPILER_VAR_501;
____BAH_COMPILER_VAR_495->data[3] = ____BAH_COMPILER_VAR_503;
____BAH_COMPILER_VAR_495->data[4] = ____BAH_COMPILER_VAR_505;
____BAH_COMPILER_VAR_495->data[5] = ____BAH_COMPILER_VAR_507;
____BAH_COMPILER_VAR_495->data[6] = ____BAH_COMPILER_VAR_509;
____BAH_COMPILER_VAR_495->data[7] = ____BAH_COMPILER_VAR_511;
____BAH_COMPILER_VAR_495->data[8] = ____BAH_COMPILER_VAR_526;
____BAH_COMPILER_VAR_495->data[9] = ____BAH_COMPILER_VAR_528;
____BAH_COMPILER_VAR_495->data[10] = ____BAH_COMPILER_VAR_530;
____BAH_COMPILER_VAR_495->data[11] = ____BAH_COMPILER_VAR_532;
____BAH_COMPILER_VAR_495->data[12] = ____BAH_COMPILER_VAR_534;
struct reflectElement ____BAH_COMPILER_VAR_535 = __reflect(____BAH_COMPILER_VAR_494, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_495, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_535);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_536 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(vct);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_536 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_536+currStrOff, vct, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_536+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_536));
}
}
if (isGlobal()) {
if ((isSubObject==false)) {
INIT = rope__add(INIT, rope(NEXT_LINE));
}
NEXT_LINE = "";
}
else {
if ((needsDefine==true)) {
char * ____BAH_COMPILER_VAR_537 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen("\n");
;                            
            ____BAH_COMPILER_VAR_537 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_537+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_537+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_537));
}
else {
char * ____BAH_COMPILER_VAR_538 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_538 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_538+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_538+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* declR = rope(____BAH_COMPILER_VAR_538);
if ((exists==false)) {
v->declRope = declR;
v->canBeReg = true;
}
OUTPUT = rope__add(OUTPUT, declR);
}
}
};
char * getCfunctionType(struct string* cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn = parseFnType(*cfrt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
register long int j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_539 =null;char * ____BAH_COMPILER_VAR_540 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_540);
;                            
            ____BAH_COMPILER_VAR_539 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_539+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_539+currStrOff, ____BAH_COMPILER_VAR_540, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_539;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_541 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_541 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_541+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_541+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_541;
}
};
char * ____BAH_COMPILER_VAR_542 =null;char * ____BAH_COMPILER_VAR_543 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(elemName);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_543);
;                            
            ____BAH_COMPILER_VAR_542 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, ____BAH_COMPILER_VAR_543, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, elemName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_542+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_542+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_542+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }return ____BAH_COMPILER_VAR_542;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
register long int j = *i;
struct Tok ft = l->data[j];
char * tpdf = "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_544 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(prev);
unsigned int strLen_1 = strlen(ft.cont);
;                            
            ____BAH_COMPILER_VAR_544 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_544+currStrOff, prev, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_544+currStrOff, ft.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fn->name = ____BAH_COMPILER_VAR_544;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_545 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_545+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_545+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * code = ____BAH_COMPILER_VAR_545;
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
char * ____BAH_COMPILER_VAR_546 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(argType);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_546 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_546+currStrOff, argType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_546+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }argType = ____BAH_COMPILER_VAR_546;
}
}
else {
isComa = true;
break;
}
j = j+1;
};
struct variable* ____BAH_COMPILER_VAR_547 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_547->name = "";
____BAH_COMPILER_VAR_547->type = "";
____BAH_COMPILER_VAR_547->isConst = false;
____BAH_COMPILER_VAR_547->constVal = "";
____BAH_COMPILER_VAR_547->isArray = false;
____BAH_COMPILER_VAR_547->from = "";
____BAH_COMPILER_VAR_547->declScope= null;
____BAH_COMPILER_VAR_547->isGlobal = false;
____BAH_COMPILER_VAR_547->declRope= null;
____BAH_COMPILER_VAR_547->isReg = false;
____BAH_COMPILER_VAR_547->lastSet= null;
____BAH_COMPILER_VAR_547->isArg = false;
struct variable* argument = ____BAH_COMPILER_VAR_547;
argument->name = argName;
argument->type = argType;

    {
        unsigned long nLength = len(arguments);
        if (nLength >= arguments->length) {
            if (nLength >= arguments->realLength) {
                if (arguments->realLength != 0) {
                    arguments->realLength *= 2;
                } else {
                    arguments->realLength = 50;
                }
                void * newPtr = memoryRealloc(arguments->data, (arguments->realLength)*sizeof(struct variable*));
                arguments->data = newPtr;
            }
            arguments->data[len(arguments)] = argument;
            arguments->length = nLength+1;
        } else {
            arguments->data[len(arguments)] = argument;
        }
    }
    ;
struct string argCType = getCType(argType,elems);
struct string cfrt = string(argType);
char * newArgType = string__str(&argCType);
if ((string__hasPrefix(&cfrt,"[]")==1)) {
string__trimLeft(&cfrt,2);
if (string__hasSuffix(&cfrt,"*")) {
long int nbast = string__count(&cfrt,"*");
string__trimRight(&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_548 =null;char * ____BAH_COMPILER_VAR_549 =string__str(&cfrt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__BAH_ARR_TYPE_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_549);
;                            
            ____BAH_COMPILER_VAR_548 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_548+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_548+currStrOff, ____BAH_COMPILER_VAR_549, strLen_1);
            currStrOff += strLen_1;
        
        }newArgType = ____BAH_COMPILER_VAR_548;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newArgType,csatd)==false)) {

    {
        unsigned long nLength = len(csatd);
        if (nLength >= csatd->length) {
            if (nLength >= csatd->realLength) {
                if (csatd->realLength != 0) {
                    csatd->realLength *= 2;
                } else {
                    csatd->realLength = 50;
                }
                void * newPtr = memoryRealloc(csatd->data, (csatd->realLength)*sizeof(char *));
                csatd->data = newPtr;
            }
            csatd->data[len(csatd)] = newArgType;
            csatd->length = nLength+1;
        } else {
            csatd->data[len(csatd)] = newArgType;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_550 =null;char * ____BAH_COMPILER_VAR_551 =string__str(&argCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(newArgType);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_551);
unsigned int strLen_4 = strlen("typedef ");
unsigned int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_550 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_550+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_550+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_550+currStrOff, ____BAH_COMPILER_VAR_551, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_550+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_550+currStrOff, newArgType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_550+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_550;
}
}
if ((string__hasPrefix(&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_552 =null;char * ____BAH_COMPILER_VAR_553 =getCfunctionType(&cfrt,argName,elems);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_553);
;                            
            ____BAH_COMPILER_VAR_552 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_552+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_552+currStrOff, ____BAH_COMPILER_VAR_553, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_552;
}
else {
char * ____BAH_COMPILER_VAR_554 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(argName);
unsigned int strLen_2 = strlen(newArgType);
unsigned int strLen_3 = strlen(code);
;                            
            ____BAH_COMPILER_VAR_554 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_554+currStrOff, code, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_554+currStrOff, newArgType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_554+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_554+currStrOff, argName, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_554;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_555 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_555 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_555+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_555+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_555;
}
else {
char * ____BAH_COMPILER_VAR_556 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_556 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_556+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_556+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_556;
break;
}
j = j+1;
};
}
else {
char * ____BAH_COMPILER_VAR_557 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_557 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_557+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_557+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_557;
}
j = j+1;
struct variable* ____BAH_COMPILER_VAR_558 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_558->name = "";
____BAH_COMPILER_VAR_558->type = "";
____BAH_COMPILER_VAR_558->isConst = false;
____BAH_COMPILER_VAR_558->constVal = "";
____BAH_COMPILER_VAR_558->isArray = false;
____BAH_COMPILER_VAR_558->from = "";
____BAH_COMPILER_VAR_558->declScope= null;
____BAH_COMPILER_VAR_558->isGlobal = false;
____BAH_COMPILER_VAR_558->declRope= null;
____BAH_COMPILER_VAR_558->isReg = false;
____BAH_COMPILER_VAR_558->lastSet= null;
____BAH_COMPILER_VAR_558->isArg = false;
struct variable* returns = ____BAH_COMPILER_VAR_558;
returns->type = "";
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_559 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(returns->type);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_559 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_559+currStrOff, returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_559+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }returns->type = ____BAH_COMPILER_VAR_559;
j = j+1;
};
if (strlen(returns->type)) {
struct string rts = string(returns->type);
string__replace(&rts," ","");
returns->type = rts.content;
}
*i = j;
returns->name = fn->name;
fn->returns = returns;
fn->args = arguments;
struct string fnRetType = getCType(returns->type,elems);
char * newFnRetType = string__str(&fnRetType);
struct string cfrt = string(returns->type);
if ((string__hasPrefix(&cfrt,"[]")==1)) {
string__trimLeft(&cfrt,2);
if (string__hasSuffix(&cfrt,"*")) {
long int nbast = string__count(&cfrt,"*");
string__trimRight(&cfrt,nbast);
}
char * ____BAH_COMPILER_VAR_560 =null;char * ____BAH_COMPILER_VAR_561 =string__str(&cfrt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__BAH_ARR_TYPE_");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_561);
;                            
            ____BAH_COMPILER_VAR_560 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_560+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_560+currStrOff, ____BAH_COMPILER_VAR_561, strLen_1);
            currStrOff += strLen_1;
        
        }newFnRetType = ____BAH_COMPILER_VAR_560;
array(char *)* csatd = compilerState.arrTypesDecl;
if ((inArrayStr(newFnRetType,csatd)==false)) {

    {
        unsigned long nLength = len(csatd);
        if (nLength >= csatd->length) {
            if (nLength >= csatd->realLength) {
                if (csatd->realLength != 0) {
                    csatd->realLength *= 2;
                } else {
                    csatd->realLength = 50;
                }
                void * newPtr = memoryRealloc(csatd->data, (csatd->realLength)*sizeof(char *));
                csatd->data = newPtr;
            }
            csatd->data[len(csatd)] = newFnRetType;
            csatd->length = nLength+1;
        } else {
            csatd->data[len(csatd)] = newFnRetType;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_562 =null;char * ____BAH_COMPILER_VAR_563 =string__str(&fnRetType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(newFnRetType);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_563);
unsigned int strLen_4 = strlen("typedef ");
unsigned int strLen_5 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_562 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, tpdf, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, ____BAH_COMPILER_VAR_563, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_562+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_562+currStrOff, newFnRetType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_562+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }tpdf = ____BAH_COMPILER_VAR_562;
}
}
char * ____BAH_COMPILER_VAR_564 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(code);
unsigned int strLen_2 = strlen(newFnRetType);
unsigned int strLen_3 = strlen(tpdf);
;                            
            ____BAH_COMPILER_VAR_564 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_564+currStrOff, tpdf, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_564+currStrOff, newFnRetType, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_564+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_564+currStrOff, code, strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_564;
return code;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* ____BAH_COMPILER_VAR_565 = memoryAlloc(sizeof(struct cStruct));
____BAH_COMPILER_VAR_565->name = "";
____BAH_COMPILER_VAR_565->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ____BAH_COMPILER_VAR_565->members->length = 0;
            ____BAH_COMPILER_VAR_565->members->elemSize = sizeof(struct structMemb*);
            ____BAH_COMPILER_VAR_565->methods = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_565->methods->length = 0;
            ____BAH_COMPILER_VAR_565->methods->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_565->postCode = "";
____BAH_COMPILER_VAR_565->extendedFrom = "";
____BAH_COMPILER_VAR_565->isBinding = false;
____BAH_COMPILER_VAR_565->hasRCPmemb = false;
struct cStruct* s = ____BAH_COMPILER_VAR_565;
array(struct cStruct*)* structs = elems->structs;

    {
        unsigned long nLength = len(structs);
        if (nLength >= structs->length) {
            if (nLength >= structs->realLength) {
                if (structs->realLength != 0) {
                    structs->realLength *= 2;
                } else {
                    structs->realLength = 50;
                }
                void * newPtr = memoryRealloc(structs->data, (structs->realLength)*sizeof(struct cStruct*));
                structs->data = newPtr;
            }
            structs->data[len(structs)] = s;
            structs->length = nLength+1;
        } else {
            structs->data[len(structs)] = s;
        }
    }
    ;
array(struct func*)* methds = s->methods;
if ((len(l)<4)) {
throwErr(&l->data[len(l)-1],"Cannot declare struct has such, please do 'struct <name> { <memberName>:<memberType> }'.");
}
struct Tok nameToken = l->data[1];
register long int i = 2;
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
++i;
struct Tok extdSNameTk = l->data[i];
++i;
if ((extdSNameTk.type!=TOKEN_TYPE_VAR)) {
throwErr(&extdSNameTk,"Cannot use {TOKEN} as struct name.");
}
struct cStruct* extdS = searchStruct(extdSNameTk.cont,elems);
s->extendedFrom = extdS->name;
if ((extdS==null)) {
throwErr(&extdSNameTk,"Struct {TOKEN} does not exist.");
}
array(struct structMemb*)* extdsmbs = extdS->members;
register long int j = 0;
while ((j<len(extdsmbs))) {
struct structMemb* em = extdsmbs->data[j];
struct string cemt = string(em->type);
char * membDeclStr= null;
if ((string__hasPrefix(&cemt,"function(")==1)) {
struct func* tmpfn = parseFnType(cemt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_566 =null;char * ____BAH_COMPILER_VAR_567 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_567);
;                            
            ____BAH_COMPILER_VAR_566 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_566+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_566+currStrOff, ____BAH_COMPILER_VAR_567, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_566;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_568 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_568+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_568+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_568;
}
};
char * ____BAH_COMPILER_VAR_569 =null;char * ____BAH_COMPILER_VAR_570 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(em->name);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_570);
;                            
            ____BAH_COMPILER_VAR_569 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_569+currStrOff, ____BAH_COMPILER_VAR_570, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_569+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_569+currStrOff, em->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_569+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_569+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_569+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_569;
}
else {
if (isRCPpointerType(em->type)) {
s->hasRCPmemb = true;
}
struct string membDecl = getCType(em->type,elems);
string__append(&membDecl," ");
string__append(&membDecl,em->name);
membDeclStr = membDecl.content;
}

    {
        unsigned long nLength = len(allMembs);
        if (nLength >= allMembs->length) {
            if (nLength >= allMembs->realLength) {
                if (allMembs->realLength != 0) {
                    allMembs->realLength *= 2;
                } else {
                    allMembs->realLength = 50;
                }
                void * newPtr = memoryRealloc(allMembs->data, (allMembs->realLength)*sizeof(char *));
                allMembs->data = newPtr;
            }
            allMembs->data[len(allMembs)] = membDeclStr;
            allMembs->length = nLength+1;
        } else {
            allMembs->data[len(allMembs)] = membDeclStr;
        }
    }
    ;

    {
        unsigned long nLength = len(members);
        if (nLength >= members->length) {
            if (nLength >= members->realLength) {
                if (members->realLength != 0) {
                    members->realLength *= 2;
                } else {
                    members->realLength = 50;
                }
                void * newPtr = memoryRealloc(members->data, (members->realLength)*sizeof(struct structMemb*));
                members->data = newPtr;
            }
            members->data[len(members)] = em;
            members->length = nLength+1;
        } else {
            members->data[len(members)] = em;
        }
    }
    ;
j = j+1;
};
}
else {
throwErr(&st,"Cannot use keyword {TOKEN} in struct declaration.");
}
}
struct Tok braceTk = l->data[i];
++i;
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
struct structMemb* ____BAH_COMPILER_VAR_571 = memoryAlloc(sizeof(struct structMemb));
____BAH_COMPILER_VAR_571->name = "";
____BAH_COMPILER_VAR_571->type = "";
____BAH_COMPILER_VAR_571->isConst = false;
____BAH_COMPILER_VAR_571->constVal = "";
____BAH_COMPILER_VAR_571->isArray = false;
____BAH_COMPILER_VAR_571->from = "";
____BAH_COMPILER_VAR_571->declScope= null;
____BAH_COMPILER_VAR_571->isGlobal = false;
____BAH_COMPILER_VAR_571->declRope= null;
____BAH_COMPILER_VAR_571->isReg = false;
____BAH_COMPILER_VAR_571->lastSet= null;
____BAH_COMPILER_VAR_571->isArg = false;
____BAH_COMPILER_VAR_571->def = "";
____BAH_COMPILER_VAR_571->isFn = false;
struct structMemb* memb = ____BAH_COMPILER_VAR_571;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name = t.cont;
register long int ii = 0;
while ((ii<len(members))) {
struct structMemb* m = members->data[ii];
if ((strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii = ii+1;
};
++i;
t = l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_572 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_572 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_572+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_572+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnPrefix = ____BAH_COMPILER_VAR_572;
struct func* ____BAH_COMPILER_VAR_573 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_573->name = "";
____BAH_COMPILER_VAR_573->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_573->args->length = 0;
            ____BAH_COMPILER_VAR_573->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_573->returns= null;
____BAH_COMPILER_VAR_573->isBinding = false;
____BAH_COMPILER_VAR_573->from = "";
____BAH_COMPILER_VAR_573->file = "";
____BAH_COMPILER_VAR_573->line = 1;
____BAH_COMPILER_VAR_573->isVar = false;
____BAH_COMPILER_VAR_573->used = false;
____BAH_COMPILER_VAR_573->code = null;
____BAH_COMPILER_VAR_573->isMut = false;
____BAH_COMPILER_VAR_573->isImported = false;
struct func* fn = ____BAH_COMPILER_VAR_573;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int j = i-1;
while ((j<len(l))) {
t = l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
if ((j==i)) {
t.type = TOKEN_TYPE_VAR;
t.cont = "this";
t.isValue = true;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
t.type = TOKEN_TYPE_VAR;
char * ____BAH_COMPILER_VAR_574 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_574 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_574+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_574+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_574;
t.isValue = true;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
struct Tok nt = l->data[j+1];
if ((strcmp(nt.cont, ")") != 0)) {
t.type = TOKEN_TYPE_SYNTAX;
t.cont = ",";
t.isValue = false;

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
}
}
j = j+1;
};
--i;
long int nli = 0;
char * ____BAH_COMPILER_VAR_575 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code = rope(____BAH_COMPILER_VAR_575);
i = i+nli;
i = i-2;
struct variable* returns = fn->returns;
array(struct variable*)* arguments = fn->args;
fn->from = s->name;
if ((shouldOnlyDecl==true)) {
code = rope__add(code, rope(";\n"));
}
else {
code = rope__add(code, rope("{\n"));
}
struct Elems* fnElems = dupElems(elems);
j = 0;
for (; (j<len(arguments)); ++j) {
struct variable* a = arguments->data[j];
a->declScope = elems;
a->isArg = true;

    {
        unsigned long nLength = len(fnElems->vars);
        if (nLength >= fnElems->vars->length) {
            if (nLength >= fnElems->vars->realLength) {
                if (fnElems->vars->realLength != 0) {
                    fnElems->vars->realLength *= 2;
                } else {
                    fnElems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(fnElems->vars->data, (fnElems->vars->realLength)*sizeof(struct variable*));
                fnElems->vars->data = newPtr;
            }
            fnElems->vars->data[len(fnElems->vars)] = a;
            fnElems->vars->length = nLength+1;
        } else {
            fnElems->vars->data[len(fnElems->vars)] = a;
        }
    }
    ;
};
array(struct func*)* fns = elems->fns;

    {
        unsigned long nLength = len(fns);
        if (nLength >= fns->length) {
            if (nLength >= fns->realLength) {
                if (fns->realLength != 0) {
                    fns->realLength *= 2;
                } else {
                    fns->realLength = 50;
                }
                void * newPtr = memoryRealloc(fns->data, (fns->realLength)*sizeof(struct func*));
                fns->data = newPtr;
            }
            fns->data[len(fns)] = fn;
            fns->length = nLength+1;
        } else {
            fns->data[len(fns)] = fn;
        }
    }
    ;
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int nbBraces = 1;
t = l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
++i;
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
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = t;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = t;
        }
    }
    ;
++i;
};
struct func* ____BAH_COMPILER_VAR_576 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_576->name = "";
____BAH_COMPILER_VAR_576->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_576->args->length = 0;
            ____BAH_COMPILER_VAR_576->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_576->returns= null;
____BAH_COMPILER_VAR_576->isBinding = false;
____BAH_COMPILER_VAR_576->from = "";
____BAH_COMPILER_VAR_576->file = "";
____BAH_COMPILER_VAR_576->line = 1;
____BAH_COMPILER_VAR_576->isVar = false;
____BAH_COMPILER_VAR_576->used = false;
____BAH_COMPILER_VAR_576->code = null;
____BAH_COMPILER_VAR_576->isMut = false;
____BAH_COMPILER_VAR_576->isImported = false;
struct func* mfn = ____BAH_COMPILER_VAR_576;
mfn->args = fn->args;
mfn->name = fn->name;
mfn->returns = fn->returns;
mfn->from = s->name;
strTrimLeft(&mfn->name,strlen(fnPrefix));

    {
        unsigned long nLength = len(methds);
        if (nLength >= methds->length) {
            if (nLength >= methds->realLength) {
                if (methds->realLength != 0) {
                    methds->realLength *= 2;
                } else {
                    methds->realLength = 50;
                }
                void * newPtr = memoryRealloc(methds->data, (methds->realLength)*sizeof(struct func*));
                methds->data = newPtr;
            }
            methds->data[len(methds)] = mfn;
            methds->length = nLength+1;
        } else {
            methds->data[len(methds)] = mfn;
        }
    }
    ;
if ((shouldOnlyDecl==false)) {
if ((len(tokens)==0)) {
code = rope__add(code, rope("};\n"));
}
else {
OUTPUT = rope("");
currentFn = fn;
beginRCPscope(fnElems,fn->args);
struct Elems* ocurrFnElems = compilerState.currFnElems;
compilerState.currFnElems = fnElems;
parseLines(tokens,fnElems);
OPTI_checkFuncScopeRef(fnElems);
compilerState.currFnElems = ocurrFnElems;
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_577 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("' is not returned.");
unsigned int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_577 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_577+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_577+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_577+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_577);
}
endRCPscope(fnElems,fn->args);
}
code = rope__add(code, rope__add(OUTPUT, rope("};\n")));
}
}
else {
fn->isImported = true;
mfn->isImported = true;
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_578 =null;char * ____BAH_COMPILER_VAR_579 =rope__toStr(code);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nextLine);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_579);
;                            
            ____BAH_COMPILER_VAR_578 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_578+currStrOff, nextLine, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_578+currStrOff, ____BAH_COMPILER_VAR_579, strLen_1);
            currStrOff += strLen_1;
        
        }nextLine = ____BAH_COMPILER_VAR_578;
}
++i;
continue;
}
}
++i;
char * mbmType = "";
unsigned int currentLine = t.line;
while ((i<len(l))) {
t = l->data[i];
if ((strcmp(t.cont, "=") == 0)) {
--i;
break;
}
if ((t.line!=currentLine)) {
--i;
break;
}
char * ____BAH_COMPILER_VAR_580 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(mbmType);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_580 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_580+currStrOff, mbmType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_580+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }mbmType = ____BAH_COMPILER_VAR_580;
++i;
};
memb->type = mbmType;
++i;
t = l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
++i;
t = l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt = getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char * ____BAH_COMPILER_VAR_581 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(memb->type);
unsigned int strLen_1 = strlen(" for member.");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_581 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_581+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_581+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_581+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_581+currStrOff, memb->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_581+currStrOff, " for member.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_581);
}
memb->def = t.cont;
}
else {
--i;
}
}
if (isRCPpointerType(memb->type)) {
s->hasRCPmemb = true;
}

    {
        unsigned long nLength = len(members);
        if (nLength >= members->length) {
            if (nLength >= members->realLength) {
                if (members->realLength != 0) {
                    members->realLength *= 2;
                } else {
                    members->realLength = 50;
                }
                void * newPtr = memoryRealloc(members->data, (members->realLength)*sizeof(struct structMemb*));
                members->data = newPtr;
            }
            members->data[len(members)] = memb;
            members->length = nLength+1;
        } else {
            members->data[len(members)] = memb;
        }
    }
    ;
char * membDeclStr= null;
struct string cmt = string(memb->type);
if ((string__hasPrefix(&cmt,"function(")==1)) {
struct func* tmpfn = parseFnType(cmt);
struct string tmpfnRetCType = getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType = "";
register long int j = 0;
while ((j<len(tmpfn->args))) {
struct variable* arg = tmpfn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_582 =null;char * ____BAH_COMPILER_VAR_583 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_583);
;                            
            ____BAH_COMPILER_VAR_582 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_582+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_582+currStrOff, ____BAH_COMPILER_VAR_583, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_582;
j = j+1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_584 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_584 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_584+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_584+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_584;
}
};
char * ____BAH_COMPILER_VAR_585 =null;char * ____BAH_COMPILER_VAR_586 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(");
unsigned int strLen_3 = strlen(memb->name);
unsigned int strLen_4 = strlen(" (*");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_586);
;                            
            ____BAH_COMPILER_VAR_585 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, ____BAH_COMPILER_VAR_586, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, " (*", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, memb->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_585+currStrOff, ")(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_585+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_585+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }membDeclStr = ____BAH_COMPILER_VAR_585;
}
else {
struct string membDecl = getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_587 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(memb->name);
;                            
            ____BAH_COMPILER_VAR_587 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_587+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_587+currStrOff, memb->name, strLen_1);
            currStrOff += strLen_1;
        
        }string__append(&membDecl,____BAH_COMPILER_VAR_587);
membDeclStr = string__str(&membDecl);
}

    {
        unsigned long nLength = len(allMembs);
        if (nLength >= allMembs->length) {
            if (nLength >= allMembs->realLength) {
                if (allMembs->realLength != 0) {
                    allMembs->realLength *= 2;
                } else {
                    allMembs->realLength = 50;
                }
                void * newPtr = memoryRealloc(allMembs->data, (allMembs->realLength)*sizeof(char *));
                allMembs->data = newPtr;
            }
            allMembs->data[len(allMembs)] = membDeclStr;
            allMembs->length = nLength+1;
        } else {
            allMembs->data[len(allMembs)] = membDeclStr;
        }
    }
    ;
++i;
};
s->members = members;
if ((doesOutput==true)) {
OUTPUT = OOUT;
NEXT_LINE = nextLine;
char * ____BAH_COMPILER_VAR_588 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen(" {\n");
unsigned int strLen_2 = strlen("struct ");
;                            
            ____BAH_COMPILER_VAR_588 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_588+currStrOff, "struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_588+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_588+currStrOff, " {\n", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* code = rope(____BAH_COMPILER_VAR_588);
i = 0;
while ((i<len(allMembs))) {
char * m = allMembs->data[i];
char * ____BAH_COMPILER_VAR_589 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(m);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_589 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_589+currStrOff, m, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_589+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = rope__add(code, rope(____BAH_COMPILER_VAR_589));
++i;
};
code = rope__add(code, rope("};\n"));
OUTPUT = rope__add(OUTPUT, code);
}
if ((debug==true)) {
struct debugStruct* ____BAH_COMPILER_VAR_590 = memoryAlloc(sizeof(struct debugStruct));
____BAH_COMPILER_VAR_590->name= null;
____BAH_COMPILER_VAR_590->membs = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_590->membs->length = 0;
            ____BAH_COMPILER_VAR_590->membs->elemSize = sizeof(struct variable*);
            struct debugStruct* ds = ____BAH_COMPILER_VAR_590;
ds->name = s->name;
i = 0;
while ((i<len(s->members))) {
struct structMemb* m = s->members->data[i];
struct variable* ____BAH_COMPILER_VAR_591 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_591->name = "";
____BAH_COMPILER_VAR_591->type = "";
____BAH_COMPILER_VAR_591->isConst = false;
____BAH_COMPILER_VAR_591->constVal = "";
____BAH_COMPILER_VAR_591->isArray = false;
____BAH_COMPILER_VAR_591->from = "";
____BAH_COMPILER_VAR_591->declScope= null;
____BAH_COMPILER_VAR_591->isGlobal = false;
____BAH_COMPILER_VAR_591->declRope= null;
____BAH_COMPILER_VAR_591->isReg = false;
____BAH_COMPILER_VAR_591->lastSet= null;
____BAH_COMPILER_VAR_591->isArg = false;
struct variable* mv = ____BAH_COMPILER_VAR_591;
mv->name = m->name;
mv->type = m->type;
mv->isConst = false;
mv->isArray = m->isArray;

    {
        unsigned long nLength = i;
        if (nLength >= ds->membs->length) {
            if (nLength >= ds->membs->realLength) {
                if (ds->membs->realLength != 0) {
                    ds->membs->realLength *= 2;
                } else {
                    ds->membs->realLength = 50;
                }
                void * newPtr = memoryRealloc(ds->membs->data, (ds->membs->realLength)*sizeof(struct variable*));
                ds->membs->data = newPtr;
            }
            ds->membs->data[i] = mv;
            ds->membs->length = nLength+1;
        } else {
            ds->membs->data[i] = mv;
        }
    }
    ;
i = i+1;
};
struct debugStruct* ____BAH_COMPILER_VAR_592 = ds;
char ** ____BAH_COMPILER_VAR_594 = (char **)((char*)(____BAH_COMPILER_VAR_592) + offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_595 = __reflect(____BAH_COMPILER_VAR_594, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
array(struct variable*)** ____BAH_COMPILER_VAR_596 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_592) + offsetof(struct debugStruct, membs));
struct variable** ____BAH_COMPILER_VAR_597 = 0;
char ** ____BAH_COMPILER_VAR_599 = (char **)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_600 = __reflect(____BAH_COMPILER_VAR_599, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_601 = (char **)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_602 = __reflect(____BAH_COMPILER_VAR_601, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_603 = (char*)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_604 = __reflect(____BAH_COMPILER_VAR_603, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_605 = (char **)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_606 = __reflect(____BAH_COMPILER_VAR_605, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_607 = (char*)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_608 = __reflect(____BAH_COMPILER_VAR_607, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_609 = (char **)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_610 = __reflect(____BAH_COMPILER_VAR_609, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_611 = (void **)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_612 = __reflect(____BAH_COMPILER_VAR_611, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_613 = (char*)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_614 = __reflect(____BAH_COMPILER_VAR_613, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_615 = (struct rope**)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_617 = (void **)((char*)(____BAH_COMPILER_VAR_615) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_618 = __reflect(____BAH_COMPILER_VAR_617, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_619 = (void **)((char*)(____BAH_COMPILER_VAR_615) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_620 = __reflect(____BAH_COMPILER_VAR_619, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_621 = (char **)((char*)(____BAH_COMPILER_VAR_615) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_622 = __reflect(____BAH_COMPILER_VAR_621, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_623 = (int*)((char*)(____BAH_COMPILER_VAR_615) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_624 = __reflect(____BAH_COMPILER_VAR_623, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_625 = (int*)((char*)(____BAH_COMPILER_VAR_615) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_626 = __reflect(____BAH_COMPILER_VAR_625, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_627 = (int*)((char*)(____BAH_COMPILER_VAR_615) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_628 = __reflect(____BAH_COMPILER_VAR_627, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_616 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_616->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_616->length = 6;
        ____BAH_COMPILER_VAR_616->data = memoryAlloc(____BAH_COMPILER_VAR_616->length * ____BAH_COMPILER_VAR_616->elemSize);
        ____BAH_COMPILER_VAR_616->data[0] = ____BAH_COMPILER_VAR_618;
____BAH_COMPILER_VAR_616->data[1] = ____BAH_COMPILER_VAR_620;
____BAH_COMPILER_VAR_616->data[2] = ____BAH_COMPILER_VAR_622;
____BAH_COMPILER_VAR_616->data[3] = ____BAH_COMPILER_VAR_624;
____BAH_COMPILER_VAR_616->data[4] = ____BAH_COMPILER_VAR_626;
____BAH_COMPILER_VAR_616->data[5] = ____BAH_COMPILER_VAR_628;
struct reflectElement ____BAH_COMPILER_VAR_629 = __reflect(____BAH_COMPILER_VAR_615, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_616, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_630 = (char*)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_631 = __reflect(____BAH_COMPILER_VAR_630, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_632 = (char*)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_633 = __reflect(____BAH_COMPILER_VAR_632, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_634 = (void **)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_635 = __reflect(____BAH_COMPILER_VAR_634, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_636 = (char*)((char*)(____BAH_COMPILER_VAR_597) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_637 = __reflect(____BAH_COMPILER_VAR_636, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_598 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_598->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_598->length = 13;
        ____BAH_COMPILER_VAR_598->data = memoryAlloc(____BAH_COMPILER_VAR_598->length * ____BAH_COMPILER_VAR_598->elemSize);
        ____BAH_COMPILER_VAR_598->data[0] = ____BAH_COMPILER_VAR_600;
____BAH_COMPILER_VAR_598->data[1] = ____BAH_COMPILER_VAR_602;
____BAH_COMPILER_VAR_598->data[2] = ____BAH_COMPILER_VAR_604;
____BAH_COMPILER_VAR_598->data[3] = ____BAH_COMPILER_VAR_606;
____BAH_COMPILER_VAR_598->data[4] = ____BAH_COMPILER_VAR_608;
____BAH_COMPILER_VAR_598->data[5] = ____BAH_COMPILER_VAR_610;
____BAH_COMPILER_VAR_598->data[6] = ____BAH_COMPILER_VAR_612;
____BAH_COMPILER_VAR_598->data[7] = ____BAH_COMPILER_VAR_614;
____BAH_COMPILER_VAR_598->data[8] = ____BAH_COMPILER_VAR_629;
____BAH_COMPILER_VAR_598->data[9] = ____BAH_COMPILER_VAR_631;
____BAH_COMPILER_VAR_598->data[10] = ____BAH_COMPILER_VAR_633;
____BAH_COMPILER_VAR_598->data[11] = ____BAH_COMPILER_VAR_635;
____BAH_COMPILER_VAR_598->data[12] = ____BAH_COMPILER_VAR_637;
struct reflectElement ____BAH_COMPILER_VAR_638 = __reflect(____BAH_COMPILER_VAR_597, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_598, 0);

        struct reflectElement ____BAH_COMPILER_VAR_639 = ____BAH_COMPILER_VAR_638;
        struct reflectElement ____BAH_COMPILER_VAR_640 = __reflect(____BAH_COMPILER_VAR_596, sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_639, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_593 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_593->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_593->length = 2;
        ____BAH_COMPILER_VAR_593->data = memoryAlloc(____BAH_COMPILER_VAR_593->length * ____BAH_COMPILER_VAR_593->elemSize);
        ____BAH_COMPILER_VAR_593->data[0] = ____BAH_COMPILER_VAR_595;
____BAH_COMPILER_VAR_593->data[1] = ____BAH_COMPILER_VAR_640;
struct reflectElement ____BAH_COMPILER_VAR_641 = __reflect(____BAH_COMPILER_VAR_592, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_593, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_641);
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
____BAH_COMPILER_VAR_642->isVar = false;
____BAH_COMPILER_VAR_642->used = false;
____BAH_COMPILER_VAR_642->code = null;
____BAH_COMPILER_VAR_642->isMut = false;
____BAH_COMPILER_VAR_642->isImported = false;
struct func* fn = ____BAH_COMPILER_VAR_642;
char * code = parseFnHeader("",l,&i,fn,elems);
array(struct func*)* fns = elems->fns;
fn->isBinding = true;

    {
        unsigned long nLength = len(fns);
        if (nLength >= fns->length) {
            if (nLength >= fns->realLength) {
                if (fns->realLength != 0) {
                    fns->realLength *= 2;
                } else {
                    fns->realLength = 50;
                }
                void * newPtr = memoryRealloc(fns->data, (fns->realLength)*sizeof(struct func*));
                fns->data = newPtr;
            }
            fns->data[len(fns)] = fn;
            fns->length = nLength+1;
        } else {
            fns->data[len(fns)] = fn;
        }
    }
    ;
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_643 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_643 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_643+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_643+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_643));
}
}
else {
char * tp = "";
++i;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_644 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tp);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_644 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_644+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_644+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_644;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType = getCType(tp,elems);
char * cTypeNewTypeStr = string__str(&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_645 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(cTypeNewTypeStr);
unsigned int strLen_4 = strlen("typedef ");
;                            
            ____BAH_COMPILER_VAR_645 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_645+currStrOff, "typedef ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_645+currStrOff, cTypeNewTypeStr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_645+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_645+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_645+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_645));
}
if ((debug==true)) {
struct debugType* ____BAH_COMPILER_VAR_646 = memoryAlloc(sizeof(struct debugType));
____BAH_COMPILER_VAR_646->name= null;
____BAH_COMPILER_VAR_646->refers= null;
struct debugType* dt = ____BAH_COMPILER_VAR_646;
dt->name = ft.cont;
dt->refers = tp;
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
array(char *)* tps = elems->types;

    {
        unsigned long nLength = len(tps);
        if (nLength >= tps->length) {
            if (nLength >= tps->realLength) {
                if (tps->realLength != 0) {
                    tps->realLength *= 2;
                } else {
                    tps->realLength = 50;
                }
                void * newPtr = memoryRealloc(tps->data, (tps->realLength)*sizeof(char *));
                tps->data = newPtr;
            }
            tps->data[len(tps)] = ft.cont;
            tps->length = nLength+1;
        } else {
            tps->data[len(tps)] = ft.cont;
        }
    }
    ;
}
};
void parseClib(__BAH_ARR_TYPE_Tok line){
array(char *)* clibs = compilerState.cLibs;
register long int i = 1;
while ((i<len(line))) {
struct Tok t = line->data[i];
if ((t.type!=TOKEN_TYPE_STR)) {
throwErr(&t,"Cannot use {TOKEN} as C library name.");
}
struct string cc = string(t.cont);
string__trimLeft(&cc,1);
string__trimRight(&cc,1);
char * ccstr = string__str(&cc);
char found = false;
register long int j = 0;
while ((j<len(clibs))) {
char * l = clibs->data[j];
if ((strcmp(l, ccstr) == 0)) {
found = true;
break;
}
j = j+1;
};
if ((found==true)) {
++i;
continue;
}

    {
        unsigned long nLength = len(clibs);
        if (nLength >= clibs->length) {
            if (nLength >= clibs->realLength) {
                if (clibs->realLength != 0) {
                    clibs->realLength *= 2;
                } else {
                    clibs->realLength = 50;
                }
                void * newPtr = memoryRealloc(clibs->data, (clibs->realLength)*sizeof(char *));
                clibs->data = newPtr;
            }
            clibs->data[len(clibs)] = ccstr;
            clibs->length = nLength+1;
        } else {
            clibs->data[len(clibs)] = ccstr;
        }
    }
    ;
++i;
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
struct variable* ____BAH_COMPILER_VAR_654 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_654->name = "";
____BAH_COMPILER_VAR_654->type = "";
____BAH_COMPILER_VAR_654->isConst = false;
____BAH_COMPILER_VAR_654->constVal = "";
____BAH_COMPILER_VAR_654->isArray = false;
____BAH_COMPILER_VAR_654->from = "";
____BAH_COMPILER_VAR_654->declScope= null;
____BAH_COMPILER_VAR_654->isGlobal = false;
____BAH_COMPILER_VAR_654->declRope= null;
____BAH_COMPILER_VAR_654->isReg = false;
____BAH_COMPILER_VAR_654->lastSet= null;
____BAH_COMPILER_VAR_654->isArg = false;
struct variable* v = ____BAH_COMPILER_VAR_654;
if (isGlobal()) {
v->isGlobal = true;
}
v->isConst = true;
v->constVal = valt.cont;
v->name = vart.cont;
v->type = getTypeFromToken(&valt,true,elems);
array(struct variable*)* vars = elems->vars;

    {
        unsigned long nLength = len(vars);
        if (nLength >= vars->length) {
            if (nLength >= vars->realLength) {
                if (vars->realLength != 0) {
                    vars->realLength *= 2;
                } else {
                    vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(vars->data, (vars->realLength)*sizeof(struct variable*));
                vars->data = newPtr;
            }
            vars->data[len(vars)] = v;
            vars->length = nLength+1;
        } else {
            vars->data[len(vars)] = v;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_655 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(valt.cont);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_655 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_655+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_655+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_655+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_655+currStrOff, valt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_655+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_655));
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
char * ____BAH_COMPILER_VAR_656 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentFn->returns->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Cannot return nothing as ");
;                            
            ____BAH_COMPILER_VAR_656 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_656+currStrOff, "Cannot return nothing as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_656+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_656+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_656);
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
char * ____BAH_COMPILER_VAR_657 =null;char * ____BAH_COMPILER_VAR_658 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rvt.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("=");
unsigned int strLen_3 = strlen(rv);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_658);
;                            
            ____BAH_COMPILER_VAR_657 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_657+currStrOff, ____BAH_COMPILER_VAR_658, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_657+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_657+currStrOff, rv, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_657+currStrOff, "=", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_657+currStrOff, rvt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_657+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_657));
}
if ((compTypes(tt,currentFn->returns->type)==false)) {
char * ____BAH_COMPILER_VAR_659 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentFn->returns->type);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot return {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_659 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, "Cannot return {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_659+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_659+currStrOff, currentFn->returns->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_659+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&rvt,____BAH_COMPILER_VAR_659);
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
char * ____BAH_COMPILER_VAR_660 =null;char * ____BAH_COMPILER_VAR_661 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rv);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(rvar);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_661);
;                            
            ____BAH_COMPILER_VAR_660 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_660+currStrOff, ____BAH_COMPILER_VAR_661, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_660+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_660+currStrOff, rvar, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_660+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_660+currStrOff, rv, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_660+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_660));
if ((tmpV!=null)&&(tmpV->declScope!=elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(tmpV,elems));
}
}
if (strHasPrefix(tt,"buffer:")) {
char * ____BAH_COMPILER_VAR_662 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rvar);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("__STR(");
;                            
            ____BAH_COMPILER_VAR_662 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_662+currStrOff, "__STR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_662+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_662+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }rvar = ____BAH_COMPILER_VAR_662;
}
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); ++j) {

    {
        unsigned long nLength = j;
        if (nLength >= excl->length) {
            if (nLength >= excl->realLength) {
                if (excl->realLength != 0) {
                    excl->realLength *= 2;
                } else {
                    excl->realLength = 50;
                }
                void * newPtr = memoryRealloc(excl->data, (excl->realLength)*sizeof(struct variable*));
                excl->data = newPtr;
            }
            excl->data[j] = currentFn->args->data[j];
            excl->length = nLength+1;
        } else {
            excl->data[j] = currentFn->args->data[j];
        }
    }
    ;
};
if ((tmpV!=null)) {

    {
        unsigned long nLength = len(excl);
        if (nLength >= excl->length) {
            if (nLength >= excl->realLength) {
                if (excl->realLength != 0) {
                    excl->realLength *= 2;
                } else {
                    excl->realLength = 50;
                }
                void * newPtr = memoryRealloc(excl->data, (excl->realLength)*sizeof(struct variable*));
                excl->data = newPtr;
            }
            excl->data[len(excl)] = tmpV;
            excl->length = nLength+1;
        } else {
            excl->data[len(excl)] = tmpV;
        }
    }
    ;
}
endRCPscope(elems,excl);
}
char * ____BAH_COMPILER_VAR_663 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(rvar);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("return ");
;                            
            ____BAH_COMPILER_VAR_663 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_663+currStrOff, "return ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_663+currStrOff, rvar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_663+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_663));
}
else {
if (RCPavailable()) {
array(struct variable*)* excl = memoryAlloc(sizeof(array(struct variable*)));

excl->length = 0;
excl->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(currentFn->args)); ++j) {

    {
        unsigned long nLength = j;
        if (nLength >= excl->length) {
            if (nLength >= excl->realLength) {
                if (excl->realLength != 0) {
                    excl->realLength *= 2;
                } else {
                    excl->realLength = 50;
                }
                void * newPtr = memoryRealloc(excl->data, (excl->realLength)*sizeof(struct variable*));
                excl->data = newPtr;
            }
            excl->data[j] = currentFn->args->data[j];
            excl->length = nLength+1;
        } else {
            excl->data[j] = currentFn->args->data[j];
        }
    }
    ;
};
if ((tmpV!=null)) {

    {
        unsigned long nLength = len(excl);
        if (nLength >= excl->length) {
            if (nLength >= excl->realLength) {
                if (excl->realLength != 0) {
                    excl->realLength *= 2;
                } else {
                    excl->realLength = 50;
                }
                void * newPtr = memoryRealloc(excl->data, (excl->realLength)*sizeof(struct variable*));
                excl->data = newPtr;
            }
            excl->data[len(excl)] = tmpV;
            excl->length = nLength+1;
        } else {
            excl->data[len(excl)] = tmpV;
        }
    }
    ;
}
endRCPscope(elems,excl);
}
OUTPUT = rope__add(OUTPUT, rope("return;\n"));
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
register long int i = 3;
while ((i<max)) {
t = l->data[i];

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = t;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = t;
        }
    }
    ;
++i;
};
char * ____BAH_COMPILER_VAR_664 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(condt.cont);
unsigned int strLen_1 = strlen(") {\n");
unsigned int strLen_2 = strlen("if (");
;                            
            ____BAH_COMPILER_VAR_664 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_664+currStrOff, "if (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_664+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_664+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_664));
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
OUTPUT = rope__add(OUTPUT, rope("}\n"));
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
OUTPUT = rope__add(OUTPUT, rope("else "));
if ((strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
register long int i = 1;
while ((i<len(l))) {

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = l->data[i];
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = l->data[i];
        }
    }
    ;
++i;
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
register long int i = 2;
while ((i<max)) {

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = l->data[i];
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = l->data[i];
        }
    }
    ;
++i;
};
OUTPUT = rope__add(OUTPUT, rope("{\n"));
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
OUTPUT = rope__add(OUTPUT, rope("}\n"));
}
};
void parseLine(__BAH_ARR_TYPE_Tok l,struct Elems* elems);
void parseFor(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}.");
}
long int nbComas = 0;
register long int i = 1;
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
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_ENCL)&&(strcmp(t.cont, "{") == 0)) {
break;
}

    {
        unsigned long nLength = len(inst);
        if (nLength >= inst->length) {
            if (nLength >= inst->realLength) {
                if (inst->realLength != 0) {
                    inst->realLength *= 2;
                } else {
                    inst->realLength = 50;
                }
                void * newPtr = memoryRealloc(inst->data, (inst->realLength)*sizeof(struct Tok));
                inst->data = newPtr;
            }
            inst->data[len(inst)] = t;
            inst->length = nLength+1;
        } else {
            inst->data[len(inst)] = t;
        }
    }
    ;
};
struct rope* oldOut = OUTPUT;
OUTPUT = rope("");
parseLine(inst,elems);
char * ____BAH_COMPILER_VAR_665 =rope__toStr(OUTPUT);struct string instC = string(____BAH_COMPILER_VAR_665);
OUTPUT = oldOut;
string__trimRight(&instC,2);
struct Tok t = l->data[i];
if ((strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}
long int max = len(l)-1;
i = i+1;
for (; (i<max); ++i) {
t = l->data[i];

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = t;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = t;
        }
    }
    ;
};
char * ____BAH_COMPILER_VAR_666 =null;char * ____BAH_COMPILER_VAR_667 =string__str(&instC);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_667);
unsigned int strLen_1 = strlen(") {\n");
unsigned int strLen_2 = strlen("; ");
unsigned int strLen_3 = strlen(condt.cont);
unsigned int strLen_4 = strlen("for (; ");
;                            
            ____BAH_COMPILER_VAR_666 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, "for (; ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, condt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_666+currStrOff, "; ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_666+currStrOff, ____BAH_COMPILER_VAR_667, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_666+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_666));
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
for (; (i<max); ++i) {
t = l->data[i];

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = t;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = t;
        }
    }
    ;
};
char * ____BAH_COMPILER_VAR_668 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(condt.cont);
unsigned int strLen_1 = strlen(") {\n");
unsigned int strLen_2 = strlen("while (");
;                            
            ____BAH_COMPILER_VAR_668 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_668+currStrOff, "while (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_668+currStrOff, condt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_668+currStrOff, ") {\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_668));
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
OUTPUT = rope__add(OUTPUT, rope("};\n"));
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
char * ____BAH_COMPILER_VAR_669 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_669 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_669+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_669+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_669));
};
void makeEvalFunc(struct func* fn,struct Elems* elems){

        char ____BAH_COMPILER_VAR_670 = 0;
        for(int i=compilerState.evals->length-1; i!=-1;i--) {
            if (compilerState.evals->data[i] != 0 && strcmp(compilerState.evals->data[i], fn->name) == 0) {
                ____BAH_COMPILER_VAR_670=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_670) {
return;
}
char * ____BAH_COMPILER_VAR_671 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__Bah_eval_");
unsigned int strLen_1 = strlen(fn->name);
;                            
            ____BAH_COMPILER_VAR_671 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_671+currStrOff, "__Bah_eval_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_671+currStrOff, fn->name, strLen_1);
            currStrOff += strLen_1;
        
        }struct func* ____BAH_COMPILER_VAR_672 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_672->name = "";
____BAH_COMPILER_VAR_672->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_672->args->length = 0;
            ____BAH_COMPILER_VAR_672->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_672->returns= null;
____BAH_COMPILER_VAR_672->isBinding = false;
____BAH_COMPILER_VAR_672->from = "";
____BAH_COMPILER_VAR_672->file = "";
____BAH_COMPILER_VAR_672->line = 1;
____BAH_COMPILER_VAR_672->isVar = false;
____BAH_COMPILER_VAR_672->used = false;
____BAH_COMPILER_VAR_672->code = null;
____BAH_COMPILER_VAR_672->isMut = false;
____BAH_COMPILER_VAR_672->isImported = false;
____BAH_COMPILER_VAR_672->name = ____BAH_COMPILER_VAR_671;
struct func* efn = ____BAH_COMPILER_VAR_672;
struct variable* ____BAH_COMPILER_VAR_673 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_673->name = "";
____BAH_COMPILER_VAR_673->type = "";
____BAH_COMPILER_VAR_673->isConst = false;
____BAH_COMPILER_VAR_673->constVal = "";
____BAH_COMPILER_VAR_673->isArray = false;
____BAH_COMPILER_VAR_673->from = "";
____BAH_COMPILER_VAR_673->declScope= null;
____BAH_COMPILER_VAR_673->isGlobal = false;
____BAH_COMPILER_VAR_673->declRope= null;
____BAH_COMPILER_VAR_673->isReg = false;
____BAH_COMPILER_VAR_673->lastSet= null;
____BAH_COMPILER_VAR_673->isArg = false;
____BAH_COMPILER_VAR_673->type = "ptr";
efn->returns = ____BAH_COMPILER_VAR_673;
struct variable* ____BAH_COMPILER_VAR_674 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_674->name = "";
____BAH_COMPILER_VAR_674->type = "";
____BAH_COMPILER_VAR_674->isConst = false;
____BAH_COMPILER_VAR_674->constVal = "";
____BAH_COMPILER_VAR_674->isArray = false;
____BAH_COMPILER_VAR_674->from = "";
____BAH_COMPILER_VAR_674->declScope= null;
____BAH_COMPILER_VAR_674->isGlobal = false;
____BAH_COMPILER_VAR_674->declRope= null;
____BAH_COMPILER_VAR_674->isReg = false;
____BAH_COMPILER_VAR_674->lastSet= null;
____BAH_COMPILER_VAR_674->isArg = false;
____BAH_COMPILER_VAR_674->name = "fnArgs";
____BAH_COMPILER_VAR_674->type = "[]ptr";
efn->args = memoryAlloc(sizeof(array(struct variable*)));

efn->args->length = 1;
efn->args->elemSize = sizeof(struct variable*);
efn->args->data = memoryAlloc(sizeof(struct variable*) * 50);
                    efn->args->realLength = 50;
efn->args->data[0] = ____BAH_COMPILER_VAR_674;
char * fnBinding = "";
char * ____BAH_COMPILER_VAR_675 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_675 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_675+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_675+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }char * fnCall = ____BAH_COMPILER_VAR_675;
register long int i = 0;
for (; (i<len(fn->args)); ++i) {
struct variable* a = fn->args->data[i];
char * v = genCompilerVar();
struct string cType = getCType(a->type,elems);
if ((isRCPpointerType(a->type)==false)) {
string__append(&cType,"*");
}
char * ____BAH_COMPILER_VAR_676 =null;char * ____BAH_COMPILER_VAR_677 =intToStr(i);char * ____BAH_COMPILER_VAR_678 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_677);
unsigned int strLen_1 = strlen("];");
unsigned int strLen_2 = strlen(" = fnArgs->data[");
unsigned int strLen_3 = strlen(v);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_678);
;                            
            ____BAH_COMPILER_VAR_676 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_676+currStrOff, ____BAH_COMPILER_VAR_678, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_676+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_676+currStrOff, v, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_676+currStrOff, " = fnArgs->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_676+currStrOff, ____BAH_COMPILER_VAR_677, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_676+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_679 =null;char * ____BAH_COMPILER_VAR_680 =____BAH_COMPILER_VAR_676;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnBinding);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_680);
;                            
            ____BAH_COMPILER_VAR_679 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_679+currStrOff, fnBinding, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_679+currStrOff, ____BAH_COMPILER_VAR_680, strLen_1);
            currStrOff += strLen_1;
        
        }fnBinding = ____BAH_COMPILER_VAR_679;
if ((i!=0)) {
char * ____BAH_COMPILER_VAR_681 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_681 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_681+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_681+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_681;
}
if (isRCPpointerType(a->type)) {
char * ____BAH_COMPILER_VAR_682 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_682 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_682+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_682+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_682;
}
else {
char * ____BAH_COMPILER_VAR_683 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("*");
unsigned int strLen_1 = strlen(v);
;                            
            ____BAH_COMPILER_VAR_683 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_683+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_683+currStrOff, v, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_684 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_683);
;                            
            ____BAH_COMPILER_VAR_684 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_684+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_684+currStrOff, ____BAH_COMPILER_VAR_683, strLen_1);
            currStrOff += strLen_1;
        
        }fnCall = ____BAH_COMPILER_VAR_684;
}
};
char * setReturnValue = "void* r = 0;";
if (isRCPpointerType(fn->returns->type)) {
setReturnValue = "void* r = ";
}
else {
struct string cType = getCType(fn->returns->type,elems);
if ((strcmp(string__str(&cType), "void") != 0)) {
char * ____BAH_COMPILER_VAR_685 =null;char * ____BAH_COMPILER_VAR_686 =string__str(&cType);char * ____BAH_COMPILER_VAR_687 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_686);
unsigned int strLen_1 = strlen("));*r = ");
unsigned int strLen_2 = strlen("* r = memoryAlloc(sizeof(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_687);
;                            
            ____BAH_COMPILER_VAR_685 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_685+currStrOff, ____BAH_COMPILER_VAR_687, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_685+currStrOff, "* r = memoryAlloc(sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_685+currStrOff, ____BAH_COMPILER_VAR_686, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_685+currStrOff, "));*r = ", strLen_1);
            currStrOff += strLen_1;
        
        }setReturnValue = ____BAH_COMPILER_VAR_685;
}
}
char * ____BAH_COMPILER_VAR_688 =null;char * ____BAH_COMPILER_VAR_689 =intToStr(len(fn->args));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnCall);
unsigned int strLen_1 = strlen(");\n        return (void*)r;\n    };");
unsigned int strLen_2 = strlen(setReturnValue);
unsigned int strLen_3 = strlen("\n        ");
unsigned int strLen_4 = strlen(fnBinding);
unsigned int strLen_5 = strlen("() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ");
unsigned int strLen_6 = strlen(fn->name);
unsigned int strLen_7 = strlen(") {\n            __BAH_panic((char*)\"eval: calling function ");
unsigned int strLen_8 = strlen(____BAH_COMPILER_VAR_689);
unsigned int strLen_9 = strlen("(array(void*)* fnArgs) {\n        if (fnArgs->length != ");
unsigned int strLen_10 = strlen(efn->name);
unsigned int strLen_11 = strlen("void* __attribute__((optimize(\"O0\"))) ");
;                            
            ____BAH_COMPILER_VAR_688 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11);
            
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, "void* __attribute__((optimize(\"O0\"))) ", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, efn->name, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, "(array(void*)* fnArgs) {\n        if (fnArgs->length != ", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, ____BAH_COMPILER_VAR_689, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, ") {\n            __BAH_panic((char*)\"eval: calling function ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, fn->name, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, "() with the wrong number of arguments.\", \"BAH_COMPILER_INTERNAL\");\n        }\n        ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, fnBinding, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, "\n        ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_688+currStrOff, setReturnValue, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_688+currStrOff, fnCall, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_688+currStrOff, ");\n        return (void*)r;\n    };", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_688));

    {
        unsigned long nLength = len(compilerState.evals);
        if (nLength >= compilerState.evals->length) {
            if (nLength >= compilerState.evals->realLength) {
                if (compilerState.evals->realLength != 0) {
                    compilerState.evals->realLength *= 2;
                } else {
                    compilerState.evals->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.evals->data, (compilerState.evals->realLength)*sizeof(char *));
                compilerState.evals->data = newPtr;
            }
            compilerState.evals->data[len(compilerState.evals)] = fn->name;
            compilerState.evals->length = nLength+1;
        } else {
            compilerState.evals->data[len(compilerState.evals)] = fn->name;
        }
    }
    ;

    {
        unsigned long nLength = len(elems->fns);
        if (nLength >= elems->fns->length) {
            if (nLength >= elems->fns->realLength) {
                if (elems->fns->realLength != 0) {
                    elems->fns->realLength *= 2;
                } else {
                    elems->fns->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->fns->data, (elems->fns->realLength)*sizeof(struct func*));
                elems->fns->data = newPtr;
            }
            elems->fns->data[len(elems->fns)] = efn;
            elems->fns->length = nLength+1;
        } else {
            elems->fns->data[len(elems->fns)] = efn;
        }
    }
    ;
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
string__trimLeft(&msg,1);
string__trimRight(&msg,1);
char * ____BAH_COMPILER_VAR_690 =string__str(&msg);throwWarning(____BAH_COMPILER_VAR_690);
return;
}
if ((strcmp(ft.cont, "#eval") == 0)) {

        char ____BAH_COMPILER_VAR_691 = 0;
        for(int i=compilerState.includes->length-1; i!=-1;i--) {
            if (compilerState.includes->data[i] != 0 && strcmp(compilerState.includes->data[i], "eval.bah") == 0) {
                ____BAH_COMPILER_VAR_691=1;
                break;
            };
        }
        if ((____BAH_COMPILER_VAR_691==false)) {
if ((includeFile("eval.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_692 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("Could not find file 'eval.bah'. Check your bah directory (");
;                            
            ____BAH_COMPILER_VAR_692 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_692+currStrOff, "Could not find file 'eval.bah'. Check your bah directory (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_692+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_692+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[0],____BAH_COMPILER_VAR_692);
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
register long int i = 0;
for (; (i<len(elems->fns)); ++i) {
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
string__trimLeft(&isOS,1);
if ((strcmp(string__str(&isOS), BAH_OS) != 0)) {
return;
}
}
else if ((strcmp(ft.cont, "#static") == 0)) {
if ((flags__isSet(&flags,"d")==1)) {
return;
}
}
else if ((strcmp(ft.cont, "#dynamic") == 0)) {
if ((flags__isSet(&flags,"d")==0)) {
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
if ((flags__isSet(&flags,"l")==0)) {
return;
}
}
else if ((strcmp(ft.cont, "#exec") == 0)) {
if ((flags__isSet(&flags,"l")==1)) {
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
else if ((strcmp(ft.cont, "#optimized") == 0)) {
if ((isOptimized==false)) {
return;
}
}
else if ((strcmp(ft.cont, "#unoptimized") == 0)) {
if ((isOptimized==true)) {
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
register long int i = 2;
while ((i<len(l)-1)) {

    {
        unsigned long nLength = i-2;
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[i-2] = l->data[i];
            nl->length = nLength+1;
        } else {
            nl->data[i-2] = l->data[i];
        }
    }
    ;
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
register long int i = 0;
while ((i<len(compilerState.cLibs))) {
if ((strcmp(compilerState.cLibs->data[i], "lpthread") == 0)) {
found = true;
break;
}
i = i+1;
};
if ((found==false)) {

    {
        unsigned long nLength = len(compilerState.cLibs);
        if (nLength >= compilerState.cLibs->length) {
            if (nLength >= compilerState.cLibs->realLength) {
                if (compilerState.cLibs->realLength != 0) {
                    compilerState.cLibs->realLength *= 2;
                } else {
                    compilerState.cLibs->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.cLibs->data, (compilerState.cLibs->realLength)*sizeof(char *));
                compilerState.cLibs->data = newPtr;
            }
            compilerState.cLibs->data[len(compilerState.cLibs)] = "lpthread";
            compilerState.cLibs->length = nLength+1;
        } else {
            compilerState.cLibs->data[len(compilerState.cLibs)] = "lpthread";
        }
    }
    ;
}
struct string sFnT = string(fnT.cont);
array(struct string)* fnNameParts = splitString(sFnT,"(");
struct string fnName = fnNameParts->data[0];
struct func* fn = searchFuncByToken(&fnT,elems);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_693 =null;char * ____BAH_COMPILER_VAR_694 =string__str(&fnName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_694);
unsigned int strLen_1 = strlen("', arround {TOKEN}.");
unsigned int strLen_2 = strlen("Internal compiler error.\n Error parsing async call for function '");
;                            
            ____BAH_COMPILER_VAR_693 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_693+currStrOff, "Internal compiler error.\n Error parsing async call for function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_693+currStrOff, ____BAH_COMPILER_VAR_694, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_693+currStrOff, "', arround {TOKEN}.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&fnT,____BAH_COMPILER_VAR_693);
}
fnName = string(fn->name);
char * sMembs = "";
char * unSerMembs = "";
i = 0;
while ((i<len(fn->args))) {
struct variable* a = fn->args->data[i];
struct string cType = getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_695 =null;char * ____BAH_COMPILER_VAR_696 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(a->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_696);
unsigned int strLen_4 = strlen(sMembs);
;                            
            ____BAH_COMPILER_VAR_695 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, sMembs, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, ____BAH_COMPILER_VAR_696, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_695+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_695+currStrOff, a->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_695+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }sMembs = ____BAH_COMPILER_VAR_695;
char * ____BAH_COMPILER_VAR_697 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("args->");
unsigned int strLen_1 = strlen(a->name);
unsigned int strLen_2 = strlen(unSerMembs);
;                            
            ____BAH_COMPILER_VAR_697 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_697+currStrOff, unSerMembs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_697+currStrOff, "args->", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_697+currStrOff, a->name, strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_697;
i = i+1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_698 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(unSerMembs);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_698 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_698+currStrOff, unSerMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_698+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }unSerMembs = ____BAH_COMPILER_VAR_698;
}
};
char * ____BAH_COMPILER_VAR_699 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sMembs);
unsigned int strLen_1 = strlen("}");
unsigned int strLen_2 = strlen("struct {\n");
;                            
            ____BAH_COMPILER_VAR_699 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_699+currStrOff, "struct {\n", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_699+currStrOff, sMembs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_699+currStrOff, "}", strLen_1);
            currStrOff += strLen_1;
        
        }char * tmpArgsStruct = ____BAH_COMPILER_VAR_699;
char * fnWrapper = genCompilerVar();
char * tmpArgs = genCompilerVar();
string__trimLeft(&sFnT,fnName.length+1);
string__trimRight(&sFnT,1);
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
char * ____BAH_COMPILER_VAR_700 =null;char * ____BAH_COMPILER_VAR_701 =string__str(&sFnT);char * ____BAH_COMPILER_VAR_702 =string__str(&fnName);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpArgs);
unsigned int strLen_1 = strlen(");\n    }; \n    \n    ");
unsigned int strLen_2 = strlen(", &");
unsigned int strLen_3 = strlen(fnWrapper);
unsigned int strLen_4 = strlen("(&id, 0, ");
unsigned int strLen_5 = strlen(tCreate);
unsigned int strLen_6 = strlen("};\n        pthread_t id;\n        ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_701);
unsigned int strLen_8 = strlen(" = {");
unsigned int strLen_9 = strlen(tmpArgs);
unsigned int strLen_10 = strlen(" ");
unsigned int strLen_11 = strlen(tmpArgsStruct);
unsigned int strLen_12 = strlen(");\n    };\n    {\n        ");
unsigned int strLen_13 = strlen(unSerMembs);
unsigned int strLen_14 = strlen("(");
unsigned int strLen_15 = strlen(____BAH_COMPILER_VAR_702);
unsigned int strLen_16 = strlen("* args) {\n        ");
unsigned int strLen_17 = strlen(tmpArgsStruct);
unsigned int strLen_18 = strlen("(");
unsigned int strLen_19 = strlen(fnWrapper);
unsigned int strLen_20 = strlen("\n    void ");
;                            
            ____BAH_COMPILER_VAR_700 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16+strLen_17+strLen_18+strLen_19+strLen_20);
            
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, "\n    void ", strLen_20);
                    currStrOff += strLen_20;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, fnWrapper, strLen_19);
                    currStrOff += strLen_19;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, "(", strLen_18);
                    currStrOff += strLen_18;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, tmpArgsStruct, strLen_17);
                    currStrOff += strLen_17;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, "* args) {\n        ", strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, ____BAH_COMPILER_VAR_702, strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, "(", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, unSerMembs, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, ");\n    };\n    {\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, tmpArgsStruct, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, tmpArgs, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, " = {", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, ____BAH_COMPILER_VAR_701, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, "};\n        pthread_t id;\n        ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, tCreate, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, "(&id, 0, ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, fnWrapper, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_700+currStrOff, ", &", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_700+currStrOff, tmpArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_700+currStrOff, ");\n    }; \n    \n    ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_700));
};
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
register long int i = 0;
if ((ltp==LINE_TYPE_VAR)) {
i = 1;
}
while ((i<len(l))) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)) {
struct variable* v = searchVirtVarByToken(&t,elems);
if ((v!=null)) {

    {
        unsigned long nLength = len(compilerState.RCPvars);
        if (nLength >= compilerState.RCPvars->length) {
            if (nLength >= compilerState.RCPvars->realLength) {
                if (compilerState.RCPvars->realLength != 0) {
                    compilerState.RCPvars->realLength *= 2;
                } else {
                    compilerState.RCPvars->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.RCPvars->data, (compilerState.RCPvars->realLength)*sizeof(struct variable*));
                compilerState.RCPvars->data = newPtr;
            }
            compilerState.RCPvars->data[len(compilerState.RCPvars)] = v;
            compilerState.RCPvars->length = nLength+1;
        } else {
            compilerState.RCPvars->data[len(compilerState.RCPvars)] = v;
        }
    }
    ;
}
}
i = i+1;
};
};
__BAH_ARR_TYPE_Tok parseChan(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
register long int i = 0;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)&&(strcmp(t.cont, "->") == 0)||(strcmp(t.cont, "<-") == 0)) {
if ((strcmp(t.cont, "<-") == 0)) {
++i;
if ((i<len(l))) {
struct Tok nt = l->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_703 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_703);
if ((string__hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_704 =null;char * ____BAH_COMPILER_VAR_705 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_705);
unsigned int strLen_1 = strlen(") as channel.");
unsigned int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_704 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_704+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_704+currStrOff, ____BAH_COMPILER_VAR_705, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_704+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_704);
}
string__trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * tmpV = "";
char * ____BAH_COMPILER_VAR_706 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_706)) {
char * ____BAH_COMPILER_VAR_707 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_707,elems);
char * ____BAH_COMPILER_VAR_708 =null;char * ____BAH_COMPILER_VAR_709 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->receive(");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen(")");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_709);
unsigned int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_708 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, ____BAH_COMPILER_VAR_709, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, ")", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_708+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_708+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_708+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_708;
}
else {
char * ____BAH_COMPILER_VAR_710 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_710,elems);
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_711 =null;char * ____BAH_COMPILER_VAR_712 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_712);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_711 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_711+currStrOff, ____BAH_COMPILER_VAR_712, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_711+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_713 =null;char * ____BAH_COMPILER_VAR_714 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->receive(");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen("*)");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_714);
unsigned int strLen_6 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_713 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, ____BAH_COMPILER_VAR_714, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_713+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_713+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_713+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }tmpV = registerRCPvar(____BAH_COMPILER_VAR_711,____BAH_COMPILER_VAR_713,elems);
char * ____BAH_COMPILER_VAR_715 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("*");
unsigned int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_715 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_715+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_715+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_715;
}
else {
char * ____BAH_COMPILER_VAR_716 =null;char * ____BAH_COMPILER_VAR_717 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("->receive(");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen("*)");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_717);
unsigned int strLen_6 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_716 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_716+currStrOff, "*(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_716+currStrOff, ____BAH_COMPILER_VAR_717, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_716+currStrOff, "*)", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_716+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_716+currStrOff, "->receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_716+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_716+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_716;
}
}
t.type = TOKEN_TYPE_FUNC;
t.isFunc = true;
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_718 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_718)) {
char * ____BAH_COMPILER_VAR_719 =string__str(&ntt);tmpV = registerRCPvar(____BAH_COMPILER_VAR_719,t.cont,elems);
t.type = TOKEN_TYPE_VAR;
t.isFunc = false;
t.cont = tmpV;
}
else {
}
}
t.isValue = true;
t.bahType = string__str(&ntt);
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
char * ____BAH_COMPILER_VAR_720 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_720);
if ((string__hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_721 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ntt);
unsigned int strLen_1 = strlen(") as channel.");
unsigned int strLen_2 = strlen("Cannot use var {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_721 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_721+currStrOff, "Cannot use var {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_721+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_721+currStrOff, ") as channel.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_721);
}
string__trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_722 =string__str(&ptt);if ((compTypes(____BAH_COMPILER_VAR_722,ntt)==false)) {
char * ____BAH_COMPILER_VAR_723 =null;char * ____BAH_COMPILER_VAR_724 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_724);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") to channel of type ");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_723+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_723+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_723+currStrOff, ") to channel of type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_723+currStrOff, ____BAH_COMPILER_VAR_724, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_723+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_723);
}
++i;
char * ____BAH_COMPILER_VAR_725 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_725)) {
char * ____BAH_COMPILER_VAR_726 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("->send(");
unsigned int strLen_5 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_726 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_726+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_726+currStrOff, "->send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_726+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_726+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_726+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_726+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_726));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_727 =null;char * ____BAH_COMPILER_VAR_728 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV);
unsigned int strLen_1 = strlen("));\n");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(tmpV);
unsigned int strLen_4 = strlen(", &");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen("->sendAny(");
unsigned int strLen_7 = strlen(pt.cont);
unsigned int strLen_8 = strlen(";\n                    ");
unsigned int strLen_9 = strlen(nt.cont);
unsigned int strLen_10 = strlen(" = ");
unsigned int strLen_11 = strlen(tmpV);
unsigned int strLen_12 = strlen(" ");
unsigned int strLen_13 = strlen(____BAH_COMPILER_VAR_728);
unsigned int strLen_14 = strlen("\n                    ");
;                            
            ____BAH_COMPILER_VAR_727 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, "\n                    ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, ____BAH_COMPILER_VAR_728, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, " ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, tmpV, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, " = ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, nt.cont, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, ";\n                    ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, "->sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_727+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_727+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_727+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_727));
}
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
return nl;
}
}

    {
        unsigned long nLength = len(nl);
        if (nLength >= nl->length) {
            if (nLength >= nl->realLength) {
                if (nl->realLength != 0) {
                    nl->realLength *= 2;
                } else {
                    nl->realLength = 50;
                }
                void * newPtr = memoryRealloc(nl->data, (nl->realLength)*sizeof(struct Tok));
                nl->data = newPtr;
            }
            nl->data[len(nl)] = t;
            nl->length = nLength+1;
        } else {
            nl->data[len(nl)] = t;
        }
    }
    ;
};
return nl;
};
long int valueFunc(struct func* fn,struct variable* parent,__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i;
long int errPos = -1;
if ((fn==null)) {
if ((i>0)) {
tokPos = i-1;
struct Tok pt = l->data[tokPos];
if ((pt.type==TOKEN_TYPE_VAR)) {
delete(l,tokPos);
errPos = pt.pos;
fn = searchFunc(pt.cont,elems,true);
if ((fn==null)) {
throwErr(&pt,"Unknown func {TOKEN}.");
}
}
else {
++tokPos;
}
}
else {
return i;
}
}
struct Tok fnt = l->data[tokPos];
if ((errPos!=-1)) {
fnt.pos = errPos;
}
if ((fn==null)) {
long int nbEncls = 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i = tokPos+1;
fnt.ogCont = "(";
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_729 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.ogCont);
unsigned int strLen_1 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_729 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_729+currStrOff, fnt.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_729+currStrOff, t.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_729;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
--nbEncls;
if ((nbEncls==0)) {
break;
}
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = t;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = t;
        }
    }
    ;
};
deleteRange(l,tokPos+1,i);
array(struct Tok)* memort = prePross(memory,(lineType)-1,elems);
struct Tok ft = memory->data[0];
fnt.cont = "(";
fnt.isOper = true;
fnt.isValue = true;
fnt.bahType = getTypeFromToken(&ft,true,elems);
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok t = memory->data[j];
char * ____BAH_COMPILER_VAR_730 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_730 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_730+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_730+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_730;
};
char * ____BAH_COMPILER_VAR_731 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_731 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_731+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_731+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_731;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = fnt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = fnt;
        }
    }
    ;
return tokPos;
}
char * ____BAH_COMPILER_VAR_732 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_732 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_732+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_732+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_732;
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
char * ____BAH_COMPILER_VAR_733 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_733 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_733+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_733+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_733;
for (; (i<len(l)); ++i) {
struct Tok t = l->data[i];
char * ____BAH_COMPILER_VAR_734 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.ogCont);
unsigned int strLen_1 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_734 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_734+currStrOff, fnt.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_734+currStrOff, t.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_734;
if ((strcmp(t.cont, "(") == 0)||(strcmp(t.cont, "{") == 0)||(strcmp(t.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(t.cont, ")") == 0)||(strcmp(t.cont, "}") == 0)||(strcmp(t.cont, "]") == 0)) {
--nbEncls;
if ((nbEncls==0)) {
break;
}
}

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = t;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = t;
        }
    }
    ;
};
deleteRange(l,tokPos+1,i);
if ((strcmp(fn->name, "noCheck") == 0)) {
fnt.cont = "";
fnt.isOper = true;
fnt.isValue = true;
fnt.bahType = "ptr";
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok t = memory->data[j];
char * ____BAH_COMPILER_VAR_735 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_735 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_735+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_735+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_735;
};

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = fnt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = fnt;
        }
    }
    ;
return tokPos;
}
char * ____BAH_COMPILER_VAR_736 =null;char * ____BAH_COMPILER_VAR_737 =intToStr(fnt.line);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_737);
unsigned int strLen_1 = strlen("\"");
unsigned int strLen_2 = strlen(":");
unsigned int strLen_3 = strlen(compilerState.currentFile);
unsigned int strLen_4 = strlen("\"");
;                            
            ____BAH_COMPILER_VAR_736 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, "\"", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, compilerState.currentFile, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_736+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_736+currStrOff, ____BAH_COMPILER_VAR_737, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_736+currStrOff, "\"", strLen_1);
            currStrOff += strLen_1;
        
        }char * currLine = ____BAH_COMPILER_VAR_736;
if ((strcmp(fn->name, "panic") == 0)) {
struct Tok ____BAH_COMPILER_VAR_738 = {};
____BAH_COMPILER_VAR_738.cont = "";
____BAH_COMPILER_VAR_738.ogCont = "";
____BAH_COMPILER_VAR_738.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_738.pos = 0;
____BAH_COMPILER_VAR_738.line = 1;
____BAH_COMPILER_VAR_738.begLine = 1;
____BAH_COMPILER_VAR_738.bahType = "";
____BAH_COMPILER_VAR_738.isValue = false;
____BAH_COMPILER_VAR_738.isFunc = false;
____BAH_COMPILER_VAR_738.isOper = false;
____BAH_COMPILER_VAR_738.isEqual = false;
____BAH_COMPILER_VAR_738.pass = false;
____BAH_COMPILER_VAR_738.bahRef= null;
____BAH_COMPILER_VAR_738.parent= null;
____BAH_COMPILER_VAR_738.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_738.cont = ",";
____BAH_COMPILER_VAR_738.line = fnt.line;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_738;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_738;
        }
    }
    ;
struct Tok ____BAH_COMPILER_VAR_739 = {};
____BAH_COMPILER_VAR_739.cont = "";
____BAH_COMPILER_VAR_739.ogCont = "";
____BAH_COMPILER_VAR_739.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_739.pos = 0;
____BAH_COMPILER_VAR_739.line = 1;
____BAH_COMPILER_VAR_739.begLine = 1;
____BAH_COMPILER_VAR_739.bahType = "";
____BAH_COMPILER_VAR_739.isValue = false;
____BAH_COMPILER_VAR_739.isFunc = false;
____BAH_COMPILER_VAR_739.isOper = false;
____BAH_COMPILER_VAR_739.isEqual = false;
____BAH_COMPILER_VAR_739.pass = false;
____BAH_COMPILER_VAR_739.bahRef= null;
____BAH_COMPILER_VAR_739.parent= null;
____BAH_COMPILER_VAR_739.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_739.cont = currLine;
____BAH_COMPILER_VAR_739.line = fnt.line;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_739;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_739;
        }
    }
    ;
fn = searchFunc("__BAH_panic",elems,true);
char * ____BAH_COMPILER_VAR_740 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_740 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_740+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_740+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_740;
}
else if ((strcmp(fn->name, "__dumpSymbols") == 0)) {
array(struct variable*)* symbols = memoryAlloc(sizeof(array(struct variable*)));

symbols->length = 0;
symbols->elemSize = sizeof(struct variable*);
register long int j = 0;
for (; (j<len(elems->vars)); ++j) {
struct variable* v = elems->vars->data[j];
if ((v->isConst==false)) {

    {
        unsigned long nLength = len(symbols);
        if (nLength >= symbols->length) {
            if (nLength >= symbols->realLength) {
                if (symbols->realLength != 0) {
                    symbols->realLength *= 2;
                } else {
                    symbols->realLength = 50;
                }
                void * newPtr = memoryRealloc(symbols->data, (symbols->realLength)*sizeof(struct variable*));
                symbols->data = newPtr;
            }
            symbols->data[len(symbols)] = v;
            symbols->length = nLength+1;
        } else {
            symbols->data[len(symbols)] = v;
        }
    }
    ;
}
};
struct variable* ____BAH_COMPILER_VAR_741 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_741->name = "";
____BAH_COMPILER_VAR_741->type = "";
____BAH_COMPILER_VAR_741->isConst = false;
____BAH_COMPILER_VAR_741->constVal = "";
____BAH_COMPILER_VAR_741->isArray = false;
____BAH_COMPILER_VAR_741->from = "";
____BAH_COMPILER_VAR_741->declScope= null;
____BAH_COMPILER_VAR_741->isGlobal = false;
____BAH_COMPILER_VAR_741->declRope= null;
____BAH_COMPILER_VAR_741->isReg = false;
____BAH_COMPILER_VAR_741->lastSet= null;
____BAH_COMPILER_VAR_741->isArg = false;
____BAH_COMPILER_VAR_741->name = genCompilerVar();
____BAH_COMPILER_VAR_741->type = "[]reflectElement";
____BAH_COMPILER_VAR_741->isArray = true;
struct variable* tmpV = ____BAH_COMPILER_VAR_741;
char * decls = "";
j = 0;
for (; (j<len(symbols)); ++j) {
struct variable* v = symbols->data[j];
char * vname = v->name;
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_742 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("&");
unsigned int strLen_1 = strlen(v->name);
;                            
            ____BAH_COMPILER_VAR_742 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_742+currStrOff, "&", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_742+currStrOff, v->name, strLen_1);
            currStrOff += strLen_1;
        
        }vname = ____BAH_COMPILER_VAR_742;
}
struct Tok ____BAH_COMPILER_VAR_743 = {};
____BAH_COMPILER_VAR_743.cont = "";
____BAH_COMPILER_VAR_743.ogCont = "";
____BAH_COMPILER_VAR_743.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_743.pos = 0;
____BAH_COMPILER_VAR_743.line = 1;
____BAH_COMPILER_VAR_743.begLine = 1;
____BAH_COMPILER_VAR_743.bahType = "";
____BAH_COMPILER_VAR_743.isValue = false;
____BAH_COMPILER_VAR_743.isFunc = false;
____BAH_COMPILER_VAR_743.isOper = false;
____BAH_COMPILER_VAR_743.isEqual = false;
____BAH_COMPILER_VAR_743.pass = false;
____BAH_COMPILER_VAR_743.bahRef= null;
____BAH_COMPILER_VAR_743.parent= null;
____BAH_COMPILER_VAR_743.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_743.cont = vname;
____BAH_COMPILER_VAR_743.bahType = v->type;
____BAH_COMPILER_VAR_743.isValue = true;
#define tmpT ____BAH_COMPILER_VAR_743
tmpT = parseReflect(tmpT,v->type,elems,true,v->name,"0");
char * ____BAH_COMPILER_VAR_744 =null;char * ____BAH_COMPILER_VAR_745 =intToStr(j);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpT.cont);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("] = ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_745);
unsigned int strLen_4 = strlen("->data[");
unsigned int strLen_5 = strlen(tmpV->name);
;                            
            ____BAH_COMPILER_VAR_744 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_744+currStrOff, tmpV->name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_744+currStrOff, "->data[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_744+currStrOff, ____BAH_COMPILER_VAR_745, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_744+currStrOff, "] = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_744+currStrOff, tmpT.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_744+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_746 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(decls);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_744);
;                            
            ____BAH_COMPILER_VAR_746 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_746+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_746+currStrOff, ____BAH_COMPILER_VAR_744, strLen_1);
            currStrOff += strLen_1;
        
        }decls = ____BAH_COMPILER_VAR_746;

#undef tmpT
};

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = tmpV;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = tmpV;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_747 =null;char * ____BAH_COMPILER_VAR_748 =intToStr(len(symbols));char * ____BAH_COMPILER_VAR_749 =intToStr(len(symbols));
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(decls);
unsigned int strLen_1 = strlen("\n        ");
unsigned int strLen_2 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
unsigned int strLen_3 = strlen(tmpV->name);
unsigned int strLen_4 = strlen(";\n        ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_748);
unsigned int strLen_6 = strlen("->length = ");
unsigned int strLen_7 = strlen(tmpV->name);
unsigned int strLen_8 = strlen(");\n        ");
unsigned int strLen_9 = strlen(____BAH_COMPILER_VAR_749);
unsigned int strLen_10 = strlen("->data = memoryAlloc(sizeof(struct reflectElement) * ");
unsigned int strLen_11 = strlen(tmpV->name);
unsigned int strLen_12 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
unsigned int strLen_13 = strlen(tmpV->name);
unsigned int strLen_14 = strlen("\n        array(struct reflectElement)* ");
;                            
            ____BAH_COMPILER_VAR_747 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14);
            
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, "\n        array(struct reflectElement)* ", strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, tmpV->name, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, tmpV->name, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, "->data = memoryAlloc(sizeof(struct reflectElement) * ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, ____BAH_COMPILER_VAR_749, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, ");\n        ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, tmpV->name, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, "->length = ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, ____BAH_COMPILER_VAR_748, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, ";\n        ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_747+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_747+currStrOff, decls, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_747+currStrOff, "\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_747));
struct Tok ____BAH_COMPILER_VAR_750 = {};
____BAH_COMPILER_VAR_750.cont = "";
____BAH_COMPILER_VAR_750.ogCont = "";
____BAH_COMPILER_VAR_750.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_750.pos = 0;
____BAH_COMPILER_VAR_750.line = 1;
____BAH_COMPILER_VAR_750.begLine = 1;
____BAH_COMPILER_VAR_750.bahType = "";
____BAH_COMPILER_VAR_750.isValue = false;
____BAH_COMPILER_VAR_750.isFunc = false;
____BAH_COMPILER_VAR_750.isOper = false;
____BAH_COMPILER_VAR_750.isEqual = false;
____BAH_COMPILER_VAR_750.pass = false;
____BAH_COMPILER_VAR_750.bahRef= null;
____BAH_COMPILER_VAR_750.parent= null;
____BAH_COMPILER_VAR_750.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_750.cont = tmpV->name;
____BAH_COMPILER_VAR_750.line = fnt.line;
____BAH_COMPILER_VAR_750.isValue = true;

    {
        unsigned long nLength = 0;
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[0] = ____BAH_COMPILER_VAR_750;
            memory->length = nLength+1;
        } else {
            memory->data[0] = ____BAH_COMPILER_VAR_750;
        }
    }
    ;
}
else if ((strcmp(fn->name, "breakPoint") == 0)) {
struct Tok ____BAH_COMPILER_VAR_751 = {};
____BAH_COMPILER_VAR_751.cont = "";
____BAH_COMPILER_VAR_751.ogCont = "";
____BAH_COMPILER_VAR_751.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_751.pos = 0;
____BAH_COMPILER_VAR_751.line = 1;
____BAH_COMPILER_VAR_751.begLine = 1;
____BAH_COMPILER_VAR_751.bahType = "";
____BAH_COMPILER_VAR_751.isValue = false;
____BAH_COMPILER_VAR_751.isFunc = false;
____BAH_COMPILER_VAR_751.isOper = false;
____BAH_COMPILER_VAR_751.isEqual = false;
____BAH_COMPILER_VAR_751.pass = false;
____BAH_COMPILER_VAR_751.bahRef= null;
____BAH_COMPILER_VAR_751.parent= null;
____BAH_COMPILER_VAR_751.type = TOKEN_TYPE_VAR;
____BAH_COMPILER_VAR_751.cont = "__dumpSymbols";
____BAH_COMPILER_VAR_751.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_752 = {};
____BAH_COMPILER_VAR_752.cont = "";
____BAH_COMPILER_VAR_752.ogCont = "";
____BAH_COMPILER_VAR_752.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_752.pos = 0;
____BAH_COMPILER_VAR_752.line = 1;
____BAH_COMPILER_VAR_752.begLine = 1;
____BAH_COMPILER_VAR_752.bahType = "";
____BAH_COMPILER_VAR_752.isValue = false;
____BAH_COMPILER_VAR_752.isFunc = false;
____BAH_COMPILER_VAR_752.isOper = false;
____BAH_COMPILER_VAR_752.isEqual = false;
____BAH_COMPILER_VAR_752.pass = false;
____BAH_COMPILER_VAR_752.bahRef= null;
____BAH_COMPILER_VAR_752.parent= null;
____BAH_COMPILER_VAR_752.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_752.cont = "(";
____BAH_COMPILER_VAR_752.line = fnt.line;
struct Tok ____BAH_COMPILER_VAR_753 = {};
____BAH_COMPILER_VAR_753.cont = "";
____BAH_COMPILER_VAR_753.ogCont = "";
____BAH_COMPILER_VAR_753.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_753.pos = 0;
____BAH_COMPILER_VAR_753.line = 1;
____BAH_COMPILER_VAR_753.begLine = 1;
____BAH_COMPILER_VAR_753.bahType = "";
____BAH_COMPILER_VAR_753.isValue = false;
____BAH_COMPILER_VAR_753.isFunc = false;
____BAH_COMPILER_VAR_753.isOper = false;
____BAH_COMPILER_VAR_753.isEqual = false;
____BAH_COMPILER_VAR_753.pass = false;
____BAH_COMPILER_VAR_753.bahRef= null;
____BAH_COMPILER_VAR_753.parent= null;
____BAH_COMPILER_VAR_753.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_753.cont = ")";
____BAH_COMPILER_VAR_753.line = fnt.line;
memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 3;
memory->elemSize = sizeof(struct Tok);
memory->data = memoryAlloc(sizeof(struct Tok) * 50);
                    memory->realLength = 50;
memory->data[0] = ____BAH_COMPILER_VAR_751;
memory->data[1] = ____BAH_COMPILER_VAR_752;
memory->data[2] = ____BAH_COMPILER_VAR_753;
memory = prePross(memory,LINE_TYPE_FN_CALL,elems);
struct Tok ____BAH_COMPILER_VAR_754 = {};
____BAH_COMPILER_VAR_754.cont = "";
____BAH_COMPILER_VAR_754.ogCont = "";
____BAH_COMPILER_VAR_754.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_754.pos = 0;
____BAH_COMPILER_VAR_754.line = 1;
____BAH_COMPILER_VAR_754.begLine = 1;
____BAH_COMPILER_VAR_754.bahType = "";
____BAH_COMPILER_VAR_754.isValue = false;
____BAH_COMPILER_VAR_754.isFunc = false;
____BAH_COMPILER_VAR_754.isOper = false;
____BAH_COMPILER_VAR_754.isEqual = false;
____BAH_COMPILER_VAR_754.pass = false;
____BAH_COMPILER_VAR_754.bahRef= null;
____BAH_COMPILER_VAR_754.parent= null;
____BAH_COMPILER_VAR_754.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_754.cont = ",";
____BAH_COMPILER_VAR_754.line = fnt.line;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_754;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_754;
        }
    }
    ;
struct Tok ____BAH_COMPILER_VAR_755 = {};
____BAH_COMPILER_VAR_755.cont = "";
____BAH_COMPILER_VAR_755.ogCont = "";
____BAH_COMPILER_VAR_755.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_755.pos = 0;
____BAH_COMPILER_VAR_755.line = 1;
____BAH_COMPILER_VAR_755.begLine = 1;
____BAH_COMPILER_VAR_755.bahType = "";
____BAH_COMPILER_VAR_755.isValue = false;
____BAH_COMPILER_VAR_755.isFunc = false;
____BAH_COMPILER_VAR_755.isOper = false;
____BAH_COMPILER_VAR_755.isEqual = false;
____BAH_COMPILER_VAR_755.pass = false;
____BAH_COMPILER_VAR_755.bahRef= null;
____BAH_COMPILER_VAR_755.parent= null;
____BAH_COMPILER_VAR_755.type = TOKEN_TYPE_STR;
____BAH_COMPILER_VAR_755.cont = currLine;
____BAH_COMPILER_VAR_755.line = fnt.line;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_755;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = ____BAH_COMPILER_VAR_755;
        }
    }
    ;
fn = searchFunc("breakPoint__inner",elems,true);
char * ____BAH_COMPILER_VAR_756 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_756 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_756+currStrOff, "(", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_756;
}
else if ((strcmp(fn->name, "sizeof") == 0)) {
char * tp = "";
register long int j = 0;
for (; (j<len(memory)); ++j) {
struct Tok tmpT = memory->data[j];
char * ____BAH_COMPILER_VAR_757 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tp);
unsigned int strLen_1 = strlen(tmpT.cont);
;                            
            ____BAH_COMPILER_VAR_757 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_757+currStrOff, tp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_757+currStrOff, tmpT.cont, strLen_1);
            currStrOff += strLen_1;
        
        }tp = ____BAH_COMPILER_VAR_757;
};
struct string cType = getCType(tp,elems);
char * ____BAH_COMPILER_VAR_758 =null;char * ____BAH_COMPILER_VAR_759 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_759);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_758 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, ____BAH_COMPILER_VAR_759, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_758+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_760 =null;char * ____BAH_COMPILER_VAR_761 =____BAH_COMPILER_VAR_758;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_761);
;                            
            ____BAH_COMPILER_VAR_760 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_760+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_760+currStrOff, ____BAH_COMPILER_VAR_761, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_760;
fnt.type = TOKEN_TYPE_FUNC;
fnt.isFunc = true;
fnt.bahType = "int";
fnt.bahRef = fn;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = fnt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = fnt;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_762 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(amp);
unsigned int strLen_1 = strlen(parent->name);
;                            
            ____BAH_COMPILER_VAR_762 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_762+currStrOff, amp, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_762+currStrOff, parent->name, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_763 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_762);
;                            
            ____BAH_COMPILER_VAR_763 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_763+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_763+currStrOff, ____BAH_COMPILER_VAR_762, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_763;
++argIndex;
if ((len(fn->args)>argIndex)) {
char * ____BAH_COMPILER_VAR_764 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_764 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_764+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_764+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_764;
}
}
register long int j = 0;
for (; (j<len(memory)); ++j) {
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
char * ____BAH_COMPILER_VAR_765 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(arg->type);
unsigned int strLen_1 = strlen(" in function call.");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(tt);
unsigned int strLen_4 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_765 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_765+currStrOff, "Cannot use {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_765+currStrOff, tt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_765+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_765+currStrOff, arg->type, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_765+currStrOff, " in function call.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_765);
}
if ((RCPavailable()==true)&&(ltp==LINE_TYPE_VAR)&&(t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(currSetVar!=null)&&(strcmp(t.cont, currSetVar->name) == 0)&&isRCPtype(currSetVar->type,elems)) {
OUTPUT = rope__add(OUTPUT, incrVar(currSetVar,elems));
}
if ((t.type==TOKEN_TYPE_FUNC)) {
struct func* afn = searchFuncByToken(&t,elems);
if ((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true)) {
t.cont = registerRCPvar(afn->returns->type,t.cont,elems);
}
}
char * ____BAH_COMPILER_VAR_766 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_766 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_766+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_766+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_766;
++argIndex;
if ((j+1<len(memory))) {
++j;
t = memory->data[j];
if ((strcmp(t.cont, ",") != 0)) {
throwErr(&t,"Need separator between arguments, not {TOKEN}.");
}
char * ____BAH_COMPILER_VAR_767 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(",");
;                            
            ____BAH_COMPILER_VAR_767 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_767+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_767+currStrOff, ",", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_767;
}
};
if ((argIndex!=len(fn->args))) {
struct Tok lt = l->data[tokPos];
char * ____BAH_COMPILER_VAR_768 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("Not enough argument {TOKEN}, calling '");
;                            
            ____BAH_COMPILER_VAR_768 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_768+currStrOff, "Not enough argument {TOKEN}, calling '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_768+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_768+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&lt,____BAH_COMPILER_VAR_768);
}
fnt.bahRef = fn;
char * ____BAH_COMPILER_VAR_769 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fnt.cont);
unsigned int strLen_1 = strlen(")");
;                            
            ____BAH_COMPILER_VAR_769 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_769+currStrOff, fnt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_769+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }fnt.cont = ____BAH_COMPILER_VAR_769;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = fnt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = fnt;
        }
    }
    ;
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
if ((t.type==TOKEN_TYPE_VAR)) {
parent = searchVar(t.cont,elems);
}
else {
char * tmpV = genCompilerVar();
struct string cType = getCType(tt,elems);
char * ____BAH_COMPILER_VAR_770 =null;char * ____BAH_COMPILER_VAR_771 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(";\n                ");
unsigned int strLen_2 = strlen(" = ");
unsigned int strLen_3 = strlen(tmpV);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_771);
unsigned int strLen_6 = strlen("\n                ");
;                            
            ____BAH_COMPILER_VAR_770 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_770+currStrOff, "\n                ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_770+currStrOff, ____BAH_COMPILER_VAR_771, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_770+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_770+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_770+currStrOff, " = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_770+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_770+currStrOff, ";\n                ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_770));
t.cont = tmpV;
struct variable* ____BAH_COMPILER_VAR_772 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_772->name = "";
____BAH_COMPILER_VAR_772->type = "";
____BAH_COMPILER_VAR_772->isConst = false;
____BAH_COMPILER_VAR_772->constVal = "";
____BAH_COMPILER_VAR_772->isArray = false;
____BAH_COMPILER_VAR_772->from = "";
____BAH_COMPILER_VAR_772->declScope= null;
____BAH_COMPILER_VAR_772->isGlobal = false;
____BAH_COMPILER_VAR_772->declRope= null;
____BAH_COMPILER_VAR_772->isReg = false;
____BAH_COMPILER_VAR_772->lastSet= null;
____BAH_COMPILER_VAR_772->isArg = false;
____BAH_COMPILER_VAR_772->name = tmpV;
____BAH_COMPILER_VAR_772->type = tt;
parent = ____BAH_COMPILER_VAR_772;
if (RCPavailable()) {

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = parent;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = parent;
        }
    }
    ;
}
}
struct func* fn = searchStructMethod(nt.cont,s,elems);
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_773 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Unknown method {TOKEN} in struct ");
;                            
            ____BAH_COMPILER_VAR_773 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_773+currStrOff, "Unknown method {TOKEN} in struct ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_773+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_773+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_773);
}
if ((t.type==TOKEN_TYPE_VAR)) {
if ((fn->isImported==true)||(fn->isMut==true)) {
struct variable* rp = searchVarByToken(&t,elems);
rp->lastSet = elems;
if ((rp->isArg==true)) {
currentFn->isMut = true;
}
}
}
if ((fn->isVar==true)) {
char * ____BAH_COMPILER_VAR_774 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sep);
unsigned int strLen_1 = strlen(fn->name);
unsigned int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_774 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_774+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_774+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_774+currStrOff, fn->name, strLen_1);
            currStrOff += strLen_1;
        
        }fn->name = ____BAH_COMPILER_VAR_774;
}
valueFunc(fn,parent,l,i,ltp,elems);
struct Tok fnt = l->data[i];
delete(l,i);
char * ____BAH_COMPILER_VAR_775 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(nt.ogCont);
unsigned int strLen_2 = strlen(t.ogCont);
;                            
            ____BAH_COMPILER_VAR_775 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_775+currStrOff, t.ogCont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_775+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_775+currStrOff, nt.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }fnt.ogCont = ____BAH_COMPILER_VAR_775;
fnt.pos = t.pos;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = fnt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = fnt;
        }
    }
    ;
return tokPos;
}
}
struct structMemb* m = searchStructMemb(nt.cont,s,elems);
if ((m==null)) {
char * ____BAH_COMPILER_VAR_776 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(s->name);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("Unknown struct member {TOKEN} in struct '");
;                            
            ____BAH_COMPILER_VAR_776 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_776+currStrOff, "Unknown struct member {TOKEN} in struct '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_776+currStrOff, s->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_776+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_776);
}
if ((m->isFn==true)) {
char * ____BAH_COMPILER_VAR_777 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("__");
unsigned int strLen_1 = strlen(m->name);
unsigned int strLen_2 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_777 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_777+currStrOff, s->name, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_777+currStrOff, "__", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_777+currStrOff, m->name, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_777;
}
else {
if ((t.type==TOKEN_TYPE_VAR)) {
t.parent = searchVarByToken(&t,elems);
}
char * ____BAH_COMPILER_VAR_778 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(sep);
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_778 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_778+currStrOff, sep, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_778+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_779 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_778);
;                            
            ____BAH_COMPILER_VAR_779 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_779+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_779+currStrOff, ____BAH_COMPILER_VAR_778, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_779;
}
char * ____BAH_COMPILER_VAR_780 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_780 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_780+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_780+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_781 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_780);
;                            
            ____BAH_COMPILER_VAR_781 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_781+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_781+currStrOff, ____BAH_COMPILER_VAR_780, strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_781;
t.bahType = m->type;
struct variable* ____BAH_COMPILER_VAR_782 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_782->name = "";
____BAH_COMPILER_VAR_782->type = "";
____BAH_COMPILER_VAR_782->isConst = false;
____BAH_COMPILER_VAR_782->constVal = "";
____BAH_COMPILER_VAR_782->isArray = false;
____BAH_COMPILER_VAR_782->from = "";
____BAH_COMPILER_VAR_782->declScope= null;
____BAH_COMPILER_VAR_782->isGlobal = false;
____BAH_COMPILER_VAR_782->declRope= null;
____BAH_COMPILER_VAR_782->isReg = false;
____BAH_COMPILER_VAR_782->lastSet= null;
____BAH_COMPILER_VAR_782->isArg = false;
____BAH_COMPILER_VAR_782->name = t.cont;
____BAH_COMPILER_VAR_782->type = t.bahType;
t.bahRef = ____BAH_COMPILER_VAR_782;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = t;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = t;
        }
    }
    ;
return tokPos;
};
long int valueArr(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-1;
struct Tok pt = l->data[tokPos];
delete(l,tokPos);
if ((pt.isValue==false)) {
throwErr(&pt,"Cannot use {TOKEN} as value (array).");
}
char * ____BAH_COMPILER_VAR_783 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_783);
struct Tok t = pt;
t.isValue = true;
char * ____BAH_COMPILER_VAR_784 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen("[");
;                            
            ____BAH_COMPILER_VAR_784 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_784+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_784+currStrOff, "[", strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_784;
long int nbEncls = 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i = tokPos+1;
for (; (i<len(l)); ++i) {
struct Tok tmpT = l->data[i];
if ((strcmp(tmpT.cont, "(") == 0)||(strcmp(tmpT.cont, "{") == 0)||(strcmp(tmpT.cont, "[") == 0)) {
++nbEncls;
}
else if ((strcmp(tmpT.cont, ")") == 0)||(strcmp(tmpT.cont, "}") == 0)||(strcmp(tmpT.cont, "]") == 0)) {
--nbEncls;
char * ____BAH_COMPILER_VAR_785 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen("]");
;                            
            ____BAH_COMPILER_VAR_785 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_785+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_785+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_785;
if ((nbEncls==0)) {
break;
}
}
char * ____BAH_COMPILER_VAR_786 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.ogCont);
unsigned int strLen_1 = strlen(tmpT.ogCont);
;                            
            ____BAH_COMPILER_VAR_786 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_786+currStrOff, t.ogCont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_786+currStrOff, tmpT.ogCont, strLen_1);
            currStrOff += strLen_1;
        
        }t.ogCont = ____BAH_COMPILER_VAR_786;

    {
        unsigned long nLength = len(memory);
        if (nLength >= memory->length) {
            if (nLength >= memory->realLength) {
                if (memory->realLength != 0) {
                    memory->realLength *= 2;
                } else {
                    memory->realLength = 50;
                }
                void * newPtr = memoryRealloc(memory->data, (memory->realLength)*sizeof(struct Tok));
                memory->data = newPtr;
            }
            memory->data[len(memory)] = tmpT;
            memory->length = nLength+1;
        } else {
            memory->data[len(memory)] = tmpT;
        }
    }
    ;
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
struct Tok second;
struct Tok third;
if ((len(memory)==3)) {
second = memory->data[1];
third = memory->data[2];
char * firstT = getTypeFromToken(&first,true,elems);
if ((compTypes(firstT,"int")==false)) {
throwErr(&first,"Cannot use {TOKEN} as int.");
}
char * thirdT = getTypeFromToken(&third,true,elems);
if ((compTypes(thirdT,"int")==false)) {
throwErr(&third,"Cannot use {TOKEN} as int.");
}
if ((strcmp(second.cont, ":") != 0)) {
throwErr(&second,"Expected ':' not {TOKEN}.");
}
from = first.cont;
to = third.cont;
}
else if ((len(memory)==2)) {
second = memory->data[1];
if ((strcmp(first.cont, ":") == 0)) {
from = "0";
char * secondT = getTypeFromToken(&second,true,elems);
if ((compTypes(secondT,"int")==false)) {
throwErr(&second,"Cannot use {TOKEN} as int.");
}
to = second.cont;
}
else if ((strcmp(second.cont, ":") == 0)) {
char * firstT = getTypeFromToken(&first,true,elems);
if ((compTypes(firstT,"int")==false)) {
throwErr(&first,"Cannot use {TOKEN} as int.");
}
from = first.cont;
}
else {
throwErr(&second,"Expected ':' not {TOKEN}");
}
}
else {
throwErr(&memory->data[3],"Cannot substiture with more than 2 values, expected ']' not {TOKEN}.");
}
}
if (string__hasPrefix(&ptt,"[]")) {
if ((split==false)) {
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_787 =getTypeFromToken(&index,true,elems);if ((compTypes(____BAH_COMPILER_VAR_787,"int")==false)) {
throwErr(&index,"Cannot use {TOKEN} as array index (int).");
}
char * ____BAH_COMPILER_VAR_788 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen("]");
unsigned int strLen_2 = strlen("->data[");
unsigned int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_788 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_788+currStrOff, "->data[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_788+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_788;
string__trimLeft(&ptt,2);
t.bahType = string__str(&ptt);
}
else {
t.bahType = string__str(&ptt);
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_789 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen("->length");
;                            
            ____BAH_COMPILER_VAR_789 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_789+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_789+currStrOff, "->length", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_789;
}
char * ____BAH_COMPILER_VAR_790 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(to);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(from);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen("arraySubstitute(");
;                            
            ____BAH_COMPILER_VAR_790 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, "arraySubstitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_790+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_790+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_790;
}
}
else if (string__hasPrefix(&ptt,"buffer:")) {
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_791 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen("]");
unsigned int strLen_2 = strlen("[");
unsigned int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_791 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_791+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_791+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_791+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_791;
}
else {
t.bahType = "cpstring";
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_792 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_792 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_792+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_792+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_792+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_792;
}
char * ____BAH_COMPILER_VAR_793 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(to);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(from);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen("cpstringSubsitute(");
;                            
            ____BAH_COMPILER_VAR_793 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_793+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_793+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_793+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_793;
}
}
else if (string__hasPrefix(&ptt,"map:")) {
if ((split==true)) {
throwErr(&pt,"Cannot do substitution on a map {TOKEN}.");
}
string__trimLeft(&ptt,4);
char * ____BAH_COMPILER_VAR_794 =string__str(&ptt);struct string elemType = getCType(____BAH_COMPILER_VAR_794,elems);
struct Tok index = memory->data[0];
if ((tokPos==0)&&(ltp==LINE_TYPE_VAR)) {
struct variable* ____BAH_COMPILER_VAR_795 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_795->name = "";
____BAH_COMPILER_VAR_795->type = "";
____BAH_COMPILER_VAR_795->isConst = false;
____BAH_COMPILER_VAR_795->constVal = "";
____BAH_COMPILER_VAR_795->isArray = false;
____BAH_COMPILER_VAR_795->from = "";
____BAH_COMPILER_VAR_795->declScope= null;
____BAH_COMPILER_VAR_795->isGlobal = false;
____BAH_COMPILER_VAR_795->declRope= null;
____BAH_COMPILER_VAR_795->isReg = false;
____BAH_COMPILER_VAR_795->lastSet= null;
____BAH_COMPILER_VAR_795->isArg = false;
____BAH_COMPILER_VAR_795->name = genCompilerVar();
____BAH_COMPILER_VAR_795->type = string__str(&ptt);
struct variable* tmpV = ____BAH_COMPILER_VAR_795;

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = tmpV;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = tmpV;
        }
    }
    ;
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_796 =null;char * ____BAH_COMPILER_VAR_797 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_797);
;                            
            ____BAH_COMPILER_VAR_796 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, ____BAH_COMPILER_VAR_797, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_796+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_796+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_796+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_796));
}
else {
char * ____BAH_COMPILER_VAR_798 =null;char * ____BAH_COMPILER_VAR_799 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_799);
;                            
            ____BAH_COMPILER_VAR_798 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_798+currStrOff, ____BAH_COMPILER_VAR_799, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_798+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_798+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_798+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_798));
}
char * ____BAH_COMPILER_VAR_800 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_800)) {
char * ____BAH_COMPILER_VAR_801 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV->name);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(index.cont);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen("mapWrapper__set(");
;                            
            ____BAH_COMPILER_VAR_801 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, "mapWrapper__set(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, index.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_801+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_801+currStrOff, tmpV->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_801+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_801;
}
else {
char * ____BAH_COMPILER_VAR_802 =null;char * ____BAH_COMPILER_VAR_803 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_803);
unsigned int strLen_1 = strlen("));\n");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(tmpV->name);
unsigned int strLen_4 = strlen(", &");
unsigned int strLen_5 = strlen(index.cont);
unsigned int strLen_6 = strlen(", ");
unsigned int strLen_7 = strlen(pt.cont);
unsigned int strLen_8 = strlen("mapWrapper__setAny(");
;                            
            ____BAH_COMPILER_VAR_802 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, "mapWrapper__setAny(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, pt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, ", ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, index.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, tmpV->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_802+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_802+currStrOff, ____BAH_COMPILER_VAR_803, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_802+currStrOff, "));\n", strLen_1);
            currStrOff += strLen_1;
        
        }NEXT_LINE = ____BAH_COMPILER_VAR_802;
}
t.cont = tmpV->name;
t.bahType = string__str(&ptt);
}
else {
t.isFunc = true;
struct rope* res= null;
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_804 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_804)) {
char * ____BAH_COMPILER_VAR_805 =null;char * ____BAH_COMPILER_VAR_806 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(t.cont);
unsigned int strLen_4 = strlen("=mapWrapper__get(");
unsigned int strLen_5 = strlen(tmpV);
unsigned int strLen_6 = strlen(" ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_806);
;                            
            ____BAH_COMPILER_VAR_805 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, ____BAH_COMPILER_VAR_806, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, " ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, tmpV, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, "=mapWrapper__get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, t.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_805+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_805+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_805+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }res = rope(____BAH_COMPILER_VAR_805);
t.cont = tmpV;
}
else {
char * ____BAH_COMPILER_VAR_807 =null;char * ____BAH_COMPILER_VAR_808 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("=mapWrapper__get(");
unsigned int strLen_5 = strlen(tmpV);
unsigned int strLen_6 = strlen("* ");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_808);
;                            
            ____BAH_COMPILER_VAR_807 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7);
            
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, ____BAH_COMPILER_VAR_808, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, "* ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, tmpV, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, "=mapWrapper__get(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_807+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_807+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_807+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }res = rope(____BAH_COMPILER_VAR_807);
char * ____BAH_COMPILER_VAR_809 =null;char * ____BAH_COMPILER_VAR_810 =string__str(&elemType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(")(*");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_810);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_809 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, ____BAH_COMPILER_VAR_810, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_809+currStrOff, ")(*", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_809+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_809+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_809;
}
if (RCPavailable()) {
struct variable* ____BAH_COMPILER_VAR_811 = memoryAlloc(sizeof(struct variable));
____BAH_COMPILER_VAR_811->name = "";
____BAH_COMPILER_VAR_811->type = "";
____BAH_COMPILER_VAR_811->isConst = false;
____BAH_COMPILER_VAR_811->constVal = "";
____BAH_COMPILER_VAR_811->isArray = false;
____BAH_COMPILER_VAR_811->from = "";
____BAH_COMPILER_VAR_811->declScope= null;
____BAH_COMPILER_VAR_811->isGlobal = false;
____BAH_COMPILER_VAR_811->declRope= null;
____BAH_COMPILER_VAR_811->isReg = false;
____BAH_COMPILER_VAR_811->lastSet= null;
____BAH_COMPILER_VAR_811->isArg = false;
____BAH_COMPILER_VAR_811->name = tmpV;
____BAH_COMPILER_VAR_811->type = string__str(&ptt);

    {
        unsigned long nLength = len(elems->vars);
        if (nLength >= elems->vars->length) {
            if (nLength >= elems->vars->realLength) {
                if (elems->vars->realLength != 0) {
                    elems->vars->realLength *= 2;
                } else {
                    elems->vars->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->vars->data, (elems->vars->realLength)*sizeof(struct variable*));
                elems->vars->data = newPtr;
            }
            elems->vars->data[len(elems->vars)] = ____BAH_COMPILER_VAR_811;
            elems->vars->length = nLength+1;
        } else {
            elems->vars->data[len(elems->vars)] = ____BAH_COMPILER_VAR_811;
        }
    }
    ;
}
if (isGlobal()) {
INIT = rope__add(INIT, res);
}
else {
OUTPUT = rope__add(OUTPUT, res);
}
t.bahType = string__str(&ptt);
}
}
else if ((strcmp(string__str(&ptt), "cpstring") == 0)) {
t.isFunc = true;
t.type = TOKEN_TYPE_FUNC;
if ((split==false)) {
t.bahType = "char";
struct Tok index = memory->data[0];
char * ____BAH_COMPILER_VAR_812 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(index.cont);
unsigned int strLen_1 = strlen("]");
unsigned int strLen_2 = strlen("[");
unsigned int strLen_3 = strlen(pt.cont);
;                            
            ____BAH_COMPILER_VAR_812 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_812+currStrOff, "[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_812+currStrOff, index.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_812+currStrOff, "]", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_812;
}
else {
if ((strcmp(to, "") == 0)) {
char * ____BAH_COMPILER_VAR_813 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("strlen(");
;                            
            ____BAH_COMPILER_VAR_813 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_813+currStrOff, "strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_813+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_813+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }to = ____BAH_COMPILER_VAR_813;
}
char * ____BAH_COMPILER_VAR_814 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(to);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(from);
unsigned int strLen_4 = strlen(", ");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen("cpstringSubsitute(");
;                            
            ____BAH_COMPILER_VAR_814 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, "cpstringSubsitute(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, ", ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, from, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_814+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_814+currStrOff, to, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_814+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_814;
}
}
else {
char * ____BAH_COMPILER_VAR_815 =null;char * ____BAH_COMPILER_VAR_816 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_816);
unsigned int strLen_1 = strlen(") as array.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_815 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_815+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_815+currStrOff, ____BAH_COMPILER_VAR_816, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_815+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_815);
}
t.isValue = true;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = t;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = t;
        }
    }
    ;
return tokPos;
};
long int valueBool(__BAH_ARR_TYPE_Tok l,long int i,lineType ltp,struct Elems* elems){
long int tokPos = i-2;
struct Tok pt = l->data[tokPos];
char * ptt = getTypeFromToken(&pt,true,elems);
struct Tok t = l->data[tokPos+1];
deleteRange(l,tokPos,tokPos+1);
if ((ltp==LINE_TYPE_FOR)&&(strcmp(ptt, "int") == 0)||(strcmp(ptt, "float") == 0)) {
struct variable* v = getRealVar(pt.cont,elems);
if ((v!=null)&&(v->canBeReg==true)&&(v->isReg==false)&&(v->declRope!=null)) {
char * odecl = rope__toStr(v->declRope);
if ((strHasPrefix(odecl,"register ")==false)) {
char * ____BAH_COMPILER_VAR_817 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("register ");
unsigned int strLen_1 = strlen(odecl);
;                            
            ____BAH_COMPILER_VAR_817 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_817+currStrOff, "register ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_817+currStrOff, odecl, strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(v->declRope,____BAH_COMPILER_VAR_817);
}
v->isReg = true;
}
}
struct Tok nt = l->data[tokPos];
char * ntt = getTypeFromToken(&nt,true,elems);
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT = string(ntt);
if ((string__hasPrefix(&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_818 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ntt);
unsigned int strLen_1 = strlen(") as array.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_818 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_818+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_818+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_818+currStrOff, ") as array.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_818);
}
string__trimLeft(&arrT,2);
char * ____BAH_COMPILER_VAR_819 =string__str(&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_819)==false)) {
char * ____BAH_COMPILER_VAR_820 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ntt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") in ");
unsigned int strLen_3 = strlen(ptt);
unsigned int strLen_4 = strlen("Cannot search for {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_820 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, "Cannot search for {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, ptt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_820+currStrOff, ") in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_820+currStrOff, ntt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_820+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_820);
}
char * compVar = genCompilerVar();
char * comp = "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_821 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(") == 0");
unsigned int strLen_2 = strlen("->data[i], ");
unsigned int strLen_3 = strlen(nt.cont);
unsigned int strLen_4 = strlen("->data[i] != 0 && strcmp(");
unsigned int strLen_5 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_821 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, "->data[i] != 0 && strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, nt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_821+currStrOff, "->data[i], ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_821+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_821+currStrOff, ") == 0", strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_821;
}
else {
char * ____BAH_COMPILER_VAR_822 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("->data[i] == ");
unsigned int strLen_1 = strlen(pt.cont);
unsigned int strLen_2 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_822 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_822+currStrOff, nt.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_822+currStrOff, "->data[i] == ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_822+currStrOff, pt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }comp = ____BAH_COMPILER_VAR_822;
}
char * ____BAH_COMPILER_VAR_823 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compVar);
unsigned int strLen_1 = strlen("=1;\n                break;\n            };\n        }\n        ");
unsigned int strLen_2 = strlen(") {\n                ");
unsigned int strLen_3 = strlen(comp);
unsigned int strLen_4 = strlen("->length-1; i!=-1;i--) {\n            if (");
unsigned int strLen_5 = strlen(nt.cont);
unsigned int strLen_6 = strlen(" = 0;\n        for(int i=");
unsigned int strLen_7 = strlen(compVar);
unsigned int strLen_8 = strlen("\n        char ");
;                            
            ____BAH_COMPILER_VAR_823 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, "\n        char ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, compVar, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, " = 0;\n        for(int i=", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, nt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, "->length-1; i!=-1;i--) {\n            if (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, comp, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_823+currStrOff, ") {\n                ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_823+currStrOff, compVar, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_823+currStrOff, "=1;\n                break;\n            };\n        }\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_823));
pt.cont = compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_824 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") with type ");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_824 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_824+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_824+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_824+currStrOff, ") with type ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_824+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_824+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_824);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_825 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(") == 0)");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_825 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_825+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_825+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_825+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_825+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_825+currStrOff, ") == 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_825;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_826 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(") != 0)");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strcmp(");
;                            
            ____BAH_COMPILER_VAR_826 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_826+currStrOff, "(strcmp(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_826+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_826+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_826+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_826+currStrOff, ") != 0)", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_826;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_827 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") > srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_827 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_827+currStrOff, ") > srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_827+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_827+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_827;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_828 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") < srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_828 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_828+currStrOff, ") < srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_828+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_828+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_828;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_829 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") >= srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_829 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_829+currStrOff, ") >= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_829+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_829+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_829;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_830 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen("))");
unsigned int strLen_2 = strlen(") <= srtlen(");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(strlen(");
;                            
            ____BAH_COMPILER_VAR_830 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_830+currStrOff, "(strlen(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_830+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_830+currStrOff, ") <= srtlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_830+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_830+currStrOff, "))", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_830;
}
}
else {
char * ____BAH_COMPILER_VAR_831 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(t.cont);
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_831 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_831+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_831+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_831+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_831;
}
}
pt.isOper = true;
pt.bahType = "bool";
pt.isValue = true;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = pt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = pt;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_832 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(pt.cont);
unsigned int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_832 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_832+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_832+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_832+currStrOff, pt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_832;

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = pt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = pt;
        }
    }
    ;
return tokPos;
}
char * ntt = getTypeFromToken(&nt,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_833 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") as ");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot compare {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_833 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, "Cannot compare {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_833+currStrOff, ") as ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_833+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_833+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_833);
}
if ((strcmp(ptt, "cpstring") == 0)) {
char * lens = "";
char * totStrLen = "1+strLen_0+strLen_1";
struct rope* cats = rope("");
char * rstr = registerRCPvar("cpstring","null",elems);
if ((pt.isFunc==true)) {
pt.cont = registerRCPvar("cpstring",pt.cont,elems);
}
char * ____BAH_COMPILER_VAR_834 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("unsigned int strLen_0 = strlen(");
;                            
            ____BAH_COMPILER_VAR_834 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_834+currStrOff, "unsigned int strLen_0 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_834+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_834+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_835 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lens);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_834);
;                            
            ____BAH_COMPILER_VAR_835 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_835+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_835+currStrOff, ____BAH_COMPILER_VAR_834, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_835;
char * ____BAH_COMPILER_VAR_836 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(", strLen_0);\n            currStrOff += strLen_0;\n        ");
unsigned int strLen_2 = strlen("+currStrOff, ");
unsigned int strLen_3 = strlen(rstr);
unsigned int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_836 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_836+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_836+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_836+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_836+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_836+currStrOff, ", strLen_0);\n            currStrOff += strLen_0;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope__add(cats, rope(____BAH_COMPILER_VAR_836));
if ((nt.isFunc==true)) {
nt.cont = registerRCPvar("cpstring",nt.cont,elems);
}
char * ____BAH_COMPILER_VAR_837 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("unsigned int strLen_1 = strlen(");
;                            
            ____BAH_COMPILER_VAR_837 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_837+currStrOff, "unsigned int strLen_1 = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_837+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_837+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_838 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lens);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_837);
;                            
            ____BAH_COMPILER_VAR_838 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_838+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_838+currStrOff, ____BAH_COMPILER_VAR_837, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_838;
char * ____BAH_COMPILER_VAR_839 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(", strLen_1);\n            currStrOff += strLen_1;\n        ");
unsigned int strLen_2 = strlen("+currStrOff, ");
unsigned int strLen_3 = strlen(rstr);
unsigned int strLen_4 = strlen("\n            memcpy(");
;                            
            ____BAH_COMPILER_VAR_839 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_839+currStrOff, "\n            memcpy(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_839+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_839+currStrOff, "+currStrOff, ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_839+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_839+currStrOff, ", strLen_1);\n            currStrOff += strLen_1;\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope__add(cats, rope(____BAH_COMPILER_VAR_839));
if ((strcmp(t.cont, "+") != 0)) {
throwErr(&t,"Can only do concatenation on cpstring, not {TOKEN}.");
}
if ((tokPos-1>=0)) {
struct Tok nat = l->data[tokPos-1];
if ((strcmp(nat.cont, "+") == 0)) {
long int rangeEnds = tokPos-1;
i = tokPos-2;
long int nb = 2;
for (; (i>=0); --i) {
tokPos = i;
struct Tok currStrTk = l->data[i];
char * tt = getTypeFromToken(&currStrTk,true,elems);
if ((compTypes(tt,"cpstring")==false)) {
char * ____BAH_COMPILER_VAR_840 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tt);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("Cannot concatenate cpstring with {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_840 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_840+currStrOff, "Cannot concatenate cpstring with {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_840+currStrOff, tt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_840+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&currStrTk,____BAH_COMPILER_VAR_840);
}
if ((currStrTk.isFunc==true)) {
currStrTk.cont = registerRCPvar("cpstring",currStrTk.cont,elems);
}
char * is = intToStr(nb);
++nb;
char * ____BAH_COMPILER_VAR_841 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currStrTk.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(" = strlen(");
unsigned int strLen_3 = strlen(is);
unsigned int strLen_4 = strlen("unsigned int strLen_");
;                            
            ____BAH_COMPILER_VAR_841 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_841+currStrOff, "unsigned int strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_841+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_841+currStrOff, " = strlen(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_841+currStrOff, currStrTk.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_841+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_842 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lens);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_841);
;                            
            ____BAH_COMPILER_VAR_842 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_842+currStrOff, lens, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_842+currStrOff, ____BAH_COMPILER_VAR_841, strLen_1);
            currStrOff += strLen_1;
        
        }lens = ____BAH_COMPILER_VAR_842;
char * ____BAH_COMPILER_VAR_843 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("+strLen_");
unsigned int strLen_1 = strlen(is);
;                            
            ____BAH_COMPILER_VAR_843 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_843+currStrOff, "+strLen_", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_843+currStrOff, is, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_844 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(totStrLen);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_843);
;                            
            ____BAH_COMPILER_VAR_844 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_844+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_844+currStrOff, ____BAH_COMPILER_VAR_843, strLen_1);
            currStrOff += strLen_1;
        
        }totStrLen = ____BAH_COMPILER_VAR_844;
char * ____BAH_COMPILER_VAR_845 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(is);
unsigned int strLen_1 = strlen(";\n                    ");
unsigned int strLen_2 = strlen(");\n                    currStrOff += strLen_");
unsigned int strLen_3 = strlen(is);
unsigned int strLen_4 = strlen(", strLen_");
unsigned int strLen_5 = strlen(currStrTk.cont);
unsigned int strLen_6 = strlen("+currStrOff, ");
unsigned int strLen_7 = strlen(rstr);
unsigned int strLen_8 = strlen("\n                    memcpy(");
;                            
            ____BAH_COMPILER_VAR_845 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, "\n                    memcpy(", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, rstr, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, "+currStrOff, ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, currStrTk.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, ", strLen_", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, is, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_845+currStrOff, ");\n                    currStrOff += strLen_", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_845+currStrOff, is, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_845+currStrOff, ";\n                    ", strLen_1);
            currStrOff += strLen_1;
        
        }cats = rope__add(rope(____BAH_COMPILER_VAR_845), cats);
if ((i-1>=0)) {
--i;
t = l->data[i];
if ((strcmp(t.cont, "+") != 0)) {

        char ____BAH_COMPILER_VAR_846 = 0;
        for(int i=signs->length-1; i!=-1;i--) {
            if (signs->data[i] != 0 && strcmp(signs->data[i], t.cont) == 0) {
                ____BAH_COMPILER_VAR_846=1;
                break;
            };
        }
        if (____BAH_COMPILER_VAR_846) {
throwErr(&t,"Can only do concatenation on cpstring, not {TOKEN}.");
}
else {
++i;
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
char * ____BAH_COMPILER_VAR_847 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(totStrLen);
unsigned int strLen_1 = strlen(");\n            ");
unsigned int strLen_2 = strlen(" = memoryAllocSTR(");
unsigned int strLen_3 = strlen(rstr);
unsigned int strLen_4 = strlen(";                            \n            ");
unsigned int strLen_5 = strlen(lens);
unsigned int strLen_6 = strlen("\n        {\n            unsigned int currStrOff = 0;\n            ");
;                            
            ____BAH_COMPILER_VAR_847 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, "\n        {\n            unsigned int currStrOff = 0;\n            ", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, lens, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, ";                            \n            ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, rstr, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_847+currStrOff, " = memoryAllocSTR(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_847+currStrOff, totStrLen, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_847+currStrOff, ");\n            ", strLen_1);
            currStrOff += strLen_1;
        
        }struct rope* res = rope__add(rope(____BAH_COMPILER_VAR_847), rope__add(cats, rope("\n        }")));
if (isGlobal()) {
INIT = rope__add(INIT, res);
}
else {
OUTPUT = rope__add(OUTPUT, res);
}
pt.type = TOKEN_TYPE_VAR;
pt.isValue = true;
pt.cont = rstr;
pt.isOper = false;
}
else {
struct cStruct* s = searchStruct(ptt,elems);
if ((s!=null)) {
char * sep = ".";
char * amp = "&";
if (isRCPpointerType(ptt)) {
sep = "->";
amp = "";
}
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
char * ____BAH_COMPILER_VAR_848 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("Undefined operation on struct {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_848 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_848+currStrOff, "Undefined operation on struct {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_848+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_848+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_848);
}
struct structMemb* methd = searchStructMemb(mName,s,elems);
if ((methd!=null)&&(methd->isFn==true)) {
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_849 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen(amp);
unsigned int strLen_5 = strlen("(");
unsigned int strLen_6 = strlen(mName);
unsigned int strLen_7 = strlen("__");
unsigned int strLen_8 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_849 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_849+currStrOff, s->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_849+currStrOff, "__", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_849+currStrOff, mName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_849+currStrOff, "(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_849+currStrOff, amp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_849+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_849+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_849+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_849+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = registerRCPvar(ptt,____BAH_COMPILER_VAR_849,elems);
pt.type = TOKEN_TYPE_VAR;
pt.isFunc = false;
pt.isOper = false;
}
else {
char * ____BAH_COMPILER_VAR_850 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen(amp);
unsigned int strLen_5 = strlen("(");
unsigned int strLen_6 = strlen(mName);
unsigned int strLen_7 = strlen("__");
unsigned int strLen_8 = strlen(s->name);
;                            
            ____BAH_COMPILER_VAR_850 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, s->name, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, "__", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, mName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, "(", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, amp, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_850+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_850+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_850+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_850;
pt.isFunc = true;
}
}
}
else {
char * ____BAH_COMPILER_VAR_851 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_851 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_851+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_851+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_852 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_851);
;                            
            ____BAH_COMPILER_VAR_852 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_852+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_852+currStrOff, ____BAH_COMPILER_VAR_851, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_852;
}
pt.isOper = true;
}

    {
        unsigned long nLength = tokPos;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[tokPos] = pt;
            l->length = nLength+1;
        } else {
            l->data[tokPos] = pt;
        }
    }
    ;
return tokPos;
};
long int valueSendChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-2;
struct Tok nt = l->data[posTok];
struct Tok pt = l->data[posTok+2];
deleteRange(l,posTok,posTok+2);
char * ntt = getTypeFromToken(&nt,true,elems);
char * ____BAH_COMPILER_VAR_853 =getTypeFromToken(&pt,true,elems);struct string ptt = string(____BAH_COMPILER_VAR_853);
if ((string__hasPrefix(&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_854 =null;char * ____BAH_COMPILER_VAR_855 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_855);
unsigned int strLen_1 = strlen(") as chan.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_854 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_854+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_854+currStrOff, ____BAH_COMPILER_VAR_855, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_854+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&pt,____BAH_COMPILER_VAR_854);
}
string__trimLeft(&ptt,5);
if (isGlobal()) {
throwErr(&pt,"Cannot send to channel {TOKEN} of a function.");
}
char * ____BAH_COMPILER_VAR_856 =string__str(&ptt);if ((compTypes(ntt,____BAH_COMPILER_VAR_856)==false)) {
char * ____BAH_COMPILER_VAR_857 =null;char * ____BAH_COMPILER_VAR_858 =string__str(&ptt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_858);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(") through chan:");
unsigned int strLen_3 = strlen(ntt);
unsigned int strLen_4 = strlen("Cannot send {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_857 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, "Cannot send {TOKEN} (", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, ntt, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_857+currStrOff, ") through chan:", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_857+currStrOff, ____BAH_COMPILER_VAR_858, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_857+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_857);
}
char * ____BAH_COMPILER_VAR_859 =string__str(&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_859)) {
char * ____BAH_COMPILER_VAR_860 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen(", ");
unsigned int strLen_3 = strlen(pt.cont);
unsigned int strLen_4 = strlen("channel__send(");
;                            
            ____BAH_COMPILER_VAR_860 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_860+currStrOff, "channel__send(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_860+currStrOff, pt.cont, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_860+currStrOff, ", ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_860+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_860+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_860));
}
else {
struct string ct = getCType(ntt,elems);
char * tmpV = genCompilerVar();
char * ____BAH_COMPILER_VAR_861 =null;char * ____BAH_COMPILER_VAR_862 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpV);
unsigned int strLen_1 = strlen("));\n        ");
unsigned int strLen_2 = strlen(", sizeof(");
unsigned int strLen_3 = strlen(tmpV);
unsigned int strLen_4 = strlen(", &");
unsigned int strLen_5 = strlen(pt.cont);
unsigned int strLen_6 = strlen(";\n        channel__sendAny(");
unsigned int strLen_7 = strlen(nt.cont);
unsigned int strLen_8 = strlen(" = ");
unsigned int strLen_9 = strlen(tmpV);
unsigned int strLen_10 = strlen(" ");
unsigned int strLen_11 = strlen(____BAH_COMPILER_VAR_862);
unsigned int strLen_12 = strlen("\n        ");
;                            
            ____BAH_COMPILER_VAR_861 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12);
            
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, "\n        ", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, ____BAH_COMPILER_VAR_862, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, " ", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, tmpV, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, " = ", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, nt.cont, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, ";\n        channel__sendAny(", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, pt.cont, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, ", &", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, tmpV, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_861+currStrOff, ", sizeof(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_861+currStrOff, tmpV, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_861+currStrOff, "));\n        ", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_861));
}
return posTok;
};
long int valueChan(__BAH_ARR_TYPE_Tok l,long int i,struct Elems* elems){
long int posTok = i-1;
delete(l,posTok);
struct Tok nt = l->data[posTok];
char * ____BAH_COMPILER_VAR_863 =getTypeFromToken(&nt,true,elems);struct string ntt = string(____BAH_COMPILER_VAR_863);
if ((string__hasPrefix(&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_864 =null;char * ____BAH_COMPILER_VAR_865 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_865);
unsigned int strLen_1 = strlen(") as chan.");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} (");
;                            
            ____BAH_COMPILER_VAR_864 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_864+currStrOff, "Cannot use {TOKEN} (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_864+currStrOff, ____BAH_COMPILER_VAR_865, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_864+currStrOff, ") as chan.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&nt,____BAH_COMPILER_VAR_864);
}
string__trimLeft(&ntt,5);
if (isGlobal()) {
throwErr(&nt,"Cannot receive from chan {TOKEN} outside a function body.");
}
char * ____BAH_COMPILER_VAR_866 =string__str(&ntt);struct string ct = getCType(____BAH_COMPILER_VAR_866,elems);
char * ____BAH_COMPILER_VAR_867 =string__str(&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_867)) {
char * ____BAH_COMPILER_VAR_868 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("channel__receive(");
;                            
            ____BAH_COMPILER_VAR_868 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_868+currStrOff, "channel__receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_868+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_868+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_869 =string__str(&ntt);char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_869,____BAH_COMPILER_VAR_868,elems);
nt.cont = tmpV;
}
else {
if (RCPavailable()) {
char * ____BAH_COMPILER_VAR_870 =null;char * ____BAH_COMPILER_VAR_871 =string__str(&ntt);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_871);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_870 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_870+currStrOff, ____BAH_COMPILER_VAR_871, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_870+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_872 =null;char * ____BAH_COMPILER_VAR_873 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)channel__receive(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_873);
unsigned int strLen_4 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_872 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_872+currStrOff, "(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_872+currStrOff, ____BAH_COMPILER_VAR_873, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_872+currStrOff, "*)channel__receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_872+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_872+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }char * tmpV = registerRCPvar(____BAH_COMPILER_VAR_870,____BAH_COMPILER_VAR_872,elems);
char * ____BAH_COMPILER_VAR_874 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("*");
unsigned int strLen_1 = strlen(tmpV);
;                            
            ____BAH_COMPILER_VAR_874 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_874+currStrOff, "*", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_874+currStrOff, tmpV, strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_874;
}
else {
char * ____BAH_COMPILER_VAR_875 =null;char * ____BAH_COMPILER_VAR_876 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(nt.cont);
unsigned int strLen_1 = strlen(")");
unsigned int strLen_2 = strlen("*)channel__receive(");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_876);
unsigned int strLen_4 = strlen("*(");
;                            
            ____BAH_COMPILER_VAR_875 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_875+currStrOff, "*(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_875+currStrOff, ____BAH_COMPILER_VAR_876, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_875+currStrOff, "*)channel__receive(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_875+currStrOff, nt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_875+currStrOff, ")", strLen_1);
            currStrOff += strLen_1;
        
        }nt.cont = ____BAH_COMPILER_VAR_875;
}
}
nt.type = TOKEN_TYPE_FUNC;
nt.isFunc = true;
nt.isValue = true;
nt.bahType = string__str(&ntt);

    {
        unsigned long nLength = posTok;
        if (nLength >= l->length) {
            if (nLength >= l->realLength) {
                if (l->realLength != 0) {
                    l->realLength *= 2;
                } else {
                    l->realLength = 50;
                }
                void * newPtr = memoryRealloc(l->data, (l->realLength)*sizeof(struct Tok));
                l->data = newPtr;
            }
            l->data[posTok] = nt;
            l->length = nLength+1;
        } else {
            l->data[posTok] = nt;
        }
    }
    ;
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
register long int i = 0;
register long int sepI = 0;
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
if ((nt.line!=t.line)) {
break;
}
}

    {
        unsigned long nLength = len(fl);
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[len(fl)] = t;
            fl->length = nLength+1;
        } else {
            fl->data[len(fl)] = t;
        }
    }
    ;
++i;
};
sepI = i;
}
else {
fl = line;
}
struct Tok ____BAH_COMPILER_VAR_877 = {};
____BAH_COMPILER_VAR_877.cont = "";
____BAH_COMPILER_VAR_877.ogCont = "";
____BAH_COMPILER_VAR_877.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_877.pos = 0;
____BAH_COMPILER_VAR_877.line = 1;
____BAH_COMPILER_VAR_877.begLine = 1;
____BAH_COMPILER_VAR_877.bahType = "";
____BAH_COMPILER_VAR_877.isValue = false;
____BAH_COMPILER_VAR_877.isFunc = false;
____BAH_COMPILER_VAR_877.isOper = false;
____BAH_COMPILER_VAR_877.isEqual = false;
____BAH_COMPILER_VAR_877.pass = false;
____BAH_COMPILER_VAR_877.bahRef= null;
____BAH_COMPILER_VAR_877.parent= null;
#define pt ____BAH_COMPILER_VAR_877
long int l = len(fl);
i = 0;
for (; (i<len(fl)); ++i) {
struct Tok t = fl->data[i];
if ((t.type==TOKEN_TYPE_VAR)&&(t.isOper==false)&&(t.cont[0]==38)) {
struct string tc = string(t.cont);
string__trimLeft(&tc,1);
char * ____BAH_COMPILER_VAR_878 =string__str(&tc);struct variable* rv = getRealVar(____BAH_COMPILER_VAR_878,elems);
if ((rv!=null)&&(rv->canBeReg==true)&&(rv->declRope!=null)) {
char * rvdr = rope__toStr(rv->declRope);
if (strHasPrefix(rvdr,"register ")) {
strTrimLeft(&rvdr,9);
OUTPUT->totalLen = OUTPUT->totalLen+ropeSet(rv->declRope,rvdr);
}
rv->canBeReg = false;
}
}
};
i = 0;
for (; (i<len(fl)); ++i) {
struct Tok t = fl->data[i];
if ((i>0)) {
pt = fl->data[i-1];
}
else {
struct Tok ____BAH_COMPILER_VAR_879 = {};
____BAH_COMPILER_VAR_879.cont = "";
____BAH_COMPILER_VAR_879.ogCont = "";
____BAH_COMPILER_VAR_879.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_879.pos = 0;
____BAH_COMPILER_VAR_879.line = 1;
____BAH_COMPILER_VAR_879.begLine = 1;
____BAH_COMPILER_VAR_879.bahType = "";
____BAH_COMPILER_VAR_879.isValue = false;
____BAH_COMPILER_VAR_879.isFunc = false;
____BAH_COMPILER_VAR_879.isOper = false;
____BAH_COMPILER_VAR_879.isEqual = false;
____BAH_COMPILER_VAR_879.pass = false;
____BAH_COMPILER_VAR_879.bahRef= null;
____BAH_COMPILER_VAR_879.parent= null;
pt = ____BAH_COMPILER_VAR_879;
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
string__trimLeft(&ptc,1);
string__trimRight(&ptc,1);
t.bahType = string__str(&ptc);
char * ____BAH_COMPILER_VAR_880 =string__str(&ptc);struct string cType = getCType(____BAH_COMPILER_VAR_880,elems);
char * ____BAH_COMPILER_VAR_881 =null;char * ____BAH_COMPILER_VAR_882 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(")");
unsigned int strLen_1 = strlen(t.cont);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_882);
unsigned int strLen_3 = strlen("(");
;                            
            ____BAH_COMPILER_VAR_881 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_881+currStrOff, "(", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_881+currStrOff, ____BAH_COMPILER_VAR_882, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_881+currStrOff, ")", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_881+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }t.cont = ____BAH_COMPILER_VAR_881;

    {
        unsigned long nLength = i-1;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[i-1] = t;
            fl->length = nLength+1;
        } else {
            fl->data[i-1] = t;
        }
    }
    ;
i = i-2;
}
else if (inArrayStr(pt.cont,signs)) {
if ((strcmp(t.cont, pt.cont) == 0)&&(i>1)) {
struct Tok ppt = fl->data[i-2];
if ((ppt.type==TOKEN_TYPE_VAR)) {
long int posTok = i-2;
deleteRange(fl,i-1,i);
char * ____BAH_COMPILER_VAR_883 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(ppt.cont);
unsigned int strLen_2 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_883 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_883+currStrOff, t.cont, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_883+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_883+currStrOff, ppt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }ppt.cont = ____BAH_COMPILER_VAR_883;
ppt.isValue = true;
ppt.isOper = true;

    {
        unsigned long nLength = posTok;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[posTok] = ppt;
            fl->length = nLength+1;
        } else {
            fl->data[posTok] = ppt;
        }
    }
    ;
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
char * ____BAH_COMPILER_VAR_884 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(t.cont);
;                            
            ____BAH_COMPILER_VAR_884 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_884+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_884+currStrOff, t.cont, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_884;

    {
        unsigned long nLength = i-1;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[i-1] = pt;
            fl->length = nLength+1;
        } else {
            fl->data[i-1] = pt;
        }
    }
    ;
--i;
}
}
else if (inArrayStr(pt.cont,comparators)&&isValue(fl,i)) {
i = valueBool(fl,i,ltp,elems)-1;
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
for (; (i<len(fl)); ++i) {
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
char * ____BAH_COMPILER_VAR_885 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ptt);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Cannot use {TOKEN} on ");
;                            
            ____BAH_COMPILER_VAR_885 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_885+currStrOff, "Cannot use {TOKEN} on ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_885+currStrOff, ptt, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_885+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&t,____BAH_COMPILER_VAR_885);
}
char * ____BAH_COMPILER_VAR_886 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.cont);
unsigned int strLen_1 = strlen(nt.cont);
;                            
            ____BAH_COMPILER_VAR_886 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_886+currStrOff, t.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_886+currStrOff, nt.cont, strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_887 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(pt.cont);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_886);
;                            
            ____BAH_COMPILER_VAR_887 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_887+currStrOff, pt.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_887+currStrOff, ____BAH_COMPILER_VAR_886, strLen_1);
            currStrOff += strLen_1;
        
        }pt.cont = ____BAH_COMPILER_VAR_887;

    {
        unsigned long nLength = i-1;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[i-1] = pt;
            fl->length = nLength+1;
        } else {
            fl->data[i-1] = pt;
        }
    }
    ;
deleteRange(fl,i,i+1);
i = i-2;
}
else if ((t.type==TOKEN_TYPE_VAR)&&(strcmp(t.bahType, "") != 0)) {
if ((t.cont[0]==38)) {
char * ____BAH_COMPILER_VAR_888 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t.bahType);
unsigned int strLen_1 = strlen("*");
;                            
            ____BAH_COMPILER_VAR_888 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_888+currStrOff, t.bahType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_888+currStrOff, "*", strLen_1);
            currStrOff += strLen_1;
        
        }t.bahType = ____BAH_COMPILER_VAR_888;

    {
        unsigned long nLength = i;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[i] = t;
            fl->length = nLength+1;
        } else {
            fl->data[i] = t;
        }
    }
    ;
}
else if ((t.cont[0]==42)) {
struct string tt = string(t.bahType);
string__replace(&tt,"*","");
t.bahType = string__str(&tt);

    {
        unsigned long nLength = i;
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[i] = t;
            fl->length = nLength+1;
        } else {
            fl->data[i] = t;
        }
    }
    ;
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
        unsigned long nLength = len(fl);
        if (nLength >= fl->length) {
            if (nLength >= fl->realLength) {
                if (fl->realLength != 0) {
                    fl->realLength *= 2;
                } else {
                    fl->realLength = 50;
                }
                void * newPtr = memoryRealloc(fl->data, (fl->realLength)*sizeof(struct Tok));
                fl->data = newPtr;
            }
            fl->data[len(fl)] = line->data[sepI];
            fl->length = nLength+1;
        } else {
            fl->data[len(fl)] = line->data[sepI];
        }
    }
    ;
++sepI;
};
}
return fl;

#undef pt
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i = 0;
struct func* ____BAH_COMPILER_VAR_889 = memoryAlloc(sizeof(struct func));
____BAH_COMPILER_VAR_889->name = "";
____BAH_COMPILER_VAR_889->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_889->args->length = 0;
            ____BAH_COMPILER_VAR_889->args->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_889->returns= null;
____BAH_COMPILER_VAR_889->isBinding = false;
____BAH_COMPILER_VAR_889->from = "";
____BAH_COMPILER_VAR_889->file = "";
____BAH_COMPILER_VAR_889->line = 1;
____BAH_COMPILER_VAR_889->isVar = false;
____BAH_COMPILER_VAR_889->used = false;
____BAH_COMPILER_VAR_889->code = null;
____BAH_COMPILER_VAR_889->isMut = false;
____BAH_COMPILER_VAR_889->isImported = false;
struct func* fn = ____BAH_COMPILER_VAR_889;
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
char * ____BAH_COMPILER_VAR_890 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(lineStr);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen(":");
unsigned int strLen_3 = strlen(ogFn->file);
unsigned int strLen_4 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
;                            
            ____BAH_COMPILER_VAR_890 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_890+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_890+currStrOff, ogFn->file, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_890+currStrOff, ":", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_890+currStrOff, lineStr, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_890+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&ft,____BAH_COMPILER_VAR_890);
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
if ((debug==true)) {
struct debugFunction* ____BAH_COMPILER_VAR_891 = memoryAlloc(sizeof(struct debugFunction));
____BAH_COMPILER_VAR_891->name= null;
____BAH_COMPILER_VAR_891->returns= null;
____BAH_COMPILER_VAR_891->args = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_891->args->length = 0;
            ____BAH_COMPILER_VAR_891->args->elemSize = sizeof(struct variable*);
            struct debugFunction* df = ____BAH_COMPILER_VAR_891;
df->name = fn->name;
df->args = fn->args;
df->returns = fn->returns->type;
struct debugFunction* ____BAH_COMPILER_VAR_892 = df;
char ** ____BAH_COMPILER_VAR_894 = (char **)((char*)(____BAH_COMPILER_VAR_892) + offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_895 = __reflect(____BAH_COMPILER_VAR_894, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
char ** ____BAH_COMPILER_VAR_896 = (char **)((char*)(____BAH_COMPILER_VAR_892) + offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_897 = __reflect(____BAH_COMPILER_VAR_896, sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
array(struct variable*)** ____BAH_COMPILER_VAR_898 = (array(struct variable*)**)((char*)(____BAH_COMPILER_VAR_892) + offsetof(struct debugFunction, args));
struct variable** ____BAH_COMPILER_VAR_899 = 0;
char ** ____BAH_COMPILER_VAR_901 = (char **)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_902 = __reflect(____BAH_COMPILER_VAR_901, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
char ** ____BAH_COMPILER_VAR_903 = (char **)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_904 = __reflect(____BAH_COMPILER_VAR_903, sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
char* ____BAH_COMPILER_VAR_905 = (char*)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_906 = __reflect(____BAH_COMPILER_VAR_905, sizeof(char), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
char ** ____BAH_COMPILER_VAR_907 = (char **)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_908 = __reflect(____BAH_COMPILER_VAR_907, sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
char* ____BAH_COMPILER_VAR_909 = (char*)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_910 = __reflect(____BAH_COMPILER_VAR_909, sizeof(char), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
char ** ____BAH_COMPILER_VAR_911 = (char **)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_912 = __reflect(____BAH_COMPILER_VAR_911, sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
void ** ____BAH_COMPILER_VAR_913 = (void **)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, declScope));
struct reflectElement ____BAH_COMPILER_VAR_914 = __reflect(____BAH_COMPILER_VAR_913, sizeof(void *), "ptr", "declScope", 0, 0, 0, 0, offsetof(struct variable, declScope));
char* ____BAH_COMPILER_VAR_915 = (char*)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, isGlobal));
struct reflectElement ____BAH_COMPILER_VAR_916 = __reflect(____BAH_COMPILER_VAR_915, sizeof(char), "bool", "isGlobal", 0, 0, 0, 0, offsetof(struct variable, isGlobal));
struct rope** ____BAH_COMPILER_VAR_917 = (struct rope**)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, declRope));
void ** ____BAH_COMPILER_VAR_919 = (void **)((char*)(____BAH_COMPILER_VAR_917) + offsetof(struct rope, left));
struct reflectElement ____BAH_COMPILER_VAR_920 = __reflect(____BAH_COMPILER_VAR_919, sizeof(void *), "ptr", "left", 0, 0, 0, 0, offsetof(struct rope, left));
void ** ____BAH_COMPILER_VAR_921 = (void **)((char*)(____BAH_COMPILER_VAR_917) + offsetof(struct rope, right));
struct reflectElement ____BAH_COMPILER_VAR_922 = __reflect(____BAH_COMPILER_VAR_921, sizeof(void *), "ptr", "right", 0, 0, 0, 0, offsetof(struct rope, right));
char ** ____BAH_COMPILER_VAR_923 = (char **)((char*)(____BAH_COMPILER_VAR_917) + offsetof(struct rope, str));
struct reflectElement ____BAH_COMPILER_VAR_924 = __reflect(____BAH_COMPILER_VAR_923, sizeof(char *), "cpstring", "str", 0, 0, 0, 0, offsetof(struct rope, str));
int* ____BAH_COMPILER_VAR_925 = (int*)((char*)(____BAH_COMPILER_VAR_917) + offsetof(struct rope, lCount));
struct reflectElement ____BAH_COMPILER_VAR_926 = __reflect(____BAH_COMPILER_VAR_925, sizeof(int), "int32", "lCount", 0, 0, 0, 0, offsetof(struct rope, lCount));
int* ____BAH_COMPILER_VAR_927 = (int*)((char*)(____BAH_COMPILER_VAR_917) + offsetof(struct rope, len));
struct reflectElement ____BAH_COMPILER_VAR_928 = __reflect(____BAH_COMPILER_VAR_927, sizeof(int), "int32", "len", 0, 0, 0, 0, offsetof(struct rope, len));
int* ____BAH_COMPILER_VAR_929 = (int*)((char*)(____BAH_COMPILER_VAR_917) + offsetof(struct rope, totalLen));
struct reflectElement ____BAH_COMPILER_VAR_930 = __reflect(____BAH_COMPILER_VAR_929, sizeof(int), "int32", "totalLen", 0, 0, 0, 0, offsetof(struct rope, totalLen));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_918 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_918->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_918->length = 6;
        ____BAH_COMPILER_VAR_918->data = memoryAlloc(____BAH_COMPILER_VAR_918->length * ____BAH_COMPILER_VAR_918->elemSize);
        ____BAH_COMPILER_VAR_918->data[0] = ____BAH_COMPILER_VAR_920;
____BAH_COMPILER_VAR_918->data[1] = ____BAH_COMPILER_VAR_922;
____BAH_COMPILER_VAR_918->data[2] = ____BAH_COMPILER_VAR_924;
____BAH_COMPILER_VAR_918->data[3] = ____BAH_COMPILER_VAR_926;
____BAH_COMPILER_VAR_918->data[4] = ____BAH_COMPILER_VAR_928;
____BAH_COMPILER_VAR_918->data[5] = ____BAH_COMPILER_VAR_930;
struct reflectElement ____BAH_COMPILER_VAR_931 = __reflect(____BAH_COMPILER_VAR_917, sizeof(struct rope), "rope*", "declRope", 0, 0, 1, ____BAH_COMPILER_VAR_918, offsetof(struct variable, declRope));
char* ____BAH_COMPILER_VAR_932 = (char*)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, canBeReg));
struct reflectElement ____BAH_COMPILER_VAR_933 = __reflect(____BAH_COMPILER_VAR_932, sizeof(char), "bool", "canBeReg", 0, 0, 0, 0, offsetof(struct variable, canBeReg));
char* ____BAH_COMPILER_VAR_934 = (char*)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, isReg));
struct reflectElement ____BAH_COMPILER_VAR_935 = __reflect(____BAH_COMPILER_VAR_934, sizeof(char), "bool", "isReg", 0, 0, 0, 0, offsetof(struct variable, isReg));
void ** ____BAH_COMPILER_VAR_936 = (void **)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, lastSet));
struct reflectElement ____BAH_COMPILER_VAR_937 = __reflect(____BAH_COMPILER_VAR_936, sizeof(void *), "ptr", "lastSet", 0, 0, 0, 0, offsetof(struct variable, lastSet));
char* ____BAH_COMPILER_VAR_938 = (char*)((char*)(____BAH_COMPILER_VAR_899) + offsetof(struct variable, isArg));
struct reflectElement ____BAH_COMPILER_VAR_939 = __reflect(____BAH_COMPILER_VAR_938, sizeof(char), "bool", "isArg", 0, 0, 0, 0, offsetof(struct variable, isArg));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_900 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_900->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_900->length = 13;
        ____BAH_COMPILER_VAR_900->data = memoryAlloc(____BAH_COMPILER_VAR_900->length * ____BAH_COMPILER_VAR_900->elemSize);
        ____BAH_COMPILER_VAR_900->data[0] = ____BAH_COMPILER_VAR_902;
____BAH_COMPILER_VAR_900->data[1] = ____BAH_COMPILER_VAR_904;
____BAH_COMPILER_VAR_900->data[2] = ____BAH_COMPILER_VAR_906;
____BAH_COMPILER_VAR_900->data[3] = ____BAH_COMPILER_VAR_908;
____BAH_COMPILER_VAR_900->data[4] = ____BAH_COMPILER_VAR_910;
____BAH_COMPILER_VAR_900->data[5] = ____BAH_COMPILER_VAR_912;
____BAH_COMPILER_VAR_900->data[6] = ____BAH_COMPILER_VAR_914;
____BAH_COMPILER_VAR_900->data[7] = ____BAH_COMPILER_VAR_916;
____BAH_COMPILER_VAR_900->data[8] = ____BAH_COMPILER_VAR_931;
____BAH_COMPILER_VAR_900->data[9] = ____BAH_COMPILER_VAR_933;
____BAH_COMPILER_VAR_900->data[10] = ____BAH_COMPILER_VAR_935;
____BAH_COMPILER_VAR_900->data[11] = ____BAH_COMPILER_VAR_937;
____BAH_COMPILER_VAR_900->data[12] = ____BAH_COMPILER_VAR_939;
struct reflectElement ____BAH_COMPILER_VAR_940 = __reflect(____BAH_COMPILER_VAR_899, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_900, 0);

        struct reflectElement ____BAH_COMPILER_VAR_941 = ____BAH_COMPILER_VAR_940;
        struct reflectElement ____BAH_COMPILER_VAR_942 = __reflect(____BAH_COMPILER_VAR_898, sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_941, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_893 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_893->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_893->length = 3;
        ____BAH_COMPILER_VAR_893->data = memoryAlloc(____BAH_COMPILER_VAR_893->length * ____BAH_COMPILER_VAR_893->elemSize);
        ____BAH_COMPILER_VAR_893->data[0] = ____BAH_COMPILER_VAR_895;
____BAH_COMPILER_VAR_893->data[1] = ____BAH_COMPILER_VAR_897;
____BAH_COMPILER_VAR_893->data[2] = ____BAH_COMPILER_VAR_942;
struct reflectElement ____BAH_COMPILER_VAR_943 = __reflect(____BAH_COMPILER_VAR_892, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_893, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_943);
}
if ((shouldOnlyDecl==true)) {
if ((ogFn!=null)) {
fn->isBinding = false;
}
fn->isImported = true;

    {
        unsigned long nLength = len(elems->fns);
        if (nLength >= elems->fns->length) {
            if (nLength >= elems->fns->realLength) {
                if (elems->fns->realLength != 0) {
                    elems->fns->realLength *= 2;
                } else {
                    elems->fns->realLength = 50;
                }
                void * newPtr = memoryRealloc(elems->fns->data, (elems->fns->realLength)*sizeof(struct func*));
                elems->fns->data = newPtr;
            }
            elems->fns->data[len(elems->fns)] = fn;
            elems->fns->length = nLength+1;
        } else {
            elems->fns->data[len(elems->fns)] = fn;
        }
    }
    ;
char * ____BAH_COMPILER_VAR_944 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_944 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_944+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_944+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_944));
return;
}
char * ____BAH_COMPILER_VAR_945 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(code);
unsigned int strLen_1 = strlen("{\n");
;                            
            ____BAH_COMPILER_VAR_945 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_945+currStrOff, code, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_945+currStrOff, "{\n", strLen_1);
            currStrOff += strLen_1;
        
        }code = ____BAH_COMPILER_VAR_945;
fn->code = rope(code);
struct Elems* fnElems = dupElems(elems);
array(struct variable*)* vs = fnElems->vars;
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* a = fn->args->data[j];
a->declScope = elems;
a->isArg = true;

    {
        unsigned long nLength = len(vs);
        if (nLength >= vs->length) {
            if (nLength >= vs->realLength) {
                if (vs->realLength != 0) {
                    vs->realLength *= 2;
                } else {
                    vs->realLength = 50;
                }
                void * newPtr = memoryRealloc(vs->data, (vs->realLength)*sizeof(struct variable*));
                vs->data = newPtr;
            }
            vs->data[len(vs)] = a;
            vs->length = nLength+1;
        } else {
            vs->data[len(vs)] = a;
        }
    }
    ;
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
        unsigned long nLength = len(fns);
        if (nLength >= fns->length) {
            if (nLength >= fns->realLength) {
                if (fns->realLength != 0) {
                    fns->realLength *= 2;
                } else {
                    fns->realLength = 50;
                }
                void * newPtr = memoryRealloc(fns->data, (fns->realLength)*sizeof(struct func*));
                fns->data = newPtr;
            }
            fns->data[len(fns)] = fn;
            fns->length = nLength+1;
        } else {
            fns->data[len(fns)] = fn;
        }
    }
    ;
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
++i;
long int max = len(l)-1;
while ((i<max)) {
struct Tok t = l->data[i];

    {
        unsigned long nLength = len(tokens);
        if (nLength >= tokens->length) {
            if (nLength >= tokens->realLength) {
                if (tokens->realLength != 0) {
                    tokens->realLength *= 2;
                } else {
                    tokens->realLength = 50;
                }
                void * newPtr = memoryRealloc(tokens->data, (tokens->realLength)*sizeof(struct Tok));
                tokens->data = newPtr;
            }
            tokens->data[len(tokens)] = t;
            tokens->length = nLength+1;
        } else {
            tokens->data[len(tokens)] = t;
        }
    }
    ;
++i;
};
if ((len(tokens)==0)) {
fn->code = rope__add(fn->code, rope("};\n"));
OUTPUT = rope__add(OUTPUT, fn->code);
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
OPTI_checkFuncScopeRef(fnElems);
compilerState.currFnElems = ocurrFnElems;
currentFn = null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_946 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen("' is not returned.");
unsigned int strLen_2 = strlen("Function '");
;                            
            ____BAH_COMPILER_VAR_946 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_946+currStrOff, "Function '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_946+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_946+currStrOff, "' is not returned.", strLen_1);
            currStrOff += strLen_1;
        
        }throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_946);
}
endRCPscope(fnElems,fn->args);
}
else {
removeDefs(fnElems);
}
fn->code = rope__add(fn->code, OUTPUT);
OUTPUT = oOut;
fn->code = rope__add(fn->code, rope("};\n"));
if ((debug==true)) {
struct Tok lt = l->data[len(l)-1];
debugEndScope(lt.line,fnElems);
}
OUTPUT = rope__add(OUTPUT, fn->code);
};
void parseLine(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
if ((len(line)==0)) {
return;
}
line = parsePointers(line,elems);
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
struct func* fn = searchFuncByToken(&ft,elems);
if ((fn!=null)&&(fn->returns!=null)&&isRCPtype(fn->returns->type,elems)) {
char * ____BAH_COMPILER_VAR_947 =registerRCPvar(fn->returns->type,ft.cont,elems);return;
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
char * ____BAH_COMPILER_VAR_948 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(ft.cont);
unsigned int strLen_1 = strlen(";\n");
;                            
            ____BAH_COMPILER_VAR_948 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_948+currStrOff, ft.cont, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_948+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_948));
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
OUTPUT = rope__add(OUTPUT, rope(NEXT_LINE));
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
unsigned int currentLine = ft.line;
long int nbEncl = 0;
register long int i = 0;
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
        unsigned long nLength = len(line);
        if (nLength >= line->length) {
            if (nLength >= line->realLength) {
                if (line->realLength != 0) {
                    line->realLength *= 2;
                } else {
                    line->realLength = 50;
                }
                void * newPtr = memoryRealloc(line->data, (line->realLength)*sizeof(struct Tok));
                line->data = newPtr;
            }
            line->data[len(line)] = t;
            line->length = nLength+1;
        } else {
            line->data[len(line)] = t;
        }
    }
    ;
struct Tok pt = tokens->data[i-1];
currentLine = pt.line;
}
else {
currentLine = t.line;
}
parseLine(line,elems);
clear(line);
if ((t.type==TOKEN_TYPE_ENCL)) {
++i;
continue;
}
}
else if ((strcmp(t.cont, ";") == 0)) {
currentLine = t.line;
parseLine(line,elems);
clear(line);
++i;
continue;
}
}

    {
        unsigned long nLength = len(line);
        if (nLength >= line->length) {
            if (nLength >= line->realLength) {
                if (line->realLength != 0) {
                    line->realLength *= 2;
                } else {
                    line->realLength = 50;
                }
                void * newPtr = memoryRealloc(line->data, (line->realLength)*sizeof(struct Tok));
                line->data = newPtr;
            }
            line->data[len(line)] = t;
            line->length = nLength+1;
        } else {
            line->data[len(line)] = t;
        }
    }
    ;
++i;
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
register long int j = 0;
while ((j<len(fn->args))) {
struct variable* arg = fn->args->data[j];
struct string ct = getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_949 =null;char * ____BAH_COMPILER_VAR_950 =string__str(&ct);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" ");
unsigned int strLen_1 = strlen(arg->name);
unsigned int strLen_2 = strlen(____BAH_COMPILER_VAR_950);
unsigned int strLen_3 = strlen(tmpfnArgsCType);
;                            
            ____BAH_COMPILER_VAR_949 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_949+currStrOff, tmpfnArgsCType, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_949+currStrOff, ____BAH_COMPILER_VAR_950, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_949+currStrOff, " ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_949+currStrOff, arg->name, strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_949;
j = j+1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_951 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(", ");
;                            
            ____BAH_COMPILER_VAR_951 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_951+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_951+currStrOff, ", ", strLen_1);
            currStrOff += strLen_1;
        
        }tmpfnArgsCType = ____BAH_COMPILER_VAR_951;
}
};
char * ____BAH_COMPILER_VAR_952 =null;char * ____BAH_COMPILER_VAR_953 =string__str(&tmpfnRetCType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(tmpfnArgsCType);
unsigned int strLen_1 = strlen(");\n");
unsigned int strLen_2 = strlen("(");
unsigned int strLen_3 = strlen(fn->name);
unsigned int strLen_4 = strlen(" ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_953);
;                            
            ____BAH_COMPILER_VAR_952 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5);
            
                    memcpy(____BAH_COMPILER_VAR_952+currStrOff, ____BAH_COMPILER_VAR_953, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_952+currStrOff, " ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_952+currStrOff, fn->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_952+currStrOff, "(", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_952+currStrOff, tmpfnArgsCType, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_952+currStrOff, ");\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_952));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_954 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->constVal);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(v->name);
unsigned int strLen_4 = strlen("#define ");
;                            
            ____BAH_COMPILER_VAR_954 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_954+currStrOff, "#define ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_954+currStrOff, v->name, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_954+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_954+currStrOff, v->constVal, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_954+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_954));
}
else {
struct string cType = getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_955 =null;char * ____BAH_COMPILER_VAR_956 =string__str(&cType);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(v->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_956);
;                            
            ____BAH_COMPILER_VAR_955 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_955+currStrOff, ____BAH_COMPILER_VAR_956, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_955+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_955+currStrOff, v->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_955+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_955));
}
};
void declareAll(struct Elems* elems){
OUTPUT = rope("\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\ntypedef array(char*)* __BAH_ARR_TYPE_cpstring;\nlong int __BAH__main(__BAH_ARR_TYPE_cpstring);\n");
register long int i = 0;
for (; (i<len(compilerState.cIncludes)); ++i) {
char * ____BAH_COMPILER_VAR_957 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(compilerState.cIncludes->data[i]);
unsigned int strLen_1 = strlen("\n");
unsigned int strLen_2 = strlen("#include ");
;                            
            ____BAH_COMPILER_VAR_957 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_957+currStrOff, "#include ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_957+currStrOff, compilerState.cIncludes->data[i], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_957+currStrOff, "\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_957));
};
i = 1;
for (; (i<len(compilerState.arrTypesDecl)); ++i) {
char * t = compilerState.arrTypesDecl->data[i];
struct string elemType = string(t);
string__trimLeft(&elemType,15);
char * ____BAH_COMPILER_VAR_958 =string__str(&elemType);struct string elemCtype = getCType(____BAH_COMPILER_VAR_958,elems);
char * ____BAH_COMPILER_VAR_959 =null;char * ____BAH_COMPILER_VAR_960 =string__str(&elemCtype);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(t);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen(")* ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_960);
unsigned int strLen_4 = strlen("typedef array(");
;                            
            ____BAH_COMPILER_VAR_959 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4);
            
                    memcpy(____BAH_COMPILER_VAR_959+currStrOff, "typedef array(", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_959+currStrOff, ____BAH_COMPILER_VAR_960, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_959+currStrOff, ")* ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_959+currStrOff, t, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_959+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_959));
};
i = 0;
for (; (i<len(elems->vars)); ++i) {
struct variable* v = elems->vars->data[i];
declareVar(v,elems);
};
i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
declareFunc(fn,elems);
};
};
char * memErrHandle(){
char * ____BAH_COMPILER_VAR_961 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("file: ");
unsigned int strLen_1 = strlen(compilerState.currentFile);
;                            
            ____BAH_COMPILER_VAR_961 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_961+currStrOff, "file: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_961+currStrOff, compilerState.currentFile, strLen_1);
            currStrOff += strLen_1;
        
        }char * r = ____BAH_COMPILER_VAR_961;
if ((currentFn!=null)) {
char * ____BAH_COMPILER_VAR_962 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(currentFn->name);
unsigned int strLen_1 = strlen("()");
unsigned int strLen_2 = strlen("\nfunction: ");
;                            
            ____BAH_COMPILER_VAR_962 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_962+currStrOff, "\nfunction: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_962+currStrOff, currentFn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_962+currStrOff, "()", strLen_1);
            currStrOff += strLen_1;
        
        }char * ____BAH_COMPILER_VAR_963 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(r);
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_962);
;                            
            ____BAH_COMPILER_VAR_963 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_963+currStrOff, r, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_963+currStrOff, ____BAH_COMPILER_VAR_962, strLen_1);
            currStrOff += strLen_1;
        
        }r = ____BAH_COMPILER_VAR_963;
}
return r;
};
long int main(__BAH_ARR_TYPE_cpstring args){
onMemoryError = memErrHandle;
execName = args->data[0];
if ((execName[0]==46)||(execName[0]==47)) {
execName = absPath(execName);
}
struct flags ____BAH_COMPILER_VAR_964 = {};
____BAH_COMPILER_VAR_964.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_964.flags->length = 0;
            ____BAH_COMPILER_VAR_964.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_964.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_964.args->length = 0;
            ____BAH_COMPILER_VAR_964.args->elemSize = sizeof(char *);
            flags = ____BAH_COMPILER_VAR_964;
flags__addString(&flags,"o","Name of the file to output.");
flags__addBool(&flags,"c","Translate bah file to C instead of compiling it.");
flags__addBool(&flags,"v","Show version of the compiler.");
flags__addBool(&flags,"l","Compile as a library.");
flags__addBool(&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");
flags__addBool(&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");
flags__addBool(&flags,"debug","Enables verbose json output.");
flags__addBool(&flags,"verboseRuntime","Enables verbose runtime, a debug mode of the compiled program. (obsolete)");
flags__addBool(&flags,"verboseCC","Enables verbose C compiler output, USE IN LAST RESORT.");
char * ____BAH_COMPILER_VAR_965 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_OS);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("Select the target OS for cross compilling (linux, windows, darwin), default: ");
;                            
            ____BAH_COMPILER_VAR_965 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_965+currStrOff, "Select the target OS for cross compilling (linux, windows, darwin), default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_965+currStrOff, BAH_OS, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_965+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags__addString(&flags,"target",____BAH_COMPILER_VAR_965);
char * ____BAH_COMPILER_VAR_966 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen(").");
unsigned int strLen_2 = strlen("If your Bah directory is not the default one (");
;                            
            ____BAH_COMPILER_VAR_966 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_966+currStrOff, "If your Bah directory is not the default one (", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_966+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_966+currStrOff, ").", strLen_1);
            currStrOff += strLen_1;
        
        }flags__addString(&flags,"bahDir",____BAH_COMPILER_VAR_966);
char * ____BAH_COMPILER_VAR_967 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_CC);
unsigned int strLen_1 = strlen(".");
unsigned int strLen_2 = strlen("To change the C compiler used, default: ");
;                            
            ____BAH_COMPILER_VAR_967 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_967+currStrOff, "To change the C compiler used, default: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_967+currStrOff, BAH_CC, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_967+currStrOff, ".", strLen_1);
            currStrOff += strLen_1;
        
        }flags__addString(&flags,"CC",____BAH_COMPILER_VAR_967);
flags__addBool(&flags,"object","Compile as an object.");
flags__addBool(&flags,"unsafe","Compile without safety checking. This will make for faster executable but if your program crashes, it will show less informations.");
flags__addBool(&flags,"nobuiltin","Does not include the builtin library (be really carefull, your program WILL break).");
flags__addBool(&flags,"optimize","Includes optimized functions");
flags__parse(&flags,args);
if ((flags__isSet(&flags,"target")==1)) {
BAH_OS = flags__get(&flags,"target");
char * ____BAH_COMPILER_VAR_968 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("Build target: ");
unsigned int strLen_1 = strlen(BAH_OS);
;                            
            ____BAH_COMPILER_VAR_968 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_968+currStrOff, "Build target: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_968+currStrOff, BAH_OS, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_968);
}
if ((flags__isSet(&flags,"bahDir")==1)) {
BAH_DIR = flags__get(&flags,"bahDir");
array(char)* bahDirArr = strAsArr(BAH_DIR);
if ((bahDirArr->data[len(bahDirArr)-1]!=47)) {
char * ____BAH_COMPILER_VAR_969 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("/");
;                            
            ____BAH_COMPILER_VAR_969 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_969+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_969+currStrOff, "/", strLen_1);
            currStrOff += strLen_1;
        
        }BAH_DIR = ____BAH_COMPILER_VAR_969;
}
char * ____BAH_COMPILER_VAR_970 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("Bah directory: ");
unsigned int strLen_1 = strlen(BAH_DIR);
;                            
            ____BAH_COMPILER_VAR_970 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_970+currStrOff, "Bah directory: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_970+currStrOff, BAH_DIR, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_970);
}
if ((flags__isSet(&flags,"CC")==1)) {
BAH_CC = flags__get(&flags,"CC");
char * ____BAH_COMPILER_VAR_971 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen("C compiler: ");
unsigned int strLen_1 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_971 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_971+currStrOff, "C compiler: ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_971+currStrOff, BAH_CC, strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_971);
}
if (flags__isSet(&flags,"verboseRuntime")) {
println("-verboseRuntime is obsolete.");
exit(1);
}
RCPlevel = 0;
if (flags__isSet(&flags,"rcp")) {
RCPlevel = 1;
}
else if (flags__isSet(&flags,"fastrcp")) {
RCPlevel = 2;
}
verboseRuntime = (flags__isSet(&flags,"verboseRuntime")==1);
debug = (flags__isSet(&flags,"debug")==1);
isObject = (flags__isSet(&flags,"object")==1);
isUnsafe = (flags__isSet(&flags,"unsafe")==1);
isOptimized = (flags__isSet(&flags,"optimize")==1);
if ((debug==true)) {
debugStart();
}
RCPenabled = (flags__isSet(&flags,"rcp")==1)||flags__isSet(&flags,"fastrcp");
if ((flags__isSet(&flags,"v")==1)) {
char * ____BAH_COMPILER_VAR_972 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_VERSION);
unsigned int strLen_1 = strlen(".\n© Alois Laurent Boe");
unsigned int strLen_2 = strlen("Bah compiler version: ");
;                            
            ____BAH_COMPILER_VAR_972 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_972+currStrOff, "Bah compiler version: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_972+currStrOff, BAH_VERSION, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_972+currStrOff, ".\n© Alois Laurent Boe", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_972);
return 0;
}
if ((flags__isSet(&flags,"c")==1)&&(flags__isSet(&flags,"l")==1)) {
__BAH_panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.","/home/alois/Documents/bah-bah/src/main.bah:139");
}
INIT = rope("");
OUTPUT = rope("\n    void __BAH_init();\n    #define noCheck(v) v\n    #define array(type)	\
    struct{	\
    type *data; \
    long int length; \
    long int realLength; \
    long int elemSize; \
    }\n    typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n    long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n    ");
if ((flags__isSet(&flags,"l")==0)) {
if ((RCPenabled==true)) {
OUTPUT = rope__add(OUTPUT, rope("\n            void RCP_init();\n            void RCP_shutdown();\n            void free(void*);\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            RCP_init();\n            array(char*) * args = malloc(sizeof(array(char*)));\n            args->data = malloc(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            free(args->data);\n            free(args);\n            RCP_shutdown();\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
else {
OUTPUT = rope__add(OUTPUT, rope("\n            #include <gc.h>\n            #include <string.h>\n            int main(int argc, char ** argv) {\n            GC_INIT();\n            array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n            args->data = GC_MALLOC(sizeof(char*)*argc);\n            memcpy(args->data, argv, sizeof(char*)*argc);\n            args->elemSize = sizeof(char*);\n            args->length = argc;\n            __BAH_init();\n            long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n            GC_FREE(args->data);\n            GC_FREE(args);\n            return r;\n            };\n            #define main(v) __BAH__main(v)\n            "));
}
}
struct compilerStateTag ____BAH_COMPILER_VAR_973 = {};
____BAH_COMPILER_VAR_973.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_973.includes->length = 0;
            ____BAH_COMPILER_VAR_973.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_973.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_973.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_973.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_973.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_973.cLibs->length = 0;
            ____BAH_COMPILER_VAR_973.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_973.currentFile= null;
____BAH_COMPILER_VAR_973.currentDir = "./";
____BAH_COMPILER_VAR_973.isBranch = false;
____BAH_COMPILER_VAR_973.isFor = false;
____BAH_COMPILER_VAR_973.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_973.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_973.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_973.haveEntryPoint = false;
____BAH_COMPILER_VAR_973.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_973.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_973.RCPvars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_973.evals = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_973.evals->length = 0;
            ____BAH_COMPILER_VAR_973.evals->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_973.hasImports = false;
____BAH_COMPILER_VAR_973.currForElems= null;
____BAH_COMPILER_VAR_973.currFnElems= null;
compilerState = ____BAH_COMPILER_VAR_973;

    {
        unsigned long nLength = 0;
        if (nLength >= compilerState.arrTypesDecl->length) {
            if (nLength >= compilerState.arrTypesDecl->realLength) {
                if (compilerState.arrTypesDecl->realLength != 0) {
                    compilerState.arrTypesDecl->realLength *= 2;
                } else {
                    compilerState.arrTypesDecl->realLength = 50;
                }
                void * newPtr = memoryRealloc(compilerState.arrTypesDecl->data, (compilerState.arrTypesDecl->realLength)*sizeof(char *));
                compilerState.arrTypesDecl->data = newPtr;
            }
            compilerState.arrTypesDecl->data[0] = "__BAH_ARR_TYPE_cpstring";
            compilerState.arrTypesDecl->length = nLength+1;
        } else {
            compilerState.arrTypesDecl->data[0] = "__BAH_ARR_TYPE_cpstring";
        }
    }
    ;
char * fileName = absPath(args->data[1]);
compilerState.currentFile = fileName;
struct fileMap ____BAH_COMPILER_VAR_974 = {};
____BAH_COMPILER_VAR_974.handle = -1;
____BAH_COMPILER_VAR_974.p= null;
#define fm ____BAH_COMPILER_VAR_974
char * f = fileMap__open(&fm,fileName);
if ((fileMap__isValid(&fm)==0)||(fm.size==0)) {
char * ____BAH_COMPILER_VAR_975 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(args->data[1]);
unsigned int strLen_1 = strlen("'.");
unsigned int strLen_2 = strlen("Could not open file '");
;                            
            ____BAH_COMPILER_VAR_975 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_975+currStrOff, "Could not open file '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_975+currStrOff, args->data[1], strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_975+currStrOff, "'.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_975);
exit(1);
}
long int startTime = getTimeUnix();
array(struct Tok)* tokens = lexer(f);
fileMap__close(&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_976 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fileName);
unsigned int strLen_1 = strlen("' not recognized.");
unsigned int strLen_2 = strlen("File '");
;                            
            ____BAH_COMPILER_VAR_976 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_976+currStrOff, "File '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_976+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_976+currStrOff, "' not recognized.", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_976);
exit(1);
}
struct Elems* ____BAH_COMPILER_VAR_977 = memoryAlloc(sizeof(struct Elems));
____BAH_COMPILER_VAR_977->vars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_977->vars->length = 0;
            ____BAH_COMPILER_VAR_977->vars->elemSize = sizeof(struct variable*);
            ____BAH_COMPILER_VAR_977->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            ____BAH_COMPILER_VAR_977->structs->length = 0;
            ____BAH_COMPILER_VAR_977->structs->elemSize = sizeof(struct cStruct*);
            ____BAH_COMPILER_VAR_977->types = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_977->types->length = 0;
            ____BAH_COMPILER_VAR_977->types->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_977->fns = memoryAlloc(sizeof(array(struct func*)));
            ____BAH_COMPILER_VAR_977->fns->length = 0;
            ____BAH_COMPILER_VAR_977->fns->elemSize = sizeof(struct func*);
            ____BAH_COMPILER_VAR_977->defined = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_977->defined->length = 0;
            ____BAH_COMPILER_VAR_977->defined->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_977->parent= null;
struct Elems* elems = ____BAH_COMPILER_VAR_977;
if ((isObject==true)) {
OUTPUT = rope("\n        #define noCheck(v) v\n        #define array(type)	\
        struct{	\
        type *data; \
        long int length; \
        long int realLength; \
        long int elemSize; \
        }\n        typedef array(char*)* __BAH_ARR_TYPE_cpstring;\n        long int __BAH__main(__BAH_ARR_TYPE_cpstring);\n        ");
shouldOnlyDecl = true;
}

                struct string ____BAH_COMPILER_VAR_978 = string(fileName);
                if ((flags__isSet(&flags,"nobuiltin")==0)&&(string__hasSuffix(&____BAH_COMPILER_VAR_978,".bahstrp")==false)) {
if ((includeFile("builtin.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_979 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(BAH_DIR);
unsigned int strLen_1 = strlen("'");
unsigned int strLen_2 = strlen("Could not find std-libs, please check '");
;                            
            ____BAH_COMPILER_VAR_979 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_979+currStrOff, "Could not find std-libs, please check '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_979+currStrOff, BAH_DIR, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_979+currStrOff, "'", strLen_1);
            currStrOff += strLen_1;
        
        }__BAH_panic(____BAH_COMPILER_VAR_979,"/home/alois/Documents/bah-bah/src/main.bah:250");
}
}
shouldOnlyDecl = false;
if ((flags__isSet(&flags,"l")==1)) {
OUTPUT = rope("");
declareAll(elems);
}
compilerState.currentDir = getDirFromFile(fileName);
parseLines(tokens,elems);
if ((isObject==false)&&(isUnsafe==false)) {
long int l = 0;
register long int i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
++l;
};
char * ____BAH_COMPILER_VAR_980 =null;char * ____BAH_COMPILER_VAR_981 =intToStr(l);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_981);
unsigned int strLen_1 = strlen("];");
unsigned int strLen_2 = strlen("volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_980 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_980+currStrOff, "volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_980+currStrOff, ____BAH_COMPILER_VAR_981, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_980+currStrOff, "];", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(OUTPUT, rope(____BAH_COMPILER_VAR_980));
long int j = 0;
i = 0;
for (; (i<len(elems->fns)); ++i) {
struct func* fn = elems->fns->data[i];
if ((fn->isBinding==true)) {
continue;
}
char * name = fn->name;
char * ____BAH_COMPILER_VAR_982 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->from);
unsigned int strLen_1 = strlen("__");
;                            
            ____BAH_COMPILER_VAR_982 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_982+currStrOff, fn->from, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_982+currStrOff, "__", strLen_1);
            currStrOff += strLen_1;
        
        }if ((strcmp(fn->from, "") != 0)&&strHasPrefix(name,____BAH_COMPILER_VAR_982)) {
struct string n = string(name);
string__trimLeft(&n,strlen(fn->from)+2);
char * ____BAH_COMPILER_VAR_983 =null;char * ____BAH_COMPILER_VAR_984 =string__str(&n);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".");
unsigned int strLen_1 = strlen(____BAH_COMPILER_VAR_984);
unsigned int strLen_2 = strlen(fn->from);
;                            
            ____BAH_COMPILER_VAR_983 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_983+currStrOff, fn->from, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_983+currStrOff, ".", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_983+currStrOff, ____BAH_COMPILER_VAR_984, strLen_1);
            currStrOff += strLen_1;
        
        }name = ____BAH_COMPILER_VAR_983;
}
char * ____BAH_COMPILER_VAR_985 =null;char * ____BAH_COMPILER_VAR_986 =intToStr(j);char * ____BAH_COMPILER_VAR_987 =intToStr(j);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fn->name);
unsigned int strLen_1 = strlen(";\n");
unsigned int strLen_2 = strlen("].p = ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_986);
unsigned int strLen_4 = strlen("\";\n            __tmp____Bah_fnNames[");
unsigned int strLen_5 = strlen(name);
unsigned int strLen_6 = strlen("].n = \"");
unsigned int strLen_7 = strlen(____BAH_COMPILER_VAR_987);
unsigned int strLen_8 = strlen("\n            __tmp____Bah_fnNames[");
;                            
            ____BAH_COMPILER_VAR_985 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8);
            
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, "\n            __tmp____Bah_fnNames[", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, ____BAH_COMPILER_VAR_987, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, "].n = \"", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, name, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, "\";\n            __tmp____Bah_fnNames[", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, ____BAH_COMPILER_VAR_986, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_985+currStrOff, "].p = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_985+currStrOff, fn->name, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_985+currStrOff, ";\n", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_985));
++j;
};
char * ____BAH_COMPILER_VAR_988 =null;char * ____BAH_COMPILER_VAR_989 =intToStr(l);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_989);
unsigned int strLen_1 = strlen(";");
unsigned int strLen_2 = strlen("\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ");
;                            
            ____BAH_COMPILER_VAR_988 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_988+currStrOff, "\n        __Bah_fnNames->data = __tmp____Bah_fnNames;\n        __Bah_fnNames->length = ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_988+currStrOff, ____BAH_COMPILER_VAR_989, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_988+currStrOff, ";", strLen_1);
            currStrOff += strLen_1;
        
        }INIT = rope__add(INIT, rope(____BAH_COMPILER_VAR_988));
}
makeInit();
array(char *)* excludeFns = memoryAlloc(sizeof(array(char *)));

excludeFns->length = 6;
excludeFns->elemSize = sizeof(char *);
excludeFns->data = memoryAlloc(sizeof(char *) * 50);
                    excludeFns->realLength = 50;
excludeFns->data[0] = "main";
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
char * ____BAH_COMPILER_VAR_990 =null;char * ____BAH_COMPILER_VAR_991 =intToStr(totalLexerTime/1000000);char * ____BAH_COMPILER_VAR_992 =intToStr(totalTime/1000000);char * ____BAH_COMPILER_VAR_993 =intToStr(totalLines);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_991);
unsigned int strLen_1 = strlen("ms)\e[0m");
unsigned int strLen_2 = strlen("ms, lexer time: ");
unsigned int strLen_3 = strlen(____BAH_COMPILER_VAR_992);
unsigned int strLen_4 = strlen(" lines, total time: ");
unsigned int strLen_5 = strlen(____BAH_COMPILER_VAR_993);
unsigned int strLen_6 = strlen("Parsed. (");
;                            
            ____BAH_COMPILER_VAR_990 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6);
            
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, "Parsed. (", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, ____BAH_COMPILER_VAR_993, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, " lines, total time: ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, ____BAH_COMPILER_VAR_992, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_990+currStrOff, "ms, lexer time: ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_990+currStrOff, ____BAH_COMPILER_VAR_991, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_990+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_990);
}
if ((flags__isSet(&flags,"o")==1)) {
fileName = flags__get(&flags,"o");
}
else {
struct string outFileName = string(args->data[1]);
string__trimRight(&outFileName,4);
fileName = string__str(&outFileName);
}
char * isStatic = "-static";
if ((flags__isSet(&flags,"d")==1)||(strcmp(BAH_OS, "darwin") == 0)) {
isStatic = "";
}
if ((flags__isSet(&flags,"c")==0)) {
char * obj = "";
if ((flags__isSet(&flags,"object")==1)) {
char * ____BAH_COMPILER_VAR_994 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fileName);
unsigned int strLen_1 = strlen(".o");
;                            
            ____BAH_COMPILER_VAR_994 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_994+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_994+currStrOff, ".o", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_994;
obj = "-c";
}
char * randFileName = "-x c - -x none";
char * ____BAH_COMPILER_VAR_995 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -w -O1 -o ");
unsigned int strLen_1 = strlen(fileName);
unsigned int strLen_2 = strlen(obj);
unsigned int strLen_3 = strlen(" ");
unsigned int strLen_4 = strlen(isStatic);
unsigned int strLen_5 = strlen(" ");
unsigned int strLen_6 = strlen(randFileName);
unsigned int strLen_7 = strlen("/\" ");
unsigned int strLen_8 = strlen(BAH_OS);
unsigned int strLen_9 = strlen("libs/");
unsigned int strLen_10 = strlen(BAH_DIR);
unsigned int strLen_11 = strlen("/include/\" -L \"");
unsigned int strLen_12 = strlen(BAH_OS);
unsigned int strLen_13 = strlen("libs/");
unsigned int strLen_14 = strlen(BAH_DIR);
unsigned int strLen_15 = strlen(" -I \"");
unsigned int strLen_16 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_995 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13+strLen_14+strLen_15+strLen_16);
            
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, BAH_CC, strLen_16);
                    currStrOff += strLen_16;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, " -I \"", strLen_15);
                    currStrOff += strLen_15;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, BAH_DIR, strLen_14);
                    currStrOff += strLen_14;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, "libs/", strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, BAH_OS, strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, "/include/\" -L \"", strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, BAH_DIR, strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, "libs/", strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, BAH_OS, strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, "/\" ", strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, randFileName, strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, " ", strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, isStatic, strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, " ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_995+currStrOff, obj, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_995+currStrOff, " -w -O1 -o ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_995+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_995;
if ((flags__isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_996 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(gccArgs);
unsigned int strLen_1 = strlen(" -c");
;                            
            ____BAH_COMPILER_VAR_996 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_996+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_996+currStrOff, " -c", strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_996;
}
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_997 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -");
unsigned int strLen_1 = strlen(l);
unsigned int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_997 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_997+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_997+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_997+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_997;
i = i+1;
};
struct command cmd = command(gccArgs);
cmd.input = rope__toStr(OUTPUT);
if ((flags__isSet(&flags,"verboseCC")==1)) {
char * ____BAH_COMPILER_VAR_998 =command__run(&cmd);println(____BAH_COMPILER_VAR_998);
}
else {
char * ____BAH_COMPILER_VAR_999 =command__run(&cmd);}
if ((cmd.status!=0)) {
println("\e[1;31m[CC-ERROR]\e[0m\nCould not compiled.");
return 1;
}
if ((flags__isSet(&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_1000 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(".a ");
unsigned int strLen_1 = strlen(fileName);
unsigned int strLen_2 = strlen(fileName);
unsigned int strLen_3 = strlen("ar rcs ");
;                            
            ____BAH_COMPILER_VAR_1000 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3);
            
                    memcpy(____BAH_COMPILER_VAR_1000+currStrOff, "ar rcs ", strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_1000+currStrOff, fileName, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1000+currStrOff, ".a ", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1000+currStrOff, fileName, strLen_1);
            currStrOff += strLen_1;
        
        }cmd = command(____BAH_COMPILER_VAR_1000);
char * ____BAH_COMPILER_VAR_1001 =command__run(&cmd);}
}
else {
if ((flags__isSet(&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_1002 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(fileName);
unsigned int strLen_1 = strlen(".c");
;                            
            ____BAH_COMPILER_VAR_1002 = memoryAllocSTR(1+strLen_0+strLen_1);
            
            memcpy(____BAH_COMPILER_VAR_1002+currStrOff, fileName, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1002+currStrOff, ".c", strLen_1);
            currStrOff += strLen_1;
        
        }fileName = ____BAH_COMPILER_VAR_1002;
}
char * ____BAH_COMPILER_VAR_1003 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(isStatic);
unsigned int strLen_1 = strlen(" -O1 -w ");
unsigned int strLen_2 = strlen(" ");
unsigned int strLen_3 = strlen(fileName);
unsigned int strLen_4 = strlen("/\" ");
unsigned int strLen_5 = strlen(BAH_OS);
unsigned int strLen_6 = strlen("libs/");
unsigned int strLen_7 = strlen(BAH_DIR);
unsigned int strLen_8 = strlen("/include/\" -L \"");
unsigned int strLen_9 = strlen(BAH_OS);
unsigned int strLen_10 = strlen("libs/");
unsigned int strLen_11 = strlen(BAH_DIR);
unsigned int strLen_12 = strlen(" -I \"");
unsigned int strLen_13 = strlen(BAH_CC);
;                            
            ____BAH_COMPILER_VAR_1003 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2+strLen_3+strLen_4+strLen_5+strLen_6+strLen_7+strLen_8+strLen_9+strLen_10+strLen_11+strLen_12+strLen_13);
            
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, BAH_CC, strLen_13);
                    currStrOff += strLen_13;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, " -I \"", strLen_12);
                    currStrOff += strLen_12;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, BAH_DIR, strLen_11);
                    currStrOff += strLen_11;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, "libs/", strLen_10);
                    currStrOff += strLen_10;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, BAH_OS, strLen_9);
                    currStrOff += strLen_9;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, "/include/\" -L \"", strLen_8);
                    currStrOff += strLen_8;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, BAH_DIR, strLen_7);
                    currStrOff += strLen_7;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, "libs/", strLen_6);
                    currStrOff += strLen_6;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, BAH_OS, strLen_5);
                    currStrOff += strLen_5;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, "/\" ", strLen_4);
                    currStrOff += strLen_4;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, fileName, strLen_3);
                    currStrOff += strLen_3;
                    
                    memcpy(____BAH_COMPILER_VAR_1003+currStrOff, " ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1003+currStrOff, isStatic, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1003+currStrOff, " -O1 -w ", strLen_1);
            currStrOff += strLen_1;
        
        }char * gccArgs = ____BAH_COMPILER_VAR_1003;
array(char *)* cLibs = compilerState.cLibs;
register long int i = 0;
while ((i<len(cLibs))) {
char * l = cLibs->data[i];
char * ____BAH_COMPILER_VAR_1004 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(" -");
unsigned int strLen_1 = strlen(l);
unsigned int strLen_2 = strlen(gccArgs);
;                            
            ____BAH_COMPILER_VAR_1004 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1004+currStrOff, gccArgs, strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1004+currStrOff, " -", strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1004+currStrOff, l, strLen_1);
            currStrOff += strLen_1;
        
        }gccArgs = ____BAH_COMPILER_VAR_1004;
i = i+1;
};
char * ____BAH_COMPILER_VAR_1005 =null;
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(gccArgs);
unsigned int strLen_1 = strlen("'\n");
unsigned int strLen_2 = strlen("//COMPILE WITH: '");
;                            
            ____BAH_COMPILER_VAR_1005 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1005+currStrOff, "//COMPILE WITH: '", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1005+currStrOff, gccArgs, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1005+currStrOff, "'\n", strLen_1);
            currStrOff += strLen_1;
        
        }OUTPUT = rope__add(rope(____BAH_COMPILER_VAR_1005), OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_1006 = {};
____BAH_COMPILER_VAR_1006.handle= null;
____BAH_COMPILER_VAR_1006.name= null;
#define fs ____BAH_COMPILER_VAR_1006
fileStream__open(&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_1007 =rope__toStr(OUTPUT);fileStream__writeFile(&fs,____BAH_COMPILER_VAR_1007);
fileStream__close(&fs);

#undef fs
}
if ((isObject==false)) {
long int totalTime = getTimeUnix()-startTime;
char * ____BAH_COMPILER_VAR_1008 =null;char * ____BAH_COMPILER_VAR_1009 =intToStr(totalTime/1000000);
        {
            unsigned int currStrOff = 0;
            unsigned int strLen_0 = strlen(____BAH_COMPILER_VAR_1009);
unsigned int strLen_1 = strlen("ms)\e[0m");
unsigned int strLen_2 = strlen("\e[1;32mDone. (compiled in ");
;                            
            ____BAH_COMPILER_VAR_1008 = memoryAllocSTR(1+strLen_0+strLen_1+strLen_2);
            
                    memcpy(____BAH_COMPILER_VAR_1008+currStrOff, "\e[1;32mDone. (compiled in ", strLen_2);
                    currStrOff += strLen_2;
                    
            memcpy(____BAH_COMPILER_VAR_1008+currStrOff, ____BAH_COMPILER_VAR_1009, strLen_0);
            currStrOff += strLen_0;
        
            memcpy(____BAH_COMPILER_VAR_1008+currStrOff, "ms)\e[0m", strLen_1);
            currStrOff += strLen_1;
        
        }println(____BAH_COMPILER_VAR_1008);
}
return 0;

#undef fm
};
volatile struct __Bah_fnName_mapper __tmp____Bah_fnNames[304];
    
    void __attribute__((optimize("O0"))) __BAH_init() {
        __BAH_panic_chan = null;
__Bah_fnNames = memoryAlloc(sizeof(array(struct __Bah_fnName_mapper)));

__Bah_fnNames->length = 0;
__Bah_fnNames->elemSize = sizeof(struct __Bah_fnName_mapper);
onMemoryError = null;
__Bah_init_segfaultHandle_OK = __Bah_init_segfaultHandle();
RAND_SEEDED = false;
BAH_DIR = "/opt/bah/";
BAH_OS = "darwin";
BAH_CC = "clang";
debug = false;
verboseRuntime = false;
isObject = false;
isUnsafe = false;
isOptimized = false;
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
enclavers->data = memoryAlloc(sizeof(char) * 50);
                    enclavers->realLength = 50;
enclavers->data[0] = 40;
enclavers->data[1] = 41;
enclavers->data[2] = 123;
enclavers->data[3] = 125;
enclavers->data[4] = 91;
enclavers->data[5] = 93;
syntaxes = memoryAlloc(sizeof(array(char)));

syntaxes->length = 15;
syntaxes->elemSize = sizeof(char);
syntaxes->data = memoryAlloc(sizeof(char) * 50);
                    syntaxes->realLength = 50;
syntaxes->data[0] = 33;
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
syntaxes->data[14] = 94;
keywords = memoryAlloc(sizeof(array(char *)));

keywords->length = 21;
keywords->elemSize = sizeof(char *);
keywords->data = memoryAlloc(sizeof(char *) * 50);
                    keywords->realLength = 50;
keywords->data[0] = "if";
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
intTypes->data = memoryAlloc(sizeof(char *) * 50);
                    intTypes->realLength = 50;
intTypes->data[0] = "int";
intTypes->data[1] = "int32";
intTypes->data[2] = "uint";
intTypes->data[3] = "uint32";
intTypes->data[4] = "bool";
floatTypes = memoryAlloc(sizeof(array(char *)));

floatTypes->length = 4;
floatTypes->elemSize = sizeof(char *);
floatTypes->data = memoryAlloc(sizeof(char *) * 50);
                    floatTypes->realLength = 50;
floatTypes->data[0] = "float";
floatTypes->data[1] = "float32";
floatTypes->data[2] = "ufloat";
floatTypes->data[3] = "ufloat32";
NB_COMP_VAR = 0;
noVOfns = memoryAlloc(sizeof(array(char *)));

noVOfns->length = 1;
noVOfns->elemSize = sizeof(char *);
noVOfns->data = memoryAlloc(sizeof(char *) * 50);
                    noVOfns->realLength = 50;
noVOfns->data[0] = "__Bah_safe_string";
cache = memoryAlloc(sizeof(array(struct cacheFile*)));

cache->length = 0;
cache->elemSize = sizeof(struct cacheFile*);
prevLine = (lineType)-1;
signs = memoryAlloc(sizeof(array(char *)));

signs->length = 10;
signs->elemSize = sizeof(char *);
signs->data = memoryAlloc(sizeof(char *) * 50);
                    signs->realLength = 50;
signs->data[0] = "|";
signs->data[1] = "&";
signs->data[2] = "%";
signs->data[3] = "+";
signs->data[4] = "-";
signs->data[5] = "*";
signs->data[6] = "/";
signs->data[7] = "<<";
signs->data[8] = ">>";
signs->data[9] = "^";
comparators = memoryAlloc(sizeof(array(char *)));

comparators->length = 7;
comparators->elemSize = sizeof(char *);
comparators->data = memoryAlloc(sizeof(char *) * 50);
                    comparators->realLength = 50;
comparators->data[0] = "==";
comparators->data[1] = "!=";
comparators->data[2] = ">";
comparators->data[3] = "<";
comparators->data[4] = "<=";
comparators->data[5] = ">=";
comparators->data[6] = "in";
compSep = memoryAlloc(sizeof(array(char *)));

compSep->length = 2;
compSep->elemSize = sizeof(char *);
compSep->data = memoryAlloc(sizeof(char *) * 50);
                    compSep->realLength = 50;
compSep->data[0] = "||";
compSep->data[1] = "&&";
equalsTokens = memoryAlloc(sizeof(array(char *)));

equalsTokens->length = 5;
equalsTokens->elemSize = sizeof(char *);
equalsTokens->data = memoryAlloc(sizeof(char *) * 50);
                    equalsTokens->realLength = 50;
equalsTokens->data[0] = "=";
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

            __tmp____Bah_fnNames[4].n = "print";
            __tmp____Bah_fnNames[4].p = print;

            __tmp____Bah_fnNames[5].n = "__BAH_memcpy";
            __tmp____Bah_fnNames[5].p = __BAH_memcpy;

            __tmp____Bah_fnNames[6].n = "len";
            __tmp____Bah_fnNames[6].p = len;

            __tmp____Bah_fnNames[7].n = "memoryAlloc";
            __tmp____Bah_fnNames[7].p = memoryAlloc;

            __tmp____Bah_fnNames[8].n = "destroy";
            __tmp____Bah_fnNames[8].p = destroy;

            __tmp____Bah_fnNames[9].n = "clear";
            __tmp____Bah_fnNames[9].p = clear;

            __tmp____Bah_fnNames[10].n = "memoryRealloc";
            __tmp____Bah_fnNames[10].p = memoryRealloc;

            __tmp____Bah_fnNames[11].n = "cleanShutDown";
            __tmp____Bah_fnNames[11].p = cleanShutDown;

            __tmp____Bah_fnNames[12].n = "memoryOnEnd";
            __tmp____Bah_fnNames[12].p = memoryOnEnd;

            __tmp____Bah_fnNames[13].n = "append";
            __tmp____Bah_fnNames[13].p = append;

            __tmp____Bah_fnNames[14].n = "copy";
            __tmp____Bah_fnNames[14].p = copy;

            __tmp____Bah_fnNames[15].n = "sharedMemory";
            __tmp____Bah_fnNames[15].p = sharedMemory;

            __tmp____Bah_fnNames[16].n = "allocateArray";
            __tmp____Bah_fnNames[16].p = allocateArray;

            __tmp____Bah_fnNames[17].n = "__serialize";
            __tmp____Bah_fnNames[17].p = __serialize;

            __tmp____Bah_fnNames[18].n = "serlen";
            __tmp____Bah_fnNames[18].p = serlen;

            __tmp____Bah_fnNames[19].n = "unser";
            __tmp____Bah_fnNames[19].p = unser;

            __tmp____Bah_fnNames[20].n = "memoryAllocSTR";
            __tmp____Bah_fnNames[20].p = memoryAllocSTR;

            __tmp____Bah_fnNames[21].n = "delete";
            __tmp____Bah_fnNames[21].p = delete;

            __tmp____Bah_fnNames[22].n = "deleteRange";
            __tmp____Bah_fnNames[22].p = deleteRange;

            __tmp____Bah_fnNames[23].n = "arrToStr";
            __tmp____Bah_fnNames[23].p = arrToStr;

            __tmp____Bah_fnNames[24].n = "strToArr";
            __tmp____Bah_fnNames[24].p = strToArr;

            __tmp____Bah_fnNames[25].n = "arrAsStr";
            __tmp____Bah_fnNames[25].p = arrAsStr;

            __tmp____Bah_fnNames[26].n = "strAsArr";
            __tmp____Bah_fnNames[26].p = strAsArr;

            __tmp____Bah_fnNames[27].n = "strTrimLeft";
            __tmp____Bah_fnNames[27].p = strTrimLeft;

            __tmp____Bah_fnNames[28].n = "strTrimRight";
            __tmp____Bah_fnNames[28].p = strTrimRight;

            __tmp____Bah_fnNames[29].n = "concatCPSTRING";
            __tmp____Bah_fnNames[29].p = concatCPSTRING;

            __tmp____Bah_fnNames[30].n = "__STR";
            __tmp____Bah_fnNames[30].p = __STR;

            __tmp____Bah_fnNames[31].n = "cArr";
            __tmp____Bah_fnNames[31].p = cArr;

            __tmp____Bah_fnNames[32].n = "__checkString";
            __tmp____Bah_fnNames[32].p = __checkString;

            __tmp____Bah_fnNames[33].n = "mutex.init";
            __tmp____Bah_fnNames[33].p = mutex__init;

            __tmp____Bah_fnNames[34].n = "mutex.lock";
            __tmp____Bah_fnNames[34].p = mutex__lock;

            __tmp____Bah_fnNames[35].n = "mutex.unlock";
            __tmp____Bah_fnNames[35].p = mutex__unlock;

            __tmp____Bah_fnNames[36].n = "mutex.destroy";
            __tmp____Bah_fnNames[36].p = mutex__destroy;

            __tmp____Bah_fnNames[37].n = "mutexCondition.init";
            __tmp____Bah_fnNames[37].p = mutexCondition__init;

            __tmp____Bah_fnNames[38].n = "mutexCondition.wait";
            __tmp____Bah_fnNames[38].p = mutexCondition__wait;

            __tmp____Bah_fnNames[39].n = "mutexCondition.send";
            __tmp____Bah_fnNames[39].p = mutexCondition__send;

            __tmp____Bah_fnNames[40].n = "mutexCondition.destroy";
            __tmp____Bah_fnNames[40].p = mutexCondition__destroy;

            __tmp____Bah_fnNames[41].n = "mutexCondition";
            __tmp____Bah_fnNames[41].p = mutexCondition;

            __tmp____Bah_fnNames[42].n = "thread.create";
            __tmp____Bah_fnNames[42].p = thread__create;

            __tmp____Bah_fnNames[43].n = "thread.createWithArg";
            __tmp____Bah_fnNames[43].p = thread__createWithArg;

            __tmp____Bah_fnNames[44].n = "thread.wait";
            __tmp____Bah_fnNames[44].p = thread__wait;

            __tmp____Bah_fnNames[45].n = "mutex";
            __tmp____Bah_fnNames[45].p = mutex;

            __tmp____Bah_fnNames[46].n = "queue.insert";
            __tmp____Bah_fnNames[46].p = queue__insert;

            __tmp____Bah_fnNames[47].n = "queue.delete";
            __tmp____Bah_fnNames[47].p = queue__delete;

            __tmp____Bah_fnNames[48].n = "queue.get";
            __tmp____Bah_fnNames[48].p = queue__get;

            __tmp____Bah_fnNames[49].n = "queue.set";
            __tmp____Bah_fnNames[49].p = queue__set;

            __tmp____Bah_fnNames[50].n = "queue.pop";
            __tmp____Bah_fnNames[50].p = queue__pop;

            __tmp____Bah_fnNames[51].n = "queue.clear";
            __tmp____Bah_fnNames[51].p = queue__clear;

            __tmp____Bah_fnNames[52].n = "channel.send";
            __tmp____Bah_fnNames[52].p = channel__send;

            __tmp____Bah_fnNames[53].n = "channel.sendAny";
            __tmp____Bah_fnNames[53].p = channel__sendAny;

            __tmp____Bah_fnNames[54].n = "channel.receive";
            __tmp____Bah_fnNames[54].p = channel__receive;

            __tmp____Bah_fnNames[55].n = "channel.destroy";
            __tmp____Bah_fnNames[55].p = channel__destroy;

            __tmp____Bah_fnNames[56].n = "channel.len";
            __tmp____Bah_fnNames[56].p = channel__len;

            __tmp____Bah_fnNames[57].n = "channel";
            __tmp____Bah_fnNames[57].p = channel;

            __tmp____Bah_fnNames[58].n = "setChanCap";
            __tmp____Bah_fnNames[58].p = setChanCap;

            __tmp____Bah_fnNames[59].n = "__Bah_common_panic";
            __tmp____Bah_fnNames[59].p = __Bah_common_panic;

            __tmp____Bah_fnNames[60].n = "__Bah_fnNames_append";
            __tmp____Bah_fnNames[60].p = __Bah_fnNames_append;

            __tmp____Bah_fnNames[61].n = "__Bah_segfault_handle";
            __tmp____Bah_fnNames[61].p = __Bah_segfault_handle;

            __tmp____Bah_fnNames[62].n = "__Bah_init_segfaultHandle";
            __tmp____Bah_fnNames[62].p = __Bah_init_segfaultHandle;

            __tmp____Bah_fnNames[63].n = "recover";
            __tmp____Bah_fnNames[63].p = recover;

            __tmp____Bah_fnNames[64].n = "cpstringCharAt";
            __tmp____Bah_fnNames[64].p = cpstringCharAt;

            __tmp____Bah_fnNames[65].n = "cpstringSubsitute";
            __tmp____Bah_fnNames[65].p = cpstringSubsitute;

            __tmp____Bah_fnNames[66].n = "arraySubstitute";
            __tmp____Bah_fnNames[66].p = arraySubstitute;

            __tmp____Bah_fnNames[67].n = "__Bah_map_hash";
            __tmp____Bah_fnNames[67].p = __Bah_map_hash;

            __tmp____Bah_fnNames[68].n = "mapWrapper.grow";
            __tmp____Bah_fnNames[68].p = mapWrapper__grow;

            __tmp____Bah_fnNames[69].n = "mapWrapper.set";
            __tmp____Bah_fnNames[69].p = mapWrapper__set;

            __tmp____Bah_fnNames[70].n = "mapWrapper.setAny";
            __tmp____Bah_fnNames[70].p = mapWrapper__setAny;

            __tmp____Bah_fnNames[71].n = "mapWrapper.delete";
            __tmp____Bah_fnNames[71].p = mapWrapper__delete;

            __tmp____Bah_fnNames[72].n = "mapWrapper.get";
            __tmp____Bah_fnNames[72].p = mapWrapper__get;

            __tmp____Bah_fnNames[73].n = "mapWrapper";
            __tmp____Bah_fnNames[73].p = mapWrapper;

            __tmp____Bah_fnNames[74].n = "stdinput";
            __tmp____Bah_fnNames[74].p = stdinput;

            __tmp____Bah_fnNames[75].n = "println";
            __tmp____Bah_fnNames[75].p = println;

            __tmp____Bah_fnNames[76].n = "fileStream.isValid";
            __tmp____Bah_fnNames[76].p = fileStream__isValid;

            __tmp____Bah_fnNames[77].n = "fileStream.open";
            __tmp____Bah_fnNames[77].p = fileStream__open;

            __tmp____Bah_fnNames[78].n = "fileStream.close";
            __tmp____Bah_fnNames[78].p = fileStream__close;

            __tmp____Bah_fnNames[79].n = "fileStream.getPos";
            __tmp____Bah_fnNames[79].p = fileStream__getPos;

            __tmp____Bah_fnNames[80].n = "fileStream.setPos";
            __tmp____Bah_fnNames[80].p = fileStream__setPos;

            __tmp____Bah_fnNames[81].n = "fileStream.getSize";
            __tmp____Bah_fnNames[81].p = fileStream__getSize;

            __tmp____Bah_fnNames[82].n = "fileStream.rewind";
            __tmp____Bah_fnNames[82].p = fileStream__rewind;

            __tmp____Bah_fnNames[83].n = "fileStream.getChar";
            __tmp____Bah_fnNames[83].p = fileStream__getChar;

            __tmp____Bah_fnNames[84].n = "fileStream.setChar";
            __tmp____Bah_fnNames[84].p = fileStream__setChar;

            __tmp____Bah_fnNames[85].n = "fileStream.createFile";
            __tmp____Bah_fnNames[85].p = fileStream__createFile;

            __tmp____Bah_fnNames[86].n = "fileStream.writeFile";
            __tmp____Bah_fnNames[86].p = fileStream__writeFile;

            __tmp____Bah_fnNames[87].n = "fileStream.writePtr";
            __tmp____Bah_fnNames[87].p = fileStream__writePtr;

            __tmp____Bah_fnNames[88].n = "fileStream.readPtr";
            __tmp____Bah_fnNames[88].p = fileStream__readPtr;

            __tmp____Bah_fnNames[89].n = "fileStream.readContent";
            __tmp____Bah_fnNames[89].p = fileStream__readContent;

            __tmp____Bah_fnNames[90].n = "fileStream.readBytes";
            __tmp____Bah_fnNames[90].p = fileStream__readBytes;

            __tmp____Bah_fnNames[91].n = "fileStream.writeBytes";
            __tmp____Bah_fnNames[91].p = fileStream__writeBytes;

            __tmp____Bah_fnNames[92].n = "fileStream._end";
            __tmp____Bah_fnNames[92].p = fileStream___end;

            __tmp____Bah_fnNames[93].n = "fileMap.open";
            __tmp____Bah_fnNames[93].p = fileMap__open;

            __tmp____Bah_fnNames[94].n = "fileMap.isValid";
            __tmp____Bah_fnNames[94].p = fileMap__isValid;

            __tmp____Bah_fnNames[95].n = "fileMap.close";
            __tmp____Bah_fnNames[95].p = fileMap__close;

            __tmp____Bah_fnNames[96].n = "listFiles";
            __tmp____Bah_fnNames[96].p = listFiles;

            __tmp____Bah_fnNames[97].n = "fileExists";
            __tmp____Bah_fnNames[97].p = fileExists;

            __tmp____Bah_fnNames[98].n = "isFolder";
            __tmp____Bah_fnNames[98].p = isFolder;

            __tmp____Bah_fnNames[99].n = "removeFile";
            __tmp____Bah_fnNames[99].p = removeFile;

            __tmp____Bah_fnNames[100].n = "getLastModified";
            __tmp____Bah_fnNames[100].p = getLastModified;

            __tmp____Bah_fnNames[101].n = "strCatOffset";
            __tmp____Bah_fnNames[101].p = strCatOffset;

            __tmp____Bah_fnNames[102].n = "charToString";
            __tmp____Bah_fnNames[102].p = charToString;

            __tmp____Bah_fnNames[103].n = "isUpper";
            __tmp____Bah_fnNames[103].p = isUpper;

            __tmp____Bah_fnNames[104].n = "isLower";
            __tmp____Bah_fnNames[104].p = isLower;

            __tmp____Bah_fnNames[105].n = "isLetter";
            __tmp____Bah_fnNames[105].p = isLetter;

            __tmp____Bah_fnNames[106].n = "isNumber";
            __tmp____Bah_fnNames[106].p = isNumber;

            __tmp____Bah_fnNames[107].n = "isAlphaNumeric";
            __tmp____Bah_fnNames[107].p = isAlphaNumeric;

            __tmp____Bah_fnNames[108].n = "isSpace";
            __tmp____Bah_fnNames[108].p = isSpace;

            __tmp____Bah_fnNames[109].n = "string.set";
            __tmp____Bah_fnNames[109].p = string__set;

            __tmp____Bah_fnNames[110].n = "string.makeEditable";
            __tmp____Bah_fnNames[110].p = string__makeEditable;

            __tmp____Bah_fnNames[111].n = "string.append";
            __tmp____Bah_fnNames[111].p = string__append;

            __tmp____Bah_fnNames[112].n = "string.prepend";
            __tmp____Bah_fnNames[112].p = string__prepend;

            __tmp____Bah_fnNames[113].n = "string.charAt";
            __tmp____Bah_fnNames[113].p = string__charAt;

            __tmp____Bah_fnNames[114].n = "string.compare";
            __tmp____Bah_fnNames[114].p = string__compare;

            __tmp____Bah_fnNames[115].n = "string.str";
            __tmp____Bah_fnNames[115].p = string__str;

            __tmp____Bah_fnNames[116].n = "string.replace";
            __tmp____Bah_fnNames[116].p = string__replace;

            __tmp____Bah_fnNames[117].n = "string.countChar";
            __tmp____Bah_fnNames[117].p = string__countChar;

            __tmp____Bah_fnNames[118].n = "string.count";
            __tmp____Bah_fnNames[118].p = string__count;

            __tmp____Bah_fnNames[119].n = "string.hasPrefix";
            __tmp____Bah_fnNames[119].p = string__hasPrefix;

            __tmp____Bah_fnNames[120].n = "string.hasSuffix";
            __tmp____Bah_fnNames[120].p = string__hasSuffix;

            __tmp____Bah_fnNames[121].n = "string.trim";
            __tmp____Bah_fnNames[121].p = string__trim;

            __tmp____Bah_fnNames[122].n = "string.trimLeft";
            __tmp____Bah_fnNames[122].p = string__trimLeft;

            __tmp____Bah_fnNames[123].n = "string.trimRight";
            __tmp____Bah_fnNames[123].p = string__trimRight;

            __tmp____Bah_fnNames[124].n = "string.add";
            __tmp____Bah_fnNames[124].p = string__add;

            __tmp____Bah_fnNames[125].n = "string.asArr";
            __tmp____Bah_fnNames[125].p = string__asArr;

            __tmp____Bah_fnNames[126].n = "string";
            __tmp____Bah_fnNames[126].p = string;

            __tmp____Bah_fnNames[127].n = "intToStr";
            __tmp____Bah_fnNames[127].p = intToStr;

            __tmp____Bah_fnNames[128].n = "intToString";
            __tmp____Bah_fnNames[128].p = intToString;

            __tmp____Bah_fnNames[129].n = "floatToStr";
            __tmp____Bah_fnNames[129].p = floatToStr;

            __tmp____Bah_fnNames[130].n = "strToInt";
            __tmp____Bah_fnNames[130].p = strToInt;

            __tmp____Bah_fnNames[131].n = "strToFloat";
            __tmp____Bah_fnNames[131].p = strToFloat;

            __tmp____Bah_fnNames[132].n = "stringToInt";
            __tmp____Bah_fnNames[132].p = stringToInt;

            __tmp____Bah_fnNames[133].n = "splitString";
            __tmp____Bah_fnNames[133].p = splitString;

            __tmp____Bah_fnNames[134].n = "joinString";
            __tmp____Bah_fnNames[134].p = joinString;

            __tmp____Bah_fnNames[135].n = "splitStringBefore";
            __tmp____Bah_fnNames[135].p = splitStringBefore;

            __tmp____Bah_fnNames[136].n = "toLower";
            __tmp____Bah_fnNames[136].p = toLower;

            __tmp____Bah_fnNames[137].n = "strHasPrefix";
            __tmp____Bah_fnNames[137].p = strHasPrefix;

            __tmp____Bah_fnNames[138].n = "strHasSuffix";
            __tmp____Bah_fnNames[138].p = strHasSuffix;

            __tmp____Bah_fnNames[139].n = "strTrim";
            __tmp____Bah_fnNames[139].p = strTrim;

            __tmp____Bah_fnNames[140].n = "strCount";
            __tmp____Bah_fnNames[140].p = strCount;

            __tmp____Bah_fnNames[141].n = "flags.addString";
            __tmp____Bah_fnNames[141].p = flags__addString;

            __tmp____Bah_fnNames[142].n = "flags.addBool";
            __tmp____Bah_fnNames[142].p = flags__addBool;

            __tmp____Bah_fnNames[143].n = "flags.addInt";
            __tmp____Bah_fnNames[143].p = flags__addInt;

            __tmp____Bah_fnNames[144].n = "flags.addFloat";
            __tmp____Bah_fnNames[144].p = flags__addFloat;

            __tmp____Bah_fnNames[145].n = "flags.invalidate";
            __tmp____Bah_fnNames[145].p = flags__invalidate;

            __tmp____Bah_fnNames[146].n = "flags.getFlag";
            __tmp____Bah_fnNames[146].p = flags__getFlag;

            __tmp____Bah_fnNames[147].n = "flags.get";
            __tmp____Bah_fnNames[147].p = flags__get;

            __tmp____Bah_fnNames[148].n = "flags.getInt";
            __tmp____Bah_fnNames[148].p = flags__getInt;

            __tmp____Bah_fnNames[149].n = "flags.getFloat";
            __tmp____Bah_fnNames[149].p = flags__getFloat;

            __tmp____Bah_fnNames[150].n = "flags.isSet";
            __tmp____Bah_fnNames[150].p = flags__isSet;

            __tmp____Bah_fnNames[151].n = "flags.parse";
            __tmp____Bah_fnNames[151].p = flags__parse;

            __tmp____Bah_fnNames[152].n = "time.now";
            __tmp____Bah_fnNames[152].p = time__now;

            __tmp____Bah_fnNames[153].n = "time.format";
            __tmp____Bah_fnNames[153].p = time__format;

            __tmp____Bah_fnNames[154].n = "time.since";
            __tmp____Bah_fnNames[154].p = time__since;

            __tmp____Bah_fnNames[155].n = "getTimeUnix";
            __tmp____Bah_fnNames[155].p = getTimeUnix;

            __tmp____Bah_fnNames[156].n = "seedRandom";
            __tmp____Bah_fnNames[156].p = seedRandom;

            __tmp____Bah_fnNames[157].n = "randomInRange";
            __tmp____Bah_fnNames[157].p = randomInRange;

            __tmp____Bah_fnNames[158].n = "cryptoRand";
            __tmp____Bah_fnNames[158].p = cryptoRand;

            __tmp____Bah_fnNames[159].n = "rope.addStr";
            __tmp____Bah_fnNames[159].p = rope__addStr;

            __tmp____Bah_fnNames[160].n = "rope.toStr";
            __tmp____Bah_fnNames[160].p = rope__toStr;

            __tmp____Bah_fnNames[161].n = "rope.add";
            __tmp____Bah_fnNames[161].p = rope__add;

            __tmp____Bah_fnNames[162].n = "createRopeStructure";
            __tmp____Bah_fnNames[162].p = createRopeStructure;

            __tmp____Bah_fnNames[163].n = "ropeSet";
            __tmp____Bah_fnNames[163].p = ropeSet;

            __tmp____Bah_fnNames[164].n = "concatenateRopes";
            __tmp____Bah_fnNames[164].p = concatenateRopes;

            __tmp____Bah_fnNames[165].n = "rope";
            __tmp____Bah_fnNames[165].p = rope;

            __tmp____Bah_fnNames[166].n = "command.run";
            __tmp____Bah_fnNames[166].p = command__run;

            __tmp____Bah_fnNames[167].n = "command.runBytes";
            __tmp____Bah_fnNames[167].p = command__runBytes;

            __tmp____Bah_fnNames[168].n = "command";
            __tmp____Bah_fnNames[168].p = command;

            __tmp____Bah_fnNames[169].n = "exec";
            __tmp____Bah_fnNames[169].p = exec;

            __tmp____Bah_fnNames[170].n = "inArray";
            __tmp____Bah_fnNames[170].p = inArray;

            __tmp____Bah_fnNames[171].n = "inArrayStr";
            __tmp____Bah_fnNames[171].p = inArrayStr;

            __tmp____Bah_fnNames[172].n = "makeToken";
            __tmp____Bah_fnNames[172].p = makeToken;

            __tmp____Bah_fnNames[173].n = "isMinus";
            __tmp____Bah_fnNames[173].p = isMinus;

            __tmp____Bah_fnNames[174].n = "lexerErr";
            __tmp____Bah_fnNames[174].p = lexerErr;

            __tmp____Bah_fnNames[175].n = "lexer";
            __tmp____Bah_fnNames[175].p = lexer;

            __tmp____Bah_fnNames[176].n = "hasStructSep";
            __tmp____Bah_fnNames[176].p = hasStructSep;

            __tmp____Bah_fnNames[177].n = "splitStructSepBefore";
            __tmp____Bah_fnNames[177].p = splitStructSepBefore;

            __tmp____Bah_fnNames[178].n = "splitStructSepAfter";
            __tmp____Bah_fnNames[178].p = splitStructSepAfter;

            __tmp____Bah_fnNames[179].n = "searchStruct";
            __tmp____Bah_fnNames[179].p = searchStruct;

            __tmp____Bah_fnNames[180].n = "searchStructMemb";
            __tmp____Bah_fnNames[180].p = searchStructMemb;

            __tmp____Bah_fnNames[181].n = "searchFunc";
            __tmp____Bah_fnNames[181].p = searchFunc;

            __tmp____Bah_fnNames[182].n = "parseFnType";
            __tmp____Bah_fnNames[182].p = parseFnType;

            __tmp____Bah_fnNames[183].n = "searchStructMethod";
            __tmp____Bah_fnNames[183].p = searchStructMethod;

            __tmp____Bah_fnNames[184].n = "typeAsStar";
            __tmp____Bah_fnNames[184].p = typeAsStar;

            __tmp____Bah_fnNames[185].n = "isRCPpointerType";
            __tmp____Bah_fnNames[185].p = isRCPpointerType;

            __tmp____Bah_fnNames[186].n = "isRCPtype";
            __tmp____Bah_fnNames[186].p = isRCPtype;

            __tmp____Bah_fnNames[187].n = "getCType";
            __tmp____Bah_fnNames[187].p = getCType;

            __tmp____Bah_fnNames[188].n = "compTypeEquiv";
            __tmp____Bah_fnNames[188].p = compTypeEquiv;

            __tmp____Bah_fnNames[189].n = "compTypes";
            __tmp____Bah_fnNames[189].p = compTypes;

            __tmp____Bah_fnNames[190].n = "reflectElement.calculateOffset";
            __tmp____Bah_fnNames[190].p = reflectElement__calculateOffset;

            __tmp____Bah_fnNames[191].n = "__reflect";
            __tmp____Bah_fnNames[191].p = __reflect;

            __tmp____Bah_fnNames[192].n = "__dumpSymbols";
            __tmp____Bah_fnNames[192].p = __dumpSymbols;

            __tmp____Bah_fnNames[193].n = "__debug_get_sym";
            __tmp____Bah_fnNames[193].p = __debug_get_sym;

            __tmp____Bah_fnNames[194].n = "toJson";
            __tmp____Bah_fnNames[194].p = toJson;

            __tmp____Bah_fnNames[195].n = "json_scan_inner";
            __tmp____Bah_fnNames[195].p = json_scan_inner;

            __tmp____Bah_fnNames[196].n = "jsonElement.get";
            __tmp____Bah_fnNames[196].p = jsonElement__get;

            __tmp____Bah_fnNames[197].n = "jsonElement.str";
            __tmp____Bah_fnNames[197].p = jsonElement__str;

            __tmp____Bah_fnNames[198].n = "jsonElement.scan";
            __tmp____Bah_fnNames[198].p = jsonElement__scan;

            __tmp____Bah_fnNames[199].n = "parseJson";
            __tmp____Bah_fnNames[199].p = parseJson;

            __tmp____Bah_fnNames[200].n = "json_isPrintable";
            __tmp____Bah_fnNames[200].p = json_isPrintable;

            __tmp____Bah_fnNames[201].n = "jsonEscapeStr";
            __tmp____Bah_fnNames[201].p = jsonEscapeStr;

            __tmp____Bah_fnNames[202].n = "toJson__inner";
            __tmp____Bah_fnNames[202].p = toJson__inner;

            __tmp____Bah_fnNames[203].n = "debugStart";
            __tmp____Bah_fnNames[203].p = debugStart;

            __tmp____Bah_fnNames[204].n = "debugPrint";
            __tmp____Bah_fnNames[204].p = debugPrint;

            __tmp____Bah_fnNames[205].n = "debugError";
            __tmp____Bah_fnNames[205].p = debugError;

            __tmp____Bah_fnNames[206].n = "debugEnd";
            __tmp____Bah_fnNames[206].p = debugEnd;

            __tmp____Bah_fnNames[207].n = "debugExit";
            __tmp____Bah_fnNames[207].p = debugExit;

            __tmp____Bah_fnNames[208].n = "debugEndScope";
            __tmp____Bah_fnNames[208].p = debugEndScope;

            __tmp____Bah_fnNames[209].n = "throwErr";
            __tmp____Bah_fnNames[209].p = throwErr;

            __tmp____Bah_fnNames[210].n = "throwWarning";
            __tmp____Bah_fnNames[210].p = throwWarning;

            __tmp____Bah_fnNames[211].n = "throwWarningLine";
            __tmp____Bah_fnNames[211].p = throwWarningLine;

            __tmp____Bah_fnNames[212].n = "absPath";
            __tmp____Bah_fnNames[212].p = absPath;

            __tmp____Bah_fnNames[213].n = "getCurrentPath";
            __tmp____Bah_fnNames[213].p = getCurrentPath;

            __tmp____Bah_fnNames[214].n = "isInside";
            __tmp____Bah_fnNames[214].p = isInside;

            __tmp____Bah_fnNames[215].n = "setCurrentPath";
            __tmp____Bah_fnNames[215].p = setCurrentPath;

            __tmp____Bah_fnNames[216].n = "isGlobal";
            __tmp____Bah_fnNames[216].p = isGlobal;

            __tmp____Bah_fnNames[217].n = "getRealVar";
            __tmp____Bah_fnNames[217].p = getRealVar;

            __tmp____Bah_fnNames[218].n = "removeVarUnar";
            __tmp____Bah_fnNames[218].p = removeVarUnar;

            __tmp____Bah_fnNames[219].n = "searchVar";
            __tmp____Bah_fnNames[219].p = searchVar;

            __tmp____Bah_fnNames[220].n = "searchVarByToken";
            __tmp____Bah_fnNames[220].p = searchVarByToken;

            __tmp____Bah_fnNames[221].n = "searchVirtVarByToken";
            __tmp____Bah_fnNames[221].p = searchVirtVarByToken;

            __tmp____Bah_fnNames[222].n = "setCType";
            __tmp____Bah_fnNames[222].p = setCType;

            __tmp____Bah_fnNames[223].n = "getTypeFromToken";
            __tmp____Bah_fnNames[223].p = getTypeFromToken;

            __tmp____Bah_fnNames[224].n = "searchFuncByToken";
            __tmp____Bah_fnNames[224].p = searchFuncByToken;

            __tmp____Bah_fnNames[225].n = "RCPavailable";
            __tmp____Bah_fnNames[225].p = RCPavailable;

            __tmp____Bah_fnNames[226].n = "declareStructMethods";
            __tmp____Bah_fnNames[226].p = declareStructMethods;

            __tmp____Bah_fnNames[227].n = "genCompilerVar";
            __tmp____Bah_fnNames[227].p = genCompilerVar;

            __tmp____Bah_fnNames[228].n = "varInArr";
            __tmp____Bah_fnNames[228].p = varInArr;

            __tmp____Bah_fnNames[229].n = "pathToVarName";
            __tmp____Bah_fnNames[229].p = pathToVarName;

            __tmp____Bah_fnNames[230].n = "makeInit";
            __tmp____Bah_fnNames[230].p = makeInit;

            __tmp____Bah_fnNames[231].n = "isOutterScope";
            __tmp____Bah_fnNames[231].p = isOutterScope;

            __tmp____Bah_fnNames[232].n = "decrVar";
            __tmp____Bah_fnNames[232].p = decrVar;

            __tmp____Bah_fnNames[233].n = "incrVar";
            __tmp____Bah_fnNames[233].p = incrVar;

            __tmp____Bah_fnNames[234].n = "beginRCPscope";
            __tmp____Bah_fnNames[234].p = beginRCPscope;

            __tmp____Bah_fnNames[235].n = "beginRCPscopeLeaky";
            __tmp____Bah_fnNames[235].p = beginRCPscopeLeaky;

            __tmp____Bah_fnNames[236].n = "removeDefs";
            __tmp____Bah_fnNames[236].p = removeDefs;

            __tmp____Bah_fnNames[237].n = "endRCPscope";
            __tmp____Bah_fnNames[237].p = endRCPscope;

            __tmp____Bah_fnNames[238].n = "endRCPscopeLeaky";
            __tmp____Bah_fnNames[238].p = endRCPscopeLeaky;

            __tmp____Bah_fnNames[239].n = "registerRCPvar";
            __tmp____Bah_fnNames[239].p = registerRCPvar;

            __tmp____Bah_fnNames[240].n = "RCPselfRef";
            __tmp____Bah_fnNames[240].p = RCPselfRef;

            __tmp____Bah_fnNames[241].n = "verboseOutGuard";
            __tmp____Bah_fnNames[241].p = verboseOutGuard;

            __tmp____Bah_fnNames[242].n = "verboseOutTransformVar";
            __tmp____Bah_fnNames[242].p = verboseOutTransformVar;

            __tmp____Bah_fnNames[243].n = "verboseOutTransformTok";
            __tmp____Bah_fnNames[243].p = verboseOutTransformTok;

            __tmp____Bah_fnNames[244].n = "verboseOutFunc";
            __tmp____Bah_fnNames[244].p = verboseOutFunc;

            __tmp____Bah_fnNames[245].n = "verboseOutOper";
            __tmp____Bah_fnNames[245].p = verboseOutOper;

            __tmp____Bah_fnNames[246].n = "readCache";
            __tmp____Bah_fnNames[246].p = readCache;

            __tmp____Bah_fnNames[247].n = "getCacheFile";
            __tmp____Bah_fnNames[247].p = getCacheFile;

            __tmp____Bah_fnNames[248].n = "updateCacheFile";
            __tmp____Bah_fnNames[248].p = updateCacheFile;

            __tmp____Bah_fnNames[249].n = "makeCacheFile";
            __tmp____Bah_fnNames[249].p = makeCacheFile;

            __tmp____Bah_fnNames[250].n = "writeCache";
            __tmp____Bah_fnNames[250].p = writeCache;

            __tmp____Bah_fnNames[251].n = "isValidCacheFile";
            __tmp____Bah_fnNames[251].p = isValidCacheFile;

            __tmp____Bah_fnNames[252].n = "genArrRealloc";
            __tmp____Bah_fnNames[252].p = genArrRealloc;

            __tmp____Bah_fnNames[253].n = "OPTI_checkFuncScopeRef";
            __tmp____Bah_fnNames[253].p = OPTI_checkFuncScopeRef;

            __tmp____Bah_fnNames[254].n = "debugLine";
            __tmp____Bah_fnNames[254].p = debugLine;

            __tmp____Bah_fnNames[255].n = "dupElems";
            __tmp____Bah_fnNames[255].p = dupElems;

            __tmp____Bah_fnNames[256].n = "getLineType";
            __tmp____Bah_fnNames[256].p = getLineType;

            __tmp____Bah_fnNames[257].n = "parseCast";
            __tmp____Bah_fnNames[257].p = parseCast;

            __tmp____Bah_fnNames[258].n = "getDirFromFile";
            __tmp____Bah_fnNames[258].p = getDirFromFile;

            __tmp____Bah_fnNames[259].n = "parseLines";
            __tmp____Bah_fnNames[259].p = parseLines;

            __tmp____Bah_fnNames[260].n = "includeFile";
            __tmp____Bah_fnNames[260].p = includeFile;

            __tmp____Bah_fnNames[261].n = "parallelObjCompile";
            __tmp____Bah_fnNames[261].p = parallelObjCompile;

            __tmp____Bah_fnNames[262].n = "parseImport";
            __tmp____Bah_fnNames[262].p = parseImport;

            __tmp____Bah_fnNames[263].n = "parseInclude";
            __tmp____Bah_fnNames[263].p = parseInclude;

            __tmp____Bah_fnNames[264].n = "prePross";
            __tmp____Bah_fnNames[264].p = prePross;

            __tmp____Bah_fnNames[265].n = "parseStructType";
            __tmp____Bah_fnNames[265].p = parseStructType;

            __tmp____Bah_fnNames[266].n = "parseArrayType";
            __tmp____Bah_fnNames[266].p = parseArrayType;

            __tmp____Bah_fnNames[267].n = "parsePointers";
            __tmp____Bah_fnNames[267].p = parsePointers;

            __tmp____Bah_fnNames[268].n = "parseSerialize";
            __tmp____Bah_fnNames[268].p = parseSerialize;

            __tmp____Bah_fnNames[269].n = "parseReflect";
            __tmp____Bah_fnNames[269].p = parseReflect;

            __tmp____Bah_fnNames[270].n = "parseArrayDecl";
            __tmp____Bah_fnNames[270].p = parseArrayDecl;

            __tmp____Bah_fnNames[271].n = "parseVar";
            __tmp____Bah_fnNames[271].p = parseVar;

            __tmp____Bah_fnNames[272].n = "getCfunctionType";
            __tmp____Bah_fnNames[272].p = getCfunctionType;

            __tmp____Bah_fnNames[273].n = "parseFnHeader";
            __tmp____Bah_fnNames[273].p = parseFnHeader;

            __tmp____Bah_fnNames[274].n = "parseStruct";
            __tmp____Bah_fnNames[274].p = parseStruct;

            __tmp____Bah_fnNames[275].n = "parseDefine";
            __tmp____Bah_fnNames[275].p = parseDefine;

            __tmp____Bah_fnNames[276].n = "parseClib";
            __tmp____Bah_fnNames[276].p = parseClib;

            __tmp____Bah_fnNames[277].n = "parseConst";
            __tmp____Bah_fnNames[277].p = parseConst;

            __tmp____Bah_fnNames[278].n = "parseReturn";
            __tmp____Bah_fnNames[278].p = parseReturn;

            __tmp____Bah_fnNames[279].n = "parseIf";
            __tmp____Bah_fnNames[279].p = parseIf;

            __tmp____Bah_fnNames[280].n = "parseElse";
            __tmp____Bah_fnNames[280].p = parseElse;

            __tmp____Bah_fnNames[281].n = "parseLine";
            __tmp____Bah_fnNames[281].p = parseLine;

            __tmp____Bah_fnNames[282].n = "parseFor";
            __tmp____Bah_fnNames[282].p = parseFor;

            __tmp____Bah_fnNames[283].n = "parseForOp";
            __tmp____Bah_fnNames[283].p = parseForOp;

            __tmp____Bah_fnNames[284].n = "makeEvalFunc";
            __tmp____Bah_fnNames[284].p = makeEvalFunc;

            __tmp____Bah_fnNames[285].n = "parsePreKeyword";
            __tmp____Bah_fnNames[285].p = parsePreKeyword;

            __tmp____Bah_fnNames[286].n = "parseAsync";
            __tmp____Bah_fnNames[286].p = parseAsync;

            __tmp____Bah_fnNames[287].n = "addRCPvars";
            __tmp____Bah_fnNames[287].p = addRCPvars;

            __tmp____Bah_fnNames[288].n = "parseChan";
            __tmp____Bah_fnNames[288].p = parseChan;

            __tmp____Bah_fnNames[289].n = "valueFunc";
            __tmp____Bah_fnNames[289].p = valueFunc;

            __tmp____Bah_fnNames[290].n = "valueStruct";
            __tmp____Bah_fnNames[290].p = valueStruct;

            __tmp____Bah_fnNames[291].n = "valueArr";
            __tmp____Bah_fnNames[291].p = valueArr;

            __tmp____Bah_fnNames[292].n = "valueBool";
            __tmp____Bah_fnNames[292].p = valueBool;

            __tmp____Bah_fnNames[293].n = "valueOper";
            __tmp____Bah_fnNames[293].p = valueOper;

            __tmp____Bah_fnNames[294].n = "valueSendChan";
            __tmp____Bah_fnNames[294].p = valueSendChan;

            __tmp____Bah_fnNames[295].n = "valueChan";
            __tmp____Bah_fnNames[295].p = valueChan;

            __tmp____Bah_fnNames[296].n = "isSmallValue";
            __tmp____Bah_fnNames[296].p = isSmallValue;

            __tmp____Bah_fnNames[297].n = "isValue";
            __tmp____Bah_fnNames[297].p = isValue;

            __tmp____Bah_fnNames[298].n = "parseFnDeclare";
            __tmp____Bah_fnNames[298].p = parseFnDeclare;

            __tmp____Bah_fnNames[299].n = "declareFunc";
            __tmp____Bah_fnNames[299].p = declareFunc;

            __tmp____Bah_fnNames[300].n = "declareVar";
            __tmp____Bah_fnNames[300].p = declareVar;

            __tmp____Bah_fnNames[301].n = "declareAll";
            __tmp____Bah_fnNames[301].p = declareAll;

            __tmp____Bah_fnNames[302].n = "memErrHandle";
            __tmp____Bah_fnNames[302].p = memErrHandle;

            __tmp____Bah_fnNames[303].n = "main";
            __tmp____Bah_fnNames[303].p = main;

        __Bah_fnNames->data = __tmp____Bah_fnNames;
        __Bah_fnNames->length = 304;
        
    };
    