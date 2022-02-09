//COMPILE WITH: 'gcc linux.c -static -O1 -w  -w /opt/bah/libs/libgc.a -lpthread -lm -O1'

void __BAH_init();
#define noCheck(v) v
#define array(type)	struct{	type *data; long int length; long int elemSize; }
typedef array(char*)* __BAH_ARR_TYPE_cpstring;
long int __BAH__main(__BAH_ARR_TYPE_cpstring);

        #include "/opt/bah/libs/include/gc.h"
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
#define null (void *)0
#define true (int)1
#define false (int)0
#include <sys/mman.h>
#define SIZE_OF_INT 8
#define SIZE_OF_CHAR 1
#define SIZE_OF_INT32 4
#define SIZE_OF_FLOAT32 4
#define SIZE_OF_FLOAT 8
long int len(void * a){
long int i =  0;
noCheck( array ( void* ) *arr = a );
noCheck( i = arr -> length );
long int ____BAH_COMPILER_VAR_0 = i;
return ____BAH_COMPILER_VAR_0;
};
#include </opt/bah/libs/include/gc.h>
void * memoryAlloc(long int s){
void * ____BAH_COMPILER_VAR_1 = GC_MALLOC(s);
return ____BAH_COMPILER_VAR_1;
};
void destroy(void * a){
GC_FREE(a);
};
void clear(void * a){
noCheck( array ( void* ) *arr = a );
noCheck( destroy ( arr -> data ) );
noCheck( arr -> data = memoryAlloc ( sizeof ( 0 ) ) );
noCheck( arr -> length = 0 );
};
void * memoryRealloc(void * p,long int s){
void * ____BAH_COMPILER_VAR_2 = GC_REALLOC(p,s);
return ____BAH_COMPILER_VAR_2;
};
void cleanShutDown(){
exit(1);
return;
};
void append(void * a,void * b){
noCheck( array ( void* ) *arrA = a );
noCheck( array ( void* ) *arrB = b );
long int lenA =  0;
long int lenB =  0;
long int realSizeA =  0;
long int realSizeB =  0;
noCheck( lenA = len ( arrA ) );
noCheck( lenB = len ( arrB ) );
if ((lenB==0)) {
return;
}
if ((lenA==0)) {
noCheck( arrA -> data = arrB -> data );
noCheck( arrA -> length = arrB -> length );
return;
}
noCheck( realSizeA = lenA * arrA -> elemSize );
noCheck( realSizeB = lenB * arrB -> elemSize );
void * buff =  memoryAlloc(realSizeA + realSizeB + 32);
noCheck( memcpy ( buff , arrA -> data , realSizeA ) );
noCheck( memcpy ( buff + lenA , arrB -> data , realSizeB ) );
noCheck( arrA -> length = lenA + lenB );
noCheck( arrA -> data = buff );
};
void copy(void * a,void * b){
noCheck( array ( void* ) *arrA = a );
noCheck( array ( void* ) *arrB = b );
long int lenB =  0;
long int realSizeB =  0;
noCheck( lenB = len ( arrB ) );
noCheck( realSizeB = lenB * arrB -> elemSize );
noCheck( arrA -> data = memoryAlloc ( realSizeB ) );
noCheck( memcpy ( arrA -> data , arrB -> data , realSizeB ) );
noCheck( arrA -> length = arrB -> length );
};
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_READWRITE 3
#define MAP_SHARED 1
#define MAP_ANONYMOUS 32
void * sharedMemory(long int size){
if ((size==0)) {
size =  4096;
}
void * r =  mmap(0,size,PROT_READ + PROT_WRITE,MAP_SHARED + MAP_ANONYMOUS,-1,0);
void * ____BAH_COMPILER_VAR_6 = r;
return ____BAH_COMPILER_VAR_6;
};
void allocateArray(void * arr,long int nbElems){
noCheck( array ( void* ) *a = arr );
noCheck( a -> length = nbElems );
noCheck( a -> data = memoryAlloc ( nbElems * a -> elemSize ) );
};
typedef array(char)* __BAH_ARR_TYPE_char;
__BAH_ARR_TYPE_char ser(void * a);
__BAH_ARR_TYPE_char __serialize(void * a,long int s){
char * r =  memoryAlloc(s + 9);
memcpy(r,&s,8);
memcpy(noCheck( r + 8 ),a,s);
long int l =  s + 1;
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> length = s + 8 );
noCheck( arr -> elemSize = 1 );
noCheck( arr -> data = r );
array(char)* ____BAH_COMPILER_VAR_7 = arr;
return ____BAH_COMPILER_VAR_7;
};
long int serlen(__BAH_ARR_TYPE_char data){

                        if (data->length <= 0) {
                            printf("array (/opt/bah/memory.bah:130): data[%d] with length %d\n", 0, data->length);
                            exit(1);
                        };
                        
                        if (data->length <= 1) {
                            printf("array (/opt/bah/memory.bah:130): data[%d] with length %d\n", 1, data->length);
                            exit(1);
                        };
                        
                        if (data->length <= 2) {
                            printf("array (/opt/bah/memory.bah:130): data[%d] with length %d\n", 2, data->length);
                            exit(1);
                        };
                        
                        if (data->length <= 3) {
                            printf("array (/opt/bah/memory.bah:130): data[%d] with length %d\n", 3, data->length);
                            exit(1);
                        };
                        
                        if (data->length <= 4) {
                            printf("array (/opt/bah/memory.bah:130): data[%d] with length %d\n", 4, data->length);
                            exit(1);
                        };
                        
                        if (data->length <= 5) {
                            printf("array (/opt/bah/memory.bah:130): data[%d] with length %d\n", 5, data->length);
                            exit(1);
                        };
                        
                        if (data->length <= 6) {
                            printf("array (/opt/bah/memory.bah:130): data[%d] with length %d\n", 6, data->length);
                            exit(1);
                        };
                        
                        if (data->length <= 7) {
                            printf("array (/opt/bah/memory.bah:130): data[%d] with length %d\n", 7, data->length);
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
long int ____BAH_COMPILER_VAR_8 = noCheck( *sarr -> data );
return ____BAH_COMPILER_VAR_8;
};
void * unser(__BAH_ARR_TYPE_char data){
long int sptr =  serlen(data);
void * r =  memoryAlloc(sptr);
memcpy(r,noCheck( data -> data + 8 ),sptr);
void * ____BAH_COMPILER_VAR_9 = r;
return ____BAH_COMPILER_VAR_9;
};
char * memoryAllocSTR(long int s){
void * r =  GC_malloc_atomic(s);
memset(r,0,s);
char * ____BAH_COMPILER_VAR_10 = r;
return ____BAH_COMPILER_VAR_10;
};
char * concatCPSTRING(char * a,char * b){
long int lenA =  strlen(a);
long int lenB =  strlen(b);
char * r =  memoryAlloc(lenA + lenB + 1);
strncpy(r,a,lenA);
strcat(r,b);
char * ____BAH_COMPILER_VAR_11 = r;
return ____BAH_COMPILER_VAR_11;
};
char * __STR(char * a){
long int lenA =  strlen(a);
char * r =  memoryAlloc(lenA + 1);
strncpy(r,a,lenA);
char * ____BAH_COMPILER_VAR_12 = r;
return ____BAH_COMPILER_VAR_12;
};
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void print(char * s){
write((void *)1,s,strlen(s));
};
void panic(char * e){
if (strlen(e)) {
print(e);
print("\n");
cleanShutDown();
}
};
void * cArr(void * arr){
noCheck( array ( void* ) *a = arr );
void * ____BAH_COMPILER_VAR_13 = noCheck( a -> data );
return ____BAH_COMPILER_VAR_13;
};
int __checkString(char * s,char * l){
if (((void *)s==null)) {
char * ____BAH_COMPILER_VAR_14 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("cpstring (");
long int strLen_1 = strlen(l);
long int strLen_2 = strlen(") is null \n");
;                            
                        ____BAH_COMPILER_VAR_14 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_14+currStrOff, "cpstring (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_14+currStrOff, l, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_14+currStrOff, ") is null \n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    print(____BAH_COMPILER_VAR_14);
exit(1);
}
int ____BAH_COMPILER_VAR_15 = true;
return ____BAH_COMPILER_VAR_15;
};
#include <pthread.h>
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
struct mutexCondition ____BAH_COMPILER_VAR_16 = {};
____BAH_COMPILER_VAR_16.init = mutexCondition__init;
____BAH_COMPILER_VAR_16.wait = mutexCondition__wait;
____BAH_COMPILER_VAR_16.send = mutexCondition__send;
____BAH_COMPILER_VAR_16.destroy = mutexCondition__destroy;
struct mutexCondition m =  ____BAH_COMPILER_VAR_16;
m.init((struct mutexCondition*)&m);
struct mutexCondition ____BAH_COMPILER_VAR_17 = m;
return ____BAH_COMPILER_VAR_17;
};
struct thread {
long int id;
void (*handle)(void *);
void(*create)(struct thread* this);
void(*createWithArg)(struct thread* this,void * arg);
void(*wait)(struct thread* this);
};
void thread__create(struct thread* this){
GC_pthread_create(&this->id,null,this->handle,null);
};
void thread__createWithArg(struct thread* this,void * arg){
GC_pthread_create(&this->id,null,this->handle,arg);
};
void thread__wait(struct thread* this){
if ((this->id==-1)) {
return;
}
GC_pthread_join(this->id,null);
};
struct mutex mutex(){
struct mutex ____BAH_COMPILER_VAR_19 = {};
____BAH_COMPILER_VAR_19.init = mutex__init;
____BAH_COMPILER_VAR_19.lock = mutex__lock;
____BAH_COMPILER_VAR_19.unlock = mutex__unlock;
____BAH_COMPILER_VAR_19.destroy = mutex__destroy;
struct mutex m =  ____BAH_COMPILER_VAR_19;
m.init((struct mutex*)&m);
struct mutex ____BAH_COMPILER_VAR_20 = m;
return ____BAH_COMPILER_VAR_20;
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
struct queueNode* node = memoryAlloc(sizeof(struct queueNode));
node->data= null;
node->next= null;
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
void * ____BAH_COMPILER_VAR_23 = zp;
return ____BAH_COMPILER_VAR_23;
}
struct queueNode* ptr =  this->head;
while ((ptr->key!=key)) {
if ((ptr->next==null)) {
void * ____BAH_COMPILER_VAR_24 = zp;
return ____BAH_COMPILER_VAR_24;
}
ptr =  ptr->next;
};
void * data =  ptr->data;
void * ____BAH_COMPILER_VAR_25 = data;
return ____BAH_COMPILER_VAR_25;
};
void queue__set(struct queue* this,long int key,void * data){
this->delete((struct queue*)this,key);
struct queueNode* node = memoryAlloc(sizeof(struct queueNode));
node->data= null;
node->next= null;
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
void * ____BAH_COMPILER_VAR_26 = data;
return ____BAH_COMPILER_VAR_26;
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
void * ____BAH_COMPILER_VAR_27 = data;
return ____BAH_COMPILER_VAR_27;
};
void channel__destroy(struct channel* this){
pthread_mutex_destroy(&this->m_mut);
pthread_cond_destroy(&this->w_cond);
pthread_cond_destroy(&this->r_cond);
};
long int channel__len(struct channel* this){
long int l =  this->queue->length;
long int ____BAH_COMPILER_VAR_28 = l;
return ____BAH_COMPILER_VAR_28;
};
struct channel* channel(){
struct channel* c = memoryAlloc(sizeof(struct channel));
c->w_waitting = 0;
c->r_waitting = 0;
c->queue= null;
c->cap = -1;
c->send = channel__send;
c->sendAny = channel__sendAny;
c->receive = channel__receive;
c->destroy = channel__destroy;
c->len = channel__len;
pthread_mutex_init(&c->m_mut,0);
pthread_cond_init(&c->w_cond,0);
pthread_cond_init(&c->r_cond,0);
c->queue = memoryAlloc(sizeof(struct queue));
c->queue->length = 0;
c->queue->head= null;
c->queue->insert = queue__insert;
c->queue->delete = queue__delete;
c->queue->get = queue__get;
c->queue->set = queue__set;
c->queue->pop = queue__pop;
c->queue->clear = queue__clear;
struct channel* ____BAH_COMPILER_VAR_29 = c;
return ____BAH_COMPILER_VAR_29;
};
void setChanCap(void * c,long int cap){
struct channel* cp =  c;
cp->cap =  cap;
};
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <math.h>
void strCatOffset(char * dest,long int destLen,char * src,long int srcLen){
memcpy(noCheck( dest + destLen ),src,srcLen);
};
char cpstringCharAt(char * s,long int i){
char c =  (char)0;
noCheck( c = s [ i ] );
char ____BAH_COMPILER_VAR_30 = c;
return ____BAH_COMPILER_VAR_30;
};
char * charToString(char c){
char * s =  memoryAlloc(2);
strncpy(s,(char *)&c,1);
char * ____BAH_COMPILER_VAR_31 = s;
return ____BAH_COMPILER_VAR_31;
};
long int isUpper(char c){
if ((c>(char)64)) {
if ((c<(char)91)) {
long int ____BAH_COMPILER_VAR_32 = 1;
return ____BAH_COMPILER_VAR_32;
}
}
long int ____BAH_COMPILER_VAR_33 = 0;
return ____BAH_COMPILER_VAR_33;
};
long int isLower(char c){
if ((c>(char)96)) {
if ((c<(char)123)) {
long int ____BAH_COMPILER_VAR_34 = 1;
return ____BAH_COMPILER_VAR_34;
}
}
long int ____BAH_COMPILER_VAR_35 = 0;
return ____BAH_COMPILER_VAR_35;
};
long int isLetter(char s){
if (isUpper(s)) {
long int ____BAH_COMPILER_VAR_36 = 1;
return ____BAH_COMPILER_VAR_36;
}
if (isLower(s)) {
long int ____BAH_COMPILER_VAR_37 = 1;
return ____BAH_COMPILER_VAR_37;
}
long int ____BAH_COMPILER_VAR_38 = 0;
return ____BAH_COMPILER_VAR_38;
};
long int isNumber(char c){
if ((c>(char)47)) {
if ((c<(char)58)) {
long int ____BAH_COMPILER_VAR_39 = 1;
return ____BAH_COMPILER_VAR_39;
}
}
long int ____BAH_COMPILER_VAR_40 = 0;
return ____BAH_COMPILER_VAR_40;
};
long int isAlphaNumeric(char s){
if (isLetter(s)) {
long int ____BAH_COMPILER_VAR_41 = 1;
return ____BAH_COMPILER_VAR_41;
}
if (isNumber(s)) {
long int ____BAH_COMPILER_VAR_42 = 1;
return ____BAH_COMPILER_VAR_42;
}
long int ____BAH_COMPILER_VAR_43 = 0;
return ____BAH_COMPILER_VAR_43;
};
long int isSpace(char c){
if ((c==(char)32)) {
long int ____BAH_COMPILER_VAR_44 = 1;
return ____BAH_COMPILER_VAR_44;
}
if ((c==(char)9)) {
long int ____BAH_COMPILER_VAR_45 = 1;
return ____BAH_COMPILER_VAR_45;
}
if ((c==(char)10)) {
long int ____BAH_COMPILER_VAR_46 = 1;
return ____BAH_COMPILER_VAR_46;
}
if ((c==(char)11)) {
long int ____BAH_COMPILER_VAR_47 = 1;
return ____BAH_COMPILER_VAR_47;
}
if ((c==(char)13)) {
long int ____BAH_COMPILER_VAR_48 = 1;
return ____BAH_COMPILER_VAR_48;
}
long int ____BAH_COMPILER_VAR_49 = 0;
return ____BAH_COMPILER_VAR_49;
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
panic("Error appending to string, possibly due to memory shortage.");
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
panic("Error appending to string, possibly due to memory shortage.");
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
noCheck( c = this -> content [ i ] );
char ____BAH_COMPILER_VAR_50 = c;
return ____BAH_COMPILER_VAR_50;
}
char ____BAH_COMPILER_VAR_51 = c;
return ____BAH_COMPILER_VAR_51;
};
long int string__compare(struct string* this,char * s){
long int r =  strcmp(this->content,s);
if ((r==0)) {
long int ____BAH_COMPILER_VAR_52 = 1;
return ____BAH_COMPILER_VAR_52;
}
long int ____BAH_COMPILER_VAR_53 = 0;
return ____BAH_COMPILER_VAR_53;
};
char * string__str(struct string* this){
char * s =  this->content;
char * ____BAH_COMPILER_VAR_54 = s;
return ____BAH_COMPILER_VAR_54;
};
void string__replace(struct string* this,char * nd,char * rl){
struct string ____BAH_COMPILER_VAR_55 = {};
____BAH_COMPILER_VAR_55.content= null;
____BAH_COMPILER_VAR_55.set = string__set;
____BAH_COMPILER_VAR_55.append = string__append;
____BAH_COMPILER_VAR_55.prepend = string__prepend;
____BAH_COMPILER_VAR_55.charAt = string__charAt;
____BAH_COMPILER_VAR_55.compare = string__compare;
____BAH_COMPILER_VAR_55.str = string__str;
____BAH_COMPILER_VAR_55.replace = string__replace;
struct string needle =  ____BAH_COMPILER_VAR_55;
needle.set((struct string*)&needle,nd);
struct string ____BAH_COMPILER_VAR_56 = {};
____BAH_COMPILER_VAR_56.content= null;
____BAH_COMPILER_VAR_56.set = string__set;
____BAH_COMPILER_VAR_56.append = string__append;
____BAH_COMPILER_VAR_56.prepend = string__prepend;
____BAH_COMPILER_VAR_56.charAt = string__charAt;
____BAH_COMPILER_VAR_56.compare = string__compare;
____BAH_COMPILER_VAR_56.str = string__str;
____BAH_COMPILER_VAR_56.replace = string__replace;
struct string repl =  ____BAH_COMPILER_VAR_56;
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
char * ____BAH_COMPILER_VAR_57 =arrAsStr(replbuffStr);char * ____BAH_COMPILER_VAR_58 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_57);
;                            
                        ____BAH_COMPILER_VAR_58 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_58+currStrOff, r, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_58+currStrOff, ____BAH_COMPILER_VAR_57, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    r =  ____BAH_COMPILER_VAR_58;
}
if (((void *)r!=null)) {
this->set((struct string*)this,r);
}
};
long int string__count(struct string* this,char * need){
long int i =  0;
long int count =  0;
struct string ____BAH_COMPILER_VAR_59 = {};
____BAH_COMPILER_VAR_59.content= null;
____BAH_COMPILER_VAR_59.set = string__set;
____BAH_COMPILER_VAR_59.append = string__append;
____BAH_COMPILER_VAR_59.prepend = string__prepend;
____BAH_COMPILER_VAR_59.charAt = string__charAt;
____BAH_COMPILER_VAR_59.compare = string__compare;
____BAH_COMPILER_VAR_59.str = string__str;
____BAH_COMPILER_VAR_59.replace = string__replace;
____BAH_COMPILER_VAR_59.count = string__count;
struct string needle =  ____BAH_COMPILER_VAR_59;
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
long int ____BAH_COMPILER_VAR_60 = count;
return ____BAH_COMPILER_VAR_60;
};
long int string__hasPrefix(struct string* this,char * need){
long int i =  0;
long int nl =  strlen(need);
if ((this->length<nl)) {
long int ____BAH_COMPILER_VAR_61 = 0;
return ____BAH_COMPILER_VAR_61;
}
while ((i<nl)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,i);
if ((c!=sc)) {
long int ____BAH_COMPILER_VAR_62 = 0;
return ____BAH_COMPILER_VAR_62;
}
i =  i + 1;
};
long int ____BAH_COMPILER_VAR_63 = 1;
return ____BAH_COMPILER_VAR_63;
};
long int string__hasSuffix(struct string* this,char * need){
long int nl =  strlen(need);
if ((this->length<nl)) {
long int ____BAH_COMPILER_VAR_64 = 0;
return ____BAH_COMPILER_VAR_64;
}
long int i =  this->length - nl;
long int needleIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,needleIndex);
if ((c!=sc)) {
long int ____BAH_COMPILER_VAR_65 = 0;
return ____BAH_COMPILER_VAR_65;
}
needleIndex =  needleIndex + 1;
i =  i + 1;
};
long int ____BAH_COMPILER_VAR_66 = 1;
return ____BAH_COMPILER_VAR_66;
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
memcpy(tmpS,noCheck( this->content + i ),this->length + 1);
this->content =  tmpS;
}
};
void string__trimLeft(struct string* this,long int s){
long int nSize =  this->length - s;
void * tmpS =  memoryAlloc(nSize);
memcpy(tmpS,noCheck( this->content + s ),nSize);
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
struct string ____BAH_COMPILER_VAR_69 = {};
____BAH_COMPILER_VAR_69.content= null;
____BAH_COMPILER_VAR_69.set = string__set;
____BAH_COMPILER_VAR_69.append = string__append;
____BAH_COMPILER_VAR_69.prepend = string__prepend;
____BAH_COMPILER_VAR_69.charAt = string__charAt;
____BAH_COMPILER_VAR_69.compare = string__compare;
____BAH_COMPILER_VAR_69.str = string__str;
____BAH_COMPILER_VAR_69.replace = string__replace;
____BAH_COMPILER_VAR_69.count = string__count;
____BAH_COMPILER_VAR_69.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_69.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_69.trim = string__trim;
____BAH_COMPILER_VAR_69.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_69.trimRight = string__trimRight;
____BAH_COMPILER_VAR_69.add = string__add;
struct string r =  ____BAH_COMPILER_VAR_69;
r.length =  this->length + s2.length;
r.content =  memoryAlloc(r.length + 1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
struct string ____BAH_COMPILER_VAR_70 = r;
return ____BAH_COMPILER_VAR_70;
};
struct string string(char * s){
struct string ____BAH_COMPILER_VAR_71 = {};
____BAH_COMPILER_VAR_71.content= null;
____BAH_COMPILER_VAR_71.set = string__set;
____BAH_COMPILER_VAR_71.append = string__append;
____BAH_COMPILER_VAR_71.prepend = string__prepend;
____BAH_COMPILER_VAR_71.charAt = string__charAt;
____BAH_COMPILER_VAR_71.compare = string__compare;
____BAH_COMPILER_VAR_71.str = string__str;
____BAH_COMPILER_VAR_71.replace = string__replace;
____BAH_COMPILER_VAR_71.count = string__count;
____BAH_COMPILER_VAR_71.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_71.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_71.trim = string__trim;
____BAH_COMPILER_VAR_71.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_71.trimRight = string__trimRight;
____BAH_COMPILER_VAR_71.add = string__add;
struct string a =  ____BAH_COMPILER_VAR_71;
a.set((struct string*)&a,s);
struct string ____BAH_COMPILER_VAR_72 = a;
return ____BAH_COMPILER_VAR_72;
};
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen =  len(arr);
char * str =  memoryAlloc(strLen + 1);
noCheck( memcpy ( str , arr -> data , strLen ) );
char * ____BAH_COMPILER_VAR_73 = str;
return ____BAH_COMPILER_VAR_73;
};
__BAH_ARR_TYPE_char strToArr(char * str){
long int strLen =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> data = memoryAlloc ( strLen + 1 ) );
noCheck( memcpy ( arr -> data , str , strLen ) );
noCheck( arr -> length = strLen );
array(char)* ____BAH_COMPILER_VAR_74 = arr;
return ____BAH_COMPILER_VAR_74;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr){
char * ____BAH_COMPILER_VAR_75 = noCheck( arr -> data );
return ____BAH_COMPILER_VAR_75;
};
__BAH_ARR_TYPE_char strAsArr(char * str){
long int l =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> length = l );
noCheck( arr -> data = str );
array(char)* ____BAH_COMPILER_VAR_76 = arr;
return ____BAH_COMPILER_VAR_76;
};
char * intToStr(long int i){
if ((i==0)) {
char * ____BAH_COMPILER_VAR_77 = "0";
return ____BAH_COMPILER_VAR_77;
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
                            printf("array (/opt/bah/string.bah:442): s[%d] with length %d\n", i, s->length);
                            exit(1);
                        };
                        char osi =  s->data[i];

                        if (s->length <= ii) {
                            printf("array (/opt/bah/string.bah:443): s[%d] with length %d\n", ii, s->length);
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
char * ____BAH_COMPILER_VAR_78 = arrAsStr(s);
return ____BAH_COMPILER_VAR_78;
};
struct string intToString(long int i){
char * ____BAH_COMPILER_VAR_79 =intToStr(i);struct string r =  string(____BAH_COMPILER_VAR_79);
struct string ____BAH_COMPILER_VAR_80 = r;
return ____BAH_COMPILER_VAR_80;
};
char * floatToStr(double f){
char * buff =  memoryAlloc(50);
sprintf(buff,"%lf",f);
char * ____BAH_COMPILER_VAR_81 = buff;
return ____BAH_COMPILER_VAR_81;
};
long int strToInt(char * s){
long int ____BAH_COMPILER_VAR_82 = atol(s);
return ____BAH_COMPILER_VAR_82;
};
double strToFloat(char * s){
double ____BAH_COMPILER_VAR_83 = strtod(s,null);
return ____BAH_COMPILER_VAR_83;
};
long int stringToInt(struct string s){
long int i =  atol(s.content);
long int ____BAH_COMPILER_VAR_84 = i;
return ____BAH_COMPILER_VAR_84;
};
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
char * ____BAH_COMPILER_VAR_85 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_85);
}
else {
if ((sepIndex>0)) {
sepIndex =  0;
char * ____BAH_COMPILER_VAR_86 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_86);
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
struct string* elem = memoryAlloc(sizeof(struct string));
elem->content= null;
elem->set = string__set;
elem->append = string__append;
elem->prepend = string__prepend;
elem->charAt = string__charAt;
elem->compare = string__compare;
elem->str = string__str;
elem->replace = string__replace;
elem->count = string__count;
elem->hasPrefix = string__hasPrefix;
elem->hasSuffix = string__hasSuffix;
elem->trim = string__trim;
elem->trimLeft = string__trimLeft;
elem->trimRight = string__trimRight;
elem->add = string__add;
char * ____BAH_COMPILER_VAR_87 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_87);
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
struct string* elem = memoryAlloc(sizeof(struct string));
elem->content= null;
elem->set = string__set;
elem->append = string__append;
elem->prepend = string__prepend;
elem->charAt = string__charAt;
elem->compare = string__compare;
elem->str = string__str;
elem->replace = string__replace;
elem->count = string__count;
elem->hasPrefix = string__hasPrefix;
elem->hasSuffix = string__hasSuffix;
elem->trim = string__trim;
elem->trimLeft = string__trimLeft;
elem->trimRight = string__trimRight;
elem->add = string__add;
char * ____BAH_COMPILER_VAR_88 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_88);
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
array(struct string)* ____BAH_COMPILER_VAR_89 = res;
return ____BAH_COMPILER_VAR_89;
};
struct string joinString(__BAH_ARR_TYPE_string a,char * sep){
long int i =  0;
struct string s =  string("");
long int max =  len(a) - 1;
while ((i<len(a))) {

                        if (a->length <= i) {
                            printf("array (/opt/bah/string.bah:555): a[%d] with length %d\n", i, a->length);
                            exit(1);
                        };
                        struct string e =  a->data[i];
if ((e.length==0)) {
i =  i + 1;
continue;
}
char * ____BAH_COMPILER_VAR_90 =e.str((struct string*)&e);struct string tmpS =  string(____BAH_COMPILER_VAR_90);
if ((i!=max)) {
tmpS.append((struct string*)&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_91 =tmpS.str((struct string*)&tmpS);s.append((struct string*)&s,____BAH_COMPILER_VAR_91);
i =  i + 1;
};
struct string ____BAH_COMPILER_VAR_92 = s;
return ____BAH_COMPILER_VAR_92;
};
char * splitStringBefore(struct string s,char * sp){
struct string sep =  string(sp);
if ((sep.length>=s.length)) {
char * ____BAH_COMPILER_VAR_93 = "";
return ____BAH_COMPILER_VAR_93;
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
char * ____BAH_COMPILER_VAR_94 = s.str((struct string*)&s);
return ____BAH_COMPILER_VAR_94;
}
}
else {
foundIndex =  0;
sepIndex =  0;
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_95 = "";
return ____BAH_COMPILER_VAR_95;
};
struct string toLower(struct string s){
array(char)* ns = memoryAlloc(sizeof(array(char)));

ns->length = 0;
ns->elemSize = sizeof(char);
long int i =  0;
while ((i<s.length)) {
char c =  s.charAt((struct string*)&s,i);
if (isUpper(c)) {
c =  c + (char)32;
}

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
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_96 =arrToStr(ns);struct string ____BAH_COMPILER_VAR_97 = string(____BAH_COMPILER_VAR_96);
return ____BAH_COMPILER_VAR_97;
};
int strHasPrefix(char * s,char * need){
long int i =  0;
long int nl =  strlen(need);
long int sl =  strlen(s);
if ((sl<nl)) {
int ____BAH_COMPILER_VAR_98 = false;
return ____BAH_COMPILER_VAR_98;
}
while ((i<nl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
int ____BAH_COMPILER_VAR_99 = false;
return ____BAH_COMPILER_VAR_99;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_100 = true;
return ____BAH_COMPILER_VAR_100;
};
int strHasSuffix(char * s,char * need){
long int sl =  strlen(s);
long int nl =  strlen(need);
if ((nl>sl)) {
int ____BAH_COMPILER_VAR_101 = false;
return ____BAH_COMPILER_VAR_101;
}
long int i =  sl - nl;
while ((i<sl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
int ____BAH_COMPILER_VAR_102 = false;
return ____BAH_COMPILER_VAR_102;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_103 = true;
return ____BAH_COMPILER_VAR_103;
};
void strTrimLeft(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i + 1);
memcpy(ns,noCheck( *s + i ),ls - i);
*s =  ns;
};
void strTrimRight(char ** s,long int i){
long int ls =  strlen(*s);
char * ns =  memoryAlloc(ls - i + 1);
memcpy(ns,*s,ls - i);
*s =  ns;
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
*s =  noCheck( *s + i );
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
long int ____BAH_COMPILER_VAR_104 = count;
return ____BAH_COMPILER_VAR_104;
};
char * stdinput(long int len){
char * buff =  memoryAlloc(len);
fgets(buff,len,noCheck( stdin ));
char * ____BAH_COMPILER_VAR_105 = buff;
return ____BAH_COMPILER_VAR_105;
};
void println(char * s){
char * ____BAH_COMPILER_VAR_106 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_106 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_106+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_106+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    write((void *)1,____BAH_COMPILER_VAR_106,strlen(s) + 1);
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
long int ____BAH_COMPILER_VAR_107 = 0;
return ____BAH_COMPILER_VAR_107;
}
long int ____BAH_COMPILER_VAR_108 = 1;
return ____BAH_COMPILER_VAR_108;
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
long int ____BAH_COMPILER_VAR_110 = 0;
return ____BAH_COMPILER_VAR_110;
}
long int ____BAH_COMPILER_VAR_111 = ftell(this->handle);
return ____BAH_COMPILER_VAR_111;
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((this->isValid((struct fileStream*)this)==0)) {
return;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
long int ____BAH_COMPILER_VAR_113 = -1;
return ____BAH_COMPILER_VAR_113;
}
long int oldPos =  this->getPos((struct fileStream*)this);
fseek(this->handle,0,2);
long int size =  ftell(this->handle);
this->setPos((struct fileStream*)this,oldPos);
long int ____BAH_COMPILER_VAR_114 = size;
return ____BAH_COMPILER_VAR_114;
};
void fileStream__rewind(struct fileStream* this){
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){
char c =  getc(this->handle);
char ____BAH_COMPILER_VAR_115 = c;
return ____BAH_COMPILER_VAR_115;
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
long int ____BAH_COMPILER_VAR_116 = -1;
return ____BAH_COMPILER_VAR_116;
}
fputs(content,this->handle);
long int ____BAH_COMPILER_VAR_117 = 1;
return ____BAH_COMPILER_VAR_117;
};
void fileStream__writePtr(struct fileStream* this,void * a,long int s){
fwrite(a,s,1,this->handle);
};
long int fileStream__readPtr(struct fileStream* this,void * a,long int s){
long int ____BAH_COMPILER_VAR_118 = fread(a,s,1,this->handle);
return ____BAH_COMPILER_VAR_118;
};
char * fileStream__readContent(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
char * ____BAH_COMPILER_VAR_119 = "invalid";
return ____BAH_COMPILER_VAR_119;
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
char * ____BAH_COMPILER_VAR_120 = r;
return ____BAH_COMPILER_VAR_120;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,this->getSize((struct fileStream*)this));
this->readPtr((struct fileStream*)this,noCheck( r -> data ),len(r));
array(char)* ____BAH_COMPILER_VAR_121 = r;
return ____BAH_COMPILER_VAR_121;
};
void fileStream__writeBytes(struct fileStream* this,__BAH_ARR_TYPE_char d){
this->writePtr((struct fileStream*)this,noCheck( d -> data ),len(d));
};
struct fileMap {
long int handle;
long int size;
char *(*open)(struct fileMap* this,char * fileName);
long int(*isValid)(struct fileMap* this);
void(*close)(struct fileMap* this);
};
char * fileMap__open(struct fileMap* this,char * fileName){
this->handle =  open(fileName,noCheck( O_RDWR ),noCheck( S_IRUSR | S_IWUSR ));
struct stat ____BAH_COMPILER_VAR_122 = {};
struct stat sb =  ____BAH_COMPILER_VAR_122;
fstat(this->handle,&sb);
this->size =  sb.st_size;
char * file =  mmap(0,sb.st_size,noCheck( PROT_READ | PROT_WRITE ),noCheck( MAP_SHARED ),this->handle,0);
char * ____BAH_COMPILER_VAR_123 = file;
return ____BAH_COMPILER_VAR_123;
};
long int fileMap__isValid(struct fileMap* this){
if ((this->handle<0)) {
long int ____BAH_COMPILER_VAR_124 = 0;
return ____BAH_COMPILER_VAR_124;
}
long int ____BAH_COMPILER_VAR_125 = 1;
return ____BAH_COMPILER_VAR_125;
};
void fileMap__close(struct fileMap* this){
close(this->handle);
};
__BAH_ARR_TYPE_cpstring listFiles(char * dir){
array(char *)* files = memoryAlloc(sizeof(array(char *)));

files->length = 0;
files->elemSize = sizeof(char *);
DIR* d =  opendir(dir);
struct dirent* file =  readdir(d);
while ((file!=null)) {
long int lf =  len(files);
if ((strcmp(file->d_name,".")==0)) {
file =  readdir(d);
continue;
}
if ((strcmp(file->d_name,"..")==0)) {
file =  readdir(d);
continue;
}

{
long nLength = lf;
if (files->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(files->data, (nLength+50)*sizeof(char *));
files->data = newPtr;
}
files->data[lf] =  __STR(file->d_name);
files->length = nLength+1;
} else {
files->data[lf] =  __STR(file->d_name);
}
};
file =  readdir(d);
};
closedir(d);
array(char *)* ____BAH_COMPILER_VAR_126 = files;
return ____BAH_COMPILER_VAR_126;
};
long int fileExists(char * path){
long int is =  access(path,0);
if ((is==0)) {
long int ____BAH_COMPILER_VAR_127 = 1;
return ____BAH_COMPILER_VAR_127;
}
long int ____BAH_COMPILER_VAR_128 = 0;
return ____BAH_COMPILER_VAR_128;
};
int removeFile(char * name){
if ((remove(name)==0)) {
int ____BAH_COMPILER_VAR_129 = true;
return ____BAH_COMPILER_VAR_129;
}
int ____BAH_COMPILER_VAR_130 = false;
return ____BAH_COMPILER_VAR_130;
};
long int getLastModified(char * name){
struct stat attr;
stat(name,&attr);
long int ____BAH_COMPILER_VAR_131 = attr.st_ctime;
return ____BAH_COMPILER_VAR_131;
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
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name= null;
f->help= null;
f->content= null;
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
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name= null;
f->help= null;
f->content= null;
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
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name= null;
f->help= null;
f->content= null;
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
struct flag* f = memoryAlloc(sizeof(struct flag));
f->name= null;
f->help= null;
f->content= null;
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
struct flag* ____BAH_COMPILER_VAR_132 = flag;
return ____BAH_COMPILER_VAR_132;
}
i =  i + 1;
};
struct flag* z = memoryAlloc(sizeof(struct flag));
z->name= null;
z->help= null;
z->content= null;
z->isSet =  0;
struct flag* ____BAH_COMPILER_VAR_133 = z;
return ____BAH_COMPILER_VAR_133;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_134 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_134);
char * ctn =  flag->content;
char * ____BAH_COMPILER_VAR_135 = ctn;
return ____BAH_COMPILER_VAR_135;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_136 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_136);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_137 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not int.");
;                            
                        ____BAH_COMPILER_VAR_137 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_137+currStrOff, "Flag '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_137+currStrOff, flag->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_137+currStrOff, "' is not int.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * error =  ____BAH_COMPILER_VAR_137;
