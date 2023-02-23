bool isPalindrome(int x){
	// Check whether given number is negative
	// Check whether given number is non zero and ends with a zero (10, 1230, 12210, etc)
	// because number with ending zero can not be a Palindrome number
    if ((x < 0) || ((x != 0) && (x % 10 == 0))) 
    {
        return false;
    }
    int rev_x = 0;
    while (rev_x < x)
    {
        rev_x = (rev_x * 10) + (x % 10);
        x /= 10;
    }
	// (rev_x == x) when number is even e.g. 1221, it can be equated as 12 == 12
	// (rev_x / 10) == x) when number is odd e.g. 12321, it must be divided by 10, 123 / 10 = 12
	return (rev_x == x) || ((rev_x / 10) == x);
}