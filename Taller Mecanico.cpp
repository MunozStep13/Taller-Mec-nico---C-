#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
#include <windows.h>
#include<conio.h>
#include<fstream>

using namespace std;
int usuario,i,j,cont,cont1,cont2,cont3,cont4;
int f,g,h,t,l,p;

struct Reservacion{
	string cedula;
	string nombre;
	string tecnico;
	string placa;
	string servicio;
	string fecha;
	string marca;
	string anio;
	string com;
	string kilo;
	string desc;
	string obv;
	string estado;
	 double total;
}reser[15];

struct Marca{
	string des;
	
}marc[15]; 

struct Tecnico{
	string cedula;
	string nombre;
	string apellido;
	string tele;
	double sueldo;
	double cont;
	string estado;
	int at;
}tecn[15]; 

struct Servicio{
 	string descripcion;
 	double precio;
 	string estado;
}servi[15];

struct Almacenar{
	string cedula;
	string nombre;
	string apellido;
	string correo;
	string fono;
	string estado;
	string placa;
	string color;
	string marca;
	string anio;
	string estado2;
	string comb;	
}cliente[15];

int menu();
void operaciones(int op);
void encabezado(void);
void registro(int op);
void Usuario();
void fun_cliente();
void fun_servicio();
void fun_tecnico();
void fun_vehiculo();
void fun_marca();
void mostrarMarca();
void consulta();
void mostrarcliente();
void mostarservicio();
void mostrartecnico();
void mostrarmarca();
void mostrarvehiculo();
void mostrartecnico1();
void fun_reser();
void menureserv();
void listar(string nom);
void fun_aten();
void fun_anula();
void fun_reporte1();
void fun_reporte2(string nom);
void fun_reporte3();
int menureport();
void respaldocliente();
void respaldoservicio();
void respaldotecnico();
void respaldomarca();
void respaldovehiculo();
void respaldoreporte1();
void respaldoreporte2();

int menurespaldo();
	void recuperarc ();
	void recuperars ();
	void recuperart ();
	void recuperarm ();
	void recuperarv ();
	void recuperarr1 ();
	void recuperarr2 ();

Reservacion *buscar6(string nombre);	
Almacenar *buscar(string ced);
Servicio *buscar1(string des);
Tecnico *buscar2(string ced);
Marca *buscar3(string marc);
Tecnico *buscar4(string ced);
Reservacion *buscar5(string nombre);

int MenuReg();
void reporte(int op1);

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

int main(){
	int op;
	do{
	    system("cls");
		op=menu();
		operaciones(op);
		gotoxy(5,25);cout<<"Desea elegir otra operacion si(1)";
		cin>>op;
		fflush(stdin);
	}while(op==1);
	getch();
	return 0;
}

int menu(){
	int op;
	do{		 
	cout<<"\t MENU PRINCIPAL"<<endl;
	cout<<"\t1. REGISTRO DE DATOS"<<endl;
	cout<<"\t2. CONSULTA DE DATOS"<<endl;
	cout<<"\t3. GESTION DE MANTENIMIENTO VEHICULARES"<<endl;
	cout<<"\t4. REPORTE DEL SISTEMA"<<endl;
	cout<<"\t5. RESPALDO DATOS"<<endl;
	cout<<"\t6. RECUPERACION DATOS"<<endl;
		cout<<" \t ELIJA UNA OPCION: ";
		cin>>op;
		fflush(stdin);
		system("cls");
	}while(op<1 or op>6);
	return op;
}

void Usuario(){
	cout<<"1. Asistente\n";
	cout<<"2. tecnico\n";
	cout<<"3. Gerente\n";
	cout<<"4. Administrador\n";
	cout<<"Que usuario es usted: \t";
	cin>>usuario;
	system("cls");
}

void operaciones(int op){
	int op1=0;
	switch(op){
	case 1:
		op1=MenuReg();
		registro(op1);
		break;
	case 2:
		consulta();
		break;
	case 3:
		 menureserv();
		break;
	case 4:
       menureport();
		break;
	case 5:
		menurespaldo();
		break;
	case 6:
		recuperarc ();
		recuperars ();
		recuperart ();
		recuperarm ();
		recuperarv ();
		recuperarr1 ();
		recuperarr2 ();
		cout<<"Recuperacion de datos exitosa"<<endl;	
		break;
	}
}

