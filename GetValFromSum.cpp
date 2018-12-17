#include <stdio.h>
#include <map>

using namespace std;

int main(){
	int nNum[] = {2,7,11,15,219,982,123}; 
	int nTarget = 226;
	int nLen = sizeof(nNum)/4;
	map<int,int> mNum;
	map<int,int>::iterator it,at;
 	for(int i = 0;i<nLen;i++){//排除大于target的值
		if(nNum[i] < nTarget)
		mNum[i] = nNum[i];
	}
	it = mNum.begin();
	at = it;
	at++;
	for(;it != mNum.end();at++){
		if(it->second + at->second == nTarget){
			printf("%d,%d\n",it->first,at->first);
			break;
		}else{
			if(at == mNum.end()){
				it++;
				at = it;
			}
		}
	}
	return 0;
}
