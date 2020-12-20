#include<iostream> 
#include<cstring>
using namespace std;
int main()
{
string code, text, ncode, ntext;
bool check = true, chr[26];
char match[26];
freopen("spy.in","r",stdin);
freopen("spy.out","w",stdout);
cin >> code >> text >> ncode;
memset(chr,false,sizeof(chr));

int len = code.length();
int nlen = ncode.length();

int i, j;
if(check)
{
    for(i = 0; i < len-1; i++)
        for(j = i+1; j < len; j++)
        {
            if((text[i] != text[j]) && (code[i] == code[j]))
               check = false;
        }  
}

if(check)
{
    for(i = 0; i < len; i++)
        chr[(int)text[i]-65] = true;
    for(i = 0; i < 26; i++)
       if(chr[i] == false) check = false;
}

if(check == false)
{
    cout << "Failed" << endl;
}
else
{
    for(i = 0; i < len; i++)
       match[(int)code[i]-65] = text[i];
    for(i = 0; i < nlen; i++)
       cout << match[(int)ncode[i]-65];
    cout << endl;
}

fclose(stdin);
fclose(stdout);

return 0;
}
