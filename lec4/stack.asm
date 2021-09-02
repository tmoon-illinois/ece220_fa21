	.ORIG	x3000


        LD      R5, PW
        ; caller-save 
        ST      R5, SaveR5

        IN      ;R0 <- keyboard
        JSR     PUSH
        IN      ;R0 <- keyboard
        JSR     PUSH
        IN      ;R0 <- keyboard
        JSR     PUSH
        IN      ;R0 <- keyboard
        JSR     PUSH
        ; 5th push -> overflow
        IN      ;R0 <- keyboard
        JSR     PUSH

        JSR     POP
        OUT
        JSR     POP
        OUT
        JSR     POP
        OUT
        JSR     POP
        OUT
        ; 5th pop -> underflow
        JSR     POP
        OUT
        ; user will read R5 to determine 
        ; whether there was an overflow
        ; if R5= 1
        ;ADD     R5, R5, #0
        ;dummy instrcution to read sign of R5
        ;BRp     OVERFLOW

       
        LD      R5, SaveR5



;PUSH subroutine
;IN: R0 (value)
;OUT: R5(0-success, 1-fail)
;R3: STACK_END
;R6: STACK_TOP
PUSH
;callee-save & initialize registers
        ST      R3, SaveR3        
        ST      R6, SaveR6
        LD      R3, STACK_END
        LD      R6, STACK_TOP
        AND     R5, R5, #0

;overflow?
;Check if STACK_TOP = STACK_END - 1
;Or check if STACK_TOP - (STACK_END - 1) = 0
        ADD     R3, R3, #-1 ;R3 = S_E-1
        NOT     R3, R3
        ADD     R3, R3, #1  ;R3 = -(S_E-1)
        ADD     R3, R6, R3  ;R3 = S_T-(S_E-1)
        BRz     OVERFLOW

;it is NOT overflow
        STR     R0, R6, #0
        ADD     R6, R6, #-1
        ST      R6, STACK_TOP
        BR      DONE_PUSH
;it is overflow
OVERFLOW
        ADD     R5, R5, #1  ;R5 = 1

;restore registers
DONE_PUSH 
        LD      R3, SaveR3        
        LD      R6, SaveR6       
        RET

;POP subroutine
;IN: none
;OUT: R0 (value)
;OUT: R5 (0: success, 1: fail)
;R3: STACK_START
;R6: STACK_TOP
POP
;callee-save & initialize registers
        ST      R3, SaveR3        
        ST      R6, SaveR6
        LD      R3, STACK_START
        LD      R6, STACK_TOP
        AND     R5, R5, #0

;underflow?
;Check if STACK_TOP = STACK_START
;Or check if STACK_TOP - STACK_START = 0
        NOT     R3, R3
        ADD     R3, R3, #1 ;R3 = -S_S
        ADD     R3, R6, R3  ;R3 = S_T - S_S
        BRz     UNDERFLOW

;it is NOT underflow
        ADD     R6, R6, #1
        LDR     R0, R6, #0
        ST      R6, STACK_TOP
        BR      DONE_POP
;it is underflow
UNDERFLOW
        ADD     R5, R5, #1
;restore registers
DONE_POP 
        LD      R3, SaveR3        
        LD      R6, SaveR6       
        RET

;temp memory
;3FFD <--STACK_END
;3FFE
;3FFF
;4000 <--STACK_START
STACK_END   .FILL x3FFD
STACK_START .FILL x4000
STACK_TOP   .FILL x4000
PW          .FILL xABCD
SaveR3      .BLKW #1
SaveR6      .BLKW #1
SaveR5      .BLKW #1
	.END
