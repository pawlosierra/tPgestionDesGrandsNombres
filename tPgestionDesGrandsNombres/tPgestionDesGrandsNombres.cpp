#include <iostream>								
#include<string>																//pour chain de characters
#include<conio.h>																//_getch
#include<cstdlib>																//pour effacer l'ecran
#include<iomanip>
using namespace std;

typedef string GNOMBRE;

char etat, etat0;//option menu
const char E1 = '1';
const char E2 = '2';
const char E3 = '3';
const char E4 = '4';
const char E5 = '5';
const char E6 = '6';
const char E7 = '7';
const char E8 = '8';
const char E9 = 'Q';
char car;

bool estChiffre(char car) {
	return ((car >= '0') && (car <= '9'));
}

void saisirGn(GNOMBRE& gn1) {
	char car;
	int n = 0;
	system("cls");
	cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
	cout << "\n   -------------------------------------------";
	cout << "\n   Donner le Nombre    :";
	gn1 = "+";
	
		do {
			car = _getch();
			cout << car;
			if ((car == '+') || estChiffre(car)) {
				do {
					if (estChiffre(car)) {
						while (car == '0') {
							car = _getch();
							cout << car;
						}
						while (estChiffre(car)) {
							gn1 = gn1 + car;
							car = _getch();
							cout << car;
						}
					}
					else
						car = _getch();
					cout << car;
				} while (car != '\r');
			}
			else
				if (car == '-') {
					gn1 = "-";
					do {
						car = _getch();
						cout << car;
						while (car == '0') {
							car = _getch();
							cout << car;
						}
						while (estChiffre(car)) {
							gn1 = gn1 + car;
							car = _getch();
							cout << car;
						}
					} while (car != '\r');
				}
		} while (car != '\r');
		n = gn1.size();
		if (n == 1) {
			gn1 = "+0";
		}
}

bool functionestEgal(GNOMBRE& gn1, GNOMBRE& gn2) {
	int n1 = gn1.size();
	int n2 = gn2.size();
	bool estEgal = false;
	if (n1 == n2) {
		for (int i = 0; i <= n1; i++) {
			if (gn1[i] == gn2[i]) {
				estEgal = true;
			}
			else {
				estEgal = false;
				i = n1;
			}
		}
	}return estEgal;
}

bool functionestInferieur(GNOMBRE& gn1, GNOMBRE& gn2) {
	int n1 = gn1.size();
	int n2 = gn2.size();
	bool estInferieur = false;
	if (n1 == n2) {
		if ((gn1[0] == '+') && (gn2[0] == '+')) {
			if (gn1[1] < gn2[1]) {
				estInferieur = true;
			}
			else
				if (gn1[1] == gn2[1]) {//
					for (int i = 2; i <= n1; i++) {
						if (gn1[i] < gn2[i]) {
							estInferieur = true;
							i = n1;
						}
					}
				}//
		}
		else
			if ((gn1[0] == '+') && (gn2[0] == '-')) {
				estInferieur = false;
			}
			else
				if ((gn1[0] == '-') && (gn2[0] == '+')) {
					estInferieur = true;
				}
				else
					if ((gn1[0] == '-') && (gn2[0] == '-')) {
						if (gn1[1] > gn2[1]) {					//
							estInferieur = true;				//
						}
						else
							if (gn1[1] == gn2[1]) {//
								for (int i = 2; i <= n1; i++) {
									if (gn1[i] > gn2[i]) {
										estInferieur = true;
										i = n1;
									}
								}
							}//
					}
	}
	else
		if ((gn1[0] == '+') && (gn2[0] == '+')) {
			if (n2 > n1) {
				estInferieur = true;
			}
		}
		else
			if ((gn1[0] == '+') && (gn2[0] == '-')) {
				estInferieur = false;
			}
			else
				if ((gn1[0] == '-') && (gn2[0] == '+')) {
					estInferieur = true;
				}
				else
					if ((gn1[0] == '-') && (gn2[0] == '-')) {
						if (n1 < n2) {
							estInferieur = false;
						}
						else
							estInferieur = true;
					}
	return estInferieur;
}

