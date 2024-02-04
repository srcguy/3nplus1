#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std::chrono;
using namespace std;
namespace fs = std::filesystem;
int x;
string command;

int main(){
    cout << ">>>";
    cin >> command;
    if (command == "DEL" || "del") {
        for (const auto& entry : fs::directory_iterator("data")) {
            fs::remove(entry.path());
        }
    }
    cout << ">";
    cin >> x;

    auto start_time = high_resolution_clock::now();

    cout << "WORKING..." << endl;

    int y = x;

    string filename = "data/" + to_string(y) + ".txt";
    ofstream file((filename));
    file << x << "\n";

    while (true){

        string filename = "data/" + to_string(y) + ".txt";
        ofstream file(filename, ios::app);
        file << x << "\n";

        if (x % 2 == 0) {
            x = x / 2;
        }
        else {
            x = 3 * x + 1;
        }

        if (x == 1) {
            //cout << "LOOP" << endl;
            file << "LOOP" << "\n";
            file.close();
            x = y + 1;
            y = x;
        }

        if (y >= 101) {
            cout << "EMERGENCY BREAK" << endl;
            auto end_time = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end_time - start_time);
            cout << duration.count();
            break;
        }

        //cout << x << endl;

    }
}
