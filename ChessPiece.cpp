// File: ChessPiece.cpp
// Author: Stefan Leonardo
// Date: 2/14/25
// Implementation of the ChessPiece class

#include "ChessPiece.hpp"
#include <iostream>
#include <cctype>
#include <algorithm>

/**
 * @brief Default Constructor : All values 
 * Default-initializes all private members.  
 * Booleans are default-initialized to False. 
 * Default color : "BLACK"
 * Default row & columns: -1 (ie. represents that it has not been put on the board yet)
 */

ChessPiece::ChessPiece() : 
    color_("BLACK"), 
    row_(-1), 
    column_(-1), 
    movingUp_(false), 
    piece_size_(0), // NEW PIECE SIZE PARAMETER
    string_type_("NONE"){} // NEW PIECE STRING PARAMETER

/**
* @brief Parameterized constructor.
* @param : A const reference to the color of the Chess Piece (a string). 
*          Set the color "BLACK" if the provided string contains 
*          non-alphabetic characters. If the string is purely alphabetic, 
*          it is converted and stored in uppercase.
*
* @param : The 0-indexed row position of the Chess Piece (as a const 
*          reference to an integer). Default value -1 if not provided, 
*          or if the value provided is outside the board's dimensions, 
*          [0, BOARD_LENGTH).
*
* @param : The 0-indexed column position of the Chess Piece (as a const 
*          reference to an integer). Default value -1 if not provided, 
*          or if the value provided is outside the board's dimensions, 
*          [0, BOARD_LENGTH).
*
* @param : A flag indicating whether the Chess Piece is moving up on the 
*          board, or not (as a const reference to a boolean). Default 
*          value false if not provided.

* ADDITIONS:
* @param : An integer representing the size of the current chess piece. 
*          Default value 0.
* @param : A string representing the type of the current chess piece. 
*          Default value "NONE".
*
*/

 ChessPiece::ChessPiece(const std::string& color, const int& row, const int& col, const bool& isMovingUp, int size, const std::string& type) : 
 
 movingUp_(isMovingUp) // Initialize movingUp_ with the provided parameter
 piece_size_(size) // Initialize piece_size_ with the provided parameter
 type_(type)  // Initialize type_ with the provided parameter

 { 
 bool isAlpha = std::all_of(color.begin(), color.end(), ::isalpha); // Check if string contains only alphabetic characters
 if (!isAlpha) {
     color_ = "BLACK"; } 
 else {
     // Convert the valid color to uppercase and assign it to color_
     color_ = color;
     std::transform(color_.begin(), color_.end(), color_.begin(), ::toupper);
 }

 // Set position, checking bounds
 if (row >= 0 && row < BOARD_LENGTH && col >= 0 && col < BOARD_LENGTH) { //If the row and col are greater than -1 and less then BOARD_LENGTH
     row_ = row;       // If true set to row/col
     column_ = col; }
 else {
     row_ = -1;        // If false set row/col to -1
     column_ = -1;     
}
 
}

/**
 * @brief Gets the color of the chess piece.
 * @return std::string - The value stored in color_
 */
std::string ChessPiece::getColor() const {
    return color_;
}

/**
 * @brief Sets the color of the chess piece.
 * @param color A const string reference, representing the color to set the piece to. 
 *     If the string contains non-alphabetic characters, the value is not set (ie. nothing happens)
 *     If the string is alphabetic, then all characters are converted and stored in uppercase
 * @post The color_ member variable is updated to the parameter value in uppercase
 * @return True if the color was set. False otherwise.
 */

bool ChessPiece::setColor(const std::string& color) {

bool isAlpha = std::all_of(color.begin(), color.end(), ::isalpha); // Check if string contains only alphabetic characters to set to black
if (!isAlpha) {
    color_ = "BLACK"; 
    return false;
} 

else {
    // Convert the valid color to uppercase and assign it to color_
    color_ = color;
    std::transform(color_.begin(), color_.end(), color_.begin(), ::toupper);
    return true;
}

}


/**
 * @brief Gets the row position of the chess piece.
 * @return The integer value stored in row_
 */
int ChessPiece::getRow() const {
    return row_;
}

/**
 * @brief Sets the row position of the chess piece 
 * @param row A const reference to an integer representing the new row of the piece
 * @post If the supplied value is outside the board dimensions [0, BOARD_LENGTH), 
 *       the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
 */

void ChessPiece::setRow(const int& row) {

    if (row >= 0 && row < BOARD_LENGTH) //If the row is greater than -1 and less then BOARD_LENGTH
        row_ = row;       // If true set row
    else {
        row_ = -1;        // If false set row/col to -1
        column_ = -1;     
    }
}

/**
 * @brief Gets the column position of the chess piece.
 * @return The integer value stored in column_
 */
int ChessPiece::getColumn() const {
    return column_;
}

/**
 * @brief Sets the column position of the chess piece 
 * @param row A const reference to an integer representing the new column of the piece
 * @post If the supplied value is outside the board dimensions [0, BOARD_LENGTH),
 *       the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
 */
void ChessPiece::setColumn(const int& col) {

    if (col >= 0 && col < BOARD_LENGTH) //If the col is greater than -1 and less then BOARD_LENGTH
        column_ = col;       // If true set col
    else {
        row_ = -1;        // If false set row/col to -1
        column_ = -1;     
    }
}

/**
 * @brief Gets the value of the flag for if a chess piece is moving up
 * @return The boolean value stored in movingUp_
 */

bool ChessPiece::isMovingUp() const {
    return movingUp_;
}

/**
 * @brief Sets the movingUp flag of the chess piece 
 * @param flag A const reference to an boolean representing whether the piece is now moving up or not
 */
void ChessPiece::setMovingUp(const bool& flag) {
    movingUp_ = flag;
}



/////////////////////////////// PROJECT 2 NEW ADDITIONS /////////////////////////////////


/**
 * @brief Sets the size of the chess piece.
 * @param size An integer representing the new size of the chess piece.
 * @note This method does not validate pre-conditions 
 *       (e.g., checking for negative sizes).
 * @post The size_ member of the ChessPiece is overridden. No value is returned.
 */

 int ChessPiece::size() const {
    return piece_size_;
}


/**
* @brief Getter for the type_ data member
* @return The string value stored in type_
*/


std::string ChessPiece::getType() const {
    return type_;
}

/**
* @brief Getter for the piece_size_ data member
* @return The integer value stored in piece_size_
*/

void ChessPiece::setSize(int size) {
    piece_size_ = size;
}

/**
 * @brief Sets the type of the chess piece.
 * @param type A const reference to a string representing the new type of the chess piece 
 *      (e.g., "ROOK", "PAWN", "NONE").
 * @note This method does not validate pre-conditions 
 *      (e.g., checking for caps or symbols in the type string).
 * @post The type_ member of the ChessPiece is overridden. No value is returned.
 */
void ChessPiece::setType(const std::string& type) {
    type_ = type;
}

// DISPLAY FUNCTION

/**
 * @brief Displays the chess piece's information in the following format,
 *        if it is considered on the board (ie. its row and col are not -1):
 * <COLOR> piece at (row, col) is moving <UP / DOWN>\n
 * 
 * Otherwise an alternative format is used:
 * <COLOR> piece is not on the board\n
 */
void ChessPiece::display() const {
    if (row_ != -1 && column_ != -1) { // If piece has a space on board (not == -1)
        std::cout << color_ << " piece at (" << row_ << "," << column_ << ") is moving " << (movingUp_ ? "UP" : "DOWN") << std::endl;
    } else {
        std::cout << color_ << " piece is not on the board" << std::endl;
    }
}