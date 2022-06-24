#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// dichiarazioni di funzioni

void inserisci_materia(int);			                
int scelta_menu_principale(void);
void calcola_media(void);
void materie_con_lode(void);		 
void menu_principale();               
void stampa_su_schermo_materia(void);      // utilizzata per debug 

// variabili globali: sezione di dichiarazione variabili e strutture

int scelta; //scelta per il menu o per i sottomenu: viene inizializzata a -1 prima di ogni utilizzo
int posizione_materia = 0; // variabile per riempire l'array esami_record
int selezione = 0;

char nome[20];
char lode[1];

struct esame{
    int codice; // codice materia
    char materia[20]; // nome materia
    int voto; //voto materia
    char lode [1];  // campo per indicare la lode : valori ammissibili S/N
};

struct esame esami_record[5];
int i;


// Sezine main

void main(void)

{

    // inizializzo la struttura esami_record[]

    for (i=0;i<5;i++ )
    {
        //inizializzo codice
        esami_record[i].codice=0;

        //inizializzo materia
        char stringa_vuota[] = "                    ";
        strcpy(esami_record[i].materia,stringa_vuota);

        //inizializzo voto
        esami_record[i].voto=0;

        //inizializzo campo per la lode
        char lode_vuota[] = " ";
        strcpy(esami_record[i].lode,lode_vuota);
    }

    // Ciclo infinito sempre in attesa di input: esce solo con lópzione 4 che arresta il programma
    while (0==0)
    {
         menu_principale();
    }
   
}

void inserisci_materia(posizione_materia)
{
    int codice = 0;   
    printf("\n inserisci codice materia: ");
    scanf("%d", &codice );
    esami_record[posizione_materia].codice = codice;
    
    printf("\n inserisci materia: ");
    scanf("%20s",nome);
	strcpy(esami_record[posizione_materia].materia,nome);
	
	int voto = -1;   
    do
    {
        printf("\n inserisci voto: ");
        scanf("%d", &voto );
    } while (voto < 18 || voto > 30); // controllo se il voto e' ammissibile
    esami_record[posizione_materia].voto = voto;
     

    if (esami_record[posizione_materia].voto == 30)
    {
        printf("\n inserisci lode (S/N): ");
        scanf("%1s", lode );
        strcpy(esami_record[posizione_materia].lode,lode);
    }
    
}

void stampa_su_schermo_materia()   
{
    for (i=0; i<5; i++)
    {
        printf("\n");
        printf("Posizione materia %d \n", i);
        printf("Codice materia %d \n", esami_record[i].codice);
        printf("Materia %s \n",esami_record[i].materia);
        printf("Voto %d \n", esami_record[i].voto);
        printf("Lode %s \n",esami_record[i].lode);
    }
            printf("\n\n\n");
}



void calcola_media(void)
{
    float media=0;
    int somma=0;
    int voti_inseriti=0;
    for (i=0;i<5;i++)
         {  if (esami_record[i].voto > 0) voti_inseriti=voti_inseriti+1;
            somma = somma + esami_record[i].voto;
         }
    if (voti_inseriti>0)
    {
        media = somma/voti_inseriti;
        printf("La media e' %f \n",media);
        printf("\n\n\n");

    } 
    else 
        {
            printf("La media e' 0 \n");
            printf("\n\n\n");
        }

}

int scelta_menu_principale(void)
{
do
{
printf("MENU PRINCIPALE\n");
printf("#1  - INSERISCI ESAME\n");
printf("#2  - CALCOLA MEDIA\n");
printf("#3  - ELENCO LODI\n");
printf("#4  - USCITA PROGRAMMA\n\n");
printf("DIGITA LA TUA SCELTA\n\n");
scanf("%d", &selezione );
} while ((selezione < 1) || (selezione > 5));
return selezione;
}

void materie_con_lode(void)		 
{
    int i;
    printf("elenco materie con lode : \n");
    for (i=0;i<5;i++)
         {                
            if (strcmp(esami_record[i].lode, "S") ==0 )
                {   
                    printf("%s\n",esami_record[i].materia);
                } 
         }
    printf("\n\n\n");

}

void menu_principale()
{
    scelta=0;
    scelta = scelta_menu_principale();

    printf("\n");


    switch (scelta)
    {
        case 1:
            if (posizione_materia >= 5)
            printf("hai gia'inserito 5 materie\n");
            else     {
                        inserisci_materia(posizione_materia);
                        posizione_materia ++;
            }
            break; 

        case 2:
        calcola_media();
            break;

        case 3:
        materie_con_lode();
            break;

        case 4:
        exit(0); //esce dal programma
            break;
        case 5:
        stampa_su_schermo_materia();
            break;

    }

}
