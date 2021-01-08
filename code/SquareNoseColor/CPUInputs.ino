void CPUInputs() {

// CPU crouches
  if(CPUIsJumping == false) {
    if((CPU_DOWN == true) && (CPUElectricShock == false)) {
      CPUY = 30;
    } else {
      CPUY = 28;
    }
  }

// move Lethal Mouse or Square Nose right and left
  if(playLethalMouse == false) {
    // Lethal Mouse: when pressing RIGHT or LEFT buttons
    if(handGoesDown == true) {
      if(CPUIsJumping == false) {
        if((CPU_RIGHT == true) && (CPUElectricShock == false)) {
          CPUGoesRight = true;
          if(CPUX < (gb.display.width() - 10)) {
            LethalMouseCPUMoves = true;
          }
        } else {
          if((CPU_LEFT == true) && (CPUElectricShock == false)) {
            CPUGoesRight = false;
            if(CPUX > 0) {
              LethalMouseCPUMoves = true;
            }
          }
        }
      }

// Lethal Mouse stops or changes direction (if not in the air)
    if(CPUIsJumping == false) {
      if((CPU_DOWN == true) && (CPUElectricShock == false)) {
        LethalMouseCPUMoves = false;
      }
    }

// moves Lethal Mouse right and left when it is mad
      if(LethalMouseCPUMoves == true) {
        if((CPUElectricShock == true) && ((madLethalMouse % 5) == 0) && (madLethalMouse != 0) && (CPUIsJumping == false)) {
          if(CPUGoesRight == true) {
            CPUGoesRight = false;
          } else {
            CPUGoesRight = true;
          }
        }
        if(CPUGoesRight == true) {
          CPUX += 3;
        } else {
          CPUX -= 3;
        }
      }
    }

    if((CPUElectricShock == true) && (CPUIsJumping == false)) {
      madLethalMouse = madLethalMouse + 1;
      if(madLethalMouse > 5) {
        madLethalMouse = 0;
      }
      LethalMouseCPUMoves = true;
    }

// Lethal Mouse: stop when hitting a wall
    if((CPUX < 1) || (CPUX > 69)) {
      if(CPUElectricShock == false) {
        LethalMouseCPUMoves = false;
      } else {
        if(CPUIsJumping == false) {
          madLethalMouse = 0;
          if(CPUGoesRight == true) {
            CPUGoesRight = false;
          } else {
            CPUGoesRight = true;
          }
          LethalMouseCPUMoves = true;
        }
      }
    }

// Square Nose moves left and right
  } else {
    if(handGoesDown == true) {
      if(((CPU_RIGHT == true)) && (CPUX < (gb.display.width() - 10))) {
        CPUX += 3;
        if((CPU_DOWN == true)) {
          CPUX += 1;
        }
        CPUGoesRight = true;
      } else {
        if(((CPU_LEFT == true)) && (CPUX > 0)) {
          CPUX -= 3;
          if((CPU_DOWN == true)) {
            CPUX -= 1;
          }
          CPUGoesRight = false;
        }
      }
    }
  }
  
// Square Nose jump
// 06-02-2020 change: button A for jumping instead of B
  if((CPUY == 28) && (CPU_pressedA == true) && (CPUElectricShock == false)) {
    CPUIsJumping = true;
    CPUJumpSpeed = -6;
    if((CPUElectricShock == false) && (handGoesDown == true)) {
      gb.sound.playTick();
    }
  }
  if((CPU_releasedA == true) && (CPUJumpSpeed < 0)) {
    CPUJumpSpeed /= 2;
  }
}
