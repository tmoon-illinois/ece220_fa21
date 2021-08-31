	.ORIG	x3000

        ; some program using R0

        ST  R0, SaveR0
        IN  ;R0 is updated
        ; some program use keyboard input
        ;
        LD  R0, SaveR0



        ;;
	LEA	R3,Binary
	LD	R6,ASCII
	LD	R7,COUNT
AGAIN	
	;TRAP	x23
        ST      R7, SaveR7      ;mem[SaveR7]<- R7
        IN      ;R0
	ADD	R0,R0,R6    
	STR	R0,R3,#0
	ADD	R3,R3,#1
        LD      R7, SaveR7
	ADD	R7,R7,#-1   ;suppose to have counter 
                            ;value in R7
	BRp	AGAIN
        HALT
ASCII	.FILL	#-48
COUNT	.FILL	#3
Binary	.BLKW	#3
SaveR7  .BLKW   #1
	.END
