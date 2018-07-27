#include <iostream>
#include <stdlib.h>

using namespace std;

template <class Tipo>
class Pilha {
		typedef struct tno{
			Tipo num;
			struct tno *prox;
			struct tno *ant; 
		}tno;
		
		tno* inicio;
	public:
		Pilha() {
			inicio = NULL;
		}
		
		void insere(Tipo x){
			tno* aux = (tno *) malloc(sizeof(tno));
			aux -> num = x;
			if(inicio == NULL){
				inicio = aux;
				inicio -> prox = inicio;
				inicio -> ant = inicio;
			} else{
				aux -> ant = inicio -> ant;
				aux -> prox = inicio;
				inicio -> ant -> prox = aux;
				inicio -> ant = aux;
			}
		}
		
		Tipo remove(){
			Tipo ret;
			if(inicio != NULL){
				tno* aux = inicio->ant;
				ret = aux->num;
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
				if(aux == inicio) inicio = NULL;
				free(aux);
			}
			return ret;
		}
		
		int vazio(){
			if(inicio == NULL) return 1;
			else return 0;
		}
		
		friend ostream &operator<<(ostream& output, const Pilha& pilha){
			output << "[";
			if(pilha.inicio != NULL){
				tno* aux = pilha.inicio;
				output << aux -> num;
				aux = aux->prox;
				while(aux != pilha.inicio){
					output << ", " << aux -> num;
					aux = aux->prox;
				}
			}
			return output << "]";
		}
		
};
