#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


using namespace std;

void dibujarFigura(int);
void clearLine(int x, int y, int length);
void moveCursor(int x, int y);
void gotoxy(int x, int y);

void moveCursor(int x, int y) {

     if(x<0) x=119;// si x,0, aparece en el lado derecho
    if(x>119) x=0;//si x> 199,       en el lado ixquierdo
    if(y<0) y=99;// parte inferior
    if(y>99) y=0;
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu(){
    int cursorX=0 , cursorY=3 ;
     COORD bufferSize = {120, 100};
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);


       cout << "Presione F1 Triangulo | F2 Cuadrado | F3 Rectangulo| F4 circulo | F5 linea |F6 Rombo | F7 Hexagono | F8 Nuevo Caracter| F9 limpiar pantalla | F10 Color de Caracter | F12 Grabar pantalla" << endl;
    moveCursor(cursorX, cursorY);

    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == ARRIBA) cursorY--;
            else if (key == ABAJO) cursorY++;
            else if (key == IZQUIERDA) cursorX--;
            else if (key == DERECHA) cursorX++;

            moveCursor(cursorX, cursorY);

            if (GetAsyncKeyState(VK_F1) & 0x8000)
            {
                dibujarFigura(1);
                break;
            }
            else if (GetAsyncKeyState(VK_F2)  & 0x8000)
            {
                dibujarFigura(2);
                break;
            }
            else if (GetAsyncKeyState(VK_F3)  & 0x8000)
            {
                dibujarFigura(3);
                break;
            }
            else if (GetAsyncKeyState(VK_F4)  & 0x8000)
            {
                dibujarFigura(4);
                break;
            }
            else if (GetAsyncKeyState(VK_F5)  & 0x8000)
            {
                dibujarFigura(5);
                break;
                }
            else if (GetAsyncKeyState(VK_F6)  & 0x8000)
            {
                dibujarFigura(6);
                break;
                }
            else if (GetAsyncKeyState(VK_F7)  & 0x8000)
            {
                dibujarFigura(7);
                break;
                }
            else if (GetAsyncKeyState(VK_F8)  & 0x8000)
            {
                dibujarFigura(8);
                break;}
            else if (GetAsyncKeyState(VK_F9)  & 0x8000)
            {
                dibujarFigura(9);
                break;
                }
            else if (GetAsyncKeyState(VK_F10)  & 0x8000)
            {
                dibujarFigura(10);
                break;

                }
            else if (GetAsyncKeyState(VK_F12)  & 0x8000)
            {
                dibujarFigura(12);
                break;
            moveCursor(cursorX, cursorY);
        }
    }
    }

}
void gotoxy(int x, int y) {

    if(x<0) x=119;// si x,0, aparece en el lado derecho
    if(x>119) x=0;//si x> 199,       en el lado ixquierdo
    if(y<0) y=99;// parte inferior
    if(y>99) y=0;// parte superior
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwPos);

}

