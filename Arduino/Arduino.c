//MircroArcade EECS 183 2014 Showcase
//Breaker Breaker

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "stdlib.h"


class Board
{
public:
    
    //MODIFIES: the private member variables of Board
    //EFFECTS: initializes paddlePos and level to 0, initializes lives to 3, paddleHeight to 7, paused and ballLeft to true
    Board();
    
    //MODIFIES: nothing
    //EFFECTS: returns paddlePos
    int getPaddlePos();
    
    //MODIFIES: paddlePos
    //EFFECTS: sets the paddle position to input
    void setPaddlePos(int input);
    
    //MODIFIES: nothing
    //EFFECTS: returns lives
    int getLives();
    
    //MODIFIES: lives
    //EFFECTS: sets the lives to input
    void setLives(int input);
    
    //MODIFIES: nothing
    //EFFECTS: returns level
    int getLevel();
    
    //MODIFIES: level
    //EFFECTS: sets the level to input
    void setLevel(int input);
    
    //MODIFIES: nothing
    //EFFECTS: returns ballRow
    int getBallRow();
    
    //MODIFIES: ballRow
    //EFFECTS: sets the row of the ball to input
    void setBallRow(int input);
    
    //MODIFIES: nothing
    //EFFECTS: returns ballCol
    int getBallCol();
    
    //MODIFIES: ballCol
    //EFFECTS: sets the column of the ball to input
    void setBallCol(int input);
    
    //MODIFIES: nothing
    //EFFECTS: returns ballLeft
    boolean getBallLeft();
    
    //MODIFIES: ballLeft
    //EFFECTS: sets ballLeft to input
    void setBallLeft(boolean input);
    
    //MODIFIES: nothing
    //EFFECTS: returns ballRight
    boolean getBallRight();
    
    //MODIFIES: ballRight
    //EFFECTS: sets ballRight to input
    void setBallRight(boolean input);
    
    //MODIFIES: nothing
    //EFFECTS: returns ballDown
    boolean getBallDown();
    
    //MODIFIES: ballDown
    //EFFECTS: sets ballDown to input
    void setBallDown(boolean input);
    
    //MODIFIES:nothing
    //EFFECTS: returns paddleHeight
    int getPaddleHeight();
    
    //MODIFIES:paused
    //EFFECTS: sets paused to false
    void resetPause();
    
    //MODIFIES:paused
    //EFFETCS: sets paused to true
    void setPause();
    
    //MODIFIES: nothing
    //EFFETCS: returns paused
    boolean getPaused();
    
    //MODIFIES: strength array, ballRow, ballCol, BallRight, ballDown
    //EFFECTS: first sets up the ball so that it is on top of the paddle
    // on the left pixel with initial direction to the left and up. Next
    //sets up the board according to which level the game is on.
    void initBoard();
    
    //EFFECTS:Displays the pixels with strength>0 on the board
    void displayBlocks();
    
    //MODIFIES: ballRow and ballCol
    //EFFECTS: updates the balls position based on what direction the ball
    //is traveling. Be careful to not let the ball go off the board!
    void updateBall();
    
    //MODIFIES: nothing
    //EFFECTS: returns true if the ball goes off the board when the player
    //fails to hit it with the paddle
    boolean lostBall();
    
    //MODIFIES:ballDown, ballRight, ballLeft
    //EFFECTS: changes the ball's direction if the ball hits the top or sides of the board
    void hitWall();
    
    //MODIFIES:ballDown, ballRight, ballLeft
    //EFFECTS:changes the direction of the ball depending on which direction the ball was traveling
    //when it hits the paddle
    void hitPaddle( );
    
    //MODIFIES:ballDown, ballRight, ballLeft, strength array
    //EFFECTS:changes the direction of the ball depending on which direction the ball was traveling
    //when it hits a block. Decrements the strength of the block.
    void hitBlock();
    
    //MODIFIES: nothing
    //EFFECTS: returns true if all blocks are destroyed, false otherwise
    boolean levelComplete();
    
    //MODIFIES:strength array
    //EFFECTS: sets all strengths to 0
    void initStrength();
    
    
private:
    
    int strength[8][16];          //The strengths of blocks on the board
    int paddlePos;		//Leftmost position of the paddle
    int paddleHeight;	        // height of the upper paddle
    int lives;			//Number of lives left
    int level;			//Current level
    int ballRow;			//Row of the ball
    int ballCol;			//Column of the ball
    boolean ballLeft;		//If ballleft == TRUE, ball is moving left
    boolean ballRight;		//If ballRight == TRUE, ball is moving right.
    boolean ballDown;		//If ballDown == TRUE, ball is moving down.  Otherwise, ball is moving up
    boolean paused;		// Pause after ball loss
    
};

//sets up the LED board with the correct parameters
Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

//EFFECTS:turns off all the pixels on the board
void clearBoard();

//REQUIRES:  val is the value of the potentiometer
//MODIFIES: nothing
//EFFECTS: returns the column position of the left pixel of the paddle
int calculatePaddlePosition(int val);


//EFFECTS:displays the number of lives remaining/level number on the board. If it doesn't all fit
//on the board at once, the text scrolls.
//use text size 1 and delay of 50
void printMessage(int number);

//EFFECTS:displays string text needed(suchs as "LIVES" or "LEVEL") on the board. If it
//doesn't all fit on the board at once, the text scrolls.
//use text size 1 and delay of 50
void printMessage(String message);

//contains data about pin assignments and values
struct Pins
{
    int potPin; 	        //input pin potentiometer
    int val;		//value of the potentiometer
    int button;		//input pin for the button
    int buttonState;      // current state of the button
    
};

void(* resetFunc) (void) = 0; //declare reset function @ address 0

//EFFECTS:displays "GameOver" on the board and resets the game. This function
//is implemented for you.
void gameOver(){
    printMessage("GameOver");
    delay(3000);
    resetFunc();
}

//DO NOT MODIFY ANY CODE ABOVE THIS LINE.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup()
{
    //set up the board, button, and potentiometer in preparation for the start of the game. All pixels should be off,
    //strengths should be 0. Display number of lives at beginning of game
    
    //YOUR CODE GOES HERE
    
}


void loop()
{
    //everything needed for the game to play goes here
    
    //YOUR CODE GOES HERE
    
    matrix.writeDisplay(); //display all changes made in one iteration of loop
    delay(150); //to slow it down and make it easier to debug. also makes the paddle lag       	
}

//WRITE YOUR FUNCTION IMPLEMENTATIONS BELOW 

Board();
int getPaddlePos();
void setPaddlePos(int input);
int getLives();
void setLives(int input);
int getLevel();
void setLevel(int input);
int getBallRow();
void setBallRow(int input);
int getBallCol();
void setBallCol(int input);
boolean getBallLeft();
void setBallLeft(boolean input);
boolean getBallRight();
void setBallRight(boolean input);
boolean getBallDown();
void setBallDown(boolean input);
int getPaddleHeight();
void resetPause();
void setPause();
boolean getPaused();
void initBoard();
void displayBlocks();
void updateBall();
boolean lostBall();
void hitWall();
void hitPaddle( );
void hitBlock();
boolean levelComplete();
void initStrength();
















































