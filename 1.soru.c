#include <stdio.h>

/* 
	1.SORUNUN KONUSU :  2D Matriste Veri Arama

	1.SORU : : Bir m x n tamsayý matrisinde bir deðer hedefini arayan ve sonucu satýr/sütun olarak veren algoritma. 
	Matris Özellikleri;
	*Her satýrdaki tamsayýlar soldan saða doðru artan þekilde sýralanýr.
	*Her sütundaki tamsayýlar yukarýdan aþaðýya doðru artan þekilde sýralanýr.
*/

int main() {
	
	printf("1.SORU : Bir m x n tamsayi matrisinde bir deger hedefini arayan ve sonucu satir/sutun olarak veren algoritma.\n");
	printf("\n\n");
	
    // Deðiþkenleri tanýmlama
    int m, n, hedef;
    int i, j, k, l;
    int temp, flag = 0; // Burada bulanan temp geçici deðer anlamýna gelir. Flag ise sinyal verici veya herhangi bir deðer yerine kullanýlabilir.(j,k,l,m gibi)
    
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

// Ýstenilen hedef deðerin satýr ve sütun üzerinde aranma
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            if(matris[i][j] == hedef) {
                printf("Hedef deger matrisin %d. satirinda ve %d. sutununda bulundu.\n", i+1, j+1);
                flag = 1;
                break;
            }
        }
// Hedef deðerin girilen deðerlerle karþýlaþtýrmasý yapýlýr.    
        if(flag == 1) {
            break;
        }
        
        else
        	printf("Hedef deger bulunamadi.\n");
        	break;
    }
    printf("Matrisin siralanmis hali:\n");
    
// Her bir deðer için büyüklük ve küçüklük aramasý yapýlýr ve geçici bir deðere atanarak iþlemler devam eder. 
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
// Ýstenen kriterlere göre aranan matriisn sýralanmýþ þekilde yazýlmasý.
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }

    return 0;
}
