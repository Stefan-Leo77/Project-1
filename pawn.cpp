// File: pawn.cpp
// Author: Stefan Leonardo
// Date: 2/14/25
// A header file that establishes the Pawn class, which is a class of ChessPiece.

#include "Pawn.hpp"

/**
 * @brief Default Constructor. All boolean values are default initialized to false.
 * @note Remember to construct the base-class as well!
 */
Pawn::Pawn() : 
    ChessPiece(),
    double_jumpable_(false) {
    setSize(1);
    setType("PAWN");
}

/**
 * @brief Parameterized constructor.
 * @param : A const reference to the color of the Pawn (a string).
 *     Set the color "BLACK" if the provided string contains non-alphabetic characters (eg. numbers or symbols). 
 *     If the string is purely alphabetic, it is converted and stored in uppercase.
 *     NOTE: We do not supply a default value for color, the first parameter.
 *           Notice that if we do, we override the default constructor.
 * @param : The 0-indexed row position of the Pawn (as a const reference to an integer).
 *          Default value -1 if not provided, or if the value provided is outside the
 *          board's dimensions, [0, BOARD_LENGTH)
 * @param : The 0-indexed column position of the Pawn (as a const reference to an integer).
 *          Default value -1 if not provided, or if the value provided is outside the
 *          board's dimensions, [0, BOARD_LENGTH)
 * @param : A flag indicating whether the Pawn is moving up on the board, or not (as a const reference to a boolean).
 *          Default value false if not provided.
 * @param : A flag indicating whether the Pawn can double jump two spaces forward or not (as a const reference to a boolean).
 *          Default value false if not provided.
 * @post : The private members are set to the values of the corresponding parameters. 
 *   If the provided color parameter is invalid (ie. not alphabetic), it is set to "BLACK"
 *   If EITHER of the provided row or col are out-of-bounds,
 *      that is between 0 (inclusive) and BOARD_LENGTH (not inclusive),
 *      then BOTH are set to -1 (regardless of being in-bounds or not).
 * @note Remember to construct the base-class as well using these parameters!
 */
       /**
        * Parameterized constructor.
        * NOTE: All previous parameters & post conditions still apply.
        *
        * ADDITIONS: 
        * 1) The piece_size_ member is set to 1
        * 2) The type member is set to "PAWN"
        */

Pawn::Pawn(const std::string& color, 
    const int& row, 
    const int& col,
    const bool& isMovingUp, 
    const bool& canDoubleJump) :
    ChessPiece(color, row, col, isMovingUp), 
    double_jumpable_(canDoubleJump) {
    setSize(1);
    setType("PAWN");
}

/**
 * @brief Gets the value of the flag for the Pawn can double jump
 * @return The boolean value stored in double_jumpable_
 */
bool Pawn::canDoubleJump() const {
    return double_jumpable_;
}

/**
 * @brief Toggles the double_jumpable_ flag of the Pawn
 * @post Sets the double_jumpable_ flag to opposite its current value
 */
void Pawn::toggleDoubleJump() {
    double_jumpable_ = !double_jumpable_;
}

/**
 * @brief Determines if this pawn can be promoted to another piece
 *     A pawn can be promoted if its row has reached the farthest row it can move up (or down) to.
 *     This is determined by the board size and the Piece's movingUp_ member.
 * @return True if this pawn can be promoted. False otherwise.
 */
bool Pawn::canPromote() const {
    int row = getRow();
    if (isMovingUp()) {
        if(row == BOARD_LENGTH - 1){ // if moving up and reach end of board return true
            return true;}} 

    else if(row == 0){ // if at last row moving down return true
            return true;}
    return false; // if not at last or top row return false
}
