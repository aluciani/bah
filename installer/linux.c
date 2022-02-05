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
char ____BAH_COMPILER_VAR_14 = c;
return ____BAH_COMPILER_VAR_14;
};
char * charToString(char c){
char * s =  memoryAlloc(2);
strncpy(s,(char *)&c,1);
char * ____BAH_COMPILER_VAR_15 = s;
return ____BAH_COMPILER_VAR_15;
};
long int isUpper(char c){
if ((c>(char)64)) {
if ((c<(char)91)) {
long int ____BAH_COMPILER_VAR_16 = 1;
return ____BAH_COMPILER_VAR_16;
}
}
long int ____BAH_COMPILER_VAR_17 = 0;
return ____BAH_COMPILER_VAR_17;
};
long int isLower(char c){
if ((c>(char)96)) {
if ((c<(char)123)) {
long int ____BAH_COMPILER_VAR_18 = 1;
return ____BAH_COMPILER_VAR_18;
}
}
long int ____BAH_COMPILER_VAR_19 = 0;
return ____BAH_COMPILER_VAR_19;
};
long int isLetter(char s){
if (isUpper(s)) {
long int ____BAH_COMPILER_VAR_20 = 1;
return ____BAH_COMPILER_VAR_20;
}
if (isLower(s)) {
long int ____BAH_COMPILER_VAR_21 = 1;
return ____BAH_COMPILER_VAR_21;
}
long int ____BAH_COMPILER_VAR_22 = 0;
return ____BAH_COMPILER_VAR_22;
};
long int isNumber(char c){
if ((c>(char)47)) {
if ((c<(char)58)) {
long int ____BAH_COMPILER_VAR_23 = 1;
return ____BAH_COMPILER_VAR_23;
}
}
long int ____BAH_COMPILER_VAR_24 = 0;
return ____BAH_COMPILER_VAR_24;
};
long int isAlphaNumeric(char s){
if (isLetter(s)) {
long int ____BAH_COMPILER_VAR_25 = 1;
return ____BAH_COMPILER_VAR_25;
}
if (isNumber(s)) {
long int ____BAH_COMPILER_VAR_26 = 1;
return ____BAH_COMPILER_VAR_26;
}
long int ____BAH_COMPILER_VAR_27 = 0;
return ____BAH_COMPILER_VAR_27;
};
long int isSpace(char c){
if ((c==(char)32)) {
long int ____BAH_COMPILER_VAR_28 = 1;
return ____BAH_COMPILER_VAR_28;
}
if ((c==(char)9)) {
long int ____BAH_COMPILER_VAR_29 = 1;
return ____BAH_COMPILER_VAR_29;
}
if ((c==(char)10)) {
long int ____BAH_COMPILER_VAR_30 = 1;
return ____BAH_COMPILER_VAR_30;
}
if ((c==(char)11)) {
long int ____BAH_COMPILER_VAR_31 = 1;
return ____BAH_COMPILER_VAR_31;
}
if ((c==(char)13)) {
long int ____BAH_COMPILER_VAR_32 = 1;
return ____BAH_COMPILER_VAR_32;
}
long int ____BAH_COMPILER_VAR_33 = 0;
return ____BAH_COMPILER_VAR_33;
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
char ____BAH_COMPILER_VAR_34 = c;
return ____BAH_COMPILER_VAR_34;
}
char ____BAH_COMPILER_VAR_35 = c;
return ____BAH_COMPILER_VAR_35;
};
long int string__compare(struct string* this,char * s){
long int r =  strcmp(this->content,s);
if ((r==0)) {
long int ____BAH_COMPILER_VAR_36 = 1;
return ____BAH_COMPILER_VAR_36;
}
long int ____BAH_COMPILER_VAR_37 = 0;
return ____BAH_COMPILER_VAR_37;
};
char * string__str(struct string* this){
char * s =  this->content;
char * ____BAH_COMPILER_VAR_38 = s;
return ____BAH_COMPILER_VAR_38;
};
void string__replace(struct string* this,char * nd,char * rl){
struct string ____BAH_COMPILER_VAR_39 = {};
____BAH_COMPILER_VAR_39.content= null;
____BAH_COMPILER_VAR_39.set = string__set;
____BAH_COMPILER_VAR_39.append = string__append;
____BAH_COMPILER_VAR_39.prepend = string__prepend;
____BAH_COMPILER_VAR_39.charAt = string__charAt;
____BAH_COMPILER_VAR_39.compare = string__compare;
____BAH_COMPILER_VAR_39.str = string__str;
____BAH_COMPILER_VAR_39.replace = string__replace;
struct string needle =  ____BAH_COMPILER_VAR_39;
needle.set((struct string*)&needle,nd);
struct string ____BAH_COMPILER_VAR_40 = {};
____BAH_COMPILER_VAR_40.content= null;
____BAH_COMPILER_VAR_40.set = string__set;
____BAH_COMPILER_VAR_40.append = string__append;
____BAH_COMPILER_VAR_40.prepend = string__prepend;
____BAH_COMPILER_VAR_40.charAt = string__charAt;
____BAH_COMPILER_VAR_40.compare = string__compare;
____BAH_COMPILER_VAR_40.str = string__str;
____BAH_COMPILER_VAR_40.replace = string__replace;
struct string repl =  ____BAH_COMPILER_VAR_40;
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
char * ____BAH_COMPILER_VAR_41 =arrAsStr(replbuffStr);char * ____BAH_COMPILER_VAR_42 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(r);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_41);
;                            
                        ____BAH_COMPILER_VAR_42 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_42+currStrOff, r, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_42+currStrOff, ____BAH_COMPILER_VAR_41, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    r =  ____BAH_COMPILER_VAR_42;
}
if (((void *)r!=null)) {
this->set((struct string*)this,r);
}
};
long int string__count(struct string* this,char * need){
long int i =  0;
long int count =  0;
struct string ____BAH_COMPILER_VAR_43 = {};
____BAH_COMPILER_VAR_43.content= null;
____BAH_COMPILER_VAR_43.set = string__set;
____BAH_COMPILER_VAR_43.append = string__append;
____BAH_COMPILER_VAR_43.prepend = string__prepend;
____BAH_COMPILER_VAR_43.charAt = string__charAt;
____BAH_COMPILER_VAR_43.compare = string__compare;
____BAH_COMPILER_VAR_43.str = string__str;
____BAH_COMPILER_VAR_43.replace = string__replace;
____BAH_COMPILER_VAR_43.count = string__count;
struct string needle =  ____BAH_COMPILER_VAR_43;
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
long int ____BAH_COMPILER_VAR_44 = count;
return ____BAH_COMPILER_VAR_44;
};
long int string__hasPrefix(struct string* this,char * need){
long int i =  0;
long int nl =  strlen(need);
if ((this->length<nl)) {
long int ____BAH_COMPILER_VAR_45 = 0;
return ____BAH_COMPILER_VAR_45;
}
while ((i<nl)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,i);
if ((c!=sc)) {
long int ____BAH_COMPILER_VAR_46 = 0;
return ____BAH_COMPILER_VAR_46;
}
i =  i + 1;
};
long int ____BAH_COMPILER_VAR_47 = 1;
return ____BAH_COMPILER_VAR_47;
};
long int string__hasSuffix(struct string* this,char * need){
long int nl =  strlen(need);
if ((this->length<nl)) {
long int ____BAH_COMPILER_VAR_48 = 0;
return ____BAH_COMPILER_VAR_48;
}
long int i =  this->length - nl;
long int needleIndex =  0;
while ((i<this->length)) {
char c =  this->charAt((struct string*)this,i);
char sc =  cpstringCharAt(need,needleIndex);
if ((c!=sc)) {
long int ____BAH_COMPILER_VAR_49 = 0;
return ____BAH_COMPILER_VAR_49;
}
needleIndex =  needleIndex + 1;
i =  i + 1;
};
long int ____BAH_COMPILER_VAR_50 = 1;
return ____BAH_COMPILER_VAR_50;
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
struct string ____BAH_COMPILER_VAR_53 = {};
____BAH_COMPILER_VAR_53.content= null;
____BAH_COMPILER_VAR_53.set = string__set;
____BAH_COMPILER_VAR_53.append = string__append;
____BAH_COMPILER_VAR_53.prepend = string__prepend;
____BAH_COMPILER_VAR_53.charAt = string__charAt;
____BAH_COMPILER_VAR_53.compare = string__compare;
____BAH_COMPILER_VAR_53.str = string__str;
____BAH_COMPILER_VAR_53.replace = string__replace;
____BAH_COMPILER_VAR_53.count = string__count;
____BAH_COMPILER_VAR_53.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_53.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_53.trim = string__trim;
____BAH_COMPILER_VAR_53.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_53.trimRight = string__trimRight;
____BAH_COMPILER_VAR_53.add = string__add;
struct string r =  ____BAH_COMPILER_VAR_53;
r.length =  this->length + s2.length;
r.content =  memoryAlloc(r.length + 1);
strncpy(r.content,this->content,this->length);
strCatOffset(r.content,this->length,s2.content,s2.length);
struct string ____BAH_COMPILER_VAR_54 = r;
return ____BAH_COMPILER_VAR_54;
};
struct string string(char * s){
struct string ____BAH_COMPILER_VAR_55 = {};
____BAH_COMPILER_VAR_55.content= null;
____BAH_COMPILER_VAR_55.set = string__set;
____BAH_COMPILER_VAR_55.append = string__append;
____BAH_COMPILER_VAR_55.prepend = string__prepend;
____BAH_COMPILER_VAR_55.charAt = string__charAt;
____BAH_COMPILER_VAR_55.compare = string__compare;
____BAH_COMPILER_VAR_55.str = string__str;
____BAH_COMPILER_VAR_55.replace = string__replace;
____BAH_COMPILER_VAR_55.count = string__count;
____BAH_COMPILER_VAR_55.hasPrefix = string__hasPrefix;
____BAH_COMPILER_VAR_55.hasSuffix = string__hasSuffix;
____BAH_COMPILER_VAR_55.trim = string__trim;
____BAH_COMPILER_VAR_55.trimLeft = string__trimLeft;
____BAH_COMPILER_VAR_55.trimRight = string__trimRight;
____BAH_COMPILER_VAR_55.add = string__add;
struct string a =  ____BAH_COMPILER_VAR_55;
a.set((struct string*)&a,s);
struct string ____BAH_COMPILER_VAR_56 = a;
return ____BAH_COMPILER_VAR_56;
};
char * arrToStr(__BAH_ARR_TYPE_char arr){
long int strLen =  len(arr);
char * str =  memoryAlloc(strLen + 1);
noCheck( memcpy ( str , arr -> data , strLen ) );
char * ____BAH_COMPILER_VAR_57 = str;
return ____BAH_COMPILER_VAR_57;
};
__BAH_ARR_TYPE_char strToArr(char * str){
long int strLen =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> data = memoryAlloc ( strLen + 1 ) );
noCheck( memcpy ( arr -> data , str , strLen ) );
noCheck( arr -> length = strLen );
array(char)* ____BAH_COMPILER_VAR_58 = arr;
return ____BAH_COMPILER_VAR_58;
};
char * arrAsStr(__BAH_ARR_TYPE_char arr){
char * ____BAH_COMPILER_VAR_59 = noCheck( arr -> data );
return ____BAH_COMPILER_VAR_59;
};
__BAH_ARR_TYPE_char strAsArr(char * str){
long int l =  strlen(str);
array(char)* arr = memoryAlloc(sizeof(array(char)));

arr->length = 0;
arr->elemSize = sizeof(char);
noCheck( arr -> length = l );
noCheck( arr -> data = str );
array(char)* ____BAH_COMPILER_VAR_60 = arr;
return ____BAH_COMPILER_VAR_60;
};
char * intToStr(long int i){
if ((i==0)) {
char * ____BAH_COMPILER_VAR_61 = "0";
return ____BAH_COMPILER_VAR_61;
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
char * ____BAH_COMPILER_VAR_62 = arrAsStr(s);
return ____BAH_COMPILER_VAR_62;
};
struct string intToString(long int i){
char * ____BAH_COMPILER_VAR_63 =intToStr(i);struct string r =  string(____BAH_COMPILER_VAR_63);
struct string ____BAH_COMPILER_VAR_64 = r;
return ____BAH_COMPILER_VAR_64;
};
char * floatToStr(double f){
char * buff =  memoryAlloc(50);
sprintf(buff,"%lf",f);
char * ____BAH_COMPILER_VAR_65 = buff;
return ____BAH_COMPILER_VAR_65;
};
long int strToInt(char * s){
long int ____BAH_COMPILER_VAR_66 = atol(s);
return ____BAH_COMPILER_VAR_66;
};
double strToFloat(char * s){
double ____BAH_COMPILER_VAR_67 = strtod(s,null);
return ____BAH_COMPILER_VAR_67;
};
long int stringToInt(struct string s){
long int i =  atol(s.content);
long int ____BAH_COMPILER_VAR_68 = i;
return ____BAH_COMPILER_VAR_68;
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
char * ____BAH_COMPILER_VAR_69 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_69);
}
else {
if ((sepIndex>0)) {
sepIndex =  0;
char * ____BAH_COMPILER_VAR_70 =charToString(c);replcBuff.append((struct string*)&replcBuff,____BAH_COMPILER_VAR_70);
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
char * ____BAH_COMPILER_VAR_71 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_71);
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
char * ____BAH_COMPILER_VAR_72 =arrToStr(tmpString);elem->set((struct string*)elem,____BAH_COMPILER_VAR_72);
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
array(struct string)* ____BAH_COMPILER_VAR_73 = res;
return ____BAH_COMPILER_VAR_73;
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
char * ____BAH_COMPILER_VAR_74 =e.str((struct string*)&e);struct string tmpS =  string(____BAH_COMPILER_VAR_74);
if ((i!=max)) {
tmpS.append((struct string*)&tmpS,sep);
}
char * ____BAH_COMPILER_VAR_75 =tmpS.str((struct string*)&tmpS);s.append((struct string*)&s,____BAH_COMPILER_VAR_75);
i =  i + 1;
};
struct string ____BAH_COMPILER_VAR_76 = s;
return ____BAH_COMPILER_VAR_76;
};
char * splitStringBefore(struct string s,char * sp){
struct string sep =  string(sp);
if ((sep.length>=s.length)) {
char * ____BAH_COMPILER_VAR_77 = "";
return ____BAH_COMPILER_VAR_77;
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
char * ____BAH_COMPILER_VAR_78 = s.str((struct string*)&s);
return ____BAH_COMPILER_VAR_78;
}
}
else {
foundIndex =  0;
sepIndex =  0;
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_79 = "";
return ____BAH_COMPILER_VAR_79;
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
char * ____BAH_COMPILER_VAR_80 =arrToStr(ns);struct string ____BAH_COMPILER_VAR_81 = string(____BAH_COMPILER_VAR_80);
return ____BAH_COMPILER_VAR_81;
};
int strHasPrefix(char * s,char * need){
long int i =  0;
long int nl =  strlen(need);
long int sl =  strlen(s);
if ((sl<nl)) {
int ____BAH_COMPILER_VAR_82 = false;
return ____BAH_COMPILER_VAR_82;
}
while ((i<nl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
int ____BAH_COMPILER_VAR_83 = false;
return ____BAH_COMPILER_VAR_83;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_84 = true;
return ____BAH_COMPILER_VAR_84;
};
int strHasSuffix(char * s,char * need){
long int sl =  strlen(s);
long int nl =  strlen(need);
if ((nl>sl)) {
int ____BAH_COMPILER_VAR_85 = false;
return ____BAH_COMPILER_VAR_85;
}
long int i =  sl - nl;
while ((i<sl)) {
if ((cpstringCharAt(s,i)!=cpstringCharAt(need,i))) {
int ____BAH_COMPILER_VAR_86 = false;
return ____BAH_COMPILER_VAR_86;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_87 = true;
return ____BAH_COMPILER_VAR_87;
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
long int ____BAH_COMPILER_VAR_88 = count;
return ____BAH_COMPILER_VAR_88;
};
char * stdinput(long int len){
char * buff =  memoryAlloc(len);
fgets(buff,len,noCheck( stdin ));
char * ____BAH_COMPILER_VAR_89 = buff;
return ____BAH_COMPILER_VAR_89;
};
void println(char * s){
char * ____BAH_COMPILER_VAR_90 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_90 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_90+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_90+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    write((void *)1,____BAH_COMPILER_VAR_90,strlen(s) + 1);
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
long int ____BAH_COMPILER_VAR_91 = 0;
return ____BAH_COMPILER_VAR_91;
}
long int ____BAH_COMPILER_VAR_92 = 1;
return ____BAH_COMPILER_VAR_92;
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
long int ____BAH_COMPILER_VAR_94 = 0;
return ____BAH_COMPILER_VAR_94;
}
long int ____BAH_COMPILER_VAR_95 = ftell(this->handle);
return ____BAH_COMPILER_VAR_95;
};
void fileStream__setPos(struct fileStream* this,long int i){
if ((this->isValid((struct fileStream*)this)==0)) {
return;
}
fseek(this->handle,i,0);
};
long int fileStream__getSize(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
long int ____BAH_COMPILER_VAR_97 = -1;
return ____BAH_COMPILER_VAR_97;
}
long int oldPos =  this->getPos((struct fileStream*)this);
fseek(this->handle,0,2);
long int size =  ftell(this->handle);
this->setPos((struct fileStream*)this,oldPos);
long int ____BAH_COMPILER_VAR_98 = size;
return ____BAH_COMPILER_VAR_98;
};
void fileStream__rewind(struct fileStream* this){
rewind(this->handle);
};
char fileStream__getChar(struct fileStream* this){
char c =  getc(this->handle);
char ____BAH_COMPILER_VAR_99 = c;
return ____BAH_COMPILER_VAR_99;
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
long int ____BAH_COMPILER_VAR_100 = -1;
return ____BAH_COMPILER_VAR_100;
}
fputs(content,this->handle);
long int ____BAH_COMPILER_VAR_101 = 1;
return ____BAH_COMPILER_VAR_101;
};
void fileStream__writePtr(struct fileStream* this,void * a,long int s){
fwrite(a,s,1,this->handle);
};
long int fileStream__readPtr(struct fileStream* this,void * a,long int s){
long int ____BAH_COMPILER_VAR_102 = fread(a,s,1,this->handle);
return ____BAH_COMPILER_VAR_102;
};
char * fileStream__readContent(struct fileStream* this){
if ((this->isValid((struct fileStream*)this)==0)) {
char * ____BAH_COMPILER_VAR_103 = "invalid";
return ____BAH_COMPILER_VAR_103;
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
char * ____BAH_COMPILER_VAR_104 = r;
return ____BAH_COMPILER_VAR_104;
};
__BAH_ARR_TYPE_char fileStream__readBytes(struct fileStream* this){
array(char)* r = memoryAlloc(sizeof(array(char)));

r->length = 0;
r->elemSize = sizeof(char);
allocateArray(r,this->getSize((struct fileStream*)this));
this->readPtr((struct fileStream*)this,noCheck( r -> data ),len(r));
array(char)* ____BAH_COMPILER_VAR_105 = r;
return ____BAH_COMPILER_VAR_105;
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
struct stat ____BAH_COMPILER_VAR_106 = {};
struct stat sb =  ____BAH_COMPILER_VAR_106;
fstat(this->handle,&sb);
this->size =  sb.st_size;
char * file =  mmap(0,sb.st_size,noCheck( PROT_READ | PROT_WRITE ),noCheck( MAP_SHARED ),this->handle,0);
char * ____BAH_COMPILER_VAR_107 = file;
return ____BAH_COMPILER_VAR_107;
};
long int fileMap__isValid(struct fileMap* this){
if ((this->handle<0)) {
long int ____BAH_COMPILER_VAR_108 = 0;
return ____BAH_COMPILER_VAR_108;
}
long int ____BAH_COMPILER_VAR_109 = 1;
return ____BAH_COMPILER_VAR_109;
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
array(char *)* ____BAH_COMPILER_VAR_110 = files;
return ____BAH_COMPILER_VAR_110;
};
long int fileExists(char * path){
long int is =  access(path,0);
if ((is==0)) {
long int ____BAH_COMPILER_VAR_111 = 1;
return ____BAH_COMPILER_VAR_111;
}
long int ____BAH_COMPILER_VAR_112 = 0;
return ____BAH_COMPILER_VAR_112;
};
int removeFile(char * name){
if ((remove(name)==0)) {
int ____BAH_COMPILER_VAR_113 = true;
return ____BAH_COMPILER_VAR_113;
}
int ____BAH_COMPILER_VAR_114 = false;
return ____BAH_COMPILER_VAR_114;
};
long int getLastModified(char * name){
struct stat attr;
stat(name,&attr);
long int ____BAH_COMPILER_VAR_115 = attr.st_ctime;
return ____BAH_COMPILER_VAR_115;
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
struct flag* ____BAH_COMPILER_VAR_116 = flag;
return ____BAH_COMPILER_VAR_116;
}
i =  i + 1;
};
struct flag* z = memoryAlloc(sizeof(struct flag));
z->name= null;
z->help= null;
z->content= null;
z->isSet =  0;
struct flag* ____BAH_COMPILER_VAR_117 = z;
return ____BAH_COMPILER_VAR_117;
};
char * flags__get(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_118 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_118);
char * ctn =  flag->content;
char * ____BAH_COMPILER_VAR_119 = ctn;
return ____BAH_COMPILER_VAR_119;
};
long int flags__getInt(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_120 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_120);
if ((flag->type!=FLAG_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_121 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not int.");
;                            
                        ____BAH_COMPILER_VAR_121 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_121+currStrOff, "Flag '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_121+currStrOff, flag->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_121+currStrOff, "' is not int.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * error =  ____BAH_COMPILER_VAR_121;
panic(error);
}
long int ctn =  flag->cont_int;
long int ____BAH_COMPILER_VAR_122 = ctn;
return ____BAH_COMPILER_VAR_122;
};
double flags__getFloat(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_123 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_123);
if ((flag->type!=FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_124 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Flag '");
long int strLen_1 = strlen(flag->name);
long int strLen_2 = strlen("' is not float.");
;                            
                        ____BAH_COMPILER_VAR_124 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_124+currStrOff, "Flag '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_124+currStrOff, flag->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_124+currStrOff, "' is not float.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * error =  ____BAH_COMPILER_VAR_124;
panic(error);
}
double ctn =  flag->cont_float;
double ____BAH_COMPILER_VAR_125 = ctn;
return ____BAH_COMPILER_VAR_125;
};
long int flags__isSet(struct flags* this,char * name){
struct string ____BAH_COMPILER_VAR_126 =string(name);struct flag* flag =  this->getFlag((struct flags*)this,____BAH_COMPILER_VAR_126);
long int ctn =  flag->isSet;
long int ____BAH_COMPILER_VAR_127 = ctn;
return ____BAH_COMPILER_VAR_127;
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
char * ____BAH_COMPILER_VAR_128 =argName.str((struct string*)&argName);currentFlag->cont_int =  atoi(____BAH_COMPILER_VAR_128);
}
else if ((currentFlag->type==FLAG_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_129 =argName.str((struct string*)&argName);currentFlag->cont_float =  strtod(____BAH_COMPILER_VAR_129,0);
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
char * ____BAH_COMPILER_VAR_130 = date;
return ____BAH_COMPILER_VAR_130;
};
long int time__since(struct time* this){
long int nt =  time(0);
long int r =  nt - this->timestamp;
long int ____BAH_COMPILER_VAR_131 = r;
return ____BAH_COMPILER_VAR_131;
};
long int getTimeUnix(){
struct timespec ____BAH_COMPILER_VAR_132 = {};
struct timespec ts =  ____BAH_COMPILER_VAR_132;
timespec_get(&ts,noCheck( TIME_UTC ));
long int s =  ts.tv_sec * 1000000000 + ts.tv_nsec;
long int ____BAH_COMPILER_VAR_133 = s;
return ____BAH_COMPILER_VAR_133;
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
long int ____BAH_COMPILER_VAR_134 = i;
return ____BAH_COMPILER_VAR_134;
};
long int cryptoRand(){
struct fileStream ____BAH_COMPILER_VAR_135 = {};
____BAH_COMPILER_VAR_135.handle= null;
____BAH_COMPILER_VAR_135.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_135.open = fileStream__open;
____BAH_COMPILER_VAR_135.close = fileStream__close;
____BAH_COMPILER_VAR_135.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_135.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_135.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_135.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_135.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_135.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_135.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_135.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_135.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_135.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_135.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_135.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_135.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_135;
fs.open((struct fileStream*)&fs,"/dev/urandom","r");
char c =  fs.getChar((struct fileStream*)&fs);
fs.close((struct fileStream*)&fs);
long int i =  (long int)c;
long int ____BAH_COMPILER_VAR_136 = i;
return ____BAH_COMPILER_VAR_136;
};
struct command {
char * command;
int error;
long int status;
FILE* handle;
char *(*run)(struct command* this);
};
char * command__run(struct command* this){
char * cm =  this->command;
if ((this->error==false)) {
char * ____BAH_COMPILER_VAR_137 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>/dev/null");
;                            
                        ____BAH_COMPILER_VAR_137 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_137+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_137+currStrOff, " 2>/dev/null", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_137;
}
else {
char * ____BAH_COMPILER_VAR_138 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cm);
long int strLen_1 = strlen(" 2>&1");
;                            
                        ____BAH_COMPILER_VAR_138 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_138+currStrOff, cm, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_138+currStrOff, " 2>&1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cm =  ____BAH_COMPILER_VAR_138;
}
this->handle =  popen(cm,"r");
if ((this->handle==null)) {
char * ____BAH_COMPILER_VAR_139 = "";
return ____BAH_COMPILER_VAR_139;
}
char * buff =  memoryAlloc(1025);
char * res =  "";
while (((void *)fgets(buff,1024,this->handle)!=null)) {
char * ____BAH_COMPILER_VAR_140 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(res);
long int strLen_1 = strlen(buff);
;                            
                        ____BAH_COMPILER_VAR_140 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_140+currStrOff, res, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_140+currStrOff, buff, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    res =  ____BAH_COMPILER_VAR_140;
};
this->status =  pclose(this->handle);
char * ____BAH_COMPILER_VAR_141 = res;
return ____BAH_COMPILER_VAR_141;
};
struct command command(char * s){
struct command ____BAH_COMPILER_VAR_142 = {};
____BAH_COMPILER_VAR_142.command= null;
____BAH_COMPILER_VAR_142.error = true;
____BAH_COMPILER_VAR_142.status = 0;
____BAH_COMPILER_VAR_142.handle= null;
____BAH_COMPILER_VAR_142.run = command__run;
struct command cmd =  ____BAH_COMPILER_VAR_142;
cmd.command =  s;
struct command ____BAH_COMPILER_VAR_143 = cmd;
return ____BAH_COMPILER_VAR_143;
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
                            printf("array (/opt/bah/exec.bah:59): args[%d] with length %d\n", i, args->length);
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
long int ____BAH_COMPILER_VAR_144 = r;
return ____BAH_COMPILER_VAR_144;
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
struct rope* ____BAH_COMPILER_VAR_145 = this;
return ____BAH_COMPILER_VAR_145;
}
struct rope* ____BAH_COMPILER_VAR_146 = this->parent->getParent((struct rope*)this->parent);
return ____BAH_COMPILER_VAR_146;
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
char * ____BAH_COMPILER_VAR_148 = this->str;
return ____BAH_COMPILER_VAR_148;
}
char * s =  memoryAlloc(this->totalLen + 1);
this->left->addStr((struct rope*)this->left,&s);
this->right->addStr((struct rope*)this->right,&s);
char * ____BAH_COMPILER_VAR_149 = s;
return ____BAH_COMPILER_VAR_149;
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
struct rope* ____BAH_COMPILER_VAR_150 = tmp;
return ____BAH_COMPILER_VAR_150;
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
struct rope* ____BAH_COMPILER_VAR_151 = tmp;
return ____BAH_COMPILER_VAR_151;
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
struct rope* ____BAH_COMPILER_VAR_152 = tmp;
return ____BAH_COMPILER_VAR_152;
};
struct rope* rope(char * a){
long int n1 =  strlen(a);
struct rope* r =  createRopeStructure(null,a,0,n1-1);
r->totalLen =  n1;
r->len =  n1;
struct rope* ____BAH_COMPILER_VAR_153 = r;
return ____BAH_COMPILER_VAR_153;
};
#define BAH_DIR "/opt/bah/"
#define BAH_OS "linux"
#define BAH_VERSION "v1.1 (build 41)"
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
int ____BAH_COMPILER_VAR_154 = true;
return ____BAH_COMPILER_VAR_154;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_155 = false;
return ____BAH_COMPILER_VAR_155;
};
int inArrayStr(char * needle,__BAH_ARR_TYPE_cpstring arr){
long int i =  0;
while ((i<len(arr))) {

                        if (arr->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:47): arr[%d] with length %d\n", i, arr->length);
                            exit(1);
                        };
                        if ((strcmp(needle, arr->data[i]) == 0)) {
int ____BAH_COMPILER_VAR_156 = true;
return ____BAH_COMPILER_VAR_156;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_157 = false;
return ____BAH_COMPILER_VAR_157;
};
struct Tok makeToken(long int pos,long int lineNb,__BAH_ARR_TYPE_char cont,tokenType type){
struct Tok ____BAH_COMPILER_VAR_158 = {};
____BAH_COMPILER_VAR_158.cont = "";
____BAH_COMPILER_VAR_158.ogCont = "";
____BAH_COMPILER_VAR_158.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_158.pos = 0;
____BAH_COMPILER_VAR_158.line = 1;
____BAH_COMPILER_VAR_158.begLine = 1;
____BAH_COMPILER_VAR_158.bahType = "";
____BAH_COMPILER_VAR_158.isValue = false;
____BAH_COMPILER_VAR_158.isFunc = false;
____BAH_COMPILER_VAR_158.isOper = false;
struct Tok t =  ____BAH_COMPILER_VAR_158;
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
struct Tok ____BAH_COMPILER_VAR_159 = t;
return ____BAH_COMPILER_VAR_159;
};
int isMinus(char c,char nc){
if ((c==45)) {
if (isNumber(nc)) {
int ____BAH_COMPILER_VAR_160 = true;
return ____BAH_COMPILER_VAR_160;
}
}
int ____BAH_COMPILER_VAR_161 = false;
return ____BAH_COMPILER_VAR_161;
};
void lexerErr(long int line,long int pos,char * msg){
char * lineStr =  intToStr(line);
char * posStr =  intToStr(pos);
char * ____BAH_COMPILER_VAR_162 =null;
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
                        ____BAH_COMPILER_VAR_162 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_162+currStrOff, "\e[1;31m[LEXER-ERROR]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_162+currStrOff, compilerState.currentFile, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_162+currStrOff, ":", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_162+currStrOff, lineStr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_162+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_162+currStrOff, posStr, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_162+currStrOff, "\n\e[0m\n", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_162+currStrOff, msg, strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    println(____BAH_COMPILER_VAR_162);
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
if ((c==124)) {
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
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:264): s[%d] with length %d\n", i, s->length);
                            exit(1);
                        };
                        c =  s->data[i];
if ((isAlphaNumeric(c)==0)) {
if ((inArray(c,varChars)==false)) {
if ((c==62)) {

                        if (memory->length <= len(memory)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/lexer.bah:269): memory[%d] with length %d\n", len(memory)-1, memory->length);
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
array(struct Tok)* ____BAH_COMPILER_VAR_163 = tokens;
return ____BAH_COMPILER_VAR_163;
};
int hasStructSep(struct string n){
if (n.count((struct string*)&n,".")) {
int ____BAH_COMPILER_VAR_164 = true;
return ____BAH_COMPILER_VAR_164;
}
if (n.count((struct string*)&n,"->")) {
int ____BAH_COMPILER_VAR_165 = true;
return ____BAH_COMPILER_VAR_165;
}
int ____BAH_COMPILER_VAR_166 = false;
return ____BAH_COMPILER_VAR_166;
};
struct string splitStructSepBefore(struct string n){
if (n.count((struct string*)&n,".")) {
char * ____BAH_COMPILER_VAR_167 =splitStringBefore(n,".");struct string res =  string(____BAH_COMPILER_VAR_167);
struct string ____BAH_COMPILER_VAR_168 = res;
return ____BAH_COMPILER_VAR_168;
}
if (n.count((struct string*)&n,"->")) {
char * ____BAH_COMPILER_VAR_169 =splitStringBefore(n,"->");struct string res =  string(____BAH_COMPILER_VAR_169);
struct string ____BAH_COMPILER_VAR_170 = res;
return ____BAH_COMPILER_VAR_170;
}
struct string ____BAH_COMPILER_VAR_171 = string("");
return ____BAH_COMPILER_VAR_171;
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
struct string ____BAH_COMPILER_VAR_172 = n;
return ____BAH_COMPILER_VAR_172;
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
struct cStruct* ____BAH_COMPILER_VAR_173 = s;
return ____BAH_COMPILER_VAR_173;
}
i =  i + 1;
};
struct cStruct* ____BAH_COMPILER_VAR_174 = null;
return ____BAH_COMPILER_VAR_174;
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
struct structMemb* ____BAH_COMPILER_VAR_175 = memb;
return ____BAH_COMPILER_VAR_175;
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
struct structMemb* ____BAH_COMPILER_VAR_176 = m;
return ____BAH_COMPILER_VAR_176;
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
struct structMemb* ____BAH_COMPILER_VAR_177 = sm;
return ____BAH_COMPILER_VAR_177;
}
i =  i + 1;
};
if ((strlen(s->extendedFrom)==0)) {
struct structMemb* ____BAH_COMPILER_VAR_178 = null;
return ____BAH_COMPILER_VAR_178;
}
struct cStruct* es =  searchStruct(s->extendedFrom,elems);
struct structMemb* ____BAH_COMPILER_VAR_179 = searchStructMemb(name,es,elems);
return ____BAH_COMPILER_VAR_179;
};
int isRCPpointerType(char * t){
if (strHasPrefix(t,"function(")) {
int ____BAH_COMPILER_VAR_180 = false;
return ____BAH_COMPILER_VAR_180;
}
if (((((strcmp(t, "cpstring") == 0)||(strcmp(t, "ptr") == 0))||(strCount(t,"*")>0))||(strHasPrefix(t,"[]")==true))) {
int ____BAH_COMPILER_VAR_181 = true;
return ____BAH_COMPILER_VAR_181;
}
int ____BAH_COMPILER_VAR_182 = false;
return ____BAH_COMPILER_VAR_182;
};
int isRCPtype(char * t,struct Elems* elems){
if ((isRCPpointerType(t)==true)) {
int ____BAH_COMPILER_VAR_183 = true;
return ____BAH_COMPILER_VAR_183;
}
struct cStruct* s =  searchStruct(t,elems);
if ((((s!=null)&&(s->isBinding==false))&&(s->hasRCPmemb==true))) {
int ____BAH_COMPILER_VAR_184 = true;
return ____BAH_COMPILER_VAR_184;
}
int ____BAH_COMPILER_VAR_185 = false;
return ____BAH_COMPILER_VAR_185;
};
struct string getCType(char * t,struct Elems* elems){
if ((strlen(t)==0)) {
struct string ____BAH_COMPILER_VAR_186 = string("void");
return ____BAH_COMPILER_VAR_186;
}
struct string tp =  string(t);
tp.replace((struct string*)&tp," ","");
if (tp.hasPrefix((struct string*)&tp,"[]")) {
tp.trimLeft((struct string*)&tp,2);
char * tpstr =  tp.str((struct string*)&tp);
tp =  getCType(tpstr,elems);
t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_187 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("array(");
long int strLen_1 = strlen(t);
long int strLen_2 = strlen(")*");
;                            
                        ____BAH_COMPILER_VAR_187 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_187+currStrOff, "array(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_187+currStrOff, t, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_187+currStrOff, ")*", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * r =  ____BAH_COMPILER_VAR_187;
struct string ____BAH_COMPILER_VAR_188 = string(r);
return ____BAH_COMPILER_VAR_188;
}
struct string ctp =  tp;
ctp.replace((struct string*)&ctp,"*","");
if (ctp.compare((struct string*)&ctp,"int")) {
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
                            printf("array (/home/alois/Documents/bah-bah/src/type.bah:91): elems->types[%d] with length %d\n", i, elems->types->length);
                            exit(1);
                        };
                        char * ct =  elems->types->data[i];