panic(error);
}
long int ctn =  flag->cont_int;
long int ____BAH_COMPILER_VAR_138 = ctn;
return ____BAH_COMPILER_VAR_138;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_139 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_139);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_140 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not float.");
;                            
                        ____BAH_COMPILER_VAR_140 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_140+currStrOff, "Flag '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_140+currStrOff, flag->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_140+currStrOff, "' is not float.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * error =  ____BAH_COMPILER_VAR_140;
panic(error);
}
double ctn =  flag->cont_float;
double ____BAH_COMPILER_VAR_141 = ctn;
return ____BAH_COMPILER_VAR_141;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_142 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_142);
long int ctn =  flag->isSet;
long int ____BAH_COMPILER_VAR_143 = ctn;
return ____BAH_COMPILER_VAR_143;
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
char * ____BAH_COMPILER_VAR_144 =argName.str((struct string*)&argName);currentFlag->cont_int =  atoi(____BAH_COMPILER_VAR_144);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_145 =argName.str((struct string*)&argName);currentFlag->cont_float =  strtod(____BAH_COMPILER_VAR_145,0);
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
char * ____BAH_COMPILER_VAR_146 = date;
return ____BAH_COMPILER_VAR_146;
};
long int time__since(struct time* this){
long int nt =  time(0);
long int r =  nt - this->timestamp;
long int ____BAH_COMPILER_VAR_147 = r;
return ____BAH_COMPILER_VAR_147;
};
long int getTimeUnix(){
struct timespec ____BAH_COMPILER_VAR_148 = {};
struct timespec ts =  ____BAH_COMPILER_VAR_148;
timespec_get(&ts,noCheck( TIME_UTC ));
long int s =  ts.tv_sec * 1000000000 + ts.tv_nsec;
long int ____BAH_COMPILER_VAR_149 = s;
return ____BAH_COMPILER_VAR_149;
};
long int RAND_SEEDED;
void seedRandom(long int i){
srand(i);
RAND_SEEDED =  1;
};
long int randomInRange(long int min,long int max){
if ((RAND_SEEDED==0)) {
srand(time(0) + getTimeUnix());
RAND_SEEDED =  1;
}
long int range =  max - min;
long int i =  rand() % range + 1;
i =  i + min;
long int ____BAH_COMPILER_VAR_150 = i;
return ____BAH_COMPILER_VAR_150;
};
long int cryptoRand(){
struct fileStream ____BAH_COMPILER_VAR_151 = {};
____BAH_COMPILER_VAR_151.handle= null;
____BAH_COMPILER_VAR_151.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_151.open = fileStream__open;
____BAH_COMPILER_VAR_151.close = fileStream__close;
____BAH_COMPILER_VAR_151.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_151.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_151.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_151.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_151.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_151.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_151.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_151.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_151.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_151.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_151.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_151.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_151.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_151;
fs.open((struct fileStream*)&fs,"/dev/urandom","r");
char c =  fs.getChar((struct fileStream*)&fs);
fs.close((struct fileStream*)&fs);
long int i =  (long int)c;
long int ____BAH_COMPILER_VAR_152 = i;
return ____BAH_COMPILER_VAR_152;
};
struct command {
char * command;
int error;
long int status;
FILE* handle;
char *(*run)(struct command* this);
array(char)*(*runBytes)(struct command* this);
};
char * command__run(struct command* this){
char * cm =  this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_153 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                        ____BAH_COMPILER_VAR_153 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_153+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_153+currStrOff, " 2>/dev/null", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_153;
}
else {
char * ____BAH_COMPILER_VAR_154 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                        ____BAH_COMPILER_VAR_154 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_154+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_154+currStrOff, " 2>&1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_154;
}
this->handle =  popen(cm,"r");
if ((this->handle==null)) {
char * ____BAH_COMPILER_VAR_155 = "";
return ____BAH_COMPILER_VAR_155;
}
char * buff =  memoryAlloc(1025);
char * res =  "";
while (((void *)fgets(buff,1024,this->handle)!=null)) {
char * ____BAH_COMPILER_VAR_156 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(res);
long int strLen_1 = strlen(buff);
;                            
                        ____BAH_COMPILER_VAR_156 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_156+currStrOff, res, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_156+currStrOff, buff, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    res =  ____BAH_COMPILER_VAR_156;
};
this->status =  pclose(this->handle);
char * ____BAH_COMPILER_VAR_157 = res;
return ____BAH_COMPILER_VAR_157;
};
__BAH_ARR_TYPE_char command__runBytes(struct command* this){
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
char * cm =  this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_158 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                        ____BAH_COMPILER_VAR_158 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_158+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_158+currStrOff, " 2>/dev/null", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_158;
}
else {
char * ____BAH_COMPILER_VAR_159 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                        ____BAH_COMPILER_VAR_159 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_159+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_159+currStrOff, " 2>&1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_159;
}
this->handle =  popen(cm,"r");
if ((this->handle==null)) {
array(char)* ____BAH_COMPILER_VAR_160 = arr;
return ____BAH_COMPILER_VAR_160;
}
char * buffer =  memoryAlloc(1025);
struct string response =  string("");
long int total =  0;
long int fd =  fileno(this->handle);
long int nDataLength =  read((void *)fd,buffer,1024);
if ((nDataLength<1024)) {
total =  nDataLength;
response.append((struct string*)&response,buffer);
}
else {
while ((nDataLength>0)) {
total =  total + nDataLength;
response.append((struct string*)&response,buffer);
if ((nDataLength<1024)) {
long int trimAmm =  1024 - nDataLength;
response.trimRight((struct string*)&response,trimAmm);
break;
}
else {
nDataLength =  read((void *)fd,buffer,1024);
}
};
}
this->status =  pclose(this->handle);
noCheck( arr -> data = response.content );
noCheck( arr -> length = total );
array(char)* ____BAH_COMPILER_VAR_161 = arr;
return ____BAH_COMPILER_VAR_161;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_162 = {};
____BAH_COMPILER_VAR_162.command= null;
____BAH_COMPILER_VAR_162.error = true;
____BAH_COMPILER_VAR_162.status = 0;
____BAH_COMPILER_VAR_162.handle= null;
____BAH_COMPILER_VAR_162.run = command__run;
____BAH_COMPILER_VAR_162.runBytes = command__runBytes;
struct command cmd =  ____BAH_COMPILER_VAR_162;
cmd.command =  s;
struct command ____BAH_COMPILER_VAR_163 = cmd;
return ____BAH_COMPILER_VAR_163;
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
nArgs->data[0] =  s;
nArgs->length = nLength+1;
} else {
nArgs->data[0] =  s;
}
};
long int i =  0;
while ((i<len(args))) {

                        if (args->length <= i) {
                            printf("array (/opt/bah/exec.bah:100): args[%d] with length %d\n", i, args->length);
                            exit(1);
                        };
                        
{
long nLength = i + 1;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i + 1] =  args->data[i];
nArgs->length = nLength+1;
} else {
nArgs->data[i + 1] =  args->data[i];
}
};
i =  i + 1;
};

{
long nLength = i + 2;
if (nArgs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nArgs->data, (nLength+50)*sizeof(char *));
nArgs->data = newPtr;
}
nArgs->data[i + 2] =  (char *)0;
nArgs->length = nLength+1;
} else {
nArgs->data[i + 2] =  (char *)0;
}
};
noCheck( r = execvp ( s , nArgs -> data ) );
long int ____BAH_COMPILER_VAR_164 = r;
return ____BAH_COMPILER_VAR_164;
};
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
struct rope* ____BAH_COMPILER_VAR_165 = this;
return ____BAH_COMPILER_VAR_165;
}
struct rope* ____BAH_COMPILER_VAR_166 = this->parent->getParent((struct rope*)this->parent);
return ____BAH_COMPILER_VAR_166;
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
char * ____BAH_COMPILER_VAR_168 = this->str;
return ____BAH_COMPILER_VAR_168;
}
char * s =  memoryAlloc(this->totalLen + 1);
this->left->addStr((struct rope*)this->left,&s);
this->right->addStr((struct rope*)this->right,&s);
char * ____BAH_COMPILER_VAR_169 = s;
return ____BAH_COMPILER_VAR_169;
};
struct rope* rope__add(struct rope* this,struct rope* root2){
long int n1 =  this->len;
struct rope* tmp = memoryAlloc(sizeof(struct rope));
tmp->left= null;
tmp->right= null;
tmp->parent= null;
tmp->str= null;
tmp->getParent = rope__getParent;
tmp->addStr = rope__addStr;
tmp->toStr = rope__toStr;
tmp->add = rope__add;
tmp->parent =  null;
tmp->left =  this;
tmp->right =  root2;
root2->parent =  tmp;
this->parent =  root2->parent;
tmp->totalLen =  this->totalLen + root2->totalLen;
tmp->str =  null;
struct rope* ____BAH_COMPILER_VAR_170 = tmp;
return ____BAH_COMPILER_VAR_170;
};
struct rope* createRopeStructure(struct rope* par,char * a,long int l,long int r){
struct rope* tmp = memoryAlloc(sizeof(struct rope));
tmp->left= null;
tmp->right= null;
tmp->parent= null;
tmp->str= null;
tmp->getParent = rope__getParent;
tmp->addStr = rope__addStr;
tmp->toStr = rope__toStr;
tmp->add = rope__add;
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
noCheck( arr [ j ] = a [ i ] );
j =  j + 1;
i =  i + 1;
};
tmp->str =  arr;
}
struct rope* ____BAH_COMPILER_VAR_171 = tmp;
return ____BAH_COMPILER_VAR_171;
};
struct rope* concatenateRopes(struct rope* root1,struct rope* root2){
long int n1 =  root1->len;
struct rope* tmp = memoryAlloc(sizeof(struct rope));
tmp->left= null;
tmp->right= null;
tmp->parent= null;
tmp->str= null;
tmp->getParent = rope__getParent;
tmp->addStr = rope__addStr;
tmp->toStr = rope__toStr;
tmp->add = rope__add;
tmp->parent =  null;
tmp->left =  root1;
tmp->right =  root2;
root2->parent =  tmp;
root1->parent =  root2->parent;
tmp->totalLen =  root1->totalLen + root2->totalLen;
tmp->str =  null;
struct rope* ____BAH_COMPILER_VAR_172 = tmp;
return ____BAH_COMPILER_VAR_172;
};
struct rope* rope(char * a){
long int n1 =  strlen(a);
struct rope* r =  createRopeStructure(null,a,0,n1-1);
r->totalLen =  n1;
r->len =  n1;
struct rope* ____BAH_COMPILER_VAR_173 = r;
return ____BAH_COMPILER_VAR_173;
};
#define BAH_DIR "/opt/bah/"
#define BAH_OS "linux"
#define BAH_VERSION "v1.1 (build 42)"
int debug;
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
};
struct structMemb {
char * name;
char * type;
int isConst;
char * constVal;
int isArray;
char * from;
int outterScope;
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
};
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
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:37): arr[%d] with length %d\n", i, arr->length);
                            exit(1);
                        };
                        if ((needle==arr->data[i])) {
int ____BAH_COMPILER_VAR_174 = true;
return ____BAH_COMPILER_VAR_174;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_175 = false;
return ____BAH_COMPILER_VAR_175;
};
int inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){
long int i =  0;
while ((i<len(arr))) {

                        if (arr->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:47): arr[%d] with length %d\n", i, arr->length);
                            exit(1);
                        };
                        if ((__checkString(needle, "/home/alois/Documents/bah-bah/src/lexer.bah:47 needle ")==1&&__checkString(arr->data[i], "/home/alois/Documents/bah-bah/src/lexer.bah:47 arr->data[i]")==1&&strcmp(needle, arr->data[i]) == 0)) {
int ____BAH_COMPILER_VAR_176 = true;
return ____BAH_COMPILER_VAR_176;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_177 = false;
return ____BAH_COMPILER_VAR_177;
};
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){
struct Tok ____BAH_COMPILER_VAR_178 = {};
____BAH_COMPILER_VAR_178.cont = "";
____BAH_COMPILER_VAR_178.ogCont = "";
____BAH_COMPILER_VAR_178.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_178.pos = 0;
____BAH_COMPILER_VAR_178.line = 1;
____BAH_COMPILER_VAR_178.begLine = 1;
____BAH_COMPILER_VAR_178.bahType = "";
____BAH_COMPILER_VAR_178.isValue = false;
____BAH_COMPILER_VAR_178.isFunc = false;
____BAH_COMPILER_VAR_178.isOper = false;
struct Tok t =  ____BAH_COMPILER_VAR_178;
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
struct Tok ____BAH_COMPILER_VAR_179 = t;
return ____BAH_COMPILER_VAR_179;
};
int isMinus(char c,char nc){
if ((c==45)) {
if (isNumber(nc)) {
int ____BAH_COMPILER_VAR_180 = true;
return ____BAH_COMPILER_VAR_180;
}
}
int ____BAH_COMPILER_VAR_181 = false;
return ____BAH_COMPILER_VAR_181;
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr =  intToStr(line);
char * posStr =  intToStr(pos);
char * ____BAH_COMPILER_VAR_182 =null;
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
                        ____BAH_COMPILER_VAR_182 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_182+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_182+currStrOff, compilerState.currentFile, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_182+currStrOff, ":", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_182+currStrOff, lineStr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_182+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_182+currStrOff, posStr, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_182+currStrOff, "\n\e[0m\n", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_182+currStrOff, msg, strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    println(____BAH_COMPILER_VAR_182);
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
while ((i<codeLength)) {

                        if (s->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:121): s[%d] with length %d\n", i, s->length);
                            exit(1);
                        };
                        char c =  s->data[i];
long int nci =  i + 1;
char nc =  (char)0;
if ((nci<codeLength)) {

                        if (s->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:125): s[%d] with length %d\n", i + 1, s->length);
                            exit(1);
                        };
                        nc =  s->data[i + 1];
}
if ((c==47)) {

                        if (s->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:128): s[%d] with length %d\n", i + 1, s->length);
                            exit(1);
                        };
                        nc =  s->data[i + 1];
if ((nc==47)) {
while ((i<codeLength)) {

                        if (s->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:131): s[%d] with length %d\n", i, s->length);
                            exit(1);
                        };
                        c =  s->data[i];
if ((c==(char)10)) {
break;
}
i =  i + 1;
};
long int max =  codeLength - 1;
if ((i>=max)) {
break;
}
}
}
if ((c==(char)10)) {
lineNb =  lineNb + 1;
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
while ((i<codeLength)) {

                        if (s->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:155): s[%d] with length %d\n", i, s->length);
                            exit(1);
                        };
                        c =  s->data[i];

                        if (s->length <= i-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:156): s[%d] with length %d\n", i-1, s->length);
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
i =  i + 1;
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
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:174): tokens[%d] with length %d\n", len(tokens) - 1, tokens->length);
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
while ((i<codeLength)) {

                        if (s->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:184): s[%d] with length %d\n", i, s->length);
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
i =  i + 1;
};
i =  i - 1;

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
i =  i + 1;

                        if (s->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:198): s[%d] with length %d\n", i, s->length);
                            exit(1);
                        };
                        char n =  s->data[i];
char * toInt =  intToStr((long int)nc);
memory =  strToArr(toInt);
i =  i + 1;

                        if (s->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:202): s[%d] with length %d\n", i, s->length);
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
i =  i + 1;
while ((i<codeLength)) {

                        if (s->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:214): s[%d] with length %d\n", i, s->length);
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
i =  i + 1;
};
i =  i - 1;

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
i =  i + 1;
char fc =  c;
while ((i<codeLength)) {

                        if (s->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:234): s[%d] with length %d\n", i, s->length);
                            exit(1);
                        };
                        c =  s->data[i];
if ((inArray(c,syntaxes)==false)) {
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
i =  i + 1;
};
i =  i - 1;

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
i =  i + 1;
while ((i<codeLength)) {

                        if (s->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:268): s[%d] with length %d\n", i, s->length);
                            exit(1);
                        };
                        c =  s->data[i];
if ((isAlphaNumeric(c)==0)) {
if ((inArray(c,varChars)==false)) {
if ((c==62)) {

                        if (memory->length <= len(memory)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:273): memory[%d] with length %d\n", len(memory)-1, memory->length);
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
i =  i - 1;
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
i =  i + 1;
};
i =  i - 1;
tokenType currentType =  TOKEN_TYPE_VAR;
char * memstr =  arrAsStr(memory);
if (inArrayStr(memstr,keywords)) {
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
i =  i + 1;
};
totalLines =  totalLines + lineNb - 1;
dur =  getTimeUnix() - dur;
totalLexerTime =  totalLexerTime + dur;
array(struct Tok)* ____BAH_COMPILER_VAR_183 = tokens;
return ____BAH_COMPILER_VAR_183;
};
int hasStructSep(struct string n){
if (n.count((struct string*)&n,".")) {
int ____BAH_COMPILER_VAR_184 = true;
return ____BAH_COMPILER_VAR_184;
}
if (n.count((struct string*)&n,"->")) {
int ____BAH_COMPILER_VAR_185 = true;
return ____BAH_COMPILER_VAR_185;
}
int ____BAH_COMPILER_VAR_186 = false;
return ____BAH_COMPILER_VAR_186;
};
struct string splitStructSepBefore(struct string n){
if (n.count((struct string*)&n,".")) {
char * ____BAH_COMPILER_VAR_187 =splitStringBefore(n,".");struct string res =  string(____BAH_COMPILER_VAR_187);
struct string ____BAH_COMPILER_VAR_188 = res;
return ____BAH_COMPILER_VAR_188;
}
if (n.count((struct string*)&n,"->")) {
char * ____BAH_COMPILER_VAR_189 =splitStringBefore(n,"->");struct string res =  string(____BAH_COMPILER_VAR_189);
struct string ____BAH_COMPILER_VAR_190 = res;
return ____BAH_COMPILER_VAR_190;
}
struct string ____BAH_COMPILER_VAR_191 = string("");
return ____BAH_COMPILER_VAR_191;
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
struct string ____BAH_COMPILER_VAR_192 = n;
return ____BAH_COMPILER_VAR_192;
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
if ((__checkString(s->name, "/home/alois/Documents/bah-bah/src/struct.bah:55 s->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/struct.bah:55 name")==1&&strcmp(s->name, name) == 0)) {
struct cStruct* ____BAH_COMPILER_VAR_193 = s;
return ____BAH_COMPILER_VAR_193;
}
i =  i + 1;
};
struct cStruct* ____BAH_COMPILER_VAR_194 = null;
return ____BAH_COMPILER_VAR_194;
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
struct structMemb* ____BAH_COMPILER_VAR_195 = memb;
return ____BAH_COMPILER_VAR_195;
}
array(struct structMemb*)* members =  s->members;
long int i =  0;
while ((i<len(members))) {

                        if (members->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/struct.bah:86): members[%d] with length %d\n", i, members->length);
                            exit(1);
                        };
                        struct structMemb* m =  members->data[i];
if ((__checkString(m->name, "/home/alois/Documents/bah-bah/src/struct.bah:87 m->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/struct.bah:87 name")==1&&strcmp(m->name, name) == 0)) {
struct structMemb* ____BAH_COMPILER_VAR_196 = m;
return ____BAH_COMPILER_VAR_196;
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
if ((__checkString(m->name, "/home/alois/Documents/bah-bah/src/struct.bah:95 m->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/struct.bah:95 name")==1&&strcmp(m->name, name) == 0)) {
struct structMemb* sm = memoryAlloc(sizeof(struct structMemb));
sm->name = "";
sm->type = "";
sm->isConst = false;
sm->constVal = "";
sm->isArray = false;
sm->from = "";
sm->outterScope = false;
sm->def = "";
sm->isFn = false;
sm->name =  m->name;
sm->from =  m->from;
sm->type =  m->returns->type;
sm->isFn =  true;
struct structMemb* ____BAH_COMPILER_VAR_197 = sm;
return ____BAH_COMPILER_VAR_197;
}
i =  i + 1;
};
if ((strlen(s->extendedFrom)==0)) {
struct structMemb* ____BAH_COMPILER_VAR_198 = null;
return ____BAH_COMPILER_VAR_198;
}
struct cStruct* es =  searchStruct(s->extendedFrom,elems);
struct structMemb* ____BAH_COMPILER_VAR_199 = searchStructMemb(name,es,elems);
return ____BAH_COMPILER_VAR_199;
};
int isRCPpointerType(char * t){
if (strHasPrefix(t,"function(")) {
int ____BAH_COMPILER_VAR_200 = false;
return ____BAH_COMPILER_VAR_200;
}
if (((((__checkString(t, "/home/alois/Documents/bah-bah/src/type.bah:11 t ")==1&&strcmp(t, "cpstring") == 0)||(__checkString(t, "/home/alois/Documents/bah-bah/src/type.bah:11 t ")==1&&strcmp(t, "ptr") == 0))||(strCount(t,"*")>0))||(strHasPrefix(t,"[]")==true))) {
int ____BAH_COMPILER_VAR_201 = true;
return ____BAH_COMPILER_VAR_201;
}
int ____BAH_COMPILER_VAR_202 = false;
return ____BAH_COMPILER_VAR_202;
};
int isRCPtype(char * t,struct Elems* elems){
if ((isRCPpointerType(t)==true)) {
int ____BAH_COMPILER_VAR_203 = true;
return ____BAH_COMPILER_VAR_203;
}
struct cStruct* s =  searchStruct(t,elems);
if ((((s!=null)&&(s->isBinding==false))&&(s->hasRCPmemb==true))) {
int ____BAH_COMPILER_VAR_204 = true;
return ____BAH_COMPILER_VAR_204;
}
int ____BAH_COMPILER_VAR_205 = false;
return ____BAH_COMPILER_VAR_205;
};
struct string getCType(char * t,struct Elems* elems){
if ((strlen(t)==0)) {
struct string ____BAH_COMPILER_VAR_206 = string("void");
return ____BAH_COMPILER_VAR_206;
}
struct string tp =  string(t);
tp.replace((struct string*)&tp," ","");
if (tp.hasPrefix((struct string*)&tp,"[]")) {
tp.trimLeft((struct string*)&tp,2);
char * tpstr =  tp.str((struct string*)&tp);
tp =  getCType(tpstr,elems);
t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_207 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("array(");
long int strLen_1 = strlen(t);
long int strLen_2 = strlen(")*");
;                            
                        ____BAH_COMPILER_VAR_207 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_207+currStrOff, "array(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_207+currStrOff, t, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_207+currStrOff, ")*", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * r =  ____BAH_COMPILER_VAR_207;
struct string ____BAH_COMPILER_VAR_208 = string(r);
return ____BAH_COMPILER_VAR_208;
}
struct string ctp =  tp;
ctp.replace((struct string*)&ctp,"*","");
if ((tp.hasPrefix((struct string*)&tp,"chan:")==1)) {
tp.set((struct string*)&tp,"struct channel *");
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
                            printf("array (/home/alois/Documents/bah-bah/src/type.bah:93): elems->types[%d] with length %d\n", i, elems->types->length);
                            exit(1);
                        };
                        char * ct =  elems->types->data[i];
