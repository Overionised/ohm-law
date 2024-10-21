#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;


void calculator();
void rovnice();
void defhodnot();
long double getInt();
void illusion();

long double U, R, I, P;

void rovnice() {
    cout <<R"(ELEKTROTECHNICKÉ VÝPOČTY

Zadej hodnoty veličin nebo 0 pro dopočet
)"<<endl;
}

void illusion() {
    const string message = "computing beep boop ";
    const char spinner[] = {'\\', '|', '/', '-'};
    const int spinnerSize = sizeof(spinner) / sizeof(spinner[0]);
    int count = 0;

    while (count < 10) {
        cout << message <<spinner[count % spinnerSize] << "\r";
        cout.flush();

        auto start = chrono::steady_clock::now();
        while (chrono::steady_clock::now() - start < chrono::milliseconds(200)) {
        }

        count++;
    }

    cout << R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠤⣠⡯⠖⠛⠉⠉⠉⠉⠉⠛⢶⣤⠖⠚⠋⠉⠛⠓⢶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠞⠛⠀⠀⣀⣤⣶⠿⢷⢦⠀⠀⠀⢲⣿⣿⣿⣦⣄⠀⠈⠻⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠟⠁⠀⢀⣤⠞⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣆⡀⠀⠈⠻⢦⡀⠀⠹⣷⡲⢦⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠁⠀⢀⡴⡏⠁⠀⢀⡄⠀⣰⡆⠀⠀⠀⡀⢀⣼⠟⣿⣦⠀⠀⠈⠻⣄⠀⠈⠳⡄⠈⠙⠷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⠀⠀⣠⢏⡞⢀⣀⡴⠋⣠⢾⡟⠀⠀⢀⡾⢁⣾⠟⠀⠈⢿⣷⡄⠀⠀⢻⢧⡀⠀⠙⢦⣀⠀⠈⠻⣶⣄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⠁⠀⢀⡜⠁⡼⣱⣻⢏⣤⣞⢉⡜⠀⠀⢠⠞⣠⡾⠋⠉⠓⠒⠺⠷⣿⣳⡀⠸⣿⣷⡄⠀⠈⢻⡷⣄⡀⠈⢻⣦⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠞⢹⠃⠀⠀⡼⣠⣾⣷⢿⠟⠋⠉⠤⠞⠀⠐⠚⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⡈⠙⠳⢦⡃⠙⣷⠀⠀⠀⢣⠈⠙⢦⡀⠹⣷⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠏⢠⡇⠀⠀⣴⣳⠿⠛⠃⠀⠠⠤⢄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠔⠚⠋⠀⠀⠀⠀⠙⢦⣸⡇⠀⠀⠈⢧⠀⠀⣽⣾⣿⣷⣄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⢀⡼⠁⠀⠀⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⠀⠀⠀⠘⡆⢸⣿⣿⣿⣿⣿⡇⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⡇⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⠤⠶⠄⠀⠀⠀⠀⠀⠀⠘⡆⠀⠀⠀⢹⠈⣿⣿⣿⣿⠋⢳⣦⠀
⠀⠀⠀⠀⠳⣄⠀⠀⣾⣿⣿⣿⠁⠀⠀⡏⠀⠀⠀⠀⣀⣤⣤⣥⣤⣯⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣽⣿⣿⣿⣿⣿⢶⣤⡀⠀⠀⣧⠀⠀⠀⠈⡗⠚⣿⣿⣿⣶⡿⠟⠀
⠀⠀⠀⡀⠀⠈⠙⠒⠿⢛⣻⣿⠀⠀⢠⠇⠀⠀⣠⣾⣿⡿⢻⣿⣿⡙⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢡⣿⣴⣷⣿⣿⣧⠙⢿⣦⡀⣿⠀⠀⠀⠀⣧⣴⡿⢳⡘⣿⠀⠀⠀
⠀⣀⠞⠁⠀⠀⠀⢠⣶⣿⣿⣿⠀⠀⢸⠀⠀⣼⡿⢋⣿⣿⣿⢿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠉⠉⢻⣿⣇⠀⢻⣷⣿⠀⠀⠀⠀⣿⣿⡇⠀⢣⣿⡆⠀⠀
⠘⠛⠳⢦⣀⠀⠀⡏⠙⣿⢿⣿⠀⠀⣸⠀⣼⡿⠁⣼⣿⣿⠁⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣟⡿⢿⠀⠀⢸⡟⣿⠀⠀⣿⣟⠀⠀⠀⠀⡿⠉⢷⠀⠈⣿⡇⠀⠀
⠀⠀⠀⠀⠈⠳⣼⡁⢀⡟⣸⣿⠀⠀⡇⢠⣿⡇⢰⣻⡏⠛⣦⣶⠏⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣇⠈⠻⠷⠛⢀⡾⠀⠀⣸⣿⠀⠀⠀⢸⡷⢤⣼⡇⠀⠘⣇⠀⠀
⠀⠀⠀⠀⠀⠀⠈⠀⢸⡇⣿⣿⠀⠀⡇⣼⣿⣧⠀⠻⣧⣀⣀⢀⣰⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠷⠦⠤⠶⠛⠁⠠⠴⠟⣿⠀⠀⠀⡏⠀⢀⠈⢿⡄⠀⢸⡆⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣄⡟⢸⠀⢰⡇⠉⠉⠉⠁⠀⠈⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⠀⠀⡄⠠⡄⠀⠀⡇⠀⡆⠀⠐⠛⣏⢙⡎⣷⠀⠈⣷⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⢡⡟⠀⢸⣿⡠⠖⠋⢁⠔⠃⢠⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠃⠀⢰⡁⠀⢷⠀⢸⠁⢰⠁⠀⡇⠀⠘⣿⠀⣿⠀⠀⢿⡄
⠀⠀⠀⠀⠀⠀⠀⠀⡼⢡⣿⠇⠀⢸⣷⣷⠀⠀⠈⠀⠀⠈⠁⠀⠀⠀⠀⠒⠤⠄⠂⡀⡀⡀⠔⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠛⠀⢼⢀⠇⠀⢰⡥⠤⠾⠁⣰⣿⡀⠀⢸⡇
⠀⠀⠀⠀⠀⠀⠀⣸⢃⣾⡿⠀⠀⢠⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡞⠀⠀⡟⠁⠀⢀⣠⢾⣿⠃⡇⢀⣼⡇
⠀⠀⠀⠀⠀⠀⣰⠃⣼⣿⠃⠀⠀⣼⣏⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⢰⡷⠶⢶⠋⠀⢸⡟⢀⣧⣾⡿⠀
⠀⠀⠀⠀⠀⢰⠏⣰⣿⠃⠀⠀⢀⣯⣄⠉⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠃⠀⣼⠀⠀⣿⠀⢀⡾⠀⣼⣯⣿⠃⠀
⠀⠀⠀⠀⠀⡞⠀⣿⠃⠀⠀⢀⣾⡇⠈⠉⠛⢷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⣿⢠⣾⡗⠀⢰⡟⢀⡞⣡⣾⣵⠟⠁⠀⠀
⠀⠀⠀⠀⢰⡇⣼⢃⣠⣤⠀⣼⢻⡇⠀⠀⠀⠈⢿⠙⠶⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠶⠛⣿⠟⣧⢿⢹⡇⠀⣾⢀⣾⣿⡿⠛⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠈⣿⡿⠋⠁⣸⡾⠃⠈⣷⠀⠀⠀⠀⠘⢷⣄⠀⠉⢻⣷⠦⣤⣀⣀⠀⠀⠀⠀⠀⠀⢀⣀⡠⢴⡞⠋⠁⠀⣸⣯⣾⣿⡄⢸⡇⠸⣷⣿⡟⠉⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣸⠟⠁⠀⣼⠟⢧⡀⠀⠘⢷⡀⠀⠀⠀⠀⠙⣷⣤⣄⣿⡆⠀⠀⠈⠛⢿⣿⠟⠛⠉⠉⠀⠀⢸⣇⣠⣴⣶⣿⠿⡟⠚⠛⠾⣧⡄⠀⢰⡗⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣰⠃⠀⢠⣾⣟⠳⣌⣷⡄⠀⠈⠻⣤⡀⡶⠚⠛⡯⠤⢼⣿⣅⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⢈⣿⡟⠋⠻⡄⠀⠙⢆⠀⠀⢸⠉⠓⠿⢄⣀⡀⠀⠀⠀⠀⠀⠀
⠀⠀⢰⠇⠀⠠⠋⣼⠙⠶⣬⣋⡛⠃⠀⢀⣨⡿⠁⢀⡼⠁⠀⢠⠏⠉⡿⢶⣄⢀⣾⡇⠀⠀⠀⠀⠀⠀⢸⡃⠱⡄⠀⠙⣄⠀⠈⢧⡀⠀⡇⠀⠀⠀⢨⡿⣷⡀⠀⠀⠀⠀
⠀⢀⠇⠀⡰⠁⢰⠇⠀⠀⠀⠉⠉⠉⠉⠛⣻⠃⠀⠞⠁⠀⢰⠋⠀⣰⠁⠀⢸⣿⠋⠁⠀⠀⠀⠀⠀⠀⢸⣧⠀⠹⠆⠀⢈⣠⠤⠖⠒⠲⣾⠀⠀⢰⠏⠁⢹⣷⠀⠀⠀⠀)" << endl;
}

