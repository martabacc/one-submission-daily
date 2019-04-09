#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char pat[], int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar 
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
	int tc; char c;
	while( scanf("%d\n", &tc)!=EOF ){
//			scanf("%d\n", &tc);
		
		char pat[tc+1];
		
		int lps[tc+1];
		lps[0] = 0;
		scanf("%s", &pat);
		
		//define lps arr
		computeLPSArray(pat, tc, lps);
		
		getchar();
		bool la = false;
	//	counting
		ll penunjuk, i=0,ptr=0;
		
		scanf("%c", &c);
		while(c!='\n')
		{
			scanf("%c" , &c);	
//			ptr++;
			penunjuk=ptr;
			
			while( !(penunjuk-ptr) )
			{
				if( c == pat[i] ){
					i++;
					ptr++;
				}
				else{
					if(i) i = lps[i-1];
					else ptr++;
				}
				if(i == tc)
				{
					printf("%lld\n", ptr-tc+1);
					la=true;
					i=lps[i-1];
				}
			}
		}
		if(!la) printf("\n");
		
	}
	
	return 0;
}