bool functionestSuperieur(GNOMBRE& gn1, GNOMBRE& gn2) {
	int n1 = gn1.size();
	int n2 = gn2.size();
	bool estSuperieur = false;
	if (n1 == n2) {
		if ((gn1[0] == '+') && (gn2[0] == '+')) {
			if (gn1[1] > gn2[1]) {
				estSuperieur = true;
			}
			else
				for (int i = 2; i <= n1; i++) {
					if (gn1[i] > gn2[i]) {
						estSuperieur = true;
						i = n1;
					}
				}
		}
		else
			if ((gn1[0] == '+') && (gn2[0] == '-')) {
				estSuperieur = true;
			}
			else
				if ((gn1[0] == '-') && (gn2[0] == '+')) {
					estSuperieur = false;
				}
				else
					if ((gn1[0] == '-') && (gn2[0] == '-')) {
						if (gn2[1] > gn1[1]) {//
							estSuperieur = true;
						}
						else
							for (int i = 2; i <= n1; i++) {
								if (gn2[i] > gn1[i]) {
									estSuperieur = true;
									i = n1;
								}
							}

					}
	}
	else
		if ((gn1[0] == '+') && (gn2[0] == '+')) {
			if (n1 > n2) {
				estSuperieur = true;
			}
		}
		else
			if ((gn1[0] == '+') && (gn2[0] == '-')) {
				estSuperieur = true;
			}
			else
				if ((gn1[0] == '-') && (gn2[0] == '-')) {
					if (n1 < n2) {
						estSuperieur = true;
					}
				}
	return estSuperieur;
}

bool functionestInferieurOuEgal(GNOMBRE gn1, GNOMBRE gn2) {
	bool estInferieurOuEgal = false;
	if (functionestInferieur(gn1, gn2)) {
		estInferieurOuEgal = true;
	}
	return estInferieurOuEgal;
}

bool functionestSuperieurOuEgal(GNOMBRE gn1, GNOMBRE gn2) {
	bool estSuperieurOuEgal = false;
	if (functionestSuperieur(gn1, gn2)) {
		estSuperieurOuEgal = true;
	}
	return estSuperieurOuEgal;
}

GNOMBRE inversantleContenu(GNOMBRE& gresultat, int n1) {
	int temp;
	for (int i = 0; i < (n1 / 2); i++) {
		temp = gresultat[i];
		gresultat[i] = gresultat[n1 - i - 1];
		gresultat[n1 - i - 1] = temp;
	}
	return gresultat;
}

GNOMBRE inversantleContenu1(GNOMBRE& gn1, int n1) {
	int temp;
	for (int i = 0; i < (n1 / 2); i++) {
		temp = gn1[i];
		gn1[i] = gn1[n1 - i - 1];
		gn1[n1 - i - 1] = temp;
	}
	return gn1;
}

GNOMBRE inversantleContenu2(GNOMBRE& gn2, int n2) {
	int temp;
	for (int i = 0; i < (n2 / 2); i++) {
		temp = gn2[i];
		gn2[i] = gn2[n2 - i - 1];
		gn2[n2 - i - 1] = temp;
	}
	return gn2;
}

GNOMBRE inversant(GNOMBRE& gresultat, int n1) {
	GNOMBRE temp1 = gresultat;
	int nombreentier1 = 0;
	for (int i = 0; i <= 0; i++) {
		temp1 = gresultat[0];
	}

	for (int i = n1 - 1; i >= 1; i--) {
		switch (gresultat[i]) {
		case '0': nombreentier1 = 0; break;
		case '1': nombreentier1 = 1; break;
		case '2': nombreentier1 = 2; break;
		case '3': nombreentier1 = 3; break;
		case '4': nombreentier1 = 4; break;
		case '5': nombreentier1 = 5; break;
		case '6': nombreentier1 = 6; break;
		case '7': nombreentier1 = 7; break;
		case '8': nombreentier1 = 8; break;
		case '9': nombreentier1 = 9; break;
		}
		temp1 = temp1 + to_string(nombreentier1);
	}
	gresultat = temp1;
	return gresultat;
}

