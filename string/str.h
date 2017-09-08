/*minimal string facilities*/


/*Fast size for loops instead call funcition this is inline*/

#ifndef __STR_H__
#define __STR_H__
#include<stdlib.h> //malloc

/*************** Aux Character functions ******************/

/*macros utility*/

/*change a char Upper to Lower vice-versa:*/
#define CHAR_TOLWR(c) { c = (c<='Z' && c>='A') ? (c+32) : c; }
#define CHAR_TOUPR(c) { c = (c<='z' && c>='a') ? (c-32) : c; }
/*says if a char is a number or a letter:*/
#define CHAR_ISNUMBER(n) (n>='0' && n<='9') ? 1 : 0
#define CHAR_ISALPHA(l) (l>='A'&& l<='Z' && l>='a' && l<='z') ? 1 : 0

/*===============  function prototypes: =============*/
int char_tolower(int);
int char_toupper(int);
int char_isnumber(int);
int char_isalpha(int);

/*=============== function implementation: ==========*/
int char_tolower(int c){
  return (c<='Z' && c>='A') ? (c+32) : c;
}

int char_toupper(int c){
  return (c<='z' && c>='a') ? (c-32) : c;
}

int char_isnumber(int n){
  return (n>='0' && n<='9') ? 1 : 0;
}

int char_isalpha(int l){
  return (l>='A'&& l<='Z' && l>='a' && l<='z') ? 1 : 0;
}

/***************** End char functions  **************/

#define FAST_STRLEN(var,str) var=0;while(str[var]) var++; 


//typedef unsigned int size_t;


/*=== PROTOTYPES ======*/
size_t str_len(const char*);
int str_cmp(const char*,const char*);
int str_cmpi(const char*,const char*);
int str_ncomp(const char*,const char*, size_t);
int str_ncompi(const char*,const char*, size_t);
void str_cat(char *, char *);
void str_ncat(char*, char*,int);
void str_cpy(char*, const char*);
void str_ncpy(char*, const char*,size_t);
char *str_chr(char*, int);
char *str_rchr(char*, int);
char *str_str(char *, char *);
char *str_rstr(char*, char*);
int str_lwr(char*);
int str_upr(char*);
char *str_dup(const char*);
int str_rev(char*);
char *str_set(char*, int);
char *str_nset(char*, int,int);
/*======== other funcs =========== */
int str_trim(char *);
int str_find(char *, char *,int,int);
char *str_msub(const char*,int, int);/*malloc*/
char *str_new(size_t);/*malloc*/
char *str_new_str(const char*);/*malloc*/


/*===  IMPLEMENTATION ====*/

//get number of byte char from a string s;
size_t str_len(const char*s){
	int i=0; while(s[i])i++; return i;
}

//compare two strings a and b, if a == b return 0; if the a < b negative number, a > b positive number.
int str_cmp(const char*a,const char*b){	
	int al=str_len(a);
	int bl=str_len(b);	
	if(al>bl) return a[bl];
	else if(al<bl){
      return b[al] *(-1);
    }    
    int i=0;
    while(a[i]){
		if(a[i]!=b[i]) break;		
		i++;
	}
  return a[i]-b[i];
}

/*same as above but dont match case: a and A are equal*/
int str_cmpi(const char*a,const char*b){	
	int al=str_len(a);
	int bl=str_len(b);	
	if(al>bl) return a[bl];
	else if(al<bl){
      return b[al] *(-1);
    }    
    int i=0;
    while(a[i]){
		if(((a[i]>='A' && a[i]<='Z') ? a[i]+32 : a[i])!=((b[i]>='A' && b[i]<='Z') ? b[i]+32 : b[i])) 
		  break;		
		i++;
	}
  return a[i]-b[i];
}