int MenuReg(){
	int op1;
	do{	
	cout<<"1. CLIENTES\n";
	cout<<"2. SERVICIOS\n";
	cout<<"3. TECNICOS\n";
	cout<<"4. MARCAS\n";
	cout<<"5. VEHICULOS DE LOS CLIENTES\n";
	cout<<"Elija una opcion a realizar: ";
	cin>>op1;
	system("cls");
}while(op1<1 || op1>5);
}

void registro(int op){
	switch(op){
		case 1:
			do{
			Usuario();
		}while(usuario!=1);
			fun_cliente();
			break;
		case 2:
			do{
			Usuario();
		}while(usuario!=4);
		fflush(stdin);
	    fun_servicio();
			break;
		case 3:
			do{
			Usuario();
		}while(usuario!=4);
		fflush(stdin);
		fun_tecnico();
			break;
			case 4:
			do{
			Usuario();
		}while(usuario!=4);
		fflush(stdin);	
		 fun_marca();
			break;
		case 5:
			do{
			Usuario();
		}while(usuario<1 || usuario>5);
		fflush(stdin);
		fun_vehiculo();
			break;
	}
}

void fun_cliente(){
	Almacenar *di;
	string ced;
	int resp;
	system("cls");
	do{
		fflush(stdin);
		cout<<"Cliente "<<cont+1<<"\n";
		if(cont==0)
		{
		cout<<"Digite numero de cedula:       ";
		getline(cin,cliente[cont].cedula);	
		cout<<"Digite el Nombre del Cliente:    ";
		getline(cin,cliente[cont].nombre);
		cout<<"Digite el Apellido del Cliente:    ";
		getline(cin,cliente[cont].apellido);
		fflush(stdin);
		cout<<"Digite numero de telefono:     ";
		getline(cin,cliente[cont].fono);
		fflush(stdin);
		cout<<"Digite correo elctronico:      ";
		getline(cin,cliente[cont].correo);
		fflush(stdin);
		cliente[cont].estado='A';
			cont=cont+1;
		}else{
		cout<<"Digite numero de cedula: ";
		fflush(stdin);getline(cin,ced);
		di=buscar(ced);
		if(di!=NULL){
			cout<<"Usuario ya registrado "<<endl;
		}else{
		cliente[cont].cedula=ced;
		cout<<"Digite el Nombre del cliente:    ";
		getline(cin,cliente[cont].nombre);
		cout<<"Digite el Apellido del Cliente:    ";
		getline(cin,cliente[cont].apellido);		
		fflush(stdin);
		cout<<"Digite numero de telefono:     ";
		getline(cin,cliente[cont].fono);
		fflush(stdin);
		cout<<"Digite correo elctronico:      ";
		getline(cin,cliente[cont].correo);
		fflush(stdin);
		cliente[cont].estado="1";
			cont=cont+1;
	}
	}
	   	cout<<"Desea ingresar otro cliente: si(1) ";
		cin>>resp;
		system("cls");
	}while(resp==1);
}

Almacenar *buscar(string ced){
	for(int i=0;i<cont;i++){
		if(cliente[i].cedula==ced){
			f=i;
			return cliente;
		}
	}
					return NULL;
		}
		Servicio *buscar1(string des){
	for(int i=0;i<cont1;i++){
		if(servi[i].descripcion==des){
			l=i;
			return servi;
		}
	}
	return NULL;
	}
	