if (ctp.compare((struct string*)&ctp,ct)) {
struct string ____BAH_COMPILER_VAR_189 = tp;
return ____BAH_COMPILER_VAR_189;
}
i =  i + 1;
};
struct string ____BAH_COMPILER_VAR_190 = string("");
return ____BAH_COMPILER_VAR_190;
}
}
struct string ____BAH_COMPILER_VAR_191 = tp;
return ____BAH_COMPILER_VAR_191;
};
int compTypes(char * a,char * b){
if ((strcmp(a, "ptr") == 0)) {
int ____BAH_COMPILER_VAR_192 = true;
return ____BAH_COMPILER_VAR_192;
}
if ((strcmp(b, "ptr") == 0)) {
int ____BAH_COMPILER_VAR_193 = true;
return ____BAH_COMPILER_VAR_193;
}
if ((strcmp(a, b) == 0)) {
int ____BAH_COMPILER_VAR_194 = true;
return ____BAH_COMPILER_VAR_194;
}
int ____BAH_COMPILER_VAR_195 = false;
return ____BAH_COMPILER_VAR_195;
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
void * ____BAH_COMPILER_VAR_196 = noCheck( base + this->offset );
return ____BAH_COMPILER_VAR_196;
};
typedef array(struct reflectElement)* __BAH_ARR_TYPE_reflectElement;
struct reflectElement __reflect(void * v,long int s,char * t,char * n,int isArr,struct reflectElement* ae,int isStruct,__BAH_ARR_TYPE_reflectElement sl,long int offset){
struct reflectElement ____BAH_COMPILER_VAR_197 = {};
____BAH_COMPILER_VAR_197.type= null;
____BAH_COMPILER_VAR_197.name= null;
____BAH_COMPILER_VAR_197.arrayElem= null;
____BAH_COMPILER_VAR_197.structLayout = memoryAlloc(sizeof(array(struct reflectElement)));
            ____BAH_COMPILER_VAR_197.structLayout->length = 0;
            ____BAH_COMPILER_VAR_197.structLayout->elemSize = sizeof(struct reflectElement);
            ____BAH_COMPILER_VAR_197.value= null;
____BAH_COMPILER_VAR_197.calculateOffset = reflectElement__calculateOffset;
struct reflectElement re =  ____BAH_COMPILER_VAR_197;
re.size =  s;
re.type =  t;
re.name =  n;
re.isArray =  isArr;
re.arrayElem =  ae;
re.isStruct =  isStruct;
re.structLayout =  sl;
re.value =  v;
re.offset =  offset;
struct reflectElement ____BAH_COMPILER_VAR_198 = re;
return ____BAH_COMPILER_VAR_198;
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
if ((strcmp(arrAsStr(nk), key) == 0)) {
struct jsonElement* ____BAH_COMPILER_VAR_199 = elem;
return ____BAH_COMPILER_VAR_199;
}
}
else {
if ((strcmp(elem->key, key) == 0)) {
struct jsonElement* ____BAH_COMPILER_VAR_200 = elem;
return ____BAH_COMPILER_VAR_200;
}
}
i =  i + 1;
};
void * z =  (void *)0;
struct jsonElement* ____BAH_COMPILER_VAR_201 = z;
return ____BAH_COMPILER_VAR_201;
};
char * jsonElement__str(struct jsonElement* this){
char * ctn =  this->content;
char * ____BAH_COMPILER_VAR_202 = ctn;
return ____BAH_COMPILER_VAR_202;
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
else if ((strcmp(e.type, "int") == 0)) {
long int* ep =  e.value;
*ep =  strToInt(this->content);
}
else if ((strcmp(e.type, "cpstring") == 0)) {
char ** ep =  e.value;
*ep =  memoryAlloc(strlen(this->content));
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
else if ((strcmp(ae->type, "float") == 0)) {
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
else if ((strcmp(ae->type, "cpstring") == 0)) {
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
char * ____BAH_COMPILER_VAR_203 =arrToStr(currentElem);
{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_203);
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_203);
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
char * ____BAH_COMPILER_VAR_204 =arrToStr(currentElem);
{
long nLength = elemIndex;
if (jsonElem->children->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(jsonElem->children->data, (nLength+50)*sizeof(struct jsonElement*));
jsonElem->children->data = newPtr;
}
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_204);
jsonElem->children->length = nLength+1;
} else {
jsonElem->children->data[elemIndex] =  parseJson(____BAH_COMPILER_VAR_204);
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
char * ____BAH_COMPILER_VAR_205 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_205);
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
char * ____BAH_COMPILER_VAR_206 =arrToStr(currentElem);struct jsonElement* elem =  parseJson(____BAH_COMPILER_VAR_206);
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
struct jsonElement* ____BAH_COMPILER_VAR_207 = jsonElem;
return ____BAH_COMPILER_VAR_207;
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
char * ____BAH_COMPILER_VAR_208 = arrToStr(r);
return ____BAH_COMPILER_VAR_208;
};
char * toJson__inner(struct reflectElement e,int isMember,long int tabs){
void ** v =  e.value;
if (((*v==null)||(e.value==null))) {
char * ____BAH_COMPILER_VAR_209 = "null";
return ____BAH_COMPILER_VAR_209;
}
if ((e.isStruct==true)) {
tabs =  tabs + 1;
char * tabsStr =  "";
long int i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_210 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                        ____BAH_COMPILER_VAR_210 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_210+currStrOff, tabsStr, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_210+currStrOff, "\t", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tabsStr =  ____BAH_COMPILER_VAR_210;
i =  i + 1;
};
char * s =  "{\n";
i =  0;
while ((i<len(e.structLayout))) {

                        if (e.structLayout->length <= i) {
                            printf("array (/opt/bah/json.bah:382): e.structLayout[%d] with length %d\n", i, e.structLayout->length);
                            exit(1);
                        };
                        struct reflectElement m =  e.structLayout->data[i];
i =  i + 1;
if ((i<len(e.structLayout))) {
char * ____BAH_COMPILER_VAR_211 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_212 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_211);
long int strLen_6 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_212 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_212+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_212+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_212+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_212+currStrOff, m.name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_212+currStrOff, "\": ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_212+currStrOff, ____BAH_COMPILER_VAR_211, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_212+currStrOff, ",\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_212;
}
else {
char * ____BAH_COMPILER_VAR_213 =toJson__inner(m,true,tabs);char * ____BAH_COMPILER_VAR_214 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("\"");
long int strLen_3 = strlen(m.name);
long int strLen_4 = strlen("\": ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_213);
long int strLen_6 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_214 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_214+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_214+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_214+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_214+currStrOff, m.name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_214+currStrOff, "\": ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_214+currStrOff, ____BAH_COMPILER_VAR_213, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_214+currStrOff, "\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_214;
}
};
tabs =  tabs - 1;
tabsStr =  "";
i =  0;
while ((i<tabs)) {
char * ____BAH_COMPILER_VAR_215 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tabsStr);
long int strLen_1 = strlen("\t");
;                            
                        ____BAH_COMPILER_VAR_215 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_215+currStrOff, tabsStr, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_215+currStrOff, "\t", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tabsStr =  ____BAH_COMPILER_VAR_215;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_216 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(tabsStr);
long int strLen_2 = strlen("}");
;                            
                        ____BAH_COMPILER_VAR_216 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_216+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_216+currStrOff, tabsStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_216+currStrOff, "}", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_216;
char * ____BAH_COMPILER_VAR_217 = s;
return ____BAH_COMPILER_VAR_217;
}
else if ((strcmp(e.type, "int") == 0)) {
long int* ip =  e.value;
char * ____BAH_COMPILER_VAR_218 = intToStr(*ip);
return ____BAH_COMPILER_VAR_218;
}
else if ((strcmp(e.type, "float") == 0)) {
double* fp =  e.value;
char * ____BAH_COMPILER_VAR_219 = floatToStr(*fp);
return ____BAH_COMPILER_VAR_219;
}
else if ((strcmp(e.type, "cpstring") == 0)) {
if ((isMember==false)) {
struct string s =  string(e.value);
char * ____BAH_COMPILER_VAR_220 =s.str((struct string*)&s);char * ____BAH_COMPILER_VAR_221 =jsonEscapeStr(____BAH_COMPILER_VAR_220);char * ____BAH_COMPILER_VAR_222 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_221);
long int strLen_2 = strlen("\"");
;                            
                        ____BAH_COMPILER_VAR_222 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_222+currStrOff, "\"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_222+currStrOff, ____BAH_COMPILER_VAR_221, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_222+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * ____BAH_COMPILER_VAR_223 = ____BAH_COMPILER_VAR_222;
return ____BAH_COMPILER_VAR_223;
}
else {
char ** sp =  e.value;
struct string s =  string(*sp);
char * ____BAH_COMPILER_VAR_224 =s.str((struct string*)&s);char * ____BAH_COMPILER_VAR_225 =jsonEscapeStr(____BAH_COMPILER_VAR_224);char * ____BAH_COMPILER_VAR_226 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\"");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_225);
long int strLen_2 = strlen("\"");
;                            
                        ____BAH_COMPILER_VAR_226 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_226+currStrOff, "\"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_226+currStrOff, ____BAH_COMPILER_VAR_225, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_226+currStrOff, "\"", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * ____BAH_COMPILER_VAR_227 = ____BAH_COMPILER_VAR_226;
return ____BAH_COMPILER_VAR_227;
}
}
else if ((strcmp(e.type, "bool") == 0)) {
int* bp =  e.value;
if ((*bp==true)) {
char * ____BAH_COMPILER_VAR_228 = "true";
return ____BAH_COMPILER_VAR_228;
}
char * ____BAH_COMPILER_VAR_229 = "false";
return ____BAH_COMPILER_VAR_229;
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
char * ____BAH_COMPILER_VAR_230 =intToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_231 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_230);
;                            
                        ____BAH_COMPILER_VAR_231 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_231+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_231+currStrOff, ____BAH_COMPILER_VAR_230, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_231;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_232 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_232 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_232+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_232+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_232;
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
char * ____BAH_COMPILER_VAR_233 =floatToStr(arr->data[i]);char * ____BAH_COMPILER_VAR_234 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_233);
;                            
                        ____BAH_COMPILER_VAR_234 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_234+currStrOff, ____BAH_COMPILER_VAR_233, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_234;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_235 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_235 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_235+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_235+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_235;
}
};
}
else if ((strcmp(ae->type, "cpstring") == 0)) {
array(char *)* arr = memoryAlloc(sizeof(array(char *)));

arr->length = 0;
arr->elemSize = sizeof(char *);
void ** arrPtr =  e.value;
arr =  *arrPtr;
char * ____BAH_COMPILER_VAR_236 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_236 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_236+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_236;
long int i =  0;
while ((i<len(arr))) {

                        if (arr->length <= i) {
                            printf("array (/opt/bah/json.bah:450): arr[%d] with length %d\n", i, arr->length);
                            exit(1);
                        };
                        char * ____BAH_COMPILER_VAR_237 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(arr->data[i]);
;                            
                        ____BAH_COMPILER_VAR_237 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_237+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_237+currStrOff, arr->data[i], strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_237;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_238 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_238 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_238+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_238+currStrOff, ",\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_238;
}
else {
char * ____BAH_COMPILER_VAR_239 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_239 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_239+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_239+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_239;
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
                            printf("array (/opt/bah/json.bah:470): arr[%d] with length %d\n", i, arr->length);
                            exit(1);
                        };
                        void * arrElem =  arr->data[i];
ae->value =  arrElem;
long int j =  0;
while ((j<len(ae->structLayout))) {

                        if (ae->structLayout->length <= j) {
                            printf("array (/opt/bah/json.bah:473): ae->structLayout[%d] with length %d\n", j, ae->structLayout->length);
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
char * ____BAH_COMPILER_VAR_240 =toJson__inner(*ae,false,tabs);char * ____BAH_COMPILER_VAR_241 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_240);
;                            
                        ____BAH_COMPILER_VAR_241 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_241+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_241+currStrOff, ____BAH_COMPILER_VAR_240, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_241;
i =  i + 1;
if ((i<len(arr))) {
char * ____BAH_COMPILER_VAR_242 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen(",\n");
;                            
                        ____BAH_COMPILER_VAR_242 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_242+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_242+currStrOff, ",\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_242;
}
else {
char * ____BAH_COMPILER_VAR_243 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_243 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_243+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_243+currStrOff, "\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_243;
}
};
}
char * ____BAH_COMPILER_VAR_244 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s);
long int strLen_1 = strlen("]");
;                            
                        ____BAH_COMPILER_VAR_244 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_244+currStrOff, s, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_244+currStrOff, "]", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    s =  ____BAH_COMPILER_VAR_244;
