
NAME="$1"

cd $NAME

CPP_FILE="*.cpp"

for f in $CPP_FILE
do
    echo "Compiling $f file..."
    g++ $f -o a.out
done

FILES="*.in"

for f in $FILES
do
    n=${f%.*}
    echo ""

    ./a.out < $n.in > out.out

    res="FAIL"
    if cmp -s $n.out out.out; then
        res="OK"
    fi

    echo "----------$n.in-------------[$res]"
        
    cat out.out
    cat $n.out

    if [ "$res" != "OK" ]; then
        echo " "
        # diff $n.out out.out
    fi

    rm out.out

done

