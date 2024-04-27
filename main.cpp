#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


using namespace std;


void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x ;
    dwPos.Y = y ;
    SetConsoleCursorPosition(hCon, dwPos);
}
void moveCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void dibujarFigura() {
    int opcion;
     int x = 40, y = 10;
    bool salir = false;
     bool figuraDibujada = false;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    cout << "Menu:" << endl;
    cout << "1. Dibujar un Triangulo | 2. Dibujar un Cuadrado | 3. Dibujar un Rectangulo| 4. Dibujar un Circulo| 5. Borrar Figura| 6. Salir" << endl;




    do {

        cout << "Elige una opcion: ";
        cin >> opcion;



        switch (opcion) {
            case 1:
                cout << "Triangulo" << endl;

                int tam;
                cout << "Ingrese el tamanio del triangulo: ";
                cin >> tam;
                cout<< "puedes moverte con las flechas antes de presionar 1"<< endl;
                cout << "Presione '1' para dibujar." << endl;



                // Obtener las coordenadas actuales del cursor
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
for (int i = 0; i < tam; i++) {
    gotoxy(x - i, y + i);
    cout << "*";

    gotoxy(x + i, y + i);
    cout << "*";

    if (i < tam - 1) {
        gotoxy(x - tam + 1 + i, y + tam);
        cout << "* ";
    } else {
        gotoxy(x - tam + 1 + i, y + tam);
        cout << " *" << endl;
    }
    cout << endl;
}
break;

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
                break;

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


                break;

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
    break;
     case 5:
        {

    cout << "Borrando la figura..." << endl;

    // Guardar las coordenadas originales del cursor
    int originalX = x;
    int originalY = y;

    // Borrar la figura dibujada reescribiendo los puntos con espacios
    for (int i = 0; i < tam; i++) {
        // Borrar los puntos en las líneas del triángulo
        gotoxy(originalX - i, originalY + i);
        cout << " ";
        gotoxy(originalX + i, originalY + i);
        cout << " ";
        if (i < tam - 1) {
            gotoxy(originalX - tam + 1 + i, originalY + tam);
            cout << " ";
        }
    }
    // Borrar los puntos del cuadrado
    for (int i = 0; i < lado; i++) {
        // Borrar los puntos en la parte superior e inferior del cuadrado
        gotoxy(originalX + i, originalY);
        cout << " ";
        gotoxy(originalX + i, originalY + lado - 1);
        cout << " ";
    }
    for (int i = 1; i < lado - 1; i++) {
        // Borrar los puntos en los lados izquierdo y derecho del cuadrado
        gotoxy(originalX, originalY + i);
        cout << " ";
        gotoxy(originalX + lado - 1, originalY + i);
        cout << " ";

    }




    // Volver a colocar el cursor en su posición original
    gotoxy(originalX, originalY);
    break;
    }


            case 6:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
        salir = false; // Restablecer la variable salir a false para permitir que el bucle continúe
    } while (opcion != 6);
}


int main() {
     int cursorX =0, cursorY = 2;
     COORD bufferSize = {120, 100};
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);


    cout << "Bienvenido al programa de figuras geometricas." << endl;
      cout << "presione 1. para continuar" << endl;

    moveCursor(cursorX, cursorY);

    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 72) {
                cursorY--;
            } else if (key == 80) {
                cursorY++;
            } else if (key == 75) {
                cursorX--;
            } else if (key == 77) {
                cursorX++;
            } else if (key == '1') {
                dibujarFigura();
                break;
            }


            moveCursor(cursorX, cursorY);
        }
    }
    return 0;
}
