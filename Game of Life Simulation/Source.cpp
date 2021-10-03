/*/
Andy Chen
Produces generations of the Game of Life
/*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> openFile(const string& file);
vector<string> nextGeneration(const vector<string>& world);
void displayWorld(const vector<string>& world);
int countCells(const vector<string>& world, const int& row, const int& col);

int main() {
    cout << "Initial World" << endl;
    string filename = "life.txt";
    vector<string> world = openFile(filename);
    for (int i = 1; i < 11; ++i) {
        cout << "Generation " << i << endl;
        world = nextGeneration(world);
        displayWorld(world);
    }
    return 0;
}

vector<string> nextGeneration(const vector<string>& world) {
    int livingCell = 0;
    vector<string> newWorld = world;

    for (int row = 1; row < world.size()-1; ++row) {
        for (int col = 1; col < world[row].size()-1; ++col) {
            livingCell = countCells(world, row, col);
            if ((livingCell < 2 || livingCell > 3) && world[row][col] == '*') {
                newWorld[row][col] = '-';
            } 
            if ((livingCell == 3 || livingCell == 2) && world[row][col] == '*') {
                newWorld[row][col] = '*';
            }
            if (livingCell == 3 && world[row][col] == '-') {
                newWorld[row][col] = '*';
            }
        }
    }
    return newWorld;
}

int countCells(const vector<string>& world, const int& row, const int& col) {
    int numOfAlive = 0;
    if (world[row][col+1] == '*') {numOfAlive += 1;} 

    if (world[row+1][col+1] == '*') {numOfAlive += 1;} 

    if (world[row+1][col] == '*') {numOfAlive += 1;} 

    if (world[row+1][col-1] == '*') {numOfAlive += 1;} 

    if (world[row][col-1] == '*') {numOfAlive += 1;}  

    if (world[row-1][col-1] == '*') {numOfAlive += 1;} 

    if (world[row-1][col] == '*') {numOfAlive += 1;}  

    if (world[row-1][col+1] == '*') {numOfAlive += 1;}

    return numOfAlive;
}

vector<string> openFile(const string& file) {
    ifstream worldFile(file);
    if (!worldFile) {
        cerr << "Could not open file.\n";
        exit(1);
    }

    vector<string> rows;
    rows.push_back("----------------------");
    string line;
    while (getline(worldFile, line)) {
        rows.push_back('-' + line + '-');
        cout << line << endl;
    }
    worldFile.close();
    rows.push_back("----------------------");
    return rows;
}

void displayWorld(const vector<string>& world) {
    for (int index = 1; index < world.size()-1; ++index){
        for (int index2 = 1; index2 < world[index].size()-1; ++index2) {
            cout << world[index][index2];
        }
        cout << endl;
    }
}