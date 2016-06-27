#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

const int tam = 3;
string gato[tam][tam];
int gana_alguien;

void define(){
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			gato[i][j]=" ";
		}
	}
}
void imprime(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<"\n\t\t\t   A  B  C";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	for(int i=0;i<tam;i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
		cout<<endl<<"\t\t\t"<<i+1<<" ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		for(int j=0;j<tam;j++){
			cout<<"|"<<gato[i][j]<<"|";
		}
	}
}
void insertar(int posL, int posC, string elem){
	gato[posL][posC]=elem;
}
int fila(){
	int contX=0,contO=0;
	for(int j=0;j<tam;j++){
		if(gato[0][j]=="x"){
			contX++;
		}
		if(gato[0][j]=="o"){
			contO++;
		}
	}
	
	if(contX==3){
		return 1;
	}
	else{
		if(contO==3){
			return 0;
		}
		else{
			return -1;
		}
	}
	
}
int fila2(){
	int contX=0,contO=0;
	for(int a=0;a<tam;a++){
		if(gato[2][a]=="x"){
			contX++;
		}
		if(gato[2][a]=="o"){
			contO++;
		}
	}
	if(contX==3){
		return 1;
	}
	else{
		if(contO==3){
			return 0;
		}
		else{
			return -1;
		}
	}
}
int fila3(){
	int contX=0,contO=0;
	for(int o=0;o<tam;o++){
		if(gato[1][o]=="x"){
			contX++;
		}
		if(gato[1][o]=="o"){
			contO++;
		}
	}
	if(contX==3){
		return 1;
	}
	else{
		if(contO==3){
			return 0;
		}
		else{
			return -1;
		}
	}
}





