//14253014--ZEHRA BETÜL BOYNUEÐRÝ
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	FILE *dosya, *dosyaCikis;
	char kelime[30], _kelime[30], _Kelime[30] ;
	int toplamOnceki = 0, toplamSonraki = 0, i, j, z, dengeliKelime = 0, a, toplamKelimeAgirligi = 0, y = 0, x = 0;
	char dengeHarfi[2] = { 'a' ,'\0' };
	char ad[100];
	printf("Lutfen islem yapilacak dosya ismini uzantisiyla birlikte giriniz:\n");
	scanf("%s", ad);
	dosya = fopen(ad, "r");
	dosyaCikis = fopen("balancedwords.txt", "w");
	if (dosya == NULL || dosyaCikis == NULL)
	{
		printf("Dosya acilamadi.");
	}
	else
	{
		while (fscanf(dosya, "%s", kelime) != EOF)
		{

			if (strlen(kelime) >= 3)
			{
			
					for (i = 1; i < strlen(kelime) - 1; i++)
					{

						toplamOnceki = 0;

						x = i;
						for (z = 0; z < i; z++)
						{


							if (kelime[z] >= 'A' && kelime[z] <= 'Z')
							{

								toplamOnceki += (kelime[z] - 64)*x;
								x--;

							}
							else
							{

								toplamOnceki += (kelime[z] - 96)*x;
								x--;
							}
						}

						toplamSonraki = 0;


						for (j = i + 1; j < strlen(kelime); j++)
						{

							y = j - i;

							if (kelime[j] >= 'A' && kelime[j] <= 'Z')
							{
								toplamSonraki += (kelime[j] - 64)*y;
								y++;
							}
							else
							{
								toplamSonraki += (kelime[j] - 96)*y;
								y++;
							}


						}

						if (toplamOnceki == toplamSonraki)
						{
							a = 1;
							dengeHarfi[0] = kelime[i];

							dengeliKelime += 1;
							toplamKelimeAgirligi = 0;
							for (int k = 0; k < strlen(kelime); k++)
							{
								if (kelime[k] >= 'A' && kelime[k] <= 'Z')
								{
									toplamKelimeAgirligi += (kelime[k] - 64);
								}
								else
								{
									toplamKelimeAgirligi += (kelime[k] - 96);
								}

							}



							break;
						}
					}
			}


			if (a == 1) {

				z = 0;

				int m;
				for (m = 0; m <i; m++)
				{

					_kelime[m] = kelime[z];
					z++;
				}
				_kelime[m] = '\0';

				z = i + 1;
				for (m = 0; m<strlen(kelime) - i - 1; m++)
				{

					_Kelime[m] = kelime[z];
					z++;
				}
				_Kelime[m] = '\0';

				fprintf(dosyaCikis, "%s  %s  %s   %s(%d)  %d\n", _kelime, dengeHarfi, _Kelime, dengeHarfi, i, toplamKelimeAgirligi);
				a = 0;

			}
		}
	}

	printf("\n");
	printf("Giris dosyasi: %s \n", ad);
	printf("\n");
	printf("Cikis dosyasi: balancedwords.txt \n");
	printf("\n");
	printf("words.txt dosyasinda %d tane dengeli kelime var. Dengeli kelimeler balancedwords.txt dosyasina kaydedildi.\n  ", dengeliKelime);
	fclose(dosya);
	fclose(dosyaCikis);

}