char * ____BAH_COMPILER_VAR_245 = s;
return ____BAH_COMPILER_VAR_245;
}
char * ____BAH_COMPILER_VAR_246 = "";
return ____BAH_COMPILER_VAR_246;
};
char * toJson(struct reflectElement e){
char * ____BAH_COMPILER_VAR_247 = toJson__inner(e,false,0);
return ____BAH_COMPILER_VAR_247;
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
struct reflectElement ____BAH_COMPILER_VAR_249 = __reflect(name, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_250 =toJson(____BAH_COMPILER_VAR_249);char * ____BAH_COMPILER_VAR_251 =intToStr(line);char * ____BAH_COMPILER_VAR_252 =toJson(e);char * ____BAH_COMPILER_VAR_253 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_250);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_251);
long int strLen_6 = strlen("\",\n        \"element\": ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_252);
long int strLen_8 = strlen("\n    },\n    ");
;                            
                        ____BAH_COMPILER_VAR_253 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, ____BAH_COMPILER_VAR_250, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, ",\n        \"path\": \"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, compilerState.currentFile, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, ____BAH_COMPILER_VAR_251, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, "\",\n        \"element\": ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, ____BAH_COMPILER_VAR_252, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_253+currStrOff, "\n    },\n    ", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    println(____BAH_COMPILER_VAR_253);
};
void debugError(char * name,long int line,long int from,long int to,struct reflectElement e){
if ((debug==false)) {
return;
}
struct reflectElement ____BAH_COMPILER_VAR_255 = __reflect(name, sizeof(char *), "cpstring", "name", 0, 0, 0, 0, 0);
char * ____BAH_COMPILER_VAR_256 =toJson(____BAH_COMPILER_VAR_255);char * ____BAH_COMPILER_VAR_257 =intToStr(line);char * ____BAH_COMPILER_VAR_258 =intToStr(from);char * ____BAH_COMPILER_VAR_259 =intToStr(to);char * ____BAH_COMPILER_VAR_260 =toJson(e);char * ____BAH_COMPILER_VAR_261 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n    {\n        \"name\": ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_256);
long int strLen_2 = strlen(",\n        \"path\": \"");
long int strLen_3 = strlen(compilerState.currentFile);
long int strLen_4 = strlen(":");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_257);
long int strLen_6 = strlen("\",\n        \"range\": [\n            ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_258);
long int strLen_8 = strlen(",\n            ");
long int strLen_9 = strlen(____BAH_COMPILER_VAR_259);
long int strLen_10 = strlen("\n        ],\n        \"element\": ");
long int strLen_11 = strlen(____BAH_COMPILER_VAR_260);
long int strLen_12 = strlen("\n    },\n    ");
;                            
                        ____BAH_COMPILER_VAR_261 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, "\n    {\n        \"name\": ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, ____BAH_COMPILER_VAR_256, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, ",\n        \"path\": \"", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, compilerState.currentFile, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, ":", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, ____BAH_COMPILER_VAR_257, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, "\",\n        \"range\": [\n            ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, ____BAH_COMPILER_VAR_258, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, ",\n            ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, ____BAH_COMPILER_VAR_259, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, "\n        ],\n        \"element\": ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, ____BAH_COMPILER_VAR_260, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_261+currStrOff, "\n    },\n    ", strLen_12);
                        currStrOff += strLen_12;
                        
                    }
                    println(____BAH_COMPILER_VAR_261);
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
struct reflectElement ____BAH_COMPILER_VAR_264 = __reflect((char **)((char*)(v) + offsetof(struct variable, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_265 = __reflect((char **)((char*)(v) + offsetof(struct variable, type)), sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_266 = __reflect((int*)((char*)(v) + offsetof(struct variable, isConst)), sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_267 = __reflect((char **)((char*)(v) + offsetof(struct variable, constVal)), sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_268 = __reflect((int*)((char*)(v) + offsetof(struct variable, isArray)), sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_269 = __reflect((char **)((char*)(v) + offsetof(struct variable, from)), sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_270 = __reflect((int*)((char*)(v) + offsetof(struct variable, outterScope)), sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_263 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_263->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_263->length = 7;
        ____BAH_COMPILER_VAR_263->data = memoryAlloc(____BAH_COMPILER_VAR_263->length * ____BAH_COMPILER_VAR_263->elemSize);
        ____BAH_COMPILER_VAR_263->data[0] = ____BAH_COMPILER_VAR_264;
____BAH_COMPILER_VAR_263->data[1] = ____BAH_COMPILER_VAR_265;
____BAH_COMPILER_VAR_263->data[2] = ____BAH_COMPILER_VAR_266;
____BAH_COMPILER_VAR_263->data[3] = ____BAH_COMPILER_VAR_267;
____BAH_COMPILER_VAR_263->data[4] = ____BAH_COMPILER_VAR_268;
____BAH_COMPILER_VAR_263->data[5] = ____BAH_COMPILER_VAR_269;
____BAH_COMPILER_VAR_263->data[6] = ____BAH_COMPILER_VAR_270;
struct reflectElement ____BAH_COMPILER_VAR_271 = __reflect(v, sizeof(struct variable*), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_263, 0);
debugPrint("var_end",line,____BAH_COMPILER_VAR_271);
}
i =  i + 1;
};
};
void throwErr(void * tp,char * format){
char * str =  "";
char * info =  "";
long int pos =  0;
if ((tp!=null)) {
struct fileMap ____BAH_COMPILER_VAR_272 = {};
____BAH_COMPILER_VAR_272.open = fileMap__open;
____BAH_COMPILER_VAR_272.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_272.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_272;
char * fileSrcStr =  fm.open((struct fileMap*)&fm,compilerState.currentFile);
struct string fileSrc =  string(fileSrcStr);
fm.close((struct fileMap*)&fm);
struct Tok* t =  tp;
struct string ffmt =  string(format);
if ((strlen(t->ogCont)==0)) {
t->ogCont =  t->cont;
}
char * ____BAH_COMPILER_VAR_273 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("'");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_273 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, "'", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, t->ogCont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_273+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    ffmt.replace((struct string*)&ffmt,"{TOKEN}",____BAH_COMPILER_VAR_273);
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
char * ____BAH_COMPILER_VAR_274 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;31m");
long int strLen_1 = strlen(t->ogCont);
long int strLen_2 = strlen("\e[1;37m");
;                            
                        ____BAH_COMPILER_VAR_274 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_274+currStrOff, "\e[1;31m", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_274+currStrOff, t->ogCont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_274+currStrOff, "\e[1;37m", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    array(char)* errTk =  strToArr(____BAH_COMPILER_VAR_274);
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
char * ____BAH_COMPILER_VAR_275 =intToStr(t->line);char * ____BAH_COMPILER_VAR_276 =intToStr(pos);char * ____BAH_COMPILER_VAR_277 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_275);
long int strLen_1 = strlen(":");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_276);
;                            
                        ____BAH_COMPILER_VAR_277 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_277+currStrOff, ____BAH_COMPILER_VAR_275, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_277+currStrOff, ":", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_277+currStrOff, ____BAH_COMPILER_VAR_276, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    info =  ____BAH_COMPILER_VAR_277;
}
if ((debug==true)) {
struct Tok* t =  tp;
struct reflectElement ____BAH_COMPILER_VAR_278 = __reflect(format, sizeof(char *), "cpstring", "format", 0, 0, 0, 0, 0);
debugError("error",t->line,pos,pos + strlen(t->ogCont),____BAH_COMPILER_VAR_278);
debugExit();
}
else {
char * ____BAH_COMPILER_VAR_279 =null;
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
                        ____BAH_COMPILER_VAR_279 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_279+currStrOff, "\e[1;31m[ERROR]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_279+currStrOff, compilerState.currentFile, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_279+currStrOff, ":", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_279+currStrOff, info, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_279+currStrOff, "\n\e[1;37m\t", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_279+currStrOff, str, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_279+currStrOff, "\e[0m\n", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_279+currStrOff, format, strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    println(____BAH_COMPILER_VAR_279);
}
exit(1);
};
void throwWarning(char * s){
char * ____BAH_COMPILER_VAR_280 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;33m[WARNING]\e[0m ");
long int strLen_1 = strlen(compilerState.currentFile);
long int strLen_2 = strlen("\n\e[1;37m\t");
long int strLen_3 = strlen(s);
long int strLen_4 = strlen("\e[0m");
;                            
                        ____BAH_COMPILER_VAR_280 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_280+currStrOff, "\e[1;33m[WARNING]\e[0m ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_280+currStrOff, compilerState.currentFile, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_280+currStrOff, "\n\e[1;37m\t", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_280+currStrOff, s, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_280+currStrOff, "\e[0m", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    println(____BAH_COMPILER_VAR_280);
};
#include <stdlib.h>
char * absPath(char * path){
char * z =  (char *)0;
char * p =  realpath(path,z);
char * ____BAH_COMPILER_VAR_281 = p;
return ____BAH_COMPILER_VAR_281;
};
char * getCurrentPath(){
char * cwd =  memoryAlloc(4096);
getcwd(cwd,4096);
char * ____BAH_COMPILER_VAR_282 = cwd;
return ____BAH_COMPILER_VAR_282;
};
int isInside(char * basePath,char * subPath){
char * abs1 =  absPath(basePath);
char * abs2 =  absPath(subPath);
int ____BAH_COMPILER_VAR_283 = (strHasPrefix(subPath,basePath)==true);
return ____BAH_COMPILER_VAR_283;
};
void setCurrentPath(char * s){
chdir(s);
};
int isGlobal(){
int ____BAH_COMPILER_VAR_284 = (currentFn==null);
return ____BAH_COMPILER_VAR_284;
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
struct variable* ____BAH_COMPILER_VAR_285 = nv;
return ____BAH_COMPILER_VAR_285;
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
struct variable* ____BAH_COMPILER_VAR_286 = null;
return ____BAH_COMPILER_VAR_286;
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((s==null)) {
struct variable* ____BAH_COMPILER_VAR_287 = null;
return ____BAH_COMPILER_VAR_287;
}
struct structMemb* memb =  searchStructMemb(membs,s,elems);
if ((memb==null)) {
struct variable* ____BAH_COMPILER_VAR_288 = null;
return ____BAH_COMPILER_VAR_288;
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
char * ____BAH_COMPILER_VAR_289 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_289 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_289+currStrOff, r, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_289+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    r =  ____BAH_COMPILER_VAR_289;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_290 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(nv->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                        ____BAH_COMPILER_VAR_290 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_290+currStrOff, "Cannot use '*' on ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_290+currStrOff, nv->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_290+currStrOff, " because it is not pointer.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(null,____BAH_COMPILER_VAR_290);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
struct variable* ____BAH_COMPILER_VAR_291 = nv;
return ____BAH_COMPILER_VAR_291;
}
long int i =  0;
while ((i<len(elems->vars))) {

                        if (elems->vars->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/var.bah:95): elems->vars[%d] with length %d\n", i, elems->vars->length);
                            exit(1);
                        };
                        struct variable* v =  elems->vars->data[i];
if ((v==null)) {
char * ____BAH_COMPILER_VAR_292 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null var'.");
;                            
                        ____BAH_COMPILER_VAR_292 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_292+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_292+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_292+currStrOff, "' resulting in null var'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_292);
}
if ((strcmp(v->name, name) == 0)) {
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
char * ____BAH_COMPILER_VAR_293 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(r);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_293 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_293+currStrOff, r, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_293+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    r =  ____BAH_COMPILER_VAR_293;
}
long int nbUnaries =  tcc.count((struct string*)&tcc,"*");
if ((nbUnaries>0)) {
struct string ct =  string(r);
long int pointerLevel =  ct.count((struct string*)&ct,"*");
if ((pointerLevel<nbUnaries)) {
char * ____BAH_COMPILER_VAR_294 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use '*' on ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" because it is not pointer.");
;                            
                        ____BAH_COMPILER_VAR_294 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_294+currStrOff, "Cannot use '*' on ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_294+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_294+currStrOff, " because it is not pointer.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(null,____BAH_COMPILER_VAR_294);
}
ct.trimRight((struct string*)&ct,nbUnaries);
r =  ct.str((struct string*)&ct);
}
nv->type =  r;
nv->name =  ogName;
struct variable* ____BAH_COMPILER_VAR_295 = nv;
return ____BAH_COMPILER_VAR_295;
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
if ((strcmp(fn->name, name) == 0)) {
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
char * ____BAH_COMPILER_VAR_296 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(arg->type);
;                            
                        ____BAH_COMPILER_VAR_296 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_296+currStrOff, nv->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_296+currStrOff, arg->type, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nv->type =  ____BAH_COMPILER_VAR_296;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_297 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_297 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_297+currStrOff, nv->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_297+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nv->type =  ____BAH_COMPILER_VAR_297;
}
};
char * ____BAH_COMPILER_VAR_298 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nv->type);
long int strLen_1 = strlen(")");
long int strLen_2 = strlen(fn->returns->type);
;                            
                        ____BAH_COMPILER_VAR_298 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, nv->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_298+currStrOff, fn->returns->type, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    nv->type =  ____BAH_COMPILER_VAR_298;
struct variable* ____BAH_COMPILER_VAR_299 = nv;
return ____BAH_COMPILER_VAR_299;
}
i =  i + 1;
};
struct variable* ____BAH_COMPILER_VAR_300 = null;
return ____BAH_COMPILER_VAR_300;
};
char * setCType(struct variable* v,struct Elems* elems){
struct string tp =  getCType(v->type,elems);
char * t =  tp.str((struct string*)&tp);
char * ____BAH_COMPILER_VAR_301 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
;                            
                        ____BAH_COMPILER_VAR_301 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_301+currStrOff, t, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_301+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_301+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    t =  ____BAH_COMPILER_VAR_301;
char * ____BAH_COMPILER_VAR_302 = t;
return ____BAH_COMPILER_VAR_302;
};
char * getTypeFromToken(struct Tok* t,int strict,struct Elems* elems){
if ((strlen(t->bahType)>0)) {
char * r =  t->bahType;
char * ____BAH_COMPILER_VAR_303 = r;
return ____BAH_COMPILER_VAR_303;
}
if ((t->type==TOKEN_TYPE_VAR)) {
struct variable* v =  searchVar(t->cont,elems);
if ((v==null)) {
if ((strict==true)) {
throwErr(t,"Unknown var {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_304 = "";
return ____BAH_COMPILER_VAR_304;
}
}
if ((strict==true)) {
if ((strlen(v->type)==0)) {
throwErr(t,"Cannot use {TOKEN} because it does not have any type.");
}
}
char * r =  v->type;
char * ____BAH_COMPILER_VAR_305 = r;
return ____BAH_COMPILER_VAR_305;
}
if ((t->type==TOKEN_TYPE_FLOAT)) {
char * ____BAH_COMPILER_VAR_306 = "float";
return ____BAH_COMPILER_VAR_306;
}
if ((t->type==TOKEN_TYPE_INT)) {
char * ____BAH_COMPILER_VAR_307 = "int";
return ____BAH_COMPILER_VAR_307;
}
if ((t->type==TOKEN_TYPE_STR)) {
char * ____BAH_COMPILER_VAR_308 = "cpstring";
return ____BAH_COMPILER_VAR_308;
}
if ((t->type==TOKEN_TYPE_CHAR)) {
char * ____BAH_COMPILER_VAR_309 = "char";
return ____BAH_COMPILER_VAR_309;
}
if ((t->type==TOKEN_TYPE_BOOL)) {
char * ____BAH_COMPILER_VAR_310 = "bool";
return ____BAH_COMPILER_VAR_310;
}
throwErr(t,"Cannot use {TOKEN} as value.");
char * ____BAH_COMPILER_VAR_311 = "";
return ____BAH_COMPILER_VAR_311;
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
char * ____BAH_COMPILER_VAR_312 =intToStr(len(nf->args));char * ____BAH_COMPILER_VAR_313 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("arg_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_312);
;                            
                        ____BAH_COMPILER_VAR_313 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_313+currStrOff, "arg_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_313+currStrOff, ____BAH_COMPILER_VAR_312, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    arg->name =  ____BAH_COMPILER_VAR_313;
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
struct func* ____BAH_COMPILER_VAR_314 = nf;
return ____BAH_COMPILER_VAR_314;
};
struct func* searchFunc(char * name,struct Elems* elems,int inclCurr){
char * ogName =  name;
if ((strcmp(name, "noCheck") == 0)) {
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
struct func* ____BAH_COMPILER_VAR_315 = fn;
return ____BAH_COMPILER_VAR_315;
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
char * ____BAH_COMPILER_VAR_316 =fnName.str((struct string*)&fnName);struct structMemb* memb =  searchStructMemb(____BAH_COMPILER_VAR_316,s,elems);
name =  fnName.content;
char * ____BAH_COMPILER_VAR_317 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(memb->from);
long int strLen_1 = strlen("__");
long int strLen_2 = strlen(name);
;                            
                        ____BAH_COMPILER_VAR_317 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_317+currStrOff, memb->from, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_317+currStrOff, "__", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_317+currStrOff, name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    name =  ____BAH_COMPILER_VAR_317;
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
char * ____BAH_COMPILER_VAR_318 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '");
long int strLen_1 = strlen(name);
long int strLen_2 = strlen("' resulting in null func'.");
;                            
                        ____BAH_COMPILER_VAR_318 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_318+currStrOff, "\e[1;31m[INTERNAL COMPILER ERROR]\e[0m\n Please report the bug as 'compiler searching '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_318+currStrOff, name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_318+currStrOff, "' resulting in null func'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_318);
}
if ((strcmp(fn->name, name) == 0)) {
struct func* ____BAH_COMPILER_VAR_319 = fn;
return ____BAH_COMPILER_VAR_319;
}
i =  i + 1;
};
if ((inclCurr==true)) {
if ((strcmp(currentFn->name, name) == 0)) {
struct func* ____BAH_COMPILER_VAR_320 = currentFn;
return ____BAH_COMPILER_VAR_320;
}
}
struct variable* v =  searchVar(ogName,elems);
if ((v==null)) {
struct func* ____BAH_COMPILER_VAR_321 = null;
return ____BAH_COMPILER_VAR_321;
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
struct func* ____BAH_COMPILER_VAR_322 = null;
return ____BAH_COMPILER_VAR_322;
}
struct func* pfn =  parseFnType(cvt);
nf->returns =  pfn->returns;
nf->args =  pfn->args;
struct func* ____BAH_COMPILER_VAR_323 = nf;
return ____BAH_COMPILER_VAR_323;
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
char * ____BAH_COMPILER_VAR_324 =null;
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
                        ____BAH_COMPILER_VAR_324 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_324+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_324+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_324+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_324+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_324+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_324+currStrOff, m->def, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_324+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_324;
declared =  true;
}
if ((cmpt.hasPrefix((struct string*)&cmpt,"[]")==1)) {
cmpt.trimLeft((struct string*)&cmpt,2);
char * cmptstr =  cmpt.str((struct string*)&cmpt);
struct string elemCType =  getCType(cmptstr,elems);
char * elemCTypeStr =  elemCType.str((struct string*)&elemCType);
char * ____BAH_COMPILER_VAR_325 =null;
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
                        ____BAH_COMPILER_VAR_325 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, " = memoryAlloc(sizeof(array(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, elemCTypeStr, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, ")));\n            ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, v->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, sep, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, m->name, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, "->length = 0;\n            ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, v->name, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, sep, strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, m->name, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, "->elemSize = sizeof(", strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, elemCTypeStr, strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_325+currStrOff, ");\n            ", strLen_16);
                        currStrOff += strLen_16;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_325;
declared =  true;
}
if ((isRCPpointerType(m->type)&&(declared==false))) {
char * ____BAH_COMPILER_VAR_326 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(sep);
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("= null;\n");
;                            
                        ____BAH_COMPILER_VAR_326 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_326+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_326+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_326+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_326+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_326+currStrOff, "= null;\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_326;
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
char * ____BAH_COMPILER_VAR_327 =null;
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
                        ____BAH_COMPILER_VAR_327 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, es->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, "__", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, m->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_327+currStrOff, ";\n", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_327;
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
char * ____BAH_COMPILER_VAR_328 =null;
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
                        ____BAH_COMPILER_VAR_328 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, sep, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, s->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, "__", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, m->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_328+currStrOff, ";\n", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_328;
i =  i + 1;
};
if ((((s->isBinding==false)&&RCPavailable())&&(s->hasRCPmemb==true))) {
if ((strCount(v->type,"*")==0)) {
char * ____BAH_COMPILER_VAR_329 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter = malloc(sizeof(int));*(int*)");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(".__RCP_counter = 1;\n");
;                            
                        ____BAH_COMPILER_VAR_329 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_329+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_329+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_329+currStrOff, ".__RCP_counter = malloc(sizeof(int));*(int*)", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_329+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_329+currStrOff, ".__RCP_counter = 1;\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_329;
}
else {
char * ____BAH_COMPILER_VAR_330 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen("->__RCP_counter = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_330 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_330+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_330+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_330+currStrOff, "->__RCP_counter = RCP_request(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_330+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_330+currStrOff, ");\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_330;
}
}
char * ____BAH_COMPILER_VAR_331 = code;
return ____BAH_COMPILER_VAR_331;
};
long int NB_COMP_VAR;
char * genCompilerVar(){
char * ____BAH_COMPILER_VAR_332 =intToStr(NB_COMP_VAR);char * ____BAH_COMPILER_VAR_333 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("____BAH_COMPILER_VAR_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_332);
;                            
                        ____BAH_COMPILER_VAR_333 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_333+currStrOff, "____BAH_COMPILER_VAR_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_333+currStrOff, ____BAH_COMPILER_VAR_332, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * name =  ____BAH_COMPILER_VAR_333;
NB_COMP_VAR =  NB_COMP_VAR + 1;
char * ____BAH_COMPILER_VAR_334 = name;
return ____BAH_COMPILER_VAR_334;
};
typedef array(struct variable*)* __BAH_ARR_TYPE_variable;
int varInArr(struct variable* v,__BAH_ARR_TYPE_variable arr){
if ((arr==null)) {
int ____BAH_COMPILER_VAR_335 = false;
return ____BAH_COMPILER_VAR_335;
}
long int j =  0;
while ((j<len(arr))) {

                        if (arr->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/var.bah:385): arr[%d] with length %d\n", j, arr->length);
                            exit(1);
                        };
                        struct variable* ev =  arr->data[j];
if ((strcmp(ev->name, v->name) == 0)) {
int ____BAH_COMPILER_VAR_336 = true;
return ____BAH_COMPILER_VAR_336;
}
j =  j + 1;
};
int ____BAH_COMPILER_VAR_337 = false;
return ____BAH_COMPILER_VAR_337;
};
void makeInit(){
OUTPUT =  OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        "))->add(OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        ")), INIT)->add(OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        "))->add(OUTPUT->add(OUTPUT, rope("\n    void __BAH_init() {\n\n        ")), INIT), rope("\n\n    };\n    "));
};
struct rope* decrVar(struct variable* v,struct Elems* elems){
struct rope* r =  rope("");
if (strHasPrefix(v->type,"[]")) {
struct string at =  string(v->type);
at.trimLeft((struct string*)&at,2);
char * ____BAH_COMPILER_VAR_338 =at.str((struct string*)&at);if (isRCPtype(____BAH_COMPILER_VAR_338,elems)) {
struct variable* arrElem = memoryAlloc(sizeof(struct variable));
arrElem->name = "";
arrElem->type = "";
arrElem->isConst = false;
arrElem->constVal = "";
arrElem->isArray = false;
arrElem->from = "";
arrElem->outterScope = false;
arrElem->type =  at.str((struct string*)&at);
char * ____BAH_COMPILER_VAR_339 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen("->data[arrElemIndex]");
;                            
                        ____BAH_COMPILER_VAR_339 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_339+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_339+currStrOff, "->data[arrElemIndex]", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    arrElem->name =  ____BAH_COMPILER_VAR_339;
char * ____BAH_COMPILER_VAR_340 =null;
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
                        ____BAH_COMPILER_VAR_340 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_340+currStrOff, "\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_340+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_340+currStrOff, ");\n            if (arrRCP != null && arrRCP->c == 1) {\n                struct RCP * arrDataRCP = RCP_request(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_340+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_340+currStrOff, "->data);\n                if (arrDataRCP != null && arrDataRCP->c == 1) {\n                    for(int arrElemIndex=len(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_340+currStrOff, v->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_340+currStrOff, ")-1; arrElemIndex >= 0; arrElemIndex--) {\n                        ", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    r =  rope(____BAH_COMPILER_VAR_340)->add(rope(____BAH_COMPILER_VAR_340), decrVar(arrElem,elems))->add(rope(____BAH_COMPILER_VAR_340)->add(rope(____BAH_COMPILER_VAR_340), decrVar(arrElem,elems)), rope("\n                    };\n                }\n                RCP_decrRCP(arrDataRCP);\n            }\n            RCP_decrRCP(arrRCP);\n            };//////////////////////\n            "));
}
else {
char * ____BAH_COMPILER_VAR_341 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen("->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };//////////////////////\n            ");
;                            
                        ____BAH_COMPILER_VAR_341 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_341+currStrOff, "\n            {//////////RCP//////////\n            struct RCP * arrRCP = RCP_request(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_341+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_341+currStrOff, ");\n            if (arrRCP != null) {\n                if (arrRCP->c == 1) {\n                    struct RCP * arrDataRCP = RCP_request(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_341+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_341+currStrOff, "->data);\n                    RCP_decrRCP(arrDataRCP);\n                }\n                RCP_decrRCP(arrRCP);\n            }\n            };//////////////////////\n            ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    r =  rope(____BAH_COMPILER_VAR_341);
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
char * ____BAH_COMPILER_VAR_342 =null;
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
                        ____BAH_COMPILER_VAR_342 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_342+currStrOff, "__RCP_clean_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_342+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_342+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_342+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_342+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_342+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_342+currStrOff, heap, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_342+currStrOff, ");\n", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_342));
}
else if ((isPointer==true)) {
char * ____BAH_COMPILER_VAR_343 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_decr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_343 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_343+currStrOff, "RCP_decr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_343+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_343+currStrOff, ");\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_343));
}
}
struct rope* ____BAH_COMPILER_VAR_344 = r;
return ____BAH_COMPILER_VAR_344;
};
struct rope* incrVar(struct variable* v,struct Elems* elems){
if ((strCount(v->name,"*")>0)) {
struct rope* ____BAH_COMPILER_VAR_345 = rope("");
return ____BAH_COMPILER_VAR_345;
}
struct cStruct* s =  searchStruct(v->type,elems);
if ((((s!=null)&&(isRCPpointerType(v->type)==false))&&(s->isBinding==false))) {
char * ____BAH_COMPILER_VAR_346 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_incrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter);");
;                            
                        ____BAH_COMPILER_VAR_346 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_346+currStrOff, "RCP_incrCounter(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_346+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_346+currStrOff, ".__RCP_counter);", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* ____BAH_COMPILER_VAR_347 = rope(____BAH_COMPILER_VAR_346);
return ____BAH_COMPILER_VAR_347;
}
char * ____BAH_COMPILER_VAR_348 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_incr(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(");");
;                            
                        ____BAH_COMPILER_VAR_348 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, "RCP_incr(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_348+currStrOff, ");", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* ____BAH_COMPILER_VAR_349 = rope(____BAH_COMPILER_VAR_348);
return ____BAH_COMPILER_VAR_349;
};
int RCPavailable(){
char * ____BAH_COMPILER_VAR_350 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("rcp.bah");
;                            
                        ____BAH_COMPILER_VAR_350 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_350+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_350+currStrOff, "rcp.bah", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * ____BAH_COMPILER_VAR_351 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen("fastrcp.bah");
;                            
                        ____BAH_COMPILER_VAR_351 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_351+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_351+currStrOff, "fastrcp.bah", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    int ____BAH_COMPILER_VAR_352 = (((strcmp(compilerState.currentFile, ____BAH_COMPILER_VAR_350) != 0)&&(strcmp(compilerState.currentFile, ____BAH_COMPILER_VAR_351) != 0))&&(RCPenabled==true));
return ____BAH_COMPILER_VAR_352;
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
char * ____BAH_COMPILER_VAR_354 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_355 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_354);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(av->name);
long int strLen_3 = strlen(" =");
long int strLen_4 = strlen(c);
long int strLen_5 = strlen(";");
;                            
                        ____BAH_COMPILER_VAR_355 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_355+currStrOff, ____BAH_COMPILER_VAR_354, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_355+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_355+currStrOff, av->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_355+currStrOff, " =", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_355+currStrOff, c, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_355+currStrOff, ";", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_355));
