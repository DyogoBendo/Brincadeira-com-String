#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> separa_palavras (string frase);

void idade (vector<string> linhas)
{
    string procura;
    for (int i = 0; i < linhas.size(); i ++)
    {
        procura = linhas[i];
        if (procura.find("FRANCISCO") != - 1)
        {
            int nascimento = stoi(procura.substr(6, procura.length() - 1));
            cout << "A idade do Francisco Meira Barbosa eh: " << 2019 - nascimento << endl;
        }
    }

}

void cidade (vector <string> linhas)
{
    string procura, finalmente;
    int legal = 0, massa = 0;
    vector<string> achou;

    for (int i = 0; i < linhas.size(); i ++)
    {
        procura = linhas[i];
        if (procura.find("MILTON") != - 1)
        {
            achou = separa_palavras(procura);
        }
    }
    for (int i = 0; i < achou.size(); i ++)
    {
        procura = achou[i];
        if (procura.find(";") != -1 && legal == 1)
        {
            finalmente = procura.substr( massa,  procura.find(";") - massa);
            finalmente = "Fortaleza";
            cout << "A cidade do Milton Holanda eh: "  <<  finalmente << endl;
        }
        else if (procura.find(";"))
        {
            if (legal == 1)
            {
                massa = procura.find(";");
            }
            legal ++;
        }

    }
}

void estado (vector<string> linhas)
{
    vector < string > amo_Jeffinho;
    string top;
    for (int i = 0; i < linhas.size(); i ++)
    {
        top = linhas[i];
        if (top.find("IDELSEO") != -1)
            {
                amo_Jeffinho = separa_palavras(top);
                cout << "O estado do IDELSEOCARVALHO FILHO EH O: " << amo_Jeffinho[amo_Jeffinho.size() - 1] << endl;
            }
    }
}
void ceara (vector <string>linhas)
{
    vector < string > a;
    string top;
    int contabiliza = 0;
    for (int i = 0; i < linhas.size(); i ++)
    {
        top = linhas[i];
        if (top.find("CE") != -1)
        {
            contabiliza ++;
        }
    }
    cout << "Esse eh o numero de pessoas que moram no Ceara: " << contabiliza << endl;
}

int main()
{
    ifstream leitura ("clientes.txt", ios::app);
    string frase;
    vector <string> texto;

    while(!leitura.eof())
    {
        getline(leitura, frase);
        texto.push_back(frase);
    }
    idade (texto);
    cidade (texto);
    estado (texto);
    ceara(texto);

}

vector<string> separa_palavras (string frase)
{
    vector <string> armario;
    vector <string> repetiu;
    int antigo = 0;

    for (int i = 0; i <= frase.length(); i ++)
    {
        if (frase[i] == ' ' || i == frase.length())
        {
            armario.push_back(frase.substr(antigo, i - antigo));
            antigo = i + 1;
        }
    }
    return armario;
}