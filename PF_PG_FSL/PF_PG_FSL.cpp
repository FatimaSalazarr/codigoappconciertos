#include <iostream>
#include<string>
#include<fstream>

using namespace std;
void menu();
void guardarConciertos();
void cargarConciertos();
void regiscon();
void menulista();
void filtroartista();
void filtrogenero();
void filtrorec();
void todos();
bool validaid(const string& tempid);
void eliminarconid();
void modificarcon();
void menumod();
float verificarnoletras(string numerosfloat);
int checarnoletras(string numerosint);



struct concierto {
	string idcon;
	string nomcon;
	string artis;
	string fecha;
	float horai;
	float condura;
	string gen;
	string lugarcye;
	string locacionrec;
	string descpcon;
	int numsecciones;
	string nomsecc[4];
	int bolxsec[4];
	float precio_bol[4];

}conci[10];

int cch = 0;
string numerosfloat1 = "";
string numerosfloat2 = "";
string numerosfloat3 = "";
string numerosint1 = "";
string numerosint2 = "";
bool registrade = false;
string tempnoms="";

int main()
{
	cargarConciertos();

	int opc = 0;
	string opt = "";
	bool registro = false;
	string ops = "";
	int salir = 0;

	do {
		menu();
		cin >> opt;

		if (isalpha(opt[0])) {
			cout << "No se admiten letras, favor de ingresar una opcion valida\n";
			registro = true;
		}

		while (registro) {
			cout << "favor de ingresar un numero\n";
			cin >> opt;
			registro = false;

			if (isalpha(opt[0])) {
				registro = true;
			}
		}

		opc = stoi(opt);

		switch(opc){
		
		case 1: {//registrar concierto
			int opr = 0;
			do {
				
			 regiscon();
			 cout << "Desea registrar otro concierto? Presione 1 para si, 0 para volver al menu principal: ";
			 cin >> opr;
			} while (opr != 0 && cch < 10);
			
			

		}break;

		case 2: {//modificar concierto
			int oc = 0;

			do {
				modificarcon();
				cout << "Desea modificar otro concierto? Presione 1 para si, 0 para no: ";
				cin >> oc;
			} while (oc != 0);
			
		}break; 

		case 3:{ //eliminar conciertos
			eliminarconid();
		}break;

		case 4: { // filtro lista 
			int opf = 0;
			string fltemp = "";
			bool flrevis = false;


			menulista();
			cin >> fltemp;

			if (isalpha(fltemp[0])) {
				cout << "No se admiten letras, favor de ingresar una opcion valida\n";
				flrevis = true;
			}

			while (flrevis) {
				cout << "favor de ingresar un numero\n";
				cin >> fltemp;
				flrevis = false;

				if (isalpha(fltemp[0])) {
					flrevis = true;
				}
			}

			opf = stoi(fltemp);

			switch (opf) {
			case 1: {
				filtroartista();
			}
			break;
			case 2: {
				filtrogenero();
			}
			break;
			case 3: {
				filtrorec();
			} 
			break;
			case 4: {
				todos();
			} 
			break;
			}

		}break;

		case 5: {//salir
			

			cout << "esta seguro de querer salir? presione 1 para si 0 para no \n";
			cin >> ops;

			if (isalpha(ops[0])) {
				cout << "No se admiten letras, favor de ingresar una opcion valida\n";
				registro = true;
			}

			while (registro) {
				cout << "favor de ingresar un numero\n";
				cin >> ops;
				registro = false;

				if (isalpha(ops[0])) {
					registro = true;
				}
			}

			salir = stoi(ops);

			guardarConciertos();
		}

		
		
		}
	} while (salir != 1);
	return 0;
	 

	//>cin>> \n
}

void menu() {
	system("cls");
	cout << "Menu" << endl;
	cout << "Bienvenido a Camiboletos Master!! Por favor seleccione una opcion:" << endl;
	cout << "1. Registrar concierto" << endl;
	cout << "2. Modificar concierto" << endl;
	cout << "3. Eliminar  concierto" << endl;
	cout << "4. Ver lista de conciertos" << endl;
	cout << "5. Salir" << endl;
}