void fun_servicio(){
	Servicio *di;
	string ser;
	int resp;
		do{
			if(cont1==0){			
			cout<<"Ingrese el servicio :";
			getline(cin,servi[cont1].descripcion);
			cout<<"Ingrese el precio: ";
			cin>>servi[cont1].precio;
			servi[cont1].estado="1";
			cont1=cont1+1;
		}else{
			fflush(stdin);
			cout<<"Ingrese el servicio: ";
			getline(cin,ser);
			di=buscar1(ser);
			if(di!=NULL){
				cout<<"Servicio ya registrado\n";
			}else{
				servi[cont1].descripcion=ser;
				cout<<"Ingrese el precio: ";
			cin>>servi[cont1].precio;
			servi[cont1].estado="1";
			cont1=cont1+1;
			}
		}
			cout<<"Desea registrar otro servicio:  si(1)";
			cin>>resp;
		}while(resp==1);	
		}

		Tecnico *buscar2(string ced){
		for(int i=0;i<cont2;i++){
		if(tecn[i].cedula==ced){
			g=i;
			return tecn;
		}
	}
					return NULL;	
		}
		
		Tecnico *buscar4(string ced){
		for(int i=0;i<cont2;i++){
		if(tecn[i].nombre==ced){
			return tecn;
		}
	}
					return NULL;	
		}
		
		void fun_tecnico(){
			Tecnico *di;
			string ced;
			int resp;
			do{
				if(cont2==0){
		cout<<"Digite numero de cedula:       ";
		getline(cin,tecn[cont2].cedula);	
		cout<<"Digite el  Nombre  del Tecnico:    ";
		getline(cin,tecn[cont2].nombre);
		cout<<"Digite el  Apellido del Tecnico:    ";
		getline(cin,tecn[cont2].apellido);
		fflush(stdin);
		cout<<"Digite numero de telefono:     ";
		getline(cin,tecn[cont2].tele);
		fflush(stdin);
		cout<<"Digite el sueldo:      ";
		cin>>tecn[cont2].sueldo;
		fflush(stdin);
		tecn[cont2].estado="1";
			cont2=cont2+1;
				}else{
					fflush(stdin);
				cout<<"Digite numero de cedula:       ";
				getline(cin,ced);
				di=buscar2(ced);
				if(di!=NULL){
					cout<<"Tecnico ya registrado\n";
				}else{
					tecn[cont2].cedula=ced;
						cout<<"Digite el Nombre  del Tecnico:    ";
		getline(cin,tecn[cont2].nombre);
			cout<<"Digite el  Apellido  del Tecnico:    ";
		getline(cin,tecn[cont2].apellido);
		fflush(stdin);
		cout<<"Digite numero de telefono:     ";
		getline(cin,tecn[cont2].tele);
		fflush(stdin);
		cout<<"Digite el sueldo:      ";
		cin>>tecn[cont2].sueldo;
		fflush(stdin);
		tecn[cont2].estado="1";
			cont2=cont2+1;
				}	
				}
			cout<<"Desea registrar otro tecnico:  si(1)";
			cin>>resp;
			}while(resp==1);
		}
		
	Marca *buscar3(string mar){
	for(int i=0;i<cont3;i++){
	
		if(marc[i].des==mar){
			return marc;
		}
	}
					return NULL;
		}
		
	void fun_marca(){
		Marca *di;
		string mar;
		int resp;
		do{
			fflush(stdin);
			if(cont3==0){
				cout<<"Ingrese la Marca: ";
				getline(cin,marc[cont3].des);
				cont3=cont3+1;
			}else{
				cout<<"Ingrese la marca: ";
				getline(cin,mar);
				di=buscar3(mar);
				if(di!=NULL){
					cout<<"La marca ya esta registrada\n";
				}else{
					marc[cont3].des=mar;
					cont3=cont3+1;
				}
			}
			cout<<"Desea registrar otra marca: si(1) ";
			cin>>resp;
		}while(resp==1);
	}	
		
	void fun_vehiculo(){
		Almacenar *di;
		Marca *de;
		string ced;
		string marc;
		int resp;
		do{
			fflush(stdin);
			if(cont3==0){
				cout<<"Ingrese el numero de cedula";
				getline(cin,ced);
				di=buscar(ced);
				if(di==NULL){
					cout<<"Cliente no registrado\n";			
				}else{
					cout<<"Ingrese el numero de placa: ";
					getline(cin,cliente[f].placa);
					cout<<"Ingrese el color del vehiculo: ";
					getline(cin,cliente[f].color);
								mostrarMarca();
					cout<<"escoja una marca: ";
					getline(cin,marc);
					de=buscar3(marc);
					if(de==NULL){
						cout<<"Marca no registrada";
					}else{
						cliente[f].marca=marc;
						cout<<"Ingrese el anio de fabricacion: ";
						getline(cin,cliente[f].anio);
						cout<<"Ingrese el tipo de combustible: ";
						getline(cin,cliente[f].comb);
					}
				}
			}else{
				cout<<"Ingrese el numero de cedula: ";
				getline(cin,ced);
				di=buscar(ced);
				if(cliente[f].marca=="")
				{
					cout<<"Ingrese el numero de placa: ";
					getline(cin,cliente[f].placa);
					cout<<"Ingrese el color del vehiculo: ";
					getline(cin,cliente[f].color);
			mostrarMarca();
					cout<<"\n escoja una marca: ";
					getline(cin,marc);
					de=buscar3(marc);
					if(de==NULL){
						cout<<"Marca no registrada";
					}else{
						cliente[f].marca=marc;
						cout<<"Ingrese el anio de fabricacion: ";
						getline(cin,cliente[f].anio);
						cout<<"Ingrese el tipo de combustible: ";
						getline(cin,cliente[f].comb);
					}
				}else{
					cout<<"Ya fue registrado los datos de este vehiculo\n";
				}
			}
			cout<<"Desea registrar otro vehiculo: si(1) ";
			cin>>resp;
			}while(resp==1);
				}
				
			void mostrarMarca(){
				cout<<"Lista de marcas de vehiculos: \n";
				for(int i=0;i<cont3;i++){	
					cout<<"\n"<<marc[i].des;
				}
			}
			
