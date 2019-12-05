#include <cstdio>
#include <string>

using namespace std;

int main(void){
  int N,Q,i,j;

  scanf("%d%d", &N, &Q);

  string s,s1;
  for(i=0;i<N;i++) s += (char)('A' + i);
	s1 = s;
  for(i=0;i<N;i++) for(j=i+1;j<N;j++){
    printf("? %c %c\n", s[i], s[j]);
    fflush(stdout);
    char ans;
    scanf(" %c", &ans);
    if(ans == '<') swap(s1[i], s1[j]);
  }

  printf("! %s\n", s1.c_str());
  fflush(stdout);

  return 0;
}