void regiscon() {

	if (cch >= 10) {
		cout << "Ya se han registrado 10 conciertos. No es posible registrar más.\n";
		return;
	}

	int opr = 0;
	bool registrado = false;
	int i = cch;
	string tempid;
	string tempnoms;
	string numtemp;
	
	int a = 0;
	
	

	system("cls");
	cout << "Ingrese el ID del concierto\n";
	getline(cin >> ws, tempid);
	for (int j = 0; j < cch; j++) {
		if (tempid == conci[j].idcon) {
			registrado = true;
			break;
		}
	}
	while (registrado) {
		cout << "Id ya registrado, favor de ingresar otro.\n";
		getline(cin >> ws, tempid);
		registrado = false;
		for (int j = 0; j < cch; j++) {
			if (tempid == conci[j].idcon) {
				registrado = true;
				break;
			}
		}
	}
	while (!validaid(tempid)) {
		cout << "Ingrese un ID valido (3 numeros, 2 letras y un caracter especial)\n";
		getline(cin >> ws, tempid);
	}
	conci[i].idcon = tempid;

	cout << "Ingrese el nombre del concierto\n";
	getline(cin >> ws, conci[i].nomcon);

	cout << "Ingrese el nombre del artista\n";
	getline(cin >> ws, conci[i].artis);

	cout << "Ingrese la fecha del concierto\n";
	getline(cin >> ws, conci[i].fecha);

	do {
		cout << "Ingrese la hora de inicio del concierto en formato 24 horas\n";
		cin >> numerosfloat1;

		conci[i].horai = verificarnoletras(numerosfloat1);
		
		if (conci[i].horai <= 0 || conci[i].horai >= 24) {
			cout << "ingrese una hora correcta (0.00-24.00)\n";
			
		}
	} while (conci[i].horai <= 0 || conci[i].horai >= 24);
	
	do {
		cout << "Ingrese la duracion del concierto (maximo 24 horas de duración por concierto)\n";
		cin >> numerosfloat2;
			
		conci[i].condura=verificarnoletras(numerosfloat2);
	

		if (conci[i].condura <= 0 || conci[i].condura >= 24) {
			cout << "ingrese una hora correcta (0.00 hasta 24.00)\n";
		}
	

	} while (conci[i].condura <= 0 || conci[i].condura >= 24);
	

	cout << "Ingrese el genero del concierto\n";
	getline(cin >> ws, conci[i].gen);

	cout << "Ingrese el nombre del recinto\n";
	getline(cin >> ws, conci[i].locacionrec);

	cout << "Ingrese la ciudad y estado donde sera el concierto\n";
	getline(cin >> ws, conci[i].lugarcye);

	cout << "Ingrese una descripcion del concierto\n";
	getline(cin >> ws, conci[i].descpcon);
	
	do {
		cout << "Ingrese el numero de secciones que tendra el concierto\n";//validacion numero de secciones mucho ojo cuate
		cin >> numerosint2;

		conci[i].numsecciones= checarnoletras(numerosint2);
		
		if (conci[i].numsecciones < 0 || conci[i].numsecciones > 4) {
			cout << "Lo sentimos solo contamos con un maximo de 4 secciones, favor de ingresar una seccion valida\n";
		}

	} while (conci[i].numsecciones < 0 || conci[i].numsecciones > 4);
	

	for (int j = 0; j < conci[i].numsecciones; j++) {

		

		cout << "Ingrese el nombre de la seccion\n";
		getline(cin >> ws, tempnoms);

		for (int a = 0; a < conci[i].numsecciones; a++) {
			if (tempnoms == conci[i].nomsecc[a]) {
				registrade = true;
				break;
			}
		}
		while (registrade) {
			cout << "Nombre ya registrado, favor de ingresar otro.\n";
			getline(cin >> ws, tempnoms);
			registrade = false;
			for (int a = 0; a < conci[i].numsecciones; a++) {
				if (tempnoms == conci[i].nomsecc[a]) {
					registrade = true;
					break;
				}
			}
		}
		conci[i].nomsecc[j] = tempnoms;

		do {
			cout << "Ingrese cuantos boletos tendra la seccion\n";
			cin >> numerosint1;
			conci[i].bolxsec[j]= checarnoletras(numerosint1);

			if (conci[i].bolxsec[j] < 0) {
				cout << "Ingrese una cantidad de boletos valida\n";
			}

		} while (conci[i].bolxsec[j] < 0);
		

		do {
			cout << "Ingrese el costo de cada boleto por seccion\n";
			cin >> numerosfloat3;

			conci[i].precio_bol[j]= verificarnoletras(numerosfloat3);

			if (conci[i].precio_bol[j] < 0) {
				cout << "Ingrese una cantidad de boletos valida\n";
			}

		} while (conci[i].precio_bol[j] < 0);

		
	}
	cch++;

}

