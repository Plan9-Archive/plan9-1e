TEXT _FORKPGRP(SB), 1, $0
MOVW R1, 0(FP)
MOVW $10, R1
SYSCALL
RET
