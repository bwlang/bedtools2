set -e;
BT=${BT-../../bin/bedtools}

FAILURES=0;

check()
{
	if diff $1 $2; then
    	echo ok
	else
    	FAILURES=$(expr $FAILURES + 1);
		echo fail
	fi
}


##################################################################
#  Test simple bedgraphs
##################################################################

echo -e "    unionbedg-1...\c"
echo -e "chr1\t10468\t10470\t66\t71" > exp
$BT unionbedg -i <(echo -e "chr1\t10468\t10470\t66") <(echo -e "chr1\t10468\t10470\t71") > obs
check obs exp
rm obs exp

##################################################################
#  Test multicolumn bedgraphs
##################################################################
echo -e "    unionbedg-2...\c"
echo -e "chr1\t10468\t10470\t66\t4\t2i\t71\t5\t2" > exp
$BT unionbedg -i <(echo -e "chr1\t10468\t10470\t66\t4\t2") <(echo -e "chr1\t10468\t10470\t71\t5\t2") > obs
check obs exp
rm obs exp

[[ $FAILURES -eq 0 ]] || exit 1;
