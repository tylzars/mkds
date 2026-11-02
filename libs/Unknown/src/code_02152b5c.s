// Two tables kept in .text after func_02152b08: the nine File functions in the order data_02152b5c is indexed, and the
// words of data_02152b80.
//
// Not compiled code: a C file can't place data in .text. 1.2 puts C tables in .rodata, also with `#pragma section`
// or a section attribute (docs/compiler.md).

    .text
    .extern FileReadViaArchive
    .extern FileWriteViaArchive
    .extern FileReadDirTableEntry
    .extern FileReadDirEntry
    .extern FileWalkPath
    .extern FileBuildPathString
    .extern FileOpenFromTableEntry
    .extern FileOpenFromRange
    .extern FileCloseReturnOk

    .global data_02152b5c
    .type data_02152b5c, @object
data_02152b5c:
    .word FileReadViaArchive
    .word FileWriteViaArchive
    .word FileReadDirTableEntry
    .word FileReadDirEntry
    .word FileWalkPath
    .word FileBuildPathString
    .word FileOpenFromTableEntry
    .word FileOpenFromRange
    .word FileCloseReturnOk
    .size data_02152b5c, . - data_02152b5c

    .global data_02152b80
    .type data_02152b80, @object
data_02152b80:
    .word 0xdec00621
    .word 0x3fce98ba
    .word 0x9de392a6
    .word 0x01edf246
    .word 0x08cce376
    .word 0xfa632356
    .word 0xdfecd4ca
    .word 0x3478629a
    .word 0x3c636d8f
    .word 0x92ca22fe
    .word 0x23978820
    .word 0xc2aecfd2
    .word 0xfe8d6732
    .word 0x986483ca
    .word 0x373efdac
    .word 0x24584687
    .size data_02152b80, . - data_02152b80