if (ctp.compare((struct string*)&ctp,ct)) {
struct string ____BAH_COMPILER_VAR_209 = tp;
return ____BAH_COMPILER_VAR_209;
}
i =  i + 1;
};
struct string ____BAH_COMPILER_VAR_210 = string("");
return ____BAH_COMPILER_VAR_210;
}
}
struct string ____BAH_COMPILER_VAR_211 = tp;
return ____BAH_COMPILER_VAR_211;
};
int compTypes(char * a,char * b){
if ((__checkString(a, "/home/alois/Documents/bah-bah/src/type.bah:109 a ")==1&&strcmp(a, "ptr") == 0)) {
int ____BAH_COMPILER_VAR_212 = true;
return ____BAH_COMPILER_VAR_212;
}
if ((__checkString(b, "/home/alois/Documents/bah-bah/src/type.bah:112 b ")==1&&strcmp(b, "ptr") == 0)) {
int ____BAH_COMPILER_VAR_213 = true;
return ____BAH_COMPILER_VAR_213;
}
if ((__checkString(a, "/home/alois/Documents/bah-bah/src/type.bah:115 a ")==1&&__checkString(b, "/home/alois/Documents/bah-bah/src/type.bah:115 b")==1&&strcmp(a, b) == 0)) {
int ____BAH_COMPILER_VAR_214 = true;
return ____BAH_COMPILER_VAR_214;
}
int ____BAH_COMPILER_VAR_215 = false;
return ____BAH_COMPILER_VAR_215;
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
void * ____BAH_COMPILER_VAR_216 = noCheck( base + this->offset );
return ____BAH_COMPILER_VAR_216;
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,int isArr,struct reflectElement* ae,int isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement ____BAH_COMPILER_VAR_217 = {};
____BAH_COMPILER_VAR_217.type= null;
____BAH_COMPILER_VAR_217.name= null;
____BAH_COMPILER_VAR_217.arrayElem= null;
____BAH_COMPILER_VAR_217.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_217.structLayout->length = 0;
            ____BAH_COMPILER_VAR_217.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_217.value= null;
____BAH_COMPILER_VAR_217.calculateOffset = reflectElement__calculateOffset;
struct reflectElement re =  ____BAH_COMPILER_VAR_217;
re.size =  s;
re.type =  t;
re.name =  n;
re.isArray =  isArr;
re.arrayElem =  ae;
re.isStruct =  isStruct;
re.structLayout =  sl;
re.value =  v;
re.offset =  offset;
struct reflectElement ____BAH_COMPILER_VAR_218 = re;
return ____BAH_COMPILER_VAR_218;
};
#define JSON_TYPE_STRING 0
#define JSON_TYPE_INT 1
#define JSON_TYPE_FLOAT 2
#define JSON_TYPE_ARRAY 3
#define JSON_TYPE_MAP 4
char * toJson(struct reflectElement e);
struct jsonElement {
long int type;
char * key;
char * content;
array(struct jsonElement*)* children;
struct jsonElement*(*map)(struct jsonElement* this,char * key);
char *(*str)(struct jsonElement* this);
void(*scan)(struct jsonElement* this,struct reflectElement e);
};
struct jsonElement* jsonElement__map(struct jsonElement* this,char * key){
long int l =  len(this->children);
long int i =  0;
while ((i<l)) {

                        if (this->children->length <= i) {
                            printf("array (/opt/bah/json.bah:28): this->children[%d] with length %d\n", i, this->children->length);
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
if ((__checkString(arrAsStr(nk), "/opt/bah/json.bah:38 arrAsStr(nk) ")==1&&__checkString(key, "/opt/bah/json.bah:38 key")==1&&strcmp(arrAsStr(nk), key) == 0)) {
struct jsonElement* ____BAH_COMPILER_VAR_219 = elem;
return ____BAH_COMPILER_VAR_219;
}
}
else {
if ((__checkString(elem->key, "/opt/bah/json.bah:42 elem->key ")==1&&__checkString(key, "/opt/bah/json.bah:42 key")==1&&strcmp(elem->key, key) == 0)) {
struct jsonElement* ____BAH_COMPILER_VAR_220 = elem;
return ____BAH_COMPILER_VAR_220;
}
}
i =  i + 1;
};
void * z =  (void *)0;
struct jsonElement* ____BAH_COMPILER_VAR_221 = z;
return ____BAH_COMPILER_VAR_221;
};
char * jsonElement__str(struct jsonElement* this){
char * ctn =  this->content;
char * ____BAH_COMPILER_VAR_222 = ctn;
return ____BAH_COMPILER_VAR_222;
};
void jsonElement__scan(struct jsonElement* this,struct reflectElement e){
if ((e.isStruct==true)) {
long int i =  0;
while ((i<len(e.structLayout))) {

                        if (e.structLayout->length <= i) {
                            printf("array (/opt/bah/json.bah:63): e.structLayout[%d] with length %d\n", i, e.structLayout->length);
                            exit(1);
                        };
                        struct reflectElement m =  e.structLayout->data[i];
struct jsonElement* ov =  this->map((struct jsonElement*)this,m.name);
if ((ov!=null)) {
ov->scan((struct jsonElement*)ov,m);
}
i =  i + 1;
};
}
else if ((__checkString(e.type, "/opt/bah/json.bah:70 e.type ")==1&&strcmp(e.type, "int") == 0)) {
long int* ep =  e.value;
*ep =  strToInt(this->content);
}
else if ((__checkString(e.type, "/opt/bah/json.bah:73 e.type ")==1&&strcmp(e.type, "cpstring") == 0)) {
char ** ep =  e.value;
*ep =  memoryAlloc(strlen(this->content));
strcpy(*ep,this->content);
}
else if ((__checkString(e.type, "/opt/bah/json.bah:77 e.type ")==1&&strcmp(e.type, "float") == 0)) {
double* ep =  e.value;
*ep =  strToFloat(this->content);
}
else if ((__checkString(e.type, "/opt/bah/json.bah:80 e.type ")==1&&strcmp(e.type, "bool") == 0)) {
int* ep =  e.value;
if (((__checkString(this->content, "/opt/bah/json.bah:82 this->content ")==1&&strcmp(this->content, "1") == 0)||(__checkString(this->content, "/opt/bah/json.bah:82 this->content ")==1&&strcmp(this->content, "true") == 0))) {
*ep =  true;
}
else {
*ep =  false;
}
}
else if ((e.isArray==true)) {
struct reflectElement* ae =  e.arrayElem;
if ((__checkString(ae->type, "/opt/bah/json.bah:89 ae->type ")==1&&strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            printf("array (/opt/bah/json.bah:94): this->children[%d] with length %d\n", i, this->children->length);
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
else if ((__checkString(ae->type, "/opt/bah/json.bah:98 ae->type ")==1&&strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            printf("array (/opt/bah/json.bah:103): this->children[%d] with length %d\n", i, this->children->length);
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
else if ((__checkString(ae->type, "/opt/bah/json.bah:107 ae->type ")==1&&strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            printf("array (/opt/bah/json.bah:112): this->children[%d] with length %d\n", i, this->children->length);
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
arr->data[i] =  memoryAlloc(strlen(c->content));
arr->length = nLength+1;
} else {
arr->data[i] =  memoryAlloc(strlen(c->content));
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
arr =  e.value;
long int i =  0;
while ((i<len(this->children))) {

                        if (this->children->length <= i) {
                            printf("array (/opt/bah/json.bah:123): this->children[%d] with length %d\n", i, this->children->length);
                            exit(1);
                        };
                        struct jsonElement* c =  this->children->data[i];
void * ne =  memoryAlloc(ae->size);
long int j =  0;
while ((j<len(ae->structLayout))) {

                        if (ae->structLayout->length <= j) {
                            printf("array (/opt/bah/json.bah:126): ae->structLayout[%d] with length %d\n", j, ae->structLayout->length);
                            exit(1);
                        };
                        struct reflectElement m =  ae->structLayout->data[j];
m.value =  m.calculateOffset((struct reflectElement*)&m,ne);
struct jsonElement* ov =  c->map((struct jsonElement*)c,m.name);
if ((ov!=null)) {
ov->scan((struct jsonElement*)ov,m);
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
};
struct jsonElement* parseJson(char * s){
struct jsonElement* jsonElem = memoryAlloc(sizeof(struct jsonElement));
jsonElem->key= null;
jsonElem->content= null;
jsonElem->children = memoryAlloc(sizeof(array(struct jsonElement*)));
            jsonElem->children->length = 0;
            jsonElem->children->elemSize = sizeof(struct jsonElement*);
            jsonElem->map = jsonElement__map;
jsonElem->str = jsonElement__str;
jsonElem->scan = jsonElement__scan;
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
while ((i<lenS - 1)) {

{
long nLength = len(ns);
if (ns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(ns->data, (nLength+50)*sizeof(char));
ns->data = newPtr;
}
ns->data[len(ns)] =  cpstringCharAt(s,i);
ns->length = nLength+1;
} else {
ns->data[len(ns)] =  cpstringCharAt(s,i);
}
};
i =  i + 1;
};
jsonElem->content =  arrToStr(ns);
}
else if (isNumber(fc)) {
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
jsonElem->type =  JSON_TYPE_STRING;
jsonElem->content =  s;
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
char * ____BAH_COMPILER_VAR_223 =arrToStr(currentElem);
{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_223);
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_223);
}
};
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
char * ____BAH_COMPILER_VAR_224 =arrToStr(currentElem);
{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_224);
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_224);
}
};
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
char * ____BAH_COMPILER_VAR_225 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_225);
elem->key =  arrToStr(currentKey);
clear(currentElem);
clear(currentKey);
isVal =  0;

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
char * ____BAH_COMPILER_VAR_226 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_226);
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
struct jsonElement* ____BAH_COMPILER_VAR_227 = jsonElem;
return ____BAH_COMPILER_VAR_227;
};
char * jsonEscapeStr(char * s){
array(char)* a =  strAsArr(s);
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
long int i =  0;
while ((i<len(a))) {

                        if (a->length <= i) {
                            printf("array (/opt/bah/json.bah:345): a[%d] with length %d\n", i, a->length);
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
char * ____BAH_COMPILER_VAR_228 = arrToStr(r);
return ____BAH_COMPILER_VAR_228;
};
char * toJson__inner(struct reflectElement e,int isMember,long int tabs){
void ** v =  e.value;
if (((e.value==null)||(*v==null))) {
if (((__checkString(e.type, "/opt/bah/json.bah:371 e.type ")==1&&strcmp(e.type, "int") == 0)||(__checkString(e.type, "/opt/bah/json.bah:371 e.type ")==1&&strcmp(e.type, "float") == 0))) {
char * ____BAH_COMPILER_VAR_229 = "0";
return ____BAH_COMPILER_VAR_229;
}
if ((__checkString(e.type, "/opt/bah/json.bah:374 e.type ")==1&&strcmp(e.type, "bool") == 0)) {
char * ____BAH_COMPILER_VAR_230 = "false";
return ____BAH_COMPILER_VAR_230;
}
char * ____BAH_COMPILER_VAR_231 = "null";
return ____BAH_COMPILER_VAR_231;
}
if ((e.isStruct==true)) {
tabs =  tabs + 1;
char * tabsStr =  "";
long int i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_232 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                        ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_232+currStrOff, tabsStr, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_232+currStrOff, "\t", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tabsStr =  ____BAH_COMPILER_VAR_232;
i =  i + 1;
};
char * s =  "{\n";
i =  0;
while ((i<len(e.structLayout))) {

                        if (e.structLayout->length <= i) {
                            printf("array (/opt/bah/json.bah:388): e.structLayout[%d] with length %d\n", i, e.structLayout->length);
                            exit(1);
                        };
                        struct reflectElement m =  e.structLayout->data[i];
i =  i + 1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_233 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_234 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_233);
long int strLen_6 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_234 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, m.name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, "\": ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, ____BAH_COMPILER_VAR_233, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, ",\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_234;
}
else {
char * ____BAH_COMPILER_VAR_235 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_236 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_235);
long int strLen_6 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_236 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, m.name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, "\": ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, ____BAH_COMPILER_VAR_235, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, "\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_236;
}
};
tabs =  tabs - 1;
tabsStr =  "";
i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_237 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                        ____BAH_COMPILER_VAR_237 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_237+currStrOff, tabsStr, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_237+currStrOff, "\t", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tabsStr =  ____BAH_COMPILER_VAR_237;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_238 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("}");
;                            
                        ____BAH_COMPILER_VAR_238 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_238+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_238+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_238+currStrOff, "}", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_238;
char * ____BAH_COMPILER_VAR_239 = s;
return ____BAH_COMPILER_VAR_239;
}
else if ((__checkString(e.type, "/opt/bah/json.bah:404 e.type ")==1&&strcmp(e.type, "int") == 0)) {
long int* ip =  e.value;
char * ____BAH_COMPILER_VAR_240 = intToStr(*ip);
return ____BAH_COMPILER_VAR_240;
}
else if ((__checkString(e.type, "/opt/bah/json.bah:407 e.type ")==1&&strcmp(e.type, "float") == 0)) {
double* fp =  e.value;
char * ____BAH_COMPILER_VAR_241 = floatToStr(*fp);
return ____BAH_COMPILER_VAR_241;
}
else if ((__checkString(e.type, "/opt/bah/json.bah:410 e.type ")==1&&strcmp(e.type, "cpstring") == 0)) {
if ((isMember==false)) {
void * s =  e.value;
char * ____BAH_COMPILER_VAR_242 =jsonEscapeStr(s);char * ____BAH_COMPILER_VAR_243 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_242);
long int strLen_2 = strlen("\"");
;                            
                        ____BAH_COMPILER_VAR_243 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_243+currStrOff, "\"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_243+currStrOff, ____BAH_COMPILER_VAR_242, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_243+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * ____BAH_COMPILER_VAR_244 = ____BAH_COMPILER_VAR_243;
return ____BAH_COMPILER_VAR_244;
}
else {
char ** sp =  e.value;
char * s =  *sp;
char * ____BAH_COMPILER_VAR_245 =jsonEscapeStr(s);char * ____BAH_COMPILER_VAR_246 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_245);
long int strLen_2 = strlen("\"");
;                            
                        ____BAH_COMPILER_VAR_246 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_246+currStrOff, "\"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_246+currStrOff, ____BAH_COMPILER_VAR_245, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_246+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * ____BAH_COMPILER_VAR_247 = ____BAH_COMPILER_VAR_246;
return ____BAH_COMPILER_VAR_247;
}
}
else if ((__checkString(e.type, "/opt/bah/json.bah:419 e.type ")==1&&strcmp(e.type, "bool") == 0)) {
int* bp =  e.value;
if ((*bp==true)) {
char * ____BAH_COMPILER_VAR_248 = "true";
return ____BAH_COMPILER_VAR_248;
}
char * ____BAH_COMPILER_VAR_249 = "false";
return ____BAH_COMPILER_VAR_249;
}
else if ((e.isArray==true)) {
char * s =  "[";
struct reflectElement* ae =  e.arrayElem;
if ((__checkString(ae->type, "/opt/bah/json.bah:428 ae->type ")==1&&strcmp(ae->type, "int") == 0)) {
array(long int)* arr = memoryAlloc(sizeof(array(long int)));

arr->length = 0;
arr->elemSize = sizeof(long int);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_250 =intToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_251 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_250);
;                            
                        ____BAH_COMPILER_VAR_251 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_251+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_251+currStrOff, ____BAH_COMPILER_VAR_250, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_251;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_252 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_252 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_252+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_252+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_252;
}
};
}
else if ((__checkString(ae->type, "/opt/bah/json.bah:439 ae->type ")==1&&strcmp(ae->type, "float") == 0)) {
array(double)* arr = memoryAlloc(sizeof(array(double)));

arr->length = 0;
arr->elemSize = sizeof(double);
void ** arrPtr =  e.value;
arr =  *arrPtr;
long int i =  0;
while ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_253 =floatToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_254 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_253);
;                            
                        ____BAH_COMPILER_VAR_254 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_254+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_254+currStrOff, ____BAH_COMPILER_VAR_253, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_254;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_255 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_255 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_255+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_255+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_255;
}
};
}
else if ((__checkString(ae->type, "/opt/bah/json.bah:450 ae->type ")==1&&strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
char * ____BAH_COMPILER_VAR_256 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_256 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_256+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_256+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_256;
long int i =  0;
while ((i<len(arr))) {

                        if (arr->length <= i) {
                            printf("array (/opt/bah/json.bah:456): arr[%d] with length %d\n", i, arr->length);
                            exit(1);
                        };
                        char * ____BAH_COMPILER_VAR_257 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(arr->data[i]);
;                            
                        ____BAH_COMPILER_VAR_257 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_257+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_257+currStrOff, arr->data[i], strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_257;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_258 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_258 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_258+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_258+currStrOff, ",\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_258;
}
else {
char * ____BAH_COMPILER_VAR_259 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_259 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_259+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_259+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_259;
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
                            printf("array (/opt/bah/json.bah:476): arr[%d] with length %d\n", i, arr->length);
                            exit(1);
                        };
                        void * arrElem =  arr->data[i];
ae->value =  arrElem;
long int j =  0;
while ((j<len(ae->structLayout))) {

                        if (ae->structLayout->length <= j) {
                            printf("array (/opt/bah/json.bah:479): ae->structLayout[%d] with length %d\n", j, ae->structLayout->length);
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
char * ____BAH_COMPILER_VAR_260 =toJson__inner(*ae,false,tabs);char * ____BAH_COMPILER_VAR_261 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_260);
;                            
                        ____BAH_COMPILER_VAR_261 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, ____BAH_COMPILER_VAR_260, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_261;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_262 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_262 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_262+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_262+currStrOff, ",\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_262;
}
else {
char * ____BAH_COMPILER_VAR_263 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_263 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_263+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_263+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_263;
}
};
}
char * ____BAH_COMPILER_VAR_264 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("]");
;                            
                        ____BAH_COMPILER_VAR_264 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_264+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_264+currStrOff, "]", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_264;
char * ____BAH_COMPILER_VAR_265 = s;
return ____BAH_COMPILER_VAR_265;
}
char * ____BAH_COMPILER_VAR_266 = "";
return ____BAH_COMPILER_VAR_266;
};
char * toJson(struct reflectElement e){
char * ____BAH_COMPILER_VAR_267 = toJson__inner(e,false,0);
return ____BAH_COMPILER_VAR_267;
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
struct reflectElement ____BAH_COMPILER_VAR_269 = __reflect(name, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_270 =toJson(____BAH_COMPILER_VAR_269);char * ____BAH_COMPILER_VAR_271 =intToStr(line);char * ____BAH_COMPILER_VAR_272 =toJson(e);char * ____BAH_COMPILER_VAR_273 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_270);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_271);
long int strLen_6 = strlen("\",\n        \"element\": ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_272);
long int strLen_8 = strlen("\n    },\n    ");
;                            
                        ____BAH_COMPILER_VAR_273 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, ____BAH_COMPILER_VAR_270, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, ",\n        \"path\": \"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, compilerState.currentFile, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, ____BAH_COMPILER_VAR_271, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, "\",\n        \"element\": ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, ____BAH_COMPILER_VAR_272, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, "\n    },\n    ", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    println(____BAH_COMPILER_VAR_273);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
struct reflectElement ____BAH_COMPILER_VAR_275 = __reflect(name, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_276 =toJson(____BAH_COMPILER_VAR_275);char * ____BAH_COMPILER_VAR_277 =intToStr(line);char * ____BAH_COMPILER_VAR_278 =intToStr(from);char * ____BAH_COMPILER_VAR_279 =intToStr(to);char * ____BAH_COMPILER_VAR_280 =toJson(e);char * ____BAH_COMPILER_VAR_281 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_276);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_277);
long int strLen_6 = strlen("\",\n        \"range\": [\n            ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_278);
long int strLen_8 = strlen(",\n            ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_279);
long int strLen_10 = strlen("\n        ],\n        \"element\": ");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_280);
long int strLen_12 = strlen("\n    },\n    ");
;                            
                        ____BAH_COMPILER_VAR_281 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, ____BAH_COMPILER_VAR_276, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, ",\n        \"path\": \"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, compilerState.currentFile, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, ____BAH_COMPILER_VAR_277, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, ____BAH_COMPILER_VAR_278, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, ",\n            ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, ____BAH_COMPILER_VAR_279, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, "\n        ],\n        \"element\": ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, ____BAH_COMPILER_VAR_280, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_281+currStrOff, "\n    },\n    ", strLen_12);
                        currStrOff += strLen_12;
                        
                    }
                    println(____BAH_COMPILER_VAR_281);
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
struct reflectElement ____BAH_COMPILER_VAR_284 = __reflect((char **)((char*)(v) + offsetof(struct variable, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_285 = __reflect((char **)((char*)(v) + offsetof(struct variable, type)), sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_286 = __reflect((int*)((char*)(v) + offsetof(struct variable, isConst)), sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_287 = __reflect((char **)((char*)(v) + offsetof(struct variable, constVal)), sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_288 = __reflect((int*)((char*)(v) + offsetof(struct variable, isArray)), sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_289 = __reflect((char **)((char*)(v) + offsetof(struct variable, from)), sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_290 = __reflect((int*)((char*)(v) + offsetof(struct variable, outterScope)), sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_283 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_283->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_283->length = 7;
        ____BAH_COMPILER_VAR_283->data = memoryAlloc(____BAH_COMPILER_VAR_283->length * ____BAH_COMPILER_VAR_283->elemSize);
        ____BAH_COMPILER_VAR_283->data[0] = ____BAH_COMPILER_VAR_284;
____BAH_COMPILER_VAR_283->data[1] = ____BAH_COMPILER_VAR_285;
____BAH_COMPILER_VAR_283->data[2] = ____BAH_COMPILER_VAR_286;
____BAH_COMPILER_VAR_283->data[3] = ____BAH_COMPILER_VAR_287;
____BAH_COMPILER_VAR_283->data[4] = ____BAH_COMPILER_VAR_288;
____BAH_COMPILER_VAR_283->data[5] = ____BAH_COMPILER_VAR_289;
____BAH_COMPILER_VAR_283->data[6] = ____BAH_COMPILER_VAR_290;
struct reflectElement ____BAH_COMPILER_VAR_291 = __reflect(v, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_283, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_291);
}
i =  i + 1;
};
};
void throwErr(void * tp,char * format){
char * str =  "";
char * info =  "";
long int pos =  0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_292 = {};
____BAH_COMPILER_VAR_292.open = fileMap__open;
____BAH_COMPILER_VAR_292.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_292.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_292;
char * fileSrcStr =  fm.open((struct fileMap*)&fm,compilerState.currentFile);
struct string fileSrc =  string(fileSrcStr);
fm.close((struct fileMap*)&fm);
struct Tok* t =  tp;
struct string ffmt =  string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont =  t->cont;
}
char * ____BAH_COMPILER_VAR_293 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("'");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_293 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_293+currStrOff, "'", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_293+currStrOff, t->ogCont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_293+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    ffmt.replace((struct string*)&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_293);
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
char * ____BAH_COMPILER_VAR_294 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;31m");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("\e[1;37m");
;                            
                        ____BAH_COMPILER_VAR_294 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_294+currStrOff, "\e[1;31m", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_294+currStrOff, t->ogCont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_294+currStrOff, "\e[1;37m", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    array(char)* errTk =  strToArr(____BAH_COMPILER_VAR_294);
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
char * ____BAH_COMPILER_VAR_295 =intToStr(t->line);char * ____BAH_COMPILER_VAR_296 =intToStr(pos);char * ____BAH_COMPILER_VAR_297 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_295);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_296);
;                            
                        ____BAH_COMPILER_VAR_297 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_297+currStrOff, ____BAH_COMPILER_VAR_295, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_297+currStrOff, ":", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_297+currStrOff, ____BAH_COMPILER_VAR_296, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    info =  ____BAH_COMPILER_VAR_297;
}
if ((debug==true)) {
struct Tok* t =  tp;
struct reflectElement ____BAH_COMPILER_VAR_298 = __reflect(format, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos + strlen(t->ogCont),____BAH_COMPILER_VAR_298);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_299 =null;
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
                        ____BAH_COMPILER_VAR_299 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_299+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_299+currStrOff, compilerState.currentFile, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_299+currStrOff, ":", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_299+currStrOff, info, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_299+currStrOff, "\n\e[1;37m\t", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_299+currStrOff, str, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_299+currStrOff, "\e[0m\n", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_299+currStrOff, format, strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    println(____BAH_COMPILER_VAR_299);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_300 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;33m[WARNING]\e[0m ");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen("\n\e[1;37m\t");
long int strLen_3 = strlen(s);
long int strLen_4 = strlen("\e[0m");
;                            
                        ____BAH_COMPILER_VAR_300 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_300+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_300+currStrOff, compilerState.currentFile, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_300+currStrOff, "\n\e[1;37m\t", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_300+currStrOff, s, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_300+currStrOff, "\e[0m", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    println(____BAH_COMPILER_VAR_300);
};
#include <stdlib.h>
char * absPath(char * path){
char * z =  (char *)0;
char * p =  realpath(path,z);
char * ____BAH_COMPILER_VAR_301 = p;
return ____BAH_COMPILER_VAR_301;
};
char * getCurrentPath(){
char * cwd =  memoryAlloc(4096);
getcwd(cwd,4096);
char * ____BAH_COMPILER_VAR_302 = cwd;
return ____BAH_COMPILER_VAR_302;
};
int isInside(char * basePath,char * subPath){
char * abs1 =  absPath(basePath);
char * abs2 =  absPath(subPath);
int ____BAH_COMPILER_VAR_303 = (strHasPrefix(subPath,basePath)==true);
return ____BAH_COMPILER_VAR_303;
};
void setCurrentPath(char * s){
chdir(s);
};
int isGlobal(){
int ____BAH_COMPILER_VAR_304 = (currentFn==null);
return ____BAH_COMPILER_VAR_304;
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
struct variable* nv = memoryAlloc(sizeof(struct variable));
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->constVal = "";
nv->isArray = false;
nv->from = "";
nv->outterScope = false;
nv->type =  vtstr;
nv->name =  ogName;
nv->isArray =  true;
struct variable* ____BAH_COMPILER_VAR_305 = nv;
return ____BAH_COMPILER_VAR_305;
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
struct variable* ____BAH_COMPILER_VAR_306 = null;
return ____BAH_COMPILER_VAR_306;
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
struct variable* ____BAH_COMPILER_VAR_307 = null;
return ____BAH_COMPILER_VAR_307;
}
struct structMemb* memb =  searchStructMemb(membs,s,elems);
if ((memb==null)) {
struct variable* ____BAH_COMPILER_VAR_308 = null;
return ____BAH_COMPILER_VAR_308;
}
struct variable* nv = memoryAlloc(sizeof(struct variable));
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->constVal = "";
nv->isArray = false;
nv->from = "";
nv->outterScope = false;
nv->from =  memb->from;
nv->name =  memb->name;
nv->type =  memb->type;
nv->name =  ogName;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
char * ____BAH_COMPILER_VAR_309 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_309 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_309+currStrOff, r, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_309+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    r =  ____BAH_COMPILER_VAR_309;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_310 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(nv->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                        ____BAH_COMPILER_VAR_310 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_310+currStrOff, "Cannot use '*' on ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_310+currStrOff, nv->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_310+currStrOff, " because it is not pointer.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(null,____BAH_COMPILER_VAR_310);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
struct variable* ____BAH_COMPILER_VAR_311 = nv;
return ____BAH_COMPILER_VAR_311;
}
long int i =  0;
while ((i<len(elems->vars))) {

                        if (elems->vars->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/var.bah:95): elems->vars[%d] with length %d\n", i, elems->vars->length);
                            exit(1);
                        };
                        struct variable* v =  elems->vars->data[i];
if ((v==null)) {
char * ____BAH_COMPILER_VAR_312 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null var'.");
;                            
                        ____BAH_COMPILER_VAR_312 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_312+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_312+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_312+currStrOff, "' resulting in null var'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_312);
}
if ((__checkString(v->name, "/home/alois/Documents/bah-bah/src/var.bah:99 v->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/var.bah:99 name")==1&&strcmp(v->name, name) == 0)) {
struct variable* nv = memoryAlloc(sizeof(struct variable));
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->constVal = "";
nv->isArray = false;
nv->from = "";
nv->outterScope = false;
nv->type =  v->type;
nv->name =  v->name;
nv->isConst =  v->isConst;
char * r =  nv->type;
struct string tcc =  string(ogName);
if (tcc.count((struct string*)&tcc,"&")) {
char * ____BAH_COMPILER_VAR_313 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_313 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_313+currStrOff, r, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_313+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    r =  ____BAH_COMPILER_VAR_313;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_314 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                        ____BAH_COMPILER_VAR_314 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_314+currStrOff, "Cannot use '*' on ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_314+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_314+currStrOff, " because it is not pointer.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(null,____BAH_COMPILER_VAR_314);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
struct variable* ____BAH_COMPILER_VAR_315 = nv;
return ____BAH_COMPILER_VAR_315;
}
i =  i + 1;
};
i =  0;
while ((i<len(elems->fns))) {

                        if (elems->fns->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/var.bah:132): elems->fns[%d] with length %d\n", i, elems->fns->length);
                            exit(1);
                        };
                        struct func* fn =  elems->fns->data[i];
if ((__checkString(fn->name, "/home/alois/Documents/bah-bah/src/var.bah:133 fn->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/var.bah:133 name")==1&&strcmp(fn->name, name) == 0)) {
struct variable* nv = memoryAlloc(sizeof(struct variable));
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->constVal = "";
nv->isArray = false;
nv->from = "";
nv->outterScope = false;
nv->name =  name;
nv->type =  "function(";
long int j =  0;
while ((j<len(fn->args))) {

                        if (fn->args->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/var.bah:138): fn->args[%d] with length %d\n", j, fn->args->length);
                            exit(1);
                        };
                        struct variable* arg =  fn->args->data[j];
char * ____BAH_COMPILER_VAR_316 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(arg->type);
;                            
                        ____BAH_COMPILER_VAR_316 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_316+currStrOff, nv->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_316+currStrOff, arg->type, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nv->type =  ____BAH_COMPILER_VAR_316;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_317 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_317 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_317+currStrOff, nv->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_317+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nv->type =  ____BAH_COMPILER_VAR_317;
}
};
char * ____BAH_COMPILER_VAR_318 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(fn->returns->type);
;                            
                        ____BAH_COMPILER_VAR_318 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_318+currStrOff, nv->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_318+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_318+currStrOff, fn->returns->type, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    nv->type =  ____BAH_COMPILER_VAR_318;
struct variable* ____BAH_COMPILER_VAR_319 = nv;
return ____BAH_COMPILER_VAR_319;
}
i =  i + 1;
};
struct variable* ____BAH_COMPILER_VAR_320 = null;
return ____BAH_COMPILER_VAR_320;
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp =  getCType(v->type,elems);
char * t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_321 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
;                            
                        ____BAH_COMPILER_VAR_321 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_321+currStrOff, t, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_321+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_321+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    t =  ____BAH_COMPILER_VAR_321;
char * ____BAH_COMPILER_VAR_322 = t;
return ____BAH_COMPILER_VAR_322;
};
char * getTypeFromToken(struct Tok* t,int strict,struct Elems* elems){
if ((strlen(t->bahType)>0)) {
char * r =  t->bahType;
char * ____BAH_COMPILER_VAR_323 = r;
return ____BAH_COMPILER_VAR_323;
}
if ((t->type==TOKEN_TYPE_VAR)) {
struct variable* v =  searchVar(t->cont,elems);
if ((v==null)) {
if ((strict==true)) {
throwErr(t,"Unknown var {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_324 = "";
return ____BAH_COMPILER_VAR_324;
}
}
if ((strict==true)) {
if ((strlen(v->type)==0)) {
throwErr(t,"Cannot use {TOKEN} because it does not have any type.");
}
}
char * r =  v->type;
char * ____BAH_COMPILER_VAR_325 = r;
return ____BAH_COMPILER_VAR_325;
}
if ((t->type==TOKEN_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_326 = "float";
return ____BAH_COMPILER_VAR_326;
}
if ((t->type==TOKEN_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_327 = "int";
return ____BAH_COMPILER_VAR_327;
}
if ((t->type==TOKEN_TYPE_STR)) {
char * ____BAH_COMPILER_VAR_328 = "cpstring";
return ____BAH_COMPILER_VAR_328;
}
if ((t->type==TOKEN_TYPE_CHAR)) {
char * ____BAH_COMPILER_VAR_329 = "char";
return ____BAH_COMPILER_VAR_329;
}
if ((t->type==TOKEN_TYPE_BOOL)) {
char * ____BAH_COMPILER_VAR_330 = "bool";
return ____BAH_COMPILER_VAR_330;
}
throwErr(t,"Cannot use {TOKEN} as value.");
char * ____BAH_COMPILER_VAR_331 = "";
return ____BAH_COMPILER_VAR_331;
};
struct func* parseFnType(struct string cvt){
struct func* nf = memoryAlloc(sizeof(struct func));
nf->name = "";
nf->args = memoryAlloc(sizeof(array(struct variable*)));
            nf->args->length = 0;
            nf->args->elemSize = sizeof(struct variable*);
            nf->returns= null;
nf->isBinding = false;
nf->from = "";
nf->file = "";
nf->line = 1;
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
struct variable* arg = memoryAlloc(sizeof(struct variable));
arg->name = "";
arg->type = "";
arg->isConst = false;
arg->constVal = "";
arg->isArray = false;
arg->from = "";
arg->outterScope = false;
char * ____BAH_COMPILER_VAR_332 =intToStr(len(nf->args));char * ____BAH_COMPILER_VAR_333 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("arg_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_332);
;                            
                        ____BAH_COMPILER_VAR_333 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_333+currStrOff, "arg_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_333+currStrOff, ____BAH_COMPILER_VAR_332, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    arg->name =  ____BAH_COMPILER_VAR_333;
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
nf->returns = memoryAlloc(sizeof(struct variable));
nf->returns->name = "";
nf->returns->type = "";
nf->returns->isConst = false;
nf->returns->constVal = "";
nf->returns->isArray = false;
nf->returns->from = "";
nf->returns->outterScope = false;
nf->returns->name =  "_return";
nf->returns->type =  arrToStr(memory);
struct func* ____BAH_COMPILER_VAR_334 = nf;
return ____BAH_COMPILER_VAR_334;
};
struct func* searchFunc(char * name,struct Elems* elems,int inclCurr){
char * ogName =  name;
if ((__checkString(name, "/home/alois/Documents/bah-bah/src/var.bah:250 name ")==1&&strcmp(name, "noCheck") == 0)) {
struct func* fn = memoryAlloc(sizeof(struct func));
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->returns= null;
fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
fn->name =  "noCheck";
struct func* ____BAH_COMPILER_VAR_335 = fn;
return ____BAH_COMPILER_VAR_335;
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
char * ____BAH_COMPILER_VAR_336 =fnName.str((struct string*)&fnName);struct structMemb* memb =  searchStructMemb(____BAH_COMPILER_VAR_336,s,elems);
name =  fnName.content;
char * ____BAH_COMPILER_VAR_337 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(memb->from);
long int strLen_1 = strlen("__");
long int strLen_2 = strlen(name);
;                            
                        ____BAH_COMPILER_VAR_337 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_337+currStrOff, memb->from, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_337+currStrOff, "__", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_337+currStrOff, name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    name =  ____BAH_COMPILER_VAR_337;
}
array(struct func*)* fns =  elems->fns;
long int i =  0;
while ((i<len(fns))) {

                        if (fns->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/var.bah:276): fns[%d] with length %d\n", i, fns->length);
                            exit(1);
                        };
                        struct func* fn =  fns->data[i];
if ((fn==null)) {
char * ____BAH_COMPILER_VAR_338 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null func'.");
;                            
                        ____BAH_COMPILER_VAR_338 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_338+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_338+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_338+currStrOff, "' resulting in null func'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_338);
}
if ((__checkString(fn->name, "/home/alois/Documents/bah-bah/src/var.bah:280 fn->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/var.bah:280 name")==1&&strcmp(fn->name, name) == 0)) {
struct func* ____BAH_COMPILER_VAR_339 = fn;
return ____BAH_COMPILER_VAR_339;
}
i =  i + 1;
};
if ((inclCurr==true)) {
if ((__checkString(currentFn->name, "/home/alois/Documents/bah-bah/src/var.bah:287 currentFn->name ")==1&&__checkString(name, "/home/alois/Documents/bah-bah/src/var.bah:287 name")==1&&strcmp(currentFn->name, name) == 0)) {
struct func* ____BAH_COMPILER_VAR_340 = currentFn;
return ____BAH_COMPILER_VAR_340;
}
}
struct variable* v =  searchVar(ogName,elems);
if ((v==null)) {
struct func* ____BAH_COMPILER_VAR_341 = null;
return ____BAH_COMPILER_VAR_341;
}
struct func* nf = memoryAlloc(sizeof(struct func));
nf->name = "";
nf->args = memoryAlloc(sizeof(array(struct variable*)));
            nf->args->length = 0;
            nf->args->elemSize = sizeof(struct variable*);
            nf->returns= null;
nf->isBinding = false;
nf->from = "";
nf->file = "";
nf->line = 1;
nf->name =  ogName;
struct string cvt =  string(v->type);
if ((cvt.hasPrefix((struct string*)&cvt,"function(")==0)) {
struct func* ____BAH_COMPILER_VAR_342 = null;
return ____BAH_COMPILER_VAR_342;
}
struct func* pfn =  parseFnType(cvt);
nf->returns =  pfn->returns;
nf->args =  pfn->args;
struct func* ____BAH_COMPILER_VAR_343 = nf;
return ____BAH_COMPILER_VAR_343;
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
char * ____BAH_COMPILER_VAR_344 =null;
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
                        ____BAH_COMPILER_VAR_344 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_344+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_344+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_344+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_344+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_344+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_344+currStrOff, m->def, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_344+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_344;
declared =  true;
}
if ((cmpt.hasPrefix((struct string*)&cmpt,"[]")==1)) {
cmpt.trimLeft((struct string*)&cmpt,2);
char * cmptstr =  cmpt.str((struct string*)&cmpt);
struct string elemCType =  getCType(cmptstr,elems);
char * elemCTypeStr =  elemCType.str((struct string*)&elemCType);
char * ____BAH_COMPILER_VAR_345 =null;
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
                        ____BAH_COMPILER_VAR_345 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, " = memoryAlloc(sizeof(array(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, elemCTypeStr, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, ")));\n            ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, v->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, sep, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, m->name, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, "->length = 0;\n            ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, v->name, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, sep, strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, m->name, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, "->elemSize = sizeof(", strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, elemCTypeStr, strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_345+currStrOff, ");\n            ", strLen_16);
                        currStrOff += strLen_16;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_345;
declared =  true;
}
if ((isRCPpointerType(m->type)&&(declared==false))) {
char * ____BAH_COMPILER_VAR_346 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("= null;\n");
;                            
                        ____BAH_COMPILER_VAR_346 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_346+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_346+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_346+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_346+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_346+currStrOff, "= null;\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_346;
}
i =  i + 1;
};
if ((strlen(s->extendedFrom)>0)) {
struct cStruct* es =  searchStruct(s->extendedFrom,elems);
i =  0;
while ((i<len(es->methods))) {

                        if (es->methods->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/var.bah:348): es->methods[%d] with length %d\n", i, es->methods->length);
                            exit(1);
                        };
                        struct func* m =  es->methods->data[i];
char * ____BAH_COMPILER_VAR_347 =null;
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
                        ____BAH_COMPILER_VAR_347 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, es->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, "__", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, m->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_347+currStrOff, ";\n", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_347;
i =  i + 1;
};
}
array(struct func*)* methods =  s->methods;
i =  0;
while ((i<len(methods))) {

                        if (methods->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/var.bah:356): methods[%d] with length %d\n", i, methods->length);
                            exit(1);
                        };
                        struct func* m =  methods->data[i];
char * ____BAH_COMPILER_VAR_348 =null;
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
                        ____BAH_COMPILER_VAR_348 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, s->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, "__", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, m->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, ";\n", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_348;