void dibujarFigura(int opcion) {


     int x = 40, y = 10;
    bool salir = false;

    CONSOLE_SCREEN_BUFFER_INFO csbi;


    do {


        switch (opcion) {
            case 1:


               cout << "Triangulo" << endl;
        int tam;
        cout << "Ingrese el tamanio del triangulo: ";
        cin >> tam;
        cout << "Puedes moverte con las flechas antes de presionar 1" << endl;
        clearLine(0, 2, 80);

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        x = csbi.dwCursorPosition.X;
        y = csbi.dwCursorPosition.Y;

        while (!salir)
        {
            if (_kbhit())
            {
                char tecla = _getch();
                if (tecla == '1') salir = true;

                if (tecla == IZQUIERDA) x--;
                else if (tecla == DERECHA) x++;
                else if (tecla == ARRIBA) y--;
                else if (tecla == ABAJO) y++;

                gotoxy(x, y);
            }
            Sleep(30);
        }

        for (int i = 0; i < tam; i++)
        {
            gotoxy((x - i + 120) % 120, (y + i) % 100);
            cout << "*";
            gotoxy((x + i) % 120, (y + i) % 100);
            cout << "*";
            if (i < tam - 1)
            {
                gotoxy((x - tam + 1 + i + 120) % 120, (y + tam) % 100);
                cout << "* ";
            }
            else
            {
                gotoxy((x - tam + 1 + i + 120) % 120, (y + tam) % 100);
                cout << " *" << endl;
            }
        }

       menu();


            case 2:
                cout << "Cuadrado" << endl;
                int lado;
                cout << "Ingrese el tamanio del cuadrado: ";
                cin >> lado;
                cout<< "puedes moverte con las flechas antes de presionar 1"<< endl;
                cout << "Presione '1' para dibujar." << endl;


                GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
                x = csbi.dwCursorPosition.X;
                y = csbi.dwCursorPosition.Y;

                while (!salir) {
                    if (_kbhit()) {
                        char tecla = _getch();

                        if (tecla == '1') {
                            salir = true;
                            break;
                        }

                        gotoxy(x, y);

                        if (tecla == IZQUIERDA) x--;
                        if (tecla == DERECHA) x++;
                        if (tecla == ARRIBA) y--;
                        if (tecla == ABAJO) y++;
                        gotoxy(x, y);
                    }
                    Sleep(30);
                }


                for (int i = 0; i < lado; i++) {
                    gotoxy(x + i, y);
                    cout << "*";
                }
                for (int i = 1; i < lado - 1; i++) {
                    gotoxy(x, y + i);
                    cout << "*";
                    gotoxy(x + lado - 1, y + i);
                    cout << "*";
                }
                for (int i = 0; i < lado; i++) {
                    gotoxy(x + i, y + lado - 1);
                    cout << "* ";
                }
                cout << endl;
                cout << endl;

                menu();

            case 3:
                cout << "Rectangulo" << endl;

    int base, altura;
    cout << "Ingrese el tamanio de la base del Rectangulo: ";
    cin >> base;
    cout << "Ingrese la altura del Rectangulo: ";
    cin >> altura;

    cout<< "puedes moverte con las flechas antes de presionar 1"<< endl;
                cout << "Presione '1' para dibujar." << endl;


    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    x = csbi.dwCursorPosition.X;
    y = csbi.dwCursorPosition.Y;
           y = csbi.dwCursorPosition.Y;
                y = csbi.dwCursorPosition.Y;
          if (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4) {
        if (x < 40) x = 40;
        if (y < 10) y = 10;
    }
    while (!salir) {
        if (_kbhit()) {
            char tecla = _getch();

            if (tecla == '1') {
                salir = true;
                break;
            }

            gotoxy(x, y);

            if (tecla == IZQUIERDA) x--;
            if (tecla == DERECHA) x++;
            if (tecla == ARRIBA) y--;
            if (tecla == ABAJO) y++;
            gotoxy(x, y);
        }
        Sleep(30);
    }

    for (int i = 0; i < base; i++) {
        gotoxy(x + i, y);
        cout << "*";
        gotoxy(x + i, y + altura - 1);
        cout << "*";
    }
    for (int i = 1; i < altura - 1; i++) {
        gotoxy(x, y + i);
        cout << "*";
        gotoxy(x + base - 1, y + i);
        cout << "*";
    }
    cout << endl;
    cout << endl;


                 menu();

            case 4:
                cout << "Circulo" << endl;
                float radio;
                cout << "Ingrese el radio del circulo: ";
                    cin >> radio;
                   cout<< "puedes moverte con las flechas antes de presionar 1"<< endl;
                cout << "Presione '1' para dibujar." << endl;


    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    x = csbi.dwCursorPosition.X;
    y = csbi.dwCursorPosition.Y;
     if (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4) {
        if (x < 40) x = 40;
        if (y < 10) y = 10;
    }


    while (!salir) {
        if (_kbhit()) {
            char tecla = _getch();

            if (tecla == '1') {
                salir = true;
                break;
            }

            gotoxy(x, y);

            if (tecla == IZQUIERDA) x--;
            if (tecla == DERECHA) x++;
            if (tecla == ARRIBA) y--;
            if (tecla == ABAJO) y++;
            gotoxy(x, y);
        }
        Sleep(30);
    }

 for (int i = -radio; i <= radio; i++) {
        for (int j = -radio; j <= radio; j++) {
            float distancia = sqrt(i * i + j * j);
            if (distancia <= radio + 0.5) {
                gotoxy(x + i, y + j);
                cout << "*";
            }
            cout << endl;
        }
    }
     menu();
     case 5:
        {
             cout << "LINEA" << endl;
                int linea;
                cout << "Longitud de la linea.. ? ";
                cin >> linea;
                cout<< "puedes moverte con las flechas antes de presionar 1"<< endl;
                cout << "Presione '1' para dibujar." << endl;


                GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
                x = csbi.dwCursorPosition.X;
                y = csbi.dwCursorPosition.Y;

                while (!salir) {
                    if (_kbhit()) {
                        char tecla = _getch();

                        if (tecla == '1') {
                            salir = true;
                            break;
                        }

                        gotoxy(x, y);

                        if (tecla == IZQUIERDA) x--;
                        if (tecla == DERECHA) x++;
                        if (tecla == ARRIBA) y--;
                        if (tecla == ABAJO) y++;
                        gotoxy(x, y);
                    }
                    Sleep(30);
                }



                for(int i = 0; i < linea; ++i){
                    cout << "*";
                }
               cout << endl;
        }
         menu();
     case 6:
        {
            cout << "ROMBO" << endl;

                int rom;
                cout << "Longitud de el ROMBO.. ? ";
                cin >> rom;
                cout<< "puedes moverte con las flechas antes de presionar 1"<< endl;
                cout << "Presione '1' para dibujar." << endl;


                GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
                x = csbi.dwCursorPosition.X;
                y = csbi.dwCursorPosition.Y;

                while (!salir) {
                    if (_kbhit()) {
                        char tecla = _getch();

                        if (tecla == '1') {
                            salir = true;
                            break;
                        }

                        gotoxy(x, y);

                        if (tecla == IZQUIERDA) x--;
                        if (tecla == DERECHA) x++;
                        if (tecla == ARRIBA) y--;
                        if (tecla == ABAJO) y++;
                        gotoxy(x, y);
                    }
                    Sleep(30);
                }

              for (int i = 0; i < rom; ++i) {
        gotoxy(x, y + i); // Mover el cursor a la posición inicial de cada línea
        for (int j = rom - i; j >= 0; --j) {
            cout << " ";
        }
        for (int k = 0; k < (i + 1); ++k) {
            cout << "* ";
        }
    }

    // Parte inferior del rombo
    for (int i = 0; i < (rom + 1); ++i) {
        gotoxy(x, y + rom + i); // Mover el cursor a la posición inicial de cada línea
        for (int j = 0; j <= i; ++j) {
            cout << " ";
        }
        for (int k = (rom - i); k >= 0; --k) {
            cout << "* ";
        }

    }
    cout<< endl;
        }
            menu();

        case 7:
        {
            cout << "Hexagono" << endl;
            {


                int n;
                cout << "Longitud de el HEXAGONO.. ? ";
                cin >> n;
                cout<< "puedes moverte con las flechas antes de presionar 1"<< endl;
                cout << "Presione '1' para dibujar." << endl;


                GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
                x = csbi.dwCursorPosition.X;
                y = csbi.dwCursorPosition.Y;

                while (!salir) {
                    if (_kbhit()) {
                        char tecla = _getch();

                        if (tecla == '1') {
                            salir = true;
                            break;
                        }

                        gotoxy(x, y);

                        if (tecla == IZQUIERDA) x--;
                        if (tecla == DERECHA) x++;
                        if (tecla == ARRIBA) y--;
                        if (tecla == ABAJO) y++;
                        gotoxy(x, y);
                    }
                    Sleep(30);
                }

           int i,j,k;
  //numero de astericos

  for (int j = 0; j < n; j++) {
        gotoxy(x, y + j); // Mover el cursor a la posición inicial de cada línea
        for (int i = 1; i < n - j; i++) cout << " ";
        for (int i = 1; i < n + 2 * j + 1; i++) cout << "*";
        cout << endl;
    }

    // Parte inferior del diamante
    for (int j = n - 2; j >= 0; j--) {
    gotoxy(x, y + (2 * n - 2 - j)); // Mover el cursor a la posición inicial de cada línea
    for (int i = 0; i < n - j - 1; i++) cout << " ";
    for (int i = 0; i < 2 * j + n; i++) cout << "*";
    cout << endl;
    }


}

            menu();
        }case 8:
        {
            cout << "Nuevo caracter" << endl;
            menu();
        }
        case 9: {
        cout << "Limpiar pantala" << endl;
            menu();


        }
        case 10: {
        cout << "Color de caracter" << endl;
            menu();





        }
        case 12: {
        cout << "grabar pantala" << endl;
            menu();


        }


            case 13:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
        salir = false; // Restablecer la variable salir a false para permitir que el bucle continúe
    } while (opcion != 12);

}

void clearLine(int x, int y, int length)
{
    gotoxy(x, y);
    for (int i = 0; i < length; ++i)
    {
        cout << " ";
    }
    gotoxy(x, y); // Volver a la posici n original para imprimir el nuevo mensaje
}


int main() {

     int cursorX =0, cursorY = 2;
     COORD bufferSize = {120, 100};
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
 system("cls");
    cout << "Bienvenido al programa de figuras geometricas." << endl;
 menu();

    return 0;
}