GNOMBRE somme(GNOMBRE gn1, GNOMBRE gn2) {
	int n1 = gn1.size();
	int n2 = gn2.size();
	GNOMBRE gresultat = "+";
	GNOMBRE temp = "+";
	int nombreentier1 = 0;
	int nombreentier2 = 0;
	int resultat = 0;
	int resultat1 = 0;
	int resultat2 = 0;
	int i = 0;

	if (n1 > n2) {
		do {
			temp = temp + '0';
			i++;
		} while (i != (n1 - n2));
		for (int i = 1; i <= n2; i++) {
			temp = temp + gn2[i];
		}
		gn2 = temp;
		n2 = n1;
	}
	else
		if (n2 > n1) {
			do {
				temp = temp + '0';
				i++;
			} while (i != (n2 - n1));
			for (int i = 1; i <= n1; i++) {
				temp = temp + gn1[i];
			}
			gn1 = temp;
			n1 = n2;

		}
	if (n1 == n2) {
		gn1=inversantleContenu1(gn1, n1);
		gn2=inversantleContenu2(gn2, n2);
		for (int i = 0; i < n1 - 1; i++) {		
			switch (gn1[i]) {
			case '0': nombreentier1 = 0; break;
			case '1': nombreentier1 = 1; break;
			case '2': nombreentier1 = 2; break;
			case '3': nombreentier1 = 3; break;
			case '4': nombreentier1 = 4; break;
			case '5': nombreentier1 = 5; break;
			case '6': nombreentier1 = 6; break;
			case '7': nombreentier1 = 7; break;
			case '8': nombreentier1 = 8; break;
			case '9': nombreentier1 = 9; break;
			}
			switch (gn2[i]) {
			case '0': nombreentier2 = 0; break;
			case '1': nombreentier2 = 1; break;
			case '2': nombreentier2 = 2; break;
			case '3': nombreentier2 = 3; break;
			case '4': nombreentier2 = 4; break;
			case '5': nombreentier2 = 5; break;
			case '6': nombreentier2 = 6; break;
			case '7': nombreentier2 = 7; break;
			case '8': nombreentier2 = 8; break;
			case '9': nombreentier2 = 9; break;			
			}
			resultat = nombreentier1 + nombreentier2;
			if ((i == n1 - 2) && (resultat >= 10)) {
				resultat = resultat + resultat2;
				resultat1 = resultat % 10;
				resultat2 = resultat / 10;
				gresultat = gresultat + to_string(resultat1);
				gresultat = gresultat + to_string(resultat2);
				resultat1 = 0;
				resultat2 = 0;
			}
			else
				if (resultat <= 9) {
					resultat = resultat + resultat2;
					if (resultat <= 9) {
						gresultat = gresultat + to_string(resultat);
						resultat1 = 0;
						resultat2 = 0;
					}
					else {
						resultat1 = resultat % 10;
						resultat2 = resultat / 10;
						if ((i == n1 - 2) && (resultat >= 10)) {
							gresultat = gresultat + to_string(resultat1);
							gresultat = gresultat + to_string(resultat2);
						}
						else
						{
							gresultat = gresultat + to_string(resultat1);
						}
					}

				}
				else
					if (resultat >= 10) {
						resultat = resultat + resultat2;
						resultat1 = resultat % 10;
						resultat2 = resultat / 10;
						gresultat = gresultat + to_string(resultat1);
					}
		}
		n1 = gresultat.size();														//Il est necessaire d'utiliser la fonction int n1=gn1.size() pour mettre a jour la taille du nombre.
		gresultat=inversant(gresultat, n1);
	}
	return gresultat;
}

