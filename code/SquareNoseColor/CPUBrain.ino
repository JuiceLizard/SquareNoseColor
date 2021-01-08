void CPUBrain() {
  if((endOfTest != true) && (CPUChasing == true)) {
// boss chasing the target
// go left
    if((meatyRingX + 4) < CPUX) {
      CPU_RIGHT = false;
      CPU_LEFT = true;
    } else {
      CPU_LEFT = false;
    }

// go right
    if((meatyRingX - 6) > CPUX) {
      CPU_LEFT = false;
      CPU_RIGHT = true;
    } else {
      CPU_RIGHT = false;
    }

// jump
    if(CPUIsJumping == false) {
      if((((meatyRingX + 1) - CPUX < CPUY - meatyRingY) && (CPUX < meatyRingX)) || ((CPUX - meatyRingX < CPUY - meatyRingY) && (CPUX > meatyRingX)) || ((LethalMouseCPUMoves == false) && (CPUY > (meatyRingY + 6) && ((CPUX < meatyRingX + 5) && (CPUX > meatyRingX - 7))))) {
        CPU_pressedA = true; 
      }
    } else {
      CPU_pressedA = false;
    }

  } else {
// boss stops moving and crouches
// when test is over or during a short time after catching a target
    CPU_RIGHT = false;
    CPU_LEFT = false;
    CPU_pressedA = false;
    CPU_DOWN = true;
// this counter begins when CPU is on the ground
    if(CPUY > 27) {
      CPUDelay += 1;
    }
// the boss stands up just before chasing a new target
    if(CPUDelay > (20 - (gameLoop * 5)) && (gameLoop < 4)) {
      CPU_DOWN = false;
    }
// the boss waits 1 second in loop 0 and this time reduces with loops
    if(CPUDelay > (25 - (gameLoop * 5))) {
      CPUDelay = 0;
      CPUChasing = true;
      CPU_DOWN = false;
    }
  }
}
