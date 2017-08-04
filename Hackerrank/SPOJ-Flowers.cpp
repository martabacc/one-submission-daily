#include<stdio.h>
#define lli long long int

lli pots, moduler,result;
#define arrsz 4
lli arr[arrsz];

#define setAll() for(int x=0;x<arrsz;x++) arr[x]=0

void fn(lli x){
	//make it fly
	
	arr[x%4]=((x+1)*arr[(x-1)%4]-(x-2)*arr[(x-2)%4]-(x-5)*arr[(x-3)%4]+(x-3)*arr[(x-4)%4])%moduler ;
	
	if(x<pots) fn(x+1);
	else {
		result = arr[x%4];
	}
}
	
int main(){

	scanf("%lld %lld", &pots, &moduler);
	setAll();
	
	arr[0] =1; arr[1]=1;
	arr[2]=0 ; arr[3]=0;
	
	fn(4);
	
	if(result<0){
		while(result<0)result+=moduler;
	}
	
	printf("%lld\n",result);
	
	return 0;
}