void consulta(){
int op;
do{
	cout<<"MENU DE CONSULTA DE DATOS \n";
	cout<<"1. CLIENTES\n";
	cout<<"2. SERVICIOS\n";
	cout<<"3. TECNICOS\n";
	cout<<"4. MARCAS\n";
	cout<<"5. VEHICULOS\n";
	cout<<"Escoja una opcion: ";
	cin>>op;
}while(op<1 || op>5);
switch(op){
	case 1:
	system("cls");
	mostrarcliente();
	break;
case 2:
	system("cls");
 mostarservicio();
		break;
		case 3:
			do{
			Usuario();
		}while(usuario!=1);
				system("cls");	
			 mostrartecnico();
			break;
			case 4:
				system("cls");
				 mostrarmarca();
			break;
			case 5:
				system("cls");
				mostrarvehiculo();
				break;
}
}		
			
void mostrarcliente(){
		int x=11;
		cout<<"ClIENTES REGISTRADOS\n";
		gotoxy(5,10);cout<<"CEDULA";
		gotoxy(16,10);cout<<"NOMBRES ";
		gotoxy(46,10);cout<<"APELLIDOS ";
		gotoxy(66,10);cout<<"TELEFONO"; 
		gotoxy(96,10);cout<<"EMAIL";
		for(int i=0;i<cont;i++){
		gotoxy(5,x);cout<<cliente[i].cedula;
		gotoxy(16,x);cout<<cliente[i].nombre;
		gotoxy(46,x);cout<<cliente[i].apellido;
		gotoxy(66,x);cout<<cliente[i].fono;
		gotoxy(96,x);cout<<cliente[i].correo;
		x=x+1;
		}
}

void mostrarvehiculo(){
	int x=11;
		cout<<"VEHICULOS REGISTRADOS\n";
		gotoxy(2,10);cout<<"PLACA";
		gotoxy(12,10);cout<<"COLOR";
		gotoxy(25,10);cout<<"MARCA ";
		gotoxy(40,10);cout<<"ANIO DE FABRICACION"; 
		gotoxy(62,10);cout<<"TIPO DE COMBUSTIBLE";
		gotoxy(90,10);cout<<"PROPIETARIO";
		for(int i=0;i<cont;i++){
			if(cliente[i].placa!="")
			{
		gotoxy(2,x);cout<<cliente[i].placa;
		gotoxy(12,x);cout<<cliente[i].color;
		gotoxy(25,x);cout<<cliente[i].marca;
		gotoxy(40,x);cout<<cliente[i].anio;
		gotoxy(62,x);cout<<cliente[i].comb;
		gotoxy(90,x);cout<<cliente[i].nombre<<" "<<cliente[i].apellido;
		x=x+1;
		}	
	}
}

void mostarservicio(){
int x=11;
		cout<<"SERVICIOS REGISTRADOS\n";
		gotoxy(5,10);cout<<"SERVICIOS";
		gotoxy(46,10);cout<<"PRECIO";
			for(int i=0;i<cont1;i++){
		gotoxy(5,x);cout<<servi[i].descripcion;
		gotoxy(46,x);cout<<servi[i].precio;
		x=x+1;
		}		
}

void mostrartecnico(){
	int x=11;
		cout<<"TECNICOS REGISTRADOS\n";
		gotoxy(5,10);cout<<"CEDULA";
		gotoxy(16,10);cout<<"NOMBRES ";
		gotoxy(46,10);cout<<"APELLIDOS ";
		gotoxy(66,10);cout<<"TELEFONO"; 
		gotoxy(96,10);cout<<"SUELDO";
		for(int i=0;i<cont2;i++){
		gotoxy(5,x);cout<<tecn[i].cedula;
		gotoxy(16,x);cout<<tecn[i].nombre;
		gotoxy(46,x);cout<<tecn[i].apellido;
		gotoxy(66,x);cout<<tecn[i].tele;
		gotoxy(96,x);cout<<tecn[i].sueldo;
		x=x+1;
}
}

void mostrarmarca(){
		int x=11;
		cout<<"MARCAS REGISTRADAS\n";
		gotoxy(5,10);cout<<"MARCAS";
		for(int i=0;i<cont3;i++){
		gotoxy(5,x);cout<<marc[i].des;
		x=x+1;
		}
}

