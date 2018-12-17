#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include <sstream>
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

bool isnum(string s)
{
	stringstream sin(s); //把s放到输入输出流中
	double t;
	char p;
	if(!(sin >> t))			
	/*解释：
         sin>>t表示把sin转换成T的变量（其实对于int和float型的都会接收），如果转换成功，则值为非0，如果转换不成功就返回为0
    */
	return false;
	if(sin >> p)
	return false;
	else
	return true;
}


int main(){
	vector<string> vStrSum;
	vector<int> vIntSum;
	string input = "5,-2,4,C,D,9,+,+";
	SplitString(input.c_str(),',',vStrSum);
	for(size_t i =0;i<vStrSum.size();i++){
		//~ printf("%s ",vSum[i].c_str());
		if(isnum(vStrSum[i])){
			vIntSum.push_back(atoi(vStrSum[i].c_str()));
		}else{
			if(!strcmp(vStrSum[i].c_str(),"C")){
				vIntSum.pop_back();
			}
			if(!strcmp(vStrSum[i].c_str(),"D")){
				vIntSum.push_back(2*vIntSum[vIntSum.size()-1]);
			}
			if(!strcmp(vStrSum[i].c_str(),"+")){
				vIntSum.push_back(vIntSum[vIntSum.size()-1]+vIntSum[vIntSum.size()-2]);
			}
		}
	}
	int nOutSum = 0;
	for(size_t j = 0;j<vIntSum.size();j++){
		printf("%d ",vIntSum[j]);
		nOutSum += vIntSum[j];
	}
	printf("\n");
	printf("nOutSum:%d\n",nOutSum);
	return 0;
}
