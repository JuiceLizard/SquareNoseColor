void updates() {
// timer
  if((level != 0) && (electricShock == false) && (endOfTest == false)) {
    frameCounter += 1;
    if(frameCounter > 24) {
      frameCounter = 0;
      seconds += 1;
    }
    if(seconds > 59) {
      seconds = 0;
      minutes += 1;
    }
    if((seconds == 8) && (minutes == 2)) {
      frameCounter = 0;
      seconds = 0;
      minutes = 0;
      gb.sound.playCancel();
      electricShock = true;
      electricX = SquareNoseX;
      electricY = SquareNoseY;
    }
  }

// stop Square Nose when hit a wall
  if(SquareNoseX < 1) {
    SquareNoseX = 0;
  }
  if(SquareNoseX > 69) {
    SquareNoseX = 70;
  }

// Square Nose jump
  if(SquareNoseIsJumping == true) {
    SquareNoseY += SquareNoseJumpSpeed;
    SquareNoseJumpCounter += 1;
    if((SquareNoseJumpCounter % 2) == 0) {
      SquareNoseJumpSpeed += 2;
    }
  }

// stop Square Nose falling when hit the ground
  if((SquareNoseY > 28) && (SquareNoseIsJumping == true)) {
    SquareNoseY = 28;
    SquareNoseIsJumping = false;
    SquareNoseJumpCounter = 0;
  }

// new meaty ring
  if(level != 0) {
    if(endOfTest == false) {
      if((gb.collide.rectRect(SquareNoseX + 1, SquareNoseY + 1, 8, 8, meatyRingX, meatyRingY, 8, 8)) && (electricShock == false)) {
        meatyRingX = random(gb.display.width() - 8);
        meatyRingY = random((gb.display.width() / 2) - 8);
        gb.sound.playOK();
        collectedMeatyRings += 1;
      }
    }
  }

// the appetence test is over when Square Nose has eaten 32 meaty rings
  if(collectedMeatyRings > 31) {
    endOfTest = true;
  }

// doctor Meggan arm vertical moves
  if(endOfTest == true) {
    if(handGoesDown) {
      handY += 1;
    } else {
      handY -= 1;
    }
  }
  
// when doctor Meggan hand catches Square Nose
  if(handY > (SquareNoseY - 4)) {
    handGoesDown = false;
  }

// doctor Meggan hand and Square Nose are out of screen and you go to next screen
  if(handY < -24) {
    gameState = 3;
    resetValues();
  }

  switch (level) {

    case 1:
// bird contact
      if((endOfTest == false) && (gb.collide.rectRect(SquareNoseX + 1, SquareNoseY + 1, 8, 8, birdX, BIRD_Y, 11, 8)) && (electricShock == false)) {
        electricShock = true;
        electricX = SquareNoseX;
        electricY = SquareNoseY;
        gb.sound.playCancel();
      }
    
// bird speed
      if(birdGoesRight == true) {
        birdX += 2;
      } else {
        birdX -= 2;
      }

// bird hits the wall
      if(birdX < 1) {
        birdGoesRight = true;
        birdX = 0;
      }

      if(birdX > (gb.display.width() - 12)) {
        birdGoesRight = false;
        birdX = (gb.display.width() - 11);
      }

// bug contact
      if((endOfTest == false) && (gb.collide.rectRect(SquareNoseX + 1, SquareNoseY + 1, 8, 8, bugX, BUG_Y, 9, 7)) && (electricShock == false)) {
        electricShock = true;
        electricX = SquareNoseX;
        electricY = SquareNoseY;
        gb.sound.playCancel();
      }
      
// bug speed
      if(bugGoesRight == true) {
        bugX += (1 + random(0, 2 + gameLoop));
      } else {
        bugX -= (1 + random(0, 2 + gameLoop));
      }

// bug hits the wall
      if(bugX < 1) {
        bugGoesRight = true;
        bugX = 0;
      }

      if(bugX > (gb.display.width() - 10)) {
        bugGoesRight = false;
        bugX = (gb.display.width() - 9);
      }
      break;

    case 2:
// frog contact
      if((endOfTest == false) && (gb.collide.rectRect(SquareNoseX + 1, SquareNoseY + 1, 8, 8, frogX, frogY, 12, 12)) && (electricShock == false)) {
        electricShock = true;
        electricX = SquareNoseX;
        electricY = SquareNoseY;
        gb.sound.playCancel();
      }

// frog jumps every two seconds in loop zero, every 1.5 seconds in loop 1 and always in loop 2
      switch(gameLoop) {
        case 0:
          if(((seconds % 2) == 0) && (frameCounter == 1)) {
            frogIsJumping = true;
          }
          break;
        case 1:
          if((((seconds % 3) == 0) && (frameCounter == 1)) || ((((seconds - 1) % 3) == 0) && (frameCounter == 13))) {
            frogIsJumping = true;
          }
          break;
        default:
          frogIsJumping = true;
          break;
        }

// frog horizontal moves (faster at loop 3 and the next ones)
      if(frogIsJumping == true) {
        if(frogGoesRight == true) {
          if(gameLoop > 2) {
            frogX += gameLoop;
          } else {
            frogX += 2;
          }
        } else {
          if(gameLoop > 2) {
            frogX -= gameLoop;
          } else {
            frogX -= 2;
          }
        }
      }

// frog direction changes when colide a wall
      if(frogX < 1) {
        frogGoesRight = true;
      }
      if(frogX > (gb.display.width() - 13)) {
        frogGoesRight = false;
      }

// frog jump
      if((frogY == 28) && (frogIsJumping == true)) {
        frogJumpSpeed = -4;
        gb.sound.playTick();
      }

      if(frogIsJumping == true) {
        frogY += frogJumpSpeed;
        frogJumpCounter += 1;
        if((frogJumpCounter % 4) == 0) {
          frogJumpSpeed += 2;
        }
      }

// stop frog falling when hit the ground
      if(frogY > 27) {
        frogY = 28;
        frogIsJumping = false;
        frogJumpCounter = 0;
        frogJumpSpeed = 0;
      }
      
      break;

    case 3:
// Squiddy contact
      if((endOfTest == false) && (gb.collide.rectRect(SquareNoseX + 1, SquareNoseY + 1, 8, 8, SquiddyX + 1, SquiddyY + 1, 8, 8)) && (electricShock == false)) {
        electricShock = true;
        electricX = SquareNoseX;
        electricY = SquareNoseY;
        gb.sound.playCancel();
      }

// Squiddy ball contact
      if((endOfTest == false) && (gb.collide.rectRect(SquareNoseX + 1, SquareNoseY + 1, 8, 8, SquiddyBallX + 1, SquiddyBallY + 1, 8, 8)) && (electricShock == false)) {
        electricShock = true;
        electricX = SquareNoseX;
        electricY = SquareNoseY;
        gb.sound.playCancel();
      }
      
// angle goes from 0 to 360
      angle -= 3 + gameLoop;
      if(angle < 0) {
        angle = 359;
      }

// Squiddy and its ball moves depending on each other
      if(SquiddySpins == true) {
        SquiddyX = SquiddyBallX + cos(angle * PI / 180) * 30;
        SquiddyY = SquiddyBallY + sin(angle * PI / 180) * 30;
      } else {
        SquiddyBallX = SquiddyX + cos(angle * PI / 180) * 30;
        SquiddyBallY = SquiddyY + sin(angle * PI / 180) * 30;
      }

// invert rotation center
      if((SquiddySpins == true) && ((SquiddyX < -1) || (SquiddyX > 71) || (SquiddyY < -1) || (SquiddyY > 31))) {
          SquiddySpins = false;
          angle += 180;
          gb.sound.playTick();

          if(SquiddyX < -1) {
            SquiddyX = 0;
          }
          if(SquiddyX > 71) {
            SquiddyX = 70;
          }
          if(SquiddyY < -1) {
            SquiddyY = 0;
          }
          if(SquiddyY > 31) {
            SquiddyY = 30;
          }
      } else {
          if((SquiddySpins == false) && ((SquiddyBallX < -1) || (SquiddyBallX > 71) || (SquiddyBallY < -1) || (SquiddyBallY > 31))) {
          SquiddySpins = true;
          angle += 180;
          gb.sound.playTick();

          if(SquiddyBallX < -1) {
            SquiddyBallX = 0;
          }
          if(SquiddyBallX > 71) {
            SquiddyBallX = 70;
          }
          if(SquiddyBallY < -1) {
            SquiddyBallY = 0;
          }
          if(SquiddyBallY > 31) {
            SquiddyBallY = 30;
          }
        }
      }

// angle doesn't go too far
      if(angle > 800) {
        angle -= 360;
      }
      break;
  }
}

void resetValues() {
    collectedMeatyRings = 0;
    SquareNoseX = 16;
    SquareNoseY = 28;
    SquareNoseGoesRight = true;
    SquareNoseIsJumping = false;
    SquareNoseJumpSpeed = 0;
    SquareNoseJumpCounter = 0;
    meatyRingX = 52;
    meatyRingY = 8;
    birdX = 18;
    birdGoesRight = false;
    bugX = 54;
    bugGoesRight = true;
    frogX = 50;
    frogY = 28;
    frogGoesRight = true;
    frogIsJumping = false;
    frogJumpSpeed = 0;
    frogJumpCounter = 0;
    SquiddyX = 42;
    SquiddyY = 30;
    SquiddyBallX = 54;
    SquiddyBallY = 8;
    angle = 0;
    SquiddySpins = false;
    electricShock = false;
    endOfTest = false;
    handGoesDown = true;
    handY = -22;
}
