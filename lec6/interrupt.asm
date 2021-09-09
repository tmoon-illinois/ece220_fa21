    
        .ORIG   x3000

        ; update INVT
        LEA     R0, MyISR
        STI     R0, KB_INVT


        ;Set IE bit of KBSR
        LD      R0, EN_IE
        STI     R0, KBSRAddr
        
        ; printing some ascii code
        LD      R2, ASCII_MONEY
LOOP
        LDI     R1, DSRAddr
        BRzp    LOOP
        STI     R2, DDRAddr
        BRnzp   LOOP


MyISR
        ST      R0, SaveR0
        ST      R7, SaveR7
    
        LDI     R0, KBDRAddr

LOPP_ISR
        LDI     R1, DSRAddr
        BRzp    LOOP
        STI     R0, DDRAddr
        LD      R0, SaveR0
        LD      R7, SaveR7
        RTI

ASCII_MONEY .FILL   #36
EN_IE       .FILL   x4000 ; 0100_0000_0000_0000

KB_INVT .FILL   x0180
KBSRAddr .FILL   xFE00
KBDRAddr .FILL   xFE02
DSRAddr .FILL   xFE04
DDRAddr .FILL   xFE06
SaveR0  .BLKW   #1
SaveR7  .BLKW   #1
        .END