void mostrartecnico1(){
		int x=16;
		cout<<"LISTADO DE TECNICOS\n";
		gotoxy(5,15);cout<<"TECNICO";
		for(int i=0;i<cont3;i++){
		gotoxy(5,x);cout<<tecn[i].nombre;
		x=x+1;
		}
}

void menureserv(){
	int resp;
	do{
	cout<<"Menu de Reservaciones\n";
	cout<<"1. Realizar una Reservacion\n";
	cout<<"2. Atencion de Mantenimiento\n";
	cout<<"3. Anulacion de Mantemiento \n";
	cout<<"Escoja una opcion: ";
	cin>>resp;
	fflush(stdin);
}while(resp<1 || resp>3);
switch(resp){
	case 1:
	system("cls");
	 fun_reser();
		break;
	case 2:
		do{	
			Usuario();
		}while(usuario!=2);
	system("cls");
	fflush(stdin);
	 fun_aten();
		break;
	case 3:
		do{
			
			Usuario();
		}while(usuario!=1);
	system("cls");
	fflush(stdin);
	 fun_anula();
		break;
}	
}

void fun_reser(){
	Almacenar *di;
	Tecnico *de;
	Servicio *se;
	string ced;
	string tecn;
	string ser;
	int resp;
	do{
		fflush(stdin);
		cout<<"RESERVACION DE MANTENIMIENTO\n";
		cout<<"Ingrese el numero de cedula del cliente: ";
		getline(cin,ced);
		di=buscar(ced);
		if(di==NULL){
			cout<<"cliente no registrado\n";
		}else{
			reser[cont4].cedula=ced;
			reser[cont4].placa=di[f].placa;
			reser[cont4].marca=di[f].marca;
			reser[cont4].com=di[f].comb;
			reser[cont4].anio=di[f].anio;
			reser[cont4].nombre=di[f].nombre+di[f].apellido;
		    mostarservicio();
		    cout<<"\nEscoja un servicio: ";
		    getline(cin,ser);
		    se=buscar1(ser);
		    if(se==NULL){
		    	cout<<"Servicio no registrado\n";
			}else{
				cout<<"\n";
				reser[cont4].servicio=ser;
				reser[cont4].total=se[l].precio;
				 mostrartecnico1();
				cout<<"\nEscoja una opcion: ";
				getline(cin,tecn);
				de=buscar4(tecn);
				if(de==NULL){
					cout<<"Tecnico no encontrado\n";
				}else{
					reser[cont4].tecnico=tecn;
					cout<<"\nIngrese la fecha del mantemiento: ";
					getline(cin,reser[cont4].fecha);
					reser[cont4].estado="1";
					cont4=cont4+1;
				}
			}
		}
		cout<<"Deseas añadir otra reservacion: si(1): ";
		cin>>resp;
	}while(resp==1);	
}

void fun_aten(){
	Tecnico *di;
	Reservacion *de;
	int resp;
	string tecn;
	string nom;
	cout<<"ATENCION DEL MANTENIMIENTO\n";
	cout<<"Ingrese el numero de cedula del tecnico: ";
	getline(cin,tecn);
	di=buscar2(tecn);
	if(di==NULL){
		cout<<"No se encuentra el usuario\n ";
	}else{
		cout<<"Bienvenido: "<<di[g].nombre+di[g].apellido;
		listar(di[g].nombre);
		cout<<"\n escoja un propietario";
		getline(cin,nom);
		de=buscar5(nom);
		if(de==NULL){
			cout<<"No existe esa reservacion\n";
		}else{
			cout<<"Ingrese el kilometraje: ";
			getline(cin,de[h].kilo);
			cout<<"Ingrese la observacion del mantenimiento";
			getline(cin,de[h].desc);
		 di[g].cont=di[g].cont+de[h].total;
		 di[g].at=di[g].at+1;
			de[h].estado="2";
		}
	}	
}

void listar(string nom){
	int x=11;
		cout<<"Rerservaciones \n";
		gotoxy(2,10);cout<<"Placa";
		gotoxy(12,10);cout<<"Marca";
		gotoxy(30,10);cout<<"Anio de fabricacion";
		gotoxy(45,10);cout<<"Tipo de combustible"; 
		gotoxy(66,10);cout<<"Propietario";
		gotoxy(96,10);cout<<"Servicio";
		for(int i=0;i<cont4;i++){
		if(reser[i].tecnico==nom){
		gotoxy(2,x);cout<<reser[i].placa;
		gotoxy(12,x);cout<<reser[i].marca;
		gotoxy(30,x);cout<<reser[i].anio;
		gotoxy(45,x);cout<<reser[i].com;
		gotoxy(66,x);cout<<reser[i].nombre;
		gotoxy(96,x);cout<<reser[i].servicio;
		}
	}				
}