void guardarConciertos() {
	ofstream archivo("conciertos.txt");

	if (archivo.is_open()) {
		for (int i = 0; i < cch; ++i) {
			archivo << conci[i].idcon << " " << conci[i].nomcon << " " << conci[i].artis << " "
				<< conci[i].fecha << " " << conci[i].horai << " " << conci[i].condura << " " << conci[i].gen << " "
				<< conci[i].lugarcye << " " << conci[i].locacionrec << " " << conci[i].descpcon << " "
				<< conci[i].numsecciones;

			for (int j = 0; j < conci[i].numsecciones; ++j) {
				archivo << " " << conci[i].nomsecc[j] << " " << conci[i].bolxsec[j] << " " << conci[i].precio_bol[j];
			}

			archivo << endl;
		}

		archivo.close();
	}
	else {
		cout << "Error al abrir el archivo para guardar conciertos." << endl;
	}
}

void cargarConciertos() {
	ifstream archivo("conciertos.txt");

	if (archivo.is_open()) {
		cch = 0;
		while (archivo >> conci[cch].idcon >> conci[cch].nomcon >> conci[cch].artis
			>> conci[cch].fecha >> conci[cch].horai >> conci[cch].condura >> conci[cch].gen
			>> conci[cch].lugarcye >> conci[cch].locacionrec >> conci[cch].descpcon
			>> conci[cch].numsecciones) {

			for (int j = 0; j < conci[cch].numsecciones; ++j) {
				archivo >> conci[cch].nomsecc[j] >> conci[cch].bolxsec[j] >> conci[cch].precio_bol[j];
			}

			++cch;
		}

		archivo.close();
	}
	else {
		cout << "No se pudo abrir el archivo." << endl;
	}
}

void menulista(){
	cout << "Seleccione la informacion que desea ver\n";
	cout << "1. Artista\n";
	cout << "2. Genero\n";
	cout << "3. Nombre del recinto\n";
	cout << "4. Todos\n";
}

void filtroartista() {
	system("cls");

	string art = "";
	bool encontrado = false;
	int pos = 0;
	float prexsec = 0;
	float vt = 0;
	float comision = 0;


	cout << "Ingrese el artista que quiere ver\n";
	getline(cin >> ws, art);

	for (int i = 0; i < cch; i++) { //en vez del 3 poner la variable global de cuantos conciertos hgay

		if (art == conci[i].artis) {
			pos = i;
			encontrado = true;
			
		}
		
		if (encontrado) {


			cout << "ID del concierto:" << endl;

			cout << conci[pos].idcon << endl;

			cout << "Nombre del concierto:" << endl;

			cout << conci[pos].nomcon << endl;

			cout << "Nombre del artista:" << endl;

			cout << conci[pos].artis << endl;

			cout << "fecha del concierto:" << endl;

			cout << conci[pos].fecha << endl;

			cout << "Hora de inicio del concierto:" << endl;

			cout << conci[pos].horai << endl;

			cout << "Duracion del concierto:" << endl;

			cout << conci[pos].condura << endl;

			cout << "Genero del concierto:" << endl;

			cout << conci[pos].gen << endl;

			cout << "Nombre del recinto:" << endl;

			cout << conci[pos].locacionrec << endl;

			cout << "Ciudad y estado del concierto:" << endl;

			cout << conci[pos].lugarcye << endl;

			cout << "Descripcion del concierto:" << endl;

			cout << conci[pos].descpcon << endl;

			for (int j = 0; j < conci[i].numsecciones; j++) {
				cout << "Seccion" << j + 1 << endl;

				cout << conci[pos].nomsecc[j] << endl;

				cout << "la seccion " << j + 1 << "tiene:" << conci[pos].bolxsec[j] << endl;

				comision = conci[pos].precio_bol[j] * 1.20;

				cout << "Y el costo de cada boleto es de:" << comision << endl;

				prexsec = conci[pos].bolxsec[j] * comision;

				vt += prexsec;

			}
			cout << "El total de todos los boletos es de:" << vt << endl;

			system("pause");

		}

		
	}

	if (encontrado == false) {

		cout << "Artista no registrado" << endl;
		system("pause");
	}
}

