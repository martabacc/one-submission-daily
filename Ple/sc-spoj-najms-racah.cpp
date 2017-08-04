#include <bits/stdc++.h>																			
using namespace std;																			
#define ll long long																			
char ch;																			

#define getchar_unlocked getchar																			
#define getInt(x) while((ch=getchar_unlocked())<'0'); x=ch-'0'; while((ch=getchar_unlocked())>='0') x=x*10+ch-'0';																			
ll bit[100005];																			
int n;																			

void update(int i,ll val)																			
{																			
	while(i<=n)																		
	{																		
		bit[i] +=val;																	
		i+= i&-i; //pos + lsb(pos)																	 
	}																		
}																			
																			
ll query(int i)																			
{																			
	ll res=0;																		
	while(i>0)																		
	{																		
		res+=bit[i];																	
		i-= i&-i;																	
	}																		
	return res;																		
}																			
																			
int main()																			
{																			
	int tst;																		
	
	getInt(tst);																		
	for(int t=1;t<=tst;t++)																		
	{																		
		char a;																	
		int q,u,v;																	
		ll val;																	
		memset(bit,0,sizeof bit);																
		
		getInt(n);getInt(q);																	
		for(int i=1;i<=n;i++)																	
		{					
																		
			getInt(val);																
			update(i,val);																
			update(i+1,-val);																
		}																	
		printf("Case %d:\n",t);																	
		while(q--)																	
		{																	
			scanf("%c",&a);																
			if(a=='w')																
			{								
																		
				getInt(u);getInt(v);getInt(val);															
				update(u,val);															
				update(v+1,-val);															
			}																
			else if(a=='f')																
			{							
															
				getInt(u);															
				printf("%lld\n",query(u));															
				
			}																
			else if(a=='m')																
			{																
			
				getInt(u);															
				ll temp = query(u);															
				update(u,-temp);															
				update(u+1,temp);															
				
			}																
		}																	
	}																		
}																				
