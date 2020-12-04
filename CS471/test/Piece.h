#pragma once

using namespace std;

class Piece {
  private:
    string current[4][4];
    int rotation, x, y;
    char type;
  public:
    int getX();
    int getY();
    void tick();
    void createNewPiece();
    bool rotateLeft();
    bool rotateRight();
    void setInBoard(string[][12]);
};