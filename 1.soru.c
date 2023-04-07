#include <stdio.h>

/* 
	1.SORUNUN KONUSU :  2D Matriste Veri Arama

	1.SORU : : Bir m x n tamsay� matrisinde bir de�er hedefini arayan ve sonucu sat�r/s�tun olarak veren algoritma. 
	Matris �zellikleri;
	*Her sat�rdaki tamsay�lar soldan sa�a do�ru artan �ekilde s�ralan�r.
	*Her s�tundaki tamsay�lar yukar�dan a�a��ya do�ru artan �ekilde s�ralan�r.
*/

int main() {
	
	printf("1.SORU : Bir m x n tamsayi matrisinde bir deger hedefini arayan ve sonucu satir/sutun olarak veren algoritma.\n");
	printf("\n\n");
	
    // De�i�kenleri tan�mlama
    int m, n, hedef;
    int i, j, k, l;
    int temp, flag = 0; // Burada bulanan temp ge�ici de�er anlam�na gelir. Flag ise sinyal verici veya herhangi bir de�er yerine kullan�labilir.(j,k,l,m gibi)
    
    printf("Matris boyutunu (m x n) seklinde giriniz: ");
    scanf("%d %d", &m, &n);

    int matris[m][n];

    printf("Matrisin elemanlarini giriniz:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &matris[i][j]);
        }
    }
    
    printf("Hedef degeri giriniz: ");
    scanf("%d", &hedef);

// �stenilen hedef de�erin sat�r ve s�tun �zerinde aranma
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            if(matris[i][j] == hedef) {
                printf("Hedef deger matrisin %d. satirinda ve %d. sutununda bulundu.\n", i+1, j+1);
                flag = 1;
                break;
            }
        }
// Hedef de�erin girilen de�erlerle kar��la�t�rmas� yap�l�r.    
        if(flag == 1) {
            break;
        }
        
        else
        	printf("Hedef deger bulunamadi.\n");
        	break;
    }
    printf("Matrisin siralanmis hali:\n");
    
// Her bir de�er i�in b�y�kl�k ve k���kl�k aramas� yap�l�r ve ge�ici bir de�ere atanarak i�lemler devam eder. 
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            for(k=0; k<n-1; k++) {
                for(l=k+1; l<n; l++) {
                    if(matris[i][k] > matris[i][l]) {
                        temp = matris[i][k];
                        matris[i][k] = matris[i][l];
                        matris[i][l] = temp;
                    }
                }
            }
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m-1; j++) {
            for(k=j+1; k<m; k++) {
                if(matris[j][i] > matris[k][i]) {
                    temp = matris[j][i];
                    matris[j][i] = matris[k][i];
                    matris[k][i] = temp;
                }
            }
        }
    }
// �stenen kriterlere g�re aranan matriisn s�ralanm�� �ekilde yaz�lmas�.
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }

    return 0;
}