char * ____BAH_COMPILER_VAR_356 = av->name;
return ____BAH_COMPILER_VAR_356;
};
struct rope* makeRCPfuncFromStruct(struct cStruct* s,struct Elems* elems){
if (((s->isBinding==true)||(RCPavailable()==false))) {
struct rope* ____BAH_COMPILER_VAR_357 = rope("");
return ____BAH_COMPILER_VAR_357;
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
if ((strcmp(rm.str((struct string*)&rm), s->name) != 0)) {
struct variable* mv = memoryAlloc(sizeof(struct variable));
mv->name = "";
mv->type = "";
mv->isConst = false;
mv->constVal = "";
mv->isArray = false;
mv->from = "";
mv->outterScope = false;
char * ____BAH_COMPILER_VAR_358 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("e->");
long int strLen_1 = strlen(m->name);
;                            
                        ____BAH_COMPILER_VAR_358 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_358+currStrOff, "e->", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_358+currStrOff, m->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    mv->name =  ____BAH_COMPILER_VAR_358;
mv->type =  m->type;
decrMembs =  decrMembs->add(decrMembs, decrVar(mv,elems));
}
else {
char * ____BAH_COMPILER_VAR_359 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Strcture '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has a self-referenced member '");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen("'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.");
;                            
                        ____BAH_COMPILER_VAR_359 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_359+currStrOff, "Strcture '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_359+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_359+currStrOff, "' has a self-referenced member '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_359+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_359+currStrOff, "'. May lead to memory leaks, recompile the program without the '-rcp' flag if memory leaks happens.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwWarning(____BAH_COMPILER_VAR_359);
char * amp =  "&";
char * heap =  "0";
if ((strCount(m->type,"*")>0)) {
amp =  "";
heap =  "1";
}
char * ____BAH_COMPILER_VAR_360 =null;
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
                        ____BAH_COMPILER_VAR_360 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, "__RCP_clean_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, "e->", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, m->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, heap, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_360+currStrOff, ");\n", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    decrMembs =  decrMembs->add(decrMembs, rope(____BAH_COMPILER_VAR_360));
}
}
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_361 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("void* __RCP_clean_");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("(struct ");
long int strLen_3 = strlen(s->name);
long int strLen_4 = strlen("* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ");
;                            
                        ____BAH_COMPILER_VAR_361 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_361+currStrOff, "void* __RCP_clean_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_361+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_361+currStrOff, "(struct ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_361+currStrOff, s->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_361+currStrOff, "* e, int heap) {\n        if(heap == 1) {\n            struct RCP* srcp = RCP_request(e);\n            if (srcp != null) {\n                if (srcp->c == 1) {\n                    ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    struct rope* r =  rope(____BAH_COMPILER_VAR_361)->add(rope(____BAH_COMPILER_VAR_361), decrMembs)->add(rope(____BAH_COMPILER_VAR_361)->add(rope(____BAH_COMPILER_VAR_361), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_361)->add(rope(____BAH_COMPILER_VAR_361), decrMembs)->add(rope(____BAH_COMPILER_VAR_361)->add(rope(____BAH_COMPILER_VAR_361), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs)->add(rope(____BAH_COMPILER_VAR_361)->add(rope(____BAH_COMPILER_VAR_361), decrMembs)->add(rope(____BAH_COMPILER_VAR_361)->add(rope(____BAH_COMPILER_VAR_361), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            "))->add(rope(____BAH_COMPILER_VAR_361)->add(rope(____BAH_COMPILER_VAR_361), decrMembs)->add(rope(____BAH_COMPILER_VAR_361)->add(rope(____BAH_COMPILER_VAR_361), decrMembs), rope("\n                }\n                RCP_decrRCP(srcp);\n            }\n        } else if(RCP_decrCounter((void*)e->__RCP_counter)==0) {\n            ")), decrMembs), rope("\n        }\n    };\n"));
struct rope* ____BAH_COMPILER_VAR_362 = r;
return ____BAH_COMPILER_VAR_362;
};
int RCPselfRef(struct variable* v){
long int i =  0;
while ((i<len(compilerState.RCPvars))) {

                        if (compilerState.RCPvars->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/mem.bah:155): compilerState.RCPvars[%d] with length %d\n", i, compilerState.RCPvars->length);
                            exit(1);
                        };
                        struct variable* r =  compilerState.RCPvars->data[i];
if ((strcmp(r->name, v->name) == 0)) {
int ____BAH_COMPILER_VAR_363 = true;
return ____BAH_COMPILER_VAR_363;
}
i =  i + 1;
};
int ____BAH_COMPILER_VAR_364 = false;
return ____BAH_COMPILER_VAR_364;
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
char * ____BAH_COMPILER_VAR_365 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(" '");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_365 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_365+currStrOff, cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_365+currStrOff, " '", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_365+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_365+currStrOff, "'", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    cont =  ____BAH_COMPILER_VAR_365;
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
struct Elems* ____BAH_COMPILER_VAR_366 = nElems;
return ____BAH_COMPILER_VAR_366;
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
lineType ____BAH_COMPILER_VAR_367 = LINE_TYPE_FN_CALL;
return ____BAH_COMPILER_VAR_367;
}
if ((ft.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(ft.cont, "#include") == 0)) {
lineType ____BAH_COMPILER_VAR_368 = LINE_TYPE_INCLUDE;
return ____BAH_COMPILER_VAR_368;
}
else if ((strcmp(ft.cont, "#define") == 0)) {
lineType ____BAH_COMPILER_VAR_369 = LINE_TYPE_DEFINE;
return ____BAH_COMPILER_VAR_369;
}
else if ((strcmp(ft.cont, "const") == 0)) {
lineType ____BAH_COMPILER_VAR_370 = LINE_TYPE_CONST;
return ____BAH_COMPILER_VAR_370;
}
else if ((strcmp(ft.cont, "struct") == 0)) {
lineType ____BAH_COMPILER_VAR_371 = LINE_TYPE_STRUCT;
return ____BAH_COMPILER_VAR_371;
}
else if ((strcmp(ft.cont, "#cLib") == 0)) {
lineType ____BAH_COMPILER_VAR_372 = LINE_TYPE_CLIB;
return ____BAH_COMPILER_VAR_372;
}
else if ((strcmp(ft.cont, "return") == 0)) {
lineType ____BAH_COMPILER_VAR_373 = LINE_TYPE_RETURN;
return ____BAH_COMPILER_VAR_373;
}
else if ((strcmp(ft.cont, "if") == 0)) {
lineType ____BAH_COMPILER_VAR_374 = LINE_TYPE_IF;
return ____BAH_COMPILER_VAR_374;
}
else if ((strcmp(ft.cont, "else") == 0)) {
lineType ____BAH_COMPILER_VAR_375 = LINE_TYPE_ELSE;
return ____BAH_COMPILER_VAR_375;
}
else if ((strcmp(ft.cont, "#macro") == 0)) {
lineType ____BAH_COMPILER_VAR_376 = LINE_TYPE_MACRO;
return ____BAH_COMPILER_VAR_376;
}
else if ((strcmp(ft.cont, "for") == 0)) {
lineType ____BAH_COMPILER_VAR_377 = LINE_TYPE_FOR;
return ____BAH_COMPILER_VAR_377;
}
else if ((strcmp(ft.cont, "async") == 0)) {
lineType ____BAH_COMPILER_VAR_378 = LINE_TYPE_ASYNC;
return ____BAH_COMPILER_VAR_378;
}
else if (((strcmp(ft.cont, "continue") == 0)||(strcmp(ft.cont, "break") == 0))) {
lineType ____BAH_COMPILER_VAR_379 = LINE_TYPE_FOR_OPERATOR;
return ____BAH_COMPILER_VAR_379;
}
else {
lineType ____BAH_COMPILER_VAR_380 = LINE_TYPE_PRE_KEYWORD;
return ____BAH_COMPILER_VAR_380;
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
if (((st.type==TOKEN_TYPE_ENCL)&&(strcmp(st.cont, "(") == 0))) {

                        if (line->length <= len(line)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:127): line[%d] with length %d\n", len(line)-1, line->length);
                            exit(1);
                        };
                        struct Tok lt =  line->data[len(line)-1];
if (((lt.type==TOKEN_TYPE_ENCL)&&(strcmp(lt.cont, "}") == 0))) {
lineType ____BAH_COMPILER_VAR_381 = LINE_TYPE_FN_DECL;
return ____BAH_COMPILER_VAR_381;
}
lineType ____BAH_COMPILER_VAR_382 = LINE_TYPE_FN_CALL;
return ____BAH_COMPILER_VAR_382;
}
lineType ____BAH_COMPILER_VAR_383 = LINE_TYPE_VAR;
return ____BAH_COMPILER_VAR_383;
}
lineType ____BAH_COMPILER_VAR_384 = (lineType)-1;
return ____BAH_COMPILER_VAR_384;
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
array(struct Tok)* ____BAH_COMPILER_VAR_385 = line;
return ____BAH_COMPILER_VAR_385;
}
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:159): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "<") == 0)) {
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
if ((strcmp(nnt.cont, ">") == 0)) {
nnnt.bahType =  nt.cont;
struct string cCast =  getCType(nt.cont,elems);
char * cCastStr =  cCast.str((struct string*)&cCast);
char * ____BAH_COMPILER_VAR_386 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(cCastStr);
long int strLen_2 = strlen(")");
long int strLen_3 = strlen(nnnt.cont);
;                            
                        ____BAH_COMPILER_VAR_386 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_386+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_386+currStrOff, cCastStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_386+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_386+currStrOff, nnnt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    nnnt.cont =  ____BAH_COMPILER_VAR_386;

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
array(struct Tok)* ____BAH_COMPILER_VAR_387 = nl;
return ____BAH_COMPILER_VAR_387;
};
char * getDirFromFile(char * f){
char * ____BAH_COMPILER_VAR_388 =__STR(f);array(char)* p =  strAsArr(____BAH_COMPILER_VAR_388);
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
char * ____BAH_COMPILER_VAR_389 = "";
return ____BAH_COMPILER_VAR_389;
}
char * ____BAH_COMPILER_VAR_390 = arrAsStr(p);
return ____BAH_COMPILER_VAR_390;
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
array(char *)* includes =  compilerState.includes;
long int i =  0;
while ((i<len(includes))) {

                        if (includes->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:228): includes[%d] with length %d\n", i, includes->length);
                            exit(1);
                        };
                        if ((strcmp(includes->data[i], ccstr) == 0)) {
int ____BAH_COMPILER_VAR_391 = true;
return ____BAH_COMPILER_VAR_391;
}
i =  i + 1;
};
struct fileMap ____BAH_COMPILER_VAR_392 = {};
____BAH_COMPILER_VAR_392.open = fileMap__open;
____BAH_COMPILER_VAR_392.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_392.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_392;
char * ____BAH_COMPILER_VAR_393 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(BAH_DIR);
long int strLen_1 = strlen(ccstr);
;                            
                        ____BAH_COMPILER_VAR_393 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_393+currStrOff, BAH_DIR, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_393+currStrOff, ccstr, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * fileName =  ____BAH_COMPILER_VAR_393;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_394 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(ccstr);
;                            
                        ____BAH_COMPILER_VAR_394 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_394+currStrOff, compilerState.currentDir, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_394+currStrOff, ccstr, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fileName =  absPath(____BAH_COMPILER_VAR_394);
f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
int ____BAH_COMPILER_VAR_395 = false;
return ____BAH_COMPILER_VAR_395;
}
}
char * oDir =  compilerState.currentDir;
char * ____BAH_COMPILER_VAR_396 =getDirFromFile(ccstr);char * ____BAH_COMPILER_VAR_397 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(compilerState.currentDir);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_396);
;                            
                        ____BAH_COMPILER_VAR_397 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_397+currStrOff, compilerState.currentDir, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_397+currStrOff, ____BAH_COMPILER_VAR_396, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    compilerState.currentDir =  ____BAH_COMPILER_VAR_397;
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
char * ____BAH_COMPILER_VAR_398 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(ccstr);
long int strLen_2 = strlen("' not recognized.");
;                            
                        ____BAH_COMPILER_VAR_398 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_398+currStrOff, "File '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_398+currStrOff, ccstr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_398+currStrOff, "' not recognized.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_398);
}
parseLines(tokens,elems);
compilerState.currentFile =  oFile;
compilerState.currentDir =  oDir;
int ____BAH_COMPILER_VAR_399 = true;
return ____BAH_COMPILER_VAR_399;
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
char * ____BAH_COMPILER_VAR_400 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(sc);
long int strLen_2 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_400 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_400+currStrOff, "#include ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_400+currStrOff, sc, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_400+currStrOff, "\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_400));

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
if ((((strcmp(t.cont, "-") == 0)&&(pt.isValue==false))&&(nt.type==TOKEN_TYPE_INT))) {
char * ____BAH_COMPILER_VAR_401 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_401 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_401+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_401+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nt.cont =  ____BAH_COMPILER_VAR_401;

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
char * ____BAH_COMPILER_VAR_402 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_402 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_402+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_402+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * c =  ____BAH_COMPILER_VAR_402;
long int tl =  t.line;
long int tp =  t.pos;
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
____BAH_COMPILER_VAR_403.cont = c;
____BAH_COMPILER_VAR_403.ogCont = c;
____BAH_COMPILER_VAR_403.isValue = false;
____BAH_COMPILER_VAR_403.line = tl;
____BAH_COMPILER_VAR_403.pos = tp;
____BAH_COMPILER_VAR_403.type = TOKEN_TYPE_SYNTAX;
struct Tok tmpT =  ____BAH_COMPILER_VAR_403;

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
char * ____BAH_COMPILER_VAR_404 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_404 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_404+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_404+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_404+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_404+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_404+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_404);
}
t.isValue =  true;
if (compTypes(ptt,"cpstring")) {
if ((strcmp(t.cont, "+") != 0)) {
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
if ((strcmp(strAddTk.cont, "+") != 0)) {
break;
}
wasAdd =  true;
}
else {
char * strAddTkT =  getTypeFromToken(&strAddTk,true,elems);
if ((compTypes(strAddTkT,"cpstring")==false)) {
char * ____BAH_COMPILER_VAR_405 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_405 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_405+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&strAddTkT,____BAH_COMPILER_VAR_405);
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
                        char * ____BAH_COMPILER_VAR_406 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(lens);
long int strLen_1 = strlen("long int strLen_");
long int strLen_2 = strlen(js);
long int strLen_3 = strlen(" = strlen(");
long int strLen_4 = strlen(strConts->data[j]);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_406 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, lens, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, "long int strLen_", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, js, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, " = strlen(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, strConts->data[j], strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_406+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    lens =  ____BAH_COMPILER_VAR_406;
char * ____BAH_COMPILER_VAR_407 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(totStrLen);
long int strLen_1 = strlen(" + strLen_");
long int strLen_2 = strlen(js);
;                            
                        ____BAH_COMPILER_VAR_407 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, totStrLen, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, " + strLen_", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_407+currStrOff, js, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    totStrLen =  ____BAH_COMPILER_VAR_407;
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
                        char * ____BAH_COMPILER_VAR_408 =null;
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
                        ____BAH_COMPILER_VAR_408 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, "\n                        strncpy(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, rstr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, "+currStrOff, ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, strConts->data[j], strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, ", strLen_", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, js, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, ");\n                        currStrOff += strLen_", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, js, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_408+currStrOff, ";\n                        ", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    cats =  cats->add(cats, rope(____BAH_COMPILER_VAR_408));
j =  j + 1;
};
char * ____BAH_COMPILER_VAR_409 =null;
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
                        ____BAH_COMPILER_VAR_409 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_409+currStrOff, "\n                    {\n                        long int currStrOff = 0;\n                        ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_409+currStrOff, lens, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_409+currStrOff, ";                            \n                        ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_409+currStrOff, rstr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_409+currStrOff, " = memoryAllocSTR(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_409+currStrOff, totStrLen, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_409+currStrOff, ");\n                        ", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    struct rope* res =  rope(____BAH_COMPILER_VAR_409)->add(rope(____BAH_COMPILER_VAR_409), cats)->add(rope(____BAH_COMPILER_VAR_409)->add(rope(____BAH_COMPILER_VAR_409), cats), rope("\n                    }\n                    "));
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
char * ____BAH_COMPILER_VAR_410 =null;
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
                        ____BAH_COMPILER_VAR_410 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_410+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_410+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_410+currStrOff, "add(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_410+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_410+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_410+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_410+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_410+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_410;
}
else if ((((strcmp(t.cont, "-") == 0)&&(subMthd!=null))&&(subMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_411 =null;
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
                        ____BAH_COMPILER_VAR_411 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, "sub(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_411+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_411;
}
else if ((((strcmp(t.cont, "*") == 0)&&(multMthd!=null))&&(multMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_412 =null;
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
                        ____BAH_COMPILER_VAR_412 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_412+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_412+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_412+currStrOff, "mult(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_412+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_412+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_412+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_412+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_412+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_412;
}
else if ((((strcmp(t.cont, "/") == 0)&&(divMthd!=null))&&(divMthd->isFn==true))) {
char * ____BAH_COMPILER_VAR_413 =null;
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
                        ____BAH_COMPILER_VAR_413 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7);
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, "div(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, pt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, ", ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, nt.cont, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_413+currStrOff, ")", strLen_7);
                        currStrOff += strLen_7;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_413;
}
else {
char * ____BAH_COMPILER_VAR_414 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Undefined operation on {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(").");
;                            
                        ____BAH_COMPILER_VAR_414 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_414+currStrOff, "Undefined operation on {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_414+currStrOff, ptt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_414+currStrOff, ").", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&pt,____BAH_COMPILER_VAR_414);
}
}
else {
char * ____BAH_COMPILER_VAR_415 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_415 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_415+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_415+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_415+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_415+currStrOff, " ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_415+currStrOff, nt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_415;
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
char * ____BAH_COMPILER_VAR_416 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_416 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_416+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_416+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_416+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_416+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_416+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_416);
}
t.type =  TOKEN_TYPE_VAR;
t.isOper =  true;
char * ____BAH_COMPILER_VAR_417 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_417 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_417+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_417+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_417;
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
array(struct Tok)* ____BAH_COMPILER_VAR_418 = nl;
return ____BAH_COMPILER_VAR_418;
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
if ((strcmp(nt.cont, "{") == 0)) {
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
if ((strcmp(t.cont, "}") == 0)) {
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
char * ____BAH_COMPILER_VAR_419 =rst.str((struct string*)&rst);char * ____BAH_COMPILER_VAR_420 =declareStructMethods(tmpV,s,elems);char * ____BAH_COMPILER_VAR_421 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_419);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvn);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen("{};\n");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_420);
;                            
                        ____BAH_COMPILER_VAR_421 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, ____BAH_COMPILER_VAR_419, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, rvn, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, "{};\n", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_421+currStrOff, ____BAH_COMPILER_VAR_420, strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    struct rope* r =  rope(____BAH_COMPILER_VAR_421);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:525): s->members[%d] with length %d\n", j, s->members->length);
                            exit(1);
                        };
                        struct structMemb* m =  s->members->data[j];
if ((strcmp(m->name, t.cont) != 0)) {
j =  j + 1;
continue;
}
char * vlt =  getTypeFromToken(&vl,true,elems);
if ((compTypes(vlt,m->type)==false)) {
char * ____BAH_COMPILER_VAR_422 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(vlt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_422 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_422+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_422+currStrOff, vlt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_422+currStrOff, ") as '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_422+currStrOff, m->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_422+currStrOff, "'.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&vl,____BAH_COMPILER_VAR_422);
}
char * ____BAH_COMPILER_VAR_423 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(vl.cont);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_423 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_423+currStrOff, rvn, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_423+currStrOff, ".", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_423+currStrOff, m->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_423+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_423+currStrOff, vl.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_423+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_423));
break;
};
if ((j==len(s->members))) {
char * ____BAH_COMPILER_VAR_424 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Struct '");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen("' has no member called {TOKEN}.");
;                            
                        ____BAH_COMPILER_VAR_424 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_424+currStrOff, "Struct '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_424+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_424+currStrOff, "' has no member called {TOKEN}.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_424);
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
char * ____BAH_COMPILER_VAR_425 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as '");
long int strLen_3 = strlen(m->type);
long int strLen_4 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_425 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, ") as '", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, m->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_425+currStrOff, "'.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_425);
}
char * ____BAH_COMPILER_VAR_426 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(rvn);
long int strLen_1 = strlen(".");
long int strLen_2 = strlen(m->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_426 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, rvn, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, ".", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, m->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_426+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    r =  r->add(r, rope(____BAH_COMPILER_VAR_426));
if ((k + 1<len(memory))) {
k =  k + 1;

                        if (memory->length <= k) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:564): memory[%d] with length %d\n", k, memory->length);
                            exit(1);
                        };
                        struct Tok st =  memory->data[k];
if ((strcmp(st.cont, ",") != 0)) {
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
array(struct Tok)* ____BAH_COMPILER_VAR_427 = nl;
return ____BAH_COMPILER_VAR_427;
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
if ((strcmp(t.cont, ".") == 0)) {
break;
}
i =  i + 1;
};
if ((i==len(line))) {
array(struct Tok)* ____BAH_COMPILER_VAR_428 = line;
return ____BAH_COMPILER_VAR_428;
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
char * ____BAH_COMPILER_VAR_429 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(v->type);
long int strLen_2 = strlen(") as a structure.");
;                            
                        ____BAH_COMPILER_VAR_429 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_429+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_429+currStrOff, v->type, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_429+currStrOff, ") as a structure.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_429);
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
char * ____BAH_COMPILER_VAR_430 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(sep);
long int strLen_2 = strlen(memb->name);
;                            
                        ____BAH_COMPILER_VAR_430 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, sep, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_430+currStrOff, memb->name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_430;
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
array(struct Tok)* ____BAH_COMPILER_VAR_431 = nl;
return ____BAH_COMPILER_VAR_431;
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
i =  i + 1;
};
if ((i==len(line))) {
array(struct Tok)* ____BAH_COMPILER_VAR_432 = line;
return ____BAH_COMPILER_VAR_432;
}
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:676): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if ((strcmp(t.cont, "[") == 0)) {
i =  i + 1;
if ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:680): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        t =  line->data[i];
if ((strcmp(t.cont, "]") == 0)) {
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
char * ____BAH_COMPILER_VAR_433 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("[]");
long int strLen_1 = strlen(arrElem);
;                            
                        ____BAH_COMPILER_VAR_433 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_433+currStrOff, "[]", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_433+currStrOff, arrElem, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    t.bahType =  ____BAH_COMPILER_VAR_433;
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
array(struct Tok)* ____BAH_COMPILER_VAR_434 = nl;
return ____BAH_COMPILER_VAR_434;
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
array(struct Tok)* ____BAH_COMPILER_VAR_435 = line;
return ____BAH_COMPILER_VAR_435;
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
if ((strcmp(t.cont, "in") == 0)) {
struct string arrT =  string(ntt);
if ((arrT.hasPrefix((struct string*)&arrT,"[]")==0)) {
char * ____BAH_COMPILER_VAR_436 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") as an array.");
;                            
                        ____BAH_COMPILER_VAR_436 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_436+currStrOff, ") as an array.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_436);
}
arrT.trimLeft((struct string*)&arrT,2);
char * ____BAH_COMPILER_VAR_437 =arrT.str((struct string*)&arrT);if ((compTypes(ptt,____BAH_COMPILER_VAR_437)==false)) {
char * ____BAH_COMPILER_VAR_438 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot search for {TOKEN} (");
long int strLen_1 = strlen(ptt);
long int strLen_2 = strlen(") inside array of type ");
long int strLen_3 = strlen(ntt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_438 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_438+currStrOff, "Cannot search for {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_438+currStrOff, ptt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_438+currStrOff, ") inside array of type ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_438+currStrOff, ntt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_438+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&pt,____BAH_COMPILER_VAR_438);
}
char * compVar =  genCompilerVar();
char * comp =  "";
if ((strcmp(ptt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_439 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("strcmp(");
long int strLen_1 = strlen(nt.cont);
long int strLen_2 = strlen("->data[i], ");
long int strLen_3 = strlen(pt.cont);
long int strLen_4 = strlen(") == 0");
;                            
                        ____BAH_COMPILER_VAR_439 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_439+currStrOff, "strcmp(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_439+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_439+currStrOff, "->data[i], ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_439+currStrOff, pt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_439+currStrOff, ") == 0", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    comp =  ____BAH_COMPILER_VAR_439;
}
else {
char * ____BAH_COMPILER_VAR_440 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nt.cont);
long int strLen_1 = strlen("->data[i] == ");
long int strLen_2 = strlen(pt.cont);
;                            
                        ____BAH_COMPILER_VAR_440 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_440+currStrOff, nt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_440+currStrOff, "->data[i] == ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_440+currStrOff, pt.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    comp =  ____BAH_COMPILER_VAR_440;
}
char * ____BAH_COMPILER_VAR_441 =null;
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
                        ____BAH_COMPILER_VAR_441 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, "\n                int ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, compVar, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, " = 0;\n                for(int i=len(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, ")-1; i != -1; i--) {\n                    if (", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, comp, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, ") {\n                        ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, compVar, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_441+currStrOff, " = 1;\n                        break;\n                    };\n                };\n                ", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_441));
pt.cont =  compVar;
}
else {
if ((compTypes(ptt,ntt)==false)) {
char * ____BAH_COMPILER_VAR_442 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot compare {TOKEN} (");
long int strLen_1 = strlen(ntt);
long int strLen_2 = strlen(") to ");
long int strLen_3 = strlen(ptt);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_442 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, "Cannot compare {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, ntt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, ") to ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, ptt, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_442+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_442);
}
if ((strcmp(ptt, "cpstring") == 0)) {
if ((strcmp(t.cont, "==") == 0)) {
char * ____BAH_COMPILER_VAR_443 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(strcmp(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(") == 0)");
;                            
                        ____BAH_COMPILER_VAR_443 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, "(strcmp(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_443+currStrOff, ") == 0)", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_443;
}
else if ((strcmp(t.cont, "!=") == 0)) {
char * ____BAH_COMPILER_VAR_444 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(strcmp(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(") != 0)");
;                            
                        ____BAH_COMPILER_VAR_444 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, "(strcmp(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_444+currStrOff, ") != 0)", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_444;
}
else if ((strcmp(t.cont, ">") == 0)) {
char * ____BAH_COMPILER_VAR_445 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") > srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_445 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_445+currStrOff, "(strlen(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_445+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_445+currStrOff, ") > srtlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_445+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_445+currStrOff, "))", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_445;
}
else if ((strcmp(t.cont, "<") == 0)) {
char * ____BAH_COMPILER_VAR_446 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") < srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_446 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, "(strlen(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, ") < srtlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_446+currStrOff, "))", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_446;
}
else if ((strcmp(t.cont, ">=") == 0)) {
char * ____BAH_COMPILER_VAR_447 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") >= srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_447 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_447+currStrOff, "(strlen(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_447+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_447+currStrOff, ") >= srtlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_447+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_447+currStrOff, "))", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_447;
}
else if ((strcmp(t.cont, "<=") == 0)) {
char * ____BAH_COMPILER_VAR_448 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(strlen(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(") <= srtlen(");
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_448 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_448+currStrOff, "(strlen(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_448+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_448+currStrOff, ") <= srtlen(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_448+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_448+currStrOff, "))", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_448;
}
}
else {
char * ____BAH_COMPILER_VAR_449 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_449 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_449+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_449+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_449+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_449+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_449+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_449;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:808): line[%d] with length %d\n", i, line->length);
                            exit(1);
                        };
                        struct Tok t =  line->data[i];
if (inArrayStr(t.cont,compSep)) {
if ((i==0)) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (nl->length <= len(nl)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:813): nl[%d] with length %d\n", len(nl)-1, nl->length);
                            exit(1);
                        };
                        struct Tok pt =  nl->data[len(nl)-1];
long int max =  i + 1;
if ((max>=len(line))) {
throwErr(&t,"Cannot use {TOKEN} to compare with nothing.");
}

                        if (line->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:818): line[%d] with length %d\n", i + 1, line->length);
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
char * ____BAH_COMPILER_VAR_450 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(pt.cont);
long int strLen_2 = strlen(t.cont);
long int strLen_3 = strlen(nt.cont);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_450 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_450+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_450+currStrOff, pt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_450+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_450+currStrOff, nt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_450+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_450;
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
array(struct Tok)* ____BAH_COMPILER_VAR_451 = nl;
return ____BAH_COMPILER_VAR_451;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:854): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_SYNTAX)) {
if ((strcmp(t.cont, "*") == 0)) {
if ((i>0)) {

                        if (nl->length <= len(nl)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:859): nl[%d] with length %d\n", len(nl)-1, nl->length);
                            exit(1);
                        };
                        struct Tok pt =  nl->data[len(nl)-1];
if ((pt.type==TOKEN_TYPE_VAR)) {
if ((i + 1<len(l))) {

                        if (l->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:862): l[%d] with length %d\n", i + 1, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i + 1];
if ((nt.isValue==false)) {
char * ____BAH_COMPILER_VAR_452 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_452 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_452+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_452+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_452;

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
char * ____BAH_COMPILER_VAR_453 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(pt.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_453 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_453+currStrOff, pt.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_453+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    pt.cont =  ____BAH_COMPILER_VAR_453;

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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:881): nl[%d] with length %d\n", len(nl)-1, nl->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:890): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i];
if ((nt.type==TOKEN_TYPE_VAR)) {
char * ____BAH_COMPILER_VAR_454 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen(nt.cont);
;                            
                        ____BAH_COMPILER_VAR_454 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_454+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_454+currStrOff, nt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nt.cont =  ____BAH_COMPILER_VAR_454;

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
array(struct Tok)* ____BAH_COMPILER_VAR_455 = nl;
return ____BAH_COMPILER_VAR_455;
};
__BAH_ARR_TYPE_Tok parseArrayVars(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
long int i =  0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:916): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:920): l[%d] with length %d\n", i, l->length);
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
array(struct Tok)* ____BAH_COMPILER_VAR_456 = l;
return ____BAH_COMPILER_VAR_456;
}

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:933): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[0];
i =  0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:936): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
long int ti =  i;
i =  i + 1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:942): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok nt =  l->data[i];
if ((strcmp(nt.cont, "[") == 0)) {
struct variable* v =  searchVar(t.cont,elems);
if ((v==null)) {
throwErr(&t,"Unknown array-var {TOKEN}.");
}
if ((strHasPrefix(v->type,"[]")==false)) {
char * ____BAH_COMPILER_VAR_457 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" (");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(") as an array.");
;                            
                        ____BAH_COMPILER_VAR_457 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, "Cannot use ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, " (", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, v->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_457+currStrOff, ") as an array.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&nt,____BAH_COMPILER_VAR_457);
}
strTrimLeft(&v->type,2);
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
i =  i + 1;
long int nbBracks =  1;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:957): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:978): memory[%d] with length %d\n", j, memory->length);
                            exit(1);
                        };
                        struct Tok mt =  memory->data[j];
