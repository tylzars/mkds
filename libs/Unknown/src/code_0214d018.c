#include "code_0214d018.h"

// clang-format off
// Fills c bytes at b (whole words) with the word a.
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward, move the base off r0 and use ldr/str for a lone word (docs/compiler.md,
// ldm/stm; checked on C). Here each word is stored with a conditional one-register `stmlt r1!`.
asm void MemFillWords(u32 a, void *b, u32 c) {
    add ip, r1, r2
fillw_loop:
    cmp r1, ip
    stmltia r1!, {r0}
    blt fillw_loop
    bx lr
}

// Copies c bytes (whole words) from a to b.
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward, move the base off r0 and use ldr/str for a lone word (docs/compiler.md,
// ldm/stm; checked on C). Here each word moves with a conditional one-register `ldmlt r0!` / `stmlt r1!`.
asm void MemCopyWords(const void *a, void *b, u32 c) {
    add ip, r1, r2
copyw_loop:
    cmp r1, ip
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt copyw_loop
    bx lr
}

// Copies c bytes (whole words) from a to the one address b.
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward, move the base off r0 and use ldr/str for a lone word (docs/compiler.md,
// ldm/stm; checked on C). Here each word is read with a conditional one-register `ldmlt r0!`.
asm void MemCopyWordsToOneAddress(const void *a, vu32 *b, u32 c) {
    add ip, r0, r2
copyp_loop:
    cmp r0, ip
    ldmltia r0!, {r2}
    strlt r2, [r1]
    blt copyp_loop
    bx lr
}

// Fills c bytes at b (whole words) with the word a: 32 bytes per store while a full block remains, then a word at a
// time.
// Not compiled code: it saves r4-r9 without lr, where in 1.2 code a function that saves r4 also saves lr
// (docs/compiler.md, Registers), and stores with conditional `stmlt r1!` lists 1.2 builds only in block moves.
asm void MemFillWordsByBlock(u32 a, void *b, u32 c) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9}
    // ip = end of the whole 32-byte blocks; r0 and r2-r8 all hold the value.
    add r9, r1, r2
    mov ip, r2, lsr #5
    add ip, r1, ip, lsl #5
    mov r2, r0
    mov r3, r2
    mov r4, r2
    mov r5, r2
    mov r6, r2
    mov r7, r2
    mov r8, r2
fillb_block_loop:
    cmp r1, ip
    stmltia r1!, {r0, r2, r3, r4, r5, r6, r7, r8}
    blt fillb_block_loop
fillb_word_loop:
    cmp r1, r9
    stmltia r1!, {r0}
    blt fillb_word_loop
    ldmfd sp!, {r4, r5, r6, r7, r8, r9}
    bx lr
}

// Copies c bytes (whole words) from a to b: 32 bytes per step while a full block remains, then a word at a time.
// Not compiled code: it saves r4-r10 without lr and without a padding word, where 1.2 saves lr with r4 and pads every
// frame to 8 bytes (docs/compiler.md, Registers; frame layout in the compiler), and copies with conditional `ldmlt` /
// `stmlt` lists 1.2 builds only in block moves.
asm void MemCopyWordsByBlock(const void *a, void *b, u32 c) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    // ip = end of the whole 32-byte blocks.
    add r10, r1, r2
    mov ip, r2, lsr #5
    add ip, r1, ip, lsl #5
copyb_block_loop:
    cmp r1, ip
    ldmltia r0!, {r2, r3, r4, r5, r6, r7, r8, r9}
    stmltia r1!, {r2, r3, r4, r5, r6, r7, r8, r9}
    blt copyb_block_loop
copyb_word_loop:
    cmp r1, r10
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt copyb_word_loop
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    bx lr
}

// Copies 8 words from a to b.
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward, move the base off r0 and use ldr/str for a lone word (docs/compiler.md,
// ldm/stm; checked on C). Here it copies with `ldm r0!` / `stm r1!` and data in r2, r3 and ip.
asm void MemCopy8Words(const void *a, void *b) {
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3}
    stmia r1!, {r2, r3}
    bx lr
}

