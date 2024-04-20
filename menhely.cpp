#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct Allat{
    std::string fajta;
    std::string nev;
    int kor;
    std::string szin;
};

void operator>>(std::istream& is, Allat& a)
{
    is >> a.fajta >> a.nev >> a.kor >> a.szin;
}

void operator<<(std::ostream& os, Allat& a)
{
    os << a.fajta << "\t" << a.nev << "\t" << a.kor << "\t" << a.szin;
}


void keres(){
    int valasz;
    std::string kifejezes;
    std::cout << "fajta(0), nev(1), kor(2), szin(3) alapjan kereses" << "\n";
    std::cin >> valasz;
    std::cout << "Mi a keresesi kifejezes?" << '\n';
    std::cin >> kifejezes;

    std::ifstream readfile("menhely.txt");
    std::string line;
    Allat a;
    std::string allat[4] = {"", "", "", ""};
    while(std::getline(readfile, line)){
        std::istringstream iss(line);
        iss >> a;
        allat[0] = a.fajta;
        allat[1] = a.nev;
        allat[2] = std::to_string(a.kor);
        allat[3] = a.szin;
        if(allat[valasz] == kifejezes)
        {
            std::cout << a;
            std::cout << '\n';
        }
    }
    readfile.close();
}

void hozzaad(){
    std::ofstream menhely;
    menhely.open("menhely.txt", std::ios::app);
    Allat a;
    std::cout << "Add meg az allat fajtajat, nevet, korat es szinet" << "\n";
    std::cin >> a;
    menhely << a;
    menhely << std::endl;
    menhely.close();
}

int main(){
    while(true){
        std::cout << "1 a hozzaadashoz, 2 a kereseshez, -1 a kilepeshez" << "\n";
        int mode = 0;
        std::cin >> mode; 
        if(mode == 1){
            hozzaad();
        }
        else if(mode == 2){
            keres();
        }
        else if(mode == -1){
            return 0;
        }
        else{
            std::cout << "Error";
            return 0;
        }
    }
}