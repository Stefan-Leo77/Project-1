// File: Rook.cpp
// Author: Stefan Leonardo
// Date: 2/14/25
// Implementation of the Rook class

#include "Rook.hpp"
#include <cmath>


/**
 * @brief Default Constructor. By default, Rooks have 3 available castle moves to make
 * @note Remember to default construct the base-class as well!
 */
        /**
         * Default Constructor.
         * NOTE: All previous post conditions still apply.
         * 
         * ADDITIONS: 
         * 1) The piece_size_ member is set to 2
         * 2) The type member is set to "ROOK"
         */
Rook::Rook() : 
    ChessPiece(),
    castle_moves_left_(3) {
    setSize(2);
    setType("ROOK");
}


/**
 * @brief Parameterized constructor.
 * @param : A const reference to the color of the Rook (a string).
 *     Set the color "BLACK" if the provided string contains non-alphabetic characters. 
 *     If the string is purely alphabetic, it is converted and stored in uppercase
 * @param : The 0-indexed row position of the Rook (as a const reference to an integer).
 *          Default value -1 if not provided, or if the value provided is outside the
 *          board's dimensions, [0, BOARD_LENGTH)
 * @param : The 0-indexed column position of the Rook (as a const reference to an integer).
 *          Default value -1 if not provided, or if the value provided is outside the
 *          board's dimensions, [0, BOARD_LENGTH)
 * @param : A flag indicating whether the Rook is moving up on the board, or not (as a const reference to a boolean).
 *          Default value false if not provided.
 * @param : An integer representing how many castle moves it can make.
 *          Default to 3 if no value provided. If a negative value is provided, 0 is used instead.
 * @post : The private members are set to the values of the corresponding parameters.
 */

        /**
        * Parameterized constructor.
        * NOTE: All previous parameters & post conditions still apply.
        *
        * ADDITIONS: 
        * 1) The piece_size_ member is set to 2
        * 2) The type member is set to "ROOK"
        */
Rook::Rook(const std::string& color, const int& row, const int& col, 
           const bool& isMovingUp, const int& castleMoves) 
    : ChessPiece(color, row, col, isMovingUp, 2, "ROOK")
    { 
    castle_moves_left_ = (castleMoves < 0) ? 0 : castleMoves;  // Validate castle moves - ensure non-negative
}

/**ChessPiece(color, row, col, isMovingUp), castle_moves_left_(castleMoves) , setSize(2), setType("ROOK") {} // if castleMoves is negative, set to 0, if 3 remains the same
brief Determines if this rook can castle with the parameter Chess Piece
 * \   This rook can castle with another piece if:
 *        1. It has more than 0 castle moves available
 *        2. Both pieces share the same color
 *        3. Both pieces are considered on-the-board (no -1 rows or columns)
 *           and laterally adjacent (ie. they share the same row and their columns differ by at most 1)
 * @param ChessPiece A const reference to chess piece with which the rook may / may not be able to castle with
 * @return True if the rook can castle with the given piece. False otherwise.
 */
bool Rook::canCastle(const ChessPiece& piece) const {
    // First check: Must have castle moves remaining
    if (castle_moves_left_ <= 0) {
        return false;
    }
    
    // Second check: Colors must match
    if (getColor() != piece.getColor()) {
        return false;
    }

    // Additional checks for valid castling would go here...
    // ... existing code ...
}

// ... rest of implementation ...
