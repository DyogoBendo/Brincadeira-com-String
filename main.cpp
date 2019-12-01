#include <iostream>
#include <string>
#include <c++/4.8.3/vector>
#include <iomanip>

using namespace std;

//Declaração das Funções
void conta_letras (string frase);

void conta_palavras (string frase);

void conta_a (string frase);

vector<string> separa_palavras (string frase);

void repete_palavras(string oracao);

void troca_palavra(string frase);

string leia ();
// Inicio da Função Principal
int main(){

    int escolha;
    string frase;
    frase = leia();
    do
    {
        cout << "Escolha uma opcao: " << endl;
        cout << "[0] Sair" << setw(47) <<
        "[1] Tamanho da Frase" << endl <<
        "[2] Numero de Palavras" << setw(35)<<
        "[3] Quantidade de 'a' " << endl <<
        "[4] Palavras Repetidas " << setw(30) <<
        "[5] Troca Palavra " << endl <<
        "[6] Reescrever Frase " << setw(30) <<
        "[7] Limpar Tela " << endl;

        cin >> escolha;

        switch (escolha)
        {
            case 1:
                conta_letras(frase);
                break;
            case 2:
                conta_palavras(frase);
                break;
            case 3:
                conta_a(frase);
                break;
            case 4:
                repete_palavras(frase);
                break;
            case 5:
                troca_palavra(frase);
                break;
            case 6:
                frase = leia();
                cin.ignore();
                break;
            case 7:
                system("cls");
                break;
            case 0:
                return 0;

        }
    } while(true);
}
//Funcionamento das Funções
void conta_letras (string frase)
{
    cout << "Comprimento da frase, contando espaco: " << frase.length() << endl;
    cin.ignore();
}

void conta_palavras (string frase)
{
    int repete = 1;
    for (int i = 0; i < frase.length(); i ++)
    {
        if (frase[i] == ' ')
        {
            repete ++;
            frase.erase(0, i);
        }
    }
    cout << "Existe " << repete << " palavra(s)" << endl;
    cin.ignore();
}

void conta_a (string frase)
{
    int num = 0;
    for (int a = 0; a < frase.length(); a ++)
    {
        if (frase[a] == 'a')
        {
            num ++;
        }
    }
    cout << "Numero de letras 'a': " << num << endl;
    cin.ignore();
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

void repete_palavras(string oracao)
{
    vector <string> palavras;
    vector <string> repetiu;
    int passou, aparece;
    string repete;

    palavras = separa_palavras(oracao);

    for (int i = 0; i < palavras.size(); i ++)
    {
        repete = palavras[i];
        passou = 0;
        aparece = 0;
        repetiu.push_back(repete);

        for (int j = 0; j < repetiu.size(); j ++)
        {
            if (repete == repetiu[j]) // Checa se a palavra ja foi testada
            {
                passou ++; // A cada vez que ela aparece, soma mais um
            }
        }

        for(int k = 0; k < palavras.size(); k++)
        {
            if (repete == palavras[k]) // Contabiiza as repetições
            {
                aparece ++;
            }
        }

        if (passou == 1) //Evita que apareça mais de uma vez a mesma palavra
        {
            cout << "A palavra " << repete << " aparece " << aparece << " vez(es)" << endl;
        }
    }
    cin.ignore();
}

void troca_palavra(string frase)
{
    vector<string> organizado = separa_palavras(frase);
    string palavra1, palavra2;

    palavra1 = organizado[0];
    palavra2 = organizado[organizado.size() - 1];

    organizado[0] = palavra2;
    organizado[organizado.size() - 1] = palavra1;

    cout << "Frase trocada: ";
    for(int i = 0; i < organizado.size(); i ++)
    {
        cout << organizado[i] << " ";
    }
    cout << endl;
    cin.ignore();
}

string leia ()
{
    string frase;
    cout << "Digite uma palavra ou frase: ";
    getline(cin, frase);
    return frase;
}