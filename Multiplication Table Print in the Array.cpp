

# include <iostream.h>
# include <conio.h>
# include <math.h>
# include <stdlib.h>
# include <iomanip.h>
# include <dos.h>

void main(){
clrscr();
int a[10][10];
int i,j;
for (i=1;i<=10;i++) {
for (j=1;j<=10;j++){
a[i-1][j-1]=i*j;
cout<<setw(4)<<a[i-1][j-1];
}
cout<<endl<<endl;
}

getch();