Reservacion *buscar5(string nombre){
		for(int i=0;i<cont3;i++){	
		if(reser[i].nombre==nombre){
			h=i;
			return reser;
		}
	}
					return NULL;
}

Reservacion *buscar6(string nombre){
		for(int i=0;i<cont3;i++){	
		if(reser[i].cedula==nombre){
			p=i;
			return reser;
		}
	}
					return NULL;
}

void fun_anula(){
	Reservacion *di;
	int resp;
	string nom;	
	cout<<"ANULACION DE RESERVACION \n";
	cout<<"Ingrese el numero de cedula del propietario: ";
	getline(cin,nom);
	di=buscar6(nom);
	if(di==NULL){
		cout<<"No existe reservacion \n";
	}else{
		cout<<"Ingrese los motivos de la anulacion: ";
		getline(cin,di[t].obv);
		di[t].estado="3";
	}
}

int menureport(){
		int op2;
	string ced;
	Tecnico *di;
	do{
	cout<<"MENU REPORTE DEL SISTEMA\n";
	cout<<"1.  RESERVACIONES ATENDIDAS \n";
	cout<<"2.  VEHICULO ATENDIDOS \n";
	cout<<"3.  TOTAL POR TECNICO \n";
	cout<<"Elija una opcion a realizar: ";
	cin>>op2;
	system("cls");
}while(op2<1 || op2>3);
   switch(op2){
		case 1:			
			cout<<"Reporte de reservaciones atendidas";
			gotoxy(5,10);cout<<"Propietario";
			gotoxy(17,10);cout<<"Placa";
			gotoxy(43,10);cout<<"Servicio";
			gotoxy(63,10);cout<<"Tecnico";
			gotoxy(93,10);cout<<"Fecha";
			gotoxy(105,10);cout<<"Estado";
			 fun_reporte1 ();
			break;
		case 2:
			fflush(stdin);
			cout<<"Ingrese el numero de cedula del tecnico: ";
			getline(cin,ced);
			di=buscar2(ced);
			if(di==NULL){
				cout<<"Tecnico no registrado\n";
			}else{
			cout<<"Tecnico: "<<di[g].nombre<<" "<<di[g].apellido<<"\n";
			cout<<"Atendidos";
			gotoxy(5,10);cout<<"Propietarios";
			gotoxy(17,10);cout<<"Placa";
			gotoxy(43,10);cout<<"Servicio";
			gotoxy(63,10);cout<<"Observacion";
			gotoxy(93,10);cout<<"Fecha";
			gotoxy(105,10);cout<<"Estado";
			 fun_reporte2 (di[g].nombre);
		}
			break;
		case 3:
		fun_reporte3();
			break;
	} 
}

void fun_reporte1(){
	string est;
	int x=11;
	for(int i=0;i<cont4;i++){
		if(reser[i].estado=="2"){
		gotoxy(5,x);cout<<reser[i].nombre;
		gotoxy(17,x);cout<<reser[i].placa;
		gotoxy(43,x);cout<<reser[i].servicio;
		gotoxy(63,x);cout<<reser[i].tecnico;
		gotoxy(93,x);cout<<reser[i].fecha;
		gotoxy(99,x);cout<<reser[i].estado;
		x=x+1;	
		}
	}
}

void fun_reporte2(string nom){
	string est;
	est="2";
	int x=11;
	for(int i=0;i<cont4;i++){
		if(reser[i].estado=="2" && reser[i].tecnico==nom ){
		gotoxy(5,x);cout<<reser[i].nombre;
		gotoxy(17,x);cout<<reser[i].placa;
		gotoxy(43,x);cout<<reser[i].servicio;
		gotoxy(63,x);cout<<reser[i].desc;
		gotoxy(93,x);cout<<reser[i].fecha;
		gotoxy(110,x);cout<<reser[i].estado;
		x=x+1;		
		}
	}
}

