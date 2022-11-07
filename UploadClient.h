#include <string>
#include <iostream>
#include <sstream>
#include <dirent.h>

using namespace std;

class UploadClient{
    
private:
    string filePath;
    string fileCaption;
    string keyWord;
    string fileDate;
public:
    UploadClient()=default;
    void getInput();
    void doPost();

    string getFilePath(){
        return filePath;
    }

    string getCaption(){
        return fileCaption;
    }

    string getkeyWord(){
        return keyWord;
    }

    string getDate(){
        return fileDate;
    }
};