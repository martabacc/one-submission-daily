#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define oo 10000000
#define midVal 186
int DP[28][28][300];
int num[32];
int N,K;

int main(){
	
	char str[64];
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &K);
		scanf("%s", str);
		N/=2;
		//insert array ke num[]
		for(int i=0;i<N;i++){
			num[i] = ( (str[2*i]) == '-' ) ? - (str[2*i+1]-'0') : (str[2*i+1]-'0');
			
		}
		
//		memset
		for ( int i=0; i<=25 ; i++){
			for(int j=0 ; j <= 25; j++){
				for(int k=0; k<=500;k++){
					DP[i][j][k] = oo;
				}
			}	
		}
		
		DP[0][0][num[0]+ midVal]=0;
		if(num[0]<0) DP[0][1][num[0] + midVal] -1;
		for(int i=1;i<N;i++){
			for(int j=0;j<=N;j++){
				for(int k=-185; k< 185 ; k++){
					int k_update = k + midVal;
					
					///...?
									
					int kk = k + midVal- ( (j&1) ? -num[i]:num[i]);
					DP[i][j][k_update] = min(DP[i][j][k_update], DP[i-1][j][kk]);
					///....?
					
					kk = k + midVal - ( ( ( j-1) & 1 ) ? -num[i] : num[i]);
					if( j-1 >= 0 && num[i] < 0){
						DP[i][j][k_update] = min( DP[i][j][k_update], 
												  DP[i-1][j-1][kk]+1);
					}
					///?
					
					kk = k + midVal - ( ( ( j+1)&1)? -num[i]:num[i]);
					DP[i][j][k_update] = min (DP[i][j][k_update],
											 DP[i-1][j+1][kk]);
				}
			
			}
		}
		
		int ans = oo;
		/// ?
		
		for(int j=0;j<=N;j++) ans = min(ans, DP[N-1][j][K+midVal]);
		if( ans == oo ) printf("NO\n");
		else printf("%d\n", ans);
		
	}
	return 0;
}