i =  i + 1;
};
if ((((s->isBinding==false)&&RCPavailable())&&(s->hasRCPmemb==true))) {
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_349 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter = malloc(sizeof(int));*(int*)");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(".__RCP_counter = 1;\n");
;                            
                        ____BAH_COMPILER_VAR_349 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_349+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_349+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_349+currStrOff, ".__RCP_counter = malloc(sizeof(int));*(int*)", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_349+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_349+currStrOff, ".__RCP_counter = 1;\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_349;
}
else {
char * ____BAH_COMPILER_VAR_350 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen("->__RCP_counter = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_350 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_350+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_350+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_350+currStrOff, "->__RCP_counter = RCP_request(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_350+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_350+currStrOff, ");\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_350;
}
}
char * ____BAH_COMPILER_VAR_351 = code;
return ____BAH_COMPILER_VAR_351;
};
long int NB_COMP_VAR;
char * genCompilerVar(){
char * ____BAH_COMPILER_VAR_352 =intToStr(NB_COMP_VAR);char * ____BAH_COMPILER_VAR_353 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("____BAH_COMPILER_VAR_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_352);
;                            
                        ____BAH_COMPILER_VAR_353 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_353+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_353+currStrOff, ____BAH_COMPILER_VAR_352, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * name =  ____BAH_COMPILER_VAR_353;
NB_COMP_VAR =  NB_COMP_VAR + 1;
char * ____BAH_COMPILER_VAR_354 = name;
return ____BAH_COMPILER_VAR_354;
};
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
int varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){
if ((arr==null)) {
int ____BAH_COMPILER_VAR_355 = false;
return ____BAH_COMPILER_VAR_355;
}
long int j =  0;
while ((j<len(arr))) {

                        if (arr->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/var.bah:385): arr[%d] with length %d\n", j, arr->length);
                            exit(1);
                        };
                        struct variable* ev =  arr->data[j];
if ((__checkString(ev->name, "/home/alois/Documents/bah-bah/src/var.bah:386 ev->name ")==1&&__checkString(v->name, "/home/alois/Documents/bah-bah/src/var.bah:386 v->name")==1&&strcmp(ev->name, v->name) == 0)) {
int ____BAH_COMPILER_VAR_356 = true;
return ____BAH_COMPILER_VAR_356;
}
j =  j + 1;
};
int ____BAH_COMPILER_VAR_357 = false;
return ____BAH_COMPILER_VAR_357;
};
void makeInit(){
OUTPUT =  OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        "))->add(OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        ")), INIT)->add(OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        "))->add(OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        ")), INIT), rope("\n\n    };\n    "));
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r =  rope("");
if (strHasPrefix(v->type,"[]")) {
struct string at =  string(v->type);
at.trimLeft((struct string*)&at,2);
char * ____BAH_COMPILER_VAR_358 =at.str((struct string*)&at);if (isRCPtype(____BAH_COMPILER_VAR_358,elems)) {
struct variable* arrElem = memoryAlloc(sizeof(struct variable));
arrElem->name = "";
arrElem->type = "";
arrElem->isConst = false;
arrElem->constVal = "";
arrElem->isArray = false;
arrElem->from = "";
arrElem->outterScope = false;
arrElem->type =  at.str((struct string*)&at);
char * ____BAH_COMPILER_VAR_359 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("->data[arrElemIndex]");
;                            
                        ____BAH_COMPILER_VAR_359 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_359+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_359+currStrOff, "->data[arrElemIndex]", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    arrElem->name =  ____BAH_COMPILER_VAR_359;
char * ____BAH_COMPILER_VAR_360 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (arrRCP != null && arrRCP->c == 1) {\n                struct RCP * arrDataRCP = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->data);\n                if (arrDataRCP != null && arrDataRCP->c == 1) {\n                    for(int arrElemIndex=len(");
long int strLen_5 = strlen(v->name);
long int strLen_6 = strlen(")-1; arrElemIndex >= 0; arrElemIndex--) {\n                        ");
;                            
                        ____BAH_COMPILER_VAR_360 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, "\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, ");\n            if (arrRCP != null && arrRCP->c == 1) {\n                struct RCP * arrDataRCP = RCP_request(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, "->data);\n                if (arrDataRCP != null && arrDataRCP->c == 1) {\n                    for(int arrElemIndex=len(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, v->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, ")-1; arrElemIndex >= 0; arrElemIndex--) {\n                        ", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    r =  rope(____BAH_COMPILER_VAR_360)->add(rope(____BAH_COMPILER_VAR_360), decrVar(arrElem,elems))->add(rope(____BAH_COMPILER_VAR_360)->add(rope(____BAH_COMPILER_VAR_360), decrVar(arrElem,elems)), rope("\n                    };\n                }\n                RCP_decrRCP(arrDataRCP);\n            }\n            RCP_decrRCP(arrRCP);\n            };//////////////////////\n            "));
}
else {
char * ____BAH_COMPILER_VAR_361 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };//////////////////////\n            ");
;                            
                        ____BAH_COMPILER_VAR_361 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_361+currStrOff, "\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_361+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_361+currStrOff, ");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_361+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_361+currStrOff, "->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };//////////////////////\n            ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    r =  rope(____BAH_COMPILER_VAR_361);
}
}
else {
int isPointer =  isRCPpointerType(v->type);
struct cStruct* s =  searchStruct(v->type,elems);
if (((s!=null)&&(s->isBinding==false))) {
char * amp =  "&";
char * heap =  "0";
if ((isPointer==true)) {
amp =  "";
heap =  "1";
}
char * ____BAH_COMPILER_VAR_362 =null;
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
                        ____BAH_COMPILER_VAR_362 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_362+currStrOff, "__RCP_clean_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_362+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_362+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_362+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_362+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_362+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_362+currStrOff, heap, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_362+currStrOff, ");\n", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_362));
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_363 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_decr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_363 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_363+currStrOff, "RCP_decr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_363+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_363+currStrOff, ");\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_363));
}
}
struct rope* ____BAH_COMPILER_VAR_364 = r;
return ____BAH_COMPILER_VAR_364;
};
struct rope* incrVar(struct variable* v,struct Elems* elems){
if ((strCount(v->name,"*")>0)) {
struct rope* ____BAH_COMPILER_VAR_365 = rope("");
return ____BAH_COMPILER_VAR_365;
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((((s!=null)&&(isRCPpointerType(v->type)==false))&&(s->isBinding==false))) {
char * ____BAH_COMPILER_VAR_366 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_incrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter);");
;                            
                        ____BAH_COMPILER_VAR_366 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_366+currStrOff, "RCP_incrCounter(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_366+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_366+currStrOff, ".__RCP_counter);", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* ____BAH_COMPILER_VAR_367 = rope(____BAH_COMPILER_VAR_366);
return ____BAH_COMPILER_VAR_367;
}
char * ____BAH_COMPILER_VAR_368 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_incr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");");
;                            
                        ____BAH_COMPILER_VAR_368 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_368+currStrOff, "RCP_incr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_368+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_368+currStrOff, ");", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* ____BAH_COMPILER_VAR_369 = rope(____BAH_COMPILER_VAR_368);
return ____BAH_COMPILER_VAR_369;
};
int RCPavailable(){
char * ____BAH_COMPILER_VAR_370 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("rcp.bah");
;                            
                        ____BAH_COMPILER_VAR_370 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_370+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_370+currStrOff, "rcp.bah", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * ____BAH_COMPILER_VAR_371 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("fastrcp.bah");
;                            
                        ____BAH_COMPILER_VAR_371 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_371+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_371+currStrOff, "fastrcp.bah", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    int ____BAH_COMPILER_VAR_372 = (((__checkString(compilerState.currentFile, "/home/alois/Documents/bah-bah/src/mem.bah:76 compilerState.currentFile ")==1&&__checkString(____BAH_COMPILER_VAR_370, "/home/alois/Documents/bah-bah/src/mem.bah:76 ____BAH_COMPILER_VAR_370")==1&&strcmp(compilerState.currentFile, ____BAH_COMPILER_VAR_370) != 0)&&(__checkString(compilerState.currentFile, "/home/alois/Documents/bah-bah/src/mem.bah:76 compilerState.currentFile ")==1&&__checkString(____BAH_COMPILER_VAR_371, "/home/alois/Documents/bah-bah/src/mem.bah:76 ____BAH_COMPILER_VAR_371")==1&&strcmp(compilerState.currentFile, ____BAH_COMPILER_VAR_371) != 0))&&(RCPenabled==true));
return ____BAH_COMPILER_VAR_372;
};
void endRCPscope(struct Elems* elems,__BAH_ARR_TYPE_variable exc){
if ((RCPavailable()==false)) {
return;
}
long int i =  0;
while ((i<len(elems->vars))) {

                        if (elems->vars->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/mem.bah:85): elems->vars[%d] with length %d\n", i, elems->vars->length);
                            exit(1);
                        };
                        struct variable* v =  elems->vars->data[i];
if (((v->outterScope==false)&&(isRCPtype(v->type,elems)==true))) {
if ((varInArr(v,exc)==false)) {
OUTPUT =  OUTPUT->add(OUTPUT, decrVar(v,elems));
}
}
i =  i + 1;
};
};
char * registerRCPvar(char * t,char * c,struct Elems* elems){
struct variable* av = memoryAlloc(sizeof(struct variable));
av->name = "";
av->type = "";
av->isConst = false;
av->constVal = "";
av->isArray = false;
av->from = "";
av->outterScope = false;
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
char * ____BAH_COMPILER_VAR_374 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_375 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_374);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(av->name);
long int strLen_3 = strlen(" =");
long int strLen_4 = strlen(c);
long int strLen_5 = strlen(";");
;                            
                        ____BAH_COMPILER_VAR_375 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_375+currStrOff, ____BAH_COMPILER_VAR_374, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_375+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_375+currStrOff, av->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_375+currStrOff, " =", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_375+currStrOff, c, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_375+currStrOff, ";", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_375));
char * ____BAH_COMPILER_VAR_376 = av->name;
return ____BAH_COMPILER_VAR_376;
};
struct rope* makeRCPfuncFromStruct(struct cStruct* s,struct Elems* elems){
if (((s->isBinding==true)||(RCPavailable()==false))) {
struct rope* ____BAH_COMPILER_VAR_377 = rope("");
return ____BAH_COMPILER_VAR_377;
}
struct rope* decrMembs =  rope("");
long int i =  0;
while ((i<len(s->members))) {

                        if (s->members->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/mem.bah:113): s->members[%d] with length %d\n", i, s->members->length);
                            exit(1);
                        };
                        struct structMemb* m =  s->members->data[i];
struct string rm =  string(m->type);
rm.replace((struct string*)&rm,"*","");
if (isRCPtype(m->type,elems)) {
if ((__checkString(rm.str((struct string*)&rm), "/home/alois/Documents/bah-bah/src/mem.bah:117 rm.str((struct string*)&rm) ")==1&&__checkString(s->name, "/home/alois/Documents/bah-bah/src/mem.bah:117 s->name")==1&&strcmp(rm.str((struct string*)&rm), s->name) != 0)) {
struct variable* mv = memoryAlloc(sizeof(struct variable));
mv->name = "";
mv->type = "";
mv->isConst = false;
mv->constVal = "";
mv->isArray = false;
mv->from = "";
mv->outterScope = false;
char * ____BAH_COMPILER_VAR_378 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("e->");
long int strLen_1 = strlen(m->name);
;                            
                        ____BAH_COMPILER_VAR_378 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_378+currStrOff, "e->", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_378+currStrOff, m->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    mv->name =  ____BAH_COMPILER_VAR_378;
mv->type =  m->type;
decrMembs =  decrMembs->add(decrMembs, decrVar(mv,elems));
}
else {
char * ____BAH_COMPILER_VAR_379 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Strcture '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has a self-referenced member '");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.");
;                            
                        ____BAH_COMPILER_VAR_379 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_379+currStrOff, "Strcture '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_379+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_379+currStrOff, "' has a self-referenced member '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_379+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_379+currStrOff, "'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwWarning(____BAH_COMPILER_VAR_379);
char * amp =  "&";
char * heap =  "0";
if ((strCount(m->type,"*")>0)) {
amp =  "";
heap =  "1";
}
char * ____BAH_COMPILER_VAR_380 =null;
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
                        ____BAH_COMPILER_VAR_380 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, "__RCP_clean_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, "e->", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, m->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, heap, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_380+currStrOff, ");\n", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    decrMembs =  decrMembs->add(decrMembs, rope(____BAH_COMPILER_VAR_380));
}
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_381 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("void* __RCP_clean_");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("(struct ");
long int strLen_3 = strlen(s->name);
long int strLen_4 = strlen("* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ");
;                            
                        ____BAH_COMPILER_VAR_381 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_381+currStrOff, "void* __RCP_clean_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_381+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_381+currStrOff, "(struct ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_381+currStrOff, s->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_381+currStrOff, "* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    struct rope* r =  rope(____BAH_COMPILER_VAR_381)->add(rope(____BAH_COMPILER_VAR_381), decrMembs)->add(rope(____BAH_COMPILER_VAR_381)->add(rope(____BAH_COMPILER_VAR_381), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_381)->add(rope(____BAH_COMPILER_VAR_381), decrMembs)->add(rope(____BAH_COMPILER_VAR_381)->add(rope(____BAH_COMPILER_VAR_381), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs)->add(rope(____BAH_COMPILER_VAR_381)->add(rope(____BAH_COMPILER_VAR_381), decrMembs)->add(rope(____BAH_COMPILER_VAR_381)->add(rope(____BAH_COMPILER_VAR_381), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_381)->add(rope(____BAH_COMPILER_VAR_381), decrMembs)->add(rope(____BAH_COMPILER_VAR_381)->add(rope(____BAH_COMPILER_VAR_381), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs), rope("\n        }\n    };\n"));
struct rope* ____BAH_COMPILER_VAR_382 = r;
return ____BAH_COMPILER_VAR_382;
};
int RCPselfRef(struct variable* v){
long int i =  0;
while ((i<len(compilerState.RCPvars))) {

                        if (compilerState.RCPvars->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/mem.bah:155): compilerState.RCPvars[%d] with length %d\n", i, compilerState.RCPvars->length);
                            exit(1);
                        };
                        struct variable* r =  compilerState.RCPvars->data[i];
if ((__checkString(r->name, "/home/alois/Documents/bah-bah/src/mem.bah:156 r->name ")==1&&__checkString(v->name, "/home/alois/Documents/bah-bah/src/mem.bah:156 v->name")==1&&strcmp(r->name, v->name) == 0)) {
int ____BAH_COMPILER_VAR_383 = true;
return ____BAH_COMPILER_VAR_383;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_384 = false;
return ____BAH_COMPILER_VAR_384;
};
void debugLine(__BAH_ARR_TYPE_Tok line){
char * cont =  "";
long int i =  0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:13): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
char * ____BAH_COMPILER_VAR_385 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(" '");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_385 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_385+currStrOff, cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_385+currStrOff, " '", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_385+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_385+currStrOff, "'", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    cont =  ____BAH_COMPILER_VAR_385;
i =  i + 1;
};
println(cont);
};
struct Elems* dupElems(struct Elems* elems){
struct Elems* nElems = memoryAlloc(sizeof(struct Elems));
nElems->vars = memoryAlloc(sizeof(array(struct variable*)));
            nElems->vars->length = 0;
            nElems->vars->elemSize = sizeof(struct variable*);
            nElems->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            nElems->structs->length = 0;
            nElems->structs->elemSize = sizeof(struct cStruct*);
            nElems->types = memoryAlloc(sizeof(array(char *)));
            nElems->types->length = 0;
            nElems->types->elemSize = sizeof(char *);
            nElems->fns = memoryAlloc(sizeof(array(struct func*)));
            nElems->fns->length = 0;
            nElems->fns->elemSize = sizeof(struct func*);
            long int j =  0;
while ((j<len(elems->vars))) {

                        if (elems->vars->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:27): elems->vars[%d] with length %d\n", j, elems->vars->length);
                            exit(1);
                        };
                        struct variable* v =  elems->vars->data[j];
struct variable* nv = memoryAlloc(sizeof(struct variable));
nv->name = "";
nv->type = "";
nv->isConst = false;
nv->constVal = "";
nv->isArray = false;
nv->from = "";
nv->outterScope = false;
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
j =  j + 1;
};
j =  0;
while ((j<len(elems->structs))) {

                        if (elems->structs->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:37): elems->structs[%d] with length %d\n", j, elems->structs->length);
                            exit(1);
                        };
                        struct cStruct* s =  elems->structs->data[j];
struct cStruct* ns = memoryAlloc(sizeof(struct cStruct));
ns->name = "";
ns->members = memoryAlloc(sizeof(array(struct structMemb*)));
            ns->members->length = 0;
            ns->members->elemSize = sizeof(struct structMemb*);
            ns->methods = memoryAlloc(sizeof(array(struct func*)));
            ns->methods->length = 0;
            ns->methods->elemSize = sizeof(struct func*);
            ns->postCode = "";
ns->extendedFrom = "";
ns->isBinding = false;
ns->hasRCPmemb = false;
*ns =  *s;

{
long nLength = j;
if (nElems->structs->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nElems->structs->data, (nLength+50)*sizeof(struct cStruct*));
nElems->structs->data = newPtr;
}
nElems->structs->data[j] =  ns;
nElems->structs->length = nLength+1;
} else {
nElems->structs->data[j] =  ns;
}
};
j =  j + 1;
};
j =  0;
while ((j<len(elems->types))) {

                        if (elems->types->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:46): elems->types[%d] with length %d\n", j, elems->types->length);
                            exit(1);
                        };
                        char * t =  elems->types->data[j];
char * nt =  t;

{
long nLength = j;
if (nElems->types->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nElems->types->data, (nLength+50)*sizeof(char *));
nElems->types->data = newPtr;
}
nElems->types->data[j] =  nt;
nElems->types->length = nLength+1;
} else {
nElems->types->data[j] =  nt;
}
};
j =  j + 1;
};
j =  0;
while ((j<len(elems->fns))) {

                        if (elems->fns->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:54): elems->fns[%d] with length %d\n", j, elems->fns->length);
                            exit(1);
                        };
                        struct func* f =  elems->fns->data[j];
struct func* nf = memoryAlloc(sizeof(struct func));
nf->name = "";
nf->args = memoryAlloc(sizeof(array(struct variable*)));
            nf->args->length = 0;
            nf->args->elemSize = sizeof(struct variable*);
            nf->returns= null;
nf->isBinding = false;
nf->from = "";
nf->file = "";
nf->line = 1;
*nf =  *f;

{
long nLength = j;
if (nElems->fns->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nElems->fns->data, (nLength+50)*sizeof(struct func*));
nElems->fns->data = newPtr;
}
nElems->fns->data[j] =  nf;
nElems->fns->length = nLength+1;
} else {
nElems->fns->data[j] =  nf;
}
};
j =  j + 1;
};
struct Elems* ____BAH_COMPILER_VAR_386 = nElems;
return ____BAH_COMPILER_VAR_386;
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
lineType prevLine;
lineType getLineType(__BAH_ARR_TYPE_Tok line){

                        if (line->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:88): line[%d] with length %d\n", 0, line->length);
                            exit(1);
                        };
                        struct Tok ft =  line->data[0];
if ((ft.type==TOKEN_TYPE_FUNC)) {
lineType ____BAH_COMPILER_VAR_387 = LINE_TYPE_FN_CALL;
return ____BAH_COMPILER_VAR_387;
}
if ((ft.type==TOKEN_TYPE_KEYWORD)) {
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:94 ft.cont ")==1&&strcmp(ft.cont, "#include") == 0)) {
lineType ____BAH_COMPILER_VAR_388 = LINE_TYPE_INCLUDE;
return ____BAH_COMPILER_VAR_388;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:96 ft.cont ")==1&&strcmp(ft.cont, "#define") == 0)) {
lineType ____BAH_COMPILER_VAR_389 = LINE_TYPE_DEFINE;
return ____BAH_COMPILER_VAR_389;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:98 ft.cont ")==1&&strcmp(ft.cont, "const") == 0)) {
lineType ____BAH_COMPILER_VAR_390 = LINE_TYPE_CONST;
return ____BAH_COMPILER_VAR_390;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:100 ft.cont ")==1&&strcmp(ft.cont, "struct") == 0)) {
lineType ____BAH_COMPILER_VAR_391 = LINE_TYPE_STRUCT;
return ____BAH_COMPILER_VAR_391;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:102 ft.cont ")==1&&strcmp(ft.cont, "#cLib") == 0)) {
lineType ____BAH_COMPILER_VAR_392 = LINE_TYPE_CLIB;
return ____BAH_COMPILER_VAR_392;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:104 ft.cont ")==1&&strcmp(ft.cont, "return") == 0)) {
lineType ____BAH_COMPILER_VAR_393 = LINE_TYPE_RETURN;
return ____BAH_COMPILER_VAR_393;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:106 ft.cont ")==1&&strcmp(ft.cont, "if") == 0)) {
lineType ____BAH_COMPILER_VAR_394 = LINE_TYPE_IF;
return ____BAH_COMPILER_VAR_394;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:108 ft.cont ")==1&&strcmp(ft.cont, "else") == 0)) {
lineType ____BAH_COMPILER_VAR_395 = LINE_TYPE_ELSE;
return ____BAH_COMPILER_VAR_395;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:110 ft.cont ")==1&&strcmp(ft.cont, "#macro") == 0)) {
lineType ____BAH_COMPILER_VAR_396 = LINE_TYPE_MACRO;
return ____BAH_COMPILER_VAR_396;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:112 ft.cont ")==1&&strcmp(ft.cont, "for") == 0)) {
lineType ____BAH_COMPILER_VAR_397 = LINE_TYPE_FOR;
return ____BAH_COMPILER_VAR_397;
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:114 ft.cont ")==1&&strcmp(ft.cont, "async") == 0)) {
lineType ____BAH_COMPILER_VAR_398 = LINE_TYPE_ASYNC;
return ____BAH_COMPILER_VAR_398;
}
else if (((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:116 ft.cont ")==1&&strcmp(ft.cont, "continue") == 0)||(__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:116 ft.cont ")==1&&strcmp(ft.cont, "break") == 0))) {
lineType ____BAH_COMPILER_VAR_399 = LINE_TYPE_FOR_OPERATOR;
return ____BAH_COMPILER_VAR_399;
}
else {
lineType ____BAH_COMPILER_VAR_400 = LINE_TYPE_PRE_KEYWORD;
return ____BAH_COMPILER_VAR_400;
}
}
else if ((ft.type==TOKEN_TYPE_VAR)) {
if ((len(line)==1)) {
throwErr(&ft,"Cannot declare var {TOKEN} without a type.");
}

                        if (line->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:125): line[%d] with length %d\n", 1, line->length);
                            exit(1);
                        };
                        struct Tok st =  line->data[1];
if (((st.type==TOKEN_TYPE_ENCL)&&(__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:126 st.cont ")==1&&strcmp(st.cont, "(") == 0))) {

                        if (line->length <= len(line)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:127): line[%d] with length %d\n", len(line)-1, line->length);
                            exit(1);
                        };
                        struct Tok lt =  line->data[len(line)-1];
if (((lt.type==TOKEN_TYPE_ENCL)&&(__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:128 lt.cont ")==1&&strcmp(lt.cont, "}") == 0))) {
lineType ____BAH_COMPILER_VAR_401 = LINE_TYPE_FN_DECL;
return ____BAH_COMPILER_VAR_401;
}
lineType ____BAH_COMPILER_VAR_402 = LINE_TYPE_FN_CALL;
return ____BAH_COMPILER_VAR_402;
}
lineType ____BAH_COMPILER_VAR_403 = LINE_TYPE_VAR;
return ____BAH_COMPILER_VAR_403;
}
lineType ____BAH_COMPILER_VAR_404 = (lineType)-1;
return ____BAH_COMPILER_VAR_404;
};
__BAH_ARR_TYPE_Tok parseCast(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:147): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:148 t.cont ")==1&&strcmp(t.cont, "<") == 0)) {
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
array(struct Tok)* ____BAH_COMPILER_VAR_405 = line;
return ____BAH_COMPILER_VAR_405;
}
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:159): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:161 t.cont ")==1&&strcmp(t.cont, "<") == 0)) {
long int max =  i + 3;
if ((max<len(line))) {

                        if (line->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:164): line[%d] with length %d\n", i + 1, line->length);
                            exit(1);
                        };
                        struct Tok nt =  line->data[i + 1];

                        if (line->length <= i + 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:165): line[%d] with length %d\n", i + 2, line->length);
                            exit(1);
                        };
                        struct Tok nnt =  line->data[i + 2];

                        if (line->length <= i + 3) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:166): line[%d] with length %d\n", i + 3, line->length);
                            exit(1);
                        };
                        struct Tok nnnt =  line->data[i + 3];
if ((nt.type==TOKEN_TYPE_VAR)) {
if ((nnt.type==TOKEN_TYPE_SYNTAX)) {
if ((__checkString(nnt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:169 nnt.cont ")==1&&strcmp(nnt.cont, ">") == 0)) {
nnnt.bahType =  nt.cont;
struct string cCast =  getCType(nt.cont,elems);
char * cCastStr =  cCast.str((struct string*)&cCast);
char * ____BAH_COMPILER_VAR_406 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(cCastStr);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nnnt.cont);
;                            
                        ____BAH_COMPILER_VAR_406 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, cCastStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, nnnt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    nnnt.cont =  ____BAH_COMPILER_VAR_406;

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
i =  i + 4;
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
i =  i + 1;
};
array(struct Tok)* ____BAH_COMPILER_VAR_407 = nl;
return ____BAH_COMPILER_VAR_407;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_408 =__STR(f);array(char)* p =  strAsArr(____BAH_COMPILER_VAR_408);
long int i =  len(p)-1;
while ((i>=0)) {

                        if (p->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:196): p[%d] with length %d\n", i, p->length);
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
char * ____BAH_COMPILER_VAR_409 = "";
return ____BAH_COMPILER_VAR_409;
}
char * ____BAH_COMPILER_VAR_410 = arrAsStr(p);
return ____BAH_COMPILER_VAR_410;
};
void parseLines(__BAH_ARR_TYPE_Tok ts,struct Elems* elems);
int includeFile(char * ccstr,struct Elems* elems){
if ((__checkString(ccstr, "/home/alois/Documents/bah-bah/src/parser.bah:214 ccstr ")==1&&strcmp(ccstr, "BAH_MEM_COLLECTOR") == 0)) {
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
array(char *)* includes =  compilerState.includes;
long int i =  0;
while ((i<len(includes))) {

                        if (includes->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:228): includes[%d] with length %d\n", i, includes->length);
                            exit(1);
                        };
                        if ((__checkString(includes->data[i], "/home/alois/Documents/bah-bah/src/parser.bah:228 includes->data[i] ")==1&&__checkString(ccstr, "/home/alois/Documents/bah-bah/src/parser.bah:228 ccstr")==1&&strcmp(includes->data[i], ccstr) == 0)) {
int ____BAH_COMPILER_VAR_411 = true;
return ____BAH_COMPILER_VAR_411;
}
i =  i + 1;
};
struct fileMap ____BAH_COMPILER_VAR_412 = {};
____BAH_COMPILER_VAR_412.open = fileMap__open;
____BAH_COMPILER_VAR_412.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_412.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_412;
char * ____BAH_COMPILER_VAR_413 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(ccstr);
;                            
                        ____BAH_COMPILER_VAR_413 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, ccstr, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * fileName =  ____BAH_COMPILER_VAR_413;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_414 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(ccstr);
;                            
                        ____BAH_COMPILER_VAR_414 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_414+currStrOff, compilerState.currentDir, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_414+currStrOff, ccstr, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fileName =  absPath(____BAH_COMPILER_VAR_414);
f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
int ____BAH_COMPILER_VAR_415 = false;
return ____BAH_COMPILER_VAR_415;
}
}
char * oDir =  compilerState.currentDir;
char * ____BAH_COMPILER_VAR_416 =getDirFromFile(ccstr);char * ____BAH_COMPILER_VAR_417 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_416);
;                            
                        ____BAH_COMPILER_VAR_417 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_417+currStrOff, compilerState.currentDir, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_417+currStrOff, ____BAH_COMPILER_VAR_416, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    compilerState.currentDir =  ____BAH_COMPILER_VAR_417;
char * oFile =  compilerState.currentFile;
compilerState.currentFile =  fileName;

{
long nLength = len(includes);
if (includes->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(includes->data, (nLength+50)*sizeof(char *));
includes->data = newPtr;
}
includes->data[len(includes)] =  ccstr;
includes->length = nLength+1;
} else {
includes->data[len(includes)] =  ccstr;
}
};
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_418 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(ccstr);
long int strLen_2 = strlen("' not recognized.");
;                            
                        ____BAH_COMPILER_VAR_418 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_418+currStrOff, "File '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_418+currStrOff, ccstr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_418+currStrOff, "' not recognized.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_418);
}
parseLines(tokens,elems);
compilerState.currentFile =  oFile;
compilerState.currentDir =  oDir;
int ____BAH_COMPILER_VAR_419 = true;
return ____BAH_COMPILER_VAR_419;
};
void parseInclude(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)>2)) {
throwErr(&l->data[len(l)-1],"Invalid usage of include, ending by {TOKEN}.");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:265): l[%d] with length %d\n", 1, l->length);
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
char * ____BAH_COMPILER_VAR_420 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(sc);
long int strLen_2 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_420 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_420+currStrOff, "#include ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_420+currStrOff, sc, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_420+currStrOff, "\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_420));

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
__BAH_ARR_TYPE_Tok parseOperations(__BAH_ARR_TYPE_Tok line,struct Elems* elems){

                        if (line->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:287): line[%d] with length %d\n", 0, line->length);
                            exit(1);
                        };
                        array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 1;
nl->elemSize = sizeof(struct Tok);
nl->data = memoryAlloc(sizeof(struct Tok) * 50);nl->data[0] = line->data[0];
long int i =  1;
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:290): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if (((t.type==TOKEN_TYPE_SYNTAX)&&inArrayStr(t.cont,signs))) {
if ((i + 1>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} on nothing.");
}

                        if (nl->length <= len(nl)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:295): nl[%d] with length %d\n", len(nl)-1, nl->length);
                            exit(1);
                        };
                        struct Tok pt =  nl->data[len(nl)-1];

                        if (line->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:296): line[%d] with length %d\n", i + 1, line->length);
                            exit(1);
                        };
                        struct Tok nt =  line->data[i + 1];
