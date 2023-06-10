
NAME="$1"
N="$2"
COUT="$3"

cd $NAME

CPP_FILE="*.cpp"

for f in $CPP_FILE
do
    echo "Compiling $f file..."
    g++ $f -o a.out -Wall
done

if [ "$N" = "" ]; then
    FILES="*.in"
else
    FILES="$N.in"
fi

echo $FILES

for f in $FILES
do
    n=${f%.*}
    echo ""

    time ./a.out < $n.in > out.out

    res="FAIL"
    if cmp -s "$n.out" "out.out"; then
        res="OK"
    fi

    echo "----------$n.in-------------[$res]"
        
    if [ "$COUT" != "" ]; then
        cat out.out
        cat $n.out
    fi
    # cat out.out
    # cat $n.out

    if [ "$res" != "OK" ]; then
        echo " "
        # diff $n.out out.out
    fi

    # rm out.out

done