GNOMBRE difference(GNOMBRE gn1, GNOMBRE gn2) {
	int n1 = gn1.size();
	int n2 = gn2.size();
	GNOMBRE gresultat = "";
	GNOMBRE temp = "+";
	GNOMBRE gntemp1 = "";
	GNOMBRE gntemp2 = "";
	int nombreentier1 = 0;
	int nombreentier2 = 0;

	int resultat = 0;
	int resultat1 = 10;
	int resultat2 = 0;
	int i = 0;
	int j = 0;


	if (n1 > n2) {
		do {
			temp = temp + '0';			
			i++;
		} while (i != (n1 - n2));
		for (int i = 1; i <= n2; i++) {
			temp = temp + gn2[i];
		}
		gn2 = temp;
		n2 = n1;
	}
	else
		if (n2 > n1) {
			do {
				temp = temp + '0';			
				i++;
			} while (i != (n2 - n1));
			for (int i = 1; i <= n1; i++) {
				temp = temp + gn1[i];
			}
			gn1 = temp;
			n1 = n2;

		}if (n1 == n2) {
			for (int i = 1; i <= n1; i++) {
				if (gn1[i] == gn2[i]) {
					gntemp1 = gn1;
					gntemp2 = gn2;
					if (i == (n1 - 1)) {
						i = n1;
						gresultat = "+";
					}
				}

				if (gn1[i] > gn2[i]) {
					gntemp1 = gn1;
					gntemp2 = gn2;
					i = n1;
					gresultat = "+";
				}
				else
					if (gn2[i] > gn1[i]) {
						gntemp1 = gn2;
						gntemp2 = gn1;
						i = n1;
						gresultat = "-";
					}
			}
			gntemp1=inversantleContenu1(gntemp1, n1);
			gntemp2=inversantleContenu2(gntemp2, n2);
			for (int i = 0; i < n1 - 1; i++) {		

				switch (gntemp1[i]) {
				case '0': nombreentier1 = 0; break;
				case '1': nombreentier1 = 1; break;
				case '2': nombreentier1 = 2; break;
				case '3': nombreentier1 = 3; break;
				case '4': nombreentier1 = 4; break;
				case '5': nombreentier1 = 5; break;
				case '6': nombreentier1 = 6; break;
				case '7': nombreentier1 = 7; break;
				case '8': nombreentier1 = 8; break;
				case '9': nombreentier1 = 9; break;
				}
				switch (gntemp2[i]) {
				case '0': nombreentier2 = 0; break;
				case '1': nombreentier2 = 1; break;
				case '2': nombreentier2 = 2; break;
				case '3': nombreentier2 = 3; break;
				case '4': nombreentier2 = 4; break;
				case '5': nombreentier2 = 5; break;
				case '6': nombreentier2 = 6; break;
				case '7': nombreentier2 = 7; break;
				case '8': nombreentier2 = 8; break;
				case '9': nombreentier2 = 9; break;			
				}
				if ((nombreentier1 > nombreentier2)) { 
					nombreentier1 = nombreentier1 - resultat2;
					resultat = nombreentier1 - nombreentier2;
					gresultat = gresultat + to_string(resultat);
					resultat2 = 0;
					resultat1 = 10;
					j = 0;
				}
				else
					if ((nombreentier1 == nombreentier2) && (j == 0)) {
						resultat = nombreentier1 - nombreentier2;
						gresultat = gresultat + to_string(resultat);
					}
					else
						if (nombreentier1 <= nombreentier2) {
							j++;
							resultat1;
							nombreentier1 = nombreentier1 + resultat1;
							resultat2 = 1;
							resultat1 = 9;
							resultat = nombreentier1 - nombreentier2;
							if (resultat > 9) {
								resultat1 = resultat % 10;
								resultat2 = resultat / 10;
								gresultat = gresultat + to_string(resultat1);
								resultat1 = 9;
							}
							else
								gresultat = gresultat + to_string(resultat);
						}
			}
			gresultat=inversant(gresultat, n1);
		}
		return gresultat;
}

GNOMBRE multiplication(GNOMBRE gn1, GNOMBRE gn2) {
	int n1 = gn1.size();
	int n2 = gn2.size();
	GNOMBRE gresultat = "+0";
	GNOMBRE temp; 
	GNOMBRE I = "+0";
	GNOMBRE N = "+1";
	GNOMBRE tempgn2;
	tempgn2 = gn2;
	tempgn2[0] = '+';
	gn2 = tempgn2;
	if (gn2[1] == '0') {
		gresultat = "+0";
	}else
	do {
		temp = somme(gresultat, gn1);						
		gresultat = temp;
		I = somme(I, N);
	} while (I != gn2);
	return gresultat;
}

