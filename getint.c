#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

// 5-1) fixing getint
int getint(int *pn) {
  int c, sign;
  while(isspace(c = getch()))
    ;
  if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if(c == '-' || c == '+'){
    int t = c;
    c = getch();
    if (!isdigit(c)){
      if(c != EOF) ungetch(c);
      ungetch(t);
      return 0;
    }
  }
    
  for(*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if(c != EOF)
    ungetch(c);

  return c;
}
