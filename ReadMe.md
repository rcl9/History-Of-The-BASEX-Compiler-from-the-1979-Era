# History of 8080-Z80 BASEX Compiler from the 1979 Era

This repo acts as a tribute and time capsule to the long lost *BASEX* compiler of the 1979 era of early 8080/Z80 computing.

<div style="text-align:center">
<img src="/Banners/banner1.webp" alt="" style="width:60%; height:auto;">
</div>

The BASEX compiler and runtime system was written by Paul K. Warme in the late 1970s as a faster byte-code interpreted version of BASIC that ran on the 8080 and Z80 platforms. It was touted and marketed as running 5 to 20 times faster than BASIC but in reality that was not quite the case. It sat half-way in speed between a BASIC interpreter and pure assembler. Its price was in the US$25-US$33 range + US$8 for the printed manual (in 1980s dollars).

You can learn more about BASEX in the 7 page "<a href="https://archive.org/details/dr_dobbs_journal_vol_03">BASEX: A Fast, Compact Interactive Compiler for Microcomputers</a>" article written by its author Paul Warme in Dr. Dobbs - Vol 3 #30, page 26 and/or 451.

As stated by an AI agent, "*BASEX was a clever, resource-efficient tool for 1970s 8-bit hobbyists who wanted BASIC-like simplicity with compiled performance on 8080 hardware. It exemplifies the creative, low-level software experimentation of the pre-IBM PC era, when publishing full compiler listings with source code in a printed manual was a practical distribution method. It was one of several niche languages/compilers, aimed at enthusiasts who built or modified their own systems.*"

As noted in the January 1981 review of BASEX by Mark Northrup in the Sorcerers Apprentice, "In general, the faults far out-weigh the benefits for this compiler. It is faster than BASIC but you pay for this speed with longer debugging time and much more coding. It is very good for animated graphic games, but not for most other applications". Please refer to the reviews further down in this page. 

A BASEX program is defined by a 3 character opcode with variable number of arguments, such as this contrived code:

```
BRT 0=49 94 0 195 50 8
DIM S$ 65 V$ 15 
STR V$ 1 3 S$ 1 
CMP V$ 1 3 "ABC" 
JMP EQ 9000
CAL FUNC1
SET V1=V 
FOR I=V1 
BRD I   
PRT A
DIV I/10 
MLT A*10
SBT I-A
JMP NE TAG 
```

