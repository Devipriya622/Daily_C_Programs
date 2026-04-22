How do you define and access a variable in a Bash script? 
Defining:
Assign a value to a name using the = operator.
Rule->Do not use spaces around the equals sign (e.g., NAME="Devi Priya").
Naming-> Must start with a letter or underscore; can include numbers.

Accessing:
Prefix the variable name with a $ symbol to retrieve its value (e.g., echo $NAME).

Explain the difference between single quotes and double quotes in Bash.
Single quotes ' ':
Treat everything literally
No variable expansion, no special character interpretation
name="Devi"
echo 'Hello $name'
Output:
Hello $name

Double quotes " ":
Allow variable expansion and some special characters
name="Devi"
echo "Hello $name"
Output:
Hello Devi
