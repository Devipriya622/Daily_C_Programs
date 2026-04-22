Explain the difference between chmod, chown, and umask. 
chmod :
Full Form -> change mode
It is used to change file permissions (read r (4), write w (2), execute x (1)) for user, group anf others
Example : chmod 755 file.sh

chown :
Full Form -> Change Owner
It is used to change the ownership of a file (user and optionally group).
Example : chown user file.txt

unmask:
Full Form -> user mask
Defines the default permissions when new files/directories are created.
It removes permissions from the system defaults.
Example: unmask 022

How do you give execute permission to a file for all users? 
chmod +x filename

Write a command to change the owner of a file to root. 
chown root filename
