void inputs() {

// "start"
  if((gb.buttons.pressed(BUTTON_A)) && (level == 0)) {
     endOfTest = true;
  }

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

// Square Nose crouches
  if(SquareNoseIsJumping == false) {
    if(gb.buttons.repeat(BUTTON_DOWN, 0)) {
      SquareNoseY = 30;
    } else {
      SquareNoseY = 28;
    }
  }

// move Square Nose right and left
  if(handGoesDown == true) {
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
  
// Square Nose jump
  if((SquareNoseY == 28) && (gb.buttons.pressed(BUTTON_B))) {
    SquareNoseIsJumping = true;
    SquareNoseJumpSpeed = -6;
    if((electricShock == false) && (handGoesDown == true)) {
      gb.sound.playTick();
    }
  }
  if((gb.buttons.released(BUTTON_B)) && (SquareNoseJumpSpeed < 0)) {
    SquareNoseJumpSpeed /= 2;
  }
}
