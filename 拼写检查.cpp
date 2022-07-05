#include<iostream>
#include<vector>
#include<map>

// using namespace std;
// #define int long long

std::vector<std::string> dict;

bool check(std::string s1,std::string s2){
	// 长度一样的情况 
	if (s1.length()==s2.length()){
		int cnt=0;
		for (int i=0;i<(int)s1.length();i++) cnt+=(s1[i]!=s2[i]);
		return cnt<=1;
	} else if (s1.length()-s2.length() == 1){ // 词典比较长 
		int j=0,cnt=0;
		for (int i=0;i<(int)s2.length();i++,j++){
			while (cnt+1<=1 && s2[i]!=s1[j]) j++,cnt++;
			if (cnt>1 || s2[i]!=s1[j]) return false;
		}
		return cnt<=1;
	} else if (s2.length()-s1.length() == 1){ // 待查比较长 
		int j=0,cnt=0;
		for (int i=0;i<(int)s1.length();i++,j++){
			while (cnt+1<=1 && s1[i]!=s2[j]) j++,cnt++;
			if (cnt>1 || s1[i]!=s2[j]) return false;
		}
		return cnt<=1;
	}return false;
}

signed main(){
	for (;;){
		std::string s; std::cin>>s;
		if (s=="#") break;
		dict.push_back(s);
	}
	for (;;){
		std::string s; std::cin>>s;
		if (s=="#") break;
		bool have=false;
		for (int i=0;i<(int)dict.size();i++)
			if (dict[i]==s) {have=true; break;}
		if (have){
			std::cout<<s<<" is correct"<<std::endl;
			continue;
		}
		std::cout<<s<<": ";
		for (int i=0;i<(int)dict.size();i++)
			if (check(dict[i],s)) std::cout<<dict[i]<<" ";
		std::cout<<std::endl;
	}
}
