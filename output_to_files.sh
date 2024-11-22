
#!/bin/bash

# Directory to store the output files
OUTPUT="output" 
# Ensure the output directory exists
mkdir -p "$OUTPUT"

# Program to run
PROGRAM="./run"  # Program name or path
MAX_COUNT=7  # Maximum number of output files to keep

# Run the program and save the output
TIMESTAMP=$(date +"%Y-%m-%d;%H:%M:%S")
OUTPUT_FILE="$OUTPUT/output_$TIMESTAMP.txt"

echo "Running the program and saving output to $OUTPUT_FILE..."
$PROGRAM > "$OUTPUT_FILE" 2>&1

# Remove the oldest file if there are more than MAX_COUNT files
FILE_COUNT=$(ls "$OUTPUT" | wc -l)

if (( FILE_COUNT > MAX_COUNT )); then
    OLDEST_FILE=$(ls -t "$OUTPUT" | tail -1)
    echo "Removing the oldest output file: $OLDEST_FILE"
    rm "$OUTPUT/$OLDEST_FILE"
fi

echo "Done. Current output files:"
ls "$OUTPUT"
