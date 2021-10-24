#include<stdlib.h>
#include<stdio.h>
#define FREE 0
	int CompareNotePA(int note1,int note2){ 			
			if(note1>note2)
				return 1;
			else
				return 0;
		}

	int main(void){
		int i,j,x,k=0,n,nbre,etu;
		
		printf("Entrez le nombre des etudiant : \n");
		scanf("%d",&n);
		
		int EtuList[n][3];										//List des etudiants avec les choix
		int EtuId[n];											// Id de l'etudiant
		int EtuNotePA[n];										//Sa note Premier année
		int EtuCurrentChoice[n];								//Premier choix de l'etudiant
		
		
		printf("Entrez les places disponible des opt :");
		scanf("%d",&nbre);
			
		int Opt[3][nbre];										
		for (int i = 0; i<3; i++){
			Opt[i][nbre];
		}
		for (int i = 0; i < n; i++) {         
			printf("Entrez les choix %d:",i+1);					//la saisie des choix
			EtuId[i]=i;
		for (int j = 0; j < 3; j++){
            scanf("%d", &EtuList[i][j]);
            
			EtuCurrentChoice[i]=FREE;     
    	}
		}	
		for ( i = 0; i<n; i++){
			printf("Entrez la note PA de l'etudiant %d: ",i+1);	//saisie de la note PA
			scanf("%d", &EtuNotePA[i]);
		}
		k=0;
		
			for ( i = 0; i < 3 ;i++){
				printf("------------\n");
				for ( j = 0; j < nbre;j++,k++){
					Opt[i][j]=EtuId[k];
					EtuCurrentChoice[k]=EtuList[k][0];
					
				}
			}
			k=10;
		while(k>=0){											//Traitement selon le premier et le deuxieme choix, et la note PA
			k--;
			int id1,id2;
			for (i = 0; i < nbre; i++){
				id1=Opt[0][i];
				id2=Opt[1][i];
				x=CompareNotePA(EtuNotePA[id2],EtuNotePA[id1]);
				if(x && (EtuList[id1][0]==EtuList[id2][0]||EtuList[id1][0]==EtuList[id2][1])){
					Opt[0][i]=id2;
					Opt[1][i]=id1;
					EtuCurrentChoice[id1]=2;
					EtuCurrentChoice[id2]=1;
				}
			} 
			for (i = 0; i < nbre; i++){
				id1=Opt[0][i];
				id2=Opt[2][i];
				x=CompareNotePA(EtuNotePA[id2],EtuNotePA[id1]);
				if(x && (EtuList[id1][0]==EtuList[id2][0]||EtuList[id1][0]==EtuList[id2][1])){
					Opt[0][i]=id2;
					Opt[2][i]=id1;
					EtuCurrentChoice[id1]=3;
					EtuCurrentChoice[id2]=1;
				}
			} 
			for (i = 0; i < nbre; i++){
				id1=Opt[1][i];
				id2=Opt[2][i];
				x=CompareNotePA(EtuNotePA[id2],EtuNotePA[id1]);
				if(x && (EtuList[id1][0]==EtuList[id2][0]||EtuList[id1][0]==EtuList[id2][1])){
					Opt[1][i]=id2;
					Opt[2][i]=id1;
					EtuCurrentChoice[id1]=3;
					EtuCurrentChoice[id2]=2;
				}
			} 
		}
		printf("\n La selection finale est : ");							//Resultat 
			for ( i = 0; i<3; i++){
				printf("\n option %d: ",i+1);
				for ( j = 0; j < nbre; j++){
					printf("%d-",Opt[i][j]+1);
				}
			}
	}
	
	
	
	
	
	
