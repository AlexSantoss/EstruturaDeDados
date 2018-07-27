#include <iostream>

using namespace std;

template <class Tipo>
class Fila {
		typedef struct tno{
			Tipo num;
			tno* prox;
		}tno;
	
		tno* inicio;
		tno* fim;
	public:
		
		Fila (){
			inicio = NULL;
		}
		
		void insere(Tipo x){
			tno* temp = (tno*)malloc(sizeof(tno));
			temp->num = x;
			temp->prox = NULL;
			if(inicio != NULL){
				fim -> prox = temp;
				fim = temp;
			}else{
				fim = temp;
				inicio = temp;
			}
		}
		
		Tipo remove(){
			Tipo ret;
			if(inicio != NULL){
				tno* aux = inicio;
				ret = aux->num;
				inicio = inicio -> prox;
				free(aux);
			}
			return ret;
		}
		
		friend ostream &operator<<( ostream &output, const Fila &fila ) {
			output << "[";
			if(fila.inicio != NULL){
				output << fila.inicio -> num;
				tno* aux = fila.inicio->prox;
				while(aux != NULL){
					output << ", "<< aux -> num;
					aux = aux->prox;
				}
			}
			output << "]";
			return output;
		}
};