if ((((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:297 t.cont ")==1&&strcmp(t.cont, "-") == 0)&&(pt.isValue==false))&&(nt.type==TOKEN_TYPE_INT))) {
char * ____BAH_COMPILER_VAR_421 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_421 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nt.cont =  ____BAH_COMPILER_VAR_421;

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
if (((nt.type==TOKEN_TYPE_SYNTAX)&&(__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:304 nt.cont ")==1&&__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:304 t.cont")==1&&strcmp(nt.cont, t.cont) == 0))) {
char * ____BAH_COMPILER_VAR_422 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_422 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_422+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_422+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * c =  ____BAH_COMPILER_VAR_422;
long int tl =  t.line;
long int tp =  t.pos;
struct Tok ____BAH_COMPILER_VAR_423 = {};
____BAH_COMPILER_VAR_423.cont = "";
____BAH_COMPILER_VAR_423.ogCont = "";
____BAH_COMPILER_VAR_423.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_423.pos = 0;
____BAH_COMPILER_VAR_423.line = 1;
____BAH_COMPILER_VAR_423.begLine = 1;
____BAH_COMPILER_VAR_423.bahType = "";
____BAH_COMPILER_VAR_423.isValue = false;
____BAH_COMPILER_VAR_423.isFunc = false;
____BAH_COMPILER_VAR_423.isOper = false;
____BAH_COMPILER_VAR_423.cont = c;
____BAH_COMPILER_VAR_423.ogCont = c;
____BAH_COMPILER_VAR_423.isValue = false;
____BAH_COMPILER_VAR_423.line = tl;
____BAH_COMPILER_VAR_423.pos = tp;
____BAH_COMPILER_VAR_423.type = TOKEN_TYPE_SYNTAX;
struct Tok tmpT =  ____BAH_COMPILER_VAR_423;

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
char * ____BAH_COMPILER_VAR_424 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_424 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_424+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_424+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_424+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_424+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_424+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_424);
}
t.isValue =  true;
if (compTypes(ptt,"cpstring")) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:328 t.cont ")==1&&strcmp(t.cont, "+") != 0)) {
throwErr(&t,"Can only do concatenation (+) on cpstrings, not {TOKEN}.");
}
long int j =  i - 1;
int wasAdd =  true;
array(char *)* strConts = memoryAlloc(sizeof(array(char *)));

strConts->length = 0;
strConts->elemSize = sizeof(char *);
while ((j<len(line))) {

                        if (line->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:335): line[%d] with length %d\n", j, line->length);
                            exit(1);
                        };
                        struct Tok strAddTk =  line->data[j];
if ((wasAdd==false)) {
if ((__checkString(strAddTk.cont, "/home/alois/Documents/bah-bah/src/parser.bah:337 strAddTk.cont ")==1&&strcmp(strAddTk.cont, "+") != 0)) {
break;
}
wasAdd =  true;
}
else {
char * strAddTkT =  getTypeFromToken(&strAddTk,true,elems);
if ((compTypes(strAddTkT,"cpstring")==false)) {
char * ____BAH_COMPILER_VAR_425 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_425 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&strAddTkT,____BAH_COMPILER_VAR_425);
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
j =  j + 1;
};
i =  j;
char * rstr =  registerRCPvar("cpstring","null",elems);
char * lens =  "";
char * totStrLen =  "1";
j =  0;
while ((j<len(strConts))) {
char * js =  intToStr(j);

                        if (strConts->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:366): strConts[%d] with length %d\n", j, strConts->length);
                            exit(1);
                        };
                        char * ____BAH_COMPILER_VAR_426 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(lens);
long int strLen_1 = strlen("long int strLen_");
long int strLen_2 = strlen(js);
long int strLen_3 = strlen(" = strlen(");
long int strLen_4 = strlen(strConts->data[j]);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_426 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, lens, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, "long int strLen_", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, js, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, " = strlen(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, strConts->data[j], strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    lens =  ____BAH_COMPILER_VAR_426;
char * ____BAH_COMPILER_VAR_427 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(" + strLen_");
long int strLen_2 = strlen(js);
;                            
                        ____BAH_COMPILER_VAR_427 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, totStrLen, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, " + strLen_", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_427+currStrOff, js, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    totStrLen =  ____BAH_COMPILER_VAR_427;
j =  j + 1;
};
struct rope* cats =  rope("");
j =  0;
while ((j<len(strConts))) {
char * js =  intToStr(j);

                        if (strConts->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:374): strConts[%d] with length %d\n", j, strConts->length);
                            exit(1);
                        };
                        char * ____BAH_COMPILER_VAR_428 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n                        strncpy(");
long int strLen_1 = strlen(rstr);
long int strLen_2 = strlen("+currStrOff, ");
long int strLen_3 = strlen(strConts->data[j]);
long int strLen_4 = strlen(", strLen_");
long int strLen_5 = strlen(js);
long int strLen_6 = strlen(");\n                        currStrOff += strLen_");
long int strLen_7 = strlen(js);
long int strLen_8 = strlen(";\n                        ");
;                            
                        ____BAH_COMPILER_VAR_428 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, "\n                        strncpy(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, rstr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, "+currStrOff, ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, strConts->data[j], strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, ", strLen_", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, js, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, ");\n                        currStrOff += strLen_", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, js, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_428+currStrOff, ";\n                        ", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    cats =  cats->add(cats, rope(____BAH_COMPILER_VAR_428));
j =  j + 1;
};
char * ____BAH_COMPILER_VAR_429 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n                    {\n                        long int currStrOff = 0;\n                        ");
long int strLen_1 = strlen(lens);
long int strLen_2 = strlen(";                            \n                        ");
long int strLen_3 = strlen(rstr);
long int strLen_4 = strlen(" = memoryAllocSTR(");
long int strLen_5 = strlen(totStrLen);
long int strLen_6 = strlen(");\n                        ");
;                            
                        ____BAH_COMPILER_VAR_429 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_429+currStrOff, "\n                    {\n                        long int currStrOff = 0;\n                        ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_429+currStrOff, lens, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_429+currStrOff, ";                            \n                        ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_429+currStrOff, rstr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_429+currStrOff, " = memoryAllocSTR(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_429+currStrOff, totStrLen, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_429+currStrOff, ");\n                        ", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    struct rope* res =  rope(____BAH_COMPILER_VAR_429)->add(rope(____BAH_COMPILER_VAR_429), cats)->add(rope(____BAH_COMPILER_VAR_429)->add(rope(____BAH_COMPILER_VAR_429), cats), rope("\n                    }\n                    "));
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
if ((((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:419 t.cont ")==1&&strcmp(t.cont, "+") == 0)&&(addMthd!=null))&&(addMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_430 =null;
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
                        ____BAH_COMPILER_VAR_430 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, "add(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_430;
}
else if ((((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:421 t.cont ")==1&&strcmp(t.cont, "-") == 0)&&(subMthd!=null))&&(subMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_431 =null;
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
                        ____BAH_COMPILER_VAR_431 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_431+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_431+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_431+currStrOff, "sub(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_431+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_431+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_431+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_431+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_431+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_431;
}
else if ((((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:423 t.cont ")==1&&strcmp(t.cont, "*") == 0)&&(multMthd!=null))&&(multMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_432 =null;
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
                        ____BAH_COMPILER_VAR_432 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_432+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_432+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_432+currStrOff, "mult(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_432+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_432+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_432+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_432+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_432+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_432;
}
else if ((((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:425 t.cont ")==1&&strcmp(t.cont, "/") == 0)&&(divMthd!=null))&&(divMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_433 =null;
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
                        ____BAH_COMPILER_VAR_433 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_433+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_433+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_433+currStrOff, "div(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_433+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_433+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_433+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_433+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_433+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_433;
}
else {
char * ____BAH_COMPILER_VAR_434 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Undefined operation on {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(").");
;                            
                        ____BAH_COMPILER_VAR_434 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_434+currStrOff, "Undefined operation on {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_434+currStrOff, ptt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_434+currStrOff, ").", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&pt,____BAH_COMPILER_VAR_434);
}
}
else {
char * ____BAH_COMPILER_VAR_435 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_435 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_435+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_435+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_435+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_435+currStrOff, " ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_435+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_435;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:445): nl[%d] with length %d\n", len(nl)-1, nl->length);
                            exit(1);
                        };
                        struct Tok pt =  nl->data[len(nl)-1];
if ((pt.isValue==true)) {
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&t,true,elems);
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_436 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_436);
}
t.type =  TOKEN_TYPE_VAR;
t.isOper =  true;
char * ____BAH_COMPILER_VAR_437 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_437 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_437+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_437+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_437;
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
i =  i + 1;
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
i =  i + 1;
};
array(struct Tok)* ____BAH_COMPILER_VAR_438 = nl;
return ____BAH_COMPILER_VAR_438;
};
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems);
__BAH_ARR_TYPE_Tok parseStructType(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:478): line[%d] with length %d\n", i, line->length);
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
i =  i + 1;
continue;
}
i =  i + 1;
if ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:487): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok nt =  line->data[i];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:488 nt.cont ")==1&&strcmp(nt.cont, "{") == 0)) {
i =  i + 1;
struct cStruct* s =  searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct name {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:496): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:497 t.cont ")==1&&strcmp(t.cont, "}") == 0)) {
break;
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
i =  i + 1;
};
long int declType =  0;
char * rvn =  genCompilerVar();
struct variable* tmpV = memoryAlloc(sizeof(struct variable));
tmpV->name = "";
tmpV->type = "";
tmpV->isConst = false;
tmpV->constVal = "";
tmpV->isArray = false;
tmpV->from = "";
tmpV->outterScope = false;
tmpV->name =  rvn;
tmpV->type =  s->name;
struct string rst =  getCType(s->name,elems);
char * ____BAH_COMPILER_VAR_439 =rst.str((struct string*)&rst);char * ____BAH_COMPILER_VAR_440 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_441 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_439);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen("{};\n");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_440);
;                            
                        ____BAH_COMPILER_VAR_441 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, ____BAH_COMPILER_VAR_439, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, rvn, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, "{};\n", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, ____BAH_COMPILER_VAR_440, strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    struct rope* r =  rope(____BAH_COMPILER_VAR_441);
long int j =  0;
long int k =  0;
while ((k<len(memory))) {

                        if (memory->length <= k) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:512): memory[%d] with length %d\n", k, memory->length);
                            exit(1);
                        };
                        t =  memory->data[k];
if ((k + 2<len(memory))) {

                        if (memory->length <= k + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:514): memory[%d] with length %d\n", k + 1, memory->length);
                            exit(1);
                        };
                        struct Tok st =  memory->data[k + 1];

                        if (memory->length <= k + 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:515): memory[%d] with length %d\n", k + 2, memory->length);
                            exit(1);
                        };
                        struct Tok vl =  memory->data[k + 2];
if ((__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:516 st.cont ")==1&&strcmp(st.cont, ":") == 0)) {
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:525): s->members[%d] with length %d\n", j, s->members->length);
                            exit(1);
                        };
                        struct structMemb* m =  s->members->data[j];
if ((__checkString(m->name, "/home/alois/Documents/bah-bah/src/parser.bah:526 m->name ")==1&&__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:526 t.cont")==1&&strcmp(m->name, t.cont) != 0)) {
j =  j + 1;
continue;
}
char * vlt =  getTypeFromToken(&vl,true,elems);
if ((compTypes(vlt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_442 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(vlt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_442 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, vlt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, ") as '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, m->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, "'.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&vl,____BAH_COMPILER_VAR_442);
}
char * ____BAH_COMPILER_VAR_443 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(vl.cont);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_443 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, rvn, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, ".", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, m->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, vl.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_443));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_444 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Struct '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has no member called {TOKEN}.");
;                            
                        ____BAH_COMPILER_VAR_444 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, "Struct '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, "' has no member called {TOKEN}.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_444);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:552): s->members[%d] with length %d\n", j, s->members->length);
                            exit(1);
                        };
                        struct structMemb* m =  s->members->data[j];
j =  j + 1;
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_445 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_445 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_445+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_445+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_445+currStrOff, ") as '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_445+currStrOff, m->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_445+currStrOff, "'.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_445);
}
char * ____BAH_COMPILER_VAR_446 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_446 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, rvn, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, ".", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, m->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_446));
if ((k + 1<len(memory))) {
k =  k + 1;

                        if (memory->length <= k) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:564): memory[%d] with length %d\n", k, memory->length);
                            exit(1);
                        };
                        struct Tok st =  memory->data[k];
if ((__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:565 st.cont ")==1&&strcmp(st.cont, ",") != 0)) {
throwErr(&st,"Need ',' separator between two values, not {TOKEN}.");
}
}
k =  k + 1;
};
if (isGlobal()) {
INIT =  INIT->add(INIT, r);
}
else {
OUTPUT =  OUTPUT->add(OUTPUT, r);
}
t.bahType =  s->name;
t.cont =  rvn;
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
i =  i + 1;
continue;
}
else {
i =  i - 1;
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
array(struct Tok)* ____BAH_COMPILER_VAR_447 = nl;
return ____BAH_COMPILER_VAR_447;
};
__BAH_ARR_TYPE_Tok parseStructVars(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:603): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:604 t.cont ")==1&&strcmp(t.cont, ".") == 0)) {
break;
}
i =  i + 1;
};
if ((i==len(line))) {
array(struct Tok)* ____BAH_COMPILER_VAR_448 = line;
return ____BAH_COMPILER_VAR_448;
}
i =  0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:615): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:619): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok it =  line->data[i];
if ((__checkString(it.cont, "/home/alois/Documents/bah-bah/src/parser.bah:620 it.cont ")==1&&strcmp(it.cont, ".") != 0)) {
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
char * ____BAH_COMPILER_VAR_449 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(v->type);
long int strLen_2 = strlen(") as a structure.");
;                            
                        ____BAH_COMPILER_VAR_449 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_449+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_449+currStrOff, v->type, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_449+currStrOff, ") as a structure.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_449);
}
i =  i + 1;

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:636): line[%d] with length %d\n", i, line->length);
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
char * ____BAH_COMPILER_VAR_450 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(memb->name);
;                            
                        ____BAH_COMPILER_VAR_450 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_450+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_450+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_450+currStrOff, memb->name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_450;
i =  i + 1;
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
i =  i + 1;
};
array(struct Tok)* ____BAH_COMPILER_VAR_451 = nl;
return ____BAH_COMPILER_VAR_451;
};
__BAH_ARR_TYPE_Tok parseArrayType(__BAH_ARR_TYPE_Tok line,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:664): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:665 t.cont ")==1&&strcmp(t.cont, "[") == 0)) {
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
array(struct Tok)* ____BAH_COMPILER_VAR_452 = line;
return ____BAH_COMPILER_VAR_452;
}
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:676): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:677 t.cont ")==1&&strcmp(t.cont, "[") == 0)) {
i =  i + 1;
if ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:680): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:681 t.cont ")==1&&strcmp(t.cont, "]") == 0)) {
i =  i + 1;
if ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:684): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        t =  line->data[i];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as array type.");
}
char * arrElem =  t.cont;
char * ____BAH_COMPILER_VAR_453 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("[]");
long int strLen_1 = strlen(arrElem);
;                            
                        ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_453+currStrOff, "[]", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_453+currStrOff, arrElem, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    t.bahType =  ____BAH_COMPILER_VAR_453;
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
array(struct Tok)* ____BAH_COMPILER_VAR_454 = nl;
return ____BAH_COMPILER_VAR_454;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:716): line[%d] with length %d\n", i, line->length);
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
array(struct Tok)* ____BAH_COMPILER_VAR_455 = line;
return ____BAH_COMPILER_VAR_455;
}
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:728): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if (inArrayStr(t.cont,comparators)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (nl->length <= len(nl)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:734): nl[%d] with length %d\n", len(nl)-1, nl->length);
                            exit(1);
                        };
                        struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (line->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:739): line[%d] with length %d\n", i + 1, line->length);
                            exit(1);
                        };
                        struct Tok nt =  line->data[i + 1];
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:743 t.cont ")==1&&strcmp(t.cont, "in") == 0)) {
struct string arrT =  string(ntt);
if ((arrT.hasPrefix((struct string*)&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_456 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as an array.");
;                            
                        ____BAH_COMPILER_VAR_456 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_456+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_456+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_456+currStrOff, ") as an array.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_456);
}
arrT.trimLeft((struct string*)&arrT,2);
char * ____BAH_COMPILER_VAR_457 =arrT.str((struct string*)&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_457)==false)) {
char * ____BAH_COMPILER_VAR_458 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot search for {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(") inside array of type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_458 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_458+currStrOff, "Cannot search for {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_458+currStrOff, ptt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_458+currStrOff, ") inside array of type ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_458+currStrOff, ntt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_458+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&pt,____BAH_COMPILER_VAR_458);
}
char * compVar =  genCompilerVar();
char * comp =  "";
if ((__checkString(ptt, "/home/alois/Documents/bah-bah/src/parser.bah:756 ptt ")==1&&strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_459 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] != 0 && strcmp(");
long int strLen_2 = strlen(nt.cont);
long int strLen_3 = strlen("->data[i], ");
long int strLen_4 = strlen(pt.cont);
long int strLen_5 = strlen(") == 0");
;                            
                        ____BAH_COMPILER_VAR_459 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_459+currStrOff, nt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_459+currStrOff, "->data[i] != 0 && strcmp(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_459+currStrOff, nt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_459+currStrOff, "->data[i], ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_459+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_459+currStrOff, ") == 0", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    comp =  ____BAH_COMPILER_VAR_459;
}
else {
char * ____BAH_COMPILER_VAR_460 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] == ");
long int strLen_2 = strlen(pt.cont);
;                            
                        ____BAH_COMPILER_VAR_460 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, nt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, "->data[i] == ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    comp =  ____BAH_COMPILER_VAR_460;
}
char * ____BAH_COMPILER_VAR_461 =null;
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
                        ____BAH_COMPILER_VAR_461 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, "\n                int ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, compVar, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, " = 0;\n                for(int i=len(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, ")-1; i != -1; i--) {\n                    if (", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, comp, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, ") {\n                        ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, compVar, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, " = 1;\n                        break;\n                    };\n                };\n                ", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_461));
pt.cont =  compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_462 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot compare {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_462 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, "Cannot compare {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, ") to ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_462+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_462);
}
if ((__checkString(ptt, "/home/alois/Documents/bah-bah/src/parser.bah:776 ptt ")==1&&strcmp(ptt, "cpstring") == 0)) {
char * check =  "";
if ((pt.type!=TOKEN_TYPE_STR)) {
char * ____BAH_COMPILER_VAR_463 =intToStr(t.line);char * ____BAH_COMPILER_VAR_464 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__checkString(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_463);
long int strLen_6 = strlen(" ");
long int strLen_7 = strlen(pt.cont);
long int strLen_8 = strlen(" \")==1&&");
;                            
                        ____BAH_COMPILER_VAR_464 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, "__checkString(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, ", \"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, compilerState.currentFile, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, ____BAH_COMPILER_VAR_463, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, " ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, pt.cont, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, " \")==1&&", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    check =  ____BAH_COMPILER_VAR_464;
}
if ((nt.type!=TOKEN_TYPE_STR)) {
char * ____BAH_COMPILER_VAR_465 =intToStr(t.line);char * ____BAH_COMPILER_VAR_466 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(check);
long int strLen_1 = strlen("__checkString(");
long int strLen_2 = strlen(nt.cont);
long int strLen_3 = strlen(", \"");
long int strLen_4 = strlen(compilerState.currentFile);
long int strLen_5 = strlen(":");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_465);
long int strLen_7 = strlen(" ");
long int strLen_8 = strlen(nt.cont);
long int strLen_9 = strlen("\")==1&&");
;                            
                        ____BAH_COMPILER_VAR_466 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                        
                        strncpy(____BAH_COMPILER_VAR_466+currStrOff, check, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_466+currStrOff, "__checkString(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_466+currStrOff, nt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_466+currStrOff, ", \"", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_466+currStrOff, compilerState.currentFile, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_466+currStrOff, ":", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_466+currStrOff, ____BAH_COMPILER_VAR_465, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_466+currStrOff, " ", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_466+currStrOff, nt.cont, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_466+currStrOff, "\")==1&&", strLen_9);
                        currStrOff += strLen_9;
                        
                    }
                    check =  ____BAH_COMPILER_VAR_466;
}
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:784 t.cont ")==1&&strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_467 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strcmp(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(") == 0)");
;                            
                        ____BAH_COMPILER_VAR_467 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, "strcmp(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, ") == 0)", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_467;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:786 t.cont ")==1&&strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_468 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strcmp(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(", ");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(") != 0)");
;                            
                        ____BAH_COMPILER_VAR_468 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, "strcmp(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, ", ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, ") != 0)", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_468;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:788 t.cont ")==1&&strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_469 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(") > srtlen(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_469 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_469+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_469+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_469+currStrOff, "strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_469+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_469+currStrOff, ") > srtlen(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_469+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_469+currStrOff, "))", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_469;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:790 t.cont ")==1&&strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_470 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(") < srtlen(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_470 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_470+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_470+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_470+currStrOff, "strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_470+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_470+currStrOff, ") < srtlen(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_470+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_470+currStrOff, "))", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_470;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:792 t.cont ")==1&&strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_471 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(") >= srtlen(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_471 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_471+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_471+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_471+currStrOff, "strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_471+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_471+currStrOff, ") >= srtlen(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_471+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_471+currStrOff, "))", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_471;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:794 t.cont ")==1&&strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_472 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(check);
long int strLen_2 = strlen("strlen(");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(") <= srtlen(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_472 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_472+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_472+currStrOff, check, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_472+currStrOff, "strlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_472+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_472+currStrOff, ") <= srtlen(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_472+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_472+currStrOff, "))", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_472;
}
}
else {
char * ____BAH_COMPILER_VAR_473 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_473 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_473+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_473+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_473+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_473+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_473+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_473;
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
i =  i + 1;
};
line =  nl;
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
i =  0;
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:815): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if (inArrayStr(t.cont,compSep)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (nl->length <= len(nl)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:820): nl[%d] with length %d\n", len(nl)-1, nl->length);
                            exit(1);
                        };
                        struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (line->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:825): line[%d] with length %d\n", i + 1, line->length);
                            exit(1);
                        };
                        struct Tok nt =  line->data[i + 1];
char * ptt =  getTypeFromToken(&pt,true,elems);
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((__checkString(ptt, "/home/alois/Documents/bah-bah/src/parser.bah:828 ptt ")==1&&strcmp(ptt, "bool") != 0)) {
if ((__checkString(ptt, "/home/alois/Documents/bah-bah/src/parser.bah:829 ptt ")==1&&strcmp(ptt, "int") != 0)) {
throwErr(&pt,"Cannot compare {TOKEN} that is not a bool.");
}
}
if ((__checkString(ntt, "/home/alois/Documents/bah-bah/src/parser.bah:833 ntt ")==1&&strcmp(ntt, "bool") != 0)) {
if ((__checkString(ntt, "/home/alois/Documents/bah-bah/src/parser.bah:834 ntt ")==1&&strcmp(ntt, "int") != 0)) {
throwErr(&nt,"Cannot compare {TOKEN} that is not a bool.");
}
}
char * ____BAH_COMPILER_VAR_474 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_474 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_474+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_474+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_474+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_474+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_474+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_474;
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
i =  i + 1;
};
array(struct Tok)* ____BAH_COMPILER_VAR_475 = nl;
return ____BAH_COMPILER_VAR_475;
};
__BAH_ARR_TYPE_Tok parsePointers(__BAH_ARR_TYPE_Tok l){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
array(char *)* ptrOpers = memoryAlloc(sizeof(array(char *)));

ptrOpers->length = 2;
ptrOpers->elemSize = sizeof(char *);
ptrOpers->data = memoryAlloc(sizeof(char *) * 50);ptrOpers->data[0] = __STR("&");
ptrOpers->data[1] = __STR("*");
long int i =  0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:861): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:864 t.cont ")==1&&strcmp(t.cont, "*") == 0)) {
if ((i>0)) {

                        if (nl->length <= len(nl)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:866): nl[%d] with length %d\n", len(nl)-1, nl->length);
                            exit(1);
                        };
                        struct Tok pt =  nl->data[len(nl)-1];
if ((pt.type==TOKEN_TYPE_VAR)) {
if ((i + 1<len(l))) {

                        if (l->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:869): l[%d] with length %d\n", i + 1, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i + 1];
if ((nt.isValue==false)) {
char * ____BAH_COMPILER_VAR_476 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_476 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_476+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_476+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_476;

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
char * ____BAH_COMPILER_VAR_477 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_477 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_477+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_477+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_477;

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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:888): nl[%d] with length %d\n", len(nl)-1, nl->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:897): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_478 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_478 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nt.cont =  ____BAH_COMPILER_VAR_478;

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
array(struct Tok)* ____BAH_COMPILER_VAR_479 = nl;
return ____BAH_COMPILER_VAR_479;
};
__BAH_ARR_TYPE_Tok parseArrayVars(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
long int i =  0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:923): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:927): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:928 t.cont ")==1&&strcmp(t.cont, "[") == 0)) {
found =  true;
break;
}
}
}
i =  i + 1;
};
if ((found==false)) {
array(struct Tok)* ____BAH_COMPILER_VAR_480 = l;
return ____BAH_COMPILER_VAR_480;
}

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:940): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[0];
i =  0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:943): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
long int ti =  i;
i =  i + 1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:949): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:950 nt.cont ")==1&&strcmp(nt.cont, "[") == 0)) {
struct variable* v =  searchVar(t.cont,elems);
if ((v==null)) {
throwErr(&t,"Unknown array-var {TOKEN}.");
}
if ((strHasPrefix(v->type,"[]")==false)) {
char * ____BAH_COMPILER_VAR_481 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" (");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(") as an array.");
;                            
                        ____BAH_COMPILER_VAR_481 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_481+currStrOff, "Cannot use ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_481+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_481+currStrOff, " (", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_481+currStrOff, v->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_481+currStrOff, ") as an array.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_481);
}
strTrimLeft(&v->type,2);
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i =  i + 1;
long int nbBracks =  1;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:964): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok it =  l->data[i];
if ((__checkString(it.cont, "/home/alois/Documents/bah-bah/src/parser.bah:965 it.cont ")==1&&strcmp(it.cont, "[") == 0)) {
nbBracks =  nbBracks + 1;
}
else if ((__checkString(it.cont, "/home/alois/Documents/bah-bah/src/parser.bah:967 it.cont ")==1&&strcmp(it.cont, "]") == 0)) {
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
i =  i + 1;
};
i =  i + 1;
if ((len(memory)==0)) {
throwErr(&l->data[i],"Expected index not {TOKEN}.");
}
memory =  prePross(memory,(lineType)-1,elems);
char * cont =  "";
long int j =  0;
while ((j<len(memory))) {

                        if (memory->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:985): memory[%d] with length %d\n", j, memory->length);
                            exit(1);
                        };
                        struct Tok mt =  memory->data[j];
char * ____BAH_COMPILER_VAR_482 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mt.cont);
;                            
                        ____BAH_COMPILER_VAR_482 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_482+currStrOff, cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_482+currStrOff, mt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cont =  ____BAH_COMPILER_VAR_482;
j =  j + 1;
};
if (((ti>0)&&(__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:990 ft.cont ")==1&&strcmp(ft.cont, "else") != 0))) {
char * ____BAH_COMPILER_VAR_483 =intToStr(t.line);char * ____BAH_COMPILER_VAR_484 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n                        if (");
long int strLen_1 = strlen(t.cont);
long int strLen_2 = strlen("->length <= ");
long int strLen_3 = strlen(cont);
long int strLen_4 = strlen(") {\n                            printf(\"array (");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_483);
long int strLen_8 = strlen("): ");
long int strLen_9 = strlen(t.cont);
long int strLen_10 = strlen("[%d] with length %d\\n\", ");
long int strLen_11 = strlen(cont);
long int strLen_12 = strlen(", ");
long int strLen_13 = strlen(t.cont);
long int strLen_14 = strlen("->length);\n                            exit(1);\n                        };\n                        ");
;                            
                        ____BAH_COMPILER_VAR_484 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "\n                        if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "->length <= ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, ") {\n                            printf(\"array (", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, compilerState.currentFile, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, ____BAH_COMPILER_VAR_483, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "): ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, t.cont, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "[%d] with length %d\\n\", ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, cont, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, t.cont, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "->length);\n                            exit(1);\n                        };\n                        ", strLen_14);
                        currStrOff += strLen_14;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_484));
}
char * ____BAH_COMPILER_VAR_485 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(cont);
long int strLen_3 = strlen("]");
;                            
                        ____BAH_COMPILER_VAR_485 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_485+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_485+currStrOff, "->data[", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_485+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_485+currStrOff, "]", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_485;
t.bahType =  v->type;

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
i =  i - 1;
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
array(struct Tok)* ____BAH_COMPILER_VAR_486 = nl;
return ____BAH_COMPILER_VAR_486;
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
char * ____BAH_COMPILER_VAR_487 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_488 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__serialize(&");
long int strLen_1 = strlen(e.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen("sizeof(struct ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_487);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_488 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_488+currStrOff, "__serialize(&", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_488+currStrOff, e.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_488+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_488+currStrOff, "sizeof(struct ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_488+currStrOff, ____BAH_COMPILER_VAR_487, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_488+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_488;
}
else {
char * ptrRect =  "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_489 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ptrRect);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_489 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_489+currStrOff, ptrRect, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_489+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ptrRect =  ____BAH_COMPILER_VAR_489;
ptrLevel =  ptrLevel - 1;
};
char * ____BAH_COMPILER_VAR_490 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_491 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__serialize(");
long int strLen_1 = strlen(ptrRect);
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen("sizeof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_490);
long int strLen_6 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_491 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_491+currStrOff, "__serialize(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_491+currStrOff, ptrRect, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_491+currStrOff, e.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_491+currStrOff, ", ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_491+currStrOff, "sizeof(struct ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_491+currStrOff, ____BAH_COMPILER_VAR_490, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_491+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_491;
long int i =  0;
while ((i<len(s->members))) {

                        if (s->members->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1049): s->members[%d] with length %d\n", i, s->members->length);
                            exit(1);
                        };
                        struct structMemb* m =  s->members->data[i];
if ((__checkString(m->type, "/home/alois/Documents/bah-bah/src/parser.bah:1050 m->type ")==1&&strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_492 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("+strlen(");
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen("->");
long int strLen_4 = strlen(m->name);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_492 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_492+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_492+currStrOff, "+strlen(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_492+currStrOff, e.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_492+currStrOff, "->", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_492+currStrOff, m->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_492+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_492;
}
i =  i + 1;
};
}
char * ____BAH_COMPILER_VAR_493 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_493 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_493+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_493+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * ____BAH_COMPILER_VAR_494 = ____BAH_COMPILER_VAR_493;
return ____BAH_COMPILER_VAR_494;
};
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,int parsedPointer,char * ogName,char * offset){
char * isArr =  "0";
char * arrElem =  "0";
if (strHasPrefix(tt,"[]")) {
isArr =  "1";
struct string aet =  string(tt);
aet.trimLeft((struct string*)&aet,2);
struct Tok ____BAH_COMPILER_VAR_495 = {};
____BAH_COMPILER_VAR_495.cont = "";
____BAH_COMPILER_VAR_495.ogCont = "";
____BAH_COMPILER_VAR_495.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_495.pos = 0;
____BAH_COMPILER_VAR_495.line = 1;
____BAH_COMPILER_VAR_495.begLine = 1;
____BAH_COMPILER_VAR_495.bahType = "";
____BAH_COMPILER_VAR_495.isValue = false;
____BAH_COMPILER_VAR_495.isFunc = false;
____BAH_COMPILER_VAR_495.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_495;
tmpT.cont =  "0";
char * ____BAH_COMPILER_VAR_496 =aet.str((struct string*)&aet);struct Tok rt =  parseReflect(tmpT,____BAH_COMPILER_VAR_496,elems,true,"","0");
char * aev =  genCompilerVar();
char * ____BAH_COMPILER_VAR_497 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_1 = strlen(aev);
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rt.cont);
long int strLen_4 = strlen(";\n        ");
;                            
                        ____BAH_COMPILER_VAR_497 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_497+currStrOff, "\n        struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_497+currStrOff, aev, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_497+currStrOff, " = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_497+currStrOff, rt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_497+currStrOff, ";\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_497));
char * ____BAH_COMPILER_VAR_498 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
                        ____BAH_COMPILER_VAR_498 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_498+currStrOff, "&", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_498+currStrOff, aev, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    arrElem =  ____BAH_COMPILER_VAR_498;
}
char * isStruct =  "0";
struct cStruct* ts =  searchStruct(tt,elems);
char * structLayout =  "0";
if ((ts!=null)) {
isStruct =  "1";
structLayout =  genCompilerVar();
struct variable* slv = memoryAlloc(sizeof(struct variable));
slv->name = "";
slv->type = "";
slv->isConst = false;
slv->constVal = "";
slv->isArray = false;
slv->from = "";
slv->outterScope = false;
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
while ((i<len(ts->members))) {

                        if (ts->members->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1101): ts->members[%d] with length %d\n", i, ts->members->length);
                            exit(1);
                        };
                        struct structMemb* m =  ts->members->data[i];
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
struct Tok tmpT =  ____BAH_COMPILER_VAR_499;
char * sep =  "->";
if ((strCount(tt,"*")==0)) {
sep =  ".";
}
struct string mCtype =  getCType(m->type,elems);
struct string offsetTT =  string(tt);
offsetTT.replace((struct string*)&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_500 =mCtype.str((struct string*)&mCtype);char * ____BAH_COMPILER_VAR_501 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_502 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_500);
long int strLen_2 = strlen("*)((char*)(");
long int strLen_3 = strlen(t.cont);
long int strLen_4 = strlen(") + offsetof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_501);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_502 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, ____BAH_COMPILER_VAR_500, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, "*)((char*)(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, t.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, ") + offsetof(struct ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, ____BAH_COMPILER_VAR_501, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, m->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, "))", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    tmpT.cont =  ____BAH_COMPILER_VAR_502;
char * ____BAH_COMPILER_VAR_503 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_504 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("offsetof(struct ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_503);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_504 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, "offsetof(struct ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, ____BAH_COMPILER_VAR_503, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    struct Tok rt =  parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_504);
char * ____BAH_COMPILER_VAR_505 =intToStr(i);char * ____BAH_COMPILER_VAR_506 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(structLayout);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_505);
long int strLen_3 = strlen("] = ");
long int strLen_4 = strlen(rt.cont);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_506 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_506+currStrOff, structLayout, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_506+currStrOff, "->data[", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_506+currStrOff, ____BAH_COMPILER_VAR_505, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_506+currStrOff, "] = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_506+currStrOff, rt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_506+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    dataLayout =  dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_506));
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_507 =intToStr(len(ts->members));char * ____BAH_COMPILER_VAR_508 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n        array(struct reflectElement) * ");
long int strLen_1 = strlen(structLayout);
long int strLen_2 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_5 = strlen(structLayout);
long int strLen_6 = strlen("->length = ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_507);
long int strLen_8 = strlen(";\n        ");
long int strLen_9 = strlen(structLayout);
long int strLen_10 = strlen("->data = memoryAlloc(");
long int strLen_11 = strlen(structLayout);
long int strLen_12 = strlen("->length * ");
long int strLen_13 = strlen(structLayout);
long int strLen_14 = strlen("->elemSize);\n        ");
;                            
                        ____BAH_COMPILER_VAR_508 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, "\n        array(struct reflectElement) * ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, structLayout, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, structLayout, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, structLayout, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, "->length = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, ____BAH_COMPILER_VAR_507, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, ";\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, structLayout, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, "->data = memoryAlloc(", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, structLayout, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, "->length * ", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, structLayout, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_508+currStrOff, "->elemSize);\n        ", strLen_14);
                        currStrOff += strLen_14;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_508))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_508)), dataLayout);
}
char * amp =  "";
if (((((strCount(tt,"*")==0)&&(__checkString(tt, "/home/alois/Documents/bah-bah/src/parser.bah:1125 tt ")==1&&strcmp(tt, "cpstring") != 0))&&(__checkString(tt, "/home/alois/Documents/bah-bah/src/parser.bah:1125 tt ")==1&&strcmp(tt, "ptr") != 0))&&(parsedPointer==false))) {
amp =  "&";
}
struct string name =  string(ogName);
if ((hasStructSep(name)==true)) {
name =  splitStructSepAfter(name);
}
struct string cType =  getCType(tt,elems);
if (cType.hasPrefix((struct string*)&cType,"struct ")) {
cType.replace((struct string*)&cType,"*","");
}
if ((cType.length==0)) {
cType.set((struct string*)&cType,"0");
}
struct variable* rv = memoryAlloc(sizeof(struct variable));
rv->name = "";
rv->type = "";
rv->isConst = false;
rv->constVal = "";
rv->isArray = false;
rv->from = "";
rv->outterScope = false;
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
char * ____BAH_COMPILER_VAR_509 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_510 =name.str((struct string*)&name);char * ____BAH_COMPILER_VAR_511 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("struct reflectElement ");
long int strLen_1 = strlen(rv->name);
long int strLen_2 = strlen(" = __reflect(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(", sizeof(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_509);
long int strLen_7 = strlen("), \"");
long int strLen_8 = strlen(tt);
long int strLen_9 = strlen("\", \"");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_510);
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
                        ____BAH_COMPILER_VAR_511 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20 + strLen_21);
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, "struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, rv->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, " = __reflect(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, ", sizeof(", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, ____BAH_COMPILER_VAR_509, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, "), \"", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, tt, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, "\", \"", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, ____BAH_COMPILER_VAR_510, strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, "\", ", strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, isArr, strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, ", ", strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, arrElem, strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, ", ", strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, isStruct, strLen_16);
                        currStrOff += strLen_16;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, ", ", strLen_17);
                        currStrOff += strLen_17;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, structLayout, strLen_18);
                        currStrOff += strLen_18;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, ", ", strLen_19);
                        currStrOff += strLen_19;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, offset, strLen_20);
                        currStrOff += strLen_20;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, ");\n", strLen_21);
                        currStrOff += strLen_21;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_511));