GNOMBRE div(GNOMBRE gn1, GNOMBRE gn2) {
	int n1 = gn1.size();
	int n2 = gn2.size();
	GNOMBRE gresultat = "+0";
	GNOMBRE temp = gn1;
	GNOMBRE I = "+0";
	GNOMBRE N = "+1";
	GNOMBRE tempgn1;
	tempgn1 = gn1;
	tempgn1[0] = '+';
	gn1 = tempgn1;
	if (gn2[1] == '0') {
		cout << "\nErreur dans la division.";
	}
	else
		if (functionestEgal(gn1, gn2)) {
			gresultat = N;
		}
		else
			if (functionestInferieur(gn1, gn2)) {
				gresultat = I;			
			}
			else
				if (functionestSuperieur(gn1, gn2)) {
					do {
						temp = difference(temp, gn2);
						I = somme(I, N);
						gresultat = I;
					} while (temp[0] == '+');
					gresultat = difference(gresultat, N);
				}
	return gresultat;
}


GNOMBRE resultatOperateursSomme(GNOMBRE gn1, GNOMBRE gn2) {
	GNOMBRE gresultat;
	GNOMBRE temp;
	if ((gn1[0] == '+') && (gn2[0] == '+')) {
		temp=somme(gn1, gn2);
		temp[0] = '+';
		
	}else
		if ((gn1[0] == '+') && (gn2[0] == '-')) {
			temp = difference(gn1, gn2);
			if (temp[0] == '+') {
				temp[0] = '+';
			}else
				if (temp[0] == '-') {
					temp[0] = '-';
				}
		}else
			if ((gn1[0] == '-') && (gn2[0] == '+')) {
				temp=difference(gn1, gn2);
				if (temp[0] == '+') {
					temp[0] = '-';
				}
				else
					if (temp[0] == '-') {
						temp[0] = '+';
					}
				
			}else
				if ((gn1[0] == '-') && (gn2[0] == '-')) {
					temp=somme(gn1, gn2);
					temp[0] = '-';
				}
			gresultat = temp;
	return gresultat;
}

GNOMBRE resultatOperateursDifference(GNOMBRE gn1, GNOMBRE gn2) {
	GNOMBRE gresultat;
	GNOMBRE temp;
	GNOMBRE temp1;
	int j = 0;
	int ntemp;
	if ((gn1[0] == '+') && (gn2[0] == '+')) {
		temp = difference(gn1, gn2);
		//temp[0] = '+';
	}
	else
		if ((gn1[0] == '+') && (gn2[0] == '-')) {
			temp = somme(gn1, gn2);
			if (functionestSuperieur(gn1,gn2)) {
				temp[0] = '+';
			}
		}
		else
			if ((gn1[0] == '-') && (gn2[0] == '+')) {
				temp = somme(gn1, gn2);
				if (functionestInferieur(gn1, gn2)) {
					temp[0] = '-';
				}
			}
			else
				if ((gn1[0] == '-') && (gn2[0] == '-')) {
					temp = difference(gn1, gn2);
					if (temp[0] == '-') {
						temp[0] = '+';
					}
					else
						if (temp[0] == '+') {
							temp[0] = '-';
						}
				}
	//gresultat = temp;
	///*
	temp1 = temp[0];
	ntemp= temp.size();
	for (int i = 1; i <= ntemp; i++) {
		 if ((temp[i] != '0')||(j!=0)) {
			 temp1 = temp1 + temp[i];
			 j++;
		 }
	}
	gresultat = temp1;
	//*/
	return gresultat;
}

GNOMBRE resultatOperateursMultiplication(GNOMBRE gn1, GNOMBRE gn2) {
	GNOMBRE gresultat;
	GNOMBRE temp;
	if ((gn1[0] == '+') && (gn2[0] == '+')) {
		temp = multiplication(gn1, gn2);
	}
	else
		if ((gn1[0] == '+') && (gn2[0] == '-')) {
			temp = multiplication(gn1, gn2);
			temp[0] = '-';
		}
		else
			if ((gn1[0] == '-') && (gn2[0] == '+')) {
				temp = multiplication(gn1, gn2);
				temp[0] = '-';
			}
			else
				if ((gn1[0] == '-') && (gn2[0] == '-')) {
					temp = multiplication(gn1, gn2);
					temp[0] = '+';
				}
	gresultat = temp;
	return gresultat;
}

