#include <stdio.h>
#include <stdlib.h>

int lineerArama(int dizi[], int boyut, int eleman) {
    for (int i=0; i<boyut; i++) {
        if (dizi[i]==eleman) {
            return i; // elemanı bulursa dizinin indeksini döndürüyor
        }
    }
    return -1; // eleman bulunmazsa -1 döndürüyor
}

int main() {
    int boyut;
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d", &boyut);

    int dizi[boyut];
    printf("Dizinin elemanlarini giriniz:\n");
    for (int i=0; i<boyut; i++) {
        printf("Eleman %d: ",i+1);
        scanf("%d", &dizi[i]);
    }

    int aranan;
    printf("Aradiginiz elemani giriniz: ");
    scanf("%d", &aranan);

    int indeks=lineerArama(dizi, boyut, aranan);

    if (indeks!=-1) {
        printf("Eleman %d, dizinin %d. indeksinde bulundu.\n", aranan, indeks);
    } else {
        printf("Eleman bulunamadi.\n");
    }

    return 0;
}