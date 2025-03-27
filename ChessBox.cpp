#include "ChessBox.hpp"
#include "ArrayBox.hpp" // Include the ArrayBox header file
#include <cctype>
#include <algorithm>

// Helper function to check if a string contains only alphabetic characters
bool isAlphaString(const std::string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

// Helper function to convert a string to uppercase
std::string toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Default constructor
ChessBox::ChessBox() : P1_COLOR_("BLACK"), P2_COLOR_("WHITE"), P1_BOX_(64), P2_BOX_(64) {
}

// Parameterized constructor
ChessBox::ChessBox(const std::string& color1, const std::string& color2, int capacity) {
    // Check if the colors are alphabetic
    bool color1_alphabetic = isAlphaString(color1);
    bool color2_alphabetic = isAlphaString(color2);
    
    // Set the colors
    if (color1_alphabetic && color2_alphabetic) {
        P1_COLOR_ = toUpperCase(color1);
        P2_COLOR_ = toUpperCase(color2);
        
        // If the colors are equal, set to default
        if (P1_COLOR_ == P2_COLOR_) {
            P1_COLOR_ = "BLACK";
            P2_COLOR_ = "WHITE";
        }
    } else {
        P1_COLOR_ = "BLACK";
        P2_COLOR_ = "WHITE";
    }
    
    // Set the capacity
    if (capacity <= 0) {
        capacity = 64;
    }
    
    // Initialize LinkedBox members
    P1_BOX_ = LinkedBox<ChessPiece>(capacity);
    P2_BOX_ = LinkedBox<ChessPiece>(capacity);
}

// Getter for P1_COLOR
std::string ChessBox::getP1Color() const {
    return P1_COLOR_;
}

// Getter for P2_COLOR
std::string ChessBox::getP2Color() const {
    return P2_COLOR_;
}

/**
 * @brief Getter for P1_BOX
 * @return The LinkedBox<ChessPiece> (ie. the value) of P1_BOX_
 */
LinkedBox<ChessPiece> ChessBox::getP1Pieces() const {
    return P1_BOX_;
}

/**
 * @brief Getter for P2_BOX
 * @return The LinkedBox<ChessPiece> (ie. the value) of P2_BOX_
 */
LinkedBox<ChessPiece> ChessBox::getP2Pieces() const {
    return P2_BOX_;
}

/**
 * @brief Adds a given ChessPiece object to the LinkedBox corresponding to its color:
 *      - If the color of the given piece matches P1_COLOR_, add it to P1_BOX_
 *      - If the color of the given piece matches P2_COLOR_, add it to P2_BOX_
 *      - If the color does not match either box, or the corresponding 
 *           box doesn't have enough remaining space to add the piece, 
 *           the add operation fails.
 * 
 * @param piece A const reference to a ChessPiece object that is to be added to one of the LinkedBoxes
 * @return True if the piece was added successfully. False otherwise.
 *
 */
bool ChessBox::addPiece(const ChessPiece& piece) {
    // Get the color of the piece
    std::string piece_color = piece.getColor();
    
    // Add to the appropriate box
    if (piece_color == P1_COLOR_) {
        return P1_BOX_.addItem(piece);
    } else if (piece_color == P2_COLOR_) {
        return P2_BOX_.addItem(piece);
    }
    
    // If the color doesn't match either box
    return false;
}


/**
 * @brief Removes a ChessPiece of the given type if one 
 *        exists in the LinkedBox corresponding to the given color
 * 
 * @param type A const reference to an uppercase string 
 *             representing the type of the ChessPiece to remove
 * @param color A const referene to an uppercase string 
 *              representing the color of the ChessPiece to remove
 * @return True if a piece is found and removed. False otherwise. 
 */
// Remove a chess piece from the appropriate box
bool ChessBox::removePiece(const std::string& type, const std::string& color) {
    // Remove from the appropriate box
    if (color == P1_COLOR_) {
        return P1_BOX_.remove(type);
    } else if (color == P2_COLOR_) {
        return P2_BOX_.remove(type);
    }
    
    // If the color doesn't match either box
    return false;
}

/**
 * @brief Finds whether a ChessPiece of the given type exists within the LinkedBox corresponding to the given color
 * 
 * @param type A const reference to an uppercase string 
 *             representing the type of the ChessPiece to find
 * @param color A const referene to an uppercase string 
 *             representing the color of the ChessPiece to find
 * @return True if a piece is contained within the correct LinkedBox. False otherwise. 
 */
// Check if a chess piece exists in the appropriate box
bool ChessBox::contains(const std::string& type, const std::string& color) const {
    // Check the appropriate box
    if (color == P1_COLOR_) {
        return P1_BOX_.contains(type);
    } else if (color == P2_COLOR_) {
        return P2_BOX_.contains(type);
    }
    
    // If the color doesn't match either box
    return false;
}