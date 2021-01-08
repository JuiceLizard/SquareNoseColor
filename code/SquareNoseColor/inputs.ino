void inputs() {

// "start"
// 06-02-2020 change: doctor Meggan hand comes
// when you catch the meaty ring or blue target
/*
  if((gb.buttons.pressed(BUTTON_A)) && (level == 0)) {
     endOfTest = true;
  }
*/
// 06-02-2020 change: place this part after the inputs() updates() outputs()
// to avoid a level 0 screen during one frame after death
/*
// restart the game if you lose
  if((electricShock == true) && (gb.buttons.pressed(BUTTON_A))) {
        level = 0;
        gameLoop = 0;
        resetValues();
        frameCounter = 0;
        seconds = 0;
        minutes = 0;
        gameState = 1;
      }
*/

// Square Nose crouches
  if(SquareNoseIsJumping == false) {
    if(gb.buttons.repeat(BUTTON_DOWN, 0) && (electricShock == false)) {
      SquareNoseY = 30;
    } else {
      SquareNoseY = 28;
    }
  }

// move Lethal Mouse or Square Nose right and left
  if(playLethalMouse == true) {
    // Lethal Mouse: when pressing RIGHT or LEFT buttons
    if((handGoesDown == true) || (level == 3)) {
      if(SquareNoseIsJumping == false) {
        if(gb.buttons.repeat(BUTTON_RIGHT, 0) && (electricShock == false)) {
          SquareNoseGoesRight = true;
          if(SquareNoseX < (gb.display.width() - 10)) {
            LethalMouseMoves = true;
          }
        } else {
          if(gb.buttons.repeat(BUTTON_LEFT, 0) && (electricShock == false)) {
            SquareNoseGoesRight = false;
            if(SquareNoseX > 0) {
              LethalMouseMoves = true;
            }
          }
        }
      }

// Lethal Mouse stops or changes direction (if not in the air)
    if(SquareNoseIsJumping == false) {
      if(gb.buttons.repeat(BUTTON_DOWN, 0) && (electricShock == false)) {
        LethalMouseMoves = false;
      }
    }

// moves Lethal Mouse right and left when it is mad
      if(LethalMouseMoves == true) {
        if((electricShock == true) && ((madLethalMouse % 5) == 0) && (madLethalMouse != 0) && (SquareNoseIsJumping == false)) {
          if(SquareNoseGoesRight == true) {
            SquareNoseGoesRight = false;
          } else {
            SquareNoseGoesRight = true;
          }
        }
        if(SquareNoseGoesRight == true) {
          SquareNoseX += 3;
        } else {
          SquareNoseX -= 3;
        }
      }
    }

    if((electricShock == true) && (SquareNoseIsJumping == false)) {
      madLethalMouse = madLethalMouse + 1;
      if(madLethalMouse > 5) {
        madLethalMouse = 0;
      }
      LethalMouseMoves = true;
    }

// Lethal Mouse: stop when hitting a wall
    if((SquareNoseX < 1) || (SquareNoseX > 69)) {
      if(electricShock == false) {
        LethalMouseMoves = false;
      } else {
        if(SquareNoseIsJumping == false) {
          madLethalMouse = 0;
          if(SquareNoseGoesRight == true) {
            SquareNoseGoesRight = false;
          } else {
            SquareNoseGoesRight = true;
          }
          LethalMouseMoves = true;
        }
      }
    }

// Square Nose moves left and right
  } else {
    if((handGoesDown == true) || (level == 3)) {
      if((gb.buttons.repeat(BUTTON_RIGHT, 0)) && (SquareNoseX < (gb.display.width() - 10))) {
        SquareNoseX += 3;
        if(gb.buttons.repeat(BUTTON_DOWN, 0)) {
          SquareNoseX += 1;
        }
        SquareNoseGoesRight = true;
      } else {
        if((gb.buttons.repeat(BUTTON_LEFT, 0)) && (SquareNoseX > 0)) {
          SquareNoseX -= 3;
          if(gb.buttons.repeat(BUTTON_DOWN, 0)) {
            SquareNoseX -= 1;
          }
          SquareNoseGoesRight = false;
        }
      }
    }
  }
  
// Square Nose jump
// 06-02-2020 change: button A for jumping instead of B
  if((SquareNoseY == 28) && (gb.buttons.pressed(BUTTON_A)) && (electricShock == false)) {
    SquareNoseIsJumping = true;
    SquareNoseJumpSpeed = -6;
    if((electricShock == false) && (handGoesDown == true)) {
      gb.sound.playTick();
    }
  }
  if((gb.buttons.released(BUTTON_A)) && (SquareNoseJumpSpeed < 0)) {
    SquareNoseJumpSpeed /= 2;
  }
}
