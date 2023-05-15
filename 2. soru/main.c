#include <stdio.h>
#include <stdlib.h>

int ikiliArama(int dizi[], int boyut, int eleman) {
    int baslangic = 0;
    int bitis = boyut-1;

    while (baslangic<=bitis) {
        int orta = (baslangic+bitis)/2;

        if (dizi[orta]==eleman) {
            return orta; // eleman bulundu dizinin indeksini döndür
        }

        if (dizi[orta] < eleman) {
            baslangic = orta + 1;
        } else {
            bitis = orta - 1;
        }
    }

    return -1; // eleman bulunamadı -1 döndür
}

int main() {
    int dizi[] = {4,8,3,84,47,76,9,24,68};
    int boyut = sizeof(dizi)/sizeof(dizi[0]);

    int aranan;
    printf("Aranacak elemani giriniz: ");
    scanf("%d", &aranan);

    int indeks = ikiliArama(dizi, boyut, aranan);

    if (indeks!=-1) {
        printf("Eleman %d, dizinin %d. indeksinde bulundu.\n", aranan, indeks);
    } else {
        printf("Eleman bulunamadi.\n");
    }

    return 0;
}