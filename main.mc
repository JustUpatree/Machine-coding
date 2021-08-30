## ELF HEADER START
7F 45 4C 46 ## Magic number
02 ## Set 64-bit platform
01 ## Set little endianness
01 ## Set current version of ELF
00 ## ABI
00 ## also ABI version
00 00 00 00 00 00 00 ## currently unused, should be filled with zeros.
02 00 ## object file type
3E 00 ## architecture version
01 00 00 00 ## the original version of ELF
F8 00 01 00 00 00 00 00 ## entry point 
40 00 00 00 00 00 00 00 ## Points to the start of the program header table
00 00 00 00 00 00 00 00 ## Points to the start of the section header table
00 00 00 00 ## Interpretation of this field depends on the target architecture
40 00 ## the size of this header
38 00 ## the size of a program header table entry	 
03 00 ## the number of entries in the program header table
00 00 ## the size of a section header table entry
00 00 ## Contains the number of entries in the section header table
00 00 ## Contains index of the section header table entry that contains the section names
## ELF HEADER END

## PROGRAM HEADER START
01 00 00 00 ## Loadable segment
04 00 00 00 ## Segment access permissions 
00 00 00 00 00 00 00 00 ## Offset of the segment in the file image
00 00 01 00 00 00 00 00 ## virtual memory address
00 00 00 00 00 00 00 00 ## physical address
E8 00 00 00 00 00 00 00 ## size in bytes of the segment in the file image
E8 00 00 00 00 00 00 00 ## Size in bytes of the segment in memory
00 00 00 00 00 00 00 00 ## Alignment
## PROGRAM HEADER END

## PROGRAM HEADER START
01 00 00 00 ## Loadable segment
04 00 00 00 ## Segment access permissions 
E8 00 00 00 00 00 00 00 ## Offset of the segment in the file image
E8 00 01 00 00 00 00 00 ## virtual memory address
00 00 00 00 00 00 00 00 ## physical address
10 00 00 00 00 00 00 00 ## size in bytes of the segment in the file image
10 00 00 00 00 00 00 00 ## Size in bytes of the segment in memory
00 00 00 00 00 00 00 00 ## Alignment
## PROGRAM HEADER END

## PROGRAM HEADER START
01 00 00 00 ## Loadable segment
01 00 00 00 ## Segment access permissions 
F8 00 00 00 00 00 00 00 ## Offset of the segment in the file image
F8 00 01 00 00 00 00 00 ## virtual memory address
00 00 00 00 00 00 00 00 ## physical address
10 00 00 00 00 00 00 00 ## size in bytes of the segment in the file image
10 00 00 00 00 00 00 00 ## Size in bytes of the segment in memory
00 00 00 00 00 00 00 00 ## Alignment
## PROGRAM HEADER END

## .data START
48 65 6c 6c 6f 2c 20 
77 6f 72 6c 64 21 0a 
00 00
## .data END

## CODE START
48 c7 c0 01 00 00 00
48 c7 c7 01 00 00 00
48 c7 c6 e8 00 01 00
48 c7 c2 0e 00 00 00
0f 05
48 C7 C0 3C 00 00 00    
48 C7 C7 2A 00 00 00    
0F 05     
## CODE END