//compare n elements in two strings.
int str_ncmp(const char*a,const char*b,size_t n){
	size_t al=str_len(a),bl=str_len(b);
	if (al < n && bl > al) return b[al] *(-1); 
    int i=0;
    while(i<n && a[i]){
		if(a[i]!=b[i]) return a[i] - b[i];		
		i++;
	}
  /*otherwise return 0 to equality;*/
  return 0;
}
/*same as above but ignore case: a and A are equals*/
int str_ncmpi(const char*a,const char*b,size_t n){
	if(!n) return 0;
	size_t al=str_len(a),bl=str_len(b);
	if (al < n && bl > al) return b[al] *(-1); 
    int i=0;
    while(i<n && a[i]){
		if(((a[i]>='A' && a[i]<='Z') ? a[i]+32 : a[i])!=((b[i]>='A' && b[i]<='Z') ? b[i]+32 : b[i])) 
		  return a[i] - b[i];		
		i++;
	}
  /*otherwise return 0 to equality;*/
  return 0;
}

//concat str2 into str1; str1 must have enough elements for str1 plus str2;
void str_cat(char *a, char *b){
	size_t al = str_len(a);
	size_t bl = str_len(b);
	int i=0;
	while(i<bl){
      a[al]=b[i];
      i++;
      al++;
    }		
    a[al]='\0'; /*insert '\0' null char*/
}

/*concat str2 into str1; str1 must have enough elements for str1 plus str2;*/
void str_ncat(char *a, char *b,int n){
	size_t al = str_len(a);
	size_t bl = str_len(b);
	int i=0;
	while(i<bl  && i<n){
      a[al]=b[i];
      i++;
      al++;
    }
    a[al]='\0';/*insert '\0' null value*/	
}
/* copy string b into a, make sure a has a enough length */
void str_cpy(char*a,const char*b){
  size_t bl = str_len(b);
  int i=0;
  for(i=0;i<bl;i++) a[i]=b[i];
  a[i]='\0'; /*insert null char at end of string;*/  
}

/* copy n characters from string b into a, make sure 'a' has a enough length */
void str_ncpy(char*a,const char*b,size_t n){
  size_t bl = str_len(b);
  int i=0;
  for(i=0;i<bl && i<n;i++) a[i]=b[i];
  a[i]='\0'; /*insert null char at end of string;*/  
}

/*searches string for one char and return a substring after given position */
char *str_chr(char *s, int ch){
	while(*s){
      if(*s==(char)ch) return (char*)s;
      s++;
	}
	return NULL;
}

/* same as above but reverse (from end to start of string);*/
char *str_rchr(char *s, int ch){
	char *ret=0;
	while(*s){
      if(*s==ch) ret = (char*)s;
      s++;
	}
	return ret;
}

/*gets ocurrence of str b from string a and return pointer of position*/
char *str_str(char *a, char *b){
	size_t bl=str_len(b);
	if(str_len(a) < bl) return NULL;
	int i = 0,j=0,k=0;
	while(a[i]){
		  int ctrl = 1;
		  k=i;
		  for(j=0;j<bl;j++){
			 if(b[j]!=a[k]) ctrl = 0;
			 k++;
		  }
		  if(ctrl==1) return &a[i];
      i++;
	}
	return NULL;	
}

/*same as above but in reverse (from end to start)*/
char *str_rstr(char *a, char *b){
	size_t bl=str_len(b);
	if(str_len(a) < bl) return NULL;
	char *ret=0;
	int i = 0,j=0,k=0;
	while(a[i]){
		  int ctrl = 1;
		  k=i;
		  for(j=0;j<bl;j++){
			 if(b[j]!=a[k]) ctrl = 0;
			 k++;
		  }
		  if(ctrl==1) ret = &a[i];
      i++;
	}
	return ret;	
}

int str_lwr(char *s){
  int ret=0;
  do{
	  /*if(*s<='Z' && *s>='A'){
		  *s=*s+32;*/
		  CHAR_TOLWR(*s); /*macro is more fast*/
		  ret = 1;
     /* }*/
  }while(*(s++));
  return ret;
}

