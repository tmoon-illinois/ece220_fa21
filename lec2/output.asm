    .ORIG   x3000

    ;DDR, mem[mem[LB]] <- R0
    LD      R0, ASCII
POLL
    LDI     R1,DSRAddr
    BRzp    POLL
    STI     R0,DDRAddr
    HALT
DSRAddr    .FILL   xFE04
DDRAddr    .FILL   xFE06
ASCII       .FILL   x0061
    .END