void filtrogenero() {
	system("cls");

	string gen = "";
	bool encontrado = false;
	int pos = 0;
	float prexsec = 0;
	float comision = 0;
	float vt = 0;


	cout << "Ingrese el genero que quiere buscar\n";
	getline(cin >> ws, gen);

	for (int i = 0; i < cch; i++) { //en vez del 3 poner la variable global de cuantos conciertos hgay

		if (gen == conci[i].gen) {
			pos = i;
			encontrado = true;
		}if (encontrado) {


			cout << "ID del concierto:" << endl;

			cout << conci[pos].idcon << endl;

			cout << "Nombre del concierto:" << endl;

			cout << conci[pos].nomcon << endl;

			cout << "Nombre del artista:" << endl;

			cout << conci[pos].artis << endl;

			cout << "fecha del concierto:" << endl;

			cout << conci[pos].fecha << endl;

			cout << "Hora de inicio del concierto:" << endl;

			cout << conci[pos].horai << endl;

			cout << "Duracion del concierto:" << endl;

			cout << conci[pos].condura << endl;

			cout << "Genero del concierto:" << endl;

			cout << conci[pos].gen << endl;

			cout << "Nombre del recinto:" << endl;

			cout << conci[pos].locacionrec << endl;

			cout << "Ciudad y estado del concierto:" << endl;

			cout << conci[pos].lugarcye << endl;

			cout << "Descripcion del concierto:" << endl;

			cout << conci[pos].descpcon << endl;

			for (int j = 0; j < conci[i].numsecciones; j++) {
				cout << "Seccion" << j + 1 << endl;

				cout << conci[pos].nomsecc[j] << endl;

				cout << "la seccion " << j + 1 << "tiene:" << conci[pos].bolxsec[j] << endl;

				comision = conci[pos].precio_bol[j] * 1.20;

				cout << "Y el costo de cada boleto es de:" << comision << endl;

				prexsec = conci[pos].bolxsec[j] * comision;

				vt = vt + prexsec;

			}
			cout << "El total de todos los boletos es de:" << vt << endl;

			system("pause");

		}
		
	}

	if (encontrado == false) {

		cout << "Genero no registrado" << endl;
		system("pause");
	}

}

void filtrorec() {
	system("cls");

	string recinto = "";
	bool encontrado = false;
	int pos = 0;
	float prexsec = 0;
	float comision = 0;
	float vt = 0;


	cout << "Ingrese el recinto deseado\n";
	getline(cin >> ws, recinto);

	for (int i = 0; i < cch; i++) { //en vez del 3 poner la variable global de cuantos conciertos hgay

		if (recinto == conci[i].locacionrec) {
			pos = i;
			encontrado = true;
		}if (encontrado) {


			cout << "ID del concierto:" << endl;

			cout << conci[pos].idcon << endl;

			cout << "Nombre del concierto:" << endl;

			cout << conci[pos].nomcon << endl;

			cout << "Nombre del artista:" << endl;

			cout << conci[pos].artis << endl;

			cout << "Nombre del fecha del concierto:" << endl;

			cout << conci[pos].fecha << endl;

			cout << "Hora de inicio del concierto:" << endl;

			cout << conci[pos].horai << endl;

			cout << "Duracion del concierto:" << endl;

			cout << conci[pos].condura << endl;

			cout << "Genero del concierto:" << endl;

			cout << conci[pos].gen << endl;

			cout << "Nombre del recinto:" << endl;

			cout << conci[pos].locacionrec << endl;

			cout << "Ciudad y estado del concierto:" << endl;

			cout << conci[pos].lugarcye << endl;

			cout << "Descripcion del concierto:" << endl;

			cout << conci[pos].descpcon << endl;

			for (int j = 0; j < conci[i].numsecciones; j++) {
				cout << "Seccion " << j + 1 << endl;

				cout << conci[pos].nomsecc[j] << endl;

				cout << "la seccion " << j + 1 << "tiene:" << conci[pos].bolxsec[j] << endl;

				comision = conci[pos].precio_bol[j] * 1.20;

				cout << "Y el costo de cada boleto es de:" << comision << endl;

				prexsec = conci[pos].bolxsec[j] * comision;

				vt = vt + prexsec;

			}
			cout << "El total de todos los boletos es de:" << vt << endl;

			system("pause");

		}
		
	}
	if (encontrado == false) {

		cout << "Recinto no registrado" << endl;
		system("pause");
	}
}

