#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

void SplitString(const char *s, char Delimiter,  vector<string> &Text)
{
	int i, j;

	if( Delimiter == '\n' && s[0] == '\0' )
		return;

	//Text.clear();
	for( j = 0, i = 0; ; )
	{
		if( s[i] == '\0' )
		{
			Text.push_back(string(s + j, i - j));
			break;
		}
		if( s[i] == Delimiter )
		{
			Text.push_back(string(s + j, i - j));
			i++;
			j = i;
			continue;
		}
		i++;
	}

	 //~ vector<string>::iterator it;
	 //~ for(size_t i = 0 ;i < Text.size();i++)
	 //~ {
		 //~ string & data = Text[i];
		 //~ printf("==>%s.\n",data.c_str());
	 //~ }
}


int main()
{
	vector<string> vDiff;
	char a[] = "apple apple";
	char b[] = "banana";
	printf("input:S1：%s|S2：%s\n",a,b);
	SplitString(a,0x20,vDiff);
	SplitString(b,0x20,vDiff);
	//~ printf("size:%lu\n",vDiff.size());
	vector<string>::iterator it;
	vector<string>::iterator at;
	for(it = vDiff.begin();it != vDiff.end();it++){
		for(at = it+1;at!=vDiff.end();at++){
				//~ printf("it:%s|at:%s\n",(*it).c_str(),(*it).c_str());
				if((*it)==(*at)){
					vDiff.erase(at);
					vDiff.erase(it);
					it--;
					break;
				}
		}
	}//endfor
	
	vector<string>::iterator st;
	for(st = vDiff.begin();st != vDiff.end();st++){
		printf("output: %s ",(*st).c_str());
	}
	printf("\n");
	//~ printf("|size:%lu\n",vDiff.size());
	return 0;
}