void fun_reporte3(){
	string est;
	Tecnico *di;
	double pre;
	double pre1;
	double total1;
	double total2;
	int x=11;
	string ced;
	fflush(stdin);
	cout<<"Ingrese el numero de cedula del tecnico: ";
	getline(cin,ced);
	di=buscar2(ced);
	if(di==NULL){
		cout<<"Tecnico no regitrado\n";
	}else{
		pre=(di[g].cont)*0.75;
		total1=(di[g].cont)-pre;
		pre1=(di[g].cont)*0.25;
		total2=(di[g].cont)-pre1;
		cout<<"Tecnico: "<<di[g].nombre<<" "<<di[g].apellido<<"\n";
		cout<<"Mantenimientos atendidos: "<<di[g].at<<"\n";
		cout<<"Honorarios  (75%) : "<<total1<<"\n";
		cout<<"Taller (25%): "<<total2<<"\n";
	}
}

int menurespaldo(){
		int op1;
		do{		
	cout<<"MENU PRINCIPAL\n";
	cout<<"1. RESPALDO DE CLIENTE\n";
	cout<<"2. RESPALDO DE SERVICIOS\n";
	cout<<"3. RESPALDO DE VEHICULOS\n";
	cout<<"4. RESPALDO DE MARCAS\n";
	cout<<"5. RESPALDO DE TECNICOS\n";
	cout<<"6. RESPALDO DE RESERVACIONES DE MANTENIMIENTO\n";
	cout<<"7. RESPALDO DE ANULACION DE MANTENIMIENTOS\n";
    cout<<"Elija una opcion a realizar: ";
	cin>>op1;
	system("cls");
}while(op1<1 || op1>7);
	switch(op1){
		case 1:
		respaldocliente();	
		break;
		case 2:
        respaldoservicio();
		break;
		case 3:
		respaldotecnico();
		break;
		case 4:
		respaldomarca();	
		break;
		case 5:
		respaldovehiculo();
		break;
		case 6:
		respaldoreporte1();
		break;
		case 7:
		respaldoreporte2();
		break;
	}
}

void respaldocliente(){
	FILE *fichero;
		ofstream ficheroE("cliente.txt");	
		for(int i=0;i<cont;i++){
		ficheroE<<cliente[i].cedula<<"\t\t"<<cliente[i].nombre<<"\t\t"<<cliente[i].apellido<<"\t\t\t\t"<<cliente[i].fono<<"\t\t\t"<<cliente[i].correo<<"\t\t\t\t"<<cliente[i].estado<<"\n";
		}
		ficheroE.close();
		cout<<"Datos respaldado"<<endl;
}

void respaldoservicio(){
	FILE *fichero;
		ofstream ficheroE("servicio.txt");	
		for(int i=0;i<cont1;i++){
		ficheroE<<servi[i].descripcion<<"\t\t"<<servi[i].precio<<"\t\t\t"<<servi[i].estado<<"\n";
		}
		ficheroE.close();
		cout<<"Datos respaldado"<<endl;
}

void respaldotecnico(){
	FILE *fichero;		
		ofstream ficheroE("tecnico.txt");	
		for(int i=0;i<cont2;i++){
		ficheroE<<tecn[i].cedula<<"\t\t"<<tecn[i].nombre<<"\t\t"<<tecn[i].apellido<<"\t\t\t\t"<<tecn[i].sueldo<<"\t\t\t\t"<<tecn[i].tele<<"\t\t\t"<<tecn[i].estado<<"\n";
		}
		ficheroE.close();
		cout<<"Datos respaldado"<<endl;
}

void respaldomarca(){
	FILE *fichero;
		ofstream ficheroE("marca.txt");	
		for(int i=0;i<cont3;i++){
		ficheroE<<marc[i].des<<"\n";
		}
		ficheroE.close();
		cout<<"Datos respaldado"<<endl;
}

void respaldovehiculo(){
	FILE *fichero;
		ofstream ficheroE("vehiculo.txt");	
		for(int i=0;i<cont;i++){
		ficheroE<<cliente[i].placa<<"\t\t"<<cliente[i].marca<<"\t\t"<<cliente[i].color<<"\t\t\t\t"<<cliente[i].anio<<"\t\t\t"<<cliente[i].comb<<"\t\t\t\t"<<cliente[i].nombre<<"\t\t"<<cliente[i].apellido<<"\n";
		}
		ficheroE.close();
		cout<<"Datos respaldado"<<endl;
}

void respaldoreporte1(){
	FILE *fichero;
		ofstream ficheroE("reporte1.txt");	
		for(int i=0;i<cont4;i++){
			if(reser[i].estado=="1"){
		ficheroE<<reser[i].nombre<<"\t\t"<<reser[i].placa<<"\t\t"<<reser[i].marca<<"\t\t\t\t"<<reser[i].anio<<"\t\t\t"<<reser[i].com<<"\t\t\t\t"<<reser[i].fecha<<"\t\t"<<reser[i].estado<<"\n";
		}
	}
		ficheroE.close();
		cout<<"Datos respaldado"<<endl;
}

