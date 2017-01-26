for i in `seq 1 32`
do
   ./tool $i 1000 ./sample/testSample$i
   ./naive ./sample/testSample$i -1
done

