echo "Enter the number"
read a
fact=1
if [ $a -eq 0 ];
then
	echo "The factorial is 1"
else
	while [ $a -gt 1 ]
	do
	fact=$(($fact*$a))
	a=$(($a-1))
	done
	echo "The factorial is : $fact"
fi
