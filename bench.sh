for i in `seq 1 32`
do
   #./tool $i 1000 ./sample/testSample$i
   #./naive ./sample/testSample$i 10000
   #./greedy ./sample/testSample$i 5000
   #./ampl ./sample/testSample$i 5000
   ./dynamic ./sample/testSample$i 10000
done

