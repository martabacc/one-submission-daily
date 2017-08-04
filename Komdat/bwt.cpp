#include<bits/stdc++.h>
using namespace std;
void kompres()
{
	char a[1000];
	memset(a,0,sizeof a);
	cout << "String input\n";
	cin >> a;
	
	char data[1000][1000];
	memset(data,0,sizeof(data));
	int counter=0;
	for(int x=0;x<strlen(a);x++)
	{
		for(int y=0;y<strlen(a);y++)
		{
			data[y][x]=a[(y+counter)%strlen(a)];
		}
		counter++;
	}
	cout <<"cellular left shift\n";
	for (int x=0;x<strlen(a);x++)cout << data[x]<< endl;
	int n=strlen(a),k,l;
	for(int i=0;i<n-1;i++){
	    for(int j=0; j<n-i-1; j++){
	        l = min(strlen(data[j]),strlen(data[j+1]));
	        for(k=0;k<l;++k)
	            if(data[j+1][k]<data[j][k]){ swap(data[j],data[j+1]); break; }
	            else if(data[j+1][k]>data[j][k]) break;
	        if(k==l and strlen(data[j])>strlen(data[j+1]))
	            swap(data[j],data[j+1]);
	        }
	    }
	cout << "lexicograpical\n";
	for(int x=0;x<strlen(a);x++)cout << data[x]<< endl;
	char temp_data[100];
	for(int x=0;x<n;x++)
	temp_data[x]=a[(x+1)%n];
	//cout << temp_data<< endl;
	for(int x=0;x<n;x++)
	{
		if(strcmp(data[x],temp_data)==0)
		{
			cout << "S1: "<<x<< endl;
			break;
		}
	}
	char F[100];
	for(int x=0;x<n;x++)F[x]=data[x][0];
	char L[100];
	for(int x=0;x<n;x++)L[x]=data[x][n-1];
	cout << "F: "<<F<< endl;
	cout << "L: "<<L<< endl;
}
void dekompress()
{
	cout <<  "L\n";
	char L[100];
	cin >> L;
	char F[100];
	cout << "F\n";
	cin >> F;
	cout << "S1\n";
	int s1;cin >> s1;
	bool flag[100];
	memset(flag,0,sizeof flag);
	int T[100];
	memset(T,0,sizeof T);
	//cout << L<< endl<<F<< endl;
	T[0]=s1;
	for(int x=0;x<strlen(L);x++)
	{
		for(int y=0;y<strlen(F);y++)
		{
			//cout << L[x]<< F[y]<< endl;
			if(!flag[y]&&(L[x]==F[y]))
			{
				T[y]=x;
				flag[y]=true;
				break;
			}
		}
	}
	cout << "T"<<endl;
	for(int x=0;x<strlen(F);x++)cout<< T[x]<<" ";
	/*For debbugging*/
	cout << endl<< "First: ";
	int new_tempp=s1;
	printf("%c\n",L[s1]);
	for(int x=0;x<strlen(F)-1;x++)
	{
		cout <<x<< " OLD temp: "<<new_tempp<< endl;
		printf("%c\n",F[new_tempp]);
		new_tempp=T[new_tempp];
		cout << x<< " new Temp "<< new_tempp<< endl;
	}
	/*For only ans*/
	cout << endl;
	int new_temp=s1;
	printf("%c",L[s1]);
	for(int x=0;x<strlen(F)-1;x++)
	{
		printf("%c",F[new_temp]);
		new_temp=T[new_temp];
		
	}
}
int main()
{
	cout << "1 encode 2 decode\n";
	int pilih;cin >> pilih;
	if(pilih==1)kompres();
	else dekompress();
	return 0;
}