t.cont =  rv->name;
struct Tok ____BAH_COMPILER_VAR_512 = t;
return ____BAH_COMPILER_VAR_512;
};
__BAH_ARR_TYPE_Tok parseFnCall(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
long int i =  0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1163): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1167): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1168 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
found =  true;
break;
}
}
}
i =  i + 1;
};
if ((found==false)) {
array(struct Tok)* ____BAH_COMPILER_VAR_513 = l;
return ____BAH_COMPILER_VAR_513;
}
i =  0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1182): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok ot =  l->data[i];
if ((ot.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1187): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1188 nt.cont ")==1&&strcmp(nt.cont, "(") == 0)) {
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1200): fn->args[%d] with length %d\n", 0, fn->args->length);
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
char * ____BAH_COMPILER_VAR_514 =fnarg1t.str((struct string*)&fnarg1t);char * ____BAH_COMPILER_VAR_515 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_514);
long int strLen_2 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_515 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, ____BAH_COMPILER_VAR_514, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    varName.prepend((struct string*)&varName,____BAH_COMPILER_VAR_515);
}
char * ____BAH_COMPILER_VAR_516 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                        ____BAH_COMPILER_VAR_516 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_516+currStrOff, fnName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_516+currStrOff, "(", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_516;
array(struct variable*)* fnArgs =  fn->args;
long int paramIndex =  0;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
if ((varName.length>0)) {
struct Tok ____BAH_COMPILER_VAR_517 = {};
____BAH_COMPILER_VAR_517.cont = "";
____BAH_COMPILER_VAR_517.ogCont = "";
____BAH_COMPILER_VAR_517.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_517.pos = 0;
____BAH_COMPILER_VAR_517.line = 1;
____BAH_COMPILER_VAR_517.begLine = 1;
____BAH_COMPILER_VAR_517.bahType = "";
____BAH_COMPILER_VAR_517.isValue = false;
____BAH_COMPILER_VAR_517.isFunc = false;
____BAH_COMPILER_VAR_517.isOper = false;
struct Tok tk =  ____BAH_COMPILER_VAR_517;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1234): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        nt =  l->data[i];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1235 nt.cont ")==1&&strcmp(nt.cont, ")") != 0)) {
struct Tok ____BAH_COMPILER_VAR_518 = {};
____BAH_COMPILER_VAR_518.cont = "";
____BAH_COMPILER_VAR_518.ogCont = "";
____BAH_COMPILER_VAR_518.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_518.pos = 0;
____BAH_COMPILER_VAR_518.line = 1;
____BAH_COMPILER_VAR_518.begLine = 1;
____BAH_COMPILER_VAR_518.bahType = "";
____BAH_COMPILER_VAR_518.isValue = false;
____BAH_COMPILER_VAR_518.isFunc = false;
____BAH_COMPILER_VAR_518.isOper = false;
tk =  ____BAH_COMPILER_VAR_518;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1244): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1245 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
nbPar =  nbPar + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1247 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
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
if ((__checkString(fnName, "/home/alois/Documents/bah-bah/src/parser.bah:1258 fnName ")==1&&strcmp(fnName, "noCheck") == 0)) {
long int j =  0;
while ((j<len(memory))) {

                        if (memory->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1260): memory[%d] with length %d\n", j, memory->length);
                            exit(1);
                        };
                        struct Tok t =  memory->data[j];
char * ____BAH_COMPILER_VAR_519 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_519 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_519+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_519+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_519+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_519;
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
memory =  prePross(memory,(lineType)-1,elems);

                        if (memory->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1274): memory[%d] with length %d\n", 0, memory->length);
                            exit(1);
                        };
                        struct Tok ft =  memory->data[0];
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1275 ft.cont ")==1&&strcmp(ft.cont, ")") != 0)) {
long int j =  0;
while ((j<len(memory))) {

                        if (memory->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1278): memory[%d] with length %d\n", j, memory->length);
                            exit(1);
                        };
                        struct Tok t =  memory->data[j];
if ((paramIndex>=len(fnArgs))) {
throwErr(&t,"Too many arguments in function call.");
}

                        if (fnArgs->length <= paramIndex) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1283): fnArgs[%d] with length %d\n", paramIndex, fnArgs->length);
                            exit(1);
                        };
                        struct variable* arg =  fnArgs->data[paramIndex];
char * tt =  getTypeFromToken(&t,true,elems);
if (((__checkString(arg->type, "/home/alois/Documents/bah-bah/src/parser.bah:1286 arg->type ")==1&&strcmp(arg->type, "reflectElement") == 0)&&(__checkString(tt, "/home/alois/Documents/bah-bah/src/parser.bah:1286 tt ")==1&&strcmp(tt, "reflectElement") != 0))) {
t =  parseReflect(t,tt,elems,false,t.cont,"0");
tt =  "reflectElement";
}
if ((compTypes(tt,arg->type)==false)) {
char * ____BAH_COMPILER_VAR_520 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(arg->type);
long int strLen_4 = strlen(" in function call.");
;                            
                        ____BAH_COMPILER_VAR_520 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, arg->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, " in function call.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_520);
}
if (((t.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(t.cont,"noCheck(")==false))) {
struct string ____BAH_COMPILER_VAR_521 =string(t.cont);char * afnName =  splitStringBefore(____BAH_COMPILER_VAR_521,"(");
struct func* afn =  searchFunc(afnName,elems,true);
if (((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true))) {
t.cont =  registerRCPvar(afn->returns->type,t.cont,elems);
}
}
char * ____BAH_COMPILER_VAR_522 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_522 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_522;
j =  j + 1;

                        if (memory->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1305): memory[%d] with length %d\n", j, memory->length);
                            exit(1);
                        };
                        t =  memory->data[j];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1306 t.cont ")==1&&strcmp(t.cont, ",") != 0)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1307 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
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
char * ____BAH_COMPILER_VAR_523 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_523 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_523+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_523+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_523;
}
j =  j + 1;
};
}
if ((paramIndex<len(fnArgs))) {
ot.cont =  fnName;
throwErr(&ot,"Not enough arguments in function call, ending by {TOKEN}.");
}
if ((__checkString(fn->name, "/home/alois/Documents/bah-bah/src/parser.bah:1328 fn->name ")==1&&strcmp(fn->name, "ser") == 0)) {
ot.cont =  parseSerialize(memory->data[0],elems);
}
else {
char * ____BAH_COMPILER_VAR_524 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_524 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_524;
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
continue;
}
}
i =  i - 1;
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
i =  i + 1;
};
array(struct Tok)* ____BAH_COMPILER_VAR_525 = nl;
return ____BAH_COMPILER_VAR_525;
};
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1355): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[0];
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1360): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        ft =  l->data[0];
int parsed =  true;
char * ____BAH_COMPILER_VAR_526 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_526 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_526+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_526+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_526));
return;
}
l =  parseStructType(l,elems);
int isEqual =  false;
int toVar =  false;
int isPointedVar =  false;
int isStruct =  false;
char * currentType =  "";

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1371): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        ft =  l->data[0];
struct variable* v =  searchVar(ft.cont,elems);
int exists =  true;
char * ogName= null;
if ((v==null)) {
exists =  false;
v = memoryAlloc(sizeof(struct variable));
v->name = "";
v->type = "";
v->isConst = false;
v->constVal = "";
v->isArray = false;
v->from = "";
v->outterScope = false;
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
long int arrayLength =  0;
if (((exists==true)&&isGlobal())) {
throwErr(&ft,"Cannot redeclare global variable {TOKEN}.");
}
if ((len(l)==2)) {

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1394): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok lt =  l->data[1];
if ((((lt.type==TOKEN_TYPE_SYNTAX)&&(__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1395 lt.cont ")==1&&strcmp(lt.cont, "++") == 0))||(__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1395 lt.cont ")==1&&strcmp(lt.cont, "--") == 0))) {
if ((exists==false)) {
char * ____BAH_COMPILER_VAR_528 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use '");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen("' on non declared {TOKEN} variable.");
;                            
                        ____BAH_COMPILER_VAR_528 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_528+currStrOff, "Cannot use '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_528+currStrOff, lt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_528+currStrOff, "' on non declared {TOKEN} variable.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&ft,____BAH_COMPILER_VAR_528);
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1400): l[%d] with length %d\n", 0, l->length);
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
struct Tok ____BAH_COMPILER_VAR_529 = {};
____BAH_COMPILER_VAR_529.cont = "";
____BAH_COMPILER_VAR_529.ogCont = "";
____BAH_COMPILER_VAR_529.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_529.pos = 0;
____BAH_COMPILER_VAR_529.line = 1;
____BAH_COMPILER_VAR_529.begLine = 1;
____BAH_COMPILER_VAR_529.bahType = "";
____BAH_COMPILER_VAR_529.isValue = false;
____BAH_COMPILER_VAR_529.isFunc = false;
____BAH_COMPILER_VAR_529.isOper = false;
____BAH_COMPILER_VAR_529.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_529.cont = "=";
____BAH_COMPILER_VAR_529.isValue = false;

{
long nLength = 1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[1] =  ____BAH_COMPILER_VAR_529;
nl->length = nLength+1;
} else {
nl->data[1] =  ____BAH_COMPILER_VAR_529;
}
};
char * c =  "";
if ((__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1409 lt.cont ")==1&&strcmp(lt.cont, "++") == 0)) {
char * ____BAH_COMPILER_VAR_530 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("+1");
;                            
                        ____BAH_COMPILER_VAR_530 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_530+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_530+currStrOff, "+1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    c =  ____BAH_COMPILER_VAR_530;
}
else if ((__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1411 lt.cont ")==1&&strcmp(lt.cont, "--") == 0)) {
char * ____BAH_COMPILER_VAR_531 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("-1");
;                            
                        ____BAH_COMPILER_VAR_531 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_531+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_531+currStrOff, "-1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    c =  ____BAH_COMPILER_VAR_531;
}
long int ltl =  lt.line;
long int ltp =  lt.pos;
char * ltc =  lt.cont;
struct Tok ____BAH_COMPILER_VAR_532 = {};
____BAH_COMPILER_VAR_532.cont = "";
____BAH_COMPILER_VAR_532.ogCont = "";
____BAH_COMPILER_VAR_532.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_532.pos = 0;
____BAH_COMPILER_VAR_532.line = 1;
____BAH_COMPILER_VAR_532.begLine = 1;
____BAH_COMPILER_VAR_532.bahType = "";
____BAH_COMPILER_VAR_532.isValue = false;
____BAH_COMPILER_VAR_532.isFunc = false;
____BAH_COMPILER_VAR_532.isOper = false;
____BAH_COMPILER_VAR_532.type = TOKEN_TYPE_INT;
____BAH_COMPILER_VAR_532.cont = c;
____BAH_COMPILER_VAR_532.line = ltl;
____BAH_COMPILER_VAR_532.ogCont = ltc;
____BAH_COMPILER_VAR_532.pos = ltp;
____BAH_COMPILER_VAR_532.isOper = true;
____BAH_COMPILER_VAR_532.isValue = true;

{
long nLength = 2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[2] =  ____BAH_COMPILER_VAR_532;
nl->length = nLength+1;
} else {
nl->data[2] =  ____BAH_COMPILER_VAR_532;
}
};
l =  nl;
}
}
long int i =  1;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1433): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1435 t.cont ")==1&&strcmp(t.cont, "=") == 0)) {
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
char * ____BAH_COMPILER_VAR_533 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(currentType);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_533 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, currentType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    currentType =  ____BAH_COMPILER_VAR_533;
}
else {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1449 t.cont ")==1&&strcmp(t.cont, "new") == 0)) {
isStruct =  true;
long int max =  i + 1;
if ((max>=len(l))) {
throwErr(&t,"Cannot initiate {TOKEN} struct without specifying struct name.");
}
max =  max + 1;
if ((max<len(l))) {

                        if (l->length <= i + 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1457): l[%d] with length %d\n", i + 2, l->length);
                            exit(1);
                        };
                        t =  l->data[i + 2];
throwErr(&t,"{TOKEN} not expected after initiating new struct.");
}

                        if (l->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1460): l[%d] with length %d\n", i + 1, l->length);
                            exit(1);
                        };
                        t =  l->data[i + 1];
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as a struct name.");
}
struct cStruct* s =  searchStruct(t.cont,elems);
if ((s==null)) {
throwErr(&t,"Unknown struct {TOKEN}.");
}
struct string vect =  getCType(s->name,elems);
char * vectStr =  vect.content;
char * ____BAH_COMPILER_VAR_534 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("memoryAlloc(sizeof(");
long int strLen_1 = strlen(vectStr);
long int strLen_2 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_534 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_534+currStrOff, "memoryAlloc(sizeof(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_534+currStrOff, vectStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_534+currStrOff, "))", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_534;
char * ____BAH_COMPILER_VAR_535 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_535 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_535+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_535+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    v->type =  ____BAH_COMPILER_VAR_535;
NEXT_LINE =  declareStructMethods(v,s,elems);
break;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1474 t.cont ")==1&&strcmp(t.cont, "chan") == 0)) {
if ((i>=len(l))) {
throwErr(&t,"Cannot declare a {TOKEN} without a type (chan <type>).");
}
i =  i+1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1479): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i];
char * ____BAH_COMPILER_VAR_536 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("chan:");
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_536 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, "chan:", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    v->type =  ____BAH_COMPILER_VAR_536;
code =  "channel()";
if ((i + 1!=len(l))) {

                        if (l->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1483): l[%d] with length %d\n", i + 1, l->length);
                            exit(1);
                        };
                        struct Tok errT =  l->data[i + 1];
throwErr(&errT,"{TOKEN} not expected after channel declaration.");
}
break;
}
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value in var declaration.");
}
char * tp =  getTypeFromToken(&t,true,elems);
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_537 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_537 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, tp, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, v->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_537);
}
}
else {
if ((strlen(currentType)==0)) {
if ((strlen(v->type)==0)) {
v->type =  tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_538 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_538 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, tp, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, v->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_538);
}
}
}
}
if (((strlen(t.cont)>0)&&(strHasPrefix(t.cont,"{")==false))) {
char * ____BAH_COMPILER_VAR_539 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_539 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_539+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_539+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_539+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_539;
if (((t.isOper==false)&&(RCPavailable()==true))) {
struct variable* iv =  searchVar(t.cont,elems);
if (((iv!=null)&&(iv->isConst==false))) {
toVar =  true;
isPointedVar =  strHasPrefix(t.cont,"&");
struct cStruct* s =  searchStruct(iv->type,elems);
if ((((s!=null)&&(strCount(iv->type,"*")==0))&&(s->isBinding==false))) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_540 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incrCounter(");
long int strLen_2 = strlen(iv->name);
long int strLen_3 = strlen(".__RCP_counter)");
;                            
                        ____BAH_COMPILER_VAR_540 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, "; RCP_incrCounter(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, iv->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, ".__RCP_counter)", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_540;
}
else {
struct string ivn =  string(iv->name);
ivn.replace((struct string*)&ivn,"*","");
char * ____BAH_COMPILER_VAR_541 =ivn.str((struct string*)&ivn);char * ____BAH_COMPILER_VAR_542 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incr(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_541);
long int strLen_3 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_542 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, "; RCP_incr(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, ____BAH_COMPILER_VAR_541, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, ")", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_542;
}
}
}
}
break;
}
if (strHasPrefix(v->type,"[]")) {
struct string arrType =  getCType(v->type,elems);
arrType.trimRight((struct string*)&arrType,1);
char * ____BAH_COMPILER_VAR_543 =arrType.str((struct string*)&arrType);char * ____BAH_COMPILER_VAR_544 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("memoryAlloc(sizeof(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_543);
long int strLen_2 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_544 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_544+currStrOff, "memoryAlloc(sizeof(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_544+currStrOff, ____BAH_COMPILER_VAR_543, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_544+currStrOff, "))", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_544;
arrType.trimLeft((struct string*)&arrType,6);
arrType.trimRight((struct string*)&arrType,1);
char * elemTypeStr =  arrType.str((struct string*)&arrType);
long int max =  i + 1;
if ((max!=len(l))) {
i =  i + 1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1542): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1543 nt.cont ")==1&&strcmp(nt.cont, "{") != 0)) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after array initialization.");
}
struct string elemBahType =  string(v->type);
elemBahType.trimLeft((struct string*)&elemBahType,2);
char * elemBahTypeStr =  elemBahType.str((struct string*)&elemBahType);
i =  i + 1;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1552): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1557): memory[%d] with length %d\n", i, memory->length);
                            exit(1);
                        };
                        t =  memory->data[i];
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_545 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(elemBahTypeStr);
;                            
                        ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, elemBahTypeStr, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_545);
}
char * strArrayLength =  intToStr(arrayLength);
arrayLength =  arrayLength + 1;
if ((__checkString(tt, "/home/alois/Documents/bah-bah/src/parser.bah:1566 tt ")==1&&strcmp(tt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_546 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__STR(");
long int strLen_1 = strlen(t.cont);
long int strLen_2 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_546 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_546+currStrOff, "__STR(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_546+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_546+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_546;
}
char * ____BAH_COMPILER_VAR_547 =null;
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
                        ____BAH_COMPILER_VAR_547 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, NEXT_LINE, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, "->data[", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, strArrayLength, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, "] = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, t.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    NEXT_LINE =  ____BAH_COMPILER_VAR_547;
i =  i + 1;

                        if (memory->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1572): memory[%d] with length %d\n", i, memory->length);
                            exit(1);
                        };
                        t =  memory->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1573 t.cont ")==1&&strcmp(t.cont, ",") != 0)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1574 t.cont ")==1&&strcmp(t.cont, "}") == 0)) {
long int allocLength =  arrayLength;
if ((allocLength>50)) {
long int modAllocAmm =  allocLength % 50;
allocLength =  allocLength + modAllocAmm;
}
else {
allocLength =  50;
}
char * allocLengthStr =  intToStr(allocLength);
char * ____BAH_COMPILER_VAR_548 =null;
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
                        ____BAH_COMPILER_VAR_548 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_548+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_548+currStrOff, "->data = memoryAlloc(sizeof(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_548+currStrOff, elemTypeStr, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_548+currStrOff, ") * ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_548+currStrOff, allocLengthStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_548+currStrOff, ");", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_548+currStrOff, NEXT_LINE, strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    NEXT_LINE =  ____BAH_COMPILER_VAR_548;
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
char * ____BAH_COMPILER_VAR_549 =null;
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
                        ____BAH_COMPILER_VAR_549 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, "\n", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, "->length = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, strArrayLength, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, v->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, "->elemSize = sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, elemTypeStr, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, ");\n", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, NEXT_LINE, strLen_9);
                        currStrOff += strLen_9;
                        
                    }
                    NEXT_LINE =  ____BAH_COMPILER_VAR_549;
break;
}
isStruct =  true;
long int max =  i + 1;
if ((max!=len(l))) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after struct initialization.");
}
char * ____BAH_COMPILER_VAR_550 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_550 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_550+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_550+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_550+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_550;
}
i =  i + 1;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1619): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok st =  l->data[1];
char * ____BAH_COMPILER_VAR_551 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot change the type of already declared var '");
long int strLen_1 = strlen(ft.cont);
long int strLen_2 = strlen("' to {TOKEN}.");
;                            
                        ____BAH_COMPILER_VAR_551 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_551+currStrOff, "Cannot change the type of already declared var '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_551+currStrOff, ft.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_551+currStrOff, "' to {TOKEN}.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&st,____BAH_COMPILER_VAR_551);
}
if ((isStruct==false)) {
if (((isRCPpointerType(v->type)&&(isPointedVar==false))&&(RCPavailable()==true))) {
struct string cType =  getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_552 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_553 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_554 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_552);
long int strLen_2 = strlen("*)RCP_decrIL(&");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(") = *(");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_553);
long int strLen_6 = strlen("*)RCP_incrIL(&");
long int strLen_7 = strlen(code);
long int strLen_8 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_554 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, "*(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, ____BAH_COMPILER_VAR_552, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, "*)RCP_decrIL(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, ") = *(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, ____BAH_COMPILER_VAR_553, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, "*)RCP_incrIL(&", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, code, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_554+currStrOff, ")", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_554;
}
else {
struct variable* tmpV = memoryAlloc(sizeof(struct variable));
tmpV->name = "";
tmpV->type = "";
tmpV->isConst = false;
tmpV->constVal = "";
tmpV->isArray = false;
tmpV->from = "";
tmpV->outterScope = false;
tmpV->name =  genCompilerVar();
tmpV->type =  v->type;
struct rope* dv =  decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_555 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_556 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_557 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_558 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_555);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = *(");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_556);
long int strLen_9 = strlen("*)RCP_incrIL(&");
long int strLen_10 = strlen(code);
long int strLen_11 = strlen(");");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_557);
;                            
                        ____BAH_COMPILER_VAR_558 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, ____BAH_COMPILER_VAR_555, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, tmpV->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, "; ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, " = *(", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, ____BAH_COMPILER_VAR_556, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, "*)RCP_incrIL(&", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, code, strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, ");", strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_558+currStrOff, ____BAH_COMPILER_VAR_557, strLen_12);
                        currStrOff += strLen_12;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_558;
}
}
else {
struct variable* tmpV = memoryAlloc(sizeof(struct variable));
tmpV->name = "";
tmpV->type = "";
tmpV->isConst = false;
tmpV->constVal = "";
tmpV->isArray = false;
tmpV->from = "";
tmpV->outterScope = false;
tmpV->name =  genCompilerVar();
tmpV->type =  v->type;
struct rope* dv =  decrVar(tmpV,elems);
char * ____BAH_COMPILER_VAR_559 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_560 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_561 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_559);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = ");
long int strLen_8 = strlen(code);
long int strLen_9 = strlen(";");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_560);
;                            
                        ____BAH_COMPILER_VAR_561 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10);
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, ____BAH_COMPILER_VAR_559, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, tmpV->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, "; ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, " = ", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, code, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, ";", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_561+currStrOff, ____BAH_COMPILER_VAR_560, strLen_10);
                        currStrOff += strLen_10;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_561;
}
}
else {
struct cStruct* s =  searchStruct(v->type,elems);
if ((((((s!=null)&&(RCPavailable()==true))&&(RCPselfRef(v)==false))&&(s->isBinding==false))&&(strCount(v->name,"*")==0))) {
char * ____BAH_COMPILER_VAR_562 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_decrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter); ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_562 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, "RCP_decrCounter(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, ".__RCP_counter); ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, code, strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_562;
}
else {
char * ____BAH_COMPILER_VAR_563 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_563 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_563+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_563+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_563+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_563;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_564 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_564 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_564+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_564+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_564+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_564;
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
i =  i + 1;
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
i =  i - 1;
};
long int tamm =  n.length - i;
n.trimRight((struct string*)&n,tamm + 6);
char * nstr =  n.str((struct string*)&n);
struct string elemType =  getCType(v->type,elems);
char * elemTypeStr =  elemType.str((struct string*)&elemType);
char * ____BAH_COMPILER_VAR_565 =null;
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
                        ____BAH_COMPILER_VAR_565 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, "\n{\nlong nLength = ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, nLengthStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, ";\nif (", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, nstr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, nstr, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, "->data, (nLength+50)*sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, elemTypeStr, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, "));\n", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, nstr, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, "->data = newPtr;\n}\n", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, code, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, ";\n", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, nstr, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, "->length = nLength+1;\n} else {\n", strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, code, strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, ";\n}\n}", strLen_16);
                        currStrOff += strLen_16;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_565;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1718): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                            exit(1);
                        };
                        struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_566 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_567 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_566);
;                            
                        ____BAH_COMPILER_VAR_567 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_567+currStrOff, ____BAH_COMPILER_VAR_566, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_567;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_568 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_568;
}
};
char * ____BAH_COMPILER_VAR_569 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_570 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_569);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_570 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, ____BAH_COMPILER_VAR_569, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    vct =  ____BAH_COMPILER_VAR_570;
}
else {
vct =  setCType(v,elems);
}
if ((strlen(code)>0)) {
if ((((isRCPpointerType(v->type)&&(RCPavailable()==true))&&(toVar==true))&&(isPointedVar==false))) {
struct string cType =  getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_571 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_572 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_571);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_572 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, " = *(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, ____BAH_COMPILER_VAR_571, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, "*)RCP_incrIL(&", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, code, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_572));
}
else {
char * ____BAH_COMPILER_VAR_573 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_574 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_573);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_574 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, " = *(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, ____BAH_COMPILER_VAR_573, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, "*)RCP_incrIL(&", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, code, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_574;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_575 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
long int strLen_3 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_575 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_575+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_575+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_575+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_575+currStrOff, ";\n", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_575));
}
else {
char * ____BAH_COMPILER_VAR_576 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_576 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_576+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_576+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_576+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_576;
}
}
}
else {
if (isRCPpointerType(v->type)) {
char * ____BAH_COMPILER_VAR_577 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen("= null");
;                            
                        ____BAH_COMPILER_VAR_577 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_577+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_577+currStrOff, "= null", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_577;
}
else {
code =  vct;
}
}
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
struct reflectElement ____BAH_COMPILER_VAR_579 = __reflect((char **)((char*)(v) + offsetof(struct variable, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_580 = __reflect((char **)((char*)(v) + offsetof(struct variable, type)), sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_581 = __reflect((int*)((char*)(v) + offsetof(struct variable, isConst)), sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_582 = __reflect((char **)((char*)(v) + offsetof(struct variable, constVal)), sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_583 = __reflect((int*)((char*)(v) + offsetof(struct variable, isArray)), sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_584 = __reflect((char **)((char*)(v) + offsetof(struct variable, from)), sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_585 = __reflect((int*)((char*)(v) + offsetof(struct variable, outterScope)), sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_578 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_578->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_578->length = 7;
        ____BAH_COMPILER_VAR_578->data = memoryAlloc(____BAH_COMPILER_VAR_578->length * ____BAH_COMPILER_VAR_578->elemSize);
        ____BAH_COMPILER_VAR_578->data[0] = ____BAH_COMPILER_VAR_579;
____BAH_COMPILER_VAR_578->data[1] = ____BAH_COMPILER_VAR_580;
____BAH_COMPILER_VAR_578->data[2] = ____BAH_COMPILER_VAR_581;
____BAH_COMPILER_VAR_578->data[3] = ____BAH_COMPILER_VAR_582;
____BAH_COMPILER_VAR_578->data[4] = ____BAH_COMPILER_VAR_583;
____BAH_COMPILER_VAR_578->data[5] = ____BAH_COMPILER_VAR_584;
____BAH_COMPILER_VAR_578->data[6] = ____BAH_COMPILER_VAR_585;
struct reflectElement ____BAH_COMPILER_VAR_586 = __reflect(v, sizeof(struct variable), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_578, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_586);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_587 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_587 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_587+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_587+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_587));
}
}
if (isGlobal()) {
INIT =  INIT->add(INIT, rope(NEXT_LINE));
NEXT_LINE =  "";
}
else {
char * ____BAH_COMPILER_VAR_588 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_588 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_588+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_588+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_588));
}
};
char * getCfunctionType(struct string cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn =  parseFnType(cfrt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {

                        if (tmpfn->args->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1780): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                            exit(1);
                        };
                        struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_589 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_590 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_589);
;                            
                        ____BAH_COMPILER_VAR_590 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_590+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_590+currStrOff, ____BAH_COMPILER_VAR_589, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_590;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_591 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_591 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_591+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_591+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_591;
}
};
char * ____BAH_COMPILER_VAR_592 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_593 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_592);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(elemName);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_593 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, ____BAH_COMPILER_VAR_592, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, elemName, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_593+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    char * ____BAH_COMPILER_VAR_594 = ____BAH_COMPILER_VAR_593;
return ____BAH_COMPILER_VAR_594;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
long int j =  *i;

                        if (l->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1796): l[%d] with length %d\n", j, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[j];
char * tpdf =  "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_595 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(prev);
long int strLen_1 = strlen(ft.cont);
;                            
                        ____BAH_COMPILER_VAR_595 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_595+currStrOff, prev, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_595+currStrOff, ft.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fn->name =  ____BAH_COMPILER_VAR_595;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_596 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
                        ____BAH_COMPILER_VAR_596 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_596+currStrOff, fn->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_596+currStrOff, "(", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * code =  ____BAH_COMPILER_VAR_596;
j =  j + 2;

                        if (l->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1810): l[%d] with length %d\n", j, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[j];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1811 t.cont ")==1&&strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {

                        if (l->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1814): l[%d] with length %d\n", j, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1824): l[%d] with length %d\n", j, l->length);
                            exit(1);
                        };
                        t =  l->data[j];
char * argType =  t.cont;
j =  j + 1;
int isComa =  false;
long int nbPars =  1;
while ((j<len(l))) {

                        if (l->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1831): l[%d] with length %d\n", j, l->length);
                            exit(1);
                        };
                        t =  l->data[j];
isComa =  false;
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1833 t.cont ")==1&&strcmp(t.cont, ",") != 0)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1834 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
nbPars =  nbPars + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1836 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
nbPars =  nbPars - 1;
}
if (((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1839 t.cont ")==1&&strcmp(t.cont, ")") == 0)&&(nbPars==0))) {
break;
}
else {
char * ____BAH_COMPILER_VAR_597 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(argType);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_597 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_597+currStrOff, argType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_597+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    argType =  ____BAH_COMPILER_VAR_597;
}
}
else {
isComa =  true;
break;
}
j =  j + 1;
};
struct variable* argument = memoryAlloc(sizeof(struct variable));
argument->name = "";
argument->type = "";
argument->isConst = false;
argument->constVal = "";
argument->isArray = false;
argument->from = "";
argument->outterScope = false;
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
char * ____BAH_COMPILER_VAR_598 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_599 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_598);
;                            
                        ____BAH_COMPILER_VAR_599 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_599+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_599+currStrOff, ____BAH_COMPILER_VAR_598, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    newArgType =  ____BAH_COMPILER_VAR_599;
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
char * ____BAH_COMPILER_VAR_600 =argCType.str((struct string*)&argCType);char * ____BAH_COMPILER_VAR_601 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_600);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newArgType);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_601 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, tpdf, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, "typedef ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, ____BAH_COMPILER_VAR_600, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, " ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, newArgType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    tpdf =  ____BAH_COMPILER_VAR_601;
}
}
if ((cfrt.hasPrefix((struct string*)&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_602 =getCfunctionType(cfrt,argName,elems);char * ____BAH_COMPILER_VAR_603 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_602);
;                            
                        ____BAH_COMPILER_VAR_603 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_603+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_603+currStrOff, ____BAH_COMPILER_VAR_602, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_603;
}
else {
char * ____BAH_COMPILER_VAR_604 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(newArgType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(argName);
;                            
                        ____BAH_COMPILER_VAR_604 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_604+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_604+currStrOff, newArgType, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_604+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_604+currStrOff, argName, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_604;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_605 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_605 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_605+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_605+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_605;
}
else {
char * ____BAH_COMPILER_VAR_606 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_606 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_606+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_606;
break;
}
j =  j + 1;
};
}
else {
char * ____BAH_COMPILER_VAR_607 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_607 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_607+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_607+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_607;
}
j =  j + 1;
struct variable* returns = memoryAlloc(sizeof(struct variable));
returns->name = "";
returns->type = "";
returns->isConst = false;
returns->constVal = "";
returns->isArray = false;
returns->from = "";
returns->outterScope = false;
returns->type =  "";
while ((j<len(l))) {

                        if (l->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1896): l[%d] with length %d\n", j, l->length);
                            exit(1);
                        };
                        t =  l->data[j];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1897 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_608 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(returns->type);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_608 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, returns->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    returns->type =  ____BAH_COMPILER_VAR_608;
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
char * ____BAH_COMPILER_VAR_609 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_610 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_609);
;                            
                        ____BAH_COMPILER_VAR_610 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_610+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_610+currStrOff, ____BAH_COMPILER_VAR_609, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    newFnRetType =  ____BAH_COMPILER_VAR_610;
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
char * ____BAH_COMPILER_VAR_611 =fnRetType.str((struct string*)&fnRetType);char * ____BAH_COMPILER_VAR_612 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_611);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newFnRetType);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_612 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, tpdf, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, "typedef ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, ____BAH_COMPILER_VAR_611, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, " ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, newFnRetType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_612+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    tpdf =  ____BAH_COMPILER_VAR_612;
}
}
char * ____BAH_COMPILER_VAR_613 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen(newFnRetType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_613 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_613+currStrOff, tpdf, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_613+currStrOff, newFnRetType, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_613+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_613+currStrOff, code, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_613;
char * ____BAH_COMPILER_VAR_614 = code;
return ____BAH_COMPILER_VAR_614;
};
void parseStruct(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
struct cStruct* s = memoryAlloc(sizeof(struct cStruct));
s->name = "";
s->members = memoryAlloc(sizeof(array(struct structMemb*)));
            s->members->length = 0;
            s->members->elemSize = sizeof(struct structMemb*);
            s->methods = memoryAlloc(sizeof(array(struct func*)));
            s->methods->length = 0;
            s->methods->elemSize = sizeof(struct func*);
            s->postCode = "";
s->extendedFrom = "";
s->isBinding = false;
s->hasRCPmemb = false;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1946): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok nameToken =  l->data[1];
long int i =  2;
int doesOutput =  true;
if ((__checkString(nameToken.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1949 nameToken.cont ")==1&&strcmp(nameToken.cont, "!") == 0)) {

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1950): l[%d] with length %d\n", 2, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1966): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok st =  l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:1968 st.cont ")==1&&strcmp(st.cont, "extend") == 0)) {
i =  i + 1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1970): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok extdSNameTk =  l->data[i];
i =  i + 1;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1982): extdsmbs[%d] with length %d\n", j, extdsmbs->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1990): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                            exit(1);
                        };
                        struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_615 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_616 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_615);
