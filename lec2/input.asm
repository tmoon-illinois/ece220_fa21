    .ORIG   x3000

    ;R1<- mem[mem[LB]]
POLL
    LDI     R1,KBSRAddr 
    BRzp    POLL
    LDI     R0,KBDRAddr
    HALT
KBSRAddr    .FILL   xFE00
KBDRAddr    .FILL   xFE02

    .END
