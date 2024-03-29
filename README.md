# CSCM28

### Oliver Morris (979663) & Amy Mason (986832) CW2 

## Installation Instructions
1. Install VirtualBox
2. Download the vm image and import this into VirtualBox

	~~https://www.dropbox.com/s/koj12jo5fcwn2uz/SUID-Demo.ova?dl=0~~ sorry this is long gone :(
      
4. Start up the VM and let it start up
5. Log in with: 

		Username: starthere Password: password
      
5. Exploitable binaries can be found on each users desktop.
6. Details for each program and it's exploit can be found below; including the recommended inputs.
7. Once a binary has been exploited, and you have obtained another users shell, navigate to their desktop to continue.

_Note: Smaller README files are also on the system that spovide step-by-step instructions on how to execute each attack._

## Included Exploits
This machine demonstrates how SUID permissions can be exploited in 2 different ways; first by using user permissions to temporarily gain root access, and secondly, by using a buffer overflow attack to target variables within a program; both attacks allow for shells to be opened with the same permissions as the SUID file being exploited. 

### Buffer Overflow
A buffer overflow attack can be carried out from the starting account to gain access into Jeff's account. The program file has SUID permissions which allows for the user to have temporary root access, so by running the file and passing in the input as an arguement we are able to run the `'motd'` program. 

When arguements are passed in, there is a value below the stack which by default, is 0; however, the input aims to overwrite this value. For the sake of the demonstration, we know that the input aims to overwrite this value to be 0xdeadbeef so the program checks for this - if the value is 0 then the program acts normally but if it's equal to 0xdeadbeef then it runs the `'motd'` program. From here, a path variable manipulation attack can be carried out to force the program to run a bash shell instead.

The shellcode used to demonstrate the vulnerability is:

`python -c 'print "A"*16 + "\xef\xbe\xad\xde"*2'`

### Path Manipulation
Path manipulation can be carried out by running a call to a function (e.g. ls or cat) but not including the path; as a result the program will rely on the $PATH variable to find the function. To carry this out, we copy a shell like bash into the same directory as the program and give it the same name as the function we're trying to call. This way when the path isn't specified, the $PATH variable will find the shell bash instead of the actual function and ultimately running the shell with the same SUID permissions as the file.

On this virtual machine, there is a program called `'main'`. One of the functions of this program is to print a message of the day when the user selects it from the menu. This relies on another program called `'motd'`, located in /usr/bin/. The `'menu'` program calls the `'motd'` program using a system call in C, `system("motd")`, but does not use an absolute path and instead relies on the $PATH variable to find the executable. Due to this oversight, the menu program can launch another program, e.g. bash, simply by manipulating the $PATH variable. By copying the bash shell from `/usr/bin/bash` to the same location as the menu program and renaming it to 'motd', as well as prepending the directory to the $PATH variable, when the user selects the motd program, a new bash shell will be spawned with the permissions of the file owner.

## Patches
Unfortunately, there isn't really a suitable patch that could be made to avoid the permission exploitation. Developers will be expected to be considerate of this vulnerability when selecting which files get the temporary root access through SUID permissions.

However, there are many built in security features which tend to protect against buffer overflow (fgets, scanf) which check the format of inputs and change the array accordingly. In an ideal scenario, fgets would be used to read in the input with the expected length specified - a check is done on the length of the input to ensure that it can fit within the designated variable memory. Further compiler-level protections can also be enabled, such as the use of stack protectors; as well as enabling ASLR functionality on the machine, causing memory addresses to be randomized when a program is run.

Path manipulation can be protected against by ensuring that only absolute paths are used (e.g. '/usr/bin/motd' instead of 'motd'). This will ensure that only the desired executable is run as the contents of /usr/bin cannot be modified without sudo permissions.