char * ____BAH_COMPILER_VAR_458 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(cont);
long int strLen_1 = strlen(mt.cont);
;                            
                        ____BAH_COMPILER_VAR_458 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_458+currStrOff, cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_458+currStrOff, mt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    cont =  ____BAH_COMPILER_VAR_458;
j =  j + 1;
};
if (((ti>0)&&(strcmp(ft.cont, "else") != 0))) {
char * ____BAH_COMPILER_VAR_459 =intToStr(t.line);char * ____BAH_COMPILER_VAR_460 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n                        if (");
long int strLen_1 = strlen(t.cont);
long int strLen_2 = strlen("->length <= ");
long int strLen_3 = strlen(cont);
long int strLen_4 = strlen(") {\n                            printf(\"array (");
long int strLen_5 = strlen(compilerState.currentFile);
long int strLen_6 = strlen(":");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_459);
long int strLen_8 = strlen("): ");
long int strLen_9 = strlen(t.cont);
long int strLen_10 = strlen("[%d] with length %d\\n\", ");
long int strLen_11 = strlen(cont);
long int strLen_12 = strlen(", ");
long int strLen_13 = strlen(t.cont);
long int strLen_14 = strlen("->length);\n                            exit(1);\n                        };\n                        ");
;                            
                        ____BAH_COMPILER_VAR_460 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, "\n                        if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, "->length <= ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, ") {\n                            printf(\"array (", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, compilerState.currentFile, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, ":", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, ____BAH_COMPILER_VAR_459, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, "): ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, t.cont, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, "[%d] with length %d\\n\", ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, cont, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, ", ", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, t.cont, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_460+currStrOff, "->length);\n                            exit(1);\n                        };\n                        ", strLen_14);
                        currStrOff += strLen_14;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_460));
}
char * ____BAH_COMPILER_VAR_461 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(t.cont);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(cont);
long int strLen_3 = strlen("]");
;                            
                        ____BAH_COMPILER_VAR_461 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, t.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, "->data[", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_461+currStrOff, "]", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_461;
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
array(struct Tok)* ____BAH_COMPILER_VAR_462 = nl;
return ____BAH_COMPILER_VAR_462;
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
char * ____BAH_COMPILER_VAR_463 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_464 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__serialize(&");
long int strLen_1 = strlen(e.cont);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen("sizeof(struct ");
long int strLen_4 = strlen(____BAH_COMPILER_VAR_463);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_464 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, "__serialize(&", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, e.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, "sizeof(struct ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, ____BAH_COMPILER_VAR_463, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_464+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_464;
}
else {
char * ptrRect =  "";
while ((ptrLevel>1)) {
char * ____BAH_COMPILER_VAR_465 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ptrRect);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_465 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_465+currStrOff, ptrRect, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_465+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ptrRect =  ____BAH_COMPILER_VAR_465;
ptrLevel =  ptrLevel - 1;
};
char * ____BAH_COMPILER_VAR_466 =svt.str((struct string*)&svt);char * ____BAH_COMPILER_VAR_467 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__serialize(");
long int strLen_1 = strlen(ptrRect);
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen(", ");
long int strLen_4 = strlen("sizeof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_466);
long int strLen_6 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_467 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, "__serialize(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, ptrRect, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, e.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, ", ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, "sizeof(struct ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, ____BAH_COMPILER_VAR_466, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_467+currStrOff, ")", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_467;
long int i =  0;
while ((i<len(s->members))) {

                        if (s->members->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1042): s->members[%d] with length %d\n", i, s->members->length);
                            exit(1);
                        };
                        struct structMemb* m =  s->members->data[i];
if ((strcmp(m->type, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_468 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("+strlen(");
long int strLen_2 = strlen(e.cont);
long int strLen_3 = strlen("->");
long int strLen_4 = strlen(m->name);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_468 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, "+strlen(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, e.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, "->", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, m->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_468+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_468;
}
i =  i + 1;
};
}
char * ____BAH_COMPILER_VAR_469 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_469 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_469+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_469+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * ____BAH_COMPILER_VAR_470 = ____BAH_COMPILER_VAR_469;
return ____BAH_COMPILER_VAR_470;
};
struct Tok parseReflect(struct Tok t,char * tt,struct Elems* elems,int parsedPointer,char * ogName,char * offset){
char * isArr =  "0";
char * arrElem =  "0";
if (strHasPrefix(tt,"[]")) {
isArr =  "1";
struct string aet =  string(tt);
aet.trimLeft((struct string*)&aet,2);
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
struct Tok tmpT =  ____BAH_COMPILER_VAR_471;
tmpT.cont =  "0";
char * ____BAH_COMPILER_VAR_472 =aet.str((struct string*)&aet);struct Tok rt =  parseReflect(tmpT,____BAH_COMPILER_VAR_472,elems,true,"","0");
char * aev =  genCompilerVar();
char * ____BAH_COMPILER_VAR_473 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n        struct reflectElement ");
long int strLen_1 = strlen(aev);
long int strLen_2 = strlen(" = ");
long int strLen_3 = strlen(rt.cont);
long int strLen_4 = strlen(";\n        ");
;                            
                        ____BAH_COMPILER_VAR_473 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_473+currStrOff, "\n        struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_473+currStrOff, aev, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_473+currStrOff, " = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_473+currStrOff, rt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_473+currStrOff, ";\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_473));
char * ____BAH_COMPILER_VAR_474 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("&");
long int strLen_1 = strlen(aev);
;                            
                        ____BAH_COMPILER_VAR_474 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_474+currStrOff, "&", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_474+currStrOff, aev, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    arrElem =  ____BAH_COMPILER_VAR_474;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1094): ts->members[%d] with length %d\n", i, ts->members->length);
                            exit(1);
                        };
                        struct structMemb* m =  ts->members->data[i];
struct Tok ____BAH_COMPILER_VAR_475 = {};
____BAH_COMPILER_VAR_475.cont = "";
____BAH_COMPILER_VAR_475.ogCont = "";
____BAH_COMPILER_VAR_475.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_475.pos = 0;
____BAH_COMPILER_VAR_475.line = 1;
____BAH_COMPILER_VAR_475.begLine = 1;
____BAH_COMPILER_VAR_475.bahType = "";
____BAH_COMPILER_VAR_475.isValue = false;
____BAH_COMPILER_VAR_475.isFunc = false;
____BAH_COMPILER_VAR_475.isOper = false;
struct Tok tmpT =  ____BAH_COMPILER_VAR_475;
char * sep =  "->";
if ((strCount(tt,"*")==0)) {
sep =  ".";
}
struct string mCtype =  getCType(m->type,elems);
struct string offsetTT =  string(tt);
offsetTT.replace((struct string*)&offsetTT,"*","");
char * ____BAH_COMPILER_VAR_476 =mCtype.str((struct string*)&mCtype);char * ____BAH_COMPILER_VAR_477 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_478 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_476);
long int strLen_2 = strlen("*)((char*)(");
long int strLen_3 = strlen(t.cont);
long int strLen_4 = strlen(") + offsetof(struct ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_477);
long int strLen_6 = strlen(", ");
long int strLen_7 = strlen(m->name);
long int strLen_8 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_478 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, ____BAH_COMPILER_VAR_476, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, "*)((char*)(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, t.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, ") + offsetof(struct ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, ____BAH_COMPILER_VAR_477, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, ", ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, m->name, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_478+currStrOff, "))", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    tmpT.cont =  ____BAH_COMPILER_VAR_478;
char * ____BAH_COMPILER_VAR_479 =offsetTT.str((struct string*)&offsetTT);char * ____BAH_COMPILER_VAR_480 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("offsetof(struct ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_479);
long int strLen_2 = strlen(", ");
long int strLen_3 = strlen(m->name);
long int strLen_4 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_480 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_480+currStrOff, "offsetof(struct ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_480+currStrOff, ____BAH_COMPILER_VAR_479, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_480+currStrOff, ", ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_480+currStrOff, m->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_480+currStrOff, ")", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    struct Tok rt =  parseReflect(tmpT,m->type,elems,true,m->name,____BAH_COMPILER_VAR_480);
char * ____BAH_COMPILER_VAR_481 =intToStr(i);char * ____BAH_COMPILER_VAR_482 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(structLayout);
long int strLen_1 = strlen("->data[");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_481);
long int strLen_3 = strlen("] = ");
long int strLen_4 = strlen(rt.cont);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_482 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_482+currStrOff, structLayout, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_482+currStrOff, "->data[", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_482+currStrOff, ____BAH_COMPILER_VAR_481, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_482+currStrOff, "] = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_482+currStrOff, rt.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_482+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    dataLayout =  dataLayout->add(dataLayout, rope(____BAH_COMPILER_VAR_482));
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_483 =intToStr(len(ts->members));char * ____BAH_COMPILER_VAR_484 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n        array(struct reflectElement) * ");
long int strLen_1 = strlen(structLayout);
long int strLen_2 = strlen(" = memoryAlloc(sizeof(array(struct reflectElement)));\n        ");
long int strLen_3 = strlen(structLayout);
long int strLen_4 = strlen("->elemSize = sizeof(struct reflectElement);\n        ");
long int strLen_5 = strlen(structLayout);
long int strLen_6 = strlen("->length = ");
long int strLen_7 = strlen(____BAH_COMPILER_VAR_483);
long int strLen_8 = strlen(";\n        ");
long int strLen_9 = strlen(structLayout);
long int strLen_10 = strlen("->data = memoryAlloc(");
long int strLen_11 = strlen(structLayout);
long int strLen_12 = strlen("->length * ");
long int strLen_13 = strlen(structLayout);
long int strLen_14 = strlen("->elemSize);\n        ");
;                            
                        ____BAH_COMPILER_VAR_484 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14);
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "\n        array(struct reflectElement) * ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, structLayout, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, " = memoryAlloc(sizeof(array(struct reflectElement)));\n        ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, structLayout, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "->elemSize = sizeof(struct reflectElement);\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, structLayout, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "->length = ", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, ____BAH_COMPILER_VAR_483, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, ";\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, structLayout, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "->data = memoryAlloc(", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, structLayout, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "->length * ", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, structLayout, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_484+currStrOff, "->elemSize);\n        ", strLen_14);
                        currStrOff += strLen_14;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_484))->add(OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_484)), dataLayout);
}
char * amp =  "";
if (((((strCount(tt,"*")==0)&&(strcmp(tt, "cpstring") != 0))&&(strcmp(tt, "ptr") != 0))&&(parsedPointer==false))) {
amp =  "&";
}
struct string name =  string(ogName);
if ((hasStructSep(name)==true)) {
name =  splitStructSepAfter(name);
}
struct string cType =  getCType(tt,elems);
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
char * ____BAH_COMPILER_VAR_485 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_486 =name.str((struct string*)&name);char * ____BAH_COMPILER_VAR_487 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("struct reflectElement ");
long int strLen_1 = strlen(rv->name);
long int strLen_2 = strlen(" = __reflect(");
long int strLen_3 = strlen(amp);
long int strLen_4 = strlen(t.cont);
long int strLen_5 = strlen(", sizeof(");
long int strLen_6 = strlen(____BAH_COMPILER_VAR_485);
long int strLen_7 = strlen("), \"");
long int strLen_8 = strlen(tt);
long int strLen_9 = strlen("\", \"");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_486);
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
                        ____BAH_COMPILER_VAR_487 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20 + strLen_21);
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, "struct reflectElement ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, rv->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, " = __reflect(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, amp, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, t.cont, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, ", sizeof(", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, ____BAH_COMPILER_VAR_485, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, "), \"", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, tt, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, "\", \"", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, ____BAH_COMPILER_VAR_486, strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, "\", ", strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, isArr, strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, ", ", strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, arrElem, strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, ", ", strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, isStruct, strLen_16);
                        currStrOff += strLen_16;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, ", ", strLen_17);
                        currStrOff += strLen_17;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, structLayout, strLen_18);
                        currStrOff += strLen_18;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, ", ", strLen_19);
                        currStrOff += strLen_19;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, offset, strLen_20);
                        currStrOff += strLen_20;
                        
                        strncpy(____BAH_COMPILER_VAR_487+currStrOff, ");\n", strLen_21);
                        currStrOff += strLen_21;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_487));
t.cont =  rv->name;
struct Tok ____BAH_COMPILER_VAR_488 = t;
return ____BAH_COMPILER_VAR_488;
};
__BAH_ARR_TYPE_Tok parseFnCall(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);
int found =  false;
long int i =  0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1152): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
if ((t.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1156): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((strcmp(t.cont, "(") == 0)) {
found =  true;
break;
}
}
}
i =  i + 1;
};
if ((found==false)) {
array(struct Tok)* ____BAH_COMPILER_VAR_489 = l;
return ____BAH_COMPILER_VAR_489;
}
i =  0;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1171): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok ot =  l->data[i];
if ((ot.type==TOKEN_TYPE_VAR)) {
i =  i + 1;
if ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1176): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1189): fn->args[%d] with length %d\n", 0, fn->args->length);
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
char * ____BAH_COMPILER_VAR_490 =fnarg1t.str((struct string*)&fnarg1t);char * ____BAH_COMPILER_VAR_491 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_490);
long int strLen_2 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_491 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_491+currStrOff, "(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_491+currStrOff, ____BAH_COMPILER_VAR_490, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_491+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    varName.prepend((struct string*)&varName,____BAH_COMPILER_VAR_491);
}
char * ____BAH_COMPILER_VAR_492 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fnName);
long int strLen_1 = strlen("(");
;                            
                        ____BAH_COMPILER_VAR_492 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_492+currStrOff, fnName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_492+currStrOff, "(", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_492;
array(struct variable*)* fnArgs =  fn->args;
long int paramIndex =  0;
array(struct Tok)* memory = memoryAlloc(sizeof(array(struct Tok)));

memory->length = 0;
memory->elemSize = sizeof(struct Tok);
if ((varName.length>0)) {
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
struct Tok tk =  ____BAH_COMPILER_VAR_493;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1223): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        nt =  l->data[i];
if ((strcmp(nt.cont, ")") != 0)) {
struct Tok ____BAH_COMPILER_VAR_494 = {};
____BAH_COMPILER_VAR_494.cont = "";
____BAH_COMPILER_VAR_494.ogCont = "";
____BAH_COMPILER_VAR_494.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_494.pos = 0;
____BAH_COMPILER_VAR_494.line = 1;
____BAH_COMPILER_VAR_494.begLine = 1;
____BAH_COMPILER_VAR_494.bahType = "";
____BAH_COMPILER_VAR_494.isValue = false;
____BAH_COMPILER_VAR_494.isFunc = false;
____BAH_COMPILER_VAR_494.isOper = false;
tk =  ____BAH_COMPILER_VAR_494;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1233): l[%d] with length %d\n", i, l->length);
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
long int j =  0;
while ((j<len(memory))) {

                        if (memory->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1249): memory[%d] with length %d\n", j, memory->length);
                            exit(1);
                        };
                        struct Tok t =  memory->data[j];
char * ____BAH_COMPILER_VAR_495 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_495 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_495+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_495+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_495+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_495;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1263): memory[%d] with length %d\n", 0, memory->length);
                            exit(1);
                        };
                        struct Tok ft =  memory->data[0];
if ((strcmp(ft.cont, ")") != 0)) {
long int j =  0;
while ((j<len(memory))) {

                        if (memory->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1267): memory[%d] with length %d\n", j, memory->length);
                            exit(1);
                        };
                        struct Tok t =  memory->data[j];
if ((paramIndex>=len(fnArgs))) {
throwErr(&t,"Too many arguments in function call.");
}

                        if (fnArgs->length <= paramIndex) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1272): fnArgs[%d] with length %d\n", paramIndex, fnArgs->length);
                            exit(1);
                        };
                        struct variable* arg =  fnArgs->data[paramIndex];
char * tt =  getTypeFromToken(&t,true,elems);
if (((strcmp(arg->type, "reflectElement") == 0)&&(strcmp(tt, "reflectElement") != 0))) {
t =  parseReflect(t,tt,elems,false,t.cont,"0");
tt =  "reflectElement";
}
if ((compTypes(tt,arg->type)==false)) {
char * ____BAH_COMPILER_VAR_496 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(arg->type);
long int strLen_4 = strlen(" in function call.");
;                            
                        ____BAH_COMPILER_VAR_496 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_496+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_496+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_496+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_496+currStrOff, arg->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_496+currStrOff, " in function call.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_496);
}
if (((t.type==TOKEN_TYPE_FUNC)&&(strHasPrefix(t.cont,"noCheck(")==false))) {
struct string ____BAH_COMPILER_VAR_497 =string(t.cont);char * afnName =  splitStringBefore(____BAH_COMPILER_VAR_497,"(");
struct func* afn =  searchFunc(afnName,elems,true);
if (((afn!=null)&&(isRCPtype(afn->returns->type,elems)==true))) {
t.cont =  registerRCPvar(afn->returns->type,t.cont,elems);
}
}
char * ____BAH_COMPILER_VAR_498 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_498 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_498+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_498+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_498;
j =  j + 1;

                        if (memory->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1294): memory[%d] with length %d\n", j, memory->length);
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
char * ____BAH_COMPILER_VAR_499 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_499 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_499+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_499+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_499;
}
j =  j + 1;
};
}
if ((paramIndex<len(fnArgs))) {
ot.cont =  fnName;
throwErr(&ot,"Not enough arguments in function call, ending by {TOKEN}.");
}
if ((strcmp(fn->name, "ser") == 0)) {
ot.cont =  parseSerialize(memory->data[0],elems);
}
else {
char * ____BAH_COMPILER_VAR_500 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ot.cont);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_500 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_500+currStrOff, ot.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_500+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    ot.cont =  ____BAH_COMPILER_VAR_500;
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
array(struct Tok)* ____BAH_COMPILER_VAR_501 = nl;
return ____BAH_COMPILER_VAR_501;
};
void parseVar(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1344): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[0];
if ((ft.isFunc==true)) {
if ((len(l)>1)) {
throwErr(&l->data[len(l)-1],"Not expecting {TOKEN} after function call.");
}

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1349): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        ft =  l->data[0];
int parsed =  true;
char * ____BAH_COMPILER_VAR_502 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_502 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_502+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_502));
return;
}
l =  parseStructType(l,elems);
int isEqual =  false;
int toVar =  false;
int isPointedVar =  false;
int isStruct =  false;
char * currentType =  "";

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1360): l[%d] with length %d\n", 0, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1383): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok lt =  l->data[1];
if ((((lt.type==TOKEN_TYPE_SYNTAX)&&(strcmp(lt.cont, "++") == 0))||(strcmp(lt.cont, "--") == 0))) {
if ((exists==false)) {
char * ____BAH_COMPILER_VAR_504 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use '");
long int strLen_1 = strlen(lt.cont);
long int strLen_2 = strlen("' on non declared {TOKEN} variable.");
;                            
                        ____BAH_COMPILER_VAR_504 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, "Cannot use '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, lt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_504+currStrOff, "' on non declared {TOKEN} variable.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&ft,____BAH_COMPILER_VAR_504);
}
array(struct Tok)* nl = memoryAlloc(sizeof(array(struct Tok)));

nl->length = 0;
nl->elemSize = sizeof(struct Tok);

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1389): l[%d] with length %d\n", 0, l->length);
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
struct Tok ____BAH_COMPILER_VAR_505 = {};
____BAH_COMPILER_VAR_505.cont = "";
____BAH_COMPILER_VAR_505.ogCont = "";
____BAH_COMPILER_VAR_505.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_505.pos = 0;
____BAH_COMPILER_VAR_505.line = 1;
____BAH_COMPILER_VAR_505.begLine = 1;
____BAH_COMPILER_VAR_505.bahType = "";
____BAH_COMPILER_VAR_505.isValue = false;
____BAH_COMPILER_VAR_505.isFunc = false;
____BAH_COMPILER_VAR_505.isOper = false;
____BAH_COMPILER_VAR_505.type = TOKEN_TYPE_SYNTAX;
____BAH_COMPILER_VAR_505.cont = "=";
____BAH_COMPILER_VAR_505.isValue = false;

{
long nLength = 1;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[1] =  ____BAH_COMPILER_VAR_505;
nl->length = nLength+1;
} else {
nl->data[1] =  ____BAH_COMPILER_VAR_505;
}
};
char * c =  "";
if ((strcmp(lt.cont, "++") == 0)) {
char * ____BAH_COMPILER_VAR_506 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("+1");
;                            
                        ____BAH_COMPILER_VAR_506 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_506+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_506+currStrOff, "+1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    c =  ____BAH_COMPILER_VAR_506;
}
else if ((strcmp(lt.cont, "--") == 0)) {
char * ____BAH_COMPILER_VAR_507 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen("-1");
;                            
                        ____BAH_COMPILER_VAR_507 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_507+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_507+currStrOff, "-1", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    c =  ____BAH_COMPILER_VAR_507;
}
long int ltl =  lt.line;
long int ltp =  lt.pos;
char * ltc =  lt.cont;
struct Tok ____BAH_COMPILER_VAR_508 = {};
____BAH_COMPILER_VAR_508.cont = "";
____BAH_COMPILER_VAR_508.ogCont = "";
____BAH_COMPILER_VAR_508.type = TOKEN_NO_TYPE;
____BAH_COMPILER_VAR_508.pos = 0;
____BAH_COMPILER_VAR_508.line = 1;
____BAH_COMPILER_VAR_508.begLine = 1;
____BAH_COMPILER_VAR_508.bahType = "";
____BAH_COMPILER_VAR_508.isValue = false;
____BAH_COMPILER_VAR_508.isFunc = false;
____BAH_COMPILER_VAR_508.isOper = false;
____BAH_COMPILER_VAR_508.type = TOKEN_TYPE_INT;
____BAH_COMPILER_VAR_508.cont = c;
____BAH_COMPILER_VAR_508.line = ltl;
____BAH_COMPILER_VAR_508.ogCont = ltc;
____BAH_COMPILER_VAR_508.pos = ltp;
____BAH_COMPILER_VAR_508.isOper = true;
____BAH_COMPILER_VAR_508.isValue = true;

