#include "ChessPiece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include <iostream>

int main() {
    // Test basic ChessPiece functionality
    ChessPiece piece;
    piece.display();
    
    // Test Pawn functionality
    Pawn pawn("WHITE", 6, 3, true, true);
    pawn.display();
    std::cout << "Can double jump: " << (pawn.canDoubleJump() ? "yes" : "no") << std::endl;
    
    // Test Rook functionality
    Rook rook("BLACK", 0, 0);
    rook.display();
    std::cout << "Castle moves left: " << rook.getCastleMovesLeft() << std::endl;
    
    return 0;
}