// Copies 9 words from a to b.
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward, move the base off r0 and use ldr/str for a lone word (docs/compiler.md,
// ldm/stm; checked on C). Here it copies with `ldm r0!` / `stm r1!` and data in r2, r3 and ip.
asm void MemCopy9Words(const void *a, void *b) {
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    bx lr
}

// Copies 12 words from a to b.
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward, move the base off r0 and use ldr/str for a lone word (docs/compiler.md,
// ldm/stm; checked on C). Here it copies with `ldm r0!` / `stm r1!` and data in r2, r3 and ip.
asm void MemCopy12Words(const void *a, void *b) {
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    bx lr
}

// Copies 16 words from a to b.
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward, move the base off r0 and use ldr/str for a lone word (docs/compiler.md,
// ldm/stm; checked on C). Here it copies with `ldm r0!` / `stm r1!` and data in r2, r3 and ip.
asm void MemCopy16Words(const void *a, void *b) {
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0, {r0, r2, r3, ip}
    stmia r1!, {r0, r2, r3, ip}
    bx lr
}

// Fills c bytes at a with the byte b using only halfword and word stores (an odd first or last byte is merged with its
// neighbour through a halfword read).
// Not compiled code: it tests bits with tst, which the 1.2 compiler never builds (docs/compiler.md).
asm void MemFill(void *a, u8 b, u32 c) {
    // Nothing to do for c = 0. An odd start address: merge the byte into the halfword below it.
    cmp r2, #0
    bxeq lr
    tst r0, #1
    beq fillh_aligned
    ldrh ip, [r0, #-1]
    and ip, ip, #0xff
    orr r3, ip, r1, lsl #8
    strh r3, [r0, #-1]
    add r0, r0, #1
    subs r2, r2, #1
    bxeq lr
    // Fewer than two bytes left: last byte. Otherwise a halfword to reach a word boundary.
fillh_aligned:
    cmp r2, #2
    blo fillh_last_byte
    orr r1, r1, r1, lsl #8
    tst r0, #2
    beq fillh_words
    strh r1, [r0], #2
    subs r2, r2, #2
    bxeq lr
    // Whole words, then a halfword and a last byte if left.
fillh_words:
    orr r1, r1, r1, lsl #16
    bics r3, r2, #3
    beq fillh_tail
    sub r2, r2, r3
    add ip, r3, r0
fillh_word_loop:
    str r1, [r0], #4
    cmp r0, ip
    blo fillh_word_loop
fillh_tail:
    tst r2, #2
    strneh r1, [r0], #2
    // Last byte: merge into the low half of the halfword there.
fillh_last_byte:
    tst r2, #1
    bxeq lr
    ldrh r3, [r0]
    and r3, r3, #0xff00
    and r1, r1, #0xff
    orr r1, r1, r3
    strh r1, [r0]
    bx lr
}

// Copies c bytes from a to b using only halfword and word accesses: an odd first or last destination byte is merged
// with its neighbour through a halfword read; when a and b differ in alignment the bytes are reassembled from halfword
// reads.
// Not compiled code: it tests bits with tst, which the 1.2 compiler never builds (docs/compiler.md).
asm void MemCopy(const void *a, void *b, u32 c) {
    // Nothing to do for c = 0. An odd destination: merge the first byte into the halfword below it.
    cmp r2, #0
    bxeq lr
    tst r1, #1
    beq copyh_aligned
    ldrh ip, [r1, #-1]
    and ip, ip, #0xff
    tst r0, #1
    ldrneh r3, [r0, #-1]
    movne r3, r3, lsr #8
    ldreqh r3, [r0]
    orr r3, ip, r3, lsl #8
    strh r3, [r1, #-1]
    add r0, r0, #1
    add r1, r1, #1
    subs r2, r2, #1
    bxeq lr
    // Source and destination of different parity: rebuild each halfword from two source halfwords.
copyh_aligned:
    eor ip, r1, r0
    tst ip, #1
    beq copyh_same_parity
    bic r0, r0, #1
    ldrh ip, [r0], #2
    mov r3, ip, lsr #8
    subs r2, r2, #2
    blo copyh_odd_tail
copyh_odd_loop:
    ldrh ip, [r0], #2
    orr ip, r3, ip, lsl #8
    strh ip, [r1], #2
    mov r3, ip, lsr #16
    subs r2, r2, #2
    bhs copyh_odd_loop
copyh_odd_tail:
    tst r2, #1
    bxeq lr
    ldrh ip, [r1]
    and ip, ip, #0xff00
    orr ip, ip, r3
    strh ip, [r1]
    bx lr
    // Same parity. Destination not word-aligned with the source: halfword copies.
copyh_same_parity:
    tst ip, #2
    beq copyh_even
    bics r3, r2, #1
    beq copyh_last_byte
    sub r2, r2, r3
    add ip, r3, r1
copyh_half_loop:
    ldrh r3, [r0], #2
    strh r3, [r1], #2
    cmp r1, ip
    blo copyh_half_loop
    b copyh_last_byte
    // Same word alignment: a halfword to reach a word boundary, then words.
copyh_even:
    cmp r2, #2
    blo copyh_last_byte
    tst r1, #2
    beq copyh_words
    ldrh r3, [r0], #2
    strh r3, [r1], #2
    subs r2, r2, #2
    bxeq lr
copyh_words:
    bics r3, r2, #3
    beq copyh_tail
    sub r2, r2, r3
    add ip, r3, r1
copyh_word_loop:
    ldr r3, [r0], #4
    str r3, [r1], #4
    cmp r1, ip
    blo copyh_word_loop
    // A halfword and a last byte if left; the last byte merges into the destination halfword.
copyh_tail:
    tst r2, #2
    ldrneh r3, [r0], #2
    strneh r3, [r1], #2
copyh_last_byte:
    tst r2, #1
    bxeq lr
    ldrh r2, [r1]
    ldrh r0, [r0]
    and r2, r2, #0xff00
    and r0, r0, #0xff
    orr r0, r2, r0
    strh r0, [r1]
    bx lr
}

#pragma thumb on

// Clears the nine words at a.
// Not compiled code: it stores with `stmia r0!` and the list {r1, r2, r3}; in Thumb code the 1.2 compiler builds stm
// only for block moves, which keep their data in r0 upward (docs/compiler.md, ldm/stm).
asm void func_0214d32c(s32 *a) {
    mov r1, #0
    mov r2, #0
    mov r3, #0
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r2, r3}
    bx lr
}

#pragma thumb off

// Swaps a with the word at b in one instruction and returns the old word.
// Not compiled code: it is a word swp, which the 1.2 compiler never builds: the instruction's opcode number appears in
// the compiler only as an argument to its error reporter, while the byte form has a code-generator use.
asm s32 func_0214d33c(s32 a, s32 *b) {
    swp r0, r0, [r1]
    bx lr
}

// Expands compressed data from a into b. The first word holds the expanded size in its upper 24 bits. Then each flag
// byte covers the next eight items, its top bit first: a clear bit is one literal byte; a set bit is a two-byte
// back copy: copy (top nibble + 3) bytes from (low 12 bits + 1) bytes back in the output. Every output byte is written
// with swpb.
// Not compiled code: it tests bits with tst, which the 1.2 compiler never builds, and tests `subs r4, r4, #1` with lt,
// where 1.2 folds a compare into a flag-setting subtract only for eq/ne/mi/pl (docs/compiler.md).
asm void func_0214d344(const void *a, void *b) {
    // r2 = the number of bytes still to write.
    stmfd sp!, {r4, r5, r6, lr}
    ldr r5, [r0], #4
    mov r2, r5, lsr #8
lz_check_end:
    cmp r2, #0
    ble lz_done
    // Next flag byte (lr); r4 counts its eight items.
    ldrb lr, [r0], #1
    mov r4, #8
lz_next_item:
    subs r4, r4, #1
    blt lz_check_end
    tst lr, #0x80
    bne lz_back_copy
    // Literal: copy one byte.
    ldrb r6, [r0], #1
    swpb r6, r6, [r1]
    add r1, r1, #1
    sub r2, r2, #1
    b lz_item_done
    // Back copy: r3 = length (top nibble + 3), ip = distance (low 12 bits + 1); copy byte by byte.
lz_back_copy:
    ldrb r5, [r0]
    mov r6, #3
    add r3, r6, r5, asr #4
    ldrb r6, [r0], #1
    and r5, r6, #0xf
    mov ip, r5, lsl #8
    ldrb r6, [r0], #1
    orr r5, r6, ip
    add ip, r5, #1
    sub r2, r2, r3
lz_copy_loop:
    ldrb r5, [r1, -ip]
    swpb r5, r5, [r1]
    add r1, r1, #1
    subs r3, r3, #1
    bgt lz_copy_loop
    // More to write: next flag bit (or the next flag byte when eight are done).
lz_item_done:
    cmp r2, #0
    movgt lr, lr, lsl #1
    bgt lz_next_item
    b lz_check_end
lz_done:
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
}
// clang-format on
