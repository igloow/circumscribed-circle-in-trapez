#include <stdio.h>
#include <math.h>
#include <stdlib.h>	// atoi()


/*

distrubutie cercuri pe inaltimea unui trapez

*/

int cerc_inscris(double unghi, double baza_mica, double baza_mare);

	double unghi;

int main(int argc, char **argv) 
{
	int n;
	int baza_mare;
	int baza_mica;
	int inaltime;

	if (argc < 4) {
		printf("usage: dist b B h \n\
				b = baza mica\n\
				B = baza Mare\n\
				h = h\n\
				, inscrie cerc\n");
		return 1;
	}
		
	n = atoi(argv[1]);
	baza_mica = n;

	n = atoi(argv[2]);
    baza_mare = n;
	
	n = atoi(argv[3]);
	inaltime = n;
	printf("Trapez cu : \n\
			baza mica   = %2d,\n\
			baza Mare  = %2d,\n\
			h  \t  =  %2d\n", baza_mica, baza_mare, inaltime);
	
	//calcul uncghi in radiani
	unghi = (baza_mare - baza_mica) ; 
	unghi /= inaltime ; 
	unghi = atan(unghi); 
	printf("angolo : %2.4f radian, %2.4f grad \n\n" , unghi, unghi*180/M_PI);


	cerc_inscris(unghi, baza_mica, baza_mare);

	return 0;
}

int cerc_inscris(double ango, double baza_mica, double baza_mare)
{
	double ipotenuza, perpendiculara, baza;
	double dife_raze, raza;
	double incre = 0.5;
	double cat_mic;
	int n, sw;

	baza = baza_mare;
	perpendiculara = 0;	
	n = 0;
	sw = 1;
	raza = baza_mare/4;
	dife_raze = 0;
		
	do{
		cat_mic = raza * tan(ango); 		
		ipotenuza = baza - raza - cat_mic;
		
		perpendiculara = ipotenuza * cos(unghi);
		dife_raze = perpendiculara - raza;
		
		if(n++ > 200) {sw = 0; printf("\t\t antente n %d iteratii\n\n\n", n);}
		if(dife_raze < 0.1) sw = 0;
		if(dife_raze > 4  ) incre = 1;
		else if(dife_raze > 1  ) incre = 0.1;
		else if(dife_raze > 0.1) incre = 0.01;
		
		raza += incre;
		// printf(" %d,  raza %2.2f, raza-max=%2.2f, dif %2.2f \n"\
					,n, raza, perpendiculara, dife_raze);
					
	} while (sw != 0);
		
	raza -= incre; // pentru afisare corecta

	// baza noua
	// baza = (nalt * sin(unghi)) + baza_mica;
	
	// printf("ipotenuza %2.2f, perpendiculara %2.2f\n", ipotenuza, perpendiculara);

	printf("Cerc : radius %2.2f, rad-max=%2.2f, med %2.2f \n\n"\
					,raza, perpendiculara, (raza + perpendiculara)/2);
		
		return 0;
}