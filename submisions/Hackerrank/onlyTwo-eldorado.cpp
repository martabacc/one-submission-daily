#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int numbers, chainlen, i,j,k;
	int number[128];
	long long ways[3][128];
	long long totways;
	
	while((scanf("%d%d",&numbers,&chainlen)==2)&&numbers){
		for(i=0;i<numbers;i++) scanf("%d", &number[i]);
		for(i=0;i<numbers;i++) ways[1][i] = 1;
		for(j=2;j<=chainlen;j++){
			for(i=0;i<numbers;i++){
				ways[j%2][i]=0;
				for(k=0;k<i;k++)
					if(number[k]<number[i]) ways[j%2][i]+=ways[(j-1)%2][k];
			}
		}
		totways = 0;
		for(i=0;i<numbers;i++) totways+=ways[chainlen%2][i];
		printf("%lld\n", totways);
	}
	return 0;
}