;                            
                        ____BAH_COMPILER_VAR_616 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, ____BAH_COMPILER_VAR_615, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_616;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_617 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_617 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_617+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_617+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_617;
}
};
char * ____BAH_COMPILER_VAR_618 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_619 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_618);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(em->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_619 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_619+currStrOff, ____BAH_COMPILER_VAR_618, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_619+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_619+currStrOff, em->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_619+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_619+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_619+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    membDeclStr =  ____BAH_COMPILER_VAR_619;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2013): extdS->methods[%d] with length %d\n", k, extdS->methods->length);
                            exit(1);
                        };
                        struct func* emt =  extdS->methods->data[k];
struct string mthdDecl =  getCType(emt->returns->type,elems);
char * ____BAH_COMPILER_VAR_620 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(emt->name);
long int strLen_2 = strlen(")(");
;                            
                        ____BAH_COMPILER_VAR_620 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_620+currStrOff, "(*", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_620+currStrOff, emt->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_620+currStrOff, ")(", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_620);
j =  0;
while ((j<len(emt->args))) {

                        if (emt->args->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2018): emt->args[%d] with length %d\n", j, emt->args->length);
                            exit(1);
                        };
                        struct variable* a =  emt->args->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_621 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                        ____BAH_COMPILER_VAR_621 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_621+currStrOff, " ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_621+currStrOff, a->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tp.append((struct string*)&tp,____BAH_COMPILER_VAR_621);
long int max =  len(emt->args) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_622 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_622);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2037): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok braceTk =  l->data[i];
i =  i + 1;
if ((__checkString(braceTk.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2039 braceTk.cont ")==1&&strcmp(braceTk.cont, "{") != 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
struct rope* OOUT =  OUTPUT;
char * nextLine =  "";
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2045): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
long int max =  i + 2;
if ((max>=len(l))) {
if (((t.type==TOKEN_TYPE_ENCL)&&(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2048 t.cont ")==1&&strcmp(t.cont, "}") == 0))) {
break;
}
throwErr(&l->data[len(l)-1],"Not enough argument in member declaration, ending by {TOKEN}.");
}
struct structMemb* memb = memoryAlloc(sizeof(struct structMemb));
memb->name = "";
memb->type = "";
memb->isConst = false;
memb->constVal = "";
memb->isArray = false;
memb->from = "";
memb->outterScope = false;
memb->def = "";
memb->isFn = false;
if ((t.type!=TOKEN_TYPE_VAR)) {
throwErr(&t,"Cannot use {TOKEN} as member name.");
}
memb->name =  t.cont;
long int ii =  0;
while ((ii<len(members))) {

                        if (members->length <= ii) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2059): members[%d] with length %d\n", ii, members->length);
                            exit(1);
                        };
                        struct structMemb* m =  members->data[ii];
if ((__checkString(m->name, "/home/alois/Documents/bah-bah/src/parser.bah:2060 m->name ")==1&&__checkString(memb->name, "/home/alois/Documents/bah-bah/src/parser.bah:2060 memb->name")==1&&strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii =  ii + 1;
};
i =  i + 1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2066): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2067 t.cont ")==1&&strcmp(t.cont, ":") != 0)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2068 t.cont ")==1&&strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_623 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("__");
;                            
                        ____BAH_COMPILER_VAR_623 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_623+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_623+currStrOff, "__", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * fnPrefix =  ____BAH_COMPILER_VAR_623;
struct func* fn = memoryAlloc(sizeof(struct func));
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->returns= null;
fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int j =  i-1;
while ((j<len(l))) {

                        if (l->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2075): l[%d] with length %d\n", j, l->length);
                            exit(1);
                        };
                        t =  l->data[j];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2076 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
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
char * ____BAH_COMPILER_VAR_624 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_624 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_624+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_624+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_624;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2091): l[%d] with length %d\n", j + 1, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[j + 1];
if ((__checkString(nt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2092 nt.cont ")==1&&strcmp(nt.cont, ")") != 0)) {
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
i =  i - 1;
long int nli =  0;
char * ____BAH_COMPILER_VAR_625 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code =  rope(____BAH_COMPILER_VAR_625);
i =  i + nli;
i =  i - 2;
struct variable* returns =  fn->returns;
array(struct variable*)* arguments =  fn->args;
fn->from =  s->name;
code =  code->add(code, rope("{\n"));
struct Elems* fnElems =  dupElems(elems);
j =  0;
while ((j<len(arguments))) {

                        if (arguments->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2116): arguments[%d] with length %d\n", j, arguments->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2127): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2128 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
i =  i + 1;
}
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2132): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2133 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
nbBraces =  nbBraces + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2135 t.cont ")==1&&strcmp(t.cont, "}") == 0)) {
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
i =  i + 1;
};
struct func* mfn = memoryAlloc(sizeof(struct func));
mfn->name = "";
mfn->args = memoryAlloc(sizeof(array(struct variable*)));
            mfn->args->length = 0;
            mfn->args->elemSize = sizeof(struct variable*);
            mfn->returns= null;
mfn->isBinding = false;
mfn->from = "";
mfn->file = "";
mfn->line = 1;
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
char * ____BAH_COMPILER_VAR_626 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                        ____BAH_COMPILER_VAR_626 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_626+currStrOff, "Function '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_626+currStrOff, fn->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_626+currStrOff, "' is not returned.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_626);
}
endRCPscope(fnElems,null);
}
code =  code->add(code, OUTPUT)->add(code->add(code, OUTPUT), rope("};\n"));
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_627 =code->toStr((struct rope*)code);char * ____BAH_COMPILER_VAR_628 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nextLine);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_627);
;                            
                        ____BAH_COMPILER_VAR_628 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_628+currStrOff, nextLine, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_628+currStrOff, ____BAH_COMPILER_VAR_627, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nextLine =  ____BAH_COMPILER_VAR_628;
}
struct string mthdDecl =  getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_629 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(mfn->name);
long int strLen_2 = strlen(")(");
;                            
                        ____BAH_COMPILER_VAR_629 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_629+currStrOff, "(*", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_629+currStrOff, mfn->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_629+currStrOff, ")(", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_629);
j =  0;
while ((j<len(arguments))) {

                        if (arguments->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2178): arguments[%d] with length %d\n", j, arguments->length);
                            exit(1);
                        };
                        struct variable* a =  arguments->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_630 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                        ____BAH_COMPILER_VAR_630 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_630+currStrOff, " ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_630+currStrOff, a->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tp.append((struct string*)&tp,____BAH_COMPILER_VAR_630);
max =  len(arguments) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_631 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_631);
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
i =  i + 1;
continue;
}
}
i =  i + 1;
char * mbmType =  "";
long int currentLine =  t.line;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2200): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2201 t.cont ")==1&&strcmp(t.cont, "=") == 0)) {
i =  i - 1;
break;
}
if ((t.line!=currentLine)) {
i =  i - 1;
break;
}
char * ____BAH_COMPILER_VAR_632 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(mbmType);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_632 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_632+currStrOff, mbmType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_632+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    mbmType =  ____BAH_COMPILER_VAR_632;
i =  i + 1;
};
memb->type =  mbmType;
i =  i + 1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2215): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((i<len(l))) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2217 t.cont ")==1&&strcmp(t.cont, "=") == 0)) {
i =  i + 1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2219): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char * ____BAH_COMPILER_VAR_633 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(memb->type);
long int strLen_4 = strlen(" for member.");
;                            
                        ____BAH_COMPILER_VAR_633 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, memb->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, " for member.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_633);
}
memb->def =  t.cont;
}
else {
i =  i - 1;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2244): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                            exit(1);
                        };
                        struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_634 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_635 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_634);
;                            
                        ____BAH_COMPILER_VAR_635 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_635+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_635+currStrOff, ____BAH_COMPILER_VAR_634, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_635;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_636 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_636 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_636+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_636+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_636;
}
};
char * ____BAH_COMPILER_VAR_637 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_638 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_637);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(memb->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_638 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, ____BAH_COMPILER_VAR_637, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, memb->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    membDeclStr =  ____BAH_COMPILER_VAR_638;
}
else {
struct string membDecl =  getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_639 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(memb->name);
;                            
                        ____BAH_COMPILER_VAR_639 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_639+currStrOff, " ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_639+currStrOff, memb->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    membDecl.append((struct string*)&membDecl,____BAH_COMPILER_VAR_639);
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
i =  i + 1;
};
s->members =  members;
if ((doesOutput==true)) {
OUTPUT =  OOUT;
NEXT_LINE =  nextLine;
char * ____BAH_COMPILER_VAR_640 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("struct ");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen(" {\n");
;                            
                        ____BAH_COMPILER_VAR_640 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_640+currStrOff, "struct ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_640+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_640+currStrOff, " {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* code =  rope(____BAH_COMPILER_VAR_640);
i =  0;
while ((i<len(allMembs))) {

                        if (allMembs->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2267): allMembs[%d] with length %d\n", i, allMembs->length);
                            exit(1);
                        };
                        char * m =  allMembs->data[i];
char * ____BAH_COMPILER_VAR_641 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(m);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_641 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, m, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_641+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  code->add(code, rope(____BAH_COMPILER_VAR_641));
i =  i + 1;
};
if ((RCPavailable()==true)) {
code =  code->add(code, rope("void * __RCP_counter;\n"));
}
code =  code->add(code, rope("};\n"));
OUTPUT =  OUTPUT->add(OUTPUT, code)->add(OUTPUT->add(OUTPUT, code), makeRCPfuncFromStruct(s,elems));
}
if ((debug==true)) {
struct debugStruct* ds = memoryAlloc(sizeof(struct debugStruct));
ds->name= null;
ds->membs = memoryAlloc(sizeof(array(struct variable*)));
            ds->membs->length = 0;
            ds->membs->elemSize = sizeof(struct variable*);
            ds->name =  s->name;
i =  0;
while ((i<len(s->members))) {

                        if (s->members->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2284): s->members[%d] with length %d\n", i, s->members->length);
                            exit(1);
                        };
                        struct structMemb* m =  s->members->data[i];
struct variable* mv = memoryAlloc(sizeof(struct variable));
mv->name = "";
mv->type = "";
mv->isConst = false;
mv->constVal = "";
mv->isArray = false;
mv->from = "";
mv->outterScope = false;
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
struct reflectElement ____BAH_COMPILER_VAR_643 = __reflect((char **)((char*)(ds) + offsetof(struct debugStruct, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_645 = __reflect((char **)((char*)(0) + offsetof(struct variable, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_646 = __reflect((char **)((char*)(0) + offsetof(struct variable, type)), sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_647 = __reflect((int*)((char*)(0) + offsetof(struct variable, isConst)), sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_648 = __reflect((char **)((char*)(0) + offsetof(struct variable, constVal)), sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_649 = __reflect((int*)((char*)(0) + offsetof(struct variable, isArray)), sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_650 = __reflect((char **)((char*)(0) + offsetof(struct variable, from)), sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_651 = __reflect((int*)((char*)(0) + offsetof(struct variable, outterScope)), sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_644 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_644->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_644->length = 7;
        ____BAH_COMPILER_VAR_644->data = memoryAlloc(____BAH_COMPILER_VAR_644->length * ____BAH_COMPILER_VAR_644->elemSize);
        ____BAH_COMPILER_VAR_644->data[0] = ____BAH_COMPILER_VAR_645;
____BAH_COMPILER_VAR_644->data[1] = ____BAH_COMPILER_VAR_646;
____BAH_COMPILER_VAR_644->data[2] = ____BAH_COMPILER_VAR_647;
____BAH_COMPILER_VAR_644->data[3] = ____BAH_COMPILER_VAR_648;
____BAH_COMPILER_VAR_644->data[4] = ____BAH_COMPILER_VAR_649;
____BAH_COMPILER_VAR_644->data[5] = ____BAH_COMPILER_VAR_650;
____BAH_COMPILER_VAR_644->data[6] = ____BAH_COMPILER_VAR_651;
struct reflectElement ____BAH_COMPILER_VAR_652 = __reflect(0, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_644, 0);

        struct reflectElement ____BAH_COMPILER_VAR_653 = ____BAH_COMPILER_VAR_652;
        struct reflectElement ____BAH_COMPILER_VAR_654 = __reflect((array(struct variable*)**)((char*)(ds) + offsetof(struct debugStruct, membs)), sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_653, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_642 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_642->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_642->length = 2;
        ____BAH_COMPILER_VAR_642->data = memoryAlloc(____BAH_COMPILER_VAR_642->length * ____BAH_COMPILER_VAR_642->elemSize);
        ____BAH_COMPILER_VAR_642->data[0] = ____BAH_COMPILER_VAR_643;
____BAH_COMPILER_VAR_642->data[1] = ____BAH_COMPILER_VAR_654;
struct reflectElement ____BAH_COMPILER_VAR_655 = __reflect(ds, sizeof(struct debugStruct), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_642, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_655);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2306): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[1];

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2307): l[%d] with length %d\n", 2, l->length);
                            exit(1);
                        };
                        struct Tok st =  l->data[2];
long int i =  1;
int doesOutput =  true;
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2311 ft.cont ")==1&&strcmp(ft.cont, "!") == 0)) {

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2312): l[%d] with length %d\n", 2, l->length);
                            exit(1);
                        };
                        ft =  l->data[2];

                        if (l->length <= 3) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2313): l[%d] with length %d\n", 3, l->length);
                            exit(1);
                        };
                        st =  l->data[3];
i =  2;
doesOutput =  false;
}
if ((__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2318 st.cont ")==1&&strcmp(st.cont, "(") == 0)) {
struct func* fn = memoryAlloc(sizeof(struct func));
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->returns= null;
fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;
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
char * ____BAH_COMPILER_VAR_656 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_656 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_656+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_656+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_656));
}
}
else {
char * tp =  "";
i =  i+1;
for (; (i<len(l)); i =  i+1) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2332): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
char * ____BAH_COMPILER_VAR_657 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_657 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_657+currStrOff, tp, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_657+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tp =  ____BAH_COMPILER_VAR_657;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType =  getCType(tp,elems);
char * cTypeNewTypeStr =  cTypeNewType.str((struct string*)&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_658 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("typedef ");
long int strLen_1 = strlen(cTypeNewTypeStr);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(ft.cont);
long int strLen_4 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_658 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_658+currStrOff, "typedef ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_658+currStrOff, cTypeNewTypeStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_658+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_658+currStrOff, ft.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_658+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_658));
}
if ((debug==true)) {
struct debugType* dt = memoryAlloc(sizeof(struct debugType));
dt->name= null;
dt->refers= null;
dt->name =  ft.cont;
dt->refers =  tp;
struct reflectElement ____BAH_COMPILER_VAR_660 = __reflect((char **)((char*)(dt) + offsetof(struct debugType, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_661 = __reflect((char **)((char*)(dt) + offsetof(struct debugType, refers)), sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_659 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_659->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_659->length = 2;
        ____BAH_COMPILER_VAR_659->data = memoryAlloc(____BAH_COMPILER_VAR_659->length * ____BAH_COMPILER_VAR_659->elemSize);
        ____BAH_COMPILER_VAR_659->data[0] = ____BAH_COMPILER_VAR_660;
____BAH_COMPILER_VAR_659->data[1] = ____BAH_COMPILER_VAR_661;
struct reflectElement ____BAH_COMPILER_VAR_662 = __reflect(dt, sizeof(struct debugType), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_659, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_662);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2362): line[%d] with length %d\n", i, line->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2374): clibs[%d] with length %d\n", j, clibs->length);
                            exit(1);
                        };
                        char * l =  clibs->data[j];
if ((__checkString(l, "/home/alois/Documents/bah-bah/src/parser.bah:2375 l ")==1&&__checkString(ccstr, "/home/alois/Documents/bah-bah/src/parser.bah:2375 ccstr")==1&&strcmp(l, ccstr) == 0)) {
found =  true;
break;
}
j =  j + 1;
};
if ((found==true)) {
i =  i + 1;
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
i =  i + 1;
};
};
void parseConst(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
l =  parseCast(l,elems);
if ((len(l)!=4)) {
throwErr(&l->data[0],"Invalid usage of {TOKEN}, must be 'const <constName> = <constValue>'. ");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2397): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok vart =  l->data[1];

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2398): l[%d] with length %d\n", 2, l->length);
                            exit(1);
                        };
                        struct Tok equt =  l->data[2];

                        if (l->length <= 3) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2399): l[%d] with length %d\n", 3, l->length);
                            exit(1);
                        };
                        struct Tok valt =  l->data[3];
if ((vart.type!=TOKEN_TYPE_VAR)) {
throwErr(&vart,"Cannot take {TOKEN} as const name.");
}
if ((__checkString(equt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2403 equt.cont ")==1&&strcmp(equt.cont, "=") != 0)) {
throwErr(&equt,"Expected '=' not {TOKEN}.");
}
if ((valt.isValue==false)) {
throwErr(&equt,"Must be a value, not {TOKEN}.");
}
struct variable* v = memoryAlloc(sizeof(struct variable));
v->name = "";
v->type = "";
v->isConst = false;
v->constVal = "";
v->isArray = false;
v->from = "";
v->outterScope = false;
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
char * ____BAH_COMPILER_VAR_663 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(valt.cont);
long int strLen_4 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_663 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_663+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_663+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_663+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_663+currStrOff, valt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_663+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_663));
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
char * ____BAH_COMPILER_VAR_664 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot return nothing as ");
long int strLen_1 = strlen(currentFn->returns->type);
long int strLen_2 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_664 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_664+currStrOff, "Cannot return nothing as ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_664+currStrOff, currentFn->returns->type, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_664+currStrOff, ".", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&l->data[0],____BAH_COMPILER_VAR_664);
}
}
else {

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2436): l[%d] with length %d\n", 1, l->length);
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
char * ____BAH_COMPILER_VAR_665 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot return {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(currentFn->returns->type);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_665 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_665+currStrOff, "Cannot return {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_665+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_665+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_665+currStrOff, currentFn->returns->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_665+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&rvt,____BAH_COMPILER_VAR_665);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned =  true;
}
char * rvar =  genCompilerVar();
struct string cType =  getCType(currentFn->returns->type,elems);
if ((strlen(rv)>0)) {
char * ____BAH_COMPILER_VAR_666 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_667 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_666);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvar);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(rv);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_667 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, ____BAH_COMPILER_VAR_666, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, rvar, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, rv, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_667));
endRCPscope(elems,null);
char * ____BAH_COMPILER_VAR_668 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("return ");
long int strLen_1 = strlen(rvar);
long int strLen_2 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_668 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_668+currStrOff, "return ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_668+currStrOff, rvar, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_668+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_668));
}
else {
endRCPscope(elems,null);
OUTPUT =  OUTPUT->add(OUTPUT, rope("return;\n"));
}
};
void parseIf(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2470): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[0];
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2473): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok condt =  l->data[1];
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2474 condt.bahType ")==1&&strcmp(condt.bahType, "bool") != 0)) {
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2475 condt.bahType ")==1&&strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2479): l[%d] with length %d\n", 2, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[2];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2480 t.cont ")==1&&strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in if statement.");
}
array(struct Tok)* tokens = memoryAlloc(sizeof(array(struct Tok)));

tokens->length = 0;
tokens->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
long int i =  3;
while ((i<max)) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2486): l[%d] with length %d\n", i, l->length);
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
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_669 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("if (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                        ____BAH_COMPILER_VAR_669 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, "if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, condt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, ") {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_669));
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(tokens,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                        if (l->length <= len(l)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2499): l[%d] with length %d\n", len(l)-1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2518): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[1];
OUTPUT =  OUTPUT->add(OUTPUT, rope("else "));
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2520 ft.cont ")==1&&strcmp(ft.cont, "if") == 0)) {
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int i =  1;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2523): l[%d] with length %d\n", i, l->length);
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
parseIf(memory,elems);
prevLine =  LINE_TYPE_IF;
}
else {
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2530 ft.cont ")==1&&strcmp(ft.cont, "{") != 0)) {
throwErr(&ft,"Expected 'if' or '{' not {TOKEN}.");
}
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
long int max =  len(l) - 1;
long int i =  2;
while ((i<max)) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2536): l[%d] with length %d\n", i, l->length);
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
OUTPUT =  OUTPUT->add(OUTPUT, rope("{\n"));
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(memory,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                        if (l->length <= len(l)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2547): l[%d] with length %d\n", len(l)-1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2566): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2567 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
break;
}
if (((t.type==TOKEN_TYPE_SYNTAX)&&(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2570 t.cont ")==1&&strcmp(t.cont, ",") == 0))) {
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2582): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[0];
throwErr(&t,"Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2587): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok condt =  l->data[1];
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2589 condt.bahType ")==1&&strcmp(condt.bahType, "bool") != 0)) {
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2590 condt.bahType ")==1&&strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2595): l[%d] with length %d\n", 2, l->length);
                            exit(1);
                        };
                        struct Tok st =  l->data[2];
if (((st.type!=TOKEN_TYPE_SYNTAX)||(__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2597 st.cont ")==1&&strcmp(st.cont, ",") != 0))) {
throwErr(&st,"Cannot use {TOKEN}, need ',' to split for loop instructions.");
}
i =  3;
for (; (i<len(l)); i =  i+1) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2602): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if (((t.type==TOKEN_TYPE_ENCL)&&(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2603 t.cont ")==1&&strcmp(t.cont, "{") == 0))) {
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
char * ____BAH_COMPILER_VAR_670 =OUTPUT->toStr((struct rope*)OUTPUT);struct string instC =  string(____BAH_COMPILER_VAR_670);
OUTPUT =  oldOut;
instC.trimRight((struct string*)&instC,2);

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2618): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2619 t.cont ")==1&&strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after '<condition>,<instruction>' in for statement.");
}
long int max =  len(l) - 1;
i =  i + 1;
for (; (i<max); i =  i+1) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2625): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_671 =instC.str((struct string*)&instC);char * ____BAH_COMPILER_VAR_672 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("for (; ");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen("; ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_671);
long int strLen_4 = strlen(") {\n");
;                            
                        ____BAH_COMPILER_VAR_672 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_672+currStrOff, "for (; ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_672+currStrOff, condt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_672+currStrOff, "; ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_672+currStrOff, ____BAH_COMPILER_VAR_671, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_672+currStrOff, ") {\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_672));
}
else {

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2632): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok condt =  l->data[1];
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2633 condt.bahType ")==1&&strcmp(condt.bahType, "bool") != 0)) {
if ((__checkString(condt.bahType, "/home/alois/Documents/bah-bah/src/parser.bah:2634 condt.bahType ")==1&&strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2638): l[%d] with length %d\n", 2, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[2];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2639 t.cont ")==1&&strcmp(t.cont, "{") != 0)) {
throwErr(&t,"Expected '{' not {TOKEN} after condtition in for statement.");
}
long int max =  len(l) - 1;
i =  3;
for (; (i<max); i =  i+1) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2644): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_673 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("while (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                        ____BAH_COMPILER_VAR_673 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_673+currStrOff, "while (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_673+currStrOff, condt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_673+currStrOff, ") {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_673));
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2658): l[%d] with length %d\n", len(l)-1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2669): l[%d] with length %d\n", 0, l->length);
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
char * ____BAH_COMPILER_VAR_674 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_674 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_674+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_674));
};
void parsePreKeyword(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2684): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[0];
if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2686 ft.cont ")==1&&strcmp(ft.cont, "#warning") == 0)) {
if ((len(l)!=2)) {
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2690): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok mt =  l->data[1];
if ((mt.type!=TOKEN_TYPE_STR)) {
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}
struct string msg =  string(mt.cont);
msg.trimLeft((struct string*)&msg,1);
msg.trimRight((struct string*)&msg,1);
char * ____BAH_COMPILER_VAR_675 =msg.str((struct string*)&msg);throwWarning(____BAH_COMPILER_VAR_675);
return;
}
if ((len(l)<3)) {
throwErr(&ft,"Invalid usage of keyword {TOKEN}.");
}
if ((((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2708 ft.cont ")==1&&strcmp(ft.cont, "#linux") == 0)||(__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2708 ft.cont ")==1&&strcmp(ft.cont, "#windows") == 0))||(__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2708 ft.cont ")==1&&strcmp(ft.cont, "#darwin") == 0))) {
struct string isOS =  string(ft.cont);
isOS.trimLeft((struct string*)&isOS,1);
if ((__checkString(isOS.str((struct string*)&isOS), "/home/alois/Documents/bah-bah/src/parser.bah:2711 isOS.str((struct string*)&isOS) ")==1&&__checkString(BAH_OS, "/home/alois/Documents/bah-bah/src/parser.bah:2711 BAH_OS")==1&&strcmp(isOS.str((struct string*)&isOS), BAH_OS) != 0)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2714 ft.cont ")==1&&strcmp(ft.cont, "#static") == 0)) {
if ((flags.isSet((struct flags*)&flags,"d")==1)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2718 ft.cont ")==1&&strcmp(ft.cont, "#dynamic") == 0)) {
if ((flags.isSet((struct flags*)&flags,"d")==0)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2722 ft.cont ")==1&&strcmp(ft.cont, "#gc") == 0)) {
if ((RCPavailable()==true)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2726 ft.cont ")==1&&strcmp(ft.cont, "#rcp") == 0)) {
if ((RCPavailable()==false)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2730 ft.cont ")==1&&strcmp(ft.cont, "#lib") == 0)) {
if ((flags.isSet((struct flags*)&flags,"l")==0)) {
return;
}
}
else if ((__checkString(ft.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2734 ft.cont ")==1&&strcmp(ft.cont, "#exec") == 0)) {
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
return;
}
}
else {
throwErr(&ft,"Undefined token {TOKEN}.");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2742): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok st =  l->data[1];

                        if (l->length <= len(l)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2743): l[%d] with length %d\n", len(l)-1, l->length);
                            exit(1);
                        };
                        struct Tok lt =  l->data[len(l)-1];
if (((__checkString(st.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2744 st.cont ")==1&&strcmp(st.cont, "{") != 0)||(__checkString(lt.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2744 lt.cont ")==1&&strcmp(lt.cont, "}") != 0))) {
throwErr(&st,"Expected code block after keyword {TOKEN}.");
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
long int i =  2;
while ((i<len(l) - 1)) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2750): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2760): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[0];
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2763): l[%d] with length %d\n", 1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2770): compilerState.cLibs[%d] with length %d\n", i, compilerState.cLibs->length);
                            exit(1);
                        };
                        if ((__checkString(compilerState.cLibs->data[i], "/home/alois/Documents/bah-bah/src/parser.bah:2770 compilerState.cLibs->data[i] ")==1&&strcmp(compilerState.cLibs->data[i], "lpthread") == 0)) {
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2783): fnNameParts[%d] with length %d\n", 0, fnNameParts->length);
                            exit(1);
                        };
                        struct string fnName =  fnNameParts->data[0];
char * ____BAH_COMPILER_VAR_684 =fnName.str((struct string*)&fnName);struct func* fn =  searchFunc(____BAH_COMPILER_VAR_684,elems,true);
if ((fn==null)) {
throwErr(&fnT,"Internal compiler error.\n Error in async parsing, arround {TOKEN}.");
}
char * sMembs =  "";
char * unSerMembs =  "";
i =  0;
while ((i<len(fn->args))) {

                        if (fn->args->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2794): fn->args[%d] with length %d\n", i, fn->args->length);
                            exit(1);
                        };
                        struct variable* a =  fn->args->data[i];
struct string cType =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_685 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_686 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(sMembs);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_685);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(a->name);
long int strLen_4 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_686 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_686+currStrOff, sMembs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_686+currStrOff, ____BAH_COMPILER_VAR_685, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_686+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_686+currStrOff, a->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_686+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    sMembs =  ____BAH_COMPILER_VAR_686;
char * ____BAH_COMPILER_VAR_687 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen("args->");
long int strLen_2 = strlen(a->name);
;                            
                        ____BAH_COMPILER_VAR_687 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_687+currStrOff, unSerMembs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_687+currStrOff, "args->", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_687+currStrOff, a->name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    unSerMembs =  ____BAH_COMPILER_VAR_687;
i =  i + 1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_688 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen(", ");
;                            
                        ____BAH_COMPILER_VAR_688 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_688+currStrOff, unSerMembs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_688+currStrOff, ", ", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    unSerMembs =  ____BAH_COMPILER_VAR_688;
}
};
char * ____BAH_COMPILER_VAR_689 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("struct {\n");
long int strLen_1 = strlen(sMembs);
long int strLen_2 = strlen("}");
;                            
                        ____BAH_COMPILER_VAR_689 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_689+currStrOff, "struct {\n", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_689+currStrOff, sMembs, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_689+currStrOff, "}", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * tmpArgsStruct =  ____BAH_COMPILER_VAR_689;
char * fnWrapper =  genCompilerVar();
char * tmpArgs =  genCompilerVar();
sFnT.trimLeft((struct string*)&sFnT,fnName.length + 1);
sFnT.trimRight((struct string*)&sFnT,1);
char * tCreate =  "pthread_create";
if ((RCPavailable()==false)) {
tCreate =  "GC_pthread_create";
}
char * ____BAH_COMPILER_VAR_690 =fnName.str((struct string*)&fnName);char * ____BAH_COMPILER_VAR_691 =sFnT.str((struct string*)&sFnT);char * ____BAH_COMPILER_VAR_692 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n    void ");
long int strLen_1 = strlen(fnWrapper);
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(tmpArgsStruct);
long int strLen_4 = strlen("* args) {\n        ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_690);
long int strLen_6 = strlen("(");
long int strLen_7 = strlen(unSerMembs);
long int strLen_8 = strlen(");\n    };\n    {\n        ");
long int strLen_9 = strlen(tmpArgsStruct);
long int strLen_10 = strlen(" ");
long int strLen_11 = strlen(tmpArgs);
long int strLen_12 = strlen(" = {");
long int strLen_13 = strlen(____BAH_COMPILER_VAR_691);
long int strLen_14 = strlen("};\n        pthread_t id;\n        ");
long int strLen_15 = strlen(tCreate);
long int strLen_16 = strlen("(&id, 0, ");
long int strLen_17 = strlen(fnWrapper);
long int strLen_18 = strlen(", &");
long int strLen_19 = strlen(tmpArgs);
long int strLen_20 = strlen(");\n    }; \n    \n    ");
;                            
                        ____BAH_COMPILER_VAR_692 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20);
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, "\n    void ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, fnWrapper, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, tmpArgsStruct, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, "* args) {\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, ____BAH_COMPILER_VAR_690, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, "(", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, unSerMembs, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, ");\n    };\n    {\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, tmpArgsStruct, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, " ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, tmpArgs, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, " = {", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, ____BAH_COMPILER_VAR_691, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, "};\n        pthread_t id;\n        ", strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, tCreate, strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, "(&id, 0, ", strLen_16);
                        currStrOff += strLen_16;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, fnWrapper, strLen_17);
                        currStrOff += strLen_17;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, ", &", strLen_18);
                        currStrOff += strLen_18;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, tmpArgs, strLen_19);
                        currStrOff += strLen_19;
                        
                        strncpy(____BAH_COMPILER_VAR_692+currStrOff, ");\n    }; \n    \n    ", strLen_20);
                        currStrOff += strLen_20;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_692));
};
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
long int i =  0;
if ((ltp==LINE_TYPE_VAR)) {
i =  1;
}
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2836): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2852): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((((t.type==TOKEN_TYPE_SYNTAX)&&(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2853 t.cont ")==1&&strcmp(t.cont, "->") == 0))||(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2853 t.cont ")==1&&strcmp(t.cont, "<-") == 0))) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2855 t.cont ")==1&&strcmp(t.cont, "<-") == 0)) {
i =  i+1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2858): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i];
if ((nt.type!=TOKEN_TYPE_VAR)) {
throwErr(&nt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_693 =getTypeFromToken(&nt,true,elems);struct string ntt =  string(____BAH_COMPILER_VAR_693);
if ((ntt.hasPrefix((struct string*)&ntt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_694 =ntt.str((struct string*)&ntt);char * ____BAH_COMPILER_VAR_695 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use var {TOKEN} (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_694);
long int strLen_2 = strlen(") as channel.");
;                            
                        ____BAH_COMPILER_VAR_695 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_695+currStrOff, "Cannot use var {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_695+currStrOff, ____BAH_COMPILER_VAR_694, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_695+currStrOff, ") as channel.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_695);
}
ntt.trimLeft((struct string*)&ntt,5);
if (isGlobal()) {
throwErr(&t,"Cannot receive ({TOKEN}) from a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_696 =ntt.str((struct string*)&ntt);if (isRCPpointerType(____BAH_COMPILER_VAR_696)) {
char * ____BAH_COMPILER_VAR_697 =ntt.str((struct string*)&ntt);struct string ct =  getCType(____BAH_COMPILER_VAR_697,elems);
char * ____BAH_COMPILER_VAR_698 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_699 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_698);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_699 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, ____BAH_COMPILER_VAR_698, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, "->receive(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_699;
}
else {
char * ____BAH_COMPILER_VAR_700 =ntt.str((struct string*)&ntt);struct string ct =  getCType(____BAH_COMPILER_VAR_700,elems);
char * ____BAH_COMPILER_VAR_701 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_702 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_701);
long int strLen_2 = strlen("*)");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("->receive(");
long int strLen_5 = strlen(nt.cont);
long int strLen_6 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_702 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_702+currStrOff, "*(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_702+currStrOff, ____BAH_COMPILER_VAR_701, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_702+currStrOff, "*)", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_702+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_702+currStrOff, "->receive(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_702+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_702+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_702;
}
t.isFunc =  true;
t.type =  TOKEN_TYPE_FUNC;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2893): l[%d] with length %d\n", i + 1, l->length);
                            exit(1);
                        };
                        struct Tok pt =  l->data[i + 1];

                        if (l->length <= i-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2894): l[%d] with length %d\n", i-1, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i-1];
