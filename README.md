readme file
startting with my 2 main files main.c and main.h
including the needed files and work gradually building my main function

using getline function to print out what was typed
and it dynamiclly allocates the memory thats why we free it ourself
thats my basic shell begining just to print out what the user type

then i'll start parsing the commands typed into the shell by using the strtok function it breaks what ever the user type into shell into individual strings that we can execute later on

implementing built-in commands, executables, and aliases
there is two ways to get access to the environment variables i'll stick to using environ

start handle path so the user should have to pass the whole path of a command to execute it, to help generate the path i'll creat a function that acts like which function

changing in the main loop so it doesn't have more than 40 line in the function

creating my own getline and strtok functions

