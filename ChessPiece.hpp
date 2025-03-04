// File: ChessPiece.hpp
// Author: Stefan Leonardo
// Date: 2/14/25
// A header file that defines the parent class/parameters ChessPiece

#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP

#include <string>

class ChessPiece {

private:
    std::string color_;  
    int row_;           
    int column_;        
    bool movingUp_;     
    int piece_size_;    // An integer representing the size of the current chess piece
    std::string type_;  // A string representing the type of the current chess piece


protected:
    static const int BOARD_LENGTH = 8; 

        /**
         * @brief Sets the size of the chess piece.
         * @param size An integer representing the new size of the chess piece.
         * @note This method does not validate pre-conditions 
         *       (e.g., checking for negative sizes).
         * @post The size_ member of the ChessPiece is overridden. No value is returned.
         */
        void setSize(int size);

        /**
         * @brief Sets the type of the chess piece.
         * @param type A const reference to a string representing the new type of the chess piece 
         *      (e.g., "ROOK", "PAWN", "NONE").
         * @note This method does not validate pre-conditions 
         *      (e.g., checking for caps or symbols in the type string).
         * @post The type_ member of the ChessPiece is overridden. No value is returned.
         */
        void setType(const std::string& type);

        
public:
/**
* @brief Default Constructor : All values 
* Default-initializes all private members.  
* Booleans are default-initialized to False. 
* Default color : "BLACK"
* Default row & columns: -1 (ie. represents that it has not been put on the board yet)
* Default piece_size: 0
* Default type: "NONE"
*/
    ChessPiece();

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
    ChessPiece(const std::string& color, 
        const int& row = -1, 
        const int& col = -1, 
        const bool& isMovingUp = false,
        const int& pieceSize = 0, // NEW PIECE SIZE PARAMETER
        const std::string& type = "NONE"); // NEW PIECE STRING PARAMETER


////////// Accessors and Mutators //////////


    /**
     * @brief Gets the color of the chess piece.
     * @return std::string - The value stored in color_
     */
    std::string getColor() const;

    /**
     * @brief Sets the color of the chess piece.
     * @param color A const string reference, representing the color to set the piece to. 
     *     If the string contains non-alphabetic characters, the value is not set (ie. nothing happens)
     *     If the string is alphabetic, then all characters are converted and stored in uppercase
     * @post The color_ member variable is updated to the parameter value in uppercase
     * @return True if the color was set. False otherwise.
     */
    bool setColor(const std::string& color);

    /**
     * @brief Gets the row position of the chess piece.
     * @return The integer value stored in row_
     */
    int getRow() const;

    /**
     * @brief Sets the row position of the chess piece 
     * @param row A const reference to an integer representing the new row of the piece
     * @post If the supplied value is outside the board dimensions [0, BOARD_LENGTH), 
     *       the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
     */
    void setRow(const int& row);

    /**
     * @brief Gets the column position of the chess piece.
     * @return The integer value stored in column_
     */
    int getColumn() const;

    /**
     * @brief Sets the column position of the chess piece 
     * @param row A const reference to an integer representing the new column of the piece
     * @post If the supplied value is outside the board dimensions [0, BOARD_LENGTH),
     *       the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
     */
    void setColumn(const int& col);

    /**
     * @brief Gets the value of the flag for if a chess piece is moving up
     * @return The boolean value stored in movingUp_
     */
    bool isMovingUp() const;

    /**
     * @brief Sets the movingUp flag of the chess piece 
     * @param flag A const reference to an boolean representing whether the piece is now moving up or not
     */
    void setMovingUp(const bool& flag);


    /**
    * @brief Getter for the piece_size_ data member
    * @return The integer value stored in piece_size_
    */
    int size() const;

    /**
    * @brief Getter for the type_ data member
    * @return The string value stored in type_
    */
    std::string getType() const;

    /**
     * @brief Displays the chess piece's information in the following format,
     *        if it is considered on the board (ie. its row and col are not -1):
     * <COLOR> piece at (row, col) is moving <UP / DOWN>\n
     * 
     * Otherwise an alternative format is used:
     * <COLOR> piece is not on the board\n
     * @note "\n" just means endline in this case. Please use "std::endl," don't print out the text "\n".
     * Example output 1:
     *   BLACK piece at (2,4) is moving UP
     * Example output 2:
     *   WHITE piece is not on the board
     */
    void display() const;
};

#endif
