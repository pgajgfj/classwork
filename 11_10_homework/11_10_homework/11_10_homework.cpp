#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string modifyIfInLineNoSpace(string fname) {
    int counter = 0, final = -1;
    string res = "";
    string current;
    ifstream file;
    file.open(fname);
    if (!file.is_open()) {
        cout << "Cannot open such file" << endl;
        return "";
    }

    while (getline(file, current))
    {
        if (current.find(' ') == string::npos) {
            final = counter;
        }
        counter++;
    }
    file.clear();
    file.seekg(0);
    counter = 0;
    
    while (getline(file, current))
    {
        if (final == -1) {
            return "\0";
        }
        if (counter == final) {
            res += current + "------------" + "\n";
        } else res += current +"\n";
        counter++;
    }
    file.close();
    return res;
}


bool isMoreThan6Letters(string s){
    if (s.length() > 6) {
        return true;
    }
    return false;
}

string readFilebyWord_filter(string fname) {
    string word = "";
    string res = "";
    ifstream file;
    file.open(fname);
    if (!file.is_open()) {
        cout << "Cannot open such file" << endl;
        return "";
    }
    while (file >> word)
    {
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        if (isMoreThan6Letters(word)) {
            res += word + " ";
        }
    }
    file.close();
    return res;

}

string readByLine(string fname) {
    string line, res;
    ifstream file;
    file.open(fname);
    if (!file.is_open()) {
        cout << "Cannot open such file" << endl;
        return "";
    }
    while (getline(file, line))
    {
        res += line + "\n";
    }
    file.close();
    return res;
}

string readByLineBackwards(string fname) {
    string line, res;
    ifstream file;
    file.open(fname);
    if (!file.is_open()) {
        cout << "Cannot open such file" << endl;
        return "";
    }
    while (getline(file, line))
    {
        res = line + "\n" + res;
    }
    return res;
}

void writeFile(string fname, string value) {
    ofstream file(fname);
    if (!file.is_open()) cout << "File not found" << endl;
    else file << value << endl;
    file.close();
}
void addinFile(string fname, string value) {
    ofstream file;
    file.open(fname, ios_base::app);
    if (!file.is_open()) cout << "File not found" << endl;
    else file << value << endl;
    file.close();
}

int main()
{
    string fname = "text.txt";
    
    string fname2 = "filtred.txt";
    writeFile(fname2, readFilebyWord_filter(fname));


    string fname3 = "task2.txt";
    string fname4 = "task2done.txt";
    writeFile(fname4, readByLine(fname3));


    string fname5 = "task2.txt";
    string fname6 = "task3done.txt";
    writeFile(fname6, readByLineBackwards(fname5));



    string fname7 = "task4.txt";
    string fname8 = "task4done.txt";
    string text = modifyIfInLineNoSpace(fname7);
    cout << text << endl;
    if (text == "\0") {
        writeFile(fname8, readByLine(fname7));
        addinFile(fname8, "------------");
    }
    else writeFile(fname8, text);
}

