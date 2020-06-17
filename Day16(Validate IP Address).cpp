class Solution {
public:
    string validIPAddress(string ip) {
        int a=0,b=0;
        for(int i=0;i<ip.length();i++){
            if(ip[i]=='.') a++;
            if(ip[i]==':') b++;
        }
        if((a!=0 && a!=3) || (b!=0 && b!=7) || ip.length()==0) return "Neither";
        else if(a!=0 && a==3){
            string s;
            if(ip[ip.length()-1]=='.') 
                return "Neither";
            for(int i=0;i<ip.length();i++){
                if(ip[i]!='.' && i!=ip.length()-1) 
                     s.push_back(ip[i]);
                else{
                    if(i==ip.length()-1) 
                        s.push_back(ip[i]);
                    if(s.size()==0) 
                        return "Neither";
                    else if(s.size()!=1 && s[0]=='0') 
                        return "Neither";
                    else if(s.length()>4) 
                        return "Neither";
                    else{
                        int ans=0;
                        for(int j=0;j<s.length();j++){
                            if(s[j]-'0'>9 || s[j]-'0'<0) 
                                return "Neither";
                            ans+=pow(10,(int)s.length()-j-1)*(s[j]-'0');
                        }
                        if(ans>255) 
                            return "Neither";
                    }
                    s.clear();
                }
            }
            return "IPv4";
        }
        else{
            string s;
            if(ip[ip.length()-1]==':') 
                return "Neither";
            for(int i=0;i<ip.length();i++){
                if(ip[i]!=':' && i!=ip.length()-1) 
                    s.push_back(ip[i]);
                else{
                    if(i==ip.length()-1) 
                        s.push_back(ip[i]);
                    if(s.size()==0) 
                        return "Neither";
                    else if(s.size()>4) 
                        return "Neither";
                    else{
                        for(int j=0;j<s.length();j++)
                            if(!((s[j]<='F' && s[j]>='A') || (s[j]<='f' && s[j]>='a') || (s[j]>='0' && s[j]<='9'))) 
                                return "Neither";
                    }
                    s.clear();
                }
            }
            return "IPv6";
        } 
        return ""; 
    }
};
