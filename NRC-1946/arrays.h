#include <stdlib.h>
#include <time.h>
namespace vector{
    void llenar (int v[], int n, int rangoi=0, int rangof=10){
        int i;
        for (int i = 0; i < n; i++)
        {
            v[i] = rand()%(rangof-rangoi+1)+rangoi;
            v[i] = rangoi + rand()% (rangof+1 - rangoi);
            //variable= limite_inferior + rand()% (limite_superior+1 - limite_inferior );
        }
        

    }
}

//isaac loaiza 