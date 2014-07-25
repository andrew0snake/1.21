#include <stdio.h>

#define MAX 100
#define TAB 7

int getl(char line[MAX],int maxline);
int entab(char entabed[MAX],int len);

int main()
{
    int i,c,len,k;
    char symb1,symb2,symb3;
    char line[MAX];

    for (i=0;i<MAX;++i){
	line[i]=0;
    }

    len=0;
    symb1='\t';
    symb2=' ';
    symb3='\n';
    while( (len=getl(line,MAX) )>0 ){
	printf("string line before detabing=\n%s;\nlen before detabing =%d\n",line,len);

	for (k=0;k<len;++k)
	    printf("entabed[%d]='%c',entabed[%d+%d-1]='%c',k=%d,\n",k,line[k],k,TAB,line[k-TAB],k);

	len=entab(line,len);

	printf("string line  after detabing=\n%s;len after detabing=%d\n",line,len);

	for (k=0;k<len;++k)
	    printf("entabed[%d]='%c',entabed[%d+%d-1]='%c',k=%d,\n",k,line[k],k,TAB,line[k-TAB],k);
    	
    }
    
    for (i=0;i<=len;++i)	
	printf("entabed[%d]=%c",i,line[i]);

}

int getl(char s [MAX],int maxline)
{
    int c,i;
    
    for (i=0;i<100;++i)
	s[i]=0;

    for (i=0;(c=getchar())!=EOF && (c!='\n');++i){
	s[i]=c;
    }
    
    if (c=='\n'){
	s[i]='\n';
        ++i;
    }
    s[i]='\0';

    return i;
}

int entab(char entabed[MAX],int len)
{	
    int i,j,k,c,count;
    i=j=c=k=0;
    count=0;

    while( (c=entabed[i])!='\0'){
	if (c==' ') {
	    if (count<(TAB-1) )	
		++count;
		else {
		    entabed[i-(TAB-1)]='\t';
		    k=(i-(TAB-1)+1);
		    j=k;
		    while( (k + (TAB-1) -1) <=len ){
		        entabed[k]=entabed[k+(TAB-1)];
			++k;
//			printf("entabed[%d]='%c',entabed[%d+%d-1]='%c',k=%d,\n",k,entabed[k],k,TAB,entabed[k-TAB],k);
		    }
		    printf("Moved from %d to %d;lenght=%d; i before=%d;i after=%d\n",k,j,len-TAB,i,i-(TAB-1));
		    count=0;
		    len=len-TAB+1;
		    i=i-(TAB-1);
		}
	}
	else 
	    count=0;
	++i;
    }

    if (c=='\n')
	entabed[i+1]='\0';

//    for (j=0;j<=len;++j)	
//	printf("entabed[%d]='%c'\n",j,entabed[j]);

    
    return len;
}



