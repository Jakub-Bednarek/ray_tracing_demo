var=$(find $1 -name "*.test")
for lib in $var ;\
do
    ./$lib
done