long double getInt() {
    long double csl;
    while (!(cin >> csl) || csl < 0 ) {
        cout << "zadejte rozumna cisla \n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return csl;
}

void defhodnot() {
    int count = 0;
    U = 0; R = 0; I = 0; P = 0;

    rovnice();
    cout << "Definujte prosím přesně 2 hodnoty. \n";

    cout << "Napětí [V]: ";
    U = getInt();
    if (U != 0) count++;

    cout << "Odpor [Ohm]: ";
    R = getInt();
    if (R != 0) count++;

    cout << "Proud [A]: ";
    I = getInt();
    if (I != 0) count++;

    cout << "Výkon [W]: ";
    P = getInt();
    if (P != 0) count++;

    if (count != 2) {
        cout << "Prosím, definujte přesně 2 hodnoty a ostatní nechte 0." << endl;
        defhodnot();
    }
}



void calculator(){

	if(R == 0){
        if(I != 0){
            if(U != 0){
                R = U/I;
                P = U*I;
                return;
            }else{
                R = P/(I*I);
                U = P/I;
                return;
            }
        }else{
            R = U/(P*P);
            I = P/U;
            return;
        }
    }if (I == 0){
        if(U != 0){
            I = U/R;
        }else{
            I = sqrt(P/R);
            U = P/I;
            return;
        }
    }

    P = I*I*R;
    U = I*R;
}
int main(){
    defhodnot();
    calculator();
    illusion();
    cout<<"Napětí je "<<U<< " V\n Odpor je: "<<R<<" ohm\n Proud je "<<I<<" A \n výkon je "<<P<<" w"<<endl;
}
