if [ $# -eq 0 ]; then
    echo "No argument provided."
    exit 1
fi

# Create target directory if it doesn't exist
mkdir -p "$1"

# Get current date in YYYY-MM-DD format
current_date=$(date +%Y-%m-%d)

# Create new folder with current date under the target directory
cp -r "0" "$1/$current_date"

code $1