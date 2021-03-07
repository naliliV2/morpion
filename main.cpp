/* 
Author : nalili
Contact me : nalili0000007@gmail.com

Version : 1.0
Last release : 07/03/2021
*/

#include <iostream>
#include <array>
#include <string>

std::array<std::string, 9> define_grid() {
    //Create a grid
    std::array<std::string, 9> grid {"1", "2", "3", "4", "5", "6", "7", "8", "9"}; // X (player 1) | O (player 2)
    return grid;
}

void print_grid(std::array<std::string, 9> grid, int player) {
    //Print the grid of morpion 
    std::cout << "This is a player " << player << " to play" << std::endl; 
    std::string const separation = "|-----------------|";
    
    std::cout << separation << std::endl << "|  " << grid[0] << "  |  " << grid[1] << "  |  " << grid[2] << "  | " << std::endl; 
    std::cout << separation << std::endl << "|  " << grid[3] << "  |  " << grid[4] << "  |  " << grid[5] << "  | " << std::endl;
    std::cout << separation << std::endl << "|  " << grid[6] << "  |  " << grid[7] << "  |  " << grid[8] << "  | " << std::endl;
    std::cout << separation << std::endl;
}

int count(const std::array<std::string, 9> list, const std::string val) { 
    const int size_list = std::size(list); 
    int count = 0;

    for (int i = 0; i < size_list; i++) {
        if (list[i] == val) {
            ++count;
        }
    }
    return count;
}

int verify_win(std::array<std::string, 9> grid) {
    //Verify if a player win the game
    for (int i=0; i < 9; i = i + 3) { 
        if ((grid[i] == "X") && (grid[i+1] == "X" ) && (grid[i+2] == "X")) // Honrizontal
            return 1; 
        else if ((grid[i] == "O") && (grid[i+1] == "O" ) && (grid[i+2] == "O"))
            return 2; 
    }

    for (int i=0; i < 3; ++i) {
        if ((grid[i] == "X") && (grid[i+3] == "X" ) && (grid[i+6] == "X"))  // Vertical 
            return 1;
        else if ((grid[i] == "O") && (grid[i+3] == "O" ) && (grid[i+6] == "O"))
            return 2;
    }

    if ((grid[0] == "X" && grid[4] == "X" && grid[8] == "X") || (grid[2] == "X" && grid[4] == "X" && grid[6] == "X")) // Diagonal 
        return 1;
    else if ((grid[0] == "O" && grid[4] == "O" && grid[8] == "O") || (grid[2] == "O" && grid[4] == "O" && grid[6] == "O"))
        return 2;
    else {
        int count_grid;
        count_grid = count(grid, "X");
        count_grid += count(grid, "O");
        if (count_grid == 9)
            return 3;
        else
            return 0; 
    }
}

int main() {
    while (true) {
        int player = 1; 
        std::array<std::string, 9> grid {define_grid()};
        std::string awser = "";
        
        while (true) {
            print_grid(grid, player);
            
            int move;
            std::cout << "What case do you want to take?" << std::endl; 
            
            while (true) {
                while (!(std::cin >> move)) {
                    std::cout << "Enter invalid, please put a correct value" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(255, '\n');
                }
                
                if (grid[move-1] == "X" || grid[move-1] == "O")
                    std::cout << "This case is already taken" << std::endl;
                else 
                    break;
            } std::cout << std::endl;
            
            if (player == 1) {
                grid[move-1] = "X";
                ++player;
            } else if (player == 2) {
                grid[move-1] = "O";
                --player;
            }
        
            int result;
            result = verify_win(grid);

            if (!(result == 0)) {
                if (result == 3) {
                    std::cout << "Draw";
                    break;
                }
                std::cout << "The player " << result << " win" << std::endl << std::endl;  
                break;
            }
        }
        while (true) {            
            std::cout << "Do you want to play again? (Y/N)" << std::endl;
            std::cin >> awser;
            if (awser == "Y" || awser == "N")
                break;
            else
                std::cout << "Enter invalid, please put a correct value" << std::endl;    
        }
        
        if (awser == "Y") {
            continue;
            std::cout << std::endl;
        } else if (awser == "N") 
            break;
    }        
    return 0;
}   