{
long nLength = 2;
if (nl->length < nLength+1) {
if ((nLength+1) % 50 == 0 || nLength == 0) {
void * newPtr = memoryRealloc(nl->data, (nLength+50)*sizeof(struct Tok));
nl->data = newPtr;
}
nl->data[2] =  ____BAH_COMPILER_VAR_508;
nl->length = nLength+1;
} else {
nl->data[2] =  ____BAH_COMPILER_VAR_508;
}
};
l =  nl;
}
}
long int i =  1;
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1422): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_509 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(currentType);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_509 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_509+currStrOff, currentType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_509+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_509+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    currentType =  ____BAH_COMPILER_VAR_509;
}
else {
if ((strcmp(t.cont, "new") == 0)) {
isStruct =  true;
long int max =  i + 1;
if ((max>=len(l))) {
throwErr(&t,"Cannot initiate {TOKEN} struct without specifying struct name.");
}
max =  max + 1;
if ((max<len(l))) {

                        if (l->length <= i + 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1446): l[%d] with length %d\n", i + 2, l->length);
                            exit(1);
                        };
                        t =  l->data[i + 2];
throwErr(&t,"{TOKEN} not expected after initiating new struct.");
}

                        if (l->length <= i + 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1449): l[%d] with length %d\n", i + 1, l->length);
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
char * ____BAH_COMPILER_VAR_510 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("memoryAlloc(sizeof(");
long int strLen_1 = strlen(vectStr);
long int strLen_2 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_510 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_510+currStrOff, "memoryAlloc(sizeof(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_510+currStrOff, vectStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_510+currStrOff, "))", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_510;
char * ____BAH_COMPILER_VAR_511 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_511 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_511+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    v->type =  ____BAH_COMPILER_VAR_511;
NEXT_LINE =  declareStructMethods(v,s,elems);
break;
}
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as value in var declaration.");
}
char * tp =  getTypeFromToken(&t,true,elems);
if ((exists==true)) {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_512 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_512 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_512+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_512+currStrOff, tp, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_512+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_512+currStrOff, v->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_512+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_512);
}
}
else {
if ((strlen(currentType)==0)) {
if ((strlen(v->type)==0)) {
v->type =  tp;
}
else {
if ((compTypes(tp,v->type)==false)) {
char * ____BAH_COMPILER_VAR_513 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tp);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(v->type);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_513 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, tp, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, v->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_513+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_513);
}
}
}
}
if (((strlen(t.cont)>0)&&(strHasPrefix(t.cont,"{")==false))) {
char * ____BAH_COMPILER_VAR_514 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_514 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_514+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_514+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_514+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_514;
if (((t.isOper==false)&&(RCPavailable()==true))) {
struct variable* iv =  searchVar(t.cont,elems);
if (((iv!=null)&&(iv->isConst==false))) {
toVar =  true;
isPointedVar =  strHasPrefix(t.cont,"&");
struct cStruct* s =  searchStruct(iv->type,elems);
if ((((s!=null)&&(strCount(iv->type,"*")==0))&&(s->isBinding==false))) {
if ((strCount(iv->name,"*")==0)) {
char * ____BAH_COMPILER_VAR_515 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incrCounter(");
long int strLen_2 = strlen(iv->name);
long int strLen_3 = strlen(".__RCP_counter)");
;                            
                        ____BAH_COMPILER_VAR_515 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, "; RCP_incrCounter(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, iv->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_515+currStrOff, ".__RCP_counter)", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_515;
}
else {
struct string ivn =  string(iv->name);
ivn.replace((struct string*)&ivn,"*","");
char * ____BAH_COMPILER_VAR_516 =ivn.str((struct string*)&ivn);char * ____BAH_COMPILER_VAR_517 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("; RCP_incr(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_516);
long int strLen_3 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_517 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, "; RCP_incr(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, ____BAH_COMPILER_VAR_516, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_517+currStrOff, ")", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_517;
}
}
}
}
break;
}
if (strHasPrefix(v->type,"[]")) {
struct string arrType =  getCType(v->type,elems);
arrType.trimRight((struct string*)&arrType,1);
char * ____BAH_COMPILER_VAR_518 =arrType.str((struct string*)&arrType);char * ____BAH_COMPILER_VAR_519 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("memoryAlloc(sizeof(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_518);
long int strLen_2 = strlen("))");
;                            
                        ____BAH_COMPILER_VAR_519 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_519+currStrOff, "memoryAlloc(sizeof(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_519+currStrOff, ____BAH_COMPILER_VAR_518, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_519+currStrOff, "))", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_519;
arrType.trimLeft((struct string*)&arrType,6);
arrType.trimRight((struct string*)&arrType,1);
char * elemTypeStr =  arrType.str((struct string*)&arrType);
long int max =  i + 1;
if ((max!=len(l))) {
i =  i + 1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1517): l[%d] with length %d\n", i, l->length);
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
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1527): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1532): memory[%d] with length %d\n", i, memory->length);
                            exit(1);
                        };
                        t =  memory->data[i];
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,elemBahTypeStr)==false)) {
char * ____BAH_COMPILER_VAR_520 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(elemBahTypeStr);
;                            
                        ____BAH_COMPILER_VAR_520 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_520+currStrOff, elemBahTypeStr, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_520);
}
char * strArrayLength =  intToStr(arrayLength);
arrayLength =  arrayLength + 1;
if ((strcmp(tt, "cpstring") == 0)) {
char * ____BAH_COMPILER_VAR_521 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__STR(");
long int strLen_1 = strlen(t.cont);
long int strLen_2 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_521 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_521+currStrOff, "__STR(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_521+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_521+currStrOff, ")", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_521;
}
char * ____BAH_COMPILER_VAR_522 =null;
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
                        ____BAH_COMPILER_VAR_522 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, NEXT_LINE, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, "->data[", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, strArrayLength, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, "] = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, t.cont, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_522+currStrOff, ";\n", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    NEXT_LINE =  ____BAH_COMPILER_VAR_522;
i =  i + 1;

                        if (memory->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1547): memory[%d] with length %d\n", i, memory->length);
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
char * ____BAH_COMPILER_VAR_523 =null;
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
                        ____BAH_COMPILER_VAR_523 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_523+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_523+currStrOff, "->data = memoryAlloc(sizeof(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_523+currStrOff, elemTypeStr, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_523+currStrOff, ") * ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_523+currStrOff, allocLengthStr, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_523+currStrOff, ");", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_523+currStrOff, NEXT_LINE, strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    NEXT_LINE =  ____BAH_COMPILER_VAR_523;
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
char * ____BAH_COMPILER_VAR_524 =null;
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
                        ____BAH_COMPILER_VAR_524 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9);
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, "\n", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, "->length = ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, strArrayLength, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, v->name, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, "->elemSize = sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, elemTypeStr, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, ");\n", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_524+currStrOff, NEXT_LINE, strLen_9);
                        currStrOff += strLen_9;
                        
                    }
                    NEXT_LINE =  ____BAH_COMPILER_VAR_524;
break;
}
isStruct =  true;
long int max =  i + 1;
if ((max!=len(l))) {
throwErr(&l->data[i + 1],"{TOKEN} not expected after struct initialization.");
}
char * ____BAH_COMPILER_VAR_525 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_525 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_525+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_525+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_525+currStrOff, t.cont, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_525;
}
i =  i + 1;
};
if ((exists==true)) {
if ((strlen(code)==0)) {
throwErr(&ft,"Cannot re-declare {TOKEN}.");
}
if ((strlen(currentType)>0)) {

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1594): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok st =  l->data[1];
char * ____BAH_COMPILER_VAR_526 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot change the type of already declared var '");
long int strLen_1 = strlen(ft.cont);
long int strLen_2 = strlen("' to {TOKEN}.");
;                            
                        ____BAH_COMPILER_VAR_526 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_526+currStrOff, "Cannot change the type of already declared var '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_526+currStrOff, ft.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_526+currStrOff, "' to {TOKEN}.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&st,____BAH_COMPILER_VAR_526);
}
if ((isStruct==false)) {
if (((isRCPpointerType(v->type)&&(isPointedVar==false))&&(RCPavailable()==true))) {
struct string cType =  getCType(v->type,elems);
if ((toVar==true)) {
if ((RCPselfRef(v)==false)) {
char * ____BAH_COMPILER_VAR_527 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_528 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_529 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("*(");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_527);
long int strLen_2 = strlen("*)RCP_decrIL(&");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(") = *(");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_528);
long int strLen_6 = strlen("*)RCP_incrIL(&");
long int strLen_7 = strlen(code);
long int strLen_8 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_529 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8);
                        
                        strncpy(____BAH_COMPILER_VAR_529+currStrOff, "*(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_529+currStrOff, ____BAH_COMPILER_VAR_527, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_529+currStrOff, "*)RCP_decrIL(&", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_529+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_529+currStrOff, ") = *(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_529+currStrOff, ____BAH_COMPILER_VAR_528, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_529+currStrOff, "*)RCP_incrIL(&", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_529+currStrOff, code, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_529+currStrOff, ")", strLen_8);
                        currStrOff += strLen_8;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_529;
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
char * ____BAH_COMPILER_VAR_530 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_531 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_532 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_533 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_530);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = *(");
long int strLen_8 = strlen(____BAH_COMPILER_VAR_531);
long int strLen_9 = strlen("*)RCP_incrIL(&");
long int strLen_10 = strlen(code);
long int strLen_11 = strlen(");");
long int strLen_12 = strlen(____BAH_COMPILER_VAR_532);
;                            
                        ____BAH_COMPILER_VAR_533 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12);
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, ____BAH_COMPILER_VAR_530, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, tmpV->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, "; ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, " = *(", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, ____BAH_COMPILER_VAR_531, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, "*)RCP_incrIL(&", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, code, strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, ");", strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_533+currStrOff, ____BAH_COMPILER_VAR_532, strLen_12);
                        currStrOff += strLen_12;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_533;
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
char * ____BAH_COMPILER_VAR_534 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_535 =dv->toStr((struct rope*)dv);char * ____BAH_COMPILER_VAR_536 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_534);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(tmpV->name);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(v->name);
long int strLen_5 = strlen("; ");
long int strLen_6 = strlen(v->name);
long int strLen_7 = strlen(" = ");
long int strLen_8 = strlen(code);
long int strLen_9 = strlen(";");
long int strLen_10 = strlen(____BAH_COMPILER_VAR_535);
;                            
                        ____BAH_COMPILER_VAR_536 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10);
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, ____BAH_COMPILER_VAR_534, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, tmpV->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, v->name, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, "; ", strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, v->name, strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, " = ", strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, code, strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, ";", strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_536+currStrOff, ____BAH_COMPILER_VAR_535, strLen_10);
                        currStrOff += strLen_10;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_536;
}
}
else {
struct cStruct* s =  searchStruct(v->type,elems);
if ((((((s!=null)&&(RCPavailable()==true))&&(RCPselfRef(v)==false))&&(s->isBinding==false))&&(strCount(v->name,"*")==0))) {
char * ____BAH_COMPILER_VAR_537 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("RCP_decrCounter(");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(".__RCP_counter); ");
long int strLen_3 = strlen(v->name);
long int strLen_4 = strlen(" = ");
long int strLen_5 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_537 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, "RCP_decrCounter(", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, ".__RCP_counter); ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, v->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, " = ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_537+currStrOff, code, strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_537;
}
else {
char * ____BAH_COMPILER_VAR_538 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_538 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_538+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_538;
}
}
}
else {
strTrim(&code);
if ((strHasPrefix(code,"{")==false)) {
char * ____BAH_COMPILER_VAR_539 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_539 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_539+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_539+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_539+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_539;
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
char * ____BAH_COMPILER_VAR_540 =null;
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
                        ____BAH_COMPILER_VAR_540 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16);
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, "\n{\nlong nLength = ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, nLengthStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, ";\nif (", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, nstr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, "->length < nLength+1) {\nif ((nLength+1) % 50 == 0 || nLength == 0) {\nvoid * newPtr = memoryRealloc(", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, nstr, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, "->data, (nLength+50)*sizeof(", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, elemTypeStr, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, "));\n", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, nstr, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, "->data = newPtr;\n}\n", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, code, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, ";\n", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, nstr, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, "->length = nLength+1;\n} else {\n", strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, code, strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_540+currStrOff, ";\n}\n}", strLen_16);
                        currStrOff += strLen_16;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_540;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1693): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                            exit(1);
                        };
                        struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_541 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_542 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_541);
;                            
                        ____BAH_COMPILER_VAR_542 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_542+currStrOff, ____BAH_COMPILER_VAR_541, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_542;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_543 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_543 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_543+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_543+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_543;
}
};
char * ____BAH_COMPILER_VAR_544 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_545 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_544);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_545 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, ____BAH_COMPILER_VAR_544, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_545+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    vct =  ____BAH_COMPILER_VAR_545;
}
else {
vct =  setCType(v,elems);
}
if ((strlen(code)>0)) {
if ((((isRCPpointerType(v->type)&&(RCPavailable()==true))&&(toVar==true))&&(isPointedVar==false))) {
struct string cType =  getCType(v->type,elems);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_546 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_547 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_546);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_547 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, " = *(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, ____BAH_COMPILER_VAR_546, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, "*)RCP_incrIL(&", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, code, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_547+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_547));
}
else {
char * ____BAH_COMPILER_VAR_548 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_549 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = *(");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_548);
long int strLen_3 = strlen("*)RCP_incrIL(&");
long int strLen_4 = strlen(code);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_549 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, " = *(", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, ____BAH_COMPILER_VAR_548, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, "*)RCP_incrIL(&", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, code, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_549+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_549;
}
}
else {
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_550 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(v->name);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
long int strLen_3 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_550 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_550+currStrOff, v->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_550+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_550+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_550+currStrOff, ";\n", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    INIT =  INIT->add(INIT, rope(____BAH_COMPILER_VAR_550));
}
else {
char * ____BAH_COMPILER_VAR_551 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(" = ");
long int strLen_2 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_551 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_551+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_551+currStrOff, " = ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_551+currStrOff, code, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_551;
}
}
}
else {
if (isRCPpointerType(v->type)) {
char * ____BAH_COMPILER_VAR_552 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen("= null");
;                            
                        ____BAH_COMPILER_VAR_552 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_552+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_552+currStrOff, "= null", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_552;
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
struct reflectElement ____BAH_COMPILER_VAR_554 = __reflect((char **)((char*)(v) + offsetof(struct variable, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_555 = __reflect((char **)((char*)(v) + offsetof(struct variable, type)), sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_556 = __reflect((int*)((char*)(v) + offsetof(struct variable, isConst)), sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_557 = __reflect((char **)((char*)(v) + offsetof(struct variable, constVal)), sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_558 = __reflect((int*)((char*)(v) + offsetof(struct variable, isArray)), sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_559 = __reflect((char **)((char*)(v) + offsetof(struct variable, from)), sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_560 = __reflect((int*)((char*)(v) + offsetof(struct variable, outterScope)), sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_553 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_553->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_553->length = 7;
        ____BAH_COMPILER_VAR_553->data = memoryAlloc(____BAH_COMPILER_VAR_553->length * ____BAH_COMPILER_VAR_553->elemSize);
        ____BAH_COMPILER_VAR_553->data[0] = ____BAH_COMPILER_VAR_554;
____BAH_COMPILER_VAR_553->data[1] = ____BAH_COMPILER_VAR_555;
____BAH_COMPILER_VAR_553->data[2] = ____BAH_COMPILER_VAR_556;
____BAH_COMPILER_VAR_553->data[3] = ____BAH_COMPILER_VAR_557;
____BAH_COMPILER_VAR_553->data[4] = ____BAH_COMPILER_VAR_558;
____BAH_COMPILER_VAR_553->data[5] = ____BAH_COMPILER_VAR_559;
____BAH_COMPILER_VAR_553->data[6] = ____BAH_COMPILER_VAR_560;
struct reflectElement ____BAH_COMPILER_VAR_561 = __reflect(v, sizeof(struct variable*), "variable*", "v", 0, 0, 1, ____BAH_COMPILER_VAR_553, 0);
debugPrint("var_declaration",ft.line,____BAH_COMPILER_VAR_561);
if (isGlobal()) {
char * ____BAH_COMPILER_VAR_562 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(vct);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_562 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, vct, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_562+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_562));
}
}
if (isGlobal()) {
INIT =  INIT->add(INIT, rope(NEXT_LINE));
NEXT_LINE =  "";
}
else {
char * ____BAH_COMPILER_VAR_563 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_563 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_563+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_563+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_563));
}
};
char * getCfunctionType(struct string cfrt,char * elemName,struct Elems* elems){
struct func* tmpfn =  parseFnType(cfrt);
struct string tmpfnRetCType =  getCType(tmpfn->returns->type,elems);
char * tmpfnArgsCType =  "";
long int j =  0;
while ((j<len(tmpfn->args))) {

                        if (tmpfn->args->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1755): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                            exit(1);
                        };
                        struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_564 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_565 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_564);
;                            
                        ____BAH_COMPILER_VAR_565 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_565+currStrOff, ____BAH_COMPILER_VAR_564, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_565;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_566 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_566 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_566+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_566+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_566;
}
};
char * ____BAH_COMPILER_VAR_567 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_568 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_567);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(elemName);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_568 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, ____BAH_COMPILER_VAR_567, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, elemName, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_568+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    char * ____BAH_COMPILER_VAR_569 = ____BAH_COMPILER_VAR_568;
return ____BAH_COMPILER_VAR_569;
};
char * parseFnHeader(char * prev,__BAH_ARR_TYPE_Tok l,long int* i,struct func* fn,struct Elems* elems){
long int j =  *i;

                        if (l->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1771): l[%d] with length %d\n", j, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[j];
char * tpdf =  "";
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as function name.");
}
char * ____BAH_COMPILER_VAR_570 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(prev);
long int strLen_1 = strlen(ft.cont);
;                            
                        ____BAH_COMPILER_VAR_570 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, prev, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_570+currStrOff, ft.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fn->name =  ____BAH_COMPILER_VAR_570;
array(struct variable*)* arguments = memoryAlloc(sizeof(array(struct variable*)));

arguments->length = 0;
arguments->elemSize = sizeof(struct variable*);
char * ____BAH_COMPILER_VAR_571 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fn->name);
long int strLen_1 = strlen("(");
;                            
                        ____BAH_COMPILER_VAR_571 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_571+currStrOff, fn->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_571+currStrOff, "(", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * code =  ____BAH_COMPILER_VAR_571;
j =  j + 2;

                        if (l->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1785): l[%d] with length %d\n", j, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[j];
if ((strcmp(t.cont, ")") != 0)) {
while ((j<len(l))) {

                        if (l->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1789): l[%d] with length %d\n", j, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1799): l[%d] with length %d\n", j, l->length);
                            exit(1);
                        };
                        t =  l->data[j];
char * argType =  t.cont;
j =  j + 1;
int isComa =  false;
long int nbPars =  1;
while ((j<len(l))) {

                        if (l->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1806): l[%d] with length %d\n", j, l->length);
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
char * ____BAH_COMPILER_VAR_572 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(argType);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_572 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, argType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_572+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    argType =  ____BAH_COMPILER_VAR_572;
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
char * ____BAH_COMPILER_VAR_573 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_574 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_573);
;                            
                        ____BAH_COMPILER_VAR_574 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_574+currStrOff, ____BAH_COMPILER_VAR_573, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    newArgType =  ____BAH_COMPILER_VAR_574;
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
char * ____BAH_COMPILER_VAR_575 =argCType.str((struct string*)&argCType);char * ____BAH_COMPILER_VAR_576 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_575);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newArgType);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_576 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_576+currStrOff, tpdf, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_576+currStrOff, "typedef ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_576+currStrOff, ____BAH_COMPILER_VAR_575, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_576+currStrOff, " ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_576+currStrOff, newArgType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_576+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    tpdf =  ____BAH_COMPILER_VAR_576;
}
}
if ((cfrt.hasPrefix((struct string*)&cfrt,"function(")==1)) {
char * ____BAH_COMPILER_VAR_577 =getCfunctionType(cfrt,argName,elems);char * ____BAH_COMPILER_VAR_578 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_577);
;                            
                        ____BAH_COMPILER_VAR_578 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_578+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_578+currStrOff, ____BAH_COMPILER_VAR_577, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_578;
}
else {
char * ____BAH_COMPILER_VAR_579 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(newArgType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(argName);
;                            
                        ____BAH_COMPILER_VAR_579 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_579+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_579+currStrOff, newArgType, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_579+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_579+currStrOff, argName, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_579;
}
if ((isComa==true)) {
char * ____BAH_COMPILER_VAR_580 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_580 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_580+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_580+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_580;
}
else {
char * ____BAH_COMPILER_VAR_581 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_581 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_581+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_581+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_581;
break;
}
j =  j + 1;
};
}
else {
char * ____BAH_COMPILER_VAR_582 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_582 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_582+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_582+currStrOff, ")", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_582;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1871): l[%d] with length %d\n", j, l->length);
                            exit(1);
                        };
                        t =  l->data[j];
if ((strcmp(t.cont, "{") == 0)) {
break;
}
char * ____BAH_COMPILER_VAR_583 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(returns->type);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_583 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_583+currStrOff, returns->type, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_583+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    returns->type =  ____BAH_COMPILER_VAR_583;
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
char * ____BAH_COMPILER_VAR_584 =cfrt.str((struct string*)&cfrt);char * ____BAH_COMPILER_VAR_585 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("__BAH_ARR_TYPE_");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_584);
;                            
                        ____BAH_COMPILER_VAR_585 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, "__BAH_ARR_TYPE_", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_585+currStrOff, ____BAH_COMPILER_VAR_584, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    newFnRetType =  ____BAH_COMPILER_VAR_585;
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
char * ____BAH_COMPILER_VAR_586 =fnRetType.str((struct string*)&fnRetType);char * ____BAH_COMPILER_VAR_587 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen("typedef ");
long int strLen_2 = strlen(____BAH_COMPILER_VAR_586);
long int strLen_3 = strlen(" ");
long int strLen_4 = strlen(newFnRetType);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_587 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_587+currStrOff, tpdf, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_587+currStrOff, "typedef ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_587+currStrOff, ____BAH_COMPILER_VAR_586, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_587+currStrOff, " ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_587+currStrOff, newFnRetType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_587+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    tpdf =  ____BAH_COMPILER_VAR_587;
}
}
char * ____BAH_COMPILER_VAR_588 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tpdf);
long int strLen_1 = strlen(newFnRetType);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(code);
;                            
                        ____BAH_COMPILER_VAR_588 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_588+currStrOff, tpdf, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_588+currStrOff, newFnRetType, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_588+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_588+currStrOff, code, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_588;
char * ____BAH_COMPILER_VAR_589 = code;
return ____BAH_COMPILER_VAR_589;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1921): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok nameToken =  l->data[1];
long int i =  2;
int doesOutput =  true;
if ((strcmp(nameToken.cont, "!") == 0)) {

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1925): l[%d] with length %d\n", 2, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1941): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok st =  l->data[i];
if ((st.type==TOKEN_TYPE_KEYWORD)) {
if ((strcmp(st.cont, "extend") == 0)) {
i =  i + 1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1945): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1957): extdsmbs[%d] with length %d\n", j, extdsmbs->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1965): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                            exit(1);
                        };
                        struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_590 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_591 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_590);
;                            
                        ____BAH_COMPILER_VAR_591 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_591+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_591+currStrOff, ____BAH_COMPILER_VAR_590, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_591;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_592 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_592 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_592+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_592+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_592;
}
};
char * ____BAH_COMPILER_VAR_593 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_594 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_593);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(em->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_594 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_594+currStrOff, ____BAH_COMPILER_VAR_593, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_594+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_594+currStrOff, em->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_594+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_594+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_594+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    membDeclStr =  ____BAH_COMPILER_VAR_594;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1988): extdS->methods[%d] with length %d\n", k, extdS->methods->length);
                            exit(1);
                        };
                        struct func* emt =  extdS->methods->data[k];
struct string mthdDecl =  getCType(emt->returns->type,elems);
char * ____BAH_COMPILER_VAR_595 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(emt->name);
long int strLen_2 = strlen(")(");
;                            
                        ____BAH_COMPILER_VAR_595 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_595+currStrOff, "(*", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_595+currStrOff, emt->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_595+currStrOff, ")(", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_595);
j =  0;
while ((j<len(emt->args))) {

                        if (emt->args->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:1993): emt->args[%d] with length %d\n", j, emt->args->length);
                            exit(1);
                        };
                        struct variable* a =  emt->args->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_596 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                        ____BAH_COMPILER_VAR_596 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_596+currStrOff, " ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_596+currStrOff, a->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tp.append((struct string*)&tp,____BAH_COMPILER_VAR_596);
long int max =  len(emt->args) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_597 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_597);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2012): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok braceTk =  l->data[i];
i =  i + 1;
if ((strcmp(braceTk.cont, "{") != 0)) {
throwErr(&braceTk,"Cannot use {TOKEN} in struct declaration.");
}
struct rope* OOUT =  OUTPUT;
char * nextLine =  "";
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2020): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2034): members[%d] with length %d\n", ii, members->length);
                            exit(1);
                        };
                        struct structMemb* m =  members->data[ii];
if ((strcmp(m->name, memb->name) == 0)) {
throwErr(&t,"Member {TOKEN} has already been declared.");
}
ii =  ii + 1;
};
i =  i + 1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2041): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((strcmp(t.cont, ":") != 0)) {
if ((strcmp(t.cont, "(") != 0)) {
throwErr(&t,"Member name should be followed by ':' not {TOKEN}.");
}
else {
char * ____BAH_COMPILER_VAR_598 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("__");
;                            
                        ____BAH_COMPILER_VAR_598 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_598+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_598+currStrOff, "__", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    char * fnPrefix =  ____BAH_COMPILER_VAR_598;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2050): l[%d] with length %d\n", j, l->length);
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
char * ____BAH_COMPILER_VAR_599 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(s->name);
long int strLen_1 = strlen("*");
;                            
                        ____BAH_COMPILER_VAR_599 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_599+currStrOff, s->name, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_599+currStrOff, "*", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    t.cont =  ____BAH_COMPILER_VAR_599;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2066): l[%d] with length %d\n", j + 1, l->length);
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
i =  i - 1;
long int nli =  0;
char * ____BAH_COMPILER_VAR_600 =parseFnHeader(fnPrefix,nl,&nli,fn,elems);struct rope* code =  rope(____BAH_COMPILER_VAR_600);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2091): arguments[%d] with length %d\n", j, arguments->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2102): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((strcmp(t.cont, "{") == 0)) {
i =  i + 1;
}
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2107): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_601 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                        ____BAH_COMPILER_VAR_601 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, "Function '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, fn->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_601+currStrOff, "' is not returned.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_601);
}
endRCPscope(fnElems,null);
}
code =  code->add(code, OUTPUT)->add(code->add(code, OUTPUT), rope("};\n"));
}
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_602 =code->toStr((struct rope*)code);char * ____BAH_COMPILER_VAR_603 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(nextLine);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_602);
;                            
                        ____BAH_COMPILER_VAR_603 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_603+currStrOff, nextLine, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_603+currStrOff, ____BAH_COMPILER_VAR_602, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    nextLine =  ____BAH_COMPILER_VAR_603;
}
struct string mthdDecl =  getCType(fn->returns->type,elems);
char * ____BAH_COMPILER_VAR_604 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("(*");
long int strLen_1 = strlen(mfn->name);
long int strLen_2 = strlen(")(");
;                            
                        ____BAH_COMPILER_VAR_604 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_604+currStrOff, "(*", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_604+currStrOff, mfn->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_604+currStrOff, ")(", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_604);
