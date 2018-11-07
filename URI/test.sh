for i in {1..40}
do
	echo "Test".$i
	./a.out < ./input/F_$i | diff ./output/F_$i -
done
