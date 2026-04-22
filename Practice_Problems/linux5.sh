Write a script that checks if a file exists and prints a message. 
#!/bin/bash
file="data.txt"
if [ -f "$file" ]; then
    echo "File exists"
else
    echo "File does not exist"
fi

How do you use a case statement to handle multiple conditions?
#!/bin/bash
read -p "Enter a choice (start/stop/restart): " action
case $action in
    start)
        echo "Starting service..."
        ;;
    stop)
        echo "Stopping service..."
        ;;
    restart)
        echo "Restarting service..."
        ;;
    *)
        echo "Invalid choice"
        ;;
esac