char * ntt =  getTypeFromToken(&nt,true,elems);
if ((pt.type!=TOKEN_TYPE_VAR)) {
throwErr(&pt,"Cannot use {TOKEN} as channel.");
}
char * ____BAH_COMPILER_VAR_703 =getTypeFromToken(&pt,true,elems);struct string ptt =  string(____BAH_COMPILER_VAR_703);
if ((ptt.hasPrefix((struct string*)&ptt,"chan:")==0)) {
char * ____BAH_COMPILER_VAR_704 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use var {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as channel.");
;                            
                        ____BAH_COMPILER_VAR_704 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_704+currStrOff, "Cannot use var {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_704+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_704+currStrOff, ") as channel.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&pt,____BAH_COMPILER_VAR_704);
}
ptt.trimLeft((struct string*)&ptt,5);
if (isGlobal()) {
throwErr(&t,"Cannot send ({TOKEN}) to a channel outside of a function.");
}
char * ____BAH_COMPILER_VAR_705 =ptt.str((struct string*)&ptt);if ((compTypes(____BAH_COMPILER_VAR_705,ntt)==false)) {
char * ____BAH_COMPILER_VAR_706 =ptt.str((struct string*)&ptt);char * ____BAH_COMPILER_VAR_707 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot send {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to channel of type ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_706);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_707 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_707+currStrOff, "Cannot send {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_707+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_707+currStrOff, ") to channel of type ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_707+currStrOff, ____BAH_COMPILER_VAR_706, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_707+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_707);
}
i =  i+1;
char * ____BAH_COMPILER_VAR_708 =ptt.str((struct string*)&ptt);if (isRCPpointerType(____BAH_COMPILER_VAR_708)) {
char * ____BAH_COMPILER_VAR_709 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen("->send(");
long int strLen_2 = strlen(pt.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen(nt.cont);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_709 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_709+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_709+currStrOff, "->send(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_709+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_709+currStrOff, ", ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_709+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_709+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_709));
}
else {
struct string ct =  getCType(ntt,elems);
char * tmpV =  genCompilerVar();
char * ____BAH_COMPILER_VAR_710 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_711 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n                    ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_710);
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
                        ____BAH_COMPILER_VAR_711 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, "\n                    ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, ____BAH_COMPILER_VAR_710, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, tmpV, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, nt.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, ";\n                    ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, pt.cont, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, "->sendAny(", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, pt.cont, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, ", &", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, tmpV, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, ", sizeof(", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, tmpV, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_711+currStrOff, "));\n", strLen_14);
                        currStrOff += strLen_14;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_711));
}
nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
array(struct Tok)* ____BAH_COMPILER_VAR_712 = nl;
return ____BAH_COMPILER_VAR_712;
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
array(struct Tok)* ____BAH_COMPILER_VAR_713 = nl;
return ____BAH_COMPILER_VAR_713;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2941): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2942 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
nbPar =  nbPar + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2944 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
nbPar =  nbPar - 1;
}
else if (((nbPar==0)&&(__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:2946 t.cont ")==1&&strcmp(t.cont, "{") == 0))) {

                        if (line->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2947): line[%d] with length %d\n", i + 1, line->length);
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
i =  i + 1;
};
}
else {
fl =  line;
}
fl =  parseStructVars(fl,elems);
fl =  parseFnCall(fl,elems);
fl =  parseArrayVars(fl,elems);
fl =  parseArrayType(fl,elems);
fl =  parseStructType(fl,elems);
fl =  parseCast(fl,elems);
addRCPvars(fl,ltp,elems);
fl =  parseOperations(fl,elems);
fl =  parseBool(fl,elems);
fl =  parseChan(fl,elems);
if ((ltp!=(lineType)-1)) {
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2972): line[%d] with length %d\n", i, line->length);
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
i =  i + 1;
};
}
array(struct Tok)* ____BAH_COMPILER_VAR_714 = fl;
return ____BAH_COMPILER_VAR_714;
};
void parseFnDeclare(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
long int i =  0;
struct func* fn = memoryAlloc(sizeof(struct func));
fn->name = "";
fn->args = memoryAlloc(sizeof(array(struct variable*)));
            fn->args->length = 0;
            fn->args->elemSize = sizeof(struct variable*);
            fn->returns= null;
fn->isBinding = false;
fn->from = "";
fn->file = "";
fn->line = 1;

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2984): l[%d] with length %d\n", 0, l->length);
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
char * ____BAH_COMPILER_VAR_715 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
long int strLen_1 = strlen(ogFn->file);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(lineStr);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_715 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_715+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_715+currStrOff, ogFn->file, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_715+currStrOff, ":", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_715+currStrOff, lineStr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_715+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&ft,____BAH_COMPILER_VAR_715);
}
}
if ((__checkString(fn->name, "/home/alois/Documents/bah-bah/src/parser.bah:2996 fn->name ")==1&&strcmp(fn->name, "main") == 0)) {
compilerState.haveEntryPoint =  true;
if ((compTypes(fn->returns->type,"int")==false)) {
throwErr(&ft,"{TOKEN} function should return 'int'.");
}
if ((len(fn->args)!=1)) {
throwErr(&ft,"{TOKEN} function should take one []cpstring argument. Should be: \n            'main(args []cpstring) int'");
}

                        if (fn->args->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3005): fn->args[%d] with length %d\n", 0, fn->args->length);
                            exit(1);
                        };
                        struct variable* fa =  fn->args->data[0];
if ((compTypes(fa->type,"[]cpstring")==false)) {
throwErr(&ft,"{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}
char * ____BAH_COMPILER_VAR_716 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("{\n");
;                            
                        ____BAH_COMPILER_VAR_716 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_716+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_716+currStrOff, "{\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_716;
OUTPUT =  OUTPUT->add(OUTPUT, rope(code));
struct Elems* fnElems =  dupElems(elems);
array(struct variable*)* vs =  fnElems->vars;
long int j =  0;
while ((j<len(fn->args))) {

                        if (fn->args->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3019): fn->args[%d] with length %d\n", j, fn->args->length);
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
i =  i + 1;
long int max =  len(l)-1;
while ((i<max)) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3038): l[%d] with length %d\n", i, l->length);
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
i =  i + 1;
};
if ((len(tokens)==0)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope("};\n"));
return;
}
currentFn =  fn;
parseLines(tokens,fnElems);
currentFn =  null;
if ((fn->returned==false)) {
if ((strlen(fn->returns->type)>0)) {
char * ____BAH_COMPILER_VAR_718 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                        ____BAH_COMPILER_VAR_718 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, "Function '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, fn->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, "' is not returned.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_718);
}
endRCPscope(fnElems,null);
}
OUTPUT =  OUTPUT->add(OUTPUT, rope("};\n"));
if ((debug==true)) {
struct debugFunction* df = memoryAlloc(sizeof(struct debugFunction));
df->name= null;
df->returns= null;
df->args = memoryAlloc(sizeof(array(struct variable*)));
            df->args->length = 0;
            df->args->elemSize = sizeof(struct variable*);
            df->name =  fn->name;
df->args =  fn->args;
df->returns =  fn->returns->type;
struct reflectElement ____BAH_COMPILER_VAR_720 = __reflect((char **)((char*)(df) + offsetof(struct debugFunction, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_721 = __reflect((char **)((char*)(df) + offsetof(struct debugFunction, returns)), sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_723 = __reflect((char **)((char*)(0) + offsetof(struct variable, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_724 = __reflect((char **)((char*)(0) + offsetof(struct variable, type)), sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_725 = __reflect((int*)((char*)(0) + offsetof(struct variable, isConst)), sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_726 = __reflect((char **)((char*)(0) + offsetof(struct variable, constVal)), sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_727 = __reflect((int*)((char*)(0) + offsetof(struct variable, isArray)), sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_728 = __reflect((char **)((char*)(0) + offsetof(struct variable, from)), sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_729 = __reflect((int*)((char*)(0) + offsetof(struct variable, outterScope)), sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_722 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_722->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_722->length = 7;
        ____BAH_COMPILER_VAR_722->data = memoryAlloc(____BAH_COMPILER_VAR_722->length * ____BAH_COMPILER_VAR_722->elemSize);
        ____BAH_COMPILER_VAR_722->data[0] = ____BAH_COMPILER_VAR_723;
____BAH_COMPILER_VAR_722->data[1] = ____BAH_COMPILER_VAR_724;
____BAH_COMPILER_VAR_722->data[2] = ____BAH_COMPILER_VAR_725;
____BAH_COMPILER_VAR_722->data[3] = ____BAH_COMPILER_VAR_726;
____BAH_COMPILER_VAR_722->data[4] = ____BAH_COMPILER_VAR_727;
____BAH_COMPILER_VAR_722->data[5] = ____BAH_COMPILER_VAR_728;
____BAH_COMPILER_VAR_722->data[6] = ____BAH_COMPILER_VAR_729;
struct reflectElement ____BAH_COMPILER_VAR_730 = __reflect(0, sizeof(struct variable), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_722, 0);

        struct reflectElement ____BAH_COMPILER_VAR_731 = ____BAH_COMPILER_VAR_730;
        struct reflectElement ____BAH_COMPILER_VAR_732 = __reflect((array(struct variable*)**)((char*)(df) + offsetof(struct debugFunction, args)), sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_731, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_719 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_719->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_719->length = 3;
        ____BAH_COMPILER_VAR_719->data = memoryAlloc(____BAH_COMPILER_VAR_719->length * ____BAH_COMPILER_VAR_719->elemSize);
        ____BAH_COMPILER_VAR_719->data[0] = ____BAH_COMPILER_VAR_720;
____BAH_COMPILER_VAR_719->data[1] = ____BAH_COMPILER_VAR_721;
____BAH_COMPILER_VAR_719->data[2] = ____BAH_COMPILER_VAR_732;
struct reflectElement ____BAH_COMPILER_VAR_733 = __reflect(df, sizeof(struct debugFunction), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_719, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_733);

                        if (l->length <= len(l)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3067): l[%d] with length %d\n", len(l)-1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3118): line[%d] with length %d\n", 0, line->length);
                            exit(1);
                        };
                        struct Tok ft =  line->data[0];
parsed =  true;
char * ____BAH_COMPILER_VAR_737 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_737 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_737+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_737+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_737));
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3148): line[%d] with length %d\n", 0, line->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3167): tokens[%d] with length %d\n", 0, tokens->length);
                            exit(1);
                        };
                        struct Tok ft =  tokens->data[0];
long int currentLine =  ft.line;
long int nbEncl =  0;
long int i =  0;
while ((i<len(tokens))) {

                        if (tokens->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3171): tokens[%d] with length %d\n", i, tokens->length);
                            exit(1);
                        };
                        struct Tok t =  tokens->data[i];
if ((t.type==TOKEN_TYPE_ENCL)) {
if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3174 t.cont ")==1&&strcmp(t.cont, "(") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3176 t.cont ")==1&&strcmp(t.cont, ")") == 0)) {
nbEncl =  nbEncl - 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3178 t.cont ")==1&&strcmp(t.cont, "{") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3180 t.cont ")==1&&strcmp(t.cont, "}") == 0)) {
nbEncl =  nbEncl - 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3182 t.cont ")==1&&strcmp(t.cont, "[") == 0)) {
nbEncl =  nbEncl + 1;
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3184 t.cont ")==1&&strcmp(t.cont, "]") == 0)) {
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3197): tokens[%d] with length %d\n", i-1, tokens->length);
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
i =  i + 1;
continue;
}
}
else if ((__checkString(t.cont, "/home/alois/Documents/bah-bah/src/parser.bah:3208 t.cont ")==1&&strcmp(t.cont, ";") == 0)) {
currentLine =  t.line;
parseLine(line,elems);
clear(line);
i =  i + 1;
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
i =  i + 1;
};
if ((len(line)>0)) {
if ((nbEncl==0)) {
parseLine(line,elems);
clear(line);
}
else {

                        if (line->length <= len(line)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3226): line[%d] with length %d\n", len(line)-1, line->length);
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
char * ____BAH_COMPILER_VAR_739 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_740 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_739);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(arg->name);
;                            
                        ____BAH_COMPILER_VAR_740 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_740+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_740+currStrOff, ____BAH_COMPILER_VAR_739, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_740+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_740+currStrOff, arg->name, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_740;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_741 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(", ");
;                            
                        ____BAH_COMPILER_VAR_741 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_741+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_741+currStrOff, ", ", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_741;
}
};
char * ____BAH_COMPILER_VAR_742 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_743 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_742);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(fn->name);
long int strLen_3 = strlen("(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_743 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_743+currStrOff, ____BAH_COMPILER_VAR_742, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_743+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_743+currStrOff, fn->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_743+currStrOff, "(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_743+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_743+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_743));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_744 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->constVal);
long int strLen_4 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_744 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_744+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_744+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_744+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_744+currStrOff, v->constVal, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_744+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_744));
}
else {
struct string cType =  getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_745 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_746 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_745);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_746 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_746+currStrOff, ____BAH_COMPILER_VAR_745, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_746+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_746+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_746+currStrOff, ";\n", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_746));
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
                        char * ____BAH_COMPILER_VAR_747 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(compilerState.cIncludes->data[i]);
long int strLen_2 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_747 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_747+currStrOff, "#include ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_747+currStrOff, compilerState.cIncludes->data[i], strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_747+currStrOff, "\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_747));
};
i =  0;
for (; (i<len(elems->vars)); i =  i+1) {

                        if (elems->vars->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:46): elems->vars[%d] with length %d\n", i, elems->vars->length);
                            exit(1);
                        };
                        struct variable* v =  elems->vars->data[i];
declareVar(v,elems);
};
i =  0;
for (; (i<len(elems->fns)); i =  i+1) {

                        if (elems->fns->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/declarative.bah:51): elems->fns[%d] with length %d\n", i, elems->fns->length);
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
struct flags ____BAH_COMPILER_VAR_748 = {};
____BAH_COMPILER_VAR_748.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_748.flags->length = 0;
            ____BAH_COMPILER_VAR_748.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_748.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_748.args->length = 0;
            ____BAH_COMPILER_VAR_748.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_748.addString = flags__addString;
____BAH_COMPILER_VAR_748.addBool = flags__addBool;
____BAH_COMPILER_VAR_748.addInt = flags__addInt;
____BAH_COMPILER_VAR_748.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_748.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_748.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_748.get = flags__get;
____BAH_COMPILER_VAR_748.getInt = flags__getInt;
____BAH_COMPILER_VAR_748.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_748.isSet = flags__isSet;
____BAH_COMPILER_VAR_748.parse = flags__parse;
flags =  ____BAH_COMPILER_VAR_748;
flags.addString((struct flags*)&flags,"o","Name of the file to output.");
flags.addBool((struct flags*)&flags,"c","Translate bah file to C instead of compiling it.");
flags.addBool((struct flags*)&flags,"v","Show version of the compiler.");
flags.addBool((struct flags*)&flags,"l","Compile as a library.");
flags.addBool((struct flags*)&flags,"d","Compile as a dynamic executable. (useful if you are using a library that is only available shared but might reduce portability).");
flags.addBool((struct flags*)&flags,"rcp","Enables RCP (reference counter) instead of the garbage collector. Warning: if you are using self-reference, this will lead to memory leaks!");
flags.addBool((struct flags*)&flags,"fastrcp","Enables RCP without leak detection. It is recommended to test you programs with the -rcp flag to test for leak detection before using this flag.");
flags.addBool((struct flags*)&flags,"debug","Enables verbose json output.");
flags.parse((struct flags*)&flags,args);
debug =  (flags.isSet((struct flags*)&flags,"debug")==1);
if ((debug==true)) {
debugStart();
}
RCPenabled =  ((flags.isSet((struct flags*)&flags,"rcp")==1)||flags.isSet((struct flags*)&flags,"fastrcp"));
if ((flags.isSet((struct flags*)&flags,"v")==1)) {
char * ____BAH_COMPILER_VAR_749 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Bah compiler version: ");
long int strLen_1 = strlen(BAH_VERSION);
long int strLen_2 = strlen(".\n© Alois Laurent Boe");
;                            
                        ____BAH_COMPILER_VAR_749 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_749+currStrOff, "Bah compiler version: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_749+currStrOff, BAH_VERSION, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_749+currStrOff, ".\n© Alois Laurent Boe", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    println(____BAH_COMPILER_VAR_749);
long int ____BAH_COMPILER_VAR_750 = 0;
return ____BAH_COMPILER_VAR_750;
}
if (((flags.isSet((struct flags*)&flags,"c")==1)&&(flags.isSet((struct flags*)&flags,"l")==1))) {
panic("Cannot use -c (to translate to C code) and -l (to compile as a library) at the same time.");
}
INIT =  rope("");
OUTPUT =  rope("\nvoid __BAH_init();\n#define noCheck(v) v\n#define array(type)	\
struct{	\
type *data; \
long int length; \
long int elemSize; \
}\ntypedef array(char*)* __BAH_ARR_TYPE_cpstring;\nlong int __BAH__main(__BAH_ARR_TYPE_cpstring);\n");
if ((flags.isSet((struct flags*)&flags,"l")==0)) {
if ((RCPenabled==true)) {
OUTPUT =  OUTPUT->add(OUTPUT, rope("\n        int main(int argc, char ** argv) {\n        RCP_init();\n        array(char*) * args = malloc(sizeof(array(char*)));\n        args->data = malloc(sizeof(char*)*argc);\n        memcpy(args->data, argv, sizeof(char*)*argc);\n        args->elemSize = sizeof(char*);\n        args->length = argc;\n        __BAH_init();\n        long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n        free(args->data);\n        free(args);\n        RCP_shutdown();\n        return r;\n        };\n        #define main(v) __BAH__main(v)\n        "));
}
else {
char * ____BAH_COMPILER_VAR_751 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n        #include \"");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen("libs/include/gc.h\"\n        int main(int argc, char ** argv) {\n        GC_INIT();\n        array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n        args->data = GC_MALLOC(sizeof(char*)*argc);\n        memcpy(args->data, argv, sizeof(char*)*argc);\n        args->elemSize = sizeof(char*);\n        args->length = argc;\n        __BAH_init();\n        long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n        GC_FREE(args->data);\n        GC_FREE(args);\n        return r;\n        };\n        #define main(v) __BAH__main(v)\n        ");
;                            
                        ____BAH_COMPILER_VAR_751 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_751+currStrOff, "\n        #include \"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_751+currStrOff, BAH_DIR, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_751+currStrOff, "libs/include/gc.h\"\n        int main(int argc, char ** argv) {\n        GC_INIT();\n        array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n        args->data = GC_MALLOC(sizeof(char*)*argc);\n        memcpy(args->data, argv, sizeof(char*)*argc);\n        args->elemSize = sizeof(char*);\n        args->length = argc;\n        __BAH_init();\n        long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n        GC_FREE(args->data);\n        GC_FREE(args);\n        return r;\n        };\n        #define main(v) __BAH__main(v)\n        ", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_751));
}
}
struct compilerStateTag ____BAH_COMPILER_VAR_752 = {};
____BAH_COMPILER_VAR_752.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_752.includes->length = 0;
            ____BAH_COMPILER_VAR_752.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_752.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_752.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_752.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_752.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_752.cLibs->length = 0;
            ____BAH_COMPILER_VAR_752.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_752.currentFile= null;
____BAH_COMPILER_VAR_752.currentDir = "./";
____BAH_COMPILER_VAR_752.isBranch = false;
____BAH_COMPILER_VAR_752.isFor = false;
____BAH_COMPILER_VAR_752.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_752.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_752.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_752.haveEntryPoint = false;
____BAH_COMPILER_VAR_752.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_752.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_752.RCPvars->elemSize = sizeof(struct variable*);
            compilerState =  ____BAH_COMPILER_VAR_752;

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
struct fileMap ____BAH_COMPILER_VAR_753 = {};
____BAH_COMPILER_VAR_753.open = fileMap__open;
____BAH_COMPILER_VAR_753.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_753.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_753;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_754 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Could not open file '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_754 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_754+currStrOff, "Could not open file '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_754+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_754+currStrOff, "'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_754);
}
long int startTime =  getTimeUnix();
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_755 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("' not recognized.");
;                            
                        ____BAH_COMPILER_VAR_755 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_755+currStrOff, "File '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_755+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_755+currStrOff, "' not recognized.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_755);
}
struct Elems* elems = memoryAlloc(sizeof(struct Elems));
elems->vars = memoryAlloc(sizeof(array(struct variable*)));
            elems->vars->length = 0;
            elems->vars->elemSize = sizeof(struct variable*);
            elems->structs = memoryAlloc(sizeof(array(struct cStruct*)));
            elems->structs->length = 0;
            elems->structs->elemSize = sizeof(struct cStruct*);
            elems->types = memoryAlloc(sizeof(array(char *)));
            elems->types->length = 0;
            elems->types->elemSize = sizeof(char *);
            elems->fns = memoryAlloc(sizeof(array(struct func*)));
            elems->fns->length = 0;
            elems->fns->elemSize = sizeof(struct func*);
            if ((includeFile("builtin.bah",elems)==false)) {
char * ____BAH_COMPILER_VAR_756 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Could not find std-libs, please check '");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_756 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_756+currStrOff, "Could not find std-libs, please check '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_756+currStrOff, BAH_DIR, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_756+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_756);
}
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
OUTPUT =  rope("");
declareAll(elems);
}
compilerState.currentDir =  getDirFromFile(fileName);
parseLines(tokens,elems);
makeInit();
if ((debug==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_757 =intToStr(totalLines);char * ____BAH_COMPILER_VAR_758 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_759 =intToStr(totalLexerTime / 1000000);char * ____BAH_COMPILER_VAR_760 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Parsed. (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_757);
long int strLen_2 = strlen(" lines, total time: ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_758);
long int strLen_4 = strlen("ms, lexer time: ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_759);
long int strLen_6 = strlen("ms)\e[0m");
;                            
                        ____BAH_COMPILER_VAR_760 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_760+currStrOff, "Parsed. (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_760+currStrOff, ____BAH_COMPILER_VAR_757, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_760+currStrOff, " lines, total time: ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_760+currStrOff, ____BAH_COMPILER_VAR_758, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_760+currStrOff, "ms, lexer time: ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_760+currStrOff, ____BAH_COMPILER_VAR_759, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_760+currStrOff, "ms)\e[0m", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    println(____BAH_COMPILER_VAR_760);
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
if ((flags.isSet((struct flags*)&flags,"d")==1)) {
isStatic =  "";
}
if ((flags.isSet((struct flags*)&flags,"c")==0)) {
char * randFileName =  "TMP_C_FILE_";
long int i =  0;
while ((i<9)) {
long int nb =  randomInRange(0,99);
char * s =  intToStr(nb);
char * ____BAH_COMPILER_VAR_761 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(randFileName);
long int strLen_1 = strlen(s);
;                            
                        ____BAH_COMPILER_VAR_761 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_761+currStrOff, randFileName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_761+currStrOff, s, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    randFileName =  ____BAH_COMPILER_VAR_761;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_762 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(randFileName);
long int strLen_1 = strlen(".c");
;                            
                        ____BAH_COMPILER_VAR_762 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_762+currStrOff, randFileName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_762+currStrOff, ".c", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    randFileName =  ____BAH_COMPILER_VAR_762;
struct fileStream ____BAH_COMPILER_VAR_763 = {};
____BAH_COMPILER_VAR_763.handle= null;
____BAH_COMPILER_VAR_763.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_763.open = fileStream__open;
____BAH_COMPILER_VAR_763.close = fileStream__close;
____BAH_COMPILER_VAR_763.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_763.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_763.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_763.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_763.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_763.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_763.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_763.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_763.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_763.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_763.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_763.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_763.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_763;
fs.open((struct fileStream*)&fs,randFileName,"w");
char * ____BAH_COMPILER_VAR_764 =OUTPUT->toStr((struct rope*)OUTPUT);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_764);
fs.close((struct fileStream*)&fs);
char * ____BAH_COMPILER_VAR_765 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("gcc ");
long int strLen_1 = strlen(randFileName);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(isStatic);
long int strLen_4 = strlen(" -w -O1 -o ");
long int strLen_5 = strlen(fileName);
;                            
                        ____BAH_COMPILER_VAR_765 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_765+currStrOff, "gcc ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_765+currStrOff, randFileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_765+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_765+currStrOff, isStatic, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_765+currStrOff, " -w -O1 -o ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_765+currStrOff, fileName, strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    char * gccArgs =  ____BAH_COMPILER_VAR_765;
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_766 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -c");
;                            
                        ____BAH_COMPILER_VAR_766 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_766+currStrOff, gccArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_766+currStrOff, " -c", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    gccArgs =  ____BAH_COMPILER_VAR_766;
}
array(char *)* cLibs =  compilerState.cLibs;
i =  0;
while ((i<len(cLibs))) {

                        if (cLibs->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/main_linux.bah:191): cLibs[%d] with length %d\n", i, cLibs->length);
                            exit(1);
                        };
                        char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_767 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                        ____BAH_COMPILER_VAR_767 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_767+currStrOff, gccArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_767+currStrOff, " -", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_767+currStrOff, l, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    gccArgs =  ____BAH_COMPILER_VAR_767;
i =  i + 1;
};
struct command cmd =  command(gccArgs);
cmd.error =  false;
cmd.run((struct command*)&cmd);
removeFile(randFileName);
if ((cmd.status!=0)) {
println("\e[1;31m[GCC-ERROR]\e[0m\nCould not compiled.");
exit(1);
}
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_768 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("ar rcs ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(".a ");
long int strLen_3 = strlen(fileName);
;                            
                        ____BAH_COMPILER_VAR_768 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_768+currStrOff, "ar rcs ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_768+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_768+currStrOff, ".a ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_768+currStrOff, fileName, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    cmd =  command(____BAH_COMPILER_VAR_768);
cmd.run((struct command*)&cmd);
}
}
else {
if ((flags.isSet((struct flags*)&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_769 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".c");
;                            
                        ____BAH_COMPILER_VAR_769 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_769+currStrOff, fileName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_769+currStrOff, ".c", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fileName =  ____BAH_COMPILER_VAR_769;
}
char * ____BAH_COMPILER_VAR_770 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("gcc ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(isStatic);
long int strLen_4 = strlen(" -O1 -w ");
;                            
                        ____BAH_COMPILER_VAR_770 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_770+currStrOff, "gcc ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_770+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_770+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_770+currStrOff, isStatic, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_770+currStrOff, " -O1 -w ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    char * gccArgs =  ____BAH_COMPILER_VAR_770;
array(char *)* cLibs =  compilerState.cLibs;
long int i =  0;
while ((i<len(cLibs))) {

                        if (cLibs->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/main_linux.bah:218): cLibs[%d] with length %d\n", i, cLibs->length);
                            exit(1);
                        };
                        char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_771 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                        ____BAH_COMPILER_VAR_771 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_771+currStrOff, gccArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_771+currStrOff, " -", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_771+currStrOff, l, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    gccArgs =  ____BAH_COMPILER_VAR_771;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_772 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("//COMPILE WITH: '");
long int strLen_1 = strlen(gccArgs);
long int strLen_2 = strlen("'\n");
;                            
                        ____BAH_COMPILER_VAR_772 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_772+currStrOff, "//COMPILE WITH: '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_772+currStrOff, gccArgs, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_772+currStrOff, "'\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* ____BAH_COMPILER_VAR_773 =rope(____BAH_COMPILER_VAR_772);OUTPUT =  concatenateRopes(____BAH_COMPILER_VAR_773,OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_774 = {};
____BAH_COMPILER_VAR_774.handle= null;
____BAH_COMPILER_VAR_774.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_774.open = fileStream__open;
____BAH_COMPILER_VAR_774.close = fileStream__close;
____BAH_COMPILER_VAR_774.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_774.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_774.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_774.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_774.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_774.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_774.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_774.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_774.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_774.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_774.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_774.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_774.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_774;
fs.open((struct fileStream*)&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_775 =OUTPUT->toStr((struct rope*)OUTPUT);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_775);
fs.close((struct fileStream*)&fs);
}
if ((debug==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_776 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_777 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;32mDone. (compiled in ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_776);
long int strLen_2 = strlen("ms)\e[0m");
;                            
                        ____BAH_COMPILER_VAR_777 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_777+currStrOff, "\e[1;32mDone. (compiled in ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_777+currStrOff, ____BAH_COMPILER_VAR_776, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_777+currStrOff, "ms)\e[0m", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    println(____BAH_COMPILER_VAR_777);
}
else {
debugEnd();
}
long int ____BAH_COMPILER_VAR_778 = 0;
return ____BAH_COMPILER_VAR_778;
};

    void __BAH_init() {

        RAND_SEEDED =  0;
debug =  false;
NEXT_LINE =  "";
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

keywords->length = 19;
keywords->elemSize = sizeof(char *);
keywords->data = memoryAlloc(sizeof(char *) * 50);keywords->data[0] = __STR("if");
keywords->data[1] = __STR("else");
keywords->data[2] = __STR("for");
keywords->data[3] = __STR("struct");
keywords->data[4] = __STR("const");
keywords->data[5] = __STR("return");
keywords->data[6] = __STR("extend");
keywords->data[7] = __STR("new");
keywords->data[8] = __STR("break");
keywords->data[9] = __STR("continue");
keywords->data[10] = __STR("default");
keywords->data[11] = __STR("switch");
keywords->data[12] = __STR("case");
keywords->data[13] = __STR("while");
keywords->data[14] = __STR("typedef");
keywords->data[15] = __STR("function");
keywords->data[16] = __STR("async");
keywords->data[17] = __STR("in");
keywords->data[18] = __STR("chan");
varChars = memoryAlloc(sizeof(array(char)));

varChars->length = 1;
varChars->elemSize = sizeof(char);
varChars->data = memoryAlloc(sizeof(char) * 50);varChars->data[0] = 95;
seps = memoryAlloc(sizeof(array(char)));

seps->length = 1;
seps->elemSize = sizeof(char);
seps->data = memoryAlloc(sizeof(char) * 50);seps->data[0] = 46;
NB_COMP_VAR =  0;
prevLine =  (lineType)-1;
signs = memoryAlloc(sizeof(array(char *)));

signs->length = 7;
signs->elemSize = sizeof(char *);
signs->data = memoryAlloc(sizeof(char *) * 50);signs->data[0] = __STR("|");
signs->data[1] = __STR("&");
signs->data[2] = __STR("%");
signs->data[3] = __STR("+");
signs->data[4] = __STR("-");
signs->data[5] = __STR("*");
signs->data[6] = __STR("/");
comparators = memoryAlloc(sizeof(array(char *)));

comparators->length = 7;
comparators->elemSize = sizeof(char *);
comparators->data = memoryAlloc(sizeof(char *) * 50);comparators->data[0] = __STR("==");
comparators->data[1] = __STR("!=");
comparators->data[2] = __STR(">");
comparators->data[3] = __STR("<");
comparators->data[4] = __STR("<=");
comparators->data[5] = __STR(">=");
comparators->data[6] = __STR("in");
compSep = memoryAlloc(sizeof(array(char *)));

compSep->length = 2;
compSep->elemSize = sizeof(char *);
compSep->data = memoryAlloc(sizeof(char *) * 50);compSep->data[0] = __STR("||");
compSep->data[1] = __STR("&&");


    };
    