void todos() {
	float prexsec = 0;
	float comision = 0;
	float vt = 0;

	for (int i = 0; i < cch; i++) { //en vez del 3 poner la variable global de cuantos conciertos hgay

		cout << "ID del concierto:" << endl;

		cout << conci[i].idcon << endl;

		cout << "Nombre del concierto:" << endl;

		cout << conci[i].nomcon << endl;

		cout << "Nombre del artista:" << endl;

		cout << conci[i].artis << endl;

		cout << "Nombre del fecha del concierto:" << endl;

		cout << conci[i].fecha << endl;

		cout << "Hora de inicio del concierto:" << endl;

		cout << conci[i].horai << endl;

		cout << "Duracion del concierto:" << endl;

		cout << conci[i].condura << endl;

		cout << "Genero del concierto:" << endl;

		cout << conci[i].gen << endl;

		cout << "Nombre del recinto:" << endl;

		cout << conci[i].locacionrec << endl;

		cout << "Ciudad y estado del concierto:" << endl;

		cout << conci[i].lugarcye << endl;

		cout << "Descripcion del concierto:" << endl;

		cout << conci[i].descpcon << endl;

		for (int j = 0; j < conci[i].numsecciones; j++) {
			cout << "Seccion" << j + 1 << endl;

			cout << conci[i].nomsecc[j] << endl;

			cout << "la seccion " << j + 1 << " tiene: " << conci[i].bolxsec[j] << endl;

			comision = conci[i].precio_bol[j] * 1.20;

			cout << " Y el costo de cada boleto es de:" << comision << endl;

			prexsec = conci[i].bolxsec[j] * comision;

			vt = vt + prexsec;

		}
		cout << "la venta total de todos los boletos es de: " << vt << endl;

		system("pause");
	}



}

bool validaid(const string& tempid){//aqui primero se checa el length pues al poner const lo toma como que no se va a realizar ningun cambio entonces asi podemos tomarlo como un arreglo por decirlo asi o como si fueran chars y podemos checar letra por letra q ingreso el usario xd saludos

	if (tempid.length() != 6){
		cout << "El ID ingresado no cumple los requisitos " << endl;
		return false;
	}

	for (int i = 0; i < 3; i++) {
		if (!isdigit(tempid[i])) {
			cout << "los primeros 3 caracteres deben de ser numeros" << endl;
			return false;
		}
	}

	for (int i = 3; i < 5; ++i) {
		if (!isalpha(tempid[i])) {
			cout << "Los siguientes 2 caracteres deben ser letras.\n";
			return false;
		}
	}

	if (!isgraph(tempid[5])) {
		cout << "El ultimo caracter debe ser un caracter especial.\n";
		return false;
	}

		
	return true;
	
}

void eliminarconid() {
	system("cls");
	string ideliminacion = "";
	int posdel = 0;
	bool encontrado = false;
	cout << "Ingrese el ID del concierto que desea eliminar\n";
	cin >> ideliminacion;

	for (int k = 0; k < 10; k++) {
		if (ideliminacion == conci[k].idcon) {

			for (int i = 0; i < 10; i++) {
				conci[i].idcon = conci[i + 1].idcon;
				conci[i].nomcon = conci[i + 1].nomcon;
				conci[i].artis = conci[i + 1].artis;
				conci[i].fecha = conci[i + 1].fecha;
				conci[i].horai = conci[i + 1].horai;
				conci[i].condura = conci[i + 1].condura;
				conci[i].gen = conci[i + 1].gen;
				conci[i].locacionrec = conci[i + 1].locacionrec;
				conci[i].lugarcye = conci[i + 1].lugarcye;
				conci[i].descpcon = conci[i + 1].descpcon;
				conci[i].numsecciones = conci[i + 1].numsecciones;

				for (int j = 0; j < 4; j++) {
					conci[i].nomsecc[j] = conci[i + 1].nomsecc[j + 1];
					conci[i].bolxsec[j] = conci[i + 1].bolxsec[j + 1];
					conci[i].precio_bol[j] = conci[i + 1].precio_bol[j + 1];
				}
			}
			encontrado = true;
			cch--;

			conci[cch].idcon = "";
			conci[cch].nomcon = "";
			conci[cch].artis = "";
			conci[cch].fecha = "";
			conci[cch].horai = 0;
			conci[cch].condura = 0;
			conci[cch].gen = "";
			conci[cch].locacionrec = "";
			conci[cch].lugarcye = "";
			conci[cch].descpcon = "";
			conci[cch].numsecciones = 0;

			for (int j = 0; j < 4; j++) {

				conci[cch].nomsecc[j] = "";

				conci[cch].bolxsec[j] = 0;

				conci[cch].precio_bol[j] = 0;

			}
	
		}
	}

	if (!encontrado) {
		cout << "Concierto no encontrado. Presione cualquier tecla para volver al menu" << endl;
		system("pause");
	}
	else {
		cout << "Concierto eliminado con éxito\n";
		system("pause");
	}
	

}

