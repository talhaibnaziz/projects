#include<bits/stdc++.h>
using namespace std; ///did not map _,$
map<char,int>identifer;
int main()
{
    int mapped_val=0;
    char alpha='A';
    for(int i=0; i<58; i++)
    {
        mapped_val++;
        identifer[alpha]=i;
        alpha++;
        if(alpha=='Z')
        {

            i++;
            identifer[alpha]=i; ///A-Z er a-z
            alpha=alpha+7;  ///Z er por a ante :|
        }
    }
    identifer['-']=mapped_val++;
    mapped_val++;
    identifer['$']=mapped_val+2;
    mapped_val++;
    identifer['-']=mapped_val+3;
    mapped_val++;
    alpha='0';
    for(int i=58; i<68; i++)
    {
        identifer[alpha]=i;
        alpha++;
        mapped_val++;
    }
    vector<string>tok;
    string arr[]= {"if","for","while","else","int","EOF"};
    string line;
    ifstream myfile;
    myfile.open("input.txt",std::ifstream::in);
    ofstream out("keyword.txt");
    ofstream cout_id("identifier.txt");
    if(myfile.is_open())
    {
        int cnt=0;
        while(getline(myfile,line))
        {
            /// tok.clear();
            cnt++;
            char* dest = new char[line.length() + 1];
            strcpy(dest,line.c_str());
            char *p = strtok(dest, " \t");
            //  p=strtok(dest,",");
            while (p)
            {

                string s(p);

                for(int i=0; arr[i]!="EOF"; i++)
                {
                    int pos=s.find(arr[i]);

                    if(pos!=-1)
                    {
                        if(i==0)  ///if
                        {
                            cout<<"line no: "<<cnt<< " -> "<<s<<endl;
                            cout<<"pos: "<<pos<<endl;
                            if(pos==0 && (s[pos+2]==NULL || s[pos+2]=='('))
                            {
                                out<<arr[i]<<" "<<cnt<<endl;
                            }
                            else if(pos!=0)
                            {
                                if(s[pos-1]=='{' && ( s[pos+2]==NULL || s[pos+2]=='('))
                                {

                                    out<<arr[i]<<" "<<cnt<<endl;

                                }
                            }

                        }
                        else if(i==1) ///for
                        {
                            if(pos==0 &&(s[pos+3]==NULL || s[pos+3]=='('))
                            {
                                out<<arr[i]<<" "<<cnt<<endl;

                            }
                            else if(pos!=0 && (s[pos-1]=='{' || s[pos-1]==';')&& (s[pos+3]==NULL || s[pos+3]==NULL))
                            {
                                out<<arr[i]<<" "<<cnt<<endl;

                            }
                        }
                        else if(i==2)///while
                        {
                            if(pos==0 && (s[pos+5]==NULL || s[pos+5]=='('))
                            {
                                out<<arr[i]<<" "<<cnt<<endl;
                            }
                            else if(pos!=0 && (s[pos-1]=='{' || s[pos-1]==';') && (s[pos+5]==NULL || s[pos+5]=='('))
                            {
                                out<<arr[i]<<" "<<cnt<<endl;

                            }
                        }
                        else if(i==3)///else
                        {
                            if(pos==0 && (s[pos+4]==NULL || s[pos+4]=='{'))
                            {
                                out<<arr[i]<<" "<<cnt<<endl;

                            }
                            else if(pos!=0 && (s[pos-1]=='{' || s[pos-1]==';'))
                            {
                                out<<arr[i]<<" "<<cnt<<endl;

                            }
                        }
                        else if(i==4)///int
                        {
                            if(pos==0 && (s[pos+3]==NULL || s[pos+3]=='('))
                            {
                                out<<arr[i]<<" "<<cnt<<endl;

                            }
                            else if(pos!=0 && s[pos-1]=='(' && (s[pos+3]==NULL || s[pos+3]=='('))
                            {
                                out<<arr[i]<<" "<<cnt<<endl;

                            }

                        }

                    }
                }


                tok.push_back(s);



                p = strtok(NULL, " ");
            }

            cout<<endl<<endl;

        }


    }
    myfile.close();
    myfile.open("input.txt",std::ifstream::in);

    int cnt1=0;

    if(myfile.is_open())
    {

        while(getline(myfile,line))
        {
            cnt1++;
            string temp;
            int flag=0;

            for(int i=0; i!=line.size(); i++)
            {


                if(flag==0) ///int / char paini
                {
                    if(identifer[line[i]]!=0)
                    {
                        temp=temp+line[i];
                    }
                    else
                    {
                        if(temp=="int" || temp=="char")
                        {
                            flag=1;
                            temp.clear();
                        }
                        temp.clear(); ///char chara onno kichu paise,tai ager ta muche felte

                    }
                }
                else ///char or int paise
                {
                    if(line[i]==';')
                    {
                        if(line[i]=='(') {} ///parenthesis diye shesh hole don't print ->func
                        else if(temp[0]>='0' && temp[0]<='9') {} ///number diye shuru hole don't print
                        else if(temp[0]==' ') {} ///space kemne included hoye jacche bujhtesina, but don't print
                        else if(temp[0]==NULL) {} ///int main e null ta chole eshe jhamela hocchilo :@
                        else
                        {
                            cout<<temp<<" "<<cnt1<<endl;
                            break;
                        }
                        break;
                    }
                    else if(identifer[line[i]]!=0)
                    {
                        temp=temp+line[i];
                    }
                    else
                    {
                        // cout<<"else e dhukar por temp[0] "<<temp[0]<<endl;
                        if(line[i]=='(') {} ///parenthesis diye shesh hole don't print ->func
                        else if(temp[0]>='0' && temp[0]<='9') {} ///number diye shuru hole don't print
                        else if(temp[0]==' ') {} ///space kemne included hoye jacche bujhtesina, but don't print
                        else if(temp[0]==NULL) {} ///int main e null ta chole eshe jhamela hocchilo :@
                        else
                        {
                            cout_id<<temp<<" "<<cnt1<<endl;
                            //else cout<<temp<<endl;
                            // int k=temp[0];
                            //cout<<k<<endl;
                        }
                        temp.clear();
                    }

                }
            }
            // cout<<endl;
        }

    }


    string temp1;
    string not_func[]= {"while","if","for"};
    ofstream cout_func("function.txt");
    int space_dekhsi=0;
    int cnt2=0;
    myfile.close();
    myfile.open("input.txt",std::ifstream::in);
    if(myfile.is_open())
    {


        while(getline(myfile,line))
        {
            cnt2++;
            int flag11=0;
            for(int i=0; i!=line.size(); i++)
            {
                if(identifer[line[i]]!=0)
                {
                    if(space_dekhsi==1)
                    {
                        temp1.clear();///space dekhar ag porjonto ja porsi ta muche feltesi, among the valid chars
                        space_dekhsi=0;
                    }

                    temp1+=line[i];
                }
                else if(line[i]==' ')
                {
                    space_dekhsi=1;
                }
                else if(line[i]=='.')temp1.clear();
                else if(line[i]=='(')
                {
                    for(int i=0; i<3; i++)
                    {
                        //   cout<<"temp1    " <<temp1<<endl;
                        if(temp1==not_func[i])
                        {
                            flag11=1;
                        }
                        // if(temp1=="compare")cout<<"compare er jonno flag11 "<<flag11<<endl;
                    }
                    if(temp1[0]=='\0') {} ///clear kore kichu na pele null pacche
                    else  if(flag11==0)
                    {
                        cout_func<<temp1<< " "<<cnt2<<endl;
                        temp1.clear();
                    }
                    temp1.clear();
                    flag11=0;

                }
            }
            temp1.clear();
        }
    }

    return 0;
}