int columna(){
	int contX=0,contO=0;
	for(int i=0;i<tam;i++){
		if(gato[i][0]=="x"){
			contX++;
		}
		if(gato[i][0]=="o"){
			contO++;
		}
	}
	if(contX==3){
		return 1;
	}
	else{
		if(contO==3){
			return 0;
		}
		else{
			return -1;
		}
	}
	
}
int columna1(){
	int contX=0,contO=0;
	for(int i=0;i<tam;i++){
		if(gato[i][1]=="x"){
			contX++;
		}
		if(gato[i][1]=="o"){
			contO++;
		}
	}
	if(contX==3){
		return 1;
	}
	else{
		if(contO==3){
			return 0;
		}
		else{
			return -1;
		}
	}
}
int columna2(){
	int contX=0,contO=0;
	for(int i=0;i<tam;i++){
		if(gato[i][2]=="x"){
			contX++;
		}
		if(gato[i][2]=="o"){
			contO++;
		}
	}
	if(contX==3){
		return 1;
	}
	else{
		if(contO==3){
			return 0;
		}
		else{
			return -1;
		}
	}
}
int filas(){
	int x=fila();
	int y=fila2();
	int z=fila3();
	if(x==1 || y==1 || z==1){
		return 1;
	}
	else{
		if(x==0 || y==0 || z==0){
			return 0;
		}
		else{
			return -1;
		}
	}
	
}
int columnas(){
	int x=columna();
	int y=columna1();
	int z=columna2();
	if(x==1 || y==1 || z==1){
		return 1;
	}
	else{
		if(x==0 || y==0 || z==0){
			return 0;
		}
		else{
			return -1;
		}
	}
	
}
int diagonalA(){
	int contX=0,contO=0;
	for(int i=0;i<tam;i++){
		if(gato[i][i]=="x"){
			contX++;
		}
		if(gato[i][i]=="o"){
			contO++;
		}
	}
	if(contX==3){
		return 1;
	}
	else{
		if(contO==3){
			return 0;
		}
		else{
			return -1;
		}
	}
	
}
int diagonalB(){
	int contX=0,contO=0;
	for(int i=0;i<tam;i++){
		if(gato[i][2-i]=="x"){
			contX++;
		}
		if(gato[i][2-i]=="o"){
			contO++;
		}
	}
	if(contX==3){
		return 1;
	}
	else{
		if(contO==3){
			return 0;
		}
		else{
			return -1;
		}
	}
	
}
int ganador(){
	int linea, Columna, DiagonalA, DiagonalB;
	for(int i=0;i<tam;i++){
		linea=filas();
		Columna=columnas();
		DiagonalA=diagonalA();
		DiagonalB=diagonalB();
		if(linea==1 || Columna==1 || DiagonalA==1 || DiagonalB==1){
			return 1;
		}
		else{
			if(linea==0 || Columna==0 || DiagonalA==0 || DiagonalB==0){
				return 0;
			}
		}
	}
	return -1;
}
int main (int argc, char *argv[]) {
	int posL, pos;
	int intercambio;
	char posC;
	string elem;
	string jugador1,jugador2;
	int contador_del_juego=0;
	int contador_de_jugadores=0;
	string gana;
	int elige;
	int menu=1;
	
	while(menu==1){
		define();
		system("cls");
		cout<<"\t\t";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		cout<<"####  ####  ####  ####"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"\t\t";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		cout<<"#     #  #   ##   #  #"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"\t\t";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		cout<<"# ##  ####   ##   #  #"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"\t\t";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		cout<<"#  #  #  #   ##   #  #"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"\t\t";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		cout<<"####  #  #   ##   ####"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		/*char space=" ";
		char bola="o";
		char equis="x";
		for(int bolita=0;bolita<50;bolita++){
			cout<<space<<bola<<equis;
		}*/
		cout<<"\n===================\n";
		cout<<"\tMenu";
		cout<<"\n===================\n"<<endl;
		cout<<"\t1. Jugar"<<endl;
		cout<<"\t2. Instrucciones"<<endl;
		cout<<"\t3. Salir"<<endl;
		cout<<"\n===================\n"<<endl;
		cin>>elige;
		if(elige==1){
			system("cls");
			cout<<"\n\n\tDigite el nombre del primer jugador > ";
			cin>>jugador1;
			cout<<"\n\n\tDigite el nombre del segundo jugador > ";
			cin>>jugador2;
			system("cls");
			cout<<endl<<jugador1<<" va con 'X'"<<endl;
			cout<<jugador2<<" va con 'O'"<<endl;
			system("PAUSE");
			bool bandera=true;
			while(bandera==true){
				define();
				for(contador_del_juego=0;contador_del_juego<9;contador_del_juego++){
					
					if(contador_de_jugadores%2==0){
						elem="x";
					}
					else{
						elem="o";
					}
					system("cls");
					imprime();
					cout<<"\n\nTurno de: "<<elem<<endl;
					if(contador_de_jugadores%2==0){
					cout<<"\tJugador 1:"<<endl;
					cout<<"\t"<<jugador1<<endl;
					}
					else{
						cout<<"\t\tJugador 2:"<<endl;
						cout<<"\t\t"<<jugador2<<endl;
					}
					cout<<"\n\tDigite:"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
					cout<<"\tFila 1 2 3 > ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
					cin>>intercambio;
					switch(intercambio){
					case 1:
						posL=0;
						break;
					case 2:
						posL=1;
						break;
					case 3:
						posL=2;
						break;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
					cout<<"\tColumna A B C > ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
					cin>>posC;
					if(posC=='A' || posC=='a'){
						pos=0;
					}
					if(posC=='B' || posC=='b'){
						pos=1;
					}
					if(posC=='C' || posC=='c'){
						pos=2;
					}
					insertar(posL, pos, elem);
					
					if(ganador()==1 || ganador()==0){
						break;
					}
					contador_de_jugadores++;
				}
		
				system("cls");
				if(ganador()==1){
					cout<<jugador1<<" ha ganado el juego!"<<endl;
				}
				else{
					if(ganador()==0){
						cout<<jugador2<<" ha ganado el juego!"<<endl;
					}
					else{
						cout<<"No gana nadie"<<endl;
					}
				}
				cout<<jugador1<<" quieres jugar de nuevo con "<<jugador2<<"?"<<endl;
				cout<<"\t1.  Si\n\t0.  No"<<endl;
				cin>>bandera;
			}
		}
		if(elige==2){
			system("cls");
			cout<<"El objetivo del juego es hacer 3 lineas de 'X' u 'O'\nSe le presentara una tabla como esta:" <<endl;
			imprime();
			cout<<"\n\nDebera llenar los espacios en blanco con 'X' u 'O'"<<endl;
			cout<<"En los espacios que elija para ganar"<<endl;
			system("PAUSE");
			system("cls");
			cout<<"\tComo se llenan?"<<endl;
			cout<<"\nSe le presentaran las coordenadas de\nA B C de las columnas y 0 1 2 de las filas"<<endl;
			cout<<"\nDebera llenarlas eligiendo una fila y una columna"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"EXACTAMENTE LO QUE SE LE PIDA"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			system("PAUSE");
			system("cls");
			cout<<"Cuando el jugador haya completado 3 signos iguales en raya"<<endl;
			cout<<"Ya sea en diagonal"<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			cout<<"\t *                * "<<endl;
			cout<<"\t   *            *   "<<endl;
			cout<<"\t     *        *     "<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"\nVertical"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<"\n\t\t*"<<endl;
			cout<<"\t\t*"<<endl;
			cout<<"\t\t*"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"\nU horizontal"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
			cout<<"\n\t  *  *  *"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"\nel jugador habra ganado."<<endl;
			system("PAUSE");
		}
		if(elige==3){
			system("cls");
			return 0;
		}
	}
}

