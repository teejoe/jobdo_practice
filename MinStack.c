#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,v,top,min,*s1,*s2;
	char t[2];
	while(scanf("%d",&n)!=EOF){
		top=0;
		s1=(int*)malloc(sizeof(int)*n);
		s2=(int*)malloc(sizeof(int)*n);
		while(n--){
			scanf("%s",t);
			if (*t=='s'){
				scanf("%d",&v);
				s1[top]=v;
				if(top==0||v<min)
					min=v;
				s2[top]=min;
				(top)++;
			}
			else{
				if (top>0){
					(top)--;
					min=s2[top-1];
				}
			}
			if (top>0)	printf("%d\n",min);
			else	printf("NULL\n");
		}
		free(s1);
		free(s2);
	}
}
