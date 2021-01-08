void outputs() {
// blue sky in level 0, gray background in others
  if(level == 0) {
    if(playLethalMouse == true) {
      gb.display.setColor(DARKGRAY);
    } else {
      gb.display.setColor(BLUE);
    }
    gb.display.fillRect(0, 0, 80, 18);
    gb.display.fillRect(0, 20, 80, 2);
    if(playLethalMouse == true) {
      gb.display.setColor(GRAY);
    } else {
      gb.display.setColor(LIGHTBLUE);
    }
    gb.display.fillRect(0, 18, 80, 2);
    gb.display.fillRect(0, 22, 80, 18);
// draw cloud and bushes like in Super Mario Bros
/*    gb.display.drawImage(42, 7, cloud);
    gb.display.drawImage(46, 32, bush);
    gb.display.drawImage(55, 32, bush);
    gb.display.drawImage(64, 32, bush);
*/
  } else {
    gb.display.setColor(GRAY);
    gb.display.fillRect(0, 0, gb.display.width(), gb.display.width()/2);
  }

// draw dark gray shapes on background in levels 1, 2, 3 and 4
  switch(level) {

    case 1:
      for(int row = 0; row < 2; row += 1) {
        for(int column = 0; column < 4; column += 1) {
          int brickX = column * 20;
          int brickY = row * 20;
          gb.display.setColor(DARKGRAY);
          gb.display.fillRect(brickX, brickY, 10, 10);
          gb.display.fillRect(brickX + 10, brickY + 10, 10, 10);
        }
      }
      break;

    case 2:
      for(int row = 0; row < 2; row += 1) {
        for(int column = 0; column < 8; column += 1) {
          int brickX = column * 10;
          int brickY = row * 20;
          gb.display.setColor(DARKGRAY);
          gb.display.drawLine(brickX + 9, brickY, brickX +9, brickY + 19);
          gb.display.drawLine(brickX, brickY, brickX + 9, brickY);
          gb.display.drawPixel(brickX + 1, brickY + 2);
          gb.display.drawPixel(brickX + 7, brickY + 2);
          gb.display.drawPixel(brickX + 7, brickY + 18);
          gb.display.drawPixel(brickX + 1, brickY + 18);
        }
      }
      break;

    case 3:
    case 4: // same background for levels 3 and 4
      for(int row = 0; row < 5; row += 1) {
        for(int column = 0; column < 10; column += 1) {
          int brickX = column * 8;
          int brickY = row * 8;
          gb.display.setColor(DARKGRAY);
          gb.display.fillRect(brickX + 1, brickY + 1, 6, 2);
          gb.display.fillRect(brickX + 1, brickY + 3, 2, 4);
        }
      }
      break;
  }

// meaty rings counter in the center of the test chamber
  if(level != 0) {
// draw the shadow of the numbers
    gb.display.setFontSize(2);
    if(level == 4) {
      gb.display.setColor(ORANGE);
    } else {
      gb.display.setColor(DARKGRAY);
    }
    gb.display.setCursor(34, 16);
    if(collectedMeatyRings < 10) {
      gb.display.print("0");
    }
    gb.display.print(collectedMeatyRings);
// draw the orange numbers (or red if level is 4)
    if(level == 4) {
      gb.display.setColor(RED);
    } else {
      gb.display.setColor(ORANGE);
    }
    gb.display.setCursor(33, 15);
    if(collectedMeatyRings < 10) {
      gb.display.print("0");
    }
    gb.display.print(collectedMeatyRings);
  }

// draw meaty ring or blue target
// 06-02-2020 change: show meaty ring or blue target in level 0
//  if((level != 0) && (endOfTest == false)) {
  if(endOfTest == false) {
    if(playLethalMouse == true) {
//      if((deadBird == false) && (deadBug == false) && (deadFrog == false) && (deadSquiddy == false) && (deadSquareNoseBall == false)) {
      if(electricShock == false) {
        if(level != 4) {
          gb.display.drawImage(meatyRingX, meatyRingY, blueTarget);
        } else {
          gb.display.drawImage(meatyRingX, meatyRingY, meatyRing);
        }
      }
    } else {
      if(level != 4) {
          gb.display.drawImage(meatyRingX, meatyRingY, meatyRing);
        } else {
          gb.display.drawImage(meatyRingX, meatyRingY, blueTarget);
        }
    }
  }

// draw animals
  switch(level) {
    case 1:
// bird
      if(birdGoesRight == true) {
        gb.display.drawImage(birdX, BIRD_Y, birdRight);
      } else {
        gb.display.drawImage(birdX, BIRD_Y, birdLeft);
      }

      if(deadBird == true) {
        explosion(birdX, BIRD_Y, 11, 8);
      }

// bug
      if(bugGoesRight == true) {
        gb.display.drawImage(bugX, BUG_Y, bugRight);
      } else {
        gb.display.drawImage(bugX, BUG_Y, bugLeft);
      }

      if(deadBug == true) {
        explosion(bugX, BUG_Y, 9, 7);
      }
      break;

    case 2:
// frog
      if(frogIsJumping == true) {
        gb.display.drawImage(frogX, frogY, frogAir);
      } else {
        gb.display.drawImage(frogX, frogY, frogGround);
      }

      if(deadFrog == true) {
        explosion(frogX, frogY, 12, 12);
      }
      break;

    case 3:
// Squiddy
      if(handGoesDown == true) {
        gb.display.drawImage(SquiddyX, SquiddyY, Squiddy);
      }
      if(deadSquiddy == true) {
        explosion(SquiddyX, SquiddyY, 10, 10);
      }
      if(playLethalMouse == true) {
        gb.display.drawImage(SquiddyBallX, SquiddyBallY, SquareNoseBall);
        if(deadSquareNoseBall == true) {
        explosion(SquiddyBallX, SquiddyBallY, 10, 10);
      }
      } else {
        gb.display.drawImage(SquiddyBallX, SquiddyBallY, SquiddyBall);
      }
      break;

      case 4:
// draw Lethal Mouse CPU or Square Nose CPU

  if(playLethalMouse == false) {
    // draw Lethal Mouse
    if(handGoesDown == true) {
      if(CPUGoesRight == true) {
        if(CPUIsJumping == true) {
          gb.display.drawImage(CPUX, CPUY, SquiddyBall);
        } else {
          if(CPU_RIGHT == true) {
            if((CPU_DOWN == true) && (CPUElectricShock == false)) {
              gb.display.drawImage(CPUX, CPUY, SquiddyBall);
            } else {
              gb.display.drawImage(CPUX, CPUY, LethalMouseRunsRight);
            }
          } else {
            if((CPU_DOWN == true) && (CPUElectricShock == false)) {
              gb.display.drawImage(CPUX, CPUY, SquiddyBall);
            } else {
              if(LethalMouseCPUMoves == true) {
                gb.display.drawImage(CPUX, CPUY, LethalMouseRunsRight);
              } else {
                gb.display.drawImage(CPUX, CPUY, LethalMouseBlinkRight);
              }
            }
          }
        }
      } else {
        if(CPUIsJumping == true) {
          gb.display.drawImage(CPUX, CPUY, SquiddyBall);
        } else {
          if(CPU_LEFT == true) {
            if((CPU_DOWN == true) && (CPUElectricShock == false)) {
              gb.display.drawImage(CPUX, CPUY, SquiddyBall);
            } else {
              gb.display.drawImage(CPUX, CPUY, LethalMouseRunsLeft);
            }
          } else {
            if((CPU_DOWN == true) && (CPUElectricShock == false)) {
              gb.display.drawImage(CPUX, CPUY, SquiddyBall);
            } else {
              if(LethalMouseCPUMoves == true) {
                gb.display.drawImage(CPUX, CPUY, LethalMouseRunsLeft);
              } else {
                gb.display.drawImage(CPUX, CPUY, LethalMouseBlinkLeft);
              }
            }
          }
        }
      }
    }
  } else {
// draw Square Nose
    if(handGoesDown == true) {
      if(CPUElectricShock == false) {
        if(CPUGoesRight == true) {
          if(CPUIsJumping == true) {
            gb.display.drawImage(CPUX, CPUY, SN_ball_clock);
          } else {
            if(CPU_RIGHT == true) {
              if(CPU_DOWN == true) {
                gb.display.drawImage(CPUX, CPUY, SN_ball_clock);
              } else {
                gb.display.drawImage(CPUX, CPUY, SquareNoseRunsRight);
              }
            } else {
              if(CPU_DOWN == true) {
                gb.display.drawImage(CPUX, CPUY, SquareNoseBall);
              } else {
                gb.display.drawImage(CPUX, CPUY, SquareNoseRight);
              }
            }
          }
        } else {
          if(CPUIsJumping == true) {
            gb.display.drawImage(CPUX, CPUY, SN_ball_counter_clock);
          } else {
            if(CPU_LEFT == true) {
              if(CPU_DOWN == true) {
                gb.display.drawImage(CPUX, CPUY, SN_ball_counter_clock);
              } else {
                gb.display.drawImage(CPUX, CPUY, SquareNoseRunsLeft);
              }
            } else {
              if(CPU_DOWN == true) {
                gb.display.drawImage(CPUX, CPUY, SquareNoseBall);
              } else {
                gb.display.drawImage(CPUX, CPUY, SquareNoseLeft);
              }
            }
          }
        }
      } else {
        gb.display.drawImage(CPUElectricX, CPUElectricY, SquareNoseElectric);
        explosion(CPUElectricX, CPUElectricY, 10, 12);
      }
    }
  }
  break;
  }

// draw Lethal Mouse or Square Nose

  if(playLethalMouse == true) {
    // draw Lethal Mouse
    if((handGoesDown == true) || (level == 3)) {
      if(SquareNoseGoesRight == true) {
        if(SquareNoseIsJumping == true) {
          gb.display.drawImage(SquareNoseX, SquareNoseY, SquiddyBall);
        } else {
          if(gb.buttons.repeat(BUTTON_RIGHT, 0)) {
            if((gb.buttons.repeat(BUTTON_DOWN, 0)) && (electricShock == false)) {
              gb.display.drawImage(SquareNoseX, SquareNoseY, SquiddyBall);
            } else {
              gb.display.drawImage(SquareNoseX, SquareNoseY, LethalMouseRunsRight);
            }
          } else {
            if((gb.buttons.repeat(BUTTON_DOWN, 0)) && (electricShock == false)) {
              gb.display.drawImage(SquareNoseX, SquareNoseY, SquiddyBall);
            } else {
              if(LethalMouseMoves == true) {
                gb.display.drawImage(SquareNoseX, SquareNoseY, LethalMouseRunsRight);
              } else {
                gb.display.drawImage(SquareNoseX, SquareNoseY, LethalMouseBlinkRight);
              }
            }
          }
        }
      } else {
        if(SquareNoseIsJumping == true) {
          gb.display.drawImage(SquareNoseX, SquareNoseY, SquiddyBall);
        } else {
          if(gb.buttons.repeat(BUTTON_LEFT, 0)) {
            if((gb.buttons.repeat(BUTTON_DOWN, 0)) && (electricShock == false)) {
              gb.display.drawImage(SquareNoseX, SquareNoseY, SquiddyBall);
            } else {
              gb.display.drawImage(SquareNoseX, SquareNoseY, LethalMouseRunsLeft);
            }
          } else {
            if((gb.buttons.repeat(BUTTON_DOWN, 0)) && (electricShock == false)) {
              gb.display.drawImage(SquareNoseX, SquareNoseY, SquiddyBall);
            } else {
              if(LethalMouseMoves == true) {
                gb.display.drawImage(SquareNoseX, SquareNoseY, LethalMouseRunsLeft);
              } else {
                gb.display.drawImage(SquareNoseX, SquareNoseY, LethalMouseBlinkLeft);
              }
            }
          }
        }
      }
    }
  } else {
// draw Square Nose
    if((handGoesDown == true) || (level == 3)) {
      if(electricShock == false) {
        if(SquareNoseGoesRight == true) {
          if(SquareNoseIsJumping == true) {
            gb.display.drawImage(SquareNoseX, SquareNoseY, SN_ball_clock);
          } else {
            if(gb.buttons.repeat(BUTTON_RIGHT, 0)) {
              if(gb.buttons.repeat(BUTTON_DOWN, 0)) {
                gb.display.drawImage(SquareNoseX, SquareNoseY, SN_ball_clock);
              } else {
                gb.display.drawImage(SquareNoseX, SquareNoseY, SquareNoseRunsRight);
              }
            } else {
              if(gb.buttons.repeat(BUTTON_DOWN, 0)) {
                gb.display.drawImage(SquareNoseX, SquareNoseY, SquareNoseBall);
              } else {
                gb.display.drawImage(SquareNoseX, SquareNoseY, SquareNoseRight);
              }
            }
          }
        } else {
          if(SquareNoseIsJumping == true) {
            gb.display.drawImage(SquareNoseX, SquareNoseY, SN_ball_counter_clock);
          } else {
            if(gb.buttons.repeat(BUTTON_LEFT, 0)) {
              if(gb.buttons.repeat(BUTTON_DOWN, 0)) {
                gb.display.drawImage(SquareNoseX, SquareNoseY, SN_ball_counter_clock);
              } else {
                gb.display.drawImage(SquareNoseX, SquareNoseY, SquareNoseRunsLeft);
              }
            } else {
              if(gb.buttons.repeat(BUTTON_DOWN, 0)) {
                gb.display.drawImage(SquareNoseX, SquareNoseY, SquareNoseBall);
              } else {
                gb.display.drawImage(SquareNoseX, SquareNoseY, SquareNoseLeft);
              }
            }
          }
        }
      } else {
        gb.display.drawImage(electricX, electricY, SquareNoseElectric);
        if(level == 4) {
          explosion(electricX, electricY, 10, 12);
        }
      }
    }
  }
  
// draw timer at the bottom of the screen
  if((level != 0) && (level != 4)) {
    gb.display.setFontSize(3);
// make a sound the last tenth seconds before time over
//(128 seconds or 2 minutes and 8 seconds)
//    if(((minutes == 1) && (seconds == 59)) || (minutes == 2)) {
//      if(frameCounter == 0) {
//        gb.sound.playTick();
//      }
//      gb.display.setColor(ORANGE);
//    } else {
      gb.display.setColor(DARKGRAY);
//    }
    gb.display.setCursor(6,45);
    gb.display.print(minutes);
    gb.display.setCursor(18,45);
    gb.display.print("m");
    gb.display.setCursor(30,45);
    gb.display.print(seconds / 10);
    gb.display.setCursor(42,45);
    gb.display.print(seconds % 10);
    gb.display.setCursor(54,45);
    gb.display.print("s");
    gb.display.setCursor(66,45);
    gb.display.print((frameCounter / 5) * 2);
//    if(((minutes == 1) && (seconds == 59)) || (minutes == 2)) {
//      gb.display.setColor(RED);
//    } else {
      gb.display.setColor(GRAY);
//    }
    gb.display.setCursor(5,44);
    gb.display.print(minutes); 
    gb.display.setCursor(17,44);
    gb.display.print("m");
    gb.display.setCursor(29,44);
    gb.display.print(seconds / 10);
    gb.display.setCursor(41,44);
    gb.display.print(seconds % 10);
    gb.display.setCursor(53,44);
    gb.display.print("s");
    gb.display.setCursor(65,44);
    gb.display.print((frameCounter / 5) * 2);
  }

// draw ground in level 0
  if(level == 0) {
    if(playLethalMouse == true) {
      gb.display.setColor(GRAY);
    } else {
      gb.display.setColor(ORANGE);
    }
    gb.display.fillRect(0, 47, 80, 17);
    if(playLethalMouse == true) {
      gb.display.setColor(DARKGRAY);
    } else {
      gb.display.setColor(BROWN);
    }
    for(int row = 0; row < 2; row += 1) {
      for(int column = 0; column < 5; column += 1) {
        int brickX = column * 16;
        int brickY = row * 16 + 43;
        gb.display.fillRect(brickX, brickY, 8, 8);
        gb.display.fillRect(brickX + 8, brickY + 8, 8, 8);
      }
    }
    if(playLethalMouse == true) {
      gb.display.setColor(BLACK);
    } else {
      gb.display.setColor(GREEN);
    }
    gb.display.fillRect(0, 40, 80, 7);
    if(playLethalMouse == true) {
      gb.display.setColor(YELLOW);
    } else {
      gb.display.setColor(LIGHTGREEN);
    }
    for(int column = 0; column < 10; column += 1) {
      int brickX = column * 8;
      gb.display.fillRect(brickX, 40, 4, 7);
    }
  }

  if(level == 4) {
    gb.display.setFontSize(3);
    gb.display.setColor(ORANGE);
    gb.display.setCursor(6,45);
    gb.display.print("DANGER");
    gb.display.setColor(RED);
    gb.display.setCursor(5,44);
    gb.display.print("DANGER");
  }

// draw doctor Meggan arm
  if(handY > 0) {
    if(level == 3) {
      gb.display.setColor(BEIGE);
      gb.display.fillRect(SquiddyX + 2, 0, 10, handY);
      gb.display.setColor(BLACK);
      gb.display.drawLine(SquiddyX + 1, 0, SquiddyX + 1, handY);
      gb.display.drawLine(SquiddyX + 12, 0, SquiddyX + 12, handY);
    } else {
      gb.display.setColor(BEIGE);
      gb.display.fillRect(SquareNoseX + 2, 0, 10, handY);
      gb.display.setColor(BLACK);
      gb.display.drawLine(SquareNoseX + 1, 0, SquareNoseX + 1, handY);
      gb.display.drawLine(SquareNoseX + 12, 0, SquareNoseX + 12, handY);
    }
  }
// draw doctor Meggan hand
  if(handGoesDown) {
    if(level == 3) {
      gb.display.drawImage(SquiddyX, handY, openHand);
    } else {
      gb.display.drawImage(SquareNoseX, handY, openHand);
    }
  } else {
    if(level == 3) {
      gb.display.drawImage(SquiddyX, handY, handSquiddy);
    } else {
      if(playLethalMouse == true) {
        gb.display.drawImage(SquareNoseX, handY, LethalMouseCaptured);
      } else {
        gb.display.drawImage(SquareNoseX, handY, closedHand);
      }
    }
  } 
}
