# Templates Prime Numbers

Algorithm and notes : 

Q:Given an integer N, how to know whether it's prime or not? 

A:We only have to check whether there exists a prime divisor leq to Sqrt(N).

If you can't figure out the fact that each composite number N has a prime divisor leq to Sqrt(N), check 'Eratosthenes Method' out.

Everything will be clear then. <br><br>

Numerical Method is good when N is very large and there is memory limitation, Eratosthenes Method however, could be really simple and fast<br><br>
but the memory cost could be enumerous when N is very large.<br><br>

I think the best way is to combine both methods with a consideration of both time and memory limitations. <br><br>
For example, we can use Eratosthenes Method to build up the initial prime list up to Sqrt(N) and then use numerical methods for the rest.<br><br>

