#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string str;
    cin>>str;
    int c = 0;

    for(int i = 0; i < str.size(); i++){
        string temp;
        for(int j = i; j < str.size(); j++){
            temp += str[j];
            bool b = 0;
            for(int k = 0; k < temp.size()/2; k++){
                if(temp[k] != temp[temp.size()-k]){
                    b = 1;
                    break;
                }
            }
            if(!b){
                c++;
            }
        }
    }

    if(c % 2){
        printf("Not Shera\n");
    }
    else{
        printf("Shera\n");
    }
}