void respaldoreporte2(){
	FILE *fichero;
		ofstream ficheroE("reporte2.txt");	
		for(int i=0;i<cont4;i++){
			if(reser[i].estado=="2"){
		ficheroE<<reser[i].nombre<<"\t\t\t"<<reser[i].placa<<"\t\t\t"<<reser[i].servicio<<"\t\t\t\t"<<reser[i].tecnico<<"\t\t\t"<<reser[i].fecha<<"\t\t\t\t"<<"\t\t"<<reser[i].estado<<"\n";
		}
	}
		ficheroE.close();
		cout<<"Datos respaldado"<<endl;
}

//recuperar datos
void recuperarc (){
	ifstream archivo;
	string texto;
	int i=0;
	archivo.open("cliente.txt",ios::in);
		if(archivo.fail()) //si ha ocurrido un error
	{
		printf("No se pudo abrir el archivo :c\n");
		exit(1);
	}
	while(!archivo.eof()){
		archivo>>cliente[i].cedula;
		archivo >> cliente[i].nombre;
		archivo >> cliente[i].apellido;
		archivo >> cliente[i].fono;
		archivo >> cliente[i].correo;
		archivo >> cliente[i].estado;
		i++;
}
archivo.close();
cont=i-1;
}

void recuperars (){
	ifstream archivo;
	int i=0;
	string texto;
	archivo.open("servicio.txt",ios::in);
		if(archivo.fail()) //si ha ocurrido un error
	{
		printf("No se pudo abrir el archivo :c\n");
		exit(1);
	}
	while(!archivo.eof()){
		archivo >> servi[i].descripcion;
		archivo >> servi[i].precio;
		archivo >> servi[i].estado;
		i++;
}
archivo.close();
}

void recuperart (){
	ifstream archivo;
	int i=0;
	string texto;
	archivo.open("tecnico.txt",ios::in);
		if(archivo.fail()) //si ha ocurrido un error
	{
		printf("No se pudo abrir el archivo :c\n");
		exit(1);
	}
	while(!archivo.eof()){
		archivo >> tecn[i].cedula;
		archivo >> tecn[i].nombre;
		archivo >> tecn[i].apellido;
		archivo >> tecn[i].tele;
		archivo >> tecn[i].sueldo;
		archivo >> tecn[i].estado;
		i++;
}
archivo.close();
cont1=i-1;
}

void recuperarm (){
	ifstream archivo;
	string texto;
	int i=0;
	archivo.open("marca.txt",ios::in);
		if(archivo.fail()) //si ha ocurrido un error
	{
		printf("No se pudo abrir el archivo :c\n");
		exit(1);
	}
	while(!archivo.eof()){
	archivo >> marc[i].des;	
		i++;
}
archivo.close();
cont2=i-1;
}

void recuperarv (){
	ifstream archivo;
	string texto;
	int i=0;
	archivo.open("vehiculo.txt",ios::in);
		if(archivo.fail()) //si ha ocurrido un error
	{
		printf("No se pudo abrir el archivo :c\n");
		exit(1);
	}
	while(!archivo.eof()){
archivo>> cliente[i].marca;
archivo>> cliente[i].color;
archivo>> cliente[i].anio;
archivo>> cliente[i].comb;
i++;
}
archivo.close();
cont =i-1;
}

void recuperarr1 (){
	ifstream archivo;
	string texto;
	archivo.open("reporte1.txt",ios::in);
		if(archivo.fail()) //si ha ocurrido un error
	{
		printf("No se pudo abrir el archivo :c\n");
		exit(1);
	}
	while(!archivo.eof()){
archivo>> reser[i].nombre;
archivo>> reser[i].placa;
archivo>> reser[i].anio;
archivo>> reser[i].com;
archivo>> reser[i].fecha;
archivo>> reser[i].estado;
i++;
}
archivo.close();
cont3=i-1;
}

void recuperarr2 (){
	ifstream archivo;
	string texto;
	int i=0;
	archivo.open("reporte2.txt",ios::in);
		if(archivo.fail()) //si ha ocurrido un error
	{
		printf("No se pudo abrir el archivo :c\n");
		exit(1);
	}
	while(!archivo.eof()){		
archivo>> reser[i].servicio;
archivo>> reser[i].tecnico;
i++;
}
archivo.close();
cont4=i-1;
}

