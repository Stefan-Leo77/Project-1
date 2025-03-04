#include "ChessPiece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "ChessBox.hpp"
#include <iostream>

// Helper function to print test results
void printTestResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Test ChessPiece class functionality
void testChessPiece() {
    std::cout << "\n=== Testing ChessPiece Class ===\n";

    // Test default constructor
    ChessPiece piece1;
    printTestResult("Default Constructor Color", piece1.getColor() == "BLACK");
    printTestResult("Default Constructor Position", piece1.getRow() == -1 && piece1.getColumn() == -1);
    
    // Test parameterized constructor
    ChessPiece piece2("WhItE", 3, 4, true);
    printTestResult("Parameterized Constructor Color", piece2.getColor() == "WHITE");
    printTestResult("Parameterized Constructor Position", piece2.getRow() == 3 && piece2.getColumn() == 4);
    
    // Test invalid inputs
    ChessPiece piece3("Wh1te", 8, 4, true);  // Invalid color and position
    printTestResult("Invalid Color Handling", piece3.getColor() == "BLACK");
    printTestResult("Invalid Position Handling", piece3.getRow() == -1 && piece3.getColumn() == -1);
}

// Test Pawn class functionality
void testPawn() {
    std::cout << "\n=== Testing Pawn Class ===\n";
    
    // Test default constructor
    Pawn pawn1;
    printTestResult("Default Pawn Type", pawn1.getType() == "PAWN");
    printTestResult("Default Pawn Size", pawn1.size() == 1);
    
    // Test parameterized constructor
    Pawn pawn2("WHITE", 6, 3, true, true);
    printTestResult("Pawn Double Jump Initial", pawn2.canDoubleJump() == true);
    
    // Test promotion logic
    Pawn pawn3("BLACK", 7, 3, true);
    printTestResult("Pawn Promotion Test", pawn3.canPromote() == true);
}

// Test Rook class functionality
void testRook() {
    std::cout << "\n=== Testing Rook Class ===\n";
    
    // Test default constructor
    Rook rook1;
    printTestResult("Default Rook Type", rook1.getType() == "ROOK");
    printTestResult("Default Rook Size", rook1.size() == 2);
    
    // Test parameterized constructor
    Rook rook2("WHITE", 0, 0, false, 3);
    printTestResult("Rook Castle Moves", rook2.getCastleMovesLeft() == 3);
    
    // Test castling
    Rook rook3("WHITE", 0, 0, false);
    ChessPiece adjacent("WHITE", 0, 1, false);
    printTestResult("Valid Castle Test", rook3.canCastle(adjacent) == true);
}

// Test ArrayBox functionality
void testArrayBox() {
    std::cout << "\n=== Testing ArrayBox Class ===\n";
    
    ArrayBox<ChessPiece> box(8);
    Pawn pawn("WHITE", 1, 1);
    Rook rook("BLACK", 0, 0);
    
    printTestResult("Initial Box Empty", box.size() == 0);
    box.addItem(pawn);
    printTestResult("Add Pawn", box.size() == 1);
    box.addItem(rook);
    printTestResult("Add Rook", box.size() == 3);  // Size increases by 2 due to Rook's size
    
    printTestResult("Contains Pawn", box.contains("PAWN") == true);
    printTestResult("Contains Rook", box.contains("ROOK") == true);
}

// Test ChessBox functionality
void testChessBox() {
    std::cout << "\n=== Testing ChessBox Class ===\n";
    
    ChessBox box("WHITE", "BLACK");
    Pawn whitePawn("WHITE", 1, 1);
    Rook blackRook("BLACK", 0, 0);
    
    printTestResult("Add White Pawn", box.addPiece(whitePawn) == true);
    printTestResult("Add Black Rook", box.addPiece(blackRook) == true);
    
    printTestResult("Contains White Pawn", box.contains("PAWN", "WHITE") == true);
    printTestResult("Contains Black Rook", box.contains("ROOK", "BLACK") == true);
    
    printTestResult("Remove White Pawn", box.removePiece("PAWN", "WHITE") == true);
    printTestResult("Pawn Removed Check", box.contains("PAWN", "WHITE") == false);
}

int main() {
    std::cout << "Starting Chess Project Tests\n";
    
    testChessPiece();
    testPawn();
    testRook();
    testArrayBox();
    testChessBox();
    
    std::cout << "\nAll tests completed.\n";
    return 0;
}