GNOMBRE resultatOperateursDivision(GNOMBRE gn1, GNOMBRE gn2) {
	GNOMBRE gresultat;
	GNOMBRE temp;
	if ((gn1[0] == '+') && (gn2[0] == '+')) {
		temp = div(gn1, gn2);
	}
	else
		if ((gn1[0] == '+') && (gn2[0] == '-')) {
			temp = div(gn1, gn2);
			if (temp[1] != '0') {
				temp[0] = '-';
			}
			else {
				temp[0] = '+';
			}
		}
		else
			if ((gn1[0] == '-') && (gn2[0] == '+')) {
				temp = div(gn1, gn2);
				if (temp[1] != '0') {
					temp[0] = '-';
				}
				else {
					temp[0] = '+';
				}
			}
			else
				if ((gn1[0] == '-') && (gn2[0] == '-')) {
					temp = div(gn1, gn2);
					temp[0] = '+';
				}
	gresultat = temp;
	return gresultat;
}

GNOMBRE minimumDeDeuxNombres(GNOMBRE gn1, GNOMBRE gn2) {
	GNOMBRE gresultat;
	if (functionestEgal(gn1, gn2)) {
		gresultat = "les nombres sont egaux";
	}else
		if (functionestInferieur(gn1, gn2)) {
			gresultat = gn1;
		}
		else {
			gresultat = gn2;
		}
	return gresultat;
}

void leTriparInsertion() {
	int const N = 10;
	int t[N] = {};
	int p = 0;
	int j;
	do {
		system("cls");
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n   Programme 2: Le Tri par insertion";
		cout << "\n";
		cout << "\n\t  Donnez 10 nombres";
		cout << "\n";
		for (int i = 0; i <= N - 1; i++) {
			int p = i + 1;
			cout << "\n   Donnez le nombre " << p << " : ";
			cin >> t[i];
		}
		cout << "\n   -------------------------------------------";
		cout << "\n   Tri par insertion:";
		for (int i = 1; i <= (N - 1); i++) {
			int element = t[i];
			j = i - 1;
			while ((j >= 0) && (t[j] > element)) {
				t[j + 1] = t[j];
				j = j - 1;
			}
			t[j + 1] = element;
		}
		for (int i = 0; i < N; i++) {
			cout << setw(6) << left <<' '<< t[i];
		}
		cout << "\n";
		cout << "\n   -------------------------------------------" << endl;
		cout << "\n Appuyez sur nimporte quelle touche pour continuer loperation" << endl;
		cout << "\n Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();														//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);

	}while (etat != 'M');
}

void additionDeNombres() {														//Le programme demande à l’utilisateur de donner 2 nombres et affiche sa somme à l’écran
	GNOMBRE gn1, gn2, gresultat;
	do {
		system("cls");															//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n   Addition de 2 nombres";
		saisirGn(gn1);															//Cette fonction prend  un grand nombre et il fait la somme.
		system("cls");
		cout << "\n   Donner le Nombre 1   :"<<gn1;
		saisirGn(gn2);
		system("cls");
		cout << "\n   Donner le Nombre 2   :"<<gn2;
		system("cls");
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n   Addition de 2 nombres";
		cout << "\n   Donner le Nombre 1   :" << gn1;
		cout << "\n   Donner le Nombre 2   :" << gn2;
		cout << "\n   Somme.............   :"<< resultatOperateursSomme(gn1, gn2);// << somme(gn1, gn2);				//La function some 
		cout << "\n";
		cout << "\n   -------------------------------------------" << endl;
		cout << "\n Appuyez sur nimporte quelle touche pour continuer loperation" << endl;
		cout << "\n Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();														//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);													//La fonction toupper permet de capitaliser les lettres escrites sur le clavier.
	} while (etat != 'M');
}

