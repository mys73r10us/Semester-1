#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int angka;
    cin >> angka;
    int k[angka][angka];
    for (int x=0;x<angka;x++){
        for (int x2=0;x2<angka;x2++){
            cin >> k[x][x2];
        }
    }
    int bV[angka]={0}; 
    int bC[angka]={0}; 
    int lV = 0;
    int lC[angka]={0};
    for (int x=0;x<angka;x++){
        for (int x2=0;x2<angka;x2++){
            if (k[x][x2]>bV[x2]){
                bV[x2]=k[x][x2];
                bC[x2]++;
            }
            if (k[x][x2]>lV){
                lV = k[x][x2];
                lC[x]++;
            }
        }
        lV =0;
    }
    for (int x=0;x<angka;x++){
        cout <<bC[x]<<" ";
    }
    cout << endl;
    for (int x=0;x<angka;x++){
        cout << lC[x] << endl;
    }
}
