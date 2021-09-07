	.ORIG	x3000
        LEA     R1, MyStr

LOOP
        LDR     R0, R1, #0
        LD      R2, NegEq   ; R2<- -#61
        ADD     R2, R0, R2
        BRz     DONE    ; we got =
        LD      R2, NegPlus
        ADD     R2, R0, R2
        BRz     DO_ADD  ; we got +
        ; we got number
        LD      R2, NegZero
        ADD     R0, R0, R2  ; make ascii number to number
        JSR     PUSH    ; push a number
        ADD     R1, R1, #1  ;update the pointer to the
                            ;next char
        BRnzp   LOOP

DO_ADD
        JSR     POP
        ADD     R5, R5, #0  ;monitoring underflow
        BRp     ERR
        ADD     R2, R0, #0  ;R2 <- R0 (second operand)
        JSR     POP
        ADD     R5, R5, #0  ;monitoring underflow
        BRp     ERR
        ADD     R0, R0, R2  ;perfomr addition
        JSR     PUSH
        ADD     R1, R1, #1  ;update the pointer to the
                            ;next char
        BRnzp   LOOP
DONE
        JSR     POP ;popping the final result
        JSR     POP ;cause underflow
        ADD     R5, R5, #0
        BRnz    ERR ;invalid
        HALT


ERR
        LEA     R0, ErrStr
        PUTS    
        HALT
        





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

NegEq       .FILL   #-61
NegPlus     .FILL   #-43
NegZero     .FILL   #-48
;MyStr       .STRINGZ "13+2+="
MyStr       .STRINGZ "13+2++++++="
ErrStr       .STRINGZ "Invalid expression.\n"

	.END
