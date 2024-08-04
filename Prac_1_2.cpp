#include<iostream>
using namespace std;
int main()
{
    string sen;
    int count=0, max=0;
    cout<<"Enter the Sentence:";
    fflush(stdin);
    getline(cin,sen);

    for(int i=0; sen[i]!='\0'; i++)
    {
        if(sen[i]!=' ')
        {
            count++;
        }
        else
        {
            count=0;
        }
        if(max<count)
        {
            max=count;
        }
    }
    cout<<"Longest word is:"<<max;
    return 0;
}