void modificarcon() { //CHECAR QUE SI JALE BN AGREGAR VALIDACIONES
	system("cls");
	string modiid = {};
	int pos = 0;
	int opm = 0;
	bool find = false;
	string opmtemp = "";
	bool menuchec = false;

	cout << "Ingrese el ID del concierto que desea modificar\n";
	cin >> modiid;

	for (int i = 0; i < 10; i++) {
		if (modiid == conci[i].idcon) {
			pos = i;
			find = true;
		}
	}

	if (!find) {
		cout << "Concierto no encontrado. Presione cualquier tecla para volver al menu" << endl;
		system("pause");
		return;
	}

	do {
		system("cls");
		menumod();
		cin >> opmtemp;

		if (isalpha(opmtemp[0])) {
			cout << "No se admiten letras, favor de ingresar una opcion valida\n";
			menuchec = true;
		}

		while (menuchec) {
			cout << "favor de ingresar un numero\n";
			cin >> opmtemp;
			menuchec = false;

			if (isalpha(opmtemp[0])) {
				menuchec = true;
			}
		}

		opm = stoi(opmtemp);

		switch (opm) {

		case 1: { //nombre concierto
			system("cls");
			cout << "Ingrese el nuevo nombre del concierto\n";
			getline(cin >> ws, conci[pos].nomcon);
			cout << "Concierto Modificado con exito\n";
			system("pause");
		}break;
		case 2: {//nombre artista
			system("cls");
			cout << "Ingrese el nuevo nombre del artista\n";
			getline(cin >> ws, conci[pos].artis);
			cout << "Concierto Modificado con exito\n";
			system("pause");
		}break;
		case 3: {
			//fecha del concierto
			system("cls");
			cout << "Ingrese la nueva fecha del concierto\n";
			cin >> conci[pos].fecha;
			cout << "Concierto Modificado con exito\n";
			system("pause");

		}break;
		case 4: {//horai del concierto 
			system("cls");
			do {
				cout << "Ingrese la hora de inicio del concierto en formato 24 horas\n";
				cin >> numerosfloat1;

				conci[pos].horai = verificarnoletras(numerosfloat1);

				if (conci[pos].horai <= 0 || conci[pos].horai >= 24) {
					cout << "ingrese una hora correcta (0.00-24.00)\n";

				}
			} while (conci[pos].horai <= 0 || conci[pos].horai >= 24);
			cout << "Concierto Modificado con exito\n";
			system("pause");
		}break;
		case 5: {//duracion del concierto
			system("cls");
			do {
				cout << "Ingrese la duracion del concierto (maximo 24 horas de duración por concierto)\n";
				cin >> numerosfloat2;

				conci[pos].condura = verificarnoletras(numerosfloat2);


				if (conci[pos].condura <= 0 || conci[pos].condura >= 24) {
					cout << "ingrese una hora correcta (0.00 hasta 24.00)\n";
				}


			} while (conci[pos].condura <= 0 || conci[pos].condura >= 24);
			cout << "Concierto Modificado con exito\n";
			system("pause");
		}break;
		case 6: {//genero
			system("cls");
			cout << "Ingrese el nuevo genero del concierto\n";
			getline(cin >> ws, conci[pos].gen);
			cout << "Concierto Modificado con exito\n";
			system("pause");
		}break;
		case 7: { //nombre recinto
			system("cls");
			cout << "Ingrese el nuevo nombre del recinto\n";
			getline(cin >> ws, conci[pos].locacionrec);
			cout << "Concierto Modificado con exito\n";
			system("pause");
		}break;
		case 8: { //ciudad y estado
			system("cls");
			cout << "Ingrese la ciudad y estado\n";
			getline(cin >> ws, conci[pos].lugarcye);
			cout << "Concierto Modificado con exito\n";
			system("pause");
		}break;
		case 9: { //descrpicion
			system("cls");
			cout << "Ingrese la nueva descripcion del concierto\n";
			getline(cin >> ws, conci[pos].descpcon);
			cout << "Concierto Modificado con exito\n";
			system("pause");
		}break;
		case 10: { //num secciones
			system("cls");
			do {
				cout << "Ingrese el numero de secciones que tendra el concierto\n";//validacion numero de secciones mucho ojo cuate
				cin >> numerosint2;

				conci[pos].numsecciones = checarnoletras(numerosint2);

				if (conci[pos].numsecciones < 0 || conci[pos].numsecciones > 4) {
					cout << "Lo sentimos solo contamos con un maximo de 4 secciones, favor de ingresar una seccion valida\n";
				}

			} while (conci[pos].numsecciones < 0 || conci[pos].numsecciones > 4);
			cout << "Concierto Modificado con exito\n";
			system("pause");
		}break;
		case 11: { //nombre de las secciones
			system("cls");
			
			for (int j = 0; j < conci[pos].numsecciones; j++) {
				cout << "Ingrese el nombre de la seccion" << j+1 << endl;
				getline(cin >> ws, tempnoms);
			  for (int a = 0; a < conci[pos].numsecciones; a++) {
				if (tempnoms == conci[pos].nomsecc[a]) {
					registrade = true;
					break;
				}
			  }

			  while (registrade) {
				cout << "Nombre ya registrado, favor de ingresar otro.\n";
				getline(cin >> ws, tempnoms);
				registrade = false;
				for (int a = 0; a < conci[pos].numsecciones; a++) {
					if (tempnoms == conci[pos].nomsecc[a]) {
						registrade = true;
						break;
					}
				}
			  }
			  conci[pos].nomsecc[j] = tempnoms;
			}
				cout << "Concierto Modificado con exito\n";
				system("pause");
			
		}break;
		case 12: {//bol x secc
			system("cls");
			for (int j = 0; j < conci[pos].numsecciones; j++) {

				do {
					cout << "Ingrese cuantos boletos tendra la seccion" << j + 1 << endl;
					cin >> numerosint1;
					conci[pos].bolxsec[j] = checarnoletras(numerosint1);

					if (conci[pos].bolxsec[j] < 0) {
						cout << "Ingrese una cantidad de boletos valida\n";
					}

				} while (conci[pos].bolxsec[j] < 0);

				cout << "Concierto Modificado con exito\n";
				system("pause");
			}
		}break;
		case 13: { //costo de cada bol
			system("cls");
			for (int j = 0; j < conci[pos].numsecciones; j++) {
				do {
					cout << "Ingrese el costo de cada boleto para la seccion" << j+1 << endl;
					cin >> numerosfloat3;

					conci[pos].precio_bol[j] = verificarnoletras(numerosfloat3);

					if (conci[pos].precio_bol[j] < 0) {
						cout << "Ingrese una cantidad de boletos valida\n";
					}

				} while (conci[pos].precio_bol[j] < 0);
				cout << "Concierto Modificado con exito\n";
				system("pause");
			}break;
		}break;
		case 14: { //todos
			
			system("cls");
			cout << "Ingrese el nombre del concierto\n";
			getline(cin >> ws, conci[pos].nomcon);

			cout << "Ingrese el nombre del artista\n";
			getline(cin >> ws, conci[pos].artis);

			cout << "Ingrese la fecha del concierto\n";
			getline(cin >> ws, conci[pos].fecha);

			do {
				cout << "Ingrese la hora de inicio del concierto en formato 24 horas\n";
				cin >> numerosfloat1;

				conci[pos].horai = verificarnoletras(numerosfloat1);

				if (conci[pos].horai <= 0 || conci[pos].horai >= 24) {
					cout << "ingrese una hora correcta (0.00-24.00)\n";

				}
			} while (conci[pos].horai <= 0 || conci[pos].horai >= 24);

			do {
				cout << "Ingrese la duracion del concierto (maximo 24 horas de duración por concierto)\n";
				cin >> numerosfloat2;

				conci[pos].condura = verificarnoletras(numerosfloat2);


				if (conci[pos].condura <= 0 || conci[pos].condura >= 24) {
					cout << "ingrese una hora correcta (0.00 hasta 24.00)\n";
				}


			} while (conci[pos].condura <= 0 || conci[pos].condura >= 24);


			cout << "Ingrese el genero del concierto\n";
			getline(cin >> ws, conci[pos].gen);

			cout << "Ingrese el nombre del recinto\n";
			getline(cin >> ws, conci[pos].locacionrec);

			cout << "Ingrese la ciudad y estado donde sera el concierto\n";
			getline(cin >> ws, conci[pos].lugarcye);

			cout << "Ingrese una descripcion del concierto\n";
			getline(cin >> ws, conci[pos].descpcon);

			do {
				cout << "Ingrese el numero de secciones que tendra el concierto\n";//validacion numero de secciones mucho ojo cuate
				cin >> numerosint2;

				conci[pos].numsecciones = checarnoletras(numerosint2);

				if (conci[pos].numsecciones < 0 || conci[pos].numsecciones > 4) {
					cout << "Lo sentimos solo contamos con un maximo de 4 secciones, favor de ingresar una seccion valida\n";
				}

			} while (conci[pos].numsecciones < 0 || conci[pos].numsecciones > 4);


			for (int j = 0; j < conci[pos].numsecciones; j++) {



				cout << "Ingrese el nombre de la seccion\n";
				getline(cin >> ws, tempnoms);

				for (int a = 0; a < conci[pos].numsecciones; a++) {
					if (tempnoms == conci[pos].nomsecc[a]) {
						registrade = true;
						break;
					}
				}
				while (registrade) {
					cout << "Nombre ya registrado, favor de ingresar otro.\n";
					getline(cin >> ws, tempnoms);
					registrade = false;
					for (int a = 0; a < conci[pos].numsecciones; a++) {
						if (tempnoms == conci[pos].nomsecc[a]) {
							registrade = true;
							break;
						}
					}
				}
				conci[pos].nomsecc[j] = tempnoms;

				do {
					cout << "Ingrese cuantos boletos tendra la seccion\n";
					cin >> numerosint1;
					conci[pos].bolxsec[j] = checarnoletras(numerosint1);

					if (conci[pos].bolxsec[j] < 0) {
						cout << "Ingrese una cantidad de boletos valida\n";
					}

				} while (conci[pos].bolxsec[j] < 0);


				do {
					cout << "Ingrese el costo de cada boleto por seccion\n";
					cin >> numerosfloat3;

					conci[pos].precio_bol[j] = verificarnoletras(numerosfloat3);

					if (conci[pos].precio_bol[j] < 0) {
						cout << "Ingrese una cantidad de boletos valida\n";
					}

				} while (conci[pos].precio_bol[j] < 0);


			}

			cout << "Concierto Modificado con exito\n";
			system("pause");
			
		}break;

		case 15: {
			break; //salir del bucle
		}
		 

		default: {
			cout << "Ingrese una opcion valida\n";
		    }
		}
		
		
	}while (opm !=15);




} //checar//agregar validaciones y las preguntas de seguir modificando  //validaciones y preguntas de seguir modificando

