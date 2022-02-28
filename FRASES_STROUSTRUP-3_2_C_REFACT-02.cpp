/*
Para el Archivo del ejercicio (a)
contar la cantidad de palabras que hay x línea, luego
mostrar la cantidad total y el promedio de palabras x línea.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream openFile(string path);
int countWords(string sentence);
bool letter(int character);
void showWordsOf();

ifstream openFile(string path)
{
    ifstream in;
    in.open(path);

    return in;
}

bool letter(int character)
{
    string validDigits = "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ0123456789áäâéëêíïîóöôúüûÁÄÂÉËÊÍÏÎÓÖÔÚÜÛ";

    int i = 0;
    bool itsALetter = false;

    while(i < validDigits.length())
    {
        if(character == validDigits[i])
        {
            itsALetter = true;
            return itsALetter;
        }
        i++;
    }

    return itsALetter;
}

int countWords(string sentence)
{
    int counter = 0;
    bool foundWord = false;

    for(int i = 0; i < sentence.length(); i++)
    {
        if(letter(sentence[i]) && foundWord == false)
        {
            counter++;
            foundWord = true;
        }
        else if(!letter(sentence[i]) && foundWord == true)
        {
            foundWord = false;
        }
    }

    return counter;
}

void showWordsOf()
{
    ifstream textFile = openFile("QuotesOfBjarne.txt");

    int sentecesNumber = 0;
    int totalWords = 0;

    if(textFile)
    {
        while (!textFile.eof())
        {
            string sentence;
            getline(textFile, sentence);
            int wordsPerSentence = countWords(sentence);
            cout << "La frase numero " << sentecesNumber + 1 << " tiene " << wordsPerSentence << " palabras" << endl;

            totalWords += wordsPerSentence; //totalWords = totalWords + wordsPerSentence;
            sentecesNumber++;
        }

        cout << "Cantidad total de palabras " << totalWords << endl;
        float averageOfWords = float(totalWords) / float(sentecesNumber);
        cout << "Promedio de palabras por linea " << averageOfWords << endl;

        textFile.close();
    }
    else
    {
        cout << "No se ha podido abrir el archivo." << endl;
    }
}

int main()
{
    /*
        IMPORTANTE PRESTAR ATENCIÓN AL PASO POR REFERENCIA
        EN LAS FUNCIONES showQuotesOf y closeFile
        NO SE PUEDE INCIALIZAR UN OBJETO ifstream CON OTRO
        Y LUEGO PASARLO POR VALOR PORQUE ifstream TIENE
        UN CONSTRUCTOR COPIA ELIMINADO, POR ESO NO SE PUEDE COPIAR
    */

    showWordsOf();

    return 0;
}