void soustractionDeNombres() {
	GNOMBRE gn1, gn2, gresultat;
	do {
		system("cls");															//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n    Soustraction de  2 nombres";
		saisirGn(gn1);															//Cette fonction prend  un grand nombre et il fait la somme.
		system("cls");
		cout << "\n   Donner le Nombre 1   :" << gn1;
		saisirGn(gn2);
		system("cls");
		cout << "\n   Donner le Nombre 2   :" << gn2;
		system("cls");
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n   Soustraction de 2 nombres";
		cout << "\n   Donner le Nombre 1   :" << gn1;
		cout << "\n   Donner le Nombre 2   :" << gn2;
		cout << "\n   Difference........   :"<< resultatOperateursDifference(gn1,gn2);// << difference(gn1, gn2);			//La function difference
		cout << "\n";
		cout << "\n   -------------------------------------------" << endl;
		cout << "\n Appuyez sur nimporte quelle touche pour continuer loperation" << endl;
		cout << "\n Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();														//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);													//La fonction toupper permet de capitaliser les lettres escrites sur le clavier.
	} while (etat != 'M');
}

void multiplicationDeNombres() {
	GNOMBRE gn1, gn2, gresultat;
	do {
		system("cls");															//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n    Multiplication de  2 nombres";
		saisirGn(gn1);															//Cette fonction prend  un grand nombre et il fait la somme.
		system("cls");
		cout << "\n   Donner le Nombre 1   :" << gn1;
		saisirGn(gn2);
		system("cls");
		cout << "\n   Donner le Nombre 2   :" << gn2;
		system("cls");
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n   Multiplication de 2 nombres";
		cout << "\n   Donner le Nombre 1   :"<<gn1;
		cout << "\n   Donner le Nombre 2   :"<<gn2;
		cout << "\n   Produit...........   :"<< resultatOperateursMultiplication(gn1,gn2);
		cout << "\n";
		cout << "\n   -------------------------------------------" << endl;
		cout << "\n Appuyez sur nimporte quelle touche pour continuer loperation" << endl;
		cout << "\n Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();														//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);													//La fonction toupper permet de capitaliser les lettres escrites sur le clavier.
	} while (etat != 'M');
}

void divisionDeNombres() {
	GNOMBRE gn1, gn2, gresultat;
	do {
		system("cls");															//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n    Division de  2 nombres";
		saisirGn(gn1);															//Cette fonction prend  un grand nombre et il fait la somme.
		system("cls");
		cout << "\n   Donner le Nombre 1   :" << gn1;
		saisirGn(gn2);
		system("cls");
		cout << "\n   Donner le Nombre 2   :" << gn2;
		system("cls");
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n   Quotient de 2 nombres";
		cout << "\n   Donner le Nombre 1   :" << gn1;
		cout << "\n   Donner le Nombre 2   :" << gn2;
		cout << "\n   Quotient..........   :"<< resultatOperateursDivision(gn1, gn2);
		cout << "\n";
		cout << "\n   -------------------------------------------" << endl;
		cout << "\n Appuyez sur nimporte quelle touche pour continuer loperation" << endl;
		cout << "\n Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();														//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);													//La fonction toupper permet de capitaliser les lettres escrites sur le clavier.
	} while (etat != 'M');
}

void minimunDeNombres() {
	GNOMBRE gn1, gn2, gresultat;
	do {
		system("cls");															//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n    Minimun de  2 nombres";
		saisirGn(gn1);															//Cette fonction prend  un grand nombre et il fait la somme.
		system("cls");
		cout << "\n   Donner le Nombre 1   :" << gn1;
		saisirGn(gn2);
		system("cls");
		cout << "\n   Donner le Nombre 2   :" << gn2;
		system("cls");
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n   Minimum de 2 nombres";
		cout << "\n   Donner le Nombre 1   :" << gn1;
		cout << "\n   Donner le Nombre 2   :" << gn2;
		cout << "\n   Minimum...........   :"<< minimumDeDeuxNombres(gn1, gn2);
		cout << "\n";
		cout << "\n   -------------------------------------------" << endl;
		cout << "\n Appuyez sur nimporte quelle touche pour continuer loperation" << endl;
		cout << "\n Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();														//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);
	} while (etat != 'M');
}

