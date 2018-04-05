#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool EstaLleno(void);//nuevo metodo
	int n_sobres_comprados; //nuevo atributo
	int *Album::GetAlbum(void);
	int *Album::GetRepetidas(void);
	int Album::GetNRepetidas(void);
	int Album::GetNEnAlbum(void);
	void Album::Cambiasso(int repetida, int nueva);
  Album(int n);
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int *album;
  int *repetidas;
};
int *Album::GetAlbum(void){
	return album;
}
int *Album::GetRepetidas(void){
	return repetidas;
}
int Album::GetNRepetidas(void){
	return n_repetidas;
}
int Album::GetNEnAlbum(void){
	return n_en_album;
}
void Album::Cambiasso(int repetida, int nueva){
	n_repetidas--;
	n_en_album++;
	album[nueva]=1;
	repetidas[repetida]--;
}

void Album::Status(void){
  cout << n_en_album << " "<<n_repetidas << endl;
}

void Album::CompraSobre(int n_en_sobre){
  int lamina;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
  n_sobres_comprados++;
}

Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
  n_sobres_comprados=0; //inicializo nuevo atributo
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}

bool Album::EstaLleno(void){
	if(n_en_album==n_total){
		return true;
	}else{
		return false;
	}
}

int main(){
  srand(time(0));
  Album A(670);
	Album B(670);
  int i;
  /*
  for(i=0;i<160;i++){
    A.CompraSobre(5);
    A.Status();
  }
  */
  //while que compra a lo que marca hasta que llene el album
  while(!A.EstaLleno()){
  	A.CompraSobre(5);
  	B.CompraSobre(5);
  }
  //imprime el numero de sobres necesatrios
  //cout<<"El numero de sobres necesarios para llenar el album fue: "<<A.n_sobres_comprados<<endl;
}
void cambia(Album A, Album B){
	int i;
	int j;
	int minimo_repetidas=0;
	if(A.GetNRepetidas()<=B.GetNRepetidas()){
		minimo_repetidas=A.GetNRepetidas();
	}else{
		minimo_repetidas=B.GetNRepetidas();
	}
	for(i=0;i<670,i++){
		if(A.GetRepetidas[i]>=1 and B.GetAlbum[i]==0){
			for(j=0;j<670;j++){
				if(B.GetRepetidas[i]>=1 and A.GetAlbum[j]==0){
					A.Cambiasso(i,j);
					B.Cambiasso(j,i);
				}
			}
		}
	}
}
