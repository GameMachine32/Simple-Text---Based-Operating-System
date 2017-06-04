#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <direct.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <conio.h>
using namespace std;
ofstream UserData;
ifstream MoveData;
ifstream ReadData;
string username;
string option;
string fn;
string ft;
string rfn;
string rftxt;
string exe;
string foldername;
string fc;
string efn;
string pause;
string bcolor = "0";
string tcolor = "7";
string fd;
string dfoldrn;
string oldfilename;
string newfilename;
string mf;
string mfn;
string mfntxt;
string mfntxtc;
DIR* readir;
char dir[60];
string ndir;
bool riw;
int main()
{
    system("COLOR 07");
    cout << "Booting..." << endl;
    Sleep(600);
    cout << "Enter your username: ";
    cin >> username;
    cout << "Welcome " << username << "!" << endl;
    for (;;) {
        system(("COLOR " + bcolor + tcolor).c_str());
        cout << "[@root." << username << "." << dir << "$]";
        cin >> option;
        if (option == "help" || option == "HELP" || option == "Help") {
            cout << "List of commands: " << endl;
            cout << "wrt: Wrties text to a file" << endl;
            cout << "rd: Reads text from a file" << endl;
            cout << "run: runs an executable program (.exe or .com)" << endl;
            cout << "exit: close the program" << endl;
            cout << "mf: Creates a new folder" << endl;
            cout << "colr: changes the console color" << endl;
            cout << "cd: changes the directory" << endl;
            cout << "dir: shows a list of all the files in the current directory" << endl;
            cout << "edt: Edits the content of a file" << endl;
            cout << "clr: clears the console window" << endl;
            cout << "del: deletes a file" << endl;
            cout << "delf: deletes a folder" << endl;
            cout << "rn: Renames a file/folder" << endl;
            cout << "lgout: kills all running applications and logs out" << endl;
            cout << "rst: restarts the computer" << endl;
            cout << "shd: shuts down the computer" << endl;
            cout << "help: Does the exact thing you just saw" << endl;
        }

        else if (option == "wrt") {
            cout << "Name of file (including extension): ";
            cin >> fn;
            cin.ignore();
            cout << "Enter file content: ";
            getline(cin, ft);
            UserData.open(fn);
            UserData << ft;
            UserData.close();
            continue;
        }

        else if (option == "rd") {
            cin.ignore();
            cout << "Enter the name of the file to be read: ";
            getline(cin, rfn);
            ReadData.open(rfn);
            if (ReadData.is_open()) {
                while (getline(ReadData, rftxt)) {
                    cout << rftxt << endl;
                }
                ReadData.close();
                continue;
            }
        }
        else if (option == "run") {
            cout << "Run program in same window (Must be a command line app(Y/N))? ";
            cin >> option;
            if (option == "Y" || option == "y") {
                riw = true;
            }
            else if (option == "N" || option == "n") {
                riw = false;
            }
            cout << "Enter the name and file extension of the executable (exe or .com): ";
            cin >> exe;
            if (riw == true) {
                system((exe).c_str());
            }

            else if (riw == false) {
                system(("start " + exe).c_str());
            }
        }
        else if (option == "mf") {
            cin.ignore();
            cout << "Type the name of the folder you want to create: ";
            getline(cin, foldername);
            mkdir((foldername).c_str());
            continue;
        }
        else if (option == "cd") {
            cin.ignore();
            cout << "Folder to go to: ";
            cin.getline(dir, 60);
            ndir = dir;
            _chdir(dir);
        }
        else if (option == "dir") {
            DIR* dir;
            struct dirent* ent;
            if ((dir = opendir("C:")) != NULL) {
                while ((ent = readdir(dir)) != NULL) {
                    printf("%s\n", ent->d_name);
                }
                closedir(dir);
            }
            else {
                perror("");
                return EXIT_FAILURE;
            }
        }
        else if (option == "edt") {
            cout << "Name of file to edit: ";
            cin >> efn;
            cin.ignore();
            cout << "New file content: ";
            getline(cin, fc);
            UserData.open(efn);
            UserData << fc;
            UserData.close();
            continue;
        }
        else if (option == "clr") {
            system("cls");
            continue;
        }
        else if (option == "colr") {
            cout << "0 = Black" << endl;
            cout << "1 = Blue" << endl;
            cout << "2 = Green" << endl;
            cout << "3 = Aqua" << endl;
            cout << "4 = Red" << endl;
            cout << "5 = Purple" << endl;
            cout << "6 = Yellow" << endl;
            cout << "7 = White" << endl;
            cout << "8 = Gray" << endl;
            cout << "9 = Light Blue" << endl;
            cout << "A = Light Green" << endl;
            cout << "B = Light Aqua" << endl;
            cout << "C = Light Red" << endl;
            cout << "D = Light Purple" << endl;
            cout << "E = Light Yellow" << endl;
            cout << "F = Bright White" << endl;
            cout << "Enter the color for text: ";
            cin >> tcolor;
            cout << "Enter color for backround: ";
            cin >> bcolor;
            system(("COLOR " + bcolor + tcolor).c_str());
            continue;
        }
        else if (option == "del") {
            cin.ignore();
            cout << "Folder to delete: ";
            getline(cin, fd);
            remove((fd).c_str());
            continue;
        }
        else if (option == "rn") {
            cin.ignore();
            cout << "Name of file/folder: ";
            getline(cin, oldfilename);
            cout << "New name: ";
            getline(cin, newfilename);
            rename((oldfilename).c_str(), (newfilename).c_str());
            continue;
        }
        else if (option == "delf") {
            cin.ignore();
            cout << "Folder to delete: ";
            getline(cin, dfoldrn);
            _rmdir((dfoldrn).c_str());
            continue;
        }
        else if (option == "jfj495sDSDF344k") {
            cout << "Well you just typed that in to get this message" << endl;
            continue;
        }
        else if (option == "mv") {
            cin.ignore();
            cout << "Name of file to move: ";
            getline(cin, mf);
            cout << "New destination: ";
            getline(cin, mfn);
            MoveData.open(mf);
            getline(MoveData, mfntxt);
            mfntxtc = mfntxt;
            MoveData.close();
            remove((mf).c_str());
            _chdir((mfn).c_str());
            UserData.open(mf);
            UserData << mfntxtc;
            UserData.close();
            _chdir((ndir).c_str());
            Sleep(1);
            continue;
        }
        else if (option == "lgout") {
            system("shutdown -f");
        }
        else if (option == "rst") {
            system("shutdown -r");
        }
        else if (option == "shd") {
            system("shutdown -s");
        }
        else if (option == "exit") {
            cout << "Exitng...";
            Sleep(400);
            exit(0);
        }
        else {
            cout << "'" << option << "' is not a valid command. Type 'Help' for a list of commands." << endl;
            continue;
        }
    }
}