void programmeUn() {
	do {
		system("cls");															//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n   Programme 1: Somme Produit Moyenne";
		cout << "\n";
		cout << "\n   Bien vouloir attendre la version d'hivers 2020 du Logiciel" << endl;
		cout << "\n   -------------------------------------------" << endl;
		cout << "\n";
		cout << "\n   Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();														//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);
	} while (etat != 'M');
}

void programmeDeux() {
	leTriparInsertion();														//
}

void programmeTrois() {
	do {
		system("cls");															//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n   Programme 3: Calculatrice";
		cout << "\n";
		cout << "\n   Bien vouloir attendre la version d'hivers 2020 du Logiciel" << endl;
		cout << "\n   -------------------------------------------" << endl;
		cout << "\n";
		cout << "\n   Appuyez sur (M) pour revenir au menu general" << endl;
		etat0 = _getch();														//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);
	} while (etat != 'M');
}

void quiterLogiciel() {															//Procedure utilisee pour Quiter le logiciel.										
	system("cls");																//Cette fonction vous permet de nettoyer l'ecran.
	cout << "\n PROJET 1-GESTION DES GRANDS NOMBRES";
	cout << "\n -------------------------------------------";
	cout << "\n FIN DU PROGRAM";
	cout << "\n Merci davoir utilise le gestionnaire des grands nombres";
	cout << "\n -------------------------------------------";
	cout << "\n Appuyez sur une touche pour finir" << endl << endl;
	etat = _getch();															//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
	etat = E9;																	//A la fin de cette procedure, la variable etat prend la valeur de E9. Cela vous permet de quitter le do-while.
}

void menu1(int option)															//Procedure utilisee pour le menu general.
{																				//Quand on lance le logiciel, le logiciel devrait afficher les menus suivants:
	do {
		system("cls");															//Cette fonction vous permet de nettoyer l'ecran.
		cout << "\n   PROJET 1-GESTION DES GRANDS NOMBRES";
		cout << "\n   -------------------------------------------";
		cout << "\n   MENU GENERAL";
		cout << "\n\t 1) Addition de 2 nombres";
		cout << "\n\t 2) Soustraction de 2 nombres";
		cout << "\n\t 3) Multiplication de 2 nombres";
		cout << "\n\t 4) Division de 2 nombres";
		cout << "\n\t 5) Minimum de 2 nombres";
		cout << "\n\t 6) Programme 1";
		cout << "\n\t 7) Programme 2";
		cout << "\n\t 8) Programme 3";
		cout << "\n\t Q) Quitter le logiciel" << endl;
		cout << "\n   Choix:";
		etat0 = _getch();														//Avec cette fonction, l'utilisateur peut faire des saisies de donnes sans echo a l'ecran.
		etat = toupper(etat0);													//La fonction toupper permet de capitaliser les lettres escrites sur le clavier.
		switch (etat) {															//La variable etat0, stocke le caractere qui permettra de selectionner les options presentees dans le switch.
		case E1:
			additionDeNombres();												//Cette option appelle la procedure 1)	Addition de 2 nombres
			break;
		case E2:
			soustractionDeNombres();											//Cette option appelle la procedure 2)	Soustraction de 2 nombres
			break;
		case E3:
			multiplicationDeNombres();											//Cette option appelle la procedure 3)	Multiplication de 2 nombres
			break;
		case E4:
			divisionDeNombres();												//Cette option appelle la procedure 4)	Division de 2 nombres
			break;
		case E5:
			minimunDeNombres();													//Cette option appelle la procedure 5)	Minimum de 2 nombres
			break;
		case E6:
			programmeUn();														//Cette option appelle la procedure 6)	Programme 1
			break;
		case E7:
			programmeDeux();													//Cette option appelle la procedure 7)	Programme 2
			break;
		case E8:
			programmeTrois();													//Cette option appelle la procedure 8)	Programme 3
			break;
		case E9:
			quiterLogiciel();													//Cette option appelle la procedure quiterLogiciel.		
			break;
		}
	} while (etat != E9);
}

int main()																		//Fonction principale. La fonction principale appelle la procedure du menu general.
{
	menu1(etat);
	return 0;
}
