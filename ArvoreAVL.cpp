#include <iostream>
#include <stdlib.h>

using namespace std;

template <class Tipo>
class ArvoreAVL {
		typedef struct tno{
			Tipo num;
			int fator;
			struct tno *esq;
			struct tno *dir; 
		}tno;
		
		tno* raiz;
		
		public:
		
		ArvoreAVL(){
			raiz = NULL;
		}
		
		tno** busca(Tipo x){
			tno** temp = &raiz;
			while(*temp != NULL){
				if((*temp) -> num > x) temp = &((*temp) -> esq);
				else temp = &((*temp) -> dir);
			}
			return temp;
		}
		
		void insere(Tipo x){
			tno** aux = busca(x);
			*aux = (tno*)malloc(sizeof(tno));
			(*aux)->esq = NULL;
			(*aux)->dir = NULL;
			(*aux)->fator = 0;
			(*aux)->num = x;
		}
		
		void insereR(Tipo x){
			insereRaux(x, &raiz);
		}
		
		int insereRaux(Tipo x, tno** pai){
			int aux = 0;
			int folha = 0;
			if(*pai != NULL){
				aux = (*pai)->fator;
				if((*pai)->num > x){
					folha = insereRaux(x, &((*pai)->esq));
					if(folha) (*pai) -> fator = (*pai) -> fator + 1;
				}
				else{
					folha = insereRaux(x, &((*pai)->dir));
					if(folha) (*pai) -> fator = (*pai) -> fator - 1;
				}
			}
			else{
				*pai = (tno*)malloc(sizeof(tno));
				(*pai)->esq = NULL;
				(*pai)->dir = NULL;
				(*pai)->fator = 0;
				(*pai)->num = x;
				return 1;
			}
			if((aux == 0 && (*pai)->fator!= 0)) return 1;
			else{
				if((*pai)->fator == 2){
					if((*pai)->esq->fator == 1)	rotacionaDir(pai);
					else{
						rotacionaEsq(&(*pai)->esq);
						rotacionaDir(pai);
					}
				}else if ((*pai)->fator == -2){
					if((*pai)->dir->fator == -1) rotacionaEsq(pai);
					else{
						rotacionaDir(&(*pai)->dir);
						rotacionaEsq(pai);
					}
				}
				return 0;
			}
		}
		
		void rotacionaDir(tno** pai){
			tno* pai2 = *pai;
			tno* filho = (*pai)->esq;
			pai2->esq = filho->dir;
			filho->dir = pai2;
			*pai = filho;
			pai2->fator = 0;
			filho->fator = 0;
		}
		
		void rotacionaEsq(tno** pai){
			tno* pai2 = *pai;
			tno* filho = (*pai)->dir;
			pai2->dir = filho->esq;
			filho->esq = pai2;
			*pai = filho;
			pai2->fator = 0;
			filho->fator = 0;
		}
		
		void printaR(){
			printaRaux(raiz, 1);
		}
		
		void printaRaux(tno* no, int tab){
			if(no != NULL){
				cout << "( " << no->num;
				printaRaux(no-> esq, tab+1);	
				printaRaux(no->dir, tab+1);
				cout << " )";
			}else cout << " () ";
		}
};
