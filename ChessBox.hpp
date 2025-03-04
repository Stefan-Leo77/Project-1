#ifndef CHESS_BOX_HPP_
#define CHESS_BOX_HPP_

#include "ArrayBox.hpp"
#include "ChessPiece.hpp"
#include <string>

class ChessBox {
    private:
        std::string P1_COLOR_;           // Color for Player 1
        std::string P2_COLOR_;           // Color for Player 2
        ArrayBox<ChessPiece> P1_BOX_;    // Box for Player 1's pieces
        ArrayBox<ChessPiece> P2_BOX_;    // Box for Player 2's pieces
        
    public:
        /**
         * Default constructor
         * @post 
         *  1) Default initializes P1_COLOR_ to "BLACK" and P2_COLOR_ to "WHITE"
         *  2) Initializes ArrayBox members with capacity 64
         */
        ChessBox();

        /**
         * Parameterized Constructor
         * @param color1 A const reference to the color of the ChessPiece (a string)
         * @param color2 A const reference to the color of the ChessPiece (a string)
         * 
         * @param capacity An integer describing the capacity of each player's ArrayBox, 
         *                 with default capacity 64.
         * 
         * @note If either color1 or color2 contains non-alphabetic characters, 
         *          set P1_COLOR_ to "BLACK" and P2_COLOR_ to "WHITE"
         *       
         *       If both strings are thus purely alphabetic, 
         *          they are transformed and stored in uppercase.
         *       Now, if the provided colors are equal, set color1 to "BLACK" and color2 to "WHITE"
         *
         *       If the specified capacity is not positive (ie. <= 0) or not provided, 
         *          64 is used instead.
         * 
         * @post Initializes ArrayBox members with the specified capacity. 
         *       All strings are initialized as described above. 
         */
        ChessBox(const std::string& color1, const std::string& color2, int capacity = 64);

        /**
         * @brief Getter for P1_Color
         * @return The string value stored in P1_COLOR
         */
        std::string getP1Color() const;

        /**
         * @brief Getter for P2_Color
         * @return The string value stored in P2_COLOR
         */
        std::string getP2Color() const;

        /**
         * @brief Getter for P1_BOX
         * @return The ArrayBox<ChessPiece> (ie. the value) of P1_BOX_
         */
        ArrayBox<ChessPiece> getP1Pieces() const;

        /**
         * @brief Getter for P2_BOX
         * @return The ArrayBox<ChessPiece> (ie. the value) of P2_BOX_
         */
        ArrayBox<ChessPiece> getP2Pieces() const;

        /**
         * @brief Adds a given ChessPiece object to the ArrayBox corresponding to its color:
         *      - If the color of the given piece matches P1_COLOR_, add it to P1_BOX_
         *      - If the color of the given piece matches P2_COLOR_, add it to P2_BOX_
         *      - If the color does not match either box, or the corresponding box doesn't have
         *           enough remaining space to add the piece, the add operation fails.
         * 
         * @param piece A const reference to a ChessPiece object 
         *              that is to be added to one of the ArrayBoxes
         * 
         * @return True if the piece was added successfully. False otherwise.
         */
        bool addPiece(const ChessPiece& piece);

        /**
         * @brief Removes a ChessPiece of the given type 
         *        if one exists in the ArrayBox corresponding to the given color
         * 
         * @param type A const reference to an uppercase string 
         *             representing the type of the ChessPiece to remove
         * @param color A const referene to an uppercase string 
         *             representing the color of the ChessPiece to remove
         * 
         * @return True if a piece is found and removed. False otherwise. 
         * @note Since we require `type` and `color` to be uppercase, you need not transform it.
         */
        bool removePiece(const std::string& type, const std::string& color);

        /**
         * @brief Determines whether a ChessPiece of the given type 
         *        exists within the ArrayBox corresponding to the given color
         * 
         * @param type A const reference to an uppercase string 
         *             representing the type of the ChessPiece to find
         * @param color A const referene to an uppercase string 
         *              representing the color of the ChessPiece to find
         * 
         * @return True if a piece is contained within the correct ArrayBox. False otherwise. 
         * @note Since we require `type` and `color` to be uppercase, you need not transform it.
         */
        bool contains(const std::string& type, const std::string& color) const;
};

#endif // CHESS_BOX_HPP_