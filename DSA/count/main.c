#include<stdio.h>
#include<stdlib.h>
int main() {
  /* a buffer to hold the count of characters 0,...,256; it is
   * initialized to zero on every element */
  int count[256] = { 0 };
  float rate[256];
    int chi=0;
  int ch=0;
  int i=0,j=-1,l=-1;

  /* loop counter */
  int k;
    FILE *fp;
  /* file handle --- in this case I am parsing this source code */
  fp = fopen("new.txt", "r");

  /* a holder for each character (stored as int) */
  int c;

  /* for as long as we can get characters... */
  while((c=fgetc(fp))) {

    /* break if end of file */
    if(c == EOF) break;

    /* otherwise add one to the count of that particular character */
    count[c]+=1;
    ch++;
  }
  char cha[ch];
    int co[ch];
  /* now print the results; only if the count is different from
   * zero */
   printf("number of characters in file is %d\n",ch);
  for(k=0; k<256; k++) {
    if(count[k] > 0){
             cha[j++]=k;
             co[l++]=count[k];
             chi++;
        rate[k]=((float)count[k]/(float)ch);
      printf("char %c: %d times, rate:%f \n", k, count[k],rate[k]);

    }

  }
  /* close the file */
  fclose(fp);
  char chaa[chi-1];
  int coo[chi-1];
  printf("\n%d",chi);
  for(i=0; i<chi-1; i++){
     printf("\n%c %d",cha[i],co[i]);
     chaa[i]=cha[i];
     coo[i]=co[i];
  }


  /* that's it */
  return 0;
}
