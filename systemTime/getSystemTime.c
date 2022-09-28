#include <windows.h>
#include <stdio.h>

SYSTEMTIME calculate_elapsed(SYSTEMTIME new, SYSTEMTIME old){
    // need to ensure that old < new
    int nSecond = new.wSecond;
    int nMillSec = new.wMilliseconds;

    int oSecond = old.wSecond;
    int oMillSec = old.wMilliseconds;
    
    SYSTEMTIME eTime;
    int eSecond;
    int eMillSec;
    eSecond = nSecond - oSecond;
    if (oMillSec < nMillSec) {
        eMillSec = nMillSec - oMillSec;
    } else {
        eMillSec = 1000 - oMillSec;
        eSecond --;
    }
    eTime.wSecond = eSecond;
    eTime.wMilliseconds = eMillSec;

    return eTime;
}

void main()
{
    SYSTEMTIME st, lt, nst, et;
    GetSystemTime(&st);
    GetLocalTime(&lt);
    
    printf("The system time is: %02d:%02d:%02d.%03d\n", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
    printf(" The local time is: %02d:%02d:%02d.%03d\n", lt.wHour, lt.wMinute, lt.wSecond, lt.wMilliseconds);

    int s = 1000;
    printf("sleep for %d milliseconds\n", s);
    Sleep(s);

    GetSystemTime(&nst);
    printf("new system time is: %02d:%02d:%02d.%03d\n", nst.wHour, nst.wMinute, nst.wSecond, nst.wMilliseconds);
    
    et = calculate_elapsed(nst, st);
    printf("elasped for: %02d.%03d seconds", et.wSecond, et.wMilliseconds);

}