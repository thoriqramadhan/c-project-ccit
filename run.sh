if [ -z "$1" ]; then
    # echo "Sedang : $1"
    exit 1
fi
FILE=$1

gcc -Wall -o ./output/$FILE $FILE.c

if [ $? -eq 0 ]; then
    echo "✅ Compile berhasil, menjalankan $FILE..."
    echo "=============================="
    ./output/$FILE
    echo "=============================="
else 
    echo "Proses compile gagal!"
fi