void menumod() {
	cout << "¿Que desea modificar de el concierto seleccionado?\n";
	cout << "1. Nombre del concierto\n";
	cout << "2. Nombre del artista\n";
	cout << "3. Fecha del concierto\n";
	cout << "4. Hora de inicio del concierto\n";
	cout << "5. Duracion\n";
	cout << "6. Genero\n";
	cout << "7. Nombre del recinto\n";
	cout << "8. La ciudad y estado\n";
	cout << "9. Descripcion del concierto\n";
	cout << "10. Numero de secciones\n";
	cout << "11. Nombre de las secciones\n";
	cout << "12. Boletos por seccion\n";
	cout << "13. Costo de los boletos\n";
	cout << "14. Todo\n";
	cout << "15. Nada volver al menu\n";

	
}

float verificarnoletras(string numerosfloat) {
	bool letras = false;
	float datotempv = 0;

	if (isalpha(numerosfloat[0])){
		cout << "No se permiten letras\n";
		letras = true;
	}
	while (letras) {
		cout << "Favor de ingresar un dato numerico\n";
		cin >> numerosfloat;
		letras = false;

		if (isalpha(numerosfloat[0])) {
			
			letras = true;
		}
	}

	datotempv = stof(numerosfloat);

	return datotempv;
}


int checarnoletras(string numerosint) {
	bool letters = false;
	int intretorno = 0;

	if (isalpha(numerosint[0])) {
		cout << "No se permiten letras\n";
		letters = true;
	}
	while (letters) {
		cout << "Favor de ingresar un dato numerico\n";
		cin >> numerosint;
		letters = false;

		if (isalpha(numerosint[0])) {

			letters = true;
		}
	}

	intretorno = stof(numerosint);

	return intretorno;
}


