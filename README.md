# CSCM28

*** Oliver Morris & Amy Mason's CW2 ***

## Installation & Setup
? A link to the virtual machine can be found below ?

## Included Exploits
This machine demonstrates 2 vulnerabilities; exploiting user permissions and buffer overflow to
gain root access.

### Buffer Overflow
A buffer overflow attack can be carried out to gain access into Jeff's account. In his home directory, 
there is a program file. By injecting shell code into the buffer and setting the pointer to be the start 
of the program it can be run using the permissions of the person who owns that file - we will now have a
open shell with Jeff's permissions??? he may have root access idk.

### Path Manipulation





## Patches
Unfortunately, there isn't really a suitable patch that could be made to avoid the permission exploitation. 
Developers will be expected to be considerate of this vulnerability when selecting which files get the temporary
root access through SUID permissions.
However, there are many built in security features which tend to protect against buffer overflow (fgets, scanf) 
which check the format of inputs and change the array accordingly????
