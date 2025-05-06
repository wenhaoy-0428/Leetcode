if [ $# -eq 0 ]; then
    echo "No argument provided."
else
    cp -r 0 $1
fi

code $1