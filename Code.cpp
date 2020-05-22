#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <string>
#define ENTER 13
#define borrar 8
#define clear system("cls")
#define pausa system("pause");
#define limpiar clear
#define stoi(aux) atoi(aux.c_str ())
using namespace std;
struct fecha {
    short dia, mes;
    int ano;
};
struct t_gravedad {
    short gravedad;
    bool atencion_imnediata;
};
struct Registro {
    fecha Fecha_de_ataque;
    string nombre, comentario;
    fecha Fecha_de_registro;
    t_gravedad gravedad;
};
bool Es_numero(const string& num) {
    if (num.size() == 0)
        return false;
    for (int i = 0; num[i] != '\0'; i++) {
        if (num[i] < '0' or num[i]>'9')
            return false;
    }
    return true;
}
bool Tiene_solo_letras(const string& validacion) {
    if (validacion.size() == 0)
        return false;
    for (int i = 0; validacion[i] != '\0'; i++) {
        if ((validacion[i] != ' ') and ((validacion[i] < 'A' or validacion[i]>'Z') and (validacion[i] < 'a' or validacion[i]>'z')))
            return false;
    }
    return true;
}
bool Tiene_letras_y_numeros(const string& validacion) {
    if (validacion.size() == 0)
        return false;
    for (int i = 0; validacion[i] != '\0'; i++) {
       if ((validacion[i] != ' ' and validacion[i]!='_') and (validacion[i]<'0' or validacion[i]>'9') and ((validacion[i] < 'A' or validacion[i]>'Z') and (validacion[i] < 'a' or validacion[i]>'z')))
            return false;
    }
    return true;
}
bool Tiene_espacios(const string& prueba) {
    for (int i = 0; i < int(prueba.size()); i++) {
        if (prueba[i] == ' ')
            return true;
    }
    return false;
}
void despedida() {
    limpiar;
    string linea;
    ifstream leer;
    leer.open("despedida.out", ios::in);
    while (!leer.eof()) {
        getline(leer, linea);
        Sleep(500);
        cout << linea << '\n';
        linea = "";
    }
    leer.close();
    exit(1);
}
void imprimir_base(const vector<Registro>& imp) {
    int i, len = imp.size(), j;
    cout << "Nombre                            fecha de ataque         gravedad      Atecion          fecha de registro\n";   
    for (i = 0; i < len; i++) {
        cout << imp[i].nombre;
        for (j = imp[i].nombre.size(); j < 35; j++) {
            cout << ' ';
        }
        cout << imp[i].Fecha_de_ataque.dia << " // " << imp[i].Fecha_de_ataque.mes << " // " << imp[i].Fecha_de_ataque.ano << "            ";
        cout << imp[i].gravedad.gravedad << "        ";
        if (imp[i].gravedad.atencion_imnediata) {
            cout << "Inmediata       ";
        }
        else {
            cout << "Espera         ";
        }
        cout << imp[i].Fecha_de_registro.dia << " // " << imp[i].Fecha_de_registro.mes << " // " << imp[i].Fecha_de_registro.ano;
        cout << '\n';
    }
    pausa;
}
bool ag_otro() {
    string aux;
    cout << "¿Desea agregar otro atque? 1=Si,2=No : "; cin >> aux;
    bool Esnum = Es_numero(aux);
    if (Esnum) {
        (stoi(aux) < 1 or stoi(aux) > 2) ? Esnum = false : true;
    }
    while (!Esnum)
    {
        cout << "Parece que escogiste alguna opcion inexistente o ingresaste caracteres distintos a los solicitados\nPor favor ingreselo otra vez : ";
        cin >> aux;
        Esnum = Es_numero(aux);
        if (Esnum) {
            (stoi(aux) < 1 or stoi(aux) > 2) ? Esnum = false : true;
        }
    }
    if (stoi(aux) == 1) {
        cin.ignore();
        return true;
    }
    cin.ignore();
    return false;
}
string comentario() {
    string aux, coment;
    cout << "Desea añadir un cometario extra 1=SI , 2=NO : ";
    cin >> aux;
    bool Esnum = Es_numero(aux);
    if (Esnum) {
        (stoi(aux) < 1 or stoi(aux) > 2) ? Esnum = false : true;
    }
    while (!Esnum)
    {
        cout << "Parece que escogiste alguna opcion inexistente o ingresaste caracteres distintos a los solicitados\nPor favor ingreselo otra vez : ";
        cin >> aux;
        Esnum = Es_numero(aux);
        if (Esnum) {
            (stoi(aux) < 1 or stoi(aux) > 2) ? Esnum = false : true;
        }
    }
    if (stoi(aux) == 1) {
        cout << "Ingrese un comentario,Este no tiene restricciones : ";
        cin.ignore();
        getline(cin, coment);
    }
    else {
        coment = "Null";
    }
    return coment;
}
t_gravedad pedir_gravedad() {
    t_gravedad temp;
    string aux;
    cout << "Ingrese la gravedad del ataque: "; cin >> aux;
    bool Esnum = Es_numero(aux);
    if (Esnum) {
        if (stoi(aux) < 0 or stoi(aux) > 5)
            Esnum = false;
    }
    while (!Esnum) {
        cout << "La gravedad se mide del 1 al 5,parece que ingrenso un numero fuera del rago o algun caracter\nPor favor ingreselo de nuevo : ";
        cin >> aux;
        Esnum = Es_numero(aux);
        if (Esnum) {
            if (stoi(aux) < 0 or stoi(aux) > 5)
                Esnum = false;
        }
    }
    cout << "Si la gravedad es superior a 3 se tomara en cuenta para una atencion e investigacion de inmediata\n";
    temp.gravedad = stoi(aux);
    if (temp.gravedad > 3) temp.atencion_imnediata = true;
    else temp.atencion_imnediata = false;
    return temp;
}
fecha pedir_fecha() {
    fecha temp;
    string fecha;
    cout << "Ingrese el dia : "; cin >> fecha;
    bool Esnum = Es_numero(fecha);
    if (Esnum) {
        if (stoi(fecha) < 0 or stoi(fecha) > 31) {
            Esnum = false;
        }
    }
    while (!Esnum)
    {
        cout << "Parece que ingresaste algun caracter diferente de un numero o este numero no existe en ningun dia del mes\nPor favor ingresalo de nuevo : ";
        cin >> fecha;
        Esnum = Es_numero(fecha);
        if (Esnum) {
            if (stoi(fecha) < 0 or stoi(fecha) > 31) {
                Esnum = false;
            }
        }
    }
    temp.dia = stoi(fecha);
    cout << "Ingrese el mes : "; cin >> fecha;
    Esnum = Es_numero(fecha);
    if (Esnum) {
        if (stoi(fecha) < 0 or stoi(fecha) > 12) {
            Esnum = false;
        }
    }
    while (!Esnum)
    {
        cout << "Parece que ingresaste algun caracter diferente de un numero o este mes no existe\nPor favor ingresalo de nuevo : ";
        cin >> fecha;
        Esnum = Es_numero(fecha);
        if (Esnum) {
            if (stoi(fecha) < 0 or stoi(fecha) > 12) {
                Esnum = false;
            }
        }
    }
    temp.mes = stoi(fecha);
    cout << "Ingrese el año : "; cin >> fecha;
    Esnum = Es_numero(fecha);
    if (Esnum) {
        if (stoi(fecha) < 1950 or stoi(fecha) > 2020) {
            Esnum = false;
        }
    }
    while (!Esnum)
    {
        cout << "Parece que ingresaste algun caracter diferente de un numero o este año aun es inexistente\nPor favor ingresalo de nuevo : ";
        cin >> fecha;
        Esnum = Es_numero(fecha);
        if (Esnum) {
            if (stoi(fecha) < 1950 or stoi(fecha) > 2020) {
                Esnum = false;
            }
        }
    }
    temp.ano = stoi(fecha);
    return temp;
}
string pedir_nombre() {
    string temp = "";
    cout << "Nombre de la persona y/o Institucion a la que sucedio el ataque: ";
    getline(cin, temp);
    while (!Tiene_solo_letras(temp)) {
        cout << "Upps!, Vaya parece que hubo un error & el ingreso solo permite letras Mayúsculas & minusculas\nTrata de ingresarlo de Nuevo Porfavor: ";
        getline(cin, temp);
    }
    return temp;
}
Registro Pedir_Registro_temp() {
    Registro temp;
    temp.nombre = pedir_nombre();
    cout << "Ingrese la Fecha en la que fue hecho el ataque En Formato DD/MM/AAAA\n";
    temp.Fecha_de_ataque = pedir_fecha();
    temp.gravedad = pedir_gravedad();
    cout << "Ingrese la Fecha de Registro (hoy) En Formato DD/MM/AAAA\n";
    temp.Fecha_de_registro = pedir_fecha();
    temp.comentario = comentario();
    return temp;
}
void agregar_linea_database(const string&nombre,const Registro& temp){
   ofstream Escribir;
   Escribir.open(nombre.c_str(),ios::out | ios::app);
   if(temp.nombre.size()>34){
      for(short i=0; i<34; i++){
         Escribir<<temp.nombre[i];
      }
   }else{
      Escribir<<temp.nombre;
      for(short i=temp.nombre.size();i<34;i++){
         Escribir<<' ';
      }
   }
   (temp.Fecha_de_ataque.dia<9) ? Escribir<<'0'<<temp.Fecha_de_ataque.dia:Escribir<<temp.Fecha_de_ataque.dia;
   Escribir<<" // ";
   (temp.Fecha_de_ataque.mes<9) ? Escribir<<'0'<<temp.Fecha_de_ataque.mes:Escribir<<temp.Fecha_de_ataque.mes;
   Escribir<<" // "<<temp.Fecha_de_ataque.ano<<"            ";
   Escribir << temp.gravedad.gravedad;
   if(temp.gravedad.atencion_imnediata)Escribir<<"        Inmediata           ";
   else Escribir<<"          Espera            ";  
   (temp.Fecha_de_registro.dia<9) ? Escribir<<'0'<<temp.Fecha_de_registro.dia  :Escribir<<temp.Fecha_de_registro.dia  ;
   Escribir<<" // ";
   (temp.Fecha_de_registro.mes<9) ? Escribir<<'0'<<temp.Fecha_de_registro.mes:Escribir<<temp.Fecha_de_registro.mes;
   Escribir<<" // "<<temp.Fecha_de_registro.ano<<'\n';
}
void Crear_base_temp() {
    bool agregar_otro = false;
    vector<Registro> _registro;
    do {
        Registro temp = Pedir_Registro_temp();
        _registro.push_back(temp);
        agregar_otro = ag_otro();
    } while (agregar_otro);
    //int len = _registro.size();
    //Ordenar por gravedad,fecha de ataque,nombre,fecha de registro;
    imprimir_base(_registro);
    //_registro[0].nombre
}
void Editar_una_base_de_datos() {
    cout << "Esta opcion aun no esta disponible :(\n";
    pausa;
}
void Crear_una_base_de_datos_permanente() {
   string nom;
   cout<<"Ingrese el nombre de su Base de Datos a crear : ";
   getline(cin,nom);
   bool nom_tspaces=false;
   if(Tiene_espacios(nom)){
      nom_tspaces=true;
   }else{
      if(Tiene_letras_y_numeros(nom)){
         nom_tspaces=false;
      }else{
         nom_tspaces=true;
      }
   }
   
   while (nom_tspaces)
   {
      cout<<"Parece que el nombre contiene caracteres no admitidos y/o espacios\nIngresalo otra vez : ";
      getline(cin,nom);
      if(Tiene_espacios(nom)){
         nom_tspaces=true;
      }else{
         if(Tiene_letras_y_numeros(nom)){
            nom_tspaces=false;
         }else{
            nom_tspaces=true;
         }
      }
   }
   nom+=".dat";
   ofstream crear_archivo;
   crear_archivo.open(nom.c_str(),ios::out);
   crear_archivo<<"Nombre                            fecha de ataque         gravedad      Atecion           fecha de registro\n";
   bool agregar_otro = false;
   crear_archivo.close();
    do 
    {
        Registro temp = Pedir_Registro_temp();
        agregar_linea_database(nom,temp);
        agregar_otro = ag_otro();
        
    } while (agregar_otro);
}
void Base_de_datos_existente() {
    ifstream leer;
    string nombre;
    bool Espacios;
    do{
        cout<<"Ingrese el nombre de la base de Datos : ";
        getline(cin,nombre);
        Espacios=Tiene_espacios(nombre);
    }while(Espacios);
    nombre+=".dat";
    leer.open(nombre.c_str(), ios::in);
    string linea_aux;
    if(!leer.fail()){
        while (!leer.eof()) {
            getline(leer,linea_aux);
            cout<<linea_aux<<'\n';
        }
        leer.close();
    }
    else{
        cout<<"\n\nNo se encontro la base de Datos Solicitada...\n\n";
    }
    pausa;
}
void Menu_Base_de_Datos() {
    string opcion;
    int iopcion;
    do {
        clear;
        cout << "\tBIENVENIDO AL MENÚ DE LA BASE DE DATOS\n\n";
        cout << "\nMenú de opciones\n\n1.-Mostrar una base de datos ya existente.\n2.-Crear una base de datos permanente.\n3.-Agregar a una base de datos.\n4.-Crear una base de datos temporal.\n5.-Regresar al menu anterior\n6.-Salir ->\n";
        fflush(stdin);
        do {
            cout << "Ingresa la opcion requerida\n--> ";
            getline(cin, opcion);
        } while (opcion != "1" and opcion != "2" and opcion != "3" and opcion != "4" and opcion != "5" and opcion != "6");
        iopcion = stoi(opcion);
        if (iopcion == 1) {
            Base_de_datos_existente();
        }
        else if (iopcion == 2) {
            Crear_una_base_de_datos_permanente();
        }
        else if (iopcion == 3) {
            Editar_una_base_de_datos();
        }
        else if (iopcion == 4) {
            Crear_base_temp();
        }
        else if (iopcion == 6) {
            despedida();
        }
    } while (iopcion != 5);
}
bool Usuarios_rep(const string& usuario) {
    string us_temp, aux;
    ifstream leer;
    leer.open("usuarios.dat", ios::in);
    while (!leer.eof()) {
        leer >> us_temp;
        leer >> aux;
        if (usuario == us_temp) {
            leer.close();
            return false;
        }
    }
    leer.close();
    return true;
}
void Agregar_usuario_sistema() {
    string t_pas, t_us, aux;
    clear;
    ofstream Esc;
    cin.ignore();
    cout << "Ingrese el nombre del Usuario : ";
    getline(cin, t_us);
    bool c_us = Tiene_espacios(t_us);
    while (c_us or (t_us.size() < 5)) {
        cout << "Parece que tu usuario es demasiado corto y/o contiene espacios\nIngresalo de nuevo : ";
        getline(cin, t_us);
        c_us = Tiene_espacios(t_us);
    }
    cout << "Ingrese el password del usuario : ";
    getline(cin, t_pas);
    bool c_pas = Tiene_espacios(t_pas);
    while (c_pas) {
        cout << "Parece que tu password contiene espacios\nIngresalo de nuevo : ";
        getline(cin, t_pas);
        c_pas = Tiene_espacios(t_pas);
    }
    if (Usuarios_rep(t_us)) {
        cout << "Usuario registrado exitosamente.:)\n";
        Esc.open("usuarios.dat", ios::out | ios::app);///ios::app escribir donde se quedo
        Esc << t_us << ' ' << t_pas << '\n';
        Esc.close();
        cout << "Desea añadir otro usuario 1=SI , 2=NO : ";
        cin >> aux;
        bool Esnum = Es_numero(aux);
        if (Esnum) {
            (stoi(aux) < 1 or stoi(aux) > 2) ? Esnum = false : true;
        }
        while (!Esnum)
        {
            cout << "Parece que escogiste alguna opcion inexistente o \ningresaste caracteres distintos a los solicitados\nPor favor ingreselo otra vez : ";
            cin >> aux;
            Esnum = Es_numero(aux);
            if (Esnum) {
                (stoi(aux) < 1 or stoi(aux) > 2) ? Esnum = false : true;
            }
        }
        if (stoi(aux) == 1) {
            Agregar_usuario_sistema();
        }
    }
    else {
        cout << "Parece que el usuario que intentas registrar , ya esta en nuestra base datos.\n";
        cout << "Deseas intentar registrar otro usuario 1=SI , 2=NO : ";
        cin >> aux;
        bool Esnum = Es_numero(aux);
        if (Esnum) {
            (stoi(aux) < 1 or stoi(aux) > 2) ? Esnum = false : true;
        }
        while (!Esnum)
        {
            cout << "Parece que escogiste alguna opcion inexistente o \ningresaste caracteres distintos a los solicitados\nPor favor ingreselo otra vez : ";
            cin >> aux;
            Esnum = Es_numero(aux);
            if (Esnum) {
                (stoi(aux) < 1 or stoi(aux) > 2) ? Esnum = false : true;
            }
        }
        if (stoi(aux) == 1) {
            Agregar_usuario_sistema();
        }
    }
}
void Escoger_opcion() {
    string op;
    bool num;
    do {
        clear;
        cout << "\t*** MENú PRINCIPAL DE OPCIONES ***\n1. Agregar otro usuario para acceder a todo el sistema\n2. Menú Base de Datos\n3. Salir ->\n";
        do {
            cout << "Ingrese su opcion : ";
            op = "";
            cin >> op;
            num = Es_numero(op);
            if (num) {
                if (stoi(op) < 1 or stoi(op) > 3)
                    num = false;
            }
        } while (!num);
        if (stoi(op) == 1)
            Agregar_usuario_sistema();
        else if (stoi(op) == 2)
            Menu_Base_de_Datos();
    } while (stoi(op) != 3);
}
bool Comprobar_us_pas(const string& us, const string& pas) {
    ifstream leer;
    leer.open("usuarios.dat", ios::in);
    string us_temp, pas_temp;
    while (!leer.eof()) {
        leer >> us_temp;
        leer >> pas_temp;
        if ((pas_temp == pas) and (us_temp == us)) {
            leer.close();
            return true;
        }
    }
    leer.close();
    return false;
}
bool Ingreso_por_paswoord() {
    string usuario = "", password = "";
    bool ingresa = false;
    int c_veces = 0;
    do {
        clear;
        usuario = ""; password = "";
        cout << "\t\t\tINSTITUTO POLITÉCNICO NACIONAL\n";
        cout << "\t\t\t\t    LOGIN\n";
        cout << "\t\t\t------------------------------\n";
        cout << "\n\tUsuario: ";
        getline(cin, usuario);
        while (usuario.size() < 5 or Tiene_espacios(usuario)) {
            usuario = "";
            cout << "\tError,parece ser que la longitud de tu usuario es demasiado \n\tcorta y/o contiene espacios , ingresalo otra vez por favor\n\tUsuario: ";
            getline(cin, usuario);
        }
        char let;
        cout << "\tPassword: ";
        do {
            let = getch();
            if (let != borrar and let != ENTER) {
                password += let;
                cout << '*';
            }
            else {
                if (let == borrar and password.size() > 0) {
                    password.pop_back();
                    cout << '\b';
                }
            }
        } while (let != ENTER);
        ingresa = Comprobar_us_pas(usuario, password);
        if ((!ingresa) and ++c_veces >= 3) {
            cout << "\n\n\tPor favor pidele alguien autorizdo que agregue tu usuario\n";
            Sleep(5000);
            exit(1);
        }
    } while (!ingresa);
    return true;
}
int main()
{
    setlocale(LC_ALL, "spanish");
    if (Ingreso_por_paswoord())
        Escoger_opcion();
    despedida();
    return 0;
}
