#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class File_handler{
    private:
    string filename;
    int sumOfNums = 0;
    public:

    void fileCreator(string);
    void fileWriter(int, int);
    void filePrinter();
    int fileArithmetic();
};

void File_handler::fileCreator(string filename){
    ofstream ofile(filename);
    this->filename = filename;
    ofile.close();
    cout<<"...FILE CREATED!\n";
}

void File_handler::fileWriter(int start, int stop){
    ofstream ofile(this->filename);
    for(int i=start; i<stop; i++){
        ofile<<i<<" ";
    }
    ofile.close();
    cout<<"...FILE DATA WRITTEN!\n";
}

void File_handler::filePrinter(){
    char singleChar;
    ifstream ifile(this->filename);
    while (!ifile.eof()){
        ifile.get(singleChar);
        cout<<singleChar;
    }
    ifile.close();
    cout<<"\n...FILE CONTENTS PRINTED!\n";
}

int File_handler::fileArithmetic(){
    ifstream ifile(this->filename);
    
    int singleNum;
    while (ifile >> singleNum){
        this->sumOfNums += singleNum;
    }
    ifile.close();
    return this->sumOfNums;
}

int main(){
    int number;
    string filename = "list_of_num.txt";

    // creating file
    File_handler obj;
    obj.fileCreator(filename);

    // writing to file
    int start= 0;
    int stop = 101;
    obj.fileWriter(start, stop);

    // displaying file contents
    // obj.filePrinter();
    // Uncomment above line for use in Linux systems. But not suitable for Windows as above function isn't suited for Windows file operations

    cout<<"Sum of file integers = "<<obj.fileArithmetic()<<"\n";
}