#include<bits/stdc++.h>
using namespace std;
int ptr=0;

class MTF
{
public:
	string encode( string str )
	{
		fillSymbolTable();
		vector<int> output;
		for( string::iterator it = str.begin(); it != str.end(); it++ )
		{
			for( int i = 0; i < 26; i++ )
			{
				if( *it == symbolTable[i] )
				{
					output.push_back( i );
					moveToFront( i );
					break;
				}
			}
		}
		string r;
		for( vector<int>::iterator it = output.begin(); it != output.end(); it++ )
		{
			ostringstream ss;
			ss << *it;
			r += ss.str() + " ";
		}
		return r;
	}

	string decode( string str)
	{
		fillSymbolTable();
		istringstream iss( str ); vector<int> output;
        int d;char c;
        while( scanf("%d%c", &d, &c)){
            output.push_back(d);
            if(c == '\n') break;
        }
		// copy( istream_iterator<int>( iss ), istream_iterator<int>(), back_inserter<vector<int> >( output ) );
		string r;
		for( vector<int>::iterator it = output.begin(); it != output.end(); it++ )
		{
			r.append( 1, symbolTable[*it] );
			moveToFront( *it );
		}
		return r;
	}

private:
	void moveToFront( int i )
	{
		char t = symbolTable[i];
		for( int z = i - 1; z >= 0; z-- )
		symbolTable[z + 1] = symbolTable[z];

		symbolTable[0] = t ;
        cout << ++ptr << " => ";
        for(int x=0;x<26;x++) cout <<  symbolTable[x] << ' ';
        cout << endl;
	}

	void fillSymbolTable()
	{
		for( int x = 0; x < 3; x++ )
		symbolTable[x] = x + 'x';
	}

	char symbolTable[26];
};

int main()
{
	MTF mtf;
    
    cout << "encode/decode(e/d)?"<< endl;
    char l;cin >> l;
    string x;
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    if(l=='e'){
        cin >> x;
        cout << mtf.encode(x) << endl;
    }
    else{
        // int z; cout << "size? "<< endl;
        // cin >> z;
        cout << "what is the sequence "<< endl;
        cout << mtf.decode(x) << endl;
    }

}
