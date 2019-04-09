#include<bits/stdc++.h>
#include<stdio.h>
#define pb push_back
#define mp make_pair
#define BP 2  //break point -> ini yang bisa di ganti ganti jadi kalau break pointnya 2 byte itu break_point + 1. 
using namespace std;
/*
contoh input
encode 
1I am Sam

Sam I am

That Sam-I-am!
That Sam-I-am!
I do not like
that Sam-I-am!

Do you like green eggs and ham?

I do not like them, Sam-I-am.
I do not like green eggs and ham.

decode 
2I am Sam

(5,3) (0,4)

That(4,4)-I-am!(19,16)I do not like
t(21,14)
Do you(58,5) green eggs and ham?
(49,14) them,(24,9).(112,15)(92,18).
*/
std::string::size_type sz;

char data[1000000];
char compressed[1000000];
vector<pair<char,int> > temp_data;
vector<pair<int,int> > simpan_data;

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    if(i.first>j.first)return (i.first>j.first);
    else if(i.first==j.first)
    {
    	return (i.second<j.second);
	}
}


int main()
{
	int pilih;
	cout <<"1. encode 2 decode\n";
	cin >> pilih;
	//cout <<endl;
	int break_point=BP;
	int ok;
	//scanf("%d",&break_point);  
	char tmp;int counter=0;
	while(scanf("%c",&tmp)!=EOF)
	{
		data[counter++]=tmp;
	}
	//cout << data<< endl;
	if(pilih==1){
		for(int x=0;x<counter;)
		{
			if(x<BP)
			{
				//compressed[x]=data[x];
				//printf("\nResult : ");
				printf("%c",data[x]);
				x++;ok++;
			}
			else
			{
				//cout <<"debug\n";
				//cout <<"data yang sama\n";
				for(int y=0;y<x;y++)
				{
					if(data[x]==data[y])
					{
						temp_data.pb(mp(data[x],y));
						
					//	cout << data[x]<<" "<< y<<endl;
					}
				}
				//cout <<"cari paling panjang\n";
				for(int y=0;y<temp_data.size();y++)
				{
					
					int longest=0,counter1=0;
					int pos=temp_data[y].second;
				//	cout << pos<< endl;
					for(int z=pos;z<counter;)
					{
						if(data[z]==data[x+counter1])
						{
				//			cout << data[z]<< " "<< data[x+counter1]<< endl;
							longest++;
							counter1++;
							z++;
								
						}
						else
						{
							break;
						}
					}
				//	cout << longest <<" "<< pos<< endl;
					if(longest>=BP)
							simpan_data.pb(mp(longest,pos));
				}
				//cout <<"sorting\n";
				if(simpan_data.size()==0)
				{
					simpan_data.clear();
					temp_data.clear();
				//	printf("\nResult : ");
					printf("%c",data[x]);
					//compressed[x]=data[x];
					x++;//ok++;
					continue;
				}
				sort(simpan_data.begin(),simpan_data.end(),compare);
				//cout <<"cek vector\n";
				//for(int x=0;x<simpan_data.size();x++)
				//cout << simpan_data[x].first<<" "<<simpan_data[x].second<< endl;
				
				/*compressed[ok++]='(';
				char tempsaja[100];itoa(simpan_data[0].second,tempsaja,10);
				//cout << tempsaja<< endl;
				for(int z=0;z<strlen(tempsaja);z++)compressed[ok++]=tempsaja[z];
				compressed[ok++]=',';
				itoa(simpan_data[0].first,tempsaja,10);
				
				for(int z=0;z<strlen(tempsaja);z++)compressed[ok++]=tempsaja[z];
				//cout<<compressed[ok-1]<<endl;
				compressed[ok++]=')';
				*/
				//printf("\nResult: ");
				printf("(%d,%d)",simpan_data[0].second,simpan_data[0].first);
				x+=simpan_data[0].first;
				//cout << x<< endl;
				simpan_data.clear();
				temp_data.clear();
			}
		}
	}
	else
	{
		bool cek=false;
		string temp_decode;
		char decompressed[100000];
		int counter100=0;
		for(int x=0;x<counter;x++)
		{
			if(data[x]=='(')
			{
				//cout << "masuk kurung\n";
				cek=true;
			}
			else if(cek&&data[x]!=')')
			{
				//cout << data[x]<<endl;
				temp_decode.push_back(data[x]);
			}
			else if(cek&&data[x]==')')
			{
				//cout << temp_decode<< endl;
				string posisi,panjang,temp;cek=false;
				int posisi1, panjang1;
				for(int y=0;y<temp_decode.size();y++)
				{
					if(temp_decode[y]==',')
					{
						//cout << temp << endl;
						posisi1=stoi(temp,&sz);
						temp.clear();
					}
					else if(y==temp_decode.size()-1)
					{
						//cout << temp<< endl;
						temp.push_back(temp_decode[y]);
						panjang1=stoi(temp,&sz);temp.clear();
						temp.clear();
					}
					else 
					{
						temp.push_back(temp_decode[y]);
					}
				}
				//cout << posisi1<<" "<<decompressed[posisi1] << " "<< panjang1<<endl;
				for(int y=0;y<panjang1;y++){
					cout << decompressed[posisi1+y];
					decompressed[counter100++]=decompressed[posisi1+y];
				}
				temp_decode.clear();
			}
			else
			{
				printf("%c",data[x]);
				decompressed[counter100++]=data[x];
			}
			
		}
	}
	//cout<< compressed<<endl;
	return 0;
}
