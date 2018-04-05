#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool EstaLleno(void);//nuevo metodo
  Album(int n);
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados; //nuevo atributo
  int *album;
  int *repetidas;
};

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
    n_sobres_comprados++;
  }
}

Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
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
  int i;
  /*
  for(i=0;i<160;i++){
    A.CompraSobre(5);
    A.Status();
  }
  */
  i=0;
  //while que compra a lo que marca hasta que llene el album
  while(!A.EstaLleno()){
  	A.CompraSobre(5);
  	i+=1;
  }
  int n_sobres_necesarios=i;
  //imprime el numero de sobres necesatrios
  cout<<"El numero de sobres necesarios para llenar el album fue: "<<n_sobres_necesarios<<endl;
}
