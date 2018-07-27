#include <iostream>
#include <stdlib.h>

using namespace std;

template <class Tipo>
class Vetor {
		typedef struct tno{
			Tipo num;
			tno* ant;
			tno* prox;
		}tno;
	
		tno* inicio;
		int size;
	public:
		
		Vetor (){
			inicio = NULL;
		}
		
		void insere(Tipo x){
			if(inicio == NULL){
				size = 1;
				inicio = (tno*)malloc(sizeof(tno));
				inicio -> num = x;
				inicio -> prox = inicio;
				inicio -> ant = inicio;
			}
			else{
				tno* temp = (tno*)malloc(sizeof(tno));
				temp -> num = x;
				tno* aux = inicio;
				
				if(aux -> num < x){
					aux = aux -> prox;
					while( aux-> num < x && aux != inicio) aux = aux -> prox;
				}

				temp -> prox = aux;
				(aux -> ant) -> prox = temp;
				temp -> ant = aux -> ant;
				aux -> ant = temp;
				size++;
				if(temp-> num < inicio-> num) inicio = temp;
			}
		}
		
		tno* busca(Tipo x){
			if(inicio != NULL){
				tno* aux = inicio;
				if(aux -> num == x) return aux;
				else{
					aux = aux -> prox;
					while(aux != inicio){
						if(aux -> num == x) return aux;
						aux = aux -> prox;
					}
					return NULL;
				}
			}else return NULL;
		}
		
		Tipo remove(Tipo x){
			Tipo ret;
			tno* aux = busca(x);
			if(aux != NULL){
				ret = aux->num;
				if(aux == inicio){
					if(aux-> ant == inicio) inicio = NULL;
					else inicio = aux-> prox;
				}
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
				free(aux);
				size--;
			}
			return ret;
		}
		
		Tipo remove_inicio(){
			Tipo ret;
			if(inicio != NULL){
				tno* aux = inicio;
				ret = aux->num;
				if(inicio->prox == inicio) inicio = NULL;
				else{
					aux->ant->prox = aux->prox;
					aux->prox->ant = aux->ant;
					inicio = aux->prox;
				}
				free(aux);
				size --;
			}
			return ret;
		}
		
		Tipo remove_fim(){
			Tipo ret;
			if(inicio != NULL){
				tno* aux = inicio->ant;
				ret = aux->num;
				if(inicio->prox == inicio) inicio = NULL;
				else{
					aux->ant->prox = aux->prox;
					aux->prox->ant = aux->ant;
					inicio = aux->prox;
				}
				free(aux);
				size--;
			}
			return ret;
		}
		
		Tipo& operator[](int i){ 
			tno* aux = inicio;
			if(i < size && i >= 0){
				for(;i > 0;i--) aux = aux->prox;
			}
			return aux->num;
		}
		
		int tamanho(){
			return size;
		}
		
		friend ostream &operator<<( ostream &output, const Vetor &fila ) {
			if(fila.inicio != NULL){
				output << "["<< fila.inicio -> num;
				tno* aux = fila.inicio -> prox;
				while(aux != fila.inicio) {
					output << ", " << aux->num;
					aux = aux-> prox;
				}
				output << "]";
			} else output << "[]";
			return output;
		}
};
