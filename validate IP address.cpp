//Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

#include<bits/stdc++.h>
using namespace std;
 bool isHexAlpha(char ch) {
        return ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F'); 
    }
    
    bool isNum(char ch) {
        return ('0' <= ch && ch <= '9');
    }
bool isHexAlphaNum(char ch) {
        return isHexAlpha(ch) || isNum(ch);
    }
bool isip6(string IP){
    string tstr;
        int tmp_int;
       // IP.push_back(':');
        for (int i=0;i< IP.length();i++) {
            if (isHexAlphaNum(IP[i])) {
                tstr.push_back(IP[i]);
            }
            else if (IP[i] == ':') {
                if (tstr.empty()) return false;
                cout<<tstr.size()<<endl;
                if (tstr.size() >= 5) return false;
                tstr = "";
            }
            else {  // invalid char
                return false;
            }
        }
        return true;
    
}
bool isip4(string IP){
    string tstr;
        int tmp_int;
       // IP.push_back('.');
        for (int i=0;i<IP.length();i++) {
            if (isNum(IP[i])) {
                tstr.push_back(IP[i]);
            }
            else if (IP[i] == '.') {
                if (tstr.empty()) return false;
                if (tstr.size() >3) return false;
                //if (tstr[0] == '0' && tstr.size() > 1) return false;
                //tmp_int = stoi(tstr);
                if (tmp_int < 0 || tmp_int > 255) return false;
                tstr = "";
            }
            else {
                return false;
            }
        }
        return true;
}
string validIPAddress(string IP) {
     int n=IP.length();
        int ip4=0;
        int ip6=0;
        for(int i=0;i<n;i++){
            if(IP[i]=='.'){
                ip4++;
            }
            else if(IP[i]==':'){
                ip6++;
            }
            else if (!isHexAlphaNum(IP[i])) {
            	//cout<<IP[i]<<endl;
            	return "Neither";
			}
			
        }
        if (ip4 == 3 && ip6 == 0)
            return (isip4(IP)? "IPv4": "Neither");
        if (ip4 == 0 && ip6 == 7) 
            return (isip6(IP)? "IPv6":"Neither");
        return "Neither";
    }
int main(){
	cout<<validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:73341");
}
