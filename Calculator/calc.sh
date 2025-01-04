x=1
while [ $x -eq 1 ]
do
echo "Enter Two Values"
read a
read b
echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Divition"
echo "eXIT"
read n 
case $n in
	1)result=$(( $a + $b))
	  echo "The Sum Of Numbers Are : $result";;
	2)result=$(( $a - $b))
	  echo "The difference Of Numbers Are : $result";;
	3)result=$(( $a * $b))
	  echo "The Multiplication Of Numbers Are : $result";;
	4)result=$(( $a / $b))
	  echo "The QUOTIENT Of Numbers Are : $result";;
	5)x=0;;
	*)echo "Invalid Operation";;
esac
done