In rebuilding my Exidy Sorcerer [Space Invaders development environment](https://github.com/rcl9/Resurrecting-and-Rebuilding-Sorcerer-Space-Invaders-from-1980--BASEX-) from the 1980-era I came to realize that there was next to no information online about BASEX. This repository strives to rebuild a basic history of BASEX as a time capsule for others to reference in the future. In no means is this a defacto historical snapshot but it does capture most of what I came to resurrect from my early 1980's hand's on experience with it. It was indeed faster for my Space Invader's game but far too cumbersome to use and very quirky. 

<div style="text-align:center">
<p><img src="https://github.com/rcl9/Resurrecting-and-Rebuilding-Sorcerer-Space-Invaders-from-1980--BASEX-/blob/main/Images/snap2.webp" alt="" style="width:50%; height:auto;">
</div>
<br>

I had spent considerable time locating Paul K. Warme (retired accountant from State College, PA) and was able to make email contact in June 2026. I penned several long emails to him offering to help "Make the BASEX name well known again" and "to capture its legacy for future generations". However, regardless of all of my good suggestions and extended emails, he simply did not want to help in rebuilding some of his history with BASEX, in making any comments whatsoever, nor in offering to make an official snapshot of it available to the current and future retro-computing community. This is rather unfortunate as my work and intent is purely to his benefit and to the legacy of the product. I have taken several months to pull together this historical archive but with no help from its original program author. 

## Some Initial Perspective of BASEX and Why It was Needed in 1979

Perspective is very important when understanding why BASEX was needed in the 1979 era. Microsoft had only released its initial BASIC interpreter for 8080 machines in 1975 and for which it started to appear on PET, TRS-80, Apple, Exidy Sorcerer and other related "consumer" machines around 1977-1978. Machines of that era typically had 4K of memory, very limited computing power and peripherals, and most often restricted to a 300 baud or 1200 baud cassette tape interface for data storage. Access to a disk drive with CP/M wouldn't become "more affordable" until well into the early 1980s and 5MB to 20MB hard disks not until the mid 1980s (for example, my Morrow SSDD 8" floppy disk unit + S-100 controller card + CP/M 2.2 were priced at US$1200 + US$300 for Microsoft Disk BASIC in 1980 dollars, or 3x more in current dollars).

Microsoft's BASCOM (BASIC compiler) did not come out until 1979 and Digital Research's CBASIC (compiled BASIC) not until a few years later. And both were disk-based CP/M software packages, with fairly hefty price tags, which were outside the scope of most non-business users. 

As such, there was a market for a lower priced "BASIC-like compiler" which did not require a floppy disk, could be run in minimal memory and from a cassette tape interface for data storage.  

For further perspective I'll mention that it was commonplace up until the early 1980s to buy a magazine, monthly compendium ("Soft Side") or book (ie. BASEX for $8) and then spend hours typing in the program listing. I spent years of my life typing in endless numbers of BASIC and assembler programs after which the files would then be saved to 1200 baud data cassette files. Buying commercial software on cassette tape was rather expensive at the time and the thought of buying a program on 8" floppy diskette was quite unthinkable for those other than companies with deep pockets. 

I'll also point out that during that era of the late 1970s and up to the late 1980s I would often encounter a new niche computer language almost every month, notably via the CP/M SIGM and LifeBoat collection of 8" disks. I had been tempted many times to try some of them but decided to keep with Z80 assembler until the late 1980s when I moved to C. In those days it was more of the norm for colleges, universities and other research + educational institutions to write and support their own languages (such as Turing from the University of Toronto and WATFOR from the Univ of Waterloo, among many many others). As such, BASEX fell into the realm of a niche compiled BASIC language, suitable for the time and era of minimalist computing. 

From Paul's opening comments in the BASEX manual:

> "BASEX is a new, easy-to-learn language for microcomputers that shares same of the best features of both BASIC and assembler language. Like assembler language programs, BASEX programs execute very rapidly.  This speed of execution is possible because the BASEX compiler produces code which makes use of the fast and powerful subroutines residing in the BASEX operating system. Since the BASEX operating system is only about 2K bytes long, BASEX programs require about 6K less memory than comparable BASIC programs, which are executed by an 8K interpreter. Array variables, text strings, arithmetic operations on signed 16 bit integers and versatile I/O communication functions are provided by BASEX."

> "The BASEX compiler is interactive; that is, it permits you to enter, list, edit and run your program without the help of any auxiliary programs, such as editors or linkage editors. Most BASEX commands resemble their counterparts in BASIC language, and this facilitates learning the language and translating programs from BASIC into BASEX."

Paul Warme had originally developed the software for the 8080 North Star computer system and its disk operating system. A printed manual was sold via BYTE Publications for US$8 which also included the source code listings to the various BASEX compiler, runtime library and loader applications. The compiler itself was written in BASEX. A TRS-80 DOS version was also available as well as that of a port to the Exidy Sorcerer. 

My BASEX implementation of Sorcerer Space Invaders came in at 2030 lines of code and 500 lines of symbol table. All of this was developed on lined paper and not interactively within the BASEX command-line driven program (as the concept of "editing and debugging" just wasn't supported well in BASEX). As changes were made on paper then they were transcribed to the BASEX compiler's code listing and saved to cassette tape -- this also ensured that my coding would be spared in case there were errors on the tape (which happened often). It also ensured that I could OCR those hand written code listings 45 years later and rebuild the same BASEX code base for the game. 

## BASEX from my own limited perspective

In the grand scheme of things I was a hard core user of BASEX for about 2 years. In April 1980 I had written 
[Space Invaders](/Resurrecting_and_Rebuilding_Sorcerer_Space_Invaders_from_1980_(BASEX))
for the Exidy Sorcerer using its PacBasic. However, I found it very slow so I opted to migrate all of it to BASEX in July 1980. I must have stumbled across BASEX in Dr. Dobbs (Vol 3 #30) and found its claims of running "Basic 5 to 20 times faster" as very enticing. In reality it wasn't as fast as pure machine language but still faster than standard Exidy 8k Basic. That experience had remained etched into my mind to this very day, given how quirky BASEX was. But one must keep in mind that I did not get my CP/M floppy disk system until July 1981 and thus had been limited to a cassette based Sorcerer for development. 

I may have ended up being one of the few people on this planet to write a large software game application entirely in BASEX and with no text editor nor any way to save/load the listing quickly (ie. via floppy disks in CP/M) other than through slow 1200 baud cassette tapes. It is utterly unbelievable today that I was able to write this complex application in any regard. A modern programmer who uses an IDE, a complex code editor and a PC would not be able to fathom what I had to endure in 1980. Alas, I didn't know any better at the time since having a personal computer like the Exidy Sorcerer was by itself a gift. Coding in BASEX was like writing software in Neanderthal times. And getting all of this to run again 45 years later in an emulator was like starting with a large puzzle with few clues, driven by intrigue and the desire to rebuild what memories I once did of the project.

BASEX provides a limited set of [byte-code instructions](</Other info/List of BASEX commands.txt>) which are executed via a common runtime library. For example, a snippet of my Space Invaders code is shown below:

```
8496 WRT 252=0 
8504 BRT 251=0 
8518 DIM CF( 11 AD( 11 FC( 11 DA( 11 V( 15 W( 8 
8636 DAT X( 1 192 192 198 198 204 210 210 216 216 222 
8694 CLS 
8698 DEF PL 1 NC 3 CR 0 MF 0 SY 0 ML 0 FI 1 F9 1 G1 3 DO 0 
8794 STR CR$ 2 2 13 
8806 FOR K=AA 
22496 BRT -144=16 16 16 40 68 68 68 0 24 60 126 
22562 CAL A6100 
22604 PRT "S O R C E R E R  I N V A D E R" CR$ 1 
```

## Core Language Style

Please refer to my [hand written command list for BASEX](</Other info/List of BASEX commands.txt>).

- Line-numbered programs (like classic BASIC): ex. `140`, `150`, `760`.

- Interactive compiler: You enter/edit/run programs directly (no separate editor or linker needed). Commands resemble BASIC for easy learning/translation.

- Variables: Signed 16-bit integers only (-32,768 to +32,767). No floating-point.

- Arrays: Supported

- Strings: HP-BASIC style . You must pre-declare the maximum length. Each character can be addressed like a 1D array element.

- No strong error checking: Overflows, bad input, or string overflows often cause a 'dump' (crash to monitor) with no helpful message or flag.

## Industry mentions of BASEX (1980 and 1981)

- BASEX Overview by Paul Warme - <a href="https://archive.org/details/dr_dobbs_journal_vol_03">Dr. Dobbs - Vol 3 #30</a>, page 26 and/or 451.

	A detailed 7 page article written by its author Paul Warme. I'll refer you to this document if you want to get a better overview of BASEX. 

- <a href="https://archive.org/details/CreativeComputingbetterScan198010/page/n47">Creative Computing v6 #10, October 1980, page 47</a>

	A one page review of BASEX by Ray C. Horn Jr. 

- <a href="https://archive.org/details/bitsavers_exidySorcerersApprenticeV3N1Jan1981_1943278">Sorcerers Apprentice, v3 #1, January 1981</a>

	Mark Northrup provides a hand's on review of using BASEX. He was generally not too happy about using it. I can chime in and say that his comments were valid and inline with my own "head banging" experience of using BASEX:

	"The major problem with BASEX is that it is somewhat weak on error checking as Dr. Warme had warned in Dr. Dobbs. It is very weak, although none of the programs I have written went "wild", there are far too many ways to get into frustrating trouble. Inserting and deleting lines is at best a dangerous proposition."

	"In general, the faults far out-weigh the benefits for this compiler. It is faster than BASIC, but you pay for this speed with longer debugging time and much more coding. It is very good for animated graphic games, but not for most other applications."

- Snippet from the March 1979 issue of BYTE magazine:

	"BASEX, a new compact, compiled language for microcomputers, has many of the best features of BASIC and the 8080 assembly language - and it can be run on any of the 8080 style microprocessors.

	Subroutines in the BASEX operating system typically execute programs up to five times faster than equivalent programs in a BASIC interpreter - while requiring about half the memory space. In addition, BASEX has most of the powerful features of good BASIC interpreters including: Array variables, Text strings, Arithmetic operations on signed 16 bit integers and Versatile I/O communication functions.

	The author, Paul Warme, has also included a BASEX Loader program which is capable of relocating programs anywhere in memory."

## The BASEX Runtime Environment

I have made the effort to rebuild a working version of BASEX and of its documentation, as I would have used it back in 1980.

The main components of the BASEX environment are:

1. The static BASEX runtime executable library which usually resided from 0100H to 0939H in memory.

2. The BASEX byte-code compiler and interactive editing environment. This was relocatable for which my version resided from 0x09DC to 0x20FF.

3. The user's BASEX program. My Sorcerer Space Invaders resided in memory from 0x2100 to 0x60B7. I had also developed a set of machine language routines (from 0x6100 to 0x6d10) that I called directly from the BASEX program (via "CAL" statements) to do the heavy lifting graphics operations and machine input/output. 

4. The all important BASEX symbol table for the user's BASEX program. A program would not be complete unless you had saved and loaded this table. It contained all the data elements for the associated program. The symbol table for my Sorcerer Space Invaders resided between 0x6F52 to 0x7EFF (end of memory for a 32k machine without CP/M running). 

5. The optional BASEX "Loader" program which could be used to relocate the user's BASEX program and its symbol table. I have not used this since the 1980 era. 

It was very important to write down the start/end of the program memory space and the symbol table memory space, as those numbers were needed every time the BASEX compiler started up. That means you'd generally need those "convenience" numbers in hand 45 years later...

## How is a BASEX Program Edited and Run?

Starting up and using the BASEX runtime environment is and was tedious when using a cassette based Exidy Sorcerer without CP/M nor with any streamlined text editing coding environment.

1. The BASEX runtime executable library needed to be loaded into memory (0100H)

2. The BASEX compiler was then needed to be loaded into memory (0x09DC)

3. The BASEX program had to be loaded into memory (0x2100)

4. And finally the BASEX symbol table needed to be loaded into memory (0x6F52).

The BASEX compiler could then be executed via "GO 0100" in the Exidy Monitor. When prompted with a "?" the user always had to type in 4 numbers which defined the start/end of the program memory space and the start/end of the symbol table memory space:

```
8496 24756  28499 32511
```

Thereafter the program could be listed via "LST". Or, it could be run via "RUN XXX" where XXX is the address of the first line of code (if you don't provide XXX then BASEX aborts its UI and ends up in the Exidy monitor). There is little or no error reporting if something goes wrong or it crashes as you'll just end up being back at the Exidy monitor's prompt. 

<!--
## How to view the BASEX Compiler Source Code

The original manual (available online elsewhere) provides a listing for the BASEX compiler and runtime system but the compiler can also be listed via itself. For my own setup in particular (with BASEX residing from 0x09DC to 0x20ff):

1. Enter "2524 7101 7102 8447" when the compiler starts up which lets the compiler see its own byte-code program.

2. List the main code with "LST 2554 7088"

3. List the symbol table with "LSM 7102"
-->

## Utility Program to dump a BASEX Symbol File

I wrote a [simple utility program](</RCL's BASEX symbol table dumper>) to dump the contents of a BASEX symbol file, sorted either by symbol name or its value. It also handles string arrays and variable arrays.

This is useful if you want to look-up some values as referenced in the orignal BASEX program, or cross reference some machine language code against where it may be called from the BASEX program.

## Online Resources for BASEX

The BASEX runtime system and its original 1979 manual can be found online in various retro computing sites. I'll leave that up to others to find themselves given that Paul Warme did not wish to contribute a snapshot of his system for posterity. 

There is also the "BASEX Northstar Tape and Disk Guide" of 1978 by Paul Warme. 

## Other References in this Repository

[My hand written command list for BASEX](</Other info/List of BASEX commands.txt>)

[The source code to my BASEX symbol table dumper program, written in C++](</RCL's BASEX symbol table dumper>)
