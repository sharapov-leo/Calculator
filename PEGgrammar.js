sentence
  = t1

t1
	= left:t2 "<" right:t1 { return left < right; }
    / left:t2 ">" right:t1 { return left > right; }
    / left:t2 "==" right:t1 { return left == right; }
    / t2

t2
  = left:t3 "+" right:t2 { return left + right; }
  / left:t3 "-" right:t2 { return left + right; }
  / t3

t3
  = left:t4 "*" right:t3 { return left * right; }
  / left:t4 "/" right:t3 { 
  	if (right == 0)
    	return undefined;
  	return left / right; 
  }
  / t4

t4
  = integer
  / whitespace "(" comparsion:t1 ")" whitespace { return comparsion; }

integer "integer"
  = whitespace digits:[0-9]+ whitespace { return parseInt(digits.join(""), 10); }

whitespace
	= [ \t\n\r]*