j =  0;
while ((j<len(arguments))) {

                        if (arguments->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2153): arguments[%d] with length %d\n", j, arguments->length);
                            exit(1);
                        };
                        struct variable* a =  arguments->data[j];
struct string tp =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_605 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(a->name);
;                            
                        ____BAH_COMPILER_VAR_605 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_605+currStrOff, " ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_605+currStrOff, a->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tp.append((struct string*)&tp,____BAH_COMPILER_VAR_605);
max =  len(arguments) - 1;
if ((j!=max)) {
tp.append((struct string*)&tp,",");
}
char * ____BAH_COMPILER_VAR_606 =tp.str((struct string*)&tp);mthdDecl.append((struct string*)&mthdDecl,____BAH_COMPILER_VAR_606);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2175): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((strcmp(t.cont, "=") == 0)) {
i =  i - 1;
break;
}
if ((t.line!=currentLine)) {
i =  i - 1;
break;
}
char * ____BAH_COMPILER_VAR_607 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(mbmType);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_607 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_607+currStrOff, mbmType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_607+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    mbmType =  ____BAH_COMPILER_VAR_607;
i =  i + 1;
};
memb->type =  mbmType;
i =  i + 1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2190): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((i<len(l))) {
if ((strcmp(t.cont, "=") == 0)) {
i =  i + 1;

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2194): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        t =  l->data[i];
if ((t.isValue==false)) {
throwErr(&t,"Cannot use {TOKEN} as default value for member.");
}
char * tt =  getTypeFromToken(&t,true,elems);
if ((compTypes(tt,memb->type)==false)) {
char * ____BAH_COMPILER_VAR_608 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot use {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(memb->type);
long int strLen_4 = strlen(" for member.");
;                            
                        ____BAH_COMPILER_VAR_608 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, "Cannot use {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, memb->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_608+currStrOff, " for member.", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&t,____BAH_COMPILER_VAR_608);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2219): tmpfn->args[%d] with length %d\n", j, tmpfn->args->length);
                            exit(1);
                        };
                        struct variable* arg =  tmpfn->args->data[j];
struct string ct =  getCType(arg->type,elems);
char * ____BAH_COMPILER_VAR_609 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_610 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_609);
;                            
                        ____BAH_COMPILER_VAR_610 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_610+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_610+currStrOff, ____BAH_COMPILER_VAR_609, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_610;
j =  j + 1;
if ((j<len(tmpfn->args))) {
char * ____BAH_COMPILER_VAR_611 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(",");
;                            
                        ____BAH_COMPILER_VAR_611 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_611+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_611+currStrOff, ",", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_611;
}
};
char * ____BAH_COMPILER_VAR_612 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_613 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_612);
long int strLen_1 = strlen(" (*");
long int strLen_2 = strlen(memb->name);
long int strLen_3 = strlen(")(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(")");
;                            
                        ____BAH_COMPILER_VAR_613 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_613+currStrOff, ____BAH_COMPILER_VAR_612, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_613+currStrOff, " (*", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_613+currStrOff, memb->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_613+currStrOff, ")(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_613+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_613+currStrOff, ")", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    membDeclStr =  ____BAH_COMPILER_VAR_613;
}
else {
struct string membDecl =  getCType(memb->type,elems);
char * ____BAH_COMPILER_VAR_614 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(" ");
long int strLen_1 = strlen(memb->name);
;                            
                        ____BAH_COMPILER_VAR_614 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_614+currStrOff, " ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_614+currStrOff, memb->name, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    membDecl.append((struct string*)&membDecl,____BAH_COMPILER_VAR_614);
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
char * ____BAH_COMPILER_VAR_615 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("struct ");
long int strLen_1 = strlen(s->name);
long int strLen_2 = strlen(" {\n");
;                            
                        ____BAH_COMPILER_VAR_615 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_615+currStrOff, "struct ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_615+currStrOff, s->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_615+currStrOff, " {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* code =  rope(____BAH_COMPILER_VAR_615);
i =  0;
while ((i<len(allMembs))) {

                        if (allMembs->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2242): allMembs[%d] with length %d\n", i, allMembs->length);
                            exit(1);
                        };
                        char * m =  allMembs->data[i];
char * ____BAH_COMPILER_VAR_616 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(m);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_616 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, m, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_616+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  code->add(code, rope(____BAH_COMPILER_VAR_616));
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2259): s->members[%d] with length %d\n", i, s->members->length);
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
struct reflectElement ____BAH_COMPILER_VAR_618 = __reflect((char **)((char*)(ds) + offsetof(struct debugStruct, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugStruct, name));
struct reflectElement ____BAH_COMPILER_VAR_620 = __reflect((char **)((char*)(0) + offsetof(struct variable, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_621 = __reflect((char **)((char*)(0) + offsetof(struct variable, type)), sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_622 = __reflect((int*)((char*)(0) + offsetof(struct variable, isConst)), sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_623 = __reflect((char **)((char*)(0) + offsetof(struct variable, constVal)), sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_624 = __reflect((int*)((char*)(0) + offsetof(struct variable, isArray)), sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_625 = __reflect((char **)((char*)(0) + offsetof(struct variable, from)), sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_626 = __reflect((int*)((char*)(0) + offsetof(struct variable, outterScope)), sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_619 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_619->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_619->length = 7;
        ____BAH_COMPILER_VAR_619->data = memoryAlloc(____BAH_COMPILER_VAR_619->length * ____BAH_COMPILER_VAR_619->elemSize);
        ____BAH_COMPILER_VAR_619->data[0] = ____BAH_COMPILER_VAR_620;
____BAH_COMPILER_VAR_619->data[1] = ____BAH_COMPILER_VAR_621;
____BAH_COMPILER_VAR_619->data[2] = ____BAH_COMPILER_VAR_622;
____BAH_COMPILER_VAR_619->data[3] = ____BAH_COMPILER_VAR_623;
____BAH_COMPILER_VAR_619->data[4] = ____BAH_COMPILER_VAR_624;
____BAH_COMPILER_VAR_619->data[5] = ____BAH_COMPILER_VAR_625;
____BAH_COMPILER_VAR_619->data[6] = ____BAH_COMPILER_VAR_626;
struct reflectElement ____BAH_COMPILER_VAR_627 = __reflect(0, sizeof(struct variable*), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_619, 0);

        struct reflectElement ____BAH_COMPILER_VAR_628 = ____BAH_COMPILER_VAR_627;
        struct reflectElement ____BAH_COMPILER_VAR_629 = __reflect((array(struct variable*)**)((char*)(ds) + offsetof(struct debugStruct, membs)), sizeof(array(struct variable*)*), "[]variable*", "membs", 1, &____BAH_COMPILER_VAR_628, 0, 0, offsetof(struct debugStruct, membs));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_617 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_617->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_617->length = 2;
        ____BAH_COMPILER_VAR_617->data = memoryAlloc(____BAH_COMPILER_VAR_617->length * ____BAH_COMPILER_VAR_617->elemSize);
        ____BAH_COMPILER_VAR_617->data[0] = ____BAH_COMPILER_VAR_618;
____BAH_COMPILER_VAR_617->data[1] = ____BAH_COMPILER_VAR_629;
struct reflectElement ____BAH_COMPILER_VAR_630 = __reflect(ds, sizeof(struct debugStruct*), "debugStruct*", "ds", 0, 0, 1, ____BAH_COMPILER_VAR_617, 0);
debugPrint("struct_declare",nameToken.line,____BAH_COMPILER_VAR_630);
}
};
void parseDefine(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<3)) {
throwErr(&l->data[len(l)-1],"Invalid usage of define, cannot end on {TOKEN}.");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2281): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[1];

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2282): l[%d] with length %d\n", 2, l->length);
                            exit(1);
                        };
                        struct Tok st =  l->data[2];
long int i =  1;
int doesOutput =  true;
if ((strcmp(ft.cont, "!") == 0)) {

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2287): l[%d] with length %d\n", 2, l->length);
                            exit(1);
                        };
                        ft =  l->data[2];

                        if (l->length <= 3) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2288): l[%d] with length %d\n", 3, l->length);
                            exit(1);
                        };
                        st =  l->data[3];
i =  2;
doesOutput =  false;
}
if ((strcmp(st.cont, "(") == 0)) {
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
char * ____BAH_COMPILER_VAR_631 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_631 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_631+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_631+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_631));
}
}
else {
char * tp =  "";
i =  i+1;
for (; (i<len(l)); i =  i+1) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2307): l[%d] with length %d\n", i, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[i];
char * ____BAH_COMPILER_VAR_632 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tp);
long int strLen_1 = strlen(t.cont);
;                            
                        ____BAH_COMPILER_VAR_632 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_632+currStrOff, tp, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_632+currStrOff, t.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tp =  ____BAH_COMPILER_VAR_632;
};
if ((ft.type!=TOKEN_TYPE_VAR)) {
throwErr(&ft,"Cannot use {TOKEN} as new type name.");
}
struct string cTypeNewType =  getCType(tp,elems);
char * cTypeNewTypeStr =  cTypeNewType.str((struct string*)&cTypeNewType);
if ((doesOutput==true)) {
char * ____BAH_COMPILER_VAR_633 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("typedef ");
long int strLen_1 = strlen(cTypeNewTypeStr);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(ft.cont);
long int strLen_4 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_633 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, "typedef ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, cTypeNewTypeStr, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, ft.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_633+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_633));
}
if ((debug==true)) {
struct debugType* dt = memoryAlloc(sizeof(struct debugType));
dt->name= null;
dt->refers= null;
dt->name =  ft.cont;
dt->refers =  tp;
struct reflectElement ____BAH_COMPILER_VAR_635 = __reflect((char **)((char*)(dt) + offsetof(struct debugType, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugType, name));
struct reflectElement ____BAH_COMPILER_VAR_636 = __reflect((char **)((char*)(dt) + offsetof(struct debugType, refers)), sizeof(char *), "cpstring", "refers", 0, 0, 0, 0, offsetof(struct debugType, refers));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_634 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_634->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_634->length = 2;
        ____BAH_COMPILER_VAR_634->data = memoryAlloc(____BAH_COMPILER_VAR_634->length * ____BAH_COMPILER_VAR_634->elemSize);
        ____BAH_COMPILER_VAR_634->data[0] = ____BAH_COMPILER_VAR_635;
____BAH_COMPILER_VAR_634->data[1] = ____BAH_COMPILER_VAR_636;
struct reflectElement ____BAH_COMPILER_VAR_637 = __reflect(dt, sizeof(struct debugType*), "debugType*", "dt", 0, 0, 1, ____BAH_COMPILER_VAR_634, 0);
debugPrint("type_declare",ft.line,____BAH_COMPILER_VAR_637);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2337): line[%d] with length %d\n", i, line->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2349): clibs[%d] with length %d\n", j, clibs->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2372): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok vart =  l->data[1];

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2373): l[%d] with length %d\n", 2, l->length);
                            exit(1);
                        };
                        struct Tok equt =  l->data[2];

                        if (l->length <= 3) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2374): l[%d] with length %d\n", 3, l->length);
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
char * ____BAH_COMPILER_VAR_638 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(valt.cont);
long int strLen_4 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_638 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, valt.cont, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_638+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_638));
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
char * ____BAH_COMPILER_VAR_639 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot return nothing as ");
long int strLen_1 = strlen(currentFn->returns->type);
long int strLen_2 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_639 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_639+currStrOff, "Cannot return nothing as ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_639+currStrOff, currentFn->returns->type, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_639+currStrOff, ".", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&l->data[0],____BAH_COMPILER_VAR_639);
}
}
else {

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2411): l[%d] with length %d\n", 1, l->length);
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
char * ____BAH_COMPILER_VAR_640 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot return {TOKEN} (");
long int strLen_1 = strlen(tt);
long int strLen_2 = strlen(") as ");
long int strLen_3 = strlen(currentFn->returns->type);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_640 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_640+currStrOff, "Cannot return {TOKEN} (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_640+currStrOff, tt, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_640+currStrOff, ") as ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_640+currStrOff, currentFn->returns->type, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_640+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&rvt,____BAH_COMPILER_VAR_640);
}
}
if ((compilerState.isBranch==false)) {
currentFn->returned =  true;
}
char * rvar =  genCompilerVar();
struct string cType =  getCType(currentFn->returns->type,elems);
if ((strlen(rv)>0)) {
char * ____BAH_COMPILER_VAR_641 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_642 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_641);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(rvar);
long int strLen_3 = strlen(" = ");
long int strLen_4 = strlen(rv);
long int strLen_5 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_642 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_642+currStrOff, ____BAH_COMPILER_VAR_641, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_642+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_642+currStrOff, rvar, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_642+currStrOff, " = ", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_642+currStrOff, rv, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_642+currStrOff, ";\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_642));
endRCPscope(elems,null);
char * ____BAH_COMPILER_VAR_643 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("return ");
long int strLen_1 = strlen(rvar);
long int strLen_2 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_643 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_643+currStrOff, "return ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_643+currStrOff, rvar, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_643+currStrOff, ";\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_643));
}
else {
endRCPscope(elems,null);
OUTPUT =  OUTPUT->add(OUTPUT, rope("return;\n"));
}
};
void parseIf(__BAH_ARR_TYPE_Tok l,struct Elems* elems){
if ((len(l)<4)) {

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2445): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[0];
throwErr(&ft,"Invalid usage of {TOKEN}, must be 'if <condition> {<code>}'");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2448): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in if statement.");
}
}

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2454): l[%d] with length %d\n", 2, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2461): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_644 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("if (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                        ____BAH_COMPILER_VAR_644 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_644+currStrOff, "if (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_644+currStrOff, condt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_644+currStrOff, ") {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_644));
struct Elems* ifElems =  dupElems(elems);
int oldIB =  compilerState.isBranch;
compilerState.isBranch =  true;
parseLines(tokens,ifElems);
endRCPscope(ifElems,null);
if ((debug==true)) {

                        if (l->length <= len(l)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2474): l[%d] with length %d\n", len(l)-1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2493): l[%d] with length %d\n", 1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2498): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2511): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2522): l[%d] with length %d\n", len(l)-1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2541): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2557): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok t =  l->data[0];
throwErr(&t,"Invalid usage of {TOKEN}, can only partition line in 2 using 'for <condition>, <insctruction> {<code>}'.");
}
array(struct Tok)* inst = memoryAlloc(sizeof(array(struct Tok)));

inst->length = 0;
inst->elemSize = sizeof(struct Tok);

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2562): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2570): l[%d] with length %d\n", 2, l->length);
                            exit(1);
                        };
                        struct Tok st =  l->data[2];
if (((st.type!=TOKEN_TYPE_SYNTAX)||(strcmp(st.cont, ",") != 0))) {
throwErr(&st,"Cannot use {TOKEN}, need ',' to split for loop instructions.");
}
i =  3;
for (; (i<len(l)); i =  i+1) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2577): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_645 =OUTPUT->toStr((struct rope*)OUTPUT);struct string instC =  string(____BAH_COMPILER_VAR_645);
OUTPUT =  oldOut;
instC.trimRight((struct string*)&instC,2);

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2593): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2600): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_646 =instC.str((struct string*)&instC);char * ____BAH_COMPILER_VAR_647 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("for (; ");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen("; ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_646);
long int strLen_4 = strlen(") {\n");
;                            
                        ____BAH_COMPILER_VAR_647 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_647+currStrOff, "for (; ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_647+currStrOff, condt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_647+currStrOff, "; ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_647+currStrOff, ____BAH_COMPILER_VAR_646, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_647+currStrOff, ") {\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_647));
}
else {

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2607): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok condt =  l->data[1];
if ((strcmp(condt.bahType, "bool") != 0)) {
if ((strcmp(condt.bahType, "int") != 0)) {
throwErr(&condt,"Cannot use {TOKEN} as condition in for statement.");
}
}

                        if (l->length <= 2) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2613): l[%d] with length %d\n", 2, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2619): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_648 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("while (");
long int strLen_1 = strlen(condt.cont);
long int strLen_2 = strlen(") {\n");
;                            
                        ____BAH_COMPILER_VAR_648 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_648+currStrOff, "while (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_648+currStrOff, condt.cont, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_648+currStrOff, ") {\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_648));
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2633): l[%d] with length %d\n", len(l)-1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2644): l[%d] with length %d\n", 0, l->length);
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
char * ____BAH_COMPILER_VAR_649 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_649 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_649+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_649+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_649));
};
void parsePreKeyword(__BAH_ARR_TYPE_Tok l,struct Elems* elems){

                        if (l->length <= 0) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2659): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[0];
if ((strcmp(ft.cont, "#warning") == 0)) {
if ((len(l)!=2)) {
throwErr(&ft,"Invalid usage of {TOKEN} '#warning \"message\"'.");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2665): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok mt =  l->data[1];
if ((mt.type!=TOKEN_TYPE_STR)) {
throwErr(&mt,"Cannot use {TOKEN} as a string.");
}
struct string msg =  string(mt.cont);
msg.trimLeft((struct string*)&msg,1);
msg.trimRight((struct string*)&msg,1);
char * ____BAH_COMPILER_VAR_650 =msg.str((struct string*)&msg);throwWarning(____BAH_COMPILER_VAR_650);
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
else {
throwErr(&ft,"Undefined token {TOKEN}.");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2717): l[%d] with length %d\n", 1, l->length);
                            exit(1);
                        };
                        struct Tok st =  l->data[1];

                        if (l->length <= len(l)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2718): l[%d] with length %d\n", len(l)-1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2725): l[%d] with length %d\n", i, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2735): l[%d] with length %d\n", 0, l->length);
                            exit(1);
                        };
                        struct Tok ft =  l->data[0];
throwErr(&ft,"Cannot use keyword {TOKEN} on a function call 'async <function call>'.");
}

                        if (l->length <= 1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2738): l[%d] with length %d\n", 1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2745): compilerState.cLibs[%d] with length %d\n", i, compilerState.cLibs->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2758): fnNameParts[%d] with length %d\n", 0, fnNameParts->length);
                            exit(1);
                        };
                        struct string fnName =  fnNameParts->data[0];
char * ____BAH_COMPILER_VAR_659 =fnName.str((struct string*)&fnName);struct func* fn =  searchFunc(____BAH_COMPILER_VAR_659,elems,true);
if ((fn==null)) {
throwErr(&fnT,"Internal compiler error.\n Error in async parsing, arround {TOKEN}.");
}
char * sMembs =  "";
char * unSerMembs =  "";
i =  0;
while ((i<len(fn->args))) {

                        if (fn->args->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2769): fn->args[%d] with length %d\n", i, fn->args->length);
                            exit(1);
                        };
                        struct variable* a =  fn->args->data[i];
struct string cType =  getCType(a->type,elems);
char * ____BAH_COMPILER_VAR_660 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_661 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(sMembs);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_660);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(a->name);
long int strLen_4 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_661 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_661+currStrOff, sMembs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_661+currStrOff, ____BAH_COMPILER_VAR_660, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_661+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_661+currStrOff, a->name, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_661+currStrOff, ";\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    sMembs =  ____BAH_COMPILER_VAR_661;
char * ____BAH_COMPILER_VAR_662 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen("args->");
long int strLen_2 = strlen(a->name);
;                            
                        ____BAH_COMPILER_VAR_662 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_662+currStrOff, unSerMembs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_662+currStrOff, "args->", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_662+currStrOff, a->name, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    unSerMembs =  ____BAH_COMPILER_VAR_662;
i =  i + 1;
if ((i<len(fn->args))) {
char * ____BAH_COMPILER_VAR_663 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(unSerMembs);
long int strLen_1 = strlen(", ");
;                            
                        ____BAH_COMPILER_VAR_663 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_663+currStrOff, unSerMembs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_663+currStrOff, ", ", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    unSerMembs =  ____BAH_COMPILER_VAR_663;
}
};
char * ____BAH_COMPILER_VAR_664 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("struct {\n");
long int strLen_1 = strlen(sMembs);
long int strLen_2 = strlen("}");
;                            
                        ____BAH_COMPILER_VAR_664 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_664+currStrOff, "struct {\n", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_664+currStrOff, sMembs, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_664+currStrOff, "}", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    char * tmpArgsStruct =  ____BAH_COMPILER_VAR_664;
char * fnWrapper =  genCompilerVar();
char * tmpArgs =  genCompilerVar();
sFnT.trimLeft((struct string*)&sFnT,fnName.length + 1);
sFnT.trimRight((struct string*)&sFnT,1);
char * tCreate =  "pthread_create";
if ((RCPavailable()==false)) {
tCreate =  "GC_pthread_create";
}
char * ____BAH_COMPILER_VAR_665 =fnName.str((struct string*)&fnName);char * ____BAH_COMPILER_VAR_666 =sFnT.str((struct string*)&sFnT);char * ____BAH_COMPILER_VAR_667 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n    void ");
long int strLen_1 = strlen(fnWrapper);
long int strLen_2 = strlen("(");
long int strLen_3 = strlen(tmpArgsStruct);
long int strLen_4 = strlen("* args) {\n        ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_665);
long int strLen_6 = strlen("(");
long int strLen_7 = strlen(unSerMembs);
long int strLen_8 = strlen(");\n    };\n    {\n        ");
long int strLen_9 = strlen(tmpArgsStruct);
long int strLen_10 = strlen(" ");
long int strLen_11 = strlen(tmpArgs);
long int strLen_12 = strlen(" = {");
long int strLen_13 = strlen(____BAH_COMPILER_VAR_666);
long int strLen_14 = strlen("};\n        pthread_t id;\n        ");
long int strLen_15 = strlen(tCreate);
long int strLen_16 = strlen("(&id, 0, ");
long int strLen_17 = strlen(fnWrapper);
long int strLen_18 = strlen(", &");
long int strLen_19 = strlen(tmpArgs);
long int strLen_20 = strlen(");\n    }; \n    \n    ");
;                            
                        ____BAH_COMPILER_VAR_667 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6 + strLen_7 + strLen_8 + strLen_9 + strLen_10 + strLen_11 + strLen_12 + strLen_13 + strLen_14 + strLen_15 + strLen_16 + strLen_17 + strLen_18 + strLen_19 + strLen_20);
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, "\n    void ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, fnWrapper, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, "(", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, tmpArgsStruct, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, "* args) {\n        ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, ____BAH_COMPILER_VAR_665, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, "(", strLen_6);
                        currStrOff += strLen_6;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, unSerMembs, strLen_7);
                        currStrOff += strLen_7;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, ");\n    };\n    {\n        ", strLen_8);
                        currStrOff += strLen_8;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, tmpArgsStruct, strLen_9);
                        currStrOff += strLen_9;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, " ", strLen_10);
                        currStrOff += strLen_10;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, tmpArgs, strLen_11);
                        currStrOff += strLen_11;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, " = {", strLen_12);
                        currStrOff += strLen_12;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, ____BAH_COMPILER_VAR_666, strLen_13);
                        currStrOff += strLen_13;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, "};\n        pthread_t id;\n        ", strLen_14);
                        currStrOff += strLen_14;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, tCreate, strLen_15);
                        currStrOff += strLen_15;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, "(&id, 0, ", strLen_16);
                        currStrOff += strLen_16;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, fnWrapper, strLen_17);
                        currStrOff += strLen_17;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, ", &", strLen_18);
                        currStrOff += strLen_18;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, tmpArgs, strLen_19);
                        currStrOff += strLen_19;
                        
                        strncpy(____BAH_COMPILER_VAR_667+currStrOff, ");\n    }; \n    \n    ", strLen_20);
                        currStrOff += strLen_20;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_667));
};
void addRCPvars(__BAH_ARR_TYPE_Tok l,lineType ltp,struct Elems* elems){
long int i =  0;
if ((ltp==LINE_TYPE_VAR)) {
i =  1;
}
while ((i<len(l))) {

                        if (l->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2811): l[%d] with length %d\n", i, l->length);
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
__BAH_ARR_TYPE_Tok prePross(__BAH_ARR_TYPE_Tok line,lineType ltp,struct Elems* elems){
array(struct Tok)* fl = memoryAlloc(sizeof(array(struct Tok)));

fl->length = 0;
fl->elemSize = sizeof(struct Tok);
long int i =  0;
long int nbPar =  0;
if ((ltp!=(lineType)-1)) {
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2830): line[%d] with length %d\n", i, line->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2836): line[%d] with length %d\n", i + 1, line->length);
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
if ((ltp!=(lineType)-1)) {
while ((i<len(line))) {

                        if (line->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2860): line[%d] with length %d\n", i, line->length);
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
array(struct Tok)* ____BAH_COMPILER_VAR_668 = fl;
return ____BAH_COMPILER_VAR_668;
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2872): l[%d] with length %d\n", 0, l->length);
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
char * ____BAH_COMPILER_VAR_669 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Cannot redeclare function {TOKEN}, previous declaration: ");
long int strLen_1 = strlen(ogFn->file);
long int strLen_2 = strlen(":");
long int strLen_3 = strlen(lineStr);
long int strLen_4 = strlen(".");
;                            
                        ____BAH_COMPILER_VAR_669 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, "Cannot redeclare function {TOKEN}, previous declaration: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, ogFn->file, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, ":", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, lineStr, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_669+currStrOff, ".", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    throwErr(&ft,____BAH_COMPILER_VAR_669);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2893): fn->args[%d] with length %d\n", 0, fn->args->length);
                            exit(1);
                        };
                        struct variable* fa =  fn->args->data[0];
if ((compTypes(fa->type,"[]cpstring")==false)) {
throwErr(&ft,"{TOKEN} function should take []cpstring as argument. Should be: \n            'main(args []cpstring) int'");
}
}
char * ____BAH_COMPILER_VAR_670 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(code);
long int strLen_1 = strlen("{\n");
;                            
                        ____BAH_COMPILER_VAR_670 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_670+currStrOff, code, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_670+currStrOff, "{\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    code =  ____BAH_COMPILER_VAR_670;
