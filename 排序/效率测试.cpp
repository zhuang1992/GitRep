#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <dos.h>
#include <conio.h>
#include <windows.h>
using namespace std;
int main()
{
    int n;
    DWORD take;
    scanf("%d",&n);
    srand((unsigned int)time(NULL));
  //  for(int i=0;i<n;i++)
  //      elems[i]=rand();

    take = GetTickCount();
    Sleep(1000); //单位是ms
   // QuickSort(elems,0,n-1);

    printf("\n%ld\n", GetTickCount() - take);//单位是ms

}
