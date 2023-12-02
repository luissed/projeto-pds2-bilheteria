    // using ofstream constructors.
#include <iostream>
#include <fstream>  
#include <iomanip>
#include <sstream>

int main() {
std::stringstream os;
    os<<"NOME: LUIS"<<std::endl;
    os<<"EMAIL: LUIS.EDUARDOD2012@GMAIL.COM"<<std::endl;
    os<<"IDADE: 20 anos"<<std::endl;
    os<<"CPF: 022.218.156-70"<<std::endl;
for(int i=0; i<4;i++){
    std::ofstream outfile ("./recibos/compra #"+std::to_string(i)+".pdf");

outfile << os.str();
outfile.close();
} 
}