OUTPUT =  OUTPUT->add(OUTPUT, rope(code));
struct Elems* fnElems =  dupElems(elems);
array(struct variable*)* vs =  fnElems->vars;
long int j =  0;
while ((j<len(fn->args))) {

                        if (fn->args->length <= j) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2907): fn->args[%d] with length %d\n", j, fn->args->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2926): l[%d] with length %d\n", i, l->length);
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
char * ____BAH_COMPILER_VAR_672 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Function '");
long int strLen_1 = strlen(fn->name);
long int strLen_2 = strlen("' is not returned.");
;                            
                        ____BAH_COMPILER_VAR_672 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_672+currStrOff, "Function '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_672+currStrOff, fn->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_672+currStrOff, "' is not returned.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    throwErr(&l->data[len(l)-1],____BAH_COMPILER_VAR_672);
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
struct reflectElement ____BAH_COMPILER_VAR_674 = __reflect((char **)((char*)(df) + offsetof(struct debugFunction, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct debugFunction, name));
struct reflectElement ____BAH_COMPILER_VAR_675 = __reflect((char **)((char*)(df) + offsetof(struct debugFunction, returns)), sizeof(char *), "cpstring", "returns", 0, 0, 0, 0, offsetof(struct debugFunction, returns));
struct reflectElement ____BAH_COMPILER_VAR_677 = __reflect((char **)((char*)(0) + offsetof(struct variable, name)), sizeof(char *), "cpstring", "name", 0, 0, 0, 0, offsetof(struct variable, name));
struct reflectElement ____BAH_COMPILER_VAR_678 = __reflect((char **)((char*)(0) + offsetof(struct variable, type)), sizeof(char *), "cpstring", "type", 0, 0, 0, 0, offsetof(struct variable, type));
struct reflectElement ____BAH_COMPILER_VAR_679 = __reflect((int*)((char*)(0) + offsetof(struct variable, isConst)), sizeof(int), "bool", "isConst", 0, 0, 0, 0, offsetof(struct variable, isConst));
struct reflectElement ____BAH_COMPILER_VAR_680 = __reflect((char **)((char*)(0) + offsetof(struct variable, constVal)), sizeof(char *), "cpstring", "constVal", 0, 0, 0, 0, offsetof(struct variable, constVal));
struct reflectElement ____BAH_COMPILER_VAR_681 = __reflect((int*)((char*)(0) + offsetof(struct variable, isArray)), sizeof(int), "bool", "isArray", 0, 0, 0, 0, offsetof(struct variable, isArray));
struct reflectElement ____BAH_COMPILER_VAR_682 = __reflect((char **)((char*)(0) + offsetof(struct variable, from)), sizeof(char *), "cpstring", "from", 0, 0, 0, 0, offsetof(struct variable, from));
struct reflectElement ____BAH_COMPILER_VAR_683 = __reflect((int*)((char*)(0) + offsetof(struct variable, outterScope)), sizeof(int), "bool", "outterScope", 0, 0, 0, 0, offsetof(struct variable, outterScope));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_676 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_676->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_676->length = 7;
        ____BAH_COMPILER_VAR_676->data = memoryAlloc(____BAH_COMPILER_VAR_676->length * ____BAH_COMPILER_VAR_676->elemSize);
        ____BAH_COMPILER_VAR_676->data[0] = ____BAH_COMPILER_VAR_677;
____BAH_COMPILER_VAR_676->data[1] = ____BAH_COMPILER_VAR_678;
____BAH_COMPILER_VAR_676->data[2] = ____BAH_COMPILER_VAR_679;
____BAH_COMPILER_VAR_676->data[3] = ____BAH_COMPILER_VAR_680;
____BAH_COMPILER_VAR_676->data[4] = ____BAH_COMPILER_VAR_681;
____BAH_COMPILER_VAR_676->data[5] = ____BAH_COMPILER_VAR_682;
____BAH_COMPILER_VAR_676->data[6] = ____BAH_COMPILER_VAR_683;
struct reflectElement ____BAH_COMPILER_VAR_684 = __reflect(0, sizeof(struct variable*), "variable*", "", 0, 0, 1, ____BAH_COMPILER_VAR_676, 0);

        struct reflectElement ____BAH_COMPILER_VAR_685 = ____BAH_COMPILER_VAR_684;
        struct reflectElement ____BAH_COMPILER_VAR_686 = __reflect((array(struct variable*)**)((char*)(df) + offsetof(struct debugFunction, args)), sizeof(array(struct variable*)*), "[]variable*", "args", 1, &____BAH_COMPILER_VAR_685, 0, 0, offsetof(struct debugFunction, args));

        array(struct reflectElement) * ____BAH_COMPILER_VAR_673 = memoryAlloc(sizeof(array(struct reflectElement)));
        ____BAH_COMPILER_VAR_673->elemSize = sizeof(struct reflectElement);
        ____BAH_COMPILER_VAR_673->length = 3;
        ____BAH_COMPILER_VAR_673->data = memoryAlloc(____BAH_COMPILER_VAR_673->length * ____BAH_COMPILER_VAR_673->elemSize);
        ____BAH_COMPILER_VAR_673->data[0] = ____BAH_COMPILER_VAR_674;
____BAH_COMPILER_VAR_673->data[1] = ____BAH_COMPILER_VAR_675;
____BAH_COMPILER_VAR_673->data[2] = ____BAH_COMPILER_VAR_686;
struct reflectElement ____BAH_COMPILER_VAR_687 = __reflect(df, sizeof(struct debugFunction*), "debugFunction*", "df", 0, 0, 1, ____BAH_COMPILER_VAR_673, 0);
debugPrint("fn_declare",ft.line,____BAH_COMPILER_VAR_687);

                        if (l->length <= len(l)-1) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:2955): l[%d] with length %d\n", len(l)-1, l->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3003): line[%d] with length %d\n", 0, line->length);
                            exit(1);
                        };
                        struct Tok ft =  line->data[0];
parsed =  true;
char * ____BAH_COMPILER_VAR_690 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(ft.cont);
long int strLen_1 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_690 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_690+currStrOff, ft.cont, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_690+currStrOff, ";\n", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_690));
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3033): line[%d] with length %d\n", 0, line->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3052): tokens[%d] with length %d\n", 0, tokens->length);
                            exit(1);
                        };
                        struct Tok ft =  tokens->data[0];
long int currentLine =  ft.line;
long int nbEncl =  0;
long int i =  0;
while ((i<len(tokens))) {

                        if (tokens->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3056): tokens[%d] with length %d\n", i, tokens->length);
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3082): tokens[%d] with length %d\n", i-1, tokens->length);
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
else if ((strcmp(t.cont, ";") == 0)) {
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
                            printf("array (/home/alois/Documents/bah-bah/src/parser.bah:3111): line[%d] with length %d\n", len(line)-1, line->length);
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
char * ____BAH_COMPILER_VAR_692 =ct.str((struct string*)&ct);char * ____BAH_COMPILER_VAR_693 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(____BAH_COMPILER_VAR_692);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(arg->name);
;                            
                        ____BAH_COMPILER_VAR_693 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_693+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_693+currStrOff, ____BAH_COMPILER_VAR_692, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_693+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_693+currStrOff, arg->name, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_693;
j =  j + 1;
if ((j<len(fn->args))) {
char * ____BAH_COMPILER_VAR_694 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(tmpfnArgsCType);
long int strLen_1 = strlen(", ");
;                            
                        ____BAH_COMPILER_VAR_694 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_694+currStrOff, tmpfnArgsCType, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_694+currStrOff, ", ", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    tmpfnArgsCType =  ____BAH_COMPILER_VAR_694;
}
};
char * ____BAH_COMPILER_VAR_695 =tmpfnRetCType.str((struct string*)&tmpfnRetCType);char * ____BAH_COMPILER_VAR_696 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_695);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(fn->name);
long int strLen_3 = strlen("(");
long int strLen_4 = strlen(tmpfnArgsCType);
long int strLen_5 = strlen(");\n");
;                            
                        ____BAH_COMPILER_VAR_696 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_696+currStrOff, ____BAH_COMPILER_VAR_695, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_696+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_696+currStrOff, fn->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_696+currStrOff, "(", strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_696+currStrOff, tmpfnArgsCType, strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_696+currStrOff, ");\n", strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_696));
};
void declareVar(struct variable* v,struct Elems* elems){
if ((v->isConst==true)) {
char * ____BAH_COMPILER_VAR_697 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#define ");
long int strLen_1 = strlen(v->name);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(v->constVal);
long int strLen_4 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_697 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_697+currStrOff, "#define ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_697+currStrOff, v->name, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_697+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_697+currStrOff, v->constVal, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_697+currStrOff, "\n", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_697));
}
else {
struct string cType =  getCType(v->type,elems);
char * ____BAH_COMPILER_VAR_698 =cType.str((struct string*)&cType);char * ____BAH_COMPILER_VAR_699 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(____BAH_COMPILER_VAR_698);
long int strLen_1 = strlen(" ");
long int strLen_2 = strlen(v->name);
long int strLen_3 = strlen(";\n");
;                            
                        ____BAH_COMPILER_VAR_699 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, ____BAH_COMPILER_VAR_698, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, " ", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, v->name, strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_699+currStrOff, ";\n", strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_699));
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
                        char * ____BAH_COMPILER_VAR_700 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("#include ");
long int strLen_1 = strlen(compilerState.cIncludes->data[i]);
long int strLen_2 = strlen("\n");
;                            
                        ____BAH_COMPILER_VAR_700 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_700+currStrOff, "#include ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_700+currStrOff, compilerState.cIncludes->data[i], strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_700+currStrOff, "\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_700));
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
struct flags ____BAH_COMPILER_VAR_701 = {};
____BAH_COMPILER_VAR_701.flags = memoryAlloc(sizeof(array(struct flag*)));
            ____BAH_COMPILER_VAR_701.flags->length = 0;
            ____BAH_COMPILER_VAR_701.flags->elemSize = sizeof(struct flag*);
            ____BAH_COMPILER_VAR_701.args = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_701.args->length = 0;
            ____BAH_COMPILER_VAR_701.args->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_701.addString = flags__addString;
____BAH_COMPILER_VAR_701.addBool = flags__addBool;
____BAH_COMPILER_VAR_701.addInt = flags__addInt;
____BAH_COMPILER_VAR_701.addFloat = flags__addFloat;
____BAH_COMPILER_VAR_701.invalidate = flags__invalidate;
____BAH_COMPILER_VAR_701.getFlag = flags__getFlag;
____BAH_COMPILER_VAR_701.get = flags__get;
____BAH_COMPILER_VAR_701.getInt = flags__getInt;
____BAH_COMPILER_VAR_701.getFloat = flags__getFloat;
____BAH_COMPILER_VAR_701.isSet = flags__isSet;
____BAH_COMPILER_VAR_701.parse = flags__parse;
flags =  ____BAH_COMPILER_VAR_701;
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
char * ____BAH_COMPILER_VAR_702 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Bah compiler version: ");
long int strLen_1 = strlen(BAH_VERSION);
long int strLen_2 = strlen(".\n© Alois Laurent Boe");
;                            
                        ____BAH_COMPILER_VAR_702 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_702+currStrOff, "Bah compiler version: ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_702+currStrOff, BAH_VERSION, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_702+currStrOff, ".\n© Alois Laurent Boe", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    println(____BAH_COMPILER_VAR_702);
long int ____BAH_COMPILER_VAR_703 = 0;
return ____BAH_COMPILER_VAR_703;
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
char * ____BAH_COMPILER_VAR_704 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\n        #include \"");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen("libs/include/gc.h\"\n        int main(int argc, char ** argv) {\n        GC_INIT();\n        array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n        args->data = GC_MALLOC(sizeof(char*)*argc);\n        memcpy(args->data, argv, sizeof(char*)*argc);\n        args->elemSize = sizeof(char*);\n        args->length = argc;\n        __BAH_init();\n        long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n        GC_FREE(args->data);\n        GC_FREE(args);\n        return r;\n        };\n        #define main(v) __BAH__main(v)\n        ");
;                            
                        ____BAH_COMPILER_VAR_704 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_704+currStrOff, "\n        #include \"", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_704+currStrOff, BAH_DIR, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_704+currStrOff, "libs/include/gc.h\"\n        int main(int argc, char ** argv) {\n        GC_INIT();\n        array(char*) * args = GC_MALLOC(sizeof(array(char*)));\n        args->data = GC_MALLOC(sizeof(char*)*argc);\n        memcpy(args->data, argv, sizeof(char*)*argc);\n        args->elemSize = sizeof(char*);\n        args->length = argc;\n        __BAH_init();\n        long int r =  __BAH__main((__BAH_ARR_TYPE_cpstring)args);\n        GC_FREE(args->data);\n        GC_FREE(args);\n        return r;\n        };\n        #define main(v) __BAH__main(v)\n        ", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    OUTPUT =  OUTPUT->add(OUTPUT, rope(____BAH_COMPILER_VAR_704));
}
}
struct compilerStateTag ____BAH_COMPILER_VAR_705 = {};
____BAH_COMPILER_VAR_705.includes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_705.includes->length = 0;
            ____BAH_COMPILER_VAR_705.includes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_705.cIncludes = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_705.cIncludes->length = 0;
            ____BAH_COMPILER_VAR_705.cIncludes->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_705.cLibs = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_705.cLibs->length = 0;
            ____BAH_COMPILER_VAR_705.cLibs->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_705.currentFile= null;
____BAH_COMPILER_VAR_705.currentDir = "./";
____BAH_COMPILER_VAR_705.isBranch = false;
____BAH_COMPILER_VAR_705.isFor = false;
____BAH_COMPILER_VAR_705.arrTypesDecl = memoryAlloc(sizeof(array(char *)));
            ____BAH_COMPILER_VAR_705.arrTypesDecl->length = 0;
            ____BAH_COMPILER_VAR_705.arrTypesDecl->elemSize = sizeof(char *);
            ____BAH_COMPILER_VAR_705.haveEntryPoint = false;
____BAH_COMPILER_VAR_705.RCPvars = memoryAlloc(sizeof(array(struct variable*)));
            ____BAH_COMPILER_VAR_705.RCPvars->length = 0;
            ____BAH_COMPILER_VAR_705.RCPvars->elemSize = sizeof(struct variable*);
            compilerState =  ____BAH_COMPILER_VAR_705;

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
struct fileMap ____BAH_COMPILER_VAR_706 = {};
____BAH_COMPILER_VAR_706.open = fileMap__open;
____BAH_COMPILER_VAR_706.isValid = fileMap__isValid;
____BAH_COMPILER_VAR_706.close = fileMap__close;
struct fileMap fm =  ____BAH_COMPILER_VAR_706;
char * f =  fm.open((struct fileMap*)&fm,fileName);
if ((fm.isValid((struct fileMap*)&fm)==0)) {
char * ____BAH_COMPILER_VAR_707 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Could not open file '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("'.");
;                            
                        ____BAH_COMPILER_VAR_707 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_707+currStrOff, "Could not open file '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_707+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_707+currStrOff, "'.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_707);
}
long int startTime =  getTimeUnix();
array(struct Tok)* tokens =  lexer(f);
fm.close((struct fileMap*)&fm);
if ((len(tokens)==0)) {
char * ____BAH_COMPILER_VAR_708 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("File '");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen("' not recognized.");
;                            
                        ____BAH_COMPILER_VAR_708 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_708+currStrOff, "File '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_708+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_708+currStrOff, "' not recognized.", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_708);
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
char * ____BAH_COMPILER_VAR_709 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Could not find std-libs, please check '");
long int strLen_1 = strlen(BAH_DIR);
long int strLen_2 = strlen("'");
;                            
                        ____BAH_COMPILER_VAR_709 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_709+currStrOff, "Could not find std-libs, please check '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_709+currStrOff, BAH_DIR, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_709+currStrOff, "'", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    panic(____BAH_COMPILER_VAR_709);
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
char * ____BAH_COMPILER_VAR_710 =intToStr(totalLines);char * ____BAH_COMPILER_VAR_711 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_712 =intToStr(totalLexerTime / 1000000);char * ____BAH_COMPILER_VAR_713 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("Parsed. (");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_710);
long int strLen_2 = strlen(" lines, total time: ");
long int strLen_3 = strlen(____BAH_COMPILER_VAR_711);
long int strLen_4 = strlen("ms, lexer time: ");
long int strLen_5 = strlen(____BAH_COMPILER_VAR_712);
long int strLen_6 = strlen("ms)\e[0m");
;                            
                        ____BAH_COMPILER_VAR_713 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5 + strLen_6);
                        
                        strncpy(____BAH_COMPILER_VAR_713+currStrOff, "Parsed. (", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_713+currStrOff, ____BAH_COMPILER_VAR_710, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_713+currStrOff, " lines, total time: ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_713+currStrOff, ____BAH_COMPILER_VAR_711, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_713+currStrOff, "ms, lexer time: ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_713+currStrOff, ____BAH_COMPILER_VAR_712, strLen_5);
                        currStrOff += strLen_5;
                        
                        strncpy(____BAH_COMPILER_VAR_713+currStrOff, "ms)\e[0m", strLen_6);
                        currStrOff += strLen_6;
                        
                    }
                    println(____BAH_COMPILER_VAR_713);
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
char * ____BAH_COMPILER_VAR_714 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(randFileName);
long int strLen_1 = strlen(s);
;                            
                        ____BAH_COMPILER_VAR_714 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_714+currStrOff, randFileName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_714+currStrOff, s, strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    randFileName =  ____BAH_COMPILER_VAR_714;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_715 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(randFileName);
long int strLen_1 = strlen(".c");
;                            
                        ____BAH_COMPILER_VAR_715 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_715+currStrOff, randFileName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_715+currStrOff, ".c", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    randFileName =  ____BAH_COMPILER_VAR_715;
struct fileStream ____BAH_COMPILER_VAR_716 = {};
____BAH_COMPILER_VAR_716.handle= null;
____BAH_COMPILER_VAR_716.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_716.open = fileStream__open;
____BAH_COMPILER_VAR_716.close = fileStream__close;
____BAH_COMPILER_VAR_716.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_716.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_716.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_716.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_716.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_716.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_716.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_716.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_716.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_716.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_716.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_716.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_716.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_716;
fs.open((struct fileStream*)&fs,randFileName,"w");
char * ____BAH_COMPILER_VAR_717 =OUTPUT->toStr((struct rope*)OUTPUT);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_717);
fs.close((struct fileStream*)&fs);
char * ____BAH_COMPILER_VAR_718 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("gcc ");
long int strLen_1 = strlen(randFileName);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(isStatic);
long int strLen_4 = strlen(" -w -O1 -o ");
long int strLen_5 = strlen(fileName);
;                            
                        ____BAH_COMPILER_VAR_718 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4 + strLen_5);
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, "gcc ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, randFileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, isStatic, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, " -w -O1 -o ", strLen_4);
                        currStrOff += strLen_4;
                        
                        strncpy(____BAH_COMPILER_VAR_718+currStrOff, fileName, strLen_5);
                        currStrOff += strLen_5;
                        
                    }
                    char * gccArgs =  ____BAH_COMPILER_VAR_718;
if ((flags.isSet((struct flags*)&flags,"l")==1)) {
char * ____BAH_COMPILER_VAR_719 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -c");
;                            
                        ____BAH_COMPILER_VAR_719 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_719+currStrOff, gccArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_719+currStrOff, " -c", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    gccArgs =  ____BAH_COMPILER_VAR_719;
}
array(char *)* cLibs =  compilerState.cLibs;
i =  0;
while ((i<len(cLibs))) {

                        if (cLibs->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/main_linux.bah:191): cLibs[%d] with length %d\n", i, cLibs->length);
                            exit(1);
                        };
                        char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_720 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                        ____BAH_COMPILER_VAR_720 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_720+currStrOff, gccArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_720+currStrOff, " -", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_720+currStrOff, l, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    gccArgs =  ____BAH_COMPILER_VAR_720;
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
char * ____BAH_COMPILER_VAR_721 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("ar rcs ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(".a ");
long int strLen_3 = strlen(fileName);
;                            
                        ____BAH_COMPILER_VAR_721 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3);
                        
                        strncpy(____BAH_COMPILER_VAR_721+currStrOff, "ar rcs ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_721+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_721+currStrOff, ".a ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_721+currStrOff, fileName, strLen_3);
                        currStrOff += strLen_3;
                        
                    }
                    cmd =  command(____BAH_COMPILER_VAR_721);
cmd.run((struct command*)&cmd);
}
}
else {
if ((flags.isSet((struct flags*)&flags,"o")==0)) {
char * ____BAH_COMPILER_VAR_722 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(fileName);
long int strLen_1 = strlen(".c");
;                            
                        ____BAH_COMPILER_VAR_722 = memoryAllocSTR(1 + strLen_0 + strLen_1);
                        
                        strncpy(____BAH_COMPILER_VAR_722+currStrOff, fileName, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_722+currStrOff, ".c", strLen_1);
                        currStrOff += strLen_1;
                        
                    }
                    fileName =  ____BAH_COMPILER_VAR_722;
}
char * ____BAH_COMPILER_VAR_723 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("gcc ");
long int strLen_1 = strlen(fileName);
long int strLen_2 = strlen(" ");
long int strLen_3 = strlen(isStatic);
long int strLen_4 = strlen(" -O1 -w ");
;                            
                        ____BAH_COMPILER_VAR_723 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2 + strLen_3 + strLen_4);
                        
                        strncpy(____BAH_COMPILER_VAR_723+currStrOff, "gcc ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_723+currStrOff, fileName, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_723+currStrOff, " ", strLen_2);
                        currStrOff += strLen_2;
                        
                        strncpy(____BAH_COMPILER_VAR_723+currStrOff, isStatic, strLen_3);
                        currStrOff += strLen_3;
                        
                        strncpy(____BAH_COMPILER_VAR_723+currStrOff, " -O1 -w ", strLen_4);
                        currStrOff += strLen_4;
                        
                    }
                    char * gccArgs =  ____BAH_COMPILER_VAR_723;
array(char *)* cLibs =  compilerState.cLibs;
long int i =  0;
while ((i<len(cLibs))) {

                        if (cLibs->length <= i) {
                            printf("array (/home/alois/Documents/bah-bah/src/main_linux.bah:218): cLibs[%d] with length %d\n", i, cLibs->length);
                            exit(1);
                        };
                        char * l =  cLibs->data[i];
char * ____BAH_COMPILER_VAR_724 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen(gccArgs);
long int strLen_1 = strlen(" -");
long int strLen_2 = strlen(l);
;                            
                        ____BAH_COMPILER_VAR_724 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_724+currStrOff, gccArgs, strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_724+currStrOff, " -", strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_724+currStrOff, l, strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    gccArgs =  ____BAH_COMPILER_VAR_724;
i =  i + 1;
};
char * ____BAH_COMPILER_VAR_725 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("//COMPILE WITH: '");
long int strLen_1 = strlen(gccArgs);
long int strLen_2 = strlen("'\n");
;                            
                        ____BAH_COMPILER_VAR_725 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_725+currStrOff, "//COMPILE WITH: '", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_725+currStrOff, gccArgs, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_725+currStrOff, "'\n", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    struct rope* ____BAH_COMPILER_VAR_726 =rope(____BAH_COMPILER_VAR_725);OUTPUT =  concatenateRopes(____BAH_COMPILER_VAR_726,OUTPUT);
struct fileStream ____BAH_COMPILER_VAR_727 = {};
____BAH_COMPILER_VAR_727.handle= null;
____BAH_COMPILER_VAR_727.isValid = fileStream__isValid;
____BAH_COMPILER_VAR_727.open = fileStream__open;
____BAH_COMPILER_VAR_727.close = fileStream__close;
____BAH_COMPILER_VAR_727.getPos = fileStream__getPos;
____BAH_COMPILER_VAR_727.setPos = fileStream__setPos;
____BAH_COMPILER_VAR_727.getSize = fileStream__getSize;
____BAH_COMPILER_VAR_727.rewind = fileStream__rewind;
____BAH_COMPILER_VAR_727.getChar = fileStream__getChar;
____BAH_COMPILER_VAR_727.setChar = fileStream__setChar;
____BAH_COMPILER_VAR_727.createFile = fileStream__createFile;
____BAH_COMPILER_VAR_727.writeFile = fileStream__writeFile;
____BAH_COMPILER_VAR_727.writePtr = fileStream__writePtr;
____BAH_COMPILER_VAR_727.readPtr = fileStream__readPtr;
____BAH_COMPILER_VAR_727.readContent = fileStream__readContent;
____BAH_COMPILER_VAR_727.readBytes = fileStream__readBytes;
____BAH_COMPILER_VAR_727.writeBytes = fileStream__writeBytes;
struct fileStream fs =  ____BAH_COMPILER_VAR_727;
fs.open((struct fileStream*)&fs,fileName,"w");
char * ____BAH_COMPILER_VAR_728 =OUTPUT->toStr((struct rope*)OUTPUT);fs.writeFile((struct fileStream*)&fs,____BAH_COMPILER_VAR_728);
fs.close((struct fileStream*)&fs);
}
if ((debug==false)) {
long int totalTime =  getTimeUnix() - startTime;
char * ____BAH_COMPILER_VAR_729 =intToStr(totalTime / 1000000);char * ____BAH_COMPILER_VAR_730 =null;
                    {
                        long int currStrOff = 0;
                        long int strLen_0 = strlen("\e[1;32mDone. (compiled in ");
long int strLen_1 = strlen(____BAH_COMPILER_VAR_729);
long int strLen_2 = strlen("ms)\e[0m");
;                            
                        ____BAH_COMPILER_VAR_730 = memoryAllocSTR(1 + strLen_0 + strLen_1 + strLen_2);
                        
                        strncpy(____BAH_COMPILER_VAR_730+currStrOff, "\e[1;32mDone. (compiled in ", strLen_0);
                        currStrOff += strLen_0;
                        
                        strncpy(____BAH_COMPILER_VAR_730+currStrOff, ____BAH_COMPILER_VAR_729, strLen_1);
                        currStrOff += strLen_1;
                        
                        strncpy(____BAH_COMPILER_VAR_730+currStrOff, "ms)\e[0m", strLen_2);
                        currStrOff += strLen_2;
                        
                    }
                    println(____BAH_COMPILER_VAR_730);
}
else {
debugEnd();
}
long int ____BAH_COMPILER_VAR_731 = 0;
return ____BAH_COMPILER_VAR_731;
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

keywords->length = 18;
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
    