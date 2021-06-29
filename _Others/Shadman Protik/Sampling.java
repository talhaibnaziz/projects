String encode(int a)
{
    int sign=0;
    if(a<0)
    {
	sign=1;
	a = a*-1;
    }
    String s;
    for(int j=0;j<7;j++){
        if(a%2==0) s+='0';
        else s+='1';
        a/=2;
    }
    s+=(sign+'0');
    reverse(s.begin(),s.end());

    return s;
}

int decode(String s)
{
    for(int i=0;i<s.size();i+=8){
        int num=0;
        for(int j=i+1;j<i+8;j++){
            num*=2;
            num+=s[j]-'0';
        }
        if(s[i]=='1') num=-num;
    }
    return num;
}