int str_upr(char *s){
  int ret=0;
  do{
	  /*if(*s<='z' && *s>='a'){
		  *s=*s-32;*/
	      CHAR_TOUPR(*s);
		  ret = 1;
      //}
  }while(*(s++));
  return ret;
}

char *str_dup(const char*s){
	size_t len = str_len(s)+1;
	char *dup = malloc(sizeof(s)*len);	
	if(!dup) return NULL;
	str_cpy(dup,s);
	return dup;
}

int str_rev(char*s){
	char *dup = str_dup(s);
	int i = str_len(s) - 1;
	if(!dup) return 0;
	do{
		*s=dup[i]; --i;
	}while( *(s++));
	if(dup) free(dup);
	return 1;
}

char *str_set(char *s, int c){
	int i=0;
	while(s[i]){ 
		s[i]=(char)c;
		i++;
	}
	return s;
}

char *str_nset(char *s, int c,int n){
	int i=0;
	while(s[i] && i<n){ 
		s[i]=(char)c;
		i++;
	}
	return s;
}

/*=======  Other funcs ======== */


int str_trim(char *s)
{
	size_t lens = str_len(s);
	int start = 0;
	int finish = lens - 1; 

	while( s[start]==' ' ){
		start++;
	}
	while( s[finish] == ' ' ){
		finish--;
	}

	int tam = ( finish + 1 ) - start;

	if( tam == lens ) return 0;

	/*char result [ tam + 1 ];*/
	int i = 0;
	int cont = start;
	for( i = 0 ; i < tam ; i++ ){
		s[i] = s[cont];
		cont++;
	}
	s[i] = '\0'; //putting the null char in the end of string
	return 1;
}

/*find a string b from string b, 0 = first ... len - 1 = last; or -1 = last; -len=first*/
int str_find(char *a, char *b,int start,int finish){
	size_t bl=str_len(b);
	size_t al=str_len(a);
	if(al< bl) return -1;
	
	if(start<0) start=al+start;
	if(finish<0) finish=al+finish;
	if(finish>al)finish=al;
	if(finish<start)finish=start;

	int i = start,j=0,k=0;
	while(a[i]&&i<=finish){
		  int ctrl = 1;
		  k=i;
		  for(j=0;j<bl;j++){
			 if(b[j]!=a[k]) ctrl = 0;
			 k++;
		  }
		  if(ctrl==1) return i; /*&a[i];*/
      i++;
	}
	return -1;
}

/*creates a new string by malloc which is a sub string from other string*/
/*use free() after*/
/* 0a 1b 2c 3d 4e*/
char *str_msub(const char *s,int start, int finish){/* 0 = first ... len-1=last element*/
  size_t len = str_len(s);
  size_t newlen=0;
    
  if(start<0) start=len+start;
  if(finish<0) finish=len+finish; 
  /*printf("start: %d finish: %d\n\n", start,finish); */
  if(finish>=len || finish < start || start >= len) return 0;
  
  newlen = finish - start +2; /*2 because '\0'*/
  char *new_s = malloc(sizeof(char)*newlen);
  int i = 0,k=0;;
  for(i=start;i<=finish;i++){
	  new_s[k]=s[i];
	  k++;
  }
  new_s[k]='\0';
  return new_s;
}

/*creating a new allocated string without string. don't forget free it*/
char *str_new(size_t size){
  char *s = malloc(sizeof(char)*(size+1));/*1 extra for '\0'*/
  return s;/*maybe NULL*/	
}

/*creating a new allocated string with string,  don't forget free it*/
char *str_new_str(const char*str){
  size_t len = str_len(str);
  char *s = malloc(sizeof(char)*(len+1));/*1 extra for '\0'*/
  if(!s) return NULL;
  str_cpy(s,str);/*makes a copy string into new string*/  
  return s;/*maybe NULL*/	
}



#endif
