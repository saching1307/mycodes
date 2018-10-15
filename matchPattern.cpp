#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
public:
	bool JudgePattern(string pattern, string s){
		if(pattern.empty()) return s.empty();
		if(s.empty()) return emptyOrSingleLetter(pattern);
		unordered_map<char, string> psmap;
		unordered_map<string, char> spmap;
		return judgeCore(pattern, 0, s, 0, psmap, spmap);
	}
private:
	bool judgeCore(string pattern, int t, string s, int p, unordered_map<char, string> &psmap, unordered_map<string, char> &spmap){
		int plen = pattern.length(); int slen = s.length();
		if(t == plen && p == slen) return true;
		if(t == plen || p == slen) return false;
		if(psmap.find(pattern[t]) != psmap.end()){
			if(p+psmap[pattern[t]].length() > slen) return false;
			string tmpstr = s.substr(p, psmap[pattern[t]].length());
			if(tmpstr == psmap[pattern[t]])
				return judgeCore(pattern, t+1, s, p+psmap[pattern[t]].length(), psmap, spmap);
		}else{
			for(int q = p+1; q <= slen; ++q){
				string subs = s.substr(p, q-p);
				if(spmap.find(subs) == spmap.end()){
					spmap[subs] = pattern[t];
					psmap[pattern[t]] = subs;
					if(judgeCore(pattern, t+1, s, q, psmap, spmap))
						return true;
					psmap.erase(psmap.find(pattern[t]));
					spmap.erase(spmap.find(subs));
				}
			}
		}
		return false;
	}

	bool emptyOrSingleLetter(string pattern){
		if(pattern.empty()) return true;
		for(int i = 1; i < pattern.length(); ++i){
			if(pattern[i] != pattern[0]) return false;
		}
		return true;
	}
};


int main(){
	Solution sln;
	cout << sln.JudgePattern("aaa", "") << endl;
	cout << sln.JudgePattern("aba", "red") << endl;
	cout << sln.JudgePattern("aabb", "xyzxyzabab") << endl;
	cout << sln.JudgePattern("aabb", "xyzxyzab") << endl;
	cout << sln.JudgePattern("fbcf", "xyzdoxyz") << endl;

	return 0;
}
